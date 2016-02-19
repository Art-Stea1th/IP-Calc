#pragma once
#include <tchar.h>
#include <windows.h>
#include <windowsx.h>
#include <commctrl.h>

#include "..\Resources\Resource.h"

#include <map>

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

	HWND GetHWndThis();

	virtual BOOL OnInitDialog(HWND hWnd, HWND hwndFocus, LPARAM lParam) = 0;
	virtual VOID OnCommand(HWND hWnd, INT id, HWND hwndCtl, UINT codeNotify) = 0;
	virtual VOID OnClose(HWND hWnd) = 0;
	
	static BOOL CALLBACK lpStaticDlgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

public:

	VOID Run() const;
	
	IDialogManager(WORD wIntDlgId, HWND hWndParent);
	IDialogManager(WORD wIntDlgId);
	virtual ~IDialogManager();	
};

static std::map<IDialogManager*, HWND> dlgList;