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
	 arrPrint(int** &pArr, int row, int col, int &bit),
	 arrPrintDescription(int n);

void getIPandMask(int** &pArr, int row, int col, int &bit);

void calcMask(int** &pArr, int row, int col, int &bit);

int getInt();
void cinWait();

// Entry point
int main(){
	int **resultArr = nullptr,
		col(4), row(7);
	int bit(0);

	arrAlloc(resultArr, row, col);
	arrInit(resultArr, row, col);
	arrPrint(resultArr, row, col, bit);
	
	getIPandMask(resultArr, row, col, bit);
	calcMask(resultArr, row, col, bit);
	arrPrint(resultArr, row, col, bit);
	
	arrRelease(resultArr, row);
	cinWait();
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
void arrPrint(int** &pArr, int row, int col, int &bit){
	system("cls");
	cout << "\n   IPv4 Calculator by Art.Stea1th (Stanislav Kuzmitch)\n\n";

	for (int i(0); i < 80; i++) cout << '-';
	
	cout << "\n";
	for (int i(0); i < row; i++){
		arrPrintDescription(i);
		for (int j(0); j < col; j++){
			cout << setw(3) << pArr[i][j];
			if (j != col - 1) cout << '.';
		}
		if (i == 1) cout << " | " << bit << " bit\n";
		else if (i == 2) cout << "\n\n";
		else cout << '\n';
	}
	cout << '\n' << setw(16) << "Hosts: " << setw(15) << 256 << "\n\n";
	
	for (int i(0); i < 80; i++) cout << '-';

	cout << "\n";
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

// Func for get IP adress
void getIPandMask(int** &pArr, int row, int col, int &bit){
	int n(0);
	
	for (int i(0); i < col; i++){
		do {
			system("cls");
			arrPrint(pArr, row, col, bit);
			cout << "\tEnter the [" << i + 1 << "] octet (0 - 255): ";
			n = getInt();
			if (n >= 0 && n <= 255){
				pArr[0][i] = n;
				n = 0;
				break;
			}
		} while (true);		
	}
	do {
		system("cls");
		arrPrint(pArr, row, col, bit);
		cout << "\tEnter bitmask (0 - 32): ";
		n = getInt();
		if (n >= 0 && n <= 32){
			bit = n;
			n = 0;
			break;
		}
	} while (true);

	//system("cls");
	//arrPrint(pArr, row, col, bit);
}
// Calculate Netmask
void calcMask(int** &pArr, int row, int col, int &bit){
	int n(bit / 8), i(0);

	while (i < n){
		pArr[1][i] = 255;
		i++;
	}

	if (i < col)
	switch (bit % 8){
	case 0: pArr[1][i] = 0; break;
	case 1: pArr[1][i] = 128; break;
	case 2: pArr[1][i] = 192; break;
	case 3: pArr[1][i] = 224; break;
	case 4: pArr[1][i] = 240; break;
	case 5: pArr[1][i] = 248; break;
	case 6: pArr[1][i] = 252; break;
	case 7: pArr[1][i] = 254; break;
	default: break;
	}
}


// Input
int getInt(){
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
void cinWait(){
	cin.clear();
	cin.sync();
	cin.get();
}