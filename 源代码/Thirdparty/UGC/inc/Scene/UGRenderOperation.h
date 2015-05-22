/* 
	\file UGRenderOperation.h
	\brief  封装的用于渲染得数据包类文件
	\author malq
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>更新说明：。</b>
	<em>1、第一条说明。</em>
	<em>2、第二条说明。</em>
*/


#if !defined(AFX_UGRENDEROPERATION_H__9A764B82_16B9_4D13_96D8_9A2E2A80CD9B__INCLUDED_)
#define AFX_UGRENDEROPERATION_H__9A764B82_16B9_4D13_96D8_9A2E2A80CD9B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Scene/UGPrerequisites.h"
#include "Base/UGFileStream.h"
#include "Scene/UGVertexData.h"

namespace UGC 
{
// 结构体可以不需要导出来,为了统一我还是写成了类
//! \brief 封装的具有纹理材质的点类
class SCENE_API TextureVertex 
{
public:
	TextureVertex(){x=0;y=0;z=0;u=0;v=0;}
	virtual ~TextureVertex(){}
	UGReal x;
	UGReal y;
	UGReal z;
	UGReal u;
	UGReal v;
};
//! \brief 封装的用于渲染得数据包类
class SCENE_API UGRenderOperation  
{
public:
	//! \brief 数据绘制的方式
	enum OpType
	{
		/// A list of points, 1 vertex per point
		OT_POINT_LIST = 1,
		/// A list of lines, 2 vertices per line
		OT_LINE_LIST = 2,
		/// A strip of connected lines, 1 vertex per line plus 1 start vertex
		OT_LINE_STRIP = 3,
		/// A list of triangles, 3 vertices per triangle
		OT_TRIANGLE_LIST = 4,
		/// A strip of triangles, 3 vertices for the first triangle, and 1 per triangle after that 
		OT_TRIANGLE_STRIP = 5,
		/// A fan of triangles, 3 vertices for the first triangle, and 1 per triangle after that
		OT_TRIANGLE_FAN = 6
	};
	//! \brief 数据绘制的属性
	enum VertexOptions
	{
		VO_NORMALS = 1,   //GL_NORMAL_ARRAY + glNormalPointer()
		VO_TEXTURE_COORDS =2, //GL_TEXTURE_COORD_ARRAY + glTexCoordPointer()
		VO_DIFFUSE_COLOURS = 4, //GL_COLOR_ARRAY + glColorPointer()
		VO_SPECULAR_COLOURS = 8, //Secondary Color
		VO_BLEND_WEIGHTS = 16,
		VO_USE_SINGLE_COLOR = 32, //use only one kind of color
		VO_USE_POINT_SMOOTHING = 64,     // 启动点反走样
		VO_MATERIAL=128 //使用材质
	};
	//! \brief 构造函数
	UGRenderOperation();
	//! \brief 构造函数
	UGRenderOperation(UGbool bUseIndex,UGint enOperationType,UGint eVertexOptions,UGint nTextureDimensions,UGint nNormalMode=SNM_NONE);
	//! \brief 析构函数
	virtual ~UGRenderOperation();
	//! \brief 设置顶点数据
	void SetTexVertexValue(UGuint index,UGReal x, UGReal y, UGReal z, UGReal u, UGReal v);
	//! \brief 设置顶点数据
	void SetTexVertexValue(UGuint index,const TextureVertex& value);
	//! \brief 设置索引数名
	void SetIndexNum(UGuint nCount);
	//! \brief 设置纹理顶点数目 
	void SetTexVertexNum(UGuint nCount);
	//! \brief 设置索引值
	void SetIndexValue(UGuint i, UGushort value);
	//! \brief 从文件中加载数据包
	// 增加构成包围盒代码
	void Load(UGFileStream& fStream,const UGString& strFilepath, UGBoundingBox& BoundingBox);
	//! \brief 将数据包存为文件
	void Save(UGFileStream& fStream);
	//! \brief 释放数据包
	void Release();
	//! \brief 绘制方式成员
	UGint m_enOperationType;
	//! \brief 顶点属性成员
	UGint m_nVertexOptions;
	//! \brief 向量模式成员
	UGint m_enNormalMode;
	//! \brief 正面方向成员
	UGint m_enFrontFace;
	//! \brief PolygonMode
	UGint m_enPolygonMode;


	//! \brief 向量数组
	UGReal* m_pNormals;
	//! \brief 向量数目
	UGint m_nNormalCount;
	//! \brief 向量数组偏移 
	UGushort m_nNormalStride; 
	//! \brief 顶点数目
	UGuint m_nVerticesCount;
	//! \brief 顶点数组
	UGReal *m_pVertices;
	//! \brief 顶点数组偏移
	UGushort m_nVertexStride;
	//! \brief 是否使用索引绘制
	UGbool m_bUseIndex;
	//! \brief 索引数目
	UGuint m_nIndexesCount;
	//! \brief 索引数组
	UGushort *m_pIndexes;	
	//! \brief 颜色数组
    UGulong *m_pDiffuseColor;
	//! \brief 颜色数组偏移
	UGushort m_nDiffuseStride;
	//! \brief 材质变量 
	UGMaterial* m_pMaterial;

	 //! \brief 贴图坐标数据 最多支持6组
	UGReal*	m_pTexCoords[SMSCN_MAX_TEXTURE_COORD_SETS];
	//! \brief 贴图纹理数据 最多支持6组
	UGTexture* m_pTextures[SMSCN_MAX_TEXTURE_COORD_SETS];
	//! \brief 每组贴图坐标的Stride
	UGushort  m_TexCoordStride[SMSCN_MAX_TEXTURE_COORD_SETS];
	//! \brief 贴图坐标的组数
	UGint           m_nTexCoordSets;
	//! \brief 贴图坐标数目
	UGint           m_TexCoordCount[SMSCN_MAX_TEXTURE_COORD_SETS];
	//! \brief 贴图坐标的维数
	UGint			m_TexDimensions[SMSCN_MAX_TEXTURE_COORD_SETS];
	//! \brief 是否使用外部数据
	UGbool m_bExternIndexData;
	
	// 新增变量，目前没有用上
	UGVertexData *vertexData;

private:


};
}
#endif // !defined(AFX_UGRENDEROPERATION_H__9A764B82_16B9_4D13_96D8_9A2E2A80CD9B__INCLUDED_)
