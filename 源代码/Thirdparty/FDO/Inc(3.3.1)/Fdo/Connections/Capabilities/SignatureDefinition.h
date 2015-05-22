#ifndef _SIGNATUREDEFINITION_H_
#define _SIGNATUREDEFINITION_H_
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
#include <Fdo/IDisposableCollection.h>
#include <Fdo/Schema/SchemaException.h>
#include <Fdo/ReadOnlyUnnamedCollection.h>
#include <Fdo/Connections/Capabilities/ReadOnlyArgumentDefinitionCollection.h>

class FdoSignatureDefinition : public FdoIDisposable
{
public:
    /// \brief
    /// Constructs an instance of a SignatureDefinition using the specified arguments.
    FDO_API static FdoSignatureDefinition* Create (
                                                            FdoDataType                     returnType,
                                                            FdoArgumentDefinitionCollection *arguments);

    /// \brief
    /// Constructs an instance of a SignatureDefinition using the specified arguments.
    FDO_API static FdoSignatureDefinition* Create (
                                                            FdoPropertyType                 returnPropertyType,
                                                            FdoDataType                     returnType,
                                                            FdoArgumentDefinitionCollection *arguments);

    /// \brief
    /// Gets an array of FdoArgumentDefinition objects required for the function. 
    FDO_API FdoReadOnlyArgumentDefinitionCollection* GetArguments ();

    /// \brief
    /// Gets the FdoPropertyType of the function return value.
    FDO_API FdoPropertyType GetReturnPropertyType ();

    /// \brief
    /// Gets the FdoDataType of the function return value. This is only valid if the function return property type is
    /// FdoPropertyType_DataProperty.
    FDO_API FdoDataType GetReturnType ();


/// \cond DOXYGEN-IGNORE
protected:
    /// Constructs an instance of a SignatureDefinition using the specified arguments.
    FdoSignatureDefinition (FdoDataType                     returnType,
                            FdoArgumentDefinitionCollection *arguments);

    /// Constructs an instance of a SignatureDefinition using the specified arguments.
    FdoSignatureDefinition (FdoPropertyType                 returnPropertyType,
                            FdoDataType                     returnType,
                            FdoArgumentDefinitionCollection *arguments);

    /// Constructs an instance of an SignatureDefinition with default properties.
    FdoSignatureDefinition();

    virtual ~FdoSignatureDefinition();

    virtual void Dispose();
/// \endcond
private:

    FdoDataType                             m_returnDataType;
    FdoPropertyType                         m_returnPropertyType;
    FdoReadOnlyArgumentDefinitionCollection *m_arguments;

};

// -----------------------------------------------------------------------------------------------------

/// \brief
/// The FdoSignatureDefinitionCollection class represents a collection of FdoSignatureDefinition objects.
class FdoSignatureDefinitionCollection : public FdoCollection<FdoSignatureDefinition, FdoConnectionException>
{
protected:
    virtual void Dispose()
    {
        delete this;
    }

public:
    /// \brief
    /// Constructs a default empty instance of an FdoSignatureDefinitionCollection.
    /// 
    /// \return
    /// Returns FdoSignatureDefinitionCollection
    /// 
    FDO_API static FdoSignatureDefinitionCollection *Create();

    /// \brief
    /// Constructs an FdoArgumentDefinitionCollection from an array of FdoArgumentDefinition objects.
    /// 
    /// \param arguments 
    /// Input an array of FdoArgumentDefinition objects
    /// \param length 
    /// Input the number of arguments
    /// 
    /// \return
    /// Returns FdoArgumentDefinitionCollection
    /// 
    FDO_API static FdoSignatureDefinitionCollection *Create(FdoSignatureDefinition** arguments, FdoInt32 length);

};

// -----------------------------------------------------------------------------------------------------

class FdoReadOnlySignatureDefinitionCollection : public FdoReadOnlyUnnamedCollection<FdoSignatureDefinition, 
                                                                                     FdoSignatureDefinitionCollection, 
                                                                                     FdoSchemaException>
{
/// \cond DOXYGEN-IGNORE
protected:
    /// Constructs an instance of a SignatureDefinition using the specified arguments.
    FdoReadOnlySignatureDefinitionCollection ();

    virtual ~FdoReadOnlySignatureDefinitionCollection();

    virtual void Dispose()
    {
        delete this;
    }
/// \endcond

public:
    /// \brief
    /// Constructs an instance of an FdoReadOnlySignatureDefinitionCollection by providing a non-readonly collection.
    /// 
    /// \param col 
    /// Input a signature collection
    /// 
    /// \return
    /// Returns FdoReadOnlySignatureDefinitionCollection
    /// 
    FDO_API static FdoReadOnlySignatureDefinitionCollection* Create(FdoSignatureDefinitionCollection *col);
};

#endif
