#include "MainDialog.h"


// --- private: --- --- --- ---

BOOL CMainDialog::OnInitDialog(HWND hWnd, HWND hwndFocus, LPARAM lParam) {

	HICON hIcon = LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_IP_CALC));
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

void CMainDialog::OnCommand(HWND hWnd, int id, HWND hwndCtl, UINT codeNotify) {
	switch (LOWORD(id)) {
	case IDC_IP_ADDRESS:    OnChange(); break;
	case IDC_COMBO_BITMASK: OnChange(); break;
	case IDC_BUTTON_RESET:
		::SendMessage(hWndIpAddrControl_[0], IPM_SETADDRESS, (WPARAM)0, (LPARAM)0);
		::SendMessage(hWndComboBitmask_, CB_SETCURSEL, (WPARAM)0, (LPARAM)0);
		OnChange();
		break;


	case IDC_BUTTON_TEST:
	{
		CAboutDialog aboutDlg(IDD_ABOUT);
		aboutDlg.Run();
	}
	}
}

void CMainDialog::OnChange() {

	::SendMessage(hWndIpAddrControl_[0], IPM_GETADDRESS, 0L, (LPARAM)&netInfo_[0]);

	_TCHAR dwBitmaskBuffer[3];
	::GetWindowText(hWndComboBitmask_, (LPWSTR)dwBitmaskBuffer, 3);

	netInfo_.SetBitMask(_wtoi(dwBitmaskBuffer));
	netInfo_.Calculate();

	for (int i(1); i < 7; i++)
		::SendMessage(hWndIpAddrControl_[i], IPM_SETADDRESS, 0L, netInfo_[i].Get());
}

void CMainDialog::OnClose(HWND hWnd) {
	EndDialog(hWnd, NULL);
}

// --- public: --- --- --- ---

CMainDialog::CMainDialog(WORD wIntDlgId)
	: IDlg(wIntDlgId) {}

CMainDialog::CMainDialog(WORD wIntDlgId, HINSTANCE hInstance)
	: IDlg(wIntDlgId, hInstance) {}

CMainDialog::CMainDialog(WORD wIntDlgId, HINSTANCE hInstance, HWND hWndParent)
	: IDlg(wIntDlgId, hInstance, hWndParent) {}

CMainDialog::~CMainDialog() {}