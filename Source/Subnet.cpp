#include "Subnet.h"
#include <iomanip>
#include <conio.h>

//  == Temporary methods solution  =====
///  == Transferred from the old func. ==

/// Fill support_arr | 256 | 128 | 64 | 32 | 16 | 8 | 4 | 2 | 1 |
void CSubnet::fill_support_arr() {
	for (int i(0); i < support_size_; i++)
		support_arr.push_back(static_cast<short>(pow(2, (support_size_ - 1 - i))));
}

/// * 1. Netmask
void CSubnet::calculate_netmask() {
	for (int i(0); i <= bitmask_ / 8 && i < oct_count_; i++) {
		if (i != bitmask_ / 8) netinfo_[1][i] = support_arr[0] - support_arr[support_size_ - 1];
		else netinfo_[1][i] = support_arr[0] - support_arr[bitmask_ % 8];
	}
}

/// * 2. Wildcard
void CSubnet::calculate_wildcard() {
	for (int i(0); i < oct_count_; i++)
		netinfo_[2][i] = support_arr[0] - support_arr[support_size_ - 1] - netinfo_[1][i];
}

/// * 3. Network
void CSubnet::calculate_network() {
	for (int i(0); i < oct_count_; i++) {
		if (i < bitmask_ / 8) netinfo_[3][i] = netinfo_[0][i];
		else if (i == bitmask_ / 8) {
			netinfo_[3][i] = netinfo_[0][i];
			while (netinfo_[3][i] + netinfo_[2][i] > support_arr[0] - support_arr[support_size_ - 1]) {
				netinfo_[3][i]--;
			}
			if (netinfo_[3][i] > 0) netinfo_[3][i]--;
		}
	}
}

/// * 4. Host Min
void CSubnet::calculate_hostmin() {
	for (int i(0); i < oct_count_; i++) {
		if (i != oct_count_ - 1) netinfo_[4][i] = netinfo_[3][i];
		else netinfo_[4][i] = netinfo_[3][i] + 1;
	}
}

/// * 5. Host Max
void CSubnet::calculate_hostmax() {
	for (int i(0); i < oct_count_; i++) {
		if (i < bitmask_ / 8) netinfo_[5][i] = netinfo_[0][i];
		else {
			if (i != oct_count_ - 1) netinfo_[5][i] = netinfo_[3][i] + netinfo_[2][i];
			else netinfo_[5][i] = netinfo_[3][i] + netinfo_[2][i] - 1;
		}
	}
}

/// * 6. Broadcast
void CSubnet::calculate_broadcast() {
	for (int i(0); i < oct_count_; i++) {
		if (i < bitmask_ / 8) netinfo_[6][i] = netinfo_[0][i];
		else netinfo_[6][i] = netinfo_[3][i] + netinfo_[2][i];
	}
}

/// * 7. Hosts
void CSubnet::calculate_hosts() {
	hosts_ = 1;
	for (int i(0); i < oct_count_; i++)
		hosts_ *= (netinfo_[2][i] + 1);
}

void CSubnet::calculate() {
	calculate_netmask();
	calculate_wildcard();
	calculate_network();
	calculate_hostmin();
	calculate_hostmax();
	calculate_broadcast();
	calculate_hosts();
	/// Exception for 32bit
	if (bitmask_ == 32) {
		for (int i(0); i < oct_count_; i++) {
			if (netinfo_[5][oct_count_ - 1 - i] > 0) {
				netinfo_[5][oct_count_ - 1 - i]--;
				break;
			}
			else netinfo_[5][oct_count_ - 1 - i] = support_arr[0] - support_arr[support_size_ - 1];
		}
	}
}

///  ====================================

const size_t & CSubnet::size() const {
	return netinfo_.size();
}

CIPv4 & CSubnet::operator[](const int &ndx) {
	return netinfo_.at(ndx);
}

ui8 & CSubnet::bitmask() {
	return bitmask_;
}

ui32 & CSubnet::hosts() {
	return hosts_;
}

CSubnet::CSubnet() { netinfo_.resize(7); fill_support_arr(); }
CSubnet::~CSubnet() { netinfo_.clear(); }
