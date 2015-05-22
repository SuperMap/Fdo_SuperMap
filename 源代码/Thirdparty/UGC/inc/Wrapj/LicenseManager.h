// LicenseManager.h: interface for the LicenseManager class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LICENSEMANAGER_H__5132C14B_4D66_4534_A932_712256583208__INCLUDED_)
#define AFX_LICENSEMANAGER_H__5132C14B_4D66_4534_A932_712256583208__INCLUDED_


#include "Wrapj/SuperMapStubH.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class LicenseManager  
{
public:
	LicenseManager();
	virtual ~LicenseManager();
public:
	UGlong m_LicenseHandle;
	UGlong m_LicenseDataHandle;

};
LicenseManager* GetLicenseManager();
#endif // !defined(AFX_LICENSEMANAGER_H__5132C14B_4D66_4534_A932_712256583208__INCLUDED_)
