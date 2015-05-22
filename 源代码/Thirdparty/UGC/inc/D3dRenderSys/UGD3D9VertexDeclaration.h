/* 
	\file UGD3D9VertexDeclaration.h
	\brief 顶点声明类。
	\author 张艳良
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>更新说明：。</b>
	<em>1、第一条说明。</em>
	<em>2、第二条说明。</em>
*/

#if !defined(AFX_UGD3D9VERTEXDECLARATION_H__9B969F14_5DC9_458F_B0D8_5A51FE01E507__INCLUDED_)
#define AFX_UGD3D9VERTEXDECLARATION_H__9B969F14_5DC9_458F_B0D8_5A51FE01E507__INCLUDED_

#include "D3dRenderSys/UGD3D9Prerequisites.h"
#include "Scene/UGHardwareVertexBuffer.h"

namespace UGC 
{
	
//! \brief 顶点声明类。
class D3DRENDERSYS_API UGD3D9VertexDeclaration : public UGVertexDeclaration
{
public:

	//! \brief 构造函数。
	UGD3D9VertexDeclaration();
	
	//! \brief 析构函数。
	virtual ~UGD3D9VertexDeclaration();	

	//! \brief 获取顶点声明。
	//! \return 顶点声明。
	LPDIRECT3DVERTEXDECLARATION9 GetD3DVertexDeclaration(void);	

protected:

	//! \brief 设备对象。
	LPDIRECT3DDEVICE9 m_lpD3DDevice;
	//! \brief 顶点声明。
	LPDIRECT3DVERTEXDECLARATION9 m_lpD3DDecl;
	//! \brief 是否重建。
	bool m_bNeedsRebuild;
};

}
#endif // !defined(AFX_UGD3D9VERTEXDECLARATION_H__9B969F14_5DC9_458F_B0D8_5A51FE01E507__INCLUDED_)
