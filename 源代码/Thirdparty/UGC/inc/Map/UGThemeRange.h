// UGThemeRange.h: interface for the UGThemeRange class.
//
//////////////////////////////////////////////////////////////////////

/*!
   **************************************************************************************
    \file     UGThemeRange.h
   **************************************************************************************
    \author   陈国雄
    \brief    分段专题图类。                                                         
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2005 SuperMap GIS Technologies,Inc.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-05-20  陈国雄    初始化版本.                                       <br>
   **************************************************************************************
*/

#if !defined(AFX_UGTHEMERANGE_H__1E880B1F_F87E_4E5A_A46F_D02EFD663CF0__INCLUDED_)
#define AFX_UGTHEMERANGE_H__1E880B1F_F87E_4E5A_A46F_D02EFD663CF0__INCLUDED_

#include "UGThemeStyle.h"
#include "UGThemeItem.h"

namespace UGC {

class UGLayer;

class MAP_API UGThemeRange : public UGThemeStyle  
{
public:
	UGThemeRange();
	virtual ~UGThemeRange();
	UGThemeRange(const UGThemeRange& ThemeRange);//copy construtor
	UGThemeRange& operator = (const UGThemeRange& ThemeRange);

public:
	//! \brief 专题图是否有效
	/**
	*/
	virtual UGbool IsValid()const;
	//! \brief 专题图数据信息导成XML格式
	/**
	*/
	virtual UGString ToXML(UGint nVersion = 0)const;
	//! \brief 从XML中读取专题图信息
	/**
	*/
	virtual UGbool FromXML(const UGString& strXML, UGint nVersion = 0);
	//! \brief 检测查询字段是否为有效类型
	/**
	*/
	virtual UGbool CheckFieldType(UGint nType);
	//! \brief 获取查询字段
	/**
	*/
	virtual UGString GetFieldName(UGbool bAddExpression = true)const;
	//! \brief 获取范围值的个数
	/**
	*/
	virtual UGint GetValueCount()const;
	//! \brief 查找Recordset对应的风格
	/**
	*/
	virtual UGbool FindStyle(UGRecordset *pRecordset, UGStyle &Style)const;

	//! \brief 得到分段中的风格范围的个数
	/**
	*/
	UGint GetCount()const;
	//! \brief 清除范围分段中风格数组和分段值数组
	/**
	*/
	void RemoveAll();

	//! \brief  添加某段值和范围
	/**
	\param dValue         段值[in]
	\param ThemeItem      该段的风格[in]
	\return 当前专题图下的所有风格分段的个数
	*/
	UGint Add(UGdouble dValue, const UGThemeItem& ThemeItem);
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
	\param ThemeItem      该段下的分段风格[in]
	\return 插入是否成功
	*/
	UGbool InsertAt(UGint nIndex, UGdouble dValue, const UGThemeItem& ThemeItem);

	//! \brief  找到该值对应的索引
	/**
	\param dValue         段值[in]
	\return 如果成功则为段值对应的索引，否则返回-1
	*/
	UGint Find(UGdouble dValue)const;
	//! \brief  找到该值对应的范围下的风格
	/**
	\param dValue         段值[in]
	\param Style          对应的风格[in/out]
	\return 是否找到对应值的风格
	*/
	UGbool FindStyle(UGdouble dValue, UGStyle& Style)const;

	//! \brief  计算对应数据集下的段值
	/**
	\param pDatasetV         数据集[in]
	\param strExpression     表达式[in]
	\param arrValues         段值[in/out]
	\return 计算是否成功
	*/
	UGbool CalculateExtremum(UGDatasetVector* pDatasetV, const UGArray<UGJoinItem>& JoinItems, const UGString& strExpression, UGArray<UGdouble>& arrValues);
	
	//! \brief 得到条件表达式
	/**
	*/
	UGString GetExpression()const;			//得到条件表达式,可以是字段名称或表达式
	//! \brief 设置条件表达式
	/**
	*/
	void SetExpression(const UGString& strExpression);

	//! \brief 是否降序
	/**
	*/
	UGbool IsDescending()const;			// 是否降序
	//! \brief 设置是否降序
	/**
	*/
	void SetDescending(UGbool bDescending = false);		// 默认升序

