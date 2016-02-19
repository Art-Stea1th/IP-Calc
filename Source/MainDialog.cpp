#include "MainDialog.h"


// --- private: --- --- --- ---

BOOL CMainDialog::OnInitDialog(HWND hWnd, HWND hwndFocus, LPARAM lParam) {

	HICON hIcon = LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_MAIN));
	::SendMessage(hWnd, WM_SETICON, ICON_SMALL, (LPARAM)hIcon);

	for (int i(0); i < 7; i++)
		hWndIpAddrControl_[i] = GetDlgItem(hWnd, i + IDC_IP_ADDRESS);

	hWndComboBitmask_ = GetDlgItem(hWnd, IDC_COMBO_BITMASK);

	for (int i(0); i < 33; i++) {
		_TCHAR tchTmp[3];
		_itow(i, tchTmp, 10);
		::SendMessage(hWndComboBitmask_, (UINT)CB_ADDSTRING, (WPARAM)0, (LPARAM)tchTmp);
	}

	::SendMessage(hWndIpAddrControl_[0], IPM_SETADDRESS, (WPARAM)0,  MAKEIPADDRESS(192, 168, 1, 2));
	::SendMessage(hWndComboBitmask_,     CB_SETCURSEL,   (WPARAM)24, (LPARAM)0);

	return FALSE;
}

VOID CMainDialog::OnCommand(HWND hWnd, INT id, HWND hwndCtl, UINT codeNotify) {
	switch (LOWORD(id)) {
	case IDC_IP_ADDRESS:    OnChange(); break;
	case IDC_COMBO_BITMASK: OnChange(); break;
	case IDC_BUTTON_RESET:
		::SendMessage(hWndIpAddrControl_[0], IPM_SETADDRESS, (WPARAM)0, (LPARAM)0);
		::SendMessage(hWndComboBitmask_,     CB_SETCURSEL,   (WPARAM)0, (LPARAM)0);
		OnChange();
		break;

	case IDC_BUTTON_TEST:
	{
		CAboutDialog aboutDlg(IDD_ABOUT, GetHWndThis());
		aboutDlg.Run();
	}
	}
}

VOID CMainDialog::OnChange() {

	::SendMessage(hWndIpAddrControl_[0], IPM_GETADDRESS, (WPARAM)0, (LPARAM)&netInfo_[0]);

	_TCHAR tChBitmaskBuffer[3];
	::GetWindowText(hWndComboBitmask_, (LPWSTR)tChBitmaskBuffer, 3);
	UINT8 ui8Bitmask(_wtoi(tChBitmaskBuffer));

	switch (ui8Bitmask) {
	case 31:
		ShowWindow(hWndIpAddrControl_[4], SW_SHOWNA);
		ShowWindow(hWndIpAddrControl_[5], SW_HIDE);
		break;
	case 32:
		ShowWindow(hWndIpAddrControl_[4], SW_HIDE);
		ShowWindow(hWndIpAddrControl_[5], SW_HIDE);
		break;
	default:
		ShowWindow(hWndIpAddrControl_[4], SW_SHOWNA);
		ShowWindow(hWndIpAddrControl_[5], SW_SHOWNA);
		break;
	}

	netInfo_.SetBitMask(ui8Bitmask);
	netInfo_.Calculate();

	for (int i(1); i < 7; i++)
		::SendMessage(hWndIpAddrControl_[i], IPM_SETADDRESS, (WPARAM)0, netInfo_[i].Get());
}

VOID CMainDialog::OnClose(HWND hWnd) {
	EndDialog(hWnd, NULL);
}

// --- public: --- --- --- ---

CMainDialog::CMainDialog(WORD wIntDlgId, HWND hWndParent)
	: IDlg(wIntDlgId, hWndParent) {}

CMainDialog::CMainDialog(WORD wIntDlgId)
	: IDlg(wIntDlgId) {}

CMainDialog::~CMainDialog() {}