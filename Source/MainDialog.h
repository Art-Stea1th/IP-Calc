#pragma once
#include "Dlg.h"
#include "Subnet.h"
#include "AboutDialog.h"

class CMainDialog : public IDlg {
private:

	CSubnet netInfo_;
	HWND
		hWndIpAddrControl_[7],
		hWndComboBitmask_;

private:

	virtual BOOL OnInitDialog(HWND hWnd, HWND hwndFocus, LPARAM lParam) final;
	virtual VOID OnCommand(HWND hWnd, INT id, HWND hwndCtl, UINT codeNotify) final;
	virtual VOID OnChange() final;
	virtual VOID OnClose(HWND hWnd) final;

	explicit CMainDialog();

public:	

	CMainDialog(WORD wIntDlgId, HWND hWndParent);
	CMainDialog(WORD wIntDlgId);
	~CMainDialog();
};