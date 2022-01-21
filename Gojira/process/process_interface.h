#ifndef __GOJIRA_PROCESSINTERFACE_H__
#define __GOJIRA_PROCESSINTERFACE_H__
#include "../include/GojiraDefs.h"
#include "../include/GContainer.h"

struct GModuleInfo {
	void* lpBaseOfDll;	//基地址
	Dword SizeOfImage;	//模块占用的线性空间的大小（以字节为单位）。 
	void* EntryPoint;	//模块的入口点。
	GString theBaseName;
	GString thePath;
};



class ProcessImpl {
public:
	enum class ModuleType {
		ModuleList32Bit = 1,
		ModuleList64Bit = 2,
		ModuleListAll = (ModuleList32Bit | ModuleList64Bit)
	};
public:
	ProcessImpl() {}
	virtual Gauge getProcAddrEx(const GString& dllName, const GString& procName) noexcept = 0;
	virtual GArray<GModuleInfo> getAllModuleInfo(ModuleType type) noexcept = 0;
	virtual GModuleInfo getModuleInfo(const GString& moduleName, ModuleType type) noexcept = 0;
	virtual bool openProcess(const GString& path) noexcept = 0;
	virtual Gauge getTebAddress() = 0;
	virtual Gauge getPebAddress() = 0;
	virtual ~ProcessImpl() {}
};
#endif