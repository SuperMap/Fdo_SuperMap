// UGDB2Datasource.h: interface for the UGDB2Datasource class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGDB2DATASOURCE_H__AC16CF1D_152A_46FD_AF33_A68041F47321__INCLUDED_)
#define AFX_UGDB2DATASOURCE_H__AC16CF1D_152A_46FD_AF33_A68041F47321__INCLUDED_

#include "ODBCEngine/UGODBCDatasource.h"

namespace UGC
{

extern "C" DB2ENGINE_API UGDataSource* CreateDataSource();

class DB2ENGINE_API UGDB2Datasource  : public UGODBCDatasource
{
public:
	UGDB2Datasource();
	virtual ~UGDB2Datasource();

public:
	//! 创建数据源,需要预先设置好连接信息
	virtual UGbool Create();

	//! 打开数据源,需要预先设置好连接信息
	virtual UGbool Open();

	//! 获取最后更新时间
	virtual UGTime GetDateLastUpdated() const;

	//! 获取创建时间
	virtual UGTime GetDateCreated() const;

	//! 修改密码
	virtual UGbool ChangePassword(const UGString& strNewPassword);

	

	//! 通过DatasetVectorInfo创建数据集
	virtual UGDatasetVector* CreateDatasetVector(
		const UGDatasetVectorInfo& vInfo);

	//! 通过DatasetVectorInfo创建数据集
	virtual UGDatasetTopo* CreateDatasetTopo(UGString strName);

	//! 通过DatasetRasterInfo创建数据集
	virtual UGDatasetRaster* CreateDatasetRaster(
		const UGDatasetRasterInfo& rInfo);

	//! 删除数据集(通过名称)
	virtual UGbool DeleteDataset(const UGString& strName);

public:
	virtual UGuint GetSeqValue(UGString &strSeq,UGint nMode = 1);
public:
	UGString GetTbSpaceName();
	UGString GetLongTbSpaceName();
	UGString GetIndexTbSpaceName();

protected:
	UGbool Connect();
	void   ReadTbSpaceInfo();
private:
	UGString m_strSchema;
	UGString m_strTbSpace;
	UGString m_strLongTbSpace;
	UGString m_strIndexTbSpace;
	
};

}

#endif // !defined(AFX_UGDB2DATASOURCE_H__AC16CF1D_152A_46FD_AF33_A68041F47321__INCLUDED_)
