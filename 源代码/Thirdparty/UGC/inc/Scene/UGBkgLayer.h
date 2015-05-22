
// UGBkgLayer.h: interface for the UGBkgLayer class.
// ±³¾°Í¼²ã
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGBKGLAYER_H__27CA6F61_7E0A_4530_BB08_2218AF4B3151__INCLUDED_)
#define AFX_UGBKGLAYER_H__27CA6F61_7E0A_4530_BB08_2218AF4B3151__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Scene/UGPrerequisites.h"
#include "Scene/UGRenderObject.h"

namespace UGC
{
class DrawArgs;
class SCENE_API UGBkgLayer: public UGRenderObject
{
public:
	UGBkgLayer();
	UGBkgLayer(UGdouble dLayerRadius,const UGString& strImagePath="");
	virtual ~UGBkgLayer();
public:
	void SetLayerRadius(UGdouble dLayerRadius);
	UGdouble GetLayerRadius();
	UGString GetImagePath();
	void SetImagePath(const UGString& strImagePath);
	UGdouble GetOpacityPercent();
	void SetOpacity(UGdouble dPercent);
	virtual void Render();
	virtual void Update();
	virtual void Initialize();
	virtual void Release();

	UGdouble GetMinLat();
	UGdouble GetMaxLat();
	UGdouble GetMinLon();
	UGdouble GetMaxLon();
	UGdouble GetRotateAngle();
	void SetMinLat(UGdouble value);
	void SetMaxLat(UGdouble value);
	void SetMinLon(UGdouble value);
	void SetMaxLon(UGdouble value);
	void SetRotateAngle(UGdouble value);
private:
	void CreateMesh();
private:
	UGdouble m_dLayerRadius;
	UGdouble m_dMinLat;
	UGdouble m_dMaxLat;
	UGdouble m_dMinLon;
	UGdouble m_dMaxLon;
	UGdouble m_dVerticalExaggeration;
	UGbool m_bDisableZbuffer;
	UGString m_strImageUrl;
	UGString m_strImagePath;
	UGushort m_nMeshPointCount;
	UGdouble m_dRotateAngle;
};
}

#endif // !defined(AFX_UGBKGLAYER_H__27CA6F61_7E0A_4530_BB08_2218AF4B3151__INCLUDED_)
