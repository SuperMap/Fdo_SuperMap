/*! \file	 UGOCIDefine.h
 *  \brief	 UGOCIDefine
 *  \author	 ugc team
 *  \attention 
 *  Copyright(c) 1996-2004 SuperMap GIS Technologies,Inc.<br>
 *  All Rights Reserved
 *  \version $Id: UGOCIDefine.h,v 1.2 2005/12/06 06:13:57 chengx Exp $
 */

#ifndef UGOCIDEFINE_H
#define UGOCIDEFINE_H

#include "Base/ugdefs.h"
#include "Base/UGArray.h"
#include "Base/UGString.h"

#ifndef OCI_ORACLE
#include "oci.h"
#endif


namespace UGC {

class ORCENGINE_API UGOCIDefine  
{
public:
	UGOCIDefine();
	UGOCIDefine(UGshort mind,ub2 mType,UGint mPos,UGint mSize,
		OCIDefine * mhp,void* mData, const UGString& mName);
	~UGOCIDefine();
	void operator = (const UGOCIDefine &def);

public:
	UGshort		indicator;
	short *		pInd;

	ub2			nType;
	UGint		nPos;
	UGint		nSize;
	OCIDefine*	dfhp;
	void *		pData;
	UGString	strName;
};

typedef UGArray<UGOCIDefine> UGOCIDefines;

}

#endif


