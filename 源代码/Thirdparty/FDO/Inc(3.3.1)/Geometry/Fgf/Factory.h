#ifndef _FGFGEOMETRYFACTORY_H_
#define _FGFGEOMETRYFACTORY_H_

//
// Copyright (C) 2004-2006  Autodesk, Inc.
// 
// This library is free software; you can redistribute it and/or
// modify it under the terms of version 2.1 of the GNU Lesser
// General Public License as published by the Free Software Foundation.
// 
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
//



#ifdef _WIN32
#pragma once
#endif

#include <Geometry/IGeometry.h>
#include <Geometry/GeometryFactoryAbstract.h>
#include <Geometry/GeometryStream/GeometryStreamFactory.h>
#include <Common/Array.h>

struct FdoFgfGeometryFactory2;   // Forward declaration (private data for class).

/// \brief
/// The FdoFgfGeometryFactory class is an FGF-based Geometry factory, a concrete class that
/// implements all the members from FdoGeometryFactoryAbstract
class FdoFgfGeometryFactory : public FdoGeometryFactoryAbstract
{
public:


    /// \brief
    /// Acquires an object of this class.
    /// 
    /// \remarks
    /// This class is its own factory.
    /// The object returned might not be a new instance,
    /// and might not be a private instance.
    /// The object returned may maintain internal pools
    /// of other objects in this package, for performance.
    /// Pools will be small, tuned to transient object use.
    /// Objects returned by this factory are safe to pass
    /// to other threads (i.e. they won't try to interact
    /// with the originating thread).
    /// 
    /// \return
    /// Returns a FdoFgfGeometryFactory object
    /// 
    FDO_GEOM_API static FdoFgfGeometryFactory * GetInstance();

    /// \brief
    /// Instantiates an object of this class.
    /// 
    /// \remarks
    /// This class is its own factory. 
    /// This method will return a new, private instance, with any internal
    /// object pools tuned to the input parameters.  NOTE:  objects created
    /// by this factory should NOT be passed between threads.
    /// 
    /// \param numGeometries 
    /// Input Minimum number of geometries to pool.
    /// \param numPositions 
    /// Input Minimum number of positions to pool.
    /// \param numEnvelopes 
    /// Input Minimum number of envelopes to pool.
    /// \param numCurveSegments 
    /// Input Minimum number of curve segments to pool.
    /// \param numRings 
    /// Input Minimum number of polygon rings to pool.
    /// 
    /// \return
    /// Returns a FdoFgfGeometryFactory object
    /// 
    FDO_GEOM_API static FdoFgfGeometryFactory * GetPrivateInstance(
        FdoInt32 numGeometries,
        FdoInt32 numPositions,
        FdoInt32 numEnvelopes,
        FdoInt32 numCurveSegments,
        FdoInt32 numRings);

    /// \brief
    /// Creates a Geometry from FGF data.
    /// 
    /// \param byteArray 
    /// Input FGF data that defines the Geometry.
    /// 
    /// \return
    /// Returns a Geometry
    /// 
    FDO_GEOM_API virtual FdoIGeometry * CreateGeometryFromFgf(
        FdoByteArray * byteArray);

    /// \brief
    /// Creates a Geometry from FGF data.
    /// 
    /// \param byteArray 
    /// Input FGF data that defines the Geometry.
    /// The caller must guarantee the validity of the array for the lifetime
    /// of the associated geometry object.
    /// \param count 
    /// Input Number of bytes of FGF data.
    /// 
    /// \return
    /// Returns a Geometry
    /// 
    FDO_GEOM_API virtual FdoIGeometry * CreateGeometryFromFgf(
        const FdoByte * byteArray, FdoInt32 count);

    /// \brief
    /// Gets FGF data from a Geometry.
    /// 
    /// \param geometry 
    /// Input a Geometry, which must be FGF-based
    /// 
    /// \return
    /// Returns FGF data representing the Geometry
    /// 
    FDO_GEOM_API virtual FdoByteArray * GetFgf(
        FdoIGeometry * geometry);

    /// \brief
    /// Creates an FGF-based Geometry from OpenGIS WKB data.
    /// 
    /// \param byteArray 
    /// Input WKB data that defines the Geometry.
    /// 
    /// \return
    /// Returns a Geometry
    /// 
    FDO_GEOM_API virtual FdoIGeometry * CreateGeometryFromWkb(
        FdoByteArray * byteArray);

