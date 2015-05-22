// UGKBRecordset.h: interface for the UGKBRecordset class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGKBRECORDSET_H__D717949F_EB98_4A9D_A62D_443C37D7495F__INCLUDED_)
#define AFX_UGKBRECORDSET_H__D717949F_EB98_4A9D_A62D_443C37D7495F__INCLUDED_

#include "ODBCEngine/UGODBCRecordset.h"
#include "KingbaseEngine/UGKBDatasetVector.h"
namespace UGC
{
class KINGENGINE_API UGKBRecordset : public UGODBCRecordset
{
public:
	UGKBRecordset();
	UGKBRecordset(UGKBDatasetVector *pDatasetVector);
	virtual ~UGKBRecordset();

};
}
#endif // !defined(AFX_UGKBRECORDSET_H__D717949F_EB98_4A9D_A62D_443C37D7495F__INCLUDED_)
