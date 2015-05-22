// UGVector4R.h: interface for the UGVector4R class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGVECTOR4R_H__92CEC4D7_6A04_475B_A0BB_2C457812FD95__INCLUDED_)
#define AFX_UGVECTOR4R_H__92CEC4D7_6A04_475B_A0BB_2C457812FD95__INCLUDED_

#include "Scene/UGPrerequisites.h"
#include "Scene/UGVector3R.h"

namespace UGC 
{
class SCENE_API UGVector4R  
{
public:
    union 
	{
        struct 
		{
            UGReal x, y, z, w;
        };
        UGReal val[4];
    };

public:
    inline UGVector4R()
    {
    }

    inline UGVector4R( const UGReal fX, const UGReal fY, const UGReal fZ, const UGReal fW )
        : x( fX ), y( fY ), z( fZ ), w( fW)
    {
    }

    inline explicit UGVector4R( const UGReal afCoordinate[4] )
        : x( afCoordinate[0] ),
          y( afCoordinate[1] ),
          z( afCoordinate[2] ),
          w( afCoordinate[3] )
    {
    }

    inline explicit UGVector4R( const int afCoordinate[4] )
    {
        x = (UGReal)afCoordinate[0];
        y = (UGReal)afCoordinate[1];
        z = (UGReal)afCoordinate[2];
        w = (UGReal)afCoordinate[3];
    }

    inline explicit UGVector4R( UGReal* const r )
        : x( r[0] ), y( r[1] ), z( r[2] ), w( r[3] )
    {
    }

    inline explicit UGVector4R( const UGReal scaler )
        : x( scaler )
        , y( scaler )
        , z( scaler )
        , w( scaler )
    {
    }

    inline explicit UGVector4R(const UGVector3R& rhs)
        : x(rhs.x), y(rhs.y), z(rhs.z), w(1.0f)
    {
    }

    inline UGVector4R( const UGVector4R& rkVector )
        : x( rkVector.x ), y( rkVector.y ), z( rkVector.z ), w (rkVector.w)
    {
    }

	inline UGReal operator [] ( const size_t i ) const
    {
        return *(&x+i);
    }

	inline UGReal& operator [] ( const size_t i )
    {
        return *(&x+i);
    }

    /** Assigns the value of the other vector.
        @param
            rkVector The other vector
    */
    inline UGVector4R& operator = ( const UGVector4R& rkVector )
    {
        x = rkVector.x;
        y = rkVector.y;
        z = rkVector.z;
        w = rkVector.w;

        return *this;
    }

	inline UGVector4R& operator = ( const UGReal fScalar)
	{
		x = fScalar;
		y = fScalar;
		z = fScalar;
		w = fScalar;
		return *this;
	}

    inline bool operator == ( const UGVector4R& rkVector ) const
    {
        return ( x == rkVector.x &&
            y == rkVector.y &&
            z == rkVector.z &&
            w == rkVector.w );
    }

    inline bool operator != ( const UGVector4R& rkVector ) const
    {
        return ( x != rkVector.x ||
            y != rkVector.y ||
            z != rkVector.z ||
            w != rkVector.w );
    }

    inline UGVector4R& operator = (const UGVector3R& rhs)
    {
        x = rhs.x;
        y = rhs.y;
        z = rhs.z;
        w = 1.0f;
        return *this;
    }

    // arithmetic operations
    inline UGVector4R operator + ( const UGVector4R& rkVector ) const
    {
        return UGVector4R(
            x + rkVector.x,
            y + rkVector.y,
            z + rkVector.z,
            w + rkVector.w);
    }

    inline UGVector4R operator - ( const UGVector4R& rkVector ) const
    {
        return UGVector4R(
            x - rkVector.x,
            y - rkVector.y,
            z - rkVector.z,
            w - rkVector.w);
    }

    inline UGVector4R operator * ( const UGReal fScalar ) const
    {
        return UGVector4R(
            x * fScalar,
            y * fScalar,
            z * fScalar,
            w * fScalar);
    }

    inline UGVector4R operator * ( const UGVector4R& rhs) const
    {
        return UGVector4R(
            rhs.x * x,
            rhs.y * y,
            rhs.z * z,
            rhs.w * w);
    }

    inline UGVector4R operator / ( const UGReal fScalar ) const
    {
        UGReal fInv = 1.0 / fScalar;

        return UGVector4R(
            x * fInv,
            y * fInv,
            z * fInv,
            w * fInv);
    }

