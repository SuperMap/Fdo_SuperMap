// UGPSRgn.h: interface for the UGPSRgn class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGPSRGN_H__1CC8315E_F964_4237_B4AF_30EDA4D84B93__INCLUDED_)
#define AFX_UGPSRGN_H__1CC8315E_F964_4237_B4AF_30EDA4D84B93__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Graphics/UGRgn.h"

namespace UGC
{
class UGPSRgn : public UGRgn  
{
public:
	UGPSRgn();
	virtual ~UGPSRgn();

	// 区域之间的复制
	virtual UGbool Copy(const UGRgn& Rgn);
	
	virtual UGbool CreateRect(UGint x1, UGint y1, UGint x2, UGint y2);
	virtual UGbool CreateRect(UGRect &rect);
	virtual UGbool CreateElliptic(UGint x1, UGint y1, UGint x2, UGint y2);
	virtual UGbool CreateElliptic(UGRect &rect);
	
	virtual UGbool CreateRoundRect(UGint x1, UGint y1, UGint x2, UGint y2, UGint x3, UGint y3);
	virtual UGbool CreateRoundRect(UGRect &rect, UGPoint point);

	virtual UGbool CreatePolygon(const UGPoint* pPoints, UGint nCount);
//	virtual UGbool CreatePolygon(const LPPOINT pPoints, UGint nCount);
	virtual UGbool CreatePolyPolygon(const UGPoint* pPoints, const UGint* pPolyCounts, UGint nCount);
//	virtual UGbool CreatePolyPolygon(const LPPOINT pPoints, const LPINT pPolyCounts, UGint nCount);
	
	// 删除Rgn
	virtual void DeleteObject();
	
	// 区域的操作函数
	virtual UGbool Combine(const UGRgn& Rgn1, const UGRgn& Rgn2, UGint nCombineMode);
	
	// 获取区域的边框
	virtual UGRect GetBox() const;
	
	// 移动区域
	virtual void Offset(UGint x, UGint y);
	virtual void Offset(const UGPoint& point);
	
	// 判断两个区域是否相等
	virtual UGbool IsEqual(const UGRgn& Rgn) const;
	
	// 判断点,矩形是否在区域中
	virtual UGbool PtInRegion(UGint x, UGint y) const;
	virtual UGbool PtInRegion(const UGPoint &point) const;
	virtual UGbool RectInRegion(UGint x1, UGint y1, UGint x2, UGint y2) const;
	virtual UGbool RectInRegion(const UGRect &rect) const;
	
	virtual UGbool GetRegionData(UGRegionData &RgnData) const;

	
private:
	UGbool m_bNeedRelease;
};
}
#endif // !defined(AFX_UGPSRGN_H__1CC8315E_F964_4237_B4AF_30EDA4D84B93__INCLUDED_)
