/* 
	\file UGDissolve.h
	\brief 消融分析类，包括面消融、线消融、接边等操作
	\author ugc team
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>更新说明：</b>
	<em>1、第一条说明。</em>
	<em>2、第二条说明。</em>
*/

#ifndef UGDISSOLVE_H
#define UGDISSOLVE_H

#include "Base/ugdefs.h"
#include "Base/UGString.h"
#include "Engine/UGDataset.h"
#include "Engine/UGRecordset.h"

namespace UGC {

class OPERATION_API UGDissolve  
{
public:
	UGDissolve();
	virtual ~UGDissolve();

};

}

#endif // !defined(UGDISSOLVE_H)
