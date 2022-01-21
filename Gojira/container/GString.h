#ifndef __GOJIRA_GSTRING_H__
#define __GOJIRA_GSTRING_H__
#include <string>
#include <bitset>
#include <sstream>
#include "../include/GojiraDefs.h"

using GString = std::string;
using GWString = std::wstring;

GString NumberToStr(Gauge integer, int base = 10);



#endif // !__GOJIRA_GSTRING_H__
