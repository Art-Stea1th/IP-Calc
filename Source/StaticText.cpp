#include "StaticText.h"


VOID CStaticText::Init() {
	return VOID();
}

VOID CStaticText::SetData(const _TCHAR* &tChLabelText) {
	::SetWindowText(GetThisHWnd(), tChLabelText);
}

//const _TCHAR* &CStaticText::GetData() const {
//	// TODO: insert return statement here
//}

CStaticText::CStaticText(const HWND &hWndParent, const WORD &wControlId)
	: IControlsManager(hWndParent, wControlId) {
}

CStaticText::~CStaticText() {}