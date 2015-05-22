// UGKBDatasetRaster.h: interface for the UGKBDatasetRaster class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGKBDATASETRASTER_H__CC641183_47BD_451D_AB35_4D6E88AD4840__INCLUDED_)
#define AFX_UGKBDATASETRASTER_H__CC641183_47BD_451D_AB35_4D6E88AD4840__INCLUDED_

#include "ODBCEngine/UGODBCDatasetRaster.h"

namespace UGC
{

class KINGENGINE_API UGKBDatasetRaster  : public UGODBCDatasetRaster
{
	friend class UGKBDatasource;

public:
	UGKBDatasetRaster();
	UGKBDatasetRaster(UGDataSource *pDatasource);
	virtual ~UGKBDatasetRaster();
	
public:
	UGbool Create(const UGDatasetRasterInfo & rInfo);
};

}

#endif // !defined(AFX_UGKBDATASETRASTER_H__CC641183_47BD_451D_AB35_4D6E88AD4840__INCLUDED_)

