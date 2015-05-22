#ifndef _GEOMETRICCONDITION_H_
#define _GEOMETRICCONDITION_H_
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
#include <Fdo/Expression/Identifier.h>
#include <Fdo/Filter/SearchCondition.h>

/// \brief
/// The FdoGeometricCondition abstract class derives from FdoSearchCondition and can
/// be used to test whether the value of a geometric property meets a particular
/// spatial criteria. FdoGeometricCondition is the base class for FdoDistanceCondition
/// and FdoSpatialCondition.
class FdoGeometricCondition : public FdoSearchCondition
{
/// \cond DOXYGEN-IGNORE
protected:
    /// Constructs a default instance of an FdoGeometricCondition.
    FdoGeometricCondition();

    /// Constructs an instance of an FdoGeometricCondition using the specified
    /// arguments.
    FdoGeometricCondition(FdoString* propertyName);

    /// Constructs an instance of an FdoGeometricCondition using the specified
    /// arguments.
    FdoGeometricCondition(FdoIdentifier* propertyName);

    virtual ~FdoGeometricCondition();
/// \endcond

public:
    /// \brief
    /// Gets the name of the geometric property.
    /// 
    /// \return
    /// Returns the name of the geometric property
    /// 
    FDO_API FdoIdentifier* GetPropertyName();

    /// \brief
    /// Sets the name of the geometric property.
    /// 
    /// \param value 
    /// Input the name of the geometric property
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API void SetPropertyName(FdoIdentifier* value);

private:
    FdoIdentifier*  m_geometricPropertyName;
};
#endif


