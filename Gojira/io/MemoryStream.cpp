#include "MemoryStream.h"



GErrCode MemoryStream::read(
	const void* const address,
	void* buff,
	size_t size) const noexcept
{
	GUARD_GENTLE(address != nullptr && buff != nullptr && size != 0, GErrCode::INVALID_PARAMETER);
	Gauge write_size = 0;
#ifdef __WINDOWS_SYSTEM__
	GUARD_GENTLE(
		ReadProcessMemory(GetCurrentProcess(), address, buff, size, &write_size),
		GErrCode::READ_MEMORY_ERROR);
#endif
	return GErrCode::SUCCESS;

}


GErrCode MemoryStream::write(
	void* address,
	const void* const buff,
	size_t size) const noexcept
{
	GUARD_GENTLE(address != nullptr && buff != nullptr && size != 0, GErrCode::INVALID_PARAMETER);
	Gauge write_size = 0;
#ifdef __WINDOWS_SYSTEM__
	GUARD_GENTLE(
		WriteProcessMemory(GetCurrentProcess(), address, buff, size, &write_size),
		GErrCode::WRITE_MEMORY_ERROR);
#endif
	return GErrCode::SUCCESS;

}