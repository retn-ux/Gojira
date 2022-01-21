#ifndef __GOJIRA_GCAPSTONE_H__
#define __GOJIRA_GCAPSTONE_H__
#include "../include/GojiraDefs.h"
#include "../include/GContainer.h"
#include "assembler_interface.h"

#ifdef __ARCH_86__
#include "../lib/capstone/x32/include/capstone/capstone.h"
#endif
#ifdef __ARCH_64__
#include "../lib/capstone/x64/include/capstone/capstone.h"
#endif
#ifdef __WINDOWS_SYSTEM__ 
#pragma comment(lib,"capstone.lib")
#endif


class Capstone {
public:
	Capstone();
	GErrCode init(GEngineMode& mode) noexcept;
	size_t disasm(const GByteArray& in_byte, 
				uint64_t base_addr, 
				GArray<GString>* receiver) const noexcept;
	size_t lengthDisasm(const GByteArray& in_byte, size_t min_value)const noexcept;
	GErrCode close() noexcept;
private:
	cs_arch csarchAdapter(GEngineMode::Arch arch);
	cs_mode csmodeAdapter(GEngineMode::Mode mode);
private:
	csh cs_handle;
};


#endif