// Art.Stea1th (Stanislav Kuzmitch)
// Calculator IPv4, Mask, first-last IP, Broadcast etc.
#include "main.h"

#define BUILD_MODE_WIN32 // <--- comment this string to build console project

#ifdef BUILD_MODE_WIN32

BOOL CALLBACK MainDlgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
HINSTANCE hInst;

// Entry point
int APIENTRY _tWinMain(HINSTANCE This, HINSTANCE Prev, LPTSTR cmd, int mode) {
	hInst = This;
	return ::DialogBox(hInst, MAKEINTRESOURCE(IDD_MAIN), NULL, MainDlgProc);
}

BOOL CALLBACK MainDlgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {

	switch (message) {
    ///   -   -   -   -   -   -   -   -   -   -   -   -   -   -   -   -   -   -   -   -   -   -   -   -   -   -   -   -
	case WM_INITDIALOG:
	{
		HICON hicon = LoadIcon(hInst, MAKEINTRESOURCE(IDI_IP_CALC));
		SendMessage(hWnd, WM_SETICON, ICON_SMALL, (LPARAM)hicon);

		HWND hWndComboBox = GetDlgItem(hWnd, IDC_COMBO_BITMASK);
		for (int i(0); i < 33; i++) {
			_TCHAR tchTmp[2];
			_itow(i, tchTmp, 10);
			::SendMessage(hWndComboBox, (UINT)CB_ADDSTRING, (WPARAM)0, (LPARAM)tchTmp);
		}
		::SendMessage(hWndComboBox, CB_SETCURSEL, (WPARAM)24/*default mask*/, (LPARAM)0);

		HWND hWndIpAddrIn = GetDlgItem(hWnd, IDC_IP_IP_ADDRESS_IN);
		::SendMessage(hWndIpAddrIn,	IPM_SETADDRESS, 0L,	MAKEIPADDRESS(192, 168, 1, 2)/*default ip*/);
		break;
	}
	///   -   -   -   -   -   -   -   -   -   -   -   -   -   -   -   -   -   -   -   -   -   -   -   -   -   -   -   -
	case WM_COMMAND:
	{
		switch (LOWORD(wParam)) {
		case IDC_BTN_CALCULATE:
		{
			HWND hWndIpAddrIn = GetDlgItem(hWnd, IDC_IP_IP_ADDRESS_IN);
			DWORD dwIp(0L);

			::SendMessage(hWndIpAddrIn, IPM_GETADDRESS, 0L, (LPARAM)&dwIp);

			IpRepresentation ipAddr;
			ipAddr(
				FIRST_IPADDRESS(dwIp),
				SECOND_IPADDRESS(dwIp),
				THIRD_IPADDRESS(dwIp),
				FOURTH_IPADDRESS(dwIp)
				);

			NetInfo netInfo;
			netInfo[0] = ipAddr;

			HWND hWndComboBox = GetDlgItem(hWnd, IDC_COMBO_BITMASK);
			_TCHAR dwBitmaskStr[3];

			::GetWindowText(hWndComboBox, (LPWSTR)dwBitmaskStr, 3);

			netInfo.bitmask() = _wtoi(dwBitmaskStr);
			netInfo.calculate();


			HWND hWndNetInfo[7];
			hWndNetInfo[0] = GetDlgItem(hWnd, IDC_IP_IP_ADDRESS);
			hWndNetInfo[1] = GetDlgItem(hWnd, IDC_IP_NETW_MASK);
			hWndNetInfo[2] = GetDlgItem(hWnd, IDC_IP_WILDCARD);
			hWndNetInfo[3] = GetDlgItem(hWnd, IDC_IP_NETWORK);
			hWndNetInfo[4] = GetDlgItem(hWnd, IDC_IP_HOSTMIN);
			hWndNetInfo[5] = GetDlgItem(hWnd, IDC_IP_HOSTMAX);
			hWndNetInfo[6] = GetDlgItem(hWnd, IDC_IP_BROADCAST);

			for (int i(0); i < 7; i++)
				::SendMessage(
					hWndNetInfo[i],
					IPM_SETADDRESS, 0L,
					MAKEIPADDRESS(
						(BYTE)netInfo[i].octet_get(0),
						(BYTE)netInfo[i].octet_get(1),
						(BYTE)netInfo[i].octet_get(2),
						(BYTE)netInfo[i].octet_get(3)
						)
					);
			break;
		}
		}

		break;
	}
	///   -   -   -   -   -   -   -   -   -   -   -   -   -   -   -   -   -   -   -   -   -   -   -   -   -   -   -   -
	case WM_CLOSE:
	{
		EndDialog(hWnd, 0);
		break;
	}
	///   -   -   -   -   -   -   -   -   -   -   -   -   -   -   -   -   -   -   -   -   -   -   -   -   -   -   -   -
	}

	return FALSE;
}

#else // BUILD_MODE_CONSOLE

int _tmain(int argc, _TCHAR *argv[], _TCHAR *envp[]) {
	
	while (true) {
		NetInfo netinfo;
		netinfo.show_to_console();

		netinfo.get_from_console();
		netinfo.calculate();
		netinfo.show_to_console();

		std::wcout << L"   ";
		system("pause");
	}
	return 0;
}

#endif