/*! \file	 UGOrcDatasetVector.h
 *  \brief	 Oracle Plus DatasetVector
 *  \author	 ugc team
 *  \attention 
 *  Copyright(c) 1996-2004 SuperMap GIS Technologies,Inc.<br>
 *  All Rights Reserved
 */


#ifndef UGORCDATASETVECTOR_H
#define UGORCDATASETVECTOR_H

#include "Base/ugdefs.h"	// Added by ClassView
#include "Engine/UGDatasetVector.h"
#include "UGOCIConnection.h"
#include "Engine/UGDBRTree.h"
#include "Base/UGThread.h"
#include "Base/UGFileStream.h"
#include "Base/UGProgress.h"
namespace UGC{

class ORCENGINE_API UGOrcDatasetVector  :public UGDatasetVector
{
	friend class UGOrcRecordset;
	friend class UGOrcEditRecordset;
	friend class UGOrcCacheRecordset;
	friend class UGOrcDatasetVectorVersion;
	friend class UGOrcSpatialIndex;
public:
	enum ORCP_DT_OPTION
	{
		ORCP_DT_OPENED				= 0x00000001,
		ORCP_DT_TRANSMODIFIED		= 0x00000002,
		ORCP_DT_CHECKED_OUT			= 0x00000004,
		ORCP_DT_LONGTRANS_REGISTED	= 0x00000008
	};

	UGuint GetOnceFetchCount();
	UGOrcDatasetVector();

	UGOrcDatasetVector(UGDataSource *pDataSource);

	virtual ~UGOrcDatasetVector();

	//!基类中定义的纯虚函数
	
	//! 打开数据集
	virtual UGbool Open();

	//! 关闭数据集
	virtual void Close();
	
	//! 保存数据集信息
	virtual UGbool SaveInfo();
	
	//! 刷新数据集信息
	virtual UGbool RefreshInfo();

	//! 设置数据集的范围
	virtual void SetBounds(const UGRect2D& r);
	
	UGbool Create(const UGString & strName, 
		UGDataset *pDatasetParent,
		const UGDatasetVectorInfo & vInfo);
	
	//! 返回最后更新时间
	virtual UGTime GetDateLastUpdated();
	
	//! 返回创建时间
	virtual UGTime GetDateCreated();
	
	//! 数据集重命名,只改变数据集名,表名不变
	virtual UGbool Rename(const UGString& strNewName);		

	//! 查询大表图库中一个图幅的数据
	virtual UGRecordset* QueryWithLibTileID(UGint nLibTileID,
		UGArray<UGString> & arFields,UGdouble dGranule);

	UGbool GetLibTileSQL(const UGRect2D& rc2SearchBounds,
		UGString& strLibTile);
	
	//! 通过矩形范围查询图幅序号
	virtual UGbool GetLibTileIDs(const UGRect2D& rc2Bounds,
		UGArray<UGint>& arLibTileIDs);
	
	//! 得到一个图幅的信息
	virtual UGbool GetLibTileInfo(UGint nTileID,UGRect2D& rc2TileBounds,
		UGint& nRecCount,UGint& nVersion);
	
	/// \brief 设置当前数据集的最大的Geometry的大小
	/// \remarks 在查询时需要根据数据集最大的Geometry的大小开辟内存缓存空间
	UGbool SetMaxGeometrySize(UGuint nRawsize);

	//! 长事务处理函数
	virtual UGbool CheckOut();
	virtual UGbool CheckIn(UGbool bKeepCheckedOut);
	virtual UGbool UndoCheckOut(UGbool bKeepCheckedOut);

	UGint GetLoggedUserID();
	UGint GetLockedUserID();
	UGint GetCheckedUserID();
	
	
	//! 通过值更新字段值
	virtual UGbool UpdateField(const UGString& strFieldName,
		const UGVariant& varValue,const UGString& strFilter = "");
	
	//! 通过表达式更新字段值
	virtual UGbool UpdateFieldEx(const UGString& strFieldName,
		const UGString& strExpress,const UGString& strFilter = "");
	
