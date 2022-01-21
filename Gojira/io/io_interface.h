#ifndef __GOJIRA_IO_INTERFACE_H__
#define __GOJIRA_IO_INTERFACE_H__
#include "../include/GojiraDefs.h"

class StreamImpl {
public:
	StreamImpl() {}
	virtual GErrCode read(const void* const address, void* buff, size_t size) const noexcept = 0;
	virtual GErrCode write(void* address, const void* const buff, size_t size) const noexcept = 0;
	virtual ~StreamImpl() {}
};

#endif