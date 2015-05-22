/*! \file	 UGException.h
 *  \brief	 异常定义类
 *  \author	 ugc team
 *  \attention 
 *  Copyright(c) 1996-2004 SuperMap GIS Technologies,Inc.<br>
 *  All Rights Reserved
 *  \version $Id: UGException.h,v 1.2 2007/10/22 06:30:31 zengzm Exp $
 */

#ifndef UGEXCEPTION_H
#define UGEXCEPTION_H
#include "ugdefs.h"
#include "UGErrorObj.h"

namespace UGC {

//! \brief 异常基类，UGC中自定义的所有异常类，应该从UGException继承
class BASE_API UGException  
{
public:

	//! \brief 构造函数。
	//! \param nErrorID [in] 错误信息的字符串资源ID。
	//! \param strMessage [in] 信息字符串。
	//! \param strCodeFile [in] 异常发生的代码文件。
	//! \param nCodeLine [in] 异常发生的代码行。
	UGException(UGuint nErrorID,
		const UGString& strMessage,
		const UGString& strCodeFile,
		UGint nCodeLine);	
	
	//! \brief 构造函数。
	//! \param nErrorID [in] 错误信息的字符串资源ID。
	//! \param strCodeFile [in] 异常发生的代码文件。
	//! \param nCodeLine [in] 异常发生的代码行。
	UGException(UGuint nErrorID,
		const UGString& strCodeFile,
		UGint nCodeLine);	

	//! \brief 把异常的内容写入到日志中。
	//! \remarks 异常的构造函数中，会调用本函数。
	virtual void WriteToLog();	

	//! \brief 得到内部维护的错误信息结构。
	//! \return 返回内部维护的错误信息结构。
	const UGErrorObj::ErrorInfo& GetErrorInfo() const;	


private:
	//! 内部维护的错误信息结构
	UGErrorObj::ErrorInfo m_ErrorInfo;
};

}

#endif


