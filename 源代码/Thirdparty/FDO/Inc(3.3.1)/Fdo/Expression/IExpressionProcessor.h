#ifndef _EXPRESSIONPROCESSOR_H_
#define _EXPRESSIONPROCESSOR_H_
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
#include <Fdo/Expression/BinaryExpression.h>
#include <Fdo/Expression/UnaryExpression.h>
#include <Fdo/Expression/Function.h>
#include <Fdo/Expression/Identifier.h>
#include <Fdo/Expression/ComputedIdentifier.h>
#include <Fdo/Expression/Parameter.h>
#include <Fdo/Expression/BooleanValue.h>
#include <Fdo/Expression/ByteValue.h>
#include <Fdo/Expression/DateTimeValue.h>
#include <Fdo/Expression/DecimalValue.h>
#include <Fdo/Expression/DoubleValue.h>
#include <Fdo/Expression/Int16Value.h>
#include <Fdo/Expression/Int32Value.h>
#include <Fdo/Expression/Int64Value.h>
#include <Fdo/Expression/SingleValue.h>
#include <Fdo/Expression/StringValue.h>
#include <Fdo/Expression/BLOBValue.h>
#include <Fdo/Expression/CLOBValue.h>
#include <Fdo/Expression/GeometryValue.h>

/// \brief
/// The FdoIExpressionProcessor interface can be used to process the nodes in an
/// Expression tree. It declares an process operation for each concrete class in
/// the FdoExpression hierarchy. Providers or client applications can create
/// classes that realize this interface to do something meaningful with an
/// FdoExpression hierarchy. For example, an RDBMS feature provider implements a
/// processor class to convert an FdoExpression hierarchy to the SQL equivalent
/// syntax.
class FdoIExpressionProcessor : public FdoIDisposable
{
public:

    /// \brief
    /// Processes the FdoBinaryExpression passed in as an argument.
    /// 
    /// \param expr 
    /// Input binary expression
    /// 
    /// \return
    /// Returns nothing
    /// 
    virtual void ProcessBinaryExpression(FdoBinaryExpression& expr) = 0;

    /// \brief
    /// Processes the FdoUnaryExpression passed in as an argument.
    /// 
    /// \param expr 
    /// Input unary expression
    /// 
    /// \return
    /// Returns nothing
    /// 
    virtual void ProcessUnaryExpression(FdoUnaryExpression& expr) = 0;

    /// \brief
    /// Processes the FdoFunction passed in as an argument.
    /// 
    /// \param expr 
    /// Input function
    /// 
    /// \return
    /// Returns nothing
    /// 
    virtual void ProcessFunction(FdoFunction& expr) = 0;

    /// \brief
    /// Processes the FdoIdentifier passed in as an argument.
    /// 
    /// \param expr 
    /// Input indentifier
    /// 
    /// \return
    /// Returns nothing
    /// 
    virtual void ProcessIdentifier(FdoIdentifier& expr) = 0;

    /// \brief
    /// Processes the FdoComputedIdentifier passed in as an argument.
    /// 
    /// \param expr 
    /// Input indentifier
    /// 
    /// \return
    /// Returns nothing
    /// 
    virtual void ProcessComputedIdentifier(FdoComputedIdentifier& expr) = 0;

    /// \brief
    /// Processes the FdoParameter passed in as an argument.
    /// 
    /// \param expr 
    /// Input parameter
    /// 
    /// \return
    /// Returns nothing
    /// 
    virtual void ProcessParameter(FdoParameter& expr) = 0;

    /// \brief
    /// Processes the FdoBooleanValue passed in as an argument.
    /// 
    /// \param expr 
    /// Input data value
    /// 
    /// \return
    /// Returns nothing
    /// 
    virtual void ProcessBooleanValue(FdoBooleanValue& expr) = 0;

    /// \brief
    /// Processes the FdoByteValue passed in as an argument.
    /// 
    /// \param expr 
    /// Input data value
    /// 
    /// \return
    /// Returns nothing
    /// 
    virtual void ProcessByteValue(FdoByteValue& expr) = 0;

    /// \brief
    /// Processes the FdoDateTimeValue passed in as an argument.
    /// 
    /// \param expr 
    /// Input data value
    /// 
    /// \return
    /// Returns nothing
    /// 
    virtual void ProcessDateTimeValue(FdoDateTimeValue& expr) = 0;

    /// \brief
    /// Processes the FdoDecimalValue passed in as an argument.
    /// 
    /// \param expr 
    /// Input data value
    /// 
    /// \return
    /// Returns nothing
    /// 
    virtual void ProcessDecimalValue(FdoDecimalValue& expr) = 0;

    /// \brief
    /// Processes the FdoDoubleValue passed in as an argument.
    /// 
    /// \param expr 
    /// Input data value
    /// 
    /// \return
    /// Returns nothing
    /// 
    virtual void ProcessDoubleValue(FdoDoubleValue& expr) = 0;

    /// \brief
    /// Processes the FdoInt16Value passed in as an argument.
    /// 
    /// \param expr 
    /// Input data value
    /// 
    /// \return
    /// Returns nothing
    /// 
    virtual void ProcessInt16Value(FdoInt16Value& expr) = 0;

    /// \brief
    /// Processes the FdoInt32Value passed in as an argument.
    /// 
    /// \param expr 
    /// Input data value
    /// 
    /// \return
    /// Returns nothing
    /// 
    virtual void ProcessInt32Value(FdoInt32Value& expr) = 0;

    /// \brief
    /// Processes the FdoInt64Value passed in as an argument.
    /// 
    /// \param expr 
    /// Input data value
    /// 
    /// \return
    /// Returns nothing
    /// 
    virtual void ProcessInt64Value(FdoInt64Value& expr) = 0;

    /// \brief
    /// Processes the FdoSingleValue passed in as an argument.
    /// 
    /// \param expr 
    /// Input data value
    /// 
    /// \return
    /// Returns nothing
    /// 
    virtual void ProcessSingleValue(FdoSingleValue& expr) = 0;

    /// \brief
    /// Processes the FdoStringValue passed in as an argument.
    /// 
    /// \param expr 
    /// Input data value
    /// 
    /// \return
    /// Returns nothing
    /// 
    virtual void ProcessStringValue(FdoStringValue& expr) = 0;

    /// \brief
    /// Processes the FdoBLOBValue passed in as an argument.
    /// 
    /// \param expr 
    /// Input data value
    /// 
    /// \return
    /// Returns nothing
    /// 
    virtual void ProcessBLOBValue(FdoBLOBValue& expr) = 0;

    /// \brief
    /// Processes the FdoCLOBValue passed in as an argument.
    /// 
    /// \param expr 
    /// Input data value
    /// 
    /// \return
    /// Returns nothing
    /// 
    virtual void ProcessCLOBValue(FdoCLOBValue& expr) = 0;

    /// \brief
    /// Processes the FdoGeometryValue passed in as an argument.
    /// 
    /// \param expr 
    /// Input geometry value
    /// 
    /// \return
    /// Returns nothing
    /// 
    virtual void ProcessGeometryValue(FdoGeometryValue& expr) = 0;
};
#endif


