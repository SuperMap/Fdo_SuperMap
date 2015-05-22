#ifndef _GEOMETRYFACTORYABSTRACT_H_
#define _GEOMETRYFACTORYABSTRACT_H_

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

#include <FdoCommon.h>
#include <Geometry/GeometryStd.h>

/// \brief
///  
/// The FdoGeometryFactoryAbstract class is a factory (abstract, non-pure) for Geometry objects and Geometry helper objects.
class FdoGeometryFactoryAbstract : public FdoIDisposable
{
public:

    /// Position

    /// \brief
    ///  Creates a position object using X and Y ordinates.
    /// 
    /// \remarks
    ///  The resulting object's accessor methods for ordinates
    /// that are not given here as input parameters will return the default
    /// value of 0.0.
    /// 
    /// \param x 
    /// Input X ordinate value
    /// \param y 
    /// Input Y ordinate value
    /// 
    /// \return
    /// Returns a direct position
    /// 
    FDO_GEOM_API virtual FdoIDirectPosition* CreatePositionXY(
        double x,
        double y);               

    /// \brief
    ///  Creates a position object using X, Y and Z ordinates.
    /// 
    /// \remarks
    ///  The resulting object's accessor methods for ordinates
    /// that are not given here as input parameters will return the default
    /// value of 0.0.
    /// 
    /// \param x 
    /// Input X ordinate value
    /// \param y 
    /// Input Y ordinate value
    /// \param z 
    /// Input Z ordinate value
    /// 
    /// \return
    /// Returns a direct position
    /// 
    FDO_GEOM_API virtual FdoIDirectPosition* CreatePositionXYZ(
        double x, 
        double y,
        double z);

    /// \brief
    ///  Creates a position object using X, Y and M ordinates.
    /// 
    /// \remarks
    ///  The resulting object's accessor methods for ordinates
    /// that are not given here as input parameters will return the default
    /// value of 0.0.
    /// 
    /// \param x 
    /// Input X ordinate value
    /// \param y 
    /// Input Y ordinate value
    /// \param m 
    /// Input M ordinate value
    /// 
    /// \return
    /// Returns a direct position
    /// 
    FDO_GEOM_API virtual FdoIDirectPosition* CreatePositionXYM(
        double x,
        double y,
        double m);

    /// \brief
    ///  Creates a position object using X, Y, Z and M ordinates.
    /// 
    /// \param x 
    /// Input X ordinate value
    /// \param y 
    /// Input Y ordinate value
    /// \param z 
    /// Input Z ordinate value
    /// \param m 
    /// Input M ordinate value
    /// 
    /// \return
    /// Returns a direct position
    /// 
    FDO_GEOM_API virtual FdoIDirectPosition* CreatePositionXYZM(
        double x,
        double y, 
        double z, 
        double m);

    FDO_GEOM_API virtual FdoIDirectPosition* CreatePosition(
        FdoInt32 dimensionality,
        const double * ordinates);

    /// \brief
    ///  Creates a position object by copying from an existing position.
    /// 
    /// \param position 
    /// Input position to copy
    /// 
    /// \return
    /// Returns a direct position
    /// 
    FDO_GEOM_API virtual FdoIDirectPosition* CreatePosition(
        FdoIDirectPosition * position);

    /// Envelope

    /// \brief
    ///  Creates an envelope object using two positions.
    /// 
    /// \param lowerLeft 
    /// Input lower-left position
    /// \param upperRight 
    /// Input upper-right position
    /// 
    /// \return
    /// Returns an envelope
    /// 
    FDO_GEOM_API virtual FdoIEnvelope* CreateEnvelope(
        FdoIDirectPosition * lowerLeft,
        FdoIDirectPosition * upperRight);

    /// \brief
    ///  Creates an envelope object by copying from an array of ordinates.
    /// 
    /// \param dimensionType 
    /// Input dimensionality of the ordinates (see FdoDimensionality)
    /// \param ordinates 
    /// Input ordinate array representing two positions
    /// 
    /// \return
    /// Returns an envelope
    /// 
    FDO_GEOM_API virtual FdoIEnvelope* CreateEnvelope(
        FdoInt32 dimensionType, 
        double * ordinates);

    /// \brief
    ///  Creates an envelope object using X and Y ordinates.
    /// 
    /// \param lowerLeftX 
    /// Input lower-left X ordinate
    /// \param lowerLeftY 
    /// Input lower-left Y ordinate
    /// \param upperRightX 
    /// Input upper-right X ordinate
    /// \param upperRightY 
    /// Input upper-right Y ordinate
    /// 
    /// \return
    /// Returns an envelope
    /// 
    FDO_GEOM_API virtual FdoIEnvelope* CreateEnvelopeXY(
        double lowerLeftX,
        double lowerLeftY,
        double upperRightX, 
        double upperRightY);

