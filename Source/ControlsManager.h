#pragma once

#include "HeadersCpp.h"
#include "HeadersWin.h"
#include "LoadString.h"


class IControlsManager {
private:

	HWND hWndParent_ = nullptr;
	HWND hWndThis_   = nullptr;

protected: // to override

	virtual VOID SetText(const tstring &tStr);
	virtual VOID SetText(const UINT &uID);
	virtual const tstring &GetText() const;

	virtual VOID Init(const HWND &hWndParent, const WORD &wControlId);

public:    // ban overriding open methods

	virtual const HWND &GetThisHWnd() const final; // return r-value

	virtual VOID Show() final;
	virtual VOID Hide() final;

public:    // c-tor / d-tor

	IControlsManager(const HWND &hWndParent, const WORD &wControlId);
	IControlsManager();
	virtual ~IControlsManager() = 0;
};