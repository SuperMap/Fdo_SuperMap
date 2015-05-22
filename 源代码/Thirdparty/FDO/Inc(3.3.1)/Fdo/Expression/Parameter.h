#ifndef _PARAMETER_H_
#define _PARAMETER_H_
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
#include <Fdo/Expression/ValueExpression.h>

/// \brief
/// The FdoParameter class derives from FdoValueExpression and represents a
/// substitution parameter in the expression. FdoParameters are represented by a
/// name: when expressions are evaluated, the caller must supply a value to be
/// bound to each parameter name.
/// \remarks
/// For information on how to set the value of a parameter, see the 
/// FdoICommand interface and FdoParameterValue.
class FdoParameter : public FdoValueExpression
{
/// \cond DOXYGEN-IGNORE
protected:
    /// Constructs a default instance of a parameter.
    FdoParameter();

    /// Constructs an instance of a parameter using the specified arguments.
    FdoParameter(FdoString* name);

    /// Default destructor for parameter.
    virtual ~FdoParameter();

    virtual void Dispose();
/// \endcond

public:

    /// \brief
    /// Constructs a default instance of a parameter.
    /// 
    /// \return
    /// Returns FdoParameter
    /// 
    FDO_API static FdoParameter* Create();

    /// \brief
    /// Constructs an instance of a parameter using the specified arguments.
    /// 
    /// \param name 
    /// Input parameter name
    /// 
    /// \return
    /// Returns FdoParameter
    /// 
    FDO_API static FdoParameter* Create(FdoString* name);

    /// \brief
    /// Gets the name of the parameter.
    /// 
    /// \return
    /// Returns the parameter name
    /// 
    FDO_API FdoString* GetName();

    /// \brief
    /// Sets the name of the parameter.
    /// 
    /// \param value 
    /// Input parameter name
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API void SetName(FdoString* value);

    /// \brief
    /// Overrides FdoExpression.Process to pass the FdoParameter to the appropriate
    /// expression processor operation.
    /// 
    /// \param p 
    /// Input an FdoIExpressionProcessor
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API void Process(FdoIExpressionProcessor* p);

    /// \brief
    /// Returns the well defined text representation of this expression.
    /// 
    /// \return
    /// Returns the well defined text string
    /// 
    FDO_API FdoString* ToString();

private:
    wchar_t*    m_name;
};
#endif


