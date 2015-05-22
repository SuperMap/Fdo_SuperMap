// UGL2.h: interface for the UGL2 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGL2_H__C69F6BD8_BF19_45E8_BEB8_09D9DD74630B__INCLUDED_)
#define AFX_UGL2_H__C69F6BD8_BF19_45E8_BEB8_09D9DD74630B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "hasp_hl.h"
#include "license_def.h"
#include "UGLData.h"

class UGL2  
{
public:
	UGL2();
	virtual ~UGL2();

public:
	hasp_status_t C(UGLData &data);
	hasp_status_t D();
	hasp_status_t F(UGLData &data);

	char* I(char *info);

private:
	hasp_handle_t m_handle;
	static int m_nInitCount;
};


#endif // !defined(AFX_UGL2_H__C69F6BD8_BF19_45E8_BEB8_09D9DD74630B__INCLUDED_)
