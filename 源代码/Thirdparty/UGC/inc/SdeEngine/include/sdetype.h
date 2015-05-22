/* $Id: sdetype.h,v 1.1 2007/03/15 11:00:26 liwl Exp $ */
/***********************************************************************
*
*N  {sdetype.h}  --  Spatial Database Engine Datatypes/Defines Header File
*
*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
*
*P  Purpose:
* 
*                  Spatial Database Engine Datatypes/Defines Header File
*
*   COPYRIGHT 1992-2005 ESRI
*
*   TRADE SECRETS: ESRI PROPRIETARY AND CONFIDENTIAL
*   Unpublished material - all rights reserved under the
*   Copyright Laws of the United States.
*
*   For additional information, contact:
*   Environmental Systems Research Institute, Inc.
*   Attn: Contracts Dept
*   380 New York Street
*   Redlands, California, USA 92373
*
*   email: contracts@esri.com
*   
*E
*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
*
*H  History:
*
*E
***********************************************************************/

#ifndef SDE_TYPES
#define SDE_TYPES

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <time.h>
#include <limits.h>

#include "sg.h"

#define SE_ALL                     0

/************************************************************
*** Backwards compatibility macros for SDE 3.0 code -- use
*** SE_RELEASE and SE_connection_get_release() instead.
*** At some future point these will probably be removed.
************************************************************/
#ifndef SDE_COMMON
#  define SE_VERSION SE_RELEASE
#  define SE_connection_get_version SE_connection_get_release
#endif /* SDE_COMMON */


/************************************************************
*** ALLOWABLE SHAPE TYPE MASKS FOR LAYERS
************************************************************/
#define SE_NIL_TYPE_MASK           (1L)
#define SE_POINT_TYPE_MASK         (1L<<1)
#define SE_LINE_TYPE_MASK          (1L<<2)
#define SE_SIMPLE_LINE_TYPE_MASK   (1L<<3)
#define SE_AREA_TYPE_MASK          (1L<<4)

#define SE_MULTIPART_TYPE_MASK     (1L<<18)

/************************************************************
*** ALLOWABLE STORAGE TYPE MASKS FOR LAYERS
************************************************************/
#define SE_STORAGE_NORMALIZED_TYPE   (1L<<31)
#define SE_STORAGE_SDEBINARY_TYPE    (1L<<24)
#define SE_STORAGE_WKB_TYPE          (1L<<25)
#define SE_STORAGE_SQL_TYPE          (1L<<26)
#define SE_STORAGE_SPATIAL_TYPE      (1L<<27)
#define SE_STORAGE_LOB_TYPE          (1L<<28)
#define SE_STORAGE_SDO_TOPO_TYPE     (1L<<23)

/************************************************************
*** ALLOWABLE LAYER CHARATERISTICS
************************************************************/
#define SE_LAYER_AUTO_REGISTER           (1L<<5)
#define SE_LAYER_HAS_USER_DEFINED_EXTENT (1L<<6)

/************************************************************
*** ALLOWABLE LAYER MASKS
************************************************************/
#define SE_LAYER_HAS_GEODETIC_EXTENT (1L<<1)  

/************************************************************
*** LAYER PRECISION 
************************************************************/
#define SE_LAYER_PRECISION_DEFAULT   0
#define SE_LAYER_PRECISION_32_BIT   32
#define SE_LAYER_PRECISION_64_BIT   64

/************************************************************
*** OGC Storage Type Declarations
************************************************************/
#define SE_OGC_STORAGE_NORMALIZED     0
#define SE_OGC_STORAGE_WKB            1
#define SE_OGC_STORAGE_OTHER          2

/************************************************************
*** OGC Geometry Type Values
************************************************************/

typedef enum {
  SE_OGC_GEOMETRY          = 0,
  SE_OGC_POINT             = 1, 
  SE_OGC_CURVE             = 2, 
  SE_OGC_LINESTRING        = 3,
  SE_OGC_SURFACE           = 4,
  SE_OGC_POLYGON           = 5,
  SE_OGC_COLLECTION        = 6,
  SE_OGC_MULTIPOINT        = 7,
  SE_OGC_MULTICURVE        = 8,
  SE_OGC_MULTILINESTRING   = 9,
  SE_OGC_MULTISURFACE      = 10,
  SE_OGC_MULTIPOLYGON      = 11
} SE_OGC_GEOMETRY_TYPES;

/**************************************************************************
*** OBSOLETE DEFINES FOR STORAGE TYPE MASKS FOR LAYERS -- NOT FOR NEW CODE
***************************************************************************/
#define SE_NORMALIZED_TYPE_MASK  SE_STORAGE_NORMALIZED_TYPE
#define SE_EXTERNAL_TYPE_MASK    SE_STORAGE_SPATIAL_TYPE
#define SE_REGISTERED_TYPE_MASK  (1L<<27)

/***************************************/
/****** ACCESS RIGHTS CONSTANTS ********/
/***************************************/
#define SE_SELECT_PRIVILEGE (1<<1)
#define SE_UPDATE_PRIVILEGE (1<<2)
#define SE_INSERT_PRIVILEGE (1<<3)
#define SE_DELETE_PRIVILEGE (1<<4)

/***************************************************/
/****** TABLE MASKS FOR UPDATING DBMS STATS ********/
/***************************************************/
#define SE_UPDATE_ADDS_TABLE_STATS      (1L<<1)
#define SE_UPDATE_DELETES_TABLE_STATS   (1L<<2)
#define SE_UPDATE_FEATURE_TABLE_STATS   (1L<<4)
#define SE_UPDATE_BUSINESS_TABLE_STATS  (1L<<5)
#define SE_UPDATE_RASTER_TABLE_STATS    (1L<<6)
#define SE_UPDATE_XML_TABLE_STATS       (1L<<7)
#define SE_UPDATE_ALL_TABLE_STATS       (SE_UPDATE_ADDS_TABLE_STATS    | \
                                         SE_UPDATE_DELETES_TABLE_STATS | \
                                         SE_UPDATE_FEATURE_TABLE_STATS | \
                                         SE_UPDATE_RASTER_TABLE_STATS  | \
                                         SE_UPDATE_XML_TABLE_STATS     | \
                                         SE_UPDATE_BUSINESS_TABLE_STATS)

/************************************************************
*** LAYER LOCKING MODES
************************************************************/
#define SE_WRITE_LOCK           1
#define SE_READ_LOCK            2

/************************************************************
*** ATTRIBUTE DATA TYPES
************************************************************/
#define SE_INT16_TYPE              1   /* 2-byte Integer */
#define SE_INT32_TYPE              2   /* 4-byte Integer */
#define SE_FLOAT32_TYPE            3   /* 4-byte Float */
#define SE_FLOAT64_TYPE            4   /* 8-byte Float */
#define SE_STRING_TYPE             5   /* Null Term. Character Array */
#define SE_BLOB_TYPE               6   /* Variable Length Data */
#define SE_DATE_TYPE               7   /* Struct tm Date */
#define SE_SHAPE_TYPE              8   /* Shape geometry (SE_SHAPE) */
#define SE_RASTER_TYPE             9   /* Raster */
#define SE_XML_TYPE                10  /* XML Document */
#define SE_INT64_TYPE              11  /* 8-byte Integer */
#define SE_UUID_TYPE               12  /* A Universal Unique ID */
#define SE_CLOB_TYPE               13  /* Character variable length data */
#define SE_NSTRING_TYPE            14  /* UNICODE Null Term. Character Array */
#define SE_NCLOB_TYPE              15  /* UNICODE Character Large Object */

#define SE_POINT_TYPE              20  /* Point ADT */
#define SE_CURVE_TYPE              21  /* LineString ADT */
#define SE_LINESTRING_TYPE         22  /* LineString ADT */
#define SE_SURFACE_TYPE            23  /* Polygon ADT */
#define SE_POLYGON_TYPE            24  /* Polygon ADT */
#define SE_GEOMETRYCOLLECTION_TYPE 25  /* MultiPoint ADT */
#define SE_MULTISURFACE_TYPE       26  /* LineString ADT */
#define SE_MULTICURVE_TYPE         27  /* LineString ADT */
#define SE_MULTIPOINT_TYPE         28  /* MultiPoint ADT */
#define SE_MULTILINESTRING_TYPE    29  /* MultiLineString ADT */
#define SE_MULTIPOLYGON_TYPE       30  /* MultiPolygon ADT */
#define SE_GEOMETRY_TYPE           31  /* Geometry ADT */

/************************************************************
*** OLD ATTRIBUTE DATA TYPES (Depreciated)
************************************************************/
#define SE_SMALLINT_TYPE           1   /* 2-byte Integer */
#define SE_INTEGER_TYPE            2   /* 4-byte Integer */
#define SE_FLOAT_TYPE              3   /* 4-byte Float */
#define SE_DOUBLE_TYPE             4   /* 8-byte Float */

/************************************************************
*** CONSTANTS DEFINING LIMITS 
************************************************************/
#define SE_MAX_MESSAGE_LENGTH      512 /* MAXIMUM ERROR MESSAGE LENGTH */
#define SE_MAX_SQL_MESSAGE_LENGTH 4096 /* MAXIMUM SQL ERROR MESSAGE LENGTH */
#define SE_MAX_PATH_LEN            512 /* MAXIMUM FILE PATH NAME LENGTH */

#define SE_MAX_CONFIG_KEYWORD_LEN  32  /* MAXIMUM CONFIGURATION KEYWORD 
                                          LENGTH */
#define SE_MAX_CONFIG_STR_LEN     2048 /* MAXIMUM CONFIGURATION STRING LENGTH */
#define SE_MAX_PROP_NAME_LEN       32  /* MAXIMUM PROPERTY NAME LENGTH */
#define SE_MAX_PROP_VAL_LEN        512 /* MAXIMUM PROPERTY VALUE LENGTH */
#define SE_MAX_DESCRIPTION_LEN     64  /* MAXIMUM LAYER DESCRIPTION LENGTH */
#define SE_MAX_FEAT_CLASS_LEN      128 /* MAXIMUM FILEINFO FEATUE CLASS 
                                          DESCRIPTION LENGTH */

#define SE_MAX_COLUMN_LEN          32  /* MAXIMUM COLUMN NAME LENGTH */
#define SE_MAX_TABLE_LEN           160 /* MAXIMUM TABLE NAME LENGTH */
#define SE_MAX_SCHEMA_TABLE_LEN    30  /* MAXIMUN TABLE 'ONLY' NAME LENGTH */
#define SE_MAX_ALIAS_LEN           32  /* MAXIMUM TABLE ALIAS LENGTH */
#define SE_MAX_ENTITY_LEN          256 /* MAXIMUM ENTITY TYPE LENGTH */
#define SE_MAX_HINT_LEN            1024/* MAXIMUM DBMS HINT LENGTH */
#define SE_MAX_OWNER_LEN           32  /* MAXIMUM TABLE OWNER NAME LENGTH */
#define SE_MAX_INDEX_LEN           160 /* MAXIMUM INDEX NAME LENGTH */
#define SE_MAX_GROUP_LEN           26  /* MAXIMUM GROUP NAME LENGTH */
#define SE_MAX_COLUMNS             256 /* MAXIMUM NUMBER OF COLUMNS */
#define SE_MAX_ANNO_TEXT_LEN       255 /* MAXIMUM ANNOTATION TEXT LENGTH */
#define SE_MAX_VERSION_LEN         64  /* MAXIMUM VERSION NAME LENGTH */
#define SE_MAX_OSNAME_LEN          64  /* MAXIMUM OPERATING SYSTEM NAME LENGTH */
#define SE_MAX_OSVERSION_LEN       128 /* MAXIMUM OPERATING SYSTEM VERSION LENGTH */
#define SE_MAX_DBMSVERSION_LEN     128 /* MAXIMUM DATABASE VERSION LENGTH */
#define SE_MAX_VERSION_INPUT_LEN   62  /* MAXIMUM USER-SUPPLIED VERSION NAME
                                          LENGTH */
#define SE_MAX_OBJECT_NAME_LEN     160 /* MAXIMUM OBJECT NAME LENGTH */
#define SE_MAX_METADATA_CLASS_LEN  32  /* MAXIMUM CLASS NAME LENGTH */
#define SE_MAX_METADATA_PROPERTY_LEN 32/* MAXIMUM PROPERTY NAME LENGTH */
#define SE_MAX_METADATA_VALUE_LEN  255 /* MAXIMUM VALUE LENGTH */

#define SE_MAX_LOCATOR_PROPERTY_LEN 32 /* MAXIMUM PROPERTY NAME LENGTH */
#define SE_MAX_LOCATOR_VALUE_LEN   255 /* MAXIMUM VALUE LENGTH */

#define SE_MAX_SERVER_LEN          32  /* MAXIMUM SERVER NAME LENGTH */
#define SE_MAX_INSTANCE_LEN        32  /* MAXIMUM INSTANCE NAME LENGTH */
#define SE_MAX_PASSWORD_LEN        32  /* MAXIMUM PASSWORD NAME LENGTH */
#define SE_MAX_DATABASE_LEN        32  /* MAXIMUM DATABASE NAME LENGTH */

#define SE_MAX_SCL_CODESIZE        256 /* MAXIMUM SCL OBJECT CODE LENGTH */
#define SE_MAX_FUNCTION_LEN        32  /* MAXIMUM FUNCTION NAME LENGTH */
#define SE_MAX_KEYWORD_LEN         32  /* MAXIMUM DBMS RESERVED KEYWORD LENGTH */

#define SE_MAX_LOGFILE_NAME_LEN    64  /* MAXIMUM BASE LOGFILE NAME LENGTH */

#define SE_UUID_STRING_LEN         40  /* UUID STRING LENGTH + 1 Nil byte +
                                          3 bytes for alignment. */

#define SE_MAX_XML_INDEX_NAME_LEN  32  /* MAXIMUM XML INDEX NAME LENGTH */
#define SE_MAX_XML_TAG_NAME_LEN   256  /* MAXIMUM XML TAG NAME STRING LENGTH */

#define SE_MAX_SID_COLUMN_LEN      38  /* MAXIMUM LENGTH OF STATE_ID COLUMN */
#define SE_MAX_LIN_COLUMN_LEN      38  /* MAXIMUM LENGTH OF LINEAGE_NAME COLUMN */

#define SE_MAX_TRANSFORM_NAME_LEN 256  /* MAXIMUM LENGTH OF A TRANSFORM NAME */

/* CONSTANTS ALLOWING FOR FULLY QUALIFIED TABLE AND COLUMN NAMES */

#define SE_QUALIFIED_TABLE_NAME    (SE_MAX_DATABASE_LEN + SE_MAX_OWNER_LEN +\
                                    SE_MAX_TABLE_LEN + 2)
#define SE_QUALIFIED_COLUMN_LEN    (SE_QUALIFIED_TABLE_NAME + \
                                    SE_MAX_COLUMN_LEN + 1)
#define SE_QUALIFIED_VERSION_LEN   (SE_MAX_OWNER_LEN + SE_MAX_VERSION_LEN + 1)
#define SE_QUALIFIED_LOGFILE_NAME  (SE_MAX_DATABASE_LEN + SE_MAX_OWNER_LEN +\
                                    SE_MAX_LOGFILE_NAME_LEN + 2)
#define SE_QUALIFIED_OBJECT_NAME   (SE_MAX_DATABASE_LEN + SE_MAX_OWNER_LEN +\
                                    SE_MAX_OBJECT_NAME_LEN + 2)
#define SE_QUALIFIED_XML_INDEX_LEN (SE_MAX_XML_INDEX_NAME_LEN + \
                                     SE_MAX_OWNER_LEN + 1)

/************************************************************
*** Minimum gridsize for Layer 
************************************************************/
#define SE_MIN_GRIDSIZE        256 /* MINIMUM LAYER GRIDSIZE (system units) */

/************************************************************
*** ATTRIBUTE INDICATOR VALUES
************************************************************/
#define SE_IS_NULL_VALUE       1
#define SE_IS_NOT_NULL_VALUE   2

/************************************************************
*** LOG FILE DEFINES
************************************************************/
#define SE_INPUT_MODE              0
#define SE_OUTPUT_MODE             1
#define SE_EXTEND_MODE             2
#define SE_OUTPUT_NO_DELETE_MODE   3

#define SE_LOG_PERSISTENT          1
#define SE_LOG_TEMPORARY           2

#define SE_LOG_FOR_TABLE           1
#define SE_LOG_FOR_LAYER           2

#define SE_LOG_INTERSECT           1
#define SE_LOG_UNION               2
#define SE_LOG_DIFFERENCE          3
#define SE_LOG_SYMDIFF             4

typedef enum {
      SE_LOGFILE_DELETE_MODE_DEFER = 0,
      SE_LOGFILE_DELETE_MODE_IMMEDIATE
} SE_LOGFILE_DELETE_MODE;

/************************************************************
*** SPATIAL REFERENCE DEFINES
************************************************************/

#define SE_MAX_SPATIALREF_AUTHNAME_LEN 256
#define SE_MAX_SPATIALREF_SRTEXT_LEN 2048

typedef struct _SE_SpatialRef *SE_SPATIALREFINFO;

/************************************************************
*** ALLOWABLE SPATIAL INDEX TYPE DEFINES FOR LAYERS
*** NOTE: THEIR AVAILABILITY IS DBMS DEPENDENT. 
************************************************************/
#define  SE_SPATIALINDEX_MULTI_GRID        1
#define  SE_SPATIALINDEX_DBTUNE            0
#define  SE_SPATIALINDEX_NONE             -1
#define  SE_SPATIALINDEX_RTREE            -2
#define  SE_SPATIALINDEX_FIXED_QUADTREE   -3
#define  SE_SPATIALINDEX_HYBRID_QUADTREE  -4
#define  SE_SPATIALINDEX_UNKNOWN          -5

/************************************************************
*** SEARCH ORDERS
************************************************************/
#define     SE_ATTRIBUTE_FIRST  1   /* DO NOT USE SPATIAL INDEX */
#define     SE_SPATIAL_FIRST    2   /* USE SPATIAL INDEX */
#define     SE_OPTIMIZE         3   /* LET SDE DECIDE */

/************************************************************
*** QUERY TYPES
************************************************************/
#define  SE_QUERYTYPE_ATTRIBUTE_FIRST  1
#define  SE_QUERYTYPE_JFA              2 
#define  SE_QUERYTYPE_JSF              3 
#define  SE_QUERYTYPE_JSFA             4 
#define  SE_QUERYTYPE_V3               5 
#define  SE_MAX_QUERYTYPE              5

/************************************************************
*** CONSTANTS FOR SE_PTABLE_SNAP routine
************************************************************/
#define SE_SNAP2D      0
#define SE_SNAP3D      1

/************************************************************
*** INDIVIDUAL BIT-MASKS FOR STATISTICS OPERATIONS
************************************************************/
#define SE_MIN_STATS      0x0001
#define SE_AVERAGE_STATS  0x0002
#define SE_MAX_STATS      0x0004
#define SE_STD_DEV_STATS  0x0008
#define SE_COUNT_STATS    0x0010
#define SE_DISTINCT_STATS 0x0020
#define SE_BASIC_STATS    SE_MIN_STATS | SE_AVERAGE_STATS | SE_MAX_STATS | \
                          SE_STD_DEV_STATS | SE_COUNT_STATS
#define SE_ALL_STATS      SE_BASIC_STATS | SE_DISTINCT_STATS

/************************************************************
*** CONCURRENCY POLICIES
************************************************************/
#define SE_UNPROTECTED_POLICY  0
#define SE_ONE_THREAD_POLICY   1
#define SE_TRYLOCK_POLICY      2
#define SE_LOCK_POLICY         3

/********************************************************************
*** SPATIAL FILTER TYPES FOR SPATIAL CONSTRAINTS AND STABLE SEARCHES
*********************************************************************/
#define SE_SHAPE_FILTER  1
#define SE_ID_FILTER     2

/************************************************************
*** STABLE OPTIONS
************************************************************/
#define SE_DELETE_CURRENT (LONG)0

/************************************************/
/***  SDE ROWID pseudo-column -- Obsolete!!!! ***/
/***  Only present for backwards compatibity: ***/
/***  Use registered tables row ID's instead. ***/
/************************************************/
#define SE_ROW_ID   "SE_ROW_ID"

/**************************
*  Binary Conversion Enum *
**************************/

typedef enum
{
  SE_BINARY_CONVERSION_TO_LOB      = 1,
  SE_BINARY_CONVERSION_TO_LONGRAW  = 2
} SE_BINARY_CONVERSION;

/*******************************/
/***  Shape attribute names  ***/
/*******************************/
#define SE_SHAPE_ATTRIBUTE_NUMOFPTS   0
#define SE_SHAPE_ATTRIBUTE_ENTITY     1
#define SE_SHAPE_ATTRIBUTE_XMIN       2
#define SE_SHAPE_ATTRIBUTE_XMAX       3
#define SE_SHAPE_ATTRIBUTE_YMIN       4
#define SE_SHAPE_ATTRIBUTE_YMAX       5
#define SE_SHAPE_ATTRIBUTE_ZMIN       6
#define SE_SHAPE_ATTRIBUTE_ZMAX       7
#define SE_SHAPE_ATTRIBUTE_MMIN       8
#define SE_SHAPE_ATTRIBUTE_MMAX       9
#define SE_SHAPE_ATTRIBUTE_AREA      10
#define SE_SHAPE_ATTRIBUTE_LENGTH    11
#define SE_SHAPE_ATTRIBUTE_TEXT      12
#define SE_SHAPE_ATTRIBUTE_FID       13

/**********************************/
/*****   DBMS IDENTIFIERS *********/
/**********************************/
#define SE_DBMS_IS_UNKNOWN  -1
#define SE_DBMS_IS_OTHER     0
#define SE_DBMS_IS_ORACLE    1
#define SE_DBMS_IS_INFORMIX  2
#define SE_DBMS_IS_SYBASE    3
#define SE_DBMS_IS_DB2       4
#define SE_DBMS_IS_SQLSERVER 5
#define SE_DBMS_IS_ARCINFO   6
#define SE_DBMS_IS_IUS       7
#define SE_DBMS_IS_DB2_EXT   8
#define SE_DBMS_IS_ARCSERVER 9
#define SE_DBMS_IS_JET       10

/******************************/
/***  DBMS Properties  ***/
/******************************/
#define SE_DBMS_CAN_RENAME                      (1<<0)
#define SE_DBMS_CAN_ADD_COL                     (1<<1)
#define SE_DBMS_CAN_DROP_COL                    (1<<2)
#define SE_DBMS_OWNER_PREFIXES_TABLE            (1<<3)
#define SE_DBMS_IS_CASE_SENSITIVE               (1<<4)
#define SE_DBMS_SUPPORT_DELIMITED_IDENTIFIER    (1<<5)
#define SE_DBMS_IS_CASE_SENSITIVE_IN_COMPARISON (1<<6)
#define SE_DBMS_IS_USER_CASE_SENSITIVE          (1<<7)
#define SE_DBMS_IS_PASSWORD_CASE_SENSITIVE      (1<<8)

#define SE_DBMS_UNICODE_IN_ALL_CHAR             (1<<9)
#define SE_DBMS_UNICODE_IN_STRING_TYPE          (1<<10)
#define SE_DBMS_UNICODE_IN_CLOB_TYPE            (1<<11)
#define SE_DBMS_UNICODE_IN_OBJECT_NAMES         (1<<12)

#define SE_DBMS_CODEPAGE_IS_UTF8                (1<<13)
#define SE_DBMS_CODEPAGE_IS_UTF16               (1<<14)
#define SE_DBMS_CODEPAGE_IS_UCS2                (1<<15)

#define SE_DBMS_CHAR_TYPES_STORE_UTF8           (1<<16)
#define SE_DBMS_CHAR_TYPES_STORE_UTF16          (1<<17)
#define SE_DBMS_CHAR_TYPES_STORE_UCS2           (1<<18)

#define SE_DBMS_NCHAR_TYPES_STORE_UTF8          (1<<19)
#define SE_DBMS_NCHAR_TYPES_STORE_UTF16         (1<<20)
#define SE_DBMS_NCHAR_TYPES_STORE_UCS2          (1<<21)
#define SE_DBMS_CODEPAGE_IS_UNICODE \
                       (SE_DBMS_CODEPAGE_IS_UTF8 |\
                        SE_DBMS_CODEPAGE_IS_UTF16 |\
                        SE_DBMS_CODEPAGE_IS_UCS2)


/******* Lock type values for SE_TABLE_LOCK *******/
/*****************************************************/
#define SE_TABLE_SHARED_SCHEMA_LOCK   1
#define SE_TABLE_EXCLUSIVE_SCHEMA_LOCK   2

/****************************************************************************/
/***  INSTANCE MODES -- Returned in system_mode field of SE_INSTANCE_STATUS */
/****************************************************************************/
#define SE_INSTANCE_ACCEPTING     1
#define SE_INSTANCE_BLOCKING      2

/*****************************************************/
/******* Lock type values for SE_INSTANCE_LOCK *******/
/*****************************************************/
#define SE_INSTANCE_LAYER_READ_LOCK   0
#define SE_INSTANCE_LAYER_WRITE_LOCK  1
#define SE_INSTANCE_AREA_READ_LOCK    2
#define SE_INSTANCE_AREA_WRITE_LOCK   3
#define SE_INSTANCE_AUTO_LOCK         4

