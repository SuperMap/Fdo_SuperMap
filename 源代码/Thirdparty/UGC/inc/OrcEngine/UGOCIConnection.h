/*! \file	 UGOCIConnection.h
 *  \brief	 Oralce OCI连接类
 *  \author	 ugc team
 *  \attention 
 *  Copyright(c) 1996-2004 SuperMap GIS Technologies,Inc.<br>
 *  All Rights Reserved
 *  \version $Id: UGOCIConnection.h,v 1.2 2007/04/05 06:57:41 zhouqin Exp $
 */

#ifndef UGOCICONNECTION_H
#define UGOCICONNECTION_H

#include "Base/ugdefs.h"
#include "OrcEngine/UGOCIBind.h"

#ifndef OCI_ORACLE
#include "oci.h"
#endif

namespace UGC {

//! 数据连接类
class ORCENGINE_API UGOCIConnection  
{
public:
	//! 构造函数
	UGOCIConnection();

	//! 析构函数
	~UGOCIConnection() {
		Disconnect();
	}

public:
	//回撤
	UGbool TransRollBack();

	//提交
	UGbool TransCommit();
	
	//! 连接
	void Connect(const UGchar* dblink, const UGchar* username, const UGchar* password,
		const UGint nMinConn, const UGint nMaxConn, const UGint nIncConn);
		
	//! 断开连接
	void Disconnect();

	//! 判断是否连接
	UGbool IsConnected() { return connected; }

	//! 检查错误
	void CheckError(OCIError* errhp,UGint status);	
	
	//! 执行
	UGbool ExecUpdate(const UGchar* pcSQL,
		UGOCIBinds& binds,
		const UGchar* pcFile, 
		UGint nLine,
		UGbool bCanTrans);

	//! 执行
	UGbool ExecUpdate(const UGchar* pcSQL,
		const UGchar* pcFile,
		UGint nLine,
		UGbool bCanTrans);

	//! 执行
	UGuint ExecStatCount(const UGchar* pcSQL,
		const UGchar* pcFile,
		UGint nLine);

	//! 执行
	UGuint ExecStatCount(const UGchar* pcSQL,
		UGOCIBinds& binds,
		const UGchar* pcFile,
		UGint nLine);

public:	
	OCIEnv* envhp;      
	
	OCIError* errhp;
	
	OCIServer* srvhp;

	OCISvcCtx* svchp;
	OCISession* usrhp;
protected:
	//! 是否连接
	UGbool connected;

private:
	//连接池 属性
	OCICPool *poolhp;
	
	//! brief 连接池名字
	OraText *poolName;
	
	//! brief 连接池长度
	sb4 poolNameLen;
};

}

#endif

