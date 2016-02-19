#pragma once

#include "ControlsManager.h"

class CStaticText : public IControlsManager {
public:    // personal

	virtual VOID SetData(const _TCHAR* &tChLabelText) final;
	//virtual const _TCHAR* &GetData() const final;

public:    // override

	virtual VOID Init() override final;

public:    // c-tor / d-tor

	CStaticText(const HWND &hWndParent, const WORD &wControlId);
	~CStaticText();
};