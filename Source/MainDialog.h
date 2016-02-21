#pragma once

#include "Subnet.h"
#include "Dialog.h"
#include "Static.h"
#include "IpAddressControl.h"

class CMainDialog : public IDialog {
private:

	CSubnet                        netInfo_;
	std::vector<CIpAddressControl> ipField_;
	std::vector<CStatic>           staticTextField_;

	CStatic groupNetw, btnReset;

	HWND hWndComboBitmask_;

private:

	virtual VOID RePaint() final;

	virtual VOID ChangeIp() final;
	virtual VOID ChangeBitmask() final;

	virtual VOID InitControls(const HWND &hWnd) final;
	virtual VOID LoadLocalization(const HWND &hWnd) final;

private:

	virtual BOOL OnInitDialog(HWND hWnd, HWND hwndFocus, LPARAM lParam)      override final;
	virtual VOID OnCommand(HWND hWnd, INT id, HWND hwndCtl, UINT codeNotify) override final;
	virtual VOID OnClose(HWND hWnd)                                          override final;

public:

	CMainDialog(const WORD &wDialogId, const HWND &hWndParent);
	CMainDialog(const WORD &wDialogId);
	~CMainDialog();
};