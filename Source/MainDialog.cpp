#include "MainDialog.h"
#include "Subnet.h"


// --- private: --- --- --- ---

BOOL CMainDialog::OnInitDialog(HWND hWnd, HWND hwndFocus, LPARAM lParam) {

	HICON hIcon = LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_IP_CALC));
	::SendMessage(hWnd, WM_SETICON, ICON_SMALL, (LPARAM)hIcon);

	HWND hWndComboBox = GetDlgItem(hWnd, IDC_COMBO_BITMASK);
	for (int i(0); i < 33; i++) {
		_TCHAR tchTmp[3];
		_itow(i, tchTmp, 10);
		::SendMessage(hWndComboBox, (UINT)CB_ADDSTRING, (WPARAM)0, (LPARAM)tchTmp);
	}
	::SendMessage(hWndComboBox, CB_SETCURSEL, (WPARAM)24/*default mask*/, (LPARAM)0);

	HWND hWndIpAddrIn = GetDlgItem(hWnd, IDC_IP_IP_ADDRESS_IN);
	::SendMessage(hWndIpAddrIn, IPM_SETADDRESS, 0L, MAKEIPADDRESS(192, 168, 1, 2)/*default ip*/);

	return FALSE;
}

void CMainDialog::OnCommand(HWND hWnd, int id, HWND hwndCtl, UINT codeNotify) {
	switch (LOWORD(id)) {
	case IDC_BTN_CALCULATE:
	{
		CSubnet netInfo;

		HWND hWndIpAddrIn = GetDlgItem(hWnd, IDC_IP_IP_ADDRESS_IN);		
		::SendMessage(hWndIpAddrIn, IPM_GETADDRESS, 0L, (LPARAM)&netInfo[0]);


		_TCHAR dwBitmaskBuffer[3];

		HWND hWndComboBox = GetDlgItem(hWnd, IDC_COMBO_BITMASK);
		::GetWindowText(hWndComboBox, (LPWSTR)dwBitmaskBuffer, 3);

		netInfo.SetBitMask(_wtoi(dwBitmaskBuffer));
		netInfo.Calculate();


		HWND hWndNetInfo[7];

		for (int i(0); i < 7; i++) {
			hWndNetInfo[i] = GetDlgItem(hWnd, i + IDC_IP_ADDRESS);
			::SendMessage(hWndNetInfo[i], IPM_SETADDRESS, 0L, netInfo[i].Get());
		}

		break;
	}
	case IDC_IP_IP_ADDRESS_IN:
	{
		
	}
	case IDC_COMBO_BITMASK:
	{
		
	}
	}
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