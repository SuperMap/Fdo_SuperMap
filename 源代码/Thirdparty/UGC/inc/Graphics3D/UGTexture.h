// UGTexture.h: interface for the UGTexture class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(UGTEXTURE_H)
#define UGTEXTURE_H
#include "Graphics3D/UGGraphics3DHeaders.h"

namespace UGC{
class UGImageEx;
enum TextureType
{
	/// 1D texture, used in combination with 1D texture coordinates
	TEX_TYPE_1D = 1,
	/// 2D texture, used in combination with 2D texture coordinates (default)
	TEX_TYPE_2D = 2,
	/// 3D texture, used in combination with 3D texture coordinates
	TEX_TYPE_3D = 3,
	/// 3D cube map, used in combination with 3D texture coordinates
	TEX_TYPE_CUBE_MAP = 4,
};
//TODO:加入对Texture_Rectangle扩展的支持
class GRAPHICS3D_API UGTexture
{
public:
	UGTexture();
	virtual ~UGTexture();
	void SetTextureType(TextureType enType);
	TextureType GetTextureType();

	void SetPixelFormat(PixelFormat pf);
	PixelFormat GetPixelFormat();

	//!\brief specificially for the opengl texture implemention
	UGint GetGLID();

	virtual void Load(const UGImageEx* pImage,UGint nWidth, UGint nHeight, UGint nLevels){};
	virtual void Update(const UGImageEx* pImage,UGint nWidth, UGint nHeight, UGint nLevels){};
		
protected:
	TextureType m_enType;
	UGint m_nWidth;
	UGint m_nHeight;
	UGint m_nDepth;
	UGint m_nID;
	UGint m_nMipmapLevels;
	PixelFormat m_enFormat;
	UGint m_nBorder;
};
}

#endif // !defined(AFX_UGTEXTURE_H__ED721F50_87B4_4D76_B2BD_EC0C15406BC2__INCLUDED_)
