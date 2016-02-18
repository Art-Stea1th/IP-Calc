#pragma once
#include <tchar.h>
#include <windows.h>
#include <windowsx.h>
#include <commctrl.h>

#include "..\Resources\Resource.h"

#include <map>

class IDlg {
private:	

	HINSTANCE hInstance_ = nullptr;
	LPCTSTR   lpTemplateName_ = nullptr;	
	HWND      hWndParent_ = nullptr;
	DLGPROC   lpDialogProc_ = nullptr;

	HWND      hWndThis_ = nullptr;

private:

	explicit IDlg();

protected:

	HWND GetHWndThis();

	virtual BOOL OnInitDialog(HWND hWnd, HWND hwndFocus, LPARAM lParam) = 0;
	virtual VOID OnCommand(HWND hWnd, INT id, HWND hwndCtl, UINT codeNotify) = 0;
	virtual VOID OnClose(HWND hWnd) = 0;
	
	static BOOL CALLBACK lpStaticDlgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

public:

	VOID Run() const;
	
	IDlg(WORD wIntDlgId, HWND hWndParent);
	IDlg(WORD wIntDlgId);
	virtual ~IDlg();	
};

static std::map<IDlg*, HWND> dlgList;