#ifndef _SPATIALCONDITION_H_
#define _SPATIALCONDITION_H_
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
#include <Fdo/Filter/GeometricCondition.h>
#include <Fdo/Expression/Identifier.h>
#include <Fdo/Expression/GeometryValue.h>
#include <Fdo/Filter/SpatialOperations.h>

class FdoGeometry;

/// \brief
/// The FdoSpatialCondition class derives from FdoGeometricCondition and can be used
/// to test whether the value of a geometric property (referenced using the name
/// of the property) and another geometric value satisfy the spatial
/// relationship implied by the operation. Some feature providers may only
/// support literal geometric values; if so, the provider's capabilities 
/// will indicate this limitation.
class FdoSpatialCondition : public FdoGeometricCondition
{
/// \cond DOXYGEN-IGNORE
protected:
    /// Constructs a default instance of an FdoSpatialCondition.
    FdoSpatialCondition();

    /// Constructs an instance of an FdoSpatialCondition using the specified
    /// arguments.
    FdoSpatialCondition(FdoString* propertyName, FdoSpatialOperations operation, FdoExpression* geometry);

    /// Constructs an instance of an FdoSpatialCondition using the specified
    /// arguments.
    FdoSpatialCondition(FdoIdentifier* propertyName, FdoSpatialOperations operation, FdoExpression* geometry);

    virtual ~FdoSpatialCondition();

    virtual void Dispose();
/// \endcond

public:
    /// \brief
    /// Constructs a default instance of an FdoSpatialCondition.
    /// 
    /// \return
    /// Returns FdoSpatialCondition
    /// 
    FDO_API static FdoSpatialCondition* Create();

    /// \brief
    /// Constructs an instance of an FdoSpatialCondition using the specified arguments.
    /// 
    /// \param propertyName 
    /// Input property name
    /// \param operation 
    /// Input spatial operation
    /// \param geometry 
    /// Input geometry
    /// 
    /// \return
    /// Returns FdoSpatialCondition
    /// 
    FDO_API static FdoSpatialCondition* Create(FdoString* propertyName, FdoSpatialOperations operation, FdoExpression* geometry);

    /// \brief
    /// Constructs an instance of an FdoSpatialCondition using the specified arguments.
    /// 
    /// \param propertyName 
    /// Input property name
    /// \param operation 
    /// Input spatial operation
    /// \param geometry 
    /// Input geometry
    /// 
    /// \return
    /// Returns FdoSpatialCondition
    /// 
    FDO_API static FdoSpatialCondition* Create(FdoIdentifier* propertyName, FdoSpatialOperations operation, FdoExpression* geometry);

    /// \brief
    /// Gets the spatial operation to use.
    /// 
    /// \return
    /// Returns the spatial operation to use
    /// 
    FDO_API FdoSpatialOperations GetOperation();

    /// \brief
    /// Sets the spatial operation to use.
    /// 
    /// \param value 
    /// Input the spatial operation to use
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API void SetOperation(FdoSpatialOperations value);

    /// \brief
    /// Gets the literal geometric value.
    /// 
    /// \return
    /// Returns the literal geometric valueg
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
    /// Overrides FdoFilter.Process to pass the FdoSpatialCondition to the
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
    FdoSpatialOperations    m_operation;
};
#endif


