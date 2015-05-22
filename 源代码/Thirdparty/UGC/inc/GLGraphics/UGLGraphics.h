// UGLGraphics.h: interface for the UGLGraphics class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(UGLGRAPHICS_H)
#define UGLGRAPHICS_H

#include "Base/ugdefs.h"
#include "Graphics3D/UGGraphics3D.h"
namespace UGC{
class GLGRAPHICS_API UGLGraphics :public UGGraphics3D
{
public:
	UGLGraphics();
	virtual ~UGLGraphics();

	virtual void BeginDrawScene(){};
	virtual void DrawPrimitiveSet(UGPrimitiveSet* pPrimitiveSet){};
	virtual void SetMaterial(UGMaterial* pMaterial){};

	virtual UGGraphics3DCapabilities* GetGraphics3DCapabilities(){return NULL;} 
	virtual UGRenderWnd* CreateRenderWnd(){return NULL;};
	virtual UGRenderWnd* CreateRenderWnd(UGString& strName){return NULL;};
	
	virtual UGTexture* CreateTexture(UGint nContextID,TextureType enType){return NULL;};
	virtual UGTexture* CreateTexture(UGint nContextID,TextureType enType,UGint nMimapLevels,PixelFormat pf,UGint nWidth,UGint nHeight,UGint nDepth,UGint nBorder){return NULL;};
	
protected:
	

};
}

#endif // !defined(AFX_UGLGRAPHICS_H__69387546_8F5B_4556_BB74_9BC512A88BBC__INCLUDED_)
