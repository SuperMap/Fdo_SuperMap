
/*!
   **************************************************************************************
    \file     UGStyle.h 
   **************************************************************************************
    \author   陈国雄
    \brief    几何风格类                                                             
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2005 SuperMap GIS Technologies,Inc.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-07-06  陈国雄    初始化版本.                                       <br>
   **************************************************************************************
*/

#ifndef UGSTYLE_H
#define UGSTYLE_H

#include "UGString.h"

namespace UGC {

typedef enum tagBrushGradientMode
{
	scbGradientNone	= 0,
	scbGradientLinear	= 1,	
	scbGradientRadial	= 2,
	scbGradientConical	= 3,
	scbGradientSquare	= 4,
		
}UGBrushGradientMode;

class UGStream;

class BASE_API UGStyle  
{
public:
	UGStyle();
	void operator = (const UGStyle &style);
	UGbool operator == (const UGStyle &style) const;
	UGbool operator != (const UGStyle &style) const;

public:	
	//! \brief 得到存储需要的size
	static UGint GetStoreSize();
	static UGString ConvertRGBColor(UGColor crRGB);
	static UGColor ConvertRGBColor(const UGString& strRGB);
	static UGbool IsSameFillStyle(const UGStyle &style1, const UGStyle &style2);
	static UGbool IsSameLineStyle(const UGStyle &style1, const UGStyle &style2);
	static UGbool IsSameMarkerStyle(const UGStyle &style1, const UGStyle &style2);
	static UGbool IsSameDimensionStyle(const UGStyle &style1, const UGStyle &style2, UGint nDimension); 

	//! \brief 填充背景色
	UGColor GetFillBackColor() const;
	void SetFillBackColor(UGColor color);
	
	//! \brief 填充前景色
	UGColor GetFillForeColor() const;
	void SetFillForeColor(UGColor color);
	
	//! \brief 填充风格
	UGint GetFillStyle() const;
	void SetFillStyle(UGint nFillStyle);
	
	//! \brief 线型颜色
	UGColor GetLineColor() const;
	void SetLineColor(UGColor color);

	//! \brief 线型类型
	UGint GetLineStyle() const;
	void SetLineStyle(UGint nLineStyle);
	
	//! \brief 线型宽度
	UGdouble GetLineWidth() const;
	void SetLineWidth(UGdouble dLineWidth);
	
	//! \brief 符号角度
	UGdouble GetMarkerAngle() const;
	void SetMarkerAngle(UGdouble dMarkerAngle);

	//! \brief 符号大小
	UGdouble GetMarkerSize() const;
	void SetMarkerSize(UGdouble dMarkerSize);

	//! \brief 符号风格
	UGint GetMarkerStyle() const;
	void SetMarkerStyle(UGint nMarkerStyle);

	//! \brief 填充背景不透明
	UGbool GetFillBackOpaque() const;
	void SetFillBackOpaque(UGbool bOpaque);

	//! \brief 填充不透明度
	UGbyte GetFillOpaqueRate() const;
	void SetFillOpaqueRate(UGbyte btFillOpaqueRate);

	//! \brief 填充渐变类型
	UGbyte GetFillGradientType() const;
	void SetFillGradientType(UGbyte btGradientType);

	//! \brief 填充角度
	UGdouble GetFillAngle() const;
	void SetFillAngle(UGdouble dFillAngle);

	//! \brief 填充渐变中心X方向偏移
	UGshort GetFillCenterOffsetX() const;
	void SetFillCenterOffsetX(UGshort nFillCenterOffsetX);

	//! \brief 填充渐变中心Y方向偏移
	UGshort GetFillCenterOffsetY() const;
	void SetFillCenterOffsetY(UGshort nFillCenterOffsetY);

	//! \brief Load Style
	//! \remarks 可以读取 30 和 50 的风格
	UGbool LoadAll(UGStream& stream, UGint nStyleSize);
	//! \brief Save Style
	//! \remarks 只支持50的存储
	//! \return 返回保存的style的size
	void SaveAll(UGStream& stream) const;
	UGint Load(UGStream& stream, UGint nDimension);
	void Save(UGStream& stream, UGint nDimension) const;

	UGbool FromXML(const UGString& strXML, UGint nVersion = 0);
	UGString ToXML(UGint nVersion = 0, const UGString& strElemName = ("")) const;
	//! \brief 设置符号的缩放比例系数参照符号本身还是符号的边框(255,255)
	//! \param bSymbolScale 真为符号 假为边框
	void SetScaleBySymbol(UGbool bSymbolScale)
	{
		m_bSymbolScale = bSymbolScale;
	}
	UGbool IsScaleBySymbol() const
	{
		return m_bSymbolScale;
	}

	//! \brief 获取风格对象的hashcode
	UGint GetHashCode() const;
private:	
	UGint m_nMarkerStyle;
	UGint m_nMarkerAngle;		//单位：0.1度
	UGint m_nMarkerSize;

	UGint m_nLineStyle;
	UGColor m_LineColor;
	UGint m_nLineWidth;
	
	UGint m_nFillStyle;
	UGColor m_FillBackColor;
	UGColor m_FillForeColor;
	UGbool m_bFillBackOpaque;
	UGbyte m_btFillOpaqueRate;
	UGbyte m_btFillGradientType;	
	UGshort m_nFillAngle;		//单位：0.1度
	UGshort m_nFillCenterOffsetX;
	UGshort m_nFillCenterOffsetY;
	
	UGbool	m_bSymbolScale;		//点符号的Size是Symbol的size还是边框(255,255)的size
								//TRUE Symbol的size 
								//FALSE 边框 dongfei adds 2007-03-29
};

}

#endif
