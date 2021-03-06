/****************************************************************************
Copyright(c) Maynard, an Archive Company. 1991

     Name:          OMHELPIDS.H

     Description:   This header file contains helpids for the
                    help manager.

     $Log:   G:/UI/LOGFILES/OMHELPID.H_V  $

   Rev 1.13   26 Mar 1993 13:36:06   DARRYLP
New IDS for Font, Format.

   Rev 1.12   25 Mar 1993 15:49:38   ROBG
Added IDH_MENU_OPERATIONSFORMAT to list to support the help
with the new menu option.

   Rev 1.9   12 Mar 1993 13:48:32   ROBG
Changes to support font, split catalog, and drive tape windows.

   Rev 1.7   22 Oct 1992 09:39:22   GLENN
Found another incomplete ID change.

   Rev 1.6   20 Oct 1992 16:54:00   GLENN
You gotta change ribbon to toolbar in both places, Steve.

   Rev 1.5   05 Oct 1992 10:36:08   STEVEN
additions from peggy

   Rev 1.4   04 Oct 1992 19:48:26   DAVEV
UNICODE AWK PASS

   Rev 1.3   03 Sep 1992 16:15:52   ROBG
Added OPERATIONSCATALOG for Peggy at Microsoft.

   Rev 1.2   11 Jun 1992 11:00:04   GLENN
Removed MEMORYTRACE references.

   Rev 1.1   10 Jun 1992 16:12:48   GLENN
Updated according to NT SPEC.

   Rev 1.0   03 Mar 1992 12:25:28   DAVEV
Initial revision.
****************************************************************************/

#ifndef helpids_h     // Do not allow multiple inclusions of this file
#define helpids_h


#define IDH_MINIMIZE_ICON             1     // Minimize button on frame
#define IDH_MAXIMIZE_ICON             2     // Maximize button on frame
#define IDH_SYSTEM_MENU               3     // System menu frame
#define IDH_TITLE_BAR                 4     // Title bar on frame
#define IDH_SIZING_BORDER             5     // Frame Border
#define IDH_FRAME_WINDOW              6     // Frame Window
#define IDH_STATUSLINE                7     // Status Bar
#define IDH_CLIENT_WINDOW             8     // MDI Client Window
#define IDH_DOC_WINDOW                9     // MDI Document Window
#define IDH_RIBBON_WINDOW             10    // Tool Bar

// MDI DOCUMENTS

#define IDH_MDI_DISKS                 20
#define IDH_MDI_TAPES                 21
#define IDH_MDI_DISKTREE              22
#define IDH_MDI_TAPETREE              23

// These processed on a "listbox" control.
// begin

#define IDH_LB_DISKTREELEFT           50
#define IDH_LB_DISKTREERIGHT          51
#define IDH_LB_TAPETREELEFT           52
#define IDH_LB_TAPETREERIGHT          53

// end

#define IDH_MENU_OPERATIONSBACKUP     100
#define IDH_MENU_OPERATIONSRESTORE    102
#define IDH_MENU_OPERATIONSERASE      103
#define IDH_MENU_OPERATIONSRETENSION  104
#define IDH_MENU_OPERATIONSEJECT      105
#define IDH_MENU_OPERATIONSHARDWARE   106
#define IDH_MENU_OPERATIONSEXIT       107
#define IDH_MENU_OPERATIONSCATALOG    108
#define IDH_MENU_OPERATIONSFORMAT     109

#define IDH_MENU_TREEEXPANDONE        200
#define IDH_MENU_TREEEXPANDBRANCH     201
#define IDH_MENU_TREEEXPANDALL        202
#define IDH_MENU_TREECOLLAPSEBRANCH   203

#define IDH_MENU_VIEWTREEANDDIR       300
#define IDH_MENU_VIEWTREEONLY         301
#define IDH_MENU_VIEWDIRONLY          302
#define IDH_MENU_VIEWNAMEONLY         303
#define IDH_MENU_VIEWALLFILEDETAILS   304
#define IDH_MENU_VIEWSTATUS           305
#define IDH_MENU_VIEWTOOLBAR          306
#define IDH_MENU_VIEWFONT             2410    // Was 307. Microsoft wants the dialog 
#define IDH_MENU_VIEWSPLIT            308  	 

#define IDH_MENU_SELECTCHECK          400
#define IDH_MENU_SELECTUNCHECK        401

#define IDH_MENU_WINDOWSCASCADE       500
#define IDH_MENU_WINDOWSTILE          501
#define IDH_MENU_WINDOWSARRANGEICONS  502
#define IDH_MENU_WINDOWSREFRESH       503
#define IDH_MENU_WINDOWSCLOSEALL      504

