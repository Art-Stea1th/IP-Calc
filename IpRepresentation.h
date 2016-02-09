#pragma once
#include <cstdint>
#include <vector>
#include <ostream>
#include <iostream>

typedef uint_fast8_t ui8;


class IpRepresentation {
private:
	std::vector<ui8>
		ip_;

public:
	const ui8 & octet_get(const ui8 & ndx) const;
	void octet_set(const ui8 & ndx, const ui8 & val);

	ui8 & operator[](const int &ndx);

	void operator()(
		const ui8 & oct1,
		const ui8 & oct2,
		const ui8 & oct3,
		const ui8 & oct4
		);

	IpRepresentation();
	~IpRepresentation();
};

std::wostream & operator<<(std::wostream & wos, const IpRepresentation & obj);