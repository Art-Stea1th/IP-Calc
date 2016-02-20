#pragma once

#include "HeadersCpp.h"
#include "HeadersWin.h"

class FLoadString {
private:

	std::wstring wStrBuf_;

public:

	operator std::wstring () const;
	operator PCWSTR () const;

	FLoadString(const UINT &uID);
	~FLoadString();
};