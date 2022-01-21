#include "process.h"


GArray<GProcessInfo> EnumProcess() {
	GArray<GProcessInfo> result;
	const Dword SIZE = 1024;
	char imagePath[MAX_PATH];
	GArray<Dword> pid_array;
	pid_array.resize(SIZE);
	Dword lpcbNeeded = 0;
	GUARD_GENTLE(EnumProcesses(pid_array.data(), pid_array.size(), &lpcbNeeded), std::move(result));

	for (Dword i = 0; i < (lpcbNeeded / sizeof(Dword)); i++) {
		GProcessInfo proc;
		proc.pid = OpenProcess(PROCESS_QUERY_INFORMATION, false, pid_array[i]);
		if (proc.pid == INVALID_PID) {
			continue;
		}
		if (GetModuleFileNameExA(proc.pid, nullptr, imagePath, MAX_PATH) != 0) {
			proc.szExeFile = imagePath;
		}
		result.push_back(proc);
	}
	return std::move(result);
}


Process::Process():hProc(INVALID_PID) {
}

Process::Process(GPid pid):hProc(pid) {
}

Process::~Process() {
}

bool Process::openProcess(const GString& path) noexcept {
#ifdef __WINDOWS_SYSTEM__
	GArray<GProcessInfo> processInfos = EnumProcess();
	GUARD_GENTLE(processInfos.size() != 0, false);
	GPid pid = INVALID_PID;
	for (GProcessInfo& info : processInfos) {
		if (info.szExeFile == path) {
			pid = info.pid;
			break;
		}
		else {
			CloseHandle(info.pid);
		}
	}
	GUARD_GENTLE(pid != INVALID_PID, false);
	this->hProc = pid;
#endif
	return true;
}

Gauge Process::getProcAddrEx(const GString& moduleName, const GString& procName) noexcept {
	GModuleInfo moduleInfo = getModuleInfo(moduleName, ProcessImpl::ModuleType::ModuleListAll);
	HMODULE hModule = LoadLibraryA(moduleInfo.thePath.c_str());
	if (hModule == 0) {
		return 0;
	}
	Gauge address = (Gauge)GetProcAddress(hModule, procName.c_str());
	Gauge offset = address - reinterpret_cast<Gauge>(hModule);
	return reinterpret_cast<Gauge>(moduleInfo.lpBaseOfDll) + offset;
}



GArray<GModuleInfo> Process::getAllModuleInfo(ModuleType type) noexcept {
	GArray<GModuleInfo> result;
	GModuleInfo moduleInfo;

	char theBaseName[MAX_PATH];
	char path[MAX_PATH];
	Dword lpcbNeeded = 0;
	//��ȡģ���С
	GUARD_GENTLE(EnumProcessModulesEx(
		hProc,
		nullptr,
		0,
		&lpcbNeeded,
		static_cast<Dword>(type)), std::move(result));
	HMODULE* module = new HMODULE[lpcbNeeded];
	//��ȡģ����
	if (!EnumProcessModulesEx(hProc, module, lpcbNeeded, &lpcbNeeded, static_cast<Dword>(type))) {
		if (module != nullptr)delete module;
		return std::move(result);
	}
	MODULEINFO mi;
	//��ȡģ�����Ϣ
	for (Dword i = 0; i < lpcbNeeded; i++) {	
		GetModuleInformation(hProc, module[i], &mi, sizeof(mi));
		moduleInfo.lpBaseOfDll = mi.lpBaseOfDll;
		moduleInfo.SizeOfImage = mi.SizeOfImage;
		moduleInfo.EntryPoint = mi.EntryPoint;
		GetModuleBaseNameA(hProc, module[i], theBaseName, sizeof(theBaseName));
		moduleInfo.theBaseName = theBaseName;
		GetModuleFileNameExA(hProc, module[i], path, sizeof(path));
		moduleInfo.thePath = path;
		result.push_back(moduleInfo);
	}
	delete[] module;
	return std::move(result);
}


GModuleInfo Process::getModuleInfo(const GString& moduleName, ModuleType type) noexcept {
	GModuleInfo moduleInfo;

	char theBaseName[MAX_PATH];
	char path[MAX_PATH];
	Dword lpcbNeeded = 0;
	//��ȡģ���С
	GUARD_GENTLE(EnumProcessModulesEx(
		hProc,
		nullptr,
		0,
		&lpcbNeeded,
		static_cast<Dword>(type)), std::move(moduleInfo));
	HMODULE* module = new HMODULE[lpcbNeeded];
	//��ȡģ����
	if (!EnumProcessModulesEx(hProc, module, lpcbNeeded, &lpcbNeeded, static_cast<Dword>(type))) {
		if (module != nullptr)delete module;
		return std::move(moduleInfo);
	}
	MODULEINFO mi;
	//��ȡģ�����Ϣ
	for (Dword i = 0; i < lpcbNeeded; i++) {
		GetModuleBaseNameA(hProc, module[i], theBaseName, sizeof(theBaseName));
		if (theBaseName == moduleName) {
			moduleInfo.theBaseName = theBaseName;
			GetModuleInformation(hProc, module[i], &mi, sizeof(mi));
			moduleInfo.lpBaseOfDll = mi.lpBaseOfDll;
			moduleInfo.SizeOfImage = mi.SizeOfImage;
			moduleInfo.EntryPoint = mi.EntryPoint;

			GetModuleFileNameExA(hProc, module[i], path, sizeof(path));
			moduleInfo.thePath = path;
			break;
		}
	}
	delete[] module;
	return std::move(moduleInfo);

}



Gauge Process::getTebAddress() noexcept {
	//THREAD_BASIC_INFORMATION tbi;
	//ulong relen;

	//NtQueryInformationThread(hThread, ThreadBasicInformation, &tbi, sizeof(tbi), &relen);
	//return toGauge(tbi.TebBaseAddress);
	return 0;
}

Gauge Process::getPebAddress()noexcept {
	GUARD_GENTLE(hProc != INVALID_PID && hProc != nullptr, 0);
	if (hProc == GetCurrentProcess()) {
		return toGauge(NtCurrentTeb()->teb.ProcessEnvironmentBlock);
	}
	PROCESS_BASIC_INFORMATION pbi;
	memset(&pbi, 0, sizeof(PROCESS_BASIC_INFORMATION));
	ulong relen;

	NtQueryInformationProcess(hProc, ProcessBasicInformation, &pbi, sizeof(PROCESS_BASIC_INFORMATION), &relen);

	return pbi.PebBaseAddress;
	return 0;
}