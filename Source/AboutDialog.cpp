#include "AboutDialog.h"

// --- private: --- --- --- ---

BOOL CAboutDialog::OnInitDialog(HWND hWnd, HWND hwndFocus, LPARAM lParam) {

	HICON hIcon = LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_IP_CALC));
	::SendMessage(hWnd, WM_SETICON, ICON_SMALL, (LPARAM)hIcon);

	return FALSE;
}

VOID CAboutDialog::OnCommand(HWND hWnd, INT id, HWND hwndCtl, UINT codeNotify) {
}

VOID CAboutDialog::OnClose(HWND hWnd) {
	EndDialog(hWnd, NULL);
}

// --- public: --- --- --- ---

CAboutDialog::CAboutDialog(WORD wIntDlgId, HWND hWndParent)
	: IDlg(wIntDlgId, hWndParent) {
}
CAboutDialog::CAboutDialog(WORD wIntDlgId)
	: IDlg(wIntDlgId) {
}
CAboutDialog::~CAboutDialog() {}