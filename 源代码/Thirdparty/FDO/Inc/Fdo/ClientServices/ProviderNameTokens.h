#ifndef _FDOPROVIDERNAMETOKENS_H_
#define _FDOPROVIDERNAMETOKENS_H_
/***************************************************************************

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


 ***************************************************************************/
#ifdef _WIN32
#pragma once
#endif

// Include definitions
#include <FdoStd.h>
#include <FdoCommon.h>
#include <Common/Vector.h>
#include <Fdo/ClientServices/ClientServices.h>

/// \brief
/// A provider name tokenized into its company, name and version parts.
class FdoProviderNameTokens : public FdoIDisposable
{
public:
    /// \brief
    /// Tokenize a full provider name
    /// The name is usually of the form "[Company].[Provider].[Version]",
    /// e.g. "Autodesk.Oracle.3.2".
    /// 
    /// \param name 
    /// Input the provider name to tokenize
    /// 
    /// \return
    /// Returns FdoProviderNameTokens
    /// 
    FDO_API static FdoProviderNameTokens* Create(FdoString* name);

    /// \brief
    /// Gets all of the tokens in this provider name
    /// 
    /// \return
    /// Returns the collection of tokens. 
    ///   Element 0 is the company
    ///   Element 1 is the unqualified name
    ///   the rest of the elements are the individual parts of the version number.
    /// 
    FDO_API  FdoStringsP GetNameTokens() const;

    /// \brief
    /// Gets all of the version number components in this provider name
    /// 
    /// \return
    /// Returns the collection of version number components. For
    /// example, if the full provider name is "Autodesk.Oracle.3.1" then 
    /// {3,1} is returned.
    /// 
    FDO_API  FdoVectorP GetVersionTokens() const;

    /// \brief
    /// Gets the local (unqualified) name of this provider.
    /// 
    /// \return
    /// Returns the local name ( without company and version ). For
    /// example, if the full provider name is "Autodesk.Oracle.3.1" then 
    /// "Oracle" is returned.
    /// 
    FDO_API  FdoStringP GetLocalName() const;

/// \cond DOXYGEN-IGNORE
protected:
    FdoProviderNameTokens() {}
    FdoProviderNameTokens(FdoString* name);

    /// Default destructor for FdoProvider.
    virtual ~FdoProviderNameTokens() {}

    virtual void Dispose();
/// \endcond

private:
    FdoStringsP mNameTokens;
    FdoStringsP mVersionTokens;
};

/// \brief
/// FdoProviderNameTokensP is a FdoPtr on FdoProviderNameTokens, provided for convenience.
/// It also provides operators for comparing two provider names.
class FdoProviderNameTokensP : public FdoPtr<FdoProviderNameTokens>
{
public:
    /// \brief
    /// Tokenized provider name FdoPtr default constructor
    /// 
    /// \return
    /// Returns FdoProviderNameTokensP
    /// 
    FDO_API FdoProviderNameTokensP() {}

    /// \brief
    /// Tokenized provider name FdoPtr copy constructor
    /// 
    /// \param src 
    /// Input the source tokenized provider name as a FdoPtr
    /// 
    /// \return
    /// Returns FdoProviderNameTokensP
    /// 
    FDO_API FdoProviderNameTokensP( const FdoProviderNameTokensP& src ) 
        : FdoPtr<FdoProviderNameTokens>(src)
    {}

    /// \brief
    /// Tokenized provider name FdoPtr copy constructor
    /// 
    /// \param src 
    /// Input the source tokenized provider name as an object pointer
    /// 
    /// \return
    /// Returns FdoProviderNameTokensP
    /// 
    FDO_API FdoProviderNameTokensP( FdoProviderNameTokens* src )
        : FdoPtr<FdoProviderNameTokens>(src)
    {}

    /// \brief
    /// Tokenized provider name FdoPtr destructor
    /// 
    FDO_API ~FdoProviderNameTokensP() {}
 
    /// \brief
    /// Copies a tokenized provider name
    /// 
    /// \param src 
    /// Input the source collection
    /// 
    /// \return
    /// Returns the copy FdoProviderNameTokens
    /// 
	FDO_API FdoProviderNameTokens* operator=( FdoProviderNameTokens* src ); 

    /// \brief
    /// Compare two tokenized provider names for equality. The names are equal
    /// if all of their elements are equal. If one name is shorter than the other
    /// then it is treated as if it were padded with null elements to the length of the
    /// other name.
    /// 
    /// \param name2 
    /// Input provider name to compare this name
    /// 
    /// \return
    /// Returns true if the two names are identical.
    /// 
	FDO_API FdoBoolean operator==( const FdoProviderNameTokensP name2 ) const;

    /// \brief
    /// Compare two tokenized provider names for difference The names are different
    /// if at least one of their elements are different. If one name is shorter than the other
    /// then it is treated as if it were padded with null elements to the length of the
    /// other name.
    /// 
    /// \param name2 
    /// Input provider name to compare this name
    /// 
    /// \return
    /// Returns true if the two names are identical.
    /// 
	FDO_API FdoBoolean operator!=( const FdoProviderNameTokensP name2 ) const;

    /// \brief
    /// Checks if this provider name is greater than another provider name.
    /// This provider name is greater only if the company and name are the same, but
    /// this provider's version is later than that of name2. Therefore, it is 
    /// possible for a provider name to be neither greater than, equal or less than
    /// another provider name.
    /// 
    /// \param name2 
    /// The other provider name
    /// 
    /// \return
    /// Returns true if this provider name is greater than name2.
    /// 
	FDO_API FdoBoolean operator>( const FdoProviderNameTokensP name2 ) const;

    /// \brief
    /// Checks if this provider name is greater than or equal to another provider name.
    /// This provider name is greater only if the company and name are the same, but
    /// this provider's version is later than that of name2. Therefore, it is 
    /// possible for a provider name to be neither greater than, equal or less than
    /// another provider name.
    /// 
    /// \param name2 
    /// The other provider name
    /// 
    /// \return
    /// Returns true if this provider name is greater than or equal to name2.
    /// 
	FDO_API FdoBoolean operator>=( const FdoProviderNameTokensP name2 ) const;

    /// \brief
    /// Checks if this provider name is less than another provider name.
    /// This provider name is less than the other name only if the company and name are 
    /// the same, but
    /// this provider's version is earlier than that of name2. Therefore, it is 
    /// possible for a provider name to be neither greater than, equal or less than
    /// another provider name.
    /// 
    /// \param name2 
    /// The other provider name
    /// 
    /// \return
    /// Returns true if this provider name is less than name2.
    /// 
	FDO_API FdoBoolean operator<( const FdoProviderNameTokensP name2 ) const;

    /// \brief
    /// Checks if this provider name is less than or equal to another provider name.
    /// This provider name is less than the other name only if the company and name are 
    /// the same, but
    /// this provider's version is earlier than that of name2. Therefore, it is 
    /// possible for a provider name to be neither greater than, equal or less than
    /// another provider name.
    /// 
    /// \param name2 
    /// The other provider name
    /// 
    /// \return
    /// Returns true if this provider name is less than or equal to name2.
    /// 
	FDO_API FdoBoolean operator<=( const FdoProviderNameTokensP name2 ) const;

/// \cond DOXYGEN-IGNORE
protected:
    FdoBoolean Compare( const FdoProviderNameTokensP name2 ) const;
/// \endcond

};
#endif


