// UGFont.h: interface for the UGFont class.
//
//////////////////////////////////////////////////////////////////////

/*!
   **************************************************************************************
    \file     UGFont.h  
   **************************************************************************************
    \author   张艳良、陈国雄
    \brief    字体基类                                                                 
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2005 SuperMap GIS Technologies,Inc.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-06-09  陈国雄    初始化版本.                                       <br>
   **************************************************************************************
*/

#if !defined(AFX_UGFONT_H__93BF2531_3AD2_4B27_ACA8_BBB861E6150E__INCLUDED_)
#define AFX_UGFONT_H__93BF2531_3AD2_4B27_ACA8_BBB861E6150E__INCLUDED_

#include "Base/ugdefs.h"
#include "Base/UGString.h"
#include "Base/UGTextCodec.h"
#include "Base/UGTextStyle.h"

namespace UGC
{

class GRAPHICS_API UGFont  
{
public:

	struct UGFontData
	{		
		UGint nHeight;
		UGint nWidth;
		UGint nWeight;
		UGint nAngle;
		UGbool bBold;
		UGbool bItalic;
		UGbool bUnderline;
		UGbool bStrikeOut;
		UGbool bHalo;
		UGbool bShadow;
		UGint nItalicAngle;
		UGTextCodec::Charset nCharset;
		UGString strName;

		UGFontData()
		{					
			nHeight = 40;
			nWidth = 0;
			nWeight = 0;
			nAngle = 0;
			bBold = false;
			bItalic = false;
			bUnderline = false;
			bStrikeOut = false;
			bHalo = false;
			bShadow = false;
			nItalicAngle = 0;
			nCharset = UGTextCodec::Default;		
			strName = ("");
		}
	};

protected:
	UGFont();
public:
	virtual ~UGFont();

	//! \brief 创建字体
	virtual UGbool Create() = 0;
	
	//! \brief 创建字体并设置字体的属性(名字,大小,样式,编码等).	
	virtual UGbool Create(const UGTextStyle& style, UGint nFontHeight, 
		UGint nFontWidth, UGint nAngle, UGuint nCharset);
	//! \brief 按照UGFontData结构创建字体
	virtual UGbool Create(const UGFontData& FontData);
	//! \brief 按照一些字体参数创建字体
	virtual UGbool Create(const UGString& strName,
					   UGint nHeight = 40, 
					   UGint nWidth = 0,
	                   UGint nWeight = 0, 
					   UGint nAngle = 0, 
	                   UGbool bBold = false, 
					   UGbool bItalic = false,
					   UGint nItalicAngle = 0,
	                   UGbool bUnderline = false, 
					   UGbool bStrikeOut = false,
					   UGbool bHalo = false, 
					   UGbool bShadow = false,
					   UGTextCodec::Charset nCharset = UGTextCodec::GB18030);
	
	//! \brief 删除字体
	virtual void DeleteObject() = 0;

	//! \brief 获取字体属性结构
	virtual void GetFontData(UGFontData& FontData);

	//! \brief 获取字体重量
	virtual UGint GetWeight() const;
	//! \brief 设置字体重量
	virtual void SetWeight(UGint nWeight);

	//! \brief 获取字体倾斜角度
	virtual UGdouble GetItalicAngle() const;
	//! \brief 设置字体倾斜角度
	virtual void SetItalicAngle(UGdouble nItalicAngle);

	//! \brief 获取字体名
	virtual UGString GetName() const;
	//! \brief 设置字体名
	virtual void SetName(const UGString& strName);

	//! \brief 获取字体高度
	virtual UGint GetHeight() const;	
	//! \brief 设置字体高度
	virtual void SetHeight(UGint nHeight);

	//! \brief 获取字体宽度
	virtual UGint GetWidth() const;	
	//! \brief 设置字体宽度
	virtual void SetWidth(UGint nWidth);

	//! \brief 获取字体的旋转角度
	virtual UGint GetAngle() const;
	//! \brief 设置字体旋转角度
	virtual void SetAngle(UGint nAngle);

	//! \brief 判断当前字体是否是粗体
	virtual UGbool IsBold() const;	
	//! \brief 设置字体为粗体
	virtual void SetBold(UGbool bBold);

	//! \brief 判断当前字体是否是斜体
	virtual UGbool IsItalic() const;
	//! \brief 设置字体为斜体
	virtual void SetItalic(UGbool bItalic);

	//! \brief 判断当前字体是否带有下划线
	virtual UGbool IsUnderline() const;
	//! \brief 设置字体带下划线
	virtual void SetUnderline(UGbool bUnderline);

	//! \brief 判断当前字体是否带有删除线
	virtual UGbool IsStrikeOut() const;
	//! \brief 设置字体带删除线
	virtual void SetStrikeOut(UGbool bStrikeOut);

	//! \brief 判断当前字体是否带有轮廓线
	virtual UGbool IsHalo() const;
	//! \brief 设置字体带轮廓线
	virtual void SetHalo(UGbool bHalo);

	//! \brief 判断当前字体是否带有阴影
	virtual UGbool IsShadow() const;
	//! \brief 设置字体带有阴影
	virtual void SetShadow(UGbool bShadow);

	//! \brief 获取字体编码
	virtual UGTextCodec::Charset GetCharset() const;
	//! \brief 设置字体编码
	virtual void SetCharset(UGTextCodec::Charset nCharset);	
	
	//! \brief 获取实际对象
	void* GetNative() const;
	//! \brief 设置实际对象
	void SetNative(void* pNative);
	//! \brief 获取显示引擎类型
	virtual UGint GetGraphicsType();

	//! \brief 设置/返回是否采用反走样 added by dongfei 2007-03-08
	/*
	 *	
	 */
	virtual void SetAntiAliasing(UGbool bAntiAliasing);
	virtual UGbool IsAntiAliasing();
	
protected:
	UGFontData m_FontData;
	void* m_pNative;

	UGint m_nGraphicsType;	
	UGbool m_bAntiAliasing;		//是否采用反走样 added by dongfei 2007-03-08
};
}
#endif // !defined(AFX_UGFONT_H__93BF2531_3AD2_4B27_ACA8_BBB861E6150E__INCLUDED_)
