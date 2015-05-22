/*! \file	 UGDatasetVector.h
 *  \brief	 矢量数据集类
 *  \author	 ugc team
 *  \attention 
 *  Copyright(c) 1996-2004 SuperMap GIS Technologies,Inc.<br>
 *  All Rights Reserved
 *  \version $Id: UGDatasetVector.h,v 1.78 2008/03/25 09:35:38 lisj Exp $
 */

#ifndef UGDATASETVECTOR_H
#define UGDATASETVECTOR_H

#include "Base/ugdefs.h"
#include "UGDataset.h"
#include "Base/UGTime.h"
#include "UGRecordset.h"
#include "Base/UGTextCodec.h"
#include "UGDatasetVectorInfo.h"
#include "Engine/UGSpatialIndexInfo.h"
#include "UGTable.h"

namespace UGC {


class UGDataHistory;
struct UG_DATA_CACHE_FILE_HEADER 
{
	UGint nVersion;
	UGint nRecordCount;
	UGDataCodec::CodecType nCodecType;
	UGint nDatasetID;
	UGint nLibID;
	UGint nOffBits;
	UGRect2D rc2Bounds;
	UGdouble dXGridSize;
	UGdouble dYGridSize;
	UGint nReserved1;
	UGint nReserved2;

	void Save(UGStream& stream)
	{
		stream<<nVersion;
		stream<<nRecordCount;
		stream<<(UGint)nCodecType;
		stream<<(UGint)nDatasetID;
		stream<<nLibID;
		stream<<nOffBits;
		
		stream<<rc2Bounds.left;
		stream<<rc2Bounds.top;
		stream<<rc2Bounds.right;
		stream<<rc2Bounds.bottom;
		
		stream<<dXGridSize;
		stream<<dYGridSize;
		stream<<nReserved1;
		stream<<nReserved2;
	};

	void Load(UGStream& stream)
	{
		stream>>nVersion;
		stream>>nRecordCount;
		UGint nEnc = 0;
		stream>>nEnc;
		nCodecType = (UGDataCodec::CodecType)nEnc;
		stream>>nDatasetID;
		stream>>nLibID;
		stream>>nOffBits;
		
		stream>>rc2Bounds.left;
		stream>>rc2Bounds.top;
		stream>>rc2Bounds.right;
		stream>>rc2Bounds.bottom;
		
		stream>>dXGridSize;
		stream>>dYGridSize;
		stream>>nReserved1;
		stream>>nReserved2;
	};
};

struct UG_INDEX_CACHE_FILE_HEADER 
{
	UGint nReserved1;
	UGint nReserved2;
	UGint nOffBits;

	void Save(UGStream& stream)
	{
		stream<<nReserved1;
		stream<<nReserved2;
		stream<<nOffBits;
	};

	void Load(UGStream& stream)
	{
		stream>>nReserved1;
		stream>>nReserved2;
		stream>>nOffBits;
	};
};	

//记录历史对象指针和是否指针有效的结构
struct ValidDataHistory{
	UGDataHistory* pDataHistory;
	UGbool bValid ;
};

class  ENGINE_API UGSubDtArray : public UGArray<UGDatasetVector *>
{
public:
	UGSubDtArray()
	{
	};

	~UGSubDtArray()
	{
	};
public:
	UGDatasetVector * operator [](UGint nIndex) const;
	UGDatasetVector * operator [](UGString strName) const;
};
//UG_SQ_MAYBEIDS
class ENGINE_API UGMaybeItem
{
public:
	UGMaybeItem()
	{
		pGeometry = NULL;
		aryIDs.RemoveAll();
	};