	//! 复制字段值,strSrcField和
	//! strDestField必须都存在且字段类型匹配
	virtual UGbool CopyField(const UGString& strSrcField,
		const UGString& strDestField);
	
	
	//! 建普通索引
	virtual UGbool CreateIndex(const UGString& strFieldNameList,
		const UGString& strIndexName);
	
	//! 删除索引
	virtual UGbool DropIndex(const UGString& strIndexName);

	//! 是否有几何数据，除了Tablur数据集，都有几何数据
	virtual UGbool HasGeometry() const;
	
	//! 查询通用入口
	virtual UGRecordset* Query(const UGQueryDef& querydef);

	virtual UGRecordset* Query2(UGLinkItem &linkitem);
	
	//! 通过Bounds查询
	virtual UGRecordset* QueryWithBounds(const UGRect2D &rc2Bounds,
		UGQueryDef::QueryOption nOptions = UGQueryDef::Geometry,
		UGQueryDef::QueryMode nMode = UGQueryDef::FuzzyQuery);
	
	//! 通过IDs查询
	virtual UGRecordset* QueryWithIDs(UGint *pIDs,UGint nCount,
		UGQueryDef::QueryOption nOptions = UGQueryDef::Both ,
		UGQueryDef::QueryMode nMode = UGQueryDef::GeneralQuery);
	
	//! 创建多个字段
	virtual UGbool CreateFields(const UGFieldInfos& fieldInfos);
	
	//! 通过FieldInfo创建字段
	virtual UGbool CreateField(const UGFieldInfo& fieldInfo);
	
	//! 创建字段
	virtual UGbool CreateField(const UGString& strName,UGFieldInfo::FieldType nType,
		UGint nSize,UGint nAttributes = 0);
	
	//! 通过字段名称删除字段
	virtual UGbool DeleteField(const UGString& strName);
	
	//! 通过索引号删除字段
	virtual UGbool DeleteField(UGint nIndex);
	
	//! 收集所有字段的信息
	virtual UGbool GetFieldInfos(UGFieldInfos& fieldInfos,
		UGbool bSystemFieldExcluded = FALSE);
	
	//! 通过字段名获取字段信息
	virtual UGbool GetFieldInfo(const UGString& strName,
		UGFieldInfo& fieldInfo);
	
	//! 通过索引获取字段信息
	virtual UGbool GetFieldInfo(UGint nIndex,
		UGFieldInfo& fieldInfo);
	
	//! 通过字段名设置字段信息
	virtual UGbool SetFieldInfo(const UGString& strName,
		const UGFieldInfo& fieldInfo);
	
	//! 通过索引设置字段信息
	virtual UGbool SetFieldInfo(UGint nIndex,
		const UGFieldInfo& fieldInfo);
	
	//! 获取字段个数
	virtual UGint GetFieldCount();
		
	//! 删除表中所有数据
	virtual UGbool Truncate();
	
	//! 统计字段值
	virtual UGVariant Statistic(const UGString& strField,
		UGStatisticMode nMode);
	
	//! 计算字段单值个数
	virtual UGint CalculateUniqueValues(const UGString &strFieldName,
		UGArray<UGVariant>& varKeys);
	
	//! 真正的SQL查询记录个数,更新Register表
	virtual UGbool ComputeRecCount();
	
	//! 获取最大空间对象的字节大小
	virtual UGint GetMaxGeoSize();
	
	//! 设置最大空间对象的字节大小
	virtual UGbool SetMaxGeoSize(UGint nMaxGeoSize);
	
	//! 时序数据的注册时间
	virtual UGTime GetRegistSequenceTime();
	
	//! 时序数据的最新更新时间
	virtual UGTime GetLUSequenceTime();
	
	//! 通过ID数组删除数据集中的记录
	virtual UGbool DeleteRecords(const UGint* pIDs,UGint nCount);
	
	//! 追加记录
	virtual UGbool Append(UGRecordset* pSrcRecordset,UGbool bShowProgress = TRUE,
		UGString strTileName = "");
	
	//! 重采样，仅对线数据集有效
	virtual UGbool Resample(UGdouble dTolerance,
		UGbool bShowProgress=TRUE);	
	
	//! 返回记录集个数
	virtual UGint GetRecordsetCount();
	
