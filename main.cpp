// Art.Stea1th (Stanislav Kuzmitch)
// Calculator IPv4, Mask, first-last IP, Broadcast etc.

#include "main.h"



// Entry point
int _tmain(int argc, _TCHAR *argv[], _TCHAR *envp[]) {
	
	while (true) {
		NetInfo netinfo;
		Print(netinfo);

		GetIPandMask(netinfo);
		netinfo.calculate();
		Print(netinfo);

		std::wcout << L"   ";
		system("pause");
	}
	return 0;
}

// Print Array
void Print(NetInfo &netinfo) {
	using namespace std;
	//======================================
	ui8
		col(netinfo.operator[](0).size()),
		row(netinfo.size()),
		bit(netinfo.bitmask());
	ui32
		hosts(netinfo.hosts());
	//======================================
	system("cls");

	wcout << L"\n   IPv4 Calculator by Art.Stea1th (Stanislav Kuzmitch)\n\n";

	for (int i(0); i < 80; i++) wcout << L'-';

	wcout << L"\n";
	for (int i(0); i < row; i++) {
		PrintDescription(i);
		for (int j(0); j < col; j++) {
			wcout << setw(3) << netinfo[i][j];
			if (j != col - 1) wcout << L'.';
		}
		if (i == 1) wcout << L" | " << bit << L" bit\n";
		else if (i == 2) wcout << L"\n\n";
		else wcout << L'\n';
	}
	wcout << L'\n' << setw(16) << L"Hosts: " << setw(15) << hosts << L"\n\n";

	for (int i(0); i < 80; i++) wcout << L'-';

	wcout << L"\n";
}

// Print Description Array Strings
void PrintDescription(int n) {
	using namespace std;

	switch (n) {
	case 0: wcout << setw(16) << L"Adress: "; break;
	case 1: wcout << setw(16) << L"Netmask: "; break;
	case 2: wcout << setw(16) << L"Wildcard: "; break;
	case 3: wcout << setw(16) << L"Network: "; break;
	case 4: wcout << setw(16) << L"Host Min: "; break;
	case 5: wcout << setw(16) << L"Host Max: "; break;
	case 6: wcout << setw(16) << L"Broadcast: "; break;
	default: wcout << setw(16); break;
	}
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
			Print(netinfo);
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
		Print(netinfo);
		wcout << L"\tEnter bitmask (0 - 32): ";
		n = GetInt();
		if (n >= 0 && n <= 32) {
			bit = n;
			n = 0;
			break;
		}
	} while (true);
}

// Calculate All
void CalculateAll(NetInfo &netinfo) {
	netinfo.calculate();
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