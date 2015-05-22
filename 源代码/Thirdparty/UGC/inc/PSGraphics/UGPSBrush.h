// UGPSBrush.h: interface for the UGPSBrush class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGPSBRUSH_H__EA477372_F1B0_44CB_9FBC_0861844FAE18__INCLUDED_)
#define AFX_UGPSBRUSH_H__EA477372_F1B0_44CB_9FBC_0861844FAE18__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Graphics/UGBrush.h"
namespace UGC
{
class PSGRAPHICS_API UGPSBrush : public UGBrush  
{
public:
	UGPSBrush();
	virtual ~UGPSBrush();

	virtual UGbool Create();
	virtual UGbool Create(const UGBrushData& BrushData);
	virtual UGbool Create(UGint nStyle, UGColor clrColor, 
					UGint nOpacity = 100,
					UGint nGradientAngle = 0,
					UGSize szGradientOffset = UGSize(0, 0),
					UGImage* pImage = NULL);	
	virtual void DeleteObject();
private:
	UGbool m_bNeedRelease;	
};
}

#endif // !defined(AFX_UGPSBRUSH_H__EA477372_F1B0_44CB_9FBC_0861844FAE18__INCLUDED_)
