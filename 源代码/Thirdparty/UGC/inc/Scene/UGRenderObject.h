/* 
	\file UGRenderObject.h
	\brief 可渲染对象的抽象类文件
	\author malq
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>更新说明：。</b>
	<em>1、第一条说明。</em>
	<em>2、第二条说明。</em>
*/

#if !defined(AFX_UGRENDEROBJECT_H__618529B0_589C_4A7C_BFEF_C57EF5C363A8__INCLUDED_)
#define AFX_UGRENDEROBJECT_H__618529B0_589C_4A7C_BFEF_C57EF5C363A8__INCLUDED_


#include "Scene/UGPrerequisites.h"
#include "Scene/UGRenderOperation.h"
#include "Scene/UGVector3R.h"
#include "Scene/UGMatrix4d.h"
#include "Scene/UGBoundingBox.h"
#include "Scene/UGColorValue.h"
#include "Scene/UGLight.h"
#include "Scene/UGQuaternion4d.h"

namespace UGC 
{

//! \brief 可渲染对象的抽象类
//! \remarks 封装了可渲染对象的公共接口
class SCENE_API UGRenderObject  
{

public:
	//! \brief 构造函数
	UGRenderObject();
	//! \brief 析构函数
	virtual ~UGRenderObject();

public:
	
	
	//! \brief 构造函数
	UGRenderObject(const UGString& strName);
	//! \brief 设置可渲染对象的名称标志
	// 名称只有UGMovableObject才拥有该属性
	// 这里参考OGRE设置方法去除Renderable中Name属性
	void SetName(const UGString& strName);
	//! \brief 获得可渲染对象的名称标志
	UGString GetName();
	//! \brief 设置可渲染对象是否可见
	void EnableShow(UGbool bShow);
	//! \brief 判断可渲染对象是否可见
	UGbool IsVisible();
	//! \brief 设置可渲染对象的透明度
	void SetOpacity(UGfloat dOpacity);
	//! \brief 获得可渲染对象的透明度
	UGfloat GetOpacity();
	//! \brief 判断可渲染对象是否初始化
	UGbool  IsInitialized();
	
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
	//! \brief 设置可渲染对象的颜色
	void SetColor(const UGColorValue& color);	
	//! \brief 得到可渲染对象的包围盒
	UGBoundingBox& GetBoundingBox();
	void SetBoundingBox(const UGBoundingBox& boundingBox);
	//! \brief 设置可渲染对象的当前相机	
// 	UGCameraBase*  GetActiveCamera();

	virtual void Release();
	//! \brief 渲染对象的初始化接口
	virtual void Initialize();
	//! \brief 渲染对象的更新接口
	virtual void Update();
	//! \brief 渲染对象的渲染接口
	virtual void Render();

	UGMatrix4d& GetRotateMatrix();
	virtual void NotifyActiveCamera(UGCameraBase* pActiveCamera);
	
	// copy ogre functions to our system
	virtual UGMaterial* GetMaterial(void) const;
	virtual UGRenderOperation *GetRenderOperation();
	virtual void GetWorldTransforms(UGMatrix4d* xform) const;	
	virtual UGQuaternion4d GetWorldOrientation(void) const;
	virtual UGVector3R GetWorldPosition(void) const;
	virtual UGReal GetSquaredViewDepth(const UGCameraBase* cam) const;
	virtual UGLightList GetLights(void) const;

	virtual UGushort GetNumWorldTransforms(void) const { return 1; }
	virtual UGbool UseIdentityProjection(void) const { return false; }
	virtual UGbool UseIdentityView(void) const { return false; }
	virtual UGbool GetNormaliseNormals(void) const { return false; }
	virtual void SetPolygonModeOverrideable(UGbool override);
	virtual UGbool GetPolygonModeOverrideable(void) const;

	virtual UGMatrix4d GetModelViewMatrix() {return UGMatrix4d::IDENTITY;}
	virtual UGbool InterSectWithRadial(const UGVector3R& nearPos, const UGVector3R& farPos){return false;}
	virtual void SetPickStatus(UGbool status);
	virtual UGbool GetPickStatus();

protected:
	
	UGbool m_bPolygonModeOverrideable;
	//! \brief 相机成员
	UGCameraBase* m_pActiveCamera;
	//! \brief 渲染成员
	UGRenderOperation m_RenderOperation;
	//! \brief 判断可见性成员
	UGbool m_bVisible;

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
	//! \brief malq-2007-11-19 点的大小或者线的粗细
	UGfloat m_fSize;

	// 设置是否选中,true选中，false不选中
	UGbool m_bPicked;
};

}
#endif // !defined(AFX_UGRENDEROBJECT_H__618529B0_589C_4A7C_BFEF_C57EF5C363A8__INCLUDED_)
