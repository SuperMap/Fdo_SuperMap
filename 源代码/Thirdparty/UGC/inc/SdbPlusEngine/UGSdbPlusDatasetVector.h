// SmDataset.h: interface for the UGSdbPlusDatasetVector class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SDBDATASET49_H__017098AB_099E_11D3_92D2_0080C8EE62D1__INCLUDED_)
#define AFX_SDBDATASET49_H__017098AB_099E_11D3_92D2_0080C8EE62D1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Base/ugdefs.h"
#include "Algorithm/UGQTreeManager.h"
#include "Engine/UGDatasetVector.h"

#include "UGRTree.h"

namespace UGC{

class UGFolder;
class UGFileLogical;

class UGSdbPlusDataSource;
class UGSdbPlusRecordset;
   
class SDBPLUSENGINE_API UGSdbPlusDatasetVector : public UGDatasetVector  
{
	friend class UGSdbPlusDataSource;
	friend class UGSdbPlusRecordset;
	friend class UGSdbPlusRecordsetSequence;

public:
	UGSdbPlusDatasetVector();
	UGSdbPlusDatasetVector(UGDataSource *pDataSource);
	virtual ~UGSdbPlusDatasetVector();

public:

	UGbool Open();	//打开Dataset
	void Close();	//关闭Dataset
	UGbool IsOpen() const;	//Dataset是否打开

	UGbool Truncate(); //删除表中的所有数据
	UGbool Rename(const UGString& strNewName);	//数据集重命名

	UGbool SaveInfo();	//数据集信息存盘

	//空间索引
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

	virtual UGbool DropSpatialIndex();
	virtual UGbool IsSpatialIndexDirty();			//空间索引是否"脏",是否需要重建空间索引
	virtual UGint GetDirtyRecordCount();			//返回空间索引脏的记录的数目，为是否需要重建空间索引提供参考

	//属性字段索引
	virtual UGbool CreateIndex(const UGString &strFieldNameList,const UGString & strIndexName);
	virtual UGbool DropIndex(const UGString & strIndexName);

	//数据集属性
//	UGbool HasGeometry();		//判断是否为空间数据数据集
	UGbool CanUpdate();		//判断数据集是否可以Update

	/// \brief 判断当前数据集是否有执行指定操作的能力
	virtual UGbool HasAbility(UGEngAbility dwEngAbility);

	UGTime GetDateLastUpdated();		//返回最后更新日期
	UGTime GetDateCreated();			//返回创建日期
	UGString GetTableName();

	
	//数据集查询
	UGRecordset* Query(const UGQueryDef &querydef);	//执行查询操作
	UGRecordset* QueryWithBounds(const UGRect2D &rc2Bounds,
		UGQueryDef::QueryOption nOptions = UGQueryDef::Geometry,
		UGQueryDef::QueryMode nMode = UGQueryDef::FuzzyQuery);

	
	UGRecordset* QueryWithIDs(UGint *pIDs,UGint nCount,
		UGQueryDef::QueryOption nOptions = UGQueryDef::Both ,
		UGQueryDef::QueryMode nMode = UGQueryDef::GeneralQuery);
	
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
	//! \remarks 范围精确空间查询
	virtual UGbool SpatialQuery(UGGeoRegion *pGeo,
		UGArray<UGint> &aryInnerIDs,
		UGMaybeItems &aryMaybeIDs,
		UGArray<UGint> &aryOuterIDs,
		SpatialQueryOption nOption);

	
	//创建字段
	UGbool CreateFields(const UGFieldInfos &fieldInfos);	//创建字段集
	UGbool CreateField(const UGFieldInfo &fieldInfo);	//创建字段
	UGbool CreateField(const UGString &strName, UGFieldInfo::FieldType nType, 
		UGint lSize, UGint lAttributes = 0);	//创建字段
	
	//删除
	UGbool DeleteField(const UGString &strName);	//删除指定名字的字段
	UGbool DeleteField(UGint nIndex);	//删除指定序号的字段
	

