// UGProjectionManager.h: interface for the UGProjectionManager class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGPROJECTIONMANAGER_H__3D504681_5B49_444D_8B4B_60443B570F96__INCLUDED_)
#define AFX_UGPROJECTIONMANAGER_H__3D504681_5B49_444D_8B4B_60443B570F96__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Base/UGMarkup.h"

namespace UGC {

class UGProjectionManager  
{
public:
	static UGProjectionManager& GetInstance(); 

	UGProjectionManager();
	~UGProjectionManager();

public:	
	UGMarkup m_PrjMarkup;
	UGMarkup m_GeoMarkup;
	UGMarkup m_HorizonMarkup;
	UGMarkup m_PrimeMarkup;
	UGMarkup m_SpheroidMarkup;
	UGMarkup m_ProjectionMarkup;

};
//extern UGProjectionManager g_ProjectionManager;

}
#endif // !defined(AFX_UGPROJECTIONMANAGER_H__3D504681_5B49_444D_8B4B_60443B570F96__INCLUDED_)
