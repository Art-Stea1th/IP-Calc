#include "NetInfo.h"
#include <iomanip>

///  == Temporary methods solution  =====
///  == Transferred from the old func. ==

/// Fill support_arr | 256 | 128 | 64 | 32 | 16 | 8 | 4 | 2 | 1 |
void NetInfo::fill_support_arr() {
	for (int i(0); i < support_size_; i++)
		support_arr.push_back(static_cast<int>(pow(2, (support_size_ - 1 - i))));
}

/// * 1. Netmask
void NetInfo::calculate_netmask() {
	for (int i(0); i <= bitmask_ / 8 && i < oct_count_; i++) {
		if (i != bitmask_ / 8) netinfo_[1][i] = support_arr[0] - support_arr[support_size_ - 1];
		else netinfo_[1][i] = support_arr[0] - support_arr[bitmask_ % 8];
	}
}

/// * 2. Wildcard
void NetInfo::calculate_wildcard() {
	for (int i(0); i < oct_count_; i++)
		netinfo_[2][i] = support_arr[0] - support_arr[support_size_ - 1] - netinfo_[1][i];
}

/// * 3. Network
void NetInfo::calculate_network() {
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
void NetInfo::calculate_hostmin() {
	for (int i(0); i < oct_count_; i++) {
		if (i != oct_count_ - 1) netinfo_[4][i] = netinfo_[3][i];
		else netinfo_[4][i] = netinfo_[3][i] + 1;
	}
}

/// * 5. Host Max
void NetInfo::calculate_hostmax() {
	for (int i(0); i < oct_count_; i++) {
		if (i < bitmask_ / 8) netinfo_[5][i] = netinfo_[0][i];
		else {
			if (i != oct_count_ - 1) netinfo_[5][i] = netinfo_[3][i] + netinfo_[2][i];
			else netinfo_[5][i] = netinfo_[3][i] + netinfo_[2][i] - 1;
		}
	}
}

/// * 6. Broadcast
void NetInfo::calculate_broadcast() {
	for (int i(0); i < oct_count_; i++) {
		if (i < bitmask_ / 8) netinfo_[6][i] = netinfo_[0][i];
		else netinfo_[6][i] = netinfo_[3][i] + netinfo_[2][i];
	}
}

/// * 7. Hosts
void NetInfo::calculate_hosts() {
	hosts_ = 1;
	for (int i(0); i < oct_count_; i++)
		hosts_ *= (netinfo_[2][i] + 1);
}

void NetInfo::calculate() {
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

void NetInfo::show_to_console() const {
	using namespace std;
	system("cls");

	wcout << L"\n   IPv4 Calculator by Art.Stea1th (Stanislav Kuzmitch)\n\n";

	for (int i(0); i < 80; i++) wcout << L'-';

	wcout << L"\n";
	for (int i(0); i < netinfo_.size(); i++) {
		show_to_console_description(i);
		for (int j(0); j < oct_count_; j++) {
			wcout << setw(3) << netinfo_.at(i).octet_get(j);
			if (j != oct_count_ - 1) wcout << L'.';
		}
		if (i == 1) wcout << L" | " << bitmask_ << L" bit\n";
		else if (i == 2) wcout << L"\n\n";
		else wcout << L'\n';
	}
	wcout << L'\n' << setw(16) << L"Hosts: " << setw(15) << hosts_ << L"\n\n";

	for (int i(0); i < 80; i++) wcout << L'-';

	wcout << L"\n";
}

void NetInfo::show_to_console_description(const ui8 & n) const {
	using namespace std;

	switch (n) {
	case 0: wcout << setw(16) << L"Adress: "; break;
	case 1: wcout << setw(16) << L"Netmask: "; break;
	case 2: wcout << setw(16) << L"Wildcard: "; break;
	case 3: wcout << setw(16) << L"Network: "; break;
	case 4: wcout << setw(16) << L"Host Min: "; break;
	case 5: wcout << setw(16) << L"Host Max: "; break;
	case 6: wcout << setw(16) << L"Broadcast: "; break;
	default: wcout << setw(16); break;
	}
}

///  ====================================

const ui8 & NetInfo::size() const {
	return netinfo_.size();
}

IpRepresentation & NetInfo::operator[](const int &ndx) {
	return netinfo_.at(ndx);
}

ui8 & NetInfo::bitmask() {
	return bitmask_;
}

ui32 & NetInfo::hosts() {
	return hosts_;
}

NetInfo::NetInfo() { netinfo_.resize(7); fill_support_arr(); }
NetInfo::~NetInfo() { netinfo_.clear(); }