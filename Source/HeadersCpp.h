#pragma once

#include <cstdint>
#include <functional>

#include <vector>
#include <string>
#include <map>

#include <ostream>



#ifdef _UNICODE
typedef std::wstring tstring;
#else
typedef std::string tstring;
#endif