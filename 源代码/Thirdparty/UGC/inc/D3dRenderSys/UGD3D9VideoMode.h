/* 
	\file UGD3D9VideoMode.h
	\brief 视频模式类。
	\author 张艳良
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>更新说明：。</b>
	<em>1、第一条说明。</em>
	<em>2、第二条说明。</em>
*/

#if !defined(AFX_UGD3D9VIDEOMODE_H__262179DF_885A_49BE_92A2_B8D8C42E0FAE__INCLUDED_)
#define AFX_UGD3D9VIDEOMODE_H__262179DF_885A_49BE_92A2_B8D8C42E0FAE__INCLUDED_

#include "D3dRenderSys/UGD3D9Prerequisites.h"

namespace UGC
{

static unsigned int g_nModeCount = 0;

//! \brief 视频模式类。
class D3DRENDERSYS_API UGD3D9VideoMode  
{

private:

	//! \brief 显示模式。
	D3DDISPLAYMODE m_DisplayMode;
	
	//! \brief 模式数目。
	unsigned int m_nModeNumber;

public:

	//! \brief 构造函数。
	UGD3D9VideoMode() { m_nModeNumber = ++g_nModeCount; ZeroMemory( &m_DisplayMode, sizeof(D3DDISPLAYMODE) ); }
	
	//! \brief 拷贝构造函数。
	UGD3D9VideoMode( const UGD3D9VideoMode &ob ) { m_nModeNumber = ++g_nModeCount; m_DisplayMode = ob.m_DisplayMode; }
	
	//! \brief 带参数构造函数。
	//! \param d3ddm 显示模式[in]。
	UGD3D9VideoMode( D3DDISPLAYMODE d3ddm ) { m_nModeNumber = ++g_nModeCount; m_DisplayMode = d3ddm; }	
	
	//! \brief 析构函数。
	~UGD3D9VideoMode()
	{
		g_nModeCount--;
	}
	
	//! \brief 获取显示模式宽。
	//! \return 宽。
	unsigned int GetWidth() const { return m_DisplayMode.Width; }	
	
	//! \brief 获取显示高度。
	//! \return 高。
	unsigned int GetHeight() const { return m_DisplayMode.Height; }	
		
	//! \brief 获取格式。
	//! \return 格式。
	D3DFORMAT GetFormat() const { return m_DisplayMode.Format; }	
	
	//! \brief 获取刷新频率。
	//! \return 刷新频率。
	unsigned int GetRefreshRate() const { return m_DisplayMode.RefreshRate; }	
	
	//! \brief 获取颜色深度。
	//! \return 颜色深度。
	unsigned int GetColourDepth() const;	
	
	
	//! \brief 获取显示模式。
	//! \return 显示模式。
	D3DDISPLAYMODE GetDisplayMode() const { return m_DisplayMode; }	
	
	//! \brief 设置刷新频率。
	//! \param rr 新值[in]。
	void IncreaseRefreshRate(unsigned int rr) { m_DisplayMode.RefreshRate = rr; } 	
		
	//! \brief 获取描述。
	//! \return 描述。
	UGString GetDescription() const;	

};

}
#endif // !defined(AFX_UGD3D9VIDEOMODE_H__262179DF_885A_49BE_92A2_B8D8C42E0FAE__INCLUDED_)
