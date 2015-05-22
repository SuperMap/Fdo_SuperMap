/* 
	\file UGRenderableObject.h
	\brief 可渲染对象类文件
	\author malq
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>更新说明：。</b>
	<em>1、第一条说明。</em>
	<em>2、第二条说明。</em>
*/
#if !defined(AFX_UGRENDERABLEOBJECT_H__E2A8E83B_C9F8_49CF_8B50_D278E9755CAD__INCLUDED_)
#define AFX_UGRENDERABLEOBJECT_H__E2A8E83B_C9F8_49CF_8B50_D278E9755CAD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Scene/UGPrerequisites.h"
#include "Scene/UGRenderable.h"
#include "Scene/UGRenderOperation.h"
#include "Scene/UGVector3R.h"
#include "Scene/UGMatrix4d.h"
#include "Scene/UGBoundingBox.h"
#include "Scene/UGCameraBase.h"
#include "Scene/UGColorValue.h"


namespace UGC 
{

//! \brief 可渲染对象类
//! \remarks 备注信息
class SCENE_API UGRenderableObject
{
public:
	//! \brief 构造函数
	UGRenderableObject();
	//! \brief 构造函数
	UGRenderableObject(const UGString& strName);
	//! \brief 析构函数
	virtual ~UGRenderableObject();
	//! \brief 设置可渲染对象的名称标志
	void SetName(const UGString& strName);
	//! \brief 获得可渲染对象的名称标志
	UGString GetName();
	//! \brief 设置可渲染对象是否可见
	void SetHide(UGbool bHide);
	//! \brief 判断可渲染对象是否可见
	UGbool IsHide();
	//UGbool IsVisible();
	//! \brief 设置可渲染对象的透明度
	void SetOpacity(UGfloat dOpacity);
	//! \brief 获得可渲染对象的透明度
	UGfloat GetOpacity();
	//! \brief 判断可渲染对象是否初始化
	UGbool  IsInitialized();
	//! \brief 
	virtual void Release() = 0;
	//! \brief 设置可渲染对象的空间位置
	void SetPosition(const UGVector3R& vecPos);
	//! \brief 得到可渲染对象的空间位置
	UGVector3R GetPosition();
	//! \brief 绕自身X,Y,Z轴旋转一个角度，以度为单位,注意不是绕世界坐标系
	void RotateX(UGReal dAngle);
	//! \brief 绕自身X,Y,Z轴旋转一个角度，以度为单位,注意不是绕世界坐标系
	void RotateY(UGReal dAngle);
	//! \brief 绕自身X,Y,Z轴旋转一个角度，以度为单位,注意不是绕世界坐标系
	void RotateZ(UGReal dAngle);
	//! \brief 单位化旋转矩阵
	void IdentityRotateMatrix();
	//! \brief 设置三个角的地旋转，传入的参数以角度为单位
	void SetRotate(const UGVector3R& vecRot);
	//! \brief 获得三个角的的旋转，传入的参数以角度为单位
	UGVector3R GetRotate();
	//! \brief 设置对象的可见距离
	void SetVisibleDist(UGdouble dDist);
	//! \brief 获得对象的可见距离
	UGdouble GetVisibleDist();
	//! \brief 设置可渲染对象的向量模式
	virtual void SetNormalMode(UGint normalMode);
	//! \brief 得到可渲染对象的向量模式
	UGint GetNormalMode();
	//! \brief 设置可渲染对象的正面方向
	virtual void SetFrontFace(UGint enFrontFace);
	//! \brief 得到可渲染对象的正面方向
	UGint GetFrontFace();
	//! \brief 设置可渲染对象的缩放比例
	void SetScale(UGfloat fScale);
	//! \brief 设置可渲染对象的缩放比例
	void SetScale(UGfloat fScaleX,UGfloat fScaleY,UGfloat fScaleZ);
	//! \brief 得到可渲染对象的缩放比例
	UGVector3R GetScale();
	//! \brief 得到可渲染对象的包围盒
	UGBoundingBox GetBoundingBox();
	//! \brief 设置可渲染对象的当前相机
	virtual void NotifyActiveCamera(UGCameraBase* pActiveCamera);
	//! \brief malq-2007-11-30
	UGCameraBase*  GetActiveCamera();

	//! \brief 判断渲染对象是不是在视景体内 
	UGbool IsVisible();



//	// copy ogre function to our system
//	virtual UGMaterial* GetMaterial(void) const {return NULL;};
//	virtual void GetRenderOperation(UGRenderOperation& op) {};
//	virtual void GetWorldTransforms(UGMatrix4d* xform) const {};	
//	virtual UGQuaternion4d& GetWorldOrientation(void) const {return  UGQuaternion4d(1,0,0,45*DTOR);};
//	virtual UGVector3R& GetWorldPosition(void) const {return UGVector3R(0,0,0);};
//	virtual UGReal GetSquaredViewDepth(const UGCameraBase* cam) const {return 0;};
//	virtual UGLightList& GetLights(void) const {UGLightList lst; return lst;}


protected:
	//! \brief 相机成员
	UGCameraBase* m_pActiveCamera;
	//! \brief 渲染成员
	UGRenderOperation m_RenderOperation;
	//! \brief 判断可见性成员
	UGbool m_bHide;
	//! \brief 名称标志成员
	UGString m_strName;
	//! \brief 透明度成员
	UGfloat  m_dOpacity;
	//! \brief 初始化标志成员
	UGbool m_bInitialized;
	//! \brief 位置成员
	UGVector3R m_vecPosition;
	//! \brief 旋转角度成员
	UGVector3R m_vecRotate;
	//! \brief 旋转举阵成员
	UGMatrix4d m_matRotate;
	//! \brief 缩放比例成员
	UGVector3R m_vecScale;
	//! \brief 向量模式成员
	UGint m_nNormalMode;
	//! \brief 面的正面方向成员
	UGint m_nFrontFace;
	//! \brief 可见距离成员
	UGdouble  m_dVisibleDist;
	//! \brief 包围盒成员
	UGBoundingBox m_BoundingBox;

	//! \brief 颜色成员
	UGColorValue m_DiffuseColor;
	//! \brief 点的大小或者线的粗细
	UGfloat m_fSize;

};

}
#endif // !defined(AFX_UGRENDERABLEOBJECT_H__E2A8E83B_C9F8_49CF_8B50_D278E9755CAD__INCLUDED_)
