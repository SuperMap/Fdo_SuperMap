// UGRay.h: interface for the UGRay class.

#if !defined(UG_RAY_H)
#define UG_RAY_H


#include <Scene/UGVector3.h>  //其中已经包含UGMath.h

namespace UGC
{

	
	class SCENE_API UGRay  
	{
	protected:
		UGVector3 m_vOrigion;
		UGVector3 m_vDirection;	
		
	public:
		UGRay()
		{
		}

		UGRay(const UGVector3& vOrigion,const UGVector3& vDirection)
		{
			m_vOrigion = vOrigion;
			m_vDirection = vDirection;
		}
		

		void SetOrigion(const UGVector3& vOrigion)
		{
			m_vOrigion = vOrigion;
		}

		void SetDirection(const UGVector3& vDirection)
		{
			m_vDirection = vDirection;
		}

		const UGVector3& GetOrigion(void) const
		{
			return m_vOrigion;
		}

		const UGVector3& GetDirection(void) const
		{
			return m_vDirection;
		}

		UGVector3 GetPoint(Real t) const
		{
			return UGVector3( m_vOrigion + m_vDirection * t );
		}
		
		UGbool Intersects(const UGPlane& plane, Real& fDistance)
		{
			return UGMath::Intersects( *this, plane, fDistance );
		}

		UGbool Intersects(const UGBoundBox& box, Real& fDistance)
		{
			return UGMath::Intersects( *this, box, fDistance );
		}

		UGbool Intersects( const UGSphere& sphere, Real& fDistance )
		{
			return UGMath::Intersects( *this, sphere, fDistance );
		}
	};
}

#endif // !defined(UGRAY_H)
