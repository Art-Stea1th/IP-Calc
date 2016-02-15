#pragma once
#include <tchar.h>
#include <windows.h>
#include <windowsx.h>
#include <commctrl.h>

#include "..\Resources\Resource.h"

class IDlg {
private:

	HINSTANCE hInstance_    = nullptr;
	LPCTSTR   lpTemplate_   = nullptr;	
	HWND      hWndParent_   = nullptr;
	DLGPROC   lpDialogFunc_ = nullptr;

	explicit IDlg();

protected:

	virtual BOOL OnInitDialog(HWND hWnd, HWND hwndFocus, LPARAM lParam) = 0;
	virtual void OnCommand(HWND hWnd, int id, HWND hwndCtl, UINT codeNotify) = 0;
	virtual void OnClose(HWND hWnd) = 0;

public:

	virtual BOOL Run() final;

	IDlg(WORD wIntDlgId);
	IDlg(WORD wIntDlgId, HINSTANCE hInstance);
	IDlg(WORD wIntDlgId, HINSTANCE hInstance, HWND hWndParent);
	virtual ~IDlg();


	static IDlg* pDlg;
	static BOOL CALLBACK lpDlgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

};