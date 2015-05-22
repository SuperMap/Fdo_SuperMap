/* 
	\file UGD3D9RenderWindow.h
	\brief 窗口类。
	\author zhangyl  luofx
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>更新说明：。</b>
	<em>1、第一条说明。</em>
	<em>2、第二条说明。</em>
*/
	
#if !defined(AFX_UGD3D9RENDERWINDOW_H__FE82B3D4_7CA9_41F6_9A74_AF0EBE45ED74__INCLUDED_)
#define AFX_UGD3D9RENDERWINDOW_H__FE82B3D4_7CA9_41F6_9A74_AF0EBE45ED74__INCLUDED_


#include "Scene/UGRenderWindow.h"
#include "D3dRenderSys/UGD3D9Driver.h"
#include "Scene/UGConfigOptionMap.h"

namespace UGC
{

//! \brief 窗口类。
class UGD3D9RenderWindow : public UGRenderWindow  
{

public:

	//! \brief 带参数构造函数。
	//! \param *pDriver 设备指针[in]。
	UGD3D9RenderWindow(UGD3D9Driver *pDriver);	
	
	//! \brief 析构函数。
	virtual ~UGD3D9RenderWindow();	
	
	//! \brief 获取D3D设备对象。
	//! \return D3D设备对象。
	LPDIRECT3DDEVICE9 GetD3DDevice();	
	
	//! \brief 获取自定义属性。
	//! \param name 名称[in]。
	//! \param pData 属性指针[in]。
	void GetCustomAttribute( const UGString& name, void* pData );	
	
	//! \brief 创建窗口。
	//! \param name 名称[in]。
	//! \param hWnd 外部句柄[in]。
	virtual void Create(UGString name, Window hWnd, NameValuePairList *miscParams);	
	
	//! \brief 销毁D3D。
	void Destroy(void);	
	
	//! \brief 销毁D3D资源。
	void DestroyD3DResources();	
	
	//! \brief 交换前后台缓存。
	//! \param waitForVSync [in]。
	void SwapBuffers( UGbool waitForVSync );	

	//! \brief 获取D3D显示参数。
	//! \return 显示参数结构体指针。
	D3DPRESENT_PARAMETERS* GetPresentationParameters(void);	
	

protected:	
	
	//! \brief 创建D3D资源。
	void CreateD3DResources(NameValuePairList *miscParams);	

protected:
	
	//! \brief D3D设备对象。
	UGD3D9Driver *m_pDriver;			// D3D9 driver
	
	//! \brief D3D显示参数结构体。
	D3DPRESENT_PARAMETERS m_d3dpp;
	
	//! \brief 是否垂直显示。
	UGbool m_bVSync;

	//! \brief FSAA类型(多重采用类型)。
	D3DMULTISAMPLE_TYPE m_FSAAType;

	//! \brief FSAA质量。
	DWORD m_FSAAQuality;
	
	UGbool m_bUseNVPerfHUD;
};

}
#endif // !defined(AFX_UGD3D9RENDERWINDOW_H__FE82B3D4_7CA9_41F6_9A74_AF0EBE45ED74__INCLUDED_)
