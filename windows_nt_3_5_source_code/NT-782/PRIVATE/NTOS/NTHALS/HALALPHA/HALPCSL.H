/*++ BUILD Version: 0001    // Increment this if a change has global effects

Copyright (c) 1991  Microsoft Corporation
Copyright (c) 1992, 1993  Digital Equipment Corporation

Module Name:

    halpcsl.h

Abstract:

    This header file includes the definitions for standard PC serial
    port UARTs.

    Stolen from jazzserp.h, which is a slightly different chip-
    it has a 16 byte fifo - we are just double buffered.

Author:

    David N. Cutler (davec) 28-Apr-1991
    Miche Baker-Harvey (miche) 01-June-1992


Revision History:

--*/

#ifndef _HALPCSL_
#define _HALPCSL_


//
// Define base port numbers for serial lines inside the combo chip
//

#define COMA_PORT_BASE 0x3f8
#define COMB_PORT_BASE 0x2f8


//
// Define serial port read registers structure.
//

typedef struct _SP_READ_REGISTERS {
    UCHAR ReceiveBuffer;
    UCHAR InterruptEnable;
    UCHAR InterruptId;
    UCHAR LineControl;
    UCHAR ModemControl;
    UCHAR LineStatus;
    UCHAR ModemStatus;
    UCHAR ScratchPad;
} SP_READ_REGISTERS, *PSP_READ_REGISTERS;

//
// Define define serial port write registers structure.
//

typedef struct _SP_WRITE_REGISTERS {
    UCHAR TransmitBuffer;
    UCHAR InterruptEnable;
    UCHAR FifoControl;
    UCHAR LineControl;
    UCHAR ModemControl;
    UCHAR Reserved1;
    UCHAR ModemStatus;
    UCHAR ScratchPad;
} SP_WRITE_REGISTERS, *PSP_WRITE_REGISTERS;

//
// Define serial port interrupt enable register structure.
//

typedef struct _SP_INTERRUPT_ENABLE {
    UCHAR ReceiveEnable : 1;
    UCHAR TransmitEnable : 1;
    UCHAR LineStatusEnable : 1;
    UCHAR ModemStatusEnable : 1;
    UCHAR Reserved1 : 4;
} SP_INTERRUPT_ENABLE, *PSP_INTERRUPT_ENABLE;

//
// Define serial port interrupt id register structure.
//

typedef struct _SP_INTERRUPT_ID {
    UCHAR InterruptPending : 1;
    UCHAR Identification : 3;
    UCHAR Reserved1 : 2;
    UCHAR FifoEnabled : 2;                // always read as 0
} SP_INTERRUPT_ID, *PSP_INTERRUPT_ID;

//
// Define serial port fifo control register structure.
// This register is here for software compatibility, but there is
// no FIFO on the 16C452
//

typedef struct _SP_FIFO_CONTROL {
    UCHAR FifoEnable : 1;
    UCHAR ReceiveFifoReset : 1;
    UCHAR TransmitFifoReset : 1;
    UCHAR DmaModeSelect : 1;
    UCHAR Reserved1 : 2;
    UCHAR ReceiveFifoLevel : 2;
} SP_FIFO_CONTROL, *PSP_FIFO_CONTROL;

//
// Define serial port line control register structure.
//

typedef struct _SP_LINE_CONTROL {
    UCHAR CharacterSize : 2;
    UCHAR StopBits : 1;
    UCHAR ParityEnable : 1;
    UCHAR EvenParity : 1;
    UCHAR StickParity : 1;
    UCHAR SetBreak : 1;
    UCHAR DivisorLatch : 1;
} SP_LINE_CONTROL, *PSP_LINE_CONTROL;

//
// Line status register character size definitions.
//

#define FIVE_BITS 0x0                   // five bits per character
#define SIX_BITS 0x1                    // six bits per character
#define SEVEN_BITS 0x2                  // seven bits per character
#define EIGHT_BITS 0x3                  // eight bits per character

//
// Line speed divisor definition.  We get our baud rate clock
// from the 82C106.
//

#define BAUD_RATE_9600  12              // divisor for 9600 baud
#define BAUD_RATE_19200  6              // divisor for 19200 baud

//
// Define serial port modem control register structure.
//

typedef struct _SP_MODEM_CONTROL {
    UCHAR DataTerminalReady : 1;
    UCHAR RequestToSend : 1;
    UCHAR Reserved1 : 1;
    UCHAR Interrupt : 1;
    UCHAR loopBack : 1;
    UCHAR Reserved2 : 3;
} SP_MODEM_CONTROL, *PSP_MODEM_CONTROL;

//
// Define serial port line status register structure.
//

typedef struct _SP_LINE_STATUS {
    UCHAR DataReady : 1;
    UCHAR OverrunError : 1;
    UCHAR ParityError : 1;
    UCHAR FramingError : 1;
    UCHAR BreakIndicator : 1;
    UCHAR TransmitHoldingEmpty : 1;
    UCHAR TransmitEmpty : 1;
    UCHAR ReceiveFifoError : 1;
} SP_LINE_STATUS, *PSP_LINE_STATUS;

//
// Define serial port modem status register structure.
//

typedef struct _SP_MODEM_STATUS {
    UCHAR DeltaClearToSend : 1;
    UCHAR DeltaDataSetReady : 1;
    UCHAR TrailingRingIndicator : 1;
    UCHAR DeltaReceiveDetect : 1;
    UCHAR ClearToSend : 1;
    UCHAR DataSetReady : 1;
    UCHAR RingIndicator : 1;
    UCHAR ReceiveDetect : 1;
} SP_MODEM_STATUS, *PSP_MODEM_STATUS;

#endif // _HALPCSL_
