// UGRenderGraph.h: interface for the UGRenderGraph class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(UGRENDERGRAPH_H)
#define UGRENDERGRAPH_H
#include "Graphics3D/UGGraphics3DHeaders.h"
#include "Base/UGDict.h"
#include "Base/UGArray.h"

namespace UGC{
class UGRenderLeaf;
class GRAPHICS3D_API UGRenderGraph  
{
public:
	typedef UGDict<UGMaterial*,UGRenderGraph*> ChildList;
	typedef UGArray<UGRenderLeaf*> LeafList;
	UGRenderGraph();
	virtual ~UGRenderGraph();
	
	void Reset();	
	UGbool IsEmpty();
	UGbool IsLeavesEmpty();
	//!生成子节点
	UGRenderGraph* FindOrInsert(const UGMaterial* pMaterial);
	void AddLeaf(UGRenderLeaf* pLeaf);
	//!得到父节点
	UGRenderGraph* GetParent();
		

protected:
	ChildList m_Children;
	LeafList  m_Leaves;
	UGMaterial* m_pMaterial;
	UGRenderGraph* m_pParent;
	UGint m_nDepth;
};

}

#endif // !defined(AFX_UGRENDERGRAPH_H__480F8598_0E4E_44A4_B596_3CF218AD2D41__INCLUDED_)
