#include "DialogManager.h"


// --- protected:  --- --- ---

const HINSTANCE &IDialogManager::GetThisHandle() const {
	return hInstance_;
}

const HWND &IDialogManager::GetThisHWnd() const {
	return hWndThis_;
}

BOOL IDialogManager::lpStaticDlgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

	auto it = dlgList.begin();

	// It will be replaced with a message filter
	if (uMsg == WM_INITDIALOG || uMsg == WM_COMMAND || uMsg == WM_CLOSE) {

		while (it != dlgList.end()) {
			if (it->first && !it->second) {
				it->first->hWndThis_ = hWnd;
				it->second = hWnd;
				break;
			}
			++it;
		}
		it = dlgList.begin();

		if (it->second != hWnd) {
			it = dlgList.begin();
			while (it->second != hWnd) ++it;
		}
	}
	switch (uMsg) {
		HANDLE_MSG(hWnd, WM_INITDIALOG, it->first->OnInitDialog);
		HANDLE_MSG(hWnd, WM_COMMAND, it->first->OnCommand);
		HANDLE_MSG(hWnd, WM_CLOSE, it->first->OnClose);
	}
	return FALSE;
}

// --- public: --- --- --- ---

VOID IDialogManager::Run() const {
	DialogBox(hInstance_, lpTemplateName_, hWndParent_, lpDialogProc_);
}

IDialogManager::IDialogManager(const WORD &wDialogId, const HWND &hWndParent) {
	hInstance_      = GetModuleHandle(NULL);
	lpTemplateName_ = MAKEINTRESOURCE(wDialogId);
	hWndParent_     = hWndParent;
	lpDialogProc_   = lpStaticDlgProc;

	dlgList.emplace(this, nullptr);
}

IDialogManager::IDialogManager(const WORD &wDialogId)
	: IDialogManager(wDialogId, nullptr) {
}

IDialogManager::~IDialogManager() {
	auto it = dlgList.find(this);
	dlgList.erase(it);
}