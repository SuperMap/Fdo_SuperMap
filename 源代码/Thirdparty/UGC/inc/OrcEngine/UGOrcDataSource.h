/*! \file	 UGOrcDataSource.h
 *  \brief	 Oracle Plus DataSource
 *  \author	 ugc team
 *  \attention 
 *  Copyright(c) 1996-2004 SuperMap GIS Technologies,Inc.<br>
 *  All Rights Reserved
 *  \version $Id: UGOrcDataSource.h,v 1.22 2007/12/27 03:15:27 liwl Exp $
 */


#ifndef UGORCDATASOURCE_H
#define UGORCDATASOURCE_H

#include "Engine/UGDataSource.h"
#include "OrcEngine/UGOCIConnection.h"
#include "OrcEngine/UGCursorDataException.h"
#include "OrcEngine/UGCursorGeneralException.h"
#include "OrcEngine/UGOrcDatasetVector.h"
#include "Base/UGTime.h"
#include "OrcEngine/UGOrcRecordset.h"


namespace UGC {

class ORCENGINE_API UGOrcDataSource : public UGDataSource
{
	friend class UGOrcDatasetVector;
public:
	UGOrcDataSource();
	virtual ~UGOrcDataSource();	

	//检查OCI错误信息
	void CheckError() const;
	
	//! 执行SQL语句，主要用于在数据库级执行的数据操作
	virtual UGbool Execute(const UGString& strSQL);
	
	//! 创建数据源,需要预先设置好连接信息
	virtual UGbool Create();
	
	//! 打开数据源,需要预先设置好连接信息
	virtual UGbool Open();

	//! 关闭数据源
	virtual void Close();
		
	//! 获取最后更新时间
	virtual UGTime GetDateLastUpdated() const ;

	//! 获取创建时间
	virtual UGTime GetDateCreated() const ;

	//! 保存数据信息
	virtual UGbool SaveInfo();

	//! 修改密码
	virtual UGbool ChangePassword(const UGString& strNewPassword);

	//! 开始事务
	virtual UGbool BeginTrans();

	//! 提交事务
	virtual void Commit();

	//! 撤消事务
	virtual void Rollback();

	//! 是否有执行某些操作的能力
	virtual UGbool HasAbility(UGEngAbility nAbility) const ;

	//! 是否支持特定的操作
	virtual UGbool IsSupport(UGEngAction nAction) const ;

	//! 通过DatasetVectorInfo创建数据集
	virtual UGDatasetVector* CreateDatasetVector(
		const UGDatasetVectorInfo& vInfo);

	//! 通过DatasetVectorInfo创建Topo数据集
	virtual UGDatasetTopo* CreateDatasetTopo(UGString strName);

	//! 通过DatasetRasterInfo创建数据集
	virtual UGDatasetRaster* CreateDatasetRaster(
		const UGDatasetRasterInfo& rInfo);

	//! 删除数据集(通过名称)
	virtual UGbool DeleteDataset(const UGString& strName);
	
	//! UndoCheckOut
	virtual UGbool UndoCheckOut(UGbool bKeepCheckedOut);

	//! CheckIn
	virtual UGbool CheckIn(UGbool bKeepCheckedOut) ;

	//! CheckOut
	virtual UGbool CheckOut() ;

	//! Login
	virtual UGbool Login(const UGString& strName,
		const UGString& strPassword);

	virtual void LogOff() ;


	//! 判断是否已经登录
	virtual UGbool IsLogged() const {
		return m_bLoged;
	}

	virtual UGMetadata * GetMetaData();

	virtual UGEngineProc * GetEngineProc();

	//! 数据源是否和数据连接
	virtual UGbool IsConnected();

	//! 仅仅连接数据库,不刷新数据集等
	virtual UGbool Connect();

	//! \brief 工作空间关联相关接口
	virtual UGbool SaveWorkspace(UGDsConnection conn, UGString strWksName, UGint nVersion, UGbyte *pbyte,UGint nbyteSize);
	virtual UGbool LoadWorkspace(UGDsConnection conn, UGString strWksName, UGint nVersion, UGbyte *&pbyte,UGint &nbyteSize);
	virtual UGbool GetWorkspaceInfo(UGDsConnection conn, UGArray<UGWorkspaceInfo> &wksInfos);
	virtual UGbool DeleteWorkspaceInfo(UGDsConnection conn, UGString strWksName);

	//版本管理
	UGbool CreateDataVersion(UGString &strVersionName,UGString &strDescription);
	UGbool DeleteDataVersion(UGString &strVersionName);	
	UGbool SetCurrentVersion(UGString &strVersionName);	
	UGbool SetCurrentVersion(UGint nVersionID);	
	UGbool GetDataVersionInfos(UGArray<UGDataVersionInfo> &aryDataVersionInfos);	

public:
	UGTime GetCurServerTime();

	UGint GetLoggedUserID() {	
		if(!m_bLoged) return 0;
		return m_nLogID;
	}
	
	UGOCIConnection* GetConnection() const {
		return m_pConnection;
	}

	UGshort GetFreeTempTableID();

	void SetTempTableEngrossedFlag(UGint nTempTableID, 
					UGbool bEngrossed = TRUE);

	//得到有效的表名
	UGString ReviseTableName(UGString &strName);
protected:
	//! \brief 同引擎复制
	virtual UGDataset * CopyDatasetLocal(UGDataset *pSrcDataset,
			const UGString &strDestDatasetName, 
			UGDataCodec::CodecType nCodeType = UGDataCodec::encNONE,
			UGbool bBuildIndxOrPyramid = FALSE);

private:
	UGbool Connect(const UGString& strServer, const UGString& strUser,const UGString& strPass,
		const UGint nMinConn, const UGint nMaxConn, const UGint nIncConn);

	UGbool OpenRegister50();
	UGbool OpenRegister51();
	UGbool OpenImgRegister50();
	UGbool OpenImgRegister51();

public:
	//! 当前用户的ID
	UGint m_nUserID;

private:
	UGbool SetDataSourceInfo();
	UGbool ReadInfo();

	//在DeleteDataset()中调用
	UGbool DeleteSubDataset(UGDatasetVector *pDataset);
	UGbool U_UpdatetoUGC();
	UGOCIConnection* m_pConnection;
		
	//! 长事务用户的ID
	UGint m_nLogID;
	
	UGbool m_bConnected;
	UGString m_strLoginName;

	UGuchar m_TempTableIDs[32];
};

extern "C" void CheckDataError(UGCursorDataException *e);
extern "C" void CheckGeneralError(UGCursorGeneralException *e);

extern "C" ORCENGINE_API UGDataSource* CreateDataSource();

}

#endif
