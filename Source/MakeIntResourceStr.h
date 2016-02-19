#pragma once

#include "HeadersWin.h"


class FMakeIntResourceStr {

	_TCHAR* tChBuffer_;

public:

	operator _TCHAR* ();

	FMakeIntResourceStr(
		const HINSTANCE &hInstance,
		const WORD &wStringResId,
		const INT &iBufferSize
		);
	~FMakeIntResourceStr();
};