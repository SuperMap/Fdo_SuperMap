/*! \file	 UGUdbDatasetVector.h
*  \brief	 Oracle Plus DatasetVector
*  \author	 ugc team
*  \attention 
*  Copyright(c) 1996-2004 SuperMap GIS Technologies,Inc.<br>
*  All Rights Reserved
*/


#ifndef UGUdbDatasetVector_H
#define UGUdbDatasetVector_H

#include "Base/ugdefs.h"	// Added by ClassView
#include "Engine/UGDatasetVector.h"
#include "Engine/UGDBRTree.h"
#include "Base/UGProgress.h"
#include "Base/UGFileStream.h"

namespace UGC{
	
	class UDBENGINE_API UGUdbDatasetVector  :public UGDatasetVector
	{
		friend class UGUdbRecordset;
		friend class UGUdbEditRecordset;
		friend class UGUdbSpatialIndex;
	public:
		UGUdbDatasetVector();
		
		UGUdbDatasetVector(UGDataSource *pDataSource);
		
		virtual ~UGUdbDatasetVector();
		
		//!基类中定义的纯虚函数
		
		//! \brief 打开数据集。
		//! \return 打开成功返回TRUE,失败返回FALSE。
		//! \remarks 。
		//! \attention 。
		virtual UGbool Open();
		
		//! \brief 关闭数据集。
		//! \remarks 。
		//! \attention 。
		virtual void Close();
		
		//! \brief 保存数据集信息。
		//! \return 保存成功返回TRUE,失败返回FALSE。
		//! \remarks 。
		//! \attention 。
		virtual UGbool SaveInfo();
		
		//! \brief 刷新数据集信息。
		//! \return 保存成功返回TRUE,失败返回FALSE。
		//! \remarks 。
		//! \attention 。
		virtual UGbool RefreshInfo();
		
		//! \brief 设置数据集的范围。
		//! \param r 数据集的范围[in]。
		//! \remarks 。
		//! \attention 。
		virtual void SetBounds(const UGRect2D& r);
		
		//! \brief 创建数据集。
		//! \param strName 数据集名[in]。
		//! \param *pDatasetParent 数据集所属数据源的指针[in]。
		//! \param vInfo 失量数据集对象[in]。
		//! \return 创建成功返回TRUE,失败返回FALSE。
		//! \remarks 。
		//! \attention 。
		UGbool Create(const UGString & strName, 
			UGUdbDatasetVector *pDatasetParent,
			const UGDatasetVectorInfo & vInfo);

		//! \brief 从WFS的GetFeature XML文件创建数据集。
		//! \param strXMLPath GetFeature XML文件地址[in]。
		//! \return 创建成功返回TRUE,失败返回FALSE。
		//! \remarks 。
		//! \attention 。
	 	UGbool Create(UGString strXMLPath);
		
		//! \brief 得到最后更新时间。
		//! \return 最后更新时间。
		//! \remarks 。
		//! \attention 。
		virtual UGTime GetDateLastUpdated();
		
		//! \brief 得到创建时间。
		//! \return 创建时间。
		//! \remarks 。
		//! \attention 。
		virtual UGTime GetDateCreated();
		
		
		//! \brief 数据集重命名。
		//! \param strNewName [in]。
		//! \return 重命名成功返回TRUE,失败返回FALSE。
		//! \remarks 只改变数据集名,表名不变。
		//! \attention 。
		virtual UGbool Rename(const UGString& strNewName);		
		
		//! \brief 查询大表图库中一个图幅的数据
		//! \param nLibTileID 图幅号[in]。
		//! \param arFields 字段名集合[in]。
		//! \return 记录集指针。
		//! \remarks 。
		//! \attention 。
		virtual UGRecordset* QueryWithLibTileID(UGint nLibTileID,
			UGArray<UGString> & arFields,UGdouble dGranule);
		
		//! \brief 。
		//! \param rc2SearchBounds [in]。
		//! \param strLibTile [in]。
		//! \return 。
		//! \remarks 。
		//! \attention 。
		UGbool GetLibTileSQL(const UGRect2D& rc2SearchBounds,
			UGString& strLibTile);
		
		//! \brief 通过矩形范围查询图幅序号。
		//! \param rc2Bounds 数据集的范围[in]。
		//! \param arLibTileIDs [in]。
		//! \return 。
		//! \remarks 。
		//! \attention 。
		virtual UGbool GetLibTileIDs(const UGRect2D& rc2Bounds,
			UGArray<UGint>& arLibTileIDs);
		
