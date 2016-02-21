#pragma once

#include "HeadersCpp.h"
#include "HeadersWin.h"
#include "..\Resources\Resource.h"


class IDialog {
private:

	HINSTANCE hInstance_ = nullptr;
	PCWSTR    lpTemplateName_ = nullptr;
	HWND      hWndParent_ = nullptr;
	DLGPROC   lpDialogProc_ = nullptr;

	HWND      hWndThis_ = nullptr;

protected: // ban overriding methods

	virtual const HINSTANCE &GetThisHandle() const final; // return r-value
	virtual const HWND      &GetThisHWnd()   const final; // return r-value

protected: // to override

	virtual BOOL OnInitDialog(HWND hWnd, HWND hwndFocus, LPARAM lParam) = 0;
	virtual VOID OnCommand(HWND hWnd, INT id, HWND hwndCtl, UINT codeNotify) = 0;
	virtual VOID OnClose(HWND hWnd) = 0;

	static INT_PTR CALLBACK lpStaticDlgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

public:    // open methods

	VOID Run() const;

public:    // c-tor / d-tor

	IDialog(const WORD &wDialogId, const HWND &hWndParent);
	IDialog(const WORD &wDialogId);
	virtual ~IDialog();
};

static std::map<IDialog*, HWND> dlgList;