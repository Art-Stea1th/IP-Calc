#pragma once
#include "Dlg.h"
#include "Subnet.h"
#include "AboutDialog.h"

class CMainDialog : public IDlg {
private:

	explicit CMainDialog();

	virtual BOOL OnInitDialog(HWND hWnd, HWND hwndFocus, LPARAM lParam) final;
	virtual void OnCommand(HWND hWnd, int id, HWND hwndCtl, UINT codeNotify) final;
	void OnChange();
	virtual void OnClose(HWND hWnd) final;

	CSubnet netInfo_;
	HWND
		hWndIpAddrControl_[7],
		hWndComboBitmask_;

public:	

	CMainDialog(WORD wIntDlgId, HWND hWndParent);
	~CMainDialog();
};