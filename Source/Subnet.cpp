#include "Subnet.h"

void CSubnet::CalculateWildcard() {
	wildcard_ = ~netmask_;
}

void CSubnet::CalculateNetwork() {
	network_ = address_ & netmask_;
}

void CSubnet::CalculateHostMin() {
	hostmin_ = (address_ & netmask_) + 1;
}

void CSubnet::CalculateHostMax() {
	hostmax_ = (address_ | ~netmask_) - 1;
}

void CSubnet::CalculateBroadcast() {
	broadcast_ = address_ | ~netmask_;
}

void CSubnet::SetIp(const ui64 & ip) {
	address_ = ip;
}

void CSubnet::SetNetMask(const ui64 & maskBin) {
	netmask_ = maskBin;
}

void CSubnet::SetIp(
	const ui64 & oct0,
	const ui64 & oct1,
	const ui64 & oct2,
	const ui64 & oct3
	) {
	address_(oct0, oct1, oct2, oct3);
}

void CSubnet::SetBitMask(const ui_8 & maskDec) {
	maskDec ?
		netmask_ = bitLimiter32 << (
			32 - (maskDec <= 32 ? maskDec : 0)
			) :
		netmask_ = 0;
}

void CSubnet::Calculate() {
	CalculateWildcard(),
	CalculateNetwork(),
	CalculateHostMin(),
	CalculateHostMax(),
	CalculateBroadcast();
}

CIPv4 & CSubnet::operator [] (const ui64 & ndx) {
	switch (ndx) {
	case 0: return address_;
	case 1: return netmask_;
	case 2: return wildcard_;
	case 3: return network_;
	case 4: return hostmin_;
	case 5: return hostmax_;
	case 6: return broadcast_;
	default: return CIPv4(0);
	}
}

CSubnet::CSubnet() {}
CSubnet::~CSubnet() {}