// Art.Stea1th (Stanislav Kuzmitch)
// Calculator IPv4, Mask, first-last IP, Broadcast etc.
#include "main.h"


// Entry point
int APIENTRY _tWinMain(HINSTANCE This, HINSTANCE Prev, LPTSTR cmd, int mode) {
	hInst = This;	
	return DialogBox(This, MAKEINTRESOURCE(IDD_MAIN), NULL, MainDlgProc);
}