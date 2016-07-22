#include "stdafx.h"
#include "AboutDialog.h"


CAboutDialog::CAboutDialog(HINSTANCE hInstance, int nResId, HWND hParent) : CDialogBase(hInstance, nResId, hParent)
{
}


CAboutDialog::~CAboutDialog()
{
}


BEGIN_MESSAGE_MAP(CAboutDialog)
	ADD_MESSAGE_HANDLER(WM_COMMAND, On_WM_COMMAND)
END_MESSAGE_MAP


BOOL CAboutDialog::On_WM_COMMAND(HWND hDlg, WPARAM wParam, LPARAM lParam)
{
	switch (LOWORD(wParam))	{

		case IDOK:
			OnOK();
			break;

		case IDCANCEL:
			OnCancel();
			break;
	}

	return TRUE;
}