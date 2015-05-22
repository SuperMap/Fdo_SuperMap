/*! \file	 UGUdbEditRecordset.h
 *  \brief	 可编辑查询结果集
 *  \author	 ugc team
 *  \attention 
 *  Copyright(c) 1996-2004 SuperMap GIS Technologies,Inc.<br>
 *  All Rights Reserved
 *  \version $Id: UGUdbEditRecordset.h,v 1.6 2007/12/19 04:54:30 liwl Exp $
 */

#ifndef UGUdbEditRecordset_H
#define UGUdbEditRecordset_H

#include "Base/ugdefs.h"
#include "Base/UGArray.h"
#include "UGUdbRecordset.h"
#include "Base/UGVariant.h"
#include "UGUdbDatasetVector.h"

namespace UGC {

class UDBENGINE_API UGUdbEditRecordset : public UGUdbRecordset  
{
public:
	UGUdbEditRecordset();
		
	UGUdbEditRecordset(UGUdbDatasetVector* pDataset);

	virtual ~UGUdbEditRecordset();

public:
	/// \brief 添加新的记录
	/// \param	[in]	pGeometry	要添加的记录的空间数据指针
	/// \return	如果添加成功，返回新记录的ID, 如果失败，返回-1
	/// \note	
	/// \@li	如果要添加Tabular记录，将pGeometry设为NULL即可
	/// \@li	AddNew操作需要Update方能生效
	/// \attention	如果失败，则不能调用Update和CancelUpdate.
	//virtual long AddNew(CElemGeometry *pGeometry);
	//成功，返回非0值，如果bReturnID=true,返回的是新对象的ID值；失败，返回-1。如果失败，则不能调用Update和CancelUpdate.
	virtual UGint AddNew(UGGeometry *pGeometry,UGbool bReturnID=FALSE);

	/// \brief 删除当前记录集中的所有记录
	/// \return  删除操作成功与否
	/// \remarks  如果当前记录集中记录数很多的话，此操作可能比较慢，如果要删除数据集中的所有记录，建议使用CDatasetVector::Truncate()方法
	/// \sa Delete, COrcPlusDatasetVector::Truncate
	virtual UGbool DeleteAll();		//删除所有的记录

	/// \brief 进行字段拷贝赋值
	/// \param strSrcField	源字段的名称，也可以是表达式，如：Field1*3+2
	/// \param strDestField	目标字段的名称，只能是数据集中已经存在的字段
	/// \return  拷贝操作成功与否
	/// \sa COrcPlusDatasetVector::UpdateField
	virtual UGbool CopyField(const UGString& strSrcField,
		const UGString& strDestField);	

	/// \brief 得到当前SmID值
	/// \return  当前SmID值
	/// \sa Create
	virtual UGint GetID();

	/// \brief 关闭当前记录集
	/// \note 释放占用的资源
	virtual void Close();

	/// \brief 得到当前记录几何对象数据指针
	/// \param geometry	传出几何对象的数据指针
	/// \note geometry指针在函数内分配，但需要在外面delete
	/// \sa	SetGeometry
	virtual UGbool GetGeometry(UGGeometry *&geometry);

	/// \brief 得到当前记录几何对象的范围
	/// \param rc2Bounds	几何对象的二维范围
	/// \param dMinZ		几何对象的最小高程(保留参数，留待后用)
	/// \param dMaxZ		几何对象的最大高程(保留参数，留待后用)
	/// \sa	GetGeometry
	virtual UGbool GetGeometryBounds(UGRect2D &rc2Bounds,
		UGdouble& dMinZ,UGdouble& dMaxZ);

	/// \brief 通过字段名得到当前记录指定字段的值
	/// \param strName		字段名称
	/// \param varValue		字段的值
	/// \sa	SetFieldValue
	virtual UGbool GetFieldValue(const UGString& strName,
		UGVariant& varValue );

	/// \brief 通过字段位置索引得到当前记录指定字段的值
	/// \param nIndex		字段位置索引
	/// \param varValue		字段的值
	/// \sa	SetFieldValue
	virtual UGbool GetFieldValue(UGint nIndex,
		UGVariant& varValue );

	/// \brief 修改当前空间数据
	/// \param geometry		新的空间数据的指针
	/// \sa	GetGeometry
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

	/// \brief 查询当前记录被谁锁定(长事务)
	/// \return 长事务用户名称
	/// \sa	CheckOut, CheckIn, UndoCheckOut
	virtual UGString GetRecordCheckedBy();

	//记录更新
	/// \brief	将当前所做的编辑操作更新到数据库
	/// \remark	需要Update的编辑操作：
	/// @li	AddNew
	/// @li	SetFieldValue
	/// @li	SetGeometry
	/// \attention	Delete和DeleteAll操作不需要Update
	/// \sa	Edit, CancelUpdate, AddNew, SetFieldValue, SetGeometry, Delete, DeleteAll
	virtual UGint Update();
	
	
	/// \brief 刷新当前记录的内容
	/// \attention	只有查询类型为dynaset时才可以调用此方法
	/// \sa Refresh
	virtual void FlushCurrentRecord();