	~UGMaybeItem()
	{
		if(pGeometry)
		{
		}
		aryIDs.RemoveAll();
	};

public:
	UGGeometry *pGeometry;
	UGArray<UGint> aryIDs;
};

class ENGINE_API UGMaybeItems : public UGArray<UGMaybeItem >
{
public:
	void ReleaseAll()
	{
		for(UGint n=0; n < this->GetSize(); n++)
		{
			delete GetAt(n).pGeometry;
//			GetAt(n).pGeometry = NULL;
		}
	};
};

typedef UGArray<UGint> UG_MayIDs;

class ENGINE_API UGDatasetVector : public UGDataset, public UGTable
{
public:
	//! 特殊系统字段标识
	enum FieldSign  
	{
		signNodeID			= 1, //! 网络数据集的节点ID，默认是SmNodeID字段
		signFNode			= 2, //! 网络数据集起点字段, 默认是SmFNode
		signTNode			= 3, //! 网络数据集终点字段, 默认是SmTNode
		signEdgeID			= 4, //! 网络数据集边的ID字段
		signRouteID			= 5, //! 路线数据集的RouteID字段			
		signCustom			= 50 //! 用户自定义字段标识起始值
	};

	

public:
	//! 构造函数
	UGDatasetVector();
	//! 析构函数
	~UGDatasetVector();

	//! 基类UGDataset定义的纯虚函数
public:
	//! 返回数据集类型
	virtual DatasetType GetType() const
	{
		return m_DatasetInfo.m_nType;
	}

	//! 返回数据集的维数
	virtual UGint GetDimension();

	//! 返回数据集名(可以和表名不同)
	virtual UGString GetName()
	{
		return m_DatasetInfo.m_strName;
	}
	
	//! 返回数据集对应表名
	virtual UGString GetTableName()
	{
		return m_strTableName;
	}

	//! 设置数据集对应的数据表的名字
	void SetTableName(const UGString& strTableName)
	{
		m_strTableName = strTableName;
	}
	
	//! 获取数据集描述信息
	virtual UGString GetDescription() const;

	//! 设置数据集描述信息
	virtual void SetDescription(const UGString& /*strDesc*/);

	//! 返回最小高程
	virtual UGdouble GetMinZ()
	{
		return m_DatasetInfo.m_dMinZ;
	}
	
	//! 设置最小高程
	virtual void SetMinZ(UGdouble d)
	{
		m_DatasetInfo.m_dMinZ = d;
		SetModifiedFlag();
	}
	
	//! 返回最大高程
	virtual UGdouble GetMaxZ()
	{
		return m_DatasetInfo.m_dMaxZ;
	}
	
	//! 设置最大高程
	virtual void SetMaxZ(UGdouble d)
	{
		m_DatasetInfo.m_dMaxZ = d;
		SetModifiedFlag();
	}

	//! 判断是否是矢量数据集
	virtual UGbool IsVector(){return m_DatasetInfo.m_nType != LinkTable;};

	virtual UGbool IsLinkTable(){return m_DatasetInfo.m_nType == LinkTable; };

	//! 判断是否是topo数据集
	virtual UGbool IsTopoDataset(){return FALSE;};

	//! 判断是否是栅格数据集
	virtual UGbool IsRaster(){return FALSE;};

	//! 返回数据集的范围
	virtual const UGRect2D& GetBounds() const{return m_DatasetInfo.m_rc2Bounds;}
	
	//! 设置数据集的范围
	virtual void SetBounds(const UGRect2D& r){
		m_DatasetInfo.m_rc2Bounds = r;SetModifiedFlag();
	}

	//! 返回空间数据编码方式
	virtual UGDataCodec::CodecType GetCodecType(){return (UGDataCodec::CodecType)m_DatasetInfo.m_nCodecType;}
	
	//! 设置空间数据编码方式,创建数据集的时候设置,如果有数据操作不能修改
	virtual void SetCodecType(UGDataCodec::CodecType c){
		m_DatasetInfo.m_nCodecType = c;
		SaveInfo();
	}

	//! 直接从内存中返回对象个数,速度比较快,
	//! 但不能保证正确,通过DatsetInfo获取
	virtual UGint GetObjectCountDirectly() {
		return m_DatasetInfo.m_nObjectCount;
	}
	
