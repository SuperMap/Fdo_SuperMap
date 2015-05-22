#ifndef _DIRECTPOSITIONIMPL_H_
#define _DIRECTPOSITIONIMPL_H_

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
#include <Common/Dimensionality.h>
#include <Geometry/IDirectPosition.h>

/// \brief
/// The FdoDirectPositionImpl class is a default implementation of FdoIDirectPosition.
/// FdoDirectPositionImpl implements accessors from FdoIDirectPosition, matching mutators, and simple data members.
/// Assignment and exact equality operators are also provided.
class FdoDirectPositionImpl : public FdoIDirectPosition
{

/// \cond DOXYGEN-IGNORE
protected:
    /// Constructors

    /// \brief
    /// Constructs a default instance of a FdoDirectPositionImpl object.
    /// 
    /// \remarks
    ///  Ordinate values default to numeric_limits<double>::quiet_NaN().
    /// Dimensionality defaults to FdoDimensionality_XY.
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_GEOM_API FdoDirectPositionImpl();

    /// \brief
    /// Constructs a 2D FdoDirectPositionImpl object from X and Y ordinates.
    /// 
    /// \remarks
    ///  Z and M ordinate values default to numeric_limits<double>::quiet_NaN().
    /// Dimensionality is set to FdoDimensionality_XY.
    /// 
    /// \param x 
    /// Input X ordinate value
    /// \param y 
    /// Input Y ordinate value
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_GEOM_API FdoDirectPositionImpl(double x, double y);

    /// \brief
    /// Constructs a 3D FdoDirectPositionImpl object from X, Y and Z ordinates.
    /// 
    /// \remarks
    ///  M ordinate value defaults to numeric_limits<double>::quiet_NaN().
    /// Dimensionality is set to FdoDimensionality_XYZ.
    /// 
    /// \param x 
    /// Input X ordinate value
    /// \param y 
    /// Input Y ordinate value
    /// \param z 
    /// Input Z ordinate value
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_GEOM_API FdoDirectPositionImpl(double x, double y, double z);

    /// \brief
    /// Constructs a 4D FdoDirectPositionImpl object from X, Y, Z and M ordinates.
    /// 
    /// \remarks
    ///  Dimensionality is set to FdoDimensionality_XYZ|FdoDimensionality_M.
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
    /// Returns nothing
    /// 
    FDO_GEOM_API FdoDirectPositionImpl(double x, double y, double z, double m);

    /// \brief
    /// Constructs a FdoDirectPositionImpl object by copying from an ordinate array.
    /// 
    /// \param dimensionality 
    /// Input dimensionality of the ordinates (see FdoDimensionality)
    /// \param ordinates 
    /// Input ordinate array
    /// 
    /// \return
    /// Returns a position
    /// 
    FDO_GEOM_API FdoDirectPositionImpl(FdoInt32 dimensionality, const double * ordinates);

    /// \brief
    /// Copy constructor for FdoDirectPositionImpl
    /// 
    /// \param position 
    /// Input position to copy
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_GEOM_API FdoDirectPositionImpl(const FdoDirectPositionImpl& position);

    /// \brief
    /// Pseudo-copy constructor for FdoDirectPositionImpl
    /// 
    /// \remarks
    ///  Copies position data using only public methods of FdoIDirectPosition,
    /// thus supporting conversion from any implementation of the interface.
    /// 
    /// \param pos 
    /// Input position to copy
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_GEOM_API FdoDirectPositionImpl(const FdoIDirectPosition* pos);

    /// Destructor

    /// \brief
    /// Default destructor.
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_GEOM_API virtual ~FdoDirectPositionImpl();

/// \endcond

public:

    /// \brief
    /// Constructs a default instance of a FdoDirectPositionImpl object.
    /// 
    /// \remarks
    ///  Ordinate values default to numeric_limits<double>::quiet_NaN().
    /// Dimensionality defaults to FdoDimensionality_XY.
    /// 
    /// \return
    /// Returns a position
    /// 
    FDO_GEOM_API static FdoDirectPositionImpl* Create();

    /// \brief
    /// Constructs a 2D FdoDirectPositionImpl object from X and Y ordinates.
    /// 
    /// \remarks
    ///  Z and M ordinate values default to numeric_limits<double>::quiet_NaN().
    /// Dimensionality is set to FdoDimensionality_XY.
    /// 
    /// \param x 
    /// Input X ordinate value
    /// \param y 
    /// Input Y ordinate value
    /// 
    /// \return
    /// Returns a position
    /// 
    FDO_GEOM_API static FdoDirectPositionImpl* Create(double x, double y);

    /// \brief
    /// Constructs a 3D FdoDirectPositionImpl object from X, Y and Z ordinates.
    /// 
    /// \remarks
    ///  M ordinate value defaults to numeric_limits<double>::quiet_NaN().
    /// Dimensionality is set to FdoDimensionality_XY|FdoDimensionality_Z.
    /// 
    /// \param x 
    /// Input X ordinate value
    /// \param y 
    /// Input Y ordinate value
    /// \param z 
    /// Input Z ordinate value
    /// 
    /// \return
    /// Returns a position
    /// 
    FDO_GEOM_API static FdoDirectPositionImpl* Create(double x, double y, double z);

