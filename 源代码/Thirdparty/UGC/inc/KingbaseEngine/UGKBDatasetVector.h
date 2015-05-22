// UGKBDatasetVector.h: interface for the UGKBDatasetVector class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGKBDATASETVECTOR_H__B2B86846_9214_4073_913E_83E38464F64A__INCLUDED_)
#define AFX_UGKBDATASETVECTOR_H__B2B86846_9214_4073_913E_83E38464F64A__INCLUDED_

#include "ODBCEngine/UGODBCDatasetVector.h"
#include "Engine/UGFieldInfo.h"
namespace UGC
{

class KINGENGINE_API UGKBDatasetVector  : public UGODBCDatasetVector
{
public:
	UGKBDatasetVector();
	UGKBDatasetVector(UGDataSource *pDataSource);
	virtual ~UGKBDatasetVector();

public:
	//! 打开数据集
	virtual UGbool Open();

	//! 数据集重命名,只改变数据集名,表名不变
	virtual UGbool Rename(const UGString& strNewName);

	//! 查询大表图库中一个图幅的数据
	virtual UGRecordset* QueryWithLibTileID(UGint nLibTileID,
		UGArray<UGString> & arFields,UGdouble dGranule);

	//! 通过矩形范围查询图幅序号
	virtual UGbool GetLibTileIDs(const UGRect2D& rc2Bounds,
		UGArray<UGint>& arLibTileIDs);

	//! 得到一个图幅的信息
	virtual UGbool GetLibTileInfo(UGint nTileID,UGRect2D& rc2TileBounds,
		UGint& nRecCount,UGint& nVersion);

	//! 查询通用入口
	virtual UGRecordset* Query(const UGQueryDef& querydef);

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

	//!创建数据集
	UGbool Create(const UGString & strName, 
		UGKBDatasetVector *pDatasetParent,
		const UGDatasetVectorInfo & vInfo);

	//! 返回最后更新时间
	virtual UGTime GetDateLastUpdated();

	//! 追加记录
	virtual UGbool Append(UGRecordset* pSrcRecordset, 
		UGbool bShowProgress = TRUE,UGString strTileName = "");

	//! brief  建普通索引
	virtual UGbool CreateIndex(const UGString& strFieldNameList,
		const UGString& strIndexName);

	virtual UGint GetNewID();
protected:
	virtual UGbool QueryFieldInfos();
	UGbool  RefreshMemDT();

};

}
#endif // !defined(AFX_UGKBDATASETVECTOR_H__B2B86846_9214_4073_913E_83E38464F64A__INCLUDED_)
