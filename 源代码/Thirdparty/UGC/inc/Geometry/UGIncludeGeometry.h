#ifndef UG_INCLUDE_GEOMETRY_H
#define UG_INCLUDE_GEOMETRY_H

#include "Geometry/UGGeoPoint.h"
#include "Geometry/UGGeoLine.h"
#include "Geometry/UGGeoRegion.h"
#include "Geometry/UGGeoText.h"
#include "Geometry/UGGeoCompound.h"
#include "Geometry/UGGeoLineM.h"		
#include "Geometry/UGGeoRect.h"

#if PACKAGE_TYPE==PACKAGE_UGC
	#include "Geometry/UGGeoArc.h"
	#include "Geometry/UGGeoBSpline.h"
	#include "Geometry/UGGeoCardinal.h"
	#include "Geometry/UGGeoCircle.h"
//	#include "Geometry/UGGeoDonut.h"	
	#include "Geometry/UGGeoEllipse.h"
	//#include "Geometry/UGGeoEllipseOblique.h"
	#include "Geometry/UGGeoEllipticArc.h"
//	#include "Geometry/UGGeoLwpline.h"
	#include "Geometry/UGGeoMultiPoint.h"
//	#include "Geometry/UGGeoPath.h"
	#include "Geometry/UGGeoPie.h"
	#include "Geometry/UGGeoRectRound.h"
	//#include "Geometry/UGGeoEquilateral.h"
	#include "Geometry/UGGeoCurve.h"
	#include "Geometry/UGTINBlock.h"
#endif // end declare ugc sdk

#endif	// UG_INCLUDE_GEOMETRY_H
