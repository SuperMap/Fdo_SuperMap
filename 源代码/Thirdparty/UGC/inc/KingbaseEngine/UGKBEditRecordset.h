// UGKBEditRecordset.h: interface for the UGKBEditRecordset class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGKBEDITRECORDSET_H__8B07D0AC_D295_4E4B_A6D1_3CBC3BEEF3DE__INCLUDED_)
#define AFX_UGKBEDITRECORDSET_H__8B07D0AC_D295_4E4B_A6D1_3CBC3BEEF3DE__INCLUDED_

#include  "ODBCEngine/UGODBCEditRecordset.h"
#include "KingbaseEngine/UGKBDatasetVector.h"

namespace UGC
{
class KINGENGINE_API UGKBEditRecordset  : public UGODBCEditRecordset
{
public:
	UGKBEditRecordset();
	UGKBEditRecordset(UGKBDatasetVector *pDatasetVector);
	virtual ~UGKBEditRecordset();

};
}

#endif // !defined(AFX_UGKBEDITRECORDSET_H__8B07D0AC_D295_4E4B_A6D1_3CBC3BEEF3DE__INCLUDED_)