    inline UGVector4R operator / ( const UGVector4R& rhs) const
    {
        return UGVector4R(
            x / rhs.x,
            y / rhs.y,
            z / rhs.z,
            w / rhs.w);
    }

    inline const UGVector4R& operator + () const
    {
        return *this;
    }

    inline UGVector4R operator - () const
    {
        return UGVector4R(-x, -y, -z, -w);
    }

    inline friend UGVector4R operator * ( const UGReal fScalar, const UGVector4R& rkVector )
    {
        return UGVector4R(
            fScalar * rkVector.x,
            fScalar * rkVector.y,
            fScalar * rkVector.z,
            fScalar * rkVector.w);
    }

    inline friend UGVector4R operator / ( const UGReal fScalar, const UGVector4R& rkVector )
    {
        return UGVector4R(
            fScalar / rkVector.x,
            fScalar / rkVector.y,
            fScalar / rkVector.z,
            fScalar / rkVector.w);
    }

    inline friend UGVector4R operator + (const UGVector4R& lhs, const UGReal rhs)
    {
        return UGVector4R(
            lhs.x + rhs,
            lhs.y + rhs,
            lhs.z + rhs,
            lhs.w + rhs);
    }

    inline friend UGVector4R operator + (const UGReal lhs, const UGVector4R& rhs)
    {
        return UGVector4R(
            lhs + rhs.x,
            lhs + rhs.y,
            lhs + rhs.z,
            lhs + rhs.w);
    }

    inline friend UGVector4R operator - (const UGVector4R& lhs, UGReal rhs)
    {
        return UGVector4R(
            lhs.x - rhs,
            lhs.y - rhs,
            lhs.z - rhs,
            lhs.w - rhs);
    }

    inline friend UGVector4R operator - (const UGReal lhs, const UGVector4R& rhs)
    {
        return UGVector4R(
            lhs - rhs.x,
            lhs - rhs.y,
            lhs - rhs.z,
            lhs - rhs.w);
    }

    // arithmetic updates
    inline UGVector4R& operator += ( const UGVector4R& rkVector )
    {
        x += rkVector.x;
        y += rkVector.y;
        z += rkVector.z;
        w += rkVector.w;

        return *this;
    }

    inline UGVector4R& operator -= ( const UGVector4R& rkVector )
    {
        x -= rkVector.x;
        y -= rkVector.y;
        z -= rkVector.z;
        w -= rkVector.w;

        return *this;
    }

    inline UGVector4R& operator *= ( const UGReal fScalar )
    {
        x *= fScalar;
        y *= fScalar;
        z *= fScalar;
        w *= fScalar;
        return *this;
    }

    inline UGVector4R& operator += ( const UGReal fScalar )
    {
        x += fScalar;
        y += fScalar;
        z += fScalar;
        w += fScalar;
        return *this;
    }

    inline UGVector4R& operator -= ( const UGReal fScalar )
    {
        x -= fScalar;
        y -= fScalar;
        z -= fScalar;
        w -= fScalar;
        return *this;
    }

    inline UGVector4R& operator *= ( const UGVector4R& rkVector )
    {
        x *= rkVector.x;
        y *= rkVector.y;
        z *= rkVector.z;
        w *= rkVector.w;

        return *this;
    }

    inline UGVector4R& operator /= ( const UGReal fScalar )
    {
        UGReal fInv = 1.0 / fScalar;

        x *= fInv;
        y *= fInv;
        z *= fInv;
        w *= fInv;

        return *this;
    }

    inline UGVector4R& operator /= ( const UGVector4R& rkVector )
    {
        x /= rkVector.x;
        y /= rkVector.y;
        z /= rkVector.z;
        w /= rkVector.w;

        return *this;
    }

    /** Calculates the dot (scalar) product of this vector with another.
        @param
            vec Vector with which to calculate the dot product (together
            with this one).
        @returns
            A float representing the dot product value.
    */
    inline UGReal dotProduct(const UGVector4R& vec) const
    {
        return x * vec.x + y * vec.y + z * vec.z + w * vec.w;
    }  
	
	UGVector4R MultiplyMatrix(UGMatrix4d m);

    // special
    static const UGVector4R ZERO;

};
}
#endif // !defined(AFX_UGVECTOR4R_H__92CEC4D7_6A04_475B_A0BB_2C457812FD95__INCLUDED_)
