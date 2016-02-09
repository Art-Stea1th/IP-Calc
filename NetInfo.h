#pragma once
#include "IpRepresentation.h"

typedef uint_fast32_t ui32;

class NetInfo {
	IpRepresentation
		ipaddress_,
		networkmask_,
		wildcard_,
		network_,
		hostmin_,
		hostmax_,
		broadcast_;
	ui32
		hosts_;
public:

	IpRepresentation & operator[](const int &ndx);

	NetInfo();
	~NetInfo();
};