	//! 返回数据集中对象个数,速度慢,但值比较正确,
	//! 通过Register表获取
	virtual UGint GetObjectCount() {
		return m_DatasetInfo.m_nObjectCount;
	}

	//! 返回数据集中对象个数,速度慢,但值比较正确,
	//! 通过Register表获取
	virtual void SetObjectCount(UGint nCount) {
		m_DatasetInfo.m_nObjectCount = nCount;
	}

	//! 返回数据集的选项信息(用四字节的整型数据代表一些属性)
	virtual UGint GetOptions()
	{
		return m_DatasetInfo.m_nOptions;
	}

	//! \brief 空间查询 
	//! \param pGeo 面对象[in]
	//! \param aryInnerIDs  [out]
	//! \param aryMaybeIDs	[out]
	//! \param aryOuterIDs	[out]
	//! \param nOption	[in] 
	//!			0x00000001 内部
	//!			0x00000002 Maybe					
	//!			0x00000004 外部
	//! \return 成功
	//! \remarks 范围精确空间查询,UG_SQ_MAYBEIDS里Geo必须是内部所有对象范围Union之后，与查询对象的裁减结果。
	virtual UGbool SpatialQuery(UGGeometry *pGeo,
		UGArray<UGint> &aryInnerIDs,
		UGMaybeItems &aryMaybeIDs,
		UGArray<UGint> &aryOuterIDs,
		SpatialQueryOption nOption, UGdouble dbTolerance=EP);

	//! \brief 图幅索引空间查询 
	//! \param pGeo 面对象[in]
	//! \param aryInnerIDs  [out]
	//! \param aryMaybeIDs	[out]
	//! \param aryOuterIDs	[out]
	//! \param nOption	[in]
    virtual UGbool LibTileSpatialQuery(UGGeometry *pGeo,
		UGArray<UGint> &aryInnerIDs, UGMaybeItems &aryMaybeIDs,
		UGArray<UGint> &aryOuterIDs, SpatialQueryOption nOption, 
		UGdouble dbTolerance);

	//! \brief R树索引空间查询 
	//! \param pGeo 面对象[in]
	//! \param aryInnerIDs  [out]
	//! \param aryMaybeIDs	[out]
	//! \param aryOuterIDs	[out]
	//! \param nOption	[in]
	virtual UGbool RTreeSpatialQuery(UGGeometry *pGeo,
		UGArray<UGint> &aryInnerIDs, UGMaybeItems &aryMaybeIDs,
		UGArray<UGint> &aryOuterIDs, SpatialQueryOption nOption,
		UGdouble dbTolerance);

	//! \brief 多级网格索引空间查询 
	//! \param pGeo 面对象[in]
	//! \param aryInnerIDs  [out]
	//! \param aryMaybeIDs	[out]
	//! \param aryOuterIDs	[out]
	//! \param nOption	[in]
	//! \brief pGeo为二维对象时，aryInnerIDs是被pGeo完全包含的对象ID；aryMaybeIDs是与pGeo相交的ID，关系需要进一步判断；aryOuterIDs是一定在pGe外部的对象ID
	//! \brief pGeo为一维对象时，aryInnerIDs为空；aryMaybeIDs是与pGeo相交的ID，关系需要进一步判断；aryOuterIDs是与pGeo没有交点对象ID
	//! \brief pGeo为零维对象时，aryInnerIDs为空；aryMaybeIDs是点落在对象范围内的对象ID，aryOuterIDs是点落在对象范围外的对象ID
	virtual UGbool DynamicSpatialQuery(UGGeometry *pGeo,
		UGArray<UGint> &aryInnerIDs, UGMaybeItems &aryMaybeIDs,
		UGArray<UGint> &aryOuterIDs, SpatialQueryOption nOption, 
		UGdouble dbTolerance);
public:
	UGDatasetVectorInfo * GetInfo();
	//! 判断数据集是否有某个选项信息
	UGbool HasFlag(UGint nOption);

