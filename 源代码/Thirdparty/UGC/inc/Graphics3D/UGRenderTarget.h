// UGRenderTarget.h: interface for the UGRenderTarget class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(UGRENDERTARGET_H)
#define UGRENDERTARGET_H
#include "Graphics3D/UGGraphics3DHeaders.h"

namespace UGC{
class UGSceneView;
class UGCamera;
//!\brief 渲染目标基类
class GRAPHICS3D_API UGRenderTarget  
{
public:
	UGRenderTarget();
	virtual ~UGRenderTarget();

	//!\brief Get the basic information
	UGint GetWidth(void);
	UGint GetHeight(void);
	UGString& GetName(void);
	UGint GetColorDepth(void);
	//!\brief support the multiple render context in OpenGL
	void  MakeCurrent();	
	
	//!\brief Create the scene view on the render target
	UGSceneView* CreateSceneView(UGCamera* pCam, Real fLeft = 0.0f, Real fTop = 0.0f ,
								Real fWidth = 1.0f, Real fHeight = 1.0f,UGint nZOrder = 0, );

	//!\brief  basic operations on the viewport of the render target
	UGSceneView* GetViewPort(UGushort nIndex);
	void RemoveAllViewPort(void);
	void RemoveViewPort(UGint nZOrder);
	UGushort GetViewPortCount(void);

	//!\brief set the current active viewport;
	void SetActiveViewPort(UGSceneView* pViewPort);
	UGushort* GetActiveViewPort(void);
	
protected:
	UGString m_strName;
	UGint  m_nWidth;
	UGint  m_nHeight;
	UGint  m_nColourDepth;
	UGbool m_bIsDepthBuffered;	
	UGbool m_bIsActive;
	UGbool m_bIsInited;
	UGuchar m_nPriority;
	typedef UGArray<UGSceneView*> SceneViewList;
	SceneViewList m_pViewPortList;	
};
}

#endif // !defined(UGRENDERTARGET_H)
