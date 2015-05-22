#ifndef UGPOINT3D_H
#define UGPOINT3D_H
#include "Base/ugdefs.h"
#include "Base/UGArray.h"

namespace UGC {

class ALGORITHM_API UGPoint3D  
{
public:
	UGdouble x;
	UGdouble y;
	UGdouble z;
public:
	UGPoint3D();
	UGPoint3D(UGdouble xx,UGdouble yy,UGdouble zz);	

public:	
	UGPoint3D& operator=(const UGPoint3D& s);
	UGPoint3D& operator+=(const UGPoint3D& p);
	UGPoint3D& operator-=(const UGPoint3D& p);
	UGPoint3D& operator*=(UGdouble c);
	UGPoint3D& operator/=(UGdouble c);
	UGPoint3D operator-();		
	//{{add by guohui 2007.09.19
	friend ALGORITHM_API UGbool operator==(const UGPoint3D& p,const UGPoint3D& q);
	friend ALGORITHM_API UGbool operator!=(const UGPoint3D& p,const UGPoint3D& q);			
	//}}add by guohui 2007.09.19

};

typedef UGArray<UGPoint3D> UGPoint3Ds;
}

#endif 


