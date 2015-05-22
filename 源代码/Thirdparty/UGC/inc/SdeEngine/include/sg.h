/* $Id: sg.h,v 1.1 2007/03/15 11:00:27 liwl Exp $ */
/***********************************************************************
*
*N  {sg.h} -- Public data structure/prototypes for the shape library.
*
*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
*
*P  Purpose:
* 
*   This file contains the well-known data structures and public 
*   function prototypes for the shape library. All data structre and
*   function names are prefixed with Sg to indicate that they are part
*   of the Shape Geometry (hence, the Sg) library.
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
*   Scott J. Simon  [11/20/96]  Original coding.
*E
***********************************************************************/

#ifndef _SG_H_
#define _SG_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <limits.h>

#include "pe.h"

/*
 * =================================================================== 
 * ...Enumerations and Defines...
 * =================================================================== 
 */

/*
 * ...Simple data types...
 */
#if defined(AXPOSF) || defined(SDE64)
#define LONG    int
#define ULONG   unsigned int
#else
#define LONG    long
#define ULONG   unsigned long
#endif

#define SHORT   short
#define USHORT  unsigned short

#define CHAR    char
#define UCHAR   unsigned char

#define ACHAR   char
#define SE_WCHAR unsigned short

#define LFLOAT  double
#define FLOAT   float
#define SFLOAT  float

#define STATIC  static

#define BOOL    int

/*
 * ...New Simple data types...
 */

#if defined (LINUX) && !defined(SDE64) 
#ifndef LLONG_MAX
#define LLONG_MAX 9223372036854775807LL
#endif
#endif

#if defined(AXPOSF) || defined(SDE64)
#  define SE_INT32      int
#  define SE_UINT32     unsigned int
#  define SE_INT64      long
#  define SE_UINT64     unsigned long
#  define SE_INT64_MAX  LONG_MAX
#  define CONST_I64(n)  n ## L
#elif defined(WIN32)
#  define SE_INT32      long
#  define SE_UINT32     unsigned long
#  define SE_INT64      __int64
#  define SE_UINT64     unsigned __int64
#  define SE_INT64_MAX  _I64_MAX
#  define CONST_I64(n)  n ## i64
#else
#  define SE_INT32      long
#  define SE_UINT32     unsigned long
#  define SE_INT64      long long
#  define SE_UINT64     unsigned long long
#  define CONST_I64(n)  n ## LL
#  if defined(AIX)
#    define     SE_INT64_MAX  LONGLONG_MAX
#  else
#    if defined(HP)
#      define   SE_INT64_MAX  LONG_LONG_MAX
#    else
#      if defined(SGI)
#        define SE_INT64_MAX  LONG_MAX
#      else
#        define SE_INT64_MAX  LLONG_MAX
#      endif
#    endif
#  endif
#endif

#define SE_INT16   short
#define SE_UINT16  unsigned short

#define SE_FLOAT64  double
#define SE_FLOAT32  float

/*
 * ...Other defines...
 */

#ifndef FALSE
#define FALSE                   (0)
#endif

#ifndef TRUE
#define TRUE                    (1)
#endif

#ifndef NULL
#define NULL                    0
#endif

#ifndef SGGLOBAL
#  if defined (_SG_SUCONV_)
#    if defined (WIN32)
#      define SGGLOBAL __declspec(dllexport)
#    elif defined (unix) || defined (OS2)
#      define SGGLOBAL
#    endif
#    define SGINITIALIZE(init) = init
#  else
#    if defined (WIN32)
#      define SGGLOBAL __declspec(dllimport)
#    elif defined (unix) || defined (OS2)
#      define SGGLOBAL extern
#    endif
#    define SGINITIALIZE(init)
#  endif
#endif

/*
 * ...Max converted projection string length...
 */
#define SG_MAX_PROJECTION_LEN 1024

/*
 * ...Search Methods...
 */