/************************************/
/***  SE_instance_control() options */
/************************************/
#define SE_CONTROL_INSTANCE_SHUTDOWN 1
#define SE_CONTROL_INSTANCE_PAUSE    2
#define SE_CONTROL_INSTANCE_RESUME   3
#define SE_CONTROL_INSTANCE_KILL     4
#define SE_CONTROL_INSTANCE_KILL_ALL 5
#define SE_CONTROL_INSTANCE_START    6

/****************************************/
/***  SE_ANNO text justification values */
/****************************************/
#define SE_ANNO_UPPER_LEFT    1
#define SE_ANNO_UPPER_CENTER  2
#define SE_ANNO_UPPER_RIGHT   3
#define SE_ANNO_CENTER_LEFT   4
#define SE_ANNO_CENTER_CENTER 5
#define SE_ANNO_CENTER_RIGHT  6
#define SE_ANNO_LOWER_LEFT    7
#define SE_ANNO_LOWER_CENTER  8
#define SE_ANNO_LOWER_RIGHT   9

/************************************/
/***  Registered Table Row ID Types */
/************************************/
#define SE_REGISTRATION_ROW_ID_COLUMN_TYPE_SDE   1
#define SE_REGISTRATION_ROW_ID_COLUMN_TYPE_USER  2
#define SE_REGISTRATION_ROW_ID_COLUMN_TYPE_NONE  3

/*********************************************************/
/***  SDE-maintained rowid columns allocation methods  ***/
/*********************************************************/
#define SE_REGISTRATION_ROW_ID_ALLOCATION_SINGLE 1
#define SE_REGISTRATION_ROW_ID_ALLOCATION_MANY   2

/************************************/
/***   Metadata Object Types      ***/
/************************************/
#define SE_METADATA_OBJECT_TYPE_TABLE   1
#define SE_METADATA_OBJECT_TYPE_LOCATOR 2
#define SE_METADATA_OBJECT_TYPE_XML_COLUMN 3

/************************************/
/***   Locator Status             ***/
/************************************/
#define SE_LOCATOR_TEMPLATE  0
#define SE_LOCATOR_VALIDATED 1
#define SE_LOCATOR_DEFINED   2

/*********************************************/
/***   External FileInfo Object Types      ***/
/*********************************************/
#define SE_FILEINFO_OBJECT_TYPE_EXPORT_FMT   1
#define SE_FILEINFO_OBJECT_TYPE_SHAPEFILE    2
#define SE_FILEINFO_OBJECT_TYPE_COVERAGE     3

/********************************/
/***  Version Reserved Names  ***/
/********************************/
#define SE_DEFAULT_VERSION_NAME  "DEFAULT"
#define SE_QUALIFIED_DEFAULT_VERSION_NAME "sde" "." SE_DEFAULT_VERSION_NAME

/******************************/
/***  Version Access Types  ***/
/******************************/
#define SE_VERSION_ACCESS_PUBLIC     0
#define SE_VERSION_ACCESS_PROTECTED  1
#define SE_VERSION_ACCESS_PRIVATE    2

/****************************/
/***  State Reserved Ids  ***/
/****************************/
#define SE_BASE_STATE_ID      (0)
#define SE_NULL_STATE_ID     (-1)
#define SE_DEFAULT_STATE_ID  (-2)

/*************************************/
/***  State Conflict Filter Types  ***/
/*************************************/
#define SE_STATE_DIFF_NOCHECK         0
#define SE_STATE_DIFF_NOCHANGE_UPDATE 1
#define SE_STATE_DIFF_NOCHANGE_DELETE 2
#define SE_STATE_DIFF_UPDATE_NOCHANGE 3
#define SE_STATE_DIFF_UPDATE_UPDATE   4
#define SE_STATE_DIFF_UPDATE_DELETE   5
#define SE_STATE_DIFF_INSERT          6
#define SE_STATE_DIFF_RESTORE         7
#define SE_STATE_DIFF_INSERT_RESTORE  8
#define SE_STATE_DIFF_UPDATE          9
#define SE_STATE_DIFF_DELETE          10

/*******************************************************/
/***  State Lock Types (for SE_INSTANCE_STATE_LOCK)  ***/
/*******************************************************/
#define SE_STATE_TREE_SHARED_LOCK     0
#define SE_STATE_TREE_EXCLUSIVE_LOCK  1
#define SE_STATE_SHARED_LOCK          2
#define SE_STATE_EXCLUSIVE_LOCK       3
#define SE_STATE_SHARED_AUTOLOCK      4
#define SE_STATE_EXCLUSIVE_AUTOLOCK   5

/********************************/
/***  Table Rowlocking Types  ***/
/********************************/
#define SE_ROWLOCKING_LOCK_ON_QUERY       (1)
#define SE_ROWLOCKING_LOCK_ON_INSERT      (1<<1)
#define SE_ROWLOCKING_LOCK_ON_UPDATE      (1<<2)
#define SE_ROWLOCKING_UNLOCK_ON_QUERY     (1<<3)
#define SE_ROWLOCKING_UNLOCK_ON_UPDATE    (1<<4)
#define SE_ROWLOCKING_FILTER_MY_LOCKS     (1<<5)
#define SE_ROWLOCKING_FILTER_OTHER_LOCKS  (1<<6)
#define SE_ROWLOCKING_FILTER_UNLOCKED     (1<<7)
#define SE_ROWLOCKING_LOCK_ONLY           (1<<8)

/****************************/
/***  Object Lock Types   ***/
/****************************/
#define SE_OBJECTLOCK_NO_LOCK_SET        (99)
#define SE_OBJECTLOCK_SHARED_LOCK         (0)
#define SE_OBJECTLOCK_EXCLUSIVE_LOCK      (1)
#define SE_OBJECTLOCK_EXCLUSIVE_AUTOLOCK  (2)

/*****************************/
/***  Version Lock Types   ***/
/*****************************/
#define SE_VERSION_SHARED_LOCK         (0)
#define SE_VERSION_EXCLUSIVE_LOCK      (1)
#define SE_VERSION_EXCLUSIVE_AUTOLOCK  (2)

/******************************/
/***  Trace Mode Types      ***/
/******************************/
#define SE_TRACE_API_BRIEF      (1<<0)
#define SE_TRACE_API_VERBOSE    (1<<1)
#define SE_TRACE_TIME_MINSEC    (1<<2)
#define SE_TRACE_TIME_HRMINSEC  (1<<3)
#define SE_TRACE_FLUSH          (1<<4)
#define SE_TRACE_CLIENT_SIDE    (1<<5)
#define SE_TRACE_SRVR_SIDE      (1<<6)

/******************************/
/***  XML TAG DATA TYPES    ***/
/******************************/
#define SE_XML_INDEX_STRING_TYPE 1 /* text XML index type. */
#define SE_XML_INDEX_DOUBLE_TYPE 2 /* numeric XML index type. */

/******************************/
/***  XML INDEX TYPES       ***/
/******************************/
#define SE_XML_INDEX_TEMPLATE   1
#define SE_XML_INDEX_DEFINITION 2
#define SE_XML_INDEX_AUTO       3
#define SE_XML_INDEX_AUTO_STRING  4

/***************************************/
/***  XML DOC PROPERTIES FOR QUERIES ***/
/***************************************/
#define SE_DOC_HAS_TAG_CONFLICTS 1

/*********************************/
/***  Raster Interleave Types  ***/
/*********************************/

typedef enum {
    SE_RASTER_INTERLEAVE_BIP,        /* interleave by pixel */  
    SE_RASTER_INTERLEAVE_BIL,        /* interleave by line */
    SE_RASTER_INTERLEAVE_BSQ         /* band sequential */
} SE_RASTER_INTERLEAVE_TYPE;

/*********************************/
/***   Interpolation Methods   ***/
/*********************************/

typedef enum {
    SE_INTERPOLATION_NONE,           /* no interpolation */
    SE_INTERPOLATION_NEAREST,        /* nearest-neighbor interpolation */
    SE_INTERPOLATION_BILINEAR,       /* bilinear interpolation */
    SE_INTERPOLATION_BICUBIC         /* bicubic interpolation */
} SE_INTERPOLATION_TYPE;

/********************************/
/*** Raster Callback Function ***/
/********************************/

typedef LONG (* SE_RASTER_PROC) (
    void              *user_data,
    void              **pixels,
    LONG              *pixels_length,
    void              **bitmask,
    LONG              *bitmask_length
);

/********************************/
/***    Bin Function Types    ***/
/********************************/

typedef enum {
    SE_BIN_FUNCTION_NONE = 0,
    SE_BIN_FUNCTION_AUTO,
    SE_BIN_FUNCTION_DIRECT,
    SE_BIN_FUNCTION_LINEAR,
    SE_BIN_FUNCTION_LOGARITHM,
    SE_BIN_FUNCTION_EXPLICIT
} SE_BIN_FUNCTION_TYPE;

/********************************/
/***  Raster Colormap Types   ***/
/********************************/

typedef enum {
    SE_COLORMAP_NONE = 0,
    SE_COLORMAP_RGB,
    SE_COLORMAP_RGBA
} SE_COLORMAP_TYPE;

/********************************/
/***  Colormap's Data Types   ***/
/********************************/

typedef enum {
    SE_COLORMAP_DATA_BYTE,
    SE_COLORMAP_DATA_SHORT
} SE_COLORMAP_DATA_TYPE;

/********************************/
/***    Raster Mosaic Mode    ***/
/********************************/

#define SE_MOSAIC_MODE_NONE    0
#define SE_MOSAIC_MODE_MERGE   1
#define SE_MOSAIC_MODE_DELETE  2

/***************************************************************************/
/***  function_id Constants(total 50 function constants). ***/
/***************************************************************************/
/* The string functions */
typedef enum {
   SE_DBMS_FUNCTION_UPPERCASE,       /* 0:Returns char in upper case */
   SE_DBMS_FUNCTION_LOWERCASE,       /* 1:Returns char in lower case */
   SE_DBMS_FUNCTION_CONCAT,          /* 2:Returns char1 concatenated with char2 */
   SE_DBMS_FUNCTION_ASCII,           /* 3:Returns decimal representation of char c */
   SE_DBMS_FUNCTION_LENGTH,          /* 4:Return length in CHAR */
   SE_DBMS_FUNCTION_LENGTHB,         /* 5:Returns length in bytes */
   SE_DBMS_FUNCTION_CHR,             /* 6:Returns the character of the binary equivalent */
   SE_DBMS_FUNCTION_LTRIM,           /* 7:remove spaces from the left */
   SE_DBMS_FUNCTION_RTRIM,           /* 8:remove trailing from the right */
   SE_DBMS_FUNCTION_SUBSTR,          /* 9:Returns a portion of char at M and N c long */
   SE_DBMS_FUNCTION_SUBSTRB,         /* 10:Returns a portion of byes at m and n bytes long */
   SE_DBMS_FUNCTION_SOUNDEX,         /* 11:Returns a char containing the phonetic representation of char2 */
   SE_DBMS_FUNCTION_TRANSLATE,       /* 12:Returns char with each char in from replaced by its corresponding char in to */
   SE_DBMS_FUNCTION_TRIM,            /* 13:strip the leading, trailing, * or both from the string */

   SE_DBMS_FUNCTION_CEIL,            /* 14:Returns smallest integer >= n */
   SE_DBMS_FUNCTION_FLOOR,           /* 15:Returns largest integer <= n */
   SE_DBMS_FUNCTION_ROUND,           /* 16:Returns n rounded to m place of n */
   SE_DBMS_FUNCTION_LN,              /* 17:Returns natural logarithm of n */
   SE_DBMS_FUNCTION_LOG10,           /* 18:Returns logarithm of base 10 */
   SE_DBMS_FUNCTION_LOG,             /* 19:Returns logarithm of base n */
   SE_DBMS_FUNCTION_MOD,             /* 20:Returns the reminder of m divided by n */
   SE_DBMS_FUNCTION_POWER,           /* 21:Returns the n power of m */
   SE_DBMS_FUNCTION_SIGN,            /* 22:Returns -1 for negative and 0 for zero and 1 for positive */
   SE_DBMS_FUNCTION_TRUNC,           /* 23:Returns n truncted to m decimal place */
   SE_DBMS_FUNCTION_SINH,            /* 24:Returns hyperbolic sine of x */
   SE_DBMS_FUNCTION_COSH,            /* 25:Returns hyperbolic cosine of x */
   SE_DBMS_FUNCTION_TANH,            /* 26:Returns hyperbolic tangent of x */
   SE_DBMS_FUNCTION_ASIN,            /* 27:Returns the arcsine of x */
   SE_DBMS_FUNCTION_ACOS,            /* 28:Returns the arccosine of x */
   SE_DBMS_FUNCTION_ATAN,            /* 29:Returns the arctangent of x */
   SE_DBMS_FUNCTION_HEX,             /* 30:Returns the hexadecimal representation of a */
   SE_DBMS_FUNCTION_SIN,             /* 31:Returns sine of x */
   SE_DBMS_FUNCTION_COS,             /* 32:Returns cosine  of x */
   SE_DBMS_FUNCTION_TAN,             /* 33:Returns tangent of x */
   SE_DBMS_FUNCTION_EXTRACT,         /* 34:Returns a numeric value of a date */ 
   SE_DBMS_FUNCTION_BITLEN,          /* 35:Returns the string length in bits */
   SE_DBMS_FUNCTION_POSITION,        /* 36:Returns the a numeric value indicates the the starting position of the search string in the source string */
   SE_DBMS_FUNCTION_ABS,             /* 37:Returns the absolute value of x */

   SE_DBMS_FUNCTION_VARIANCE,        /* 38:Returns variance of x */
   SE_DBMS_FUNCTION_STDDEV,          /* 39:Returns the standard deviation */
   SE_DBMS_FUNCTION_AVG,             /* 40:Returns the average value of n */
   SE_DBMS_FUNCTION_COUNT,           /* 41:Returns the number of rows in the query */
   SE_DBMS_FUNCTION_MAX,             /* 42:Returns the maximum value of expression */
   SE_DBMS_FUNCTION_MIN,             /* 43:Returns the minimum value of expression */
   SE_DBMS_FUNCTION_SUM,             /* 44:Returns the sum of values of n */

   SE_DBMS_FUNCTION_COALSCE,         /* 45:Returns the first NOT_NULL value */
   SE_DBMS_FUNCTION_CONVERT,         /* 46:The convert function  */
   SE_DBMS_FUNCTION_CAST,            /* 47:Converts one data type to another one */
   SE_DBMS_FUNCTION_USER             /* 48:Returns the current user name */
} SE_SQL_FUNCTION;        

/* SQL special characters for DBMSs */
typedef enum 
{
  SE_SQL_WILDCARD_MANYMATCH_CHAR = 49, /* always start from the total number of
                                          function constants */
  SE_SQL_WILDCARD_SINGLEMATCH_CHAR,
  SE_SQL_DELIMITED_CHAR_PREFIX,
  SE_SQL_DELIMITED_CHAR_SUFFIX,
  SE_SQL_DEFAULT_ESCAPE_CHAR_PREFIX,
  SE_SQL_DEFAULT_ESCAPE_CHAR_SUFFIX,
  SE_SQL_ESCAPE_CLAUSE_PREFIX,
  SE_SQL_ESCAPE_CLAUSE_SUFFIX
} SE_SQL_SPECIAL_CHARACTER;

/* Sublineage type */

typedef enum {
  SE_SUBLINEAGE_SOURCE,
  SE_SUBLINEAGE_DIFF,
  SE_SUBLINEAGE_PAST,
  SE_LINEAGE_SOURCE,
  SE_LINEAGE_DIFF,
  SE_LINEAGE_NONE
} SE_LINEAGE_TYPES;

/***************************************************************************/
/***  annotation alignment constants                                     ***/
/***************************************************************************/
#define SE_ANNO_ALIGN_DEFAULT   0
#define SE_ANNO_ALIGN_LEFT      1
#define SE_ANNO_ALIGN_RIGHT     2
#define SE_ANNO_ALIGN_CENTER    3
#define SE_ANNO_ALIGN_AUTOMATIC 4

/*****************************
*  Error log mode types      *
******************************/

#define SE_ERRLOG_NONE      0
#define SE_ERRLOG_TIME     (1)
#define SE_ERRLOG_SDEID    (1<<1)
#define SE_ERRLOG_CLIENT   (1<<2)

/***************************************************************************/
/***  Shape Data Types (Re)Definitions (see sg.h for full definition)    ***/
/***************************************************************************/
typedef SgSimpleShapePoint  SE_POINT;
typedef SgShapePoint        SE_SDEPOINT;
typedef SgShapeEnvelope     SE_ENVELOPE;
typedef SgCoordRef          SE_COORDREF;

typedef struct
{
    LFLOAT minz;
    LFLOAT minm;
    LFLOAT maxz;
    LFLOAT maxm;
} SE_ZMEXTENT;

/**************************/
/***  Shape Build Modes ***/
/**************************/
typedef enum {
  SE_Build_Polygons_From_All_Rings              = 0,
  SE_Build_Polygons_From_Clockwise_Rings        = 3,
  SE_Build_Polygons_From_CounterClockwise_Rings = 2,
  SE_Build_SimpleLines                          = 4,

  /* The following codes are obsolete, and are only included for backwards
     compatibility. */

  SE_Build_Clockwise_Polygons                   = 0,
  SE_Build_CounterClockwise_Polygons            = 1,
  SE_Build_Forward_Polygons                     = 2,
  SE_Build_Backward_Polygons                    = 3
} SE_BUILD_MODE;

/****************************/
/*** Shape Rotation Modes ***/
/****************************/
typedef enum {
  SE_DEFAULT_ROTATION,
  SE_LEFT_HAND_ROTATION,
  SE_RIGHT_HAND_ROTATION
} SE_ROTATION_TYPE;


/*******************************/
/***  Transformation Types   ***/
/*******************************/

typedef enum {
  SE_TRANSFORM_UNKNOWN = 0,
  SE_TRANSFORM_PLANER,
  SE_TRANSFORM_PROJECTIVE,
  SE_TRANSFORM_POLYNOMIAL,
  SE_TRANSFORM_CUSTOM
} SE_TRANSFORM_TYPE;

typedef enum {
  SE_POLYNOMIAL_1ST_ORDER = 0,
  SE_POLYNOMIAL_2ND_ORDER,
  SE_POLYNOMIAL_3RD_ORDER
} SE_POLYNOMIAL_TYPE;

/************************************************************
*** LOG FILE TYPES
************************************************************/
typedef int                 SE_LOG;
typedef struct _SE_LogFile  *SE_LOGINFO;

/************************************************************
*** SDE BLOB ATTRIBUTE STRUCTURE "SE_BLOB_INFO"
************************************************************/
typedef struct {
    LONG        blob_length;            /* LENGTH IN BYTES OF BLOB */
    CHAR        *blob_buffer;           /* LINEAR BUFFER OF BLOB DATA */
} SE_BLOB_INFO;

typedef struct {
    LONG        clob_length;            /* LENGTH IN BYTES OF CLOB */
    CHAR        *clob_buffer;           /* LINEAR BUFFER OF CLOB DATA */
} SE_CLOB_INFO;

typedef struct {
    LONG        nclob_length;           /* LENGTH IN BYTES OF NCLOB */ 
    SE_WCHAR    *nclob_buffer;          /* LINEAR BUFFER OF NCLOB DATA */
} SE_NCLOB_INFO;

/************************************************************
*** SDE COLUMN DEFINITION STRUCTURE "SE_COLUMN_DEF"
************************************************************/
typedef struct {
    CHAR  column_name[SE_MAX_COLUMN_LEN]; /* the column name */
    LONG  sde_type;                       /* the SDE data type */
    LONG  size;                           /* the size of the column values */
    SHORT decimal_digits;                 /* number of digits after decimal */
    BOOL  nulls_allowed;                  /* allow NULL values ? */
    SHORT row_id_type;                    /* column's use as table's row id */
} SE_COLUMN_DEF;


/************************************************************
*** SDE SSA INPUT DEFINITION STRUCTURE "SE_INPUT_DESC"
************************************************************/
typedef struct {
    LONG  sde_type;                       /* the SDE data type */
    LONG  size;                           /* the size of the input values */
} SE_INPUT_DESC;

/************************************************************
*** SDE SQL CONSTRUCTOR
************************************************************/
typedef struct {
    LONG       num_tables;    /* number of tables */
    CHAR       **tables;      /* table names */
    CHAR       *where;        /* where clause */
} SE_SQL_CONSTRUCT;

/************************************************************
*** SDE INDEX DESCRIPTION STRUCTURE "SE_INDEX_DEF"
************************************************************/
typedef struct {
    SHORT num_columns;                    /* number of columns */
    CHAR  **column_name;                  /* the column name */
    CHAR  index_name[SE_MAX_COLUMN_LEN];   /* the index name */
    BOOL  unique;                         /* unique index */
    BOOL  *ascending;                      /* ascending order */
} SE_INDEX_DEF;

/************************************************************
*** SDE POINT TABLE STRUCTURES
************************************************************/
typedef struct _SE_PointTable *SE_PTABLE;
typedef struct
{
    LFLOAT  x, y, z;
    ULONG   mask;
} SE_SNAPPED_POINT;

/************************************************************
*** SDE RELEASE/VERSION STRUCTURE
************************************************************/
typedef struct
{
    LONG    major;             /* Major release    */
    LONG    minor;             /* Minor release    */
    LONG    bug;               /* Bug version      */
    CHAR    desc[96];          /* Description      */
    LONG    release;           /* Release Number   */
    LONG    rel_low_supported; /* Lowest Release supported */
}   SE_RELEASE;

/************************************************************
*** SDE SHAPE HANDLE
************************************************************/
typedef struct _SE_ShapeRecord *SE_SHAPE;

/************************************************************
*** SDE ANNOTATION HANDLE
************************************************************/
typedef struct _SE_AnnoRecord *SE_ANNO;

/************************************************************
*** SDE EXTERNAL DATA FILE HANDLE 
************************************************************/
typedef struct _SE_ExternalFileInfo *SE_FILEINFO;

/************************************************************
*** SDE LAYER HANDLE
************************************************************/
typedef struct _SE_LayerRecord *SE_LAYERINFO;

/************************************************************
*** SDE METADATA HANDLE
************************************************************/
typedef struct _SE_MetaData *SE_METADATAINFO;

/************************************************************
*** SDE REGISTRATION HANDLE
************************************************************/
typedef struct _SE_Registration *SE_REGINFO;

/************************************************************
*** SDE VERSION HANDLE
************************************************************/
typedef struct _SE_VersionRecord *SE_VERSIONINFO;

/************************************************************
*** SDE STATE HANDLE
************************************************************/
typedef struct _SE_StateRecord *SE_STATEINFO;

/************************************************************
*** SDE LOCATOR HANDLE
************************************************************/
typedef struct _SE_Locator *SE_LOCATORINFO;

/************************************************************
*** SDE OBJECTLOCK HANDLE
************************************************************/
typedef struct _SE_ObjectLock *SE_OBJECTLOCKINFO;

/************************************************************
*** SDE CONNECTION HANDLE
************************************************************/
typedef struct _SE_ClientRecord *SE_CONNECTION;

/************************************************************
*** SDE STREAM HANDLE
************************************************************/
typedef struct _SE_StreamRecord *SE_STREAM;

/************************************************************
*** SDE UUID GENERATOR HANDLE
************************************************************/
typedef struct _SE_UUIDsysRecord *SE_UUIDGENERATOR;

/************************************************************
*** SDE XML TAG HANDLE
************************************************************/
typedef struct _SE_XmlTagInfo *SE_XMLTAGINFO;

/************************************************************
*** SDE XML INDEX HANDLE
************************************************************/
typedef struct _SE_XmlIndexInfo *SE_XMLINDEXINFO;

/************************************************************
*** SDE XML COLUMN HANDLE
************************************************************/
typedef struct _SE_XmlColumnInfo *SE_XMLCOLUMNINFO;

/************************************************************
*** SDE XML DOCUMENT HANDLE
************************************************************/
typedef struct _SE_XmlDoc       *SE_XMLDOC;

/************************************************************
*** SDE REGISTERED COLUMN HANDLE
************************************************************/
typedef struct _SE_RegisteredColumn *SE_COLUMNINFO;

/************************************************************
*** SDE SERVER INFORMATION HANDLE
************************************************************/
typedef struct _SE_ServerinfoRecord *SE_SERVERINFO;

/************************************************************
*** SDE QUERY HANDLE
************************************************************/
typedef struct _SE_QueryInfo         *SE_QUERYINFO;

/************************************************************
*** SDE TRANSFORM HANDLE
************************************************************/
typedef struct _SE_TransformRecord   *SE_TRANSFORMINFO;

/************************************************************
*** SDE SPATIAL FILTER STRUCTURE
************************************************************/
typedef struct {
  CHAR   table[SE_QUALIFIED_TABLE_NAME];    /* the spatial table name */
  CHAR   column[SE_MAX_COLUMN_LEN];         /* the spatial column name */
  LONG   filter_type;                       /* the type of spatial filter */
  union
  {
    SE_SHAPE    shape;                      /* a shape object */
    struct
    {
      LONG  id;                             /* A SDE_ROW_ID id for a shape */
      CHAR  table[SE_QUALIFIED_TABLE_NAME]; /* The shape's spatial table */
    } id;
  } filter;

  LONG  method;                            /* the search method to satisfy */
  BOOL  truth;         /* TRUE to pass the test, FALSE if it must NOT pass */
  char  *cbm_source ;                   /* set ONLY if the method is SM_CBM */
  UCHAR *cbm_object_code ;                      /* internal system use only */
} SE_FILTER;

