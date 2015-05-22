/*! \file	 UGImgScanline.h
 *  \brief	 扫描线类定义文件
 *  \author	 ugc team
 *  \attention 
 *  Copyright(c) 1996-2004 SuperMap GIS Technologies,Inc.<br>
 *  All Rights Reserved
 *  \version $Id: UGImgScanline.h,v 1.6 2005/03/31 01:33:59 aiguo Exp $
 */

#ifndef UGIMGSCANLINE_H
#define UGIMGSCANLINE_H

#include "Base/ugdefs.h"
#include "Base/UGArray.h"
#include "Base/UGToolkit.h"

namespace UGC {


//! 扫描线类

//=======================================================
//{{ Modified by GUOQC at [2005-02-23 09:56:08]
// * 修改原因及必要说明	
//如果m_data作为成员，很多对于array的使用就不方便，比如调用者想直接调用getdata，setsize之类的东西
//改跟sfc中的设计一样，从array继承

class GEOMETRY_API UGImgScanline:public UGArray<UGuchar>
{
public:
	//! 构造函数
	UGImgScanline();
	
	//! 析构函数
	~UGImgScanline();
	
	//! 将红蓝的BYTE顺序交换
	void SwapBlueRed();	
	
	//! 将左右的BYTE顺序交换
	void SwapLeftRight();
	
	//! 设置Pixel
	UGbool SetPixel(UGint x,UGint nPixel);
	
	//! 获取Pixel
	UGint GetPixel(UGint x);
	
	//! 设置Value
	UGbool SetValue(UGint x,UGdouble dValue);
	
	//! 获取Value
	UGdouble GetValue(UGint x);

	//! 获取像素格式
	PixelFormat GetPixelFormat() const {return m_ePixelFormat;}

	//! 设置像素格式
	void SetPixelFormat(const PixelFormat ePixelFormat){m_ePixelFormat = ePixelFormat;}

	//! 获取扫描线所占字节数
	UGint GetWidthBytes() const
	{
		return (m_nWidth*UGToolkit::GetBitCount(m_ePixelFormat)+7)/8;
	}

	//! 设置扫描线所占字节数
	void SetWidthBytes(const UGint nNewSize)
	{
		SetSize(nNewSize);
	}


	//! 获取扫描线宽度
	UGint GetWidth() const {return m_nWidth;}

	//! 设置扫描线宽度
	void SetWidth(const UGint nWidth) {m_nWidth = nWidth;}
		
private:
	//! 象素格式
	PixelFormat m_ePixelFormat;

	//! 扫描线宽度
	UGint m_nWidth;
};
//}} Modified by GUOQC at [2005-02-23 09:56:08]
//=======================================================

}

#endif


