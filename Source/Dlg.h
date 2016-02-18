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

	explicit IDlg();

protected:
	
	HWND      hWndThis_ = nullptr;

	virtual BOOL OnInitDialog(HWND hWnd, HWND hwndFocus, LPARAM lParam) = 0;
	virtual void OnCommand(HWND hWnd, int id, HWND hwndCtl, UINT codeNotify) = 0;
	virtual void OnClose(HWND hWnd) = 0;	

public:

	BOOL Run();

	IDlg(WORD wIntDlgId, HWND hWndParent);
	virtual ~IDlg();

	static BOOL CALLBACK lpDlgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
};
static std::map<IDlg*, HWND> dlgList;