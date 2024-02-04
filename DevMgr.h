#ifndef __ICE_DEVMGR_H
#define __ICE_DEVMGR_H
//
#ifdef __cplusplus
extern "C" {
#endif
//
#pragma once
//
#include <windows.h>
#include <Uxtheme.h>
#include <dbt.h>
#include <stdio.h>
#include "util.h"
#include "setup.h"
#include "wdmsetup.h"
#include "syssetup.h"
#include "resource.h"

#pragma comment(lib, "uxtheme.lib")

#ifndef WM_DPICHANGED
#define WM_DPICHANGED 0x02E0
#endif

//
INT_PTR CALLBACK MainDialog(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK InstallDialog(HWND, UINT, WPARAM, LPARAM);
//
void DisableRadioBtn(HWND, const char);
void GetInstallOption(HWND, short *, short *);
char OpenINFFile(const char, char *);
void SetCharSet(const UINT, const UINT);
void DeleteINFFile(const char *);
BOOL EnablePrivilege(LPCTSTR);
BOOL CALLBACK EnumWindowsProc(HWND hwnd, LPARAM lParam);

#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")

//
#ifdef __cplusplus
}
#endif
//
#endif