#ifndef __GOJIRA_MEMORYINTERFACE_H__
#define __GOJIRA_MEMORYINTERFACE_H__

#include "../include/GojiraDefs.h"

class MemoryImpl {
public:
	enum class MemoryProtect {
#ifdef __WINDOWS_SYSTEM__
		PageRead = PAGE_READONLY,
		PageReadWrite = PAGE_READWRITE,
		PageExcute = PAGE_EXECUTE,
		PageExcuteRead = PAGE_EXECUTE_READ,
		PageExcuteReadWrite = PAGE_EXECUTE_READWRITE
#endif
#ifdef __LINUX_SYSTEM__
		PageRead = PROT_READ,
		PageWrite = PROT_READ | PROT_WRITE,
		PageExcute = PROT_EXEC
#endif
	};
	
public:
	MemoryImpl() {}
	virtual void* alloc(void* address,size_t size, MemoryProtect memory_protected)noexcept = 0;
	virtual GErrCode free(void* address, size_t size) noexcept = 0;
	virtual ~MemoryImpl() {};
};


#endif