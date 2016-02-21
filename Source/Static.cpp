#include "Static.h"


VOID CStatic::SetData(const std::wstring &tStr) {
	IControl::SetText(tStr);
}

VOID CStatic::SetData(const UINT &uID) {
	IControl::SetText(uID);
}

std::wstring CStatic::GetData() const {
	return IControl::GetText();
}


VOID CStatic::Init(const HWND &hWndParent, const WORD &wControlId) {
	IControl::Init(hWndParent, wControlId);
	IControl::SetText(TEXT("Static"));
}

VOID CStatic::Init(const HWND &hWndParent, const WORD &wControlId, const std::wstring &tStr) {
	IControl::Init(hWndParent, wControlId);
	IControl::SetText(tStr);
}

VOID CStatic::Init(const HWND &hWndParent, const WORD &wControlId, const UINT &uID) {
	IControl::Init(hWndParent, wControlId);
	IControl::SetText(uID);
}

CStatic::CStatic(const HWND &hWndParent, const WORD &wControlId)
	: IControl(hWndParent, wControlId) {
}

CStatic::CStatic()
	: IControl() {
}

CStatic::~CStatic() {}