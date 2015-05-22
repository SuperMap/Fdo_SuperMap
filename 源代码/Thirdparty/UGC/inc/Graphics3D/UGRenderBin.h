// UGRenderBin.h: interface for the UGRenderBin class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(UGRENDERBIN_H)
#define UGRENDERBIN_H
#include "Graphics3D/UGGraphics3DHeaders.h"
#include "Base/UGArray.h"
namespace UGC{
class UGRenderLeaf;
class UGRenderGraph;
class UGRenderStage;
//!\brief 将相似的物体做为一组进行渲染，例如透明
class GRAPHICS3D_API UGRenderBin  
{
public:
	typedef UGArray<UGRenderLeaf*> RenderLeafList;
	typedef UGArray<UGRenderGraph*> RenderGraphList;
	enum SortMode
	{
		NO_SORT,
		SORT_BY_MATERIAL,
        SORT_FRONT_TO_BACK,
        SORT_BACK_TO_FRONT
	};
public:
	UGRenderBin();
	virtual ~UGRenderBin();

	virtual void Reset(){};
	virtual void Clear(){};

	void AddRenderGraph(UGRenderGraph* pRenderGraph);	

	UGRenderBin* GetParent();
	void SetParent(UGRenderBin* pParent);

	void SetSortMode(SortMode sm);
	SortMode GetSortMode();

	//! 根据不同的设置，进行排序
	void Sort();
	//! 开始画
	void Draw(UGGraphics3D* pGraphics3D);

protected:
	void SortFromBackToFront();
	void SortFromFrontToBack();
	void SortByMaterial();	
	
	UGRenderStage* m_pParent;
	RenderGraphList m_GraphList;
	RenderLeafList m_LeafList;
	SortMode m_enSortMode;
};

}

#endif // !defined(AFX_UGRENDERBIN_H__1DD8212D_5367_445D_95B1_5E62978A324F__INCLUDED_)
