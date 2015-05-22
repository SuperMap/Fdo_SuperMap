// UGBoundSphere.h: interface for the UGBoundSphere class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(UGBOUNDSPHERE_H)
#define UGBOUNDSPHERE_H

#include "Graphics3D/UGGraphics3DHeaders.h"
#include "UGVector3.h"

namespace UGC{
class GRAPHICS3D_API UGBoundSphere  
{
public:
	UGBoundSphere();
	virtual ~UGBoundSphere();
	UGVector3& GetCenter(){return m_fCenter;}
	const UGVector3& GetCenter()const{return m_fCenter;}
	void SetCenter(const UGVector3& center){m_fCenter = center;}

	Real& GetRadius(){return m_fRadius;}
	const Real& GetRadius()const{return m_fRadius;}
	void SetRadius(Real fRadius){m_fRadius = fRadius;};

	UGbool IsContain(const UGVector3& vec)const;
	UGbool IsIntersect(const UGBoundSphere& bs)const;

protected:
	UGVector3 m_fCenter;
	Real m_fRadius;

};
}

#endif // !defined(AFX_UGBOUNDSPHERE_H__2CAA9B9C_6923_4C6C_AD4D_E4392364FDBD__INCLUDED_)