    /// \brief
    /// Gets OpenGIS WKB data from a Geometry.
    /// 
    /// \param geometry 
    /// Input a Geometry, which must be FGF-based
    /// 
    /// \return
    /// Returns WKB data representing the Geometry
    /// 
    FDO_GEOM_API virtual FdoByteArray * GetWkb(
        FdoIGeometry * geometry);

    /// Methods from FdoGeometryFactoryAbstract

    /// \brief
    ///  Creates a LineString object by copying from a collection of positions.
    /// 
    /// \param positions 
    /// Input collection of positions to copy
    /// 
    /// \return
    /// Returns a LineString
    /// 
    FDO_GEOM_API virtual FdoILineString* CreateLineString(
        FdoDirectPositionCollection * positions);

    /// \brief
    ///  Creates a LineString object by copying from an array of ordinates.
    /// 
    /// \param dimensionType 
    /// Input dimensionality of the ordinates (see FdoDimensionality)
    /// \param numOrdinates 
    /// Input total number of ordinates in the array
    /// \param ordinates 
    /// Input ordinate array representing positions
    /// 
    /// \return
    /// Returns a LineString
    /// 
    FDO_GEOM_API virtual FdoILineString* CreateLineString(
        FdoInt32 dimensionType,
        FdoInt32 numOrdinates,
        double* ordinates);

    /// \brief
    ///  Creates a Geometry object by copying from another Geometry.
    /// 
    /// \remarks
    ///  This is a pseudo-copy-constructor.
    /// It is required that any implementation use only public methods on the underlying 
    /// Geometry object, thus enabling conversion from Geometries of the same, or any
    /// other, implementation of this Geometry package.  Thus, this implementation creates
    /// FGF-based Geometry objects based on any implementation of the Geometry API.
    /// 
    /// \param geometry 
    /// Input Source geometry
    /// 
    /// \return
    /// Returns an envelope
    /// 
    FDO_GEOM_API virtual FdoIGeometry * CreateGeometry(
        FdoIGeometry * geometry);

    /// \brief
    ///  Creates a Geometry object by converting from a text string.
    /// 
    /// \param text 
    /// Input Source geometry
    /// 
    /// \return
    /// Returns a geometry
    /// 
    FDO_GEOM_API virtual FdoIGeometry * CreateGeometry(
        FdoString* text);

    /// \brief
    ///  Creates a Geometry object by converting from an envelope.
    /// 
    /// \remarks
    ///  This method will produce a new FGF-based Geometry 
    /// based on the given envelope.
    /// 
    /// \param envelope 
    /// Input Source envelope
    /// 
    /// \return
    /// Returns a geometry
    /// 
    FDO_GEOM_API virtual FdoIGeometry * CreateGeometry(
        FdoIEnvelope * envelope);

    /// Point

    /// \brief
    ///  Creates a point object by copying from a position.
    /// 
    /// \param position 
    /// Input position to copy
    /// 
    /// \return
    /// Returns a point
    /// 
    FDO_GEOM_API virtual FdoIPoint* CreatePoint(
        FdoIDirectPosition* position);

    /// \brief
    ///  Creates an point object by copying from an array of ordinates.
    /// 
    /// \param dimensionality 
    /// Input dimensionality of the ordinates (see FdoDimensionality)
    /// \param ordinates 
    /// Input ordinate array representing one position
    /// 
    /// \return
    /// Returns a point
    /// 
    FDO_GEOM_API virtual FdoIPoint* CreatePoint(
        FdoInt32 dimensionality,
        double* ordinates);

    /// LinearRing

    /// \brief
    ///  Creates a LinearRing object by copying from a collection of positions.
    /// 
    /// \remarks
    ///  The first and last positions must be equal.
    /// 
    /// \param positions 
    /// Input collection of positions to copy
    /// 
    /// \return
    /// Returns a LinearRing
    /// 
    FDO_GEOM_API virtual FdoILinearRing* CreateLinearRing(
        FdoDirectPositionCollection* positions);

