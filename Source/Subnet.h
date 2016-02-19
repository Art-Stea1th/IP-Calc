#pragma once
#include "IPv4.h"


class CSubnet {

	CIPv4 address_;
	CIPv4 netmask_;
	CIPv4 wildcard_;
	CIPv4 network_;
	CIPv4 hostmin_;
	CIPv4 hostmax_;
	CIPv4 broadcast_;

	static const ui32 bitLimiter32 = 0xffffffff;  // 32 bit max

	void CalculateWildcard();
	void CalculateNetwork();
	void CalculateHostMin();
	void CalculateHostMax();
	void CalculateBroadcast();

public:

	void SetIp(const ui64 &ip);
	void	SetIp(
		const ui64 &oct0,
		const ui64 &oct1,
		const ui64 &oct2,
		const ui64 &oct3
		);
	void	SetNetMask(const ui64 &netmask);
	void	SetBitMask(const ui_8 &bitmask);

	void Calculate();

//   c-tors \ d-tors   -   -   -   -   -   -   -   -   -   -   -   -   -

	CSubnet();
	~CSubnet();

//   operators -   -   -   -   -   -   -   -   -   -   -   -   -   -   -

	CIPv4 & operator [] (const ui64 &ndx);
	
};