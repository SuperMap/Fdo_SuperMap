#ifndef _INCONDITION_H_
#define _INCONDITION_H_
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
#include <Fdo/Filter/ValueExpressionCollection.h>
#include <Fdo/Expression/Identifier.h>
#include <Fdo/Filter/SearchCondition.h>

/// \brief
/// The FdoInCondition class derives from FdoSearchCondition and can be used to test
/// if the value of a specified data property is within a given set of literal
/// values.
class FdoInCondition : public FdoSearchCondition
{
/// \cond DOXYGEN-IGNORE
protected:
    /// Constructs a default instance of an FdoInCondition.
    FdoInCondition();

    /// Constructs an instance of an FdoInCondition using the specified arguments.
    FdoInCondition(FdoString* propertyName, FdoString** values, FdoInt32 length);

    /// Constructs an instance of an FdoInCondition using the specified arguments.
    FdoInCondition(FdoIdentifier* propertyName, FdoString** values, FdoInt32 length);

    virtual ~FdoInCondition();

    virtual void Dispose();
/// \endcond

public:
    /// \brief
    /// Constructs a default instance of an FdoInCondition.
    /// 
    /// \return
    /// Returns FdoInCondition
    /// 
    FDO_API static FdoInCondition* Create();

    /// \brief
    /// Constructs an instance of an FdoInCondition using the specified arguments.
    /// 
    /// \param propertyName 
    /// Input property name
    /// \param values 
    /// Input array of values
    /// \param length 
    /// Input number of values
    /// 
    /// \return
    /// Returns FdoInCondition
    /// 
    FDO_API static FdoInCondition* Create(FdoString* propertyName, FdoString** values, FdoInt32 length);

    /// \brief
    /// Constructs an instance of an FdoInCondition using the specified arguments.
    /// 
    /// \param propertyName 
    /// Input property name
    /// \param values 
    /// Input array of values
    /// \param length 
    /// Input number of values
    /// 
    /// \return
    /// Returns FdoInCondition
    /// 
    FDO_API static FdoInCondition* Create(FdoIdentifier* propertyName, FdoString** values, FdoInt32 length);

    /// \brief
    /// Constructs an instance of an FdoInCondition using the specified arguments.
    /// 
    /// \param propertyName 
    /// Input property name
    /// \param pCollection 
    /// Input collection of values
    /// 
    /// \return
    /// Returns FdoInCondition
    /// 
    FDO_API static FdoInCondition* Create(FdoIdentifier* propertyName, FdoValueExpressionCollection* pCollection);

    /// \brief
    /// Gets the name of the data property.
    /// 
    /// \return
    /// Returns the name of the data property
    /// 
    FDO_API FdoIdentifier* GetPropertyName();

    /// \brief
    /// Sets the name of the data property.
    /// 
    /// \param value 
    /// Input the name of the data property
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API void SetPropertyName(FdoIdentifier* value);

    /// \brief
    ///  Gets the FdoLiteralCollection that contains the literal values.
    /// 
    /// \return
    /// Returns FdoValueExpressionCollection
    /// 
    FDO_API FdoValueExpressionCollection* GetValues();

    /// \brief
    /// Overrides FdoFilter.Process to pass the FdoInCondition to the appropriate
    /// filter processor operation.
    /// 
    /// \param p 
    /// Input filter processor
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API void Process(FdoIFilterProcessor* p);

    /// \brief
    /// Converts the filter expression to its well defined text representation.
    /// 
    /// \return
    /// Returns well defined text string
    /// 
    FDO_API FdoString* ToStringInternal( FdoIdentifierCollection *pIdCol );

private:
    FdoIdentifier*                  m_propertyName;
    FdoValueExpressionCollection*   m_values;
};
#endif


