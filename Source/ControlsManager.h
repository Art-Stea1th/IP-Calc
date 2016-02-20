#pragma once

#include "HeadersCpp.h"
#include "HeadersWin.h"
#include "LoadString.h"


class IControlsManager {
private:

	HWND hWndParent_ = nullptr;
	HWND hWndThis_   = nullptr;

protected: // to override

	virtual VOID Init() = 0;
	virtual VOID SetText(const PCTSTR tChStr);
	virtual const PCTSTR GetText() const;

public:    // ban overriding open methods

	virtual const HWND &GetThisHWnd() const final; // return r-value

	virtual VOID Show() final;
	virtual VOID Hide() final;

public:    // c-tor / d-tor

	IControlsManager(const HWND &hWndParent, const WORD &wControlId);
	virtual ~IControlsManager();

};