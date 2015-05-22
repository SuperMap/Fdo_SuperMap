// UGThemeUnique.h: interface for the UGThemeUnique class.
//
//////////////////////////////////////////////////////////////////////

/*!
   **************************************************************************************
    \file     UGThemeUnique.h
   **************************************************************************************
    \author   陈国雄
    \brief    单值专题图类。                                                         
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2005 SuperMap GIS Technologies,Inc.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-05-20  陈国雄    初始化版本.                                       <br>
   **************************************************************************************
*/

#if !defined(AFX_UGTHEMEUNIQUE_H__5C24AD2C_3397_4CF7_89CA_8D10DA408701__INCLUDED_)
#define AFX_UGTHEMEUNIQUE_H__5C24AD2C_3397_4CF7_89CA_8D10DA408701__INCLUDED_

#include "UGThemeStyle.h"
#include "UGThemeItem.h"

namespace UGC {

class MAP_API UGThemeUnique : public UGThemeStyle  
{
public:
	UGThemeUnique();
	virtual ~UGThemeUnique();
	UGThemeUnique(const UGThemeUnique& ThemeUnique);
	UGThemeUnique& operator = (const UGThemeUnique& ThemeUnique);

public:
	//! \brief 专题图是否有效
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
	virtual UGbool CheckFieldType(UGint nType);

	//! \brief 获取查询字段
	virtual UGString GetFieldName(UGbool bAddExpression = true)const;
	//! \brief 获取记录集对应的风格
	/**
	\param pRecordset 所选的记录集[in]
	\param Style      对应风格[in/out]
	*/
	virtual UGbool FindStyle(UGRecordset *pRecordset, UGStyle &Style) const;
	//! \brief 获取字段表达式
	UGString GetExpression()const;
	//! \brief 设置字段表达式
	void SetExpression(const UGString& strExpression);

	//! \brief 得到该索引对应的段值
	/**
	\param nIndex 索引值[in]
	\return 对应索引的值
	*/
	UGString GetValueAt(UGint nIndex)const;
	//! \brief 设置该索引对应的段值
	/**
	\param nIndex     索引值[in]
	\param strValue   对应的值[in]
	*/
	void SetValueAt(UGint nIndex, const UGString& strValue);

	//! \brief 得到该索引对应的风格
	/**
	\param nIndex     索引值[in]
	\return 对应的风格[in]
	*/
	const UGStyle& GetStyleAt(UGint nIndex )const;
	//! \brief 设置该索引对应的风格
	/**
	\param nIndex     索引值[in]
	\param Style      对应的风格[in]
	*/
	void SetStyleAt(UGint nIndex, const UGStyle& Style);
	
	//! \brief 得到该索引对应的标题
	/**
	\param nIndex     索引值[in]
	\return 索引对应的标题
	*/
	UGString GetCaptionAt(UGint nIndex)const;
	//! \brief 设置该索引对应的标题
	/**
	\param nIndex          索引值[in]
	\param strCaption      对应的标题[in]
	*/
	void SetCaptionAt(UGint nIndex, const UGString& strCaption);

	//! \brief 该索引对应的风格是否可见
	/**
	\param nIndex        索引值[in]
	\return    是否可见
	*/
	UGbool IsVisibleAt(UGint nIndex)const;
	//! \brief 设置该索引对应的风格是否可见
	/**
	\param nIndex          索引值[in]
	\param bVisible        是否可见[in]
	*/
	void SetVisibleAt(UGint nIndex, UGbool bVisible = true);

	//! \brief 检验该段值是否存在
	/**
	\param strValue        段值[in]
	\return 该段值是否存在
	*/
	UGbool IsExist(const UGString& strValue)const;
	//! \brief 查找对应的段值的字段风格信息
	/**
	\param strValue        段值[in]
	\param ThemeItem       对应风格信息[in/out]
	\return 返回查找该段值是否成功
	*/
	UGbool Find(const UGString& strValue, UGThemeItem& ThemeItem) const;
	//! \brief 查找对应的段值的字段标题
	/**
	\param strValue        段值[in]
	\param strCaption      对应标题[in/out]
	\return 返回查找该段值是否成功
	*/
	UGbool FindCaption(const UGString& strValue, UGString& strCaption) const;

