#pragma once
#include <tchar.h>
#include <windows.h>
#include <windowsx.h>
#include <commctrl.h>

#include "resource.h"

class CDlg {
private:

	HINSTANCE hInstance_    = nullptr;
	LPCTSTR   lpTemplate_   = nullptr;	
	HWND      hWndParent_   = nullptr;
	DLGPROC   lpDialogFunc_ = nullptr;

	explicit CDlg();

protected:

	virtual BOOL OnInitDialog(HWND hWnd, HWND hwndFocus, LPARAM lParam) = 0;
	virtual void OnCommand(HWND hWnd, int id, HWND hwndCtl, UINT codeNotify) = 0;
	virtual void OnClose(HWND hWnd) = 0;

public:

	virtual BOOL Run() final;

	CDlg(WORD wIntDlgId);
	CDlg(WORD wIntDlgId, HINSTANCE hInstance);
	CDlg(WORD wIntDlgId, HINSTANCE hInstance, HWND hWndParent);
	virtual ~CDlg();


	static CDlg* pDlg;
	static BOOL CALLBACK lpDlgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

};