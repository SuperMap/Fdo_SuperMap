/* 
	\file UG3DStyle.h
	\brief 文件内容的简要描述。
	\author 文件作者
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>更新说明：。</b>
	<em>1、第一条说明。</em>
	<em>2、第二条说明。</em>
*/

// UG3DStyle.h: interface for the UG3DStyle class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UG3DSTYLE_H__726C9B52_917E_4FA3_8C40_E9CBE4AE5DA3__INCLUDED_)
#define AFX_UG3DSTYLE_H__726C9B52_917E_4FA3_8C40_E9CBE4AE5DA3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Scene/UGPrerequisites.h"
#include "Scene/UGColorValue.h"
namespace UGC
{
//! \brief
enum UG3DPointType
{
	PT_SIMPLE,
	PT_ICON,
	PT_ENTITY
};
//! \brief 类的简要说明。
//! \remarks 备注信息。
class SCENE_API UG3DPointStyle  
{
public:
	//! \brief 构造函数
	UG3DPointStyle();
	//! \brief 析构函数
	virtual ~UG3DPointStyle();
	//! \brief 得到点对象的颜色
	UGColorValue GetPointColor();
	//! \brief 得到点对象的大小
	UGReal      GetPointSize();
	//! \brief 得到点对象的类型
	UG3DPointType	GetPointType();
	//! \brief 得到图标点所使用的图标的路径
	UGString    GetPointIconPath();
	//! \brief 得到模型点所使用的模型的路径
	UGString    GetPointModelPath();
	//! \brief 
	UGbool		IsPointSmooth();
	//! \brief
	UGbool 		IsPointSizeAutoChanged();
	//! \brief
	UGReal*		GetPointQuadratic();
	//! \brief 风格是否发生了改变，这个用于控制图标模型等的更新
	UGbool		IsIconChanged();
	//! \brief
	UGbool		IsModelChanged();
	
	//! \brief 设置点对象的类型
	void		SetPointType(UG3DPointType enPointType);
	//! \brief 设置图标点所使用的图标的路径
	void		SetPointIconPath(const UGString& strIconPath);
	//! \brief 设置模型点所使用的模型的路径
	void		SetPointModelPath(const UGString& strModelPath);
	//! \brief 设置点对象的颜色
	void		SetPointColor(const UGColorValue& color);
	//! \brief 设置点对象的大小
	void		SetPointSize(UGReal fSize);
	//! \brief 设置点的大小随距离改变的参数因子，对图表点有效
	void		SetQuadratic(UGReal a,UGReal b,UGReal c);
	//! \brief 设置
	void		SetPointSmooth(UGbool bSmooth);
	//! \brief 
	void		SetPointSizeAutoChanged(UGbool bChanged);
	//! \brief 
	void		SetIconChanged(UGbool bChanged);
	//! \brief
	void		SetModelChanged(UGbool bChanged);


private:
	//! \brief 图标点所使用的图标
	UGString m_strPointIcon;
	//! \brief 模型点所使用的模型
	UGString m_strPointModel;
	//! \brief 点的颜色
	UGColorValue m_PointColor;
	//! \brief 点的大小
	UGReal       m_fPointSize;
	//! \brief 点的类型 
	UG3DPointType m_enPointType;
	//! \brief 点的大小是否随距离而改变，对图标点有效
	UGbool m_bSizeChanged;
	//! \brief 点的大小随距离改变的参数因子，对图标点有效
	UGReal  m_Quadratic[3];
	//! \brief 点是圆形点还是方型点，对普通点有效，为TRUE表示圆形点
	UGbool m_bSmooth;
	//! \brief
	UGbool m_bIconChanged;
	//! \brief 
	UGbool m_bModelChanged;
};
//! \brief 类的简要说明。
//! \remarks 备注信息。
class SCENE_API UG3DLineStyle  
{
public:
	//! \brief 构造函数
	UG3DLineStyle();
	//! \brief 析构函数
	virtual ~UG3DLineStyle();
	//! \brief 得到线对象的颜色
	UGColorValue GetLineColor();
	//! \brief 得到线对象的宽度
	UGReal		 GetLineWidth();
	//! \brief 设置线对象的颜色
	void		 SetLineColor(UGColorValue color);
	//! \brief 设置线对象的宽度
	void		 SetLineWidth(UGReal fWidth);
private:
	//! \brief 线对象的颜色值
	UGColorValue m_LineColor;
	//! \brief 线对象的宽度值
	UGReal	     m_fLineWidth;
};

}

#endif // !defined(AFX_UG3DSTYLE_H__726C9B52_917E_4FA3_8C40_E9CBE4AE5DA3__INCLUDED_)