	//! 设置数据集的属性,一般不可以直接修改
	virtual void SetFlag(UGint nOption,UGbool bHas) =0;

	//! 是否有几何数据，除了Tablur数据集，都有几何数据
	virtual UGbool HasGeometry() const =0;

	//! 查询通用入口
	virtual UGRecordset* Query(const UGQueryDef& querydef) =0;

	//! 外挂属性表查询
	virtual UGRecordset* Query2(UGLinkItem &linkitem);

	//! 获取最大空间对象的字节大小
	virtual UGint GetMaxGeoSize() =0;

	//! 设置最大空间对象的字节大小
	virtual UGbool SetMaxGeoSize(UGint nMaxGeoSize) =0;

	//! 追加记录
	virtual UGbool Append(UGRecordset* pSrcRecordset, 
		UGbool bShowProgress = TRUE,UGString strTileName = "") =0;

	//! 追加记录,属性字段有对应关系,空间字段不处理
	virtual UGbool Append(UGRecordset* pSrcRecordset,
		UGArray<UGString> &strSrcFieldNames,
		UGArray<UGString> &strDesFieldNames,
		UGbool bShowProgress = TRUE,
		UGString strTileName = "");

	//! 获取父数据集指针
	UGDataset* GetParentDataset() const {
		return m_pParentDataset;
	}

	//! 获取子数据集指针
	UGDatasetVector * GetChildDataset() const;

	//! 设置父数据集指针
	void SetParentDataset(UGDatasetVector* pDatasetVector)
	{
		m_pParentDataset = pDatasetVector;
	}

	//! 返回记录集个数
	virtual UGint GetRecordsetCount() =0;

	//! 返回指定索引的数据集指针
	virtual UGRecordset* GetRecordsetAt(UGint nIndex) =0;

	//! 通过索引释放记录集
	virtual UGbool ReleaseRecordset(UGint nIndex) =0;

	//! 通过引用释放记录集
	virtual UGbool ReleaseRecordset(UGRecordset *pRecordset) =0;

	//! 释放所有记录集
	void ReleaseAllRecordsets();

	//! 得到数据集中空间索引的BOUNDS
	UGRect2D GetIndexBounds() const {
		return m_DatasetInfo.m_rc2IndexedBounds;
	}

	//! 设置数据集中索引的BOUNDS
	void SetIndexBounds(const UGRect2D& rc2Bounds)
	{
		m_DatasetInfo.m_rc2IndexedBounds = rc2Bounds;
		SetModifiedFlag();
	}

	//! 判断字段名是否有效
	virtual UGbool IsAvailableFieldName(const UGString& strFieldName) =0;

	//! 得到未被占用的字段名
	virtual UGString GetUnoccupiedFieldName(const UGString& strFieldName);

	//! 得到图库索引图的名字	
	virtual UGString GetMiniatureDtName() =0;
	
	//! 通过类别获取字段名
	virtual UGString GetFieldNameBySign(FieldSign nSign) =0;
	
	//! 设置字段的类别
	virtual UGbool SetFieldSign(const UGString& strFieldName,FieldSign nSign) =0;


	virtual UGString GetDVATabName();
	virtual UGString GetDVAIndexTabName();
	
	virtual UGString GetDVDTabName();
	
	virtual UGString GetDVCTabName();

	//! 返回数据集字符编码方式
	UGTextCodec::Charset GetCharset() const {
		return m_nCharset;
	}
	
	//! 设置数据集字符编码方式
	virtual void SetCharset(UGTextCodec::Charset c) {
		m_nCharset = c;
		SetModifiedFlag();
	}
	
