#include "Dlg.h"

// --- public: --- --- --- ---

BOOL IDlg::Run() {
	//DialogParam* dlgParam;
	//CreateDialogParam(hInstance_, lpTemplateName_, hWndParent_, lpDialogProc_, (LPARAM)this);
	//DialogBoxParam(hInstance_, lpTemplateName_, hWndParent_, lpDialogProc_, (LPARAM)this);
	//CreateDialog(hInstance_, lpTemplateName_, hWndParent_, lpDialogProc_);
	DialogBox(hInstance_, lpTemplateName_, hWndParent_, lpDialogProc_);
	return NULL;
}

IDlg::IDlg(WORD wIntDlgId, HWND hWndParent) {
	hInstance_      = GetModuleHandle(NULL);
	lpTemplateName_ = MAKEINTRESOURCE(wIntDlgId);
	hWndParent_     = hWndParent;
	lpDialogProc_   = lpDlgProc;

	std::pair<IDlg*, HWND> p;
	p.first = this;
	p.second = nullptr;
	dlgList.insert(p);
}

IDlg::~IDlg() {
	std::map<IDlg*, HWND>::iterator it;
	it = dlgList.find(this);
	dlgList.erase(it);

	lpDialogProc_   = nullptr;
	hWndParent_     = nullptr;
	lpTemplateName_ = nullptr;
	hInstance_      = nullptr;
}

// --- static: --- --- --- ---

BOOL IDlg::lpDlgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

	std::map<IDlg*, HWND>::iterator it;

	// It will be replaced with a message map
	if (uMsg == WM_INITDIALOG || uMsg == WM_COMMAND || uMsg == WM_CLOSE) {

		for (it = dlgList.begin(); it != dlgList.end(); it++)
			if (it->first)
				if (!it->second) {
					it->second = hWnd;
					break;
				}
		it = dlgList.begin();

		if (it->second != hWnd) {
			it = dlgList.begin();
			while (it->second != hWnd) it++;
		}
	}

	switch (uMsg) {
		HANDLE_MSG(hWnd, WM_INITDIALOG, it->first->OnInitDialog);
		HANDLE_MSG(hWnd, WM_COMMAND, it->first->OnCommand);
		HANDLE_MSG(hWnd, WM_CLOSE, it->first->OnClose);
	}

	return FALSE;
}