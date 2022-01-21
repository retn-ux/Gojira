#include "GAssembler.h"


X32Mode::Arch X32Mode::getArch() {
	return Arch::ArchX86;
}

X32Mode::Mode X32Mode::getMode() {
	return Mode::X32Mode;
}

X64Mode::Arch X64Mode::getArch() {
	return Arch::ArchX86;
}

X64Mode::Mode X64Mode::getMode() {
	return Mode::X64Mode;
}



Assembler::Assembler() {}
Assembler::~Assembler() {}
GErrCode Assembler::init(GEngineMode* mode) noexcept {
	this->mode = mode;
	GErrCode errcode = keystone.init(*mode);
	GUARD_GENTLE(errcode == GErrCode::SUCCESS, errcode);
	errcode = capstone.init(*mode);
	return errcode;
}
GEngineMode::Arch Assembler::getArch() const noexcept {
	return mode->getArch();
}
GEngineMode::Mode Assembler::getMode() const noexcept {
	return mode->getMode();
}
size_t Assembler::assembly(
	const GString& opcode,
	uint64_t baseAddress,
	OUT GByteArray* receiver) const noexcept {
	return keystone.assembly(opcode, baseAddress, receiver);
}
size_t Assembler::disasm(const GByteArray& in_byte,
	uint64_t base_addr,
	OUT GArray<GString>* receiver) const noexcept {
	return capstone.disasm(in_byte, base_addr, receiver);
}
size_t Assembler::lengthDisasm(const GByteArray& in_byte, size_t min_value)const noexcept {
	return capstone.lengthDisasm(in_byte, min_value);
}


GErrCode Assembler::close() noexcept {
	GErrCode errcode = keystone.close();
	GUARD_GENTLE(errcode == GErrCode::SUCCESS, errcode);
	errcode = capstone.close();
	return errcode;
}