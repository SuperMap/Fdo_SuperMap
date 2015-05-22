
#if !defined(AFX_UGFRUSTUM_H__6FC62AD3_A0AB_4AA8_8039_040470804A89__INCLUDED_)
#define AFX_UGFRUSTUM_H__6FC62AD3_A0AB_4AA8_8039_040470804A89__INCLUDED_


#include "Scene/UGPrerequisites.h"
#include "Scene/UGRenderable.h"
#include "Scene/UGPlane.h"
#include "Scene/UGMatrix4d.h"
#include "Scene/UGQuaternion4d.h"
#include "Algorithm/UGPoint2D.h"
#include "Scene/UGVertexData.h"


namespace UGC 
{

enum ProjectionType
{
    PT_ORTHOGRAPHIC,
    PT_PERSPECTIVE
};

class SCENE_API UGFrustum : public UGRenderable, public UGMovableObject
{
public:
	UGFrustum();
	virtual ~UGFrustum();

	UGbool ContainsPoint(const UGVector3R& v);
	UGbool IsVisible(const UGBoundingBox& box);	

	void UpdateFrustum();
	void UpdateFrustumImpl();	
	
	virtual void UpdateView(void);
	virtual void UpdateViewImpl(void);
	
	virtual void UpdateFrustumPlanes(void);
	virtual void UpdateFrustumPlanesImpl();
	
	virtual const UGMatrix4d& GetViewMatrix();	
	virtual const UGMatrix4d& GetWorldMatrix();
	virtual const UGMatrix4d& GetProjectionMatrix(void);
	virtual const UGPlane* GetFrustumPlanes(void);

	UGdouble GetFov();
	UGdouble GetAspect();
	UGdouble GetNearDist();
	UGdouble GetFarDist();

	virtual void UpdateVertexData(void) const;

	/** Overridden from Renderable */
    virtual UGMaterial* GetMaterial(void) const;
    virtual void GetRenderOperation(UGRenderOperation& op);
    virtual void GetWorldTransforms(UGMatrix4d* xform) const;
    virtual UGQuaternion4d GetWorldOrientation(void) const;
    virtual UGVector3R GetWorldPosition(void) const;
    virtual UGReal GetSquaredViewDepth(const UGCameraBase* cam) const;
    virtual UGLightList GetLights(void) const;



protected:
	ProjectionType m_ProjType;

	UGdouble m_dFov;
	//视口比例
	UGdouble m_fAspect;
	//视锥近点
	UGdouble m_fNearDist;
	//视锥远点
	UGdouble m_fFarDist;	

	UGPoint2D m_FrustumOffset;

	UGdouble m_fFocalLength;	

	UGbool m_bRecalcFrustum;
	UGbool m_bRecalcFrustumPlanes;
	UGbool m_bRecalcView;

	UGMatrix4d m_ProjectionMatrixRSDepth;
	UGMatrix4d m_ProjectionMatrixRS;
	UGMatrix4d m_ProjectionMatrix; // Projection matrix used in last render.
	UGMatrix4d m_ViewMatrix; // View matrix used in last render.
	UGMatrix4d m_WorldMatrix;
	
	UGPlane m_Planes[6];
	
	UGMaterial* m_pMaterial;
	
	/// Something re the vertex data has changed
    mutable UGbool m_bRecalcVertexData;
	mutable UGVertexData m_VertexData;
	
public:
	static const UGdouble INFINITE_FAR_PLANE_ADJUST;
};

}
#endif // !defined(AFX_UGFRUSTUM_H__6FC62AD3_A0AB_4AA8_8039_040470804A89__INCLUDED_)
