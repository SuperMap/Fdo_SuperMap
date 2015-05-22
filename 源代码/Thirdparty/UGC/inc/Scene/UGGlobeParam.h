// UGGlobeParam.h: interface for the UGGlobeParam class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGGLOBEPARAM_H__41AF85FC_71E8_4B3A_B215_58896441D668__INCLUDED_)
#define AFX_UGGLOBEPARAM_H__41AF85FC_71E8_4B3A_B215_58896441D668__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Scene/UGPrerequisites.h"

namespace UGC 
{

class SCENE_API UGGlobeParam  
{
public:
	UGGlobeParam();
	virtual ~UGGlobeParam();

	UGReal m_dEquatorialRadius;
};
}
#endif // !defined(AFX_UGGLOBEPARAM_H__41AF85FC_71E8_4B3A_B215_58896441D668__INCLUDED_)
