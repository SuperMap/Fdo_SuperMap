// UGSceneView.h: interface for the UGSceneView class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(UGSCENEVIEW_H)
#define UGSCENEVIEW_H
#include "Graphics3D/UGGraphics3DHeaders.h"
#include "UGColorValue.h"

namespace UGC{
class UGCamera;
class UGRenderWnd;
class UGRenderGraph;
class UGRenderStage;
class UGCullVisitor;
class GRAPHICS3D_API UGSceneView  
{
public:
	enum LightOptions
	{
		NO_LIGHT = 0x0,
		HEADLIGHT = 0x1,
        SKY_LIGHT = 0x2,
	};
public:
	UGSceneView();
	UGSceneView(UGCamera *pCamera,UGRenderWnd *pWindow,Real fLeft,Real fTop,Real fWidth, Real fHeight,UGint nZOrder);
	virtual ~UGSceneView();
	
	void UpdateDimension(void);
	void SetDimensions(Real left, Real top, Real width, Real height);
	
	void Draw(void);

	UGRenderWnd* GetWindow(void) const;
	UGCamera* GetCamera(void) const;

	//!\brief Get the actual dimension of the render window
	UGint GetActLeft(void) const;
	UGint GetActTop(void) const;
	UGint GetActWidth(void) const;
	UGint GetActHeight(void) const;
	//!\brief Get the relative dimension of the render window
	Real GetRelLeft(void) const;
	Real GetRelTop(void) const;
	Real GetRelWidth(void) const;
	Real GetRelHeight(void) const;
	
	const UGColorValue& GetBGColor(void)const;
	void SetBGColor(const UGColorValue& color);
	int  GetZOrder(void)const;
	bool IsUpdated(void);
	void ClearUpdateFlag(void);

	//! 设置根节点
	void SetData(UGNode* pNode);
protected:

	void Init(void);
	void Cull(void);
	void Update(void);
	UGCullVisitor* m_pCullVisitor;
	UGRenderStage* m_pRenderStage;
	UGRenderGraph* m_pRenderGraph;
	UGNode* m_pRoot;
	UGCamera *m_pCamera;
	UGRenderWnd *m_pTarget;
	UGfloat  m_fRelLeft,m_fRelTop,m_fRelWidth,m_fRelHeight;
	UGint   m_nActLeft,m_nActTop,m_nActWidth,m_nActHeight;
	UGColorValue m_BGColor;	
	UGint m_nZorder;
	UGbool m_bIsUpdated;
	LightOptions m_LightOptions;
	UGLight* m_pLight;
	//! 全局的Material存储共性的Material属性
	UGMaterial* m_pGlobalMaterial;
};
}

#endif // !defined(UGSCENEVIEW_H)
