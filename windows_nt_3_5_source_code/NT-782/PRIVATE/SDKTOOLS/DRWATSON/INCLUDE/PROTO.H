/*++

Copyright (c) 1993  Microsoft Corporation

Module Name:

    proto.h

Abstract:

    Prototypes for drwatson.

Author:

    Wesley Witt (wesw) 1-May-1993

Environment:

    User Mode

--*/

#include <imagehlp.h>

// error.c
void NonFatalError(char *format, ...);
void FatalError(char *format, ...);
void AssertError( char *exp, char * file, DWORD line );
void dprintf(char *format, ...);

//log.c
void OpenLogFile( char *szFileName, BOOL fAppend, BOOL fVisual );
void CloseLogFile( void );
void lprintfs(char *format, ...);
void lprintf(DWORD dwFormatId, ...);
void MakeLogFileName( char *szName );
char * GetLogFileData( LPDWORD dwLogFileDataSize );

// walk.c
LPVOID SwFunctionTableAccess( HANDLE  hProcess, DWORD   dwPCAddr );
DWORD  SwGetModuleBase( HANDLE  hProcess, DWORD   ReturnAddress );
BOOL   SwReadProcessMemory( HANDLE  hProcess, LPCVOID lpBaseAddress, LPVOID  lpBuffer, DWORD   nSize, LPDWORD lpNumberOfBytesRead );
DWORD  SwTranslateAddress( HANDLE    hProcess, HANDLE    hThread, LPADDRESS lpaddr );

// regs.c
void   OutputAllRegs(PDEBUGPACKET dp);
ULONG  GetRegValue(PDEBUGPACKET dp, ULONG regnum);
ULONG GetRegFlagValue (PDEBUGPACKET dp, ULONG regnum);

// disasm.c
BOOLEAN disasm( PDEBUGPACKET dp, PULONG pOffset, PUCHAR pchDst, BOOLEAN fEAout );

// symbols.c
BOOL LoadCodeViewSymbols(PMODULEINFO mi, PUCHAR pCvData, DWORD dwSize, PIMAGE_SECTION_HEADER sectionHdrs, DWORD numSections);
BOOL LoadCoffSymbols( PMODULEINFO mi, PUCHAR stringTable, PIMAGE_SYMBOL allSymbols, DWORD numberOfSymbols);
BOOL LoadExceptionData( PMODULEINFO mi, PRUNTIME_FUNCTION start, DWORD size);
BOOL LoadFpoData( PMODULEINFO mi, PFPO_DATA start, DWORD size );
BOOL LoadOmap( PMODULEINFO mi, POMAP start, DWORD size, DWORD OmapType );
PSYMBOL GetSymFromAddr( DWORD dwAddr, PDWORD pdwDisplacement, PMODULEINFO mi);
void DumpSymbols( PDEBUGPACKET dp );
PMODULEINFO GetModuleForPC( PDEBUGPACKET dp, DWORD dwPcAddr );
PSYMBOL GetSymFromAddrAllContexts( DWORD dwAddr, PDWORD pdwDisplacement, PDEBUGPACKET dp );
POMAP GetOmapEntry(PMODULEINFO mi, DWORD addr);
DWORD ConvertOmapToSrc(PMODULEINFO mi, DWORD addr, LPDWORD bias);
DWORD ConvertOmapFromSrc(PMODULEINFO mi, DWORD addr, LPDWORD bias);
VOID ProcessOmapForModule(PMODULEINFO mi);

// module.c
BOOL ProcessModuleLoad ( PDEBUGPACKET dp, LPDEBUG_EVENT de );

// debug.c
DWORD DispatchDebugEventThread( PDEBUGPACKET dp );
DWORD TerminationThread( PDEBUGPACKET dp );
BOOL  DoMemoryRead(PDEBUGPACKET dp, LPCVOID addr, LPVOID buf, DWORD size, LPDWORD lpcb);

// registry.c
BOOL RegInitialize( POPTIONS o );
BOOL RegSave( POPTIONS o );
DWORD RegGetNumCrashes( void );
void RegSetNumCrashes( DWORD dwNumCrashes );
void RegLogCurrentVersion( void );
BOOLEAN RegInstallDrWatson( BOOL fQuiet );

// eventlog.c
BOOL ElSaveCrash( PCRASHES crash, DWORD dwNumCrashes );
BOOL ElEnumCrashes( PCRASHINFO crashInfo, CRASHESENUMPROC lpEnumFunc );
BOOL ElClearAllEvents( void );

// undname.c
LPSTR UnDName( PSYMBOL psym );

// process.c
void LogTaskList( void );
void LogProcessInformation( HANDLE hProcess );
void GetTaskName( ULONG pid, char *szTaskName, LPDWORD pdwSize );

// context.c
void GetContextForThread( PDEBUGPACKET dp );

// browse.c
BOOL BrowseForDirectory( char *szCurrDir );
BOOL GetWaveFileName( char *szWaveName );

// notify.c
void NotifyWinMain ( void );
BOOLEAN GetCommandLineArgs( LPDWORD dwPidToDebug, LPHANDLE hEventToSignal );

// ui.c
void DrWatsonWinMain ( void );

// util.c
void GetAppName( char *pszAppName, DWORD len );
void GetHelpFileName( char *pszHelpFileName, DWORD len );
char * LoadRcString( UINT wId );

// controls.c
BOOL SubclassControls( HWND hwnd );
void SetFocusToCurrentControl( void );
