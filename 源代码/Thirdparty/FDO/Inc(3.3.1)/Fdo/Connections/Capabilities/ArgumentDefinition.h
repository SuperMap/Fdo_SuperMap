#ifndef _ARGUMENTDEFINITION_H_
#define _ARGUMENTDEFINITION_H_
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
#include <Fdo/Schema/PropertyType.h>
#include <Fdo/Schema/DataType.h>
#include <Fdo/Schema/PropertyValueConstraintList.h>

/// \brief
/// The FdoArgumentDefinition class contains metadata that describes an argument to a function.
class FdoArgumentDefinition : public FdoIDisposable
{

/// \cond DOXYGEN-IGNORE

protected:

    /// Constructs an instance of an FdoArgumentDefinition using the specified arguments.
    FdoArgumentDefinition(FdoString   *name,
                          FdoString   *description,
                          FdoDataType dataType);

    /// Constructs an instance of an FdoArgumentDefinition using the specified arguments.
    FdoArgumentDefinition(FdoString       *name,
                          FdoString       *description,
                          FdoPropertyType propertyType,
                          FdoDataType     dataType);

    /// Constructs an instance of an FdoArgumentDefinition with default properties.
    FdoArgumentDefinition();

    virtual ~FdoArgumentDefinition();

    virtual void Dispose();

/// \endcond

public:

    /// \brief
    /// Constructs an instance of an FdoArgumentDefinition using the specified arguments.
    /// 
    /// \param name 
    /// Input the name of the argument.
    /// \param description 
    /// Input a brief description of the argument.
    /// \param dataType 
    /// Input the type of argument.
    /// 
    /// \return
    /// Returns FdoArgumentDefinition
    /// 
    FDO_API static FdoArgumentDefinition *Create(FdoString   *name,
                                                 FdoString   *description,
                                                 FdoDataType dataType);

    /// \brief
    /// Constructs an instance of an FdoArgumentDefinition using the specified arguments.
    /// 
    /// \param name 
    /// Input the name of the argument.
    /// \param description 
    /// Input a brief description of the argument.
    /// \param propertyType
    /// Input the property type of the argument
    /// \param dataType 
    /// Input the data type of the argument;
    /// This is used only if the argument's property type is FdoPropertyType_DataProperty.
    /// 
    /// \return
    /// Returns FdoArgumentDefinition
    /// 
    FDO_API static FdoArgumentDefinition *Create(FdoString       *name,
                                                 FdoString       *description,
                                                 FdoPropertyType propertyType,
                                                 FdoDataType     dataType);

    /// \brief
    /// Gets the name of the argument.
    /// 
    /// \return
    /// Returns the argument name
    /// 
    FDO_API FdoString *GetName();

    /// \brief
    /// Gets a brief description of the argument.
    /// 
    /// \return
    /// Returns the argument description
    /// 
    FDO_API FdoString *GetDescription();

    /// \brief
    /// Gets the FdoDataType of the argument.
    /// 
    /// \return
    /// Returns the property type of the argument
    /// 
    FDO_API FdoPropertyType GetPropertyType();

    /// \brief
    /// Gets the FdoDataType of the argument.
    /// 
    /// \return
    /// Returns the data type of the argument;
    /// This is valid only if the argument's property type is FdoPropertyType_DataProperty.
    /// 
    FDO_API FdoDataType GetDataType();

    /// \brief
    /// Returns the argument value list for the current argument
    /// 
    /// \return
    /// Returns the argument value list for the current argument
    FDO_API FdoPropertyValueConstraintList *GetArgumentValueList ();

    /// \brief
    /// Sets the argument value list for the current argument
    FDO_API void SetArgumentValueList (FdoPropertyValueConstraintList *argumentValueList);

protected:

    wchar_t                        *m_name;
    wchar_t                        *m_description;
    FdoPropertyType                m_propertyType;
    FdoDataType                    m_dataType;
    FdoPropertyValueConstraintList *m_argumentValueList;

};

#endif


