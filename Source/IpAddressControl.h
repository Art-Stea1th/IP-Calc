#pragma once

#include "Control.h"


class CIpAddressControl : public IControl {
public:

	virtual VOID SetData(const UINT &uIp) final;

	virtual VOID SetData(
		const UINT &uOct1,
		const UINT &uOct2,
		const UINT &uOct3,
		const UINT &uOct4
		) final;

	virtual UINT GetData() const final;

	virtual VOID Init(const HWND &hWndParent, const WORD &wControlId) override final;
	virtual VOID Init(const HWND &hWndParent, const WORD &wControlId, const UINT &uIp) final;
	virtual VOID Init(
		const HWND &hWndParent,
		const WORD &wControlId,
		const UINT &uOct1,
		const UINT &uOct2,
		const UINT &uOct3,
		const UINT &uOct4
		) final;

public:    // c-tor / d-tor

	CIpAddressControl(const HWND &hWndParent, const WORD &wControlId);
	CIpAddressControl();
	~CIpAddressControl();
};