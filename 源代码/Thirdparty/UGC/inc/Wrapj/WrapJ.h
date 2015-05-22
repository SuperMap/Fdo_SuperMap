// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the WRAPJ_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// WRAPJ_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.


//#ifdef WRAPJ_EXPORTS
//#define WRAPJ_API __declspec(dllexport)
//#else
//#define WRAPJ_API __declspec(dllimport)
//#endif
//
//// This class is exported from the WrapJ.dll
//class WRAPJ_API CWrapJ {
//public:
//	CWrapJ(void);
//	// TODO: add your methods here.
//};
//
//extern WRAPJ_API int nWrapJ;
//
//WRAPJ_API int fnWrapJ(void);



#pragma warning(disable:4819 4996)




// include Base
#include "Base/UGString.h"
#include "Base/UGStringW.h"
#include "Base/ugdefs.h"
#include "Base/UGStyle.h"
#include "Base/UGDict.h"
#include "Base/UGVariant.h"
#include "Base/UGStyle.h"
#include "Base/UGTextStyle.h"
#include "Base/UGAutoPtr.h"
#include "Base/UGLogFile.h"


#include "Geometry/UGGeoArc.h"
#include "Geometry/UGGeoBSpline.h"
#include "Geometry/UGGeoCardinal.h"
#include "Geometry/UGGeoCircle.h"
#include "Geometry/UGGeoCompound.h"
#include "Geometry/UGGeoDonut.h"
#include "Geometry/UGGeoEllipse.h"
#include "Geometry/UGGeoEllipticArc.h"
#include "Geometry/UGGeoEquilateral.h"
#include "Geometry/UGGeoLine.h"
#include "Geometry/UGGeoLineM.h"
#include "Geometry/UGGeoLwpline.h"
#include "Geometry/UGGeoMultiPoint.h"
#include "Geometry/UGGeoPath.h"
#include "Geometry/UGGeoPie.h"
#include "Geometry/UGGeoPoint.h"
#include "Geometry/UGGeoRect.h"
#include "Geometry/UGGeoRectRound.h"
#include "Geometry/UGGeoRegion.h"
#include "Geometry/UGGeoText.h"
#include "Geometry/UGGeoOperator.h"
#include "Geometry/UGGeoRelation.h"
#include "Geometry/UGGeoFactory.h"


//
#include "Operation/UGBuffer.h"
#include "Operation/UGSpatialQuery.h"

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
#include "Engine/UGFieldInfo.h"
#include "Engine/UGSpatialIndex.h"


#include "Graphics/UGImage.h"
#include "Graphics/UGGraphicsManager.h"
#include "Graphics/UGGraphics.h"
#include "FileParser/UGExchangeFileType.h"

#include "Drawing/UGDrawCache.h"
#include "Drawing/UGDrawing.h"



// include Workspace
#include "Workspace/UGWorkspace.h"
#include "Workspace/UGWorkspaceConnection.h"



// include Map
#include "Map/UGMap.h"
#include "Map/UGLayer.h"
#include "Map/UGGeoEvent.h"

// include Editor
#include "Editor/UGMapWnd.h"

// include NetworkAnalyst
#include "NetworkAnalyst/UGNetworkAnalyst.h"
#include "NetworkAnalyst/UGTrafficAnalyst.h"
#include "NetworkAnalyst/UGRoute.h"
#include "NetworkAnalyst/UGBusNetwork.h"

// include spatialAnalyst
#include "Operation/UGBuffer.h"
#include "Operation/UGOverlayAnalyst.h"
#include "Operation/UGFourColor.h"

#include "Topology/UGTopoBuild.h"
#include "GeoCode/UGAddressData.h"
#include "GeoCode/UGFuzzySearch.h"

using namespace UGC;

#include <jni.h>

//由于FLT_MIN、DBL_MIN的值是无限接近0的正值，不是我们先要的接近负无穷的值，
//故在此处重新定义doulbe和float类型的最大最小值。
#define FLT_MAX_VALUE         3.4028235e+038        /*float max value */
#define FLT_MIN_VALUE         -3.4028235e+038        /* float min value */
#define DBL_MAX_VALUE         1.7976931348623157e+308        /* double max value */
#define DBL_MIN_VALUE        -1.7976931348623157e+308        /* double min value */


#define HANDLE_TYPE_UGMap 1
#define HANDLE_TYPE_UGMapWnd 2
#define HANDLE_TYPE_UGStyle 3
#define HANDLE_TYPE_UGDsConnection 4
#define HANDLE_TYPE_UGDataSource 5
#define HANDLE_TYPE_UGGeoLine  6
#define HANDLE_TYPE_UGGeoRegion  7
#define HANDLE_TYPE_UGGeometry  8
#define HANDLE_TYPE_UGSelection  9
#define HANDLE_TYPE_UGThemeLabelBackgroundStyle 10
#define HANDLE_TYPE_UGTrackingLayer 11
#define HANDLE_TYPE_UGLayer 12
#define HANDLE_TYPE_UGMapBackgroundStyle 13
#define HANDLE_TYPE_UGGeoText 14
#define HANDLE_TYPE_UGSubPart 15
#define HANDLE_TYPE_UGTextStyle 16
#define HANDLE_TYPE_UGThemeLabel 17
#define HANDLE_TYPE_UGThemeGraphItem 18
#define HANDLE_TYPE_UGThemeGraphAxes 19
#define HANDLE_TYPE_UGDatasetVector 20
#define HANDLE_TYPE_UGFieldInfo 21
#define HANDLE_TYPE_UGLayerSelection 22
#define HANDLE_TYPE_UGFieldInfos 23
#define HANDLE_TYPE_UGQueryDef 24
#define HANDLE_TYPE_UGRecordset 25
#define HANDLE_TYPE_UGThemeUnique  26
#define HANDLE_TYPE_UGThemeItem  27
#define HANDLE_TYPE_UGJoinItem  28
#define HANDLE_TYPE_UGLinkItem  29
#define HANDLE_TYPE_UGThemeLabelTextStyleAt 30
#define HANDLE_TYPE_UGLayerThemeLabelTextStyleAt 31


