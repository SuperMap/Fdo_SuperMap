/* 
	\file UGD3D9Texture.h
	\brief D3D纹理对象类。
	\author 张艳良  luofx
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>更新说明：。</b>
	<em>1、第一条说明。</em>
	<em>2、第二条说明。</em>
*/


#if !defined(AFX_UGD3D9TEXTURE_H__0D158FAF_52C9_4755_BF83_A3473C71015F__INCLUDED_)
#define AFX_UGD3D9TEXTURE_H__0D158FAF_52C9_4755_BF83_A3473C71015F__INCLUDED_

#include "D3dRenderSys/UGD3D9Prerequisites.h"
#include "Scene/UGTexture.h"

namespace UGC
{

//! \brief D3D纹理类。
class UGD3D9Texture : public UGTexture
{
	
public:
	
	//! \brief 构造函数。
	UGD3D9Texture();	
	//! \brief 带有参数构造函数。
	//! \param strImgPath 纹理图片路径[in]。
	//! \param pD3DDevice D3D设备对象[in]。
	//! \param ppTexture 纹理对象集合指针[in]。
	UGD3D9Texture(const UGString& strImgPath, LPDIRECT3DDEVICE9 pD3DDevice, LPDIRECT3DTEXTURE9* ppTexture);	
	//! \brief 析构函数。
	virtual ~UGD3D9Texture();	


public:
	//! \brief 绑定纹理。
	virtual void BindTexture();

	//! \brief 加载纹理数据。
	//! \param bReleaseImgData=TRUE 是否释放图片数据[in]。
	virtual void LoadTexture(UGbool bReleaseImgData=TRUE) ;
	
	//! \brief 删除纹理。
	//! \param bReleaseImgData=TRUE [in]。
	virtual void DeleteTexture(UGbool bReleaseImgData=TRUE) ;	

private:

	//! \brief 生成纹理ID。
	//! \return 纹理ID 。
	UGuint GenTextureID();	

protected:

	//! \brief 设备对象。
	LPDIRECT3DDEVICE9 m_pD3DDevice;
	//! \brief 纹理集合首指针。
	LPDIRECT3DTEXTURE9* m_ppTexture;	
};

}
#endif // !defined(AFX_UGD3D9TEXTURE_H__0D158FAF_52C9_4755_BF83_A3473C71015F__INCLUDED_)
