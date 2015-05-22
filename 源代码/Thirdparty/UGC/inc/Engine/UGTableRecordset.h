// UGTableRecordset.h: interface for the UGTableRecordset class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGTABLERECORDSET_H__7C95DC17_F28F_441D_A6C8_4AEB7AC45601__INCLUDED_)
#define AFX_UGTABLERECORDSET_H__7C95DC17_F28F_441D_A6C8_4AEB7AC45601__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Base/ugdefs.h"
#include "Base/UGString.h"
#include "Base/UGVariant.h"
#include "UGFieldInfo.h"

namespace UGC{

class ENGINE_API UGTableRecordset  
{
public:
	UGTableRecordset();
	virtual ~UGTableRecordset();

public:
	//! 是否记录集为空(没有记录)
	virtual UGbool IsEmpty() = 0; 

	//! 判断当前记录指针是否指向头
	virtual UGbool IsBOF() =0;

	//! 判断当前记录指针是否指向尾
	virtual UGbool IsEOF() =0;
	
	//! 关闭记录集
	virtual void Close() =0;

	//! 通过字段名获取字段值
	virtual UGbool GetFieldValue(const UGString& strName,UGVariant& varVal) =0;

	//! 通过索引序号获取字段值
	virtual UGbool GetFieldValue(UGint nIndex,UGVariant& varVal) =0;

	//! 通过字段名设置当前记录的字段值,值为变体类型
	virtual UGbool SetFieldValue(const UGString& strName,const UGVariant& varVal) =0;
	
	//! 通过字段名设置当前记录的字段值,值为字符串类型
	virtual UGbool SetFieldValue(const UGString& strName,const UGString& strVal) =0;
	
	//! 通过索引序号设置当前记录的字段值,值为变体类型
	virtual UGbool SetFieldValue(UGint nIndex,const UGVariant& varVal) =0;

	//! 通过索引序号设置当前记录的字段值,值为字符串类型
	virtual UGbool SetFieldValue(UGint nIndex,	const UGString& strVal) =0;

	//! 通过字段名设置字段值为空
	virtual UGbool SetFieldValueNull(const UGString& strName) =0;

	//! 通过索引设置字段值为空
	virtual UGbool SetFieldValueNull(UGint nIndex) =0;

	//! 在记录集中再次查询,查找符合条件的第一条记录
	virtual UGbool FindFirst(const UGString& strFilter) =0;
	
	//! 在记录集中再次查询,查找符合条件的最后一条记录
	virtual UGbool FindLast(const UGString& strFilter) =0;

	//! 在记录集中再次查询,查找符合条件的下一条记录
	virtual UGbool FindNext(const UGString& strFilter) =0;

	//! 在记录集中再次查询,查找符合条件的上一条记录
	virtual UGbool FindPrev(const UGString& strFilter) =0;

	//! 给定相应的数,向前或向后移动记录指针
	virtual UGbool Move(UGint nRows) =0;

	//! 移动记录指针到最前
	virtual UGbool MoveFirst() =0;

	//! 移动记录指针到最后
	virtual UGbool MoveLast() =0;

	//! 向下移动一位记录指针
	virtual UGbool MoveNext() =0;

	//! 向上移动一位记录指针
	virtual UGbool MovePrev() =0;

	//! 移动记录指针到指定位置
	virtual UGbool MoveTo(UGint nRow) =0;

	//! 获取记录个数
	virtual UGint GetRecordCount() =0;

	//! 收集所有字段的信息
	virtual UGbool GetFieldInfos(UGFieldInfos& fieldInfos) =0;
	
	//! 通过字段名获取字段信息
	virtual UGbool GetFieldInfo(const UGString& strName,UGFieldInfo& fieldInfo)  =0;
	
	//! 通过索引取字段信息
	virtual UGbool GetFieldInfo(UGint nIndex,UGFieldInfo& fieldInfo)  =0;
	
	//! 获取字段个数
	virtual UGint GetFieldCount()  =0;

public:

	//! 特殊的外键查询
	virtual UGbool GetForeignKeysVal(UGArray<UGString> &aryForeignKeys,UGArray<UGVariant> &aryVal);
	virtual UGbool FetchForeignKeysVal(UGArray<UGVariant> &aryVal);
};

}

#endif // !defined(AFX_UGTABLERECORDSET_H__7C95DC17_F28F_441D_A6C8_4AEB7AC45601__INCLUDED_)

