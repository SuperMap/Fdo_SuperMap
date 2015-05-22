
/*!
   **************************************************************************************
    \file     UGFillSymbol.h
   **************************************************************************************
    \author   陈国雄
    \brief    填充符号类。                                                                       
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2005 SuperMap GIS Technologies,Inc.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-05-23  陈国雄    初始化版本.                                       <br>
   **************************************************************************************
   \version 2.0
   <b>更新说明：</b>\n
   <em>1、由于实现子层填充的功能，所以增加了一个子层概念，在UGFillSymbolBase类中，详细查看到该类中查看\n
   <em>2、参照点符号和线符号的管理方式，目前本类主要负责多个子层的管理，绘制等功能，而单个填充符号的存储主要放到UGFillSymbolBase类中管理，在读取上向上兼容以前和FillSymbolLib，向下保证读取和存储各个子层UGFillSymbolBase中的数据，同时兼容以前的格式。\n
*/



#ifndef UGFILLSYMBOL_H
#define UGFILLSYMBOL_H

#include "UGSymbol.h"
#include "UGMarkerSymFill.h"
#include "UGFillSymParam.h"
#include "Symbol/UGFillSymbolBase.h"

namespace UGC {

class SYMBOL_API UGFillSymbol : public UGSymbol
{
public:
	enum RenderImageType
	{
		RIT_NORMAL = 0,		//! Image 填充
		RIT_AND = 1,		//! Image And 填充
		RIT_OR = 2			//! Image Or 填充
	};	

public:
	UGFillSymbol();
	virtual ~UGFillSymbol();
	UGFillSymbol(const UGFillSymbol& symbol);
	virtual UGFillSymbol& operator = (const UGFillSymbol& symbol);

public:
	//! \brief 导入填充符号信息
	virtual UGbool Load(UGStream& stream, UGuint nVersion = 0);
	//! \brief 保存填充符号信息
	virtual UGbool Save(UGStream& stream, UGuint nVersion = 0) const;

	//! \brief 绘制多边形填充
	/**
	\param graphics			绘制到的graphics[in]
	\param FillSymParam		填充参数[in]
	\param pPoints			填充点[in]
	\param nCount			点个数[in]
	*/
	void Polygon(UGGraphics& graphics, UGFillSymParam& FillSymParam,
				const UGPoint* pPoints, UGint nCount);
	//! \brief 绘制多个多边形填充
	/**
	\param graphics			绘制到的graphics[in]
	\param FillSymParam		填充参数[in]
	\param pPoints			填充点指针[in]
	\param pPointCount		多个多边形每组的点个数[in]
	\param nCount			组数[in]
	*/
	void PolyPolygon(UGGraphics& graphics, UGFillSymParam& FillSymParam, 
				const UGPoint* pPoints,	const UGint* pPointCount, UGint nCount);
	//! \brief 绘制矩形填充
	/**
	\param graphics			绘制到的graphics[in]
	\param FillSymParam		填充参数[in]
	\param rect				填充矩形[in]
	*/
	void Rectangle(UGGraphics& graphics, UGFillSymParam& FillSymParam, const UGRect& rect);

	//! \brief 得到填充符号第nIndex个子符号的类型，默认为0
	UGint GetType(UGint nIndex = 0) const;

	//! \brief 设置填充符号第nIndex个子符号的点符号信息
	void SetMarkerSymFill(UGMarkerSymFill* pMarkerSymFill,UGint nIndex = 0);
	//! \brief 得到填充符号第nIndex个子符号的点符号信息
	UGMarkerSymFill* GetMarkerSymFill(UGint nIndex = 0) const;

	//! \brief 得到填充符号第nIndex个子符号的分辨率
	UGint GetResolution(UGint nIndex = 0) const;
	//! \brief 设置填充符号第nIndex个子符号的分辨率
	void SetResolution(UGint nResolution,UGint nIndex = 0);
	//! \brief 导入一位图
	UGbool LoadBitmap(const UGString& strFileName);
	//! \brief 保存成位图信息
	/**
	\param strFileName		输出路径[in]
	\param pSymLib			如果为点符号填充，指定该点符号对应的点符号库[in]
	\param nIndex			第nIndex子符号[in]
	\param clrFront			前景色[in]
	\param clrBack			背景色[in]
	\return 是否转化成功
	*/
	UGbool SaveBitmap(const UGString& strFileName,
		        UGMarkerSymbolLib* pSymLib = NULL,
		        UGint nIndex = 0,
				UGColor clrFront = UGRGB(0,0,0), 
				UGColor clrBack = UGRGB(255,255,255));
	const UGImage::UGImageData* GetImageData(UGint nIndex = 0) const;
	//! \brief  渲染需要填充的符号
	/**
	\param graphics          绘制的显示引擎[in]
	\param FillSymParam      绘制参数[in]
	\param nRenderImageType  绘制类型[in]
	\return 返回渲染得到的Image
	*/
	UGImage* Render(UGGraphics& graphics, UGFillSymParam& FillSymParam, UGint nRenderImageType);
	//! \brief  清空数据，负责内存释放
	void Clear();
	UGbool EnableBackTransparent(UGint nIndex = 0);

	//! \brief  得到子层个数
	UGint GetCountOfFillSymbolBase()const;	
	//! \brief  得到第nIndex子层指针
	/**
	\param nIndex     子层的索引[in]
	\return 返回该层指针
	*/
	UGFillSymbolBase* GetFillSymbolBaseAt(UGint nIndex)const;

	//! \brief  添加某一层
	void AddFillSymbolBase(UGFillSymbolBase* pBaseFillSymbol);
	//! \brief  添加某一层
	void AddFillSymbol(UGFillSymbol* pFillSymbol);

	//! \brief  移除某一层
	UGbool RemoveFillSymbolBase(UGint nIndex);
	//! \brief  移除某一层
	UGbool RemoveFillSymbolBase(UGFillSymbolBase* pBaseFillSymbol);

protected:
	UGint GetBitmapSize(const UGImage::UGImageData* pImageData) const;
	UGbool SaveBitmap(UGStream& stream, UGint nFileSize, const UGImage::UGImageData* pImageData) const;
	UGbool LoadBitmap(UGStream& stream,UGint nIndex,UGint nResolution);
	UGbool LoadMarkerSymFill(UGStream& stream,UGint nIndex);
	UGbool RegionWithImage(UGGraphics& graphics, UGFillSymParam& FillSymParam, UGRgn *pRgn, UGbool bRect = false);
	void PrepareFillSymParam(UGFillSymParam& subFillSymParam,const UGFillSymParam& FillSymParam,UGFillSymbolBase* pBaseFillSymbol)const;
	//! 透明绘制位图，将其中一种颜色(由参数clrTransparent指定)相对于背景图透明显示
	void TransparentDraw(UGGraphics& graphics, UGImage* pImgSrc, 
		                 UGint xStart, UGint yStart, UGColor clrTransparent, UGint nTransPercent = 100) const;

protected:
	UGArray<UGFillSymbolBase* > m_pFillSymbolBase;
	
};

}

#endif


