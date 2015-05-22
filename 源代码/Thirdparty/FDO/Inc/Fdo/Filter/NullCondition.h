#ifndef _NULLCONDITION_H_
#define _NULLCONDITION_H_
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
/// The FdoNullCondition class derives from FdoSearchCondition and can be used to test
/// if the value of a specified data property is null.
class FdoNullCondition : public FdoSearchCondition
{
/// \cond DOXYGEN-IGNORE
protected:
    /// Constructs a default instance of an FdoNullCondition.
    FdoNullCondition();

    /// Constructs an instance of an FdoNullCondition using the specified arguments.
    FdoNullCondition(FdoString* propertyName);

    /// Constructs an instance of an FdoNullCondition using the specified arguments.
    FdoNullCondition(FdoIdentifier* propertyName);

    virtual ~FdoNullCondition();

    virtual void Dispose();
/// \endcond

public:
    /// \brief
    /// Constructs a default instance of an FdoNullCondition.
    /// 
    /// \return
    /// Returns an FdoNullCondition
    /// 
    FDO_API static FdoNullCondition* Create();

    /// \brief
    /// Constructs an instance of an FdoNullCondition using the specified arguments.
    /// 
    /// \param propertyName 
    /// Input name
    /// 
    /// \return
    /// Returns an FdoNullCondition
    /// 
    FDO_API static FdoNullCondition* Create(FdoString* propertyName);

    /// \brief
    /// Constructs an instance of an FdoNullCondition using the specified arguments.
    /// 
    /// \param propertyName 
    /// Input name
    /// 
    /// \return
    /// Returns an FdoNullCondition
    /// 
    FDO_API static FdoNullCondition* Create(FdoIdentifier* propertyName);

    /// \brief
    /// Gets the name of the data property.
    /// 
    /// \return
    /// Returns FdoIdentifier
    /// 
    FDO_API FdoIdentifier* GetPropertyName();

    /// \brief
    ///  Sets the name of the data property.
    /// 
    /// \param value 
    /// Input name
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API void SetPropertyName(FdoIdentifier* value);

    /// \brief
    /// Overrides FdoFilter.Process to pass the FdoNullCondition to the
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
    FdoIdentifier*  m_propertyName;
};
#endif


