#pragma once
#include "DialogBase.h"

class CAboutDialog :
	public CDialogBase
{
public:
	CAboutDialog(HINSTANCE hInstance, int nResId, HWND hParent = NULL);
	virtual ~CAboutDialog();

	DECLARE_MESSAGE_MAP
	DECLARE_MESSAGE_HANDLER(On_WM_COMMAND)
};

