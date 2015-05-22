// UGMomentumCamera.h: interface for the UGMomentumCamera class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGMOMENTUMCAMERA_H__888E88A9_2318_4563_938F_52AEBCE057A4__INCLUDED_)
#define AFX_UGMOMENTUMCAMERA_H__888E88A9_2318_4563_938F_52AEBCE057A4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Scene/UGPrerequisites.h"
#include "Scene/UGWorldCamera.h"

namespace UGC 
{

class SCENE_API UGMomentumCamera : public UGWorldCamera
{
public:
	UGMomentumCamera();
	UGMomentumCamera(const UGVector3R& position, UGdouble dRadius, UGScene *pScene);
	virtual ~UGMomentumCamera();

public:
	void SetTargetTilt(UGdouble value);
	UGdouble GetTargetTilt();

	void SetTargetBank(UGdouble value);
	UGdouble GetTargetBank();

	void SetTargetHeading(UGdouble value);
	UGdouble GetTargetHeading();

	UGdouble GetTargetFov();
	void SetTargetFov(UGdouble value);

	UGdouble GetTargetAltitude();
	void SetTargetAltitude(UGdouble value);

	void SlerpToTargetOrientation(UGdouble percent);
	void ComputeTargetDistance( UGdouble altitude, UGdouble tilt );
	void ComputeTargetAltitude(UGdouble distance, UGdouble tilt );		
	
	virtual UGdouble GetTargetDistance();	
	virtual void SetTargetDistance(UGdouble value);

	UGbool GetMomentum();
	void SetMomentum(UGbool value);
	virtual void RotationXYZ(UGdouble RotationY, UGdouble RotationZ, UGdouble RotationX);

	virtual void ZoomStepped(UGdouble ticks);
	virtual void Zoom(UGdouble percent);
	virtual void Pan(UGdouble LatX, UGdouble LonY);
	virtual void RenderScene(UGViewport *pVp, UGbool bIncludeOverlays);
	virtual void SetPosition(UGdouble lon, UGdouble lat, UGdouble heading, UGdouble dAltitude, UGdouble tilt, UGdouble bank);



protected:
	UGdouble m_dLatitudeMomentum;
	UGdouble m_dLongitudeMomentum;
	UGdouble m_dHeadingMomentum;

	// 用于惯性的变量
	UGdouble m_dAngle;
	UGQuaternion4d m_quaTargetOrientation;
	UGdouble m_dTargetDistance;
	UGdouble m_dTargetAltitude;
	UGdouble m_dTargetTilt;
	UGdouble m_dTargetBank;
	UGdouble m_dTargetFov;
	UGdouble m_dTargetHeading;
	UGdouble m_dTargetLatitude;
	UGdouble m_dTargetLongitude;


};
}
#endif // !defined(AFX_UGMOMENTUMCAMERA_H__888E88A9_2318_4563_938F_52AEBCE057A4__INCLUDED_)