#define IDH_MENU_HELPINDEX            900
#define IDH_MENU_HELPKEYBOARD         901
#define IDH_MENU_HELPSEARCH           902
#define IDH_MENU_HELPCOMMANDS         903
#define IDH_MENU_HELPPROCEDURES       904
#define IDH_MENU_HELPUSINGHELP        905
#define IDH_MENU_HELPABOUTNOSTRADOMUS 906

#define IDH_MENU_WINDOWSNAMES         505   // Generic for 1. drives and 2. tapes
#define IDH_SYSMENU                   800   // generic for move, restore, ...

#define IDH_DB_BACKUPSET              3000  // Backup setup
#define IDH_DB_RESTORESET             3010  // Restore setup
#define IDH_DB_ERASE                  3020  // Erase
#define IDH_DB_TENSION                2030  // Retension
#define IDH_DB_STATUS                 2040  // Runtime status for BU and RS
#define IDH_DB_INSERTTAPE             2050  // Insert the specified tape'
#define IDH_DB_INSERTNEXTTAPE         2051  // Insert the next tape in seq.
#define IDH_DB_ABORT                  2060  // Tape operation aborted
#define IDH_DB_TAPEREWOUND            2070  // Tape is rewound
#define IDH_DB_CATNOTAVAILABLE        2080  // Catalog not available
#define IDH_DB_HARDWARESETUP          2090  // Hardware config.
#define IDH_DB_VIEWFONT					  2410  // Font dialog.
#define IDH_DB_FORMAT 					  2415  // Font dialog.
#define IDH_DB_BATCHHELP                       2420  // batch command help


// THE FOLLOWING HELP IDs ARE NOT USED IN THE MICROSOFT NT BACKUP.EXE
// IGNORE THESE.

#define IDH_MDI_MACROS                23
#define IDH_MDI_JOBS                  24
#define IDH_MDI_SERVERS               27
#define IDH_MDI_LOGFILES              28
#define IDH_MDI_DEBUG                 29
#define IDH_MDI_SEARCH                30

#define IDH_LB_SERVERLEFT             54
#define IDH_LB_SERVERRIGHT            55

#define IDH_DB_ABOUT                  2000
#define IDH_DB_SELECTADVANCED         2010
#define IDH_DB_SELECTSAVE             2020
#define IDH_DB_SELECTUSE              2030
#define IDH_DB_SELECTDELETE           2040
#define IDH_DB_ADVRESTORE             2050
#define IDH_DB_JOBEDIT                2060
#define IDH_DB_JOBNEW                 2070
#define IDH_DB_JOBMAINTENANCE         2080
#define IDH_DB_JOBOPTS                2090
#define IDH_DB_JOBSCHEDULE            2100
#define IDH_DB_SCHEDOPTS              2110
#define IDH_DB_SETTINGSOPTIONS        2120
#define IDH_DB_SETTINGSBACKUP         2130
#define IDH_DB_SETTINGSRESTORE        2140
#define IDH_DB_SETTINGSLOGGING        2150
#define IDH_DB_SETTINGSNETWORK        2160
#define IDH_DB_SETTINGSCATALOG        2170
#define IDH_DB_SETTINGSHARDWARE       2180
#define IDH_DB_SETTINGSDEBUG          2190
#define IDH_DB_LOGINPSWD              2200
#define IDH_DB_SEARCHTAPE             2210
#define IDH_DB_PRINTERSETUP           2220
#define IDH_DB_PRINT                  2230
#define IDH_DB_CATMAINT               2240
#define IDH_DB_CATTAPE                2250
#define IDH_DB_TAPEPSWD               2260
#define IDH_DB_LANTAPEPSWD            2270
#define IDH_DB_JOBPROGRAMITEM         2280
#define IDH_DB_VERIFYSET              2310
#define IDH_DB_REENTERPASSWORD        2320
#define IDH_DB_SKIPOPEN               2330
#define IDH_DB_FILEREPLACE            2340
#define IDH_DB_NEXTSET                2380
#define IDH_DB_PWDBPASSWORD           2390
#define IDH_DB_TRANSFER               2400

// Defines for the three topics for the launcher.

#define IDH_LAUNCHMAINSCREEN        2460
#define IDH_LAUNCHRUNDELAY          2470
#define IDH_LAUNCHSCHEDDELAY        2480


//
// THESE ARE THE OLD STYLE DEFINES -- THEY SHOULD HAVE STARTED WITH IDH
//


