// UGTexture.h: interface for the UGTexture class.
// by-malq
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGTEXTURE_H__7BE6E4FE_7CC0_49A7_8592_672F01686416__INCLUDED_)
#define AFX_UGTEXTURE_H__7BE6E4FE_7CC0_49A7_8592_672F01686416__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Scene/UGPrerequisites.h"

namespace UGC
{
class SCENE_API UGTexture  
{
	class SCENE_API UGTextureData
	{
	public:
		UGTextureData()
		{
			m_pBuffer=NULL;
			m_nWidth=0;
			m_nHeight=0;
			m_enFormat=PF_UNKNOWN;
		}
		virtual ~UGTextureData()
		{
			 Release();
		}
		void Release()
		{
			if (m_pBuffer!=NULL) 
			{
				delete []m_pBuffer;
				m_pBuffer=NULL;
				m_nWidth=0;
				m_nHeight=0;
				m_enFormat=PF_UNKNOWN;
			}
		}
	public:
		UGuchar* m_pBuffer;
		UGuint m_nHeight;
		UGuint m_nWidth;
		UG3DPixelFormat m_enFormat;

	};
public:
	UGTexture();
	UGTexture(const UGString& strImgPath);
	virtual ~UGTexture();

	//! \brief 纹理对象ID第一次使用时创建一个纹理对象，若已创建纹理对象则该纹理对象进入活动状态。
	//! \param nTextureID 纹理对象ID[in]。
	//! \remarks D3D和GL都实现。		
	virtual void BindTexture()  = 0;
	//! \brief 删除纹理。
	//! \param nTextureID 纹理对象ID[in]。
	//! \remarks D3D和GL实现版本不一致，GL为在EndFrame中才删除纹理，D3D直接删除纹理。
	//! \attention 重新确定一下该函数功能。
	virtual void DeleteTexture(UGbool bReleaseImgData=TRUE) = 0;
	//! \brief 加载纹理数据。
	//! \param TextrueData 纹理数据对象[in]。
	//! \return 纹理对象ID。
	virtual void LoadTexture(UGbool bReleaseImgData=TRUE) = 0;

	//	 目前仅支持2维纹理，并且图像格式统一成RGBA	
	UGbool IsLoaded();
	UGbool LoadImageData(const UGString& strFilePath);
	UGbool LoadImageData();

	virtual void ReleaseImgData();


	UGuint GetLoadType(const UGString& strExt);
	UG3DPixelFormat IlFormat2ScnFormat( UGint ImageFormat,  UGint BytesPerPixel );
	UG3DPixelFormat ImgFormat2ScnFormat(PixelFormat pf);
	PixelFormat ScnFomat2ImgFormat(UG3DPixelFormat pf);
	void SetTextureData(UGint nWidth,UGint nHeight,UGuchar* pData);
	void FlipTexture();
	UGuint GetBindID();
	// 增加引用计数
	void AddRef();
	// 减小引用计数
	void DecRef();
	// 得到引用计数
	UGint GetRef(); 
	// malq-2007-9-6-临时添加，只是为了去掉数据的无效的白色边沿部分
	void TransparentInvalid();
	//! \brief 获取纹理是否是重复模式。
	//! \return TRUE为是，FALSE为否。
	UGbool IsTextureRepeatMode();
	//! \brief 设置纹理模式为重复模式。
	//! \param bRepeat TRUE为纹理重复模式，FALSE为非重复模式[in]。
	void   SetTextureRepeatMode(UGbool bRepeat);
	
public:
	UGString m_strTexFilePath;

protected:
	void RescaleNPower2();
	void ScaleImage(UGint nNewWidth,UGint nNewHeight);
	UGTextureData m_TextureData;
	UGuint m_nBindID;
	UGbool m_bLoadedImg;
	UGint m_nRefAdd;//引用计数

	//! \brief 标志纹理是否是重复贴图模式。
	//! \remarks TRUE为是，FALSE为不是。
	UGbool  m_bTextureRepeatMode;
};
/*

*/



/*
UGDict<UGString,UGTexture*> g_TextureManager;
UGDict<UGString,UGMaterial*>g_MaterialManager;
UGMaterial* FindMaterial(const UGString& strName)
{
	UGDict<UGString,UGMaterial*>::POSITION pos=g_MaterialManager.GetStartPosition();
	UGMaterial* pMaterial=NULL;
	while(!g_MaterialManager.IsEOF(pos))
	{
		UGString key;
		UGMaterial* pTemp=NULL;
		g_MaterialManager.GetNextAssoc(pos,key,pTemp);
		if (pTemp!=NULL && pTemp->m_strName.Compare(strName)==0) 
		{
			pMaterial=pTemp;
			break;
		}
	}
	return pMaterial;
}
UGMaterial* FindTexture(const UGString& strName)
{
	UGDict<UGString,UGTexture*>::POSITION pos=g_TextureManager.GetStartPosition();
	UGTexture* pTexture=NULL;
	while(!g_TextureManager.IsEOF(pos))
	{
		UGString key;
		UGTexture* pTemp=NULL;
		g_TextureManager.GetNextAssoc(pos,key,pTemp);
		if (pTemp!=NULL && pTemp->m_strName.Compare(strName)==0) 
		{
			pTexture=pTemp;
			break;
		}
	}
	return pTexture;
}
*/

}
#endif // !defined(AFX_UGTEXTURE_H__7BE6E4FE_7CC0_49A7_8592_672F01686416__INCLUDED_)
