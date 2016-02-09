// Art.Stea1th (Stanislav Kuzmitch)
// Calculator IPv4, Mask, first-last IP, Broadcast etc.
#include "main.h"

BOOL CALLBACK DlgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

HINSTANCE hInst;

// Entry point
int APIENTRY _tWinMain(HINSTANCE This, HINSTANCE Prev, LPTSTR cmd, int mode) {
	hInst = This;

	return ::DialogBox(hInst, MAKEINTRESOURCE(IDD_MAIN), NULL, DlgProc);
}

BOOL CALLBACK DlgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
	switch (message) {
	case WM_CLOSE: EndDialog(hWnd, 0); break;
	}
	return 0;
}

//int _tmain(int argc, _TCHAR *argv[], _TCHAR *envp[]) {
//	
//	while (true) {
//		NetInfo netinfo;
//		netinfo.show_to_console();
//
//		netinfo.get_from_console();
//		netinfo.calculate();
//		netinfo.show_to_console();
//
//		std::wcout << L"   ";
//		system("pause");
//	}
//	return 0;
//}