// UGODBCDatasetVector.h: interface for the UGODBCDatasetVector class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGODBCDATASETVECTOR_H__C7B96DD7_2CBA_4F39_AD4_9C23CB53FD__INCLUDED_)
#define AFX_UGODBCDATASETVECTOR_H__C7B96DD7_2CBA_4F39_AD4_9C23CB53FD__INCLUDED_

#include "Engine/UGDatasetVector.h"
#include "Engine/UGDBRTree.h"
#include "Base/UGFileStream.h"
#include "Base/UGThread.h"
#include "Base/UGProgress.h"

namespace UGC
{

class UGODBCConnection;

class UGEXPORT UGODBCDatasetVector  : public UGDatasetVector
{
	friend class UGODBCEditRecordset;
	friend class UGODBCRecordset;
	friend class UGODBCSpatialIndex;

public:
	UGODBCDatasetVector();
	virtual ~UGODBCDatasetVector();

public:
	//! \brief  关闭数据集
	virtual void Close();

	//! \brief  保存数据集信息
	virtual UGbool SaveInfo();
	
	//! \brief  刷新数据集信息
	virtual UGbool RefreshInfo();

	//! \brief  返回最后更新时间
	virtual UGTime GetDateLastUpdated();

	//! \brief  返回创建时间
	virtual UGTime GetDateCreated();

	//! \brief  长事务处理函数
	virtual UGbool CheckOut();
	virtual UGbool CheckIn(UGbool bKeepCheckedOut);
	virtual UGbool UndoCheckOut(UGbool bKeepCheckedOut);

	//! \brief  通过值更新字段值
	virtual UGbool UpdateField(const UGString& strFieldName,
		const UGVariant& varValue,const UGString& strFilter = "");

	//! \brief  通过表达式更新字段值
	virtual UGbool UpdateFieldEx(const UGString& strFieldName,
		const UGString& strExpress,const UGString& strFilter = "");

	//! \brief 复制字段值,strSrcField和
	//! \brief  strDestField必须都存在且字段类型匹配
	virtual UGbool CopyField(const UGString& strSrcField,
		const UGString& strDestField);

	//! \brief  建普通索引
	virtual UGbool CreateIndex(const UGString& strFieldNameList,
		const UGString& strIndexName);

	//! \brief  删除索引
	virtual UGbool DropIndex(const UGString& strIndexName);

	//! \brief  R树操作函数
	UGbool ExtractLeafData(const UGRectUInt& SearchBounds, 
		UGArray<UGint>& aryItemIDs, 
		UGArray<UGint>& aryCertainLeafIDs,
		UGArray<UGRectUInt> &aryCertainBounds,
		UGArray<UGint>& aryMaybeLeafIDs,
		UGArray<UGRectUInt> &aryMaybeBounds,
		UGbool bFuzzy,
		UGdouble dGranule);
	virtual UGint LoadRTreeLeaf(UGint nID,UGStream &stream);
	virtual UGbool StoreRTreeLeaf(UGint nID,UGStream &stream);

	//! \brief  是否有几何数据，除了Tablur数据集，都有几何数据
	virtual UGbool HasGeometry() const;

	//! \brief  收集所有字段的信息
	virtual UGbool GetFieldInfos(UGFieldInfos& fieldInfos,
		UGbool bSystemFieldExcluded = FALSE);

	//! \brief  通过字段名获取字段信息
	virtual UGbool GetFieldInfo(const UGString& strName,
		UGFieldInfo& fieldInfo);
	
	//! \brief  通过索引获取字段信息
	virtual UGbool GetFieldInfo(UGint nIndex,
		UGFieldInfo& fieldInfo);
	
	//! \brief 通过字段名设置字段信息
	virtual UGbool SetFieldInfo(const UGString& strName,
		const UGFieldInfo& fieldInfo);

	//! \brief  通过索引设置字段信息
	virtual UGbool SetFieldInfo(UGint nIndex,
		const UGFieldInfo& fieldInfo);

	//! \brief  获取字段个数
	virtual UGint GetFieldCount();

	//! \brief  删除表中所有数据
	virtual UGbool Truncate();

	//! \brief  统计字段值
	virtual UGVariant Statistic(const UGString& strField,
		UGStatisticMode nMode);
	
	//! \brief  计算字段单值个数
	virtual UGint CalculateUniqueValues(const UGString &strFieldName,
		UGArray<UGVariant>& varKeys);

	//! \brief  真正的SQL查询记录个数,更新Register表
	virtual UGbool ComputeRecCount();

	//! \brief  获取最大空间对象的字节大小
	virtual UGint GetMaxGeoSize();

