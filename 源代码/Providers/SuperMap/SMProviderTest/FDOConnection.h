#ifndef __FDOCONNECTION_H__
#define __FDOCONNECTION_H__

#include "FDOCommon.h"

FdoIConnection *GetFDOConnection(char * strEngineType = "sdb", bool bImage = false);

#endif