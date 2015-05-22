/*!
   **************************************************************************************
    \file     UGImage.h 
   **************************************************************************************
    \author   张艳良、陈国雄
    \brief    栅格内存位图类                                                         
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2005 SuperMap GIS Technologies,Inc.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-06-09  陈国雄    初始化版本.                                       <br>
   **************************************************************************************
*/

#if !defined(AFX_UGIMAGE_H__824E53E6_0F39_49FA_A3A4_1EFA13C6FD4B__INCLUDED_)
#define AFX_UGIMAGE_H__824E53E6_0F39_49FA_A3A4_1EFA13C6FD4B__INCLUDED_

#include "Algorithm/UGPoint.h"
#include "UGPalette.h"

namespace UGC
{
class UGGraphics;

class GRAPHICS_API UGImage  
{
public:
	struct UGImageData
	{		
		UGint nWidth;		//! \brief Image的宽
		UGint nHeight;		//! \brief Image的高
		UGint nWidthBytes;	//! \brief Image宽字节数，等于nWidth*每个象素字节数，比如32位字节数就是4
		UGbyte btPlanes;	//! \brief 调色板颜色数目
		UGbyte btBitsPixel; //! \brief 每个象素的bit数，比如32，24
		UGPalette palette;	//! \brief 调色板
		void* pBits;		//! \brief 内存数组，通常用来存储颜色值

		UGImageData()
		{		
			nWidth = 0;
			nHeight = 0;
			nWidthBytes = 0;
			btPlanes = 1;
			btBitsPixel = 0;
			pBits = NULL;
		}
	};

protected:
	// 生成空的UGImage对象
	UGImage();	
public:
	// destructor
	virtual ~UGImage();		
	
	//! \brief 创建Image	
	virtual UGbool Create(const UGImageData& ImageData) = 0;
	virtual UGbool Create(
						UGint nWidth,
						UGint nHeight,
						UGuint nPlanes, 
						UGuint nBitcount, 
						const UGPalette& palette,
						const void* pBits) = 0;
	//! \brief 建议都用该接口来创建Image对象。
	virtual UGbool CreateCompatibleImage(UGGraphics *pGraphics, 
										UGint nWidth, UGint nHeight) = 0;
	
	//! \brief 删除Image
	virtual void DeleteObject() = 0;

	//! \brief 从资源装载图片
	virtual UGbool Load(UGuint nIDResource) = 0;

	//! \brief 获取ImageData
	virtual UGbool GetImageData(UGImageData& ImageData) = 0;		


	//! \brief 获取UGImage对象内部数据
	virtual UGuint GetBits(UGuint unCount, void* pBits) const = 0;
	//! \brief 设置UGImage对象内部数据
	virtual UGuint SetBits(UGuint unCount, const void* pBits) = 0;	
	
	//added by xielin 2007-08-24 外部调用其实希望放回一个UGColor的数组，
	//并且在linux下这样效率高很多(2~4倍)，所以增加这样一个接口，在Windows
	//上内部调用还是推荐还是用Bits，而linux上用Colors，外部调用建议都用Colors
	//! \brief 获取UGImage对象内部数据，转换成了UGColor格式,注意，返回的指针
	//! \brief 外部不要删除，内部来管理，目前只支持16位以上颜色
	virtual UGuint* GetColors();

	//! \brief 设置UGImage对象内部数据，目前只支持16位以上颜色
	virtual void SetColors(UGuint unCount,const UGuint* pColors);

	//! \brief 取图像中(x, y)点的像素值
	virtual UGColor GetPixel(UGint x, UGint y) const = 0;
	//! \brief 设置图像中(x, y)点的像素值
	virtual UGColor SetPixel(UGint x, UGint y, UGColor color) = 0;	
	
	//! \brief 设置透明色
	void SetTransparentColor(UGColor color);	
	//! \brief 获取透明色
	UGColor GetTransparentColor() const;
	
	//! \brief 判断是否是单值图像
	virtual UGbool IsMonochrom() const = 0;		
	
	//! \brief 改变m_pData内存区的大小
	virtual void Scale(UGint w,UGint h, UGbool bIsResample=true) = 0;	
	
	//! \brief 获取实际对象
	void* GetNative() const;
	//! \brief 设置实际对象
	void SetNative(void* pNative);
	//! \brief 获取显示引擎类型
	virtual UGint GetGraphicsType();

	//added by xielin 2007-04-20
	//! \brief 把image中得数据缓存到buffer中，目前主要用于linux中的反走样
	//实现方式是每次绘制一个图层前，把以前绘制的缓存到Image的一个成员变量中
	//反走样中绘制走样点的时候getpixel就直接取缓存中的变量中获取，提高速度
	virtual void PrepareBuffer() = 0;
	
protected:
	//! 用户自定义资源的标识
	//! 例如:在X11中为指向服务器端的缓存图像, 在Windows下为CBITMAP
	void* m_pNative;	
	UGColor m_clrTransparent;	// 保存透明颜色的值

	UGint m_nGraphicsType;	
};	

}

#endif // !defined(AFX_UGIMAGE_H__824E53E6_0F39_49FA_A3A4_1EFA13C6FD4B__INCLUDED_)
