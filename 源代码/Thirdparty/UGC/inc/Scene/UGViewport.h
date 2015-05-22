// UGViewport.h: interface for the UGViewport class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGVIEWPORT_H__347A41D2_5BC2_4D44_A53B_B05C59B92FF5__INCLUDED_)
#define AFX_UGVIEWPORT_H__347A41D2_5BC2_4D44_A53B_B05C59B92FF5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Scene/UGPrerequisites.h"
#include "Scene/UGColorValue.h"


namespace  UGC 
{

class SCENE_API UGViewport  
{
public:	
	UGViewport(){}
	UGViewport(UGMomentumCamera *pCamera, 
		UGRenderTarget *pTarget,
		UGReal left, UGReal top,
		UGReal width, UGReal height,
		UGint ZOrder);
	UGViewport(UGint ActLeft, UGint ActTop, UGint ActWidth, UGint ActHeight);
	virtual ~UGViewport();

public:	
	void Update();
	UGRenderTarget *GetTarget(void) const;
	UGMomentumCamera *GetCamera(void) const;
	void SetCamera(UGMomentumCamera *pCam);
	UGint GetZOrder(void) const;
	UGReal GetLeft(void) const;
	UGReal GetTop(void) const;
	UGReal GetWidth(void) const;
	UGReal GetHeight(void) const;
	UGint GetActualLeft(void) const;
	UGint GetActualTop(void) const;
	UGint GetActualWidth(void) const;
	UGint GetActualHeight(void) const;

	void SetActualLeft(const UGint x);
	void SetActualTop(const UGint y);
	void SetActualWidth(const UGint width);
	void SetActualHeight(const UGint height);

	UGint GetMinZ(void) const;
	UGint GetMaxZ(void) const;
	void UpdateDimensions();	
	
protected:
	UGMomentumCamera *m_pCameraBase;
    UGRenderTarget *m_pTarget;
    // Relative dimensions, irrespective of target dimensions (0..1)
    UGReal m_RelLeft, m_RelTop, m_RelWidth, m_RelHeight;
    // Actual dimensions, based on target dimensions
    UGint m_ActLeft, m_ActTop, m_ActWidth, m_ActHeight;
    /// ZOrder
    UGint m_ZOrder;

	UGint m_nMinZ;
	UGint m_nMaxZ;
    /// Background options
    UGColorValue m_BackColour;
    UGbool m_bClearEveryFrame;
	UGuint m_unClearBuffers;
    UGbool m_bUpdated;
    UGbool m_bShowOverlays;
    UGbool m_bShowSkies;
	UGbool m_bShowShadows;
	
	/// Material scheme
	UGString mMaterialSchemeName;
};

}
#endif // !defined(AFX_UGVIEWPORT_H__347A41D2_5BC2_4D44_A53B_B05C59B92FF5__INCLUDED_)
