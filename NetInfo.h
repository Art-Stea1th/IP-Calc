#pragma once
#include "IpRepresentation.h"

typedef uint_fast32_t ui32;

class NetInfo {
	//  netinfo_:
	//      ...[0] - IP Address
	//      ...[1] - Network Mask
	//      ...[2] - Wildcard
	//      ...[3] - Network
	//      ...[4] - HostMin
	//      ...[5] - HostMax
	//      ...[6] - Broadcast
	std::vector<IpRepresentation>
		netinfo_;

	//  bitmask_ max = 32
	ui8	bitmask_ = 0;

	//  hosts_ max = unsigned int
	ui32 hosts_ = 0;

	///  == Temporary methods solution  =====

	///  == Temp fields =====================
	const int oct_count_ = 4;
	const int support_size_ = 9;
	std::vector<short> support_arr;

	///  == Transferred from the old func. ==
	void
		fill_support_arr(),
		calculate_netmask(),
		calculate_wildcard(),
		calculate_network(),
		calculate_hostmin(),
		calculate_hostmax(),
		calculate_broadcast(),
		calculate_hosts();	
	///  ====================================

public:

	///  == Temporary methods solution  =====
	///  == Transferred from the old func. ==
	void calculate();
	void show_to_console() const;
	void show_to_console_description(const ui8 & n) const;
	///  ====================================

	const ui8 & size() const;

	IpRepresentation & operator[](const int &ndx);
	ui8 & bitmask();
	ui32 & hosts();	

	NetInfo();
	~NetInfo();
};