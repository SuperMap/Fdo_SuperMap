// UGFrustum.h: interface for the UGFrustum class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(UGFRUSTUM_H)
#define UGFRUSTUM_H
#include "Graphics3D/UGGraphics3DHeaders.h"
#include "Graphics3D/UGPlane.h"
namespace UGC{
class UGVector3;
class UGBoundBox;
class UGBoundSphere;
//!brief define the geometry Frustum, actually it is a polytope, because the main use of it is in the 
// UGCamera to represent the Frustum of the camera, so we it UGFrustum here.
class GRAPHICS3D_API UGFrustum  
{
public:
	typedef UGArray<UGPlane> PlaneList;
	UGFrustum();
	UGFrustum(PlaneList& planes);
	virtual ~UGFrustum();
	void SetPlanes(const PlaneList& planes);
	void AddPlane(const UGPlane& plane);

	PlaneList& GetPlanes();
	const PlaneList& GetPlanes()const;

	UGbool IsContain(const UGVector3& vec3);
	//!\brief Check whether the frustum conail any part of the specifically geometry
	UGbool IsContain(const UGVec3Array& vec3s);
	//!\brief Check whether the frustum conail any part of the specifically geometry
	UGbool IsContain(const UGBoundBox& bb);
	//!\brief Check whether the frustum conail any part of the specifically geometry
	UGbool IsContain(const UGBoundSphere& bs);

	//!\brief Check whether the frustum conail the whole part of the specifically geometry
	UGbool IsContainsAll(const UGVec3Array& vec3s);
	//!\brief Check whether the frustum conail the whole part of the specifically geometry
	UGbool IsContainsAll(const UGBoundBox& bb);
	//!\brief Check whether the frustum conail the whole part of the specifically geometry
	UGbool IsContainsAll(const UGBoundSphere& bs);	
protected:

	PlaneList m_Planes;
};
}
#endif // !defined(AFX_UGFRUSTUM_H__94C61509_B911_4622_A8CE_B7D83D00703D__INCLUDED_)
