#pragma once

#include "ControlsManager.h"


class CStaticText : public IControlsManager {
public:

	virtual VOID SetData(const std::wstring &tStr) final;
	virtual VOID SetData(const UINT &uID) final;
	virtual std::wstring GetData() const final;

	virtual VOID Init(const HWND &hWndParent, const WORD &wControlId) override final;
	virtual VOID Init(const HWND &hWndParent, const WORD &wControlId, const std::wstring &tStr) final;
	virtual VOID Init(const HWND &hWndParent, const WORD &wControlId, const UINT &uID) final;

public:    // c-tor / d-tor

	CStaticText(const HWND &hWndParent, const WORD &wControlId);
	CStaticText();
	~CStaticText();
};