#pragma once

#include "HeadersCpp.h"
#include "HeadersWin.h"


class FLoadString {
private:
	
	UINT uID_;
	const tstring &tStrConvert(const UINT &uID) const;

public:

	operator const tstring &() const;
	operator PCTSTR () const;

	FLoadString(const UINT &uID);
	~FLoadString();
};