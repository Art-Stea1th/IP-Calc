#include "LoadString.h"


FLoadString::operator std::wstring () const {
	return wStrBuf_;
}

FLoadString::operator PCWSTR () const {
	return wStrBuf_.c_str();
}

FLoadString::FLoadString(const UINT &uID) {
	
	PCWSTR pcwStrBuf = nullptr;
	INT iBufSz = ::LoadStringW(GetModuleHandleW(nullptr), uID, reinterpret_cast<PWSTR>(&pcwStrBuf), 0);

	if (iBufSz > 0) {
		wStrBuf_.resize(static_cast<size_t>(iBufSz));

		while (iBufSz--)
			wStrBuf_.at(iBufSz) = pcwStrBuf[iBufSz];
	}
	else wStrBuf_.clear();
}

FLoadString::~FLoadString() { wStrBuf_.clear(); }