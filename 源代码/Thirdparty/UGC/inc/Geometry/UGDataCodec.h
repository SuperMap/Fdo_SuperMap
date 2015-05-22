/*! \file	 UGDataCodec.h
 *  \brief	 空间数据编码类的定义
 *  \author	 ugc team
 *  \attention 
 *  Copyright(c) 1996-2004 SuperMap GIS Technologies,Inc.<br>
 *  All Rights Reserved
 *  \version $Id: UGDataCodec.h,v 1.23 2007/11/16 06:08:51 zhouqin Exp $
 */


#ifndef UGDATACODEC_H
#define UGDATACODEC_H

#include "Base/ugdefs.h"
#include "Algorithm/UGPoint2D.h"
#include "UGImgBlock.h"
#include "Base/UGArray.h"
#include "Base/UGMemoryStream.h"


namespace UGC {

//! 空间数据编码类
class GEOMETRY_API UGDataCodec  
{
public:
	//! 编码类型
	enum CodecType
	{
		encNONE		= 0,	//! 不使用编码方式
		encBYTE		= 1,	//! 使用BYTE(1)类型存储
		encWORD		= 2,	//! 使用WORD(2)类型存储
		enc3BYTE	= 3,	//! 使用3字节类型存储
		encDWORD	= 4,	//! 使用4字节类型存储
		//encFLOAT	= 5,	//! 使用float类型存储
		encDOUBLE	= 0,	//! 使用doubel类型存储		
		encDCT		= 8,	//! Image的压缩
		encSGL		= 9,	//! SuperMap Grid LZW encoded.
		encLGL		= 10,	//! another Grid LZW encoded.
		encLZW		= 11,	//! 适用于索引色影像的压缩方式，无损
	};

public:
	//! \brief 把一个点串按照指定的编码方式进行编码，并输出到给定的缓存中
	//! \param pPoints 要编码的点串的指针
	//! \param nPointCount 要编码的点串的点个数
	//! \param buf[out] 输出的缓存
	//! \param eType 编码方式, 支持encBYTE, encWORD, enc3BYTE, encDWORD四种编码方式
	//! \param rcBounds 点串的Bounds, 函数内部要使用;
	//!		对于Geometry,可以用Geometry的GetBounds方法;对于非Geometry内的点串,可以用UGOpPoints的Bounds方法
	//! \remarks 主要用于矢量数据集编码使用
	//! \return 成功返回true,失败返回false
	static UGbool Encode( const UGPoint2D* pPoints, UGint nPointCount,
		UGArray<UGuchar>& buf, CodecType eType, const UGRect2D& rcBounds);

	//! \brief Encode SDBPlus
	static UGbool EncodeSDB( const UGPoint2D* pPoints, UGint nPointCount,
		UGArray<UGuchar>& buf, CodecType eType, const UGRect2D& rcBounds);

	//! \brief 和Encode功能类似,不同在于输出中不包含left,bottom和GridSize
	//! \remarks 一般使用Encode, 本函数仅在缓存文件等特殊地方使用
	static UGbool EncodeStatic( const UGPoint2D* pPoints, UGint nPointCount,
		UGArray<UGuchar>& buf, CodecType eType, UGdouble dLeft,UGdouble dBottom,
		UGdouble dXGridSize,UGdouble dYGridSize);

	/*static UGbool Encode(const UGPoint2GSetReferencePoints( UGPoint2D* pPoints, UGint nCount )
		CodecType eType, 
		const UGRect2DComputeBounds*/

	//! \brief 从数据区中解码得到点串, 和 Encode 方法相对应
	//! \param pPoints 得到的点串, 注意点串的空间要事先分配好
	//! \param pRawData 数据区指针
	//! \param nRawSize 数据区的大小(字节)
	//! \param eType 编码方式, 支持encBYTE, encWORD, enc3BYTE, encDWORD四种编码方式
	//! \return 成功返回true,失败返回false
	static UGbool Decode(UGPoint2D* pPoints, const UGuchar* pRawData, UGint nRawSize, CodecType eType);

	//! \brief SDBPlus
	static UGbool DecodeSDB(UGPoint2D* pPoints, UGint nPointCount,UGStream &stream, CodecType eType,const UGRect2D& rcBounds);	

	//! \brief 和 EncodeStatic 对应的解码方法
	static UGbool DecodeStatic(UGPoint2D* pPoints,const UGuchar* pRawData,UGint nRawSize,
		UGdouble dLeft,UGdouble dBottom,UGdouble dXGridSize,UGdouble dYGridSize, CodecType eType);