    /// \brief
    ///  Creates a LinearRing object by copying from an array of ordinates.
    /// 
    /// \remarks
    ///  The ordinates representing the first and last positions must be equal.
    /// 
    /// \param dimensionality 
    /// Input dimensionality of the ordinates (see FdoDimensionality)
    /// \param numOrdinates 
    /// Input total number of ordinates in the array
    /// \param ordinates 
    /// Input ordinate array representing positions
    /// 
    /// \return
    /// Returns a LinearRing
    /// 
    FDO_GEOM_API virtual FdoILinearRing* CreateLinearRing(
        FdoInt32 dimensionality,
        FdoInt32 numOrdinates,
        double* ordinates);

    /// LineStringSegment

    /// \brief
    ///  Creates a LineStringSegment object by copying from a collection of positions.
    /// 
    /// \param positions 
    /// Input collection of positions to copy
    /// 
    /// \return
    /// Returns a LineStringSegment
    /// 
    FDO_GEOM_API virtual FdoILineStringSegment* CreateLineStringSegment(
        FdoDirectPositionCollection* positions);

    /// \brief
    ///  Creates a LineStringSegment object by copying from an array of ordinates.
    /// 
    /// \param dimtype 
    /// Input dimensionality of the ordinates (see FdoDimensionality)
    /// \param numOrdinates 
    /// Input total number of ordinates in the array
    /// \param ordinates 
    /// Input ordinate array representing positions
    /// 
    /// \return
    /// Returns a LineStringSegment
    /// 
    FDO_GEOM_API virtual FdoILineStringSegment* CreateLineStringSegment(
        FdoInt32 dimtype,
        FdoInt32 numOrdinates, 
        double* ordinates);

    /// Polygon

    /// \brief
    ///  Creates a polygon object by copying from given LinearRing objects.
    /// 
    /// \param exteriorRing 
    /// Input exterior ring to copy
    /// \param interiorRings 
    /// Input collection of interior rings to copy
    /// 
    /// \return
    /// Returns a polygon
    /// 
    FDO_GEOM_API virtual FdoIPolygon* CreatePolygon(
        FdoILinearRing* exteriorRing, 
        FdoLinearRingCollection* interiorRings);

    /// MultiPoint

    /// \brief
    ///  Creates a MultiPoint object by copying from a collection of point objects.
    /// 
    /// \param points 
    /// Input collection of point objects to copy
    /// 
    /// \return
    /// Returns a MultiPoint
    /// 
    FDO_GEOM_API virtual FdoIMultiPoint* CreateMultiPoint(
        FdoPointCollection* points);

    /// \brief
    ///  Creates a MultiPoint object by copying from an array of ordinates.
    /// 
    /// \param dimensionality 
    /// Input dimensionality of the ordinates (see FdoDimensionality)
    /// \param numOrdinates 
    /// Input total number of ordinates in the array
    /// \param ordinates 
    /// Input ordinate array representing positions
    /// 
    /// \return
    /// Returns a MultiPoint
    /// 
    FDO_GEOM_API virtual FdoIMultiPoint* CreateMultiPoint(
        FdoInt32 dimensionality,
        FdoInt32 numOrdinates, 
        double* ordinates);

    /// MultiLineString

    /// \brief
    ///  Creates a MultiLineString object by copying from a collection of LineString objects.
    /// 
    /// \param lineStrings 
    /// Input collection of LineString objects to copy
    /// 
    /// \return
    /// Returns a MultiLineString
    /// 
    FDO_GEOM_API virtual FdoIMultiLineString* CreateMultiLineString(
        FdoLineStringCollection* lineStrings);

    //MultiPolygon

    /// \brief
    ///  Creates a MultiPolygon object by copying from a collection of polygon objects.
    /// 
    /// \param polygons 
    /// Input collection of polygon objects to copy
    /// 
    /// \return
    /// Returns a MultiPolygon
    /// 
    FDO_GEOM_API virtual FdoIMultiPolygon* CreateMultiPolygon(
        FdoPolygonCollection* polygons);

    /// CircularArcSegment

    /// \brief
    ///  Creates a CircularArcSegment object by copying from three points on the arc.
    /// 
    /// \param startPosition 
    /// Input starting position of the arc
    /// \param midPosition 
    /// Input a position on the arc, and not equal to the starting or ending positions
    /// \param endPosition 
    /// Input ending position of the arc
    /// 
    /// \return
    /// Returns a CircularArcSegment
    /// 
    FDO_GEOM_API virtual FdoICircularArcSegment* CreateCircularArcSegment(
        FdoIDirectPosition* startPosition,
        FdoIDirectPosition* midPosition,
        FdoIDirectPosition* endPosition);

