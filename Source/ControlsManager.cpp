#include "ControlsManager.h"


VOID IControlsManager::SetText(const tstring &tStr) {
	::SetWindowText(hWndThis_, tStr.c_str());
}

VOID IControlsManager::SetText(const UINT &uID) {
	SetText(FLoadString(uID));
}

const tstring &IControlsManager::GetText() const {

	PCTSTR tChBuffer = nullptr;
	INT len = ::GetWindowText(hWndThis_, reinterpret_cast<PTSTR>(&tChBuffer), 0);

	return len
		? tstring(tChBuffer, static_cast<size_t>(len))
		: tstring();
}


VOID IControlsManager::Init(const HWND &hWndParent, const WORD &wControlId) {
	hWndParent_ = hWndParent;
	hWndThis_ = GetDlgItem(hWndParent, wControlId);
}

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

IControlsManager::IControlsManager()
	: IControlsManager(nullptr, NULL) {
}


IControlsManager::~IControlsManager() {}