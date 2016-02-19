#include "ControlsManager.h"


IControlsManager::IControlsManager(const HWND &hWndParent, const WORD &wControlId) {
	hWndParent_ = hWndParent;
	hWndThis_   = GetDlgItem(hWndParent, wControlId);
}


IControlsManager::~IControlsManager() {}