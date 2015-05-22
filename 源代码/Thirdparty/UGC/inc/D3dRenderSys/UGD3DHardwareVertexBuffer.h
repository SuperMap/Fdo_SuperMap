/* 
	\file UGD3DHardwareVertexBuffer.h
	\brief 硬件顶点缓冲类
	\author 张艳良
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>更新说明：。</b>
	<em>1、第一条说明。</em>
	<em>2、第二条说明。</em>
*/

#if !defined(AFX_UGD3DHARDWAREVERTEXBUFFER_H__E37468E5_451A_4FE4_94B1_ED9C639F3FEC__INCLUDED_)
#define AFX_UGD3DHARDWAREVERTEXBUFFER_H__E37468E5_451A_4FE4_94B1_ED9C639F3FEC__INCLUDED_

#include "D3dRenderSys/UGD3D9Prerequisites.h"
#include "Scene/UGHardwareVertexBuffer.h"

namespace UGC 
{

//! \brief 硬件顶点缓冲类。
class D3DRENDERSYS_API UGD3DHardwareVertexBuffer : public UGHardwareVertexBuffer
{

public:
	
	//! \brief 构造函数。
	UGD3DHardwareVertexBuffer();	
	
	//! \brief 析构函数。
	virtual ~UGD3DHardwareVertexBuffer();	

public:
	
	//! \brief 获取顶点缓冲。
	//! \return 顶点缓冲。
	LPDIRECT3DVERTEXBUFFER9 getD3D9VertexBuffer(void) const;	

protected:
	
	//! \brief 顶点缓冲。
	LPDIRECT3DVERTEXBUFFER9 m_lpD3DBuffer;

};

}

#endif // !defined(AFX_UGD3DHARDWAREVERTEXBUFFER_H__E37468E5_451A_4FE4_94B1_ED9C639F3FEC__INCLUDED_)
