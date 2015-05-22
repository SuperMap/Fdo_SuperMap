/*! 
	\file	SMCTable.h
    \brief	数据集基类（抽象类）预留在此以便扩展对属性数据的操作
	\author	周旭
	\attention
	----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2007 SuperMap GIS Technologies,Inc.                            <br>
    All Rights Reserved.                                                              <br>
    ----------------------------------------------------------------------------------<br> 
	\version 2007-9-19 初始化版本
*/

#ifndef SMCTABLE_H
#define SMCTABLE_H

#include "SMC.h"
#include "SMCFieldInfo.h"
#include "SMCVariant.h"

class SMC_API SMCTable
{
public:
	SMCTable(){}
	virtual ~SMCTable(){}
/*
public:
	//! 通过值更新字段值
//	virtual bool UpdateField(const _tstring& strFieldName,
//		const SMCVariant& varValue,const _tstring& strFilter = _T("")) =0;

	//! 通过表达式更新字段值
	virtual bool UpdateFieldEx(const _tstring& strFieldName,
		const _tstring& strExpress,const _tstring& strFilter = _T("")) =0;

	//! 复制字段值,strSrcField和
	//! strDestField必须都存在且字段类型匹配
	virtual bool CopyField(const _tstring& strSrcField,
		const _tstring& strDestField) =0;

	//! 建普通索引
	virtual bool CreateIndex(const _tstring& strFieldNameList,
		const _tstring& strIndexName) =0;
	//! 删除索引
	virtual bool DropIndex(const _tstring& strIndexName) =0;
	*/
/*
	//! 创建多个字段
	virtual bool CreateFields(const SMCFieldInfos& fieldInfos) =0;
	
	//! 通过FieldInfo创建字段
	virtual bool CreateField(const SMCFieldInfo& fieldInfo) =0;

	//! 创建字段
	virtual bool CreateField(const _tstring& strName,SMCFieldInfo::FieldType nType,int nSize,int nAttributes = 0) =0;

	//! 通过字段名称删除字段
	virtual bool DeleteField(const _tstring& strName) =0;
  
	//! 通过索引号删除字段
	virtual bool DeleteField(int nIndex) =0;

	//! 收集所有字段的信息
	virtual bool GetFieldInfos(SMCFieldInfos& fieldInfos,bool bSystemFieldExcluded = FALSE) =0;

	//! 通过字段名获取字段信息
	virtual bool GetFieldInfo(const _tstring& strName,SMCFieldInfo& fieldInfo) =0;
	
	//! 通过索引获取字段信息
	virtual bool GetFieldInfo(int nIndex,SMCFieldInfo& fieldInfo) =0;

	//! 通过字段名设置字段信息
	virtual bool SetFieldInfo(const _tstring& strName,const SMCFieldInfo& fieldInfo) =0;

	//! 通过索引设置字段信息
	virtual bool SetFieldInfo(int nIndex,const SMCFieldInfo& fieldInfo) =0;
	
	//! 获取字段个数
	virtual int GetFieldCount() =0;

	//! 删除表中所有数据
	virtual bool Truncate() =0;

	//! 统计字段值
//	virtual SMCVariant Statistic(const _tstring& strField,UGStatisticMode??? nMode) =0;

	//! 计算字段单值个数
	virtual int CalculateUniqueValues(const _tstring &strFieldName,SMCArray<SMCVariant>& varKeys) =0;
	*/

public:
	void* m_pTable;
};

#endif