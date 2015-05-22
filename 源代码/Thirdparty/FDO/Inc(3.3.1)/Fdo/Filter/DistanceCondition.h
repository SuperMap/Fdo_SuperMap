#ifndef _DISTANCECONDITION_H_
#define _DISTANCECONDITION_H_
// 

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

#include <FdoStd.h>
#include <Fdo/Filter/DistanceOperations.h>
#include <Fdo/Filter/GeometricCondition.h>
#include <Fdo/Expression/GeometryValue.h>
#include <Fdo/Expression/Identifier.h>
#include <Fdo/Filter/SpatialOperations.h>

class FdoGeometry;

/// \brief
/// The FdoDistanceCondition class derives from FdoGeometricCondition and can be used
/// to test whether the value of a geometric property is within or beyond a
/// specified distance of the specified geometric value. Some feature providers
/// may only support literal geometric values; if so, the provider's capabilities
/// will indicate this limitation.
class FdoDistanceCondition : public FdoGeometricCondition
{
/// \cond DOXYGEN-IGNORE
protected:
    /// Constructs a default instance of an FdoDistanceCondition.
    FdoDistanceCondition();

    /// Constructs an instance of an FdoDistanceCondition using the specified
    /// arguments.
    FdoDistanceCondition(FdoString* propertyName, FdoDistanceOperations operation, FdoExpression* geometry, double distance);

    /// Constructs an instance of an FdoDistanceCondition using the specified
    /// arguments.
    FdoDistanceCondition(FdoIdentifier* propertyName, FdoDistanceOperations operation, FdoExpression* geometry, double distance);

    virtual ~FdoDistanceCondition();

    virtual void Dispose();
/// \endcond

public:

    /// \brief
    /// Constructs a default instance of an FdoDistanceCondition.
    /// 
    /// \return
    /// Returns FdoDistanceCondition
    /// 
    FDO_API static FdoDistanceCondition* Create();

    /// \brief
    /// Constructs an instance of an FdoDistanceCondition using the specified arguments.
    /// 
    /// \param propertyName 
    /// Input property name
    /// \param operation 
    /// Input operation
    /// \param geometry 
    /// Input geometry
    /// \param distance 
    /// Input distance
    /// 
    /// \return
    /// Returns FdoDistanceCondition
    /// 
    FDO_API static FdoDistanceCondition* Create(FdoString* propertyName, FdoDistanceOperations operation, FdoExpression* geometry, double distance);

    /// \brief
    /// Constructs an instance of an FdoDistanceCondition using the specified arguments.
    /// 
    /// \param propertyName 
    /// Input property name
    /// \param operation 
    /// Input operation
    /// \param geometry 
    /// Input geometry
    /// \param distance 
    /// Input distance
    /// 
    /// \return
    /// Returns FdoDistanceCondition
    /// 
    FDO_API static FdoDistanceCondition* Create(FdoIdentifier* propertyName, FdoDistanceOperations operation, FdoExpression* geometry, double distance);

    /// \brief
    /// Gets the distance operation to use.
    /// 
    /// \return
    /// Returns the distance operation
    /// 
    FDO_API FdoDistanceOperations GetOperation();

    /// \brief
    /// Sets the distance operation to use.
    /// 
    /// \param value 
    /// Input the distance operation
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API void SetOperation(FdoDistanceOperations value);

    /// \brief
    /// Gets the literal geometric value.
    /// 
    /// \return
    /// Returns the literal geometric value
    /// 
    FDO_API FdoExpression* GetGeometry();

    /// \brief
    /// Sets the literal geometric value.
    /// 
    /// \param value 
    /// Input the literal geometric value
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API void SetGeometry(FdoExpression* value);

    /// \brief
    /// Gets the distance value.
    /// 
    /// \return
    /// Returns the distance value
    /// 
    FDO_API double GetDistance();

    /// \brief
    /// Sets the distance value.
    /// 
    /// \param value 
    /// Input the distance value
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API void SetDistance(double value);

    /// \brief
    /// Overrides FdoFilter.Process to pass the FdoDistanceCondition to the
    /// appropriate filter processor operation.
    /// 
    /// \param p 
    /// Input filter processor
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API void Process(FdoIFilterProcessor* p);

/// \cond DOXYGEN-IGNORE

    /// \brief
    /// This is an internal method. It returns the well defined text representation of the filter. 
    /// 
    /// \param pIdCol 
    /// A identifier collection that contains all the computed identifier used by the filter
    /// 
    /// \return
    /// Returns the well defined text string
    /// 
    FdoString* ToStringInternal( FdoIdentifierCollection *pIdCol );
/// \endcond

private:
    FdoExpression*          m_geometry;
    double                  m_distance;
    FdoDistanceOperations   m_operation;
};
#endif


