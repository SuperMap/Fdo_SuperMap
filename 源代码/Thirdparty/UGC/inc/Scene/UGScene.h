/* 
	\file UGScene.h
	\brief 文件内容的简要描述。
	\author malq
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>更新说明：。</b>
	<em>1、第一条说明。</em>
	<em>2、第二条说明。</em>
*/
#if !defined(AFX_UGSCENE_H__0863518E_8AEE_4702_8105_7D7A51E4C276__INCLUDED_)
#define AFX_UGSCENE_H__0863518E_8AEE_4702_8105_7D7A51E4C276__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Scene/UGPrerequisites.h"
#include "Scene/UGSceneSetting.h"
#include "Scene/UGVectorDatasetAtr.h"
#include "Scene/UGRenderable.h"
#include "Scene/UGRenderSys.h"
#include "Base/UGThread.h"
#include "Scene/UG3DLayers.h"
#include "Scene/UGRenderObjectList.h"


namespace UGC 
{
//! \brief MeasureDistanceFunc 事件回调函数
extern "C" typedef UGdouble (*MeasureDistanceFunc)(const UGPoint2D &pntFrom,const UGPoint2D& pntTo,UGdouble dRadius);

//! \brief 场景类
//! \remarks 备注信息。
class SCENE_API UGScene
{
public:
	UGScene();
	//! \brief 构造函数
	UGScene(const UGString& name);
	//! \brief 析构函数
	virtual ~UGScene();
	//! \brief 初始化
	//void Initialize();
	//! \brief 更新函数
	void UpdateData();
	//! \brief 渲染函数
	//void Render();
	//! \brief 渲染场景
	void RenderScene(UGViewport *pVP, UGbool bIncludeOverlays);
	//! \brief 设置视口
	virtual void SetViewport(UGViewport *vp);
	//! \brief 释放场景
	void Release();
	//! \brief 设置某个可渲染对象是否可见
	void SetLayerHide(UGString strName, UGbool bShow);
	//! \brief 得到某个可渲染对象是否可
	UGbool IsLayerHide(UGString strName);
	//! \brief 得到地形获取器
	UGTerrainAccessor* GetTerrainAccessor();
	//! \brief 设置地形获取器
	void SetTerrainAccessor(UGTerrainAccessor* pTerrainAccessor);
	//! \brief 等待渲染
	static void  WaitForRender(UGulong& dBeiginClock);
	//! \brief 设置光源位置
	void SetLightPos(UGReal dLon,UGReal dLat,UGReal dHeight,UGbool bMoveLight);
	//! \brief 释放所有相机
	void DestroyAllCameras();
	//! \brief 创建一个相机
	UGMomentumCamera *CreateCamera(const UGString& Name);
	//! \brief 得到一个相机
	UGMomentumCamera *GetCamera(const UGString& name);
	//! \brief 设置使用的渲染引擎
	void SetDestRenderSys(UGRenderSys *pRenderSys);
	//! \brief 得到使用的渲染引擎
	UGRenderSys* GetDestRenderSys();
	//! \brief 设置当前的相机
	virtual void NotifyActiveCamera(UGCameraBase* pActiveCamera);
	//! \brief 向Scene中添加数据集
	void AddDataset(const UGVectorDatasetAtr& DatasetAtr);
	//! \brief 得到场景中的某个数据集
	UGbool GetDataset(const UGString& strName,UGVectorDatasetAtr& atr);
	//! \brief 移除场景中的某个数据集
	void RemoveDataset(const UGString& strName);
	UGRenderObject *AddDataset(const UGString& strSgdFile);

public:
	//! \brief 场景属性参数
	static UGSceneSetting ms_SceneSetting;
	//! \brief 渲染标志参数
	static UGbool       ms_bRendering;
	//! \brief 休眠标志
	static UGdouble     ms_dSleepTime;
	//! \brief 允许渲染标志
	static UGbool ms_bSceneRenderAllow;
	//! \brief 允许更新标志
	static UGbool ms_bSceneUpdateAllow;
	//! \brief 判断是否需要绘制
	static UGbool ms_bNeedRefresh;

protected:
	//! \brief 场景中所有可渲染对象列表
//	UGRenderableObjectList m_RootList;
	//! \brief
	UGlong m_nLastElevationUpdate;
	//! \brief
	UGRenderSys *m_pDestRenderSystem;
	//! \brief 相机列表
	typedef UGDict<UGString, UGMomentumCamera *> UGCameraBaseMap;
	//! \brief
	UGCameraBaseMap m_CameraBaseMap;

	// 用来判断是不是改变了，如果这些没有改变就不用重画场景了了
	UGMatrix4d m_OldProjectionMatrix; 
	UGMatrix4d m_OldViewMatrix;
	UGMatrix4d m_OldWorldMatrix;

	// 控制线程切换,控制显示函数
	// 这里使用用临界区来实现进程同步
	UGMutex m_Mutex;

// 后面参考OGRE添加属性和方法
protected:
	UGString m_strName;
	UGColorValue m_AmbientLight;
	typedef UGDict<UGString, UGSceneNode*> SceneNodeList;
	SceneNodeList m_SceneNodes;
	UGMomentumCamera* m_CameraInProgress;
	UGViewport* m_CurrentViewport;

	UGSceneNode* m_pSceneRoot;
	UGSceneNode* m_pLayerRootNode;

	UGRenderObjectList m_RenderObjectList;
	UGRenderObjectList m_RenderObjectListPlane;
	UGRenderObject* m_pSelectedRenderObject;


