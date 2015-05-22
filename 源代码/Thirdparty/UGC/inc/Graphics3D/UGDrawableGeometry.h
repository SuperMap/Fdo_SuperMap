// UGDrawableGeometry.h: interface for the UGDrawableGeometry class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(UGDRAWABLEGEOMETRY_H)
#define UGDRAWABLEGEOMETRY_H

#include "UGDrawable.h"
#include "UGPrimitiveSet.h"
#include "UGVector3.h"
#include "UGColorValue.h"
#include "UGVector2.h"
namespace UGC{

class GRAPHICS3D_API UGDrawableGeometry :public UGDrawable
{
public:
	enum AttributeBinding
	{
		BIND_OFF=0,
        BIND_OVERALL,
        BIND_PER_PRIMITIVE_SET,
        BIND_PER_PRIMITIVE,
        BIND_PER_VERTEX
	};
	typedef UGArray<UGPrimitiveSet*>PrimitiveSetList;
	//!\brief 添加PrimitiveSet
	UGbool AddPrimitiveSet(UGPrimitiveSet* pPrimitiveSet);
	UGbool SetPrimitiveSet(UGint i, UGPrimitiveSet* pPrimitiveSet);
	UGbool InsertPrimitiveSet(UGint i,UGPrimitiveSet* pPrimitiveSet);
	UGbool RemovePrimitiveSet(UGint i,UGPrimitiveSet* pPrimitiveSet);
	UGint  GetPrimitiveCount();
	UGPrimitiveSet* GetPrimitiveSet(UGint nIndex);
	const UGPrimitiveSet* GetPrimitiveSet(UGint nIndex)const;

	//!\brief 设置相应的顶点数据
	void SetVertexArray(UGVec3Array& array);
	UGVec3Array& GetVertexArray();
	const UGVec3Array& GetVertexArray()const;

	//!\brief　设置对应的向量的Binding方式
	void SetNormalBinding(AttributeBinding enBinding);
	AttributeBinding GetNormalBinding();

	//!\brief 设置向量信息
	void SetNormalArray(UGVec3Array& array);
	UGVec3Array GetNormalArray();
	const UGVec3Array GetNormalArray()const;

	//!\brief　设置对应的颜色的 Binding 方式
	void SetColorBinding(AttributeBinding enBinding);
	AttributeBinding GetColorBinding();

	//!\brief 设置颜色数组
	void SetColorArray(UGColorArray& array);
	UGColorArray& GetColorArray();
	const UGColorArray& GetColorArray()const;

	//!\brief 设置对应的纹理坐标
	void SetTexCoordArray(UGint nUnit, UGVec2Array& array);
	UGVec2Array& GetTexCoordArray(UGint nUnit);
	const UGVec2Array& GetTexCoordArray(UGint nUnit)const;
	//!\brief　得到对应的纹理坐标的个数UGC定义的最大纹理数目为8
	UGint GetTexCoordCount();

	void Draw(UGGraphics3D* pGraphics3D);

public:
	UGDrawableGeometry();
	virtual ~UGDrawableGeometry();
protected:
	//这里以后肯定还要增加新的类型
	
	//!\brief 子对象数组
	PrimitiveSetList m_PrimitiveSets;
	
	//!\brief 顶点数组
	UGVec3Array  m_VertexArray;

	//! Normal数据的Binding方式
	AttributeBinding m_enNormalBinding;
	
	//! \brief 向量数组
	UGVec3Array  m_NormalArray;

	//!\brief Color数据的Binding方式
	AttributeBinding  m_enColorBinding;
	
	//! \brief 颜色数组
	UGColorArray m_ColorArray;

	//暂时只实现二维纹理
	
	//!\brief 纹理数组
	UGArray<UGVec2Array> m_TexCoordArray;
};

}

#endif // !defined(AFX_UGDRAWABLEGEOMETRY_H__57376EE3_0263_4AF0_A987_1B37E14AB2C5__INCLUDED_)
