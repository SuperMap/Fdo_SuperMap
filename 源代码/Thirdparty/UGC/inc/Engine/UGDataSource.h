#ifndef UGDATASOURCE_H
#define UGDATASOURCE_H

/*!
   **************************************************************************************
    \file     UGDataSource.h
   **************************************************************************************
    \author   李绍俊
    \brief    数据源对象的基类，所有引擎中的数据源都需要从本类中派生，并实现本类所定 
              义的纯虚函数。                                                         
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2004 SuperMap GIS Technologies,Inc.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-04-26  李绍俊    初始化版本.                                       <br>
   **************************************************************************************
*/



#include "Base/ugdefs.h"
#include "Base/UGString.h"
#include "UGDsConnection.h"
#include "Base/UGTime.h"
#include "ugeng.h"
#include "UGDataset.h"
#include "UGDatasetVectorInfo.h"
#include "UGDatasetRasterInfo.h"
#include "UGDatasetVector.h"
#include "UGDatasetRaster.h"
#include "UGEngDefs.h"
#include "UGTopoDataset.h"


namespace UGC {

//! \brief 存储工作空间相关信息
struct UGWorkspaceInfo
{
	UGint nVersion;
	UGString strWorkspaceName;
	UGString strUser;
};


class UGMetadata;
class UGEngineProc;
//! 数据源类
class ENGINE_API UGDataSource
{
public:
	//! 构造函数
	UGDataSource();

	//! 析构函数
	virtual ~UGDataSource();

	enum InvalidNameState
	{
		nsIsEmpty,			//名称为空
		nsBeyondLimit,		//长度超过30个字节
		nsInvalidChar,		//有非法字符
		nsHasAgainName,		//有重名
		nsPrefixIsSM,		//前两个字符是"sm"
		nsPrefixError,		//第一个字符为数字或下划线
		nsAgainsystemName	//与系统名称冲突
	};	//数据集或属性字段命名错误类型

public:

	//========================================================
	//! \brief 		获取当前数据源所在的Schema
	//! \return 	UGString
	UGString GetSchema() const;

	//! 获取数据源连接信息,返回为引用类型,
	//! 所以可以更改其连接信息
	UGDsConnection& GetConnectionInfo() {
		return m_Connection;
	}

	//! 执行SQL语句，主要用于在数据库级执行的数据操作
	virtual UGbool Execute(const UGString& strSQL) {
		return FALSE;
	}
	
	//! 创建数据源,需要预先设置好连接信息
	virtual UGbool Create() =0;

	//! 打开数据源,需要预先设置好连接信息
	virtual UGbool Open() =0;

	//! 数据源是否和数据连接
	virtual UGbool IsConnected() =0;

	//! 仅仅连接数据库,不刷新数据集等
	virtual UGbool Connect() =0;

	//! 关闭数据源
	virtual void Close() =0;
	
	//! 判断数据源是否已经打开
	UGbool IsOpen() const{
		return m_bOpened;
	}

	//! 获取最后更新时间
	virtual UGTime GetDateLastUpdated() const =0;

	//! 获取创建时间
	virtual UGTime GetDateCreated() const =0;

	//! 保存数据信息
	virtual UGbool SaveInfo() =0;

	//! 修改密码
	virtual UGbool ChangePassword(const UGString& strNewPassword) =0;

	//! 删除数据集(通过名称)
	virtual UGbool DeleteDataset(const UGString& strName) =0;

	//! 通过DatasetVectorInfo创建数据集
	virtual UGDatasetVector* CreateDatasetVector(
		const UGDatasetVectorInfo& vInfo) =0;

	//! 通过DatasetVectorInfo创建数据集
	virtual UGDatasetTopo* CreateDatasetTopo(UGString strName) =0;
	//! 通过DatasetRasterInfo创建数据集
	virtual UGDatasetRaster* CreateDatasetRaster(
		const UGDatasetRasterInfo& rInfo) =0;

	//! 复制数据集,需要调用CreateDatasetFrom新建数据集strDestDatasetName
	virtual UGDataset* CopyDataset(UGDataset* pSrcDataset, 
		const UGString& strDestDatasetName,
		UGDataCodec::CodecType nCodeType = UGDataCodec::encNONE,
		UGbool bBuildIndexOrPyramid = FALSE);

	//! \brief 得到元数据库
	//! \return 非空表示支持元数据操作
	//! \remarks 
	//! \attention 
	virtual UGMetadata * GetMetaData();	

