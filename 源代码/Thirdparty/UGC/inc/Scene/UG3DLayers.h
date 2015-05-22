// UG3DLayers.h: interface for the UG3DLayers class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UG3DLAYERS_H__86588036_022C_4645_8565_81526067529E__INCLUDED_)
#define AFX_UG3DLAYERS_H__86588036_022C_4645_8565_81526067529E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include"Scene/UGPrerequisites.h"
#include"Scene/UGSceneNode.h"
#include"Scene/UGQuadGridSet.h"
namespace UGC
{

class SCENE_API UG3DLayers:public UGSceneNode  
{
public:
	UG3DLayers(UGScene* creator);
	UG3DLayers(UGScene* creator, const UGString& name);
	virtual ~UG3DLayers();
	virtual void Release();
public:
	// 矢量四叉树，用来管理所有分块的矢量文件
	UGQuadGridSet m_QuadGridSet;
};
}

#endif // !defined(AFX_UG3DLAYERS_H__86588036_022C_4645_8565_81526067529E__INCLUDED_)
