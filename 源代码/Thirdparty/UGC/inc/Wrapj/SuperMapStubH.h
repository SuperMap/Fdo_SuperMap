// SUPERMAPSTUBH.h: interface for the SUPERMAPSTUBH class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SUPERMAPSTUBH_H__890A573A_5B5E_4F98_B96A_F0E2FD96C91E__INCLUDED_)
#define AFX_SUPERMAPSTUBH_H__890A573A_5B5E_4F98_B96A_F0E2FD96C91E__INCLUDED_


// include Base
#include "Base/UGString.h"
#include "Base/ugdefs.h"
#include "Base/UGStyle.h"
#include "Base/UGDict.h"
#include "Base/UGVariant.h"
#include "Base/UGStyle.h"
#include "Base/UGTextStyle.h"
#include "Base/UGAutoPtr.h"


#include "Geometry/UGGeoArc.h"
#include "Geometry/UGGeoBSpline.h"
#include "Geometry/UGGeoCardinal.h"
#include "Geometry/UGGeoCircle.h"
#include "Geometry/UGGeoCompound.h"
//#include "Geometry/UGGeoDonut.h"
#include "Geometry/UGGeoEllipse.h"
#include "Geometry/UGGeoEllipticArc.h"
//#include "Geometry/UGGeoEquilateral.h"
#include "Geometry/UGGeoLine.h"
#include "Geometry/UGGeoLineM.h"
//#include "Geometry/UGGeoLwpline.h"
#include "Geometry/UGGeoMultiPoint.h"
//#include "Geometry/UGGeoPath.h"
#include "Geometry/UGGeoPie.h"
#include "Geometry/UGGeoPoint.h"
#include "Geometry/UGGeoRect.h"
#include "Geometry/UGGeoRectRound.h"
#include "Geometry/UGGeoRegion.h"
#include "Geometry/UGGeoText.h"
#include "Geometry/UGGeoOperator.h"
#include "Geometry/UGGeoFactory.h"


//
#include "Operation/UGBuffer.h"

#include "Project/UGSpheroid.h"
#include "Project/UGDatum.h"
#include "Project/UGPrjParams.h"
#include "Project/UGGeoCoordSys.h"
#include "Project/UGPrjCoordSys.h"


// include Engine
#include "Engine/UGQueryDef.h"
#include "Engine/UGDataSource.h"
#include "Engine/UGDataset.h"
#include "Engine/UGDatasetVector.h"
#include "Engine/UGDatasetRaster.h"


#include "Graphics/UGImage.h"
#include "Graphics/UGGraphicsManager.h"
#include "Graphics/UGGraphics.h"

#include "Drawing/UGDrawCache.h"



// include Workspace
#include "Workspace/UGWorkspace.h"

// include Map
#include "Map/UGMap.h"
#include "Map/UGLayer.h"
#include "Map/UGGeoEvent.h"

// include Editor
#include "Editor/UGMapWnd.h"

// include NetworkAnalyst
#include "NetworkAnalyst/UGNetworkAnalyst.h"
#include "NetworkAnalyst/UGRoute.h"

using namespace UGC;

#include <jni.h>


#define CLASS_UNKNOWN  0
#define CLASS_SUPERWORKSPACE  1
#define CLASS_SUPERMAP  2
#define CLASS_IMAGE  3

#define CLASS_GEOARC  4
#define CLASS_GEOBSPLINE  5
#define CLASS_GEOCARDINAL  6
#define CLASS_GEOCIRCLE  7
#define CLASS_GEOCOMPOUND  8
#define CLASS_GEODONUT  9
#define CLASS_GEOELLIPSE  10
#define CLASS_GEOELLIPTICARC  11
#define CLASS_GEOEQUILATERAL  12
#define CLASS_GEOLINE  13
#define CLASS_GEOLINEM  14
#define CLASS_GEOLWPLINE  15
#define CLASS_GEOMULTIPOINT  16
#define CLASS_GEOPATH  17
#define CLASS_GEOPIE  18
#define CLASS_GEOPOINT  19
#define CLASS_GEORECT  20
#define CLASS_GEORECTROUND  21
#define CLASS_GEOREGION  22
#define CLASS_GEOTEXT  23


#define CLASS_RECT2D  24
#define CLASS_VARIANT  25
#define CLASS_FIELDINFO  26
#define CLASS_POINTS  27
#define CLASS_QUERYDEF  28




#endif // !defined(AFX_SUPERMAPSTUBH_H__890A573A_5B5E_4F98_B96A_F0E2FD96C91E__INCLUDED_)


