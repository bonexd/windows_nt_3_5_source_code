/*++

Copyright (c) 1989-1993  Microsoft Corporation

Module Name:

    receive.c

Abstract:

    This module contains code which performs the following TDI services:

        o   TdiReceiveDatagram

Environment:

    Kernel mode

Revision History:

--*/

#include "precomp.h"
#pragma hdrstop



VOID
IpxTransferDataComplete(
    IN NDIS_HANDLE BindingContext,
    IN PNDIS_PACKET NdisPacket,
    IN NDIS_STATUS NdisStatus,
    IN UINT BytesTransferred
    )

/*++

Routine Description:

    This routine receives control from the physical provider as an
    indication that an NdisTransferData has completed. We use this indication
    to complete any pended requests to our clients.

Arguments:

    BindingContext - The Adapter Binding specified at initialization time.

    NdisPacket/RequestHandle - An identifier for the request that completed.

    NdisStatus - The completion status for the request.

    BytesTransferred - Number of bytes actually transferred.


Return Value:

    None.

--*/

{
    PADAPTER Adapter = (PADAPTER)BindingContext;
    PIPX_RECEIVE_RESERVED Reserved = (PIPX_RECEIVE_RESERVED)(NdisPacket->ProtocolReserved);
    PREQUEST Request, LastRequest;
    PADDRESS_FILE AddressFile;
    ULONG ByteOffset;
    PLIST_ENTRY p;
    PDEVICE Device;


    switch (Reserved->Identifier) {

    case IDENTIFIER_IPX:

        if (Reserved->SingleRequest) {

            //
            // The transfer was directly into the client buffer,
            // so simply complete the request.
            //

            Request = Reserved->SingleRequest;

            if (NdisStatus == NDIS_STATUS_SUCCESS) {

                IPX_DEBUG (RECEIVE, ("Transferred %d bytes\n", BytesTransferred));
                REQUEST_INFORMATION(Request) = BytesTransferred;
                REQUEST_STATUS(Request) = STATUS_SUCCESS;

            } else {

                IPX_DEBUG (RECEIVE, ("Transfer failed\n"));
                REQUEST_INFORMATION(Request) = 0;
                REQUEST_STATUS(Request) = STATUS_ADAPTER_HARDWARE_ERROR;

            }

            LastRequest = Request;
            Reserved->SingleRequest = NULL;

        } else {

            //
            // Multiple clients requested this datagram. Save
            // the last one to delay queueing it for completion.
            //

            LastRequest = LIST_ENTRY_TO_REQUEST (Reserved->Requests.Blink);

            while (TRUE) {

                p = RemoveHeadList (&Reserved->Requests);
                if (p == &Reserved->Requests) {
                    break;
                }

                Request = LIST_ENTRY_TO_REQUEST(p);
                AddressFile = REQUEST_OPEN_CONTEXT(Request);

                if (AddressFile->ReceiveIpxHeader) {
                    ByteOffset = 0;
                } else {
                    ByteOffset = sizeof(IPX_HEADER);
                }

                if (NdisStatus == NDIS_STATUS_SUCCESS) {

                    REQUEST_STATUS(Request) =
                    TdiCopyBufferToMdl(
                        Reserved->ReceiveBuffer->Data,
                        ByteOffset + REQUEST_INFORMATION(Request),
                        ((PTDI_REQUEST_KERNEL_RECEIVEDG)(REQUEST_PARAMETERS(Request)))->ReceiveLength,
                        REQUEST_NDIS_BUFFER(Request),
                        0,
                        &REQUEST_INFORMATION(Request));

                } else {

                    REQUEST_INFORMATION(Request) = 0;
                    REQUEST_STATUS(Request) = STATUS_ADAPTER_HARDWARE_ERROR;

                }

                if (Request != LastRequest) {

                    IPX_INSERT_TAIL_LIST(
                        &Adapter->RequestCompletionQueue,
                        REQUEST_LINKAGE(Request),
                        Adapter->DeviceLock);

                }

            }

            //
            // Now free the receive buffer back.
            //

            IPX_PUSH_ENTRY_LIST(
                &Adapter->ReceiveBufferList,
                &Reserved->ReceiveBuffer->PoolLinkage,
                Adapter->DeviceLock);

            Reserved->ReceiveBuffer = NULL;

        }


        //
        // Now free the packet.
        //

        NdisReinitializePacket (NdisPacket);

        if (Reserved->OwnedByAddress) {

            Reserved->Address->ReceivePacketInUse = FALSE;

        } else {

            Device = Adapter->Device;

            IPX_PUSH_ENTRY_LIST(
                &Device->ReceivePacketList,
                &Reserved->PoolLinkage,
                &Device->Lock);

        }


        //
        // We Delay inserting the last request (or the only one)
        // until after we have put the packet back, to keep the
        // address around if needed (the address won't go away
        // until the last address file does, and the address file
        // won't go away until the datagram is completed).
        //

        IPX_INSERT_TAIL_LIST(
            &Adapter->RequestCompletionQueue,
            REQUEST_LINKAGE(LastRequest),
            Adapter->DeviceLock);

        IpxReceiveComplete ((NDIS_HANDLE)Adapter);

        break;

    default:

        Device = Adapter->Device;

        (*Device->UpperDrivers[Reserved->Identifier].TransferDataCompleteHandler)(
            NdisPacket,
            NdisStatus,
            BytesTransferred);

        break;

    }

}   /* IpxTransferDataComplete */