#define     SM_ENVP             0   /* ENVELOPES OVERLAP */
#define     SM_ENVP_BY_GRID     1   /* ENVELOPES OVERLAP */
#define     SM_CP               2   /* COMMON POINT */
#define     SM_LCROSS           3   /* LINE CROSS */
#define     SM_COMMON           4   /* COMMON EDGE/LINE */
#define     SM_CP_OR_LCROSS     5   /* COMMON POINT OR LINE CROSS */
#define     SM_LCROSS_OR_CP     5   /* COMMON POINT OR LINE CROSS */
#define     SM_ET_OR_AI         6   /* EDGE TOUCH OR AREA INTERSECT */
#define     SM_AI_OR_ET         6   /* EDGE TOUCH OR AREA INTERSECT */
#define     SM_ET_OR_II         6   /* EDGE TOUCH OR INTERIOR INTERSECT */
#define     SM_II_OR_ET         6   /* EDGE TOUCH OR INTERIOR INTERSECT */
#define     SM_AI               7   /* AREA INTERSECT */
#define     SM_II               7   /* INTERIOR INTERSECT */
#define     SM_AI_NO_ET         8   /* AREA INTERSECT AND NO EDGE TOUCH */
#define     SM_II_NO_ET         8   /* INTERIOR INTERSECT AND NO EDGE TOUCH */
#define     SM_PC               9   /* PRIMARY CONTAINED IN SECONDARY */
#define     SM_SC               10  /* SECONDARY CONTAINED IN PRIMARY */
#define     SM_PC_NO_ET         11  /* PRIM CONTAINED AND NO EDGE TOUCH */
#define     SM_SC_NO_ET         12  /* SEC CONTAINED AND NO EDGE TOUCH */
#define     SM_PIP              13  /* FIRST POINT IN PRIMARY IN SEC */
#define     SM_IDENTICAL        15  /* IDENTICAL */
#define		SM_CBM				16	/* Calculus-based method [Clementini] */

/*
 * ...Individual bit-masks for shape relationships...
 */
#define     RM_LINE_CROSS           1       /* LINE CROSS */
#define     RM_COMMON_PT            (1<<1)  /* COMMON POINT */
#define     RM_EMBEDDED_PT          (1<<2)  /* VERTICE EMBEDDED IN LINE */
#define     RM_CBOUND_SAME          (1<<3)  /* COM. EDGE SAME DIRECTION */
#define     RM_CBOUND_DIFF          (1<<4)  /* COM. EDGE OPP. DIRECTION */
#define     RM_PARALLEL_OVERLAPPING (1<<5)  /* PARALLEL OVERLAPPING LINES */
#define     RM_IDENTICAL            (1<<6)  /* PRIMARY == SECONDARY */
#define     RM_AREA_INTERSECT       (1<<7)  /* AREA INTERSECTION */
#define     RM_INTERIOR_INTERSECT   (1<<7)  /* INTERIOR INTERSECTION */
#define     RM_BOUNDARY_INTERSECT   (1<<8)  /* BOUNDARY INTERSECTION */
#define     RM_PRIM_LEP_INTERIOR    (1<<9)  /* PRIM END PT TOUCHES INTERIOR */
#define     RM_SEC_LEP_INTERIOR     (1<<10) /* SEC END PT TOUCHES INTERIOR */
#define     RM_PRIM_CONTAINED       (1<<11) /* PRIMARY CONTAINED BY SECONDARY */
#define     RM_SEC_CONTAINED        (1<<12) /* SECONDARY CONTAINED BY PRIMARY */
#define     RM_TESTS_PERFORMED      (1<<15) /* ANY TESTS PERFORMED? */

/*
 * ...Allowable shape types...
 */
#define SG_NIL_SHAPE                0
#define SG_POINT_SHAPE              1
#define SG_LINE_SHAPE               2
#define SG_SIMPLE_LINE_SHAPE        4
#define SG_AREA_SHAPE               8
#define SG_SHAPE_CLASS_MASK         255  /* Mask all of the previous */
#define SG_SHAPE_MULTI_PART_MASK    256  /* Bit flag indicates mult parts */
#define SG_MULTI_POINT_SHAPE        257
#define SG_MULTI_LINE_SHAPE         258
#define SG_MULTI_SIMPLE_LINE_SHAPE  260
#define SG_MULTI_AREA_SHAPE         264
#define SG_ILLEGAL_SHAPE            1000

/*
 * ...Shape's SQL types...
 */
#define SG_UNSPECIFIED_TYPE         0
#define SG_POINT_TYPE               4
#define SG_POINTM_TYPE              5
#define SG_POINTZ_TYPE              6
#define SG_POINTZM_TYPE             7
#define SG_MULTIPOINT_TYPE          8
#define SG_MULTIPOINTM_TYPE         9
#define SG_MULTIPOINTZ_TYPE         10
#define SG_MULTIPOINTZM_TYPE        11
#define SG_LINESTRING_TYPE          12
#define SG_LINESTRINGM_TYPE         13
#define SG_LINESTRINGZ_TYPE         14
#define SG_LINESTRINGZM_TYPE        15
#define SG_POLYGON_TYPE             16
#define SG_POLYGONM_TYPE            17
#define SG_POLYGONZ_TYPE            18
#define SG_POLYGONZM_TYPE           19
#define SG_MULTILINESTRING_TYPE     20
#define SG_MULTILINESTRINGM_TYPE    21
#define SG_MULTILINESTRINGZ_TYPE    22
#define SG_MULTILINESTRINGZM_TYPE   23
#define SG_MULTIPOLYGON_TYPE        24
#define SG_MULTIPOLYGONM_TYPE       25
#define SG_MULTIPOLYGONZ_TYPE       26
#define SG_MULTIPOLYGONZM_TYPE      27