/************************************************************
*** SDE STREAM SPECIFICATION
************************************************************/
typedef struct {
    LONG  min_size;            /* minimum size of buffer */
    LONG  max_size;            /* total size of buffer */
    LONG  min_objects;         /* minimum number of objects to put in buffer */
    LONG  max_array_size;      /* maximum number of elements per array */
    LONG  attribute_bytes;     /* attribute array buffer size */
    LONG  shape_point_bytes;   /* shape geometry array buffer size */
    LONG  blob_bytes;          /* obsolete as of ArcSDE 8.0.2 */
    LONG  max_bytes_per_blob;  /* obsolete as of ArcSDE 8.0.2 */
    LONG  stream_pool_size;    /* minimum # of streams to keep in the pool */
    LONG  raster_buf_size;     /* raster buffer size */
} SE_STREAM_SPEC;

/* Stream info structure passed to SSA at initialization time. */
typedef struct _SE_StreamInfo {
  SE_STREAM_SPEC   stream_spec;        /* Stream settings. */
  SE_LOG           logfile;            /* Output logfile handle. */
  BOOL             logfile_only;       /* Don't return rows, only log rows. */
  LONG             rowlock_action;     /* Automatic row locking rule. */
  const SE_FILTER  *spatial_filters;   /* Current spatial filters. */
  SHORT            num_filters;        /* Number of spatial filters. */
  BOOL             buffered_write;     /* Buffered I/O on or off. */
  LONG             state_id;           /* Current state id. */
  LONG             difference_id;      /* Current difference id. */
  LONG             difference_type;    /* Current difference type. */
} SE_STREAM_INFO;

/************************************************************
*** SDE STATISTICS STRUCTURES
************************************************************/
typedef struct {
    LONG        freq;          /* frequency of value */
    union {
        CHAR      *str_val;    /* SE_STRING_TYPE value */
        LONG      int_val;     /* SE_INTEGER_TYPE value */
        LFLOAT    double_val;  /* SE_DOUBLE_TYPE value */
        struct tm date_val;    /* SE_DATE_TYPE value */
        SE_WCHAR  *wstr_val;   /* SE_NSTRING_TYPE value */
    }uval;
}  SE_VALUE;

typedef struct {
    LONG        num_distinct;  /* number of distinct values */
    LONG        type;          /* value type */
    SE_VALUE    *values;       /* array of counts and union'ed values */
}  SE_DISTINCT;

typedef struct {
    LONG        count;         /* number of rows */
    LFLOAT      min;           /* minimum value */
    LFLOAT      average;       /* average value */
    LFLOAT      max;           /* maximum value */
    LFLOAT      std_dev;       /* standard deviation */
    SE_DISTINCT *distinct;     /* distinct info */
}  SE_STATS;

/************************************************************
*** SDE ERROR STRUCTURE
************************************************************/
typedef struct {
    LONG sde_error;                          /* SDE error code */
    LONG ext_error;                          /* DBMS or OS errno code */
    CHAR err_msg1[SE_MAX_MESSAGE_LENGTH];    /* DBMS or SE_error_get_string
                                                msg */
    CHAR err_msg2[SE_MAX_SQL_MESSAGE_LENGTH];/* Second DBMS error, if
                                                applicable */
} SE_ERROR;

/************************************************************
*** SDE FEATURE TABLE STRUCTURES
************************************************************/
typedef struct _SE_STableRec *SE_STABLE;

/************************************************************
*** SE_layer_statistics STRUCTURES
************************************************************/
typedef struct {
  LONG     features;            /* Features indexed by this grid level. */
  LONG     indexRecords;        /* Index records in this grid level. */
  LONG     groupCounts[8];      /* Index rec count by group: <=4, >4, >10, >25,
                                                      >50, >100, >250, >500. */
  LONG     maxFPG;              /* Maximum number of features per grid cell. */
  LONG     gridCells;           /* # of grid cells in this level. */
  LONG     featuresInside1;     /* # of features wholly inside one grid cell. */
} SE_GRID_STATS;

typedef struct {
  CHAR          table[SE_QUALIFIED_TABLE_NAME]; /* Spatial table. */
  CHAR          column[SE_MAX_COLUMN_LEN];      /* Spatial column. */
  LONG          nGrids;                         /* # of spatial index grids. */
  SE_GRID_STATS grids[3];                       /* Individual grid stats. */
} SE_SI_STATS;

typedef struct {                 /*** Layer statistics structure. ***/
   LONG        layer_id;           /* Layer id. */
   LONG        NILs;               /* # of Nil shapes in layer. */
   LONG        POINTs,MultiPOINTs; /* # of Point and Multipoints in layer. */
   LONG        LINEs,MultiLINEs;   /* # of Lines & Multilines in layer. */
   LONG        SIMPLE_LINEs,MultiSIMPLE_LINEs; /* # of Simple Lines &
                                                  Simple Multilines. */
   LONG        AREAs,MultiAREAs;   /* # of Area and Multiareas in layer. */
   LONG        TotalFeatures;      /* Total # of shapes in layer. */
   SE_ENVELOPE bounds;             /* Layer extrema. */
   LONG        lastModified;       /* POSIX time_t date last modified.*/
   LONG        minFid,maxFid;      /* Minimum and maximum IDs in layer. */
   LONG        minPoints,maxPoints;/* Min/max # of pts in layer shapes. */
   LFLOAT      minArea,maxArea;    /* Min and max area shape areas. */
   LFLOAT      minLength,maxLength;/* Min and max linear shape lengths. */
   LFLOAT      averagePoints;      /* Average number of points/shape. */
   LFLOAT      averageArea;        /* Average area/shape. */
   LFLOAT      averageLength;      /* Average length/shape. */
} SE_LAYER_STATS;

/************************************************************
*** SDE LAYER LOCKS STRUCTURES
************************************************************/
typedef struct {
   CHAR          username[SE_MAX_OWNER_LEN + 4];
   LONG          lock_type;
   SE_ENVELOPE   bounds;
} SE_LAYER_LOCKS;

/************************************************************
*** SDE TABLE LOCKS STRUCTURES
************************************************************/
typedef struct {
   CHAR          username[SE_MAX_OWNER_LEN + 4];
   LONG          lock_type;
} SE_TABLE_LOCK;

/************************************************************
*** SDE VERSION LOCK STRUCTURES
************************************************************/
typedef struct {
   CHAR          username[SE_MAX_OWNER_LEN + 4];
   LONG          lock_mode;
} SE_VERSION_LOCK;

/************************************************************
*** SDE INSTANCE STRUCTURES
************************************************************/
typedef struct {
  SE_RELEASE   version;     /* Release version of specified instance.       */
  LONG         connections; /* Number of current connections to SDE on node.*/
  LONG         system_mode; /* Accepting connections or blocking.           */
} SE_INSTANCE_STATUS;

typedef struct {
    LONG svrpid;                           /* Forked Server Task pid */
    LONG cstime;                           /* Connection Start time */
    BOOL xdr_needed;                       /* Use XDR Boolean */
    CHAR sysname[SE_MAX_OWNER_LEN + 1];    /* Client Operating System  Name */
    CHAR nodename[SE_MAX_OWNER_LEN + 1];   /* Client Host Node Name */
    CHAR username[SE_MAX_OWNER_LEN + 1];   /* User Name */
} SE_INSTANCE_USER;

/* For future developments, please do not use the structure
   SE_INSTANCE_CONFIG and API SE_instance_configuration() for
   instance/server configuration info. They are provided only for
   backward compatibility and will be deprecated for the post
   9.0 releases. Instead, please use SE_SERVERINFO structure
   and SE_instance_serverconfig_get_info() API respectively. */

typedef struct {
        LONG max_connections;
        LONG max_locks;
        LONG max_state_locks;
        LONG max_table_locks;
        LONG max_object_locks;
        LONG child_timeout;
        LONG min_net_block_size;
        LONG max_net_block_size;
        LONG min_net_obj_count;
        LONG max_mem_dissolve;
        LONG max_blob_size;
        LONG max_mem_blob;
        LONG auto_commit_freq;
        LONG max_init_feats;
        LONG max_distinct;
        LONG max_streams;
        LONG stream_pool_size;
        LONG max_layers;
        LONG max_registrations;
        LONG max_rastercolumns;
        LONG shape_point_buf_size;
        LONG attribute_buf_size;
        LONG blob_buf_size;
        LONG raster_buf_size;
        LONG max_array_size;
        LONG max_array_bytes;
        LONG max_time_diff;
        CHAR home_path[SE_MAX_PATH_LEN];        /* PATH TO SDE HOME DIR */
        CHAR log_path[SE_MAX_PATH_LEN];         /* PATH TO SDE LOG FILE DIR */
        CHAR tmp_path[SE_MAX_PATH_LEN];         /* PATH TO SDE TEMP FILE DIR */
        LONG dbms_id;                           /* Underlying DBMS ID. */ 
        LONG dbms_properties;                   /* DBMS properties. */ 
        LONG client_count;                      /* Connection count */
        BOOL state_caching;
        BOOL tcp_keepalive;
        BOOL instance_read_only;
        LONG default_precision;
        BOOL state_autolocking;
} SE_INSTANCE_CONFIG;

typedef struct {
    LONG    pid;
    LONG    rcount;     /* TOT # READS BY PROCESS */
    LONG    wcount;     /* TOT # WRITES BY PROCESS */
    LONG    opcount;    /* TOT # F OPERATIONS BY PROCESS */
    LONG    numlocks;   /* TOT # F LOCKS HELD BY THIS PID */
    LONG    fb_partial; /* TOT # F PARTIAL SHAPES SHIPPED BY THIS PROCESS */
    LONG    fb_count;   /* TOT # F BUFFERS LOADED BY THIS PROCESS */
    LONG    fb_fcount;  /* TOT # F SHAPES BUFFERED BY THIS PROCESS */
    LONG    fb_kbytes;  /* TOT # F 1K BYTES BUFFERED DATA BY THIS PROCESS */
} SE_INSTANCE_STATS;

typedef struct {
    LONG        pid;    
    SHORT       layer_id;
    LONG        lock_type;
} SE_INSTANCE_LOCK;

typedef struct _SE_InstanceStateLock {
  LONG   pid;       /* Gsrvr process id that holds this lock. */
  LONG   state_id;  /* State being locked. */
  SHORT  lock_type; /* Shared, exclusive or table. */
} SE_INSTANCE_STATE_LOCK;

typedef struct _SE_InstanceTableLock {
  LONG   pid;       /* Gsrvr process id that holds this lock. */
  LONG   registration_id;  /* table being locked. */
  SHORT  lock_type; /* Shared, exclusive or table. */
} SE_INSTANCE_TABLE_LOCK;

typedef struct _SE_InstanceVersionLock {
  LONG   pid;         /* Gsrvr process id that holds this lock. */
  LONG   version_id;  /* Version being locked. */
  SHORT  lock_mode;   /* Shared or exclusive. */
} SE_INSTANCE_VERSION_LOCK;

/************************************************************
*** Struct to receive shape comparison info.
************************************************************/
typedef struct {
        LONG    primary_entity_type ;
        LONG    secondary_entity_type ;
        LONG    mask ;
        LONG    sectdims[3][3] ;
} SE_CBM_INFO ;

/************************************************************
*** Struct to receive dbtune table error data.
************************************************************/
typedef struct {
  CHAR    keyword[SE_MAX_CONFIG_KEYWORD_LEN];
  CHAR    parameter_name[SE_MAX_CONFIG_KEYWORD_LEN];
  CHAR    config_string[SE_MAX_CONFIG_STR_LEN];
} SE_DBTUNE;

/************************************************************
*** Struct to receive server_config table error data.
************************************************************/

typedef struct {
    CHAR prop_name [SE_MAX_PROP_NAME_LEN];
    CHAR char_prop_value[SE_MAX_PROP_VAL_LEN];
    LONG num_prop_value;
} SE_SVR_CONFIG_ERR;




/*****************************************************************************
**  Spatial Database Engine API Prototypes
**
*****************************************************************************/
#ifdef WIN32
#define SDEAPI __stdcall
#else
#define SDEAPI
#endif

/*
 * ==========================================================================
 *
 * THE FOLLOWING FUNCTIONS ARE FOR PUBLIC USE.
 *
 * ==========================================================================
 */

/* Annotation object functions */

extern LONG SDEAPI SE_anno_create             (SE_ANNO        *anno);
extern LONG SDEAPI SE_anno_duplicate(          const SE_ANNO  src_anno, 
                                               SE_ANNO        tgt_anno);
extern void SDEAPI SE_anno_free               (SE_ANNO        anno);
extern LONG SDEAPI SE_anno_get_alignment      (const SE_ANNO  anno,
                                               LONG *alignment);
extern LONG SDEAPI SE_anno_get_justification  (const SE_ANNO  anno,
                                               LONG           *justification);
extern LONG SDEAPI SE_anno_get_leader         (const SE_ANNO  anno,
                                               SE_SHAPE       leader);
extern LONG SDEAPI SE_anno_get_level          (const SE_ANNO  anno,
                                               LONG           *level);
extern LONG SDEAPI SE_anno_get_offset         (const SE_ANNO  anno,
                                               LFLOAT         *x_offset,
                                               LFLOAT         *y_offset);
extern LONG SDEAPI SE_anno_get_placement      (const SE_ANNO  anno,
                                               SE_SHAPE       placement);
extern LONG SDEAPI SE_anno_get_symbol         (const SE_ANNO  anno,
                                               LONG           *symbol);
extern LONG SDEAPI SE_anno_get_text           (const SE_ANNO  anno,
                                               CHAR           *text);
extern LONG SDEAPI SE_anno_get_text_size      (const SE_ANNO  anno,
                                               LFLOAT         *height,
                                               LFLOAT         *gap_ratio);
extern LONG SDEAPI SE_anno_set_alignment      (SE_ANNO        anno,
                                               const LONG     alignment);
extern LONG SDEAPI SE_anno_set_justification  (SE_ANNO        anno,
                                               LONG           justification);
extern LONG SDEAPI SE_anno_set_leader         (SE_ANNO        anno,
                                               const SE_SHAPE leader);
extern LONG SDEAPI SE_anno_set_level          (SE_ANNO        anno,
                                               LONG           level);
extern LONG SDEAPI SE_anno_set_offset         (SE_ANNO        anno,
                                               LFLOAT         x_offset,
                                               LFLOAT         y_offset);
extern LONG SDEAPI SE_anno_set_placement      (SE_ANNO        anno,
                                               const SE_SHAPE placement);
extern LONG SDEAPI SE_anno_set_symbol         (SE_ANNO        anno,
                                               LONG           symbol);
extern LONG SDEAPI SE_anno_set_text           (SE_ANNO        anno,
                                               const CHAR     *text);
extern LONG SDEAPI SE_anno_set_text_size      (SE_ANNO        anno,
                                               LFLOAT         height,
                                               LFLOAT         gap_ratio);

/* Blob object function */

extern void SDEAPI SE_blob_free (SE_BLOB_INFO  *blob);
extern void SDEAPI SE_clob_free (SE_CLOB_INFO  *clob);
extern void SDEAPI SE_nclob_free(SE_NCLOB_INFO *nclob);

/* Registered Column object functions */

extern LONG SDEAPI SE_columninfo_create       (SE_COLUMNINFO        *column);
extern LONG SDEAPI SE_columninfo_duplicate    (const SE_COLUMNINFO  src_column,
                                               SE_COLUMNINFO        tgt_column);
extern void SDEAPI SE_columninfo_free         (SE_COLUMNINFO        column);

extern BOOL SDEAPI SE_columninfo_allows_nulls (const SE_COLUMNINFO  column);
extern LONG SDEAPI SE_columninfo_get_decimal_digits 
                                          (const SE_COLUMNINFO  column,
                                           LONG                 *decimal_digits);
extern LONG SDEAPI SE_columninfo_get_description 
                                             (const SE_COLUMNINFO  column,
                                              CHAR                 *description);
extern LONG SDEAPI SE_columninfo_get_object_id   
                                             (const SE_COLUMNINFO  column,
                                              LONG                 *object_id);
extern LONG SDEAPI SE_columninfo_get_name    (const SE_COLUMNINFO  column,
                                              CHAR                 *name);
extern LONG SDEAPI SE_columninfo_get_rowid_type  
                                             (const SE_COLUMNINFO  column,
                                              LONG                 *rowid_type);
extern LONG SDEAPI SE_columninfo_get_size    (const SE_COLUMNINFO  column,
                                              LONG                 *size);
extern LONG SDEAPI SE_columninfo_get_table_name
                                             (const SE_COLUMNINFO  column,
                                              CHAR                 *table_name);
extern LONG SDEAPI SE_columninfo_get_type    (const SE_COLUMNINFO  column,
                                              LONG                 *sde_type);

extern LONG SDEAPI SE_columninfo_set_allows_nulls 
                                               (SE_COLUMNINFO    column,
                                                BOOL             allows_nulls);
extern LONG SDEAPI SE_columninfo_set_description 
                                               (SE_COLUMNINFO      column,
                                                const CHAR         *description);
extern LONG SDEAPI SE_columninfo_set_type      (SE_COLUMNINFO        column,
                                                LONG                 type);

/* Connection object functions */

extern LONG SDEAPI SE_connection_commit_transaction
                                              (SE_CONNECTION    connection);
extern LONG SDEAPI SE_connection_create       (const CHAR       *server,
                                               const CHAR       *instance,
                                               const CHAR       *database,
                                               const CHAR       *username,
                                               const CHAR       *password,
                                               SE_ERROR         *error,
                                               SE_CONNECTION    *connection);
extern LONG SDEAPI SE_connection_delete_gcdrule_file
                                              (SE_CONNECTION connection,
                                               const CHAR *filename);
extern LONG SDEAPI SE_connection_disable_tlm_check (SE_CONNECTION  handle);
extern LONG SDEAPI SE_connection_enable_tlm_check  (SE_CONNECTION  handle);
extern LONG SDEAPI SE_connection_export_dbtune(SE_CONNECTION    connection,
                                               const CHAR  *dbtune_file);
extern LONG SDEAPI SE_connection_export_gcdrule_file
                                              (SE_CONNECTION handle,
                                               const CHAR *filename,
                                               const CHAR *directory,
                                               BOOL force_overwrite);
extern LONG SDEAPI SE_connection_free_all_locks  
                                              (SE_CONNECTION    connection);
extern void SDEAPI SE_connection_free         (SE_CONNECTION    connection);
extern void SDEAPI SE_connection_free_keyword_info (LONG keyword_count,
                                                    CHAR **keyword_list);
extern LONG SDEAPI SE_connection_get_admin_database
                                              (SE_CONNECTION    connection,
                                               CHAR            *admin_database);
extern LONG SDEAPI SE_connection_get_database (SE_CONNECTION    connection,
                                               CHAR             *database);
extern LONG SDEAPI SE_connection_get_default_database
                                              (SE_CONNECTION    connection,
                                               CHAR            *default_database);
extern LONG SDEAPI SE_connection_get_dbms_info
                                              (SE_CONNECTION    connection,
                                               LONG             *dbms_id,
                                               LONG         *dbms_properties);
extern LONG SDEAPI SE_connection_get_ext_error
                                              (SE_CONNECTION    connection,
                                               SE_ERROR         *error);
extern LONG SDEAPI SE_connection_get_instance_layerlocks
                                              (SE_CONNECTION    handle,
                                               SE_INSTANCE_LOCK **lock_list_addr,
                                               LONG             *lock_count_addr);
extern LONG SDEAPI SE_connection_get_instance_name
                                              (SE_CONNECTION    handle,
                                               CHAR           *instance_name);
extern LONG SDEAPI SE_connection_get_instance_objectlocks
                                              (SE_CONNECTION     handle,
                                               SE_OBJECTLOCKINFO **lock_list_addr,
                                               LONG              *lock_count_addr);
extern LONG SDEAPI SE_connection_get_instance_statelocks
                                              (SE_CONNECTION          handle,
                                            SE_INSTANCE_STATE_LOCK **lock_list_addr,
                                            LONG                   *lock_count_addr);
extern LONG SDEAPI SE_connection_get_instance_statistics
                                              (SE_CONNECTION     handle,
                                               SE_INSTANCE_STATS **stats_list_addr,
                                               LONG              *stats_count_addr);
extern LONG SDEAPI SE_connection_get_instance_status
                                              (SE_CONNECTION      handle,
                                               SE_INSTANCE_STATUS *status);
extern LONG SDEAPI SE_connection_get_instance_tablelocks
                                              (SE_CONNECTION          handle,
                                               SE_INSTANCE_TABLE_LOCK **lock_list_addr,
                                               LONG                   *lock_count_addr);
extern LONG SDEAPI SE_connection_get_instance_users
                                              (SE_CONNECTION     handle,
                                               SE_INSTANCE_USER  **user_list_addr,
                                               LONG              *user_count_addr);
extern LONG SDEAPI SE_connection_get_instance_versionlocks
                                              (SE_CONNECTION            handle,
                                               SE_INSTANCE_VERSION_LOCK **lock_list_addr,
                                               LONG                     *lock_count_addr);
extern LONG SDEAPI SE_connection_get_release  (SE_CONNECTION    connection,
                                               SE_RELEASE       *rls_version);
extern LONG SDEAPI SE_connection_get_server_name
                                              (SE_CONNECTION    handle,
                                               CHAR             *server_name);
extern LONG SDEAPI SE_connection_get_server_time 
                                              (SE_CONNECTION    connection);
extern LONG SDEAPI SE_connection_get_sql_info
                                              (SE_CONNECTION    connection,
                                               LONG             sql_id,
                                               CHAR            *sql_name);
extern LONG SDEAPI SE_connection_get_keyword_info(
                                               SE_CONNECTION handle,
                                               LONG *keyword_count,
                                               CHAR ***keyword_list);
extern LONG SDEAPI SE_connection_get_stream_spec
                                              (SE_CONNECTION    connection,
                                               SE_STREAM_SPEC *spec);
extern LONG SDEAPI SE_connection_get_user_name
                                              (SE_CONNECTION    handle,
                                               CHAR             *user_name);
extern LONG SDEAPI SE_connection_get_sdedba_name
                                              (SE_CONNECTION    handle,
                                               CHAR             *user_name);
extern LONG SDEAPI SE_connection_get_transaction_autocommit
                                              (SE_CONNECTION    handle,
                                               LONG             *interval);
extern LONG SDEAPI SE_connection_import_dbtune(SE_CONNECTION    handle,
                                               const CHAR  *dbtune_file,
                                               SE_DBTUNE   *dbtune_error_data);
extern LONG SDEAPI SE_connection_import_gcdrule_file
                                              (SE_CONNECTION connection,
                                               const CHAR *filename,
                                               BOOL force_overwrite);
extern LONG SDEAPI SE_connection_instance_control
                                              (SE_CONNECTION handle,
                                               LONG          option);
extern LONG SDEAPI SE_connection_rollback_transaction
                                              (SE_CONNECTION    connection);
extern LONG SDEAPI SE_connection_set_concurrency 
                                              (SE_CONNECTION    connection,
                                               LONG             policy);
extern LONG SDEAPI SE_connection_set_stream_spec 
                                              (SE_CONNECTION    connection,
                                               const SE_STREAM_SPEC *spec);
extern LONG SDEAPI SE_connection_set_transaction_autocommit 
                                              (SE_CONNECTION    connection,
                                               LONG             interval);
extern LONG SDEAPI SE_connection_start_transaction 
                                              (SE_CONNECTION    connection);
extern LONG SDEAPI SE_connection_test_server  (SE_CONNECTION    connection,
                                               time_t       round_trip_interval);

/* Coordinate reference object functions */

extern LONG SDEAPI SE_coordref_create      (SE_COORDREF *coordref);
extern void SDEAPI SE_coordref_free        (SE_COORDREF  coordref);
extern LONG SDEAPI SE_coordref_duplicate   (SE_COORDREF  src_ref, 
                                            SE_COORDREF  tgt_ref);
extern LONG SDEAPI SE_coordref_get_coordsys(SE_COORDREF  coordref, 
                                            PE_COORDSYS *cs);
extern LONG SDEAPI SE_coordref_get_description    (SE_COORDREF  coordref, 
                                                   CHAR        *description);
extern LONG SDEAPI SE_coordref_get_id             (SE_COORDREF  coordref, 
                                                   LONG        *coordsys_id);
extern LONG SDEAPI SE_coordref_get_m              (SE_COORDREF  coordref, 
                                                   LFLOAT      *falsem, 
                                                   LFLOAT      *munits);
extern LONG SDEAPI SE_coordref_get_m_range        (SE_COORDREF  coordref, 
                                                   LFLOAT      *min_value, 
                                                   LFLOAT      *max_value);
extern LONG SDEAPI SE_coordref_get_precision      (SE_COORDREF  coordref, 
                                                   LONG        *precision);
extern LONG SDEAPI SE_coordref_get_srid           (SE_COORDREF  coordref, 
                                                   LONG        *srid);
extern LONG SDEAPI SE_coordref_get_xy             (SE_COORDREF  coordref, 
                                                   LFLOAT      *falsex, 
                                                   LFLOAT      *falsey, 
                                                   LFLOAT      *xyunits);
extern LONG SDEAPI SE_coordref_get_xy_envelope    (SE_COORDREF  coordref, 
                                                   SE_ENVELOPE *extent);
extern LONG SDEAPI SE_coordref_get_z              (SE_COORDREF  coordref, 
                                                   LFLOAT      *falsez, 
                                                   LFLOAT      *zunits);
extern LONG SDEAPI SE_coordref_get_z_range        (SE_COORDREF  coordref, 
                                                   LFLOAT      *min_value, 
                                                   LFLOAT      *max_value);
