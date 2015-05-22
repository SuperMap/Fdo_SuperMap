#ifndef _UGLICENSE_H
#define _UGLICENSE_H

#include "lserv.h"
#include "UGL2.h"

class UGL
{
public:	
	LS_STATUS_CODE C(UGLData &data);
	char* I(UGLData &data);
	char* S(UGLData &data);

private:
	void GetIniFileName(char *strFileName);
	void GetRegisterSubKey(Module ProductID, char *strProductName);
	int ReadProductLicMode(char *pchProduct);
	
	LS_STATUS_CODE LicAladdin(UGLData &data);
	LS_STATUS_CODE LicLM(UGLData &data);
	LS_STATUS_CODE LicComputerName(UGLData &data);

private:
	UGL2 m_ugl2;
	LS_HANDLE m_handle;
	static int m_nInitCount;
};
#endif