/*
 * ...Coordref Precisions...
 */
#define SG_PRECISION_DEFAULT   0
#define SG_PRECISION_32_BIT   32
#define SG_PRECISION_64_BIT   64

/*
 * ...Shape build enumerations...
 */
typedef enum
{
    eSgShapeBuildSimpleLines = 1,               
    eSgShapeBuildClockwisePolygons = 2,         
    eSgShapeBuildCounterClockwisePolygons = 3,  
    eSgShapeBuildForwardPolygons = 4,           
    eSgShapeBuildBackwardPolygons = 5           
} SgShapeBuildMode;

/*
 * ...Shape Rotation enumerations..
 */
typedef enum
{
    eSgDefaultRotation,
    eSgLeftHandRotation,  /* Polygon interior is on the left */
    eSgRightHandRotation  /* Polygon interior is on the right */
} SgRotationType;

/*
 * ...Match Mask definitions...
 */
#define SG_MATCH_ZEDS       1
#define SG_MATCH_MEASURES   2

/*
 * binary shape byte order enumerations and constants...
 */
typedef enum
{
  eSgBigEndian         = 0,
  eSgLittleEndian      = 1
} SgByteOrder;

#if defined(WIN32) || defined (AXPOSF) || defined (OS2) || defined (SWAPL)
#define IS_LITTLE_ENDIAN 1
#else
#define IS_LITTLE_ENDIAN 0
#endif

/*
 * ESRI binary shape type enumerations in memory...
 */

typedef enum
{
  eSgHasZs                  = (LONG)0x80000000, /* 1 << 31 */
  eSgHasMs                  = (LONG)0x40000000, /* 1 << 30 */
  eSgHasCurves              = (LONG)0x20000000, /* 1 << 29 */
  eSgHasIDs                 = (LONG)0x10000000, /* 1 << 28 */
  eSgHasNormals             = (LONG)0x08000000, /* 1 << 27 */
  eSgHasTextures            = (LONG)0x04000000, /* 1 << 26 */
  eSgHasPartIDs             = (LONG)0x02000000, /* 1 << 25 */
  eSgModifierMask           = (LONG)0xff000000,
  eSgModifierMaskEx         = (LONG)0xffff0000,
  eSgBasicTypeMask          = (LONG)0x000000ff,
  eSgBasicModifierMask      = eSgHasZs | eSgHasMs,
  eSgNonBasicModifierMask   = eSgModifierMask & ~eSgBasicModifierMask,
  eSgNonBasicModifierMaskEx = eSgModifierMaskEx & ~eSgBasicModifierMask
} eSgModifiers;

#ifdef AXPOSF
typedef enum
{
  eSgBinaryNil               = 0,
  eSgBinaryPoint             = 1,
  eSgBinaryPolyline          = 3,
  eSgBinaryPolygon           = 5,
  eSgBinaryMultiPoint        = 8,
  eSgBinaryPointZ            = 9,
  eSgBinaryPolylineZ         = 10,
  eSgBinaryPointZM           = 11,
  eSgBinaryPolylineZM        = 13,
  eSgBinaryPolygonZM         = 15,
  eSgBinaryMultiPointZM      = 18,
  eSgBinaryPolygonZ          = 19,
  eSgBinaryMultiPointZ       = 20,
  eSgBinaryPointM            = 21,
  eSgBinaryPolylineM         = 23,
  eSgBinaryPolygonM          = 25,
  eSgBinaryMultiPointM       = 28,
  eSgBinaryMultiPatch        = 31,
  eSgBinaryMultiPatchM       = 32,
  eSgBinaryGeneralPolyline   = 50,
  eSgBinaryGeneralPolygon    = 51,
  eSgBinaryGeneralPoint      = 52,
  eSgBinaryGeneralMultiPoint = 53,
  eSgBinaryGeneralMultiPatch = 54
} SgESRIBinaryShapeType;

