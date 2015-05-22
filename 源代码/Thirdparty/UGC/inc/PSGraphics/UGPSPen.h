// UGPSPen.h: interface for the UGPSPen class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGPSPEN_H__D6436503_C6C8_458A_B820_F54DEF0AD94F__INCLUDED_)
#define AFX_UGPSPEN_H__D6436503_C6C8_458A_B820_F54DEF0AD94F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Graphics/UGPen.h"

namespace UGC
{
class UGPSPen : public UGPen  
{
public:
	UGPSPen();
	virtual ~UGPSPen();
//
	virtual UGbool Create();
	virtual UGbool Create(const UGPenData& PenData);
	virtual UGbool Create(
		UGint nStyle,
		UGint nWidth = 0,
		UGColor clrColor = UGRGB(0, 0, 0),
		UGint nCapStyle = 0,
		UGint nJoinStyle = 0);
	
	//
	virtual void DeleteObject();

private:
	UGbool m_bNeedRelease;
};
}
#endif // !defined(AFX_UGPSPEN_H__D6436503_C6C8_458A_B820_F54DEF0AD94F__INCLUDED_)
