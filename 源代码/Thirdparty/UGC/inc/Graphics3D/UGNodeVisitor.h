// UGNodeVisitor.h: interface for the UGNodeVisitor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(UGNODEVISITOR_H)
#define UGNODEVISITOR_H
#include "Graphics3D/UGGraphics3DHeaders.h"
#include "Graphics3D/UGNode.h"
#include "Graphics3D/UGFrameStamp.h"

namespace UGC{
class GRAPHICS3D_API UGNodeVisitor  
{
public:
	UGNodeVisitor();
	virtual ~UGNodeVisitor();
public:
	enum TraversalMode
	{
		TRAVERSE_NONE,
        TRAVERSE_PARENTS,
        TRAVERSE_ALL_CHILDREN,
        TRAVERSE_ACTIVE_CHILDREN
	};
	enum VisitorType
	{
		NODE_VISITOR = 0,
        UPDATE_VISITOR,
        EVENT_VISITOR,
        COLLECT_OCCLUDER_VISITOR,
        CULL_VISITOR
	};
	void Reset();

	//visitor design pattern;
	virtual void Apply(UGNode& node)                      { Traverse(node);}	
	virtual void Apply(UGGeode& node)                     { Apply((UGNode&)node); }
	virtual void Apply(UGBillboard& node)                 { Apply((UGGeode&)node); }
	virtual void Apply(UGGroup& node)                     { Apply((UGNode&)node); }
	virtual void Apply(UGProjectionNode& node)            { Apply((UGGroup&)node); }
	virtual void Apply(UGCoordinateSystemNode& node)      { Apply((UGGroup&)node); }
	virtual void Apply(UGLightNode& node)                 { Apply((UGGroup&)node); }
	virtual void Apply(UGTransform& node)                 { Apply((UGGroup&)node); }
	
	virtual void Apply(UGSwitch& node)                    { Apply((UGGroup&)node); }
	virtual void Apply(UGSequence& node)                  { Apply((UGGroup&)node); }
	virtual void Apply(UGLOD& node)                       { Apply((UGGroup&)node); }
	virtual void Apply(UGClearNode& node)                 { Apply((UGGroup&)node); }
	

	inline void Traverse(UGNode& node)
	{
		if (m_enTraversalMode==TRAVERSE_PARENTS) node.Ascend(*this);
		else if (m_enTraversalMode!=TRAVERSE_NONE) node.Traverse(*this);
	}
	
	inline void SetVisitorType(VisitorType type);
	inline VisitorType GetVisitorType() const;
	
	inline void SetTraversalNumber(int nFrameNumber);
	inline UGint GetTraversalNumber() const;
	
	inline void SetFrameStamp(UGFrameStamp* fs) ;
	inline const UGFrameStamp* GetFrameStamp() const;

	inline void PushOntoNodePath(UGNode* node);
	inline void PopFromNodePath();
	const NodePath& GetNodePath() const;
	NodePath& GetNodePath();
    
protected:

	UGint m_nTraversalNumber;
	NodePath  m_NodePath;
	TraversalMode m_enTraversalMode;
	VisitorType m_enType;
	UGFrameStamp* m_pFrameStamp;

};

}

#endif // !defined(AFX_UGNODEVISITOR_H__AB1DEEC6_B9F7_4804_A339_B42F9C594016__INCLUDED_)
