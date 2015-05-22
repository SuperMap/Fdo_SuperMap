/* 
	\file UG3DText.h
	\brief 文件内容的简要描述。
	\author 文件作者
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>更新说明：。</b>
	<em>1、第一条说明。</em>
	<em>2、第二条说明。</em>
*/

// UG3DText.h: interface for the UG3DText class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGTEXT_H__8284F63B_BBB9_46D8_BE44_44190C2E8662__INCLUDED_)
#define AFX_UGTEXT_H__8284F63B_BBB9_46D8_BE44_44190C2E8662__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Scene/UGPrerequisites.h"
#include "Scene/UGRenderable.h"
#include "Scene/UGColorValue.h"

namespace UGC
{

	//! \brief
	typedef enum Text3DType
	{
		TEXT_2D,
		TEXT_3D
	};
	//! \brief 类的简要说明。
	//! \remarks 备注信息。
	class SCENE_API UG3DText: public UGRenderable, public UGMovableObject 
	{
		public:
			//! \brief 构造函数
			UG3DText();
			//! \brief 析构函数
			virtual ~UG3DText();

			//! \brief 两种是不同的效果,这个有外框 
			//void SetFont(HFONT hFont);
			//! \brief
			void Initialize();
			//! \brief
			void Update();
			//! \brief
			void Render();
			//! \brief
			void Release();
			//! \brief
			void SetText(const UGString&  strText);
		public:
			//! \brief 边框颜色
			UGColorValue m_OutlineColor;
			//! \brief 文字颜色
			UGColorValue m_TextColor;  
			
		//	HFONT    m_hFont; //字体
			//! \brief 文本内
			UGString m_strText;

			//! \brief
			Text3DType m_Text3DType;
			//! \brief
			UGint* m_pCharList;		

	};

}

#endif // !defined(AFX_UGTEXT_H__8284F63B_BBB9_46D8_BE44_44190C2E8662__INCLUDED_)
