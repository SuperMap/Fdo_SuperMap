// UG2DImage.h: interface for the UG2DImage class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UG2DIMAGE_H__285A74F4_BF7E_4E68_8F8D_B4D1E19B2199__INCLUDED_)
#define AFX_UG2DIMAGE_H__285A74F4_BF7E_4E68_8F8D_B4D1E19B2199__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Scene/UGPrerequisites.h"
#include "Scene/UGRenderable.h"
namespace UGC
{
	class SCENE_API UG2DImage:  public UGRenderable , public UGMovableObject
	{
	public:
		UG2DImage();
		UG2DImage(UGdouble dLayerRadius,const UGString& strImagePath="");
		virtual ~UG2DImage();
	public:
		void SetLayerRadius(UGdouble dLayerRadius);
		UGString GetImagePath();
		void SetImagePath(const UGString& strImagePath);
		UGdouble GetOpacityPercent();
		void SetOpacity(UGdouble dPercent);
		virtual void Render();
		virtual void Update();
		virtual void Initialize();
		virtual void Release();
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
	};

}


#endif // !defined(AFX_UG2DIMAGE_H__285A74F4_BF7E_4E68_8F8D_B4D1E19B2199__INCLUDED_)
