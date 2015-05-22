// UGGLRenderWnd.h: interface for the UGGLRenderWnd class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(UGGLRENDERWND_H)
#define UGGLRENDERWND_H

#include "Graphics3D/UGGraphics3D.h"
#include "Base/ugdefs.h"
#include "Graphics3D/UGRenderWnd.h"

#ifdef WIN32  //window stuff
	#include <windows.h>
	namespace UGC {	
		typedef HGLRC    GLContext;
		typedef WPARAM   KeySymbol;
		typedef HCURSOR  Cursor;
		typedef PIXELFORMATDESCRIPTOR  VisualInfo;  
	}
#else  //X11 stuff

	#include <X11/Xlib.h>  
	#include <X11/Xutil.h>
	#include <GL/glx.h>

	namespace UGC{
		// Display, Window and Cursor natively defined
		typedef GLXContext GLContext;
		typedef GLXPbuffer Pbuffer;
		typedef KeySym    KeySymbol;
		typedef XVisualInfo VisualInfo;	
	}

#endif

namespace UGC{
class GLGRAPHICS_API UGGLRenderWnd :public UGRenderWnd
{
public:
	UGGLRenderWnd();
	virtual ~UGGLRenderWnd();
	virtual void Realize(){};
	virtual void Destroy(){};
	virtual void Update(){};
	virtual void SwapBuffers(void){};
protected:
	GLContext m_GLRC;
};
}

#endif // !defined(AFX_UGGLRENDERWND_H__62F5DF99_5E06_4E39_9623_1435DE5A06EA__INCLUDED_)
