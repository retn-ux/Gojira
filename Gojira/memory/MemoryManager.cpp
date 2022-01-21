#include "MemoryManager.h"


void* MemoryManager::alloc(
	void* address,
	size_t size,
	MemoryProtect memory_protected) noexcept 
{
	void* result = nullptr;
#ifdef __WINDOWS_SYSTEM__
	result = VirtualAllocEx(
		GetCurrentProcess(), 
		address, size, 
		MEM_RESERVE | MEM_COMMIT,
		static_cast<Dword>(memory_protected));
#endif
#ifdef __LINUX_SYSTEM__
	result=mmap(address, size, static_cast<int>(memory_protected), MAP_PRIVATE | MAP_ANONYMOUS  , -1, 0);
#endif
	return result;
}



GErrCode MemoryManager::free(void* address, size_t size) noexcept {
#ifdef __WINDOWS_SYSTEM__
	GUARD_GENTLE(VirtualFreeEx(GetCurrentProcess(), address, 0, MEM_RELEASE),
		GErrCode::RELEASE_RESOURCE_ERROR);
	GUARD_GENTLE(VirtualFreeEx(GetCurrentProcess(), address, 0, MEM_DECOMMIT),
		GErrCode::RELEASE_RESOURCE_ERROR);
#endif
#ifdef __LINUX_SYSTEM__
		GUARD_GENTLE(munmap(address,size)==0, GErrCode::RELEASE_RESOURCE_ERROR);
#endif
	return GErrCode::SUCCESS;
}