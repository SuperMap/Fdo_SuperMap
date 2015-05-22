// UGGroup.h: interface for the UGGroup class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(UGGROUP_H)
#define UGGROUP_H

#include "Graphics3D/UGGraphics3DHeaders.h"
#include "Graphics3D/UGNode.h"

namespace UGC{
typedef UGArray<UGNode*>NodeList;
class GRAPHICS3D_API UGGroup:public UGNode
{
public:
	UGGroup();
	virtual ~UGGroup();
public:
	virtual void Traverse(UGNodeVisitor& nv);
	UGbool AdChild( UGNode *child );
	UGbool IsertChild( UGuint index, UGNode *child );
	UGbool RemoveChild( UGNode *child );
	
	UGbool RemoveChild(UGuint npos,UGuint nChildrenToRemove=1);
	UGbool ReplaceChild( UGNode *pOrigChild, UGNode* pNewChild );
	inline UGuint getNumChildren() const { return m_Children.GetSize(); }
	UGbool SetChild( UGint i, UGNode* node );
	inline UGNode* GetChild( UGint i ) { return m_Children[i]; }
	inline const UGNode* GetChild( UGuint i ) const { return m_Children[i]; }
	
	inline UGbool ContainsNode( const UGNode* node ) const;	
	inline UGint GetChildIndex( const UGNode* node ) const;
	
protected:
	NodeList m_Children;
};

}

#endif // !defined(AFX_UGGROUP_H__03E1B5A6_6300_4380_9B08_3F75CAF98D19__INCLUDED_)
