// UGSqlDatasetVector.h: interface for the UGSqlDatasetVector class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGSqlDATASETVECTOR_H__B2B86846_9214_4073_913E_83E38464F64A__INCLUDED_)
#define AFX_UGSqlDATASETVECTOR_H__B2B86846_9214_4073_913E_83E38464F64A__INCLUDED_

#include "ODBCEngine/UGODBCDatasetVector.h"
#include "Engine/UGFieldInfo.h"
namespace UGC
{

class SQLENGINE_API UGSqlDatasetVector  : public UGODBCDatasetVector
{
public:
	UGSqlDatasetVector();
	UGSqlDatasetVector(UGDataSource *pDataSource);
	virtual ~UGSqlDatasetVector();

public:
	//! \brief 打开数据集
	virtual UGbool Open();

	//! \brief 查询大表图库中一个图幅的数据
	virtual UGRecordset* QueryWithLibTileID(UGint nLibTileID,
		UGArray<UGString> & arFields,UGdouble dGranule);

	//! \brief 通过矩形范围查询图幅序号
	virtual UGbool GetLibTileIDs(const UGRect2D& rc2Bounds,
		UGArray<UGint>& arLibTileIDs);

	//! \brief 得到一个图幅的信息
	virtual UGbool GetLibTileInfo(UGint nTileID,UGRect2D& rc2TileBounds,
		UGint& nRecCount,UGint& nVersion);

	//! \brief 通过类别获取字段名
	virtual UGString GetFieldNameBySign(FieldSign nSign);

	//! \brief 设置字段的类别
	virtual UGbool SetFieldSign(const UGString& strFieldName,FieldSign nSign);

	//! \brief 查询通用入口
	virtual UGRecordset* Query(const UGQueryDef& querydef);

	//! \brief 关联表查询
	virtual UGRecordset* Query2(UGLinkItem &linkitem);

	//! \brief 通过Bounds查询
	// param  rc2Bounds 查询范围[in]
	// param  nOptions	查询选项[in]
	// param  nMode　　 查询模式[in]
	virtual UGRecordset* QueryWithBounds(const UGRect2D &rc2Bounds,
		UGQueryDef::QueryOption nOptions = UGQueryDef::Geometry,
		UGQueryDef::QueryMode nMode = UGQueryDef::FuzzyQuery);

	//! \brief 通过IDs查询
	// param  pIDs	 查询IDs数组[in]
	// param  nCount	查询数目[in]
	// param  nOptions	查询选项[in]
	// param  nMode　　 查询模式[in]
	virtual UGRecordset* QueryWithIDs(UGint *pIDs,UGint nCount,
		UGQueryDef::QueryOption nOptions = UGQueryDef::Both ,
		UGQueryDef::QueryMode nMode = UGQueryDef::GeneralQuery);

	//! \brief 创建多个字段
	// param  fieldInfos 字段信息数组[in]
	virtual UGbool CreateFields(const UGFieldInfos& fieldInfos);
	
	//! \brief 通过FieldInfo创建字段
	// param  fieldInfo 字段信息[in]
	virtual UGbool CreateField(const UGFieldInfo& fieldInfo);

	//! \brief 创建字段
	// param  strName	字段名[in]
	// param  nType		查询类型[in]
	// param  nSize		字段大小[in]
	// param  nAttributes [in]
	virtual UGbool CreateField(const UGString& strName,UGFieldInfo::FieldType nType,
		UGint nSize,UGint nAttributes = 0);

	//! \brief 通过字段名称删除字段
	virtual UGbool DeleteField(const UGString& strName);

	//! \brief 通过索引号删除字段
	virtual UGbool DeleteField(UGint nIndex);

	//! \brief 注册选项信息
	virtual UGbool RegisterOption(UGint nOption);

	//! \brief 注销选项信息
	virtual UGbool UnRegisterOption(UGint nOption);

	//! \brief 创建数据集
	UGbool Create(const UGString & strName,
		UGDataset *pDatasetParent,
		const UGDatasetVectorInfo & vInfo);

	//! \brief 返回最后更新时间
	virtual UGTime GetDateLastUpdated();

	//! \brief 返回正确的ID
	virtual UGint GetNewID();

	//! \brief 数据集追加
	// param pSrcRecordset 源数据集[in]
	// param bShowProgress　是否显示进程条[in]
	// param strTileName 处理索引[in]
	virtual UGbool Append(UGRecordset* pSrcRecordset, 
		UGbool bShowProgress = TRUE,UGString strTileName = "");

	//! \brief 读取字段信息
	virtual UGbool QueryFieldInfos();


	//! \brief 版本提交管理
	// param　strVersion　		版本
	// param　nPostOption		冲突解决方式
	// param　CheckConfilcts	记录发生的冲突
	virtual UGbool PostToMainVersion(UGString strVersion,
					UGPostOption nPostOption,
					UGArray<UGCheckConflict> &CheckConfilcts);	

	//! \brief 版本提交管理
	// param　strVersion　		版本号
	// param　nPostOption		冲突解决方式
	// param　CheckConfilcts	记录发生的冲突
	virtual UGbool PostToMainVersion(UGint nVersionID,
					UGPostOption nPostOption,
					UGArray<UGCheckConflict> &CheckConfilcts);

	//! \brief 版本提交管理
	// param　strVersion　		版本
	virtual UGbool PostToMainVersion(UGint nVersionID,
					UGint nDataID,
					UGPostOption nPostOption);


	//! \brief 版本回滚
	// param　strVersion　		版本号
	virtual UGbool RollBackVersion(UGint nVersion);

	//! \brief 版本管理相关方法
	//! \brief 数据源删除版本时调用
	UGbool U_DeleteVersion(UGint nVersionID);

	//! \brief 刷新数据集信息
	void U_RefreshExtInfo(UGint nDataVersionID);

protected:
	//! \brief 如果参与了topo 可以获得topo数据集指针
	virtual UGDataset * GetTopoAdscriptionDT();
	virtual UGbool CreateSubDataset(UGDatasetVectorInfo &vInfo);
	virtual UGbool DeleteSubDataset(UGString &strName);

public:
	friend class UGSqlDatasource;
};

}
#endif // !defined(AFX_UGSqlDATASETVECTOR_H__B2B86846_9214_4073_913E_83E38464F64A__INCLUDED_)
