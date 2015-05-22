// UGDB2Recordset.h: interface for the UGDB2Recordset class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGDB2RECORDSET_H__D717949F_EB98_4A9D_A62D_443C37D7495F__INCLUDED_)
#define AFX_UGDB2RECORDSET_H__D717949F_EB98_4A9D_A62D_443C37D7495F__INCLUDED_

#include "ODBCEngine/UGODBCRecordset.h"
#include "DB2Engine/UGDB2DatasetVector.h"
namespace UGC
{
class DB2ENGINE_API UGDB2Recordset : public UGODBCRecordset
{
public:
	UGDB2Recordset();
	UGDB2Recordset(UGDB2DatasetVector *pDatasetVector);
	virtual ~UGDB2Recordset();

};
}
#endif // !defined(AFX_UGDB2RECORDSET_H__D717949F_EB98_4A9D_A62D_443C37D7495F__INCLUDED_)
