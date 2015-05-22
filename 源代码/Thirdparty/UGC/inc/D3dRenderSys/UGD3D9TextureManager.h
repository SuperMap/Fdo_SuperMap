/* 
	\file UGD3D9TextureManager.h
	\brief D3D纹理管理类。
	\author zhangyl luofx
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>更新说明：。</b>
	<em>1、第一条说明。</em>
	<em>2、第二条说明。</em>
*/

#if !defined(AFX_UGD3D9TEXTUREMANAGER_H__B57DCB1F_DB41_4255_BF5F_0C3751BF2801__INCLUDED_)
#define AFX_UGD3D9TEXTUREMANAGER_H__B57DCB1F_DB41_4255_BF5F_0C3751BF2801__INCLUDED_

#include "D3dRenderSys/UGD3D9Prerequisites.h"
#include "Scene/UGTextureManager.h"

namespace UGC
{

//! \brief 纹理对象管理类。
class D3DRENDERSYS_API UGD3D9TextureManager : public UGTextureManager
{

public:
	
	//! \brief 构造函数。
	UGD3D9TextureManager();	
	
	//! \brief 带参数构造函数。
	//! \param m_pD3DDevice 设备对象[in]。
	//! \param pppTexture 纹理数组首指针[in]。
	UGD3D9TextureManager(LPDIRECT3DDEVICE9 m_pD3DDevice, LPDIRECT3DTEXTURE9* pppTexture);	
	
	//! \brief 析构函数。
	virtual ~UGD3D9TextureManager();	

public:

	//! \brief 获取纹理对象。
	//! \param strTextureName 纹理对象名称[in]。
	virtual UGTexture* GetTexture(const UGString& strTextureName);	
	
	//! \brief 删除无用纹理。
	virtual void DeleteUnusedTextures();	

protected:
	
	//! \brief 设备对象。
	LPDIRECT3DDEVICE9 m_pD3DDevice;

	//! \brief 纹理数组首地址。
	LPDIRECT3DTEXTURE9* m_ppTexture;	
	
};

}
#endif // !defined(AFX_UGD3D9TEXTUREMANAGER_H__B57DCB1F_DB41_4255_BF5F_0C3751BF2801__INCLUDED_)
