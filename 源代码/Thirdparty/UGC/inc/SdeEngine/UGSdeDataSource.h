// UGSdeDataSource.h: interface for the UGSdeDataSource class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGSDEDATASOURCE_H__EDBD4488_AA85_42AC_9169_833D32CF62C9__INCLUDED_)
#define AFX_UGSDEDATASOURCE_H__EDBD4488_AA85_42AC_9169_833D32CF62C9__INCLUDED_


#include "Engine/UGDataSource.h"
#include "Base/ugdefs.h"
#include "Base/UGString.h"
#include "Base/UGTime.h"
#include "SdeEngine/include/sdetype.h"

namespace UGC {	

class SDEENGINE_API UGSdeDataSource : public UGDataSource
{
public:
	UGSdeDataSource();
	virtual ~UGSdeDataSource();

public:

	//! 创建数据源,需要预先设置好连接信息
	virtual UGbool Create();

	//! 打开数据源,需要预先设置好连接信息
	virtual UGbool Open();

	//! 关闭数据源
	virtual void Close();

	//! 获取最后更新时间
	virtual UGTime GetDateLastUpdated() const;

	//! 获取创建时间
	virtual UGTime GetDateCreated() const;

	//! 保存数据信息
	virtual UGbool SaveInfo();

	//! 修改密码
	virtual UGbool ChangePassword(const UGString& strNewPassword);

	//! 通过DatasetVectorInfo创建数据集
	virtual UGDatasetVector* CreateDatasetVector(const UGDatasetVectorInfo& vInfo);

	virtual UGDatasetTopo* CreateDatasetTopo(UGString strName);
	//! 通过DatasetRasterInfo创建数据集
	virtual UGDatasetRaster* CreateDatasetRaster(const UGDatasetRasterInfo& rInfo);

	//! 删除数据集(通过名称)
	virtual UGbool DeleteDataset(const UGString& strName);

	//! 元数据管理类
	virtual UGMetadata* GetMetaData();

	//! 数据源是否和数据连接
	virtual UGbool IsConnected();

	//! 仅仅连接数据库,不刷新数据集等
	virtual UGbool Connect();

public:
	UGbool check_error(SE_CONNECTION *conn, SE_STREAM stream, UGuint nResultCode,UGchar *comment);

public:
	SE_CONNECTION m_SDEConnection;
};

extern "C" SDEENGINE_API UGDataSource* CreateDataSource();

}
#endif // !defined(AFX_UGSDEDATASOURCE_H__EDBD4488_AA85_42AC_9169_833D32CF62C9__INCLUDED_)

