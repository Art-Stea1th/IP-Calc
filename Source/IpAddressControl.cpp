#include "IpAddressControl.h"


VOID CIpAddressControl::SetData(const UINT &uIp) {
	::SendMessage(GetThisHWnd(), IPM_SETADDRESS, static_cast<WPARAM>(0), static_cast<WPARAM>(uIp));
}

VOID CIpAddressControl::SetData(
	const UINT &uOct1,
	const UINT &uOct2,
	const UINT &uOct3,
	const UINT &uOct4
	) {
	SetData(
		MAKEIPADDRESS(
			static_cast<DWORD>(uOct1),
			static_cast<DWORD>(uOct2),
			static_cast<DWORD>(uOct3),
			static_cast<DWORD>(uOct4)
			)
		);
}

UINT CIpAddressControl::GetData() const {
	UINT uResult;
	::SendMessage(GetThisHWnd(), IPM_GETADDRESS, static_cast<WPARAM>(0), reinterpret_cast<WPARAM>(&uResult));
	return uResult;
}


VOID CIpAddressControl::Init(const HWND &hWndParent, const WORD &wControlId) {
	IControlsManager::Init(hWndParent, wControlId);
}

VOID CIpAddressControl::Init(const HWND &hWndParent, const WORD &wControlId, const UINT &uIp) {
	IControlsManager::Init(hWndParent, wControlId);
	CIpAddressControl::SetData(uIp);
}

VOID CIpAddressControl::Init(
	const HWND &hWndParent,
	const WORD &wControlId,
	const UINT &uOct1,
	const UINT &uOct2,
	const UINT &uOct3,
	const UINT &uOct4
	) {
	IControlsManager::Init(hWndParent, wControlId);
	CIpAddressControl::SetData(uOct1, uOct2, uOct3, uOct4);
}

CIpAddressControl::CIpAddressControl(const HWND &hWndParent, const WORD &wControlId)
	: IControlsManager(hWndParent, wControlId) {
}

CIpAddressControl::CIpAddressControl()
	: IControlsManager() {
}

CIpAddressControl::~CIpAddressControl() {}