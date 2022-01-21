#include "PEDosHeader.h"
bool IsPEDosHeader(const IMAGE_DOS_HEADER& header){
    const Word DosHeaderMagic=0x4D5A;
    if(header.e_magic==DosHeaderMagic){
        return true;
    }
    return false;
}


PEDosHeader::PEDosHeader() :
    address(nullptr) 
{
}

GErrCode PEDosHeader::init(void* address,StreamImpl& stream){
    GErrCode errcode=stream.read(address,&dos_header,sizeof(dos_header));
    GUARD_GENTLE(errcode == GErrCode::SUCCESS, errcode);
    if(!IsPEDosHeader(dos_header))
    {
        return GErrCode::FILE_FORMAT_ERROR;
    }
    this->address = address;
    return GErrCode::SUCCESS;
}

IMAGE_DOS_HEADER* PEDosHeader::header() noexcept {
    return &dos_header;
}
GErrCode PEDosHeader::write(StreamImpl& stream) noexcept {
    return stream.write(address, &dos_header, sizeof(dos_header));
}