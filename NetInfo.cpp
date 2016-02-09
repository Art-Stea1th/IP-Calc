#include "NetInfo.h"



IpRepresentation & NetInfo::operator[](const int &ndx) {
	switch (ndx) {
	case 0: return ipaddress_;
	case 1: return networkmask_;
	case 2: return wildcard_;
	case 3: return network_;
	case 4: return hostmin_;
	case 5: return hostmax_;
	case 6: return broadcast_;
	default:
		break;
	}
}

NetInfo::NetInfo() {}
NetInfo::~NetInfo() {}