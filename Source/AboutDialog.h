#pragma once
#include "DialogManager.h"

class CAboutDialog : public IDialogManager {
private:

	virtual BOOL OnInitDialog(HWND hWnd, HWND hwndFocus, LPARAM lParam) final;
	virtual VOID OnCommand(HWND hWnd, INT id, HWND hwndCtl, UINT codeNotify) final;
	virtual VOID OnClose(HWND hWnd) final;

	explicit CAboutDialog();

public:

	CAboutDialog(WORD wIntDlgId, HWND hWndParent);
	CAboutDialog(WORD wIntDlgId);
	~CAboutDialog();
};