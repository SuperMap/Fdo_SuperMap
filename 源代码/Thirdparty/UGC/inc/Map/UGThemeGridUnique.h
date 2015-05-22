// UGThemeGridUnique.h: interface for the UGThemeGridUnique class.
//
//////////////////////////////////////////////////////////////////////

/*!
   **************************************************************************************
    \file     UGThemeGridUnique.h
   **************************************************************************************
    \author   陈国雄
    \brief    Grid单值专题图类。                                                     
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2005 SuperMap GIS Technologies,Inc.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-05-20  陈国雄    初始化版本.                                       <br>
   **************************************************************************************
*/

#if !defined(AFX_UGTHEMEGRIDUNIQUE_H__8B99A243_9B39_4032_9576_3A33420C55BD__INCLUDED_)
#define AFX_UGTHEMEGRIDUNIQUE_H__8B99A243_9B39_4032_9576_3A33420C55BD__INCLUDED_

#include "Base/UGColorset.h"
#include "UGTheme.h"

namespace UGC {

class MAP_API UGThemeGridUnique : public UGTheme  
{
	friend class UGLayer;
public:
	UGThemeGridUnique();
	virtual ~UGThemeGridUnique();	
	UGThemeGridUnique(const UGThemeGridUnique& ThemeGridUnique);
	UGThemeGridUnique& operator = (const UGThemeGridUnique& ThemeGridUnique);

public:
	//位了支持double类型的grid或者dem，把以前存储为UGint都改为UGdouble,modified by xielin 2007-08-06
	//! \brief 专题图是否有效
	virtual UGbool IsValid()const;
	//! \brief 专题图数据信息导成XML格式
	virtual UGString ToXML(UGint nVersion = 0)const;
	//! \brief 从XML中读取专题图信息
	virtual UGbool FromXML(const UGString& strXML, UGint nVersion = 0);
	//! \brief 获取查询字段
	virtual UGString GetFieldName(UGbool bAddExpression = true)const;

	//! \brief 得到第nIndex段的段值
	UGdouble GetValueAt(UGint nIndex)const;
	//! \brief 设置第nIndex段的段值
	void SetValueAt(UGint nIndex, UGdouble dValue);

	//! \brief 得到第nIndex段的颜色
	UGColor GetColorAt(UGint nIndex)const;
	//! \brief 设置第nIndex段的颜色
	void SetColorAt(UGint nIndex, UGColor color);
	
	//! \brief 得到第nIndex段的标题
	UGString GetCaptionAt(UGint nIndex)const;
	//! \brief 设置第nIndex段的标题
	void SetCaptionAt(UGint nIndex, const UGString& strCaption);

	//! \brief 第nIndex段是否可见
	UGbool IsVisibleAt(UGint nIndex)const;
	//! \brief 设置第nIndex段是否可见
	void SetVisibleAt(UGint nIndex, UGbool bVisible = true);
	
	//! \brief 获取默认颜色
	UGColor GetDefaultColor()const;
	//! \brief 得到默认颜色
	void SetDefaultColor(UGColor color);

	//! \brief 检查某字段值四否存在
	UGbool IsExist(UGdouble dValue)const;
	//! \brief 查找某值对应的颜色
	UGColor FindColor(UGdouble dValue)const;
	//! \brief 查找某值对应的索引
	UGint Find(UGdouble nValue)const;

	
	//UGbool Add(UGint nValue);
	//! \brief  添加某段值
	/**
	\param dValue         段值[in]
	\return 添加是否成功
	*/
	UGbool Add(UGdouble dValue);
	//UGbool InsertAt(UGint nIndex, UGint nValue);
	//! \brief  插入某段值和范围
	/**
	\param nIndex         插入段的索引[in]
	\param dValue         段值[in]
	\return 插入是否成功
	*/
	UGbool InsertAt(UGint nIndex, UGdouble dValue);
	//! \brief  移除某段值和范围
	/**
	\param nIndex         移除段的索引[in]
	\param nCount         从该索引下删除的个数[in]
	\return 删除的个数
	*/
	UGint RemoveAt(UGint nIndex,UGint nCount = 1);	
	//! \brief  交换两个索引对应的值和颜色的位置
	UGbool Swap(UGint nIndex1, UGint nIndex2);	
	//! \brief 清除单值分段中颜色数组和分段值数组
	void RemoveAll();
	//! \brief 获取段值个数
	UGint GetCount()const;

	//! \brief 对段值进行排序
	/**
	\param bDescending    是否按照降序[in]
	*/
	void Sort(UGbool bDescending = false);
	//! \brief 是否为有效段数
	UGbool IsValidCount(UGint nCount)const;
	
	//! \brief 设置默认标题
	void MakeDefaultCaptions();
	//! \brief 设置默认颜色
	void MakeGradientColors(UGColor clrStart, UGColor clrEnd);
	//! \brief 设置默认颜色
	void MakeDefaultColors();

	//! \brief 获取专题图对象的hashcode
	virtual UGint GetHashCode() const;

	UGColor m_NoDataStyle;
protected:  
	void Swap(const UGThemeGridUnique& theme);	

protected:
	//改成double的吧，要支持double,modified by xielin 2007-08-06
	//UGArray<UGint> m_Values;		//Values
	UGArray<UGdouble> m_Values;
	UGColorset m_Colors;		//colors
	UGArray<UGbool> m_Visibles;		//Visibles
	UGColor m_DefaultColor;			//default color
	UGArray<UGString> m_Captions;		//每个单值的Caption

};

}

#endif // !defined(AFX_UGTHEMEGRIDUNIQUE_H__8B99A243_9B39_4032_9576_3A33420C55BD__INCLUDED_)
