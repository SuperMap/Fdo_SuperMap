/*! 
	\file	SMCQueryDef.h
    \brief	查询定义类
	\author	周 旭
	\attention
	----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2007 SuperMap GIS Technologies,Inc.                            <br>
    All Rights Reserved.                                                              <br>
    ----------------------------------------------------------------------------------<br> 
	\version 2007-9-25 初始化版本
*/

#ifndef SMCQUERYDEF_H
#define SMCQUERYDEF_H

#include "SMC.h"

class SMC_API SMCQueryDef
{
	public:
	//! 查询类型枚举
	enum QueryType
	{
		General							=0, //! 一般查询
		Bounds							=1, //! 使用Bounds查询
		IDs								=2, //! 使用ID数组查询
	};

	//! 查询选项枚举
	enum QueryOption
	{		
		Geometry						= 1,//! 查询几何对象
		Attribute						= 2,//! 查询属性信息
		Both							= 3 //! 查询几何对象及属性信息
	};

	//! 查询模式枚举
	enum QueryMode
	{
		GeneralQuery					=0x00000000, //! 一般查询
		FuzzyQuery						=0x00000001  //! 模糊查询
	};

public:
	//! 构造函数
	SMCQueryDef();
	//! 析构函数
	~SMCQueryDef();

public:
	//! 查询类型(General,Bounds,IDs及各种空间查询等）
	//! 必须 (默认 General)
	QueryType			m_nType;

	//! 查询选项(是否返回Geometry或Attribute,或两者都有等）
	//! 必须 （默认 Both）
	QueryOption			m_nOptions;

	//! 查询方式(GeneralQuery或FuzzyQuery)
	//! 可选 默认呢，GeneralQuery
	QueryMode			m_nMode;
};

#endif