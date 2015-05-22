/* 
	\file UG3DLine.h
	\brief 文件内容的简要描述。
	\author 文件作者
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>更新说明：。</b>
	<em>1、第一条说明。</em>
	<em>2、第二条说明。</em>
*/

// UG3DLine.h: interface for the UG3DLine class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UG3DLINE_H__C0BC817F_7532_486E_94B7_4A6B91963C78__INCLUDED_)
#define AFX_UG3DLINE_H__C0BC817F_7532_486E_94B7_4A6B91963C78__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Scene/UGPrerequisites.h"
#include "Scene/UGRenderObject.h"
#include "Scene/UGColorValue.h"

namespace UGC
{
//! \brief 类的简要说明。
//! \remarks 备注信息。
class SCENE_API UG3DLine: public UGRenderObject
{
public:
	//! \brief 构造函数
	UG3DLine();
	//! \brief 析构函数
	virtual ~UG3DLine();
	//! \brief 初始化
	void Initialize();
	//! \brief 更新
	void Update();
	//! \brief
	void Render();
	//! \brief 释放
	void Release();
	//! \brief 注意该函数传入的是空间坐标，而不是经纬度坐标或投影坐标
	void CreateLine(UGVector3R* pPoints,UGint* pPolyCount,UGint nSubCount);
	//! \brief 注意该函数传入的是空间坐标，而不是经纬度坐标或投影坐标 
	void CreateLine(UGVector3R* pVectors,UGint nNumPoints);
	//! \brief
	void SetLineStyle(UG3DLineStyle* m_pLineStyle);
	//! \brief
	UG3DLineStyle* GetLineStyle();

	virtual UGbool InterSectWithRadial(const UGVector3R& nearPos, const UGVector3R& farPos);
	UGbool InsectLineWithRadial(UGVector3R lineStart, UGVector3R lineEnd, const UGVector3R& nearPos, const UGVector3R& farPos);
	virtual void SetPickStatus(UGbool status);

	//张艳良－为了组件接口临时加的，6.0改掉
	UG3DLine *GetSubLine();
private:
	//! \brief
	UGList<UG3DLine*>m_SubList;
	//! \brief 注意这个风格指针是外面传入的，UG3DLine不负责释放
	UG3DLineStyle* m_pLineStyle;


	UGVector3R tmpLineStart;
	UGVector3R tmpLineEnd;
	UGVector3R tmpLineIntersectPoint;

 
};
}
#endif // !defined(AFX_UG3DLINE_H__C0BC817F_7532_486E_94B7_4A6B91963C78__INCLUDED_)