extern LONG SDEAPI SE_coordref_set_coordsys       (SE_COORDREF  coordref, 
                                                   PE_COORDSYS  cs);
extern LONG SDEAPI SE_coordref_set_by_description (SE_COORDREF  coordref, 
                                                   const CHAR  *description);
extern LONG SDEAPI SE_coordref_set_by_id          (SE_COORDREF  coordref, 
                                                   LONG         coordsys_id);
extern LONG SDEAPI SE_coordref_set_m              (SE_COORDREF  coordref, 
                                                   LFLOAT       falsem, 
                                                   LFLOAT       munits);
extern LONG SDEAPI SE_coordref_set_m_by_range     (SE_COORDREF  coordref, 
                                                   LFLOAT       min_mvalue, 
                                                   LFLOAT       max_mvalue);
extern LONG SDEAPI SE_coordref_set_precision      (SE_COORDREF  coordref, 
                                                   LONG         precision);
extern LONG SDEAPI SE_coordref_set_xy             (SE_COORDREF  coordref, 
                                                   LFLOAT       falsex, 
                                                   LFLOAT       falsey, 
                                                   LFLOAT       xyunits);
extern LONG SDEAPI SE_coordref_set_xy_by_envelope (SE_COORDREF  coordref, 
                                                   SE_ENVELOPE *extent);
extern LONG SDEAPI SE_coordref_set_z              (SE_COORDREF  coordref, 
                                                   LFLOAT       falsez, 
                                                   LFLOAT       zunits);
extern LONG SDEAPI SE_coordref_set_z_by_range     (SE_COORDREF  coordref, 
                                                   LFLOAT       min_zvalue, 
                                                   LFLOAT       max_zvalue);

/* Database object functions */

extern LONG SDEAPI SE_database_list       (SE_CONNECTION       connection,
                                           LONG                *num_databases,
                                           CHAR                ***databases);
extern void SDEAPI SE_database_free_list  (LONG                num_databases,
                                           CHAR                **databases );
extern LONG SDEAPI SE_database_use        (SE_CONNECTION       connection,
                                           CHAR                *database);

/* Error object functions */

extern LONG SDEAPI SE_error_get_string            (LONG  error_code,
                                                   CHAR  *error_string);
extern LONG SDEAPI SE_connection_get_error_string (SE_CONNECTION connection,
                                                   LONG  error_code,
                                                   CHAR  *error_string);

/* External file info object functions */

extern LONG SDEAPI SE_file_close           (SE_FILEINFO         fileinfo);
extern LONG SDEAPI SE_file_create          (SE_FILEINFO         fileinfo,
                                            SHORT               num_columns,
                                            const SE_COLUMN_DEF *column_defs);
extern LONG SDEAPI SE_file_describe        (SE_FILEINFO         fileinfo,
                                            SHORT               *num_columns,
                                            SE_COLUMN_DEF       **column_defs);
extern BOOL SDEAPI SE_file_exist           (SE_FILEINFO         fileinfo,
                                            LONG                *status);
extern void SDEAPI SE_file_free_descriptions(SE_COLUMN_DEF      *column_defs);
extern LONG SDEAPI SE_file_open            (SE_FILEINFO         fileinfo);

extern LONG SDEAPI SE_fileinfo_create      (SE_FILEINFO         *fileinfo);
extern LONG SDEAPI SE_fileinfo_duplicate   (const SE_FILEINFO   src_fileinfo,
                                            SE_FILEINFO         tgt_fileinfo);
extern void SDEAPI SE_fileinfo_free        (SE_FILEINFO         fileinfo);

extern LONG SDEAPI SE_fileinfo_get_layerinfo
                                           (const SE_FILEINFO   fileinfo,
                                            SE_LAYERINFO        layer);
extern LONG SDEAPI SE_fileinfo_get_name    (const SE_FILEINFO   fileinfo,
                                            CHAR                *name);
extern LONG SDEAPI SE_fileinfo_get_type    (const SE_FILEINFO   fileinfo,
                                            LONG                *file_type,
                                            CHAR                *feat_class);

extern LONG SDEAPI SE_fileinfo_set_layerinfo
                                           (SE_FILEINFO         fileinfo,
                                            const SE_LAYERINFO  layer);
extern LONG SDEAPI SE_fileinfo_set_name    (SE_FILEINFO         fileinfo,
                                            const CHAR          *name);
extern LONG SDEAPI SE_fileinfo_set_type    (SE_FILEINFO         fileinfo,
                                            const LONG          file_type,
                                            const CHAR          *feat_class);

/* Instance object functions */

/* For future developments, please do not use the structure
   SE_INSTANCE_CONFIG and API SE_instance_configuration() for
   server configuration info. They are provided only for
   backward compatibility and will be deprecated for the post
   9.0 releases. Instead, please use SE_SERVERINFO structure
   and SE_instance_serverconfig_get_info() API respectively. */

extern LONG SDEAPI SE_instance_configuration 
                                           (const CHAR         *server,
                                            const CHAR         *instance,
                                            SE_INSTANCE_CONFIG *configuration);
extern LONG SDEAPI SE_instance_serverconfig_get_info
                                           (const CHAR         *server,
                                            const CHAR         *instance,
                                            SE_SERVERINFO      svr_config);
extern LONG SDEAPI SE_instance_control     (const CHAR         *server,
                                            const CHAR         *instance,
                                            const CHAR         *password,
                                            LONG               option,
                                            LONG               pid);

extern void SDEAPI SE_instance_free_locks  (SE_INSTANCE_LOCK   *lock_list,
                                            LONG               lock_count);
extern void SDEAPI SE_instance_free_state_locks  
                                           (SE_INSTANCE_STATE_LOCK *lock_list,
                                            LONG                   lock_count);
extern void SDEAPI SE_instance_free_table_locks
                                            (SE_INSTANCE_TABLE_LOCK   *lock_list,
                                            LONG               lock_count);
extern void SDEAPI SE_instance_free_version_locks
                                        (SE_INSTANCE_VERSION_LOCK   *lock_list,
                                         LONG                       lock_count);
extern void SDEAPI SE_instance_free_statistics  
                                           (SE_INSTANCE_STATS  *stats_list,
                                            LONG               stats_count);
extern void SDEAPI SE_instance_free_users  (SE_INSTANCE_USER   *user_list,
                                            LONG               user_count);
extern void SDEAPI SE_instance_free_variables (CHAR            **variables,
                                               LONG            var_count);
extern LONG SDEAPI SE_instance_get_locks(const CHAR          *server,
                                         const CHAR          *instance,
                                         SE_INSTANCE_LOCK    **lock_list_addr,
                                         LONG                *lock_count_addr);
extern LONG SDEAPI SE_instance_get_objectlocks (const CHAR         *server,
                                                const CHAR         *instance,
                                                SE_OBJECTLOCKINFO  **lock_list,
                                                LONG               *lock_count);
extern LONG SDEAPI SE_instance_get_state_locks
                                     (const CHAR              *server,
                                      const CHAR              *instance,
                                      SE_INSTANCE_STATE_LOCK  **lock_list_addr,
                                      LONG                   *lock_count_addr);
extern LONG SDEAPI SE_instance_get_table_locks
                                     (const CHAR              *server,
                                      const CHAR              *instance,
                                      SE_INSTANCE_TABLE_LOCK  **lock_list_addr,
                                      LONG                   *lock_count_addr);
extern LONG SDEAPI SE_instance_get_statistics  
                                     (const CHAR          *server,
                                      const CHAR          *instance,
                                      SE_INSTANCE_STATS   **stats_list_addr,
                                      LONG                *stats_count_addr);
extern LONG SDEAPI SE_instance_get_users (const CHAR         *server,
                                         const CHAR          *instance,
                                         SE_INSTANCE_USER    **user_list_addr,
                                         LONG                *user_count_addr);
extern LONG SDEAPI SE_instance_get_variables (const CHAR     *server,
                                              const CHAR     *instance,
                                              CHAR           ***variables,
                                              LONG           *var_count_addr);
extern LONG SDEAPI SE_instance_get_version_locks 
                                   (const CHAR                *server,
                                    const CHAR                *instance,
                                    SE_INSTANCE_VERSION_LOCK  **lock_list_addr,
                                    LONG                      *lock_count_addr);
extern LONG SDEAPI SE_instance_start     (const CHAR         *sdehome,
                                          const CHAR         *password);
extern LONG SDEAPI SE_instance_status    (const CHAR         *server,
                                          const CHAR         *instance,
                                          SE_INSTANCE_STATUS *istatus);

/* Layer object functions */

extern LONG SDEAPI SE_layer_alter           (SE_CONNECTION      connection,
                                             const SE_LAYERINFO layer); 
extern LONG SDEAPI SE_layer_create          (SE_CONNECTION      connection,
                                             const SE_LAYERINFO layer,
                                             LONG               initialf,
                                             LONG               avg_points);
extern LONG SDEAPI SE_layer_delete          (SE_CONNECTION      connection,
                                             const CHAR         *table,
                                             const CHAR         *column);
extern void SDEAPI SE_layer_free_info_list  (LONG               count,
                                             SE_LAYERINFO       *layer_list);
extern LONG SDEAPI SE_layer_free_lock       (SE_CONNECTION      connection,
                                             const CHAR         *table,
                                             const CHAR         *column);
extern void SDEAPI SE_layer_free_locks      (SE_LAYER_LOCKS     *locks);
extern LONG SDEAPI SE_layer_calculate_extent(SE_CONNECTION      connection,
                                             const CHAR         *table,
                                             const CHAR         *column,
                                             BOOL               use_index,
                                             SE_ENVELOPE        *e,
                                             LFLOAT             *minz,
                                             LFLOAT             *maxz,
                                             const SE_SQL_CONSTRUCT *construct);
extern LONG SDEAPI SE_layer_get_info_by_id  (SE_CONNECTION      connection,
                                             LONG               layer_id,
                                             SE_LAYERINFO       layer);
extern LONG SDEAPI SE_layer_get_info        (SE_CONNECTION      connection,
                                             const CHAR         *table,
                                             const CHAR         *column,
                                             SE_LAYERINFO       layer);
extern LONG SDEAPI SE_layer_get_info_list   (SE_CONNECTION      connection,
                                             SE_LAYERINFO       **layer_list,
                                             LONG               *count_addr);
extern LONG SDEAPI SE_layer_get_locks       (SE_CONNECTION      connection,
                                             const CHAR         *table,
                                             const CHAR         *column,
                                             LONG               *num_locks,
                                             SE_LAYER_LOCKS     **locks);
extern LONG SDEAPI SE_layer_get_si_statistics(SE_CONNECTION     connection,
                                             const CHAR         *table,
                                             const CHAR         *column,
                                             SE_SI_STATS        *stats);
extern LONG SDEAPI SE_layer_grant_access    (SE_CONNECTION      connection,
                                             const CHAR         *table,
                                             const CHAR         *column,
                                             LONG               privilege,
                                             BOOL               grant,
                                             const CHAR         *user);
extern LONG SDEAPI SE_layer_lock            (SE_CONNECTION      connection,
                                             const CHAR         *table,
                                             const CHAR         *column,
                                             LONG               lock_mode);
extern LONG SDEAPI SE_layer_lock_area       (SE_CONNECTION      connection,
                                             const CHAR         *table,
                                             const CHAR         *column,
                                             LONG               lock_mode,
                                             const SE_ENVELOPE  *area);
extern LONG SDEAPI SE_layer_modify_lock     (SE_CONNECTION      connection,
                                             const CHAR         *table,
                                             const CHAR         *column,
                                             LONG               new_lock_mode,
                                             const SE_ENVELOPE  *area);
extern LONG SDEAPI SE_layer_revoke_access   (SE_CONNECTION      connection,
                                             const CHAR         *table,
                                             const CHAR         *column,
                                             LONG               privilege,
                                             const CHAR         *user);
extern LONG SDEAPI SE_layer_truncate        (SE_CONNECTION      connection,
                                             const CHAR         *table,
                                             const CHAR         *column);
extern LONG SDEAPI SE_layer_shape_attribute_name (
                                             SE_CONNECTION      connection,
                                             const CHAR         *table,
                                             const CHAR         *column,
                                             LONG               attr_code,
                                             CHAR               *attr_name );

/* Obsolete layer function(s). */
extern LONG SDEAPI SE_layer_get_statistics  (SE_CONNECTION      connection,
                                             const CHAR         *table,
                                             const CHAR         *column,
                                             SE_LAYER_STATS     *stats);


/* Layer info object functions */

extern LONG SDEAPI SE_layerinfo_create       (const SE_COORDREF   coordref,
                                              SE_LAYERINFO        *layer);
extern LONG SDEAPI SE_layerinfo_duplicate    (const SE_LAYERINFO  src_layer,
                                              SE_LAYERINFO        tgt_layer);
extern void SDEAPI SE_layerinfo_free         (SE_LAYERINFO        layer);

extern LONG SDEAPI SE_layerinfo_get_access   (const SE_LAYERINFO  layer,
                                              LONG                *privileges);
extern LONG SDEAPI SE_layerinfo_get_array_size
                                             (const SE_LAYERINFO  layer,
                                              LONG *optimal_array_size,
                                              struct tm *last_calculated_date);
extern LONG SDEAPI SE_layerinfo_get_coordref (const SE_LAYERINFO  layer,
                                               SE_COORDREF         coordref);
extern LONG SDEAPI SE_layerinfo_get_creation_date    
                                             (const SE_LAYERINFO  layer,
                                              struct tm           *date);
extern LONG SDEAPI SE_layerinfo_get_creation_keyword 
                                             (const SE_LAYERINFO  layer,
                                              CHAR *config_keyword);
extern LONG SDEAPI SE_layerinfo_get_description    
                                             (const SE_LAYERINFO  layer,
                                              CHAR          *description);
extern LONG SDEAPI SE_layerinfo_get_envelope (const SE_LAYERINFO  layer,
                                              SE_ENVELOPE   *envelope);
extern LONG SDEAPI SE_layerinfo_get_Zrange (const SE_LAYERINFO  layer,
                                            LFLOAT              *zmin,
                                            LFLOAT              *zmax);
extern LONG SDEAPI SE_layerinfo_get_Mrange (const SE_LAYERINFO  layer,
                                            LFLOAT              *mmin,
                                            LFLOAT              *mmax);
extern LONG SDEAPI SE_layerinfo_get_grid_sizes 
                                             (const SE_LAYERINFO  layer,
                                              LFLOAT              *grid_size,
                                              LFLOAT              *grid_size2,
                                              LFLOAT              *grid_size3);
extern LONG SDEAPI SE_layerinfo_get_id       (const SE_LAYERINFO  layer,
                                              LONG                *layer_id);
extern LONG SDEAPI SE_layerinfo_get_minimum_id    
                                             (const SE_LAYERINFO  layer,
                                              ULONG               *minimum_id);
extern LONG SDEAPI SE_layerinfo_get_shape_types    (const SE_LAYERINFO  layer,
                                                    LONG *shape_types);
extern LONG SDEAPI SE_layerinfo_get_spatial_column (const SE_LAYERINFO  layer,
                                                    CHAR                *table,
                                                    CHAR *column);
extern LONG SDEAPI SE_layerinfo_get_storage_type   (const SE_LAYERINFO  layer,
                                                   LONG                *storage_type);
extern BOOL SDEAPI SE_layerinfo_has_anno           (const SE_LAYERINFO  layer);
extern BOOL SDEAPI SE_layerinfo_has_autolocking    (const SE_LAYERINFO  layer);
extern BOOL SDEAPI SE_layerinfo_has_cad            (const SE_LAYERINFO  layer);
extern BOOL SDEAPI SE_layerinfo_has_spatial_index  (const SE_LAYERINFO  layer); 
extern BOOL SDEAPI SE_layerinfo_is_3D              (const SE_LAYERINFO  layer);
extern BOOL SDEAPI SE_layerinfo_is_in_load_mode    (const SE_LAYERINFO  layer);
extern BOOL SDEAPI SE_layerinfo_is_measured        (const SE_LAYERINFO  layer);
extern BOOL SDEAPI SE_layerinfo_is_storage_external
                                                   (const SE_LAYERINFO  layer);
extern BOOL SDEAPI SE_layerinfo_is_storage_lob     (const SE_LAYERINFO  layer);
extern BOOL SDEAPI SE_layerinfo_is_storage_normalized
                                                   (const SE_LAYERINFO  layer);
extern BOOL SDEAPI SE_layerinfo_is_storage_sdebinary
                                                   (const SE_LAYERINFO  layer);
extern BOOL SDEAPI SE_layerinfo_is_storage_sql     (const SE_LAYERINFO  layer);
extern BOOL SDEAPI SE_layerinfo_is_storage_wkb     (const SE_LAYERINFO  layer);
extern LONG SDEAPI SE_layerinfo_set_3D             (SE_LAYERINFO  layer,
                                                    BOOL          is_3D);
extern LONG SDEAPI SE_layerinfo_set_anno           (SE_LAYERINFO  layer,
                                                    BOOL          has_anno);
extern LONG SDEAPI SE_layerinfo_set_array_size     (SE_LAYERINFO  layer,
                                                    LONG    optimal_array_size);
extern LONG SDEAPI SE_layerinfo_set_autolocking    (SE_LAYERINFO  layer,
                                                    BOOL   autolocking_enabled);
extern LONG SDEAPI SE_layerinfo_set_cad            (SE_LAYERINFO  layer,
                                                    BOOL          has_cad);
extern LONG SDEAPI SE_layerinfo_set_coordref       (SE_LAYERINFO  layer,
                                                    SE_COORDREF   coordref);
extern LONG SDEAPI SE_layerinfo_set_creation_keyword(SE_LAYERINFO layer,
                                                    const CHAR *config_keyword);
extern LONG SDEAPI SE_layerinfo_set_description    (SE_LAYERINFO  layer,
                                                    const CHAR    *description);
extern LONG SDEAPI SE_layerinfo_set_envelope       (SE_LAYERINFO  layer,
                                                   const SE_ENVELOPE *envelope);
extern LONG SDEAPI SE_layerinfo_set_grid_sizes     (SE_LAYERINFO  layer,
                                                    LFLOAT        grid_size,
                                                    LFLOAT        grid_size2,
                                                    LFLOAT        grid_size3);
extern LONG SDEAPI SE_layerinfo_set_load_mode      (SE_LAYERINFO  layer,
                                                    BOOL is_in_load_mode);
extern LONG SDEAPI SE_layerinfo_set_measured       (SE_LAYERINFO  layer,
                                                    BOOL          is_measured);
extern LONG SDEAPI SE_layerinfo_set_minimum_id    (SE_LAYERINFO   layer,
                                                   ULONG          minimum_id);
extern LONG SDEAPI SE_layerinfo_set_shape_types    (SE_LAYERINFO  layer,
                                                    LONG          shape_types);
extern LONG SDEAPI SE_layerinfo_set_spatial_column (SE_LAYERINFO  layer,
                                                    const CHAR    *table,
                                                    const CHAR    *column);

extern LONG SDEAPI SE_layerinfo_set_storage_type   (SE_LAYERINFO  layer,
                                                    LONG          storage_type);
extern LONG SDEAPI SE_layerinfo_set_Zrange         (const SE_LAYERINFO  layer,
                                                    LFLOAT              zmin,
                                                    LFLOAT              zmax);
extern LONG SDEAPI SE_layerinfo_set_Mrange         (const SE_LAYERINFO  layer,
                                                    LFLOAT              mmin,
                                                    LFLOAT              mmax);

/* Locator object functions */
extern LONG SDEAPI SE_locator_alter
                                        (SE_CONNECTION  handle,
                                         const SE_LOCATORINFO locator);
extern LONG SDEAPI SE_locator_create
                                        (SE_CONNECTION  handle,
                                         const SE_LOCATORINFO locator);
extern LONG SDEAPI SE_locator_delete
                                        (SE_CONNECTION  handle,
                                         const CHAR    *locator_name);
extern LONG SDEAPI SE_locator_get_info
                                        (SE_CONNECTION  handle,
                                         const CHAR    *locator_name,
                                         SE_LOCATORINFO locator);
extern LONG SDEAPI SE_locator_get_info_by_id
                                        (SE_CONNECTION  handle,
                                         LONG           id,
                                         SE_LOCATORINFO locator);
extern void SDEAPI SE_locator_free_info_list
                                        (LONG           count,
                                         SE_LOCATORINFO *locator_list);
extern LONG SDEAPI SE_locator_get_info_list
                                        (SE_CONNECTION  handle,
                                         const CHAR     *where,
                                         SE_LOCATORINFO **locator_list,
                                         LONG           *count_addr);
extern LONG SDEAPI SE_locator_describe_output
                                        (SE_CONNECTION connection,
                                         SE_LOCATORINFO locator,
                                         SHORT *num_columns,
                                         SE_COLUMN_DEF **column_defs);
extern void SDEAPI SE_locator_free_descriptions(SE_COLUMN_DEF *column_defs);
extern LONG SDEAPI SE_locator_describe_inputs
                                        (SE_CONNECTION handle,
                                         SE_LOCATORINFO locator,
                                         LONG *num_inputs,
                                         CHAR ***inputs,
                                         CHAR ***aliases,
                                         BOOL **required_indicators,
                                         LONG **sizes);
extern void SDEAPI SE_locator_free_input_descriptions
                                        (LONG num_inputs,
                                         CHAR **columns,
                                         CHAR **aliases,
                                         BOOL *required_indicators,
                                         LONG *sizes);
extern LONG SDEAPI SE_locator_describe_shape
                                        (SE_CONNECTION handle,
                                         SE_LOCATORINFO locator,
                                         LONG *shape_mask,
                                         SE_COORDREF coordref,
                                         BOOL *is_3D,
                                         BOOL *has_Ms);
extern LONG SDEAPI SE_locator_refresh   (SE_CONNECTION handle,
                                         SE_LOCATORINFO locator,
                                         const CHAR *table);

/* Locatorinfo object functions */
extern LONG SDEAPI SE_locatorinfo_create
                                        (SE_LOCATORINFO        *locator);
extern void SDEAPI SE_locatorinfo_free
                                        (SE_LOCATORINFO        locator);
extern LONG SDEAPI SE_locatorinfo_duplicate
                                        (const SE_LOCATORINFO  src_locator,
                                         SE_LOCATORINFO        tgt_locator);
extern LONG SDEAPI SE_locatorinfo_get_description
                                        (const SE_LOCATORINFO  locator,
                                         CHAR                  *description);
extern LONG SDEAPI SE_locatorinfo_get_category
                                        (const SE_LOCATORINFO  locator,
                                         CHAR                  *category);
extern LONG SDEAPI SE_locatorinfo_get_id
                                        (const SE_LOCATORINFO  locator,
                                         LONG                  *id);
extern LONG SDEAPI SE_locatorinfo_get_type
                                        (const SE_LOCATORINFO  locator,
                                         LONG                  *type);
extern LONG SDEAPI SE_locatorinfo_get_name
                                        (const SE_LOCATORINFO  locator,
                                         CHAR                  *name);
extern LONG SDEAPI SE_locatorinfo_get_owner
                                        (const SE_LOCATORINFO  locator,
                                         CHAR                  *owner);
extern LONG SDEAPI SE_locatorinfo_get_property_value
                                        (SE_LOCATORINFO        locator,
                                         const CHAR            *property,
                                         LONG                  *num_values,
                                         CHAR                  ***values);
extern void SDEAPI SE_locatorinfo_free_property_value
                                        (LONG                  num_values,
                                         CHAR                  **values);
extern LONG SDEAPI SE_locatorinfo_get_property_values
                                        (const SE_LOCATORINFO  locator,
                                         LONG                  *num_props,
                                         CHAR                  ***properties,
                                         CHAR                  ***values);
extern void SDEAPI SE_locatorinfo_free_property_values
                                        (LONG                  num_props,
                                         CHAR                  **properties,
                                         CHAR                  **values);
extern LONG SDEAPI SE_locatorinfo_get_single_property_value
                                        (SE_LOCATORINFO        locator,
                                         const CHAR            *property,
                                         CHAR                  *value_buffer);
extern LONG SDEAPI SE_locatorinfo_set_description
                                        (SE_LOCATORINFO        locator,
                                         const CHAR            *description);
extern LONG SDEAPI SE_locatorinfo_set_category
                                        (SE_LOCATORINFO        locator,
                                         const CHAR            *category);
extern LONG SDEAPI SE_locatorinfo_set_name
                                        (SE_LOCATORINFO        locator,
                                         const CHAR            *name);
extern LONG SDEAPI SE_locatorinfo_set_property
                                        (SE_LOCATORINFO        locator,
                                         const CHAR            *property,
                                         LONG                  num_values,
                                         const CHAR            **values);
extern LONG SDEAPI SE_locatorinfo_set_property_values
                                        (SE_LOCATORINFO        locator,
                                         LONG                  num_props,
                                         const CHAR            **properties,
                                         const CHAR            **values);
extern LONG SDEAPI SE_locatorinfo_set_single_property
                                        (SE_LOCATORINFO        locator,
                                         const CHAR            *property,
                                         const CHAR            *value);
extern LONG SDEAPI SE_locatorinfo_set_type
                                        (SE_LOCATORINFO        locator,
                                         LONG                  type);




/***********************
* Logfile functions.
************************/

/* Functions to create and free loginfo objects. */

extern LONG SDEAPI SE_loginfo_create         (SE_LOGINFO        *loginfo);
extern void SDEAPI SE_loginfo_free           (SE_LOGINFO        loginfo);
extern LONG SDEAPI SE_loginfo_duplicate      (const SE_LOGINFO  src_loginfo,
                                              SE_LOGINFO        tgt_loginfo);
