// UGGraphItem.h: interface for the UGGraphItem class.
//
//////////////////////////////////////////////////////////////////////

/*!
   **************************************************************************************
    \file     UGGraphItem.h
   **************************************************************************************
    \author   陈国雄
    \brief    统计图字段项参数管理类。                                                                       
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2005 SuperMap GIS Technologies,Inc.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-05-20  陈国雄    初始化版本.                                       <br>
   **************************************************************************************
*/

#if !defined(AFX_UGGRAPHITEM_H__593BA4E1_3516_4558_B2BA_5B55B9432CDE__INCLUDED_)
#define AFX_UGGRAPHITEM_H__593BA4E1_3516_4558_B2BA_5B55B9432CDE__INCLUDED_

#include "Base/UGString.h"
#include "Base/UGStyle.h"
#include "Map/UGThemeRange.h"

namespace UGC {

class MAP_API UGGraphItem  
{
public:
	UGGraphItem();
	virtual ~UGGraphItem();
	UGGraphItem(const UGGraphItem& GraphItem);
	UGGraphItem& operator = (const UGGraphItem& GraphItem);

public:
	UGbool FromXML(const UGString& strXML, UGint nVersion = 0);
	UGString ToXML(UGint nVersion = 0)const;

public:
	UGString m_strExpression;
	UGString m_strCaption;
	UGStyle m_Style; 
	UGArray<UGStyle> m_StyleArray;
	UGThemeRange* m_pThemeRange;
};

}

#endif // !defined(AFX_UGGRAPHITEM_H__593BA4E1_3516_4558_B2BA_5B55B9432CDE__INCLUDED_)
