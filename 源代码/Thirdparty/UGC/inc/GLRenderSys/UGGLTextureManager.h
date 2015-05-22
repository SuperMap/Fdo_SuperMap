/* 
	\file UGGLTextureManager.h
	\brief 纹理管理类。
	\author zhangyl luofx
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>更新说明：。</b>
	<em>1、第一条说明。</em>
	<em>2、第二条说明。</em>
*/

#if !defined(AFX_UGGLTEXTUREMANAGER_H__7B82CFE2_B69C_4BF4_A8E9_79E44C2A0041__INCLUDED_)
#define AFX_UGGLTEXTUREMANAGER_H__7B82CFE2_B69C_4BF4_A8E9_79E44C2A0041__INCLUDED_

#include "GLRenderSys/UGGLPrerequisites.h"
#include "Scene/UGTextureManager.h"

namespace UGC
{

//! \brief 纹理管理类。
class GLRENDERSYS_API UGGLTextureManager : public UGTextureManager 
{
public:

	//! \brief 带参数构造函数。
	//! \param *pGLSupport GLSupport指针[in]。
	UGGLTextureManager(UGGLSupport *pGLSupport);	
	
	//! \brief 析构函数。
	virtual ~UGGLTextureManager();	

public:

	//! \brief 获取纹理对象。
	//! \param strTextureName 名称[in]。
	//! \return 纹理对象指针。
	virtual UGTexture* GetTexture(const UGString& strTextureName);	
	
	//! \brief 删除无用纹理。
	virtual void DeleteUnusedTextures();	

private:

	//! \brief GL支持对象指针。
	UGGLSupport *m_pGLSupport;

};

}
#endif // !defined(AFX_UGGLTEXTUREMANAGER_H__7B82CFE2_B69C_4BF4_A8E9_79E44C2A0041__INCLUDED_)