    /// CurveString

    /// \brief
    ///  Creates a CurveString object by copying from a collection of CurveSegment objects.
    /// 
    /// \param curveSegments 
    /// Input collection of CurveSegment objects to copy
    /// 
    /// \return
    /// Returns a CurveString
    /// 
    FDO_GEOM_API virtual FdoICurveString* CreateCurveString(
        FdoCurveSegmentCollection* curveSegments);

    /// MultiCurveString

    /// \brief
    ///  Creates a MultiCurveString object by copying from a collection of CurveString objects.
    /// 
    /// \param curveStrings 
    /// Input collection of CurveString objects to copy
    /// 
    /// \return
    /// Returns a MultiCurveString
    /// 
    FDO_GEOM_API virtual FdoIMultiCurveString* CreateMultiCurveString(
        FdoCurveStringCollection* curveStrings);

    /// Ring

    /// \brief
    ///  Creates a ring object by copying from a collection of CurveSegment objects.
    /// 
    /// \param curveSegments 
    /// Input collection of CurveSegment objects to copy
    /// 
    /// \return
    /// Returns a Ring
    /// 
    FDO_GEOM_API virtual FdoIRing* CreateRing(
        FdoCurveSegmentCollection* curveSegments);

    /// CurvePolygon

    /// \brief
    ///  Creates a CurvePolygon object by copying from given ring objects.
    /// 
    /// \param exteriorRing 
    /// Input exterior ring to copy
    /// \param interiorRings 
    /// Input collection of interior rings to copy
    /// 
    /// \return
    /// Returns a CurvePolygon
    /// 
    FDO_GEOM_API virtual FdoICurvePolygon* CreateCurvePolygon(
        FdoIRing* exteriorRing,
        FdoRingCollection* interiorRings);

    /// MultiCurvePolygon

    /// \brief
    ///  Creates a MultiCurvePolygon object by copying from a collection of CurvePolygon objects.
    /// 
    /// \param curvePolygons 
    /// Input collection of CurvePolygon objects to copy
    /// 
    /// \return
    /// Returns a MultiCurvePolygon
    /// 
    FDO_GEOM_API virtual FdoIMultiCurvePolygon* CreateMultiCurvePolygon(
        FdoCurvePolygonCollection* curvePolygons);

    /// MultiGeometry

    /// \brief
    ///  Creates a MultiGeometry object by copying from a collection of Geometry objects.
    /// 
    /// \param geometries 
    /// Input collection of Geometry objects to copy
    /// 
    /// \return
    /// Returns a MultiGeometry
    /// 
    FDO_GEOM_API virtual FdoIMultiGeometry* CreateMultiGeometry(
        FdoGeometryCollection* geometries);

    /// Get an empty (possibly pooled) byte array.
    FDO_GEOM_API virtual FdoByteArray * GetByteArray();

    /// Pool this array, released from some geometry.
    FDO_GEOM_API virtual void TakeReleasedByteArray(FdoByteArray * byteArray);

/// \cond DOXYGEN-IGNORE

protected:

    FdoFgfGeometryFactory2 *         m_private;

    FDO_GEOM_API void Dispose();

    /// Union of public CreateGeometryFromFgf methods. One of byteArray or byteArrayData must be non-NULL.
    FdoIGeometry * CreateGeometryFromFgf(FdoByteArray * byteArray, const FdoByte * byteArrayData, FdoInt32 count);

    /// \brief
    /// Constructs a default instance of a FdoFgfGeometryFactory.
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_GEOM_API FdoFgfGeometryFactory();

    /// \brief
    /// Default destructor.
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_GEOM_API ~FdoFgfGeometryFactory();

    /// Constructor for a private instance.
    FdoFgfGeometryFactory(
        FdoInt32 numGeometries,
        FdoInt32 numPositions,
        FdoInt32 numEnvelopes,
        FdoInt32 numCurveSegments,
        FdoInt32 numRings);

/// \endcond
};
#endif