	//! \brief 得到第nIndex段的信息
	/**
	*/
	UGThemeItem GetAt(UGint nIndex)const;
	//! \brief 得到第nIndex段的信息
	/**
	*/
	void SetAt(UGint nIndex, const UGThemeItem& ThemeItem);

	//! \brief 得到第nIndex段的标题
	/**
	*/
	UGString GetCaptionAt(UGint nIndex)const;
	//! \brief 设置第nIndex段的标题
	/**
	*/
	void SetCaptionAt(UGint nIndex, const UGString& strCaption );

	//! \brief 得到第nIndex段的风格
	/**
	*/
	const UGStyle& GetStyleAt(UGint nIndex)const;
	//! \brief 设置第nIndex段的风格
	/**
	*/
	void SetStyleAt(UGint nIndex, const UGStyle& Style);
	
	//! \brief 得到第nIndex段的段值
	/**
	*/
	UGdouble GetValueAt(UGint nIndex)const;
	//! \brief 设置第nIndex段的段值
	/**
	*/
	void SetValueAt(UGint nIndex, UGdouble dValue);

	//! \brief 第nIndex段是否可见
	/**
	*/
	UGbool IsVisibleAt(UGint nIndex)const;
	//! \brief 设置第nIndex段是否可见
	/**
	*/
	void SetVisibleAt(UGint nIndex, UGbool bVisible = true);

	//modified by xilin 2007-07-10 陈勇上面包装的时候不想传入UGLayer，修改一下接口如下
	//UGbool MakeDefault(UGint nClassType, UGint nClasses, const UGArray<UGdouble> &aryValues, UGdouble dInterval = 0.0, UGLayer* pLayer = NULL);
	//! \brief 设置默认分段
	/**
	\param nClassType         分段类型[in]
	\param nClasses           分段个数[in]
	\param aryValues          分段值[in]
	\param dInterval          自定义分段的范围[in]
	\param pDv                对应数据集[in]
	\param pQueryDef          查询条件[in]
	*/
	UGbool MakeDefault(UGint nClassType, UGint nClasses, const UGArray<UGdouble> &aryValues, UGdouble dInterval = 0.0, UGDatasetVector* pDv = NULL,UGQueryDef* pQueryDef = NULL);
	//! \brief 设置默认标题
	void MakeDefaultCaptions();
	//! \brief 设置默认风格
	void MakeDefaultStyles(UG_ENUM_STOCK_GRADIENT_SET_STYLE nIndex);

	//! \brief 设置分段范围
	/**
	*/
	UGbool SetRanges(UGdouble *pValues, UGint nValueCount);
	//! \brief 分段是否有效
	/**
	*/
	UGbool IsValidValueCount(UGint nValueCount)const;
	
	//! \brief 获取专题图对象的hashcode
	virtual UGint GetHashCode() const;
protected:  
	void Swap(const UGThemeRange& theme);	
	UGRecordset * QueryWithExpression(UGDatasetVector *pDatasetV, const UGArray<UGJoinItem>& JoinItems, const UGString& strExpression);
	void ClassifyWithCustomInterval(UGdouble dInterval, UGdouble dMaxVaue, UGdouble dMinValue);
	void ClassifyWithEqualDistance(UGint nClasses, UGdouble dMaxVaue, UGdouble dMinValue);
	void ClassifyWithExtraction(UGint nClasses, UGdouble dMaxVaue, UGdouble dMinValue);
	void Stdev(const UGArray<UGdouble> &arySrc, UGdouble &dMean, UGdouble &dStdev);
	void ClassifyWithStdev(const UGArray<UGdouble> &arySrc);
	void ClassifyWithLogarithm(UGint nClasses, UGdouble dMaxVaue, UGdouble dMinValue);
	//modified by xilin 2007-07-10 陈勇上面包装的时候不想传入UGLayer，修改一下接口如下
	//void ClassifyWithQuantile(UGint nClasses, UGint nKeyCount, UGLayer* pLayer);
	void ClassifyWithQuantile(UGint nClasses, UGint nKeyCount, UGDatasetVector* pDv,UGQueryDef* pQueryDef);

protected:
	UGString m_strExpression;
	UGbool m_bDescending;
	UGArray<UGdouble> m_Values;
	UGArray<UGThemeItem> m_RangeItems;

};

}

#endif // !defined(AFX_UGTHEMERANGE_H__1E880B1F_F87E_4E5A_A46F_D02EFD663CF0__INCLUDED_)