	//字段信息
	UGint GetFieldCount();	//字段数
	UGbool GetFieldInfos(UGFieldInfos &fieldInfos,UGbool bSystemFieldExcluded = false/*,UGQueryDef::FIOptions fiOptions = UGQueryDef::fiCustom*/);	//收集所有字段的信息
	UGbool GetFieldInfo(const UGString &strName, UGFieldInfo &fieldInfo/*,UGQueryDef::FIOptions fiOptions = UGQueryDef::fiCustom*/);	//收集指定名字字段的信息
	UGbool GetFieldInfo(UGint nIndex, UGFieldInfo &fieldInfo/*,UGQueryDef::FIOptions fiOptions = UGQueryDef::fiCustom*/);			//收集指定序号字段的信息
	
	virtual UGbool SetFieldInfo(const UGString &strName, const UGFieldInfo &fieldInfo);		//设置字段信息，CDaoFieldInfo里定义的属性无法设置，只能在创建时候指定，其他的属性可以设定
	virtual UGbool SetFieldInfo(UGint nIndex, const UGFieldInfo &fieldInfo);				//设置第nIndex字段信息,同上
	virtual UGString GetFieldNameBySign(UGDatasetVector::FieldSign nSign);			//设置特殊字段标识	
	virtual UGbool SetFieldSign(const UGString& strFieldName,UGDatasetVector::FieldSign nSign);
	
	//统计字段值，根据字段类型，返回一个变量。nMode是统计类型。
	virtual UGVariant Statistic(const UGString& strField,UGStatisticMode nMode);
	//边界
	UGbool ComputeBounds();	//计算数据集Bounds

	//数据集选项，如时序数据集等。
	virtual UGbool RegisterOption(UGint dwOption);
	virtual UGbool UnRegisterOption(UGint dwOption);

	virtual UGbool IsSupport(UGEngAction dwEngAction);

	//注册/反注册时序数据集
	UGbool RegisterSequence();
	UGbool UnRegisterSequence();

public:
	virtual UGbool RefreshInfo();

	virtual UGRecordset* QueryWithLibTileID(UGint nLibTileID,
											UGArray<UGString> & arFields,
											UGdouble dGranule);

	//! 通过矩形范围查询图幅序号
	virtual UGbool GetLibTileIDs(const UGRect2D& rc2Bounds,
								 UGArray<UGint>& arLibTileIDs);

	//! 得到一个图幅的信息
	virtual UGbool GetLibTileInfo(UGint nTileID,UGRect2D& rc2TileBounds,
									UGint& nRecCount,UGint& nVersion);

	virtual UGbool CheckOut();
	virtual UGbool CheckIn(UGbool bKeepCheckedOut);
	virtual UGbool UndoCheckOut(UGbool bKeepCheckedOut);

	virtual UGbool UpdateField(const UGString& strFieldName,
		const UGVariant& varValue,const UGString& strFilter = "");

	//! 通过表达式更新字段值
	virtual UGbool UpdateFieldEx(const UGString& strFieldName,
		const UGString& strExpress,const UGString& strFilter = "");

	//! 复制字段值,strSrcField和
	//! strDestField必须都存在且字段类型匹配
	virtual UGbool CopyField(const UGString& strSrcField,const UGString& strDestField);

	//! R树操作函数
	virtual UGint LoadRTreeLeaf(UGint nID, UGStream &stream);
	virtual UGbool StoreRTreeLeaf(UGint nID,UGStream &stream);

	virtual UGbool HasGeometry() const;

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
	virtual UGbool Append(UGRecordset* pSrcRecordset, 
		UGbool bShowProgress = TRUE,UGString strTileName = "");

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
	virtual void SetFlag(UGint nOption,UGbool bHas);


	//! 判断字段名是否有效
	virtual UGbool IsAvailableFieldName(const UGString& strFieldName);

	//! 得到图库索引图的名字	
	virtual UGString GetMiniatureDtName();
	

	//! 获取数据集描述信息
	virtual UGString GetDescription() const;
	//! 设置数据集描述信息
	virtual void SetDescription(const UGString& strDesc);

public:  //根据父类的要求，实现动态分段需要的三个函数
	/*! \brief 删除动态事件
	 
	 *  \return 删除事件成功返回TRUE,有任何错误返回FALSE
	 *  \note  删除动态事件要做两件事：
	  1、从SmEventProperty表中删除相关纪录
	  2、从tabular事件表中删除几何对象字段.(如点事件删除smx,smy)
	 */
	UGbool DeleteEvent();

