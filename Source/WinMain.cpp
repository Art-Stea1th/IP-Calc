// Art.Stea1th (Stanislav Kuzmitch)
// Calculator IPv4, Mask, first-last IP, Broadcast etc.

#include "MainDialog.h"

INT APIENTRY wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, INT nCmdShow) {

	CMainDialog mainDlg(IDD_MAIN);
	mainDlg.Run();

	return FALSE;
}