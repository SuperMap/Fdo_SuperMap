// UGSqlDatasetRaster.h: interface for the UGSqlDatasetRaster class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGSqlDATASETRASTER_H__CC641183_47BD_451D_AB35_4D6E88AD4840__INCLUDED_)
#define AFX_UGSqlDATASETRASTER_H__CC641183_47BD_451D_AB35_4D6E88AD4840__INCLUDED_

#include "ODBCEngine/UGODBCDatasetRaster.h"

namespace UGC
{
class SQLENGINE_API UGSqlDatasetRaster  : public UGODBCDatasetRaster
{
	friend class UGSqlDatasource;

public:
	UGSqlDatasetRaster();
	UGSqlDatasetRaster(UGDataSource *pDatasource);
	virtual ~UGSqlDatasetRaster();
	
public:
	//! \brief 栅格数据集的创建
	//! param rInfo 栅格数据集相关信息[in]
	UGbool Create(const UGDatasetRasterInfo & rInfo);
};

}

#endif // !defined(AFX_UGSqlDATASETRASTER_H__CC641183_47BD_451D_AB35_4D6E88AD4840__INCLUDED_)

