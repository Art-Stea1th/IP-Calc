#include "StaticText.h"


VOID CStaticText::SetData(const tstring &tStr) {
	IControlsManager::SetText(tStr);
}

VOID CStaticText::SetData(const UINT &uID) {
	IControlsManager::SetText(uID);
}

const tstring &CStaticText::GetData() const {
	return IControlsManager::GetText();
}


VOID CStaticText::Init(const HWND &hWndParent, const WORD &wControlId) {
	IControlsManager::Init(hWndParent, wControlId);
	IControlsManager::SetText(TEXT("Static Text"));
}

VOID CStaticText::Init(const HWND &hWndParent, const WORD &wControlId, const tstring &tStr) {
	IControlsManager::Init(hWndParent, wControlId);
	IControlsManager::SetText(tStr);
}

VOID CStaticText::Init(const HWND &hWndParent, const WORD &wControlId, const UINT &uID) {
	IControlsManager::Init(hWndParent, wControlId);
	IControlsManager::SetText(uID);
}

CStaticText::CStaticText(const HWND &hWndParent, const WORD &wControlId)
	: IControlsManager(hWndParent, wControlId) {
}

CStaticText::CStaticText()
	: IControlsManager() {
}

CStaticText::~CStaticText() {}