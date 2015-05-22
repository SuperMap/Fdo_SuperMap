// UGPlane.h: interface for the UGPlane class.


#if !defined(UG_PLANE_H)
#define UG_PLANE_H

#include "Graphics3D/UGVector3.h"

namespace UGC
{
	/** 定义三维空间中的一个平面
    @remarks
        平面的方程如下：
        Ax + By + Cz + D = 0
		其中(A,B,C)为法向量，而D为距离
    */
	class GRAPHICS3D_API UGPlane  
	{
	public:
		UGVector3 m_vNormal;
        Real m_fDistance;

	public:
		
		UGPlane ();
        UGPlane ( const UGPlane& rhs );
        UGPlane ( const UGVector3& rkNormal, Real fConstant );
        UGPlane ( const UGVector3& rkNormal, const UGVector3& rkPoint );
        UGPlane ( const UGVector3& rkPoint0, 
			      const UGVector3& rkPoint1,
                  const UGVector3& rkPoint2 );

        /** The "positive side" of the plane is the half space to which the
            plane normal points. The "negative side" is the other half
            space. The flag "no side" indicates the plane itself.
        */
        enum Side
        {
            NO_SIDE,  
            POSITIVE_SIDE, 
            NEGATIVE_SIDE
        };

        Side GetSide (const UGVector3& rkPoint) const;

        /** This is a pseudodistance. The sign of the return value is
            positive if the point is on the positive side of the plane,
            negative if the point is on the negative side, and zero if the
            point is on the plane.
            @par
            The absolute value of the return value is the true distance only
            when the plane normal is a unit length vector.
        */
        Real GetDistance (const UGVector3& rkPoint) const;

        friend std::ostream& operator<< (std::ostream& o, UGPlane& p);
	};
}

#endif // !defined(UG_PLANE_H)

