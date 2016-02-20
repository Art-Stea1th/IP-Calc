#pragma once
#include "HeadersCpp.h"

typedef uint_fast8_t ui_8;
typedef uint_fast32_t ui32;
typedef uint_fast64_t ui64;


class CIPv4 {
private:

	ui32 ip_ = 0;

	static const ui_8 bitLimiter_8 = 0xff;        //  8 bit max
	static const ui32 bitLimiter32 = 0xffffffff;  // 32 bit max

public:

//   getters \ setters -   -   -   -   -   -   -   -   -   -   -   -   -

	ui_8 GetOctet(const ui_8 &ndx) const;
	void SetOctet(const ui_8 &ndx, const ui64 &val);

	const ui32 &Get() const;
	void Set(const ui64 &ip);

//   c-tors \ d-tors   -   -   -   -   -   -   -   -   -   -   -   -   -

	CIPv4(const CIPv4 &obj);

	CIPv4(
		const ui64 &oct0,
		const ui64 &oct1,
		const ui64 &oct2,
		const ui64 &oct3
		);

	CIPv4(const ui64 &val);

	CIPv4();
	~CIPv4();

//   operators -   -   -   -   -   -   -   -   -   -   -   -   -   -   -

	CIPv4 &operator = (const CIPv4 &obj);
	CIPv4 operator + (const CIPv4 &obj) const;
	CIPv4 operator - (const CIPv4 &obj) const;
	CIPv4 operator & (const CIPv4 &obj) const;
	CIPv4 operator | (const CIPv4 &obj) const;
	CIPv4 operator ~ () const;

	void operator()(
		const ui64 &oct0,
		const ui64 &oct1,
		const ui64 &oct2,
		const ui64 &oct3
		);
};