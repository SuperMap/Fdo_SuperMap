// UGSqlRecordset.h: interface for the UGSqlRecordset class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGSqlRECORDSET_H__D717949F_EB98_4A9D_A62D_443C37D7495F__INCLUDED_)
#define AFX_UGSqlRECORDSET_H__D717949F_EB98_4A9D_A62D_443C37D7495F__INCLUDED_

#include "ODBCEngine/UGODBCRecordset.h"
#include "SqlPlusEngine/UGSqlDatasetVector.h"

namespace UGC
{
class SQLENGINE_API UGSqlRecordset : public UGODBCRecordset
{
public:
	UGSqlRecordset();
	UGSqlRecordset(UGSqlDatasetVector *pDatasetVector);
	virtual ~UGSqlRecordset();

};
}
#endif // !defined(AFX_UGSqlRECORDSET_H__D717949F_EB98_4A9D_A62D_443C37D7495F__INCLUDED_)
