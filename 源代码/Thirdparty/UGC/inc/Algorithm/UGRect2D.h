#ifndef UGRECT2D_H
#define UGRECT2D_H
#include "Base/ugdefs.h"
#include "UGPoint2D.h"

namespace UGC {

class ALGORITHM_API UGRect2D  
{
public:
	UGdouble left;
	UGdouble top;
	UGdouble right;
	UGdouble bottom;	// 注意：这里的bottom < top
public:
	UGRect2D();	
	UGRect2D(UGdouble l,UGdouble t,UGdouble r,UGdouble b);
	UGRect2D(const UGPoint2D& p,const UGSize2D& s);
	UGRect2D(const UGPoint2D& tl,const UGPoint2D& br);	
	friend ALGORITHM_API UGbool operator==(const UGRect2D& p,const UGRect2D& q);
	friend ALGORITHM_API UGbool operator!=(const UGRect2D& p,const UGRect2D& q);
	void SetRect(UGdouble l,UGdouble t,UGdouble r,UGdouble b);
	void SetRect(const UGPoint2D& tl,const UGPoint2D& br);
	void SetEmpty();
	UGbool IsEmpty() const;
	UGbool IsNull() const;
	UGdouble Width() const;
	UGdouble  Height() const;

	UGPoint2D& TopLeft();
	const UGPoint2D& TopLeft() const;	
	UGPoint2D TopRight() const;

	UGPoint2D& BottomRight();		
	const UGPoint2D& BottomRight() const;
	UGPoint2D BottomLeft() const;
	
	UGPoint2D CenterPoint() const;
	UGSize2D Size() const;
	void SwapLeftRight();
	void SwapTopBottom();	
	
	UGbool PtInRect(const UGPoint2D& p) const;
	UGbool Contains(const UGRect2D& r) const;
	UGbool Withins(const UGRect2D& r) const;
	UGbool IsIntersect(const UGRect2D& r) const;
	
	void Normalize();
	
	void Offset(UGdouble x,UGdouble y);
	void Offset(const UGSize2D& s);
	void Offset(const UGPoint2D& p);
	
	void Inflate(UGdouble margin);
	void Inflate(UGdouble hormargin,UGdouble vermargin);
	void Inflate(UGdouble leftmargin,UGdouble topmargin,UGdouble rightmargin,UGdouble bottommargin);
	
	void Deflate(UGdouble margin);
	void Deflate(UGdouble hormargin,UGdouble vermargin);
	void Deflate(UGdouble leftmargin,UGdouble topmargin,UGdouble rightmargin,UGdouble bottommargin);
	
	void Union(const UGPoint2D& p);
	void Union(const UGRect2D& r);	

	UGbool IntersectRect(const UGRect2D& r);
	UGbool IntersectRect(const UGRect2D& r1,const UGRect2D& r2);

	void UnionRotate(const UGPoint2D &pntOrg, UGdouble dbAngle);

	//! \brief 判断UGRect2D对象是否有效，默认构造的UGRect2D对象的上下左右赋一个无效值
	UGbool IsValid();
	

};

}

#endif 


