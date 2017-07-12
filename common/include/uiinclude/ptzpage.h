#ifndef _PTZPAGE_H_
#define _PTZPAGE_H_

#include "ui.h"

#define IDC_STATIC_PTZ_CHNINDEX				IDD_DIALOG_PTZ+1
#define IDC_STATIC_PTZ_ENABLEPRE			IDD_DIALOG_PTZ+2
#define IDC_STATIC_PTZ_PRE					IDD_DIALOG_PTZ+3
#define IDC_STATIC_PTZ_ENABLECRUISE			IDD_DIALOG_PTZ+4
#define IDC_STATIC_PTZ_CRUISE				IDD_DIALOG_PTZ+5
#define IDC_STATIC_PTZ_ENABLETRACK			IDD_DIALOG_PTZ+6

#define IDC_COMBO_PTZ_CHNINDEX				IDD_DIALOG_PTZ+7
#define IDC_CHECK_PTZ_ENABLEPRE				IDD_DIALOG_PTZ+8
#define IDC_EDIT_PTZ_PRE					IDD_DIALOG_PTZ+9
#define IDC_CHECK_PTZ_ENABLECRUISE			IDD_DIALOG_PTZ+10
#define IDC_EDIT_PTZ_CRUISE					IDD_DIALOG_PTZ+11
#define IDC_CHECK_PTZ_ENABLETRACK			IDD_DIALOG_PTZ+12

#define IDC_BUTTON_PTZ_OK					IDD_DIALOG_PTZ+13
#define IDC_BUTTON_PTZ_CANCEL				IDD_DIALOG_PTZ+14

BOOL CreatePTZPage();
BOOL ShowPTZPage();

u8 GetAlarmInputPtzID();
void SetAlarmInputPtzID(u8 id);

#endif
