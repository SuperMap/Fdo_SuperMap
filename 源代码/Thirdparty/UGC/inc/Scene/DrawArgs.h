// DrawArgs.h: interface for the DrawArgs class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DRAWARGS_H__AC46F148_A677_451B_BD1F_F21C0B3C685D__INCLUDED_)
#define AFX_DRAWARGS_H__AC46F148_A677_451B_BD1F_F21C0B3C685D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Scene/UGPrerequisites.h"
#include "Algorithm/UGPoint.h"
#include "Scene/UGGlobeParam.h"
#include "Base/UGThread.h"

namespace UGC 
{
class SCENE_API DrawArgs  
{
public:
	DrawArgs();
	virtual ~DrawArgs();	
		
public:
	void SetActiveRenderSys(UGRenderSys *pActiveRenderSys);
	UGulong GetSecondsSinceLastFrame();
	void Present();
//	void SetSceneCamera(UGMomentumCamera *pCamera);
//	UGScene *GetCurrentScene();
//	void SetCurrentScene(UGScene *pScene);
//	void InitializeReference();
	
//	void BeginRender();
//	void EndRender();
//	void Present();
//	static double GetSecondsSinceLastFrame();

public:
//	int m_nNumBoundaryPointsTotal;
//	int m_nNumBoundaryPointsRendered;
//	int m_nNumBoundariesDrawn;
//	int m_nScreenWidth;
//	int m_nScreenHeight;
//	CPoint m_pntLastMousePosition;
//	int m_nNumberTilesDrawn;
//	CPoint m_pntCurrentMousePosition;
//	CString m_strUpperLeftCornerText;
	UGRenderSys *m_pRenderSys;
	UGMomentumCamera *m_pSceneCamera;
	UGGlobeParam m_globeParam;
	UGPoint m_pntLastMousePosition;
	UGbool m_bLeftMouseButtonDown;
	UGbool m_bRightMouseButtonDown;
	UGulong m_dCurrentFrameStartTicks;
	UGulong m_dLastFrameSecondsElapsed;
	UGint m_nScreenWidth;
	UGint m_nScreenHeight;
	UGint m_nNumberTilesDrawn;
	UGint m_nRenderTail;
	static UGbool ms_bNeedRefresh;
//	CSmWorld* m_pCurrentWorld;
//	int m_nTexturesLoadedThisFrame;
//	bool m_bRenderWireFrame;
//public:
//	static long s_nCurrentFrameStartTicks;
//	static Real s_dLastFrameSecondsElapsed;
//	static bool s_bLeftMouseButtonDown;
//	static bool s_bRightMouseButtonDown;
//	bool m_bRepaint;
//	bool m_bPainting;
};

}
#endif // !defined(AFX_DRAWARGS_H__AC46F148_A677_451B_BD1F_F21C0B3C685D__INCLUDED_)
