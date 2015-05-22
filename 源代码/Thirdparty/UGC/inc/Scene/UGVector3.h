// UGVector3.h: interface for the UGVector3 class.


#ifndef UG_VECTOR3_H
#define UG_VECTOR3_H

#include <Scene/UGSceneHeaders.h>
#include <Scene/UGMath.h>
#include <Scene/UGQuaternion.h>

namespace UGC
{
	/** Standard 3-dimensional vector.
        @remarks
            A direction in 3D space represented as distances along the 3
            orthoganal axes (x, y, z). Note that positions, directions and
            scaling factors can be represented by a vector, depending on how
            you interpret the values.
    */
	class SCENE_API UGVector3
	{
	public:
		// components
		Real x;
		Real y;
		Real z;

	public:
		// special points
		static const UGVector3 ZERO;
		static const UGVector3 UNIT_X;
		static const UGVector3 UNIT_Y;
		static const UGVector3 UNIT_Z;
		static const UGVector3 UNIT_SCALE;
		
	public:
		//----------------------------------------------------------------
		inline UGVector3();

		inline UGVector3( Real fX, Real fY, Real fZ );	

		inline UGVector3( Real fCoordinate[3] );

		inline UGVector3( UGint nCoordinate[3] );

		inline UGVector3( const UGVector3& vec );
		
		inline UGVector3( const Real* const V );
		
		//---------------------------------------------------------------

		inline Real operator [] ( const UGuint i ) const;

		inline Real& operator [] (const UGuint i);

        //----------------------------------------------------------------

		inline UGVector3& operator = ( const UGVector3& vec );

        //----------------------------------------------------------------

		inline UGbool operator == ( const UGVector3& vec ) const;
		
		inline UGbool operator != ( const UGVector3& vec ) const;

		inline UGbool operator > ( const UGVector3& vec ) const;
		
		inline UGbool operator < ( const UGVector3& vec ) const;
		
		//----------------------------------------------------------------

		inline UGVector3 operator + ( const UGVector3& vec ) const;

		inline UGVector3 operator - ( const UGVector3& vec ) const;
		
		inline UGVector3 operator * ( const Real fScale ) const;

		inline UGVector3 operator * ( const UGVector3& vec ) const;

		inline UGVector3 operator / ( const Real fScale ) const;
		
		inline UGVector3 operator - () const;
				
		inline UGVector3& operator += ( const UGVector3& vec ) ;
		
		inline UGVector3& operator -= ( const UGVector3& vec );
		
		inline UGVector3& operator *= ( const Real fScale );
		
		inline UGVector3& operator /= ( const UGVector3& vec );
		
		//----------------------------------------------------------------

		inline Real Length() const;

		inline Real SquareLength() const;

		inline UGbool IsZeroLength( void ) const;

		inline UGVector3& Normalize();

		inline Real DotProduct( const UGVector3& vec ) const;
		
		inline  UGVector3 CrossProduct( const UGVector3 &vec ) const;

		inline void MakeCeil( const UGVector3& vec );

		inline void MakeFloor( const UGVector3& vec );
		
		inline UGVector3 Perpendicular( void ) const;

		inline UGQuaternion GetRotationTo( const UGVector3& dest ) const;

		inline UGVector3 NormalisedCopy( void ) const;
		
		inline UGVector3 Reflect( const UGVector3& normal );

		inline friend std::ostream& operator << ( std::ostream& o, const UGVector3& v );
	};

//******************************************************************//
	
	inline UGVector3::UGVector3()
	{
	}
	
	inline UGVector3::UGVector3( Real fX, Real fY, Real fZ )
		: x( fX ), y( fY ), z( fZ )
	{
	}
	
	inline UGVector3::UGVector3( Real fCoordinate[3] )
		: x( fCoordinate[0] ),
		y( fCoordinate[1] ),
		z( fCoordinate[2] )
	{			
	}
	
	inline UGVector3::UGVector3( UGint nCoordinate[3] )
	{
		x = (Real)nCoordinate[0];
		y = (Real)nCoordinate[1];
		z = (Real)nCoordinate[2];
	}	
	
	inline UGVector3::UGVector3( const UGVector3& vec )
		:x(vec.x),y(vec.y),z(vec.z)
	{		
	}
	
