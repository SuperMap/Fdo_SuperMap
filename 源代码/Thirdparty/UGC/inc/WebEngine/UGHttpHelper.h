//////////////////////////////////////////////////////////////////////////
//                    _   _   ____   ____                    
//   Project         | | | | / ___) / ___)                   
//                   | | | || | __ | |                       
//                   | |_| || |_\ || \___                    
//                    \____/ \____| \ ___)     2.0           
//                                                           
//!  \file UGHttpHelper.h
//!  \brief UGHttpHelper 的接口定义。
//!  \details 文件详细信息。
//!  \author duxiaomin。
//!  \attention 
//!   Copyright (c) 1996-2007 SuperMap GIS Technologies,Inc.  <br> 
//!   All Rights Reserved.
//!  \version 2.0
//////////////////////////////////////////////////////////////////////////

#ifndef UGHTTPHELPER_H
#define UGHTTPHELPER_H


#include "Base/ugexports.h"
#include "Base/UGString.h"
#include "Base/UGFileStream.h"
#include "Base/UGDict.h"
#include "Algorithm/UGRect2D.h"

namespace UGC
{
	
//! \brief Http助手，提供Web数据源使用到的Http请求及解析的相关操作。
//! \remarks 备注信息。
class WEBENGINE_API UGHttpHelper
{
public:
	UGHttpHelper();

	virtual ~UGHttpHelper();

	enum RequestMethod
	{
		GET = 0,
		POST = 1
	};

	enum HttpFileType
	{
		CHARACTER = 0,
		BINARY = 1
	};

	enum ProtocolType
	{
		FTP = 1,
		GOPHER = 2,
		HTTP = 3
	};

	//! \brief 通过URL请求得到服务器响应文件。
	//! \param strURL 服务器URL地址[in]。
	//! \param strUser 登录服务器用户名,匿名访问置空[in]。
	//! \param strPasswd 登录服务器用密码,匿名访问置空[in]。
	//! \param reqMmethod http请求方式,post或get,默认置空[in]。
	//! \param fileType 请求文件流格式,二进制或文本,默认置空[in]。
	//! \return 请求得到的文件路径和文件名,存放在临时路径。
	//! \remarks 。
	//! \attention 。
	static UGString RequestFile(UGString strURL, UGString strUser, 
								UGString strPasswd, RequestMethod reqMmethod, 
								HttpFileType fileType);

	//! \brief 通过URL请求得到服务器响应文件并保存到揸定路径。
	//! \param strURL 服务器URL地址[in]。
	//! \param strDstPath 请求得到的文件的地址和文件各[in]。
	//! \param strUser 登录服务器用户名,匿名访问置空[in]。
	//! \param strPasswd 登录服务器用密码,匿名访问置空[in]。
	//! \param reqMmethod http请求方式,post或get,默认置空[in]。
	//! \param fileType 请求文件流格式,二进制或文本,默认置空[in]。
	//! \return 是否成功得到文件,成功返回TRUE,失败返回FALSE。。
	//! \remarks 。
	//! \attention 。
	static UGbool RequestFile2(UGString strURL,UGString strDstPath, 
							   UGString strUser, UGString strPasswd, 
							   RequestMethod reqMmethod, HttpFileType fileType);

	//! \brief URL参数解析。
	//! \param pstrURL URL字符串[in]。
	//! \param dwServiceType 网络协议种类[out]。
	//! \param strServer 网络服务器名或IP地址[out]。
	//! \param strObject URL中的Path和查询选项[out]。
	//! \param nPort 端口号[out]。
	//! \return 是否解析成功,成功返回TRUE,失败返回FALSE。
	static UGbool UGParseURL(UGString strURL, UGuint& dwServiceType, 
							 UGString& strServer, UGString& strObject, 
							 UGushort& nPort );

	//! \brief URL参数解析。
	//! \param pstrURL URL字符串[in]。
	//! \param dwServiceType 网络协议种类[out]。
	//! \param strServer 网络服务器名或IP地址[out]。
	//! \param strPath URL中的Path[out]。
	//! \param strPath URL中的查询选项[out]。
	//! \param nPort 端口号[out]。
	//! \return 是否解析成功,成功返回TRUE,失败返回FALSE。
	static UGbool UGParseURL2(UGString strURL, UGuint& dwServiceType, 
							  UGString& strServer, UGString& strPath, 
							  UGString& strQuery, UGushort& nPort);

	//! \brief URL参数解析。
	//! \param pstrURL URL字符串[in]。
	//! \param strServerPath URL中的ServerName、Port、Path串[out]。
	//! \param strQuery URL中的查询选项[out]。
	//! \return 是否解析成功,成功返回TRUE,失败返回FALSE。
	static UGbool UGParseURL3(UGString strURL, 
							  UGString& strServerPath, UGString& strQuery);	
	
	static UGbool URLtoKVPairs(const UGString& strURLsrc,
							   UGString& strBaseURL, UGDict<UGString,UGString>& dictQueryPairs);

	static UGbool KVPairstoURL(const UGString& strBaseURL, const UGDict<UGString,UGString>& dictQueryPairsUGString, 
							   UGString& strURLdes);

	//! \brief 从URL中得到四至信息。
	//! \param strURL 请求的URL字符串[in]。
	//! \param rcGeoRef 四至信息[out]。
	//! \return 是否解析成功,成功返回TRUE,失败返回FALSE。
	static UGbool GetBBox(const UGString& strURL,UGRect2D& rcGeoRef);

	//! \brief 测试一个OGC Web数据源的请求是否成功。
	//! \param strURL OGC Web数据源的请求,包括GetCapabilitys,DescribFeature等[in]。
	//! \param strUser Http访问的用户名[in]。
	//! \param strPasswd Http访问的密码[in]。
	//! \return 成功返回TRUE,失败返回FALSE。。
	static UGbool CheckOGCRequest(UGString strURL,
								  UGString strUser = "",UGString strPasswd= "");

};
	
}
#endif // !defined(UGHTTPHELPER_H)
