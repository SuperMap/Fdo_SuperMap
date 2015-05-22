// UGWImage.h: interface for the UGWImage class.
//
//////////////////////////////////////////////////////////////////////

/*!
   **************************************************************************************
    \file     UGWImage.h
   **************************************************************************************
    \author   张艳良、陈国雄
    \brief    Windows位图类                                                          
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2005 SuperMap GIS Technologies,Inc.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-06-09  陈国雄    初始化版本.                                       <br>
   **************************************************************************************
*/

#if !defined(AFX_UGWIMAGE_H__1E3D0CD0_C1C7_4B31_91FB_9D7A600AAD54__INCLUDED_)
#define AFX_UGWIMAGE_H__1E3D0CD0_C1C7_4B31_91FB_9D7A600AAD54__INCLUDED_

#include "Graphics/UGImage.h"

namespace UGC
{

class WGRAPHICS_API UGWImage : public UGImage  
{
public:
	UGWImage();
	virtual ~UGWImage();

	// 创建Image	
	virtual UGbool Create(const UGImageData& ImageData);
	virtual UGbool Create(
		UGint nWidth,
		UGint nHeight,
		UGuint nPlanes, 
		UGuint nBitcount, 
		const UGPalette& palette, 
		const void* pBits);
	virtual UGbool CreateCompatibleImage(UGGraphics *pGraphics, 
		UGint nWidth, UGint nHeight);
	
	// 删除Image
	virtual void DeleteObject();

	virtual UGbool Load(UGuint nIDResource);
	
	virtual UGbool GetImageData(UGImageData& ImageData);
	
	
	// 获取UGImage对象内部数据
	virtual UGuint GetBits(UGuint unCount, void* pBits) const;
	virtual UGuint SetBits(UGuint unCount, const void* pBits);

	//added by xielin 2007-08-24 外部调用其实希望放回一个UGColor的数组，
	//并且在linux下这样效率高很多(2~4倍)，所以增加这样一个接口，在Windows
	//上内部调用还是推荐还是用Bits，而linux上用Colors，外部调用建议都用Colors
	//! \brief 获取UGImage对象内部数据，转换成了UGColor格式,注意，返回的指针
	//! \brief 外部不要删除，内部来管理，目前只支持16位以上颜色
	virtual UGuint* GetColors();

	//! \brief 设置UGImage对象内部数据，目前只支持16位以上颜色
	virtual void SetColors(UGuint unCount,const UGuint* pColors);
	
	//! 取图像中(x, y)点的像素值
	virtual UGColor GetPixel(UGint x, UGint y) const;
	//! 设置图像中(x, y)点的像素值
	virtual UGColor SetPixel(UGint x, UGint y, UGColor color);		

	//! 判断是否是单值图像
	virtual UGbool IsMonochrom() const;
	//! 改变m_pData内存区的大小
	virtual void Scale(UGint w,UGint h, UGbool bIsResample = true);	
	void SetNativePalette(CPalette *pNativePalette);
	CPalette *GetNativePalette() const;

	//added by xielin 2007-04-20
	//! \brief 把image中得数据缓存到buffer中，目前主要用于linux中的反走样
	//实现方式是每次绘制一个图层前，把以前绘制的缓存到Image的一个成员变量中
	//反走样中绘制走样点的时候getpixel就直接取缓存中的变量中获取，提高速度
	virtual void PrepareBuffer();

private:
	UGbool m_bNeedRelease;
	UGPalette m_Palette;
	CPalette *m_pNativePalette;
	//added by xielin 2007-08-24 用来保存颜色数组，getcolors用到
	UGColor* m_pBuf;
	//added by xielin 2007-08-24 用来保存bits,不用每次new，getcolors用到
	UGbyte* m_pBits;
	UGint m_nBufCount;
	UGint m_nBitsCount;
};

}

#endif // !defined(AFX_UGWIMAGE_H__1E3D0CD0_C1C7_4B31_91FB_9D7A600AAD54__INCLUDED_)
