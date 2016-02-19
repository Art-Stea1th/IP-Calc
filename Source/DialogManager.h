#pragma once

#include "HeadersCpp.h"
#include "HeadersWin.h"
#include "..\Resources\Resource.h"

class IDialogManager {
private:	

	HINSTANCE hInstance_ = nullptr;
	LPCTSTR   lpTemplateName_ = nullptr;	
	HWND      hWndParent_ = nullptr;
	DLGPROC   lpDialogProc_ = nullptr;

	HWND      hWndThis_ = nullptr;

private:

	explicit IDialogManager();

protected:

	HWND GetHWndThis() const;

	virtual BOOL OnInitDialog(HWND hWnd, HWND hwndFocus, LPARAM lParam) = 0;
	virtual VOID OnCommand(HWND hWnd, INT id, HWND hwndCtl, UINT codeNotify) = 0;
	virtual VOID OnClose(HWND hWnd) = 0;
	
	static BOOL CALLBACK lpStaticDlgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

public:

	VOID Run() const;
	
	IDialogManager(WORD wDialogId, HWND hWndParent);
	IDialogManager(WORD wDialogId);
	virtual ~IDialogManager();	
};

static std::map<IDialogManager*, HWND> dlgList;