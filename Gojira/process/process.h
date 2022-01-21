#ifndef __GOJIRA_PROCESS_H__
#define __GOJIRA_PROCESS_H__

#include "../include/GojiraDefs.h"
#include "../include/GContainer.h"
#include "../include/GSystem.h"
#include "process_interface.h"

struct GProcessInfo {
	GPid pid;
	GString szExeFile;
};



GArray<GProcessInfo> EnumProcess();


class Process:public ProcessImpl {
public:
	Process();
	Process(GPid pid);
	~Process();
public:
	bool openProcess(const GString& path) noexcept override;
	Gauge getProcAddrEx(const GString& moduleName, const GString& procName) noexcept override;
	GArray<GModuleInfo> getAllModuleInfo(ModuleType type) noexcept override;
	GModuleInfo getModuleInfo(const GString& moduleName, ModuleType type) noexcept override;
	Gauge getTebAddress() noexcept override;
	Gauge getPebAddress() noexcept override;
private:
	GPid hProc;
};


#endif