#ifndef UGTEXTCODEC_H
#define UGTEXTCODEC_H

#include "ugdefs.h"
#include "UGString.h"

namespace UGC {

//! 字符集转换器, 内部采用iconv实现
class BASE_API UGTextCodec  
{
public:
	enum Charset
	{
		ANSI = 0,
		Default = 1,
		Symbol = 2,
		MAC = 77,
		ShiftJIS = 128,
		Hangeul = 129,
		Johab	= 130,
		//! GB2312 是最核心的简体中文字符集, 而GBK是在GB2312上面的扩展,加入了很多日文和繁体字形
		//! GB18030则是最新的国家标准,它涵盖了GB2312和GBK等很多内容, 因此,我们统一用GB18030来代表中国(大陆)的字符集
		GB18030 = 134, 
		//GB2312 = 134, 
		//! Big5是台湾几个5大计算机公司搞出来的繁体字符集, 由于当时和中国(大陆)没有沟通和协商, 所以Big5和GB是不兼容的,
		//! 两者收录的字形有较大差别, 且编码有部分重叠, 因此计算机系统是无法自动识别 某个编码是 GB 还是 Big5的.
		//! 香港和澳门由于繁体字，因此也采用Big5；同时由于受葡萄牙语影响较大, 因此很多葡萄牙语也经常要和Big5混杂使用，
		//! 于是又在Big5上面进行了扩展, 最流行的为 BIG5-HKSCS:2001. 因此我们采用|BIG5-HKSCS:2001".
		ChineseBIG5 = 136, // 等同于BIG5-HKSCS:2001
		Greek = 161,
		Turkish = 162,
		Vietnamese = 163,
		Hebrew = 177,
		Arabic = 178,
		Baltic = 186,		
		Russian = 204,
		Thai = 222,
		EastEurope = 238,
		//! 从严格意义上说, UTF8,乃是UCS2,UCS4等都不是字符集,而只是Unicode的一种编码方式, 
		//! 但由于这几种使用较为频繁, 且计算机的处理上和其它字符集比较类似, 因此,都统一放在这里了.
		UTF8 = 250,
		UCS2LE = 251,//Windows默认的Unicode编码	
		UCS2BE = 252,
		UCS4LE = 253,
		UCS4BE = 254,
		OEM = 255
		//上面的为Windows系统字符编码
		/* 目前不能存储这么大的字符集，字符集范围 0~255
		UTF8 = 65536,
		UCS2LE = 65537,//Windows默认的Unicode编码	
		UCS2BE = 65538,
		UCS4LE = 65539,
		UCS4BE = 65540
		*/
	};

public:
	UGTextCodec();
	~UGTextCodec();
	UGTextCodec(const UGString& to, const UGString& from);
	UGTextCodec(Charset to, Charset from);

public:
	static UGString GetCharsetName(Charset charset);
	static Charset GetCharset(const UGString &strCharsetName);
	

public:
	// modified by jifang, 07/29/2005.
	//!\remarks 这个函数在用的时候, 是系统相关的, 要看系统所支持的编码之间的转换. 
	//!\remarks 而且直接指定字符串很容易导致打开失败, 如果能用下面的枚举参数的函数, 
	//!\remarks 就尽量用下面的重载函数, 实在不行的, 再直接用这个函数. 
	//!\remarks 总之一句话, 使用时要小心, 谨遵医嘱, 否则治死人不偿命!
	UGbool Open(const UGString& to, const UGString& from);
	
	UGbool Open(Charset to, Charset from);

	UGbool IsOpen();
	void Close();	

	//! 传入 pSource 和 nSize(按字节计)，
	//! 用target传出转换后的字符串
	//! remark 本函数适用于转换后的字符串属于MBCS（多字节编码）
	UGbool Convert(UGString& target,const UGString& source);
	UGbool Convert(UGString& target, const UGchar* pSource, UGint nSize);

	// by zengzm 2007-11-21 这几个函数 有问题(static 对象), 先封起来
	//static UGTextCodec& UGTOMBCS(Charset charset);
	//static UGTextCodec& UGTOUCS(Charset charset);
	//!\remarks if bDirction == TRUE convert the Unicode to MBCS and vice versa
	//static UGTextCodec& GetDefault(UGbool bDirection = TRUE);

