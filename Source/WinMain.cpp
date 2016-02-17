// Art.Stea1th (Stanislav Kuzmitch)
// Calculator IPv4, Mask, first-last IP, Broadcast etc.

#include "WinMain.h"

int APIENTRY _tWinMain(HINSTANCE This, HINSTANCE Prev, LPTSTR cmd, int mode) {
	
	HWND window;

	CMainDialog mainDlg(IDD_MAIN, nullptr);
	mainDlg.Run();

	return FALSE;
}