    /// \brief
    ///  Creates an envelope object using X, Y and Z ordinates.
    /// 
    /// \param lowerLeftX 
    /// Input lower-left, rear X ordinate
    /// \param lowerLeftY 
    /// Input lower-left, rear Y ordinate
    /// \param lowerLeftZ 
    /// Input lower-left, rear Z ordinate
    /// \param upperRightX 
    /// Input upper-right, front X ordinate
    /// \param upperRightY 
    /// Input upper-right, front Y ordinate
    /// \param upperRightZ 
    /// Input upper-right, front Z ordinate
    /// 
    /// \return
    /// Returns an envelope
    /// 
    FDO_GEOM_API virtual FdoIEnvelope* CreateEnvelopeXYZ(
        double lowerLeftX,
        double lowerLeftY,
        double lowerLeftZ,
        double upperRightX,
        double upperRightY,
        double upperRightZ);

    /// \brief
    ///  Creates a envelope object by copying from another envelope.
    /// 
    /// \param envelope 
    /// Input Source envelope
    /// 
    /// \return
    /// Returns an envelope
    /// 
    FDO_GEOM_API virtual FdoIEnvelope* CreateEnvelope(
        FdoIEnvelope * envelope);

    /// LineString

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
        FdoDirectPositionCollection* positions) = 0;

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
        double* ordinates) = 0;

    /// Geometry

    /// \brief
    ///  Creates a Geometry object by copying from another Geometry.
    /// 
    /// \remarks
    ///  This is a pseudo-copy-constructor.
    /// It is required that any implementation use only public methods on the underlying 
    /// Geometry object, thus enabling conversion from geometries of the same (or any
    /// other) implementation of this Geometry package.
    /// 
    /// \param geometry 
    /// Input Source geometry
    /// 
    /// \return
    /// Returns an envelope
    /// 
    FDO_GEOM_API virtual FdoIGeometry * CreateGeometry(
        FdoIGeometry * geometry) = 0;

    /// \brief
    ///  Creates a Geometry object by converting from a text string.
    /// 
    /// \remarks
    ///  While this method is not pure virtual, its default implementation will
    /// throw an exception if called.  A concrete, derived class should override this
    /// method if conversion from text is required.
    /// 
    /// \param text 
    /// Input Source geometry text
    /// 
    /// \return
    /// Returns a Geometry
    /// 
    FDO_GEOM_API FdoIGeometry * CreateGeometry(
        FdoString* text);

    /// \brief
    ///  Creates a Geometry object by converting from an envelope.
    /// 
    /// \remarks
    ///  This method will produce a new Geometry 
    /// based on the given envelope.  The actual geometry type produced is implementation-dependent.
    /// 
    /// \param envelope 
    /// Input Source envelope
    /// 
    /// \return
    /// Returns a Geometry
    /// 
    FDO_GEOM_API virtual FdoIGeometry * CreateGeometry(
        FdoIEnvelope * envelope) = 0;

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
        FdoIDirectPosition* position) = 0;

    /// \brief
    ///  Creates a point object by copying from an array of ordinates.
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
        double* ordinates) = 0;

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
        FdoDirectPositionCollection* positions) = 0;

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
        double* ordinates) = 0;

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
        FdoDirectPositionCollection* positions) = 0;

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
        double* ordinates) = 0;

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
        FdoLinearRingCollection* interiorRings) = 0;

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
        FdoPointCollection* points) = 0;

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
        double* ordinates) = 0;

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
        FdoLineStringCollection* lineStrings) = 0;

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
        FdoPolygonCollection* polygons) = 0;

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
        FdoIDirectPosition* endPosition) = 0;

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
        FdoCurveSegmentCollection* curveSegments) = 0;

    /// MultiCurveString

    /// \brief
    ///  Creates an MultiCurveString object by copying from a collection of CurveString objects.
    /// 
    /// \param curveStrings 
    /// Input collection of CurveString objects to copy
    /// 
    /// \return
    /// Returns a MultiCurveString
    /// 
    FDO_GEOM_API virtual FdoIMultiCurveString* CreateMultiCurveString(
        FdoCurveStringCollection* curveStrings) = 0;

    /// Ring

    /// \brief
    ///  Creates a ring object by copying from a collection of CurveSegment objects.
    /// 
    /// \param curveSegments 
    /// Input collection of CurveSegment objects to copy
    /// 
    /// \return
    /// Returns a ring
    /// 
    FDO_GEOM_API virtual FdoIRing* CreateRing(
        FdoCurveSegmentCollection* curveSegments) = 0;

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
        FdoRingCollection* interiorRings) = 0;

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
        FdoCurvePolygonCollection* curvePolygons) = 0;

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
        FdoGeometryCollection* geometries) = 0;

protected:

    /// \brief
    /// Constructs a default instance of a FdoGeometryFactoryAbstract.
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_GEOM_API FdoGeometryFactoryAbstract() {};

    /// \brief
    /// Default destructor.
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_GEOM_API virtual ~FdoGeometryFactoryAbstract() {};
};
#endif


