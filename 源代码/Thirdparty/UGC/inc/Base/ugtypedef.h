#if !defined(UGTYPEDEF_H)
#define UGTYPEDEF_H

 namespace UGC
{
		//! 象素格式
		enum PixelFormat {
			IPF_UNKNOWN			= 0,	//! 尚未设定, 内部使用
				IPF_MONO			= 1,	//! 1位,单色
				IPF_FBIT			= 4,	//! 4位,16色
				IPF_BYTE			= 8,	//! 8位,256色
				IPF_TBYTE			= 16,	//! 16位,彩色
				IPF_RGB				= 24,	//! 24位,真彩色
				IPF_RGBA			= 32,	//! 32位,增强真彩色
				IPF_TRGB			= 48,	//! 48位,真彩色
				IPF_LONGLONG		= 64,	//! 64位,长整型
				IPF_LONG			= 320,	//! LONG
				IPF_FLOAT			= 3200,	//! 32位,浮点型
				IPF_DOUBLE			= 6400	//! 64位,双精度浮点型
		};

		//色彩空间格式类型.
		typedef enum {
			ICS_RGB = 1,	//显示系统使用.
				ICS_CMY = 2,	//印刷系统使用(Cyan,Magenta,Yellow).
				ICS_YIQ = 4,	//北美电视系统使用(NTSC,Y:Luminance,Chrominance).
				ICS_YUV = 8,	//欧洲电视系统使用(PAL).
				ICS_YCC = 16	//与YUV类似,JPEG使用.
		} ImgColorSpace;
		
		//定义不同象素格式的位数.
#define IPF_MONO_BITS 1
#define IPF_FBIT_BITS 4
#define IPF_BYTE_BITS 8
#define IPF_TBYTE_BITS 16
#define IPF_RGB_BITS  24
#define IPF_RGBA_BITS 32
		
		//定义不同象素格式的颜色数.
#define IPF_MONO_COLOR	0x00000001
#define IPF_FBIT_COLOR	0x0000000F
#define IPF_BYTE_COLOR	0x000000FF
#define IPF_TBYTE_COLOR 0x0000FFFF
#define IPF_RGB_COLOR	0x00FFFFFF
#define IPF_RGBA_COLOR	0xFFFFFFFF

		///////////////////////////////////////////////////////////////////////
		//得到以Byte为单位的DWORD对齐的宽度.
#define WIDTHBYTES(bits)    (((bits) + 31) / 32 * 4) 
#define WIDTHBYTESBYTE(bits)    (((bits) + 7) / 8 )  
#define WIDTHBYTESWORD(bits)    (((bits) + 15) / 16 * 2)  

}

#endif //UGTYPEDEF_H
