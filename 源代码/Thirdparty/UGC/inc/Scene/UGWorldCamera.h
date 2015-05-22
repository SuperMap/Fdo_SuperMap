// UGWorldCamera.h: interface for the UGWorldCamera class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGWORLDCAMERA_H__516F8F2C_48F3_4BC0_AD83_F408E9FE4239__INCLUDED_)
#define AFX_UGWORLDCAMERA_H__516F8F2C_48F3_4BC0_AD83_F408E9FE4239__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Scene/UGPrerequisites.h"
#include "Scene/UGCameraBase.h"

namespace UGC 
{
class SCENE_API UGWorldCamera : public UGCameraBase  
{
public:
	UGWorldCamera();
	UGWorldCamera( UGVector3R targetPosition,UGdouble radius, UGScene *pScene);
	virtual ~UGWorldCamera();

public:
	virtual UGbool CanBeZoomed(UGdouble distance,UGdouble tilt);

	virtual void PickingRayIntersection(UGint screenX, UGint screenY,
			UGdouble &dLatY, UGdouble &dLonX);

	virtual void PickingRayIntersection(UGint screenX, UGint screenY, UGVector3R& vecPos);

	UGdouble GetDistance();
	void SetDistance(UGdouble value);
	
	virtual void Pan(UGdouble LatX, UGdouble LonY);	

	virtual void ComputeAltitude(UGdouble distance, UGdouble tilt );
	virtual void ComputeTilt(UGdouble alt, UGdouble distance );

	virtual void SetTilt(UGdouble value);
	virtual void PointGoto( UGdouble dLon,UGdouble dLat);

	virtual void RenderScene(UGViewport *pVp, UGbool bIncludeOverlays);

	virtual void UpdateViewImpl(void);	

	virtual UGVector3R& GetPositionForViewUpdate(void);

	virtual UGdouble GetLongitude();
	virtual UGdouble GetLatitude();	
	virtual UGdouble GetAltitude();

	UGdouble GetAltitudeAboveTerrain();	

	UGdouble GetTerrainElevation();
	void SetTerrainElevation(UGdouble dTerrainElevation);

	virtual void SetPosition( UGdouble dLon,UGdouble dLat, UGdouble heading, UGdouble dAltitude, UGdouble tilt, UGdouble bank);
	void RotationXYZ(UGdouble RotationY, 
								UGdouble RotationZ, UGdouble RotationX);

	virtual const UGMatrix4d& GetProjectionMatrix(void);
	
	virtual UGdouble GetDistanceNoElevation();

	virtual void ComputeAngleAndAxis(UGVector3R vecPrev, UGVector3R vecCur);
	virtual void ComputeAutoRotateAngleAndAxis(UGVector3R vecPrev, UGVector3R vecCur, UGdouble nMillSecods);
	
	virtual void SetIsAutoRotate(UGbool bIsAutoRotate);
	virtual UGMatrix4d GetRotateMatrix(){return m_matRoateView;}
	virtual UGdouble GetRotateAngle(UGbool bMaxAngle);
	virtual void     SetRotateAngle(UGdouble angle);
	virtual void  SetHeading(UGdouble angle);
	virtual UGdouble GetHeading();
	virtual void SetRotateAngleOfCenterVecter(UGdouble angle);
	virtual UGdouble GetRotateAngleOfCenterVecter();

	const static UGdouble m_dMinTilt;
	const static UGdouble m_dMaxTilt;
	const static UGdouble m_dMinimumAltitude;
protected:
	UGdouble m_dLongitude;
	UGdouble m_dLatitude;
	UGdouble m_dWorldRadius;
	UGdouble m_dAltitude; // Altitude above sea level
	UGdouble m_dTerrainElevation;
	UGdouble m_dMaximumAltitude;

	UGQuaternion4d m_quaOldOrientation;
	UGdouble m_dSlerpStepDist;
	UGdouble m_dSlerpStepAlt;
	UGdouble m_dSlerpStepTilt;
	UGdouble m_dSlerpStepBank;
	UGdouble m_dSlerpStepFov;
	UGdouble m_dSlerpStepHeading;
	UGdouble m_dSlerpStepLat;
	UGdouble m_dSlerpStepLon;


	UGint m_nLatLonTimes;
	UGint m_nTiltTime;
	UGint m_nDistTimes;
	UGint m_nBankTime;

	UGdouble m_dMaxAngle;
	UGdouble m_dMinAngle;
	UGdouble m_dAngle;
	UGMatrix4d m_matRoateView;
	UGbool    m_bAutomaticRotate;
	UGVector3R m_vecRotateAxis;
	
	// 绕屏幕中心点向量旋转角度
	UGdouble m_dCenterAngle;
	
};

}
#endif // !defined(AFX_UGWORLDCAMERA_H__516F8F2C_48F3_4BC0_AD83_F408E9FE4239__INCLUDED_)
