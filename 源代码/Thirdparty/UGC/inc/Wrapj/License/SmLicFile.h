// SmLicFile.h: interface for the CSmLicFile class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SMLICFILE_H__2F83F083_4625_47ED_BEA7_0EE3CF13023B__INCLUDED_)
#define AFX_SMLICFILE_H__2F83F083_4625_47ED_BEA7_0EE3CF13023B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CSmLicFile  
{
public:
	CSmLicFile();
	virtual ~CSmLicFile();
	
	void GenerateLicData(
		char* strUser,
		char* strCompany,
		unsigned int dwHardwareID,
		unsigned long pExpiredDate,
		unsigned long pStartDate,
		char *strRegister);
};

#endif // !defined(AFX_SMLICFILE_H__2F83F083_4625_47ED_BEA7_0EE3CF13023B__INCLUDED_)
