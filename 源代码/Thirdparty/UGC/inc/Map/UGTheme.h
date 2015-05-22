// UGTheme.h: interface for the UGTheme class.
//
//////////////////////////////////////////////////////////////////////

/*!
   **************************************************************************************
    \file     UGTheme.h 
   **************************************************************************************
    \author   陈国雄
    \brief    专题图基类，所有专题图都从它派生。                                                             
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2005 SuperMap GIS Technologies,Inc.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-05-20  陈国雄    初始化版本.                                       <br>
   **************************************************************************************
*/

#if !defined(AFX_UGTHEME_H__AEAB0616_AD6A_4049_9C12_07AE84BC1270__INCLUDED_)
#define AFX_UGTHEME_H__AEAB0616_AD6A_4049_9C12_07AE84BC1270__INCLUDED_

#include "Engine/UGDataSource.h"
#include "Base/UGDict.h"
#include "Base/UGHashCode.h"

namespace UGC {

#define UG_THEME_MAX_VALUE_COUNT	256

class MAP_API UGTheme  
{
public:
	enum UGClassType
	{
		ctEqualDistance,
		ctExtraction,
		ctStdev,
		ctLogarithm,
		ctQuantile,
		ctCustomInterval
	};
	enum UGThemeType //专题图类型
	{
		ttNone =			0,
		ttUnique = 			1,			//UNIQUE专题图
		ttRange	 = 			2,			//RANGE专题图
		ttGraph	 = 			3,			//GRAPH专题图
		ttGraduatedSymbol = 4,			//GRADUATED_SYMBOL专题图
		ttDotDensity =		5,			//DENSITY专题图
//		ttSymbolShade =		6,			//SYMBOL_SHADE专题图
		ttLabel	=			7,			//LABEL专题图
		ttCustom =			8,			//CUSTOM专题图
		ttGridUnique = 		11,			//GRIDUNIQUE专题图
		ttGridRange	 = 		12			//GRIDRANGE专题图
	};
	enum UGThemeGraduatedMode
	{
		gmConstant,
		gmSquareRoot,
		gmLogarithm
	};
	enum UGThemeDataType
	{
		tvRecordset,
		tvExternal,
		tvMixed
	};

public:
	UGTheme();
	virtual ~UGTheme();

public:
	//! \brief 专题图是否有效
	virtual UGbool IsValid()const = 0;
	//! \brief 获取专题图字段
	virtual UGString GetFieldName(UGbool bAddExpression = true)const = 0;
	//! \brief 查看选择字段是否合法
	virtual UGbool CheckFieldType(UGint nType);
	//! \brief 专题图保存为XML信息
	virtual UGString ToXML(UGint nVersion = 0)const;
	//! \brief 专题图读取XML信息
	virtual UGbool FromXML(const UGString& strXML, UGint nVersion = 0);
	//! \brief 获取专题图对象的hashcode
	virtual UGint GetHashCode() const = 0;

	//! \brief 设置外部值
	void SetExternalValue(const UGString& strKey, const UGString& strExternalValue);
	//! \brief 得到外部值
	UGbool GetExternalValue(const UGString& strKey, UGString& strExternalValue)const;
	//! \brief 清空外部值
	void ClearExternalData();
	
	//! \brief 得到最大可见比例	
	UGdouble GetVisibleScaleMax()const;							
	//! \brief 得到最小可见比例	
	UGdouble GetVisibleScaleMin()const;						
	//! \brief 设置最大可见比例
	void SetVisibleScaleMax(UGdouble dVisibleScaleMax);		
	//! \brief 取消最大可见比例
	void CancelVisibleScaleMax();							
	//! \brief 设置最小可见比例
	void SetVisibleScaleMin(UGdouble dVisibleScaleMin);		
	//! \brief 取消最小可见比例
	void CancelVisibleScaleMin();							

	//! \brief 是否可见范围内
	UGbool IsVisibleScale(UGdouble dScale)const;
	//! \brief 是否可见
	UGbool IsVisible()const;
	//! \brief 设置是否可见
	void SetVisible(UGbool bVisible = true);

	//! \brief 得到专题图标题
	UGString GetCaption()const;
	//! \brief 设置专题图标题
	void SetCaption(const UGString& strCaption );

	//! \brief 得到专题图类型
	UGint GetType()const;

	//! \brief 得到专题图数据类型
	UGint GetDataType()const;
	//! \brief 设置专题图数据类型
	void SetDataType(UGint nDataType);

	//! \brief 专题图是否修改
	UGbool IsModified()const;
	//! \brief 设置专题图是否修改
	void SetModifiedFlag(UGbool bModified = true);

	//! \brief 变量转成double型
	static UGbool Variant2Double(const UGVariant& var, double& dKey);
	//! \brief 变量转成字符串
	static UGString Variant2String(const UGVariant& var); //变体变成字符串
	//! \brief 转化专题图类型名称
	/**
	\param nThemeType				类型对应的int值[in]
	\return 对应的字符串名称
	*/
	static UGString ConvertThemeType(UGint nThemeType);
	//! \brief 转化专题图类型名称
	/**
	\param strThemeType		类型对应的字符串名称[in]
	\return 对应的int值
	*/
	static UGint ConvertThemeType(const UGString& strThemeType);

	//! \brief 设置专题图类型名称
	void SetName(UGString strLayerName) {m_strName = strLayerName;};

	//! \brief 得到专题图类型名称
	UGString GetName() {return m_strName;};
	
	
protected:  
	void Swap(const UGTheme& theme);

protected:  
	UGbool m_bModified;
	UGint m_nType;		// 专题图类型
	UGint m_nDataType; // 1,属性表，2，外部用户输入数据,其他为以后预留
	UGDict<UGString,UGString> m_ExternalData; // 字段(表达式)值和外部输入数据的对应	
	
	UGString m_strCaption; //caption for this thematic map
	UGbool m_bVisible;

	UGdouble m_dVisibleScaleMax;	//当地图比例尺大于该值的时候，本图层不显示，若该值小于等于0，则该限制无效。默认为0
	UGdouble m_dVisibleScaleMin;	//当地图比例尺小于该值的时候，本图层不显示，若该值小于等于0，则该限制无效。默认为0

	UGString m_strName;
	

};

}

#endif // !defined(AFX_UGTHEME_H__AEAB0616_AD6A_4049_9C12_07AE84BC1270__INCLUDED_)
