#pragma once
#include <cstdint>
#include <vector>
#include <ostream>
#include <iostream>

typedef uint_fast8_t ui8;


class CIPv4 {
private:
	//  ip_:
	//  ...[0] - octet 1
	//  ...[1] - octet 2
	//  ...[2] - octet 3
	//  ...[3] - octet 4
	std::vector<ui8>
		ip_;

public:
	const size_t & size() const;

	const ui8 & octet_get(const ui8 & ndx) const;
	void octet_set(const ui8 & ndx, const ui8 & val);

	ui8 & operator[](const int &ndx);

	void operator()(
		const ui8 & oct1,
		const ui8 & oct2,
		const ui8 & oct3,
		const ui8 & oct4
		);

	CIPv4();
	~CIPv4();
};

std::wostream & operator<<(std::wostream & wos, const CIPv4 & obj);
