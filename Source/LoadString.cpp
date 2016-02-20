#include "LoadString.h"


const tstring &FLoadString::tStrConvert(const UINT &uID) const {

	PCTSTR tChBuffer = nullptr;
	INT len = ::LoadString(GetModuleHandle(NULL), uID, reinterpret_cast<PTSTR>(&tChBuffer), 0);

	return len
		? tstring(tChBuffer, static_cast<size_t>(len))
		: tstring();
}

FLoadString::operator const tstring &() const {
	return tStrConvert(uID_);
}

FLoadString::operator PCTSTR () const {
	return tStrConvert(uID_).c_str();
}

FLoadString::FLoadString(const UINT &uID) : uID_(uID) {}

FLoadString::~FLoadString() {}