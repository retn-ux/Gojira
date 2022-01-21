#ifndef __GOJIRA_ASSEMBLER_INTERFACE_H__
#define __GOJIRA_ASSEMBLER_INTERFACE_H__
#include "../include/GContainer.h"

class GEngineMode {
public:
	enum class Arch {
		ArchX86
	};
	enum class Mode {
		X32Mode,
		X64Mode
	};
public:
	GEngineMode() {}
	virtual Arch getArch() = 0;
	virtual Mode getMode() = 0;
	virtual ~GEngineMode() {}
};

class AssemblerImpl {
public:
	AssemblerImpl() {}
	virtual GErrCode init(GEngineMode* mode) noexcept = 0;
	virtual GEngineMode::Arch getArch() const noexcept = 0;
	virtual GEngineMode::Mode getMode() const noexcept = 0;
	virtual size_t assembly(
		const GString& opcode,
		uint64_t baseAddress,
		OUT GByteArray* receiver) const noexcept = 0;
	virtual size_t disasm(const GByteArray& in_byte,
		uint64_t base_addr,
		OUT GArray<GString>* receiver) const noexcept = 0;
	virtual size_t lengthDisasm(const GByteArray& in_byte, size_t min_value)const noexcept = 0;
	virtual GErrCode close() noexcept = 0;
	virtual ~AssemblerImpl() {}
};

#endif