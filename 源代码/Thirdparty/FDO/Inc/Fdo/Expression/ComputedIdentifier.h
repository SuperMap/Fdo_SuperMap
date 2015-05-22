#ifndef _COMPUTEDIDENTIFIER_H_
#define _COMPUTEDIDENTIFIER_H_
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

/// \brief
/// The FdoComputedIdentifier class derives from FdoIdentifier and represents an expression
/// with alias. The name or alias must be a simple name and should not be scoped or contain the
/// the schema name. The FdoComputedIdentifier can be used to provide an alias to an expression. For
/// example the expression Length*NumLanes can be refered to as MaxTraficCapacity. In this case, a 
/// computed identifier can be created as: 
/// \code
/// 	FdoComputedIdentifier::Create(L"MaxTraficCapacity", 
///        FdoBinaryExpression::Create( FdoIdentifier(L"Length"),
///                                     FdoBinaryOperations_Multiply,
///                                     FdoIdentifier(L"NumLanes")
///         );
///		);
/// \endcode
/// \note
/// For clarity, the example omits the release code needed to free the various created objects.
/// 
class FdoComputedIdentifier : public FdoIdentifier
{
/// \cond DOXYGEN-IGNORE
protected:
    /// Constructs a default instance of an identifier.
    FdoComputedIdentifier();

    /// Constructs an instance of a computed identifier using the specified arguments.
    FdoComputedIdentifier(FdoString* name, FdoExpression* expression);

    /// Default destructor for identifier.
    virtual ~FdoComputedIdentifier();

    virtual void Dispose();
/// \endcond

public:
    /// \brief
    /// Constructs a default instance of an identifier.
    /// 
    /// \return
    /// Returns the FdoComputedIdentifier
    /// 
    FDO_API static FdoComputedIdentifier* Create();

    /// \brief
    /// Constructs an instance of an identifier using the specified arguments.
    /// 
    /// \param name 
    /// Input the computed identifier name
    /// \param expression 
    /// Input the fdo expression
    /// 
    /// \return
    /// Returns the FdoComputedIdentifier
    /// 
    FDO_API static FdoComputedIdentifier* Create(FdoString* name, FdoExpression* expression);

    /// \brief
    /// Gets the full text of the identifier.
    /// 
    /// \return
    /// Returns the identifier text
    /// 
    FDO_API FdoExpression* GetExpression();

    /// \brief
    /// Sets the full text of the identifier.
    /// 
    /// \param value 
    /// Input identifier text
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API void SetExpression(FdoExpression* value);

    /// \brief
    /// Overrides FdoExpression.Process to pass the FdoComputedIdentifier to the appropriate
    /// expression processor operation.
    /// 
    /// \param p 
    /// Input expression processor interface
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

    /// \brief
    /// This is an internal method. It returns the well defined text representation of the expression. 
    /// 
    /// \param pIdCol 
    /// A identifier collection that contains all the computed identifier used by the filter
    /// 
    /// \return
    /// Returns the well defined text string
    /// 
    virtual FdoString* ToStringInternal( FdoIdentifierCollection *pIdCol );

private:
    FdoExpression*    m_Expression; 
};
#endif


