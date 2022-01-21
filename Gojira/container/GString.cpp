#include "GString.h"



GString NumberToStr(Gauge integer, int base) {
	using std::bitset;
	using std::stringstream;
	stringstream sstr;
	if (base == 2) {
		bitset<sizeof(Fword) * 8> bit_num(integer);
		sstr << bit_num;
	}
	else if (base == 8) {
		sstr << std::oct << integer;
	}
	else if (base == 10) {
		sstr << integer;
	}
	else if (base == 16) {
		sstr << std::hex << integer;
	}
	return sstr.str();
}