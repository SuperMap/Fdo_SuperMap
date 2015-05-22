/* 
	\file UGD3D9Driver.h
	\brief D3D9设备类文件
	\author 张艳良
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>更新说明：。</b>
	<em>1、第一条说明。</em>
	<em>2、第二条说明。</em>
*/

#if !defined(AFX_UGD3D9DRIVER_H__96DC3D02_6239_462E_AEF1_C34547D47EBC__INCLUDED_)
#define AFX_UGD3D9DRIVER_H__96DC3D02_6239_462E_AEF1_C34547D47EBC__INCLUDED_

#include "Base/UGString.h"
#include "D3dRenderSys/UGD3D9Prerequisites.h"

namespace UGC
{

class UGD3D9VideoModeList;
class UGD3D9VideoMode;

//! \brief D3D设备类
class D3DRENDERSYS_API UGD3D9Driver  
{

private:
	
	//! \brief 用来创建D3D设备对象,D3D接口对象。
	LPDIRECT3D9 m_pD3D;

	//! \brief D3D设备对象。
	LPDIRECT3DDEVICE9 m_pD3DDevice;

	//! \brief 适配器数目。
	unsigned int m_AdapterNumber;

	//! \brief 区分不同适配器结构体。
	D3DADAPTER_IDENTIFIER9 m_AdapterIdentifier;

	//! \brief 桌面显示模式。
	D3DDISPLAYMODE m_DesktopDisplayMode;

	//! \brief 成员的简要说明。
	//! \remarks 备注信息。
	UGD3D9VideoModeList* m_pVideoModeList;

	//! \brief 成员的简要说明。
	//! \remarks 备注信息。
	unsigned int tempNo;

	//! \brief 成员的简要说明。
	//! \remarks 备注信息。
    static unsigned int driverCount;

public:

	//! \brief 构造函数。
	UGD3D9Driver();		// Default


	//! \brief 拷贝构造函数。
	//! \param &ob 拷贝对象[in]。
	UGD3D9Driver( const UGD3D9Driver &ob );	// Copy

	//! \brief 带参数构造函数。
	//! \param pD3D 设备对象[in]。
	//! \param adapterNumber 适配器个数[in]。
	//! \param adapterIdentifer 适配器信息[in]。
	//! \param desktopDisplayMode 桌面现实模式[in]。
	UGD3D9Driver( LPDIRECT3D9 pD3D, unsigned int adapterNumber, const D3DADAPTER_IDENTIFIER9& adapterIdentifer, const D3DDISPLAYMODE& desktopDisplayMode );
	
	//! \brief 析构函数。
	~UGD3D9Driver();

	//! \brief 获取设备名称。
	UGString DriverName() const;


	//! \brief 获取设备描述。
	UGString DriverDescription() const;

	//! \brief 获取D3D对象。
	//! \return D3D对象。	
	LPDIRECT3D9 GetD3D() { return m_pD3D; }
	

	//! \brief 获取设备对象。
	//! \return 设备对象。
	LPDIRECT3DDEVICE9 GetD3DDevice() { return m_pD3DDevice; }

	
	//! \brief 设置设备对象。
	//! \param pD3DDevice 设备对象[in]。
	void SetD3DDevice(LPDIRECT3DDEVICE9 pD3DDevice) { m_pD3DDevice = pD3DDevice; }


	//! \brief 获取适配器个数。
	//! \return 适配器个数。
	unsigned int GetAdapterNumber() const { return m_AdapterNumber; }

	//! \brief 获取适配器信息。
	//! \return 适配器信息。
	const D3DADAPTER_IDENTIFIER9& GetAdapterIdentifier() const { return m_AdapterIdentifier; }


	//! \brief 获取桌面显示模式。
	//! \return 桌面显示模式。
	const D3DDISPLAYMODE& GetDesktopMode() const { return m_DesktopDisplayMode; }

	//! \brief 获取显示模式列表。
	//! \return 显示模式列表。
	UGD3D9VideoModeList* GetVideoModeList();
	
};

}
#endif // !defined(AFX_UGD3D9DRIVER_H__96DC3D02_6239_462E_AEF1_C34547D47EBC__INCLUDED_)