	virtual UGEngineProc * GetEngineProc();
public:
	//! \brief 工作空间关联相关接口
	virtual UGbool SaveWorkspace(UGDsConnection conn, UGString strWksName, UGint nVersion, UGbyte *pbyte,UGint nbyteSize);
	virtual UGbool LoadWorkspace(UGDsConnection conn, UGString strWksName, UGint nVersion, UGbyte *&pbyte,UGint &nbyteSize);
	virtual UGbool GetWorkspaceInfo(UGDsConnection conn, UGArray<UGWorkspaceInfo> &wksInfos);
	virtual UGbool DeleteWorkspaceInfo(UGDsConnection conn, UGString strWksName);

	//版本管理
	virtual UGbool CreateDataVersion(UGString &strVersionName,UGString &strDescription);
	virtual UGbool DeleteDataVersion(UGString &strVersionName);	
	virtual UGbool SetCurrentVersion(UGString &strVersionName);	
	virtual UGbool SetCurrentVersion(UGint nVersionID);	
	virtual UGbool GetDataVersionInfos(UGArray<UGDataVersionInfo> &aryDataVersionInfos);

public:
	//! 获取密码(通过获取连接信息也可以得到密码)
	UGString GetPassword() const {
		return m_Connection.m_strPassword;
	}

	//! 获取数据源名称
	UGString GetName() const ;

	//! 获取引擎类型
	UGEngineType GetEngineType() const{
		return m_Connection.m_nEngineType;
	}

	//! 获取引擎名称
	virtual UGString GetEngineName() const ;

	//! 生成一个数据源中目前没有的数据集名字
	virtual UGString GetUnoccupiedDatasetName(const UGString& strDatasetName);

	//! 判断数据集名称是否合法
	virtual UGbool IsAvailableDatasetName(const UGString& strDatasetName,InvalidNameState& nState);

	virtual UGint GetVersion();

	UGbool IsModified();
	void SetModifiedFlag(UGbool bModified = TRUE);

	//========================================================
	//! \brief 		判断数据源是否为只读
	//! \return 	UGbool
	UGbool IsReadOnly() const {
		return m_Connection.m_bReadOnly;
	}
	
	//========================================================
	//! \brief 		判断数据源是否为独占方式打开
	//! \return 	UGbool
	UGbool IsExclusive() const {
		return m_Connection.m_bExclusive;
	}
	
	//========================================================
	//! \brief 		判断数据源是否使用密码打开
	//! \return 	UGbool
	UGbool IsEncrypt() const {
		return m_Connection.m_bEncrypt;
	}

	//========================================================
	//! \brief 		判断数据源是否是自动连接
	//! \return 	UGbool
	UGbool IsAutoConnect() const {
		return m_Connection.m_bAutoConnect;
	}

	//========================================================
	//! \brief 		设置数据源的自动连接选项
	//! \return 	void
	//! \param 		bAutoConnect
	void SetAutoConnect(UGbool bAutoConnect) {
		m_Connection.m_bAutoConnect = bAutoConnect;
	}
	
	
	//========================================================
	//! \brief 		获取数据源的别名
	//! \return 	UGString
	UGString GetAlias() const {
		return m_Connection.m_strAlias;
	}

	//========================================================
	//! \brief 		设置数据源的别名
	//! \return 	void
	//! \param 		strAlias
	void SetAlias(const UGString& strAlias) {
		m_Connection.m_strAlias = strAlias;
	}
	
	//! 是否有执行某些操作的能力
	virtual UGbool HasAbility(UGEngAbility nAbility) const {
		return FALSE;
	}

	//! 是否支持特定的操作
	virtual UGbool IsSupport(UGEngAction nAction) const {
		return FALSE;
	}

	virtual UGbool IsSupport(UGDataset::DatasetType nDtType) const;

	//! 返回数据集个数
	UGint GetDatasetCount() const {
		return m_Datasets.GetSize();
	}

	//! 通过序号返回数据集指针
	UGDataset* GetDataset(UGint nIndex) const {		
		return m_Datasets[nIndex];
	}

	//! 返回指定名称的数据集指针
	UGDataset* GetDataset(const UGString& strDatasetName) const;
	
	//========================================================
	//! \brief 		判断传入的字段名或表名是否可用
	//! \return 	UGbool
	//! \param 		strFieldOrTableName
	//! \param 		nInvalidStata
	UGbool IsValidFieldOrTableName(const UGString& strFieldOrTableName, UGint& nInvalidStata);

