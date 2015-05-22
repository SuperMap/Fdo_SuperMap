// UGThemeGraduatedSymbol.h: interface for the UGThemeGraduatedSymbol class.
//
//////////////////////////////////////////////////////////////////////

/*!
   **************************************************************************************
    \file     UGThemeGraduatedSymbol.h
   **************************************************************************************
    \author   陈国雄
    \brief    等级符号专题图类。                                                     
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2005 SuperMap GIS Technologies,Inc.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-05-20  陈国雄    初始化版本.                                       <br>
   **************************************************************************************
*/

#if !defined(AFX_UGTHEMEGRADUATEDSYMBOL_H__DF2EF891_8B50_4D38_8FF0_440CB02B0055__INCLUDED_)
#define AFX_UGTHEMEGRADUATEDSYMBOL_H__DF2EF891_8B50_4D38_8FF0_440CB02B0055__INCLUDED_

#include "UGThemeSymbol.h"

namespace UGC {

class MAP_API UGThemeGraduatedSymbol : public UGThemeSymbol  
{
public:
	UGThemeGraduatedSymbol();
	virtual ~UGThemeGraduatedSymbol();
	UGThemeGraduatedSymbol(const UGThemeGraduatedSymbol& ThemeGraduatedSymbol);
	UGThemeGraduatedSymbol& operator = (const UGThemeGraduatedSymbol& ThemeGraduatedSymbol);

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
	
	//! \brief 获取X偏移量
	virtual UGString GetOffsetXFieldName(UGbool bAddExpression = true)const;
	//! \brief 获取Y偏移量
	virtual UGString GetOffsetYFieldName(UGbool bAddExpression = true)const;

	//! \brief 计算符号风格
	UGbool CalculateSymbolStyle(UGdouble dValue, UGStyle& Style);
	//! \brief 计算符号大小
	UGdouble CalculateSymbolSize(UGdouble dValue);

	//! \brief 设置默认等级符号风格
	/**
	\param pDatasetV    数据集[in]
	\param JoinItems    外部关联表[in]
	*/
	UGbool MakeDefault(UGDatasetVector *pDatasetV, const UGArray<UGJoinItem>& JoinItems);

	//! \brief 得到等级符号基准值
	UGdouble GetDefinitionValue()const;
	//! \brief 设置等级符号基准值
	void SetDefinitionValue(UGdouble dValue);

	//! \brief 得到等级符号分级方式
	UGint GetGraduatedMode()const;
	//! \brief 设置等级符号分级方式
	void SetGraduatedMode(UGint nGraduatedMode = UGTheme::gmSquareRoot);

	//! \brief 设置等级符号是否显示负值
	void SetEnableNegative(UGbool bEnableNegative = true);
	//! \brief 得到等级符号是否显示负值
	UGbool IsEnableNegative()const;

	//! \brief 计算等级符号值的极值
	/**
	\param pDatasetV       数据集[in]
	\param JoinItems       外部关联表[in]
	\param strFieldName    数据集表达的字段[in]
	*/
	UGdouble CalculateExtremum(UGDatasetVector* pDatasetV, const UGArray<UGJoinItem>& JoinItems, const UGString strFieldName);

	//! \brief 得到负值的风格
	const UGStyle& GetNegativeStyle()const;
	//! \brief 设置负值的风格
	void SetNegativeStyle(const UGStyle& Style);

	//! \brief 得到正值的风格
	const UGStyle& GetPositiveStyle()const;
	//! \brief 设置正值的风格
	void SetPositiveStyle(const UGStyle& Style);

	//! \brief 得到字段表达式
	UGString GetExpression()const;
	//! \brief 设置字段表达式
	void SetExpression(const UGString& strExpression);

	//! \brief 获取专题图对象的hashcode
	virtual UGint GetHashCode() const;

	//! \brief 设置是否置顶
	void SetGraduatedSymbolAlwaysOnTop(UGbool bAlwaysOnTop);
	//! \brief 得到是否置顶
	UGbool IsGraduatedSymbolAlwaysOnTop()const;

	//! \brief 得到是否支持零值
	UGbool IsEnableZero()const;

	//! \brief 是否支持零值
	void SetEnableZero(UGbool bEnableZero);

	//! \brief 得到零值的风格
	const UGStyle& GetZeroStyle()const;

	//! \brief 设置零值的风格
	void SetZeroStyle(const UGStyle& Style);

	//! \brief 得到近似零值的大小
	UGdouble GetEpsilon() const;

	//! \brief 设置近似零值的大小
	void SetEpsilon(UGdouble dEpsilon);

	UGDict<UGint, UGPoint2D> m_arrCustomSymbol;

protected:  
	void Swap(const UGThemeGraduatedSymbol& theme);

protected:
	UGStyle m_NegativeStyle; 
	UGStyle m_PositiveStyle; 
	UGStyle m_ZeroStyle;
	UGdouble m_dDefinitionValue;
	UGString m_strExpression;
	UGbool m_bAlwaysOnTop;
	double m_dEpsilon;  //如果字段值比这个值小，那就认为是0值,默认1e-10;

};

}

#endif // !defined(AFX_UGTHEMEGRADUATEDSYMBOL_H__DF2EF891_8B50_4D38_8FF0_440CB02B0055__INCLUDED_)