	inline UGVector3::UGVector3( const Real* const V )
		:x( V[0] ), y( V[1] ), z( V[2] )
	{			
	}
	
	//		inline UGVector3(const CPoint3D& pnt3D)
	//			:x(pnt3D.x),y(pnt3D.y),z(pnt3D.z)
	//		{	
	//		}
	//---------------------------------------------------------------
	inline Real UGVector3::operator [] ( const UGuint i ) const
	{
		assert( i >= 0 && i < 3 );
		return *( &x + i );
	}
	
	inline Real& UGVector3::operator [] (const unsigned i)
	{
		assert( i >= 0 && i < 3 );
		return *( &x + i );
	}
	
	//----------------------------------------------------------------
	
	inline UGVector3& UGVector3::operator = ( const UGVector3& vec )
	{
		x = vec.x;
		y = vec.y;
		z = vec.z;
		
		return *this;
	}
	
	//----------------------------------------------------------------
	
	inline UGbool UGVector3::operator == ( const UGVector3& vec ) const
	{
		return ( x == vec.x && y == vec.y && z == vec.z );
	}
	
	inline UGbool UGVector3::operator != ( const UGVector3& vec ) const
	{
		return ( x != vec.x || y != vec.y || z != vec.z );
	}
	
	inline UGbool UGVector3::operator > ( const UGVector3& vec ) const
	{
		return ( x > vec.x && y > vec.y && z > vec.z );
	}
	
	inline UGbool UGVector3::operator < ( const UGVector3& vec ) const
	{
		return ( x < vec.x && y < vec.y && z < vec.z );
	}
	
	//----------------------------------------------------------------
	
	inline UGVector3 UGVector3::operator + ( const UGVector3& vec ) const
	{
		UGVector3 TempVec( x + vec.x,
			y + vec.y,
			z + vec.z );
		return TempVec;
	}
	
	inline UGVector3 UGVector3::operator - ( const UGVector3& vec ) const
	{
		UGVector3 TempVec( x - vec.x,
			y - vec.y,
			z - vec.z );
		
		return TempVec;
	}
	
	inline UGVector3 UGVector3::operator * ( const Real fScale ) const
	{
		UGVector3 TempVec;
		
		TempVec.x = x * fScale;
		TempVec.y = y * fScale;
		TempVec.z = z * fScale;
		
		return TempVec;
	}
	
	inline UGVector3 UGVector3::operator * ( const UGVector3& vec ) const
	{
		UGVector3 TempVec;
		
		TempVec.x = x * vec.x;
		TempVec.y = y * vec.y;
		TempVec.z = z * vec.z;
		
		return TempVec;
	}
	
	inline UGVector3 UGVector3::operator / ( const Real fScale ) const
	{
		assert( fScale < -1e-06 || fScale > 1e-06 ); //不能太小
		
		UGVector3 TempVec;
		
		TempVec.x = x / fScale;
		TempVec.y = y / fScale;
		TempVec.z = z / fScale;
		
		return TempVec;
	}
	
	inline UGVector3 UGVector3::operator - () const
	{
		UGVector3 TempVec;
		
		TempVec.x = -x;
		TempVec.y = -y;
		TempVec.z = -z;
		
		return TempVec;
	}
				
	inline UGVector3& UGVector3::operator += ( const UGVector3& vec ) 
	{
		x += vec.x;
		y += vec.y;
		z += vec.z;
		
		return *this;
	}
	
	inline UGVector3& UGVector3::operator -= ( const UGVector3& vec )
	{
		x -= vec.x;
		y -= vec.y;
		z -= vec.z;
		
		return *this;
	}
	
	inline UGVector3& UGVector3::operator *= ( const Real fScale )
	{
		x *= fScale;
		y *= fScale;
		z *= fScale;
		
		return *this;
	}
	
	inline UGVector3& UGVector3::operator /= ( const UGVector3& vec )
	{
		x /= vec.x;
		y /= vec.y;
		z /= vec.z;
		
		return *this;
	}
	
	//----------------------------------------------------------------
	
	inline Real UGVector3::Length() const
	{
		return Real( UGMath::Sqrt( x * x + y * y + z * z ) );
	}
	
	inline Real UGVector3::SquareLength() const
	{
		return x * x + y * y + z * z;		
	}
	
