#include "Dlg.h"

// --- public: --- --- --- ---
//void IDlg::Create() {
//	//hWndCurrent_ = CreateDialogParam(hInstance_, lpTemplateName_, hWndParent_, lpDialogFunc_, WM_INITDIALOG);
//	hWndCurrent_ = CreateDialog(hInstance_, lpTemplateName_, hWndParent_, lpDialogFunc_);
//}
//
//void IDlg::Run() {
//	//DialogBox(hInstance_, lpTemplateName_, hWndParent_, lpDialogFunc_);
//	//hWndCurrent_ = CreateDialogParam(hInstance_, lpTemplateName_, hWndParent_, lpDialogFunc_, WM_INITDIALOG);
//}
//
//IDlg::IDlg(WORD wIntDlgId) {
//	//pDlg          = this;
//	//hWndCurrent_ = CreateDialogParam(hInstance_, lpTemplateName_, hWndParent_, lpDialogFunc_, WM_INITDIALOG);
//	
//	lpTemplateName_ = MAKEINTRESOURCE(wIntDlgId);
//	lpDialogFunc_ = Proc;
//
//	//Create();
//
//	std::pair<HWND, IDlg*> p;
//	p.first = nullptr;
//	p.second = this;
//	dlgList.insert(p);
//
//
//	CreateDialogParam(hInstance_, lpTemplateName_, hWndParent_, Proc, WM_INITDIALOG);
//
//	//Run();
//}
//LRESULT IDlg::Proc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
//	LONG dwNewLong;
//	IDlg* pDlg;
//
//	if (uMsg == WM_INITDIALOG) {
//		dwNewLong = (long)(((LPCREATESTRUCT)lParam)->lpCreateParams);
//		SetWindowLong(hWnd, GWL_USERDATA, dwNewLong);
//		return TRUE;
//	}
//	else {
//		pDlg = (IDlg *)GetWindowLong(hWnd, GWL_USERDATA);
//	}
//
//	if (pDlg) return pDlg->OnMessage(hWnd, uMsg, wParam, lParam);
//
//	return 0;
//}
//
//LRESULT IDlg::OnMessage(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
//
//	switch (uMsg) {
//		HANDLE_MSG(hWnd, WM_INITDIALOG, OnInitDialog);
//		HANDLE_MSG(hWnd, WM_COMMAND, OnCommand);
//		HANDLE_MSG(hWnd, WM_CLOSE, OnClose);
//	default:
//		return DefWindowProc(hWnd, uMsg, wParam, lParam);
//	}
//
//	return 0;
//}
//BOOL IDlg::Run() {
//	return DialogBox(hInstance_, lpTemplate_, hWndParent_, lpDialogFunc_);
//}
//
//IDlg::IDlg(WORD wIntDlgId) {
//	//pDlg          = this;
//
//	lpTemplate_   = MAKEINTRESOURCE(wIntDlgId);
//	lpDialogFunc_ = Proc;
//}
//
//IDlg::IDlg(WORD wIntDlgId, HWND hWnd)
//	: IDlg(wIntDlgId) {
//	std::pair<HWND, IDlg*> p;
//	p.first = GetWindow(hWnd, GW_OWNER);
//	p.second = this;
//
//	dlgList.insert(p);
//}
//
//IDlg::IDlg(WORD wIntDlgId, HINSTANCE hInstance)
//	: IDlg(wIntDlgId) {
//	hInstance_    = hInstance;
//}
//
//IDlg::IDlg(WORD wIntDlgId, HINSTANCE hInstance, HWND hWndParent)
//	: IDlg(wIntDlgId, hInstance) {
//	hWndParent_   = hWndParent;
//}
//
//IDlg::~IDlg() {
//	lpDialogFunc_ = nullptr;
//	hWndParent_   = nullptr;
//	lpTemplate_   = nullptr;
//	hInstance_    = nullptr;
//	//pDlg          = nullptr;
//}
// --- static: --- --- --- ---
//IDlg * IDlg::pDlg = nullptr;
//BOOL CALLBACK IDlg::Proc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
//	//IDlg * pDlg = (IDlg *)GetWindowLongPtr(hWnd, IDD_MAIN);
//	static IDlg * pDlg = nullptr;
//
//	for (auto it = dlgList.begin(); it != dlgList.end(); ++it) {
//		if (hWnd == it->first)
//			pDlg = it->second;
//	}
//
//	if (!pDlg) return FALSE;
//
//	switch (message) {
//		HANDLE_MSG(hWnd, WM_INITDIALOG, pDlg->OnInitDialog);
//		HANDLE_MSG(hWnd, WM_COMMAND, pDlg->OnCommand);
//		HANDLE_MSG(hWnd, WM_CLOSE, pDlg->OnClose);
//	}
//
//	return FALSE;
//}

// --- public: --- --- --- ---

BOOL IDlg::Run() {

	IDlg* lParam = this;

	DialogBoxParam(hInstance_, lpTemplateName_, hWndParent_, lpDialogProc_, (LPARAM)this);
	//CreateDialogParam(hInstance_, lpTemplateName_, hWndParent_, lpDialogProc_, (LPARAM)this);
	return NULL;
}

