#include "GSystemExp.h"

#ifdef __WINDOWS_SYSTEM__

bool NtQueryInformationProcess(
	IN HANDLE ProcessHandle,
	IN PROCESSINFOCLASS ProcessInformationClass,
	OUT PVOID           ProcessInformation,
	IN ULONG            ProcessInformationLength,
	OUT PULONG          ReturnLength) {
	HMODULE hModule = GetModuleHandle(NTDLL_LIB_NAME);
	PfnNtQueryInformatioProcess fun_ptr = (PfnNtQueryInformatioProcess)GetProcAddress(hModule, "NtQueryInformationProcess");
	GUARD_GENTLE(fun_ptr != nullptr, false);
	if (!NTSTATUS_SUCCESS(fun_ptr(
		ProcessHandle,
		ProcessInformationClass,
		ProcessInformation,
		ProcessInformationLength,
		ReturnLength))) {
		return false;

	}
	return true;
}

bool RtlCreateThread(
	IN HANDLE               ProcessHandle,
	IN PSECURITY_DESCRIPTOR SecurityDescriptor OPTIONAL,
	IN BOOLEAN              CreateSuspended,
	IN ULONG                StackZeroBits,
	IN OUT PULONG           StackReserved,
	IN OUT PULONG           StackCommit,
	IN PVOID                StartAddress,
	IN PVOID                StartParameter OPTIONAL,
	OUT PHANDLE             ThreadHandle,
	OUT PCLIENT_ID          ClientID) {
	HMODULE hModule = GetModuleHandle(NTDLL_LIB_NAME);
	PfnRtlCreateProcess fun_ptr = (PfnRtlCreateProcess)GetProcAddress(hModule, "RtlCreateProcess");
	GUARD_GENTLE(fun_ptr != nullptr, false);
	if (!NTSTATUS_SUCCESS(fun_ptr(
		ProcessHandle,
		SecurityDescriptor,
		CreateSuspended,
		StackZeroBits,
		StackReserved,
		StackCommit,
		StartAddress,
		StartParameter,
		ThreadHandle,
		ClientID
	))) {
		return false;
	};
	return true;
}

bool ZwTerminateThread(HANDLE hThread, ULONG uExitCode) {
	HMODULE hModule = GetModuleHandle(NTDLL_LIB_NAME);
	PfnZwTerminateThread fun_ptr = (PfnZwTerminateThread)GetProcAddress(hModule, "ZwTerminateThread");
	GUARD_GENTLE(fun_ptr != NULL, false);
	if (!NTSTATUS_SUCCESS(fun_ptr(hThread, uExitCode))) {
		return false;
	}
	return true;
}



bool NtQueryInformationThread(
	IN HANDLE          ThreadHandle,
	IN THREADINFOCLASS ThreadInformationClass,
	OUT PVOID          ThreadInformation,
	IN ULONG           ThreadInformationLength,
	OUT PULONG         ReturnLength
) {
	HMODULE hModule = GetModuleHandle(NTDLL_LIB_NAME);
	PfnNtQueryInformationThread fun_ptr = (PfnNtQueryInformationThread)GetProcAddress(hModule, "NtQueryInformationThread");
	GUARD_GENTLE(fun_ptr != NULL, false)
		if (!NTSTATUS_SUCCESS(fun_ptr(ThreadHandle, ThreadInformationClass, ThreadInformation, ThreadInformationLength, ReturnLength))) {
			return false;
		}
	return true;

}



bool NtQuerySystemInformation(
	IN SYSTEM_INFORMATION_CLASS SystemInformationClass,
	OUT PVOID                   SystemInformation,
	IN ULONG                    SystemInformationLength,
	OUT PULONG                  ReturnLength
) {
	HMODULE hModule = GetModuleHandle(NTDLL_LIB_NAME);
	PfnNtQuerySystemInformation fun_ptr = (PfnNtQuerySystemInformation)GetProcAddress(hModule, "NtQuerySystemInformation");
	GUARD_GENTLE(fun_ptr != nullptr, false);
	if (!NTSTATUS_SUCCESS(fun_ptr(SystemInformationClass, SystemInformation, SystemInformationLength, ReturnLength))) {
		return false;
	}
	return true;
}






/*
bool GetSystemProcessInfo(HANDLE handle) {
	SYSTEM_INFO sysInfo;
	GetSystemInfo(&sysInfo);
	//ϵͳӦ�ó�����СѰַ��ַ
	PBYTE lpAddress = (PBYTE)sysInfo.lpMinimumApplicationAddress;

	while(lpAddress<(PBYTE)sysInfo.lpMaximumApplicationAddress){
		MEMORY_BASIC_INFORMATION memoryInfo;
		ZeroMemory(&memoryInfo, sizeof(MEMORY_BASIC_INFORMATION));
		SIZE_T size = VirtualQueryEx(handle,lpAddress, &memoryInfo, sizeof(MEMORY_BASIC_INFORMATION));
		if (size == 0) {
			return false;
		}
		if (memoryInfo.State == MEM_COMMIT) {
			if (memoryInfo.Type == MEM_IMAGE) {
				if (GetMappedFileName(handle,) {

				}
			}
		}
		else if (memoryInfo.State = MEM_RESERVE) {
			lpAddress += memoryInfo.RegionSize;
			continue;
		}
		lpAddress += sysInfo.dwPageSize;
	}
}
*/







bool RtlAdjustPrivilege
(
	ULONG    Privilege,
	BOOLEAN Enable,
	BOOLEAN CurrentThread,
	PBOOLEAN Enabled
) {
	HMODULE hModule = GetModuleHandle(NTDLL_LIB_NAME);
	PfnRtlAdjustPrivilege fun_ptr = (PfnRtlAdjustPrivilege)GetProcAddress(hModule, "RtlAdjustPrivilege");
	GUARD_GENTLE(fun_ptr != nullptr, false);
	if (!NTSTATUS_SUCCESS(fun_ptr(Privilege, Enable, CurrentThread, Enabled))) {
		return false;
	}
	return true;

}


bool ZwShutdownSystem(SHUTDOWN_ACTION action) {
	HMODULE hModule = GetModuleHandle(NTDLL_LIB_NAME);
	PfnZwShutdownSystem fun_ptr = (PfnZwShutdownSystem)GetProcAddress(hModule, "ZwShutdownSystem");
	GUARD_GENTLE(fun_ptr != nullptr, false);
	if (!NTSTATUS_SUCCESS(fun_ptr(action))) {
		return false;
	}
	return true;
}


bool NtRaiseHardError
(
	IN NTSTATUS             ErrorStatus,
	IN ULONG                NumberOfParameters,
	IN PUNICODE_STRING      UnicodeStringParameterMask OPTIONAL,
	IN PVOID* Parameters,
	IN HARDERROR_RESPONSE_OPTION ResponseOption,
	OUT PHARDERROR_RESPONSE Response
) {
	HMODULE hModule = GetModuleHandle(NTDLL_LIB_NAME);
	PfnNtRaiseHardError fun_ptr = (PfnNtRaiseHardError)GetProcAddress(hModule, "NtRaiseHardError");
	GUARD_GENTLE(fun_ptr != nullptr, false);
	fun_ptr(ErrorStatus, NumberOfParameters, UnicodeStringParameterMask, Parameters, ResponseOption, Response);
	return true;

}
#endif