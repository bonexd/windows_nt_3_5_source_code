/*++

Copyright (c) 1990  Microsoft Corporation

Module Name:

    mac2hex.c

Abstract:

    This program will read in MAC.BIN and produce MACBIN.H.  MACBIN.H
    will consist of a character array representation (MacBinImage[])
    of MAC.BIN.

Author:

    Keith Moore (KeithMo) 23-Jan-1991

Environment:

    OS/2 1.x/2.x Protected Mode

Revision History:


--*/

#define INCL_BASE
#include <os2.h>

#include <stdio.h>
#include <stdlib.h>


//
// Macros
//
#define CHECK_RETURN(code)                                              \
{                                                                       \
    if ((code) != NO_ERROR) {                                           \
        printf(                                                         \
            "Error %d, File %s, Line %ld\n",                            \
            (code),                                                     \
            __FILE__,                                                   \
            (long)__LINE__                                              \
        );                                                              \
        exit(1);                                                        \
    }                                                                   \
}


//
// Prototypes
//
int
main(
    int nArgc,
    char *pArgv[]
    );

VOID
CreateHeaderFile(
    PUCHAR pBuffer,
    USHORT usLength
    );


//
// main
//
int
main(
    int nArgc,
    char *pArgv[]
    )

/*++

Routine Description:

    Usual C entry point.

Arguments:

    nArgc - Count of command line arguments.
    pArgv - Array of pointers to the command line arguments.

Return Value:

    0 if everything went OK.
    1 if something horrible happened.

--*/

{

    FILESTATUS  FileStatus;
    HFILE       hFile;
    PCHAR       pFileName;
    PVOID       pBuffer;
    SEL         Selector;
    USHORT      usAction;
    USHORT      usFileSize;
    USHORT      usNumRead;
    USHORT      usResult;

    //
    // If no command line arguments are given, then
    // use "MAC.BIN" for the input file.  Otherwise,
    // assume that the first (only?) argument is the
    // name of the download file.
    //

    pFileName = (nArgc > 1) ? (PCHAR)pArgv[1] : (PCHAR)"MAC.BIN";

    //
    // Open MAC.BIN.
    //

    usResult = DosOpen(
                    pFileName,
                    &hFile,
                    &usAction,
                    0L,
                    FILE_NORMAL,
                    FILE_OPEN,
                    OPEN_ACCESS_READONLY
                        | OPEN_SHARE_DENYNONE,
                    0L
                    );
    CHECK_RETURN(usResult);

    //
    // Query the file so we can retrive its length.
    //

    usResult = DosQFileInfo(
                    hFile,
                    FIL_STANDARD,
                    (PBYTE)&FileStatus,
                    sizeof(FILESTATUS)
                    );
    CHECK_RETURN(usResult);

    usFileSize = (USHORT)FileStatus.cbFile;

    //
    // Allocate a chunk of memory to use.
    //

    usResult = DosAllocSeg(
                    usFileSize,
                    &Selector,
                    SEG_NONSHARED
                    );
    CHECK_RETURN(usResult);

    //
    // Build our pointer from the selector we just allocated.
    //

    pBuffer = MAKEP(Selector, 0);

    //
    // Read MAC.BIN into our buffer.
    //

    usResult = DosRead(
                    hFile,
                    pBuffer,
                    usFileSize,
                    &usNumRead
                    );
    CHECK_RETURN(usResult);

    //
    // Close MAC.BIN.
    //

    usResult = DosClose(
                    hFile
                    );
    CHECK_RETURN(usResult);

    //
    // Write the new file.
    //
    CreateHeaderFile(pBuffer, usFileSize);

    //
    // Free the allocated memory.
    //
    usResult = DosFreeSeg(
                    Selector
                    );
    CHECK_RETURN(usResult);

    return 0;

}


//
// CreateHeaderFile
//
VOID
CreateHeaderFile(
    PUCHAR pBuffer,
    USHORT usLength
    )

/*++

Routine Description:

    Create a C header file containing a character
    array representation of the specified buffer.

Arguments:

    pBuffer - Pointer to the buffer to convert.

    usLength - The length (in bytes) of the buffer.

Return Value:

    None.

--*/

{

    //
    // TRUE if we're starting a new line.
    //
    BOOL fNewLine;

    //
    // Number of bytes on current line.
    //
    USHORT usNumBytes;

    //
    // Create the prologue
    //

    printf("/*++\n");
    printf("\n");
    printf("Copyright (c) 1990  Microsoft Corporation\n");
    printf("\n");
    printf("Module Name:\n");
    printf("\n");
    printf("    macbin.h\n");
    printf("\n");
    printf("Abstract:\n");
    printf("\n");
    printf("    This module is generated by MAC2HEX.EXE.  MAC2HEX reads in the\n");
    printf("    NE3200's MAC.BIN module and produces this C character array\n");
    printf("    representation.  This is an unfortunate artifact of having\n");
    printf("    all device drivers linked into the kernel.  Once we have real\n");
    printf("    installable device drivers, this will be unnecessary (the\n");
    printf("    NE3200 driver will just open MAC.BIN and read it).  But for now,\n");
    printf("    all device drivers get initialized *before* the filesystem.\n");
    printf("    Ergo, device drivers cannot open files at initialization time.\n");
    printf("\n");
    printf("Author:\n");
    printf("\n");
    printf("    Keith Moore (KeithMo) 24-Jan-1991\n");
    printf("\n");
    printf("Environment:\n");
    printf("\n");
    printf("    Kernel Mode - Or whatever is the equivalent on OS/2 and DOS.\n");
    printf("\n");
    printf("Revision History:\n");
    printf("\n");
    printf("\n");
    printf("--*/\n");
    printf("\n");
    printf("#define NE3200_MACBIN_LENGTH %u\n", usLength);
    printf("\n");
    printf("UCHAR NE3200MacBinImage[] = {");

    fNewLine = TRUE;

    while(usLength--) {

        if (fNewLine) {

            printf("\n");
            printf("            ");
            fNewLine   = FALSE;
            usNumBytes = 0;

        }

        printf("0x%02X", (UINT)(*pBuffer++));

        if (usLength > 0)
            printf(",");

        if (++usNumBytes >= 13)
            fNewLine = TRUE;

    }

    printf("\n");
    printf("            };\n");

}
