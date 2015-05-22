// UGVector3R.h: interface for the UGVector3R class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGVECTOR3R_H__07E8BCDA_D3A9_431B_A917_E7A1D7351969__INCLUDED_)
#define AFX_UGVECTOR3R_H__07E8BCDA_D3A9_431B_A917_E7A1D7351969__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Scene/UGPrerequisites.h"
#include "Scene/UGMatrix3R.h"


namespace UGC 
{

class SCENE_API UGVector3R  
{

//friend class UGQuaternion4d;

public:
	UGVector3R();
	inline UGVector3R(UGReal fX, UGReal fY, UGReal fZ)
		:x(fX), y(fY), z(fZ)
	{
	};
	virtual ~UGVector3R();	

	inline UGVector3R& Normalize()
	{
		UGReal fLength;
		fLength = UGReal(sqrt(x*x + y*y + z*z));
		
		if(fLength > 1e-06)
		{
			x /= fLength;
			y /= fLength;
			z /= fLength;
		}		
		return *this;
	}
	inline UGReal operator [] (const unsigned i) const
	{
		UGASSERT(i < 3);
		return *(&x + i);
	}
	//这里的引用千万不能改掉 ???
	inline UGReal& operator [] (const unsigned i)
	{
		UGASSERT(i < 3);
		return *(&x + i);
	}
	inline UGVector3R& operator = (const UGVector3R& vec)
	{
		x = vec.x;
		y = vec.y;
		z = vec.z;
		return *this;
	}
	inline bool operator == (const UGVector3R& vec) const
	{
		return ((x == vec.x)&&(y == vec.y)&&(z == vec.z));
	}
	
	inline bool operator != (const UGVector3R& vec) const
	{
		return (x != vec.x|| y != vec.y||z != vec.z);
	}
	inline bool operator > (const UGVector3R& vec)const
	{
		return (x > vec.x && y > vec.y && z > vec.z);
		
	}
	inline bool operator < (const UGVector3R& vec)const
	{
		return (x < vec.x && y < vec.y && z < vec.z);
	}
	
	inline UGVector3R operator + (const UGVector3R& vec) const
	{
		UGVector3R TempVec;
		TempVec.x =x + vec.x;
		TempVec.y =y + vec.y;
		TempVec.z =z + vec.z;
		return TempVec;
		
	}
	inline UGVector3R operator - (const UGVector3R& vec) const
	{
		UGVector3R TempVec;
		TempVec.x =x - vec.x;
		TempVec.y =y - vec.y;
		TempVec.z =z - vec.z;
		return TempVec;
	}
	
	inline UGVector3R operator * (const UGReal fScale) const
	{
		UGVector3R TempVec;
		TempVec.x =x * fScale;
		TempVec.y =y * fScale;
		TempVec.z =z * fScale;
		return TempVec;
		
	}
	inline UGVector3R& operator * (UGMatrix3R& m)
	{
		UGdouble tmpX, tmpY, tmpZ;
		tmpX = x * m[0][0] + y * m[1][0] + z * m[2][0];
		tmpY = x * m[0][1] + y * m[1][1] + z * m[2][1];
		tmpZ = z;
		x = tmpX;
		y = tmpY;
		z = tmpZ;
		return *this;
	}
	inline UGVector3R operator* (const UGVector3R& vec)const
	{
		UGVector3R TempVec;
		TempVec.x = x*vec.x;
		TempVec.y = y*vec.y;
		TempVec.z = z*vec.z;
		return TempVec;
	}
	inline UGVector3R operator / (const UGReal fScale) const
	{
		UGVector3R TempVec;
		TempVec.x =x / fScale;
		TempVec.y =y / fScale;
		TempVec.z =z / fScale;
		return TempVec;
	}


	
	inline UGVector3R operator - () const
	{
		UGVector3R TempVec;
		TempVec.x = -x;
		TempVec.y = -y;
		TempVec.z = -z;
		return TempVec;
	}
	
	
	inline UGVector3R& operator += (const UGVector3R& vec) 
	{
		x += vec.x;
		y += vec.y;
		z += vec.z;
		return *this;
	}
	
	inline UGVector3R& operator -= (const UGVector3R& vec)
	{
		x -= vec.x;
		y -= vec.y;
		z -= vec.z;
		return *this;
	}
	
	inline UGVector3R& operator *= (const UGReal fScale)
	{
		x *= fScale;
		y *= fScale;
		z *= fScale;
		return *this;
	}
	
	inline UGVector3R& operator /= (const UGVector3R& vec)
	{
		x /= vec.x;
		y /= vec.y;
		z /= vec.z;
		return *this;
	}

	inline UGVector3R& operator /= (const UGReal fScale )
	{
		if ( !UGIS0( fScale ) )
		{
			x /= fScale;
			y /= fScale;
			z /= fScale;
		}

		return *this;
	}
	inline  UGVector3R CrossProduct(const UGVector3R &vec) const
	{
		UGVector3R TempVector;
		TempVector.x = y*vec.z- z*vec.y;
		TempVector.y = z*vec.x - x*vec.z;
		TempVector.z = x*vec.y - y*vec.x;
		
		return TempVector;
	}
	inline UGReal DotProduct(const UGVector3R& vec) const
	{
		return x*vec.x + y*vec.y + z*vec.z;
	}
	inline UGReal SquareLength() const
	{
		return x*x + y*y + z*z;		
	}
	inline void MakeFloor( const UGVector3R& cmp )
    {
        if( cmp.x < x ) x = cmp.x;
        if( cmp.y < y ) y = cmp.y;
        if( cmp.z < z ) z = cmp.z;
    }
	inline void MakeCeil( const UGVector3R& cmp )
    {
        if( cmp.x > x ) x = cmp.x;
        if( cmp.y > y ) y = cmp.y;
        if( cmp.z > z ) z = cmp.z;
    }
	
    inline UGVector3R operator / ( const UGVector3R& rhs) const
    {
        return UGVector3R(
            x / rhs.x,
            y / rhs.y,
            z / rhs.z);
    }

	inline UGVector3R NormalizedCopy(void) const
    {
        UGVector3R ret = *this;
        ret.Normalize();
        return ret;
    }
	
	UGbool IsZeroLength(void) const;
	UGQuaternion4d GetRotationTo(const UGVector3R& dest,
										 const UGVector3R& fallbackAxis = UGVector3R::ZERO) const;

    void Project(const UGViewport &viewport, const UGMatrix4d &projection, const UGMatrix4d &view, const UGMatrix4d &world);
	void UnProject(const UGViewport &viewport, const UGMatrix4d &projection, const UGMatrix4d &view, const UGMatrix4d &world);
	void MultiplyMatrix(const UGMatrix4d& m, UGReal &w);
	UGReal Length();

	static const UGVector3R ZERO;
	static const UGVector3R UNIT_X;
    static const UGVector3R UNIT_Y;
    static const UGVector3R UNIT_Z;
    static const UGVector3R NEGATIVE_UNIT_X;
    static const UGVector3R NEGATIVE_UNIT_Y;
    static const UGVector3R NEGATIVE_UNIT_Z;
    static const UGVector3R UNIT_SCALE;
public:
	UGReal x, y, z;
};
}
#endif // !defined(AFX_UGVECTOR3R_H__07E8BCDA_D3A9_431B_A917_E7A1D7351969__INCLUDED_)
