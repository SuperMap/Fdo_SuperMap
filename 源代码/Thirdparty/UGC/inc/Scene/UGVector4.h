// UGVector4.h: interface for the UGVector4 class.


#if !defined(UG_VECTOR4_H)
#define UG_VECTOR4_H

#include "Scene/UGSceneHeaders.h"
#include <Scene/UGVector3.h>
#include <Scene/UGMatrix4.h>

namespace UGC
{
	/**  4Œ¨∆Î¥ŒœÚ¡ø
	*/
	class SCENE_API UGVector4  
	{
	public:
		Real x;
		Real y;
		Real z;
		Real w;

	public:
		inline UGVector4()
		{			
		}

		inline UGVector4( Real fx, Real fy, Real fz, Real fw )
			: x( fx ), y( fy ), z( fz ), w( fw )
		{
		}

		inline UGVector4( Real fCordinates[4] )
			: x ( fCordinates[0] ), 
			  y ( fCordinates[1] ),
			  z ( fCordinates[2] ),
			  w ( fCordinates[3] )
		{			
		}

		inline UGVector4( UGint nCordinates[4] )
		{
			x = (Real)nCordinates[0];
			y = (Real)nCordinates[1];
			z = (Real)nCordinates[2];
			w = (Real)nCordinates[3];
		}

		inline UGVector4( const Real * const r )
			: x( r[0] ), y( r[1] ), z( r[2] ), w( r[3] )
		{
		}

		inline UGVector4( const UGVector4 &rkVec )
			: x( rkVec.x ), y( rkVec.y ), z( rkVec.z ), w( rkVec.w )
		{			
		}
		
		inline Real operator []( UGint nIndex ) const
		{
			assert(nIndex < 4);
			return * ( &x + nIndex );
			
		}

		inline Real& operator []( UGint nIndex )
		{
			assert( nIndex < 4 );
			return * ( &x + nIndex );
		}
		
		inline UGVector4& operator = ( const UGVector4 &vec )
		{
			x = vec.x;
			y =	vec.y;
			z =	vec.z;
			w = vec.w;

			return *this;
		}

		inline UGbool operator == ( const UGVector4 &vec ) const
		{
			return ( ( x == vec.x ) &&
				     ( y == vec.y ) &&
				     ( z == vec.z ) &&
					 ( w == vec.w ) );
		}

		inline UGbool operator != ( const UGVector4 &vec ) const
		{
			return ( ( x != vec.x ) || 
				     ( y != vec.y ) ||
				     ( z != vec.z ) ||
					 (w != vec.w) );
		}	
		
		inline Real DotProduct( const UGVector4& vec ) const
		{
			return x * vec.x + y * vec.y + z * vec.z + w * vec.w;
		}
		
		inline UGVector4& operator = ( const UGVector3& rhs )
		{
			x = rhs.x;
			y = rhs.y;
			z = rhs.z;
			w = 1.0f;

			return *this;
		}
		
		inline UGVector4 operator * (const UGMatrix4& mat) const
		{
			return UGVector4(
				x*mat[0][0] + y*mat[0][1] + z*mat[0][2] + w*mat[0][3],
				x*mat[1][0] + y*mat[1][1] + z*mat[1][2] + w*mat[1][3],
				x*mat[2][0] + y*mat[2][1] + z*mat[2][2] + w*mat[2][3],
				x*mat[3][0] + y*mat[3][1] + z*mat[3][2] + w*mat[3][3]
				);
		}

		inline friend std::ostream& operator <<
			( std::ostream& o, const UGVector4& v )
		{
			o << "UGVector4(" << v.x << ", " << v.y << ", " << v.z << ", " << v.w << ")";
			return o;
		}
		
	};

}

#endif // !defined(UG_VECTOR4_H)

