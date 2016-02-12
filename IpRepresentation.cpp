#include "IpRepresentation.h"


const size_t & IpRepresentation::size() const {
	return ip_.size();
}

const ui8 & IpRepresentation::octet_get(const ui8 & ndx) const {
	return ip_.at(ndx);
}

void IpRepresentation::octet_set(const ui8 & ndx, const ui8 & val) {
	//try {
	//	if (val > std::numeric_limits<ui8>::max())
	//		throw(std::exception("out of range \"uint_fast8_t\" type"));
		ip_.at(ndx) = val;
	//}
	//catch (const std::exception& a) { std::wcout << "\n\nException: " << a.what() << "\n\n"; }
	//catch (...) { std::wcout << "\n\nException: unknown\n\n";	}
}

ui8 & IpRepresentation::operator[](const int & ndx) {
	return ip_.at(ndx);
}

void IpRepresentation::operator()(
	const ui8 & oct1,
	const ui8 & oct2,
	const ui8 & oct3,
	const ui8 & oct4
	) {
	ip_.resize(4),
		octet_set(0, oct1),
		octet_set(1, oct2),
		octet_set(2, oct3),
		octet_set(3, oct4);
}

IpRepresentation::IpRepresentation() { this->operator()(0, 0, 0, 0); }
IpRepresentation::~IpRepresentation() { ip_.clear(); }


std::wostream & operator<<(std::wostream & wos, const IpRepresentation & obj) {
	wos 
		<< obj.octet_get(0) << L'.'
		<< obj.octet_get(1) << L'.'
		<< obj.octet_get(2) << L'.'
		<< obj.octet_get(3);
	return wos;
}