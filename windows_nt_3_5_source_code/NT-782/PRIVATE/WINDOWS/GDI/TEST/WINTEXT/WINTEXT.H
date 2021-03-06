/****************************** Module Header ******************************\
* Module Name: wintext.h
*
* Copyright (c) 1991, Microsoft Corporation
*
* wintext's header file
*
* History:
* 11-21-91 KentD      Created.
* 7-4-92   Gerritv    Added unicode options and checked menu items.
\***************************************************************************/

#include <windows.h>
#include <string.h>

/*
 * Resource defines
 */
#define WINDOWMENU  1

#ifdef RC_INVOKED
#define ID(id) id
#else
#define ID(id) MAKEINTRESOURCE(id)
#endif

/*
 * Menu ID's
 */
#define MM_NEW          8001
#define MM_EXIT         8002
#define MM_ABOUT        8003
#define IDM_STARTTESTS  8004
#define IDM_0		8010
#define IDM_1		8011
#define IDM_2		8012
#define IDM_3		8013
#define IDM_4		8014
#define IDM_5		8015
#define IDM_6		8016
#define IDM_7		8017
#define IDM_8		8018
#define IDM_9		8019
#define IDM_OEMFONT	8020
#define IDM_SYSTEMFONT	8021
#define IDM_TRANSPARENT 8022
#define IDM_OPAQUE	8023
#define IDM_ASCII   8024
#define IDM_UNICODE 8025

