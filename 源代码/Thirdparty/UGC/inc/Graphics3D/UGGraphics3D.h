// UGGraphics3D.h: interface for the UGGraphics3D class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(UGGRAPHCIS3D_H)
#define UGGRAPHCIS3D_H

#include "Graphics3D/UGGraphics3DHeaders.h"
#include "UGTexture.h"
#include "Base/UGString.h"
namespace UGC
{
class UGTexture;
class UGRenderWnd;
class UGGraphics3DCapabilities;
class GRAPHICS3D_API UGGraphics3D  
{
public:
	UGGraphics3D();
	virtual ~UGGraphics3D();
	
	virtual void BeginDrawScene(){};
	virtual void DrawPrimitiveSet(UGPrimitiveSet* pPrimitiveSet){};
	virtual void SetMaterial(UGMaterial* pMaterial){};


	virtual UGRenderWnd* CreateRenderWnd() = 0;
	virtual UGRenderWnd* CreateRenderWnd(UGString& strName) = 0;


	virtual UGTexture* CreateTexture(UGint nContextID,TextureType enType) = 0;
	virtual UGTexture* CreateTexture(UGint nContextID,TextureType enType,UGint nMimapLevels,PixelFormat pf,UGint nWidth,UGint nHeight,UGint nDepth,UGint nBorder)= 0;

	virtual UGGraphics3DCapabilities* GetGraphics3DCapabilities() = 0;

protected:
	

};
}
#endif // !defined(UGGRAPHCIS3D_H)
