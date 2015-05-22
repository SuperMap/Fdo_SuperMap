/* 
	\file UGDataVersion.h
	\brief 文件内容的简要描述。
	\author 文件作者
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>更新说明：。</b>
	<em>1、第一条说明。</em>
	<em>2、第二条说明。</em>
*/

#if !defined(AFX_UGDATAVERSION_H__9BAC4D74_E861_4A1B_A4FB_BB45038FEBDA__INCLUDED_)
#define AFX_UGDATAVERSION_H__9BAC4D74_E861_4A1B_A4FB_BB45038FEBDA__INCLUDED_

#include "Engine/UGDataSource.h"

namespace UGC {

class ENGINE_API UGDataVersion  
{
public:
	UGDataVersion();
	virtual ~UGDataVersion();

public:

	//! \brief 创建数据源的版本
	//! \param *pDs [in]。
	//! \param &strVersionName [in]。
	//! \param &strDescription [in]。
	//! \return UGbool
	//! \remarks 。
	//! \attention 。
	UGbool CreateDataVersion(UGDataSource *pDs,UGString &strVersionName,UGString &strDescription);
	
	//! \brief 删除版本
	//! \param *pDs [in]。
	//! \param &strVersionName [in]。
	//! \return 。
	//! \remarks 此操作要慎重，删除所有针对此版本的操作。
	//! \attention 。
	UGbool DeleteDataVersion(UGDataSource *pDs,UGString &strVersionName);	

	//! \brief 设置当前的版本
	//! \param *pDs [in]。
	//! \param &strVersionName [in]。
	//! \return 。
	//! \remarks 。
	//! \attention 。
	UGbool SetCurrentVersion(UGDataSource *pDs,UGString &strVersionName);		

	//! \brief 设置当前的版本
	//! \param *pDs [in]。
	//! \param nVersionID [in]。
	//! \return 。
	//! \remarks 。
	//! \attention 。
	UGbool SetCurrentVersion(UGDataSource *pDs,UGint nVersionID);		

	//! \brief 得到版本的信息
	//! \param *pDs [in]。
	//! \param &aryDataVersionInfos [in]。
	//! \return 。
	//! \remarks 。
	//! \attention 。
	UGbool GetDataVersionInfos(UGDataSource *pDs,
					UGArray<UGDataVersionInfo> &aryDataVersionInfos);	
	
	//! \brief 注册数据集为支持版本
	//! \param *pDt [in]。
	//! \return 。
	//! \remarks 添加A，D表
	//! \attention 必须注册
	UGbool Register(UGDatasetVector *pDt);

	//! \brief 反注册
	//! \param *pDt [in]。
	//! \return 。
	//! \remarks 。
	//! \attention 。
	UGbool UnRegister(UGDatasetVector *pDt);	

	//! \brief 提交一个版本到数据集
	//! \param *pDt [in]。
	//! \param strVersion [in]。
	//! \param nPostOption [in]。
	//! \param &nCheckConfilct [out]。
	//! \return 。
	//! \remarks 。
	//! \attention 。
	UGbool PostToMainVersion(UGDatasetVector *pDt,
					UGString strVersion,
					UGPostOption nPostOption,
					UGArray<UGCheckConflict> &CheckConfilcts);

	//! \brief 提交一个版本到数据集
	//! \param *pDt [in]。
	//! \param nVersionID [in]。
	//! \param nPostOption [in]。
	//! \param &nCheckConfilct [out]。
	//! \return 。
	//! \remarks 。
	//! \attention 。
	UGbool PostToMainVersion(UGDatasetVector *pDt,
					UGint nVersionID,
					UGPostOption nPostOption,
					UGArray<UGCheckConflict> &CheckConfilcts);


	//! \brief 提交一个对象到数据集
	//! \param *pDt [in] 版本数据集
	//! \param nVersionID [in] 版本号 
	//! \param nDataID [in] 此数据集的对象ID
	//! \param nPostOption [in] 提交数据要采用的方式 
	//! \return 
	//! \remarks 
	//! \attention 
	UGbool PostToMainVersion(UGDatasetVector *pDt,
					UGint nVersionID,
					UGint nDataID,
					UGPostOption nPostOption);

	//! \brief 清除一个版本的编辑
	//! \param *pdt [in]。
	//! \param nVersion [in]。
	//! \return 。
	//! \remarks 。
	//! \attention 。
	UGbool RollBackVersion(UGDatasetVector *pdt,UGint nVersion);
};

}

#endif // !defined(AFX_UGDATAVERSION_H__9BAC4D74_E861_4A1B_A4FB_BB45038FEBDA__INCLUDED_)
