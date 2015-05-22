/* 
	\file UGLight.h
	\brief 文件内容的简要描述。
	\author 文件作者
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>更新说明：。</b>
	<em>1、第一条说明。</em>
	<em>2、第二条说明。</em>
*/

// UGLight.h: interface for the UGLight class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGLIGHT_H__7A46AF17_BFD1_4C51_8148_C638C4D9EB3B__INCLUDED_)
#define AFX_UGLIGHT_H__7A46AF17_BFD1_4C51_8148_C638C4D9EB3B__INCLUDED_

#include "Scene/UGPrerequisites.h"
#include "Scene/UGAngle.h"
#include "Scene/UGColorValue.h"
#include "Scene/UGVector3R.h"
#include "Scene/UGMovableObject.h"
#include "Scene/UGQuaternion4d.h"

namespace UGC 
{
class SCENE_API UGLight : public UGMovableObject 
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
	
	UGLight();
	UGLight(const UGString& name);
	UGLight(const UGString& name, UGScene* pCreator);
	~UGLight();

    void SetType(LightTypes type);
    LightTypes GetType() const;
	
	void SetDiffuseColour(UGReal red, UGReal green, UGReal blue);
	void SetDiffuseColour(const UGColorValue& colour);
	UGColorValue GetDiffuseColour() const;

//	void SetAmbientColour(UGReal red, UGReal green, UGReal blue);
//	void SetAmbientColour(const UGColorValue& colour);
//	UGColorValue GetAmbientColour() const;

	void SetSpecularColour(UGReal red, UGReal green, UGReal blue);
	void SetSpecularColour(const UGColorValue& colour);
	UGColorValue GetSpecularColour() const;
	
	void SetAttenuation(UGReal range, UGReal constant, UGReal linear, UGReal quadratic);
	UGReal GetAttenuationRange() const;
	UGReal GetAttenuationConstant() const;
	UGReal GetAttenuationLinear() const;
	UGReal GetAttenuationQuadric() const;
	
	
	void SetPosition(UGReal x, UGReal y, UGReal z);
	void SetPosition(const UGVector3R& vec);
	UGVector3R GetPosition() const;
	
	void SetDirection(UGReal x, UGReal y, UGReal z);
	void SetDirection(const UGVector3R& vec);
	UGVector3R GetDirection() const;
	
	
	void SetSpotlightRange(UGReal innerAngle, UGReal outerAngle, UGReal falloff = 1.0);
	void SetSpotlightInnerAngle(UGReal val);
	UGReal GetSpotlightInnerAngle(void) const;
	void SetSpotlightOuterAngle(UGReal val);
	UGReal GetSpotlightOuterAngle() const;
	void SetSpotlightFalloff(UGReal val);
	UGReal GetSpotlightFalloff() const;

	UGVector4R GetAs4DVector() const;
	void SetPowerScale(UGReal power);
	UGReal GetPowerScale() const;

	UGVector3R GetDerivedPosition() const;
	UGVector3R GetDerivedDirection() const;


	
	
	
//	const AxisAlignedBox& GetBoundingBox(void) const;	
//	void _updateRenderQueue(RenderQueue* queue);	
//	const String& GetMovableType(void) const;	
//	void SetVisible(bool visible);
//	virtual const PlaneBoundedVolume& _GetNearClipVolume(const Camera* const cam) const;	
//	virtual const PlaneBoundedVolumeList& _GetFrustumClipVolumes(const Camera* const cam) const;	
//	UGReal GetBoundingRadius(void) const { return 0; /* not visible */ }	
//	uint32 GetTypeFlags(void) const;
//	AnimableValuePtr createAnimableValue(const String& valueName);

protected:
	void Update() const;
	
protected:
	LightTypes m_LightType;
	UGReal m_fSpotFalloff;
	UGReal m_fSpotInner;
	UGReal m_fSpotOuter;
	UGColorValue m_Diffuse;
	UGColorValue m_Specular;
	mutable UGVector3R m_vecDerivedPosition;
 	mutable UGVector3R m_vecDerivedDirection;
	UGReal m_fRange;
	UGReal m_fPowerScale;
	UGReal m_fAttenuationConst;
	UGReal m_fAttenuationLinear;
	UGReal m_fAttenuationQuad;


	UGVector3R m_vecPosition;
	UGVector3R m_vecDirection;
	
	mutable UGQuaternion4d m_quaLastParentOrientation;
	mutable UGVector3R m_vecLastParentPosition;

	mutable UGbool m_bLocalTransformDirty;
public:
	static UGString FACTORY_TYPE_NAME;
};
typedef UGList<UGLight*> UGLightList;


}
#endif // !defined(AFX_UGLIGHT_H__7A46AF17_BFD1_4C51_8148_C638C4D9EB3B__INCLUDED_)
