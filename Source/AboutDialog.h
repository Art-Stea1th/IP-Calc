#pragma once
#include "DialogManager.h"

class CAboutDialog : public IDialogManager {
private: // override

	virtual BOOL OnInitDialog(HWND hWnd, HWND hwndFocus, LPARAM lParam)      override final;
	virtual VOID OnCommand(HWND hWnd, INT id, HWND hwndCtl, UINT codeNotify) override final;
	virtual VOID OnClose(HWND hWnd)                                          override final;

public:

	CAboutDialog(const WORD &wDialogId, const HWND &hWndParent);
	CAboutDialog(const WORD &wDialogId);
	~CAboutDialog();
};