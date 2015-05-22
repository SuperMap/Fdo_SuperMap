// UGSky.h: interface for the UGSky class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGSKY_H__E8A41CA2_458F_4292_9227_B430A4D641A5__INCLUDED_)
#define AFX_UGSKY_H__E8A41CA2_458F_4292_9227_B430A4D641A5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Scene/UGPrerequisites.h"
#include "Scene/UGRenderObject.h"
namespace UGC
{
typedef enum SkyStyle
{
	SKY_STYLE_GLOABAL,
	SKY_STYLE_PLANE
};
typedef enum SkyImgStyle
{
	SKY_IMG_FILE,
	SKY_IMG_FRACTAL
};
class SCENE_API UGSky: public UGRenderObject
{

public:

	UGSky();
	UGSky(UGReal dLayerRadius,const UGString& strImagePath="");
	virtual ~UGSky();
public:
	void SetSkyStyle(SkyStyle style);
	void SetSkyImgStyle(SkyImgStyle style);
	void SetLayerRadius(UGReal dLayerRadius);
	UGString GetImagePath();
	void SetImagePath(const UGString& strImagePath);
	void GenFractalImg();
	void SurfToSkyImg(UGfloat *fa, UGint size, UGuchar *skyTex);
	UGReal GetOpacityPercent();
	void SetOpacity(UGReal dPercent);
	virtual void Render();
	virtual void Update();
	virtual void Initialize();
	virtual void Release();
private:
	void CreateGlobalMesh();
	void CreatePlaneMesh();
private:
	UGReal m_dLayerRadius;
	UGReal m_dMinLat;
	UGReal m_dMaxLat;
	UGReal m_dMinLon;
	UGReal m_dMaxLon;
	UGReal m_dVerticalExaggeration;
	UGbool m_bDisableZbuffer;
	UGString m_strImageUrl;
	UGString m_strImagePath;
	UGushort m_nMeshPointCount;

	// 天空类型

	SkyStyle m_SkyStyle;
	SkyImgStyle m_SkyImgStyle;


	// 分形相关

	UGuint  m_nCloudIter;
	UGfloat* m_pCloudFA;
	UGuint m_nRandomSeed;
	UGfloat m_fCloudH;
	UGint m_nChangefrequency;
};
}

#endif // !defined(AFX_UGSKY_H__E8A41CA2_458F_4292_9227_B430A4D641A5__INCLUDED_)
