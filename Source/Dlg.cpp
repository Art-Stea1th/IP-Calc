#include "Dlg.h"

// --- public: --- --- --- ---

BOOL IDlg::Run() {
	return DialogBox(hInstance_, lpTemplate_, hWndParent_, lpDialogFunc_);
}

IDlg::IDlg(WORD wIntDlgId) {
	pDlg          = this;
	lpTemplate_   = MAKEINTRESOURCE(wIntDlgId);
	lpDialogFunc_ = lpDlgProc;
}

IDlg::IDlg(WORD wIntDlgId, HINSTANCE hInstance)
	: IDlg(wIntDlgId) {
	hInstance_    = hInstance;
}

IDlg::IDlg(WORD wIntDlgId, HINSTANCE hInstance, HWND hWndParent)
	: IDlg(wIntDlgId, hInstance) {
	hWndParent_   = hWndParent;
}

IDlg::~IDlg() {
	lpDialogFunc_ = nullptr;
	hWndParent_   = nullptr;
	lpTemplate_   = nullptr;
	hInstance_    = nullptr;
	pDlg          = nullptr;
}

// --- static: --- --- --- ---

IDlg* IDlg::pDlg = nullptr;

BOOL CALLBACK IDlg::lpDlgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
	switch (message) {
		HANDLE_MSG(hWnd, WM_INITDIALOG, pDlg->OnInitDialog);
		HANDLE_MSG(hWnd, WM_COMMAND, pDlg->OnCommand);
		HANDLE_MSG(hWnd, WM_CLOSE, pDlg->OnClose);
	}
	return FALSE;
}