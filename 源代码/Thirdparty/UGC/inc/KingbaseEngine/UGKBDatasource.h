// UGKBDatasource.h: interface for the UGKBDatasource class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGKBDATASOURCE_H__AC16CF1D_152A_46FD_AF33_A68041F47321__INCLUDED_)
#define AFX_UGKBDATASOURCE_H__AC16CF1D_152A_46FD_AF33_A68041F47321__INCLUDED_

#include "ODBCEngine/UGODBCDatasource.h"

namespace UGC
{

extern "C" KINGENGINE_API UGDataSource* CreateDataSource();

class KINGENGINE_API UGKBDatasource  : public UGODBCDatasource
{
public:
	UGKBDatasource();
	virtual ~UGKBDatasource();

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

protected:
	UGbool Connect();

private:
	UGString m_strSchema;

	
};

}

#endif // !defined(AFX_UGKBDATASOURCE_H__AC16CF1D_152A_46FD_AF33_A68041F47321__INCLUDED_)
