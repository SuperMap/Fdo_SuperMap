/**  \file UGFillSymbolBase.h
   \brief 实现填充符号类子层管理
   \author lugw
   \attention 为了实现多层填充，所以将原先的UGFillSymbol降一层变为UGFillSymbolBase，来管理单层的相关功能，而原先的UGFillSymbol则负责多层叠加，绘制等功能
   Copyright(c) 1996-2007 SuperMap GIS Technologies, Inc.<br>
   All Rights Reserved.
 */

#ifndef UGFILLSYMBOLBASE_H
#define UGFILLSYMBOLBASE_H

#include "UGSymbol.h"
#include "UGMarkerSymFill.h"
#include "UGFillSymParam.h"

namespace UGC {
	
class SYMBOL_API UGFillSymbolBase
{

public:

	enum FS_RESOLUTION		//! 分辨率；
	{
		FS_72DPI = 72,
		FS_81DPI = 81,
		FS_96DPI = 96,
		FS_127DPI = 127,
		FS_150DPI = 150,
		FS_200DPI = 200,
		FS_254DPI = 254
	};

	enum FillSymbolType
	{
		FST_BITMAP = 0,		//! bmp 填充
		FST_POINTSYMBOL = 1	//! 点符号填充
	};

	enum RenderImageType
	{
		RIT_NORMAL = 0,		//! Image 填充
		RIT_AND = 1,		//! Image And 填充
		RIT_OR = 2			//! Image Or 填充
	};	

public:
	UGFillSymbolBase();
	virtual ~UGFillSymbolBase();
	UGFillSymbolBase( UGFillSymbolBase& symbol);
	virtual UGFillSymbolBase& operator = ( UGFillSymbolBase& symbol);
	
public:
	//! \brief 得到填充类型
	UGint GetType() const;
	//! \brief 设置填充类型
	void  SetType(UGbyte eType);

	//! \brief 得到分辨率
	UGint GetResolution()const;
	//! \brief 设置分辨率
	void SetResolution(UGint nResolution);

	//! \brief 设置点符号填充信息
	void SetMarkerSymFill(UGMarkerSymFill* pMarkerSymFill);
	//! \brief 得到点符号填充信息
	UGMarkerSymFill* GetMarkerSymFill() const;

	//! \brief 得到栅格符号填充信息
	const UGImage::UGImageData* GetImageData() const;
	//! \brief 对填充信息渲染，转成适合Graphics绘制的image
	/**
	\param graphics			绘制到的graphics[in]
	\param FillSymParam		填充参数[in]
	\param nRenderImageType 填充类型[in]
	\return 填充后的Image信息
	*/
	UGImage* Render(UGGraphics& graphics, UGFillSymParam& FillSymParam, UGint nRenderImageType);
	//! \brief 清空
	void Clear();
	//! \brief 背景是否透明
	UGbool EnableBackTransparent();
	//! \brief 保存位图信息
	UGbool SaveBitmap(UGStream& stream, UGint nFileSize) const;
	//! \brief 读取位图信息
	UGbool LoadBitmap(UGStream& stream);
	//! \brief 读取点符号信息
	UGbool LoadMarkerSymFill(UGStream& stream);

	//! \brief 读取指定位图到填充符号
	UGbool LoadBitmap(const UGString& strFileName);
	//! \brief 保存填充符号为位图
	/**
	\param strFileName		输出路径[in]
	\param pSymLib			如果为点符号填充，指定该点符号对应的点符号库[in]
	\param clrFront			前景色[in]
	\param clrBack			背景色[in]
	\return 是否转化成功
	*/
	UGbool SaveBitmap(const UGString& strFileName, 
		UGMarkerSymbolLib* pSymLib = NULL,
		UGColor clrFront = UGRGB(0,0,0), 
		UGColor clrBack = UGRGB(255,255,255));
	
	//! \brief 是否固定前景色
	UGbool IsFixedForeColor()const;
	//! \brief 是否固定背景色
	UGbool IsFixedBackColor()const;

	//! \brief 得到前景色
	UGColor GetForeColor() const;
	//! \brief 设置前景色
	void    SetForeColor(UGColor color);
	//! \brief 得到背景色
	UGColor GetBackColor() const;
	//! \brief 设置背景色
	void    SetBackColor(UGColor color);

	//! \brief 设置是否固定前景色
	void SetFixedForeColor(UGbool bFixed);
	//! \brief 设置是否固定背景色
	void SetFixedBackColor(UGbool bFixed);

protected:
	UGint GetBitmapSize() const;

protected:
	UGbyte m_eType;
	UGint m_nResolution;
	UGImage::UGImageData* m_pImageData;
	UGMarkerSymFill* m_pMarkerSymFill;
	/*   8 7 6 5 4 3 2 1---------- 1  fore是否固定
		 | | | | | | +------------ 2  back是否固定
		 | | | | | +-------------- 3 
		 | | | | +---------------- 4 
		 | | | +------------------ 5 
		 | | +-------------------- 6 
		 | +---------------------- 7 
		 +------------------------ 8 */
	UGuchar m_nProperties;
	UGColor m_ForeColor;
	UGColor m_BacColor;
};

}

#endif
