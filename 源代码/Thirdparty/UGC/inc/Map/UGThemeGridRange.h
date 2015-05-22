// UGThemeGridRange.h: interface for the UGThemeGridRange class.
//
//////////////////////////////////////////////////////////////////////

/*!
   **************************************************************************************
    \file     UGThemeGridRange.h
   **************************************************************************************
    \author   陈国雄
    \brief    Grid分段专题图类。                                                     
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2005 SuperMap GIS Technologies,Inc.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-05-20  陈国雄    初始化版本.                                       <br>
   **************************************************************************************
*/

#if !defined(AFX_UGTHEMEGRIDRANGE_H__66F63B7E_2BC1_47BA_8BBA_15B35BDEF0B8__INCLUDED_)
#define AFX_UGTHEMEGRIDRANGE_H__66F63B7E_2BC1_47BA_8BBA_15B35BDEF0B8__INCLUDED_

#include "UGTheme.h"

namespace UGC {

class UGLayer;

class MAP_API UGThemeGridRange : public UGTheme  
{
	friend class UGLayer;

public:
	UGThemeGridRange();
	virtual ~UGThemeGridRange();
	UGThemeGridRange(const UGThemeGridRange& ThemeGridRange);//copy construtor
	UGThemeGridRange& operator = (const UGThemeGridRange& ThemeGridRange);

public:
	//! \brief 专题图是否有效
	virtual UGbool IsValid()const;
	//! \brief 专题图数据信息导成XML格式
	virtual UGString ToXML(UGint nVersion = 0)const;
	//! \brief 从XML中读取专题图信息
	virtual UGbool FromXML(const UGString& strXML, UGint nVersion = 0);
	//! \brief 获取查询字段
	virtual UGString GetFieldName(UGbool bAddExpression = true)const;
	
	//! \brief 获取范围值的个数
	virtual UGint GetValueCount()const;

	//! \brief 得到分段中的风格范围的个数
	UGint GetCount()const;
	//! \brief 清除范围分段中风格数组和分段值数组
	void RemoveAll();

	//! \brief  添加某段值
	/**
	\param dValue         段值[in]
	\return 当前专题图下的所有风格分段的个数
	*/
	UGint Add(UGdouble dValue);
	//! \brief  移除某段值和范围
	/**
	\param nIndex         移除段的索引[in]
	\param nCount         从该索引下删除的个数[in]
	\return 删除的个数
	*/
	UGint RemoveAt(UGint nIndex, UGint nCount = 1);
	//! \brief  插入某段值和范围
	/**
	\param nIndex         插入段的索引[in]
	\param dValue         段值[in]
	\return 插入是否成功
	*/
	UGbool InsertAt(UGint nIndex, UGdouble dValue);

	//! \brief  查找某段值
	UGint Find(UGdouble dValue)const ;
	//! \brief  查找某值对应的颜色
	UGbool FindColor(UGdouble dValue, UGColor& color)const;

	//! \brief 是否降序
	UGbool IsDescending()const;			// 是否降序
	//! \brief 设置是否降序
	void SetDescending(UGbool bDescending = false);		// 默认升序

	//! \brief 得到第nIndex段的标题
	UGString GetCaptionAt(UGint nIndex)const;
	//! \brief 设置第nIndex段的标题
	void SetCaptionAt(UGint nIndex, const UGString& strCaption );

	//! \brief 得到第nIndex段的颜色
	UGColor GetColorAt(UGint nIndex)const;
	//! \brief 设置第nIndex段的颜色
	void SetColorAt(UGint nIndex, UGColor color);
	
	//! \brief 得到第nIndex段的段值
	UGdouble GetValueAt(UGint nIndex)const;
	//! \brief 设置第nIndex段的段值
	void SetValueAt(UGint nIndex, UGdouble dValue);

	//! \brief 第nIndex段是否可见
	UGbool IsVisibleAt(UGint nIndex)const;
	//! \brief 设置第nIndex段是否可见
	void SetVisibleAt(UGint nIndex, UGbool bVisible = true);

	//! \brief 分段是否有效
	UGbool IsValidValueCount(UGint nValueCount)const;
	//! \brief 设置分段范围
	UGbool SetRanges(UGdouble *pValues, UGint nValueCount);

	//! \brief 设置默认分段
	/**
	\param nClassType         分段类型[in]
	\param nClasses           分段个数[in]
	\param dMaxValue          分段最大值[in]
	\param dMinValue          分段最小值[in]
	*/
	UGbool MakeDefault(UGint nClassType, UGint nClasses, UGdouble dMaxValue, UGdouble dMinValue, UGdouble dInterval = 0.0);
	//! \brief 设置默认颜色值
	void MakeDefaultColors();
	void MakeDefaultColors(UG_ENUM_STOCK_GRADIENT_SET_STYLE nIndex);
	void MakeDefaultColors(UGColor clrStart, UGColor clrEnd);
	//! \brief 设置默认标题
	void MakeDefaultCaptions();

	//! \brief 获取专题图对象的hashcode
	virtual UGint GetHashCode() const;

	UGColor m_NoDataStyle;

protected:  
	void Swap(const UGThemeGridRange& theme);	
	void ClassifyWithCustomInterval(UGdouble dInterval, UGdouble dMaxVaue, UGdouble dMinValue);
	void ClassifyWithEqualDistance(UGint nClasses, UGdouble dMaxVaue, UGdouble dMinValue);
	void ClassifyWithExtraction(UGint nClasses, UGdouble dMaxVaue, UGdouble dMinValue);
	void ClassifyWithLogarithm(UGint nClasses, UGdouble dMaxVaue, UGdouble dMinValue);

protected:
	UGbool m_bDescending;
	UGArray<UGdouble> m_Values;
	UGColorset m_Colors;		//colors
	UGArray<UGbool> m_Visibles;		//Visibles
	UGArray<UGString> m_Captions;	//每个单值的Caption

};

}

#endif // !defined(AFX_UGTHEMEGRIDRANGE_H__66F63B7E_2BC1_47BA_8BBA_15B35BDEF0B8__INCLUDED_)
