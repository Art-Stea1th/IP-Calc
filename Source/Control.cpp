#include "Control.h"


VOID IControl::SetText(const std::wstring &tStr) {
	::SetWindowText(hWndThis_, tStr.c_str());
}

VOID IControl::SetText(const UINT &uID) {
	SetText(FLoadString(uID));
}

std::wstring IControl::GetText() const {

	PCWSTR tChBuffer = nullptr;
	INT iBufferSize = ::GetWindowText(hWndThis_, reinterpret_cast<PWSTR>(&tChBuffer), 0);

	return iBufferSize
		? std::wstring(tChBuffer, static_cast<size_t>(iBufferSize))
		: std::wstring();
}


VOID IControl::Init(const HWND &hWndParent, const WORD &wControlId) {
	hWndParent_ = hWndParent;
	hWndThis_ = GetDlgItem(hWndParent, wControlId);
}

const HWND &IControl::GetThisHWnd() const {
	return hWndThis_;
}

VOID IControl::Show() {
	ShowWindow(hWndThis_, SW_SHOWNA);
}

VOID IControl::Hide() {
	ShowWindow(hWndThis_, SW_HIDE);
}

IControl::IControl(const HWND &hWndParent, const WORD &wControlId) {
	Init(hWndParent, wControlId);
}

IControl::IControl()
	: IControl(nullptr, NULL) {
}

IControl::~IControl() {}