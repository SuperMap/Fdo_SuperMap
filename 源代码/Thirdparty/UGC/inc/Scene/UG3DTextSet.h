/* 
	\file UG3DTextSet.h
	\brief 文件内容的简要描述。
	\author 文件作者
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>更新说明：。</b>
	<em>1、第一条说明。</em>
	<em>2、第二条说明。</em>
*/

// UG3DTextSet.h: interface for the UG3DTextSet class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UG3DTEXTSET_H__9C1775CA_8173_4FAD_AD3D_3AA21BA86C38__INCLUDED_)
#define AFX_UG3DTEXTSET_H__9C1775CA_8173_4FAD_AD3D_3AA21BA86C38__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Scene/UGPrerequisites.h"
#include "Scene/UGRenderObject.h"
#include "Scene/UGColorValue.h"
#include "Scene/UG3DText.h"
#include "Base/UGThread.h"
#include "Engine/UGDataset.h"

namespace UGC
{
//! \brief 类的简要说明。
//! \remarks 备注信息。
class SCENE_API UG3DTextSet:public UGRenderObject
{
public:
	//! \brief 构造函数
	UG3DTextSet();
	//! \brief 析构函数
	virtual ~UG3DTextSet();
	//! \brief
	virtual void Release();
	//! \brief
	virtual void Initialize();
	//! \brief
	virtual void Update();
	//! \brief
	virtual void Render();	
	//! \brief
	void RemoveAllText();
	//! \brief 设置文字颜色
	void SetTextColor(const UGColorValue& textColor);
private:
	//! \brief 文字颜色
	UGColorValue m_TextColor;
	//! \brief
	UGList<UG3DText*>m_listText;

};
}
#endif // !defined(AFX_UG3DTEXTSET_H__9C1775CA_8173_4FAD_AD3D_3AA21BA86C38__INCLUDED_)
