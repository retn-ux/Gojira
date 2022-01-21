#ifndef __GOJIRA_HOOKENGINE_H__
#define __GOJIRA_HOOKENGINE_H__

#include "../include/GojiraDefs.h"
#include "../include/GojiraIO.h"
#include "../include/GAsm.h"
#include "../include/GContainer.h"
#include "../include/GMemory.h"

#include "hook_interface.h"

typedef void (*HOOK_FUNCTION)(Dword ebp, Dword esp);

class HookEngine:public HookImpl {
public:
	HookEngine(
		StreamImpl* stream, 
		AssemblerImpl* assembler, 
		MemoryImpl* memoryManager) noexcept;
	~HookEngine();
public:
	GErrCode relativeJmpHook(void* address, void* code_addr) noexcept;
	GErrCode uninstall(void* address) noexcept override;
	GErrCode close() noexcept;
private:
	struct Debris {
		GByteArray byte_code;	//��hook��Դ����
		void* address;			//hook��ַ
		void* springboard;		//������ڴ��ַ
		size_t size;			//�ڴ��С
	};

	struct HkPage{
			MemoryBlock mb;
			GArray<Debris> debris;
			size_t remain_size;
	};
private:
	GArray<HkPage> hk_list;
	StreamImpl* stream; 
	AssemblerImpl* assembler;
	MemoryImpl* memoryManager;
};

#endif