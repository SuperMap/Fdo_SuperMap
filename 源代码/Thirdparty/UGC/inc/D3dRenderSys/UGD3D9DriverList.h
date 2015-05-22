/* 
	\file UGD3D9DriverList.h
	\brief 设备列表。
	\author 张艳良
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>更新说明：。</b>
	<em>1、第一条说明。</em>
	<em>2、第二条说明。</em>
*/

#if !defined(AFX_UGD3D9DRIVERLIST_H__063A8C6E_8C1D_4E93_9E84_624E400A723D__INCLUDED_)
#define AFX_UGD3D9DRIVERLIST_H__063A8C6E_8C1D_4E93_9E84_624E400A723D__INCLUDED_

#include "Base/UGList.h"
#include "D3dRenderSys/UGD3D9Driver.h"

namespace UGC
{

//! \brief 设备列表。
class D3DRENDERSYS_API UGD3D9DriverList  
{

private:

	//! \brief 设备列表。
	UGList<UGD3D9Driver> m_DriverList;

	//! \brief D3D对象。
	LPDIRECT3D9 m_pD3D;

public:
	
	//! \brief 带参数构造函数。
	//! \param pD3D D3D对象[in]。
	UGD3D9DriverList( LPDIRECT3D9 pD3D );

	//! \brief 析构函数。
	~UGD3D9DriverList();

	//! \brief 列举所有显示模式。
	BOOL Enumerate();

	//! \brief 获取设备列表中设备个数。
	//! \return 设备个数。
	size_t Count() const;

	//! \brief 获取设备列表中设备。
	//! \param index 索引号[in]。
	UGD3D9Driver* Item( size_t index );

	//! \brief 获取设备列表中设备。
	//! \param &name 名称[in]。
	UGD3D9Driver* Item( const UGString &name );

};


}
#endif // !defined(AFX_UGD3D9DRIVERLIST_H__063A8C6E_8C1D_4E93_9E84_624E400A723D__INCLUDED_)
