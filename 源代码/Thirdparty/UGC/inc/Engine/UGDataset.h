/*! \file	 UGDataset.h
 *  \brief	 数据集基类
 *  \author	 ugc team
 *  \attention 
 *  Copyright(c) 1996-2004 SuperMap GIS Technologies,Inc.<br>
 *  All Rights Reserved
 *  \version $Id: UGDataset.h,v 1.35 2008/04/01 02:13:22 zhouqin Exp $
 */

#ifndef UGDATASET_H
#define UGDATASET_H

#include "Base/ugdefs.h"
#include "Base/UGTime.h"
#include "Base/UGString.h"
#include "Algorithm/UGRect2D.h"
#include "Geometry/UGDataCodec.h"
#include "ugeng.h"
#include "UGEngDefs.h"

namespace UGC {

class UGDataSource;

//! 数据集基类
class ENGINE_API UGDataset  
{
public:
	//! 数据集类型,数据源的IsSupport方法加以详细支持说明
	enum DatasetType
	{
		Tabular		=0,		//! 只有属性表，没有几何对象
		Point		=1,		//! 点数据集
		Line		=3,		//! 线数据集
		Network		=4,		//! 网络数据集
		Region		=5,		//! 多边形数据集
		Text		=7,		//! 文本数据集
		LineM		=35,	//! 路线数据集
		Image		=81,	//! 影像
		MrSID		=82,	//! MrSID
		Grid		=83,	//! 栅格
		DEM			=84,	//! DEM
		ECW			=85,	//! ECW
		WMS			=86,	//! WMS	
		WCS			=87,	//! WCS
	
		PointZ		=101,	//! 三维点
		LineZ		=103,	//! 三维线
		RegionZ		=105,	//! 三维面
		PointGL		=137,	//! 带法向量的Point3D
		TIN			=139,	//! TIN数据集
		CAD			=149,	//! CAD数据集
		
		WFS			=151,	//! WFS
		LinkTable	=153,	//! 数据库表,只读功能
		Topo		=154,	//! Topo数据集
		TIN2		=155	//! 新的Tin数据和以前的区分开
	}; 

	enum DatasetOption
	{
		Default		= 0x00000000,	/**< 默认选项 */
		HasStyle	= 0x00000001,	/**< 风格支持 */
		//{{2007.7.15 ri以后禁止应用
		Zip			= 0x00000002,	/**< Zip压缩存储 */
		//}}
		Pyramid     = 0x00000004,	/**< 支持影像金字塔存储 */
		Sequence	= 0x00000008,	/**< 支持时序存储 */
		MemCache	= 0x00000010,	/**< 支持内存缓存模式 */
		LongTrans	= 0x00000020,	/**< 支持长事务操作 */
		UserLock	= 0x00000040,	/**< 支持用户锁定 */
		CacheMode	= 0x00000080,	/**< 支持本地缓存模式 */
		//{{2007.7.15 ri以后禁止应用
		Library		= 0x00010000,	/**< 支持单表图库模式 */
		//}}
		ReadOnly	= 0x00020000,	/**< 只读 */
		DataVersion = 0x00040000,	/**< 版本管理 */
		TopoAdscription = 0x00080000, /**< topo 归属 */
//		CacheIndex		= 0x00100000 /**< 静态索引缓存 */
		//CHARSET		((nOptions & 0x0000ff00 ) >> 8)
	};


public:
	//! 构造函数
	UGDataset();
	
	//! 析构函数
	virtual ~UGDataset();

public:
	//! 打开数据集
	virtual UGbool Open() = 0;

	//! 关闭数据集
	virtual void Close() = 0;
	
	//! 返回数据集类型
	virtual UGDataset::DatasetType GetType() const = 0;

	//! 返回最后更新时间
	virtual UGTime GetDateLastUpdated() = 0;

	//! 返回创建时间
	virtual UGTime GetDateCreated() = 0;
	
	//! 返回数据集名(可以和表名不同)
	virtual UGString GetName() =0;
	
	//! 返回数据集对应表名
	virtual UGString GetTableName() =0;
	
	//! 数据集重命名,只改变数据集名,表名不变
	virtual UGbool Rename(const UGString& strNewName) = 0;

	//! 返回最小高程
	virtual UGdouble GetMinZ() =0;

	//! 设置最小高程
	virtual void SetMinZ(UGdouble d) =0;