#define HELPID_MINIMIZE_ICON IDH_MINIMIZE_ICON
#define HELPID_MAXIMIZE_ICON IDH_MAXIMIZE_ICON
#define HELPID_SYSTEM_MENU   IDH_SYSTEM_MENU
#define HELPID_TITLE_BAR     IDH_TITLE_BAR
#define HELPID_SIZING_BORDER IDH_SIZING_BORDER
#define HELPID_FRAME_WINDOW  IDH_FRAME_WINDOW
#define HELPID_STATUSLINE    IDH_STATUSLINE
#define HELPID_CLIENT_WINDOW IDH_CLIENT_WINDOW
#define HELPID_DOC_WINDOW    IDH_DOC_WINDOW
#define HELPID_RIBBON_WINDOW IDH_RIBBON_WINDOW

#define HELPID_DISKS         IDH_MDI_DISKS
#define HELPID_TAPES         IDH_MDI_TAPES
#define HELPID_MACROS        IDH_MDI_MACROS
#define HELPID_JOBS          IDH_MDI_JOBS
#define HELPID_DISKTREE      IDH_MDI_DISKTREE
#define HELPID_TAPETREE      IDH_MDI_TAPETREE
#define HELPID_SERVERS       IDH_MDI_SERVERS
#define HELPID_LOGFILES      IDH_MDI_LOGFILES
#define HELPID_DEBUG         IDH_MDI_DEBUG
#define HELPID_SEARCH        IDH_MDI_SEARCH

// These processed on a "listbox" control.
// begin

#define HELPID_DISKTREELEFT  IDH_LB_DISKTREELEFT
#define HELPID_DISKTREERIGHT IDH_LB_DISKTREERIGHT
#define HELPID_TAPETREELEFT  IDH_LB_TAPETREELEFT
#define HELPID_TAPETREERIGHT IDH_LB_TAPETREERIGHT
#define HELPID_SERVERLEFT    IDH_LB_SERVERLEFT
#define HELPID_SERVERRIGHT   IDH_LB_SERVERRIGHT

// end

#define HELPID_OPERATIONSBACKUP     IDH_MENU_OPERATIONSBACKUP
#define HELPID_OPERATIONSRESTORE    IDH_MENU_OPERATIONSRESTORE
#define HELPID_OPERATIONSCATALOG    IDH_MENU_OPERATIONSCATALOG
#define HELPID_OPERATIONSERASE      IDH_MENU_OPERATIONSERASE
#define HELPID_OPERATIONSRETENSION  IDH_MENU_OPERATIONSRETENSION
#define HELPID_OPERATIONSEJECT      IDH_MENU_OPERATIONSEJECT
#define HELPID_OPERATIONSHARDWARE   IDH_MENU_OPERATIONSHARDWARE
#define HELPID_OPERATIONSEXIT       IDH_MENU_OPERATIONSEXIT
#define HELPID_OPERATIONSFORMAT     IDH_MENU_OPERATIONSFORMAT

#define HELPID_TREEEXPANDONE        IDH_MENU_TREEEXPANDONE
#define HELPID_TREEEXPANDBRANCH     IDH_MENU_TREEEXPANDBRANCH
#define HELPID_TREEEXPANDALL        IDH_MENU_TREEEXPANDALL
#define HELPID_TREECOLLAPSEBRANCH   IDH_MENU_TREECOLLAPSEBRANCH

#define HELPID_VIEWTREEANDDIR       IDH_MENU_VIEWTREEANDDIR
#define HELPID_VIEWTREEONLY         IDH_MENU_VIEWTREEONLY
#define HELPID_VIEWDIRONLY          IDH_MENU_VIEWDIRONLY
#define HELPID_VIEWNAMEONLY         IDH_MENU_VIEWNAMEONLY
#define HELPID_VIEWALLFILEDETAILS   IDH_MENU_VIEWALLFILEDETAILS
#define HELPID_VIEWSTATUS           IDH_MENU_VIEWSTATUS
#define HELPID_VIEWURIBBON          IDH_MENU_VIEWTOOLBAR
#define HELPID_VIEWFONTS            IDH_MENU_VIEWFONT
#define HELPID_VIEWSPLIT            IDH_MENU_VIEWSPLIT

#define HELPID_SELECTCHECK          IDH_MENU_SELECTCHECK
#define HELPID_SELECTUNCHECK        IDH_MENU_SELECTUNCHECK

#define HELPID_WINDOWSCASCADE       IDH_MENU_WINDOWSCASCADE
#define HELPID_WINDOWSTILE          IDH_MENU_WINDOWSTILE
#define HELPID_WINDOWSARRANGEICONS  IDH_MENU_WINDOWSARRANGEICONS
#define HELPID_WINDOWSREFRESH       IDH_MENU_WINDOWSREFRESH
#define HELPID_WINDOWSCLOSEALL      IDH_MENU_WINDOWSCLOSEALL

