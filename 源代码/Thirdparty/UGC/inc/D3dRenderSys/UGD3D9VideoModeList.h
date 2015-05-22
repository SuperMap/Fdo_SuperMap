/* 
	\file UGD3D9VideoModeList.h
	\brief 视频模式列表类。
	\author 张艳良
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>更新说明：。</b>
	<em>1、第一条说明。</em>
	<em>2、第二条说明。</em>
*/

#if !defined(AFX_UGD3D9VIDEOMODELIST_H__CDB38CE1_1C84_4D11_A346_202B293B7632__INCLUDED_)
#define AFX_UGD3D9VIDEOMODELIST_H__CDB38CE1_1C84_4D11_A346_202B293B7632__INCLUDED_

#include "Base/UGList.h"
#include "D3dRenderSys/UGD3D9Driver.h"
#include "D3dRenderSys/UGD3D9VideoMode.h"

namespace UGC
{
	
//! \brief 视频模式列表类。
class D3DRENDERSYS_API UGD3D9VideoModeList  
{
private:

	//! \brief 设备对象。
	UGD3D9Driver* m_pDriver;

	//! \brief 视频模式列表。
	UGList<UGD3D9VideoMode> m_ModeList;

public:
	
	//! \brief 带参数构造函数。
	//! \param pDriver 设备对象[in]。
	UGD3D9VideoModeList( UGD3D9Driver* pDriver );	
	
	//! \brief 析构函数。
	~UGD3D9VideoModeList();	

	//! \brief 枚举所有视频模式。
	BOOL Enumerate();	

	//! \brief 获取视频模式。
	//! \param index 视频模式索引[in]。
	//! \return 视频模式。
	UGD3D9VideoMode* Item( size_t index );	
	
	//! \brief 获取列表总数。
	size_t Count();	

	//! \brief 获取视频模式。
	//! \param &name 名称[in]。
	//! \return 视频模式。
	UGD3D9VideoMode* Item( const UGString &name );	

};

}
#endif // !defined(AFX_UGD3D9VIDEOMODELIST_H__CDB38CE1_1C84_4D11_A346_202B293B7632__INCLUDED_)