	UGbool PJConvert( UGRefTranslator *pRefTranslator );		//投影转换
	UGbool PJForward( UGPrjCoordSys *pPrjCoordSys );			//地理坐标到投影坐标,假定Datum相同.
	UGbool PJInverse( UGPrjCoordSys *pPrjCoordSys );			//投影坐标到地理坐标,假定Datum相同.


	//*****************数据维护函数******************
	//! 真正的SQL查询记录个数,更新Register表
	virtual UGbool ComputeRecCount() =0;
	//*****************数据维护函数******************

	//! 通过ID数组删除数据集中的记录
	virtual UGbool DeleteRecords(const UGint* pIDs,UGint nCount) =0;

	//*****************版本管理的方法******************
	virtual UGbool RollBackVersion(UGint nVersion);

	virtual UGbool PostToMainVersion(UGString strVersion,
					UGPostOption nPostOption,
					UGArray<UGCheckConflict> &CheckConfilcts);	

	virtual UGbool PostToMainVersion(UGint nVersionID,
					UGPostOption nPostOption,
					UGArray<UGCheckConflict> &CheckConfilcts);

	virtual UGbool PostToMainVersion(UGint nVersionID,
					UGint nDataID,
					UGPostOption nPostOption);
	//*****************版本管理的方法******************

	virtual UGbool ExtractLeafData(const UGRectUInt& SearchBounds,
					const UGRectUInt& rcReferenceBounds,
					UGArray<UGint>& aryItemIDs,
					UGArray<UGint>& aryCertainLeafIDs,
					UGArray<UGRectUInt> &aryCertainBounds,
					UGArray<UGint>& aryMaybeLeafIDs,
					UGArray<UGRectUInt> &aryMaybeBounds,
					UGbool bFuzzy,
					UGdouble dGranule);

	//! 获取缓存文件的临时路径
	UGString GetCacheTempPath() const {return m_strCacheTempPath;}

	//! 设置缓存文件的临时路径
	void SetCacheTempPath(const UGString& strTempPath){ m_strCacheTempPath = strTempPath;}

	//! 长事务处理函数
	virtual UGbool CheckOut() =0;
	virtual UGbool CheckIn(UGbool bKeepCheckedOut) =0;
	virtual UGbool UndoCheckOut(UGbool bKeepCheckedOut) =0;

	//! 返回索引表的名字
	virtual UGString GetIndexTableName()
	{
		return m_strIndexTable;
	}

	//! 设置索引表的名字
	void SetIndexTableName(const UGString& strIndexTable)
	{
		m_strIndexTable = strIndexTable;
	}
		
	//*************时空操作************
	//! 时序数据的注册时间
	virtual UGTime GetRegistSequenceTime() =0;

	//! 时序数据的最新更新时间
	virtual UGTime GetLUSequenceTime() =0;
	//*************时空操作************

	//! R树操作函数
	virtual UGint LoadRTreeLeaf(UGint nID,UGStream &stream) =0;
	virtual UGbool StoreRTreeLeaf(UGint nID,UGStream &stream) =0;
	virtual UGbool StoreRTreeTrunk(UGStream &stream);
	

	
	//! 容限是否空(0.0) 
	UGbool IsToleranceEmpty() const {
		return UGIS0(m_DatasetInfo.m_dToleranceDangle) &&
			UGIS0(m_DatasetInfo.m_dToleranceExtend) &&
			UGIS0(m_DatasetInfo.m_dToleranceGrain) &&
			UGIS0(m_DatasetInfo.m_dToleranceNodeSnap) &&
			UGIS0(m_DatasetInfo.m_dToleranceSmallPolygon);
	}

	//! 使用默认容限
	virtual void SetToleranceToDefault();

	//! 设置容限为空
	void EmptyTolerance() {
		m_DatasetInfo.m_dToleranceDangle = 0;
		m_DatasetInfo.m_dToleranceExtend = 0;
		m_DatasetInfo.m_dToleranceGrain = 0;
		m_DatasetInfo.m_dToleranceNodeSnap = 0;
		m_DatasetInfo.m_dToleranceSmallPolygon = 0;
		SetModifiedFlag();
	}

