#ifndef _UGLDATA_H
#define _UGLDATA_H
#include "license_def.h"

#pragma warning(disable:4996 4244)

class UGLData
{
public:
	UGLData();
	~UGLData();
	FunctionID functionid;	
	Module chModuleID;
	LicMode licMode;
	char *pchProduct;
	char *pchVersion;
	char *pchUser;
	char *pchCompany;	
};
#endif
