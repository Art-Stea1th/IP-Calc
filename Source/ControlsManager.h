#pragma once

#include "HeadersWin.h"


class IControlsManager {
private:

	HWND hWndParent_ = nullptr;
	HWND hWndThis_   = nullptr;

protected:

	virtual VOID Init() = 0;
	virtual VOID SetData() = 0;
	virtual VOID GetData() = 0;

	virtual VOID Show() = 0;
	virtual VOID Hide() = 0;

public:

	IControlsManager(const HWND &hWndParent, const WORD &wControlId);
	virtual ~IControlsManager();
};