	// by zengzm 2007-11-21 经过测试,发现 TextCodec的Open 100万次的时间在2秒左右,
	// 效率还马马虎虎, 因此,暂时不进行特殊的优化; 以后谁发现这个是性能瓶颈,再做针对处理

	//! 得到某个字符集转换为 UCS2LE的 转换器
	//! \param charset 字符集类型
	//! \remarks 内部采用返回特定静态对象的方式, 提高效率
	//! \return 返回转换器
//	static UGTextCodec& ToUCS2LE(Charset charset);

	//! 得把UCS2LE 转换为 某个字符集的 转换器
	//! \param charset 字符集类型
	//! \remarks 内部采用返回特定静态对象的方式, 提高效率
	//! \return 返回转换器
//	static UGTextCodec& ToUCS2LE(Charset charset);

private:
	void* m_pHandle;
	// 经过测试,发现iconv应该支持多线程, 因此把buffer放到函数内部, 以便Textcodec也能支持多线程
	// UGString m_strBuffer;
};

}

#endif

/* iconv的主页说明
European languages 
	ASCII, ISO-8859-{1,2,3,4,5,7,9,10,13,14,15,16}, KOI8-R, KOI8-U, KOI8-RU, CP{1250,1251,1252,1253,1254,1257}, CP
	{850,866}, Mac{Roman,CentralEurope,Iceland,Croatian,Romania}, Mac{Cyrillic,Ukraine,Greek,Turkish}, Macintosh 
Semitic languages 
	ISO-8859-{6,8}, CP{1255,1256}, CP862, Mac{Hebrew,Arabic} 
Japanese 
	EUC-JP, SHIFT_JIS, CP932, ISO-2022-JP, ISO-2022-JP-2, ISO-2022-JP-1 
Chinese 
	EUC-CN, HZ, GBK, CP936, GB18030, EUC-TW, BIG5, CP950, BIG5-HKSCS, BIG5-HKSCS:2001, BIG5-HKSCS:1999, ISO-2022-CN, 
	ISO-2022-CN-EXT 
Korean 
	EUC-KR, CP949, ISO-2022-KR, JOHAB 
Armenian 
	ARMSCII-8 
Georgian 
	Georgian-Academy, Georgian-PS 
Tajik 
	KOI8-T 
Kazakh 
	PT154 
Thai 
	ISO-8859-11, TIS-620, CP874, MacThai 
Laotian 
	MuleLao-1, CP1133 
Vietnamese 
	VISCII, TCVN, CP1258 
Platform specifics 
	HP-ROMAN8, NEXTSTEP 
Full Unicode 
	UTF-8 
	UCS-2, UCS-2BE, UCS-2LE 
	UCS-4, UCS-4BE, UCS-4LE 
	UTF-16, UTF-16BE, UTF-16LE 
	UTF-32, UTF-32BE, UTF-32LE 
	UTF-7 
	C99, JAVA 
Full Unicode, in terms of uint16_t or uint32_t (with machine dependent endianness and alignment) 
	UCS-2-INTERNAL, UCS-4-INTERNAL 
Locale dependent, in terms of `char' or `wchar_t' (with machine dependent endianness and alignment, and with OS and 
locale dependent semantics) 
	char, wchar_t 
	The empty encoding name "" is equivalent to "char": it denotes the locale dependent character encoding. 

When configured with the option --enable-extra-encodings, it also provides support for a few extra encodings: 
European languages 
	CP{437,737,775,852,853,855,857,858,860,861,863,865,869,1125} 
Semitic languages 
	CP864 
Japanese 
	EUC-JISX0213, Shift_JISX0213, ISO-2022-JP-3 
Chinese 
	BIG5-2003 (experimental) 
Turkmen 
	TDS565 
Platform specifics 
	ATARIST, RISCOS-LATIN1 

It can convert from any of these encodings to any other, through Unicode conversion. 
It has also some limited support for transliteration, i.e. when a character cannot be represented in the target 
character set, it can be approximated through one or several similarly looking characters. Transliteration is 
activated when "//TRANSLIT" is appended to the target encoding name. 

libiconv is for you if your application needs to support multiple character encodings, but that support lacks from 
your system. 
*/
