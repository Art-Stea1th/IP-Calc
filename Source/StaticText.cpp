#include "StaticText.h"


VOID CStaticText::SetText(const tstring & tStr) {
	IControlsManager::SetText(tStr);
}

const tstring &CStaticText::GetText() const {
	return IControlsManager::GetText();
}

VOID CStaticText::Init() {
	return VOID();
}

CStaticText::CStaticText(const HWND &hWndParent, const WORD &wControlId)
	: IControlsManager(hWndParent, wControlId) {
}

CStaticText::~CStaticText() {}