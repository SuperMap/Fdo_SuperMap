#ifndef _UGLICENSE_H
#define _UGLICENSE_H

#include "lserv.h"
class UGLData;
class UGL
{
public:
	enum FunctionID
	{
		//! brief 得到许可中的用户信息
		efnGetUserInfo = 1,			
		//! brief 验证许可是否正确
		efnVerifyLicense = 2,		 
		//! brief 打开网络锁
		efnOpenLock = 3,			 
		//! brief 关闭网络锁
		efnCloseLock = 4,			 
	};
	LS_STATUS_CODE C(UGLData &data);

private:
	LS_HANDLE m_handle;
	static int m_nInitCount;
};
class UGLData
{
public:
	UGLData();
	~UGLData();
	UGL::FunctionID functionid;
	char *pchProduct;
	char *pchVersion;
	char *pchUser;
	char *pchCompany;
};
#endif
