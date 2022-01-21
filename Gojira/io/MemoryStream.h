#ifndef __GOJIRA_MEMORYSTREAM_H__
#define __GOJIRA_MEMORYSTREAM_H__


#include "../include/GojiraDefs.h"
#include "io_interface.h"

class MemoryStream:public StreamImpl {
public:
	virtual GErrCode read(const void* const address, void* buff, size_t size) const noexcept override;
	virtual GErrCode write(void* address, const void* const buff, size_t size) const noexcept override;
};

#endif