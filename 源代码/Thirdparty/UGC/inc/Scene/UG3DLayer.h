// UG3DLayer.h: interface for the UG3DLayer class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UG3DLAYER_H__3C5AC4F4_3504_4A63_A2AE_435C6A09ED57__INCLUDED_)
#define AFX_UG3DLAYER_H__3C5AC4F4_3504_4A63_A2AE_435C6A09ED57__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include"Scene/UGPrerequisites.h"
#include"Scene/UGSceneNode.h"
namespace UGC
{

class SCENE_API UG3DLayer:public UGSceneNode 
{
public:
	UG3DLayer(UGScene* creator);
	UG3DLayer(UGScene* creator, const UGString& name);
	virtual ~UG3DLayer();
};
}


#endif // !defined(AFX_UG3DLAYER_H__3C5AC4F4_3504_4A63_A2AE_435C6A09ED57__INCLUDED_)
