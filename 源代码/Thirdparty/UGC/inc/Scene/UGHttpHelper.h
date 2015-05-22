// UGHttpHelper.h: interface for the UGHttpHelper class.
//
//////////////////////////////////////////////////////////////////////

#ifndef UGHTTPHELPER_H
#define UGHTTPHELPER_H

#include "Scene/UGPrerequisites.h"
#include "Base/UGFileStream.h"
#include "Algorithm/UGRect2D.h"

namespace UGC{
	
//! \brief Http助手，提供Web数据源使用到的Http请求及解析的相关操作。
//! \remarks 备注信息。
class SCENE_API UGHttpHelper
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
static UGbool RequestFile2(UGString strURL,UGString strDstPath, UGString strUser, 
	UGString strPasswd, RequestMethod reqMmethod, HttpFileType fileType);


};
	
}
#endif // !defined(UGHTTPHELPER_H)
