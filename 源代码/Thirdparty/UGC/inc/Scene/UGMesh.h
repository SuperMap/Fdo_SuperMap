/* 
	\file UGMesh.h
	\brief 面结构体和网格对象类。
	\author malq zhangyl
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>更新说明：。</b>
	<em>1、第一条说明。</em>
	<em>2、第二条说明。</em>
*/


#if !defined(AFX_UGMESH_H__E5567E39_00CB_4E7D_9FF6_835268B2D58B__INCLUDED_)
#define AFX_UGMESH_H__E5567E39_00CB_4E7D_9FF6_835268B2D58B__INCLUDED_

#include "Scene/UGPrerequisites.h"
#include "Scene/UGRenderOperation.h"

namespace UGC
{

//! \brief 面结构体。
struct Face
{
	//! \brief 平面方程系数。
	UGushort a,b,c;
	
	//! \brief 索引。
	UGshort m_MatIndex;

	//! \brief 构造函数。
	Face()	
	{
		a = 0;
		b = 0;
		c = 0;
		m_MatIndex = -1;
	}
};

//! \brief 网格对象。
class SCENE_API UGMesh
{

public:

	//! \brief 构造函数。
	UGMesh();	
	
	//! \brief 带参数构造函数。
	//! \param strName 名称[in]。
	UGMesh(const UGString& strName);
	
	//! \brief 析构函数。
	virtual ~UGMesh();	

	//! \brief 释放资源。
	void Release();	
	
	//! \brief 设置纹理。
	//! \param pTexture 纹理对象[in]。
	void SetTexture(UGTexture* pTexture);	
	
	//! \brief 设置纹理。
	//! \param strImgPath 纹理图片路径[in]。
	void SetTexture(const UGString& strImgPath);	
	
	//! \brief 设置前面。
	//! \param enFrontFace 前面方式常量[in]。
	void SetFrontFace(UGint enFrontFace);	
	
	//! \brief 设置向量模式。
	//! \param normalMode 模式常量[in]。
	void SetNormalMode(UGint normalMode);	
	
	//! \brief 渲染对象。
	//! \param &drawArgs 参数[in]。
	void Render();	
	
	//! \brief 初始化网格对象。
	//! \param &drawArgs 参数[in]。
	void Initialize();	
	
	//! \brief 查找网格对象。
	//! \param strName 名称[in]。
	//! \return 网格对象指针。
	UGMesh* FindMesh(const UGString& strName);	
	
	// 注意这个函数不改变计数，所以外面一定要改变计数
	
	//! \brief 建立几何数据。
	//! \param numVertice 顶点数目[in]。
	//! \param numNormal 向量数目[in]。
	//! \param numFace 面数目[in]。
	//! \param numTextCoord 纹理坐标数目[in]。
	void SetupGeometryData(UGint numVertice,UGint numNormal,UGint numFace,UGint numTextCoord );	

	//! \brief 获取子网格对象。
	//! \param index 索引号[in]。
	//! \return 网格对象指针。
	UGMesh* GetSubMeshAt(UGint index);	
	
	//! \brief 添加网格对象。
	//! \param strName 名称[in]。
	//! \return 网格对象指针。
	UGMesh* AddMesh(const UGString& strName);	
	
	//! \brief 获取子网格集合。
	//! \return 子网格列表。
	UGList<UGMesh*>* GetSubList();	
	
	//! \brief 网格伸缩。
	//! \param fScale 伸缩系数[in]。
	void Scale(UGfloat fScale);	
	
	//! \brief 调整顶点值。
	//! \param vecCenter 中心位置[in]。
	//! \param fScale 缩放系数[in]。
	void Unitize(const UGVector3R& vecCenter,UGReal fScale);	
	
	//! \brief 计算顶点向量。
	void ComputerVertexNormals();	

public:

	//! \brief 渲染对象。
	UGRenderOperation m_RenderOperation;
	//! \brief 名称。
	UGString m_strName;
	//! \brief 材质ID。
	UGint  m_nMaterialID;

	// 这几个都是帮助生成 RenderOperation的
	//! \brief 三角形索引集首指针。
	UGuint* m_pIndexTriangles;

	//! \brief 面参数集首地址。
	Face   *m_pFaces;        // 三角面顶点索引(a,b,c)
	
	//! \brief 三角形数目。
	UGuint m_nNumTriangles;
	
	//! \brief 标记是否共享顶点数据。
	UGbool m_bShareVertexData;
	
	//! \brief 材质对象数组。
	UGArray<UGMaterial*> m_arryMaterial;


private:

	//! \brief 子网格对象列表。
	UGList<UGMesh*>m_listSubMesh;
};

}

#endif // !defined(AFX_UGMESH_H__E5567E39_00CB_4E7D_9FF6_835268B2D58B__INCLUDED_)