extern void SDEAPI SE_loginfo_free_list      (SE_LOGINFO        *loginfo_list,
                                              LONG              count);
                                                    
/* Functions to get attributes of loginfo objects. */

extern LONG SDEAPI SE_loginfo_get_id         (const SE_LOGINFO  loginfo,
                                              LONG              *log_id);
extern LONG SDEAPI SE_loginfo_get_name       (const SE_LOGINFO  loginfo,
                                              CHAR              *name);
extern LONG SDEAPI SE_loginfo_get_target_object
                                             (const SE_LOGINFO  loginfo,
                                              LONG              *target_type,
                                              CHAR              *table,
                                              CHAR           *spatial_column);
extern LONG SDEAPI SE_loginfo_get_delete_mode(const SE_LOGINFO        loginfo,
                                              SE_LOGFILE_DELETE_MODE  *delete_mode);
extern BOOL SDEAPI SE_loginfo_is_persistent  ( const SE_LOGINFO  loginfo);

/* Functions to modify attributes of loginfo objects. */

extern LONG SDEAPI SE_loginfo_set_name       (SE_LOGINFO        loginfo,
                                              const CHAR        *name);
extern LONG SDEAPI SE_loginfo_set_target_object   
                                             (SE_LOGINFO        loginfo,
                                              LONG              target_type,
                                              CHAR              *table,
                                              CHAR           *spatial_column);
extern LONG SDEAPI SE_loginfo_set_persistence(SE_LOGINFO        loginfo,
                                              BOOL             is_persistent);

extern LONG SDEAPI SE_loginfo_set_delete_mode(SE_LOGINFO        loginfo,
                                              SE_LOGFILE_DELETE_MODE  delete_mode);

/* Functions to find and return logfile information. */

extern LONG SDEAPI SE_log_get_by_name        (SE_CONNECTION     connection,
                                              const CHAR        *logfile,
                                                      /* Qualified name OK. */
                                              SE_LOGINFO        loginfo);
extern LONG SDEAPI SE_log_get_by_owner       (SE_CONNECTION     connection,
                                              const CHAR        *owner,
                                                     /* If NULL, this user. */
                                              SE_LOGINFO   **loginfo_list_addr,
                                              LONG              *count_addr);
extern LONG SDEAPI SE_log_get_by_table       (SE_CONNECTION     connection,
                                              const CHAR        *log_owner,
                                                     /* If NULL, this user. */
                                              const CHAR        *table,
                                              SE_LOGINFO   **loginfo_list_addr,
                                              LONG              *count_addr);
extern LONG SDEAPI SE_log_get_open_log_info  (SE_CONNECTION      connection,
                                              const SE_LOG       log,
                                              SE_LOGINFO         loginfo);

/* Functions to create and manipulate logfiles. */

extern LONG SDEAPI SE_log_make_name         (SE_CONNECTION     connection,
                                             CHAR              *logfile);
extern LONG SDEAPI SE_log_create            (SE_CONNECTION     connection,
                                             SE_LOGINFO        loginfo);
extern LONG SDEAPI SE_log_delete            (SE_CONNECTION     connection,
                                             const CHAR        *log_name);
extern LONG SDEAPI SE_log_alter             (SE_CONNECTION     connection,
                                             SE_LOGINFO        loginfo);
extern LONG SDEAPI SE_log_calculate_extent  (SE_CONNECTION         connection,
                                             const CHAR             *logname,
                                             SE_ENVELOPE            *e,
                                             LFLOAT                 *minz,
                                             LFLOAT                 *maxz,
                                             const SE_SQL_CONSTRUCT *construct);
extern LONG SDEAPI SE_log_count_ids         (SE_CONNECTION     connection,
                                             SE_LOGINFO        loginfo);
extern LONG SDEAPI SE_log_combine           (SE_CONNECTION     connection,
                                             const CHAR        *logfile1,
                                             const CHAR        *logfile2,
                                             const CHAR        *logfile12,
                                             LONG              operation);
extern LONG SDEAPI SE_log_copy              (SE_CONNECTION     connection,
                                             const CHAR        *oldlogfile,
                                             const CHAR        *newlogfile);
extern LONG SDEAPI SE_log_grant_access      (SE_CONNECTION     connection,
                                             const CHAR        *logfiles_owner, 
                                             const CHAR        *dbms_user);
extern LONG SDEAPI SE_log_revoke_access     (SE_CONNECTION     connection,
                                             const CHAR        *logfiles_owner, 
                                             const CHAR        *dbms_user);
extern LONG SDEAPI SE_log_sort              (SE_CONNECTION     connection,
                                             const CHAR        *logfile);

   /* See also SE_stream_query_logfile */

/* Functions to work with an open logfile - SE_LOG handle. */

extern LONG SDEAPI SE_log_open_log          (SE_CONNECTION     connection,
                                             const SE_LOGINFO  loginfo,
                                             LONG              mode,
                                             SE_LOG            *log);
extern LONG SDEAPI SE_log_close             (SE_CONNECTION     connection,
                                             SE_LOG            log);
extern LONG SDEAPI SE_log_count             (SE_CONNECTION     connection,
                                             SE_LOG            log);
extern LONG SDEAPI SE_log_add_id            (SE_CONNECTION     connection,
                                             SE_LOG            log,
                                             LONG              id);
extern LONG SDEAPI SE_log_add_id_list       (SE_CONNECTION     connection,
                                             SE_LOG            log,
                                             LONG              num_ids,
                                             const LONG        *idbuf);
extern LONG SDEAPI SE_log_delete_id_list    (SE_CONNECTION     connection,
                                             SE_LOG            log,
                                             LONG              num_ids,
                                             const LONG        *idbuf);
extern LONG SDEAPI SE_log_get_id_list       (SE_CONNECTION     connection,
                                             SE_LOG            log,
                                             const LONG        max_num_ids,
                                             LONG              *num_ids,
                                             LONG              *idbuf);
   /* See also SE_stream_set_logfile */

/* Obsolete logfile functions. */

extern LONG SDEAPI SE_log_open              (SE_CONNECTION     connection,
                                             const CHAR        *logfile,
                                             CHAR              *table,
                                             LONG              mode,
                                             LONG              type,
                                             SE_LOG            *log);
extern LONG SDEAPI SE_log_set_type          (SE_CONNECTION     connection,
                                             const CHAR        *logfile,
                                             LONG              type);
/************************
* End logfile functions.
*************************/

/* Metadata object functions */

extern void SDEAPI SE_metadata_free_info_list (LONG             record_count,
                                               SE_METADATAINFO  *metadata_list);
extern LONG SDEAPI SE_metadata_get_info_by_id
                                          (SE_CONNECTION      handle,
                                           LONG               record_id,
                                           SE_METADATAINFO    metadata_record);
extern LONG SDEAPI SE_metadata_get_info_list
                                          (SE_CONNECTION    handle,
                                           const CHAR       *where_clause,
                                           SE_METADATAINFO  **metadata_list,
                                           LONG             *record_count);

/* Metadata info object functions */

extern LONG SDEAPI SE_metadatainfo_create (SE_METADATAINFO  *metadata_record);
extern void SDEAPI SE_metadatainfo_free   (SE_METADATAINFO  metadata_record);
extern LONG SDEAPI SE_metadatainfo_duplicate
                                  (const SE_METADATAINFO   src_metadata_record,
                                   SE_METADATAINFO         tgt_metadata_record);
extern LONG SDEAPI SE_metadatainfo_get_classname 
                                  (const SE_METADATAINFO   metadata_record,
                                   CHAR                    *classname);
extern LONG SDEAPI SE_metadatainfo_get_date
                                  (const SE_METADATAINFO   metadata_record,
                                   struct tm               *date);
extern LONG SDEAPI SE_metadatainfo_get_description
                                  (const SE_METADATAINFO   metadata_record,
                                   CHAR                    *description);
extern LONG SDEAPI SE_metadatainfo_get_id
                                  (const SE_METADATAINFO   metadata_record,
                                   LONG                    *id);
extern LONG SDEAPI SE_metadatainfo_get_object_owner
                                  (const SE_METADATAINFO   metadata_record,
                                   CHAR                    *object_owner);
extern LONG SDEAPI SE_metadatainfo_get_object_type
                                  (const SE_METADATAINFO   metadata_record,
                                   LONG                    *object_type);
extern LONG SDEAPI SE_metadatainfo_get_property
                                  (const SE_METADATAINFO   metadata_record,
                                   CHAR                    *property);
extern LONG SDEAPI SE_metadatainfo_get_object_name
                                  (const SE_METADATAINFO   metadata_record,
                                   CHAR                    *object_name);
extern LONG SDEAPI SE_metadatainfo_get_value
                                  (const SE_METADATAINFO   metadata_record,
                                   CHAR                    *value);
extern LONG SDEAPI SE_metadatainfo_set_classname
                                  (SE_METADATAINFO         metadata_record,
                                   const CHAR              *classname);
extern LONG SDEAPI SE_metadatainfo_set_description
                                  (SE_METADATAINFO         metadata_record,
                                   const CHAR              *description);
extern LONG SDEAPI SE_metadatainfo_set_object_type
                                  (SE_METADATAINFO         metadata_record,
                                   const LONG              object_type);
extern LONG SDEAPI SE_metadatainfo_set_property
                                  (SE_METADATAINFO         metadata_record,
                                   const CHAR              *property);
extern LONG SDEAPI SE_metadatainfo_set_object_name
                                  (SE_METADATAINFO         metadata_record,
                                   const CHAR              *object_name);
extern LONG SDEAPI SE_metadatainfo_set_value
                                  (SE_METADATAINFO         metadata_record,
                                   const CHAR              *value);

/* Object lock object functions. */

extern LONG SDEAPI SE_objectlock_free_lock (SE_CONNECTION            connection,
                                            const SE_OBJECTLOCKINFO  objectlock);
extern void SDEAPI SE_objectlock_free_list (LONG               lock_count,
                                            SE_OBJECTLOCKINFO  *lock_list);
extern LONG SDEAPI SE_objectlock_get_list (SE_CONNECTION            connection,
                                           const SE_OBJECTLOCKINFO  example,
                                           SE_OBJECTLOCKINFO        **lock_list,
                                           LONG                    *lock_count);
extern LONG SDEAPI SE_objectlock_lock (SE_CONNECTION            connection,
                                       const SE_OBJECTLOCKINFO  objectlock,
                                       LONG                     lock_mode);

/* Object lock info object functions. */

extern LONG SDEAPI SE_objectlockinfo_create (SE_OBJECTLOCKINFO  *objectlock);
extern LONG SDEAPI SE_objectlockinfo_duplicate 
                                            (const SE_OBJECTLOCKINFO  src_lock,
                                             SE_OBJECTLOCKINFO        tgt_lock);
extern void SDEAPI SE_objectlockinfo_free (SE_OBJECTLOCKINFO  objectlock);

extern LONG SDEAPI SE_objectlockinfo_get_lock_mode
                               (const SE_OBJECTLOCKINFO  objectlock,
                                LONG                     *lock_mode);
extern LONG SDEAPI SE_objectlockinfo_get_object_id
                               (const SE_OBJECTLOCKINFO  objectlock,
                                LONG                    *object_id);
extern LONG SDEAPI SE_objectlockinfo_get_object_type
                               (const SE_OBJECTLOCKINFO  objectlock,
                                LONG                     *object_type);
extern LONG SDEAPI SE_objectlockinfo_get_owner 
                               (const SE_OBJECTLOCKINFO  objectlock,
                                CHAR                     *owner,
                                LONG                     *svrpid);
extern LONG SDEAPI SE_objectlockinfo_set_object_id
                               (SE_OBJECTLOCKINFO  objectlock,
                                LONG               object_id);
extern LONG SDEAPI SE_objectlockinfo_set_object_type 
                               (SE_OBJECTLOCKINFO  objectlock,
                                LONG               object_type);

/* Point table object functions */

extern LONG SDEAPI SE_ptable_add_point       (SE_PTABLE      ptable,
                                              SE_POINT       *pt,
                                              LFLOAT         *z,
                                              LONG           count,
                                              ULONG          mask);
extern LONG SDEAPI SE_ptable_add_shape       (SE_PTABLE      ptable,
                                              const SE_SHAPE shape,
                                              ULONG          mask);
extern LONG SDEAPI SE_ptable_create          (SE_ENVELOPE    *window,
                                              SE_COORDREF    coordref,
                                              SE_PTABLE      *ptable);
extern LONG SDEAPI SE_ptable_delete_point    (SE_PTABLE      ptable,
                                              SE_POINT       *pt,
                                              LFLOAT         *z,
                                              LONG           count,
                                              ULONG          mask);
extern LONG SDEAPI SE_ptable_delete_shape    (SE_PTABLE      ptable,
                                              const SE_SHAPE shape,
                                              ULONG          mask);
extern void SDEAPI SE_ptable_free            (SE_PTABLE      ptable);
extern LONG SDEAPI SE_ptable_get             (SE_PTABLE      ptable,
                                              SE_ENVELOPE    *userwin,
                                              ULONG          mask,
                                              void           (*user_function)
                                                 (void            *argument,
                                                 SE_SNAPPED_POINT *points,
                                                 LONG             count),
                                              void           *argument);
extern LONG SDEAPI SE_ptable_set_concurrency (SE_PTABLE      ptable,
                                              LONG           policy);
extern LONG SDEAPI SE_ptable_snap            (SE_PTABLE      ptable,
                                              SE_POINT       *pt,
                                              LFLOAT         z,
                                              LFLOAT         radius,
                                              ULONG          mask,
                                              SE_SNAPPED_POINT *spt,
                                              LONG           snapmode);


/* Query info object functions */

extern LONG SDEAPI SE_queryinfo_create        (SE_QUERYINFO        *query_info);
extern void SDEAPI SE_queryinfo_free          (SE_QUERYINFO         query_info);
extern void SDEAPI SE_queryinfo_free_columns  (CHAR                **columns);
extern void SDEAPI SE_queryinfo_free_tables   (CHAR                **tables);

extern LONG SDEAPI SE_queryinfo_get_columns   (const SE_QUERYINFO  query_info,
                                               LONG                *num_columns,
                                               CHAR                ***columns);
extern LONG SDEAPI SE_queryinfo_get_entity_type
                                              (const SE_QUERYINFO  query_info,
                                               LONG                *entity_type);

extern LONG SDEAPI SE_queryinfo_get_logfile   (const SE_QUERYINFO  query_info,
                                               CHAR                *logfile);
extern LONG SDEAPI SE_queryinfo_get_by_clause (const SE_QUERYINFO  query_info,
                                               CHAR                *order_by);
extern LONG SDEAPI SE_queryinfo_get_query_type(const SE_QUERYINFO  query_info,
                                               LONG                *query_type);
extern LONG SDEAPI SE_queryinfo_get_tables    (const SE_QUERYINFO  query_info,
                                               LONG                *num_tables,
                                               CHAR                ***tables);
extern LONG SDEAPI SE_queryinfo_get_where_clause
                                              (const SE_QUERYINFO  query_info,
                                               CHAR                *where_clause);
extern LONG SDEAPI SE_queryinfo_set_columns   (SE_QUERYINFO        query_info,
                                               const LONG          num_columns,
                                               const CHAR          **columns);
extern LONG SDEAPI SE_queryinfo_set_dynamic_bind
                                              (SE_QUERYINFO        query_info,
                                               SHORT               position,
                                               LONG                sde_type,
                                               LONG                length,
                                               const void          *data,
                                               const SHORT         *indicator);
extern LONG SDEAPI SE_queryinfo_set_entity_type
                                              (SE_QUERYINFO        query_info,
                                               const LONG          entity_type);
extern LONG SDEAPI SE_queryinfo_set_logfile   (SE_QUERYINFO         query_info,
                                               const CHAR           *logfile);  
extern LONG SDEAPI SE_queryinfo_set_by_clause (SE_QUERYINFO        query_info,
                                               const CHAR          *order_by);
extern LONG SDEAPI SE_queryinfo_set_query_type(SE_QUERYINFO        query_info,
                                               const LONG          query_type);
extern LONG SDEAPI SE_queryinfo_set_tables    (SE_QUERYINFO        query_info,
                                               const LONG          num_tables,
                                               const CHAR          **tables,
                                               const CHAR          **aliases);
extern LONG SDEAPI SE_queryinfo_set_where_clause
                                              (SE_QUERYINFO        query_info,
                                               const CHAR          *where_clause);
extern LONG SDEAPI SE_queryinfo_set_xml_doc_property
                                              (SE_QUERYINFO       query_info,
                                               const CHAR         *table,
                                               const CHAR         *column,
                                               LONG               doc_property);
extern LONG SDEAPI SE_queryinfo_set_xpath_constraint (SE_QUERYINFO query_info,
                                                   const CHAR      *table,
                                                   const CHAR      *column,
                                                   const CHAR      *xpath_expr);
extern LONG SDEAPI SE_queryinfo_duplicate     (const SE_QUERYINFO  src_queryinfo,
                                               SE_QUERYINFO        tgt_queryinfo);


/* Registration info object functions. */

extern LONG SDEAPI SE_registration_make_single_version (SE_CONNECTION  handle,
                                              const CHAR     *version_name,
                                              const CHAR     *table_name);
extern LONG SDEAPI SE_reginfo_create          (SE_REGINFO  *registration);
extern LONG SDEAPI SE_reginfo_duplicate       (const SE_REGINFO  src_reginfo,
                                               SE_REGINFO        tgt_reginfo);
extern void SDEAPI SE_reginfo_free            (SE_REGINFO  registration);
extern BOOL SDEAPI SE_reginfo_allow_rowlocks  (SE_REGINFO  registration);
extern BOOL SDEAPI SE_reginfo_allows_interioredits 
                                              (SE_REGINFO  registration);
extern LONG SDEAPI SE_reginfo_get_access      (const SE_REGINFO  registration,
                                               LONG              *privileges);
extern LONG SDEAPI SE_reginfo_get_creation_keyword 
                                              (const SE_REGINFO  registration,
                                               CHAR *config_keyword);
extern LONG SDEAPI SE_reginfo_get_description (const SE_REGINFO  registration,
                                               CHAR              *description);
extern LONG SDEAPI SE_reginfo_get_id          (const SE_REGINFO  registration,
                                               LONG              *reg_id);
extern LONG SDEAPI SE_reginfo_get_mv_view_name(const SE_REGINFO  registration,
                                               CHAR             *im_view_name);
extern LONG SDEAPI SE_reginfo_get_minimum_id  (const SE_REGINFO  registration,
                                               ULONG             *minimum_id);
extern LONG SDEAPI SE_reginfo_get_reg_date    (const SE_REGINFO  registration,
                                               struct tm         *reg_date);
extern LONG SDEAPI SE_reginfo_get_rowid_allocation 
                                              (const SE_REGINFO  registration,
                                               LONG              *method);
extern LONG SDEAPI SE_reginfo_get_rowid_column 
                                              (const SE_REGINFO  registration,
                                               CHAR             *rowid_column,
                                               LONG              *type);
extern LONG SDEAPI SE_reginfo_get_table_name  (const SE_REGINFO  registration,
                                               CHAR              *table_name);
extern BOOL SDEAPI SE_reginfo_has_layer       (SE_REGINFO  registration);
extern BOOL SDEAPI SE_reginfo_has_locator     (SE_REGINFO  registration);
extern BOOL SDEAPI SE_reginfo_has_raster      (SE_REGINFO  registration);
extern BOOL SDEAPI SE_reginfo_has_xml         (SE_REGINFO  registration);
extern BOOL SDEAPI SE_reginfo_is_hidden (const SE_REGINFO  registration);
extern BOOL SDEAPI SE_reginfo_is_multiversion (SE_REGINFO  registration);
extern BOOL SDEAPI SE_reginfo_is_view         (SE_REGINFO  registration);
extern LONG SDEAPI SE_reginfo_set_creation_keyword 
                                              (SE_REGINFO  registration,
                                               const CHAR *config_keyword);
extern LONG SDEAPI SE_reginfo_set_description (SE_REGINFO  registration,
                                               const CHAR  *description);
extern LONG SDEAPI SE_reginfo_set_hidden      (SE_REGINFO  registration,
                                               BOOL        hidden);
extern LONG SDEAPI SE_reginfo_set_interioredits
                                              (SE_REGINFO  registration,
                                               BOOL        interioredits_ok);
extern LONG SDEAPI SE_reginfo_set_locator
                                              (SE_REGINFO  registration,
                                               BOOL        has_locator);
extern LONG SDEAPI SE_reginfo_set_minimum_id  (SE_REGINFO  registration,
                                               ULONG       minimum_id);
extern LONG SDEAPI SE_reginfo_set_multiversion 
                                              (SE_REGINFO  registration,
                                               BOOL        is_multiversion);
extern LONG SDEAPI SE_reginfo_set_rowlocks    (SE_REGINFO  registration,
                                               BOOL        allow_row_lock);
extern LONG SDEAPI SE_reginfo_set_rowid_allocation
                                              (SE_REGINFO  registration,
                                               LONG        method);
extern LONG SDEAPI SE_reginfo_set_rowid_column 
                                              (SE_REGINFO  registration,
                                               const CHAR  *rowid_column,
                                               LONG        type);
extern LONG SDEAPI SE_reginfo_set_table_name  (SE_REGINFO  registration,
                                               const CHAR  *table_name);
extern LONG SDEAPI SE_reginfo_set_view
                                              (SE_REGINFO  registration,
                                               BOOL        is_view);

/* Registration object functions. */

extern LONG SDEAPI SE_registration_alter          (SE_CONNECTION  connection,
                                                   SE_REGINFO     reginfo);
extern LONG SDEAPI SE_registration_create         (SE_CONNECTION  connection,
                                                   SE_REGINFO     reginfo);
extern LONG SDEAPI SE_registration_delete         (SE_CONNECTION  connection,
                                                   const CHAR     *name);
extern LONG SDEAPI SE_registration_get_difference_list 
                                                  (SE_CONNECTION  connection,
                                                   LONG           state1_id,
                                                   LONG           state2_id,
                                                   SE_REGINFO  **reg_list_addr,
                                                   LONG           *count_addr);
extern LONG SDEAPI SE_registration_get_info_by_id (SE_CONNECTION  connection,
                                                   LONG           reg_id,
                                                   SE_REGINFO     reginfo);
extern LONG SDEAPI SE_registration_get_info       (SE_CONNECTION  connection,
                                                   const CHAR     *table,
                                                   SE_REGINFO     reginfo);
extern LONG SDEAPI SE_registration_get_info_list  (SE_CONNECTION  connection,
                                                   SE_REGINFO  **reg_list_addr,
                                                   LONG           *count_addr);
extern void SDEAPI SE_registration_free_info_list (LONG           count,
                                                   SE_REGINFO     *reg_list);
extern LONG SDEAPI SE_registration_get_dependent_tables
                                                  (SE_CONNECTION  handle,
                                                   const CHAR     *table,
                                                   CHAR           ***table_list,
                                                   LONG           *table_count);
extern void SDEAPI SE_registration_free_dependent_tables
                                                  (CHAR  **table_list,
                                                   LONG  *table_count);


/* SQL constructor object functions */

extern void SDEAPI SE_sql_construct_free     (SE_SQL_CONSTRUCT  *constructor);

extern LONG SDEAPI SE_sql_construct_alloc    (LONG               num_tables,
                                              SE_SQL_CONSTRUCT **constructor);

/* Shape object functions */

extern LONG SDEAPI SE_shape_add_island     (SE_SHAPE            shape, 
                                            SE_SDEPOINT         *pointlist, 
                                            LONG                num_pts);
extern LONG SDEAPI SE_shape_add_part       (const SE_SHAPE      src_shape, 
                                            SE_SHAPE            tgt_shape);
extern LONG SDEAPI SE_shape_as_line        (const SE_SHAPE      src_shape, 
                                            SE_SHAPE            tgt_shape);
extern LONG SDEAPI SE_shape_as_point       (const SE_SHAPE      src_shape, 
                                            SE_SHAPE            tgt_shape);
extern LONG SDEAPI SE_shape_as_polygon     (const SE_SHAPE      src_shape, 
                                            SE_SHAPE            tgt_shape);
extern LONG SDEAPI SE_shape_as_simple_line (const SE_SHAPE      src_shape, 
                                            SE_SHAPE            tgt_shape);
extern LONG SDEAPI SE_shape_build          (SE_SHAPE            src_shape, 
                                            SE_BUILD_MODE       mode, 
                                            BOOL                dissolve, 
                                            LONG                match_mask, 
                                            SE_SHAPE            tgt_shape);
extern LONG SDEAPI SE_shape_calculate_distance
                                           (const SE_SHAPE      primary_shape, 
                                            const SE_SHAPE      secondary_shape,
                                            LFLOAT              *distance,
                                            BOOL                inside_test);
extern LONG SDEAPI SE_shape_change_coordref(const SE_SHAPE      src_shape, 
                                            SE_COORDREF         coordref, 
                                            PE_GEOGTRAN         geogtran,
                                            SE_SHAPE            tgt_shape);
extern LONG SDEAPI SE_shape_change_path    (SE_SHAPE            shape, 
                                            SE_SDEPOINT         *firstpt, 
                                            SE_SDEPOINT         *midpt, 
                                            SE_SDEPOINT         *lastpt, 
                                            SE_SDEPOINT         *pointlist, 
                                            LONG                num_pts);
