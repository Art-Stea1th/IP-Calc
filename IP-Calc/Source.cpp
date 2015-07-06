// Art.Stea1th (Stanislav Kuzmitch)
// Calculator IPv4, Mask, first-last IP, Broadcast etc.
#include <cstdio>
#include <conio.h>

#include <iostream>
#include <iomanip>
using namespace std;

void arrAlloc(int** &pArr, int row, int col),
	 arrRelease(int** &pArr, int row);

void arrInit(int** &pArr, int row, int col),
	 arrPrint(int** &pArr, int row, int col);

void arrPrintDescription(int n);

int GetInt();
void CinWait();

// Entry point
int main(){
	int **resultArr = nullptr,
		col(4), row(7);
	int bit(0);

	arrAlloc(resultArr, row, col);
	arrInit(resultArr, row, col);
	arrPrint(resultArr, row, col);

	
	arrRelease(resultArr, row);
	CinWait();
	return 0;
}

// Allocates memory for an array
void arrAlloc(int** &pArr, int row, int col){
	pArr = new int*[row];

	for (int i(0); i < row; i++)
		pArr[i] = new int[col];
}
// Release memory for an array
void arrRelease(int** &pArr, int row){
	
	for (int i(0); i < row; i++)
		delete[] pArr[i];

	delete[] pArr;
}

// Init Array (null)
void arrInit(int** &pArr, int row, int col){

	for (int i(0); i < row; i++)
		for (int j(0); j < col; j++)
			pArr[i][j] = 0;
}
// Print Array
void arrPrint(int** &pArr, int row, int col){
	cout << "\n   IPv4 Calculator by Art.Stea1th (Stanislav Kuzmitch)\n\n";

	for (int i(0); i < 80; i++) cout << '-';
	
	cout << "\n";
	for (int i(0); i < row; i++){
		arrPrintDescription(i);
		for (int j(0); j < col; j++){
			cout << setw(3) << pArr[i][j];
			if (j != col - 1) cout << '.';
		}
		if (i == 1) cout << " | " << 32 << " bit\n";
		else if (i == 2) cout << "\n\n";
		else cout << '\n';
	}
	cout << '\n' << setw(16) << "Hosts: " << setw(15) << 256;
}

// Print Description Array Strings
void arrPrintDescription(int n){
	switch (n){
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

// Input
int GetInt(){
	int k, n = 0, c = 0, q = 0;
	cin.clear(); cin.sync();

	while (true){
		k = getch();
		if ((k >= '0') && (k <= '9')){
			printf("%c", k);
			n = n * 10 + k - '0';
			c++;
			q++;
		}
		if (k == 8){
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
void CinWait(){
	cin.clear();
	cin.sync();
	cin.get();
}