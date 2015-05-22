// UGTextureUnitState.h: interface for the UGTextureUnitState class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGTEXTUREUNITSTATE_H__8CD48F14_6B32_4535_AAFC_1AE07A7A4CF6__INCLUDED_)
#define AFX_UGTEXTUREUNITSTATE_H__8CD48F14_6B32_4535_AAFC_1AE07A7A4CF6__INCLUDED_

#include "Scene/UGPrerequisites.h"
#include "Scene/UGLayerBlendMode.h"
#include "Scene/UGColorValue.h"
#include "Scene/UGMatrix4d.h"
#include "Scene/UGAngle.h"

namespace UGC 
{
class SCENE_API UGTextureUnitState  
{
	friend class UGRenderSys;
public:
	 enum TextureEffectType
    {
        /// Generate all texture coords based on angle between camera and vertex
        ET_ENVIRONMENT_MAP,
        /// Generate texture coords based on a frustum
        ET_PROJECTIVE_TEXTURE,
        /// Constant u/v scrolling effect
        ET_UVSCROLL,
		/// Constant u scrolling effect
        ET_USCROLL,
		/// Constant u/v scrolling effect
        ET_VSCROLL,
        /// Constant rotation
        ET_ROTATE,
        /// More complex transform
        ET_TRANSFORM

    };
	  /** Enumeration to specify type of envmap.
    @note
        Note that these have no effect when using the programmable pipeline, since their
        effect is overridden by the vertex / fragment programs.
    */
    enum EnvMapType
    {
        /// Envmap based on vector from camera to vertex position, good for planar geometry
        ENV_PLANAR,
        /// Envmap based on dot of vector from camera to vertex and vertex normal, good for curves
        ENV_CURVED,
        /// Envmap entended to supply reflection vectors for cube mapping
        ENV_REFLECTION,
        /// Envmap entended to supply normal vectors for cube mapping
        ENV_NORMAL
    };

	 /** Texture addressing modes - default is TAM_WRAP.
        @note
            These settings are relevant in both the fixed-function and the
            programmable pipeline.
        */
    enum TextureAddressingMode
    {
        /// Texture wraps at values over 1.0
        TAM_WRAP,
        /// Texture mirrors (flips) at joins over 1.0
        TAM_MIRROR,
        /// Texture clamps at 1.0
        TAM_CLAMP,
        /// Texture coordinates outside the range [0.0, 1.0] are set to the border colour
        TAM_BORDER
    };
	 /** Internal structure defining a texture effect.
        */
    struct TextureEffect {
        TextureEffectType type;
        UGint subtype;
        UGReal arg1, arg2;
        WaveformType waveType;
        UGReal base;
        UGReal frequency;
        UGReal phase;
        UGReal amplitude;
        //Controller<Real>* controller;
        const UGFrustum* pFrustum;
    };
	/** Texture addressing mode for each texture coordinate. */
	struct UVWAddressingMode
	{
		TextureAddressingMode u, v, w;
	};
	typedef UGDict<TextureEffectType, TextureEffect> EffectMap;
public:
	UGTextureUnitState();
	virtual ~UGTextureUnitState();

	UGbool IsBlank(void) const;
	const UGString& GetTextureName(void) const;
	UGuint GetTextureCoordSet(void) const;
	FilterOptions GetTextureFiltering(FilterType ftpye) const;
	UGuint GetTextureAnisotropy() const;
	const UGLayerBlendModeEx& GetColourBlendMode(void) const;
	const UGLayerBlendModeEx& GetAlphaBlendMode(void) const;
	const UVWAddressingMode& GetTextureAddressingMode(void) const;
	const UGColorValue& GetTextureBorderColour(void) const;	
	const UGMatrix4d& GetTextureTransform(void) const;

protected:
	void RecalcTextureMatrix(void) const;

protected:
	UGbool m_bBlank;
	UGuint m_unCurrentFrame;
	UGuint m_unTextureCoordSetIndex;
	UGbool m_bDefaultFiltering;

	FilterOptions m_MinFilter;

	UGList<UGString> m_Frames;
	UGbool m_bDefaultAniso;
	UGLayerBlendModeEx m_ColourBlendMode;
	UGLayerBlendModeEx m_AlphaBlendMode;
	UVWAddressingMode m_AddressMode;
	UGColorValue m_BorderColour;

	EffectMap m_Effects;
	mutable UGbool m_bRecalcTexMatrix;
	mutable UGMatrix4d m_TexModMatrix;

	UGReal m_dUMod, m_dVMod;
	UGReal m_dUScale, m_dVScale;
	UGAngle m_Rotate;	
};
}
#endif // !defined(AFX_UGTEXTUREUNITSTATE_H__8CD48F14_6B32_4535_AAFC_1AE07A7A4CF6__INCLUDED_)
