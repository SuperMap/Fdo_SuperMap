// UGXRgn.h: interface for the UGXRgn class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGXRGN_H__6277ACA6_0BD9_47C0_AC6C_5ED80C87EC70__INCLUDED_)
#define AFX_UGXRGN_H__6277ACA6_0BD9_47C0_AC6C_5ED80C87EC70__INCLUDED_

#include "Graphics/UGRgn.h"
#include <X11/Xlib.h>	// for XPoint

namespace UGC
{

class XGRAPHICS_API UGXRgn : public UGRgn  
{
public:
	UGXRgn();
	virtual ~UGXRgn();

	virtual UGbool Copy(const UGRgn& Rgn);
	virtual UGbool CreateRect(UGint x1, UGint y1, UGint x2, UGint y2);
	virtual UGbool CreateRect(UGRect &rect);
	virtual UGbool CreateElliptic(UGint x1, UGint y1, UGint x2, UGint y2);
	virtual UGbool CreateElliptic(UGRect &rect);
	virtual UGbool CreateRoundRect(UGint x1, UGint y1, UGint x2, UGint y2, UGint x3, UGint y3);
	virtual UGbool CreateRoundRect(UGRect &rect, UGPoint point);
	virtual UGbool CreatePolygon(const UGPoint* pPoints, UGint nCount) ;
	virtual UGbool CreatePolyPolygon(const UGPoint* pPoints, const UGint* pPolyCounts, UGint nCount) ;
	virtual void DeleteObject();
	virtual UGbool Combine(const UGRgn& Rgn1, const UGRgn& Rgn2, UGint nCombineMode);
	virtual UGRect GetBox() const;
	virtual void Offset(UGint x, UGint y);
	virtual void Offset(const UGPoint& point);
	virtual UGbool IsEqual(const UGRgn& Rgn) const;
	virtual UGbool PtInRegion(UGint x, UGint y) const;
	virtual UGbool PtInRegion(const UGPoint &point) const;
	virtual UGbool RectInRegion(UGint x1, UGint y1, UGint x2, UGint y2) const;
	virtual UGbool RectInRegion(const UGRect &rect) const;
	virtual UGint GetDataSize() const;
	virtual UGbool GetRegionData(UGRegionData &RgnData) const ;

	//added by xielin 2007-08-15 加入两个函数，为x11做优化
	//! \brief 根据设备坐标创建，主要是为X11优化，x11绘制多边形的时候用到了，就不要坐标转来转去，浪费效率
	UGbool CreatePolygon_Dp(XPoint* pPoints, UGint nCount) ;
	//! \brief 根据设备坐标创建，主要是为X11优化，x11绘制多边形的时候用到了，就不要坐标转来转去，浪费效率
	UGbool CreatePolyPolygon_Dp(XPoint* pPoints, const UGint* pPolyCounts, UGint nCount) ;

protected:
	UGRegionData m_RegionData;
	UGbool m_bNeedRelease;

};

}

#endif // !defined(AFX_UGXRGN_H__6277ACA6_0BD9_47C0_AC6C_5ED80C87EC70__INCLUDED_)
