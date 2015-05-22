
/*!
   **************************************************************************************
    \file     UGTextStyle.h
   **************************************************************************************
    \author   陈国雄
    \brief    文本风格类                                                             
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2005 SuperMap GIS Technologies,Inc.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-07-06  陈国雄    初始化版本.                                       <br>
   **************************************************************************************
*/

#ifndef UGTEXTSTYLE_H
#define UGTEXTSTYLE_H

#include "ugdefs.h"
#include "UGString.h"

namespace UGC {

//! \brief 文本风格类
class BASE_API UGTextStyle  
{
public:
	UGTextStyle();
	UGTextStyle(const UGTextStyle& textStyle);
	virtual ~UGTextStyle();

	void operator=(const UGTextStyle& textStyle);
	UGbool operator==(const UGTextStyle& textStyle);
	UGbool operator!=(const UGTextStyle& textStyle);

public:
	//! 得到字体颜色
	UGColor GetForeColor() const;
	//! 设置字体颜色
	void SetForeColor(UGColor foreColor);

	//! 背景色，阴影色，外框色
	UGColor	GetBackColor() const;
	//! 设置背景色,同时也是阴影色，外框色
	void SetBackColor(UGColor backColor);

	//! 得到旋转角度，以度为单位，逆时针方向
	UGdouble GetAngle() const;
	//! 设置旋转角度，以度为单位，逆时针方向	
	void SetAngle(UGdouble dAngle);

	//! 得到字体宽度，地理单位
	UGdouble GetWidth() const;
	//! 设置字体宽度，地理单位
	void SetWidth(UGdouble dWidth);

	//! 得到字体高度，地理单位
	UGdouble GetHeight() const;
	//! 设置字体高度，地理单位
	void SetHeight(UGdouble dHeight);

	//! 得到字体名称		
	UGString GetFaceName() const;
	//! 设置字体名称
	void SetFaceName(const UGString& strFaceName);

	//! 得到所有风格信息:粗体，斜体，透明，黑体,排列等
	UGint GetStyle() const;			
	//! 设置所有的风格，高级用户使用!
	void SetStyle(UGint nStyle);	
	
	//! 是否粗体
	UGbool IsBold() const;	
	//! 设置是否粗体
	void SetBold(UGbool bBold = true);				

	//! 是否下划线
	UGbool IsUnderline() const;
	//! 设置是否下划线
	void SetUnderline(UGbool bUnderline = true);		

	//! 是否斜体
	UGbool IsItalic() const;	
	//! 设置是否斜体
	void SetItalic(UGbool bItalic = true);			

	//! 是否删除线
	UGbool IsStrikeOut() const;		
	//! 设置是否删除线
	void SetStrikeOut(UGbool bStrikeOut = true);

	//! 得到对齐方式
	UGbyte GetAlign() const;				
	//! 设置对齐方式
	void SetAlign(UGbyte nAlign = 0);				

	//! 得到文本的笔划宽度
	UGint GetWeight() const;		
	//! 设置文本的笔划宽度			
	void SetWeight(UGint nWeight);	
			
	//! 是否固定大小
	UGbool IsFixedSize() const;			
	//! 固定大小，字体不随地图的缩放而缩放
	void SetFixedSize(UGbool bFixedSize=true);			
	
	//! 固定大小的尺寸，mm单位
	UGdouble GetSizeForFixed() const;			
	//! 设置固定大小的尺寸，mm单位
	void SetSizeForFixed(UGdouble dSize);		

	//! 是否背景不透明, 注意了,true表示不透明!!
	UGbool IsBackOpaque() const;				
	//! 设置是否背景不透明
	void SetBackOpaque(UGbool bBackOpaque = false);				
	
	//! 是否显示外框
	UGbool IsHalo() const;			
	//! 设置是否显示外框
	void SetHalo(UGbool bHalo = true);		
	
	//! 是否显示阴影
	UGbool IsShadow() const;	
	//! 设置是否显示阴影
	void SetShadow(UGbool bShadow = true);			
	
	UGbool FromXML(const UGString& strXML, UGint nVersion = 0);
	UGString ToXML(UGint nVersion = 0) const;

	//! \brief 获取文本风格对象的hashcode
	UGint GetHashCode() const;

	//! \brief 获取/设置耸肩效果,正负60度之间，目前只对标签专题图有效，传入的是度为单位
	UGdouble GetItalicAngle() const;
	void SetItalicAngle(UGdouble nItalicAngle);
	
private:
	UGColor		m_ForeColor;			//! 字体颜色
	UGColor		m_BackColor;			//! 背景色，阴影色，外框色
	UGint		m_nAngle;				//! 旋转角度，以0.1度为单位,x坐标正方向为起始，逆时针方向
	UGint		m_nItalicAngle;			//! 旋转角度，以0.1度为单位,x坐标正方向为起始，逆时针方向
	UGdouble	m_dWidth;				//! 字体宽度，地理单位
	UGdouble	m_dHeight;				//! 字体高度，地理单位
	UGString	m_strFaceName;			//! 字体名字
	UGint		m_nStyle;				//! 风格:粗体，斜体，透明，黑体,排列等	
};

}

#endif
