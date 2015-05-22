
/** \file	 SuperMap.h
 *  \author	 ºÂÓñ½­
 *  \attention 
 *  Copyright &copy;  1996-2007 SuperMap GIS Technologies,Inc.<br>
 *  All Rights Reserved
 *  \version 1.0
 *  \date 2007-09-19
 */


#ifndef __SUPERMAP_H__
#define __SUPERMAP_H__

#include <SuperMapTrace.h>

// FDO Headers File
#include <FdoStd.h>
#include <FDO.h>
#include <FdoCommon.h>
#include <FdoGeometry.h>
#include <FdoMessage.h>

// FdoCommon Headers File
#include <FdoCommonConnPropDictionary.h>
#include <FdoCommonMiscUtil.h>
#include <FdoCommonSchemaUtil.h>
#include <FdoCommonOSUtil.h>
#include <FdoCommonStringUtil.h>
#include <FdoCommonCommand.h>
#include <FdoCommonFeatureCommand.h>
#include <FdoCommonFile.h>
#include <FdoCommonStringUtil.h>
#include <FdoCommonOSUtil.h>
#include <FdoCommonConnStringParser.h>

// SuperMap Provider Headers
#include <../Message/Inc/SuperMapMessage.h>
#include <FdoSuperMapProvider.h>
#include <SuperMapProvider.h>
#include <SuperMapConnection.h>
#include <SuperMapConnectionInfo.h>
#include <SuperMapConnectionPool.h>
#include <SuperMapConfig.h>

// Capabilities
#include <SuperMapCommandCapabilities.h>
#include <SuperMapConnectionCapabilities.h>
#include <SuperMapGeometryCapabilities.h>
#include <SuperMapExpressionCapabilities.h>
#include <SuperMapSchemaCapabilities.h>
#include <SuperMapRasterCapabilities.h>
#include <SuperMapTopologyCapabilities.h>
#include <SuperMapFilterCapabilities.h>

// Command
#include <SuperMapDescribeSchemaCommand.h>
#include <SuperMapApplySchemaCommand.h>
#include <SuperMapCreateSpatialContextCommand.h>
#include <SuperMapDescribeSchemaMappingCommand.h>
#include <SuperMapDestroySchemaCommand.h>
#include <SuperMapGetSpatialContextsCommand.h>
#include <SuperMapSelectAggregatesCommand.h>
#include <SuperMapSelectCommand.h>
#include <SuperMapInsertCommand.h>
#include <SuperMapUpdateCommand.h>
#include <SuperMapDeleteCommand.h>
#include <SuperMapCreateDataStoreCommand.h>
#include <SuperMapFeatureReader.h>
#include <SuperMapInsertReader.h>
#include <SuperMapLpFeatureSchema.h>
#include <SuperMapLpClassDefinition.h>
#include <SuperMapLpPropertyDefinition.h>
#include <SuperMapDataReader.h>

// GeoConvert
#include <SuperMapGeoToFgfGeo.h>
#include <SuperMapFgfGeoToUGCGeo.h>

// Spatial Context     
#include <SuperMapSpatialContext.h>
#include <SuperMapSpatialContextReader.h>

// Filter
#include <SuperMapFilterStringBuffer.h>
#include <SuperMapFilterProcessor.h>
#include <SuperMapExpressionProcessor.h>

// Raster
#include <SuperMapRaster.h>
#include <SuperMapStreamReader.h>
#include <SuperMapRasterPropertyDictionary.h>

// Transaction
//#include <SuperMapTransaction.h>

//UGC_support
#include <Base/UGAutoPtr.h>
#include <Base/UGUnit.h>
#include <Base/UGFile.h>
#include <Base/UGLogFile.h>
#include <Engine/ugeng.h>
#include <Engine/UGDataSource.h>
#include <Engine/UGDsConnection.h>
#include <Engine/UGDataSourceManager.h>
#include <Engine/UGDatasetVector.h>
#include <Engine/UGDatasetRaster.h>
#include <Geometry/UGGeoPoint.h>
#include <Geometry/UGGeoLine.h>
#include <Geometry/UGGeoMultiPoint.h>
#include <Geometry/UGGeoRegion.h>
#include <Geometry/UGGeoText.h>
#include <Algorithm/UGPoint2D.h>
#include <Operation/UGSpatialQuery.h>

// Util
#include <SupermapUtil.h>
#include <SuperMapIniFile.h>
#include <ctime>

#endif // __SUPERMAP_H__