	//! \brief  设置最大空间对象的字节大小
	virtual UGbool SetMaxGeoSize(UGint nMaxGeoSize);

	//! \brief  时序数据的注册时间
	virtual UGTime GetRegistSequenceTime();

	//! \brief  时序数据的最新更新时间
	virtual UGTime GetLUSequenceTime();

	//! \brief  通过ID数组删除数据集中的记录
	virtual UGbool DeleteRecords(const UGint* pIDs,UGint nCount);

	//! \brief  重采样，仅对线数据集有效
	virtual UGbool Resample(UGdouble dTolerance,
		UGbool bShowProgress=TRUE);	

	//! \brief  返回记录集个数
	virtual UGint GetRecordsetCount();

	//! \brief  返回指定索引的数据集指针
	virtual UGRecordset* GetRecordsetAt(UGint nIndex);

	//! \brief  通过索引释放记录集
	virtual UGbool ReleaseRecordset(UGint nIndex);

	//! \brief  通过引用释放记录集
	virtual UGbool ReleaseRecordset(UGRecordset *pRecordset);

	//! \brief  设置选项信息
	virtual void SetFlag(UGint nOption,UGbool bHas);

	//! \brief  判断字段名是否有效
	virtual UGbool IsAvailableFieldName(const UGString& strFieldName);

	//! \brief  得到图库索引图的名字	
	virtual UGString GetMiniatureDtName();

	//! \brief  通过类别获取字段名
	virtual UGString GetFieldNameBySign(FieldSign nSign);
	
	//! \brief  设置字段的类别
	virtual UGbool SetFieldSign(const UGString& strFieldName,FieldSign nSign);

	//! \brief  判断当前数据集是否可编辑
	virtual UGbool CanUpdate();

	//! \brief  注册选项信息
	virtual UGbool RegisterOption(UGint nOption);

	//! \brief  反注册选项信息
	virtual UGbool UnRegisterOption(UGint nOption);

	//! \brief  返回数据集中对象个数,速度慢,但值比较正确,
	//! \brief  通过Register表获取
	virtual UGint GetObjectCount();

	//! \brief  设置范围
	virtual void SetBounds(const UGRect2D& r);
	//! \brief 计算数据集Bound,一般在数据集中元素被删除或修改后使用，将耗费大量时间
	virtual UGbool ComputeBounds();

	//! \brief 数据集重命名,只改变数据集名,表名不变
	virtual UGbool Rename(const UGString& strNewName);
	
protected:
	//! \brief  建立空间索引
	virtual UGbool BuildSpatialIndex(UGSpatialIndexInfo &spatial);

	//! \brief 根据当前索引状态重建索引
	//! \param *pDataset [in]。
	//! \return
	//! \remarks
	//! \attention 
	virtual UGbool ReBuildSpatialIndex();

	//! \brief 脏数据的空间索引更新
	//! \param *pDataset [in]。
	//! \return 。
	//! \remarks 。
	//! \attention 。
	virtual UGbool UpdateSpatialIndex();

	//! \brief  清除空间索引
	virtual UGbool DropSpatialIndex();

	//! \brief  是否需要重建空间索引
	virtual UGbool IsSpatialIndexDirty();
	
	//! \brief  返回空间索引脏的记录的数目，为是否需要重建空间索引提供参考
	virtual UGint GetDirtyRecordCount();

	//! \brief  对数据的空间索引进行统计分析
	virtual UGbool StatisticIndex(UGDataSource *pDs);
	
public:
	//! \brief  设置查询范围
	void SetQueryBounds(UGRect2D &rcRectBounds);
	
	//! \brief 		多用户操作刷新最大GeometrySize
	//! \return 	void
	//! \remarks 	只刷新内存变量	
	void RefreshMaxGeoSize();

	/// \brief 从数据库中读取当前数据集的Bounds信息
	/// \remarks 此函数与CDatasetVector::GetBounds有所区别，此函数是从数据库中读取，得到的是最新的Bounds，而后者是直接从内存中读取m_DatasetInfo中存储的Bounds信息，速度要快得多
	/// \sa	CDatasetVector::GetBounds
	UGRect2D GetBoundsDirectly();

	//************图库************//
	//! \brief 根据查询范围内的图幅ID构造查询SQL语句
	//! \param	[in]	rc2SearchBounds		查询范围
	//! \param	[in/out]	strLibTile		构造出的查询语句
	//! \sa GetLibTileInfo, GetLibTileIDs
	UGbool GetLibTileSQL(const UGRect2D& rc2SearchBounds,UGString & strLibTile);
	//! \brief 返回查询范围内的LibTileIDs
	//! \param	[in]	rc2Bounds		查询范围
	//! \param	[in/out]	aryLibTileIDs	查询出来的IDs
	//! \sa GetLibTileInfo, GetLibTileSQL
	virtual UGbool GetLibTileIDs(UGRect2D & rc2Bounds,
						UGArray<UGint> &aryLibTileIDs);

