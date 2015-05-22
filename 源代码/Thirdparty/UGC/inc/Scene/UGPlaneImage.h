// UGPlaneImage.h: interface for the UGPlaneImage class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGPLANEIMAGE_H__EDE34C08_8EF1_4FC6_8676_86347969D06D__INCLUDED_)
#define AFX_UGPLANEIMAGE_H__EDE34C08_8EF1_4FC6_8676_86347969D06D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Scene/UGPrerequisites.h"
#include "Scene/UGRenderObject.h"

namespace UGC
{
class SCENE_API UGPlaneImage: public UGRenderObject  
{
public:
	UGPlaneImage();
	UGPlaneImage(const UGString& strImagePath,UGbool fixedWidthAndHeight, UGdouble dStartXRatio,UGdouble dStartYRatio,UGdouble Width, UGdouble Height, UGbool bSupportRotate = FALSE);

	virtual ~UGPlaneImage();
	virtual void Render();
	virtual void Update();
	virtual void Initialize();
	virtual void Release();
	void SetImagePath(const UGString& strImagePath);
	virtual void UpdateParams();
	virtual UGdouble GetAlphaRejectSetting();
	// alpha值在[0, 255]之间
	virtual void SetAlphaRejectSetting(UGdouble dAlphaRejectSetting);
//	virtual void ComputeRotateAngle();

private:

	UGString m_strImagePath;
	UGdouble m_dStartXRatio;
	UGdouble m_dStartYRatio;
	UGdouble m_dWidthRatio;
	UGdouble m_dHeightRatio;
	UGbool m_bFixedSize;
	UGbool m_bSupportRotate; 
	UGint m_nStartX;
	UGint m_nStartY;
	UGint m_nWidth;
	UGint m_nHeight;
	UGdouble m_dAngleRotate;
	UGdouble m_dAlphaRejectSetting;

	UGTexture* m_pTexture;

};
}


#endif // !defined(AFX_UGPLANEIMAGE_H__EDE34C08_8EF1_4FC6_8676_86347969D06D__INCLUDED_)