	/*! \brief 创建动态事件的几何对象,要求在子类中实现

	 *  \return 
	 *  \note  关键在于调用 
	         CGeoLineM::GetCoordinateAtM 得到动态点
	     和  CGeoLineM::GetSubCurveAtM  得到动态线

	 */
	UGbool BuildEventGeometry();

	/*! \brief 保存动态事件属性到数据库中

	 *  \return
	 *  \note  在子类中实现。把CSmEventProperty中的数据存储起来
	 共有11个数据
	 1、UGString	  m_strEventRouteIDFieldName; /// 事件表中RouteID字段名
	 2、EventType m_nEventType;			    /// 事件类型
	 3、UGString m_strFromMeasureFieldName; /// 线事件的起始Measure字段
	 4、UGString m_strToMeasureFieldName;   /// 线事件的终止Measure字段
	 5、UGString m_strMeasureFieldName;     /// 点事件的Measure
	 6、UGint m_nEventMeasureUnit;          /// Measure单位
	 7、UGString m_strEventTableName;
	 8、UGString m_strRouteDataSourceAlias; /// Route数据集所在的数据源别名
	 9、UGString m_strRouteDtName;		   /// Route数据集名称	 
	10、UGString m_strRouteIDFieldName;	   /// RouteID字段	 
	11、UGString m_strOffsetField;		   /// 数据定位偏移字段	
	 */
	UGbool SaveEvent();

protected: //call by buildeventgeometry;

	UGbool BuildPointEventGeometry();
	UGbool BuildLineEventGeometry();

protected:

	UGFolder  *m_pFolderDataset;		// 数据集的Folder
	CDaoTableDef *m_pTableDef;			// 数据集的属性数据的Table	

	UGFileLogical	*m_pFileInfo;			// 存放数据集信息,任何数据集都有
	UGFileLogical	*m_pFileMetadata;		// 存放数据集元数据,任何数据集都有
	UGFileLogical	*m_pFileGeometry;		// 存放空间数据,Tabular数据集无含义
	UGFileLogical	*m_pFileTree;			// 存放空间数据的R树索引以及Q树索引
	UGFileLogical	*m_pFileIndex;			// 存放空间数据的对象ID和位置的对应关系

	UGQTreeManager m_QTreeIndex;		// 四叉树索引
	//CSmRTree		m_RTreeIndex;		// R树索引
	UGRTree		m_RTreeIndex;			// R树索引

	UGbool m_bCached;				//是否已放入Cache的标志

	UGString m_strDescription;

protected:
	UGint m_nNextID;
	UGint m_nEncryptionKey[2];	//保留字

protected:  //对象ID和对象在Geometry文件中的位置对应表。

	UGint *m_pIndexTable;		// 数据库索引,具体结构为m_pIndexTable[xxx][2]
								// [0]存放记录ID,-1代表该记录已被删除;
								// [1]存放记录在Geometry文件中的位置;
	UGint m_nIndexAllCount;		// 索引的记录数,包括已被标志为删除的索引记录
	UGint m_nIndexValidCount;	// 索引的记录数,不包括已被标志为删除的索引记录

	void AddNewIDandPos(UGint& nID,UGint nGeoPos);  //新增加ID和Pos
	void GetIDandGeoPos(UGint nIndex,UGint& nID,UGint& nGeoPos); //得到ID和Pos
	UGint GetIDByIndex(UGint nIndex);				//根据nIndex得到ID
	void SetIDByIndex(UGint nIndex,UGint nID);	//设置ID
	UGint GetGeoPosByID(UGint nID);				//根据ID得到Pos
	void SetGeoPosByID(UGint nID,UGint nGeoPos);	//根据ID设置Pos
	UGint GetGeoPosByIndex(UGint nIndex);			//根据位置(nIndex)得到Pos
	void SetGeoPosByIndex(UGint nIndex,UGint nGeoPos); //根据index设置Pos
	void DeleteIDandPos(UGint nID);			//删除某个ID

	UGint IdToIndexPos(UGint nID);	//查找ID对应的记录在Dataset索引中的序号

protected:

