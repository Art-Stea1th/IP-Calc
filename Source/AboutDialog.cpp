#include "AboutDialog.h"

// --- private: --- --- --- ---

BOOL CAboutDialog::OnInitDialog(HWND hWnd, HWND hwndFocus, LPARAM lParam) {

	HICON hIcon = LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_MAIN));
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
	: IDialogManager(wIntDlgId, hWndParent) {
}
CAboutDialog::CAboutDialog(WORD wIntDlgId)
	: IDialogManager(wIntDlgId) {
}
CAboutDialog::~CAboutDialog() {}