	//! 返回最大高程
	virtual UGdouble GetMaxZ() =0;

	//! 设置最大高程
	virtual void SetMaxZ(UGdouble d) =0;

	//! 返回数据集的维数
	virtual UGint GetDimension() =0;

	//! 判断是否是矢量数据集
	virtual UGbool IsVector() =0;

	//! 判断是否是Topo数据集
	virtual UGbool IsTopoDataset() =0;

	//! 判断是否是栅格数据集
	virtual UGbool IsRaster() =0;

	virtual UGbool IsLinkTable() = 0;

	//! 返回数据集的范围
	virtual const UGRect2D& GetBounds() const =0;

	//! 设置数据集的范围
	virtual void SetBounds(const UGRect2D& r) = 0;

	//! 返回空间数据编码方式
	virtual UGDataCodec::CodecType GetCodecType() =0;
	
	//! 设置空间数据编码方式
	virtual void SetCodecType(UGDataCodec::CodecType c) =0;

	//! 返回数据集的选项信息(用四字节的整型数据代表一些属性)
	virtual UGint GetOptions() =0;

	//! 保存数据集信息
	virtual UGbool SaveInfo() = 0;
	
	//! 刷新数据集信息
	virtual UGbool RefreshInfo() = 0;	
	
public:
	//! 返回数据集的ID
	UGint GetID() const {return m_nID;}

	//! 设置数据集的ID
	void SetID(UGint nID) { m_nID = nID; }

	UGString GetSchema() const;

	//! 返回数据源指针
	UGDataSource* GetDataSource() const {return m_pDataSource;}

	//! 设置数据源指针
	void SetDataSource(UGDataSource* pDs) {m_pDataSource = pDs;}

	UGbool IsModified() const {return m_bModified;}
	
	void SetModifiedFlag(UGbool bModified = TRUE) {m_bModified = bModified;}

	//! 判断数据集是否已经打开
	virtual UGbool IsOpen() const {return m_bOpened;}

	//! 计算数据集范围,一般在数据集中元素被删除或修改后使用,
	//! 可能耗费较多时间
	virtual UGbool ComputeBounds() {return FALSE;};

	//! 直接从内存中返回对象个数,速度比较快,
	//! 但不能保证正确,通过DatsetInfo获取
	virtual UGint GetObjectCountDirectly() {return -1;};

	//! 返回数据集中对象个数,速度慢,但值比较正确,
	//! 通过Register表获取
	virtual UGint GetObjectCount() {return -1;}

	//! 获取数据集占用的硬盘空间
	virtual UGint GetStoredSpace() {return -1;}

	//! 获取数据集描述信息
	virtual UGString GetDescription() const {return "";};

	//! 设置数据集描述信息
	virtual void SetDescription(const UGString& /*strDesc*/) {};
	
	//! 判断当前数据集是否可编辑
	virtual UGbool CanUpdate() {return FALSE;}
	
	//! 注册选项信息
	virtual UGbool RegisterOption(UGint /*nOption*/) {return FALSE;}

	//! 反注册选项信息
	virtual UGbool UnRegisterOption(UGint /*nOption*/) {return FALSE;}
	
	//! 判断数据集是否有某个选项信息
	virtual UGbool HasFlag(UGint /*nOption*/) {return FALSE;}
	
	//! 数据集是否有某种模式的操作的能力
	virtual UGbool HasAbility(UGEngAbility /*dwEngAbility*/) {return FALSE;}
	
	//! 判断数据集是否支持某种操作
	virtual UGbool IsSupport(UGEngAction /*nAction*/) {return FALSE;}

#if PACKAGE_TYPE==PACKAGE_UGC
	//! 锁定数据集,不允许其他用户编辑
	virtual UGbool Lock() {return FALSE;}

	//! 对数据集解锁
	virtual UGbool Unlock() {return FALSE;}

#endif // end declare ugc sdk
protected:

	//! 设置数据集的选项信息
	virtual void SetOptions(UGint nOptions) =0;

public:
	//! 数据集的ID
	UGint m_nID;
protected:	
	//! 是否打开
	UGbool m_bOpened;
	//! 是否已经修改
	UGbool m_bModified;	
	//! 数据源指针
	UGDataSource* m_pDataSource;
};

typedef UGArray<UGDataset*> UGDatasets;
 
}

#endif 