extern LONG SDEAPI SE_shape_clip           (SE_SHAPE            src_shape, 
                                            SE_ENVELOPE         *window, 
                                            SE_SHAPE            tgt_shape);
extern LONG SDEAPI SE_shape_create         (SE_COORDREF         coordref, 
                                            SE_SHAPE            *shape);
extern LONG SDEAPI SE_shape_delete_island  (SE_SHAPE            shape, 
                                            SE_POINT            *pt);
extern LONG SDEAPI SE_shape_delete_part    (SE_SHAPE            shape, 
                                            LONG                part_num);
extern LONG SDEAPI SE_shape_delete_path    (SE_SHAPE            shape, 
                                            SE_SDEPOINT         *firstpt, 
                                            SE_SDEPOINT         *midpt, 
                                            SE_SDEPOINT         *lastpt);
extern LONG SDEAPI SE_shape_delete_point   (SE_SHAPE            shape, 
                                            SE_SDEPOINT         *pt);
extern LONG SDEAPI SE_shape_difference     (const SE_SHAPE      primary_shape, 
                                            const SE_SHAPE      secondary_shape,
                                            SE_SHAPE            tgt_shape);
extern LONG SDEAPI SE_shape_duplicate      (const SE_SHAPE      src_shape, 
                                            SE_SHAPE            tgt_shape);
extern LONG SDEAPI SE_shape_extend_line    (SE_SHAPE            shape, 
                                            SE_SDEPOINT         *endpoint, 
                                            SE_SDEPOINT         *pointlist, 
                                            LONG                num_pts);
extern LONG SDEAPI SE_shape_filter_coordinates 
                                           (const SE_SHAPE      src_shape, 
                                            LFLOAT              distance, 
                                            SE_SHAPE            tgt_shape);
extern LONG SDEAPI SE_shape_find_along     (SE_SHAPE            shape, 
                                            LFLOAT              measure, 
                                            LONG                *num_shapes, 
                                            SE_SHAPE            **new_shapes);
extern LONG SDEAPI SE_shape_find_between   (SE_SHAPE            shape, 
                                            LFLOAT              from_measure,
                                            LFLOAT              to_measure, 
                                            LONG                *num_shapes, 
                                            SE_SHAPE            **new_shapes);
extern LONG SDEAPI SE_shape_find_relation  (const SE_SHAPE      primary_shape,
                                            const SE_SHAPE      secondary_shape,
                                            LONG                *mask);
extern LONG SDEAPI SE_shape_find_CBM_relation (const SE_SHAPE   primary_shape,
                                            const SE_SHAPE      secondary_shape,
                                            SE_CBM_INFO                 *info) ;
extern LONG SDEAPI SE_shape_evaluate_CBM        (SE_CBM_INFO            *info,
                                            char                *scltext,
                                            BOOL                                *testresult);
extern void SDEAPI SE_shape_free           (SE_SHAPE            shape);
extern void SDEAPI SE_shape_free_array     (LONG                num_shapes,
                                            SE_SHAPE            *shapelist);
extern LONG SDEAPI SE_shape_generate_buffer(const SE_SHAPE      src_shape, 
                                            LFLOAT              distance, 
                                            LONG                max_pts, 
                                            SE_SHAPE            tgt_shape);
extern LONG SDEAPI SE_shape_generate_circle(SE_POINT            center, 
                                            LFLOAT              radius, 
                                            LONG                num_pts, 
                                            SE_SHAPE            tgt_shape);
extern LONG SDEAPI SE_shape_generate_convex_hull
                                           (SE_SHAPE            src_shape, 
                                            SE_SHAPE            tgt_shape);
extern LONG SDEAPI SE_shape_generate_ellipse
                                           (SE_POINT            center, 
                                            LFLOAT              semi_major_axis,
                                            LFLOAT              semi_minor_axis,
                                            LFLOAT              angle, 
                                            LONG                num_pts, 
                                            SE_SHAPE            tgt_shape);
extern LONG SDEAPI SE_shape_generate_from_part
                                           (const SE_SHAPE      src_shape, 
                                            LONG                part_num, 
                                            SE_SHAPE            tgt_shape);
extern LONG SDEAPI SE_shape_generate_label_point
                                           (const SE_SHAPE      shape, 
                                            SE_POINT           *pt);
extern LONG SDEAPI SE_shape_generate_line  (LONG                num_pts, 
                                            LONG                num_parts, 
                                            LONG               *part_offsets, 
                                            SE_POINT           *point_array, 
                                            LFLOAT             *z, 
                                            LFLOAT             *measure, 
                                            SE_SHAPE            tgt_shape);
extern LONG SDEAPI SE_shape_generate_point (LONG                num_pts, 
                                            SE_POINT           *point_array, 
                                            LFLOAT             *z, 
                                            LFLOAT             *measure, 
                                            SE_SHAPE            tgt_shape);
extern LONG SDEAPI SE_shape_generate_polygon
                                           (LONG                num_pts, 
                                            LONG                num_parts, 
                                            LONG               *part_offsets, 
                                            SE_POINT           *point_array, 
                                            LFLOAT             *z, 
                                            LFLOAT             *measure, 
                                            SE_SHAPE            tgt_shape);
extern LONG SDEAPI SE_shape_generate_rectangle
                                           (SE_ENVELOPE        *rect, 
                                            SE_SHAPE            tgt_shape);
extern LONG SDEAPI SE_shape_generate_simple_line  
                                           (LONG                num_pts, 
                                            LONG                num_parts, 
                                            LONG               *part_offsets, 
                                            SE_POINT           *point_array, 
                                            LFLOAT             *z, 
                                            LFLOAT             *measure, 
                                            SE_SHAPE            tgt_shape);
extern LONG SDEAPI SE_shape_get_3D_length  (const SE_SHAPE      shape, 
                                            LONG                part_num, 
                                            LFLOAT             *length);
extern LONG SDEAPI SE_shape_get_all_points (const SE_SHAPE      shape,
                                            SE_ROTATION_TYPE    rotation,
                                            LONG               *part_offsets, 
                                            LONG               *subpart_offsets,
                                            SE_POINT           *point_array, 
                                            LFLOAT             *z, 
                                            LFLOAT             *measure);
extern LONG SDEAPI SE_shape_get_anno       (const SE_SHAPE      shape,
                                            SE_ANNO             anno);
extern LONG SDEAPI SE_shape_get_area       (const SE_SHAPE      shape, 
                                            LONG                part_num, 
                                            LFLOAT             *area);
extern LONG SDEAPI SE_shape_get_coordref   (const SE_SHAPE      shape, 
                                            SE_COORDREF         coordref);
extern LONG SDEAPI SE_shape_get_extent     (const SE_SHAPE      shape, 
                                            LONG                part_num, 
                                            SE_ENVELOPE        *extent);
extern LONG SDEAPI SE_shape_get_length     (const SE_SHAPE      shape, 
                                            LONG                part_num, 
                                            LFLOAT             *length);
extern LONG SDEAPI SE_shape_get_Mrange     (const SE_SHAPE      shape, 
                                            LONG                part_num, 
                                            LFLOAT             *mmin, 
                                            LFLOAT             *mmax);
extern LONG SDEAPI SE_shape_get_num_parts  (const SE_SHAPE      shape, 
                                            LONG               *num_parts,
                                            LONG               *num_subparts);
extern LONG SDEAPI SE_shape_get_num_points (const SE_SHAPE      shape, 
                                            LONG                part_num, 
                                            LONG                subpart_num, 
                                            LONG               *num_pts);
extern LONG SDEAPI SE_shape_get_num_subparts
                                           (const SE_SHAPE      shape,
                                            LONG                part_num,
                                            LONG               *num_subparts);
extern LONG SDEAPI SE_shape_get_points     (const SE_SHAPE      shape, 
                                            LONG                part_num, 
                                            SE_ROTATION_TYPE    rotation,
                                            LONG               *subpart_offsets,
                                            SE_POINT           *point_array, 
                                            LFLOAT             *z, 
                                            LFLOAT             *measure);
extern LONG SDEAPI SE_shape_get_type       (const SE_SHAPE      shape, 
                                            LONG               *shape_type);
extern LONG SDEAPI SE_shape_get_Zrange     (const SE_SHAPE      shape, 
                                            LONG                part_num, 
                                            LFLOAT             *zmin, 
                                            LFLOAT             *zmax);
extern BOOL SDEAPI SE_shape_has_anno       (const SE_SHAPE      shape);
extern LONG SDEAPI SE_shape_insert_part    (const SE_SHAPE      src_shape, 
                                            LONG                part_num, 
                                            SE_SHAPE            tgt_shape);
extern LONG SDEAPI SE_shape_interpolate_by_measures
                                           (SE_SHAPE            src_shape, 
                                            LFLOAT              delta, 
                                            SE_SHAPE            tgt_shape);
extern LONG SDEAPI SE_shape_intersect      (const SE_SHAPE      primary_shape, 
                                            const SE_SHAPE      secondary_shape,
                                            LONG               *num_shapes, 
                                            SE_SHAPE          **new_shapes);
extern BOOL SDEAPI SE_shape_is_3D          (const SE_SHAPE      shape);
extern BOOL SDEAPI SE_shape_is_containing  (const SE_SHAPE     primary_shape,
                                            const SE_SHAPE     secondary_shape);
extern BOOL SDEAPI SE_shape_is_crossing    (const SE_SHAPE     primary_shape, 
                                            const SE_SHAPE     secondary_shape);
extern BOOL SDEAPI SE_shape_is_disjoint    (const SE_SHAPE     primary_shape, 
                                            const SE_SHAPE     secondary_shape);
extern BOOL SDEAPI SE_shape_is_equal       (const SE_SHAPE     primary_shape, 
                                            const SE_SHAPE     secondary_shape);
extern BOOL SDEAPI SE_shape_is_line        (const SE_SHAPE     shape);
extern BOOL SDEAPI SE_shape_is_measured    (const SE_SHAPE     shape);
extern BOOL SDEAPI SE_shape_is_multipart   (const SE_SHAPE     shape);
extern BOOL SDEAPI SE_shape_is_nil         (const SE_SHAPE     shape);
extern BOOL SDEAPI SE_shape_is_overlapping (const SE_SHAPE     primary_shape, 
                                            const SE_SHAPE     secondary_shape);
extern BOOL SDEAPI SE_shape_is_point       (const SE_SHAPE     shape);
extern BOOL SDEAPI SE_shape_is_polygon     (const SE_SHAPE     shape);
extern BOOL SDEAPI SE_shape_is_simple_line (const SE_SHAPE     shape);
extern BOOL SDEAPI SE_shape_is_touching    (const SE_SHAPE     primary_shape, 
                                            const SE_SHAPE     secondary_shape);
extern BOOL SDEAPI SE_shape_is_within      (const SE_SHAPE     primary_shape, 
                                            const SE_SHAPE     secondary_shape);
extern LONG SDEAPI SE_shape_make_nil       (SE_SHAPE           shape);
extern LONG SDEAPI SE_shape_move_point     (SE_SHAPE           shape, 
                                            SE_SDEPOINT        *from_pt, 
                                            SE_SDEPOINT        *to_pt);
extern LONG SDEAPI SE_shape_overlay        (const SE_SHAPE primary_shape, 
                                            const SE_SHAPE secondary_shape,
                                            LONG           *num_common_shapes,
                                            SE_SHAPE       primary_remainder, 
                                            SE_SHAPE       **common_shapes, 
                                            SE_SHAPE       secondary_remainder);
extern LONG SDEAPI SE_shape_replace_part   (const SE_SHAPE      src_shape, 
                                            LONG                part_num, 
                                            SE_SHAPE            tgt_shape);
extern LONG SDEAPI SE_shape_replace_path_with_arc 
                                           (SE_SHAPE            shape, 
                                            SE_SDEPOINT        *first_pt, 
                                            SE_SDEPOINT        *mid_pt, 
                                            SE_SDEPOINT        *last_pt, 
                                            LFLOAT              radius, 
                                            LONG                arc_segs);
extern LONG SDEAPI SE_shape_set_anno       (SE_SHAPE            shape,
                                            const SE_ANNO       anno);
extern LONG SDEAPI SE_shape_set_coordref   (SE_SHAPE            shape, 
                                            SE_COORDREF         coordref);
extern LONG SDEAPI SE_shape_symmetrical_difference
                                           (const SE_SHAPE      primary_shape, 
                                            const SE_SHAPE      secondary_shape,
                                            SE_SHAPE            tgt_shape);
extern LONG SDEAPI SE_shape_union          (const SE_SHAPE      primary_shape, 
                                            const SE_SHAPE      secondary_shape,
                                            SE_SHAPE            result_shape);


/* Shape i/o functions */

extern LONG SDEAPI SE_shape_as_text        (const SE_SHAPE      shape,
                                            LONG                alloc_size,
                                            CHAR               *text_shape);
extern LONG SDEAPI SE_shape_generate_from_text
                                           (const CHAR         *text_shape,
                                            SE_SHAPE           shape);
extern LONG SDEAPI SE_shape_get_text_size  (const SE_SHAPE      shape,
                                            LONG               *size);
extern LONG SDEAPI SE_shape_as_WKB         (const SE_SHAPE      shape,
                                            LONG                alloc_size,
                                            LONG               *binary_size,
                                            CHAR               *WKB_type);
extern LONG SDEAPI SE_shape_generate_from_WKB        
                                           (const CHAR         *WKB_type,
                                            SE_SHAPE            shape);
extern LONG SDEAPI SE_shape_get_WKB_size
                                           (const SE_SHAPE      shape,
                                            LONG               *size);
extern LONG SDEAPI SE_shape_as_binary      (const SE_SHAPE      shape,
                                            LONG                alloc_size,
                                            LONG               *binary_size,
                                            CHAR               *binary_type);
extern LONG SDEAPI SE_shape_generate_from_binary
                                           (const CHAR         *binary_type,
                                            SE_SHAPE            shape);
extern LONG SDEAPI SE_shape_get_binary_size
                                           (const SE_SHAPE      shape,
                                            LONG               *size);


/* Functions to manage spatial reference entries. */

extern LONG SDEAPI SE_spatialref_alter     (SE_CONNECTION     connection,
                                            SE_SPATIALREFINFO spatialref);
extern LONG SDEAPI SE_spatialref_create    (SE_CONNECTION     connection,
                                            SE_SPATIALREFINFO spatialref);
extern LONG SDEAPI SE_spatialref_delete    (SE_CONNECTION     connection,
                                            LONG              srid);
extern void SDEAPI SE_spatialref_free_info_list 
                                           (LONG         count,
                                            SE_SPATIALREFINFO *sref_list_addr);
extern LONG SDEAPI SE_spatialref_get_info  (SE_CONNECTION     connection,
                                            LONG              srid, 
                                            SE_SPATIALREFINFO spatialref);
extern LONG SDEAPI SE_spatialref_get_info_list 
                                           (SE_CONNECTION     connection, 
                                            SE_SPATIALREFINFO **sref_list_addr, 
                                            LONG              *count_addr);
					       
/* Functions to access and set spatial reference object properties */

extern LONG SDEAPI SE_spatialrefinfo_create
                                           (SE_SPATIALREFINFO *spatialref);
extern LONG SDEAPI SE_spatialrefinfo_duplicate 
                                           (const SE_SPATIALREFINFO src_sref, 
                                            SE_SPATIALREFINFO       tgt_sref);
extern void SDEAPI SE_spatialrefinfo_free  (SE_SPATIALREFINFO      spatialref);
extern LONG SDEAPI SE_spatialrefinfo_get_auth_name 
                                           (const SE_SPATIALREFINFO spatialref, 
                                            CHAR                    *auth_name);
extern LONG SDEAPI SE_spatialrefinfo_get_auth_srid
                                           (const SE_SPATIALREFINFO spatialref,
                                            LONG                    *auth_srid);
extern LONG SDEAPI SE_spatialrefinfo_get_coordref 
                                           (const SE_SPATIALREFINFO spatialref, 
                                            SE_COORDREF             coordref);
extern LONG SDEAPI SE_spatialrefinfo_get_description 
                                           (const SE_SPATIALREFINFO spatialref, 
                                            CHAR                 *description);
extern LONG SDEAPI SE_spatialrefinfo_get_srid 
                                           (const SE_SPATIALREFINFO spatialref,
                                            LONG                    *srid);
extern LONG SDEAPI SE_spatialrefinfo_set_auth_name 
                                           (SE_SPATIALREFINFO       spatialref,
                                            const CHAR              *auth_name);
extern LONG SDEAPI SE_spatialrefinfo_set_auth_srid 
                                           (SE_SPATIALREFINFO       spatialref, 
                                            LONG                    auth_srid);
extern LONG SDEAPI SE_spatialrefinfo_set_coordref 
                                           (SE_SPATIALREFINFO       spatialref, 
                                            SE_COORDREF             coordref);
extern LONG SDEAPI SE_spatialrefinfo_set_description 
                                           (SE_SPATIALREFINFO       spatialref, 
                                            const CHAR              *description);

/* Shape table object functions */

extern LONG SDEAPI SE_stable_add_shape       (SE_STABLE          stable,
                                              SE_SHAPE           shape,
                                              LONG               user_id,
                                              const void        *associated);
extern LONG SDEAPI SE_stable_create          (const SE_ENVELOPE *extent,
                                              SE_COORDREF        coordref,
                                              SE_STABLE         *stable);
extern LONG SDEAPI SE_stable_delete_shape    (SE_STABLE          stable,
                                              LONG               user_id);
extern void SDEAPI SE_stable_free            (SE_STABLE          stable);
extern LONG SDEAPI SE_stable_get_extent      (SE_STABLE          stable,
                                              SE_ENVELOPE       *extent);
extern LONG SDEAPI SE_stable_get_shape       (SE_STABLE          stable,
                                              LONG               user_id,
                                              SE_SHAPE           *shape_ptr,
                                              const void       **associatedptr);
extern LONG SDEAPI SE_stable_get_num_shapes  (SE_STABLE          stable);
extern LONG SDEAPI SE_stable_set_concurrency (SE_STABLE          stable,
                                              LONG               policy);
extern LONG SDEAPI SE_stable_size            (SE_STABLE          stable);
extern LONG SDEAPI SE_stable_search          (SE_STABLE          stable,
                                              SHORT              num_filters,
                                              const SE_FILTER   *filters,
                                              BOOL       (*func)
                                                 (void        *argument,
                                                  SE_SHAPE    shape,
                                                  const LONG  user_id,
                                                  const void  *associated,
                                                  SHORT       num_filters,
                                                  ULONG       *search_masks),
                                                  void        *argument);

/* State object functions */

extern LONG SDEAPI SE_state_close     (SE_CONNECTION         connection,
                                       LONG                  state_id);
extern LONG SDEAPI SE_state_compress_tree 
                                      (SE_CONNECTION         connection);
extern LONG SDEAPI SE_state_create    (SE_CONNECTION         connection,
                                       const SE_STATEINFO    state,
                                       LONG                  parent_state_id,
                                       SE_STATEINFO          result_state);
extern LONG SDEAPI SE_state_delete    (SE_CONNECTION         connection,
                                       LONG                  state_id);
extern LONG SDEAPI SE_state_delete_range 
                                      (SE_CONNECTION         connection,
                                       LONG                  low_state_id,
                                       LONG                  high_state_id);
extern void SDEAPI SE_state_free_info_list
                                      (LONG                  count,
                                       SE_STATEINFO          *state_list);
extern LONG SDEAPI SE_state_free_lock (SE_CONNECTION         connection,
                                       LONG                  state_id);
extern LONG SDEAPI SE_state_get_base_info (SE_CONNECTION         connection,
                                           LONG                  state_id,
                                           SE_STATEINFO          state);
extern LONG SDEAPI SE_state_get_info  (SE_CONNECTION         connection,
                                       LONG                  state_id,
                                       SE_STATEINFO          state);
extern LONG SDEAPI SE_state_get_info_list
                                      (SE_CONNECTION         connection,
                                       const CHAR            *where_clause,
                                       SE_STATEINFO          **state_list,
                                       LONG                  *count);
extern LONG SDEAPI SE_state_lock      (SE_CONNECTION         connection,
                                       LONG                  state_id);
extern LONG SDEAPI SE_state_merge     (SE_CONNECTION         connection,
                                       LONG                  parent_state_id,
                                       LONG                  changes_state_id,
                                       SE_STATEINFO          merged_state);
extern LONG SDEAPI SE_state_new_edit  (SE_CONNECTION         connection,
                                       const SE_STATEINFO    state,
                                       LONG                  parent_state_id,
                                       SE_STATEINFO          result_state);
extern LONG SDEAPI SE_state_open      (SE_CONNECTION         connection,
                                       LONG                  state_id);
extern LONG SDEAPI SE_state_trim_tree (SE_CONNECTION         connection,
                                       LONG                  low_state_id,
                                       LONG                  high_state_id);
                                         

/* Stateinfo object functions */

extern LONG SDEAPI SE_stateinfo_create (SE_STATEINFO        *state);
extern LONG SDEAPI SE_stateinfo_duplicate
                                       (const SE_STATEINFO  src_state,
                                        SE_STATEINFO        tgt_state);
extern void SDEAPI SE_stateinfo_free   (SE_STATEINFO        state);
extern void SDEAPI SE_stateinfo_free_lineage
                                       (LONG                  count,
                                        LONG                  *lineage);
extern LONG SDEAPI SE_stateinfo_get_closing_time
                                       (const SE_STATEINFO  state,
                                        struct tm           *closing_time);
extern LONG SDEAPI SE_stateinfo_get_creation_time
                                       (const SE_STATEINFO  state,
                                        struct tm           *created_time);
extern LONG SDEAPI SE_stateinfo_get_id (const SE_STATEINFO  state,
                                        LONG                *id);
extern LONG SDEAPI SE_stateinfo_get_lineage
                                        (const SE_STATEINFO  state,
                                         LONG                **lineage,
                                         LONG                *count);
extern LONG SDEAPI SE_stateinfo_get_owner
                                        (const SE_STATEINFO  state,
                                         CHAR                *owner);
extern LONG SDEAPI SE_stateinfo_get_parent
                                        (const SE_STATEINFO  state,
                                         LONG                *parent_id);
extern BOOL SDEAPI SE_stateinfo_is_open (const SE_STATEINFO  state);

/* Stream object functions */

extern LONG SDEAPI SE_stream_bind_input_column  (SE_STREAM     stream,
                                                 SHORT         column,
                                                 void          *data,
                                                 SHORT         *indicator);
extern LONG SDEAPI SE_stream_bind_output_column (SE_STREAM     stream,
                                                 SHORT         column,
                                                 void          *data,
                                                 SHORT         *indicator);
extern LONG SDEAPI SE_stream_calculate_layer_extent(SE_STREAM  stream,
                                        const SE_QUERYINFO     query_info,
                                        SE_ENVELOPE            *e,
                                        LFLOAT                 *minz,
                                        LFLOAT                 *maxz);
extern LONG SDEAPI SE_stream_calculate_layer_statistics(SE_STREAM stream,
                                        const SE_QUERYINFO     query_info,
                                        SE_LAYER_STATS         *stats);
extern LONG SDEAPI SE_stream_calculate_table_statistics(SE_STREAM stream,
                                        const CHAR             *column,
                                        LONG                   mask,
                                        const SE_QUERYINFO     query_info,
                                        LONG                   max_distinct,
                                        SE_STATS               **stats);
extern LONG SDEAPI SE_stream_copy_state_rows    (SE_STREAM   stream,
                                                 const CHAR  *table,
                                                 const LONG  *row_id_list,
                                                 LONG        row_id_count);

extern LONG SDEAPI SE_stream_create             (SE_CONNECTION connection,
                                                 SE_STREAM     *stream);
extern LONG SDEAPI SE_stream_describe_column    (SE_STREAM     stream,
                                                 SHORT         column,
                                                 SE_COLUMN_DEF *column_def);

extern LONG SDEAPI SE_stream_execute            (SE_STREAM     stream);

extern LONG SDEAPI SE_stream_fetch              (SE_STREAM     stream);

extern LONG SDEAPI SE_stream_fetch_row          (SE_STREAM     stream, 
                                                 const CHAR    *table,
                                                 LONG          sde_row_id,
                                                 SHORT         num_columns,
                                                 const CHAR    **columns);
extern LONG SDEAPI SE_stream_flush_buffered_writes(SE_STREAM   stream);
extern LONG SDEAPI SE_stream_free               (SE_STREAM     stream);
extern LONG SDEAPI SE_stream_close              (SE_STREAM     stream,
                                                 BOOL          reset);
extern LONG SDEAPI SE_stream_delete_from_table  (SE_STREAM     stream,
                                                 const CHAR    *table,
                                                 const CHAR    *where_clause);
extern LONG SDEAPI SE_stream_delete_by_id_list  (SE_STREAM     stream,
                                                 const CHAR    *table,
                                                 LONG          *id_list,
                                                 LONG          id_count);
extern LONG SDEAPI SE_stream_delete_row         (SE_STREAM     stream, 
                                                 const CHAR    *table,
                                                 LONG          sde_row_id);
extern LONG SDEAPI SE_stream_delete_table       (SE_STREAM     stream,
                                                 const CHAR    *table,
                                                 const CHAR    *where_clause);
extern LONG SDEAPI SE_stream_get_blob           (SE_STREAM     stream,
                                                 SHORT         column,
                                                 SE_BLOB_INFO  *blob_val);
extern LONG SDEAPI SE_stream_get_clob           (SE_STREAM     stream,
                                                 SHORT         column,
                                                 SE_CLOB_INFO  *clob_val);