	inline UGbool UGVector3::IsZeroLength( void ) const
	{
		Real sqlen = (x * x) + (y * y) + (z * z);
		return ( sqlen < ( 1e-06 * 1e-06 ) );	 
	}
	
	inline UGVector3& UGVector3::Normalize()
	{
		Real fLength = Real( UGMath::Sqrt( x*x + y*y + z*z) );
		
		if ( fLength > 1e-06 )
		{
			Real fInvLength = 1.0 / fLength;
			x *= fInvLength;
			y *= fInvLength;
			z *= fInvLength;
		}		
		
		return *this;
	}
	
	inline UGVector3 UGVector3::NormalisedCopy( void ) const
	{
		UGVector3 ret = *this;
		ret.Normalize();
		return ret;
	}

	//点积
	inline Real UGVector3::DotProduct( const UGVector3& vec ) const
	{
	/*
	   向量P( Px, Py, Pz )，向量Q( Qx, Qy, Qz)
	   P·Q ＝ PxQx + PyQy + PzQz
	*/
		
		return x * vec.x + y * vec.y + z * vec.z;
	}
	
	//叉积
	inline  UGVector3 UGVector3::CrossProduct( const UGVector3 &vec ) const
	{
	  /*
	     向量P( Px, Py, Pz )，向量Q( Qx, Qy, Qz)
				 |  i  j  k  |
		P×Q ＝  |  Px Py Pz | ＝[ (PyQz-PzQy), (PzQx-PxQz), (PxQy-PyQx) ]
				 |  Qx Qy Qz |
		*/
		UGVector3 TempVector;
		
		TempVector.x = y * vec.z - z * vec.y;
		TempVector.y = z * vec.x - x * vec.z;
		TempVector.z = x * vec.y - y * vec.x;
		
		return TempVector;
	}
	
	inline void UGVector3::MakeCeil( const UGVector3& vec )
	{
		if(vec.x > x) x = vec.x;
		if(vec.y > y) y = vec.y;
		if(vec.z > z) z = vec.z;
	}
	
	inline void UGVector3::MakeFloor( const UGVector3& vec )
	{
		if(vec.x < x) x = vec.x;
		if(vec.y < y) y = vec.y;
		if(vec.z < z) z = vec.z;
	}
	
	inline UGVector3 UGVector3::Perpendicular( void ) const
	{
		static const Real fSquareZero = 1e-06 * 1e-06;
		
		UGVector3 perp = this->CrossProduct( UGVector3::UNIT_X );
		
		// Check length
		if( perp.SquareLength() < fSquareZero )
		{
		/* This vector is the Y axis multiplied by a scalar, so we have 
		to use another axis.
			*/
			perp = this->CrossProduct( UGVector3::UNIT_Y );
		}
		
		return perp;
	}
	
	inline UGQuaternion UGVector3::GetRotationTo(const UGVector3& dest) const
	{ 
				// Based on Stan Melax's article in Game Programming Gems
		UGQuaternion q;
		// Copy, since cannot modify local
		UGVector3 v0 = *this;
		UGVector3 v1 = dest;
		v0.Normalize();
		v1.Normalize();
		
		UGVector3 c = v0.CrossProduct(v1);
		
		// NB if the crossProduct approaches zero, we get unstable because ANY axis will do
		// when v0 == -v1
		Real d = v0.DotProduct(v1);
		// If dot == 1, vectors are the same
		if (d >= 1.0f)
		{
			return UGQuaternion::IDENTITY;
		}
		Real s = UGMath::Sqrt( (1+d)*2 );
		Real invs = 1 / s;
		
		q.x = c.x * invs;
		q.y = c.y * invs;
		q.z = c.z * invs;
		q.w = s * 0.5;
		return q;
	}
	
	/** Calculates a reflection vector to the plane with the given normal . 
	@remarks NB assumes 'this' is pointing AWAY FROM the plane, invert if it is not.
	*/
	inline UGVector3 UGVector3::Reflect( const UGVector3& normal )
	{
		return UGVector3( ( normal * 2 * (this->DotProduct(normal)) ) - *this );
	}
	
	inline std::ostream& operator << ( std::ostream& o, const UGVector3& v )
	{
		o << "UGVector3(" << v.x << ", " << v.y << ", " << v.z << ")";
		return o;
	}
}

#endif


