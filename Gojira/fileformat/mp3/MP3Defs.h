#ifndef __GOJIRA_MP3DEFS_H__
#define __GOJIRA_MP3DEFS_H__

#define ID3V2_FLAG_UNSYNCHRONISATION 0x80
#define ID3V2_FLAG_EXTENSION_HEADER	0x40
#define ID3V2_FLAG_TEST_TAB	0x20
#define GetID3V2Size(size)\
	(Size[0]&0x7F)*0x200000+ (Size[1]&0x7F)*0x400 + (Size[2]&0x7F)*0x80 +(Size[3]&0x7F) 


struct FrameHeader {

};



struct Mp3ID3V2Header {
	char sign[3];	//��־ ID3
	char version;	//�汾
	char reversion;	//���汾	һ��Ϊ0
	char flag;		//��־��ֻ�и�3λ��Ч
	char size[4];	//��С
};

struct Mp3ID3V2 {

};

#endif // !__GOJIRA_MP3DEFS_H__