	//! \brief 获取变量对应的风格
	/**
	\param variant    所选的变量[in]
	\param Style      对应风格[in/out]
	\return 如果返回为-1则为查找失败，如果为0则为查找成功但该风格不可见，如果为1则为查找成功且该风格可见
	*/
	UGint FindStyle(const UGVariant& variant, UGStyle &Style) const;
	//! \brief 获取对应段值的风格
	/**
	\param strValue    所选的段值[in]
	\param Style       对应风格[in/out]
	\return 如果返回为-1则为查找失败，如果为0则为查找成功但该风格不可见，如果为1则为查找成功且该风格可见
	*/
	UGint FindStyle(const UGString& strValue, UGStyle &Style) const;
	
	//! \brief 计算对应数据集下的各个段值
	/**
	\param strValue        段值[in]
	\param JoinItems       对应外部属性表[in]
	\param strExpression   字段表达式[in]
	\param strValues       得到的段值[in/out]
	\param bLimitCount     是否限制段个数[in]
	\return 返回段值个数，如果为0则表示失败
	*/
	UGint CalculateUniqueValues(UGDatasetVector *pDatasetV, const UGArray<UGJoinItem>& JoinItems, const UGString& strExpression, UGArray<UGString>& strValues, UGbool bLimitCount = false);
	
	//! \brief 得到默认风格
	const UGStyle& GetDefaultStyle()const;
	//! \brief 设置默认风格
	void SetDefaultStyle(const UGStyle& Style);

	//! \brief 得到该索引下的段风格
	UGThemeItem GetAt(UGint nIndex)const;
	//! \brief 设置该索引下的段风格
	void SetAt(UGint nIndex, const UGThemeItem& ThemeItem);

	//! \brief 添加某一风格字段
	/**
	\param strValue        段值[in]
	\param ThemeItem       添加风格[in]
	\return 添加是否成功
	*/
	UGbool Add(const UGString& strValue, const UGThemeItem& ThemeItem);	
	//! \brief 插入某一风格字段
	/**
	\param nIndex          要插入的索引[in]
	\param strValue        段值[in]
	\param ThemeItem       添加风格[in]
	\return 插入是否成功
	*/
	UGbool InsertItem(UGint nIndex, const UGString& strValue, const UGThemeItem& ThemeItem);
	//! \brief 移除某一风格字段
	/**
	\param nIndex          要移除的索引[in]
	\param nCount          移除的个数[in]
	\return 实际移除的个数
	*/
	UGint RemoveAt(UGint nIndex, UGint nCount = 1);
	//! \brief 移除某一风格字段
	/**
	\param strValue          要移除的段值[in]
	\return 移除是否成功
	*/
	UGbool Remove(const UGString& strValue);
	
	//! \brief 交换段值位置
	/**
	\param nIndex1          要交换的段值1[in]
	\param nIndex2          要交换的段值2[in]
	\return 交换是否成功
	*/
	UGbool Swap(UGint nIndex1, UGint nIndex2);	
	//! \brief 清空段值及其风格
	void RemoveAll();

	//! \brief 获取段个数
	UGint GetCount()const;

	//! \brief 对段值进行排序
	/**
	\param nType          排序方式[in]
	\param bDescending    是否按照降序[in]
	*/
	void Sort(UGint nType, UGbool bDescending = false);
	//! \brief 是否为有效段数
	UGbool IsValidValueCount(UGint nValueCount)const;
	
	//! \brief 获取专题图对象的hashcode
	virtual UGint GetHashCode() const;
protected:  
	void Swap(const UGThemeUnique& theme);	
	UGRecordset * QueryWithExpression(UGDatasetVector *pDatasetV, const UGArray<UGJoinItem>& JoinItems, const UGString& strExpression);

protected:
	UGString m_strExpression;
	UGDict<UGString,UGThemeItem> m_UniqueItems;
	UGArray<UGString> m_strKeys;

	UGStyle m_DefaultStyle; 

};

}

#endif // !defined(AFX_UGTHEMEUNIQUE_H__5C24AD2C_3397_4CF7_89CA_8D10DA408701__INCLUDED_)
