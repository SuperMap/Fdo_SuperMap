//////////////////////////////////////////////////////////////////////////
//                    _   _   ____   ____                    
//   Project         | | | | / ___) / ___)                   
//                   | | | || | __ | |                       
//                   | |_| || |_\ || \___                    
//                    \____/ \____| \ ___)     2.0           
//                                                           
//!  \file UGWebRecordSet.h
//!  \brief UGWebRecordSet 的接口定义。
//!  \details 文件详细信息。
//!  \author duxiaomin。
//!  \attention 
//!   Copyright (c) 1996-2007 SuperMap GIS Technologies,Inc.  <br> 
//!   All Rights Reserved.
//!  \version 2.0
//////////////////////////////////////////////////////////////////////////

#ifndef UGWEBRECORDSET_H
#define UGWEBRECORDSET_H

#include "Base/ugexports.h"
#include "Base/UGArray.h"
#include "Base/UGVariant.h"
#include "Engine/UGRecordset.h"

namespace UGC{

class WEBENGINE_API UGWebRecordSet : public UGRecordset  
{
public:
	UGWebRecordSet();

	UGWebRecordSet(UGDatasetVector * pDataset);

	virtual ~UGWebRecordSet();
public:
	//! 删除所有记录
	virtual UGbool DeleteAll();

	//! 按某种统计方法统计某个字段
	virtual UGVariant Statistic(const UGString& strField,
		UGStatisticMode nMode);

	//! 刷新记录集,一般就是重新查询一遍
	virtual UGbool Refresh();

	//! 复制字段值,strSrcField和
	//! strDestField必须都存在且字段类型匹配
	virtual UGbool CopyField(const UGString& strSrcField,
		const UGString& strDestField);	
	
	//! 获取当前记录的ID
	virtual UGint GetID();

	//! 判断当前记录指针是否指向头
	virtual UGbool IsBOF();

	//! 判断当前记录指针是否指向尾
	virtual UGbool IsEOF();
	
	//! 关闭记录集
	virtual void Close();

	//! 直接读出几何对象的指针,对于把所有数据都读到内存中的引擎(如dgn)来说，
	//! 不需要拷贝几何对象，外面也不要去删除它,这样可以加快访问速度
	virtual UGbool GetGeometryDirect(UGGeometry*& pGeometry);

	//! 取得几何对象，返回的几何对象指针在函数内分配内存，
	//! 外面负责删除，否则会有内存泄漏
	virtual UGbool GetGeometry(UGGeometry*& pGeometry);

	//! 通过字段名获取字段值
	virtual UGbool GetFieldValue(const UGString& strName,
		UGVariant& varVal);

	//! 通过索引序号获取字段值
	virtual UGbool GetFieldValue(UGint nIndex,
		UGVariant& varVal);

	//! 设置当前记录的几何对象
	virtual UGbool SetGeometry(UGGeometry &geometry);
	
	//! 通过字段名设置当前记录的字段值,值为变体类型
	virtual UGbool SetFieldValue(const UGString& strName,
		const UGVariant& varVal);
	
	//! 通过字段名设置当前记录的字段值,值为字符串类型
	virtual UGbool SetFieldValue(const UGString& strName,
		const UGString& strVal);
	
	//! 通过索引序号设置当前记录的字段值,值为变体类型
	virtual UGbool SetFieldValue(UGint nIndex,
		const UGVariant& varVal);

	//! 通过索引序号设置当前记录的字段值,值为字符串类型
	virtual UGbool SetFieldValue(UGint nIndex,
		const UGString& strVal);	

	//! 通过字段名设置字段值为空
	virtual UGbool SetFieldValueNull(const UGString& strName);	

	//! 通过索引设置字段值为空
	virtual UGbool SetFieldValueNull(UGint nIndex);

	//! 在记录集中再次查询,查找符合条件的第一条记录
	virtual UGbool FindFirst(const UGString& strFilter);
	
	//! 在记录集中再次查询,查找符合条件的最后一条记录
	virtual UGbool FindLast(const UGString& strFilter);

	//! 在记录集中再次查询,查找符合条件的下一条记录
	virtual UGbool FindNext(const UGString& strFilter);

	//! 在记录集中再次查询,查找符合条件的上一条记录
	virtual UGbool FindPrev(const UGString& strFilter);

	//! 给定相应的数,向前或向后移动记录指针
	virtual UGbool Move(UGint nRows);

	//! 移动记录指针到最前
	virtual UGbool MoveFirst();

