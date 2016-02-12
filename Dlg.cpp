#include "Dlg.h"

// --- public: --- --- --- ---

BOOL CDlg::Run() {
	return DialogBox(hInstance_, lpTemplate_, hWndParent_, lpDialogFunc_);
}

CDlg::CDlg(WORD wIntDlgId) {
	pDlg          = this;
	lpTemplate_   = MAKEINTRESOURCE(wIntDlgId);
	lpDialogFunc_ = lpDlgProc;
}

CDlg::CDlg(WORD wIntDlgId, HINSTANCE hInstance)
	: CDlg(wIntDlgId) {
	hInstance_    = hInstance;
}

CDlg::CDlg(WORD wIntDlgId, HINSTANCE hInstance, HWND hWndParent)
	: CDlg(wIntDlgId, hInstance) {
	hWndParent_   = hWndParent;
}

CDlg::~CDlg() {
	lpDialogFunc_ = nullptr;
	hWndParent_   = nullptr;
	lpTemplate_   = nullptr;
	hInstance_    = nullptr;
	pDlg          = nullptr;
}

// --- static: --- --- --- ---

CDlg* CDlg::pDlg = nullptr;

BOOL CALLBACK CDlg::lpDlgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
	switch (message) {
		HANDLE_MSG(hWnd, WM_INITDIALOG, pDlg->OnInitDialog);
		HANDLE_MSG(hWnd, WM_COMMAND, pDlg->OnCommand);
		HANDLE_MSG(hWnd, WM_CLOSE, pDlg->OnClose);
	}
	return FALSE;
}