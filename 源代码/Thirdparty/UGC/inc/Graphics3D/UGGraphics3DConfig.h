//UG_GRAPHICS3DCONFIG_H

#ifndef UG_GRAPHICS3DCONFIG_H
#define UG_GRAPHICS3DCONFIG_H

#include <Base/ugdefs.h>

namespace UGC
{

#ifdef GRAPHICS3D_DOUBLE_PRECISION 
	typedef UGfloat Real;
#else
	typedef UGdouble Real;
#endif

#ifndef UGC_MAX_TEXTURE_COORD_SETS
#define	UGC_MAX_TEXTURE_COORD_SETS 8
#endif

	

}

#endif// UG_GRAPHICS3DCONFIG_H