		//! \brief 得到一个图幅的信息。
		//! \param nTileID 图幅号[in]。
		//! \param rc2TileBounds 数据集的范围[in]。
		//! \param nRecCount [in]。
		//! \param nVersion [in]。
		//! \return 。
		//! \remarks 。
		//! \attention 。
		virtual UGbool GetLibTileInfo(UGint nTileID,UGRect2D& rc2TileBounds,
			UGint& nRecCount,UGint& nVersion);
		
		
		//! \brief 长事务处理函数,签出。
		//! \return 操作成功返回TRUE,失败返回FALSE。
		//! \remarks 。
		//! \attention 。
		virtual UGbool CheckOut();
		
		//! \brief 长事务处理函数,签入。
		//! \param bKeepCheckedOut [in]。
		//! \return 操作成功返回TRUE,失败返回FALSE。
		//! \remarks 。
		//! \attention 。
		virtual UGbool CheckIn(UGbool bKeepCheckedOut);
		
		//! \brief 长事务处理函数,撤销签出。
		//! \param bKeepCheckedOut [in]。
		//! \return 操作成功返回TRUE,失败返回FALSE。
		//! \remarks 。
		//! \attention 。
		virtual UGbool UndoCheckOut(UGbool bKeepCheckedOut);
		
		//! \brief 得到被锁定用户的ID。
		//! \return 被锁定用户的ID。
		//! \remarks 。
		//! \attention 。
		UGint GetLockedUserID();
		
		//! \brief 得到签出用户的ID。
		//! \return 签出用户的ID。
		//! \remarks 。
		//! \attention 。
		UGint GetCheckedUserID();
		
		
		//! \brief 通过传值方法更新字段值。
		//! \param strFieldName 要更新的字段名。
		//! \param varValue 要更新的字段值。
		//! \param strFilter 过滤条件Where Info 不带"Where 关键字"。
		//! \return 更新成功返回TRUE,失败返回FALSE 。
		//! \remarks 。
		//! \attention 。
		virtual UGbool UpdateField(const UGString& strFieldName,
			const UGVariant& varValue,const UGString& strFilter = "");
		
		//! \brief 通过表达式更新字段值。
		//! \param strFieldName 准备更新的字段名。
		//! \param strExpress 准备更新的字段值。
		//! \param strFilter  过滤条件Where Info 不带"Where 关键字",默认为空。
		//! \return 更新成功返回TRUE,失败返回FALSE 。
		//! \remarks 。
		//! \attention 。
		virtual UGbool UpdateFieldEx(const UGString& strFieldName,
			const UGString& strExpress,const UGString& strFilter = "");
		
		
		//! \brief 复制字段值。
		//! \param strSrcField 源字段名[in]。
		//! \param strDestField 目的字段名[in]。
		//! \return 复制成功返回TRUE,失败返回FALSE。
		//! \remarks 。
		//! \attention 。
		virtual UGbool CopyField(const UGString& strSrcField,
			const UGString& strDestField);
		
		
		//! \brief 建普通索引。
		//! \param strFieldNameList 索引字段列表,多字段需要用 "," 隔开,例如 fld1,fld2,fld3[in]。
		//! \param strIndexName 索引名[in]。
		//! \return 建立索引成功返回TRUE,失败返回FALSE。
		//! \remarks 。
		//! \attention 。
		virtual UGbool CreateIndex(const UGString& strFieldNameList,
			const UGString& strIndexName);
		
		//! \brief 删除索引 。
		//! \param strIndexName 索引名[in]。
		//! \return 删除索引成功返回TRUE,失败返回FALSE。
		//! \remarks 。
		//! \attention 。
		virtual UGbool DropIndex(const UGString& strIndexName);
		
		//! \brief R树操作函数,加载叶节点。
		//! \param nID 叶节点ID[in]。
		//! \param &stream 叶节点数据包[in]。
		//! \return 包的大小。
		//! \remarks 。
		//! \attention 。
		virtual UGint LoadRTreeLeaf(UGint nID,UGStream &stream);
		
		//! \brief R树操作函数,存储叶节点。
		//! \param nID 叶节点ID[in]。
		//! \param &stream 叶节点数据包[in]。
		//! \return 存储成功返回TRUE,失败返回FALSE。
		//! \remarks 。
		//! \attention 。
		virtual UGbool StoreRTreeLeaf(UGint nID,UGStream &stream);
				

