#ifndef _IMAGEALARMPAGE_H_
#define _IMAGEALARMPAGE_H_

#include "ui.h"

#define IDC_STATIC_IMAGEALARM_RECORDCHN			IDD_DIALOG_IMAGEALARM+1

#define IDC_STATIC_IMAGEALARM_RECORDCHN1		IDD_DIALOG_IMAGEALARM+2
#define IDC_STATIC_IMAGEALARM_RECORDCHN2		IDD_DIALOG_IMAGEALARM+3
#define IDC_STATIC_IMAGEALARM_RECORDCHN3		IDD_DIALOG_IMAGEALARM+4
#define IDC_STATIC_IMAGEALARM_RECORDCHN4		IDD_DIALOG_IMAGEALARM+5

#define IDC_CHECK_IMAGEALARM_RECORDCHN1			IDD_DIALOG_IMAGEALARM+6
#define IDC_CHECK_IMAGEALARM_RECORDCHN2			IDD_DIALOG_IMAGEALARM+7
#define IDC_CHECK_IMAGEALARM_RECORDCHN3			IDD_DIALOG_IMAGEALARM+8
#define IDC_CHECK_IMAGEALARM_RECORDCHN4			IDD_DIALOG_IMAGEALARM+9

#define IDC_STATIC_IMAGEALARM_SOUNDALARM		IDD_DIALOG_IMAGEALARM+10
#define IDC_STATIC_IMAGEALARM_CENTER			IDD_DIALOG_IMAGEALARM+11
#define IDC_STATIC_IMAGEALARM_OUT				IDD_DIALOG_IMAGEALARM+12

#define IDC_STATIC_IMAGEALARM_OUT1				IDD_DIALOG_IMAGEALARM+13
#define IDC_STATIC_IMAGEALARM_OUT2				IDD_DIALOG_IMAGEALARM+14
#define IDC_STATIC_IMAGEALARM_OUT3				IDD_DIALOG_IMAGEALARM+15
#define IDC_STATIC_IMAGEALARM_OUT4				IDD_DIALOG_IMAGEALARM+16

#define IDC_CHECK_IMAGEALARM_SOUNDALARM			IDD_DIALOG_IMAGEALARM+17
#define IDC_CHECK_IMAGEALARM_CENTER				IDD_DIALOG_IMAGEALARM+18
#define IDC_CHECK_IMAGEALARM_OUT				IDD_DIALOG_IMAGEALARM+19

#define IDC_CHECK_IMAGEALARM_OUT1				IDD_DIALOG_IMAGEALARM+20
#define IDC_CHECK_IMAGEALARM_OUT2				IDD_DIALOG_IMAGEALARM+21
#define IDC_CHECK_IMAGEALARM_OUT3				IDD_DIALOG_IMAGEALARM+22
#define IDC_CHECK_IMAGEALARM_OUT4				IDD_DIALOG_IMAGEALARM+23

#define IDC_BUTTON_IMAGEALARM_OK				IDD_DIALOG_IMAGEALARM+24
#define IDC_BUTTON_IMAGEALARM_CANCEL			IDD_DIALOG_IMAGEALARM+25

BOOL CreateImagealarmPage();
BOOL ShowImagealarmPage();

u8 GetImagealarmChn();
void SetImagealarmChn(u8 id);

#endif