	UGint GetFieldBufferPos(const UGString& strFieldName, 
		UGint &nFieldIndex);


	/// \brief 添加新的记录
	/// \param	[in]	pGeometry	要添加的记录的空间数据指针
	/// \return	如果添加成功，返回新记录的ID, 如果失败，返回-1
	/// \note	如果要添加Tabular记录，将pGeometry设为NULL即可
	/// \attention	如果失败，则不能调用Update和CancelUpdate.
	virtual UGbool Delete();
	

	//状态
	/// \brief 判断当前记录集是否支持编辑操作
	/// \remarks 以下几种情况不允许编辑：
	/// @li		数据集选项为ReadOnly
	/// @li		关联查询时
	/// \sa Edit, AddNew, Update
	virtual UGbool CanUpdate();


	/// \brief 判断是否可以向当前记录集中追加新的记录
	/// \remarks 以下几种情况不允许追加:
	/// @li		数据集选项为ReadOnly
	/// @li		关联查询时
	/// \sa Edit, AddNew, Update
	virtual UGbool CanAppend();

	
	/// \brief	取消当前所做的编辑操作
	/// \remark	可以取消的编辑操作有：
	/// @li	AddNew
	/// @li	SetFieldValue
	/// @li	SetGeometry
	/// \attention	Delete和DeleteAll操作不能CancelUpdate
	/// \sa	Edit, Update, AddNew, SetFieldValue, SetGeometry, Delete, DeleteAll
	virtual UGbool CancelUpdate();
	
	/// \brief	声明开始编辑操作
	/// \remark	以下操作需要声明Edit后才能执行
	/// @li	AddNew
	/// @li	SetFieldValue
	/// @li	SetGeometry
	/// \attention	Delete和DeleteAll操作不需要Edit
	/// \sa	Update, CancelUpdate, AddNew, SetFieldValue, SetGeometry, Delete, DeleteAll
	virtual UGbool Edit();
	
	
	//! \brief 		普通查询，即根据属性查询条件，查询出结果,或进行默认全部查询
	//! \return 	UGbool
	//! \param 		querydef
	//! \remarks 		
	virtual UGbool CreateWithGeneral(const UGQueryDef& querydef);

	/// \brief 根据指定的空间范围进行Bounds限制的查询
	/// \param [in]	querydef	查询对象，内含查询的各种条件、选项等
	/// \note	只有querydef.m_nOptions == CSmQuerydef::Bounds时才会调用此函数
	/// \sa CSmQuerydef, Create, CreteWithGeneral, CreateWithIDs, CreateWithSpatialQuery
	virtual UGbool CreateWithBounds(const UGRect2D& rc2Bounds, 
		UGint nOptions,UGint nMode);

	/// \brief 根据指定的ID数组进行查询
	/// \param [in]	querydef	查询对象，内含查询的各种条件、选项等
	/// \note	只有querydef.m_nOptions == CSmQuerydef::IDs时才会调用此函数
	/// \sa CSmQuerydef, Create, CreteWithGeneral, CreateWithBounds, CreateWithSpatialQuery
	virtual UGbool CreateWithIDs(UGint *pIDs,UGint nCount,UGint nOptions,UGint nMode,UGbool bRTree = FALSE);

	//! 判断当前记录指针是否指向尾
	virtual UGbool IsEOF();
private:
	UGbool IsFieldModifyed(const UGString &strFieldName);
	
	/// \brief 根据构造好的SQL语句执行第一次数据读取操作
	/// \param [in]	strSQL 构造好的SQL语句
	UGbool FetchData(const UGString & strSQL);
	
	//对Geometry作Update准备
	UGbool PrepareGeometry(UGGeometry *pGeo);

	UGbool FetchIDs();

	//判断两组字段是否相等
	UGbool BindingsEqual(UGArray<UGString> &curFields,UGArray<UGString> &bindFields);
protected:
	UGint		m_nCurrentID;
	UGint		m_nCurrentDataIndex;
	
	//当前编辑的字段
	UGArray<UGString> m_CurrentModifiedFields;
	//当前编辑的值
	UGArray<UGVariant> m_CurrentModifiedfieldValues;

	//上一次编辑的字段
	UGArray<UGString> m_ModifiedFields;
	
	CppSQLite3Statement m_SQLstatement;

	UGRect2D m_rc2Org;
	UGRect2D m_rc2New;
private:
	//主要用来保存编辑后的空间对象.
	//是Addnew后复制的一份，防止Addnew之后外边删除了对象，然后再次调用update
	UGGeometry *m_pGeometry;
};

}

#endif

