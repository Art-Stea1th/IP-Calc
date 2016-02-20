#include "MainDialog.h"


// --- private: --- --- --- ---

VOID CMainDialog::RePaint() {
	for (UINT i(1); i < ipField_.size(); i++)
		ipField_.at(i).SetData(netInfo_[i].Get());
}

VOID CMainDialog::ChangeIp() {

	netInfo_[0] = ipField_.at(0).GetData();
	netInfo_.Calculate();
	RePaint();
}

VOID CMainDialog::ChangeBitmask() {

	TCHAR tChBitmaskBuffer[3];
	::GetWindowText(hWndComboBitmask_, (PWSTR)tChBitmaskBuffer, 3);
	UINT8 ui8Bitmask(_wtoi(tChBitmaskBuffer));

	switch (ui8Bitmask) {
	case 31:
	case 32:
		ipField_.at(4).Hide();
		ipField_.at(5).Hide(); break;

	default:
		ipField_.at(4).Show();
		ipField_.at(5).Show(); break;
	}

	netInfo_.SetBitMask(ui8Bitmask);
	netInfo_.Calculate();
	RePaint();
}

VOID CMainDialog::SetIp(const UINT8 &oct1, const UINT8 &oct2, const UINT8 &oct3, const UINT8 &oct4) {
	ipField_.at(0).SetData(oct1, oct2, oct3, oct4);
	ChangeIp();
}

VOID CMainDialog::SetBitmask(const UINT8 &bitmask) {
	::SendMessage(hWndComboBitmask_, CB_SETCURSEL, (WPARAM)bitmask, (LPARAM)0);
	ChangeBitmask();
}

VOID CMainDialog::InitControls(const HWND &hWnd) {

	// Init CIpAddress Controls

	ipField_.resize(7);

	for (UINT i(0); i < ipField_.size(); ++i)
		ipField_.at(i).Init(hWnd, IDC_IP_ADDRESS + i, 0, 0, 0, 0);

	// Init Bitmask Control

	hWndComboBitmask_ = GetDlgItem(hWnd, IDC_COMBO_BITMASK);

	for (int i(0); i < 33; i++) {
		WCHAR tchTmp[3];
		_itow(i, tchTmp, 10);
		::SendMessage(hWndComboBitmask_, (UINT)CB_ADDSTRING, (WPARAM)0, (LPARAM)tchTmp);
	}

	// Set CIpAddress Control at(0) and Bitmask Control to default value

	ipField_.at(0).SetData(192, 168, 1, 2); SetBitmask(24);
}

VOID CMainDialog::LoadLocalization(const HWND &hWnd) {

	::SetWindowText(hWnd, FLoadString(IDS_MAIN_DIALOG_CAPTION));

	staticTextField_.resize(7);

	for (UINT i(0); i < staticTextField_.size(); i++)
		staticTextField_.at(i).Init(hWnd, IDC_STATIC_TEXT_IP_ADDRESS + i, IDS_MAIN_DIALOG_STATIC_IP + i);

	HWND hWndBtnReset = GetDlgItem(hWnd, IDS_MAIN_DIALOG_BTN_RESET);
	::SetWindowText(hWndBtnReset, FLoadString(IDS_MAIN_DIALOG_BTN_RESET));
}


// --- private: --- --- --- ---

BOOL CMainDialog::OnInitDialog(HWND hWnd, HWND hwndFocus, LPARAM lParam) {

	HICON hIcon = LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_MAIN));
	::SendMessage(hWnd, WM_SETICON, ICON_SMALL, (LPARAM)hIcon);


	LoadLocalization(hWnd);
	InitControls(hWnd);

	return FALSE;
}

VOID CMainDialog::OnCommand(HWND hWnd, INT id, HWND hwndCtl, UINT codeNotify) {
	switch (LOWORD(id)) {
	case IDC_IP_ADDRESS:    ChangeIp();      break;
	case IDC_COMBO_BITMASK: ChangeBitmask(); break;
	case IDC_BUTTON_RESET:
		ipField_.at(0).SetData(0, 0, 0, 0);
		SetBitmask(0);
		break;
	}
}

VOID CMainDialog::OnClose(HWND hWnd) {
	EndDialog(hWnd, NULL);
}

// --- public: --- --- --- ---

CMainDialog::CMainDialog(const WORD &wDialogId, const HWND &hWndParent)
	: IDialogManager(wDialogId, hWndParent) {
}

CMainDialog::CMainDialog(const WORD &wDialogId)
	: IDialogManager(wDialogId) {
}

CMainDialog::~CMainDialog() {}