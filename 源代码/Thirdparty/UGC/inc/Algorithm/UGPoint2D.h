#ifndef UGPOINT2D_H
#define UGPOINT2D_H
#include "Base/ugdefs.h"
#include "UGSize2D.h"
#include "UGPoint.h"
#include "Base/UGArray.h"

namespace UGC {

class UGStream;

class ALGORITHM_API UGPoint2D  
{
public:
	UGdouble x;
	UGdouble y;
public:
	UGPoint2D();
	UGPoint2D(UGdouble xx,UGdouble yy);	
	UGPoint2D(const UGSize2D& s);
	UGPoint2D(const UGPoint& p);
	
	void Rotate(const UGPoint2D& pntAnchor, UGdouble dRadian);
	void Rotate(const UGPoint2D& pntAnchor, UGdouble dCos, UGdouble dSin);
	void Offset(const UGSize2D &szValue);
	void Offset(UGdouble dOffsetX, UGdouble dOffsetY);
	UGbool EQ(const UGPoint2D& pntAnchor, UGdouble dTolerance)const;
	
	friend ALGORITHM_API UGbool operator==(const UGPoint2D& p,const UGPoint2D& q);
	friend ALGORITHM_API UGbool operator!=(const UGPoint2D& p,const UGPoint2D& q);			
	UGPoint2D& operator=(const UGSize2D& s);		
	UGPoint2D& operator=(const UGPoint& p);
	UGPoint2D& operator+=(const UGPoint2D& p);
	UGPoint2D& operator+=(const UGSize2D& s);
	UGPoint2D& operator-=(const UGPoint2D& p);
	UGPoint2D& operator-=(const UGSize2D& s);	
	UGPoint2D& operator*=(UGdouble c);
	UGPoint2D& operator/=(UGdouble c);
	UGPoint2D operator-();		
	friend ALGORITHM_API UGPoint2D operator+(const UGPoint2D& p,const UGPoint2D& q);
	friend ALGORITHM_API UGPoint2D operator+(const UGPoint2D& p,const UGSize2D& s);
	friend ALGORITHM_API UGPoint2D operator+(const UGSize2D& s,const UGPoint2D& p);	
	friend ALGORITHM_API UGPoint2D operator-(const UGPoint2D& p,const UGPoint2D& q);
	friend ALGORITHM_API UGPoint2D operator-(const UGPoint2D& p,const UGSize2D& s);
	friend ALGORITHM_API UGPoint2D operator-(const UGSize2D& s,const UGPoint2D& p);	
	friend ALGORITHM_API UGPoint2D operator*(const UGPoint2D& s,UGdouble c);	
	friend ALGORITHM_API UGPoint2D operator*(const UGdouble c,const UGPoint2D& p);
	friend ALGORITHM_API UGPoint2D operator/(const UGPoint2D& p,UGdouble c);
	friend ALGORITHM_API UGPoint2D operator/(UGdouble c,const UGPoint2D& p);	
	friend ALGORITHM_API UGbool operator<(const UGPoint2D& p,const UGPoint2D& s);

	friend ALGORITHM_API UGStream& operator<<(UGStream& store,const UGPoint2D& pnt);
	friend ALGORITHM_API UGStream& operator>>(UGStream& store,UGPoint2D& pnt);
};

typedef UGArray<UGPoint2D> UGPoint2Ds;

}

#endif


