// UGDataSourceManager.h: interface for the UGDataSourceManager class.
//
//////////////////////////////////////////////////////////////////////

/*!
   **************************************************************************************
    \file     UGDataSourceManager.h
   **************************************************************************************
    \author   陈国雄
    \brief    数据引擎动态库管理类，负责动态加载和释放sdx引擎动态库，并根据引擎类型和
			  动态库句柄创建不同类型的数据源。                                             
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2005 SuperMap GIS Technologies,Inc.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-05-19  陈国雄    初始化版本.                                       <br>
   **************************************************************************************
*/


#if !defined(AFX_UGDATASOURCEMANAGER_H__EA4836B3_3C1F_4535_A920_07AC41C17303__INCLUDED_)
#define AFX_UGDATASOURCEMANAGER_H__EA4836B3_3C1F_4535_A920_07AC41C17303__INCLUDED_

#include "UGEngineDefine.h"

namespace UGC {
  
class ENGINE_API UGDataSourceManager  
{
public:
	UGDataSourceManager();
	virtual ~UGDataSourceManager();

public:
	//========================================================
	//! \brief 		创建数据源实例，本函数并不会真正创建一个数据源，不会生成Oracle或SQL Server数据库，
	//				仅仅根据指定的数据源类型创建一个UGDataSource某个子类的实例，并返回其指针。
	//! \return 	UGDataSource*  new一个数据源指针，如果创建不成功就返回NULL。
	//! \param 		nEngineType 数据引擎类型，可以是用户扩展的引擎类型。
	static UGDataSource* CreateDataSource(UGEngineType nEngineType);

	static void FreeDao();

protected:

	//========================================================
	//! \brief 		动态加载后缀名为sdx的数据引擎动态库。
	void LoadSDX();



protected:
	
	//========================================================
	//! \brief 		释放动态加载的sdx数据引擎动态库。
	void UnloadSDX();
	//========================================================
	//! \brief 		判断数据引擎动态库句柄是否有效，如果有效就构造一个引擎动态库定义。
	//! \return 	UGbool 如果数据引擎动态库句柄有效就返回true，否则就返回false。
	//! \param 		hHandle 数据引擎动态库句柄。
	//! \param 		EngineDef 引擎动态库定义。
	UGbool CheckEngineDef(void* hHandle, UGEngineDefine& EngineDef);
	//========================================================
	//! \brief 		根据数据源引擎类型查找一个引擎动态库定义。
	//! \return 	UGbool 如果找到就返回true，否则就返回false。
	//! \param 		nEngineType 数据源引擎类型。
	//! \param 		EngineDefine 引擎动态库定义。
	UGbool FindEngine(UGEngineType nEngineType, UGEngineDefine& EngineDefine);

public:	
	//! \brief 		引擎动态库定义数组 
	UGArray<UGEngineDefine> m_EngineDefines;

};

extern ENGINE_API UGDataSourceManager g_DataSourceManager;

}

#endif // !defined(AFX_UGDATASOURCEMANAGER_H__EA4836B3_3C1F_4535_A920_07AC41C17303__INCLUDED_)
