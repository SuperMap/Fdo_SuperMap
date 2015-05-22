// UGMesh.h: interface for the UGMesh class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(UGMESH_H)
#define UGMESH_H

#include "Graphics3D/UGGraphics3DHeaders.h"
#include "Graphics3D/UGGeometry3D.h"
#include "UGVector3.h"
#include "UGVector2.h"

namespace UGC{	
class GRAPHICS3D_API UGMesh:public UGGeometry3D
{
public:
	enum Mode
	{
		TRIANGLES,// = GL_TRIANGLES,
		TRIANGLE_STRIP,// = GL_TRIANGLE_STRIP,
		TRIANGLE_FAN,// = GL_TRIANGLE_FAN,
	};
public:
	UGMesh();
	virtual ~UGMesh();
	
protected:
	//!\brief 子对象个数
	UGuint m_nSubCount;
	//!\brief 子对象的Mode值
	Mode* m_pModes;
	//每个字对象对应的索引
	Real** m_pIndices;
	//!\brief 点的个数
	UGuint m_nNumVertices;
	//!\brief 定点坐标数据
	Real* m_pVertices;	
	//! \brief 向量
	UGbool m_bHasNormal;
	//! \brief 向量数据
	Real*   m_pNormals;	
	//! \brief 颜色
	UGbool  m_bHasColor;	
	//! \brief 颜色数据
	UGint * m_pColors;
	//! \brief 纹理坐标的个数
	UGushort m_nNumTexCoords;	
	//! \brief 每个纹理的维数
	UGushort m_nTexCoordDim[UGC_MAX_TEXTURE_COORD_SETS];	
	//! \brief 文理坐标
	Real*    m_pTexCoords[UGC_MAX_TEXTURE_COORD_SETS];
	//!\brief stride
//	UGushort  m_nVertexStride;
//	UGushort m_nNormalStride;
//	UGushort  m_nTexCoordStride[UGC_MAX_TEXTURE_COORD_SETS];
//	UGushort  m_nColorStride;
	
};

}

#endif // !defined(UGMESH_H)
