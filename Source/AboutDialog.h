#pragma once
#include "Dlg.h"
class CAboutDialog : public IDlg {
private:

	explicit CAboutDialog();

	virtual BOOL OnInitDialog(HWND hWnd, HWND hwndFocus, LPARAM lParam) final;
	virtual void OnCommand(HWND hWnd, int id, HWND hwndCtl, UINT codeNotify) final;
	virtual void OnClose(HWND hWnd) final;

public:

	CAboutDialog(WORD wIntDlgId);
	CAboutDialog(WORD wIntDlgId, HINSTANCE hInstance);
	CAboutDialog(WORD wIntDlgId, HINSTANCE hInstance, HWND hWndParent);
	~CAboutDialog();
};

