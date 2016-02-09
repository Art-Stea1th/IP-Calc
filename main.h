#pragma once
#include <tchar.h>

#include <cstdio>
#include <conio.h>

#include <iostream>
#include <iomanip>

#include "NetInfo.h"

typedef unsigned long long ull;

void Print(NetInfo &netinfo);
void PrintDescription(int n);

void GetIPandMask(NetInfo &netinfo);

void CalculateAll(NetInfo &netinfo);

int GetInt();