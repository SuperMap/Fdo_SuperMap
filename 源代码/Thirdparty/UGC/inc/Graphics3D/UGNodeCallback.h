// UGNodeCallback.h: interface for the UGNodeCallback class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(UGNODECALLBACK_H)
#define UGNODECALLBACK_H

#include "Graphics3D/UGGraphics3DHeaders.h"
namespace UGC{

class UGNode;
class UGNodeVisitor;
class GRAPHICS3D_API UGNodeCallback  
{
public:
	UGNodeCallback();
	virtual ~UGNodeCallback();
public:
	virtual void operator()(UGNodeVisitor* node, UGNodeVisitor* nv)
	{ 
		Traverse(node,nv);
	}
	
	void Traverse(UGNodeVisitor* node, UGNodeVisitor* nv);

};
}

#endif // !defined(AFX_UGNODECALLBACK_H__58D7E016_3B15_49E8_97CF_6E220F51BC12__INCLUDED_)
