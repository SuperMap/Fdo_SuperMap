/* 
	\file UGRenderableObjectList.h
	\brief 可渲染对象列表类文件
	\author malq
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>更新说明：。</b>
	<em>1、第一条说明。</em>
	<em>2、第二条说明。</em>
*/

#if !defined(AFX_UGRENDERABLEOBJECTLIST_H__260EEE73_E53A_4651_9778_2B09D6187D01__INCLUDED_)
#define AFX_UGRENDERABLEOBJECTLIST_H__260EEE73_E53A_4651_9778_2B09D6187D01__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Scene/UGPrerequisites.h"
#include "Base/UGThread.h"
#include "Scene/UGRenderable.h"

namespace UGC 
{

//! \brief 可渲染对象列表管理数组类，具有同步处理能力
//! \remarks 备注信息。
class SCENE_API  SyncRenderObjectArray
{
public:
	//! \brief 构造函数
	SyncRenderObjectArray(){};
	//! \brief 析构函数
	virtual ~SyncRenderObjectArray(){};
	//! \brief 加锁
	void   Lock(){m_mutex.lock();};
	//! \brief 解锁
	void   Unlock(){m_mutex.unlock();};
public:
	//! \brief 互斥对象成员
	UGMutex m_mutex;
	//! \brief 数组成员
	UGArray<UGRenderable*> m_Array;

	
};
//! \brief 可渲染对象列表管理数组类，具有异步处理能力
class SCENE_API UGRenderableObjectList : public UGRenderable
{
public:
	//! \brief 构造函数
	UGRenderableObjectList();
	//! \brief 析构函数
	virtual ~UGRenderableObjectList();
	//! \brief 初始化
	virtual void Initialize();
	//! \brief 更新函数，在更新线程中调用
	virtual void Update();
	//! \brief 渲染函数，在渲染线程中调用
	virtual void Render();
	//! \brief 释放数据
	virtual void Release();
	//! \brief 添加一个渲染对象
	void Add(UGRenderable *ro);
	//! \brief 移出所有渲染对象
	void RemoveAll();
	//! \brief 设置对象是否可见
	void SetLayerHide(UGString strName, UGbool bHide);
	//! \brief 判断对象是否可见
	UGbool IsLayerHide(UGString strName);
	//! \brief 根据标志名称获取可渲染对象
	UGRenderable* GetRenderObject(const UGString& strName);
	//! \brief 设置相机
	virtual void NotifyActiveCamera(UGCameraBase* pActiveCamera);

private:
	//! \brief 管理所有可渲染对象的同步数组成员
	SyncRenderObjectArray m_Children;

};
}
#endif // !defined(AFX_UGRENDERABLEOBJECTLIST_H__260EEE73_E53A_4651_9778_2B09D6187D01__INCLUDED_)
