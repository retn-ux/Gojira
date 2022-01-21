#ifndef __GOJIRA_GKEYSTONE_H__
#define __GOJIRA_GKEYSTONE_H__
#include "../include/GojiraDefs.h"
#include "../include/GContainer.h"
#include "assembler_interface.h"

#ifdef __ARCH_86__
#include "../lib/keystone/keystone-0.9.2-win64/include/keystone/keystone.h"
#endif
#ifdef __ARCH_64__
#include "../lib/keystone/keystone-0.9.2-win64/include/keystone/keystone.h"
#endif
#ifdef __WINDOWS_SYSTEM__
#ifdef _DEBUG
#pragma comment(lib,"keystone_debug.lib")
#else
#pragma comment(lib,"keystone.lib")
#endif
#endif // __WINDOWS_SYSTEM__

class Keystone{
public:
	Keystone();
	GErrCode init(GEngineMode& mode) noexcept;
	size_t assembly(
		const GString& opcode, 
		uint64_t baseAddress, 
		GByteArray* receiver) const noexcept;
	GErrCode close() noexcept;
private:
	ks_arch ksarchAdapter(GEngineMode::Arch arch);
	ks_mode ksmodeAdapter(GEngineMode::Mode mode);
private:
	ks_engine* ks_handle;
};

#endif