	//========================================================
	//! \brief 		设置数据源的投影信息
	//! \param 		UGPrjCoordSys 投影信息
	void SetPrjCoordSys(const UGPrjCoordSys &PrjCoordSys);
	
	//========================================================
	//! \brief 		获取数据源的投影信息
	//! \return 	UGPrjCoordSys 读取出来的投影信息
	const UGPrjCoordSys& GetPrjCoordSys();

	UGbool PJConvert( UGRefTranslator *pRefTranslator);		//投影转换
	UGbool PJForward( UGPrjCoordSys *pPrjCoordSys );		//地理坐标到投影坐标
	UGbool PJInverse();										//投影坐标到地理坐标

	//!Recordset to Dataset
	UGDatasetVector * RecordsetToDataset(UGRecordset *pRecord,UGString strNewDatasetName);

	void SetDescription(UGString strDesc){m_strDescription = strDesc; SetModifiedFlag();};

	UGString GetDescription(){return m_strDescription;};

	UGint GetDataversionID(){return m_nDataVersionID;};

	//! 通过Template创建数据集
	virtual UGDataset* CreateDatasetFrom(const UGString &strNewName,
		UGDataset * pReferenceDataset,UGDataCodec::CodecType nType);
	
	//! 开始事务
	virtual UGbool BeginTrans() {
		return FALSE;
	}

	//! 提交事务
	virtual void Commit() {}

	//! 撤消事务
	virtual void Rollback() {}

	//! 判断事务是否开始 
	UGbool IsTransStarted() const {
		return m_bTransStarted;
	}
	//========================================================
	//! \brief 		判断数据源是否支持短事务操作
	//! \return 	UGbool
	UGbool IsTransacted() const {
		return m_Connection.m_bTransacted;
	}

	//! UndoCheckOut
	virtual UGbool UndoCheckOut(UGbool bKeepCheckedOut) {
		return FALSE;
	}

	//! CheckIn
	virtual UGbool CheckIn(UGbool bKeepCheckedOut) {
		return FALSE;
	}

	//! CheckOut
	virtual UGbool CheckOut() {
		return FALSE;
	}

	//! Login
	virtual UGbool Login(const UGString& strName,
		const UGString& strPassword) {
		return FALSE;
	}

	//! 判断是否已经登录
	virtual UGbool IsLogged() const {
		return m_bLoged;
	}

	//! 退出
	virtual void LogOff() {
		m_bLoged = FALSE;
	}
		
	//========================================================
	//! \brief 		判断数据源是否有自动CheckOut选项
	//! \return 	UGbool
	UGbool IsAutoCheckOut() const;

	//========================================================
	//! \brief 		设置数据源的自动CheckOut选项
	//! \return 	void
	//! \param 		bAutoCheckOut
	void SetAutoCheckOut(UGbool bAutoCheckOut);

	//! \brief 得到各类系统表中序列化字段中的最大值 added by yanmb 2007.06.07
	virtual UGint GetMaxTableID(){
		return -100000;
	}
	virtual UGint GetFieldMaxValue(const UGString &strTableName, const UGString &strFieldName){
		return -100000;
	}

protected:	
	//! \brief 同引擎复制
	virtual UGDataset * CopyDatasetLocal(UGDataset *pSrcDataset,
		const UGString &strDestDatasetName, 
		UGDataCodec::CodecType nCodeType = UGDataCodec::encNONE,
		UGbool bBuildIndxOrPyramid = FALSE);

protected:
	//! 连接信息
	UGDsConnection m_Connection;
	//! 判断是否打开
	UGbool m_bOpened;	

	UGArray<UGDataset*> m_Datasets;
	//std::vector<UGint> m_IArray;
	//! \brief 		数据源的投影信息
	UGPrjCoordSys m_PrjCoordSys;

	//数据的主版本
	UGint m_nVersion;
	//数据的小版本
	UGint m_nMinorVersion;
	//VersionDate
	UGint m_nVersionDate;

	//! 描述信息
	UGString m_strDescription;
	//! 是否更改
	UGbool m_bModified;

	//! 当前版本ID
	UGint m_nDataVersionID;
	
	//! 判断是否自动CheckOut
	UGbool m_bAutoCheckOut;
	
		//! 事务是否启动
	UGbool m_bTransStarted;
	
		//! 判断是否已经登陆长事务
	UGbool m_bLoged;
};

}

#endif

