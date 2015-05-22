// UJImage.h: interface for the UJImage class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UJIMAGE_H__FD0C7006_54CA_4E04_A527_94C820CD9B34__INCLUDED_)
#define AFX_UJIMAGE_H__FD0C7006_54CA_4E04_A527_94C820CD9B34__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Wrapj/SuperMapStubH.h"

class UJImage  
{
public:
	UJImage();
	UJImage(UGint nWidth, UGint nHeight);
	virtual ~UJImage();

	void SetSize(UGint nWidth, UGint nHeight);
public:
	UGImage* m_pRealImage;
	UGbyte* m_pTempBits;
	UGbyte* m_pbuf;
	UGint* GetBits();
	void SetBits(UGint* buf,UGint nLength);

};

#endif // !defined(AFX_UJIMAGE_H__FD0C7006_54CA_4E04_A527_94C820CD9B34__INCLUDED_)
