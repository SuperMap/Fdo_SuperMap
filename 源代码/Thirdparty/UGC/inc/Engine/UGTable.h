/*! \file	 UGTable.h
 *  \brief	 数据集基类
 *  \author	 ugc team
 *  \attention 
 *  Copyright(c) 1996-2004 SuperMap GIS Technologies,Inc.<br>
 *  All Rights Reserved
 *  \version $Id: UGTable.h,v 1.5 2007/11/30 02:28:15 chenyong Exp $
 */

#if !defined(AFX_UGTABLE_H__93882047_ECE5_4A73_9B3F_FD8D539F8C69__INCLUDED_)
#define AFX_UGTABLE_H__93882047_ECE5_4A73_9B3F_FD8D539F8C69__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Base/ugdefs.h"
#include "UGDataset.h"
#include "Base/UGVariant.h"
#include "UGRecordset.h"

namespace UGC{

class ENGINE_API UGTable  
{
public:
	UGTable();
	virtual ~UGTable();

public:
	//! 通过值更新字段值
	virtual UGbool UpdateField(const UGString& strFieldName,
		const UGVariant& varValue,const UGString& strFilter = "") =0;

	//! 通过表达式更新字段值
	virtual UGbool UpdateFieldEx(const UGString& strFieldName,
		const UGString& strExpress,const UGString& strFilter = "") =0;

	//! 复制字段值,strSrcField和
	//! strDestField必须都存在且字段类型匹配
	virtual UGbool CopyField(const UGString& strSrcField,
		const UGString& strDestField) =0;

	//! 建普通索引
	virtual UGbool CreateIndex(const UGString& strFieldNameList,
		const UGString& strIndexName) =0;
	//! 删除索引
	virtual UGbool DropIndex(const UGString& strIndexName) =0;

	//! 创建多个字段
	virtual UGbool CreateFields(const UGFieldInfos& fieldInfos) =0;
	
	//! 通过FieldInfo创建字段
	virtual UGbool CreateField(const UGFieldInfo& fieldInfo) =0;

	//! 创建字段
	virtual UGbool CreateField(const UGString& strName,UGFieldInfo::FieldType nType,UGint nSize,UGint nAttributes = 0) =0;

	//! 通过字段名称删除字段
	virtual UGbool DeleteField(const UGString& strName) =0;

	//! 通过索引号删除字段
	virtual UGbool DeleteField(UGint nIndex) =0;

	//! 收集所有字段的信息
	virtual UGbool GetFieldInfos(UGFieldInfos& fieldInfos,UGbool bSystemFieldExcluded = FALSE) =0;

	//! 通过字段名获取字段信息
	virtual UGbool GetFieldInfo(const UGString& strName,UGFieldInfo& fieldInfo) =0;
	
	//! 通过索引获取字段信息
	virtual UGbool GetFieldInfo(UGint nIndex,UGFieldInfo& fieldInfo) =0;

	//! 通过字段名设置字段信息
	virtual UGbool SetFieldInfo(const UGString& strName,const UGFieldInfo& fieldInfo) =0;

	//! 通过索引设置字段信息
	virtual UGbool SetFieldInfo(UGint nIndex,const UGFieldInfo& fieldInfo) =0;
	
	//! 获取字段个数
	virtual UGint GetFieldCount() =0;

	//! 删除表中所有数据
	virtual UGbool Truncate() =0;

	//! 统计字段值
	virtual UGVariant Statistic(const UGString& strField,UGStatisticMode nMode) =0;

	//! 计算字段单值个数
	virtual UGint CalculateUniqueValues(const UGString &strFieldName,UGArray<UGVariant>& varKeys) =0;

public:
	//保持一致和组件 
	UGFieldInfos m_FieldInfos;
};

}

#endif // !defined(AFX_UGTABLE_H__93882047_ECE5_4A73_9B3F_FD8D539F8C69__INCLUDED_)
