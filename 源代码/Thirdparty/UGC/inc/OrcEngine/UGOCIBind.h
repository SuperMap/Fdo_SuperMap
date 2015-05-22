/*! \file	 UGOCIBind.h
 *  \brief	 UGOCIBind
 *  \author	 ugc team
 *  \attention 
 *  Copyright(c) 1996-2004 SuperMap GIS Technologies,Inc.<br>
 *  All Rights Reserved
 *  \version $Id: UGOCIBind.h,v 1.4 2007/04/30 05:07:48 xielin Exp $
 */

#ifndef UGOCIBIND_H
#define UGOCIBIND_H

#include "Base/ugdefs.h"
#include "Base/UGString.h"
#include "Base/UGArray.h"

#ifndef OCI_ORACLE
#include "oci.h"
#endif

namespace UGC {

class ORCENGINE_API UGOCIBind  
{
public:
	UGOCIBind();
	UGOCIBind(UGshort mind,ub2 mType,UGint mPos,UGint mSize,
		OCIBind* mhp,void* mData,const UGString& mName);
	~UGOCIBind();

	void operator = (const UGOCIBind &bind)
	{
		indicator = bind.indicator;
		nType = bind.nType;
		nPos = bind.nPos;
		nSize = bind.nSize;
		bindhp = bind.bindhp;
		pData = bind.pData;
		strName = bind.strName;
		pInd = bind.pInd;
	}
public:
	UGshort		indicator;
	UGshort *	pInd;
	ub2			nType;
	UGint		nPos;
	UGint		nSize;
	OCIBind*	bindhp;
	void*		pData;
	UGString	strName;
};

typedef UGArray<UGOCIBind> UGOCIBinds;

}

#endif


