#ifndef __GOJIRA_MP3DEFS_H__
#define __GOJIRA_MP3DEFS_H__

//Mp3ID3V2LabelHeader.flag
#define ID3V2_LH_FLAG_UNSYNCHRONISATION 0x80
#define ID3V2_LH_FLAG_EXTENSION_HEADER	0x40
#define ID3V2_LH_FLAG_TEST_TAB	0x20
#define GetMp3ID3V2Size(size)\
	(size & 0x7F000000)*0x200000+ (size & 0x7F0000)*0x400 + (size & 0x7F00)*0x80 +(size & 0x7F) 





//ID3v2的标签头
struct Mp3ID3V2LabelHeader {
	char sign[3];	//标志 ID3
	char version;	//版本
	char reversion;	//副版本	一般为0
	char flag;		//标志，只有高3位有效
	Dword size;	//标签大小，包括标签头的10 个字节和所有的标签帧的大小
};


//Mp3ID3V2LFHeader.id
#define ID3V2_LFH_ID_TIT2 0x54495432 //标题 "TIT2"
#define ID3V2_LFH_ID_TPE1 0x54504531 //专辑 "TPE1"
#define ID3V2_LFH_ID_TRCK 0x5452434b //音轨格式：N/M 其中N 为专集中的第N 首，M为专集中共M 首，N和M 为ASCII 码表示的数字 "TRCK"
#define ID3V2_LFH_ID_TYER 0x54594552 //年代是用ASCII 码表示的数字 "TYER"
#define ID3V2_LFH_ID_TCON 0x54434f4e //类型直接用字符串表示 "TCON"
#define ID3V2_LFH_ID_COMM 0x434f4d4d //备注，字符串 "COMM"

//Mp3ID3V2LFHeader.flag
#define ID3V2_LFH_FLAG_LABEL_PROTECTION 0x8000	//标签保护标志，设置时认为此帧作废
#define ID3V2_LFH_FLAG_FILE_PROTECTION 0x4000	//文件保护标志，设置时认为此帧作废
#define ID3V2_LFH_FLAG_READ_ONLY 0x2000	//只读标志，设置时认为此帧不能修改
#define ID3V2_LFH_FLAG_COMPRESSION 0x80 //压缩标志，设置时一个字节存放两个BCD 码表示数字 
#define ID3V2_LFH_FLAG_ENCRYPTION 0x40 //加密标志
#define ID3V2_LFH_FLAG_GROUP 0x20 //组标志，设置时说明此帧和其他的某帧是一组

//获取标签帧内容的大小，不包括标签帧头部
#define GetMp3ID3V2LFBodySize(size)\
	(size & 0xFF000000)*0x100000000 + (size & 0xFF0000)*0x10000+ (size & 0xFF00)*0x100 + (size & 0xFF); 

struct Mp3AudioFrameHeader {
	Dword sync:11;                        //同步信息
	Dword version:2;                      //版本	00:MPEG_2.5 01:MPEG_2 11:MPEG_1
	Dword layer: 2;                       //层 	00:undefine 01:Layer_3 10:Layer:2 11:Layer_1 
	Dword crc:1;						//CRC校验标志 0:校验 1:不校验
	Dword bit_rate:4;					//位率
	Dword sampling_frequency:2;			//采样频率
	Dword padding:1;					//帧长调节
	Dword private:1;					//保留
	Dword channel_mode;					//声道模式
	Dword extended_mode;				//扩充模式,当声道模式为01才可使用
	Dword copyright;					//版权 0-不合法 1-合法
	Dword original;						//是否为原版
	Dword emphasis;						//强调方式，用于声音降噪压缩后再补偿的分类
};

//ID3v2标签帧的头部
struct Mp3ID3V2LFHeader{
	Dword id;		//帧标识
	Dword size;	//帧内容大小，不包括头部大小，不小于1
	Word flag;	//存放标识
}

#endif // !__GOJIRA_MP3DEFS_H__
