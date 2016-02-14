#pragma once
#include "IPv4.h"


class CSubnet {

	CIPv4
		address_,
		netmask_,
		wildcard_,
		network_,
		hostmin_,
		hostmax_,
		broadcast_;

	static const ui32 bitLimiter32 = 0xffffffff;  // 32 bit max

	void
		CalculateWildcard(),
		CalculateNetwork(),
		CalculateHostMin(),
		CalculateHostMax(),
		CalculateBroadcast();

public:

	void
		SetIp(const ui64 & ip),
		SetIp(
			const ui64 & oct0,
			const ui64 & oct1,
			const ui64 & oct2,
			const ui64 & oct3
			),
		SetNetMask(const ui64 & maskBin),
		SetBitMask(const ui_8 & maskDec);

	void Calculate();

	CIPv4 & operator [] (const ui64 & ndx);

	CSubnet();
	~CSubnet();
};