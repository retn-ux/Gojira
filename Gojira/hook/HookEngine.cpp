#include "HookEngine.h"

HookEngine::HookEngine(
	StreamImpl* stream,
	AssemblerImpl* assembler,
	MemoryImpl* memoryManager)noexcept :
	stream(stream), 
	assembler(assembler), 
	memoryManager(memoryManager)  {
}


HookEngine::~HookEngine() {
	if (memoryManager != nullptr) {
		delete memoryManager;
		memoryManager == nullptr;
	}
	if (stream != nullptr) {
		delete stream;
		stream = nullptr;
	}
	if (assembler != nullptr) {
		delete assembler;
		assembler = nullptr;
	}
	
}


GErrCode HookEngine::relativeJmpHook(void* address, void* code_addr) noexcept {
	// const size_t JMP_SIZE = 5;
	// const size_t MIN_READ_SIZE = 20;
	// GByteArray readBuff(MIN_READ_SIZE);
	// const size_t MIN_ALLOC_SIZE = 0x1000;
	// ////��ȡ�ܹ���JMP��С
	// GByteArray jmp_code;
	// //size_t size = asmEngine->assembly("jmp 0x123456", toFword(address), &jmp_code);
	// //GUARD_GENTLE(size != 0, GErrCode::RESOURCE_ERROR);
	// //��ȡ20���ֽ�
	// GErrCode errcode = stream->read(address, readBuff.data(), MIN_READ_SIZE);
	// GUARD_GENTLE(errcode == GErrCode::SUCCESS, errcode);
	// //�ж���С�����ֽ�
	// size_t min_size = assembler->lengthDisasm(readBuff, JMP_SIZE);
	// GUARD_GENTLE(min_size != 0, GErrCode::RESOURCE_ERROR);
	// //����������Ŀռ�,�ɶ� ��д ��ִ��
	// void* springboard_addr = memoryManager->alloc(
	// 	nullptr,
	// 	MIN_ALLOC_SIZE,
	// 	MemoryManager::MemoryProtect::PageRead|MemoryManager::MemoryProtect::PageWrite|MemoryManager::MemoryProtect::PageExcute);
	// this->byte_code.resize(min_size);
	// std::copy(readBuff.begin(), readBuff.begin() + min_size, byte_code.begin());
	// GUARD_GENTLE(springboard_addr != nullptr, GErrCode::ALLOC_MEMORY_ERROR);
	// //д�����jmp
	// size_t size = assembler->assembly("jmp 0x"+NumberToStr(toGauge(springboard_addr),16), 
	// 	toFword(address), &jmp_code);
	// GUARD_GENTLE(size != 0, GErrCode::RESOURCE_ERROR);
	// for (size_t diff = min_size - JMP_SIZE; diff > 0; diff--) {
	// 	array_append(jmp_code, char('0x90'));
	// }
	// errcode = stream->write(address, jmp_code.data(), jmp_code.size());
	// GUARD_GENTLE(errcode == GErrCode::SUCCESS, GErrCode::WRITE_MEMORY_ERROR);
	// //д��̤�����
	// GString springboard_str;
	// if (assembler->getMode()==GEngineMode::Mode::X32Mode) {
	// 	springboard_str = "pushad\npushfd\npush ebp\npush esp\ncall 0x" +
	// 		NumberToStr(toGauge(code_addr), 16);
	// }else if(assembler->getMode() == GEngineMode::Mode::X64Mode) {
	// 	springboard_str = "pushad\npushfd\npush rbp\npush rsp\ncall 0x" +
	// 		NumberToStr(toGauge(code_addr), 16);
	// }
	// springboard_str += "\npop eax\npop eax\npopfd\npopad";
	// GByteArray springboard_byteCode;
	// size = assembler->assembly(springboard_str, toFword(springboard_addr), &springboard_byteCode);
	// GUARD_GENTLE(size != 0, GErrCode::RESOURCE_ERROR);
	// size_t byteCodeSize = springboard_byteCode.size();
	// springboard_byteCode.resize(byteCodeSize + min_size);
	// copy(readBuff.begin(), readBuff.begin() + min_size, springboard_byteCode.begin() + byteCodeSize);
	// jmp_code.clear();
	// size = assembler->assembly(
	// 	"jmp 0x" + NumberToStr(toGauge(address) + min_size, 16),
	// 	toFword(springboard_addr) + springboard_byteCode.size()
	// 	, &jmp_code);
	// GUARD_GENTLE(size != 0, GErrCode::RESOURCE_ERROR);
	// byteCodeSize = springboard_byteCode.size();
	// springboard_byteCode.resize(byteCodeSize + jmp_code.size());
	// copy(jmp_code.begin(), jmp_code.end(), springboard_byteCode.begin() + byteCodeSize);
	// errcode = stream->write(springboard_addr, springboard_byteCode.data(), springboard_byteCode.size());
	// return errcode;
	return GErrCode::SUCCESS;
}


GErrCode HookEngine::close() noexcept {
	GErrCode errcode = assembler->close();
	return errcode;
}