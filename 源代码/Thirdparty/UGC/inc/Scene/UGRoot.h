// UGRoot.h: interface for the UGRoot class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGROOT_H__03A35829_E853_4F08_82E9_704E50EF7DC1__INCLUDED_)
#define AFX_UGROOT_H__03A35829_E853_4F08_82E9_704E50EF7DC1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Scene/UGPrerequisites.h"
#include "Scene/UGScene.h"
#include "Scene/UG3DWorkThread.h"
#include "Scene/UG3DWindowTypes.h"
#include "Scene/UGRenderWindow.h"
#include "Scene/UGSingleton.h"
namespace UGC
{

//! \brief 重定义数据类型,重定义函数指针	
typedef  UGRenderSys* (*CREATERENDERSYS)();

class SCENE_API UGRoot : public UGSingleton<UGRoot>
{
public:
	//! \brief 定义渲染方式枚举常量
	typedef enum _RenderSysType
	{
		RST_NONE = 0, 
			RST_OGL = 1, 
			RST_D3D = 2
	} RenderSysType;
public:
	UGRoot();
	virtual ~UGRoot();
	
	
public:
	UGScene &GetScene();
	//! \brief 清除使用过资源，析构函数中调用该函数
	void Fini();
	
	//! \brief 设置窗口渲染类型
	void SetRenderSysType(RenderSysType renderSysType);	
	
	//! \brief 得到激活渲染类型
	RenderSysType  GetRenderSysType();
	
	//! \brief 空闲处理函数
	/**
	这个函数完成场景渲染,包括对场景所有处理都在该函数中完成
	\param lCount 没有用到,建议删除
	*/
	void OnApplicationIdle(UGlong lCount);		
	
	//! \brief 初始化UGRenderWindow对象
	UGRenderWindow *Initialize(Window hWnd);
	UGDict<RenderSysType, UGRenderSys*> &GetRenderSysMap();
	
	UGRenderSys* GetActiveRenderSys();
	
	void SetActiveRenderSys(UGRenderSys* pActiveRenderSys);	
	// 设置所有的RenderTarget为同一种字体 
	void SetRenderTargetsFont(const UGTextStyle& textStyle);
	
protected:
	
	void UpdateAllRenderTargets(void);		
	
	void CreateWorkThread();	
	
	//! \brief 程序是否空闲
	UGbool IsAppStillIdle();	
	UGRenderSys* SetupGLRenderSys();
	UGRenderSys* SetupD3DRenderSys();
	void SetupRenderSys();
	
public:
	
	//! \brief 当前渲染系统
	static UGRoot& GetSingleton();
	
	
protected:
	//! \brief 渲染对象类型
	RenderSysType m_nRenderSysType;		
	
	UGDict<RenderSysType, UGRenderSys*> m_RenderSysMap;	
	
	UGRenderSys* m_pActiveRenderSys;
	
	//! \brief 渲染动态库句柄
	void* m_hRSLibHandle;
	UGDict<RenderSysType, void*> m_RSLibHandle;	 
	
	//! \brief 工作线程指针
	UG3DWorkThread *m_pWorkThread;
	
	UGScene m_Scene;
	
	
};
}
#endif // !defined(AFX_UGROOT_H__03A35829_E853_4F08_82E9_704E50EF7DC1__INCLUDED_)
