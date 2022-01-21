#include "GCapstone.h"

Capstone::Capstone():cs_handle(0) {}


GErrCode Capstone::init(GEngineMode& mode) noexcept {
	if (cs_handle == 0) {
		cs_err err = cs_open(
			csarchAdapter(mode.getArch()),
			csmodeAdapter(mode.getMode()),
			&cs_handle);
		if (err == cs_err::CS_ERR_ARCH || err == cs_err::CS_ERR_MODE) {
			return GErrCode::INVALID_PARAMETER;
		}
		else if (err != cs_err::CS_ERR_OK) {
			return GErrCode::GET_RESOURCE_ERROR;
		}
	}
	return GErrCode::SUCCESS;
}


size_t 
Capstone::disasm(
	const GByteArray& in_byte,
	uint64_t base_addr, 
	OUT GArray<GString>* receiver)const noexcept 
{
	size_t count = 0;
	cs_insn* insn;
	count = cs_disasm(cs_handle, in_byte.data(), in_byte.size(), base_addr, 0, &insn);
	if (count > 0) {
		for (size_t i = 0; i < count; i++) {
			array_ptr_append(receiver,insn->op_str);
		}
		cs_free(insn, count);
	}
	return count;
}

size_t Capstone::lengthDisasm(const GByteArray& in_byte, size_t min_value) const noexcept {
	size_t count = 0;
	Gauge td = 0;
	cs_insn* insn;
	count = cs_disasm(cs_handle, in_byte.data(), in_byte.size(), 0, min_value, &insn);
	if (count > 0) {
		for (size_t i = 0; i < count; i++) {
			td += insn[i].size;
			if (td >= min_value) {
				cs_free(insn, count);
				return td;
			}
		}
	}
	cs_free(insn, count);
	return 0;
}


GErrCode Capstone::close() noexcept {
	if (cs_handle != 0) {
		cs_err _Errno = cs_close(&cs_handle);
		GUARD_GENTLE(_Errno == CS_ERR_OK, GErrCode::RELEASE_RESOURCE_ERROR);
		return GErrCode::SUCCESS;
	}
}


cs_arch Capstone::csarchAdapter(GEngineMode::Arch arch) {
	cs_arch csarch;
	switch (arch) {
	case GEngineMode::Arch::ArchX86:
		csarch = cs_arch::CS_ARCH_X86;
		break;
	}
	return csarch;
}
cs_mode Capstone::csmodeAdapter(GEngineMode::Mode mode) {
	cs_mode csmode;
	switch (mode) {
	case GEngineMode::Mode::X32Mode:
		csmode = cs_mode::CS_MODE_32;
		break;
	case GEngineMode::Mode::X64Mode:
		csmode = cs_mode::CS_MODE_64;
		break;
	}
	return csmode;
}