    /// \brief
    /// Constructs a 4D FdoDirectPositionImpl object from X, Y, Z and M ordinates.
    /// 
    /// \remarks
    ///  Dimensionality is set to FdoDimensionality_XY|FdoDimensionality_Z|FdoDimensionality_M.
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
    /// Returns a position
    /// 
    FDO_GEOM_API static FdoDirectPositionImpl* Create(double x, double y, double z, double m);

    /// \brief
    /// Constructs a FdoDirectPositionImpl object by copying from an ordinate array.
    /// 
    /// \param dimensionality 
    /// Input dimensionality of the ordinates (see FdoDimensionality)
    /// \param ordinates 
    /// Input ordinate array
    /// 
    /// \return
    /// Returns a position
    /// 
    FDO_GEOM_API static FdoDirectPositionImpl* Create(FdoInt32 dimensionality, const double* ordinates);

    /// \brief
    /// Constructs a copy of a FdoDirectPositionImpl
    /// 
    /// \param position 
    /// Input position to copy
    /// 
    /// \return
    /// Returns a position
    /// 
    FDO_GEOM_API static FdoDirectPositionImpl* Create(const FdoDirectPositionImpl& position);

    /// \brief
    /// Constructs a copy of a FdoDirectPositionImpl
    /// 
    /// \remarks
    ///  Copies position data using only public methods of FdoIDirectPosition,
    /// thus supporting conversion from any implementation of the interface.
    /// 
    /// \param pos 
    /// Input position to copy
    /// 
    /// \return
    /// Returns a position
    /// 
    FDO_GEOM_API static FdoDirectPositionImpl* Create(const FdoIDirectPosition* pos);

    /// \brief
    /// Assignment operator for FdoDirectPositionImpl.
    /// 
    /// \param position 
    /// Input position to copy
    /// 
    /// \return
    /// Returns a position
    /// 
    FDO_GEOM_API FdoDirectPositionImpl& operator=(const FdoDirectPositionImpl& position);

    /// \brief
    /// Assignment operator for FdoDirectPositionImpl from a FdoIDirectPosition, using public methods.
    /// 
    /// \param position 
    /// Input position to copy
    /// 
    /// \return
    /// Returns a position
    /// 
    FDO_GEOM_API FdoDirectPositionImpl& operator=(const FdoIDirectPosition& position);

    /// \brief
    /// Equality operator for FdoDirectPositionImpl.
    /// 
    /// \param rhs 
    /// Input position for comparison (right-hand-side of equation)
    /// 
    /// \return
    /// Returns true if all ordinates and dimensionality are exactly equal.
    /// 
    FDO_GEOM_API bool operator==(const FdoDirectPositionImpl& rhs) const;

    /// \brief
    /// Gets the X ordinate.
    /// 
    /// \return
    /// Returns the X ordinate; default is numeric_limits<double>::quiet_NaN()
    /// 
    FDO_GEOM_API double GetX() const;

    /// \brief
    /// Gets the Y ordinate.
    /// 
    /// \return
    /// Returns the Y ordinate; default is numeric_limits<double>::quiet_NaN()
    /// 
    FDO_GEOM_API double GetY() const;

    /// \brief
    /// Gets the Z ordinate.
    /// 
    /// \return
    /// Returns the Z ordinate; default is numeric_limits<double>::quiet_NaN()
    /// 
    FDO_GEOM_API double GetZ() const;

    /// \brief
    /// Gets the M ordinate.
    /// 
    /// \return
    /// Returns the M ordinate; default is numeric_limits<double>::quiet_NaN()
    /// 
    FDO_GEOM_API double GetM() const;

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
    /// Gets the dimensionality of ordinates in this position.
    /// 
    /// \remarks
    ///  Values are from the FdoDimensionality enumeration.
    /// A return type of "FdoInt32" is used instead of the enumeration, catering to typical use with bit masking.
    /// 
    /// \return
    /// Returns the ordinate dimensionality
    /// 
    FDO_GEOM_API FdoInt32 GetDimensionality() const;

    /// \brief
    /// Sets the X ordinate.
    /// 
    /// \param x 
    /// Input X ordinate value
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_GEOM_API void SetX(double x);

    /// \brief
    /// Sets the Y ordinate.
    /// 
    /// \param y 
    /// Input Y ordinate value
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_GEOM_API void SetY(double y);

    /// \brief
    /// Sets the Z ordinate.
    /// 
    /// \param z 
    /// Input Z ordinate value
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_GEOM_API void SetZ(double z);

    /// \brief
    /// Sets the M ordinate.
    /// 
    /// \param m 
    /// Input M ordinate value
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_GEOM_API void SetM(double m);

    /// \brief
    /// Sets the dimensionality.
    /// 
    /// \remarks
    ///  Use values (including bitwise combinations) from the FdoDimensionality enumeration.
    /// 
    /// \param dimensionality 
    /// Input dimensionality value
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_GEOM_API void SetDimensionality(FdoInt32 dimensionality);

/// \cond DOXYGEN-IGNORE
protected:

    void Dispose();

    double      m_x;
    double      m_y;
    double      m_z;
    double      m_m;
    FdoInt32    m_dimensionality;

    /// The following is just to retain ownership of the ordinate array in
    /// case GetOrdinates() is called.  An alternative implementation might
    /// optimise for GetOrdinates() by always using "double m_ordinates[4]" 
    /// instead of the m_x, m_y, ... above.
    double *    m_ordinates;

/// \endcond
};
#endif


