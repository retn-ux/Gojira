#ifndef __GOJIRA_HOOKINTERFACE_H__
#define __GOJIRA_HOOKINTERFACE_H__

#include "../include/GojiraDefs.h"

class HookImpl {
public:
	HookImpl() {}
	virtual GErrCode relativeJmpHook(void* address, void* code_addr) noexcept = 0;
	virtual GErrCode uninstall(void* address) noexcept = 0;
	virtual GErrCode close() noexcept = 0 ;
	virtual ~HookImpl() {}
};

#endif