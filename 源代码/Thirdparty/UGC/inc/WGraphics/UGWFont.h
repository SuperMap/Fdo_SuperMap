// UGWFont.h: interface for the UGWFont class.
//
//////////////////////////////////////////////////////////////////////

/*!
   **************************************************************************************
    \file     UGWFont.h 
   **************************************************************************************
    \author   张艳良、陈国雄
    \brief    Windows字体类                                                          
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2005 SuperMap GIS Technologies,Inc.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-06-09  陈国雄    初始化版本.                                       <br>
   **************************************************************************************
*/

#if !defined(AFX_UGWFONT_H__2C01872B_FE49_4DD9_ADD3_4B88CE95D1EC__INCLUDED_)
#define AFX_UGWFONT_H__2C01872B_FE49_4DD9_ADD3_4B88CE95D1EC__INCLUDED_

#include "Graphics/UGFont.h"

namespace UGC
{

class WGRAPHICS_API UGWFont : public UGFont  
{
public:
	UGWFont();
	virtual ~UGWFont();

	// 创建字体
	virtual UGbool Create();
	
	// 创建字体并设置字体的属性(名字,大小,样式,编码等).	
	virtual UGbool Create(const UGFontData& FontData);
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
	//! \brief 设置是否采用反走样 added by dongfei 2007-03-08
	/**
	 *
	 */
	virtual void SetAntiAliasing(UGbool bAntiAliasing);
	
	// 删除字体
	virtual void DeleteObject();
private:
	UGbool m_bNeedRelease;	
};

}

#endif // !defined(AFX_UGWFONT_H__2C01872B_FE49_4DD9_ADD3_4B88CE95D1EC__INCLUDED_)
