// UGDB2EditRecordset.h: interface for the UGDB2EditRecordset class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGDB2EDITRECORDSET_H__8B07D0AC_D295_4E4B_A6D1_3CBC3BEEF3DE__INCLUDED_)
#define AFX_UGDB2EDITRECORDSET_H__8B07D0AC_D295_4E4B_A6D1_3CBC3BEEF3DE__INCLUDED_

#include  "ODBCEngine/UGODBCEditRecordset.h"
#include "DB2Engine/UGDB2DatasetVector.h"

namespace UGC
{
class DB2ENGINE_API UGDB2EditRecordset  : public UGODBCEditRecordset
{
public:
	UGDB2EditRecordset();
	UGDB2EditRecordset(UGDB2DatasetVector *pDatasetVector);
	virtual ~UGDB2EditRecordset();

};
}

#endif // !defined(AFX_UGDB2EDITRECORDSET_H__8B07D0AC_D295_4E4B_A6D1_3CBC3BEEF3DE__INCLUDED_)
