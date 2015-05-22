// UGEngineDefine.h: interface for the UGEngineDefine class.
//
//////////////////////////////////////////////////////////////////////

/*!
   **************************************************************************************
    \file     UGEngineDefine.h
   **************************************************************************************
    \author   陈国雄
    \brief    数据引擎动态库定义类。                                                 
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2005 SuperMap GIS Technologies,Inc.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-05-19  陈国雄    初始化版本.                                       <br>
   **************************************************************************************
*/

#if !defined(AFX_UGENGINEDEFINE_H__050487B3_D93F_41AF_974B_AAB48862D363__INCLUDED_)
#define AFX_UGENGINEDEFINE_H__050487B3_D93F_41AF_974B_AAB48862D363__INCLUDED_

#include "Engine/UGDataSource.h"

namespace UGC {

class ENGINE_API UGEngineDefine  
{
public:
	UGEngineDefine();
	virtual ~UGEngineDefine();
	
public:
	void operator =(const UGEngineDefine& EngineDef);
	//========================================================
	//! \brief 		清空数据引擎定义信息。
	void Empty();
public:
	//! \brief 		数据源引擎类型。 
	UGEngineType m_nType;
	//! \brief 		数据引擎动态库名称描述。
	UGString m_strName;
	//! \brief 		数据引擎动态库句柄。 
	void* m_hHandle;	
};

}

#endif // !defined(AFX_UGENGINEDEFINE_H__050487B3_D93F_41AF_974B_AAB48862D363__INCLUDED_)
