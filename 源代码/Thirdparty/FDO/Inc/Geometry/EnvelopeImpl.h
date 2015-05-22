#ifndef _ENVELOPEIMPL_H_
#define _ENVELOPEIMPL_H_

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

#include <Geometry/IEnvelope.h>
#include <Geometry/IDirectPosition.h>

/// \brief
/// The FdoEnvelopeImpl class is a default implementation of FdoIEnvelope.
/// FdoEnvelopeImpl implements accessors from FdoIEnvelope, matching mutators, and simple data members.
/// Assignment, exact equality operators, and utility methods are also provided.
class FdoEnvelopeImpl : public FdoIEnvelope
{

/// \cond DOXYGEN-IGNORE
protected:
    /// \brief
    /// Constructs a default instance of a FdoEnvelopeImpl object.
    /// 
    /// \remarks
    ///  Ordinate values default to numeric_limits<double>::quiet_NaN().
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_GEOM_API FdoEnvelopeImpl();

    /// \brief
    /// Constructs a 2D FdoEnvelopeImpl object from X and Y ordinates.
    /// 
    /// \remarks
    ///  Z ordinate value defaults to numeric_limits<double>::quiet_NaN().
    /// 
    /// \param minX 
    /// Input Lower-left X ordinate
    /// \param minY 
    /// Input Lower-left Y ordinate
    /// \param maxX 
    /// Input Upper-right X ordinate
    /// \param maxY 
    /// Input Upper-right Y ordinate
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_GEOM_API FdoEnvelopeImpl(double minX, double minY,
                 double maxX, double maxY);

    /// \brief
    /// Constructs a 3D FdoEnvelopeImpl object from X, Y and Z ordinates.
    /// 
    /// \param minX 
    /// Input Lower-left X ordinate
    /// \param minY 
    /// Input Lower-left Y ordinate
    /// \param minZ 
    /// Input Lower-left, rear Z ordinate
    /// \param maxX 
    /// Input Upper-right X ordinate
    /// \param maxY 
    /// Input Upper-right Y ordinate
    /// \param maxZ 
    /// Input Upper-right, front Z ordinate
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_GEOM_API FdoEnvelopeImpl(double minX, double minY, double minZ,
                 double maxX, double maxY, double maxZ);

    /// \brief
    /// Copy constructor for FdoEnvelopeImpl.
    /// 
    /// \param envelopeImpl 
    /// Input envelope to copy
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_GEOM_API FdoEnvelopeImpl(FdoEnvelopeImpl& envelopeImpl);

    /// \brief
    /// Constructs a FdoEnvelopeImpl object from two positions.
    /// 
    /// \param lowerLeft 
    /// Input Lower-left position
    /// \param upperRight 
    /// Input Upper-right position
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_GEOM_API FdoEnvelopeImpl(FdoIDirectPosition* lowerLeft, FdoIDirectPosition * upperRight);

    /// \brief
    ///  Constructs a FdoEnvelopeImpl object by copying from an array of ordinates.
    /// 
    /// \param dimensionType 
    /// Input dimensionality of the ordinates (see FdoDimensionality)
    /// \param ordinates 
    /// Input ordinate array representing two positions
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_GEOM_API FdoEnvelopeImpl(FdoInt32 dimensionType, double * ordinates);

    /// \brief
    /// Default destructor.
    /// 
    /// \return
    /// Returns nothing
    /// 
    virtual ~FdoEnvelopeImpl();

/// \endcond

public:

    /// \brief
    /// Constructs a default instance of a FdoEnvelopeImpl object.
    /// 
    /// \remarks
    ///  Ordinate values default to numeric_limits<double>::quiet_NaN().
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_GEOM_API static FdoEnvelopeImpl* Create();

    /// \brief
    /// Constructs a 2D FdoEnvelopeImpl object from X and Y ordinates.
    /// 
    /// \remarks
    ///  Z ordinate value defaults to numeric_limits<double>::quiet_NaN().
    /// 
    /// \param minX 
    /// Input Lower-left X ordinate
    /// \param minY 
    /// Input Lower-left Y ordinate
    /// \param maxX 
    /// Input Upper-right X ordinate
    /// \param maxY 
    /// Input Upper-right Y ordinate
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_GEOM_API static FdoEnvelopeImpl* Create(double minX, double minY,
                 double maxX, double maxY);

    /// \brief
    /// Constructs a 3D FdoEnvelopeImpl object from X, Y and Z ordinates.
    /// 
    /// \param minX 
    /// Input Lower-left X ordinate
    /// \param minY 
    /// Input Lower-left Y ordinate
    /// \param minZ 
    /// Input Lower-left, rear Z ordinate
    /// \param maxX 
    /// Input Upper-right X ordinate
    /// \param maxY 
    /// Input Upper-right Y ordinate
    /// \param maxZ 
    /// Input Upper-right, front Z ordinate
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_GEOM_API static FdoEnvelopeImpl* Create(double minX, double minY, double minZ,
                 double maxX, double maxY, double maxZ);

    /// \brief
    /// Constructs a copy of a FdoEnvelopeImpl.
    /// 
    /// \param envelopeImpl 
    /// Input envelope to copy
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_GEOM_API static FdoEnvelopeImpl* Create(FdoEnvelopeImpl& envelopeImpl);