	//field info of all table.
	///	\brief	add new record of fieldinfo
	UGbool InsertField(const UGString& strTable,const UGString& strFieldName,const UGString& strCaption);
	UGbool InsertField(const UGFieldInfo& fieldInfo);
	/// \brief delete a record of fieldinfo
	UGbool DeleteField(const UGString& strTable,const UGString& strFieldName);
	/// \brief get field's info,such as caption, domain,updatable
	UGbool GetFieldInfo(const UGString& strTable,const UGString& strFieldName,UGFieldInfo& fieldInfo);
	UGbool GetFieldCaption(const UGString& strTable,const UGString& strFieldName,UGString& strCaption);
	/// \brief alter field info.
	UGbool SetFieldCaption(const UGString& strTable,const UGString& strFieldName,UGFieldInfo& fieldInfo);
	UGbool SetFieldCaption(const UGString& strTable,const UGString& strFieldName,const UGString& strCaption);
	
protected:
	//元数据描述管理
	UGint GetMetadataDescCount();	//返回元数据描述个数
	UGbool GetMetadataDesc(UGint nIndex, UGString &strTitle, UGString &strContent);	//返回元数据描述
	UGint AddMetadataDesc(UGString strTitle, UGString strContent);	//追加元数据描述字符串在已有的元数据描述字符串后面，返回添加到的位置
	void ClearMetadataDesc();				//清除原有的元数据描述
	UGbool DeleteMetadataDesc(UGint nIndex);	//删除指定的元数据描述

protected:	//method
	
	//strName		Dataset名字
	//nType			Dataste类型
	//nOptions		Dataste Options,参见SmDatasource.h
	//dwStgmOpt		storage and stream create mode
	//stgDataset	父Storage,普通数据集是m_stgDatasets,Node和TINVertex数据集是当前m_stgDataset
	//pDatasetParent父数据集,普通数据集是NULL,Node和TINVertex数据集是当前数据集
	//5.0新增，坐标存储模式，目前支持encNone,encWORD,encDWORD
	UGbool Create(UGString strName, UGDataset::DatasetType nType,UGint nOptions,
				UGFolder *stgDataset,
				UGSdbPlusDatasetVector *pDatasetParent,
				UGDataCodec::CodecType nEncType=UGDataCodec::encNONE);
	

	//stgDataset	父Storage,普通数据集是m_stgDatasets,Node和TINVertex数据集是当前m_stgDataset
	//bCached		Cache标志
	UGbool OpenEx(UGFolder *stgDataset,UGbool bCached);	//打开数据集
	
	UGbool IsValidDataset();	//判断是否合法Dataset

	//以下函数提供给Spatial Index使用
	UGbool InitialSpatialIndex();	//初始化Spatial Index
	UGbool SaveSpatialIndex();	//Save Spatial Index to m_stmIndex
	UGbool LoadSpatialIndex();	//Load Spatial Index from m_stmIndex

	void Encrypt(UGString& strPassword);		//数据加密
	
	//修复坏掉的数据
	UGbool RepairEx(UGint& nGeometryCount,UGint& nRecordCount);	//检查空间数据与属性数据是否一一对应，并且删除缺失空间数据的属性数据，缺失属性数据的空间数据则补上。
	UGbool Repair();					//空间数据与属性数据不一致是的修复,调用修复之前,数据集名，datasetinfo,stgDataset等已经打开。
	UGbool RepairNoProperty();		//属性表丢失后的修复。
	
	/*
	//UGString strFileName,	得到的文本文件的路径和名字
	//UGint &nDatasetN,			//要向SQL Server数据集设置的空间信息
	//UGString strTerminate = "--$"		//用以间隔字节段的间隔符
	UGbool Export2Txt(UGString strFileName,double &dGridSize,		
					UGint &nDatasetW,	UGint &nDatasetN,UGint &nDatasetE,UGint &nDatasetS,
					UGString strTerminate = "--$");	

	UGbool ExportSqlPlusText(UGString strFileName,UGint & nRecordCount,
							UGRect2D &rc2Bounds,	UGString strTerminate = "--$");
	
	UGbool ExportSybaseText(UGString strFileName,UGint & nRecordCount,
						UGRect2D &rc2Bounds,UGString strTerminate = "--$");
	*/

	static UGbool InitVariant(COleVariant& var,short nType);

};

}
#endif // !defined(AFX_SDBDATASET49_H__017098AB_099E_11D3_92D2_0080C8EE62D1__INCLUDED_)