IDlg::IDlg(WORD wIntDlgId, HWND hWndParent) {
	hInstance_      = GetModuleHandle(NULL);
	lpTemplateName_ = MAKEINTRESOURCE(wIntDlgId);
	hWndParent_     = hWndParent;
	hWndThis_       = GetActiveWindow();
	//hWndThis_ = WindowFromDC(NULL);
	lpDialogProc_   = lpDlgProc;
	//SetWindowLong(hWnd, GWL_USERDATA, (LONG)lpDlgProc);
	//pDlg = this;
	//hWndThis_       = CreateDialogParam(hInstance_, lpTemplateName_, hWndParent_, lpDialogProc_, (LPARAM)this);
}

IDlg::~IDlg() {
	lpDialogProc_ = nullptr;
	hWndParent_ = nullptr;
	lpTemplateName_ = nullptr;
	hInstance_ = nullptr;
}

// --- static: --- --- --- ---

//BOOL IDlg::lpTemp(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
//	if (message == WM_INITDIALOG) {
//
//		std::pair<HWND, IDlg*> p;
//		p.first = hWnd;
//		p.second = (IDlg*)lParam;
//		dlgList.insert(p);
//
//		SetWindowLong(hWnd, GWL_WNDPROC, (LONG)lpDlgProc);
//	}
//	
//	
//
//	//static std::map<HWND, IDlg*>::iterator it;
//	//it = dlgList.find(hWnd);
//
//	////static IDlg* pDlg = it->second;
//
//	//if (it->first == nullptr) {
//
//	//	std::pair<HWND, IDlg*> p;
//	//	p.first = hWnd;
//	//	p.second = (IDlg*)lParam;
//	//	dlgList.insert(p);
//
//	//	SetWindowLong(hWnd, GWL_WNDPROC, (LONG)lpDlgProc);
//	//}
//	
//	/*switch (message) {
//		HANDLE_MSG(hWnd, WM_INITDIALOG, it->second->OnInitDialog);
//		HANDLE_MSG(hWnd, WM_COMMAND, it->second->OnCommand);
//		HANDLE_MSG(hWnd, WM_CLOSE, it->second->OnClose);
//	}*/
//	return FALSE;
//}

IDlg * IDlg::pDlg = nullptr;

BOOL IDlg::lpDlgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

	/*static IDlg* pDlg = nullptr;

	if (uMsg == WM_INITDIALOG) {
		//((IDlg*)lParam)->hWndThis_ = hWnd;
		static std::map<HWND, IDlg*>::iterator it;
		it = dlgList.find(hWnd);

		//static IDlg* pDlg = it->second;
		//
		if (it == dlgList.end()) {

			std::pair<HWND, IDlg*> p;
			p.first = hWnd;
			p.second = pDlg = (IDlg*)lParam;
			dlgList.insert(p);

			//SetWindowLong(hWnd, GWL_WNDPROC, (LONG)lpDlgProc);
			//
		}
		pDlg->hWndThis_ = hWnd;
		//pDlg->OnInitDialog;
	}
	
	switch (uMsg) {
		//HANDLE_MSG(hWnd, WM_INITDIALOG, pDlg->OnInitDialog);
		HANDLE_MSG(hWnd, WM_COMMAND, pDlg->OnCommand);
		HANDLE_MSG(hWnd, WM_CLOSE, pDlg->OnClose);
	}*/

	// ----------------------------------------------------

	//static std::map<HWND, IDlg*>::iterator it;
	//it = dlgList.find(hWnd);
	//static IDlg* pDlg = it->second;
	//if (uMsg == WM_INITDIALOG) {
	//	((IDlg*)lParam)->hWndThis_ = hWnd;
	//	if (it == dlgList.end()) {
	//		std::pair<HWND, IDlg*> p;
	//		p.first = hWnd;
	//		p.second = (IDlg*)lParam;
	//		dlgList.insert(p);
	//		it = dlgList.find(hWnd);
	//		pDlg = it->second;
	//	}
	//	//pDlg->OnInitDialog(hWnd, 0, lParam);
	//}

	//pDlg = ((IDlg*)lParam);

	switch (uMsg) {
		HANDLE_MSG(hWnd, WM_INITDIALOG, pDlg->OnInitDialog);
		HANDLE_MSG(hWnd, WM_COMMAND, pDlg->OnCommand);
		HANDLE_MSG(hWnd, WM_CLOSE, pDlg->OnClose);
	}


	/*static IDlg* pDlg = nullptr;

	std::map<HWND, IDlg*>::iterator it;
	it = dlgList.find(hWnd);

	if (hWnd == it->first)
		pDlg = it->second;

	switch (message) {
		HANDLE_MSG(hWnd, WM_INITDIALOG, pDlg->OnInitDialog);
		HANDLE_MSG(hWnd, WM_COMMAND, pDlg->OnCommand);
		HANDLE_MSG(hWnd, WM_CLOSE, pDlg->OnClose);
	}*/
	return FALSE;
}