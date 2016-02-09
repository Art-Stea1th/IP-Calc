#pragma once
#include <tchar.h>

#include <cstdio>
#include <conio.h>

#include <iostream>
#include <iomanip>

typedef unsigned long long ull;

void arrAlloc(int** &pArr, int row, int col),
arrRelease(int** &pArr, int row);

void arrInit(int** &pArr, int row, int col),
arrPrint(int** &pArr, int row, int col, int &bit, ull &hosts),
arrPrintDescription(int n);

void getIPandMask(int** &pArr, int row, int col, int &bit, ull &hosts);

void calculateAll(int** &pArr, int row, int col, int &bit, ull &hosts);

int getInt();