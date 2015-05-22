// UGCameraBase.h: interface for the UGCameraBase class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGCAMERABASE_H__8BE76E33_DEB3_498B_AA6E_F4F2C8AC2F06__INCLUDED_)
#define AFX_UGCAMERABASE_H__8BE76E33_DEB3_498B_AA6E_F4F2C8AC2F06__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Scene/UGPrerequisites.h"
#include "Scene/UGFrustum.h"


namespace UGC 
{
class SCENE_API UGCameraBase : public UGFrustum
{
public:
	UGCameraBase();
	UGCameraBase(const UGVector3R& position, UGScene *pScene); 
	virtual ~UGCameraBase();

public:
	virtual UGdouble  GetTrueViewRange();
	virtual UGdouble  GetViewRange();

	virtual UGbool CanBeZoomed(UGdouble  distance,UGdouble  tilt);
	
//	virtual UGVector3R Project(const UGVector3R& point)const;
	virtual void PickingRayIntersection(UGint screenX, UGint screenY,
			UGdouble  &x, UGdouble  &y);
	
	virtual UGdouble  GetDistance();
	virtual void SetDistance(UGdouble  value);

	virtual void ZoomStepped(UGdouble  ticks);
	virtual void Zoom(UGdouble  percent);
	virtual void Pan(UGdouble  x, UGdouble  y);

	virtual void RotationXYZ(UGdouble  RotationY, UGdouble  RotationZ, UGdouble  RotationX);	

	virtual void ComputeAltitude(UGdouble  distance, UGdouble tilt );
	virtual void ComputeTilt(UGdouble  alt, UGdouble  distance );
	
	virtual void SetTilt(UGdouble  value);
	virtual UGdouble  GetTilt();
	virtual void SetBank(UGdouble  value);
	virtual UGdouble  GetBank();
	virtual void SetHeading(UGdouble value);
	virtual UGdouble  GetHeading();

	virtual void PointGoto(UGdouble  x, UGdouble  y);

	virtual void SetPosition(UGdouble  x, UGdouble  y, UGdouble  z);	
	
	virtual UGQuaternion4d& GetOrientationForViewUpdate();
	virtual UGVector3R& GetPositionForViewUpdate(void);
	
	virtual void RenderScene(UGViewport *pVp, UGbool bIncludeOverlays);
	
//	UGdouble CalcRelativeScreenArea(const UGBoundingBox& box);

	UGdouble GetDistFromEye(const UGVector3R& vecWorldPos);	
	UGdouble GetDistFromEye(const UGVector3R& vecWorldPos, UGMatrix4d modelViewMatrix);
	
	void NotifyViewport(UGViewport *pViewport);
		
	UGQuaternion4d GetDerivedOrientation(void);
	UGVector3R GetDerivedPosition(void);
	UGReal GetLodBiasInverse(void) const;

	UGVector3R Project(const UGVector3R& point);
	
protected:
	UGVector3R m_RealPosition;
	UGQuaternion4d m_RealQuaOrientation;

	/// Derived orientation/position of the camera, including reflection
    mutable UGQuaternion4d m_quaDerivedOrientation;
    mutable UGVector3R m_vecDerivedPosition;
	
	UGdouble  m_dTrueViewRange;
	UGdouble  m_dViewRange;

	UGdouble  m_dHeading;
	UGdouble  m_dTilt;
	UGdouble  m_dBank;	
	UGdouble  m_dDistance; // Distance from eye to target		

	UGdouble  m_dCurCameraElevation;
	UGVector3R m_vecCameraUpVector;	
	
	UGint  m_nLastStepZoomTickCount;

	UGViewport *m_pLastViewport;
	UGuint	m_VisFacesLastRender;

	UGReal m_dSceneLodFactor;
	
	UGReal m_dSceneLodFactorInv;
	
protected:
	UGScene *m_pScene;

};

}
#endif // !defined(AFX_UGCAMERABASE_H__8BE76E33_DEB3_498B_AA6E_F4F2C8AC2F06__INCLUDED_)
