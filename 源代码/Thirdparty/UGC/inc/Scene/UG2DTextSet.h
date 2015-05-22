/* 
	\file UG2DTextSet.h
	\brief 文件内容的简要描述。
	\author 文件作者
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>更新说明：。</b>
	<em>1、第一条说明。</em>
	<em>2、第二条说明。</em>
*/

// UG2DTextSet.h: interface for the UG2DTextSet class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UG2DTEXTSET_H__8A9D5ED9_C8AD_42BA_8CE9_76BAE9AA249E__INCLUDED_)
#define AFX_UG2DTEXTSET_H__8A9D5ED9_C8AD_42BA_8CE9_76BAE9AA249E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Scene/UGRenderable.h"
#include "Base/UGThread.h"
#include "Scene/UGColorValue.h"
#include "Base/UGString.h"
#include "Engine/UGDataset.h"
#include "Base/ugdefs.h"
#include "Scene/UG2DText.h"
#include "Base/UGTextStyle.h"
#include "Scene/UGQuadDataset.h"

namespace UGC
{
class UGGeoText;
//! \brief 类的简要说明。
//! \remarks 备注信息。
class SCENE_API UG2DTextSet:public UGQuadDataset  
{
public:
	//! \brief
	UG2DTextSet();
	//! \brief
	virtual ~UG2DTextSet();
	//! \brief
	virtual void Release();
	//! \brief
	virtual void Initialize();
	//! \brief
	virtual void Update();
	//! \brief
	virtual void Render();	
	//! \brief
	void SetTextStyle(const UGTextStyle& textStyle);
	//! \brief
	UGTextStyle& GetTextStyle();
	//! \brief
	void AddText(UG2DText* pText);
	//! \brief
	void AddDataFromDataset(const UGVectorDatasetAtr& DatasetAtr);

	UG2DText *Get2DText();
	
private:
	//! \brief
	UGString GetText(UGGeoText* pGeoText);
	//! \brief
	void AddDatasetTexts(const UGVectorDatasetAtr& DatasetAtr);
	
private:
	//! \brief
	UGList<UG2DText*>m_listText;
	//! \brief
	UGTextStyle m_TextStyle;
};
}
#endif // !defined(AFX_UG2DTEXTSET_H__8A9D5ED9_C8AD_42BA_8CE9_76BAE9AA249E__INCLUDED_)