    /// \brief
    /// Constructs a FdoEnvelopeImpl object from two positions.
    /// 
    /// \param lowerLeft 
    /// Input Lower-left position
    /// \param upperRight 
    /// Input Upper-right position
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_GEOM_API static FdoEnvelopeImpl* Create(FdoIDirectPosition* lowerLeft, FdoIDirectPosition * upperRight);

    /// \brief
    ///  Constructs a FdoEnvelopeImpl object by copying from an array of ordinates.
    /// 
    /// \param dimensionType 
    /// Input dimensionality of the ordinates (see FdoDimensionality)
    /// \param ordinates 
    /// Input ordinate array representing two positions
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_GEOM_API static FdoEnvelopeImpl *Create(FdoInt32 dimensionType, double * ordinates);

    /// \brief
    /// Equality operator for FdoEnvelopeImpl.
    /// 
    /// \param rhs 
    /// Input envelope for comparison (right-hand-side of equation)
    /// 
    /// \return
    /// Returns true if all non-NaN ordinates exactly equal.  All NaN values compare as equal to each other.
    /// 
    FDO_GEOM_API bool operator==(FdoEnvelopeImpl& rhs) const;

    /// \brief
    /// Gets the minimum X coordinate value.
    /// 
    /// \return
    /// Returns the minimum X ordinate; numeric_limits<double>::quiet_NaN() by default
    /// 
    FDO_GEOM_API double GetMinX() const;

    /// \brief
    /// Gets the minimum Y coordinate value.
    /// 
    /// \return
    /// Returns the minimum Y ordinate; numeric_limits<double>::quiet_NaN() by default
    /// 
    FDO_GEOM_API double GetMinY() const;

    /// \brief
    /// Gets the minimum Z coordinate value.
    /// 
    /// \return
    /// Returns the minimum Z ordinate; numeric_limits<double>::quiet_NaN() by default
    /// 
    FDO_GEOM_API double GetMinZ() const;

    /// \brief
    /// Gets the maximum X coordinate value.
    /// 
    /// \return
    /// Returns the maximum X ordinate; numeric_limits<double>::quiet_NaN() by default
    /// 
    FDO_GEOM_API double GetMaxX() const;

    /// \brief
    /// Gets the maximum Y coordinate value.
    /// 
    /// \return
    /// Returns the maximum Y ordinate; numeric_limits<double>::quiet_NaN() by default
    /// 
    FDO_GEOM_API double GetMaxY() const;

    /// \brief
    /// Gets the maximum Z coordinate value.
    /// 
    /// \return
    /// Returns the maximum Z ordinate; numeric_limits<double>::quiet_NaN() by default
    /// 
    FDO_GEOM_API double GetMaxZ() const;

    /// \brief
    /// Gets the ordinates as an array.
    /// 
    /// \remarks
    /// The caller must not free the returned array.
    /// The ordinates are in the order XYZM, with only those present 
    /// according to the dimensionality.
    /// 
    /// \return
    /// Returns the ordinates
    /// 
    FDO_GEOM_API virtual const double * GetOrdinates();

    /// \brief
    /// Indicates whether the envelope's extents are set.
    /// 
    /// \return
    /// Returns 'true' if none of the X, Y and Z extents have been set; 'false' otherwise
    /// 
    FDO_GEOM_API bool GetIsEmpty() const;

    /// \brief
    /// Sets the minimum X coordinate value.
    /// 
    /// \param minX 
    /// Input Lower-left X ordinate
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_GEOM_API void SetMinX(double minX);

    /// \brief
    /// Sets the minimum Y coordinate value.
    /// 
    /// \param minY 
    /// Input Lower-left Y ordinate
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_GEOM_API void SetMinY(double minY);

    /// \brief
    /// Sets the minimum Z coordinate value.
    /// 
    /// \param minZ 
    /// Input Lower-left, rear Z ordinate
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_GEOM_API void SetMinZ(double minZ);

    /// \brief
    /// Sets the maximum X coordinate value.
    /// 
    /// \param maxX 
    /// Input Upper-right X ordinate
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_GEOM_API void SetMaxX(double maxX);

    /// \brief
    /// Sets the maximum Y coordinate value.
    /// 
    /// \param maxY 
    /// Input Upper-right Y ordinate
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_GEOM_API void SetMaxY(double maxY);

    /// \brief
    /// Sets the maximum Z coordinate value.
    /// 
    /// \param maxZ 
    /// Input Upper-right, front Z ordinate
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_GEOM_API void SetMaxZ(double maxZ);

    /// \brief
    /// Expands the envelope's extents to include a given position.
    /// 
    /// \param position 
    /// Input position to include in extent
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_GEOM_API void Expand(FdoIDirectPosition* position);

    /// \brief
    /// Expands the envelope's extents to include another envelope.
    /// 
    /// \param envelope 
    /// Input envelope to include in extent
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_GEOM_API void Expand(FdoIEnvelope* envelope);
    
/// \cond DOXYGEN-IGNORE
protected:

    void Dispose();

    double  m_minX;
    double  m_minY;
    double  m_minZ;
    double  m_maxX;
    double  m_maxY;
    double  m_maxZ;
    bool    m_isEmpty;

    /// The following is just to retain ownership of the ordinate array in
    /// case GetOrdinates() is called.  An alternative implementation might
    /// optimise for GetOrdinates() by always using "double m_ordinates[4]" 
    /// instead of the individual ordinate members above.
    double *    m_ordinates;
/// \endcond
};
#endif


