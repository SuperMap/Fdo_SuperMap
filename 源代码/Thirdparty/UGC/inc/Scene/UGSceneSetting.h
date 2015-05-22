// UGSceneSetting.h: interface for the UGSceneSetting class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGSCENESETTING_H__C66FF9A7_EA08_4849_85AA_7662DB171D7A__INCLUDED_)
#define AFX_UGSCENESETTING_H__C66FF9A7_EA08_4849_85AA_7662DB171D7A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Scene/UGPrerequisites.h"
#include "Scene/UGVector3R.h"

namespace UGC 
{
class SCENE_API UGSceneSetting  
{
public:
	UGSceneSetting();
	virtual ~UGSceneSetting();

	UGbool m_bCameraTwistLock;
	UGdouble m_dCameraRotationSpeed;
	UGdouble m_dCameraZoomAnalogFactor;
	UGdouble m_dCameraZoomStepFactor;
	UGdouble m_dCameraZoomAcceleration;
	UGdouble m_dVerticalExaggeration;
	UGbool m_bCameraBankLock;
	UGbool m_bCameraIsPointGoto;
	UGbool m_bCameraSmooth;
	UGdouble m_dCameraSlerpPercentage;
	UGdouble m_dCameraZoomStepKeyboard;
	
	UGdouble m_dCameraFov;
	UGdouble m_dCameraFovMin;
	UGdouble m_dCameraFovMax ;
	UGbool m_bCameraHasMomentum;
	/// <summary>
	/// Maximum frames-per-second setting
	/// </summary>
	UGint m_nThrottleFpsHz;
	UGfloat m_fMinSamplesPerDegree;

	// 决定惯性的长短
	UGint m_nSlerpTimes;
	UGdouble m_dSquareSlerpTimes;

	// 是否光滑浏览
	UGbool m_bSmoothBrowse;
	UGbool m_bFogOpen;
	UGdouble m_dFogEndRatio;
	UGbool m_bPickModel;
	UGbool m_bPickVector;

	// 光照
	UGbool m_bParallelLight;
	UGbool m_bMotorialLight;
	UGVector3R m_vecLightPos;

	UGbool m_bQuadTreeShow;
	UGdouble m_dGlobalRadius;
	// 渲染模式
	UGint m_nRenderTail;
	
	//! \brief 自动旋转，true为自动旋转，false为不自动旋转
	UGbool m_bIsCircuRotate;
	UGuint m_nMinRotateMouseTime;
};
}
#endif // !defined(AFX_UGSCENESETTING_H__C66FF9A7_EA08_4849_85AA_7662DB171D7A__INCLUDED_)
