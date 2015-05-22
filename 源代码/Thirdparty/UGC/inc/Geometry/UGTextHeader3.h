/*! \file	 UGTextHeader3.h
 *  \brief	 3.0版本文本头类
 *  \author	 ugc team
 *  \attention 
 *  Copyright(c) 1996-2004 SuperMap GIS Technologies,Inc.<br>
 *  All Rights Reserved
 *  \version 
 */

#ifndef UGTEXTHEADER3_H
#define UGTEXTHEADER3_H

#include "Base/ugdefs.h"
#include "Algorithm/UGPoint2D.h"
#include "Base/UGString.h"
#include "Base/UGTextStyle.h"

namespace UGC {

//! \brief SuperMap SFC 3 中 GeoText的文本头结构
class GEOMETRY_API UGTextHeader3		//SuperMap3.x的TextHeader结构
{
public:
	//! \brief 构造函数
	UGTextHeader3();
	//! \brief 从textStyle构造。
	//! \param textStyle [in] 文本风格。
	void FromTextStyle(const UGTextStyle& textStyle);	

	//! \brief 转化为文本风格对象。
	//! \param textStyle [out] 转换后得到的文本风格对象。
	void ToTextStyle(UGTextStyle& textStyle) const;	

public:
	//! 子对象数
	UGint m_nSubCount;	
	//! 文本的颜色
	UGColor	m_Color;		
	//! 文本的风格,   0x BYTE4 BYTE3 BYTE2 BYTE1 
	UGint	m_nStyle;		
	//! 背景色
	UGColor	m_BgColor;		
	//! 半角英文字符宽，可以为0, 由系统自定
	UGdouble	m_dFontWidth;	
	//! 半角英文字符高，不能为0, 否则文字可能不显示
	UGdouble	m_dFontHeight;	
	//! 文字的定位点
	UGPoint2D m_pntAnchor;	
};
//其中 SmInt32 m_nStyle;//文本的风格,   0x BYTE4 BYTE3 BYTE2 BYTE1 
						//由几部分组成,	     |     |     |     |
						//具体如右图:        |     |     |     +--Text Align
						//				     |     |     +--Text Style
						//				     |     +--Text Font Weight
						//                   +--Text Other Attribute 
						//========================================================
						//BYTE1 文本的对齐方式
						//	   左  中  右
						// 上	0	1	2
						// 中	3	4	5
						// 下	6	7	8
						//--------------------------------------------------------
						//BYTE2 文本的一般风格	   本字节     在m_lStyle中
						//粗体	(Bold)				0x01     ( 0x00000100 )
						//斜体  (Italic)			0x02     ( 0x00000200 )
						//下划线(Underline)			0x04     ( 0x00000400 )
						//删除线(Stroke)			0x08     ( 0x00000800 )
						//--------------------------------------------------------
						//BYTE2 文本的高级风格	   本字节     在m_lStyle中
						//固定大小(FixedSize)		0x10     ( 0x00001000 )
						//背景填充(Opaque)			0x20     ( 0x00002000 )
						//轮廓背景(Outline)			0x40     ( 0x00004000 )    
						//显示阴影(Shadow)			0x80     ( 0x00008000 )    
						//--------------------------------------------------------
						//BYTE3 文本的笔划粗细 --> 与windows一致
						//--------------------------------------------------------
						//BYTE4固定大小的文本的尺寸 本字节    在m_lStyle中
						//固定的大小(FixedSize)		0xff     ( 0xff000000 )
						//========================================================

}

#endif


