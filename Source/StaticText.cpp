#include "StaticText.h"


VOID CStaticText::Init() {
	return VOID();
}

VOID CStaticText::SetData(const PCTSTR &tChLabelText) {
	::SetWindowText(GetThisHWnd(), tChLabelText);
}

const PCTSTR &CStaticText::GetData() const {
	return TEXT(" ");
}

CStaticText::CStaticText(const HWND &hWndParent, const WORD &wControlId)
	: IControlsManager(hWndParent, wControlId) {
}

CStaticText::~CStaticText() {}