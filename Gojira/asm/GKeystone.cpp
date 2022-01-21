#include "GKeystone.h"


Keystone::Keystone():ks_handle(nullptr) {}

GErrCode Keystone::init(GEngineMode& mode) noexcept {
	if (ks_handle == nullptr) {
		ks_err _Errno = ks_open(
			ksarchAdapter(mode.getArch()),
			ksmodeAdapter(mode.getMode()),
			&ks_handle);
		if (_Errno == ks_err::KS_ERR_ARCH || _Errno == ks_err::KS_ERR_MODE) {
			return GErrCode::INVALID_PARAMETER;
		}
		else if (_Errno != ks_err::KS_ERR_OK) {
			return GErrCode::GET_RESOURCE_ERROR;
		}
	}
	return GErrCode::SUCCESS;
}

size_t Keystone::assembly(
	const GString& opcode,
	uint64_t baseAddress,
	OUT GByteArray* receiver) const noexcept 
{
	Byte* encoding = nullptr;
	size_t size = 0;
	size_t success_count = 0;
	if (ks_asm(ks_handle, opcode.c_str(), baseAddress, &encoding, &size, &success_count) == 0) {	
		array_ptr_muti_append(receiver, encoding, size);
		ks_free(encoding);
		return success_count;
	}
	return 0;
}
GErrCode Keystone::close() noexcept {
	if (ks_handle != nullptr) {
		ks_err _Errno = ks_close(ks_handle);
		GUARD_GENTLE(_Errno == KS_ERR_OK, GErrCode::RELEASE_RESOURCE_ERROR);
	}
	return GErrCode::SUCCESS;
}


ks_arch Keystone::ksarchAdapter(GEngineMode::Arch arch) {
	ks_arch ksarch;
	switch (arch) {
	case GEngineMode::Arch::ArchX86:
		ksarch = ks_arch::KS_ARCH_X86;
		break;
	}
	return ksarch;
}
ks_mode Keystone::ksmodeAdapter(GEngineMode::Mode mode) {
	ks_mode ksmode;
	switch (mode) {
	case GEngineMode::Mode::X32Mode:
		ksmode = ks_mode::KS_MODE_32;
		break;
	case GEngineMode::Mode::X64Mode:
		ksmode = ks_mode::KS_MODE_64;
		break;
	}
	return ksmode;
}