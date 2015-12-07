// Art.Stea1th (Stanislav Kuzmitch)
// Calculator IPv4, Mask, first-last IP, Broadcast etc.
#define ULL unsigned long long

#include <cstdio>
#include <conio.h>

#include <iostream>
#include <iomanip>
using namespace std;

void arrAlloc(int** &pArr, int row, int col),
arrRelease(int** &pArr, int row);

void arrInit(int** &pArr, int row, int col),
arrPrint(int** &pArr, int row, int col, int &bit, ULL &hosts),
arrPrintDescription(int n);

void getIPandMask(int** &pArr, int row, int col, int &bit, ULL &hosts);

void calculateAll(int** &pArr, int row, int col, int &bit, ULL &hosts);

int getInt();
void cinWait();

// Entry point
int main() {
	int **resultArr = nullptr,
		col(4), row(7);
	while (true) {
		int bit(0);
		ULL hosts(0);

		arrAlloc(resultArr, row, col);
		arrInit(resultArr, row, col);
		arrPrint(resultArr, row, col, bit, hosts);

		getIPandMask(resultArr, row, col, bit, hosts);
		calculateAll(resultArr, row, col, bit, hosts);
		arrPrint(resultArr, row, col, bit, hosts);

		arrRelease(resultArr, row);
		cinWait();
	}
	return 0;
}

// Print Array
void arrPrint(int** &pArr, int row, int col, int &bit, ULL &hosts) {
	system("cls");
	cout << "\n   IPv4 Calculator by Art.Stea1th (Stanislav Kuzmitch)\n\n";

	for (int i(0); i < 80; i++) cout << '-';

	cout << "\n";
	for (int i(0); i < row; i++) {
		arrPrintDescription(i);
		for (int j(0); j < col; j++) {
			cout << setw(3) << pArr[i][j];
			if (j != col - 1) cout << '.';
		}
		if (i == 1) cout << " | " << bit << " bit\n";
		else if (i == 2) cout << "\n\n";
		else cout << '\n';
	}
	cout << '\n' << setw(16) << "Hosts: " << setw(15) << hosts << "\n\n";

	for (int i(0); i < 80; i++) cout << '-';

	cout << "\n";
}
// Print Description Array Strings
void arrPrintDescription(int n) {
	switch (n) {
	case 0: cout << setw(16) << "Adress: "; break;
	case 1: cout << setw(16) << "Netmask: "; break;
	case 2: cout << setw(16) << "Wildcard: "; break;
	case 3: cout << setw(16) << "Network: "; break;
	case 4: cout << setw(16) << "Host Min: "; break;
	case 5: cout << setw(16) << "Host Max: "; break;
	case 6: cout << setw(16) << "Broadcast: "; break;
	default: cout << setw(16); break;
	}
}



// Func for get IP adress
void getIPandMask(int** &pArr, int row, int col, int &bit, ULL &hosts) {
	int n(0);

	for (int i(0); i < col; i++) {
		do {
			arrPrint(pArr, row, col, bit, hosts);
			cout << "\tEnter the [" << i + 1 << "] octet (0 - 255): ";
			n = getInt();
			if (n >= 0 && n <= 255) {
				pArr[0][i] = n;
				n = 0;
				break;
			}
		} while (true);
	}
	do {
		arrPrint(pArr, row, col, bit, hosts);
		cout << "\tEnter bitmask (0 - 32): ";
		n = getInt();
		if (n >= 0 && n <= 32) {
			bit = n;
			n = 0;
			break;
		}
	} while (true);
}

// Calculate Mask & Wildcard
void calculateAll(int** &pArr, int row, int col, int &bit, ULL &hosts) {
	const int size(9);
	int support_arr[size];

	// Fill support_arr | 256 | 128 | 64 | 32 | 16 | 8 | 4 | 2 | 1 |
	for (int i(0); i < size; i++)
		support_arr[i] = pow(2, (size - 1 - i));

	// * 1. Netmask
	for (int i(0); i <= bit / 8 && i < col; i++) {
		if (i != bit / 8) pArr[1][i] = support_arr[0] - support_arr[size - 1];
		else pArr[1][i] = support_arr[0] - support_arr[bit % 8];
	}

	// * 2. Wildcard
	for (int i(0); i < col; i++)
		pArr[2][i] = support_arr[0] - support_arr[size - 1] - pArr[1][i];

	// * 3. Network
	for (int i(0); i < col; i++) {
		if (i < bit / 8) pArr[3][i] = pArr[0][i];
		else if (i == bit / 8) {
			pArr[3][i] = pArr[0][i];
			while (pArr[3][i] + pArr[2][i] > support_arr[0] - support_arr[size - 1]) {
				pArr[3][i]--;
			}
			if (pArr[3][i] > 0) pArr[3][i]--;
		}
	}

	// * 4. Host Min
	for (int i(0); i < col; i++) {
		if (i != col - 1) pArr[4][i] = pArr[3][i];
		else pArr[4][i] = pArr[3][i] + 1;
	}

	// * 5. Host Max
	for (int i(0); i < col; i++) {
		if (i < bit / 8) pArr[5][i] = pArr[0][i];
		else {
			if (i != col - 1) pArr[5][i] = pArr[3][i] + pArr[2][i];
			else pArr[5][i] = pArr[3][i] + pArr[2][i] - 1;
		}
	}

	// * 6. Broadcast
	for (int i(0); i < col; i++) {
		if (i < bit / 8) pArr[6][i] = pArr[0][i];
		else pArr[6][i] = pArr[3][i] + pArr[2][i];
	}


	// 7. Hosts
	hosts = 1;
	for (int i(0); i < col; i++)
		hosts *= (pArr[2][i] + 1);


	// Exception for 32bit
	if (bit == 32) {
		for (int i(0); i < col; i++) {
			if (pArr[5][col - 1 - i] > 0) {
				pArr[5][col - 1 - i]--;
				break;
			}
			else pArr[5][col - 1 - i] = support_arr[0] - support_arr[size - 1];
		}
	}

}

// Input
int getInt() {
	int k, n = 0, c = 0, q = 0;
	cin.clear(); cin.sync();

	while (true) {
		k = getch();
		if ((k >= '0') && (k <= '9')) {
			printf("%c", k);
			n = n * 10 + k - '0';
			c++;
			q++;
		}
		if (k == 8) {
			putch(8);
			putch(' ');
			putch(8);
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
// Pause
void cinWait() {
	cin.clear();
	cin.sync();
	cin.get();
}



// Allocates memory for an array
void arrAlloc(int** &pArr, int row, int col) {
	pArr = new int*[row];

	for (int i(0); i < row; i++)
		pArr[i] = new int[col];
}
// Release memory for an array
void arrRelease(int** &pArr, int row) {

	for (int i(0); i < row; i++)
		delete[] pArr[i];

	delete[] pArr;
}
// Init Array (nULL)
void arrInit(int** &pArr, int row, int col) {

	for (int i(0); i < row; i++)
		for (int j(0); j < col; j++)
			pArr[i][j] = 0;
}