		//! \brief 。
		//! \param SearchBounds [in]。
		//! \param aryItemIDs [in]。
		//! \param aryCertainLeafIDs [in]。
		//! \param &aryCertainBounds [in]。
		//! \param aryMaybeLeafIDs [in]。
		//! \param &aryMaybeBounds [in]。
		//! \param bFuzzy [in]。
		//! \param dGranule [in]。
		//! \return 。
		//! \remarks 。
		//! \attention 。
			virtual UGbool ExtractLeafData(const UGRectUInt& SearchBounds, 
			UGArray<UGint>& aryItemIDs, 
			UGArray<UGint>& aryCertainLeafIDs,
			UGArray<UGRectUInt> &aryCertainBounds,
			UGArray<UGint>& aryMaybeLeafIDs,
			UGArray<UGRectUInt> &aryMaybeBounds,
			UGbool bFuzzy,
			UGdouble dGranule);
		
		//! \brief 得到空间数据列的字段名。
		//! \return 空间数据列的字段名。
		//! \remarks 。
		//! \attention 。
		virtual UGString GetGeoColName() const;
		
		//! \brief 是否有几何数据。
		//! \return 有几何数据返回TRUE,没有返回FALSE。
		//! \remarks 除了Tablur数据集，都有几何数据。
		//! \attention 。
		virtual UGbool HasGeometry() const;
		
		//! \brief 查询通用入口。
		//! \param querydef 查询定义对象[in]。
		//! \return UGRecordset 记录集指针。
		//! \remarks 。
		//! \attention 。
		virtual UGRecordset* Query(const UGQueryDef& querydef);
		
		//! \brief 创建多个字段。
		//! \param fieldInfos 字段信息集合[in]。
		//! \return 创建成功返回TRUE,失败返回FALSE。
		//! \remarks 。
		//! \attention 。
		virtual UGbool CreateFields(const UGFieldInfos& fieldInfos);
		
		//! \brief 通过FieldInfo创建字段。
		//! \param fieldInfo 字段信息[in]。
		//! \return 创建成功返回TRUE,失败返回FALSE。
		//! \remarks 。
		//! \attention 。
		virtual UGbool CreateField(const UGFieldInfo& fieldInfo);
		
		//! \brief 创建字段。
		//! \param strName 字段名称[in]。
		//! \param nType 字段类型[in]。
		//! \param nSize 字段长度(字节)[in]。
		//! \param nAttributes 字段属性[in]。
		//! \return 创建成功返回TRUE,失败返回FALSE。
		//! \remarks 。
		//! \attention 。
		virtual UGbool CreateField(const UGString& strName,UGFieldInfo::FieldType nType,
			UGint nSize,UGint nAttributes = 0);
		
		//! \brief 通过字段名称删除字段。
		//! \param strName 字段名称[in]。
		//! \return 删除成功返回TRUE,失败返回FALSE。
		//! \remarks 。
		//! \attention 。
		virtual UGbool DeleteField(const UGString& strName);
		
		//! \brief 通过索引号删除字段。
		//! \param nIndex 索引号[in]。
		//! \return 删除成功返回TRUE,失败返回FALSE。
		//! \remarks 。
		//! \attention 。
		virtual UGbool DeleteField(UGint nIndex);
		
		//! \brief 收集所有字段的信息。
		//! \param fieldInfos 字段信息集合[in]。
		//! \param bSystemFieldExcluded 是否把系统字段排除在外[in]。
		//! \return 操作成功返回TRUE,失败返回FALSE。
		//! \remarks 。
		//! \attention 。
		virtual UGbool GetFieldInfos(UGFieldInfos& fieldInfos,
			UGbool bSystemFieldExcluded = FALSE);
		
		//! \brief 通过字段名获取字段信息。
		//! \param strName 字段名称[in]。
		//! \param fieldInfo 字段信息[in]。
		//! \return 操作成功返回TRUE,失败返回FALSE。
		//! \remarks 。
		//! \attention 。
		virtual UGbool GetFieldInfo(const UGString& strName,
			UGFieldInfo& fieldInfo);
		
