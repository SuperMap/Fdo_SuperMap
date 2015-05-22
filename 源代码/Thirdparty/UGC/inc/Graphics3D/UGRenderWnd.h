// UGRenderWnd.h: interface for the UGRenderWnd class.
//
//////////////////////////////////////////////////////////////////////
#ifndef UGRENDERWND_H
#define UGRENDERWND_H
#include "Graphics3D/UGGraphics3DHeaders.h"
#include "Graphics3D/UGObject3D.h"
#include "Base/UGString.h"
namespace UGC{
class UGSceneView;
class UGCamera;

#ifdef WIN32  //window stuff
	#include <windows.h>
	typedef HDC      Display;
	typedef HWND     Window;  
#endif
//!\brief base class of the render window
class GRAPHICS3D_API UGRenderWnd
{		
public:
	UGRenderWnd();
	UGRenderWnd(UGString& strName);
	virtual ~UGRenderWnd();	

	//!\brief Set the input window handle
	void SetExternalWnd(Window hWnd);
	Window GetExternalWnd();

	//!\brief Set the dc handle attached to the render wnd
	void SetDisplay(Display hDC);
	Display GetDisplay();

	//!\brief special for the X11 implemention
	void SetHostName(UGString& strName);
	const UGString& GetHostName()const;

	//!\brief set the name of the window
	void SetWindowName(UGString& strName);
	const UGString& GetWindowName()const;
	//!\brief set and get the dimension of the render window
	void SetWindowRect(UGint nLeft, UGint nTop, UGint nWidth, UGint nHeight);
	void GetWindowRect(UGint& nLeft, UGint& nTop, UGint& nWidth, UGint& nHeight);
	UGint GetWindowOriginX();
	UGint GetWindowOriginY();
	UGint GetWindowWidth();
	UGint GetWindowHeight();

	//!\brief Get the basic information
	UGint GetColorDepth(void);
	void SetColroDepth(UGint nDepth);
	
	//!\brief initialize the window according to the configuration
	virtual void Realize() = 0;
	virtual void Destroy() = 0;
	virtual void Update() = 0;
	//!\brief Swap buffers
	virtual void SwapBuffers(void) = 0;

	//!\brief get the status of the render wnd;
	UGbool IsRealized();
	void   FullScreen(UGbool bFlag);
	UGbool IsFullScreen();


	//!\brief support the multiple render context in OpenGL
	void  MakeCurrent();	
	
	//!\brief Create the scene view on the render target
	UGSceneView* CreateSceneView(UGCamera* pCam, Real fLeft = 0.0f, Real fTop = 0.0f ,
								Real fWidth = 1.0f, Real fHeight = 1.0f,UGint nZOrder = 0);
	
	//!\brief  basic operations on the viewport of the render target
	UGSceneView* GetSceneView(UGushort nIndex);
	void RemoveAllSceneView(void);
	void RemoveSceneView(UGint nZOrder);
	UGushort GetSceneViewCount(void);
	
	//!\brief set the current active viewport;
	void SetActiveSceneView(UGSceneView* pViewPort);
	UGushort* GetActiveSceneView(void);
	
protected:

	UGString m_strName;
	UGint m_nLeft;
	UGint m_nTop;
	UGint  m_nWidth;
	UGint  m_nHeight;
	UGint  m_nColourDepth;
	UGbool m_bIsDepthBuffered;	
	UGbool m_bIsActive;
	UGbool m_bIsRealized;
	UGuchar m_nPriority;
	typedef UGArray<UGSceneView*> SceneViewList;
	SceneViewList m_pViewPortList;	
	UGbool m_bIsFullScreen;
	
	Window m_hWnd;
	Display m_hDC;	
};
}

#endif // !defined(UGRENDERWND_H)
