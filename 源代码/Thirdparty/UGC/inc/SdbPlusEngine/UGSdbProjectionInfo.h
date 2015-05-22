// ElemProjectionInfo.h: interface for the UGSdbProjectionInfo class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_UGSDBPROJECTIONINFO_H)
#define _UGSDBPROJECTIONINFO_H

#include "Base/ugdefs.h"
#include "Base/UGArray.h"


#include "Project/UGPrjCoordSys.h"

namespace UGC
{

class UGRecordHeader;

class  UGSdbProjectionInfo
{
public:
	UGSdbProjectionInfo();
	virtual ~UGSdbProjectionInfo();

	//坐标系统号
	void SetCoordinateSystem(UGint nCoordSys);
	UGint GetCoordinateSystem();
public:
	UGbool IsValid();				//是否有效对象
	UGbool GetRecordHeader(UGRecordHeader *pRcdHdr);	//保存记录头到内存块

	UGuchar* GetData();
	UGint GetDataSize();

	void To(UGPrjCoordSys &PJCoordSys);
	void From(const UGPrjCoordSys& PJCoordSys);
protected:
	UGArray<UGuchar> m_Data;
	//PJCoordSys-->坐标系对象
//	void GetProjection( CSmPJCoordSys  &PJCoordSys );
//	void SetProjection( CSmPJCoordSys  PJCoordSys );
};

}

#endif // !defined(_UGSDBPROJECTIONINFO_H)
