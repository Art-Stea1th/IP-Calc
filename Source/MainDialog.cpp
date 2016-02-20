#include "MainDialog.h"


// --- private: --- --- --- ---

VOID CMainDialog::RePaint() {
	for (auto i(1); i < hWndIpAddrControl_.size(); i++)
		::SendMessage(hWndIpAddrControl_.at(i), IPM_SETADDRESS, (WPARAM)0, (LPARAM)netInfo_[i].Get());
}

VOID CMainDialog::ChangeIp() {
	
	::SendMessage(hWndIpAddrControl_.at(0), IPM_GETADDRESS, (WPARAM)0, (LPARAM)&netInfo_[0]);
	netInfo_.Calculate();
	RePaint();
}

VOID CMainDialog::ChangeBitmask() {

	TCHAR tChBitmaskBuffer[3];
	::GetWindowText(hWndComboBitmask_, (LPTSTR)tChBitmaskBuffer, 3);
	UINT8 ui8Bitmask(_ttoi(tChBitmaskBuffer));

	switch (ui8Bitmask) {
	case 31:
		ShowWindow(hWndIpAddrControl_.at(4), SW_SHOWNA);
		ShowWindow(hWndIpAddrControl_.at(5), SW_HIDE);
		break;
	case 32:
		ShowWindow(hWndIpAddrControl_.at(4), SW_HIDE);
		ShowWindow(hWndIpAddrControl_.at(5), SW_HIDE);
		break;
	default:
		ShowWindow(hWndIpAddrControl_.at(4), SW_SHOWNA);
		ShowWindow(hWndIpAddrControl_.at(5), SW_SHOWNA);
		break;
	}
	netInfo_.SetBitMask(ui8Bitmask);
	netInfo_.Calculate();
	RePaint();
}

VOID CMainDialog::SetIp(const UINT8 &oct1, const UINT8 &oct2, const UINT8 &oct3, const UINT8 &oct4) {
	::SendMessage(hWndIpAddrControl_.at(0), IPM_SETADDRESS, (WPARAM)0, MAKEIPADDRESS(oct1, oct2, oct3, oct4));
	ChangeIp();
}

VOID CMainDialog::SetBitmask(const UINT8 &bitmask) {
	::SendMessage(hWndComboBitmask_, CB_SETCURSEL, (WPARAM)bitmask, (LPARAM)0);
	ChangeBitmask();
}

VOID CMainDialog::InitControls(const HWND &hWnd) {

	hWndIpAddrControl_.resize(7);

	for (auto i(0); i < hWndIpAddrControl_.size(); ++i)
		hWndIpAddrControl_.at(i) = GetDlgItem(hWnd, i + IDC_IP_ADDRESS);

	hWndComboBitmask_ = GetDlgItem(hWnd, IDC_COMBO_BITMASK);

	for (auto i(0); i < 33; i++) {
		TCHAR tchTmp[3];
		_itot(i, tchTmp, 10);
		::SendMessage(hWndComboBitmask_, (UINT)CB_ADDSTRING, (WPARAM)0, (LPARAM)tchTmp);
	}

	SetIp(192, 168, 1, 2); SetBitmask(24);
}

// --- private: --- --- --- ---

BOOL CMainDialog::OnInitDialog(HWND hWnd, HWND hwndFocus, LPARAM lParam) {

	HICON hIcon = LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_MAIN));
	::SendMessage(hWnd, WM_SETICON, ICON_SMALL, (LPARAM)hIcon);
	
	::SetWindowText(hWnd, FLoadString(IDS_MAIN_DIALOD_CAPTION));
	InitControls(hWnd);

	return FALSE;
}

VOID CMainDialog::OnCommand(HWND hWnd, INT id, HWND hwndCtl, UINT codeNotify) {
	switch (LOWORD(id)) {
	case IDC_IP_ADDRESS:    ChangeIp();                       break;
	case IDC_COMBO_BITMASK: ChangeBitmask();                  break;
	case IDC_BUTTON_RESET:  SetIp(0, 0, 0, 0); SetBitmask(0); break;
	}
}

VOID CMainDialog::OnClose(HWND hWnd) {
	EndDialog(hWnd, NULL);
}

// --- public: --- --- --- ---

CMainDialog::CMainDialog(const WORD &wDialogId, const HWND &hWndParent)
	: IDialogManager(wDialogId, hWndParent) {}

CMainDialog::CMainDialog(const WORD &wDialogId)
	: IDialogManager(wDialogId) {}

CMainDialog::~CMainDialog() {}