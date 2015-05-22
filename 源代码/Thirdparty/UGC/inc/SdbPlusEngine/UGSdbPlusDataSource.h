// SmDataSource.h: interface for the UGSdbPlusDataSource class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SDBDATASOURCEPlus_H__F53EF3A0_08FE_11D3_92D1_0080C8EE62D1__INCLUDED_)
#define AFX_SDBDATASOURCEPlus_H__F53EF3A0_08FE_11D3_92D1_0080C8EE62D1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Base/UGTime.h"
#include "CompoundFile/UGFileLogical.h"
#include "CompoundFile/UGFolder.h"
#include "CompoundFile/UGStorehouse.h"
#include "Engine/UGDataSource.h"

#include "UGSdbDataSourceInfo.h"
#include "UGSdbPlusDatasetVector.h"
#include "UGSdbPlusRecordset.h"


namespace UGC{

class UGSdbPlusDatasetRaster;
class UGSdbPlusDatasetVector;


class SDBPLUSENGINE_API UGSdbPlusDataSource : public UGDataSource  
{
	friend class UGSdbPlusDatasetVector;
	friend class UGSdbPlusDatasetRaster;
	friend class UGSdbPlusRecordset;

public://constructors
	UGSdbPlusDataSource();
	virtual ~UGSdbPlusDataSource();

public:	

	//数据源创建、打开、关闭
	//! 创建数据源,需要预先设置好连接信息
	UGbool Create();

	//! 打开数据源,需要预先设置好连接信息
	virtual UGbool Open();

	//! 关闭数据源
	virtual void Close();

	/*
	UGbool Create(const UGString &strDataSourceName, UGuint dwOptions = smdsExclusive, const UGString& strPassword = (""));	//for more information about "dwOptions", see above...
	UGbool Open(const UGString &strDataSourceName, UGuint dwOptions = smdsExclusive, const UGString& strPassword = (""));	//for more information about "dwOptions", see above...
	UGbool Open(const UGString &strDataSourceName,
				UGbool bReadOnly = FALSE,
				UGbool bExclusive = TRUE,
				UGbool bTransacted = FALSE,
				UGbool bEncrypt = FALSE,
				const UGString& strPassword = (""));

	virtual UGbool Open(UGDsConnection *pDsConnection = NULL);

	void Close();
	*/

	UGbool SaveInfo();

	//数据源属性
	UGString GetEngineName();			//引擎名称，请使用字符串资源
	UGTime GetDateLastUpdated() const;	//返回最后更新时间
	UGTime GetDateCreated() const;		//返回创建时间

	//! 执行SQL语句，主要用于在数据库级执行的数据操作
	UGbool Execute(const UGString& strSQL);

	UGDatasetVector* CreateDatasetVector(const UGDatasetVectorInfo& vInfo);

	UGDatasetTopo* CreateDatasetTopo(UGString strName);

	//生成栅格图层
	UGDatasetRaster* CreateDatasetRaster(const UGDatasetRasterInfo& rInfo);

	//数据集删除
	UGbool DeleteDataset(const UGString& strName);

/*	//元数据描述管理
	UGString GetDescription();									//返回元数据描述
	void ResetDescription();									//清除原有的元数据描述
	void SetDescription(UGString &strDesc);			//追加元数据描述字符串在已有的元数据描述字符串后面
*/

	//事务递交和撤销,SDB5.0先不提供事务处理功能。
	UGbool BeginTrans();		
	void Commit();
	void Rollback();

	/// \brief Is the file a SDB 5.0 File?
	/// \param strPathName, the file path name.
	/// \return TRUE if the file is a SDB 5.0 file.
	static UGbool IsSdb5File(const UGString& strPathName);

	//! 数据源是否和数据连接
	virtual UGbool IsConnected();

	//! 仅仅连接数据库,不刷新数据集等
	virtual UGbool Connect();

	virtual UGbool IsSupport(UGDataset::DatasetType nDtType) const;
public: // methods
	void SetLogLevel(int nLevel);
	int GetLogLevel();
	UGbool WriteLog(UGString &strDatasource,UGString &strdataset,UGString& strActionCode,int nReturnCode,UGString& strActionDesc);
	
	UGbool QueryMetaData(const CStringList& listValue,CStringList &listResult,const int nOption=0);

	UGbool Query(UGQueryDef& QueryDef,UGString& strNewDtName);
	
	virtual UGbool Compact(UGbool bShowProgress=TRUE);
	virtual UGbool CompactDatabase( LPCTSTR lpszSrcName, LPCTSTR lpszDestName, LPCTSTR lpszLocale, int nOptions, LPCTSTR lpszPassword);
	virtual UGbool CompactDatabase( LPCTSTR lpszSrcName, LPCTSTR lpszDestName, LPCTSTR lpszLocale = dbLangGeneral, int nOptions = 0 );
	virtual	UGbool RepairDatabase( LPCTSTR lpszName,UGString strPassword =(""));  //修复数据库 
	virtual UGbool IsSupport(UGEngAction dwEngAction);	//是否支持指定的操作(此处可用的操作有BeginTrans/CommitTrans/Rollback/LoginLongTrans/LogoutLongTrans)

	UGbool HasPassword(const UGString &strDataSourceName);
	UGbool ChangePassword(const UGString& strNewPassword);

public:
	
	virtual UGMetadata* GetMetaData();

protected://attributes
	
	CDaoDatabase	m_FileSDD;		//Access mdb file
	UGStorehouse m_FileSDB;		//SSS file

	UGFolder *m_pFolderDatasets; //Datasets Folder
	UGFolder *m_pFolderInfo;		// Info Folder
	UGFileLogical *m_pFileInfo;		//Info file in Info Folder
	UGFileLogical *m_pFileProj;		//Projection file  in Info Folder

	UGSdbDataSourceInfo m_DataSourceInfo;

protected:

	UGbool RepairDatasetRaster(UGSdbPlusDatasetRaster *pDatasetRaster);
	UGbool RepairDatasetVector(UGSdbPlusDatasetVector *pDatasetVector);

	//填充
	UGbool FillDatasets();
	UGbool ReadDatasetInfo(UGSdbPlusDatasetVector* pDatasetVector);
	
	//参数转换
//	UGuint SmOptToSdbOpt(UGuint dwOptions);	//Supermap => SSS file
//	void SmOptToMdbOpt(UGuint dwOptions,UGbool &bExclusive, UGbool &bReadOnly);	//Supermap => MDB

	UGbool CopyZippedRasterLocal(UGDatasetRaster* pSrcDataset,UGDatasetRaster* pDestDataset);

	//本地复制数据集strSrcDatasetName到当前数据源名为strDestDatasetName的数据集中
	virtual UGDataset * CopyDatasetLocal(UGDataset *pSrcDataset,
		const UGString &strDestDatasetName, 
		UGDataCodec::CodecType nCodeType = UGDataCodec::encNONE,
		UGbool bBuildIndxOrPyramid = FALSE);


};

extern "C" SDBPLUSENGINE_API UGDataSource* CreateDataSource();

//extern "C" ORCENGINE_API void StartupDao360();
// added by zengzm 2005-9-12 测试关闭 Dao36
extern "C" SDBPLUSENGINE_API void BeforeSdxUnload();

}

#endif // !defined(AFX_SDBATASOURCEPlus_H__F53EF3A0_08FE_11D3_92D1_0080C8EE62D1__INCLUDED_)

