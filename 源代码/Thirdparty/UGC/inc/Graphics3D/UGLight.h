// UGLight.h: interface for the UGLight class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(UGLIGHT_H)
#define UGLIGHT_H
#include "Graphics3D/UGGraphics3DHeaders.h"
#include "UGColorValue.h"
#include "UGVector3.h"

namespace UGC
{

class GRAPHICS3D_API UGLight
{
public:
	enum LightTypes
    {
		/// Point light sources give off light equally in all directions, so require only position not direction
		LT_POINT,
		/// Directional lights simulate parallel light beams from a distant source, hence have direction but no position
		LT_DIRECTIONAL,
		/// Spotlights simulate a cone of light from a source so require position and direction, plus extra values for falloff
		LT_SPOTLIGHT
    };
public:
	UGLight();
	virtual ~UGLight();

	LightTypes		GetType(void);
	void			SetType(LightTypes nType);	

	void            SetDiffuseColor(Real red, Real green, Real blue);
	void			SetDiffuseColor(const UGColorValue& color);
	UGColorValue	GetDiffuseColor(void);
	
	void			SetSpecularColor(Real red, Real green, Real blue);
	void			SetSpecularColor(const UGColorValue& color);
	UGColorValue	GetSpecularColor(void);
	
	void			SetAttenuation(Real range, Real constant, Real linear, Real quadratic);
	Real			GetAttenuationRange(void);
	Real			GetAttenuationConstant(void);
	Real			GetAttenuationLinear(void);
	Real			GetAttenuationQuadric(void);
	
	
	void			SetPosition(Real x, Real y, Real z);
	void			SetPosition(UGVector3& vec);
	UGVector3&		GetPosition(void);
	
	void			SetDirection(Real x, Real y, Real z);
	void			SetDirection(UGVector3& vec);
	UGVector3&		GetDirection(void);
	
	void			SetSpotLightRange(Real fInnerAngle,Real fOuterAngle,Real falloff = 1.0 );
	Real			GetSpotLightInnerAngle(void);
	Real			GetSpotLightOuterAngle(void);
	Real			GetSpotLightFallOff(void);

protected:
	LightTypes  m_LightType;
	UGVector3   m_vPosition;
	UGVector3   m_vDirection;

	Real			m_fSpotOuter;
	Real			m_fSpotInner;
	Real			m_fSpotFallOff;
	Real			m_fRange;
    Real			m_fAttenuationConst;
    Real			m_fAttenuationLinear;
    Real			m_fAttenuationQuad;
	
	UGColorValue		m_cSpecularColor;
	UGColorValue		m_cDiffuseClolor;		
};
}

#endif // !defined(UGLIGHT_H)