	//! 设置最小多边形面积的范围
	void SetToleranceSmallPolygon(UGdouble dNewValue) {
		m_DatasetInfo.m_dToleranceSmallPolygon = dNewValue;
		SetModifiedFlag();
	}

	//! 得到最小多边形面积的范围
	UGdouble GetToleranceSmallPolygon() const {
		return m_DatasetInfo.m_dToleranceSmallPolygon;
	}

	//! 设置短悬线容限
	void SetToleranceDangle(UGdouble dNewValue) {
		m_DatasetInfo.m_dToleranceDangle = dNewValue;
		SetModifiedFlag();
	}

	//! 得到短悬线容限
	UGdouble GetToleranceDangle() const {
		return m_DatasetInfo.m_dToleranceDangle;
	}

	//! 设置节点容限
	void SetToleranceNodeSnap(UGdouble dNewValue) {
		m_DatasetInfo.m_dToleranceNodeSnap = dNewValue;
		SetModifiedFlag();
	}

	//! 得到节点容限
	UGdouble GetToleranceNodeSnap() const {
		return m_DatasetInfo.m_dToleranceNodeSnap;
	}

	//! 设置曲线容限
	void SetToleranceGrain(UGdouble dNewValue) {
		m_DatasetInfo.m_dToleranceGrain = dNewValue;
		SetModifiedFlag();
	}

	//! 得到曲线容限
	UGdouble GetToleranceGrain() const {
		return m_DatasetInfo.m_dToleranceGrain;
	}

	//! 设置合并假节点容限
	void SetToleranceExtend(UGdouble dNewValue) {
		m_DatasetInfo.m_dToleranceExtend = dNewValue;
		SetModifiedFlag();
	}

	//! 得到合并假节点容限
	UGdouble GetToleranceExtend() const {
		return m_DatasetInfo.m_dToleranceExtend;
	}
	
	//! 设置数据集的选项信息
	void SetOptions(UGint nOptions)
	{
		m_DatasetInfo.m_nOptions = nOptions;
		SetModifiedFlag();
	}

	//added by xielin 2007-05-23 
	void RegisterToDataset(UGDataHistory* pDataHistory);
	void UnRegisterFromDataset(UGDataHistory* pDataHistory);

	//! 如果参与了topo 可以获得topo数据集指针
	virtual UGDataset * GetTopoAdscriptionDT();

	//! For Tin 数据集
	virtual UGbool CreateSubDataset(UGDatasetVectorInfo & vInfo);
	virtual UGbool DeleteSubDataset(UGString &strName);

	//!通过真实宽度，和设备宽度，来计算显示Tin金字塔的那一层数据
	UGDatasetVector * GetTinLayer(UGint nWidth,UGint nDeviceWidth);
protected:
	//! 建立空间索引
	//! 此方法只能用来建立四叉树索引和R树索引,图幅索引见其他的函数,如果是IDXNone
	//! 那么默认重建四叉树索引和R树索引
	virtual UGbool BuildSpatialIndex(UGSpatialIndexInfo  &spatial)=0;
	
	//! \brief 根据当前索引状态重建索引
	//! \param *pDataset [in]。
	//! \return
	//! \remarks
	//! \attention 
	virtual UGbool ReBuildSpatialIndex() = 0;

	//! \brief 脏数据的空间索引更新
	//! \param *pDataset [in]。
	//! \return 。
	//! \remarks 。
	//! \attention 。
	virtual UGbool UpdateSpatialIndex() = 0;

	//! 清除空间索引,为没有索引的状态
	virtual UGbool DropSpatialIndex() = 0;
	
