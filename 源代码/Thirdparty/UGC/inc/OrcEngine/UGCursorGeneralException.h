/*! \file	 UGCursorGeneralException.h
 *  \brief	 普通意外处理
 *  \author	 ugc team
 *  \attention 
 *  Copyright(c) 1996-2004 SuperMap GIS Technologies,Inc.<br>
 *  All Rights Reserved
 *  \version $Id: UGCursorGeneralException.h,v 1.1.1.1 2004/12/15 06:54:08 litt Exp $
 */

#ifndef UGCURSORGENERALEXCEPTION_H
#define UGCURSORGENERALEXCEPTION_H

#include "Base/ugdefs.h"
#include "Base/UGException.h"

namespace UGC {

//! 普通意外处理类
class ORCENGINE_API UGCursorGeneralException : public UGException
{
public:
	//! 构造函数
	UGCursorGeneralException(UGuint nErrorID,
		const UGString& strMessage,
		const UGString& strCodeFile,
		UGint nCodeLine);

	//! 析构函数
	virtual ~UGCursorGeneralException();

};

}

#endif


