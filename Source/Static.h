#pragma once

#include "Control.h"


class CStatic : public IControl {
public:

	virtual VOID SetData(const std::wstring &tStr) final;
	virtual VOID SetData(const UINT &uID) final;
	virtual std::wstring GetData() const final;

	virtual VOID Init(const HWND &hWndParent, const WORD &wControlId) override final;
	virtual VOID Init(const HWND &hWndParent, const WORD &wControlId, const std::wstring &tStr) final;
	virtual VOID Init(const HWND &hWndParent, const WORD &wControlId, const UINT &uID) final;

public:    // c-tor / d-tor

	CStatic(const HWND &hWndParent, const WORD &wControlId);
	CStatic();
	~CStatic();
};