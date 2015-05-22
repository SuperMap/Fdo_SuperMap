// UGODBCEngineProc.h: interface for the UGODBCEngineProc class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGODBCENGINEPROC_H__0054E816_8709_45DB_8346_FE3BCEC49864__INCLUDED_)
#define AFX_UGODBCENGINEPROC_H__0054E816_8709_45DB_8346_FE3BCEC49864__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Engine/UGEngineProc.h"

namespace UGC
{
class UGEXPORT UGODBCEngineProc:public UGEngineProc
{
public:
	UGODBCEngineProc();
	virtual ~UGODBCEngineProc();

	//! \brief 取得数据库服务中所有数据库用户信息
	//! \param &ConnSys [in] 数据库连接，要提供系统用户
	//! \param &aryDBInfos [out] 具体数据库信息
	//! \return 成功 True 
	//! \attention ConnSys一定有系统权限	
	virtual UGbool GetAllDbInfo(UGDsConnection &ConnSys,UGArray<UGDBInfo> &aryDBInfos);

};
}
#endif // !defined(AFX_UGODBCENGINEPROC_H__0054E816_8709_45DB_8346_FE3BCEC49864__INCLUDED_)
