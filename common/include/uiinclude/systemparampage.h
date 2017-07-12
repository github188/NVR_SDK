#ifndef _SYSTEMPARAMPAGE_H_
#define _SYSTEMPARAMPAGE_H_

#include "ui.h"

#define IDC_STATIC_SYSTEMPARAM_DEVICEID			IDD_DIALOG_SYSTEMPARAM+1
#define IDC_STATIC_SYSTEMPARAM_DEVICENAME		IDD_DIALOG_SYSTEMPARAM+2
#define IDC_STATIC_SYSTEMPARAM_DISKFULL			IDD_DIALOG_SYSTEMPARAM+3
#define IDC_STATIC_SYSTEMPARAM_SYSDATE			IDD_DIALOG_SYSTEMPARAM+4
#define IDC_STATIC_SYSTEMPARAM_SYSTIME			IDD_DIALOG_SYSTEMPARAM+5
#define IDC_STATIC_SYSTEMPARAM_KEYBOARDLOCKTIME IDD_DIALOG_SYSTEMPARAM+6
#define IDC_STATIC_SYSTEMPARAM_SWITCHTIME		IDD_DIALOG_SYSTEMPARAM+7
#define IDC_STATIC_SYSTEMPARAM_STATESHOW		IDD_DIALOG_SYSTEMPARAM+8
#define IDC_STATIC_SYSTEMPARAM_VIDEOFORMAT		IDD_DIALOG_SYSTEMPARAM+9
#define IDC_STATIC_SYSTEMPARAM_VGARESOUTION		IDD_DIALOG_SYSTEMPARAM+10

#define IDC_EDIT_SYSTEMPARAM_DEVICEID			IDD_DIALOG_SYSTEMPARAM+11
#define IDC_EDIT_SYSTEMPARAM_DEVICENAME		IDD_DIALOG_SYSTEMPARAM+12
#define IDC_COMBO_SYSTEMPARAM_DISKFULL			IDD_DIALOG_SYSTEMPARAM+13
#define IDC_EDIT_SYSTEMPARAM_SYSDATE			IDD_DIALOG_SYSTEMPARAM+14
#define IDC_EDIT_SYSTEMPARAM_SYSTIME			IDD_DIALOG_SYSTEMPARAM+15
#define IDC_COMBO_SYSTEMPARAM_KEYBOARDLOCKTIME IDD_DIALOG_SYSTEMPARAM+16
#define IDC_COMBO_SYSTEMPARAM_SWITCHTIME		IDD_DIALOG_SYSTEMPARAM+17
#define IDC_CHECK_SYSTEMPARAM_STATESHOW		IDD_DIALOG_SYSTEMPARAM+18
#define IDC_COMBO_SYSTEMPARAM_VIDEOFORMAT		IDD_DIALOG_SYSTEMPARAM+19
#define IDC_COMBO_SYSTEMPARAM_VGARESOUTION		IDD_DIALOG_SYSTEMPARAM+20

#define IDC_BUTTON_SYSTEMPARAM_OK				IDD_DIALOG_SYSTEMPARAM+21
#define IDC_BUTTON_SYSTEMPARAM_CANCEL			IDD_DIALOG_SYSTEMPARAM+22

#define IDC_DATETIME_SYSTEMPARAM_SYSDATE             IDD_DIALOG_SYSTEMPARAM+23
#define IDC_DATETIME_SYSTEMPARAM_SYSTIME             IDD_DIALOG_SYSTEMPARAM+24

BOOL CreateSystemParamPage();
BOOL ShowSystemParamPage();

void OnSystemParamOK(s32 param);
void OnSystemParamCancel(s32 param);

#endif
