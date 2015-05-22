/*! \file	 UGErrorObj.h
 *  \brief	 错误对象定义文件
 *  \author	 ugc team
 *  \attention 
 *  Copyright(c) 1996-2004 SuperMap GIS Technologies,Inc.<br>
 *  All Rights Reserved
 *  \version $Id: UGErrorObj.h,v 1.9 2007/10/11 09:13:39 zengzm Exp $
 */

#ifndef UGERROROBJ_H
#define UGERROROBJ_H

#include "ugdefs.h"
#include "UGString.h"
#include "UGArray.h"
#include "ugplatform.h"
//#include "UGLogFile.h"

namespace UGC {

typedef void (*ErrorInfoProc)(const UGchar* pchErrorInfo);

//! 错误对象
class BASE_API UGErrorObj  
{
	friend class UGLogFile;
public:
	//! 错误信息
	struct ErrorInfo
	{
		//! \brief 错误发生所在的线程id
		UGint m_nThreadId;
		//! 编号, 资源字符串id
		UGint m_nID;
		//! 描述
		UGString m_strMessage; 
		//! 文件名
		UGString m_strCodeFile;
		//! 行号
		UGint m_nCodeLine;
		//! 默认构造函数
		ErrorInfo() {
			m_nThreadId = -1; 
			m_nID = 0;			//! 表示还没有设置错误, 
			m_nCodeLine = -1;	//! 表示非法值
		}

		ErrorInfo(UGuint nThreadId,UGint nID,UGString strMessage,
			UGString strCodeFile,UGint nCodeLine) 
		{
			m_nThreadId = nThreadId;
			m_nID = nID;
			m_strMessage = strMessage;
			m_strCodeFile = strCodeFile;
			m_nCodeLine = nCodeLine;
		}
	};

	UGErrorObj();	
private:
	UGErrorObj(const UGErrorObj&);
	UGErrorObj& operator=(const UGErrorObj&);
	
public:	
	~UGErrorObj();

	//! \brief 得到错误对象的唯一实例, 不要直接定义错误对象
	//! \remarks 要想得到错误信息, 必须先调用Startup 或打开日志文件
	static UGErrorObj& GetInstance(); 

	//! \brief 启动错误对象
	//! \remarks 错误对象必须先启动一下，才能使用; 内部使用LogFile实现
	//! \return 成功启动返回true,失败返回false
	UGbool Startup();

	//! \return 返回是否启动
	UGbool IsStartup();

	//! \brief 设置错误处理的回调函数指针
	static void SetErrorInfoProc(ErrorInfoProc pErrorInfoFun);	

	//! 得到错误对象个数
	UGint GetCount() const;
	
	//! 清空错误对象
	void Clear();

	//! 设置容量大小
	void SetCapacity(UGint nCapacity);

	//! 获取容量大小
	UGint GetCapacity() const;

	ErrorInfo GetAt(UGint nIndex) const;

	//! \brief 得到最后一条错误信息
	//! \param bBythread 是否只考虑当前线程,默认为考虑; 如果为true,则会取出在当前线程中的最后一条错误信息
	//! 如果为false,则取出所有错误信息中的最后一条
	//! \return 返回最后一条错误信息
	ErrorInfo GetLast(UGbool bBythread=TRUE) const;

	void Dump(UGString& strErrorInofs,UGbool bBythread=TRUE) const;

	static void Format(const ErrorInfo& errorInfo,UGString& strErrorInfo,UGbool bBythread=TRUE);

private:
	//! 添加错误信息
	void Add(const ErrorInfo& errorInfo);

	//! 添加错误信息
	void Add(UGuint nThreadID, UGuint nID, UGString m_strCodeFile, UGint m_nCodeLine);

private:

	// by zengzm 2007-10-11 错误对象内部采用日志文件来实现, 这些东东先注释起来
	//! 是否是循环的
//	UGbool m_bCycled;
	//! 下一个填充位置
//	UGint m_nPos;
	//! 存储错误信息
//	UGArray<ErrorInfo> m_ErrorObjs;	

	
	//! \brief 错误信息回调函数指针
	static ErrorInfoProc ms_pErrorInfoFun;
};

}

#endif

