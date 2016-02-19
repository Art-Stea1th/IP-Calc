#include "ControlsManager.h"


const HWND &IControlsManager::GetThisHWnd() const {
	return hWndThis_;
}

VOID IControlsManager::Show() {
	ShowWindow(hWndThis_, SW_SHOWNA);
}

VOID IControlsManager::Hide() {
	ShowWindow(hWndThis_, SW_HIDE);
}

IControlsManager::IControlsManager(const HWND &hWndParent, const WORD &wControlId) {
	hWndParent_ = hWndParent;
	hWndThis_   = GetDlgItem(hWndParent, wControlId);
}


IControlsManager::~IControlsManager() {}