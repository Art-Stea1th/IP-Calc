#pragma once

#include "ControlsManager.h"

class CStaticText : public IControlsManager {
public:    // override

	virtual VOID SetText(const tstring &tStr) override final;
	virtual const tstring &GetText() const override final;
	virtual VOID Init() override final;

public:    // c-tor / d-tor

	CStaticText(const HWND &hWndParent, const WORD &wControlId);
	~CStaticText();
};