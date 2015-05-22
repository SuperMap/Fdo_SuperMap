// UGThemeCustom.h: interface for the UGThemeCustom class.
//
//////////////////////////////////////////////////////////////////////

/*!
   **************************************************************************************
    \file     UGThemeCustom.h
   **************************************************************************************
    \author   陈国雄
    \brief    自定义专题图类。                                                        
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2005 SuperMap GIS Technologies,Inc.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-05-20  陈国雄    初始化版本.                                       <br>
   **************************************************************************************
*/

#if !defined(AFX_UGTHEMECUSTOM_H__D7DEC1A3_106F_4EB3_806F_FA190E338AE4__INCLUDED_)
#define AFX_UGTHEMECUSTOM_H__D7DEC1A3_106F_4EB3_806F_FA190E338AE4__INCLUDED_

#include "UGThemeStyle.h"

namespace UGC {

class MAP_API UGThemeCustom : public UGThemeStyle  
{
public:
	UGThemeCustom();
	virtual ~UGThemeCustom();
	UGThemeCustom(const UGThemeCustom& ThemeCustom);
	UGThemeCustom& operator = (const UGThemeCustom& ThemeCustom);

public:
	//! \brief 专题图是否有效
	virtual UGbool IsValid()const;
	//! \brief 专题图数据信息导成XML格式
	virtual UGString ToXML(UGint nVersion = 0)const;
	//! \brief 从XML中读取专题图信息
	virtual UGbool FromXML(const UGString& strXML, UGint nVersion = 0);
	//! \brief 检测查询字段是否为有效类型
	virtual UGbool CheckFieldType(UGint nType);

	//! \brief 获取查询字段
	virtual UGString GetFieldName(UGbool bAddExpression = true)const;
	//! \brief 清空自定义专题图信息
	void SetEmpty();	

	//! \brief 获取点符号字段的所有信息，如符号风格，大小，角度，颜色等
	UGbool GetMarkerFieldName(UGArray<UGString>& strArray)const; 
	//! \brief 获取线形符号字段的所有信息，如符号风格，线宽，颜色等
	UGbool GetLineFieldName(UGArray<UGString>& strArray)const;
	//! \brief 获取线形符号字段的所有信息，如符号前后景色，透明，渐变等
	UGbool GetFillFieldName(UGArray<UGString>& strArray)const;	

	//! \brief 查找对应记录集的风格
	virtual UGbool FindStyle(UGRecordset *pRecordset, UGStyle &Style)const;	

	//! \brief 获取专题图对象的hashcode
	virtual UGint GetHashCode() const;
	
protected:  
	void Swap(const UGThemeCustom& theme);
	UGbool GetFieldValue(const UGString& strFieldName, UGRecordset *pRecordset, UGdouble &dValue)const;
	
public:
	UGString m_strMarkerStyle;		
	UGString m_strMarkerSize;	
	UGString m_strMarkerAngle;	

	UGString m_strLineStyle;		
	UGString m_strLineWidth;		
	UGString m_strLineColor;		

	UGString m_strFillStyle;	
	UGString m_strFillForeColor;	
	UGString m_strFillBackColor;	
	UGString m_strFillOpaqueRate;	
	UGString m_strFillGradientType;
	UGString m_strFillAngle;		
	UGString m_strFillCenterOffsetX;
	UGString m_strFillCenterOffsetY;

};

}

#endif // !defined(AFX_UGTHEMECUSTOM_H__D7DEC1A3_106F_4EB3_806F_FA190E338AE4__INCLUDED_)
