// UGFog.h: interface for the UGFog class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(UGFOG_H)
#define UGFOG_H
#include "Graphics3D/UGGraphics3DHeaders.h"
#include "Graphics3D/UGColorValue.h"
namespace UGC{
enum FogMode
{
	/// No fog.
	FOG_NONE,
	/// Fog density increases  exponentially from the camera (fog = 1/e^(distance * density))
	FOG_EXP,
	/// Fog density increases at the square of FOG_EXP, i.e. even quicker (fog = 1/e^(distance * density)^2)
	FOG_EXP2,
	/// Fog density increases linearly between the start and end distances
	FOG_LINEAR
};	
class GRAPHICS3D_API UGFog
{
public:
	UGFog();
	virtual ~UGFog();
	void SetFog(
		FogMode enMode = FOG_NONE, UGColorValue color = UGColorValue::White,
		Real fExpDensity = 0.001, Real fLinearStart = 0.0, Real fLinearEnd = 1.0);
	FogMode GetFogMode(void) const;
	const UGColorValue & GetFogColor(void) const;
	Real GetFogStart(void) const;
    Real GetFogEnd(void) const;
    Real GetFogDensity(void) const;
	
	void SetFogMode(FogMode enMode);
	void SetFogColor(const UGColorValue& color);
	void SetFogStart(Real fFogStart);
    void SetFogEnd(Real fFogEnd);
    void SetFogDensity(Real fFogDensity);
	UGFog& operator =(const UGFog& fog);	

protected:
	FogMode m_FogMode;
	UGColor m_FogColor;
	Real m_fFogStart;
	Real m_fFogEnd;
	Real m_fFogDensity;	

};

}

#endif // !defined(UGFOG_H)
