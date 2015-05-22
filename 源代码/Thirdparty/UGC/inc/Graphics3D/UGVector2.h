// UGVector2.h: interface for the UGVector2 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(UGVECTOR2_H)
#define UGVECTOR2_H
#include "Graphics3D/UGGraphics3DHeaders.h"
#include "Base/UGArray.h"

namespace UGC{
class GRAPHICS3D_API UGVector2  
{
public:
	Real x;
	Real y;
public:
	UGVector2(){};
	UGVector2(Real fx, Real fy){};
	UGVector2(Real fCoordinates[2]){};
	UGVector2(const UGVector2& vec ){};
	virtual ~UGVector2(){};
public:
	inline Real operator [] ( const UGuint i ) const;
	
	inline Real& operator [] (const UGuint i);

	inline UGVector2& operator = ( const UGVector2& vec )
	{
		this->x = vec.x;
		this->y =vec.y;
		return* this;
	};
	
	inline UGbool operator == ( const UGVector2& vec ) const;
	
	inline UGbool operator != ( const UGVector2& vec ) const;
	
	inline UGbool operator > ( const UGVector2& vec ) const;
	
	inline UGbool operator < ( const UGVector2& vec ) const;
	
	//----------------------------------------------------------------
	
	inline UGVector2 operator + ( const UGVector2& vec ) const;
	
	inline UGVector2 operator - ( const UGVector2& vec ) const;
	
	inline UGVector2 operator * ( const Real fScale ) const;
	
	inline UGVector2 operator * ( const UGVector2& vec ) const;
	
	inline UGVector2 operator / ( const Real fScale ) const;
	
	inline UGVector2 operator - () const;
				
	inline UGVector2& operator += ( const UGVector2& vec ) ;
	
	inline UGVector2& operator -= ( const UGVector2& vec );
	
	inline UGVector2& operator *= ( const Real fScale );
	
	inline UGVector2& operator /= ( const UGVector2& vec );
	
	//----------------------------------------------------------------
	
	inline Real Length() const;
	
	inline Real SquareLength() const;
	
	inline UGbool IsZeroLength( void ) const;
	
	inline UGVector2& Normalize();
	
	inline Real DotProduct( const UGVector2& vec ) const;
	
	inline  UGVector2 CrossProduct( const UGVector2 &vec ) const;
	
	inline void MakeCeil( const UGVector2& vec );
	
	inline void MakeFloor( const UGVector2& vec );
	
	inline UGVector2 Perpendicular( void ) const;
	
	inline UGVector2 NormalisedCopy( void ) const;
	
	inline UGVector2 Reflect( const UGVector2& normal );
	
	inline friend std::ostream& operator << ( std::ostream& o, const UGVector2& v );
	
};
typedef UGArray<UGVector2> UGVec2Array;

}

#endif // !defined(AFX_UGVECTOR2_H__9BA8C114_2B9D_43CB_8632_EB03D0850CE1__INCLUDED_)
