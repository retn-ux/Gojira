#ifndef __GOJIRA_GOJIRADEFS_H__
#define __GOJIRA_GOJIRADEFS_H__

#include <cassert>


#include "Gojira.h"

#define OUT
#define IN

typedef unsigned long Dword;
typedef unsigned short Word;
typedef unsigned char Byte;

#ifdef __LINUX_SYSTEM__
typedef u_int64_t Fword;
#endif

#ifdef __WINDOWS_SYSTEM__
typedef unsigned __int64 Fword;
#endif
typedef unsigned long ulong;
typedef unsigned short ushort;

#ifdef __ARCH_86__
typedef Dword Gauge;
#endif
#ifdef __ARCH_64__
typedef Fword Gauge;
#endif


#define GUARD_SEVERE assert
#define GUARD_GENTLE(pred,ret) if(!(pred))return ret;
#define GUARD_EXCEPT(predi,except) if(!(predi))throw except;



#define toWord(d)\
	reinterpret_cast<Word>(d)

#define toVoidPtr(d)\
	reinterpret_cast<void*>(d)

#define toGauge(v)\
	reinterpret_cast<Gauge>(v)

#define toDword(v)\
	reinterpret_cast<Dword>(v)

#define toFword(v)\
	reinterpret_cast<Fword>(v)


#ifdef __WINDOWS_SYSTEM__
typedef HANDLE GPid;	//����id
typedef Dword pid_t;
#define INVALID_PID INVALID_HANDLE_VALUE 
#endif

#ifdef __LINUX_SYSTEM__
typedef pid_t GPid;
#define INVALID_PID 0;
#endif

#ifdef __WINDOWS_SYSTEM__
#ifdef __HRESULT_INFO__
#define HRESULT_CLASS_SUCCESS 0
#define HRESULT_CLASS_CONTAINS_INFORMATION 1
#define HRESULT_CLASS_WARNNING 2
#define HRESULT_CLASS_ERROR 3
//��HRESULT�л�ȡ���
#define GetClassFormValue(hresult,_class)\
	_class=hresult&0xC0000000;\
	_class >>= 30;

#define HRESULT_USER_DEFINE 1
#define HRESULT_NOT_USER_DEFINE 0
#define GetDefineClassFromValue(hresult,_class)\
	_class=hresult&0x20000000;\
	_class >>= 29;


#define GetFacilityFromValue(hresult,_class)\
	_class=hresult&0x1FFF0000;\
	_class>>=16;


#define GetResultCodeFromValue(hresult,_class)\
	_class=hresult&0xFFFF;


#endif // __WIN__
#endif

	


//�쳣����
enum class GErrCode {
	//��������
	SUCCESS,
	//��ַ����
	ADDRESS_ERROR,
	ADDRESS_BLANK,			//�յ�ַ
	ADDRESS_NOT_ACCESS,		//��ַ�޷�����
	//��Դ����
	RESOURCE_ERROR,
	GET_RESOURCE_ERROR,		//��ȡ��Դ����
	RELEASE_RESOURCE_ERROR, //�ͷ���Դ����

	INVALID_HANDLE,			//��Ч�ľ���������ϵľ��
	INVALID_PARAMETER,		//��Ч�Ĳ���

	READ_MEMORY_ERROR,		//��ȡ�ڴ����
	WRITE_MEMORY_ERROR,		//д���ڴ����

	TYPE_ERROR,				//���ʹ���

	ALLOC_MEMORY_ERROR,		//�����ڴ����

	CHANGE_PROTECT_ERROR,	//�ı��ڴ����Դ���

	FILE_FORMAT_ERROR
};

struct MemoryBlock{
	void* begin;
	size_t size;
};

#endif


