/*! \file	 UGOCICursor.h
 *  \brief	 游标类
 *  \author	 ugc team
 *  \attention 
 *  Copyright(c) 1996-2004 SuperMap GIS Technologies,Inc.<br>
 *  All Rights Reserved
 *  \version $Id: UGOCICursor.h,v 1.2 2007/05/10 07:49:21 liwl Exp $
 */

#ifndef UGOCICURSOR_H
#define UGOCICURSOR_H

#include "Base/ugdefs.h"
#include "UGOCIConnection.h"
#include "Base/UGString.h"
#include "Engine/UGFieldInfo.h"
#include "UGOCIBind.h"
#include "UGOCIDefine.h"

namespace UGC {

//! 游标类
class ORCENGINE_API UGOCICursor  
{
public:
	//! 构造函数
	UGOCICursor();

	UGOCICursor(UGOCIConnection* c);

	//! 析构函数
	~UGOCICursor();

	//! 设置数据连接
	void SetConnection(UGOCIConnection* c);

	//! 打开
	void Open();

	//! 关闭
	void Close();	

	//! 换取字段信息
	UGbool GetFieldInfos(UGFieldInfos & fieldInfos,UGFieldInfos &SrcFieldInfos);

	UGbool GetFieldInfo(UGint nPos,
		sb1 *pbScale,
		sb1 *pbIsNULL,
		ub2 *pwType,
		ub2 *pnPrecision,
		ub4 *pnDataSize,
		UGString & strName);

	//分析	
	void Prepare(const UGString& strStmt);
	
	//绑定
	void BindByPos(UGint pos, void* value, 
		UGint size, void* indicator, ub2 type);

	void BindByPos(UGint pos, OCIBind *& binhp,
		void* value, UGint size, void* indicator, ub2 type);

	void BindByPos(UGOCIBind &bind);

	void Bind(UGOCIBinds &binds);


	//输出
	void DefineByPos(UGint pos, void* value,
		UGint size, void* indicator, ub2 type);

	void DefineByPos(UGint pos, OCIDefine *& defhp, 
		void* value, UGint size, void* indicator, ub2 type);

	void DefineByPos(UGOCIDefine &def);

	void Define(UGOCIDefines &defs);
	
	
	//执行取值
	void Execute(UGint times, const UGString & strFileName = "",
		UGint nLineNumber = 0);

	void Fetch(UGint rows);

protected:
	void CheckError(sword status);
public:
	UGOCIConnection* conn;
	OCIStmt* stmthp;
	OCIDefine* m_pOCIDefine;
	UGString m_strFileName;
	UGint m_nLineNumber;
	UGString m_strSQL;
	UGbool m_bOpened;
};

}

#endif