typedef enum
{

  eSgBinaryPolylineCurve     = eSgBinaryGeneralPolyline + eSgHasCurves,
  eSgBinaryPolygonCurve      = eSgBinaryGeneralPolygon  + eSgHasCurves

} eSgGeneralModifiers;
#else
typedef enum
{
  eSgBinaryNil               = 0,
  eSgBinaryPoint             = 1,
  eSgBinaryPolyline          = 3,
  eSgBinaryPolygon           = 5,
  eSgBinaryMultiPoint        = 8,
  eSgBinaryPointZ            = 9,
  eSgBinaryPolylineZ         = 10,
  eSgBinaryPointZM           = 11,
  eSgBinaryPolylineZM        = 13,
  eSgBinaryPolygonZM         = 15,
  eSgBinaryMultiPointZM      = 18,
  eSgBinaryPolygonZ          = 19,
  eSgBinaryMultiPointZ       = 20,
  eSgBinaryPointM            = 21,
  eSgBinaryPolylineM         = 23,
  eSgBinaryPolygonM          = 25,
  eSgBinaryMultiPointM       = 28,
  eSgBinaryMultiPatch        = 31,
  eSgBinaryMultiPatchM       = 32,
  eSgBinaryGeneralPolyline   = 50,
  eSgBinaryGeneralPolygon    = 51,
  eSgBinaryGeneralPoint      = 52,
  eSgBinaryGeneralMultiPoint = 53,
  eSgBinaryGeneralMultiPatch = 54,
  eSgBinaryPolylineCurve     = eSgBinaryGeneralPolyline + eSgHasCurves,
  eSgBinaryPolygonCurve      = eSgBinaryGeneralPolygon  + eSgHasCurves
} SgESRIBinaryShapeType;
#endif

/*
 * Well Known Binary shape type (OGIS) enumerations...
 */
typedef enum
{
  eSgWkbPoint              = 1,
  eSgWkbLineString         = 2,
  eSgWkbPolygon            = 3,
  eSgWkbMultiPoint         = 4,
  eSgWkbMultiLineString    = 5,
  eSgWkbMultiPolygon       = 6,
  eSgWkbGeometryCollection = 7
} SgWkbShapeType;

/*
 * Envelope macros...
 */
#define SG_IS_EMPTY_ENVELOPE(e)   ((e).minx > (e).maxx || (e).miny > (e).maxy)
#define SG_MAKE_EMPTY_ENVELOPE(e) {(e).minx = (e).miny = SE_INT64_MAX;\
                                   (e).maxx = (e).maxy = 0;}

/*
 * =================================================================== 
 * ...Data Structures...
 * =================================================================== 
 */

/*
 * ...Double precision point structures...
 */
typedef struct 
{
    LFLOAT  x,
            y; 
} SgSimpleShapePoint;

typedef struct
{
    LFLOAT x;
    LFLOAT y;
    LFLOAT z;
    LFLOAT m;
} SgShapePoint;

/*
 * ...Double precision envelope structure...
 */
typedef struct
{
    LFLOAT minx;
    LFLOAT miny;
    LFLOAT maxx;
    LFLOAT maxy;
} SgShapeEnvelope;

/*
 * ...Coordinate reference data object...
 */
typedef struct _SgCoordRefRecord *SgCoordRef;

/*
 * ...Shape object...
 */
typedef struct _SgShapeRecord *SgShape;

/*
 * =================================================================== 
 * ...User-Settable Module Global Variables...
 * =================================================================== 
 */

/*
 * The following flag (initialized to FALSE) effects the all shape
 * functions that return coordinates or extents called by the
 * current program.  When TRUE, bits in coordinates past the limits
 * of storage resolution are cleared to 0.  This is some CPU cost to
 * this operation, and for most applications it is unnecessary.
 */

 SGGLOBAL BOOL SgGlobalCoordinateTruncationFlag SGINITIALIZE(FALSE);

/*
 * =================================================================== 
 * ...Function Prototypes...
 * =================================================================== 
 */
#ifndef SHAPEAPI
#define SHAPEAPI

/*
 * Coordinate Reference object functions...
 */
extern LONG SgCoordRefCreate(              SgCoordRef *pCoordRef);
extern void SgCoordRefFree(                SgCoordRef CoordRef);
extern LONG SgCoordRefDuplicate(           SgCoordRef srcRef, 
                                           SgCoordRef tgtRef);
extern LONG SgCoordRefGetCoordSys(         SgCoordRef coordRef, 
                                           PE_COORDSYS *cs);
extern LONG SgCoordRefGetDescription(      SgCoordRef coordRef, 
                                           CHAR *pDescription);
extern LONG SgCoordRefGetId(               SgCoordRef coordRef, 
                                           LONG *projCoordSysId);
extern LONG SgCoordRefGetM(                SgCoordRef coordRef, 
                                           LFLOAT *pFalseM, 
                                           LFLOAT *pMUnits);
extern LONG SgCoordRefGetMRange(           SgCoordRef coordRef, 
                                           LFLOAT *pMinValue, 
                                           LFLOAT *pMaxValue);
extern LONG SgCoordRefGetPrecision(        SgCoordRef coordRef, 
                                           LONG *precision);
extern LONG SgCoordRefGetSrId(             SgCoordRef coordRef, 
                                           LONG *srId);