#define HELPID_HELPINDEX            IDH_MENU_HELPINDEX
#define HELPID_HELPKEYBOARD         IDH_MENU_HELPKEYBOARD
#define HELPID_HELPSEARCH           IDH_MENU_HELPSEARCH
#define HELPID_HELPCOMMANDS         IDH_MENU_HELPCOMMANDS
#define HELPID_HELPPROCEDURES       IDH_MENU_HELPPROCEDURES
#define HELPID_HELPUSINGHELP        IDH_MENU_HELPUSINGHELP
#define HELPID_HELPABOUTNOSTRADOMUS IDH_MENU_HELPABOUTNOSTRADOMUS

#define HELPID_DIALOGABOUT              IDH_DB_ABOUT
#define HELPID_DIALOGSELECTADVANCED     IDH_DB_SELECTADVANCED
#define HELPID_DIALOGSELECTSAVE         IDH_DB_SELECTSAVE
#define HELPID_DIALOGSELECTUSE          IDH_DB_SELECTUSE
#define HELPID_DIALOGSELECTDELETE       IDH_DB_SELECTDELETE
#define HELPID_DIALOGADVRESTORE         IDH_DB_ADVRESTORE
#define HELPID_DIALOGJOBEDIT            IDH_DB_JOBEDIT
#define HELPID_DIALOGJOBNEW             IDH_DB_JOBNEW
#define HELPID_DIALOGJOBMAINTENANCE     IDH_DB_JOBMAINTENANCE
#define HELPID_DIALOGJOBOPTS            IDH_DB_JOBOPTS
#define HELPID_DIALOGJOBSCHEDULE        IDH_DB_JOBSCHEDULE
#define HELPID_DIALOGSCHEDOPTS          IDH_DB_SCHEDOPTS
#define HELPID_DIALOGSETTINGSOPTIONS    IDH_DB_SETTINGSOPTIONS
#define HELPID_DIALOGSETTINGSBACKUP     IDH_DB_SETTINGSBACKUP
#define HELPID_DIALOGSETTINGSRESTORE    IDH_DB_SETTINGSRESTORE
#define HELPID_DIALOGSETTINGSLOGGING    IDH_DB_SETTINGSLOGGING
#define HELPID_DIALOGSETTINGSNETWORK    IDH_DB_SETTINGSNETWORK
#define HELPID_DIALOGSETTINGSCATALOG    IDH_DB_SETTINGSCATALOG
#define HELPID_DIALOGSETTINGSHARDWARE   IDH_DB_SETTINGSHARDWARE
#define HELPID_DIALOGSETTINGSDEBUG      IDH_DB_SETTINGSDEBUG
#define HELPID_DIALOGLOGINPSWD          IDH_DB_LOGINPSWD
#define HELPID_DIALOGSEARCHTAPE         IDH_DB_SEARCHTAPE
#define HELPID_DIALOGPRINTERSETUP       IDH_DB_PRINTERSETUP
#define HELPID_DIALOGPRINT              IDH_DB_PRINT
#define HELPID_DIALOGCATMAINT           IDH_DB_CATMAINT
#define HELPID_DIALOGCATTAPE            IDH_DB_CATTAPE
#define HELPID_DIALOGTAPEPSWD           IDH_DB_TAPEPSWD
#define HELPID_DIALOGLANTAPEPSWD        IDH_DB_LANTAPEPSWD
#define HELPID_DIALOGJOBPROGRAMITEM     IDH_DB_JOBPROGRAMITEM
#define HELPID_DIALOGBACKUPSET          IDH_DB_BACKUPSET
#define HELPID_DIALOGRESTORESET         IDH_DB_RESTORESET
#define HELPID_DIALOGVERIFYSET          IDH_DB_VERIFYSET
#define HELPID_DIALOGREENTERPASSWORD    IDH_DB_REENTERPASSWORD
#define HELPID_DIALOGSKIPOPEN           IDH_DB_SKIPOPEN
#define HELPID_DIALOGFILEREPLACE        IDH_DB_FILEREPLACE
#define HELPID_DIALOGERASE              IDH_DB_ERASE
#define HELPID_DIALOGRUNTIME            IDH_DB_STATUS
#define HELPID_DIALOGTENSION            IDH_DB_TENSION
#define HELPID_DIALOGNEXTSET            IDH_DB_NEXTSET
#define HELPID_DIALOGPWDBPASSWORD       IDH_DB_PWDBPASSWORD
#define HELPID_DIALOGTRANSFER           IDH_DB_TRANSFER
#define HELPID_DIALOGFORMAT             IDH_DB_FORMAT

// Defines for the three topics for the launcher.

#define HELPID_LAUNCHMAINSCREEN         IDH_LAUNCHMAINSCREEN
#define HELPID_LAUNCHRUNDELAY           IDH_LAUNCHRUNDELAY
#define HELPID_LAUNCHSCHEDDELAY         IDH_LAUNCHSCHEDDELAY

#endif

