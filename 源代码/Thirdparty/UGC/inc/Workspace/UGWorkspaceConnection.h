/*! \file	 UGWorkspaceConnection.h
 *  \brief	 工作空间连接信息类定义
 *  \author	 xielin
 *  \attention 
 *  Copyright(c) 1996-2004 SuperMap GIS Technologies,Inc.<br>
 *  All Rights Reserved
 *  \version $Id: UGWorkspaceConnection.h,v 1.3 2007/09/24 09:02:02 xielin Exp $
 */

#if !defined(AFX_UGWORKSPACECONNECTION_H__FD9EB000_6044_422A_B5AF_CD922BEA06BC__INCLUDED_)
#define AFX_UGWORKSPACECONNECTION_H__FD9EB000_6044_422A_B5AF_CD922BEA06BC__INCLUDED_

#include "Base/ugdefs.h"
#include "Base/UGString.h"
//#include "Workspace/UGWorkspace.h"

namespace UGC {
class UGWorkspace;

class WORKSPACE_API UGWorkspaceConnection  
{
public:		
	//! \brief 默认构造函数
	UGWorkspaceConnection();

	//! \brief 构造函数
	UGWorkspaceConnection(
		UGint nWorkspaceType,
		const UGString& strWorkspaceName,
		const UGString& strServer,
		const UGString& strDriver,
		const UGString& strDatabase,
		const UGString& strUser,
		const UGString& strPassword);

	//! \brief 构造函数
	UGWorkspaceConnection(
		UGint nWorkspaceType,
		const UGString& strWorkspaceName,
		const UGString& strServer,
		const UGString& strDriver,
		const UGString& strDatabase,
		const UGString& strUser,
		const UGString& strPassword,
		UGint nVersion,
		UGbool bFailIfExists);

	//! 析构函数
	~UGWorkspaceConnection();

	void operator =(const UGWorkspaceConnection &conn);

	UGbool operator ==(const UGWorkspaceConnection &conn);

public:
	//! \brief 工作空间类型
	UGint	m_nWorkspaceType;
	
	//! \brief 数据库名
	UGString		m_strDatabase;

	//! \brief 服务名，如果是文件型工作空间，那么就是全路径加上文件名
	UGString		m_strServer;

	//! \brief 用户名
	UGString		m_strUser;
	
	//! \brief 密码
	UGString		m_strPassword;

	//! \brief 工作空间名字
	UGString		m_strWorkspaceName;

	//! \brief 针对文件型工作空间有效，如果文件已经存在是否返回失败,默认是true
	UGbool			m_bFailIfExists;
	
	//! \brief	工作空间的版本，默认是0
	UGint			m_nVersion;

	//! \brief ODBC Driver
	UGString		m_strDriver;	

};


}

#endif // !defined(AFX_UGWORKSPACECONNECTION_H__FD9EB000_6044_422A_B5AF_CD922BEA06BC__INCLUDED_)