extern LONG SgCoordRefGetXY(               SgCoordRef coordRef, 
                                           LFLOAT *pFalseX, 
                                           LFLOAT *pFalseY, 
                                           LFLOAT *pXYUnits);
extern LONG SgCoordRefGetXYEnvelope(       SgCoordRef coordRef, 
                                           SgShapeEnvelope *pExtent);
extern LONG SgCoordRefGetZ(                SgCoordRef coordRef, 
                                           LFLOAT *pFalseZ, 
                                           LFLOAT *pZUnits);
extern LONG SgCoordRefGetZRange(           SgCoordRef coordRef, 
                                           LFLOAT *pMinValue, 
                                           LFLOAT *pMaxValue);
extern BOOL SgCoordRefIsEqual(             const SgCoordRef coordRefA, 
                                           const SgCoordRef coordRefB);
extern LONG SgCoordRefSetCoordSys(         SgCoordRef coordRef, 
                                           PE_COORDSYS cs);
extern LONG SgCoordRefSetByDescription(    SgCoordRef coordRef, 
                                           const CHAR *pDescription);
extern LONG SgCoordRefSetById(             SgCoordRef coordRef, 
                                           LONG projCoordSysId);
extern LONG SgCoordRefSetM(                SgCoordRef coordRef, 
                                           LFLOAT falseM, 
                                           LFLOAT mUnits);
extern LONG SgCoordRefSetMByRange(         SgCoordRef coordRef, 
                                           LFLOAT minMValue, 
                                           LFLOAT maxMValue);
extern LONG SgCoordRefSetPrecision(        SgCoordRef coordRef, 
                                           LONG precision);
extern LONG SgCoordRefSetSrId(             SgCoordRef coordRef, 
                                           LONG srId);
extern LONG SgCoordRefSetXY(               SgCoordRef coordRef, 
                                           LFLOAT falseX, 
                                           LFLOAT falseY, 
                                           LFLOAT xyUnits);
extern LONG SgCoordRefSetXYByEnvelope(     SgCoordRef coordRef, 
                                           SgShapeEnvelope *pExtent);
extern LONG SgCoordRefSetZ(                SgCoordRef coordRef, 
                                           LFLOAT falseZ, 
                                           LFLOAT zUnits);
extern LONG SgCoordRefSetZByRange(         SgCoordRef coordRef, 
                                           LFLOAT minZValue, 
                                           LFLOAT maxZValue);
extern LONG SgCoordRefSnapPointArray(      SgCoordRef          coordRef, 
                                           SgSimpleShapePoint  *pointArray,
                                           LFLOAT              *zArray,
                                           LFLOAT              *mArray,
                                           LONG                numPoints);

/*
 * Shape object functions...
 */
extern LONG SgShapeAddIsland(              SgShape shape, 
                                           SgShapePoint *pPoints, 
                                           LONG numPoints);
extern LONG SgShapeAddPart(                const SgShape srcShape, 
                                           SgShape tgtShape,
                                           BOOL q_verify);
extern LONG SgShapeAllocate(               SgShape shape, 
                                           LONG numPoints, 
                                           BOOL allocZeds, 
                                           BOOL allocMeasures);
extern LONG SgShapeAsLine(                 const SgShape srcShape, 
                                           SgShape tgtShape);
extern LONG SgShapeAsPoint(                const SgShape srcShape, 
                                           SgShape tgtShape);
extern LONG SgShapeAsPolygon(              const SgShape srcShape, 
                                           SgShape tgtShape);
extern LONG SgShapeAsSimpleLine(           const SgShape srcShape, 
                                           SgShape tgtShape);
extern LONG SgShapeBuild(                  SgShape srcShape, 
                                           SgShapeBuildMode buildMode, 
                                           BOOL dissolveFlag, 
                                           LONG matchMask, 
                                           SgShape tgtShape);
extern LONG SgShapeCalculateDistance(      const SgShape primaryShape, 
                                           const SgShape secondaryShape, 
                                           LFLOAT *pDistance, 
                                           BOOL insideTest);
extern LONG SgShapeChangeCoordRef(         SgShape srcShape, 
                                           SgCoordRef coordRef,
                                           PE_GEOGTRAN geogTran, 
                                           SgShape tgtShape);
extern LONG SgShapeChangePath(             SgShape shape, 
                                           SgShapePoint *pFirstPoint, 
                                           SgShapePoint *pMidPoint, 
                                           SgShapePoint *pLastPoint, 
                                           SgShapePoint *pPoints, 
                                           LONG numPoints);
extern LONG SgShapeClip(                   SgShape srcShape, 
                                           SgShapeEnvelope *pExtent, 
                                           SgShape tgtShape);
extern LONG SgShapeCreate(                 SgCoordRef coordRef, 
                                           SgShape *pShape);
