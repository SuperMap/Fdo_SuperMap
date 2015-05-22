/*! \file	 UGRecordset.h
 *  \brief	 记录集类定义文件
 *  \author	 ugc team
 *  \attention 
 *  Copyright(c) 1996-2004 SuperMap GIS Technologies,Inc.<br>
 *  All Rights Reserved
 *  \version $Id: UGRecordset.h,v 1.11 2007/11/07 03:15:50 liwl Exp $
 */

#ifndef UGRECORDSET_H
#define UGRECORDSET_H

#include "Algorithm/UGRect2D.h"
#include "UGQueryDef.h"
#include "ugeng.h"
#include "Base/UGVariant.h"
#include "Base/UGString.h"
#include "Geometry/UGGeometry.h"
#include "UGFieldInfo.h"
#include "Base/UGArray.h"
#include "Algorithm/UGRectUInt.h"
#include "Geometry/UGGeoCompound.h"
#include "UGTableRecordset.h"

namespace UGC {

class UGDatasetVector;

//! 记录集类
class ENGINE_API UGRecordset :public UGTableRecordset
{
public:
	//! 编辑模式
	enum EditMode {
		EditNone			= 0x00000000, //! 未做任何编辑
		EditAdd				= 0x00000001, //! 已执行过AddNew操作
		EditInProgress		= 0x00000002, //! 正在编辑
		EditSetFieldValue	= 0x00000004, //! 已更改属性数据 
		EditSetGeometry		= 0x00000008, //! 已执行过SetGeometry操作
		EditDeleted			= 0x00000010  //! 已删除记录
	};
	
public:
	//! 构造函数
	UGRecordset();
	//! 析构函数
	virtual ~UGRecordset();
public:
	//! 获取记录集对应的数据集
	UGDatasetVector* GetDataset() const {
		return m_pDataset;
	}
	
	//! 判断是否有属性数据
	UGbool HasDBInfo() {
		return (m_QueryDef.m_nOptions & UGQueryDef::Attribute);
	}

	//! 判断是否有几何数据
	UGbool HasGeometry() {
		return (m_QueryDef.m_nOptions & UGQueryDef::Geometry);
	}
	
	//! 删除所有记录
	virtual UGbool DeleteAll() =0;

	//! 按某种统计方法统计某个字段
	virtual UGVariant Statistic(const UGString& strField,
		UGStatisticMode nMode) =0;

	//! 刷新记录集,一般就是重新查询一遍
	virtual UGbool Refresh() =0;

	//! 复制字段值,strSrcField和
	//! strDestField必须都存在且字段类型匹配
	virtual UGbool CopyField(const UGString& strSrcField,
		const UGString& strDestField) =0;
	
	//! 获取当前记录的ID
	virtual UGint GetID() = 0;

	//! 直接读出几何对象的指针,对于把所有数据都读到内存中的引擎(如dgn)来说，
	//! 不需要拷贝几何对象，外面也不要去删除它,这样可以加快访问速度
	virtual UGbool GetGeometryDirect(UGGeometry*& pGeometry) =0;

	//! 取得几何对象，返回的几何对象指针在函数内分配内存，
	//! 外面负责删除，否则会有内存泄漏
	virtual UGbool GetGeometry(UGGeometry*& pGeometry) =0;

	//! 取得几何对象的三维Bounds
	UGbool GetGeometryBounds(UGRect2D &rc2Bounds,
		double& dMinZ,double& dMaxZ) {
		UGGeometry* pGeometry = NULL;
		GetGeometry(pGeometry);
		if(pGeometry) {
			rc2Bounds = pGeometry->GetBounds();
			delete pGeometry;
			return TRUE;
		}
		return FALSE;
	}

	//! 设置当前记录的几何对象
	virtual UGbool SetGeometry(UGGeometry &geometry) =0;

	UGbool IsEmpty();

	//! 通过ID定位记录指针
	virtual UGbool SeekID(UGint nID) =0;