		//! \brief 通过索引获取字段信息。
		//! \param nIndex 索引号[in]。
		//! \param fieldInfo 字段信息[in]。
		//! \return 操作成功返回TRUE,失败返回FALSE。
		//! \remarks 。
		//! \attention 。
		virtual UGbool GetFieldInfo(UGint nIndex,
			UGFieldInfo& fieldInfo);
		
		//! \brief 通过字段名设置字段信息。
		//! \param strName 字段名[in]。
		//! \param fieldInfo 字段信息[in]。
		//! \return 操作成功返回TRUE,失败返回FALSE。
		//! \remarks 。
		//! \attention 。
		virtual UGbool SetFieldInfo(const UGString& strName,
			const UGFieldInfo& fieldInfo);
		
		//! \brief 通过索引设置字段信息。
		//! \param nIndex 索引号[in]。
		//! \param fieldInfo 字段信息[in]。
		//! \return 操作成功返回TRUE,失败返回FALSE。
		//! \remarks 。
		//! \attention 。
		virtual UGbool SetFieldInfo(UGint nIndex,
			const UGFieldInfo& fieldInfo);
		
		//! \brief 获取字段个数。
		//! \return 字段个数。
		//! \remarks 。
		//! \attention 。
		virtual UGint GetFieldCount();
		
		//! \brief 删除表中所有数据。
		//! \return 删除成功返回TRUE,失败返回FALSE。
		//! \remarks 。
		//! \attention 。
		virtual UGbool Truncate();
		
		//! \brief 统计字段值。
		//! \param strField 要统计的字段[in]。
		//! \param nMode 统计方式[in]。
		//! \return 统计结果,非UGStatisticMode统计方式返回0。
		//! \remarks 非UGStatisticMode统计方式返回0。
		//! \attention 。
		virtual UGVariant Statistic(const UGString& strField,
			UGStatisticMode nMode);
		
		//! \brief 计算字段单值个数。
		//! \param &strFieldName 字段名[in]。
		//! \param varKeys 不同单值的集合[out]。
		//! \return 操作成功返回0,失败返回负数。
		//! \remarks 。
		//! \attention 。
		virtual UGint CalculateUniqueValues(const UGString &strFieldName,
			UGArray<UGVariant>& varKeys);
		
		//! \brief 真正的SQL查询记录个数,更新Register表。
		//! \return 成功更新Register表返回TRUE,失败返回FALSE。
		//! \remarks 。
		//! \attention 。
		virtual UGbool ComputeRecCount();
		
		//! \brief 获取最大空间对象的字节大小。
		//! \return 最大空间对象的字节大小。
		//! \remarks 。
		//! \attention 。
		virtual UGint GetMaxGeoSize();
		
		//! \brief 设置最大空间对象的字节大小。
		//! \param nMaxGeoSize 最大空间对象的字节大小[in]。
		//! \return 设置成功返回TRUE,失败返回FALSE。
		//! \remarks 。
		//! \attention 。
		virtual UGbool SetMaxGeoSize(UGint nMaxGeoSize);
		
		//! \brief 得到时序数据的注册时间。
		//! \return 时序数据的注册时间。
		//! \remarks 。
		//! \attention 。
		virtual UGTime GetRegistSequenceTime();
		
		//! \brief 得到时序数据的最新更新时间。
		//! \return 时序数据的最新更新时间。
		//! \remarks 。
		//! \attention 。
		virtual UGTime GetLUSequenceTime();
		
		//! \brief 通过ID数组删除数据集中的记录。
		//! \param pIDs ID数组指针[in]。
		//! \param nCount 要删除的记录数必须与ID数组的个数相等[in]。
		//! \return 删除成功返回TRUE,失败返回FALSE。
		//! \remarks 。
		//! \attention 。
		virtual UGbool DeleteRecords(const UGint* pIDs,UGint nCount);
		
		//! \brief 追加记录。
		//! \param pSrcRecordset 源数据集[in]。
		//! \param bShowProgress  是否显示进度条，默认显示[in]。
		//! \param strTileName 图幅名称,默认为空[in]。
		//! \return 追加记录成功返回TRUE,失败返回FALSE。
		//! \remarks 。
		//! \attention 。
		virtual UGbool Append(UGRecordset* pSrcRecordset,UGbool bShowProgress = TRUE,UGString strTileName = "");
		