extern LONG SgShapeDeleteIsland(           SgShape shape, 
                                           SgSimpleShapePoint *pPoints);
extern LONG SgShapeDeletePart(             SgShape shape, 
                                           LONG partNum);
extern LONG SgShapeDeletePath(             SgShape shape, 
                                           SgShapePoint *pFirstPoint, 
                                           SgShapePoint *pMidPoint, 
                                           SgShapePoint *pLastPoint);
extern LONG SgShapeDeletePoint(            SgShape shape, 
                                           SgShapePoint *pPoint);
extern LONG SgShapeDifference(             const SgShape primaryShape, 
                                           const SgShape secondaryShape, 
                                           SgShape tgtShape);
extern LONG SgShapeDuplicate(              const SgShape srcShape, 
                                           SgShape tgtShape);
extern LONG SgShapeExtendLine(             SgShape shape, 
                                           SgShapePoint *pEndPoint, 
                                           SgShapePoint *pPoints, 
                                           LONG numPoints);
extern LONG SgShapeFilterCoordinates(      const SgShape srcShape, 
                                           LFLOAT distance, 
                                           SgShape tgtShape);
extern LONG SgShapeFindAlong(              SgShape shape, 
                                           LFLOAT measure, 
                                           LONG *pNumShapes, 
                                           SgShape **pResultShapes);
extern LONG SgShapeFindBetween(            SgShape shape, 
                                           LFLOAT fromMeasure, 
                                           LFLOAT toMeasure, 
                                           LONG *pNumShapes, 
                                           SgShape **pResultShapes);
extern LONG SgShapeFindRelation(           const SgShape primaryShape, 
                                           const SgShape secondaryShape,
                                           LONG sectdims[3][3], 
                                           LONG *pMask);
extern void SgShapeFree(                   SgShape shape);
extern void SgShapeFreeArray(              LONG numShapes, 
                                           SgShape *pShapes);
extern LONG SgShapeFromBinary(             const CHAR *binary_shape,
                                           SgESRIBinaryShapeType *sql_type,
                                           SgShape shape);
extern LONG SgShapeFromBinaryByteOrder(    const CHAR            *binary_shape,
                                           SgESRIBinaryShapeType *sql_type,
                                           SgShape               shape,
                                          BOOL                  process_invalid);
extern LONG SgShapeFromText(               LONG expected_sql_type,
                                           const CHAR *shptxt,
                                           LONG *specific_sql_type,
                                           SgShape shape);
extern LONG SgShapeFromWkb(                const CHAR *binary_shape,
                                           SgWkbShapeType *sql_type,
                                           SgShape    shape);
extern LONG SgShapeGenerateBuffer(         const SgShape srcShape, 
                                           LFLOAT distance, 
                                           LONG maxPoints, 
                                           SgShape tgtShape);
extern LONG SgShapeGenerateCircle(         SgSimpleShapePoint center, 
                                           LFLOAT radius, 
                                           LONG numPoints, 
                                           SgShape tgtShape);
extern LONG SgShapeGenerateConvexHull(     SgShape srcShape, 
                                           SgShape tgtShape);
extern LONG SgShapeGenerateEllipse(        SgSimpleShapePoint center, 
                                           LFLOAT semiMajorAxis, 
                                           LFLOAT semiMinorAxis, 
                                           LFLOAT angle, 
                                           LONG numPoints, 
                                           SgShape tgtShape);
extern LONG SgShapeGenerateFromPart(       const SgShape srcShape, 
                                           LONG partNum, 
                                           SgShape tgtShape);
extern LONG SgShapeGenerateLabelPoint(     const SgShape shape, 
                                           SgSimpleShapePoint *pPoint);
extern LONG SgShapeGenerateLine(           LONG numPoints, 
                                           LONG numParts, 
                                           LONG *pPartOffsets, 
                                           SgSimpleShapePoint *pPoints, 
                                           LFLOAT *pZeds, 
                                           LFLOAT *pMeasures, 
                                           SgShape tgtShape);
extern LONG SgSubGenerateLinearShape(      LONG numPoints,
                                           LONG numParts,
                                           LONG *pPartOffsets,
                                           SgSimpleShapePoint *pPoints,
                                           LFLOAT *pZeds,
                                           LFLOAT *pMeasures,
                                           SHORT   entityType,
                                           SgShape tgtShape);
extern LONG SgShapeGeneratePoint(          LONG numPoints, 
                                           SgSimpleShapePoint *pPoints, 
                                           LFLOAT *pZeds, 
                                           LFLOAT *pMeasures, 
                                           SgShape tgtShape);
