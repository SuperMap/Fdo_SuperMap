// UGTextureManager.h: interface for the UGTextureManager class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(UGTEXTUREMANAGER_H)
#define UGTEXTUREMANAGER_H
#include "Graphics3D/UGGraphics3DHeaders.h"
#include "Base/UGArray.h"
#include "Base/UGDict.h"
#include "UGTexture.h"
namespace UGC{
class UGTexture;
class GRAPHICS3D_API UGTextureManager  
{
public:
	UGTextureManager();
	virtual ~UGTextureManager();
	UGTexture* CreateTexture(UGint nContextID,TextureType enType);
	UGTexture* CreateTexture(UGint nContextID,TextureType enType,UGint nMimapLevels,PixelFormat pf,UGint nWidth,UGint nHeight,UGint nDepth,UGint nBorder);
//	UGTexture* ReuseTexture(UGint nContextID,TextureType enType,UGint nMimapLevels,PixelFormat pf,UGint nWidth,UGint nHeight,UGint nDepth,UGint nBorder);
//	UGTexture* CreateOrReuseTexture(UGint nContextID,TextureType enType,UGint nMimapLevels,PixelFormat pf,UGint nWidth,UGint nHeight,UGint nDepth,UGint nBorder);
	
protected:
	typedef UGArray<UGTexture*> TextureList;
	TextureList m_TextureBuffers;
	UGDict<UGint,TextureList> m_TextureListMap;
};
}

#endif // !defined(AFX_UGTEXTUREMANAGER_H__0EA2CF69_FFDE_443B_B334_BB42436C6CF5__INCLUDED_)
