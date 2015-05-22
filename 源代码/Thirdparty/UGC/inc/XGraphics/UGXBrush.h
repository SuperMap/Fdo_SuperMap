// UGXBrush.h: interface for the UGXBrush class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGXBRUSH_H__4C306AFB_3423_40AD_9B82_709CF03A0C39__INCLUDED_)
#define AFX_UGXBRUSH_H__4C306AFB_3423_40AD_9B82_709CF03A0C39__INCLUDED_

#include "Graphics/UGBrush.h"

namespace UGC
{
class XGRAPHICS_API UGXBrush : public UGBrush  
{
public:
	UGXBrush();
	virtual ~UGXBrush();

	virtual UGbool Create();
	virtual UGbool Create(const UGBrushData& BrushData) ;
	virtual UGbool Create(UGint nStyle, UGColor clrColor, 
						UGint nOpacity = 100,
						UGint nGradientAngle = 0,
						UGSize szGradientOffset = UGSize(0, 0),
						UGImage* pImage = NULL);
	
	virtual void DeleteObject();

private:
	static const UGchar BSDownward[8];
	static const UGchar BSCross[8];
	static const UGchar BSCross45[8];
	static const UGchar BSUpward[8];
	static const UGchar BSHorizontal[8];
	static const UGchar BSVertical[8];

private:
	// Brush Style
	// typedef unsigned long XID;
	// typedef XID Pixmap;
	unsigned long BS_Downward;
	unsigned long BS_Cross;
	unsigned long BS_Cross45;
	unsigned long BS_Upward;
	unsigned long BS_Horizontal;
	unsigned long BS_Vertical;

private:
	UGbool m_bNeedRelease;
};

}

#endif // !defined(AFX_UGXBRUSH_H__4C306AFB_3423_40AD_9B82_709CF03A0C39__INCLUDED_)