	typedef UGList<UGSceneNode*> AutoTrackingSceneNodes;
    AutoTrackingSceneNodes m_AutoTrackingSceneNodes;

	// Fog
    FogMode m_FogMode;
    UGColorValue m_FogColour;
    UGReal m_FogStart;
    UGReal m_FogEnd;
    UGReal m_FogDensity;
	
	
	typedef UGDict<UGString, UGMovableObject*> MovableObjectMap;
	typedef UGDict<UGString, MovableObjectMap*> MovableObjectCollectionMap;
	MovableObjectCollectionMap m_MovableObjectCollectionMap;

	UGbool m_bDisplayNodes;
	UGbool m_bFindVisibleObjects;



protected:
	// 实现体不能放到cpp文件中
	// 放在cpp中编译不过去怀疑MovableObjectMap自定义类型问题
	// 解决方法：咨询马师兄MovableObjectMap前要加类作用符
	// UGScene::MovableObjectMap就能编译通过
	MovableObjectMap* GetMovableObjectMap(UGString typeName);


public:
	enum PrefabType 
	{
            PT_PLANE
    };
public:
	virtual UGbool HasCamera(const UGString& name) const;
	virtual void DestroyCamera(UGMomentumCamera* cam);
	virtual void DestroyCamera(const UGString& name);
	virtual UGLight* CreateLight(const UGString& name);
	virtual UGLight* GetLight(const UGString& name);
	virtual UGbool HasLight(const UGString& name) const;
	virtual void DestroyLight(const UGString& name);
	virtual void DestroyLight(UGLight* light);
	virtual void DestroyAllLights(void);
	virtual void PopulateLightList(const UGVector3R& position, UGReal radius, UGLightList& destList);
	virtual UGSceneNode* CreateSceneNode(void);
	virtual UGSceneNode* CreateSceneNode(const UGString& name);
	virtual void DestroySceneNode(const UGString& name);
	virtual UGSceneNode* GetRootSceneNode(void) const;
	virtual UGSceneNode* GetSceneNode(const UGString& name) const;
	virtual UGbool HasSceneNode(const UGString& name) const;
	virtual UGEntity*    CreateEntity(UGString entityName, UGString meshName);
	virtual UGEntity* CreateEntity(const UGString& entityName, PrefabType ptype);
	virtual UGEntity* GetEntity(const UGString& name);
	virtual UGbool HasEntity(const UGString& name) const;
	virtual void DestroyEntity(UGEntity* ent);
	virtual void DestroyEntity(const UGString& name);
	virtual void DestroyAllEntities(void);
	void SetAmbientLight(const UGColorValue& colour);
	UGColorValue GetAmbientLight(void) const;
	void SetFog(FogMode mode = FOG_NONE, const UGColorValue& colour = UGColorValue::White,
            UGReal expDensity = 0.001, UGReal linearStart = 0.0, UGReal linearEnd = 1.0);
	virtual FogMode GetFogMode(void) const;
	virtual const UGColorValue& GetFogColour(void) const;
	virtual UGReal GetFogStart(void) const;
	virtual UGReal GetFogEnd(void) const;
	virtual UGReal GetFogDensity(void) const;
	virtual void SetDisplaySceneNodes(UGbool display);
	virtual UGMovableObject* CreateMovableObject(UGString name, UGString typeName, 
												 NameValuePairList* params = 0);
	virtual void DestroyMovableObject(const UGString& name, const UGString& typeName);
	virtual void DestroyMovableObject(UGMovableObject* m);
	virtual void DestroyAllMovableObjectsByType(const UGString& typeName);
	virtual void DestroyAllMovableObjects(void);
	virtual UGMovableObject* GetMovableObject(const UGString& name, const UGString& typeName);
	virtual UGbool HasMovableObject(const UGString& name, const UGString& typeName) const;
	virtual void InjectMovableObject(UGMovableObject* m);
	virtual void ExtractMovableObject(const UGString& name, const UGString& typeName);
	virtual void ExtractMovableObject(UGMovableObject* m);
	virtual void ExtractAllMovableObjectsByType(const UGString& typeName);
	
	//! \brief 选中模型
	UGRenderObject* PickModelObjects(const UGint pointx, const UGint pointy, UGbool bPick = true);
	UGRenderObject* PickVectorObjects(const UGint pointx, const UGint pointy, UGbool bPick = true);
	virtual void AddSceneNode(UGSceneNode* node);

	UGRenderObjectList& GetRenderObjectList();
	UGRenderObjectList& GetRenderObjectListPlane();
	UGRenderObject *GetSelectedRenderObject();
	void SetSelectedRenderObjectNULL();


public:
	// 设置回调函数
	void SetMeasureDistanceFunc(MeasureDistanceFunc pFunc);
	
	// 执行回调函数
	UGdouble RunMeasureDistanceFunc(UGPoint2D pntFrom,UGPoint2D pntTo,UGdouble dRadius = 6378137);
protected:
	MeasureDistanceFunc m_pFunc;


public:
	const UGString& GetName(void) const { return m_strName; }
	virtual UGbool GetDisplaySceneNodes(void) const {return m_bDisplayNodes;}
	virtual void SetFindVisibleObjects(UGbool find) { m_bFindVisibleObjects = find; }
	virtual UGbool GetFindVisibleObjects(void) { return m_bFindVisibleObjects; }
	UGViewport* GetCurrentViewport(void) { return m_CurrentViewport; }	

};

}
#endif // !defined(AFX_UGSCENE_H__0863518E_8AEE_4702_8105_7D7A51E4C276__INCLUDED_)