extern LONG SgSubShapeGeneratePoint(       LONG numPoints,
                                           SgSimpleShapePoint *pPoints,
                                           LFLOAT *pZeds,
                                           LFLOAT *pMeasures,
                                           SgShape tgtShape);
extern LONG SgShapeGeneratePolygon(        LONG numPoints, 
                                           LONG numParts, 
                                           LONG *pPartOffsets, 
                                           SgSimpleShapePoint *pPoints, 
                                           LFLOAT *pZeds, 
                                           LFLOAT *pMeasures, 
                                           SgShape tgtShape);
extern LONG SgSubShapeGeneratePolygon(     LONG numPoints,
                                           LONG numParts,
                                           LONG *pPartOffsets,
                                           SgSimpleShapePoint *pPoints,
                                           LFLOAT *pZeds,
                                           LFLOAT *pMeasures,
                                           SgShape tgtShape);
extern LONG SgShapeGenerateRectangle(      SgShapeEnvelope *pExtent, 
                                           SgShape tgtShape);
extern LONG SgSubShapeGenerateRectangle(   SgShapeEnvelope *pExtent,
                                           SgShape tgtShape);
extern LONG SgShapeGenerateSimpleLine(     LONG numPoints, 
                                           LONG numParts, 
                                           LONG *pPartOffsets, 
                                           SgSimpleShapePoint *pPoints, 
                                           LFLOAT *pZeds, 
                                           LFLOAT *pMeasures, 
                                           SgShape tgtShape);
extern LONG SgShapeGet3DLength(            const SgShape shape,
                                           LONG partNum,
                                           LFLOAT *pLength);
extern LONG SgShapeGetAllPoints(           const SgShape shape, 
                                           SgRotationType rotation,
                                           LONG *pPartOffsets, 
                                           LONG *pSubPartOffsets,
                                           SgSimpleShapePoint *pPoints, 
                                           LFLOAT *pZeds, 
                                           LFLOAT *pMeasures);
extern LONG SgShapeGetArea(                const SgShape shape, 
                                           LONG partNum, 
                                           LFLOAT *pArea);
extern LONG SgShapeGetBinarySize(          const SgShape shape, 
                                           LONG *size);
extern LONG SgShapeGetTextSize(            const SgShape shape,
                                           LONG *size);
extern LONG SgShapeGetCoordRef(            const SgShape shape, 
                                           SgCoordRef coordRef);
extern LONG SgShapeGetExtent(              const SgShape shape, 
                                           LONG partNum, 
                                           SgShapeEnvelope *pExtent);
extern LONG SgShapeGetLength(              const SgShape shape, 
                                           LONG partNum, 
                                           LFLOAT *pLength);
extern LONG SgShapeGetMRange(              const SgShape shape, 
                                           LONG partNum, 
                                           LFLOAT *pMinMeasure, 
                                           LFLOAT *pMaxMeasure);
extern LONG SgShapeGetNumParts(            const SgShape shape, 
                                           LONG *pNumParts,
                                           LONG *pNumSubParts);
extern LONG SgShapeGetNumPoints(           const SgShape shape, 
                                           LONG partNum, 
                                           LONG subPartNum,
                                           LONG *pNumPoints);
extern LONG SgShapeGetNumSubParts(         const SgShape shape, 
                                           LONG partNum,
                                           LONG *pNumSubParts);
extern LONG SgShapeGetPoints(              const SgShape shape, 
                                           LONG partNum, 
                                           SgRotationType rotation,
                                           LONG *pSubPartOffsets,
                                           SgSimpleShapePoint *pPoints, 
                                           LFLOAT *pZeds, 
                                           LFLOAT *pMeasures);
extern LONG SgShapeGetType(                const SgShape shape, 
                                           LONG *pShapeType);
extern LONG SgShapeGetWkbSize(             const SgShape shape, 
                                           LONG *size);
extern LONG SgShapeGetZRange(              const SgShape shape, 
                                           LONG partNum, 
                                           LFLOAT *pMinZ, 
                                           LFLOAT *pMaxZ);
extern BOOL SgShapeInclusionsAreRings(     const SgShape shape);
extern LONG SgShapeInclusionsToRings(      SgShape  shape);
extern LONG SgShapeInsertPart(             const SgShape srcShape, 
                                           LONG partNum, 
                                           SgShape tgtShape);
extern LONG SgShapeInterpolateByMeasures(  SgShape srcShape, 
                                           LFLOAT delta, 
                                           SgShape tgtShape);
extern LONG SgShapeIntersect(              const SgShape primaryShape, 
                                           const SgShape secondaryShape, 
                                           LONG *pNumShapes, 
                                           SgShape **pResultShapes);
extern BOOL SgShapeIs32bitSafe(            const SgShape shape);
extern BOOL SgShapeIs3D(                   const SgShape shape);
extern BOOL SgShapeIsContaining(           const SgShape primaryShape, 
                                           const SgShape secondaryShape);
