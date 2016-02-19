#include "IPv4.h"

//   getters \ setters -   -   -   -   -   -   -   -   -   -   -   -   -

ui_8 CIPv4::GetOctet(const ui_8 &ndx) const {
	switch (ndx) {
	case 0: return (ip_ >> 24) & bitLimiter_8;
	case 1: return (ip_ >> 16) & bitLimiter_8;
	case 2: return (ip_ >> 8) & bitLimiter_8;
	case 3: return ip_ & bitLimiter_8;
	}
	return static_cast<ui_8>(0);
}

void CIPv4::SetOctet(const ui_8 &ndx, const ui64 &val) {
	switch (ndx) {
	case 0: ip_ |= ((val & bitLimiter_8) << 24); break;
	case 1: ip_ |= ((val & bitLimiter_8) << 16); break;
	case 2: ip_ |= ((val & bitLimiter_8) << 8); break;
	case 3: ip_ |= (val & bitLimiter_8); break;
	}
}

const ui32 &CIPv4::Get() const {
	return ip_;
}

void CIPv4::Set(const ui64 &ip) {
	ip_ = ip & bitLimiter32;
}

//   c-tors \ d-tors   -   -   -   -   -   -   -   -   -   -   -   -   -

CIPv4::CIPv4(const CIPv4 &obj) {
	ip_ = obj.ip_;
}

CIPv4::CIPv4(
	const ui64 &oct0,
	const ui64 &oct1,
	const ui64 &oct2,
	const ui64 &oct3
	) {
	this->operator()(oct0, oct1, oct2, oct3);
}

CIPv4::CIPv4(const ui64 &val) {
	ip_ = (val & bitLimiter32);
}

CIPv4::CIPv4()
	: CIPv4(0) {
}

CIPv4::~CIPv4() { ip_ = 0; }

//   operators -   -   -   -   -   -   -   -   -   -   -   -   -   -   -

CIPv4 &CIPv4::operator = (const CIPv4 &obj) {
	if (&obj != this) ip_ = obj.ip_;
	return *this;
}

CIPv4 CIPv4::operator + (const CIPv4 &obj) const {
	return CIPv4(ip_ + obj.ip_);
}

CIPv4 CIPv4::operator - (const CIPv4 &obj) const {
	return CIPv4(ip_ - obj.ip_);
}

CIPv4 CIPv4::operator & (const CIPv4 &obj) const {
	return CIPv4(ip_ & obj.ip_);
}

CIPv4 CIPv4::operator | (const CIPv4 &obj) const {
	return CIPv4(ip_ | obj.ip_);
}

CIPv4 CIPv4::operator ~ () const {
	return CIPv4(~ip_);
}

void CIPv4::operator()(
	const ui64 &oct0,
	const ui64 &oct1,
	const ui64 &oct2,
	const ui64 &oct3
	) {
	SetOctet(0, oct0);
	SetOctet(1, oct1);
	SetOctet(2, oct2);
	SetOctet(3, oct3);
}

std::wostream &operator << (std::wostream &wos, const CIPv4 &obj) {
	return wos
		<< obj.GetOctet(0) << L'.'
		<< obj.GetOctet(1) << L'.'
		<< obj.GetOctet(2) << L'.'
		<< obj.GetOctet(3);
}