	//! 返回指定索引的数据集指针
	virtual UGRecordset* GetRecordsetAt(UGint nIndex);
	
	//! 通过索引释放记录集
	virtual UGbool ReleaseRecordset(UGint nIndex);
	
	//! 通过引用释放记录集
	virtual UGbool ReleaseRecordset(UGRecordset *pRecordset);
	
	//! 是否每个对象有自己的风格
	virtual UGbool HasStyle();

	//! 设置是否每个对象有自己的风格
	//virtual void SetStyleFlag(UGbool bHasStyle);
	virtual void SetFlag(UGint nOption,UGbool bHas);
	
	//! 判断字段名是否有效
	virtual UGbool IsAvailableFieldName(const UGString& strFieldName);
	
	//! 得到图库索引图的名字	
	virtual UGString GetMiniatureDtName();		
	
	//! 通过类别获取字段名
	virtual UGString GetFieldNameBySign(FieldSign nSign);
	
	//! 设置字段的类别
	virtual UGbool SetFieldSign(const UGString& strFieldName,FieldSign nSign);

	//! 判断当前数据集是否可编辑
	virtual UGbool CanUpdate();

	//! 注册选项信息
	virtual UGbool RegisterOption(UGint nOption);

	//! 反注册选项信息
	virtual UGbool UnRegisterOption(UGint nOption);

	//!数据集是否支持某种操作模式
	virtual UGbool HasAbility(UGEngAbility dwEngAbility);

	virtual UGbool IsSupport(UGEngAction nAction);

	//! 计算数据集范围,一般在数据集中元素被删除或修改后使用,
	//! 可能耗费较多时间
	virtual UGbool ComputeBounds();

	//! 返回数据集中对象个数,速度慢,但值比较正确,
	//! 通过Register表获取
	virtual UGint GetObjectCount();

	virtual UGbool PostToMainVersion(UGString strVersion,
					UGPostOption nPostOption,
					UGArray<UGCheckConflict> &CheckConfilcts);	

	virtual UGbool PostToMainVersion(UGint nVersionID,
					UGPostOption nPostOption,
					UGArray<UGCheckConflict> &CheckConfilcts);

	virtual UGbool PostToMainVersion(UGint nVersionID,
					UGint nDataID,
					UGPostOption nPostOption);


	virtual UGbool RollBackVersion(UGint nVersion);

	
	//! R树操作函数
	virtual UGint LoadRTreeLeaf(UGint nID,UGStream &stream);
	virtual UGbool StoreRTreeLeaf(UGint nID,UGStream &stream);
	
	virtual UGbool ExtractLeafData(const UGRectUInt& SearchBounds, 
		UGArray<UGint>& aryItemIDs, 
		UGArray<UGint>& aryCertainLeafIDs,
		UGArray<UGRectUInt> &aryCertainBounds,
		UGArray<UGint>& aryMaybeLeafIDs,
		UGArray<UGRectUInt> &aryMaybeBounds,
		UGbool bFuzzy,
		UGdouble dGranule);

protected:
	//! 建立空间索引
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

	//! 清除空间索引
	virtual UGbool DropSpatialIndex();

	//! 是否需要重建空间索引
	virtual UGbool IsSpatialIndexDirty();

	//! 对数据的空间索引进行统计分析
	virtual UGbool StatisticIndex(UGDataSource *pDs);
	
	//! 返回空间索引脏的记录的数目，为是否需要重建空间索引提供参考
	virtual UGint GetDirtyRecordCount();

	//! 如果参与了topo 可以获得topo数据集指针
	virtual UGDataset * GetTopoAdscriptionDT();

	virtual UGbool CreateSubDataset(UGDatasetVectorInfo & vInfo);
	virtual UGbool DeleteSubDataset(UGString &strName);

	//! \brief 图幅索引空间查询 
	//! \param pGeo 面对象[in]
	//! \param aryInnerIDs  [out]
	//! \param aryMaybeIDs	[out]
	//! \param aryOuterIDs	[out]
	//! \param nOption	[in]
    virtual UGbool LibTileSpatialQuery(UGGeometry *pGeo,
		UGArray<UGint> &aryInnerIDs,
		UGMaybeItems &aryMaybeIDs,
		UGArray<UGint> &aryOuterIDs,
		SpatialQueryOption nOption, UGdouble dbTolerance);

