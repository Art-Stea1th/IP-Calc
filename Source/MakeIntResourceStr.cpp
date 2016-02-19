#include "MakeIntResourceStr.h"


FMakeIntResourceStr::operator _TCHAR* () {
	return tChBuffer_;
}

FMakeIntResourceStr::FMakeIntResourceStr(
	const HINSTANCE &hInstance,
	const WORD &wStringResId,
	const INT &iBufferSize
	) {
	tChBuffer_ = new _TCHAR[iBufferSize + 1];
	tChBuffer_[iBufferSize] = _TEXT('\0');
	::LoadString(hInstance, wStringResId, tChBuffer_, iBufferSize);
}

FMakeIntResourceStr::~FMakeIntResourceStr() {
	delete[] tChBuffer_;
}