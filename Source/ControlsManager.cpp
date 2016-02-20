#include "ControlsManager.h"


VOID IControlsManager::SetText(const std::wstring &tStr) {
	::SetWindowText(hWndThis_, tStr.c_str());
}

VOID IControlsManager::SetText(const UINT &uID) {
	SetText(FLoadString(uID));
}

std::wstring IControlsManager::GetText() const {

	PCWSTR tChBuffer = nullptr;
	INT iBufferSize = ::GetWindowText(hWndThis_, reinterpret_cast<PWSTR>(&tChBuffer), 0);

	return iBufferSize
		? std::wstring(tChBuffer, static_cast<size_t>(iBufferSize))
		: std::wstring();
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
	Init(hWndParent, wControlId);
}

IControlsManager::IControlsManager()
	: IControlsManager(nullptr, NULL) {
}

IControlsManager::~IControlsManager() {}