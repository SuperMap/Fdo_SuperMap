// UGXPen.h: interface for the UGXPen class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGXPEN_H__7E425D53_781B_4AA1_9713_B41DBD68150D__INCLUDED_)
#define AFX_UGXPEN_H__7E425D53_781B_4AA1_9713_B41DBD68150D__INCLUDED_

#include "Graphics/UGPen.h"

namespace UGC
{
class XGRAPHICS_API UGXPen : public UGPen  
{
public:
	UGXPen();
	virtual ~UGXPen();	

	virtual UGbool Create();
	virtual UGbool Create(const UGPenData& PenData);
	virtual UGbool Create(
					UGint nStyle,
					UGint nWidth = 0,
					UGColor clrColor = UGRGB(0, 0, 0),
					UGint nCapStyle = 0,
					UGint nJoinStyle = 0);
	
	virtual void DeleteObject();

protected:
	static inline UGint ConvertJoinStyle(UGPen::JoinStyle eJoinStyle) ;
	static inline UGint ConvertCapStyle(UGPen::CapStyle eCapStyle) ;
	static inline UGint ConvertPenStyle(UGPen::PenStyle ePenStyle) ;

protected:
	UGbool m_bNeedRelease;

	// ÐéÏßÑùÊ½
	static const UGchar PS_Dash[2] ;
	static const UGchar PS_Dot[2] ;
	static const UGchar PS_DashDot[4] ;
	static const UGchar PS_DashDotDot[6] ;

};

}

#endif // !defined(AFX_UGXPEN_H__7E425D53_781B_4AA1_9713_B41DBD68150D__INCLUDED_)