	//! 移动记录指针到最后
	virtual UGbool MoveLast();

	//! 向下移动一位记录指针
	virtual UGbool MoveNext();

	//! 向上移动一位记录指针
	virtual UGbool MovePrev();

	//! 移动记录指针到指定位置
	virtual UGbool MoveTo(UGint nRow);

	//! 通过ID定位记录指针
	virtual UGbool SeekID(UGint nID);

	//! 获取记录个数
	virtual UGint GetRecordCount();

	//! 收集所有字段的信息
	virtual UGbool GetFieldInfos(UGFieldInfos& fieldInfos);
	
	
	//! 通过字段名获取字段信息
	virtual UGbool GetFieldInfo(const UGString& strName,
		UGFieldInfo& fieldInfo) ;
	
	//! 通过索引取字段信息
	virtual UGbool GetFieldInfo(UGint nIndex,
		UGFieldInfo& fieldInfo);
	
	//! 获取字段个数
	virtual UGint GetFieldCount();
	
	//! 更新，提交修改
	virtual UGint Update();

	//! 取消修改
	virtual UGbool CancelUpdate();
	
	//! 开始修改数据
	virtual UGbool Edit();
	
	//! 添加新记录
	virtual UGint AddNew(UGGeometry *pGeometry,
		UGbool bReturnID=FALSE);

	//! 删除当前记录
	virtual UGbool Delete();

	//! 刷新记录
	virtual void FlushCurrentRecord();
	
	//! 是否支持事务
	virtual UGbool CanTransact() const;

	//! 是否可更新
	virtual UGbool CanUpdate();

	//! 是否可添加
	virtual UGbool CanAppend();

	//! 是否支持指定的操作
	virtual UGbool IsSupport(UGEngAction nAction);

	//! 计算记录集的范围
	virtual UGbool ComputeBounds(UGRect2D &rc2Bounds,
		UGdouble &dMinZ,UGdouble &dMaxZ);	

	//! 非长事务状态下的锁定
	virtual UGbool Lock();

	//! 非长事务状态下的解锁
	virtual UGbool UnLock();	

	//! 得到当前记录被谁给锁定了
	virtual UGString GetRecordCheckedBy();

	virtual UGbool UndoCheckOutCurrent(UGbool bKeepCheckedOut);

	virtual UGbool CheckInCurrent(UGbool bKeepCheckedOut);	
	
	virtual UGbool CheckOutCurrent();

	virtual UGbool UndoCheckOut(UGbool bKeepCheckedOut);

	virtual UGbool CheckIn(UGbool bKeepCheckedOut);

	virtual UGbool CheckOut();

	UGString GetFilter() const;
	
	void CheckError() const;

	UGbool Create(const UGQueryDef& queryDef);

	UGbool RefreshPos();

	UGbool IsOpen() const;

	void CheckFields(UGArray<UGString>& fields);

	/// \brief 对当前查询字段进行一些初始化处理，主要是把SMID放到最前面
	UGbool InitFields();

	virtual UGString BuildBoundsSQL(const UGRect2D& rc2Bounds);
	
	/// \brief 构造General查询的SQL语句
	virtual UGString BuildGeneralSQL();
	
	virtual UGString BuildIDsSQL(UGint *pIDs,UGint nCount,UGbool bRTree = FALSE);

	virtual UGbool CreateWithGeneral(const UGQueryDef& querydef);

	/// \brief 根据指定的空间范围进行Bounds限制的查询
	/// \param [in]	rc2Bounds	查询数据集的 Bounds
	/// \note	只有querydef.m_nOptions == CSmQuerydef::Bounds时才会调用此函数
	/// \sa CSmQuerydef, Create, CreteWithGeneral, CreateWithIDs
	virtual UGbool CreateWithBounds(const UGRect2D& rc2Bounds, 
		UGint nOptions,UGint nMode);

	/// \brief 根据指定的ID数组进行查询（ID的顺序不是取出来的记录的顺序）
	/// \param [in]	pIDs	一组SmID的IDs查询
	/// \note	只有querydef.m_nOptions == CSmQuerydef::IDs时才会调用此函数
	/// \sa CSmQuerydef, Create, CreteWithGeneral, CreateWithBounds
	virtual UGbool CreateWithIDs(UGint *pIDs,UGint nCount,UGint nOptions,UGint nMode,UGbool bRTree = FALSE);
private:
	UGDatasetVector* m_pDataset;
};

}
#endif // !defined(UGWEBRECORDSET_H)
