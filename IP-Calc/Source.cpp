// Art.Stea1th (Stanislav Kuzmitch)
// Calculator IPv4, Mask, first-last IP, Broadcast etc.
#include <cstdio>
#include <conio.h>

#include <iostream>
using namespace std;

void IPArrAlloc(int** &pArr, int row, int col),
	 IPArrRelease(int** &pArr, int row);

void IPArrInit(int** &pArr, int row, int col),
	 IPArrPrint(int** &pArr, int row, int col);

int GetInt();
void CinWait();

// Entry point
int main(){
	int **IPArr = NULL;
	int col(4), row(7);

	IPArrAlloc(IPArr, row, col);
	IPArrInit(IPArr, row, col);
	IPArrPrint(IPArr, row, col);
	IPArrRelease(IPArr, row);	

	CinWait();
	return 0;
}

// Allocates memory for an array
void IPArrAlloc(int** &pArr, int row, int col){
	pArr = new int*[row];

	for (int i(0); i < row; i++)
		pArr[i] = new int[col];
}
// Release memory for an array
void IPArrRelease(int** &pArr, int row){
	
	for (int i(0); i < row; i++)
		delete[] pArr[i];

	delete[] pArr;
}

// Init Array
void IPArrInit(int** &pArr, int row, int col){

	for (int i(0); i < row; i++)
		for (int j(0); j < col; j++)
			pArr[i][j] = 0;
}
// Print Array
void IPArrPrint(int** &pArr, int row, int col){

	for (int i(0); i < row; i++){
		for (int j(0); j < col; j++){
			cout << pArr[i][j];
			if (j != col - 1) cout << '.';
		}
		cout << '\n';
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