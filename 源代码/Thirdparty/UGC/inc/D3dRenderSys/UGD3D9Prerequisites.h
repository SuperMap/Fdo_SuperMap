#ifndef __UGD3D9PREREQUISITES_H__
#define __UGD3D9PREREQUISITES_H__

#include "Scene/UGPrerequisites.h"

#define SAFE_DELETE(p)       { if(p) { delete (p);     (p)=NULL; } }
#define SAFE_RELEASE(p)      { if(p) { (p)->Release(); (p)=NULL; } }

#include "d3d9.h"
#include "d3dx9.h"

#endif