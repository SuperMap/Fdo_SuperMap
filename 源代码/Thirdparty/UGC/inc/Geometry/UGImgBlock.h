/*! \file	 UGImgBlock.h
 *  \brief	 影像块类
 *  \author	 ugc team
 *  \attention 
 *  Copyright(c) 1996-2004 SuperMap GIS Technologies,Inc.<br>
 *  All Rights Reserved
 *  \version $Id: UGImgBlock.h,v 1.14 2007/11/16 06:05:09 zhouqin Exp $
 */

#ifndef UGIMGBLOCK_H
#define UGIMGBLOCK_H

#include "Base/ugdefs.h"
#include "Algorithm/UGSize.h"
#include "Algorithm/UGRect2D.h"
#include "Base/UGColorset.h"
#include "UGImgScanline.h"

#define UG_IMG_NOVALUE -9999 


namespace UGC {

//! 影像块类
class GEOMETRY_API UGImgBlock  
{
public:
	//! 构造函数
	UGImgBlock();
	//! 析构函数
	~UGImgBlock();
	void Create(PixelFormat ePixelFormat, 
					UGint nBlockRowIndex, 
					UGint nBlockColIndex, 
					UGint nPixelRowIndex,
					UGint nPixelColIndex,
					UGint nWidth,
					UGint nHeight,
					UGSize validSize,
					UGColorset * pColorset,
					UGbool bInited,
					UGint nWidthBytes
					);

	//! 获取字节宽度
	UGint GetWidthBytes();

	UGbool IsModified() const {
		return m_bModified;
	}

	void SetModifiedFlag(UGbool bFlag = TRUE) {
		m_bModified = bFlag;
	}

	//! 清空数据，释放内存
	void Empty(){
		m_Data.RemoveAll();
	};

	//! 是否有效对象
	UGbool IsValid() const {
		//! wait to implement
		return TRUE;
	}	
	
	UGint GetByteSize() const {
		return m_Data.GetSize();
	}	

	void SetByteSize(const UGint nNewSize)
	{
		m_Data.SetSize(nNewSize);
	}
			
	UGbyte* GetBlockData() const {
		return const_cast<UGuchar*>(m_Data.GetData());
	}	

	//! 设置Pixel
	UGbool SetPixel(UGint x,UGint y,UGint nPixel);
	
	//! 获取Pixel
	UGint GetPixel(UGint x,UGint y);
	
	//! 设置Value
	UGbool SetValue(UGint x,UGint y,UGdouble dValue);
	
	//! 获取Value
	UGdouble GetValue(UGint x,UGint y);
	
	//! 得到扫描线
	UGbool GetScanline(UGint nRowIndex,UGImgScanline& ScanLine, UGint nStartPosInSL,UGint nStartPosInBlk = 0 );
	
	//! 通过行列索引设置扫描线
	UGbool SetScanline(UGint nRowIndex,
		const UGImgScanline& scanline, UGint nStartPosInSL,UGint nStartPosInBlk = 0 );

	void SetBounds(const UGRect2D & rc2Bounds)
	{
		m_rc2Bounds = rc2Bounds;
	}

	//! 初始化	
	UGbool Init();

	//! Grid的Block使用NoValue初始化
	UGbool InitGrid(UGint nNoValue);

	//! 重新设置大小
	UGbool Resize(const UGRect2D& rcNewBounds) {
		m_rc2Bounds = rcNewBounds;
		SetModifiedFlag();
		return true;
	}
	
	UGbool CalcuExtremum(UGdouble& dMaxZ,UGdouble& dMinZ);

// 	void SetMinZ(UGdouble nMinZ){
// 		m_dMinZ = nMinZ;
// 	}
// 	
// 	void SetMaxZ(UGdouble nMaxZ){
// 		m_dMaxZ = nMaxZ;
// 	}
	
	UGdouble GetMinZ() {
		if(m_bIsExtremumDirty)
		{
			CalcuExtremum(m_dMaxZ, m_dMinZ);
		}
		return m_dMinZ;
	}

	UGdouble GetMaxZ() {
		if(m_bIsExtremumDirty)
		{
			CalcuExtremum(m_dMaxZ, m_dMinZ);
		}
		return m_dMaxZ;
	}

	//! \brief ImageBlock的存储
	UGbool SaveBlock(UGStream& stream);
	
	//! \brief ImageBlock的存储
	UGbool LoadBlock(UGStream& stream);
	
protected:
	UGColor GetPixel1(UGint x, UGint y);

	UGColor GetPixel4(UGint x, UGint y);

	UGColor GetPixel8(UGint x, UGint y);

	UGColor GetPixel16(UGint x, UGint y);

	UGColor GetPixel24(UGint x, UGint y);

	UGColor GetPixel32(UGint x, UGint y);

	UGColor GetPixel32UGint(UGint x, UGint y);

	UGbool SetPixel1(UGint x, UGint y, UGColor ColorValue);

	UGbool SetPixel4(UGint x, UGint y, UGColor ColorValue);

	UGbool SetPixel8(UGint x, UGint y, UGColor ColorValue);

	UGbool SetPixel16(UGint x, UGint y, UGColor ColorValue);

	UGbool SetPixel24(UGint x, UGint y, UGColor ColorValue);

	UGbool SetPixel32(UGint x, UGint y, UGColor ColorValue);

	UGbool SetPixel32UGint(UGint x, UGint y, UGColor ColorValue);

	
public:
	//! 象素的格式
	PixelFormat m_ePixelFormat;

	//! 所处的行索引
	UGint m_nBlockRowIndex;

	//! 所处的列索引
	UGint m_nBlockColIndex;

	//! 开始的列数(象素单位)
	UGint m_nPixelColIndex;
	
	//! 开始的行数(象素单位)
	UGint m_nPixelRowIndex;

	//! 宽度
	UGint m_nWidth;

	//! 字节宽度
	UGint m_nWidthBytes;

	//! 高度
	UGint m_nHeight;

	//! 有效矩形
	UGSize m_ValidSize;
	
	//! 是否已经初始化
	UGbool m_bInited;

	//! 地理范围
	UGRect2D m_rc2Bounds;

	//! 判断是否修改
	UGbool m_bModified;

	//! 最小高程
	UGdouble m_dMinZ;

	//! 最大高程
	UGdouble m_dMaxZ;

	//! 调色板
	UGColorset* m_pColorset;	
	
private:
	//! 象素数组
	UGArray<UGuchar> m_Data;
	
	//! 标记m_dMax和m_dMin是否需要重新计算
	UGbool m_bIsExtremumDirty;		
};

//! Block指针的集合
class GEOMETRY_API UGImgBlocks : public UGArray<UGImgBlock*>
{
public:
	void SetBlockSize(const UGint nNewSize)
	{
		this->SetSize(nNewSize);
	}
};

}

#endif

