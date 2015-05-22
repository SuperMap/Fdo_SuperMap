#ifndef FDO_STRING_COLLECTION_H
#define FDO_STRING_COLLECTION_H		1
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

#include <Common/Collection.h>

/// \cond DOXYGEN-IGNORE
// An element in a string collection.
// This class is just a wrapper around a string.
class FdoStringElement : public FdoDisposable
{
public:
    /// Create from a string.
	static FdoStringElement* Create( FdoStringP src )
	{
	    return new FdoStringElement(src);
	}

    /// Operator to copy from a "managed" string.
	FdoStringElement& operator=( const FdoStringP& src )
	{
	    mString = src;
        return(*this);
	}

    /// Operator to copy from an "unmanaged" string.
	FdoStringElement& operator=( const FdoString* wString )
	{
	    mString = wString;
        return(*this);
	}

    /// Returns the string that this element represents.
	FdoStringP GetString()
	{
	    return mString;
	}

protected:
    /// Create from a string.
    FdoStringElement() {}
    FdoStringElement( FdoStringP src )
    {
	    mString = src;
    }

    virtual ~FdoStringElement(void)
    {
    }

private:
    FdoStringP mString;
};

typedef FdoPtr<FdoStringElement> FdoStringElementP;
/// \endcond

/// \brief
/// FdoStringCollection is a collection of strings.
class FdoStringCollection : public FdoCollection<FdoStringElement,FdoException>
{
public:
    /// \brief
    /// Constructs a new empty string collection
    /// 
    /// \return
    /// Returns FdoStringCollection
    /// 
	FDO_API_COMMON static FdoStringCollection* Create(void);

    /// \brief
    /// Creates a copy of string collection
    /// 
    /// \param src 
    /// Input the source collection
    /// 
    /// \return
    /// Returns FdoStringCollection
    /// 
	FDO_API_COMMON static FdoStringCollection* Create( const FdoStringCollection& src);

    /// \brief
    /// Creates a copy of string collection
    /// 
    /// \param src 
    /// Input pointer to the source collection
    /// 
    /// \return
    /// Returns FdoStringCollection
    /// 
	FDO_API_COMMON static FdoStringCollection* Create( const FdoStringCollection* src);

    /// \brief
    /// Creates a string collection that is tokenize from a string.
    /// The collection contains an element for each token.
    /// 
    /// \param inString 
    /// Input the string to tokenize.
    /// \param delimiters 
    /// Input list of single character token delimiters.
    /// \param bNullTokens 
    /// true: include zero-length tokens in the collection.
    /// false: exclude zero-length tokens
    /// 
    /// \return
    /// Returns FdoStringCollection
    /// 
	FDO_API_COMMON static FdoStringCollection* Create( const FdoStringP& inString, const FdoString* delimiters, bool bNullTokens = false );

    /// \brief
    /// Gets the string in the collection at the specified index. Throws an invalid argument exception if the index is out of range.
    /// 
    /// \param index 
    /// Input index
    /// 
    /// \return
    /// Returns the string in the collection at the specified index
    /// 
	FDO_API_COMMON FdoString* GetString(int index) const;

    /// \brief
    /// Appends the strings from src to the end of this collection.
    /// 
    /// \param src 
    /// Input the source collection
    /// 
	FDO_API_COMMON void Append( const FdoStringCollection& src);

    /// \brief
    /// Adds a string to the end of this collection.
    /// 
    /// \param src 
    /// Input the source collection
    /// 
	FDO_API_COMMON int Add( FdoStringP src);

    /// \brief
    /// Given a string, returns its position in this collection.
    /// 
    /// \param value 
    /// Input the string to check
    /// \param caseSensitive 
    /// Input if true, do a case-sensitive comparison
    /// of the string and members of this collection. If false, the comparison
    /// is case-insensitive.
    /// 
    /// \return
    /// Returns the string's position. Returns -1 if the string
    /// is not in this collection.
    /// 
    FDO_API_COMMON virtual FdoInt32 IndexOf(FdoStringP value, FdoBoolean caseSensitive = true) const;

    /// \brief
    /// Concatenates the strings in this collection.
    /// 
    /// \param separator 
    /// Input separate each collection string with this separator string.
    /// 
    /// \return
    /// Returns the concatenation if all strings in this collection.
    /// 
    /// Returns a concatenation of all the strings in this collection, 
    /// separated by the given separator.
	FDO_API_COMMON FdoStringP ToString( const FdoString* separator = L", " );

protected:
/// \cond DOXYGEN-IGNORE
	FDO_API_COMMON FdoStringCollection(void);
	FDO_API_COMMON FdoStringCollection( const FdoStringCollection& src);
	FDO_API_COMMON FdoStringCollection( const FdoStringCollection* src);
	FDO_API_COMMON FdoStringCollection( const FdoStringP& inString, const FdoString* delimiters, bool bNullTokens = false );

	FDO_API_COMMON virtual ~FdoStringCollection(void);

/// \endcond
    FDO_API_COMMON virtual void Dispose()
    {
        delete this;
    }

private:
};

//typedef FdoPtr<FdoStringCollection> FdoStringsP;

/// \brief
/// FdoStringsP is a FdoPtr on FdoStringCollection, provided for convenience.
class FdoStringsP : public FdoPtr<FdoStringCollection>
{
public:
    FdoStringsP() {}
    FdoStringsP( const FdoStringsP& src ) 
        : FdoPtr<FdoStringCollection>(src)
    {}

    FdoStringsP( FdoStringCollection* src )
        : FdoPtr<FdoStringCollection>(src)
    {}

    ~FdoStringsP() {}
    /// \brief
    /// Copies a string collection
    /// 
    /// \param src 
    /// Input the source collection
    /// 
    /// \return
    /// Returns the copy FdoStringCollection
    /// 
	FDO_API_COMMON FdoStringCollection* operator=( FdoStringCollection* src ); 

    /// \brief
    /// Concatenates two string collections
    /// 
    /// \param coll2 
    /// Input collection to append to the end of this collection
    /// 
    /// \return
    /// Returns the concatenated FdoStringCollection
    /// 
	FDO_API_COMMON const FdoStringsP operator+( const FdoStringsP coll2 ) const;

    /// \brief
    /// Concatenates a string collection and a string
    /// 
    /// \param str2 
    /// Input stromg to append to the end of this collection
    /// 
    /// \return
    /// Returns the concatenated FdoStringCollection
    /// 
	FDO_API_COMMON const FdoStringsP operator+( const FdoStringP str2 ) const;

    /// \brief
    /// Concatenates two string collections
    /// 
    /// \param coll2 
    /// Input collection to append to the end of this collection
    /// 
    /// \return
    /// Returns the concatenated FdoStringCollection
    /// 
	FDO_API_COMMON FdoStringsP operator+=( FdoStringsP coll2 );

    /// \brief
    /// Concatenates a string collection and a string
    /// 
    /// \param str2 
    /// Input stromg to append to the end of this collection
    /// 
    /// \return
    /// Returns the concatenated FdoStringCollection
    /// 
	FDO_API_COMMON FdoStringsP operator+=( FdoStringP str2 );

};

#endif


