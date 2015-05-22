// UGTextureManager.h: interface for the UGTextureManager class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGTEXTUREMANAGER_H__740876F2_4FCC_4AE2_B7C8_8D9D55419691__INCLUDED_)
#define AFX_UGTEXTUREMANAGER_H__740876F2_4FCC_4AE2_B7C8_8D9D55419691__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Scene/UGPrerequisites.h"
#include "Scene/UGSingleton.h"
#include "Scene/UGTextureCacheEntry.h"

namespace UGC
{

class  SCENE_API UGTextureManager: public  UGSingleton<UGTextureManager>
{
public:
	UGTextureManager();
	virtual ~UGTextureManager();

public:
	// 这个函数先从管理器中找，找到了就返回，如果找不到就创建这个纹理
	virtual UGTexture* GetTexture(const UGString& strTextureName) = 0;
	void  RemoveTexture(UGTexture* pTexture);
	virtual void DeleteUnusedTextures() = 0;

protected:		
	virtual void DeleteTexture(UGuint nTextureID);		
	
	void  RemoveTexture(const UGString& strTextureName);
	// 必须实现这个函数
	void Release();
	void AddToCache(UGTextureCacheEntry* pTc);
	void DelNoUseTexture();
	
public:
	static UGTextureManager& GetSingleton();
	
public:
	static UGint ms_nCacheSize;
protected:
	//! \brief 保存纹理数据流
	UGbyte m_btTexDelFlag [MAX_TEXTURE_NUM];
	UGList<UGTextureCacheEntry*> m_TextureCache;

};
}
#endif // !defined(AFX_UGTEXTUREMANAGER_H__740876F2_4FCC_4AE2_B7C8_8D9D55419691__INCLUDED_)
