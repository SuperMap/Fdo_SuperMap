
/*!
   **************************************************************************************
    \file     UGFillSymbolLib.h
   **************************************************************************************
    \author   陈国雄
    \brief    填充符号库类。                                                                       
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2005 SuperMap GIS Technologies,Inc.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-05-23  陈国雄    初始化版本.                                       <br>
   **************************************************************************************
*/

#ifndef UGFILLSYMBOLLIB_H
#define UGFILLSYMBOLLIB_H

#include "UGFillSymbol.h"
#include "UGSymbolLib.h"
#include "UGMarkerSymbolLib.h"

namespace UGC {

class SYMBOL_API UGFillSymbolLib : public UGSymbolLib
{
public:
	UGFillSymbolLib();
	virtual ~UGFillSymbolLib();

public:
	//! \brief 填充库读取
	virtual UGbool Load(UGStream& stream);	
	//! \brief 填充库追加
	virtual UGbool Append(UGStream& stream, UGbool bReplace = true);
	//! \brief 填充库保存
	virtual UGbool Save(UGStream& stream, UGuint nVersion = 0) const;

	//! \brief 填充库增加符号
	UGbool Add(const UGString& strRasterFile, UGSymbolGroup *pSymbolGroup = NULL);
	//! \brief 填充库设置关联的点符号库
	void SetResMarkerSymLib(UGMarkerSymbolLib* pResMarkerSymLib);

	//! \brief 填充库获取关联的点符号库
	UGMarkerSymbolLib* GetResMarkerSymLib() const;
	//! \brief 填充库获取关联的点符号库
	UGMarkerSymbolLib* GetMarkerSymLib();

protected:
	UGMarkerSymbolLib* m_pResMarkerSymLib;
	UGMarkerSymbolLib m_MarkerSymLib;
};

}

#endif


