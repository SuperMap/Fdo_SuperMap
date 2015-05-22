// UGSqlEditRecordset.h: interface for the UGSqlEditRecordset class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGSqlEDITRECORDSET_H__8B07D0AC_D295_4E4B_A6D1_3CBC3BEEF3DE__INCLUDED_)
#define AFX_UGSqlEDITRECORDSET_H__8B07D0AC_D295_4E4B_A6D1_3CBC3BEEF3DE__INCLUDED_

#include  "ODBCEngine/UGODBCEditRecordset.h"
#include "SqlPlusEngine/UGSqlDatasetVector.h"

namespace UGC
{
class SQLENGINE_API UGSqlEditRecordset  : public UGODBCEditRecordset
{
public:
	UGSqlEditRecordset();
	UGSqlEditRecordset(UGSqlDatasetVector *pDatasetVector);
	virtual ~UGSqlEditRecordset();

};
}

#endif // !defined(AFX_UGSqlEDITRECORDSET_H__8B07D0AC_D295_4E4B_A6D1_3CBC3BEEF3DE__INCLUDED_)
