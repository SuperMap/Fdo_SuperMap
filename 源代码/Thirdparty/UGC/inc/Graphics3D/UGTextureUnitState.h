// UGTextureUnitState.h: interface for the UGTextureUnitState class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(UGTEXTUREUNITSTATE_H)
#define UGTEXTUREUNITSTATE_H
#include "Graphics3D/UGGraphics3DHeaders.h"
#include "UGTexture.h"
#include "UGColorValue.h"
namespace UGC{
class UGImageEx;
enum WrapTarget
{
	WRAP_S,
	WRAP_T,
	WRAP_R
};	
enum WrapMode 
{
	CLAMP,
	CLAMP_TO_EDGE,
	CLAMP_TO_BORDER,
	REPEAT,
	MIRROR
};
enum FilterMode 
{
	LINEAR,
	LINEAR_MIPMAP_LINEAR,
	LINEAR_MIPMAP_NEAREST,
	NEAREST,
	NEAREST_MIPMAP_LINEAR,
	NEAREST_MIPMAP_NEAREST
};
//TODO:多纹理之间操作参数的支持
class GRAPHICS3D_API UGTextureUnitState  
{
public:
	UGTextureUnitState();
	virtual ~UGTextureUnitState();	
	
	void SetImage(UGImageEx* pImage);
	UGImageEx* GetImage();
	
	TextureType GetTextureType();
	void SetTextureType(TextureType enType);

	void SetWrapMode(WrapTarget enTarget,WrapMode enMode);
	WrapMode GetWrapMode(WrapTarget enTarget);

	void SetMinFilterMode(FilterMode enFilterMode);
	FilterMode GetMinFilterMode();

	void SetMaxFilterMode(FilterMode enFilterMode);
	FilterMode GetMaxFilterMode();

	void SetTextureCoordIndex(UGint nIndex);
	UGint GetTextureCoordIndex();

	void SetMaxAnisotropy(UGfloat fMaxAnisotropy);
	UGfloat GetMaxAnisotropy();

	void Load();
	
protected:
	TextureType m_enType;
	UGImageEx* m_pImage;	
	FilterMode m_enMinFilter;
	FilterMode m_enMaxFilter;
	UGfloat    m_fMaxAnisotropy;
	UGColorValue m_BordColor;
	UGint      m_nBordWidth;
	WrapMode  m_enWrapS;
	WrapMode  m_enWrapR;
	WrapMode  m_enWrapT;
	UGbool m_bTextureObjectDirty;
	UGint m_nTextureCoordIndex;
};
}

#endif // !defined(AFX_UGTEXTUREUNITSTATE_H__2830045D_C9F7_48CF_B845_2CCA487B0A6E__INCLUDED_)
