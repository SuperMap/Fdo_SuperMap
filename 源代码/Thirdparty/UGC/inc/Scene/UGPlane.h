// UGPlane.h: interface for the UGPlane class.
//
//////////////////////////////////////////////////////////////////////
/* 
	\file UGPlane.h
	\brief UGC三维平面类头文件。
	\author 马柳青
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>更新说明：。</b>
	<em>1、第一条说明。</em>
	<em>2、第二条说明。</em>
*/

#if !defined(AFX_UGPLANE_H__FB442292_3E4D_49F8_A98D_245EE80AE3B2__INCLUDED_)
#define AFX_UGPLANE_H__FB442292_3E4D_49F8_A98D_245EE80AE3B2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Scene/UGPrerequisites.h"
#include "Scene/UGVector3R.h"

namespace UGC 
{
//! \brief 三维平面类，在视景体中使用。
//! \remarks 
	
class SCENE_API UGPlane  
{
public:
	UGPlane();
	UGPlane(const UGVector3R& vec,UGReal fDistance);
	virtual ~UGPlane();
	void Normalize();

	//! \brief 获取指定的点到该平面的距离值。
	//! \param vPoint 指定的三维空间中的点位置[in]。
	//! \return 返回计算出来的距离。
	UGReal GetDistance(const UGVector3R& vPoint)const;

	//! \brief 成员的简要说明。
	//! \remarks 备注信息。
	UGVector3R m_vNormal;
	UGReal m_fDistance;
};
}
#endif // !defined(AFX_UGPLANE_H__FB442292_3E4D_49F8_A98D_245EE80AE3B2__INCLUDED_)
