/* 
	\file UG2DText.h
	\brief 文件内容的简要描述。
	\author 文件作者
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>更新说明：。</b>
	<em>1、第一条说明。</em>
	<em>2、第二条说明。</em>
*/


// UG2DText.h: interface for the UG2DText class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UG2DTEXT_H__80FFDD9F_A58F_4FE5_9453_AE3832C81569__INCLUDED_)
#define AFX_UG2DTEXT_H__80FFDD9F_A58F_4FE5_9453_AE3832C81569__INCLUDED_

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
class SCENE_API UG2DText : public UGRenderObject
{
public:
	//! \brief 
	UG2DText();
	//! \brief 
	UG2DText(const UGString& strText,const UGVector3R& vecPos);	
    //! \brief 
	virtual ~UG2DText();
	//! \brief 
	void SetText(const UGString&  strText);
	//! \brief 注意这里传的是空间坐标，而非经纬度坐标，所以经纬度坐标必须先在外面转化
	void SetTextPos(UGReal x,UGReal y,UGReal z);
	//! \brief 
	void SetTextPos(const UGVector3R& vecPos);
	//! \brief
	UGVector3R GetTextPos();
	//! \brief
	void Render();
	//! \brief
	UGString GetText();
private:
	//! \brief 文本内
	UGString m_strText;
	//! \brief 这个是三维空间坐标而非经纬度坐标
	UGVector3R m_vecPos;
};
}

#endif // !defined(AFX_UG2DTEXT_H__80FFDD9F_A58F_4FE5_9453_AE3832C81569__INCLUDED_)
