#pragma once
#include <tchar.h>

#include <cstdio>
#include <conio.h>

#include <iostream>
#include <iomanip>

#include "NetInfo.h"

typedef unsigned long long ull;

void arrPrint(NetInfo &pArr, int row, int col, int &bit, ull &hosts),
arrPrintDescription(int n);

void getIPandMask(NetInfo &pArr, int row, int col, int &bit, ull &hosts);

void calculateAll(NetInfo &pArr, int row, int col, int &bit, ull &hosts);

int getInt();