	//! \brief 影像块编码
	static UGint Encode(UGImgBlock * pImgBlock,
		PixelFormat ipf,
		UGbyte *&pBuffer,
		UGuint &nBufferSize,
		UGint nNoValue,
		CodecType eType,
		UGint nQuality = 75);

	//! \brief 影像块解码
	static UGbool Decode(UGImgBlock* pImgBlock,
		const UGuchar* pRawData,
		UGint nRawSize,
		UGint nNoValue,
		CodecType encType);

private:
	//! \brief 把uint类型的最小的三个字节存储到stream中
	static void Save3Byte(UGStream& stream, UGuint value);
	//! \brief 从stream中读取三个字节（最小），构成一个uint
	static UGuint Load3Byte(UGStream& stream);

	static UGint Block2DCT(UGbyte * &pData,UGImgBlock* ImgBlock,UGint nQuality);
	static UGint DCT2Block(UGbyte * pData,UGint nSize,UGImgBlock* ImgBlock);

// 	//! \brief 		压缩数据
// 	//! \return 	UGint			返回数据长度
// 	//! \param 		nPixelFormat	DEM数据的像素格式，可用值：
// 	//!								IPF_FLOAT, IPF_DOUBLE
// 	//! \param 		*pSrcData       数据指针
// 	//! \param 		lWidth			数据大小
// 	//! \param 		cx				数据长宽
// 	//! \param 		cy
// 	//! \param 		dMinZ			最大值
// 	//! \param 		dMaxZ           最小值
// 	//! \param 		*pDestData      压缩后的数据指针
// 	//! \remarks 		
// 	static UGint EncDEM(UGint nPixelFormat, 
// 					 UGbyte *pSrcData, 
// 					 UGint lWidth,
// 					 UGint cx,UGint cy,
// 					 UGdouble dMinZ, 
// 					 UGdouble dMaxZ, 
// 					 UGbyte *pDestData);
// 
// 	//! \brief 		解压缩
// 	//! \return 	UGbool
// 	//! \param 		nPixelFormat
// 	//! \param 		*pSrcData
// 	//! \param 		lWidth
// 	//! \param 		cx
// 	//! \param 		cy
// 	//! \param 		&dMinZ
// 	//! \param 		&dMaxZ
// 	//! \param 		*pDestData
// 	//! \remarks 		
	static UGbool DecDEM(UGint nPixelFormat,
					 UGbyte *pSrcData, 
					 UGint lWidth,
					 UGint cx,UGint cy,
					 UGdouble &dMinZ, 
					 UGdouble &dMaxZ, 
					 UGbyte *pDestData);

	static UGint EncDEM(UGImgBlock& imgBlock, UGMemoryStream& streamBlock);

//	static UGbool DecDEM(UGImgBlock& imgBlock, UGMemoryStream& streamBlock, UGint nNoValue);

	
	// SuperMap Grid LZW 编码 
	static UGbool EncSGL(UGImgBlock& imgBlock, UGMemoryStream& streamBlock, UGint nNoValue);
	//{{
	static void SGL_SaveOneValue(UGdouble dValue, UGint nBitCount, UGMemoryStream& streamBlock );

	static void SGL_SaveSeperatorValues(UGdouble* pValues, UGint nCount, UGMemoryStream& streamBlock, 
										UGdouble dMinValue, UGint nBitCount);
	static void SGL_SaveSameValues(UGdouble dValue, UGint nCount, UGMemoryStream& streamBlock, 
									UGdouble dMinValue, UGint nBitCount);
	static void SGL_SaveNoValues(UGint nCount, UGMemoryStream& streamBlock);

	static void SGL_EndSave(UGMemoryStream& streamBlock, UGint nStartPos);
	//}}
	// SuperMap Grid LZW 解码
	static UGbool DecSGL(UGImgBlock& imgBlock, UGMemoryStream& streamBlock, UGint nNoValue);
	// {{
	static UGdouble SGL_LoadOneValue(UGMemoryStream& streamBlock, UGint nValueSize);
	static void SGL_LoadSeperatorValues(UGdouble *dValues, UGint nCount,
										UGMemoryStream& streamBlock,  UGint nTileType, UGdouble dMinValue);
	static UGbyte GetStoreBitCount(UGint nValue);
	// }}

};
}

#endif /*UGDATACODEC_H*/
