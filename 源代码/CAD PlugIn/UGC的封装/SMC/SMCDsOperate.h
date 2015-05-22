/*! 
	\file	SMCDsOperate.h
    \brief	数据源操作类
	\author	马 俊
	\attention
	----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2007 SuperMap GIS Technologies,Inc.                            <br>
    All Rights Reserved.                                                              <br>
    ----------------------------------------------------------------------------------<br> 
	\version 2007-9-28 初始化版本
*/

#include "SMC.h"
#include "SMCDsConnection.h"

const  _tstring SMC_CONNECTION_TYPE			= _T("type");
const  _tstring SMC_CONNECTION_SERVER		= _T("server");
const  _tstring SMC_CONNECTION_DATABASE		= _T("database");
const  _tstring SMC_CONNECTION_USER			= _T("user");
const  _tstring SMC_CONNECTION_PWD			= _T("pwd");
const  _tstring SMC_CONNECTION_FILE			= _T("file");

//! \brief		根据引擎名字得到引擎类型
//! \return		SMCDsConnection::SMEngineType 引擎类型
//! \param		[in]strSource 引擎名字
SMCDsConnection::SMEngineType EngNameToEngType(const _tstring strSource);