	virtual UGbool RTreeSpatialQuery(UGGeometry *pGeo,
		UGArray<UGint> &aryInnerIDs, UGMaybeItems &aryMaybeIDs,
		UGArray<UGint> &aryOuterIDs, SpatialQueryOption nOption,
		UGdouble dbTolerance);

	virtual UGbool DynamicSpatialQuery(UGGeometry *pGeo, 
		UGArray<UGint> &aryInnerIDs, UGMaybeItems &aryMaybeIDs, 
		UGArray<UGint> &aryOuterIDs, SpatialQueryOption nOption, 
		UGdouble dbTolerance);

	//! \brief 计算范围边界网格
	//! \param &rcBounds [in]。
	//! \param &aryGrids [out]。
	//! \return T
	//! \remarks 有几层就计算几层，aryGrids按照左下，右上记录
	//! \attention 。
	UGbool FindQueryGrids(UGRect2D &rcBounds,UGArray<UGPoint> &aryGrids);
public:

	/// \brief 从数据库中读取当前数据集的Bounds信息
	/// \remarks 此函数与CDatasetVector::GetBounds有所区别，此函数是从数据库中读取，得到的是最新的Bounds，而后者是直接从内存中读取m_DatasetInfo中存储的Bounds信息，速度要快得多
	/// \sa	CDatasetVector::GetBounds
	UGRect2D GetBoundsDirectly();

	UGbool RegisterUser(UGint nLogID,UGbool bRecordsetLevel = FALSE);

	UGOCIConnection * GetConnection() const;
	
	void CheckError() const;

	UGbool CanTransact();

	UGbool GetCacheFile(UGString &strFileName,UGint nLibTileID);
	UGbool RefreshIndexCache();
	
	UGbool QueryFieldInfos();
	
	UGbool IsSupportMyOption(UGint nMyOption){ return (m_nMyOption & nMyOption) == nMyOption;}
	void SetMyOption(UGint nMyOption){m_nMyOption |= nMyOption;}
	void UnsetMyOption(UGint nMyOption){m_nMyOption &= (~nMyOption);}
	UGString CheckFieldName(UGString strFieldName);
	UGbool ORAType2FieldType(UGString oraType, UGint nLength,UGint nScale,UGFieldInfo::FieldType &nFieldType);

	UGbool SetFieldInfo(const UGString& strName,
		const UGString& strForeignName,
		UGFieldInfo::FieldType nType,
		const UGString & strFormat,
		const UGString & strDomain,
		UGbool bUpdatable);

	UGbool U_CreateTable(UGString strName,UGFieldInfos &fieldInfos);
	void U_RefreshExtInfo(UGint nDataVersionID);

	//数据源删除版本时调用
	UGbool U_DeleteVersion(UGint nVersionID);

	UGbool IsPointDT();

	//! \brief	设置字符集及保存smOption;
	void SetCharset(UGTextCodec::Charset c);

protected:
	void U_CreateLinkDatasource(UGDsConnection &conn);

	//版本数据集 视图名替换表名
	UGString ReplaceTNameByVName(UGString strSQL);
	
private:
	/// \brief 刷新当前数据集的选项信息
	/// \sa RegisterOption, UnRegisterOption, CSmDataset::GetOptions
	UGbool RefreshOption();
	
	UGbool Var2Ptr(UGbyte * pDestData,const UGFieldInfo & fieldInfo,UGVariant var);

	UGint GetMaxSmID();

	// \brief 获取自增序列的名字
	UGString GetSequenceName();

	UGString GetStringbyFieldtype(const UGFieldInfo &fieldInfo);

public:
	UGDBRTree * m_pRTreeIndex;

private:
	UGint m_nMaxIndexSize;	
	UGint m_nMyOption;
	UGint m_nState;
	UGMutex m_mutex;
	UGMutex m_nOpenmutex;
	UGFileStream m_IndexFile;
};

}
#endif // !defined(UGORCDATASETVECTOR_H)
