// GLRenderSys.h: interface for the GLRenderSys class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(GLRENDERSYS_H)
#define GLRENDERSYS_H

#include "GLRenderSys\UGLRenderSysHeaders.h"
#include "Scene\UGRenderSys.h"

namespace UGC{

class GLRENDERSYS_API UGLRenderSys: public UGRenderSys  
{
public:
	UGLRenderSys(); 
	virtual ~UGLRenderSys();

};
}

#endif // !defined(GLRENDERSYS_H)