extern LONG SDEAPI SE_stream_get_connection     (SE_STREAM     stream,
                                                 SE_CONNECTION *connection);
extern LONG SDEAPI SE_stream_get_double         (SE_STREAM     stream,
                                                 SHORT         column,
                                                 LFLOAT        *double_val);
extern LONG SDEAPI SE_stream_get_date           (SE_STREAM     stream,
                                                 SHORT         column,
                                                 struct tm     *date_val);
extern LONG SDEAPI SE_stream_get_ext_error      (SE_STREAM     stream,
                                                 SE_ERROR      *error);
extern LONG SDEAPI SE_stream_get_float          (SE_STREAM     stream,
                                                 SHORT         column,
                                                 FLOAT         *float_val);
extern LONG SDEAPI SE_stream_get_int64          (SE_STREAM     stream,
                                                 SHORT         column,
                                                 SE_INT64      *int64_val);
extern LONG SDEAPI SE_stream_get_integer        (SE_STREAM     stream,
                                                 SHORT         column,
                                                 LONG          *int_val);
extern LONG SDEAPI SE_stream_get_nclob          (SE_STREAM     stream,
                                                 SHORT         column,
                                                 SE_NCLOB_INFO *nclob_val);
extern LONG SDEAPI SE_stream_get_nstring        (SE_STREAM     stream,
                                                 SHORT         column,
                                                 SE_WCHAR      *string_val);
extern LONG SDEAPI SE_stream_get_shape          (SE_STREAM     stream,
                                                 SHORT         column,
                                                 SE_SHAPE      shape_val);
extern LONG SDEAPI SE_stream_get_smallint       (SE_STREAM     stream,
                                                 SHORT         column,
                                                 SHORT         *short_val);
extern LONG SDEAPI SE_stream_get_spatial_masks  (SE_STREAM     stream,
                                                 LONG          *masks);
extern LONG SDEAPI SE_stream_get_string         (SE_STREAM     stream,
                                                 SHORT         column,
                                                 CHAR          *string_val);
extern LONG SDEAPI SE_stream_get_uuid           (SE_STREAM     stream,
                                                 SHORT         column,
                                                 CHAR          *uuid_val);
extern LONG SDEAPI SE_stream_get_xml            (SE_STREAM     stream,
                                                 SHORT         column,
                                                 SE_XMLDOC     xml_val);
extern LONG SDEAPI SE_stream_invoke_ssa         (SE_STREAM     stream,
                                                 BOOL          query_stream,
                                                 SHORT         num_inputs,
                                                 SE_INPUT_DESC *input_desc,
                                                 void          **data,
                                                 const CHAR    *ssaName);
extern LONG SDEAPI SE_stream_insert_into_file   (SE_STREAM     stream, 
                                                 SE_FILEINFO   fileinfo,
                                                 SHORT         num_columns, 
                                                 const CHAR    **columns);
extern LONG SDEAPI SE_stream_insert_table       (SE_STREAM     stream, 
                                                 const char    *table, 
                                                 SHORT         num_columns, 
                                                 const CHAR    **columns);
extern LONG SDEAPI SE_stream_in_progress        (SE_STREAM     stream,
                                                 BOOL          *in_progress);
extern LONG SDEAPI SE_stream_last_inserted_row_id (SE_STREAM  stream,
                                                   LONG       *last_row_id);
extern LONG SDEAPI SE_stream_locate_table       (SE_STREAM stream,
                                                 const CHAR *table,
                                                 const CHAR *where,
                                                 SE_LOCATORINFO locator);
extern LONG SDEAPI SE_stream_locate_single      (SE_STREAM stream,
                                                 SE_LOCATORINFO locator,
                                                 SHORT num_inputs,
                                                 const SE_INPUT_DESC *input_desc,
                                                 const void **inputs);

extern LONG SDEAPI SE_stream_num_result_columns (SE_STREAM     stream,
                                                 SHORT         *num_columns);
extern LONG SDEAPI SE_stream_prepare_sql        (SE_STREAM     stream,
                                                 const CHAR    *sql_stmt);
extern LONG SDEAPI SE_stream_query              (SE_STREAM     stream, 
                                                 SHORT         num_columns,
                                                 const CHAR    **columns,
                                                 const SE_SQL_CONSTRUCT *construct);
extern LONG SDEAPI SE_stream_query_from_file    (SE_STREAM     stream,
                                                 SE_FILEINFO   fileinfo,
                                                 SHORT         num_columns,
                                                 const CHAR    **columns);
extern LONG SDEAPI SE_stream_query_logfile      (SE_STREAM     stream, 
                                                 const CHAR    *logfile,
                                                 SHORT         num_columns,
                                                 const CHAR    **columns,
                                                 const SE_SQL_CONSTRUCT *construct);
extern LONG SDEAPI SE_stream_query_with_info    
                                         (SE_STREAM              stream,
                                          const SE_QUERYINFO     query_info);
extern LONG SDEAPI SE_stream_query_rowid_by_uuid
                                         (SE_STREAM              stream,
                                          const CHAR             *table,
                                          const CHAR             *uuid_column,
                                          CHAR                   **uuid_array,
                                          LONG                   num_uuids,
                                          ULONG                  *not_found_bit_array,
                                          SE_LOGINFO             loginfo);
extern LONG SDEAPI SE_stream_restore_rows(SE_STREAM              stream,
                                          const CHAR             *table,
                                          const LONG             *row_id_list,
                                          LONG                   row_id_count);
extern LONG SDEAPI SE_stream_restore_rows_from_lineage_by_rowid
                                         (SE_STREAM              stream,
                                          const CHAR             *table,
                                          LONG                   *rowid_list,
                                          LONG                   row_id_count);
extern LONG SDEAPI SE_stream_set_blob    (SE_STREAM              stream, 
                                          SHORT                  column, 
                                          const SE_BLOB_INFO     *blob_val);
extern LONG SDEAPI SE_stream_set_clob    (SE_STREAM              stream,
                                          SHORT                  column,
                                          const SE_CLOB_INFO     *clob_val);
extern LONG SDEAPI SE_stream_set_date    (SE_STREAM              stream, 
                                          SHORT                  column, 
                                          const struct tm        *date_val);
extern LONG SDEAPI SE_stream_set_double  (SE_STREAM              stream, 
                                          SHORT                  column, 
                                          const LFLOAT           *double_val);
extern LONG SDEAPI SE_stream_set_float   (SE_STREAM              stream, 
                                          SHORT                  column, 
                                          const FLOAT            *float_val);
extern LONG SDEAPI SE_stream_set_int64   (SE_STREAM              stream, 
                                          SHORT                  column, 
                                          const SE_INT64         *int64_val);
extern LONG SDEAPI SE_stream_set_integer (SE_STREAM              stream, 
                                          SHORT                  column, 
                                          const LONG             *int_val);
extern LONG SDEAPI SE_stream_set_dynamic_bind
                                         (SE_STREAM              stream,
                                          SHORT                  position,
                                          LONG                   sde_type,
                                          LONG                   length,
                                          const void             *data,
                                          const SHORT            *indicator);
extern LONG SDEAPI SE_stream_set_logfile (SE_STREAM              stream,
                                          SE_LOG                 log,
                                          BOOL                   logfile_only);
extern LONG SDEAPI SE_stream_set_nclob   (SE_STREAM              stream,
                                          SHORT                  column,
                                          const SE_NCLOB_INFO    *nclob_val);
extern LONG SDEAPI SE_stream_set_nstring (SE_STREAM              stream, 
                                          SHORT                  column, 
                                          const SE_WCHAR         *string_val);
extern LONG SDEAPI SE_stream_set_output_coordref (SE_STREAM      stream,
                                          const SE_COORDREF      coordref,
                                          const PE_GEOGTRAN      geogtran);
extern LONG SDEAPI SE_stream_set_rowlocking
                                         (SE_STREAM              stream,
                                          LONG                   rowlck_action);
extern LONG SDEAPI SE_stream_set_row     (SE_STREAM              stream, 
                                          const CHAR             *table,
                                          LONG                   sde_row_id,
                                          SHORT                  num_columns,
                                          const CHAR             **columns);
extern LONG SDEAPI SE_stream_set_shape   (SE_STREAM              stream, 
                                          SHORT                  column, 
                                          const SE_SHAPE         shape_val);
extern LONG SDEAPI SE_stream_set_smallint
                                         (SE_STREAM              stream, 
                                          SHORT                  column, 
                                          const SHORT            *short_val);
extern LONG SDEAPI SE_stream_set_spatial_constraints 
                                         (SE_STREAM              stream,
                                          SHORT                  search_order,
                                          BOOL                   calc_masks,
                                          SHORT                  num_filters,
                                          SE_FILTER              *filters);
extern LONG SDEAPI SE_stream_set_ssa_filter
                                         (SE_STREAM              stream,
                                          const CHAR             *ssaName,
                                          const CHAR             *init_str);
extern LONG SDEAPI SE_stream_set_state   (SE_STREAM              stream,
                                          LONG                   source_id,
                                          LONG                   differences_id,
                                          LONG                  difference_type);
extern LONG SDEAPI SE_stream_set_string  (SE_STREAM              stream, 
                                          SHORT                  column, 
                                          const CHAR             *string_val);
extern LONG SDEAPI SE_stream_set_uuid    (SE_STREAM              stream, 
                                          SHORT                  column, 
                                          const CHAR             *uuid_val);
extern LONG SDEAPI SE_stream_set_write_mode
                                         (SE_STREAM              stream,
                                          BOOL                   buffered);
extern LONG SDEAPI SE_stream_set_invalidshape_mode(SE_STREAM stream,
                                                   BOOL      fetchinvalid);
extern LONG SDEAPI SE_stream_get_invalidshape_mode(SE_STREAM stream,
                                                   BOOL      *fetchinvalid);
extern LONG SDEAPI SE_stream_set_xml     (SE_STREAM              stream, 
                                          SHORT                  column, 
                                          const SE_XMLDOC        xml_val);
extern LONG SDEAPI SE_stream_update_ordered (SE_STREAM           stream,
                                             const CHAR          *table,
                                             LONG                *sde_row_id,
                                             const LONG          *id_list,
                                             LONG                id_count,
                                             SHORT               num_columns,
                                             const CHAR          **columns);
extern LONG SDEAPI SE_stream_update_row  (SE_STREAM     stream, 
                                          const CHAR    *table,
                                          LONG          *sde_row_id,
                                          SHORT         num_columns,
                                          const CHAR    **columns);
extern LONG SDEAPI SE_stream_update_sdodim_table (SE_STREAM     stream,
                                                  const CHAR    *table_name);
extern LONG SDEAPI SE_stream_update_table
                                         (SE_STREAM     stream, 
                                          const char    *table, 
                                          SHORT         num_columns, 
                                          const CHAR    **columns,
                                          const CHAR    *where);

/* Table object functions */

extern LONG SDEAPI SE_table_add_column   (SE_CONNECTION       connection,
                                          const CHAR          *table,
                                          const SE_COLUMN_DEF *column_def);

extern LONG SDEAPI SE_table_add_uuid_column(SE_CONNECTION   connection,
                                          const CHAR       *table,
                                          const CHAR       *column);

extern LONG SDEAPI SE_table_populate_uuid_column(SE_CONNECTION   connection,
                                          const CHAR       *table,
                                          const CHAR       *column);


extern LONG SDEAPI SE_table_alter_column (SE_CONNECTION        handle,
                                          const CHAR           *table,
                                          SE_COLUMNINFO        column);
extern LONG SDEAPI SE_table_create       (SE_CONNECTION       connection,
                                          const CHAR          *table,
                                          SHORT               num_columns,
                                          const SE_COLUMN_DEF *column_defs,
                                          const CHAR          *config_keyword);
extern LONG SDEAPI SE_table_create_mv_view (SE_CONNECTION  connection,
                                            const CHAR     *table,
                                            const CHAR     *im_view);
extern LONG SDEAPI SE_table_create_index (SE_CONNECTION       connection,
                                          const CHAR          *table,
                                          const CHAR          *column,
                                          BOOL                unique,
                                          BOOL                ascending,
                                          const CHAR          *index_name,
                                          const CHAR          *config_keyword);
extern LONG SDEAPI SE_table_create_indexes (SE_CONNECTION     connection,
                                            const CHAR              *table, 
                                            SHORT             num_indexes,
                                            SE_INDEX_DEF      *index_defs,
                                            const CHAR        *config_keyword);
extern LONG SDEAPI SE_table_create_primarykey_constraint (
                                            SE_CONNECTION  handle,
                                            const CHAR     *table,
                                            SHORT          num_columns,
                                            const CHAR     **columns,
                                            const CHAR     *constraint_name,
                                            const CHAR     *config_keyword);
extern LONG SDEAPI SE_table_create_unique_constraint (
                                            SE_CONNECTION  handle,
                                            const CHAR     *table,
                                            SHORT          num_columns,
                                            const CHAR     **columns,
                                            const CHAR     *constraint_name,
                                            const CHAR     *config_keyword);
extern LONG SDEAPI SE_table_create_view  (SE_CONNECTION     connection,
                                            const CHAR        *view,
                                            SHORT             num_view_columns,
                                            SHORT             num_table_columns,
                                            const CHAR        **view_columns,
                                            const CHAR        **table_columns,
                                            const SE_SQL_CONSTRUCT  *construct);
extern LONG SDEAPI SE_table_delete_constraint(SE_CONNECTION handle,
                                              const CHAR    *table,
                                              const CHAR    *constraint_name);
extern LONG SDEAPI SE_table_delete_mv_view (SE_CONNECTION  connection,
                                            const CHAR     *table);
extern LONG SDEAPI SE_table_delete_index (SE_CONNECTION       connection,
                                          const CHAR          *table,
                                          const CHAR          *index_name);
extern LONG SDEAPI SE_table_delete       (SE_CONNECTION       connection,
                                          const CHAR          *table);
extern LONG SDEAPI SE_table_describe     (SE_CONNECTION       connection,
                                          const CHAR          *table,
                                          SHORT               *num_columns,
                                          SE_COLUMN_DEF       **column_defs);
extern LONG SDEAPI SE_table_describe_indexes (SE_CONNECTION       connection,
                                            const CHAR          *table,
                                            SHORT               *num_indexes,
                                            SE_INDEX_DEF       **index_defs);
extern LONG SDEAPI SE_table_drop_column  (SE_CONNECTION       connection,
                                          const CHAR          *table,
                                          const CHAR          *column);
extern void SDEAPI SE_table_free_column_list (SHORT                column_count,
                                              SE_COLUMNINFO        *column_list);
extern void SDEAPI SE_table_free_descriptions(SE_COLUMN_DEF   *column_defs);
extern void SDEAPI SE_table_free_index_descriptions
                                           (LONG count,
                                            SE_INDEX_DEF  *index_def);
extern void SDEAPI SE_table_free_list       (LONG                num_tables,
                                             CHAR                **tables);
extern LONG SDEAPI SE_table_free_lock       (SE_CONNECTION      connection,
                                             const CHAR         *table);
extern void SDEAPI SE_table_free_locks      (SE_TABLE_LOCK      *lock_list,
                                             LONG               lock_count);
extern void SDEAPI SE_table_free_stats      (SE_STATS             *stats);
extern LONG SDEAPI SE_table_get_column_list (SE_CONNECTION        handle,
                                             const CHAR           *table,
                                             SE_COLUMNINFO        **column_list,
                                             SHORT                *column_count);
extern LONG SDEAPI SE_table_get_locks       (SE_CONNECTION      connection,
                                             const CHAR         *table,
                                             LONG               *num_locks,
                                             SE_TABLE_LOCK     **locks);
extern LONG SDEAPI SE_table_get_ids        (SE_CONNECTION       handle,
                                            const CHAR          *table,
                                            LONG                num_ids,
                                            LONG                *start_id,
                                            LONG                *id_count);
extern LONG SDEAPI SE_table_return_ids     (SE_CONNECTION       handle,
                                            const CHAR          *table,
                                            LONG                start_id,
                                            LONG                ids_returned);
extern LONG SDEAPI SE_table_get_mvedit_states (SE_CONNECTION  handle,
                                               const CHAR     *table,
                                               SE_STATEINFO   **state_list,
                                               LONG           *count);
extern LONG SDEAPI SE_table_get_permissions(SE_CONNECTION     connection,
                                          const CHAR          *table,
                                          LONG                *permissions);
extern LONG SDEAPI SE_table_grant_access (SE_CONNECTION       connection,
                                          const CHAR          *table,
                                          LONG                privilege,
                                          BOOL                grant,
                                          const CHAR          *user);
extern LONG SDEAPI SE_table_list         (SE_CONNECTION       connection,
                                          LONG                permissions,
                                          LONG                *num_tables,
                                          CHAR                ***tables);
extern LONG SDEAPI SE_table_lock            (SE_CONNECTION      connection,
                                             const CHAR         *table,
                                             LONG               lock_mode);
extern LONG SDEAPI SE_table_make_qualified_name 
                                            (SE_CONNECTION   handle,
                                             const CHAR      *database,
                                             const CHAR      *owner,
                                             const CHAR      *table,
                                             const CHAR      *column,
                                             CHAR            *qualified_name);
extern LONG SDEAPI SE_table_metadata_alter
                                     (SE_CONNECTION         handle,
                                     const CHAR             *table,
                                     LONG                   record_count,
                                     const SE_METADATAINFO  *metadata_records);
extern LONG SDEAPI SE_table_metadata_add
                                    (SE_CONNECTION          handle,
                                    const CHAR              *table,
                                    LONG                    record_count,
                                    const SE_METADATAINFO   *metadata_records);
extern LONG SDEAPI SE_table_metadata_delete (SE_CONNECTION   handle,
                                             const CHAR      *table,
                                             LONG            record_count,
                                             LONG            *record_id_list);
extern LONG SDEAPI SE_table_metadata_delete_where
                                            (SE_CONNECTION   handle,
                                             const CHAR      *table,
                                             const CHAR      *where_clause);
extern void SDEAPI SE_table_metadata_free_info_list
                                            (LONG            record_count,
                                             SE_METADATAINFO *metadata_list);
extern LONG SDEAPI SE_table_metadata_get_info_list
                                             (SE_CONNECTION     handle,
                                              const CHAR        *table,
                                              SE_METADATAINFO   **metadata_list,
                                              LONG              *record_count);
extern LONG SDEAPI SE_table_parse_qualified_name
                                             (SE_CONNECTION  handle,
                                              const CHAR      *qualified_name,
                                              CHAR            *database,
                                              CHAR            *owner,
                                              CHAR            *table,
                                              CHAR            *column,
                                              BOOL            iscolumn);
extern LONG SDEAPI SE_table_rebuild_index (SE_CONNECTION       connection,
                                           const CHAR          *table,
                                           LONG                index_mask);
extern LONG SDEAPI SE_table_rename       (SE_CONNECTION       connection,
                                          const CHAR          *old_name,
                                          const CHAR          *new_name);
extern LONG SDEAPI SE_table_revoke_access(SE_CONNECTION       connection,
                                          const CHAR          *table,
                                          LONG                privilege,
                                          const CHAR          *user);
extern LONG SDEAPI SE_table_truncate     (SE_CONNECTION       connection,
                                          const CHAR          *table);
                                          
extern LONG SDEAPI SE_table_update_dbms_stats  (SE_CONNECTION   connection,
                                                const CHAR     *table,
                                                const CHAR     *index,
                                                const CHAR     *mode,
                                                const LONG      keyword);

/* Table locator functions */

extern LONG SDEAPI SE_table_add_locator  (SE_CONNECTION        connection,
                                          const CHAR           *table,
                                          const SE_LOCATORINFO locator);

extern LONG SDEAPI SE_table_delete_locator  (SE_CONNECTION    connection,
                                             const CHAR       *table,
                                             const CHAR       *locator_name);

extern LONG SDEAPI SE_table_get_locator_list (SE_CONNECTION    connection,
                                             const CHAR    *table,
                                             SE_LOCATORINFO    **locator_list,
                                             LONG          *num_locators);

extern void SDEAPI SE_table_free_locator_list
                                        (LONG           num_locators,
                                         SE_LOCATORINFO *locator_list);

extern LONG SDEAPI SE_table_locate      (SE_CONNECTION handle,
                                         SE_LOCATORINFO locator,
                                         const CHAR *input_table,
                                         const CHAR *where_clause,
                                         LONG num_input_columns,
                                         const CHAR **input_columns,
                                         LONG num_key_columns,
                                         const CHAR **key_columns,
                                         LONG num_columns_to_copy,
                                         const CHAR **columns_to_copy,
                                         const CHAR *output_table,
                                         const CHAR *config_keyword);

extern LONG SDEAPI SE_table_rematch     (SE_CONNECTION connection,
                                         SE_LOCATORINFO locator,
                                         const CHAR *rematch_table,
                                         const CHAR *where_clause);
/* Table Row lock functions */

extern LONG SDEAPI SE_table_add_rowlocks      (SE_CONNECTION   connection,
                                               const CHAR     *table,
                                               LONG            num_locks,
                                               LONG           *row_ID,
                                               LONG            state_ID,
                                               LONG           *failed_rowID);
extern LONG SDEAPI SE_table_remove_rowlocks   (SE_CONNECTION   connection,
                                               const CHAR     *table,
                                               LONG            num_locks,
                                               LONG           *row_ID,
                                               LONG            state_ID,
                                               LONG           *failed_rowID);
extern LONG SDEAPI SE_table_get_rowlocks      (SE_CONNECTION   connection,
                                               const CHAR     *table,
                                               LONG           *num_locks,
                                               LONG          **row_ID,
                                               CHAR         ***user_names );
extern LONG SDEAPI SE_table_get_rowlocks_by_user
                                              (SE_CONNECTION   connection,
                                               const CHAR     *table,
                                               const CHAR     *user_name,
                                               LONG           *num_locks,
                                               LONG          **row_ID );
extern void SDEAPI SE_table_free_rowlocks_list
                                              (LONG            num_locks,
                                               LONG           *row_ID,
                                               CHAR          **user_name );
       /* See also SE_stream_set_rowlocking() */

/* Obsolete table function(s). */

extern LONG SDEAPI SE_table_calculate_stats
                                         (SE_CONNECTION       connection,
                                          const CHAR          *column,
                                          LONG                mask,
                                          const SE_SQL_CONSTRUCT *construct,
                                          LONG                max_distinct,
                                          SE_STATS            **stats);

/* Trace environment functions */

extern LONG SDEAPI SE_trace_on           (const CHAR *trace_log_name,
                                          CHAR      *trace_options);

extern LONG SDEAPI SE_trace_off          (void);

/* Transforminfo object functions */

extern LONG SDEAPI SE_transforminfo_create (SE_TRANSFORMINFO        *transform,
                                            LONG                    type);
extern void SDEAPI SE_transforminfo_free   (SE_TRANSFORMINFO        transform);
extern LONG SDEAPI SE_transforminfo_duplicate 
                                           (const SE_TRANSFORMINFO  src_xform,
                                            SE_TRANSFORMINFO        tgt_xform);
extern LONG SDEAPI SE_transforminfo_get_name 
                                           (const SE_TRANSFORMINFO  transform,
                                            CHAR                    *name);
extern LONG SDEAPI SE_transforminfo_set_name 
                                           (SE_TRANSFORMINFO        transform,
                                            const CHAR              *name);
extern LONG SDEAPI SE_transforminfo_get_type 
                                           (const SE_TRANSFORMINFO  transform,
                                            SE_TRANSFORM_TYPE       *type);
extern LONG SDEAPI SE_transforminfo_get_coordsys 
                                           (const SE_TRANSFORMINFO  transform,
                                            PE_COORDSYS             *cs);
extern LONG SDEAPI SE_transforminfo_get_geogtran 
                                           (const SE_TRANSFORMINFO  transform,
                                           PE_GEOGTRAN              *geogtran);
extern LONG SDEAPI SE_transforminfo_set_coordsys 
                                           (SE_TRANSFORMINFO        transform,
                                            const PE_COORDSYS       cs);
extern LONG SDEAPI SE_transforminfo_set_geogtran 
                                           (SE_TRANSFORMINFO        transform,
                                            const PE_GEOGTRAN       geogtran);
extern LONG SDEAPI SE_transforminfo_get_polynomial 
                                           (const SE_TRANSFORMINFO  transform,
                                            SE_POLYNOMIAL_TYPE      *type,
                                            LFLOAT                  **poly);
extern LONG SDEAPI SE_transforminfo_set_polynomial 
                                           (SE_TRANSFORMINFO        transform,
                                            SE_POLYNOMIAL_TYPE      type,
                                            const LFLOAT            *poly);
extern LONG SDEAPI SE_transforminfo_get_custom 
                                           (const SE_TRANSFORMINFO  transform,
                                            LONG                    *type,
                                            LONG                    *length,
                                            void                    **data);
extern LONG SDEAPI SE_transforminfo_set_custom 
                                           (SE_TRANSFORMINFO        transform,
                                            LONG                    type,
                                            LONG                    length,
                                            const void              *data);
/* UUID generation functions. */

extern LONG SDEAPI SE_uuidgenerator_create   (SE_UUIDGENERATOR  *uuid_generator);
extern void SDEAPI SE_uuidgenerator_free     (SE_UUIDGENERATOR  uuid_generator);
extern LONG SDEAPI SE_uuidgenerator_get_uuids  (SE_UUIDGENERATOR  uuid_generator,
                                                LONG              uuid_count,
                                                CHAR              ***uuid_list);
