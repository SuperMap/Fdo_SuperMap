// UGDB2DatasetRaster.h: interface for the UGDB2DatasetRaster class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGDB2DATASETRASTER_H__CC641183_47BD_451D_AB35_4D6E88AD4840__INCLUDED_)
#define AFX_UGDB2DATASETRASTER_H__CC641183_47BD_451D_AB35_4D6E88AD4840__INCLUDED_

#include "ODBCEngine/UGODBCDatasetRaster.h"

namespace UGC
{

class DB2ENGINE_API UGDB2DatasetRaster  : public UGODBCDatasetRaster
{
	friend class UGDB2Datasource;

public:
	UGDB2DatasetRaster();
	UGDB2DatasetRaster(UGDataSource *pDatasource);
	virtual ~UGDB2DatasetRaster();
	
public:
	UGbool Create(const UGDatasetRasterInfo & rInfo);
};

}

#endif // !defined(AFX_UGDB2DATASETRASTER_H__CC641183_47BD_451D_AB35_4D6E88AD4840__INCLUDED_)

