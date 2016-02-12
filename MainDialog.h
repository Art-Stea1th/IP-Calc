#pragma once
#include "Dlg.h"

class CMainDialog : public CDlg {
private:

	explicit CMainDialog();

	virtual BOOL OnInitDialog(HWND hWnd, HWND hwndFocus, LPARAM lParam) final;
	virtual void OnCommand(HWND hWnd, int id, HWND hwndCtl, UINT codeNotify) final;
	virtual void OnClose(HWND hWnd) final;

public:	

	CMainDialog(WORD wIntDlgId);
	CMainDialog(WORD wIntDlgId, HINSTANCE hInstance);
	CMainDialog(WORD wIntDlgId, HINSTANCE hInstance, HWND hWndParent);
	~CMainDialog();
};