		//! \brief 重采样，仅对线数据集有效。
		//! \param dTolerance [in]。
		//! \param bShowProgress 是否显示进度条，默认显示[in]。
		//! \return 重采样成功返回TRUE,失败返回FALSE。
		//! \remarks 。
		//! \attention 。
		virtual UGbool Resample(UGdouble dTolerance,
			UGbool bShowProgress=TRUE);	
		
		//! \brief 得到记录集个数。
		//! \return 记录集个数。
		//! \remarks 。
		//! \attention 。
		virtual UGint GetRecordsetCount();
		
		//! \brief 返回指定索引的数据集指针。
		//! \param nIndex 索引号[in]。
		//! \return 数据集指针。
		//! \remarks 。
		//! \attention 。
		virtual UGRecordset* GetRecordsetAt(UGint nIndex);
		
		//! \brief 通过索引释放记录集。
		//! \param nIndex 索引号[in]。
		//! \return 释放成功返回TRUE,失败返回FALSE。
		//! \remarks 。
		//! \attention 。
		virtual UGbool ReleaseRecordset(UGint nIndex);
		
		//! \brief 通过引用释放记录集。
		//! \param pRecordset 数据集指针in]。
		//! \return 释放成功返回TRUE,失败返回FALSE。
		//! \remarks 。
		//! \attention 。
		virtual UGbool ReleaseRecordset(UGRecordset *pRecordset);
		
		//! \brief 设置是否每个对象有自己的风格。
		//! \param nOption [in]。
		//! \param bHas 是否每有自己的风格[in]。
		//! \remarks 。
		//! \attention 。
		virtual void SetFlag(UGint nOption,UGbool bHas);
		
		//! \brief 判断字段名是否有效。
		//! \param strFieldName [in]。
		//! \return 有效返回TRUE,无效返回FALSE。
		//! \remarks 。
		//! \attention 。
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

protected:
		//! \brief 建立空间索引
		//! \param nType 空间索引类型，默认没有IdxNone [in]。
		//! \param bShowProgressCtrl 是否显示进程条,默认显示[in]。
		//! \return 建立索引成功返回TRUE,失败返回FALSE。
		//! \remarks
		//! \attention 。
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

		//! \brief 清除空间索引。
		//! \return 清除索引成功返回TRUE,失败返回FALSE。
		//! \remarks 。
		//! \attention 。
		virtual UGbool DropSpatialIndex();
		
		//! \brief 是否需要重建空间索引。
		//! \return 需要重建返回TRUE,不需要返回FALSE。
		//! \remarks 根据空间索引脏的记录的数目判断。
		//! \attention 。
		virtual UGbool IsSpatialIndexDirty();

		//! \brief 对数据的空间索引进行统计分析。
		//! \param pDs 数据源指针[in]。
		//! \return 是否成功统计,成功返回顾TRUE,否则返回FALSE。
		virtual UGbool StatisticIndex(UGDataSource *pDs);

		//! \brief 返回空间索引脏的记录的数目，为是否需要重建空间索引提供参考。
		//! \return 空间索引脏的记录的数目。
		//! \remarks 。
		//! \attention 。
		virtual UGint GetDirtyRecordCount();

public:
	/// \brief 从数据库中读取当前数据集的Bounds信息
	/// \remarks 此函数与CDatasetVector::GetBounds有所区别，此函数是从数据库中读取，得到的是最新的Bounds，而后者是直接从内存中读取m_DatasetInfo中存储的Bounds信息，速度要快得多
	/// \sa	CDatasetVector::GetBounds
	UGRect2D GetBoundsDirectly();
	
	UGbool RegisterUser(UGint nLogID,UGbool bRecordsetLevel = FALSE);
	
	void CheckError() const;
	
	UGbool CanTransact();
		
	UGbool GetCacheFile(UGString &strFileName,UGint nLibTileID);
	
	UGbool QueryFieldInfos();
	
	UGString CheckFieldName(UGString strFieldName);

private:
	/// \brief 刷新当前数据集的选项信息
	/// \sa RegisterOption, UnRegisterOption, CSmDataset::GetOptions
	UGbool RefreshOption();
	
	
	
public:
	UGFieldInfos m_fieldInfos;
	UGDBRTree * m_pRTreeIndex;

private:
	UGint m_nMyOption;
	UGint m_nState;
	UGFileStream m_IndexFile;

	UGMutex m_mutex;
	UGMutex m_nOpenmutex;
};

}
#endif // !defined(UGUdbDatasetVector_H)
