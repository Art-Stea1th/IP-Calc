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

CAboutDialog::CAboutDialog(const WORD &wDialogId, const HWND &hWndParent)
	: IDialogManager(wDialogId, hWndParent) {
}
CAboutDialog::CAboutDialog(const WORD &wDialogId)
	: IDialogManager(wDialogId) {
}
CAboutDialog::~CAboutDialog() {}