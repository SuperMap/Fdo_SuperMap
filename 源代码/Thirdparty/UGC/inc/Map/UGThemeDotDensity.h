// UGThemeDotDensity.h: interface for the UGThemeDotDensity class.
//
//////////////////////////////////////////////////////////////////////

/*!
   **************************************************************************************
    \file     UGThemeDotDensity.h
   **************************************************************************************
    \author   陈国雄
    \brief    点密度专题图类。                                                         
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2005 SuperMap GIS Technologies,Inc.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-05-20  陈国雄    初始化版本.                                       <br>
   **************************************************************************************
*/

#if !defined(AFX_UGTHEMEDOTDENSITY_H__06A0D835_186A_4C11_9157_F6BBC8423E8A__INCLUDED_)
#define AFX_UGTHEMEDOTDENSITY_H__06A0D835_186A_4C11_9157_F6BBC8423E8A__INCLUDED_

#include "UGTheme.h"
#include "Drawing/UGDrawing.h"

namespace UGC {

class MAP_API UGThemeDotDensity : public UGTheme  
{
public:
	UGThemeDotDensity();
	virtual ~UGThemeDotDensity();
	UGThemeDotDensity(const UGThemeDotDensity& ThemeDotDensity);
	UGThemeDotDensity& operator = (const UGThemeDotDensity& ThemeDotDensity);

public:
	//! \brief 点密度专题图是否有效
	virtual UGbool IsValid()const;
	//! \brief 点密度专题图保存为XML信息
	virtual UGString ToXML(UGint nVersion = 0)const;
	//! \brief 点密度专题图读取XML信息
	virtual UGbool FromXML(const UGString& strXML, UGint nVersion = 0);
	//! \brief 点密度专题图检查字段是否合法
	virtual UGbool CheckFieldType(UGint nType);
	//! \brief 点密度专题图获取字段名称
	virtual UGString GetFieldName(UGbool bAddExpression = true)const;

	//! \brief 得到条件表达式,可以是字段名称或表达式
	UGString GetExpression()const;						
	//! \brief 设置条件表达式,可以是字段名称或表达式
	void SetExpression(const UGString& strExpression );	

	//! \brief 点密度专题图转化为几何对象
	/**
	\param pRegion			类型对应的字符串名称[in]
	\param pDrawParam		类型对应的字符串名称[in]
	\param dValue			点代表的值[in]
	\return 转换的几何对象
	*/
	UGGeometry* ConvertToGeometry(UGGeoRegion* pRegion, UGDrawParamaters *pDrawParam, UGdouble dValue);
	
	UGdouble RecommendDotValue(UGDatasetVector *pDatasetV, const UGArray<UGJoinItem>& JoinItems, const UGString& strFieldName);
	//! \brief 绘制点密度专题图
	/**
	\param pDrawing			绘制参数[in]
	\param pRegion			绘制的面对象[in]
	\param dValue			点代表的值[in]
	\return 转换的几何对象
	*/
	UGbool Draw(UGDrawing *pDrawing, UGGeoRegion *pRegion, UGdouble dValue);
	
	//! \brief 得到点代表的符号
	const UGStyle& GetMarkerStyle()const;
	//! \brief 设置点代表的符号
	void SetMarkerStyle(UGStyle& Style);

	//! \brief 得到点代表的值
	UGdouble GetDotValue()const;
	//! \brief 设置点代表的值
	void SetDotValue(UGdouble dDotValue);
	
	//! \brief 获取专题图对象的hashcode
	virtual UGint GetHashCode() const;

protected:  
	void Swap(const UGThemeDotDensity& theme);
	UGbool DotFillRandom(UGDrawing *pDrawing, UGGeoRegion *pRegion, UGint nDotCount);
	
protected:
	UGStyle m_MarkerStyle;
	UGdouble m_dDotValue;
	UGString m_strExpression;

};

}

#endif // !defined(AFX_UGTHEMEDOTDENSITY_H__06A0D835_186A_4C11_9157_F6BBC8423E8A__INCLUDED_)
