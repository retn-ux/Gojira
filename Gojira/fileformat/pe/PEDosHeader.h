#ifndef __GOJIRA_PEDOSHEADER_H__
#define __GOJIRA_PEDOSHEADER_H__
#include "../../include/GojiraDefs.h"
#include "../../include/GojiraIO.h"
#include "PEDefs.h"

bool IsPEDosHeader(const IMAGE_DOS_HEADER& header);

class PEDosHeader{
public:
    PEDosHeader();
    GErrCode init(void* address,StreamImpl& stream);
    IMAGE_DOS_HEADER* header() noexcept;
    GErrCode write(StreamImpl& stream) noexcept;
private:
    void* address;
    IMAGE_DOS_HEADER dos_header;
};

#endif