	//! \brief 查询大表图库中一个图幅的数据
	//! \param nLibTileID [in]。
	//! \param arFields [in]。
	//! \param dGranule [in]。
	//! \return UGRecordset
	//! \remarks 如果dGraunle<=0，那么就不采用过滤方式,反之过滤
	//! \attention 。
	virtual UGRecordset* QueryWithLibTileID(UGint nLibTileID,
		UGArray<UGString> & arFields,UGdouble dGranule) =0;

	//! \brief 通过矩形范围查询图幅序号
	//! \param rc2Bounds [in]。
	//! \param arLibTileIDs [out]。
	//! \return UGbool
	//! \remarks 。
	//! \attention 。
	virtual UGbool GetLibTileIDs(const UGRect2D& rc2Bounds,
		UGArray<UGint>& arLibTileIDs) =0;
	
// 	virtual UGbool GetLibTileIDs(const UGGeoRegion *pGeo,
// 		UGArray<UGint>& aryInnerLibTileIDs,UGArray<UGint>& aryMaybeLibTileIDs);

	//! \brief 得到一个图幅的信息
	//! \param nTileID [in]。
	//! \param rc2TileBounds [out]。
	//! \param nRecCount [out]。
	//! \param nVersion [out]。
	//! \return 。
	//! \remarks 。
	//! \attention 。
	virtual UGbool GetLibTileInfo(UGint nTileID,UGRect2D& rc2TileBounds,
		UGint& nRecCount,UGint& nVersion) =0;	

	//! 是否需要重建空间索引
	//! 规定:如果没有索引返回FALSE,有索引看索引的情况
	virtual UGbool IsSpatialIndexDirty() =0;
	//! 返回空间索引脏的记录的数目，为是否需要重建空间索引提供参考
	//! 如果没有索引返回数据对象数,有索引以实际情况为准
	virtual UGint GetDirtyRecordCount() =0;

	//! 对数据的索引进行统计分析
	virtual UGbool StatisticIndex(UGDataSource *pDs);

	//! \brief 计算网格的范围
	//! \param aryGrid		网格[in]
	//! \param aryGridRect	网格的范围[out]
	virtual UGbool GetGridBounds(UGint& nLevel,UGArray<UGPoint>& aryGrid,UGArray<UGRect2D>& aryGridRect);

	//! \brief	maybe网格排序(最先按照X+1的方向)
	//! \param aryGridMaybe			满足maybe的网格[in]
	//! \param aryGridMaybeTemp		排序后的maybe网格(顺时针，逆时针方向的顺序都有可能)[out]
	virtual UGbool GridMaybeSort(UGArray<UGPoint> &aryGridMaybe,UGArray<UGPoint> &aryGridMaybeTemp);

public:
	//! 一次获取的记录数
	UGint m_nOnceFetchCount;
	//! 优化器记录数优化参数
	UGint m_nOptimizeCount;
	//! 优化器面积优化参数
	UGdouble m_dOptimizeRatio;
	//! 最大空间对象的字节大小
	UGint m_nMaxGeometrySize;
	//! 最大符号的字节大小
	UGint m_nMaxSymbolSize;
	//! 数据集的子数据集指针
	UGSubDtArray m_ArySubDataset;
	//! 矢量数据集信息
	UGDatasetVectorInfo m_DatasetInfo;
	//! TIN数据集子数据集指针

	//! 数据集关联查询的外部数据源
	UGArray<UGDataSource *> m_aryLinkDatasource;
	
protected:
	//! 记录集指针的集合，打开的所有记录集必须放在这里，
	//! 否则不知道怎么释放
	UGRecordsets m_Recordsets;
	//! 缓存文件的临时路径
	UGString m_strCacheTempPath;

	UGTextCodec::Charset m_nCharset;

	//! 父数据集的指针
	UGDataset * m_pParentDataset;

	//! 数据库中表的名字
	UGString m_strTableName;
	//! 索引表的名字
	UGString m_strIndexTable;

	//added by xielin 2007-05-22
	UGArray<ValidDataHistory> m_aryValidDataHistory;

	friend class UGSpatialIndex;
};

}

#endif
