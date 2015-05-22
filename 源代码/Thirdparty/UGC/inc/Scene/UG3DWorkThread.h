/**  \file UG3DWorkThread.h
   \brief   工作线程
   \auothor malq
   \attetion 球模型采用多线程技术,主线程用于渲染对象
             工作线程用于修改及时更新对象参数
   Copyright(c) 1996-2007 SuperMap GIS Technolgoies, Inc<br>
   All Rights Reserved
   \version 2.0
   <b>更新说明：</b>\n
	<em>1、第一条说明。\n
	<em>2、第二条说明。\n
*/
#if !defined(AFX_UG3DWORKTHREAD_H__A06B2C3A_96B8_42C0_9095_B708C208B766__INCLUDED_)
#define AFX_UG3DWORKTHREAD_H__A06B2C3A_96B8_42C0_9095_B708C208B766__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Scene/UGPrerequisites.h"
#include "Base/UGThread.h"

namespace UGC 
{

//! \brief 3D工作线程
/**
  UG3DWorkThread 派生于基类UGThread
  主要用于及时更新渲染对象参数
*/
class SCENE_API UG3DWorkThread : public UGThread
{

public:

	//! \brief 构造函数
	/**
	  \param *pScene    场景对象指针
	  \param *pDrawArgs 渲染参数
	*/
	UG3DWorkThread(UGRoot *pRoot);
	
	//! \brief 析构函数
	virtual ~UG3DWorkThread();

protected:
	
	//! \brief 重写基类run函数
	/**
	  主要更新UGScene中DrawArgs参数
	  主要用于及时更新面片切分等实时变化
	*/
	UGint run();
	
	UGRoot *m_pRoot;

};

}

#endif // !defined(AFX_UG3DWORKTHREAD_H__A06B2C3A_96B8_42C0_9095_B708C208B766__INCLUDED_)
