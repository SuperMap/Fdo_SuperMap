// UGOrcEngineProc.h: interface for the UGOrcEngineProc class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGORCENGINEPROC_H__F46AC2F5_0F1E_4492_B786_C7108E190E2C__INCLUDED_)
#define AFX_UGORCENGINEPROC_H__F46AC2F5_0F1E_4492_B786_C7108E190E2C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Engine/UGEngineProc.h"

namespace UGC {

class ORCENGINE_API UGOrcEngineProc : public UGEngineProc
{
public:
	UGOrcEngineProc();
	virtual ~UGOrcEngineProc();
	
	//! \brief 取得数据库服务中所有数据库用户信息
	//! \param &ConnSys [in] 数据库连接，要提供系统用户
	//! \param &aryDBInfos [out] 具体数据库信息
	//! \return 成功 True 
	//! \attention ConnSys一定有系统权限	
	virtual UGbool GetAllDbInfo(UGDsConnection &ConnSys,UGArray<UGDBInfo> &aryDBInfos);

};
}
#endif // !defined(AFX_UGORCENGINEPROC_H__F46AC2F5_0F1E_4492_B786_C7108E190E2C__INCLUDED_)
