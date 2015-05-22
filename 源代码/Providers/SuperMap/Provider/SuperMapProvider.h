
/** \file	 SuperMapProvider.h
 *  \author	 郝玉江
 *  \attention 
 *  Copyright &copy;  1996-2007 SuperMap GIS Technologies,Inc.<br>
 *  All Rights Reserved
 *  \version 1.0
 *  \date 2007-09-19
 */


#ifndef __SUPERMAP_PROVIDER_H__
#define __SUPERMAP_PROVIDER_H__

#define __W(x)      L ## x
#define WTEXT(x)    __W(x)

// General descriptive items of SuperMap Provier:
#define SUPERMAP_PROVIDER_NAME					L"SuperMap.SuperMap SDX.1.0"
//#define SUPERMAP_PROVIDER_DEFAULT_DISPLAY_NAME	"适用于 SuperMap SDB/SDX+ 的 SuperMap FDO 提供程序"
#define SUPERMAP_PROVIDER_DEFAULT_DISPLAY_NAME	"FDO Provider for SuperMap"
//#define SUPERMAP_PROVIDER_DEFAULT_DESCRIPTION	"对基于 SuperMap SDB/SDX+ 的数据存储具有读/写权限。"
#define SUPERMAP_PROVIDER_DEFAULT_DESCRIPTION	"Read/write access to SuperMap SDB/SDX-based Data."

#define SUPERMAP_PROVIDER_VERSION				L"1.0.1.0"
#define SUPERMAP_FDO_VERSION					L"3.3.0.0"  // 应为3.2.3.0

// Connection property strings:
const wchar_t CONNECTIONPROPERTY_DATASOURCE[] = L"DataSource";		//L"数据源";

// 连接属性
const wchar_t CONNECTIONPROPERTY_SERVER[]		= L"server";
const wchar_t CONNECTIONPROPERTY_USER[]			= L"user";
const wchar_t CONNECTIONPROPERTY_PASSWORD[]		= L"password";
const wchar_t CONNECTIONPROPERTY_CONN_TYPE[]	= L"type";
const wchar_t CONNECTIONPROPERTY_DATABASE[]		= L"database";
const wchar_t CONNECTIONPROPERTY_IMAGE[]        = L"IsImage"; //added by zhouxu for Image

// SuperMap Provier identifier names
const wchar_t FEATID_PROPERTY[5] = L"SmID";
const wchar_t GEOMETRY_PROPERTY[9] = L"Geometry";
const wchar_t RASTER_PROPERTY[9] = L"SuRaster";

//TODO::改一个用户可以很容易识别，但又不可能重复的名字
const wchar_t TEXT_PROPERTY[12] = L"TextString"; // added by zhoux for text dataset.
const wchar_t TEXT_SIZE_PROPERTY[9] = L"TextSize"; 
const int TEXT_LENGTH = 100; // 文本数据集转点数据集后的文本字段长度设置，暂订为100

// Spatial context constants:
//const wchar_t SPATIALCONTEXT_DEFAULT_NAME[18] = L"默认";
const wchar_t SPATIALCONTEXT_DEFAULT_NAME[18] = L"Default";
const wchar_t SPATIALCONTEXT_CSYS_DEFAULT_NAME[4] = L"";
const wchar_t SPATIALCONTEXT_CSYS_DEFAULT_WKT[4] = L"";

const double SPATIALCONTEXT_DEFAULT_XY_TOLERANCE = 0.001;
const double SPATIALCONTEXT_DEFAULT_XY_TOLERANCE_LL = 0.0000001; 
const double  SPATIALCONTEXT_DEFAULT_Z_TOLERANCE = 0.001;
const double  SPATIALCONTEXT_DEFAULT_MINX = -10000000;//-10000000
const double  SPATIALCONTEXT_DEFAULT_MINY = -10000000;
const double  SPATIALCONTEXT_DEFAULT_MAXX = 10000000;
const double  SPATIALCONTEXT_DEFAULT_MAXY = 10000000;

// 有关影像数据集的调色板的属性
const wchar_t PALETTEATTRNAME[] =  L"PaletteAttrName";
const wchar_t NUMOFPALETTEENTRIESATTRNAME[] = L"NumOfPaletteEntriesAttrName";


#endif // __SUPERMAP_PROVIDER_H__
