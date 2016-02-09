// Art.Stea1th (Stanislav Kuzmitch)
// Calculator IPv4, Mask, first-last IP, Broadcast etc.

#include "main.h"



// Entry point
int _tmain(int argc, _TCHAR *argv[], _TCHAR *envp[]) {
	
	while (true) {
		NetInfo netinfo;
		netinfo.show_to_console();

		GetIPandMask(netinfo);
		netinfo.calculate();
		netinfo.show_to_console();

		std::wcout << L"   ";
		system("pause");
	}
	return 0;
}

// Func for get IP adress
void GetIPandMask(NetInfo &netinfo) {
	using namespace std;
	//======================================
	ui8
		col(netinfo.operator[](0).size()),
		row(netinfo.size()),
		bit(netinfo.bitmask());
	ui32
		hosts(netinfo.hosts());
	//======================================
	int n(0);

	for (int i(0); i < col; i++) {
		do {
			netinfo.show_to_console();
			wcout << L"\tEnter the [" << i + 1 << L"] octet (0 - 255): ";
			n = GetInt();
			if (n >= 0 && n <= 255) {
				netinfo[0][i] = n;
				n = 0;
				break;
			}
		} while (true);
	}
	do {
		netinfo.show_to_console();
		wcout << L"\tEnter bitmask (0 - 32): ";
		n = GetInt();
		if (n >= 0 && n <= 32) {
			bit = n;
			n = 0;
			break;
		}
	} while (true);
}

// Input
int GetInt() {
	int k, n = 0, c = 0, q = 0;

	while (true) {
		k = _getch();
		if ((k >= '0') && (k <= '9')) {
			printf("%c", k);
			n = n * 10 + k - '0';
			c++;
			q++;
		}
		if (k == 8) {
			_putch(8);
			_putch(' ');
			_putch(8);
			n = n / 10;
			q--;
			if (q < 0) q = 0;
			c--;
			if (c < 0) c = 0;
		}

		if ((k == 13) && (c != 0) && (q != 0)) break;
	}

	return n;
}