NTSTATUS
IpxTdiReceiveDatagram(
    IN PREQUEST Request
    )

/*++

Routine Description:

    This routine performs the TdiReceiveDatagram request for the transport
    provider. Receive datagrams just get queued up to an address, and are
    completed when a DATAGRAM or DATAGRAM_BROADCAST frame is received at
    the address.

Arguments:

    Irp - I/O Request Packet for this request.

Return Value:

    NTSTATUS - status of operation.

--*/

{

    PADDRESS Address;
    PADDRESS_FILE AddressFile;
    IPX_DEFINE_SYNC_CONTEXT (SyncContext)
    IPX_DEFINE_LOCK_HANDLE (LockHandle)


    //
    // Do a quick check of the validity of the address.
    //

    AddressFile = (PADDRESS_FILE)REQUEST_OPEN_CONTEXT(Request);

    if ((AddressFile->Size != sizeof (ADDRESS_FILE)) ||
        (AddressFile->Type != IPX_ADDRESSFILE_SIGNATURE)) {

        return STATUS_INVALID_HANDLE;
    }

    Address = AddressFile->Address;

    if ((Address == NULL) ||
        (Address->Size != sizeof (ADDRESS)) ||
        (Address->Type != IPX_ADDRESS_SIGNATURE)) {

        return STATUS_INVALID_HANDLE;
    }

    IPX_BEGIN_SYNC (&SyncContext);

    IPX_GET_LOCK (&Address->Lock, &LockHandle);

    if (AddressFile->State != ADDRESSFILE_STATE_OPEN) {

        IPX_FREE_LOCK (&Address->Lock, LockHandle);
        IPX_END_SYNC (&SyncContext);
        return STATUS_INVALID_HANDLE;
    }


    InsertTailList (&AddressFile->ReceiveDatagramQueue, REQUEST_LINKAGE(Request));

    IoSetCancelRoutine (Request, IpxCancelReceiveDatagram);

    if (Request->Cancel) {

        (VOID)RemoveTailList (&AddressFile->ReceiveDatagramQueue);
        IoSetCancelRoutine (Request, (PDRIVER_CANCEL)NULL);
        IPX_FREE_LOCK (&Address->Lock, LockHandle);
        IPX_END_SYNC (&SyncContext);
        return STATUS_CANCELLED;
    }

    IPX_DEBUG (RECEIVE, ("RDG posted on %lx\n", AddressFile));

    IpxReferenceAddressFileLock (AddressFile, AFREF_RCV_DGRAM);

    IPX_FREE_LOCK (&Address->Lock, LockHandle);

    IPX_END_SYNC (&SyncContext);

    return STATUS_PENDING;

}   /* IpxTdiReceiveDatagram */


VOID
IpxCancelReceiveDatagram(
    IN PDEVICE_OBJECT DeviceObject,
    IN PIRP Irp
    )

/*++

Routine Description:

    This routine is called by the I/O system to cancel a receive
    datagram. The datagram is found on the address file's receive
    datagram queue.

    NOTE: This routine is called with the CancelSpinLock held and
    is responsible for releasing it.

Arguments:

    DeviceObject - Pointer to the device object for this driver.

    Irp - Pointer to the request packet representing the I/O request.

Return Value:

    none.

--*/

{

    PLIST_ENTRY p;
    PADDRESS_FILE AddressFile;
    PADDRESS Address;
    PREQUEST Request = (PREQUEST)Irp;
    BOOLEAN Found;
    IPX_DEFINE_LOCK_HANDLE (LockHandle)


    CTEAssert ((REQUEST_MAJOR_FUNCTION(Request) == IRP_MJ_INTERNAL_DEVICE_CONTROL) &&
               (REQUEST_MINOR_FUNCTION(Request) == TDI_RECEIVE_DATAGRAM));

    CTEAssert (REQUEST_OPEN_TYPE(Request) == (PVOID)TDI_TRANSPORT_ADDRESS_FILE);

    AddressFile = (PADDRESS_FILE)REQUEST_OPEN_CONTEXT(Request);
    Address = AddressFile->Address;

    Found = FALSE;

    IPX_GET_LOCK (&Address->Lock, &LockHandle);

    for (p = AddressFile->ReceiveDatagramQueue.Flink;
         p != &AddressFile->ReceiveDatagramQueue;
         p = p->Flink) {

        if (LIST_ENTRY_TO_REQUEST(p) == Request) {

            RemoveEntryList (p);
            Found = TRUE;
            break;
        }
    }

    IPX_FREE_LOCK (&Address->Lock, LockHandle);
    IoReleaseCancelSpinLock (Irp->CancelIrql);

    if (Found) {

        IPX_DEBUG(RECEIVE, ("Cancelled datagram on %lx\n", AddressFile));

        REQUEST_INFORMATION(Request) = 0;
        REQUEST_STATUS(Request) = STATUS_CANCELLED;

        IpxCompleteRequest (Request);
        ASSERT( DeviceObject->DeviceExtension == IpxDevice );
        IpxFreeRequest(IpxDevice, Request);

        IpxDereferenceAddressFile (AddressFile, AFREF_RCV_DGRAM);

    }

}   /* IpxCancelReceiveDatagram */

