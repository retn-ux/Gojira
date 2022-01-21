#ifndef __GOJIRA_GASSEMBLER_H__
#define __GOJIRA_GASSEMBLER_H__

#include "../include/GojiraDefs.h"
#include "../include/GContainer.h"
#include "assembler_interface.h"
#include "GKeystone.h"
#include "GCapstone.h"


class X32Mode:public GEngineMode {
public:
	X32Mode() {}
	virtual Arch getArch();
	virtual Mode getMode();
	virtual ~X32Mode() {}
};

class X64Mode :public GEngineMode {
public:
	X64Mode() {}
	virtual Arch getArch();
	virtual Mode getMode();
	virtual ~X64Mode() {}
};

class Assembler :public AssemblerImpl {
public:
	Assembler();
	virtual ~Assembler();
public:
	GErrCode init(GEngineMode* mode) noexcept override;
	virtual GEngineMode::Arch getArch() const noexcept override;
	virtual GEngineMode::Mode getMode() const noexcept override;
	virtual size_t assembly(
		const GString& opcode,
		uint64_t baseAddress,
		OUT GByteArray* receiver) const noexcept override;
	virtual size_t disasm(const GByteArray& in_byte,
		uint64_t base_addr,
		OUT GArray<GString>* receiver) const noexcept override;
	virtual size_t lengthDisasm(const GByteArray& in_byte, size_t min_value)const noexcept override;
	GErrCode close() noexcept override;
private:
	Keystone keystone;
	Capstone capstone;
	GEngineMode* mode;
};


#endif