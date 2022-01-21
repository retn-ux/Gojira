#ifndef __GOJIRA_MEMORYMANAGER_H__
#define __GOJIRA_MEMORYMANAGER_H__

#include "../include/GojiraDefs.h"
#include "memory_interface.h"

class MemoryManager :public MemoryImpl {
public:
	virtual void* alloc(void* address, size_t size, MemoryProtect memory_protected) noexcept override;
	virtual GErrCode free(void* address, size_t size) noexcept override;
	virtual ~MemoryManager() {}
};

#endif