	//! 更新，提交修改
	virtual UGint Update() =0;

	//! 取消修改
	virtual UGbool CancelUpdate() =0;
	
	//! 开始修改数据
	virtual UGbool Edit() =0;

	//! 获取当前编辑模式
	EditMode GetEditMode() const {
		return m_nEditMode;
	}
	
	//! \brief 增加新记录,成功，返回TRUE值，失败返回FALSE值；
	//! \param *pGeometry [in] 添加的Geometry指针
	//! \param bReturnID=FALSE [in] 此参数已经不起作用。
	//! \return True 和 False 的值
	//! \remarks 如果想得到新对象的ID，那么马上调用GetId方法
	virtual UGint AddNew(UGGeometry *pGeometry,
		UGbool bReturnID=FALSE) =0;

	//! 删除当前记录
	virtual UGbool Delete() =0;

	//! 刷新记录
	virtual void FlushCurrentRecord() =0;
	
	//! 是否支持事务
	virtual UGbool CanTransact() const =0;

	//! 是否可更新
	virtual UGbool CanUpdate() =0;	

	//! 是否可添加
	virtual UGbool CanAppend() =0;

	//! 是否支持指定的操作
	virtual UGbool IsSupport(UGEngAction nAction) =0;

	//! 计算记录集的范围
	virtual UGbool ComputeBounds(UGRect2D &rc2Bounds,
		UGdouble &dMinZ,UGdouble &dMaxZ) =0;

	//! 对Bounds取整
	virtual UGbool GetUIntRectBounds(UGRectUInt& rcUIntRect);

	//! 设置查询定义
	void SetQueryDef(const UGQueryDef& querydef) {
		m_QueryDef = querydef;
	}

	//! 获取查询定义
	void GetQueryDef(UGQueryDef & querydef) const
	{
		querydef = m_QueryDef;
	}

	UGQueryDef::QueryOption GetOptions() const
	{
		return m_QueryDef.m_nOptions;
	}

	//检查要加进来的数据类型是否合法
	UGbool IsGeometryTypeValid(UGGeometry::Type& geoType);

	//! \brief 生成XML格式的信息
	UGString ToXML(UGGeometry::GMLVersionType versionType, UGint nPace = 0);
	
	//! \brief 从XML字符串中生成Geometry
	UGbool FromXML(const UGString& strXML,UGGeometry::GMLVersionType versionType);

#if PACKAGE_TYPE==PACKAGE_UGC
	
	//! 非长事务状态下的锁定
	virtual UGbool Lock() =0;

	//! 非长事务状态下的解锁
	virtual UGbool UnLock() =0;
	
	//! 得到当前记录被谁给锁定了
	virtual UGString GetRecordCheckedBy() = 0;

	virtual UGbool UndoCheckOutCurrent(UGbool bKeepCheckedOut) =0;	
	virtual UGbool CheckInCurrent(UGbool bKeepCheckedOut) =0;
	virtual UGbool CheckOutCurrent() =0;
	virtual UGbool UndoCheckOut(UGbool bKeepCheckedOut) =0;
	virtual UGbool CheckIn(UGbool bKeepCheckedOut) =0;
	virtual UGbool CheckOut() =0;

#endif // end declare ugc sdk
protected:	
	//! 记录集对应的数据集
	UGDatasetVector* m_pDataset;

	//! 当前编辑模式
	/// \brief 当前编辑状态
	/// @li	0 -- EditNone			未做任何编辑
	/// @li	1 -- EditInProgress		正在编辑
	/// @li	2 -- EditAdd			已执行过AddNew操作
	/// @li	3 -- EditOfGeometry		已执行过SetGeometry操作
	EditMode m_nEditMode;
public:
	//! 查询定义
	UGQueryDef m_QueryDef;
};

//! 记录集集合类
class ENGINE_API UGRecordsets : public UGArray<UGRecordset*>
{
public:
	//! 清除所有的记录集(释放Recordset指针)
	void ReleaseAll();
};

}

#endif


