#ifndef _YUNTAICRUISEPAGE_H_
#define _YUNTAICRUISEPAGE_H_

#include "ui.h"

#define IDC_BUTTON_YTCRUISE_START			 IDD_DIALOG_YTCRUISE+1
#define IDC_BUTTON_YTCRUISE_STOP			 IDD_DIALOG_YTCRUISE+2
#define IDC_STATIC_YTCRUISE_PATHNUM			 IDD_DIALOG_YTCRUISE+3
#define IDC_EDIT_YTCRUISE_PATHNUM			 IDD_DIALOG_YTCRUISE+4
#define IDC_STATIC_YTCRUISE_ADDPOS			 IDD_DIALOG_YTCRUISE+5
#define IDC_EDIT_YTCRUISE_ADDPOS			 IDD_DIALOG_YTCRUISE+6
#define IDC_STATIC_YTCRUISE_ADD			 IDD_DIALOG_YTCRUISE+7
#define IDC_STATIC_YTCRUISE_ADDPRESETPOS			 IDD_DIALOG_YTCRUISE+8
#define IDC_EDIT_YTCRUISE_ADDPRESETPOS			 IDD_DIALOG_YTCRUISE+9
#define IDC_BUTTON_YTCRUISE_ADDPOS			 IDD_DIALOG_YTCRUISE+10
#define IDC_STATIC_YTCRUISE_DWELLTIME			 IDD_DIALOG_YTCRUISE+11
#define IDC_EDIT_YTCRUISE_DWELL_TIME			 IDD_DIALOG_YTCRUISE+12
#define IDC_STATIC_YTCRUISE_SPEED			 IDD_DIALOG_YTCRUISE+13

#define IDC_EDIT_YTCRUISE_SPEED			 IDD_DIALOG_YTCRUISE+14
#define IDC_BUTTON_YTCRUISE_ADDOK			 IDD_DIALOG_YTCRUISE+15
#define IDC_STATIC_YTCRUISE_DEL			 IDD_DIALOG_YTCRUISE+16
#define IDC_STATIC_YTCRUISE_DELPOS			 IDD_DIALOG_YTCRUISE+17
#define IDC_EDIT_YTCRUISE_DELPOS			 IDD_DIALOG_YTCRUISE+18
#define IDC_BUTTON_YTCRUISE_DELPOS			 IDD_DIALOG_YTCRUISE+19

#define IDC_BUTTON_YTCRUISE_OK				 IDD_DIALOG_YTCRUISE+20
#define IDC_BUTTON_YTCRUISE_RET			 IDD_DIALOG_YTCRUISE+21

BOOL CreateYunTaiCruisePage();
BOOL ShowYunTaiCruisePage();

#endif
