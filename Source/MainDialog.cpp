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
		ipField_.at(4).Hide(); staticTextField_.at(4).Hide();
		ipField_.at(5).Hide(); staticTextField_.at(5).Hide(); break;

	default:
		ipField_.at(4).Show(); staticTextField_.at(4).Show();
		ipField_.at(5).Show(); staticTextField_.at(5).Show(); break;
	}

	netInfo_.SetBitMask(ui8Bitmask);
	netInfo_.Calculate();
	RePaint();
}

VOID CMainDialog::InitControls(const HWND &hWnd) {

	groupNetw.Init(hWnd, IDC_GROUP_NETWORK_PARAM);           // - Init Group-network

	staticTextField_.resize(7);                              // - Init Left-column Static Text
	for (UINT i(0); i < staticTextField_.size(); i++)        //
		staticTextField_.at(i).Init(                         //
			hWnd, IDC_STATIC_TEXT_IP_ADDRESS + i);           //

	ipField_.resize(7);                                      // - Init CIpAddress Controls
	for (UINT i(0); i < ipField_.size(); ++i)                //
		ipField_.at(i).Init(hWnd, IDC_IP_ADDRESS + i);       //

	btnReset.Init(hWnd, IDC_BUTTON_RESET);                   // - Init Reset Button

	hWndComboBitmask_ = GetDlgItem(hWnd, IDC_COMBO_BITMASK); // - Init Bitmask Control
	for (int i(0); i < 33; i++) {                            //
		WCHAR tchTmp[3];                                     //
		_itow(i, tchTmp, 10);                                //
		::SendMessage(                                       //
			hWndComboBitmask_, (UINT)CB_ADDSTRING,           //
			(WPARAM)0, (LPARAM)tchTmp);                      //
	}

	ipField_.at(0).SetData(192, 168, 1, 2);                  // - Set ipField_.at(0)  to default value

	::SendMessage(                                           // - Set Bitmask Control to default value
		hWndComboBitmask_, CB_SETCURSEL,                     //
		(WPARAM)24, (LPARAM)0);                              //
}

VOID CMainDialog::LoadLocalization(const HWND &hWnd) {

	groupNetw.SetData(IDS_MAIN_DIALOG_GROUP_NETWORK);        // - SetData Group-network

	for (UINT i(0); i < staticTextField_.size(); i++)        // - SetData Left-column Static Text
		staticTextField_.at(i).SetData(                      //
			IDS_MAIN_DIALOG_STATIC_IP + i);                  //

	btnReset.SetData(IDS_MAIN_DIALOG_BTN_RESET);             // - SetData Reset Button

	
															 
	//  -  TEMP  -   -   -   -   -   -   -   -   -   -   -   -   -
	//  -  It will be implemented as a recursive dynamic of constructing a hierarchy structure of menu items.

	std::vector<std::wstring> vecStrBuffer;

	for (int i(0); i < 3; ++i)
		vecStrBuffer.push_back(FLoadString(IDS_MAIN_DIALOG_MENU_FILE + i * 100));

	HMENU hMenuMain = GetMenu(hWnd);

	for (int i(0); i < 3; i++) {
		MENUITEMINFOW mii = {};
		mii.cbSize = sizeof(mii);
		mii.dwTypeData = const_cast<PWSTR>(vecStrBuffer.at(i).c_str());
		mii.fMask = MIIM_STRING;
		SetMenuItemInfoW(hMenuMain, i, true, &mii);
	}

	//  -  TEMP  -   -   -   -   -   -   -   -   -   -   -   -   -

}


// --- private: --- --- --- ---

BOOL CMainDialog::OnInitDialog(HWND hWnd, HWND hwndFocus, LPARAM lParam) {

	HICON hIcon = LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_MAIN)); // - Load Main Dialog Icon
	::SendMessage(hWnd, WM_SETICON, ICON_SMALL, (LPARAM)hIcon);               //

	::SetWindowText(hWnd, FLoadString(IDS_MAIN_DIALOG_CAPTION));              // - Set Main Dialog caption

	InitControls(hWnd);
	LoadLocalization(hWnd);

	return FALSE;
}

VOID CMainDialog::OnCommand(HWND hWnd, INT id, HWND hwndCtl, UINT codeNotify) {
	switch (LOWORD(id)) {
	case IDC_IP_ADDRESS:    ChangeIp();      break;
	case IDC_COMBO_BITMASK: ChangeBitmask(); break;
	case IDC_BUTTON_RESET:
		ipField_.at(0).SetData(0, 0, 0, 0); ChangeIp();
		::SendMessage(hWndComboBitmask_, CB_SETCURSEL, (WPARAM)0, (LPARAM)0); ChangeBitmask();
		break;
	}
}

VOID CMainDialog::OnClose(HWND hWnd) {
	EndDialog(hWnd, NULL);
}

// --- public: --- --- --- ---

CMainDialog::CMainDialog(const WORD &wDialogId, const HWND &hWndParent)
	: IDialog(wDialogId, hWndParent) {
}

CMainDialog::CMainDialog(const WORD &wDialogId)
	: IDialog(wDialogId) {
}

CMainDialog::~CMainDialog() {}