	//! \brief 获取连接
	UGODBCConnection * GetConnection() const;
	
	//! \brief　三级索引缓存
	//! \param strFileName 文件名[in]
	UGbool GetCacheFile(UGString &strFileName,UGint nLibTileID = 0);

	//! \brief 的到序列化的字段
	virtual UGint GetNewID();

	//! \brief 创建外挂表的数据源
	//! \param conn　数据源连接信息[in]
	void X_CreateLinkDatasource(UGDsConnection &conn);

	//! \brief	设置字符集，及保存smOption
	void SetCharset(UGTextCodec::Charset c);
	
protected:
	//! \brief 设置字段信息
	//! \param strName　字段名[in]
	//! \param strForeignName　字段别名[in]
	//! \param m_nType　字段类型[in]
	UGbool SetFieldInfo(const UGString & strName,const UGString & strForeignName,
		UGFieldInfo::FieldType nType,const UGString & strFormat,
		const UGString & strDomain,UGbool bUpdatable);

	//! \brief 获取字段信息
	virtual UGbool QueryFieldInfos();

	//! \brief 删除表中的数据
	//! \param strName　表名[in]
	virtual UGbool TruncateTable(UGString & strName);

public:
	//! \brief
	// 根据数据集的对象大小以及缓存限制在20M内计算出一次取对象的个数
	// 很多地方可以用得到，所以就作为公有开放出来了 added by yanmb
	UGint GetOnceFetchCount();

	//! \brief 图幅索引空间查询 
	//! \param pGeo 面对象[in]
	//! \param aryInnerIDs  [out]
	//! \param aryMaybeIDs	[out]
	//! \param aryOuterIDs	[out]
	//! \param nOption		[in]
    virtual UGbool LibTileSpatialQuery(UGGeometry *pGeo,
		UGArray<UGint> &aryInnerIDs,
		UGMaybeItems &aryMaybeIDs,
		UGArray<UGint> &aryOuterIDs,
		SpatialQueryOption nOption,
		UGdouble dbTolerance);

	//! \brief R树索引空间查询 
	//! \param pGeo 面对象[in]
	//! \param aryInnerIDs  [out]
	//! \param aryMaybeIDs	[out]
	//! \param aryOuterIDs	[out]
	//! \param nOption		[in]
	virtual UGbool RTreeSpatialQuery(UGGeometry *pGeo,
		UGArray<UGint> &aryInnerIDs,
		UGMaybeItems &aryMaybeIDs,
		UGArray<UGint> &aryOuterIDs,
		SpatialQueryOption nOption,
		UGdouble dbTolerance);

	//! \brief 多级网格索引空间查询 
	//! \param pGeo 面对象[in]
	//! \param aryInnerIDs  [out]
	//! \param aryMaybeIDs	[out]
	//! \param aryOuterIDs	[out]
	//! \param nOption	[in]
	virtual UGbool DynamicSpatialQuery(UGGeometry *pGeo,
		UGArray<UGint> &aryInnerIDs, UGMaybeItems &aryMaybeIDs,
		UGArray<UGint> &aryOuterIDs, SpatialQueryOption nOption,UGdouble dbTolerance);

private:
	UGint GetKey(const UGRect2D rc2Bounds);
	UGbool Var2Ptr(UGbyte * pDestData,const UGFieldInfo & fieldInfo,UGVariant var);

	//! \brief 计算给定范围经过的所有网格中最左下及右上网格的坐标 
	//! \param rcBounds 矩形范围[in]
	//! \param aryGrids 左下及右上网格的坐标[out]
	UGbool FindQueryGrids(UGRect2D &rcBounds,UGArray<UGPoint> &aryGrids);

	//! \brief 刷新选项信息
	void RefreshOption();

public:
	UGDBRTree * m_pRTreeIndex;
	//过滤条件
	UGdouble	m_dGranule;
	UGbool m_bMemoryed;
	UGTime m_memLastUpdateTime;
	UGMutex m_mutex;
	UGMutex m_nOpenMutex;
	UGint m_nMaxIndexSize;
protected:
	UGString m_strDescription;
	UGRect2D m_QueryBounds;
	
private:
	UGFileStream m_IndexFile;
};

}

#endif // !defined(AFX_UGODBCDATASETVECTOR_H__C7B96DD7_2CBA_4F39_AD4_9C23CB53FD__INCLUDED_)

