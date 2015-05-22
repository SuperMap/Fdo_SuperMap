// UGRenderLeaf.h: interface for the UGRenderLeaf class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(UGRENDERLEAF_H)
#define UGRENDERLEAF_H
#include "Graphics3D/UGGraphics3DHeaders.h"
#include "Graphics3D/UGMatrix4.h"

namespace UGC{
class UGRenderGraph;
class UGGraphics3D;
class GRAPHICS3D_API UGRenderLeaf
{
public:
	UGRenderLeaf();
	UGRenderLeaf(UGDrawable* pDrawable, UGMatrix4& projectionmatix, UGMatrix4& modelviewmatrix,Real fDepth = 0.0f);
	virtual ~UGRenderLeaf();
	void Reset();
	void Set(UGDrawable* pDrawable, UGMatrix4& projectionmatix, UGMatrix4& modelviewmatrix,Real fDepth = 0.0f);
	void Draw(UGGraphics3D* pGraphics3D);

protected:
	UGRenderGraph* m_pParentGraph;
	UGDrawable* m_pDrawable;
	UGMatrix4 m_ProjectionMatrix;
	UGMatrix4 m_ModelViewMatrix;
	Real m_fDepth;
};

}

#endif // !defined(AFX_UGRENDERLEAF_H__70181F6C_F685_4663_97B6_5A9EC3ACB323__INCLUDED_)
