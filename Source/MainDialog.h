#pragma once

#include "DialogManager.h"
#include "Subnet.h"

class CMainDialog : public IDialogManager {
private:

	CSubnet netInfo_;
	std::vector<HWND>
		hWndIpAddrControl_;
	HWND hWndComboBitmask_;

private:

	explicit CMainDialog();

	virtual VOID RePaint() final;

	virtual VOID ChangeIp() final;
	virtual VOID ChangeBitmask() final;

	virtual VOID SetIp(const UINT8 &oct1, const UINT8 &oct2, const UINT8 &oct3, const UINT8 &oct4) final;
	virtual VOID SetBitmask(const UINT8 &bitmask) final;

	virtual VOID InitControls(const HWND &hWnd) final;

private:

	virtual BOOL OnInitDialog(HWND hWnd, HWND hwndFocus, LPARAM lParam) final;
	virtual VOID OnCommand(HWND hWnd, INT id, HWND hwndCtl, UINT codeNotify) final;
	virtual VOID OnClose(HWND hWnd) final;

public:	

	CMainDialog(WORD wDialogId, HWND hWndParent);
	CMainDialog(WORD wDialogId);
	~CMainDialog();
};