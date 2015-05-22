// UGSqlDatasource.h: interface for the UGSqlDatasource class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGSqlDATASOURCE_H__AC16CF1D_152A_46FD_AF33_A68041F47321__INCLUDED_)
#define AFX_UGSqlDATASOURCE_H__AC16CF1D_152A_46FD_AF33_A68041F47321__INCLUDED_

#include "ODBCEngine/UGODBCDatasource.h"

namespace UGC
{

extern "C" UGEXPORT UGDataSource* CreateDataSource();

class SQLENGINE_API UGSqlDatasource  : public UGODBCDatasource
{
	friend class UGSqlDatasetVector;
public:
	UGSqlDatasource();
	virtual ~UGSqlDatasource();

public:
	//! \brief 创建数据源,需要预先设置好连接信息
	virtual UGbool Create();

	//! \brief  打开数据源,需要预先设置好连接信息
	virtual UGbool Open();

	//! \brief  获取最后更新时间
	virtual UGTime GetDateLastUpdated() const;

	//! \brief  获取创建时间
	virtual UGTime GetDateCreated() const;

	//! \brief 连接数据源
	virtual UGbool Connect();

	//! \brief  修改密码
	virtual UGbool ChangePassword(const UGString& strNewPassword);

	//! \brief  通过DatasetVectorInfo创建数据集
	virtual UGDatasetVector* CreateDatasetVector(
		const UGDatasetVectorInfo& vInfo);

	virtual UGDatasetTopo* CreateDatasetTopo(UGString strName);
	//! \brief  通过DatasetRasterInfo创建数据集
	virtual UGDatasetRaster* CreateDatasetRaster(
		const UGDatasetRasterInfo& rInfo);

	//! \brief  删除数据集(通过名称)
	virtual UGbool DeleteDataset(const UGString& strName);

	//! \brief 得到元数据库
	//! \return 非空表示支持元数据操作
	//! \remarks 
	//! \attention 
	virtual UGMetadata * GetMetaData();	

	//! \brief 版本管理
	//! \brief 创建版本
	//! \param strVersionName　版本[in]
	//! \param strDescription　版本描述信息[in]
	//! \remarks 
	UGbool CreateDataVersion(UGString &strVersionName,UGString &strDescription);
	//! \brief 删除版本
	//! \param strVersionName　版本[in]
	UGbool DeleteDataVersion(UGString &strVersionName);	
	//! \brief 设置当前版本
	//! \param strVersionName　版本[in]
	UGbool SetCurrentVersion(UGString &strVersionName);	
	//! \brief 设置当前版本
	//! \param nVersionID　版本号[in]
	UGbool SetCurrentVersion(UGint nVersionID);	
	//! \brief 获取版本信息
	//! \param aryDataVersionInfos　版本信息数组[out]
	UGbool GetDataVersionInfos(UGArray<UGDataVersionInfo> &aryDataVersionInfos);

public:
	//! \brief 得到序列化的值
	//! \param nDatasetID 数据集ID[in]
	virtual UGuint GetSeqValue(UGint nDatasetID);

protected:
	//! \brief 同类型数据源复制数据集
	//! \param strSrcDatasetName　	 源数据源数据集名[in]
	//! \param strDestDatasetName	 目标数据集名[in]
	//! \param codecType			 数据集编码[in]
	//! \param bShowProgress		 是否显示进度条[in]
	//! \param bBuildIndxOrPyramid	 是否创建索引或者金字塔[in]
	//! \return 返回结果数据集指针
	virtual UGDataset *CopyDatasetLocal(UGDataset *pSrcDataset,const UGString &strDestDatasetName,
		UGDataCodec::CodecType codecType = UGDataCodec::encNONE,
		UGbool bBuildIndxOrPyramid = FALSE);
	
	//! \brief 数据集版本维护
	//! \brief UGC20打开SFC52的数据时自动更新维护系统表
	UGbool UpdateVersion();
	//! \brief 打开50的数据
	UGbool OpenRegister50();

	//! \brief 多了topo数据集 和 smregister 的smparentid字段
	UGbool OpenRegister53();
	UGbool OpenImgRegister50();

	//! \brief 外挂属性表
	UGbool OpenExpandTable();

	//! \brief 数据集删除时，删除子数据集 
	void DeleteSubDataset(UGDatasetVector *pSubDataset);

	UGbool ConnectDB();
private:
	UGString m_strSchema;
};

}

#endif // !defined(AFX_UGSqlDATASOURCE_H__AC16CF1D_152A_46FD_AF33_A68041F47321__INCLUDED_)
