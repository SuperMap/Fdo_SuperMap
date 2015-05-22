// UGCullVisitor.h: interface for the UGCullVisitor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(UGCULLVISITOR_H)
#define UGCULLVISITOR_H

#include "Graphics3D/UGGraphics3DHeaders.h"
#include "Graphics3D/UGNodeVisitor.h"
#include "UGMatrix4.h"
#include "Base/UGArray.h"

namespace UGC{
class UGRenderGraph;
class UGRenderStage;
class GRAPHICS3D_API UGCullVisitor:public UGNodeVisitor  
{
public:
	UGCullVisitor();
	virtual ~UGCullVisitor();
	void SetRenderGraph(const UGRenderStage* pRenderGraph);
	UGRenderStage* GetRenderGraph();

	void SetRenderStage(const UGRenderGraph* pRenderStage);
	UGRenderGraph* GetRenderStage();

	void PushMaterial(UGMaterial* pMaterial);
	void PopMaterial();

	//!\brief  climbing the scenegraph trees
	virtual void Apply(UGNode& node){};
	virtual void Apply(UGLightNode& light){};
	virtual void Apply(UGGroup& group){};
	virtual void Apply(UGTransform& transform){};
	virtual void Apply(UGGeode& geode){};
	virtual void Apply(UGBillboard& billboard){};
	virtual void Apply(UGSwitch& switchnode){};
	virtual void Apply(UGSequence& sequence){};
	virtual void Apply(UGLOD& lod ){};
	virtual void Apply(UGClearNode& clearnode){};

	void PushModelMatrix(const UGMatrix4& modelmatrix);
	void PopModelMatrix();

	void PushProjectionMatrix(const UGMatrix4& projectionmatrix);
	void PopProjectionMatrix();

protected:
	UGRenderStage* m_pRenderStage;
	UGRenderGraph* m_pRenderGraph;
	UGCamera* m_pCamera;
	UGArray<UGMatrix4> m_ModelMatrixStack;
	UGArray<UGMatrix4> m_ProjectionMatrixStack;
};

}

#endif // !defined(AFX_UGCULLVISITOR_H__591C26F1_D25D_4F1C_94AE_CE9202F584BA__INCLUDED_)