extern BOOL SgShapeIsCrossing(             const SgShape primaryShape, 
                                           const SgShape secondaryShape);
extern BOOL SgShapeIsDisjoint(             const SgShape primaryShape, 
                                           const SgShape secondaryShape);
extern BOOL SgShapeIsEqual(                const SgShape primaryShape, 
                                           const SgShape secondaryShape);
extern BOOL SgShapeIsLine(                 const SgShape shape);
extern BOOL SgShapeIsMeasured(             const SgShape shape);
extern BOOL SgShapeIsMultipart(            const SgShape shape);
extern BOOL SgShapeIsNil(                  const SgShape shape);
extern BOOL SgShapeIsOverlapping(          const SgShape primaryShape, 
                                           const SgShape secondaryShape);
extern BOOL SgShapeIsPoint(                const SgShape shape);
extern BOOL SgShapeIsPolygon(              const SgShape shape);
extern BOOL SgShapeIsSimpleLine(           const SgShape shape);
extern BOOL SgShapeIsReadOnly(             const SgShape shape);
extern BOOL SgShapeIsTouching(             const SgShape primaryShape, 
                                           const SgShape secondaryShape);
extern BOOL SgShapeIsWithin(               const SgShape primaryShape, 
                                           const SgShape secondaryShape);
extern BOOL SgShapeHasJoinedRings(         const SgShape shape);
extern LONG SgShapeMakeNil(                SgShape shape);
extern LONG SgShapeMovePoint(              SgShape shape, 
                                           SgShapePoint *pFromPoint, 
                                           SgShapePoint *pToPoint);
extern LONG SgShapeOverlay(                const SgShape primaryShape, 
                                           const SgShape secondaryShape, 
                                           LONG *pNumCommonShapes, 
                                           SgShape primaryRemainder, 
                                           SgShape **commonShapes, 
                                           SgShape secondaryRemainder);
extern LONG SgShapeReplacePart(            const SgShape srcShape, 
                                           LONG partNum, 
                                           SgShape tgtShape);
extern LONG SgShapeReplacePathWithArc(     SgShape shape, 
                                           SgShapePoint *pFirstPoint, 
                                           SgShapePoint *pMidPoint, 
                                           SgShapePoint *pLastPoint, 
                                           LFLOAT radius, 
                                           LONG arcSegs);
extern LONG SgShapeSetCoordRef(            SgShape shape, 
                                           SgCoordRef coordRef);
extern LONG SgShapeSetInclusionsAreRings(  SgShape shape,
                                           BOOL inclusionsAreRings);
extern LONG SgShapeSetReadOnly(            SgShape shape,
                                           BOOL readOnly);
extern LONG SgShapeSymmetricalDifference(  const SgShape primaryShape, 
                                           const SgShape secondaryShape, 
                                           SgShape tgtShape);
extern LONG SgShapeToBinary(               const SgShape shape,
                                           LONG  alloc_size,
                                           LONG  *binary_size,
                                           CHAR  *binary_shape);
extern LONG SgShapeToBinaryByteOrder(      const SgShape shape,
                                           LONG          alloc_size,
                                           LONG          *binary_size,
                                           CHAR          *binary_shape);
extern LONG SgShapeToText(                 const SgShape shape,
                                           LONG  sql_type,
                                           LONG  max_str_len,
                                           CHAR  *shptxt);
extern LONG SgShapeToWkb(                  const SgShape shape,
                                           LONG  alloc_size,
                                           LONG  *binary_size,
                                           CHAR  *binary_shape);
extern LONG SgShapeUnion(                  const SgShape primaryShape, 
                                           const SgShape secondaryShape, 
                                           SgShape resultShape);

/*
 * Binary support functions...
 */
extern LONG  SgGetInteger(                 CHAR          **buf_ptr,
                                           SgByteOrder   byte_order,
                                           LONG          num_ints,
                                           ULONG         *int_vals);
extern LONG  SgGetDouble(                  CHAR          **buf_ptr,
                                           SgByteOrder   byte_order,
                                           LONG          num_doubles,
                                           LFLOAT        *values);
extern void  SgPutInteger(                 CHAR          **buf_ptr,
                                           SgByteOrder   byte_order,
                                           LONG          num_ints,
                                           LONG          *int_vals);
extern void  SgPutDouble(                  CHAR          **buf_ptr,
                                           SgByteOrder   byte_order,
                                           LONG          num_doubles,
                                           LFLOAT        *double_vals);

#endif /* #ifndef SHAPEAPI */

#ifdef __cplusplus
};
#endif

#endif /* #ifndef _SG_H_ */