extern void SDEAPI SE_uuidgenerator_free_uuids (CHAR             **uuid_list,
                                                LONG             uuid_count);

/* Version object functions */

extern LONG SDEAPI SE_version_alter     (SE_CONNECTION         connection,
                                         const SE_VERSIONINFO  version);
extern LONG SDEAPI SE_version_change_state
                                        (SE_CONNECTION         connection,
                                         const SE_VERSIONINFO  version,
                                         LONG                  new_state_id);
extern LONG SDEAPI SE_version_create    (SE_CONNECTION         connection,
                                         const SE_VERSIONINFO  version,
                                         BOOL                  unique_name,
                                         SE_VERSIONINFO        result_version);
extern LONG SDEAPI SE_version_delete    (SE_CONNECTION         connection,
                                         const CHAR            *name);
extern void SDEAPI SE_version_free_info_list
                                        (LONG                  count,
                                         SE_VERSIONINFO        *version_list);
extern LONG SDEAPI SE_version_free_lock (SE_CONNECTION         connection,
                                         const CHAR            *version_name);
extern void SDEAPI SE_version_free_locks (SE_VERSION_LOCK       *lock_list,
                                         LONG                  lock_count);
extern LONG SDEAPI SE_version_get_info  (SE_CONNECTION         connection,
                                         const CHAR            *version_name,
                                         SE_VERSIONINFO        version);
extern LONG SDEAPI SE_version_get_info_by_id 
                                        (SE_CONNECTION         connection,
                                         LONG                  version_id,
                                         SE_VERSIONINFO        version);
extern LONG SDEAPI SE_version_get_info_list
                                        (SE_CONNECTION         connection,
                                         const CHAR            *where_clause,
                                         SE_VERSIONINFO        **version_list,
                                         LONG                  *count);
extern LONG SDEAPI SE_version_get_locks (SE_CONNECTION         connection,
                                         const CHAR            *version_names,
                                         LONG                  *num_locks,
                                         SE_VERSION_LOCK       **locks);
extern LONG SDEAPI SE_version_lock      (SE_CONNECTION         connection,
                                         const CHAR            *version_name,
                                         LONG                  lock_mode);
extern LONG SDEAPI SE_version_rename    (SE_CONNECTION         connection,
                                         const CHAR            *old_name,
                                         const CHAR            *new_name);

/* Versioninfo object functions */

extern LONG SDEAPI SE_versioninfo_create(SE_VERSIONINFO        *version);
extern LONG SDEAPI SE_versioninfo_duplicate
                                        (const SE_VERSIONINFO  src_version,
                                         SE_VERSIONINFO        tgt_version);
extern void SDEAPI SE_versioninfo_free  (SE_VERSIONINFO        version);
extern LONG SDEAPI SE_versioninfo_get_access
                                        (const SE_VERSIONINFO  version,
                                         LONG                  *access);
extern LONG SDEAPI SE_versioninfo_get_creation_time
                                        (const SE_VERSIONINFO  version,
                                         struct tm             *created_time);
extern LONG SDEAPI SE_versioninfo_get_description
                                        (const SE_VERSIONINFO  version,
                                         CHAR                  *description);
extern LONG SDEAPI SE_versioninfo_get_id (const SE_VERSIONINFO  version,
                                          LONG                  *version_id);
extern LONG SDEAPI SE_versioninfo_get_name
                                        (const SE_VERSIONINFO  version,
                                         CHAR                  *name);
extern LONG SDEAPI SE_versioninfo_get_parent_id 
                                        (const SE_VERSIONINFO  version,
                                         LONG                  *parent_id);
extern LONG SDEAPI SE_versioninfo_get_parent_name
                                        (const SE_VERSIONINFO  version,
                                         CHAR                  *parent_name);
extern LONG SDEAPI SE_versioninfo_get_state_id
                                        (const SE_VERSIONINFO  version,
                                         LONG                  *state_id);
extern LONG SDEAPI SE_versioninfo_set_access
                                        (SE_VERSIONINFO        version,
                                         LONG                  access);
extern LONG SDEAPI SE_versioninfo_set_description
                                        (SE_VERSIONINFO        version,
                                         const CHAR            *description);
extern LONG SDEAPI SE_versioninfo_set_name
                                        (SE_VERSIONINFO        version,
                                         const CHAR            *name);
extern LONG SDEAPI SE_versioninfo_set_parent_name
                                        (SE_VERSIONINFO        version,
                                         const CHAR            *parent_name);
extern LONG SDEAPI SE_versioninfo_set_state_id
                                        (SE_VERSIONINFO        version,
                                         LONG                  state_id);

/* XMLCOLUMN object functions */

extern LONG SDEAPI SE_xmlcolumn_alter      (SE_CONNECTION          handle,
                                            const SE_XMLCOLUMNINFO xmlcolumn);
extern LONG SDEAPI SE_xmlcolumn_create     (SE_CONNECTION          handle,
                                            const SE_XMLCOLUMNINFO xmlcolumn);
extern LONG SDEAPI SE_xmlcolumn_delete     (SE_CONNECTION          handle,
                                            const CHAR             *table,
                                            const CHAR             *column);
extern LONG SDEAPI SE_xmlcolumn_get_info   (SE_CONNECTION          handle,
                                            const CHAR             *table,
                                            const CHAR             *column,
                                            SE_XMLCOLUMNINFO       xmlcolumn);

/* XMLCOLUMNINFO object functions */

extern LONG SDEAPI SE_xmlcolumninfo_create (
                      SE_XMLCOLUMNINFO       *xmlcolumn);
extern void SDEAPI SE_xmlcolumninfo_free (
                      SE_XMLCOLUMNINFO       xmlcolumn);
extern LONG SDEAPI SE_xmlcolumninfo_get_creation_keyword (
                      const SE_XMLCOLUMNINFO xmlcolumn,
                      CHAR                   *config_keyword);
extern LONG SDEAPI SE_xmlcolumninfo_get_index (
                      const SE_XMLCOLUMNINFO xmlcolumn,
                      SE_XMLINDEXINFO        index);
extern LONG SDEAPI SE_xmlcolumninfo_get_id (
                      const SE_XMLCOLUMNINFO xmlcolumn,
                      LONG                   *xmlcolumn_id);
extern LONG SDEAPI SE_xmlcolumninfo_get_minimum_id (
                      const SE_XMLCOLUMNINFO xmlcolumn,
                      LONG                   *minimum_id);
extern LONG SDEAPI SE_xmlcolumninfo_get_xml_column (
                      const SE_XMLCOLUMNINFO xmlcolumn,
                      CHAR                   *table,
                      CHAR                   *column_name);
extern BOOL SDEAPI SE_xmlcolumninfo_has_index (
                      const SE_XMLCOLUMNINFO xmlcolumn);
extern BOOL SDEAPI SE_xmlcolumninfo_is_in_load_mode(
                      const SE_XMLCOLUMNINFO  xmlcolumn);
extern BOOL SDEAPI SE_xmlcolumninfo_is_in_uncompressed_mode 
                      (const SE_XMLCOLUMNINFO  xmlcolumn);
extern LONG SDEAPI SE_xmlcolumninfo_set_creation_keyword (
                      SE_XMLCOLUMNINFO xmlcolumn,
                      const CHAR       *config_keyword);
extern LONG SDEAPI SE_xmlcolumninfo_set_index (
                      SE_XMLCOLUMNINFO       xmlcolumn,
                      const SE_XMLINDEXINFO  index);
extern LONG SDEAPI SE_xmlcolumninfo_set_load_mode(
                      SE_XMLCOLUMNINFO xmlcolumn,
                      BOOL             is_in_load_mode);
extern LONG SDEAPI SE_xmlcolumninfo_set_minimum_id (
                      SE_XMLCOLUMNINFO xmlcolumn,
                      LONG             minimum_id);
extern LONG SDEAPI SE_xmlcolumninfo_set_uncompress_mode 
                     (SE_XMLCOLUMNINFO xmlcolumn);
extern LONG SDEAPI SE_xmlcolumninfo_set_xml_column (
                      SE_XMLCOLUMNINFO xmlcolumn,
                      const CHAR       *table,
                      const CHAR       *column_name);


/* XMLDOC object functions */

extern LONG SDEAPI SE_xmldoc_create            (SE_XMLDOC         *xml_doc);
extern void SDEAPI SE_xmldoc_free              (SE_XMLDOC         xml_doc);
extern LONG SDEAPI SE_xmldoc_get_length        (const SE_XMLDOC   xml_doc,
                                                LONG              *length);
extern LONG SDEAPI SE_xmldoc_get_tag_conflicts  
                                         (SE_CONNECTION          handle,
                                          const SE_XMLDOC        xml_doc,
                                          const SE_XMLINDEXINFO  xml_index,
                                          LONG                   *num_tag_conflicts,
                                          SE_XMLTAGINFO          **tags);

extern LONG SDEAPI SE_xmldoc_get_text          (const SE_XMLDOC   xml_doc,
                                                void              *text);
extern LONG SDEAPI SE_xmldoc_set_text          (SE_XMLDOC         xml_doc,
                                                LONG              num_bytes,
                                                const void        *text);

/* XML index functions */

extern LONG SDEAPI SE_xmlindex_alter_template  (SE_CONNECTION         handle,
                                                const SE_XMLINDEXINFO xml_index);
extern LONG SDEAPI SE_xmlindex_create_template (SE_CONNECTION         handle,
                                                const SE_XMLINDEXINFO xml_index);
extern LONG SDEAPI SE_xmlindex_delete_template (SE_CONNECTION     handle,
                                                const CHAR        *index_name);
extern LONG SDEAPI SE_xmlindex_update_text_index (SE_CONNECTION     handle,
                                                const CHAR        *table,
												const CHAR        *column);
extern void SDEAPI SE_xmlindex_free_info_list  (LONG            count,
                                                SE_XMLINDEXINFO *xml_index_list);
extern LONG SDEAPI SE_xmlindex_get_info        (SE_CONNECTION     handle,
                                                const CHAR        *index_name,
                                                SE_XMLINDEXINFO   xml_index);
extern LONG SDEAPI SE_xmlindex_get_info_list   (SE_CONNECTION   handle,
                                                SE_XMLINDEXINFO **xml_index_list,
                                                LONG            *count_addr);


/* XMLINDEXINFO object functions */

extern LONG SDEAPI SE_xmlindexinfo_add_tag (SE_XMLINDEXINFO     xml_index,
                                            const SE_XMLTAGINFO tag);
extern LONG SDEAPI SE_xmlindexinfo_create (SE_XMLINDEXINFO  *xml_index);
extern LONG SDEAPI SE_xmlindexinfo_delete_tags  (SE_XMLINDEXINFO xml_index);
extern void SDEAPI SE_xmlindexinfo_free   (SE_XMLINDEXINFO  xml_index);
extern LONG SDEAPI SE_xmlindexinfo_get_description (
                                      const SE_XMLINDEXINFO xml_index,
                                      CHAR                  *description);
extern LONG SDEAPI SE_xmlindexinfo_get_name (const SE_XMLINDEXINFO xml_index,
                                             CHAR                  *name);
extern LONG SDEAPI SE_xmlindexinfo_get_tags (const SE_XMLINDEXINFO xml_index,
                                             LONG                  *num_tags,
                                             SE_XMLTAGINFO         **tags);
extern LONG SDEAPI SE_xmlindexinfo_get_type (const SE_XMLINDEXINFO xml_index,
                                             LONG                  *index_type);
extern LONG SDEAPI SE_xmlindexinfo_generate_from_doc(
                                      SE_CONNECTION     handle,
                                      SE_XMLINDEXINFO   xml_index,
                                      const SE_XMLDOC   xml_doc);
extern LONG SDEAPI SE_xmlindexinfo_set_description(
                                      SE_XMLINDEXINFO xml_index,
                                      const CHAR      *description);
extern LONG SDEAPI SE_xmlindexinfo_set_name (SE_XMLINDEXINFO xml_index,
                                             const CHAR      *name);
extern LONG SDEAPI SE_xmlindexinfo_set_type (SE_XMLINDEXINFO xml_index,
                                             LONG            index_type);

/* XMLTAGINFO object functions */

extern LONG SDEAPI SE_xmltaginfo_create        (SE_XMLTAGINFO       *xml_tag);
extern void SDEAPI SE_xmltaginfo_free          (SE_XMLTAGINFO       xml_tag);
extern void SDEAPI SE_xmltaginfo_free_array    (LONG 		        num_tags,
                                                SE_XMLTAGINFO       *tags);
extern LONG SDEAPI SE_xmltaginfo_get_alias     (const SE_XMLTAGINFO xml_tag,
                                                LONG                *alias);
extern LONG SDEAPI SE_xmltaginfo_get_data_type (const SE_XMLTAGINFO xml_tag,
                                                LONG                *data_type);
extern LONG SDEAPI SE_xmltaginfo_get_description 
                                     (const SE_XMLTAGINFO xml_tag,
                                      CHAR                *description);
extern LONG SDEAPI SE_xmltaginfo_get_name        (const SE_XMLTAGINFO xml_tag,
                                                  CHAR                *name);
extern BOOL SDEAPI SE_xmltaginfo_is_excluded     (const SE_XMLTAGINFO xml_tag);
extern LONG SDEAPI SE_xmltaginfo_set_alias       (SE_XMLTAGINFO xml_tag,
                                                  LONG          alias);
extern LONG SDEAPI SE_xmltaginfo_set_data_type   (SE_XMLTAGINFO xml_tag,
                                                  LONG          data_type);
extern LONG SDEAPI SE_xmltaginfo_set_description (SE_XMLTAGINFO xml_tag,
                                                  const CHAR    *description);
extern LONG SDEAPI SE_xmltaginfo_set_exclusion   (SE_XMLTAGINFO xml_tag,
                                                  BOOL          is_excluded);
extern LONG SDEAPI SE_xmltaginfo_set_name        (SE_XMLTAGINFO xml_tag,
                                                  const CHAR    *name);

/* Server Information object functions */

extern LONG SDEAPI SE_serverconfig_get_info        (SE_CONNECTION  handle,
                                                    SE_SERVERINFO  svrInfo);
extern LONG SDEAPI SE_serverconfig_alter           (SE_CONNECTION     handle,
                                                    const SE_SERVERINFO svrInfo,
                                                    SE_SVR_CONFIG_ERR *svr_conf_err_data);
extern LONG SDEAPI SE_serverinfo_create            (SE_SERVERINFO  *svrInfo);
extern void SDEAPI SE_serverinfo_free              (SE_SERVERINFO  svrInfo);
extern LONG SDEAPI SE_serverinfo_get_tempdir       (const SE_SERVERINFO  svrInfo,
                                                    CHAR                 *tempdir);
extern LONG SDEAPI SE_serverinfo_set_tempdir       (SE_SERVERINFO svrInfo,
                                                    const CHAR    *tempdir);
extern LONG SDEAPI SE_serverinfo_get_maxconnections(const SE_SERVERINFO  svrInfo,
                                                    LONG  *conns);
extern LONG SDEAPI SE_serverinfo_set_maxconnections(SE_SERVERINFO svrInfo,
                                                    LONG          conns);
extern LONG SDEAPI SE_serverinfo_get_minbufsize    (const SE_SERVERINFO svrInfo,
                                                    LONG  *bufsize);
extern LONG SDEAPI SE_serverinfo_set_minbufsize    (SE_SERVERINFO svrInfo,
                                                    LONG          bufsize);
extern LONG SDEAPI SE_serverinfo_get_maxbufsize    (const SE_SERVERINFO svrInfo,
                                                    LONG  *bufsize);
extern LONG SDEAPI SE_serverinfo_set_maxbufsize    (SE_SERVERINFO svrInfo,
                                                    LONG          bufsize);
extern LONG SDEAPI SE_serverinfo_get_minbufobjects (const SE_SERVERINFO  svrInfo,
                                                    LONG  *bufobjects);
extern LONG SDEAPI SE_serverinfo_set_minbufobjects (SE_SERVERINFO svrInfo,
                                                    LONG          bufobjects);
extern LONG SDEAPI SE_serverinfo_get_maxblobsize   (const SE_SERVERINFO  svrInfo,
                                                    LONG  *blobsize);
extern LONG SDEAPI SE_serverinfo_set_maxblobsize   (SE_SERVERINFO svrInfo,
                                                    LONG          blobsize);
extern LONG SDEAPI SE_serverinfo_get_blobmem       (const SE_SERVERINFO  svrInfo,
                                                    LONG  *blobmem);
extern LONG SDEAPI SE_serverinfo_set_blobmem       (SE_SERVERINFO svrInfo,
                                                    LONG          blobmem);
extern LONG SDEAPI SE_serverinfo_get_autocommit    (const SE_SERVERINFO  svrInfo,
                                                    LONG  *autocommit);
extern LONG SDEAPI SE_serverinfo_set_autocommit    (SE_SERVERINFO svrInfo,
                                                    LONG          autocommit);
extern LONG SDEAPI SE_serverinfo_get_maxinitialfeats(const SE_SERVERINFO svrInfo,
                                                    LONG  *initfeats);
extern LONG SDEAPI SE_serverinfo_set_maxinitialfeats(SE_SERVERINFO svrInfo,
                                                    LONG          initfeats);
extern LONG SDEAPI SE_serverinfo_get_maxdistinct   (const SE_SERVERINFO  svrInfo,
                                                    LONG  *distinct);
extern LONG SDEAPI SE_serverinfo_set_maxdistinct   (SE_SERVERINFO svrInfo,
                                                    LONG          distinct);
extern LONG SDEAPI SE_serverinfo_get_streampoolsize(const SE_SERVERINFO svrInfo,
                                                    LONG  *streampool);
extern LONG SDEAPI SE_serverinfo_set_streampoolsize(SE_SERVERINFO svrInfo,
                                                    LONG          streampool);
extern LONG SDEAPI SE_serverinfo_get_shapeptsbufsize(const SE_SERVERINFO  svrInfo,
                                                    LONG  *ptsbufsize);
extern LONG SDEAPI SE_serverinfo_set_shapeptsbufsize(SE_SERVERINFO svrInfo,
                                                    LONG          ptsbufsize);
extern LONG SDEAPI SE_serverinfo_get_attrbufsize   (const SE_SERVERINFO  svrInfo,
                                                    LONG  *attrbuf);
extern LONG SDEAPI SE_serverinfo_set_attrbufsize   (SE_SERVERINFO svrInfo,
                                                    LONG          attrbuf);
extern LONG SDEAPI SE_serverinfo_get_rasterbufsize (const SE_SERVERINFO svrInfo,
                                                    LONG  *rasterbuf);
extern LONG SDEAPI SE_serverinfo_set_rasterbufsize (SE_SERVERINFO svrInfo,
                                                    LONG          rasterbuf);
extern LONG SDEAPI SE_serverinfo_get_maxarraysize  (const SE_SERVERINFO  svrInfo,
                                                    LONG  *maxarray);
extern LONG SDEAPI SE_serverinfo_set_maxarraysize  (SE_SERVERINFO svrInfo,
                                                    LONG          maxarray);
extern LONG SDEAPI SE_serverinfo_get_maxarraybytes (const SE_SERVERINFO svrInfo,
                                                    LONG  *arraybytes);
extern LONG SDEAPI SE_serverinfo_set_maxarraybytes (SE_SERVERINFO svrInfo,
                                                    LONG  arraybytes);
extern LONG SDEAPI SE_serverinfo_get_maxtimediff   (const SE_SERVERINFO  svrInfo,
                                                    LONG  *timediff);
extern LONG SDEAPI SE_serverinfo_set_maxtimediff   (SE_SERVERINFO svrInfo,
                                                    LONG  timediff);
extern LONG SDEAPI SE_serverinfo_get_stateautolocking  
                                                   (const SE_SERVERINFO  svrInfo,
                                                    BOOL  *stateautolock);
extern LONG SDEAPI SE_serverinfo_set_stateautolocking
                                                   (SE_SERVERINFO svrInfo,
                                                    BOOL   stateautolock);
extern LONG SDEAPI SE_serverinfo_get_tcpkeepalive  (const SE_SERVERINFO svrInfo,
                                                    BOOL  *tcpkeepalive);
extern LONG SDEAPI SE_serverinfo_set_tcpkeepalive  (SE_SERVERINFO svrInfo,
                                                    BOOL  tcpkeepalive);
extern LONG SDEAPI SE_serverinfo_get_readonly      (const SE_SERVERINFO svrInfo,
                                                    BOOL  *readonly);
extern LONG SDEAPI SE_serverinfo_set_readonly      (SE_SERVERINFO svrInfo,
                                                    BOOL  readonly);
extern LONG SDEAPI SE_serverinfo_get_defaultprecision
                                                   (const SE_SERVERINFO svrInfo,
                                                    LONG  *precision);
extern LONG SDEAPI SE_serverinfo_set_defaultprecision
                                                   (SE_SERVERINFO svrInfo,
                                                    LONG  precision);
extern LONG SDEAPI SE_serverinfo_get_tlm_interval
                                                   (const SE_SERVERINFO svrInfo,
                                                    LONG  *tlm_interval);
extern LONG SDEAPI SE_serverinfo_set_tlm_interval
                                                   (SE_SERVERINFO svrInfo,
                                                    LONG  tlm_interval);
extern LONG SDEAPI SE_serverinfo_get_logfilepoolsize
                                 (const SE_SERVERINFO  svrInfo,
                                  LONG                 *logfilepoolsize);
extern LONG SDEAPI SE_serverinfo_set_logfilepoolsize
                                 (SE_SERVERINFO        svrInfo,
                                  LONG                 logfilepoolsize);
extern LONG SDEAPI SE_serverinfo_get_maxstandalonelogs
                                  (const SE_SERVERINFO svrInfo,
                                   LONG                *maxstandalonelogs);
extern LONG SDEAPI SE_serverinfo_set_maxstandalonelogs
                                  (SE_SERVERINFO       svrInfo,
                                   LONG                maxstandalonelogs);
extern LONG SDEAPI SE_serverinfo_get_allowsessionlogfile
                                  (const SE_SERVERINFO svrInfo,
                                   BOOL                *allowsessionlogfile);
extern LONG SDEAPI SE_serverinfo_set_allowsessionlogfile
                                  (SE_SERVERINFO       svrInfo,
                                   BOOL                allowsessionlogfile);
extern LONG SDEAPI SE_serverinfo_get_holdlogpooltables
                                  (const SE_SERVERINFO svrInfo,
                                   BOOL                *holdlogpooltables);
extern LONG SDEAPI SE_serverinfo_set_holdlogpooltables
                                  (SE_SERVERINFO       svrInfo,
                                   BOOL                holdlogpooltables);
extern LONG SDEAPI SE_serverinfo_get_largeidblock 
                                  (const SE_SERVERINFO svrInfo,
                                   LONG                *LargeIdBlock);
extern LONG SDEAPI SE_serverinfo_set_largeidblock 
                                  (SE_SERVERINFO       svrInfo,
                                   LONG                LargeIdBlock);
extern LONG SDEAPI SE_serverinfo_get_smallidblock 
                                  (const SE_SERVERINFO svrInfo,
                                   LONG                *SmallIdBlock);
extern LONG SDEAPI SE_serverinfo_set_smallidblock 
                                  (SE_SERVERINFO       svrInfo,
                                   LONG                SmallIdBlock);
extern LONG SDEAPI SE_serverinfo_get_procstats 
                                  (const SE_SERVERINFO svrInfo,
                                   LONG                *Procstats);
extern LONG SDEAPI SE_serverinfo_set_procstats 
                                  (SE_SERVERINFO       svrInfo,
                                   LONG                Procstats);
extern LONG SDEAPI SE_serverinfo_get_precision10 
                                  (const SE_SERVERINFO svrInfo,
                                   BOOL                *Precision10);
extern LONG SDEAPI SE_serverinfo_set_precision10 
                                  (SE_SERVERINFO       svrInfo,
                                   BOOL                Precision10);
extern LONG SDEAPI SE_serverinfo_get_detect8Xnullshape 
                                  (const SE_SERVERINFO svrInfo,
                                   BOOL                 *Detect8XNullShape);
extern LONG SDEAPI SE_serverinfo_set_detect8Xnullshape 
                                  (SE_SERVERINFO       svrInfo,
                                   BOOL                Detect8XNullShape);
extern LONG SDEAPI SE_serverinfo_get_disableautoreg 
                                  (const SE_SERVERINFO svrInfo,
                                   BOOL                *DisableAutoReg);
extern LONG SDEAPI SE_serverinfo_set_disableautoreg 
                                  (SE_SERVERINFO       svrInfo,
                                   BOOL                DisableAutoReg);
extern LONG SDEAPI SE_serverinfo_get_errlogmode
                                  (const SE_SERVERINFO svrInfo,
                                   LONG                *ErrlogMode);
extern LONG SDEAPI SE_serverinfo_set_errlogmode
                                  (SE_SERVERINFO       svrInfo,
                                   LONG                ErrlogMode);
extern LONG SDEAPI SE_serverinfo_get_layerautolocking
                                  (const SE_SERVERINFO svrInfo,
                                   BOOL                *layerautolock);
extern LONG SDEAPI SE_serverinfo_set_layerautolocking
                                  (SE_SERVERINFO       svrInfo,
                                   BOOL                layerautolock);

extern LONG SDEAPI SE_serverinfo_get_int64types
                                  (const SE_SERVERINFO svrInfo,
                                   BOOL                *int64types);
extern LONG SDEAPI SE_serverinfo_set_int64types
                                  (SE_SERVERINFO       svrInfo,
                                   BOOL                int64types);


#ifdef __cplusplus
};
#endif

#endif
