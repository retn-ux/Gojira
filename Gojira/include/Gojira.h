#ifndef __GOJIRA_GOJIRA_H__
#define __GOJIRA_GOJIRA_H__

#define __WINDOWS_SYSTEM__
#define __ARCH_64__

#ifdef _X86
#define __ARCH_86__
#elif _X64
#define __ARCH_64__
#endif

#ifdef __WINDOWS_SYSTEM__

#include <Windows.h>
#include <TlHelp32.h>
#include <bcrypt.h>
#include <Psapi.h>
#pragma comment(lib,"Psapi.lib")
#endif

#ifdef __LINUX_SYSTEM__
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#endif

#endif