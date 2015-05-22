#ifndef UGCOMPRESS_H
#define UGCOMPRESS_H
#include "ugdefs.h"

namespace UGC {

//! \brief 压缩算法类。
//! \remarks 目前仅提供Zip的压缩和解压缩。
class BASE_API UGCompress  
{
public:
	//! \brief Zip 压缩函数
	/** \details 根据C++编码规范,目的参数在前,源参数在后,故而对Sm30中参数的位置和名称做了相应的改动
	压缩数据参数说明
	void *pvDestBuffer: 目标内存区域 ,dwDestLen: 目标内存区域大小
	const void *pvSrcBuffer: 源数据; UGuint dwSrcLen:源数据长度
	
	  目标内存区域需要事先开辟，至少要有 dwSrcLen * 1% + 12,	进行压缩后，
	  内存的大小会改变，dwDestLen 传出改变后的大小;
	  pvSrcBuffer和pvDestBuffer不能相同
	  参数UGint nLevel 可以取1到9之间的整数.
	  nLevel越小，压缩过程中用的内存最少，但是压缩速度慢，压缩率低;
	  nLevel越大，压缩过程中用的内存最多，但是压缩速度快，压缩率高;
	  
		compress returns Z_OK if success, Z_MEM_ERROR if there was not enough
		memory, Z_BUF_ERROR if there was not enough room in the output buffer,
		Z_STREAM_ERROR if the level parameter is invalid.
		compress2 (dest, dwDesLen, source, dwDesLen, level)
	*/
	static UGbool Zip(UGbyte *pvDestBuffer, UGuint &dwDestLen, 
		const UGbyte *pvSrcBuffer, UGuint dwSrcLen, UGint nLevel=8);
	
	//! \brief UnZip解压缩函数
	/** \details 根据C++编码规范,目的参数在前,源参数在后,故而对Sm30中参数的位置和名称做了相应的改动
	解压缩数据参数说明
	void *pvDestBuffer: 目标内存区域 ,dwDestLen: 目标内存区域大小
	const void *pvSrcBuffer: 源数据; UGuint dwSrcLen:源数据长度
	
	  目标内存区域需要事先开辟，至少要有 dwSrcLen * 101% + 12,进行解压缩后，
	  内存的大小会改变，dwDestLen传出改变后的大小;
	  pvSrcBuffer和pvDestBuffer不能相同
	  Decompress returns Z_OK if success, Z_MEM_ERROR if there was not
	  enough memory, Z_BUF_ERROR if there was not enough room in the output
	  buffer, or Z_DATA_ERROR if the input data was corrupted.
	*/
	static UGbool UnZip(UGbyte *pvDestBuffer, UGuint &dwDestLen, 
		const UGbyte *pvSrcBuffer, UGuint dwSrcLen);

};

}

#endif

