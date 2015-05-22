#ifndef FDO_STRINGP_H
#define FDO_STRINGP_H		1

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

/// \brief
/// FdoStringP is smart pointer wrapper around strings. 
/// Provides memory management,plus conversion of strings between unicode and utf8
/// and various string manipulation functions
class FdoStringP
{
public:
    /// \brief
    /// Creates an empty string with value L"".
    /// 
	FDO_API_COMMON FdoStringP(void);

    /// \brief
    /// Creates a string from another string pointer.
    /// 
    /// \param oValue 
    /// Source string to set this string from.
    /// 
	FDO_API_COMMON FdoStringP(const FdoStringP& oValue);

    /// \brief
    /// Creates a string from a unicode (FdoString) string
    /// 
    /// \param wValue 
    /// the unicode string
    /// \param bAttach 
    /// true: just point to the given string without copying it to an 
    /// internal buffer. The caller is responsible for ensuring that
    /// the given string is not deleted before this object.
    /// false: copy the given string to an internal buffer
    /// 
	FDO_API_COMMON FdoStringP( FdoString* wValue, FdoBoolean bAttach = false );

    /// \brief
    /// Creates a string from a utf8 string
    /// 
    /// \param sValue 
    /// the utf8 string
    /// 
	FDO_API_COMMON FdoStringP( const char* sValue );

    /// \brief
    /// Destroys this string and releases its contents
    /// 
	FDO_API_COMMON ~FdoStringP(void);

    /// Operators to copy from other strings in various forms

    /// \brief
    /// Copies a string from a string pointer.
    /// 
    /// \param oString 
    /// Source string to copy from.
    /// 
    /// \return
    /// Returns the copied string
    /// 
	FDO_API_COMMON FdoStringP& operator=( const FdoStringP& oString ); 

    /// \brief
    /// Copies a string from a utf8 string.
    /// 
    /// \param sString 
    /// Utf8 string to copy from.
    /// 
    /// \return
    /// Returns the copied string
    /// 
    FDO_API_COMMON FdoStringP& operator=( const char* sString );

    /// \brief
    /// Copies a string from a unicode string.
    /// 
    /// \param wString 
    /// Unicode string to copy from.
    /// 
    /// \return
    /// Returns the copied string
    /// 
	FDO_API_COMMON FdoStringP& operator=( FdoString* wString );

    /// Various operators for concatenating str2 to this.

    /// \brief
    /// Appends a unicode string onto this string.
    /// 
    /// \param str2 
    /// Unicode string to concatenate
    /// 
    /// \return
    /// Returns the concatenation of this string plus str2
    /// 
	FDO_API_COMMON const FdoStringP operator+( FdoString* str2 ) const
	{
        return(FdoStringP::Format( L"%ls%ls", mwString, str2 ? str2 : L"") );
	}

    /// \brief
    /// Appends the contents of another string onto this string.
    /// 
    /// \param str2 
    /// string to concatenate
    /// 
    /// \return
    /// Returns the concatenation of this string plus str2
    /// 
	FDO_API_COMMON const FdoStringP operator+( const FdoStringP str2 ) const
	{
		return( (*this) + (FdoString*) str2 );
	}

    /// \brief
    /// Appends a unicode string onto this string.
    /// 
    /// \param str2 
    /// Unicode string to concatenate
    /// 
    /// \return
    /// Returns the concatenation of this string plus str2
    /// 
	FDO_API_COMMON FdoStringP operator+=( FdoString* str2 )
	{
		(*this) = (*this) + str2;
		return( *this );
	}

    /// \brief
    /// Appends the contents of another string onto this string.
    /// 
    /// \param str2 
    /// string to concatenate
    /// 
    /// \return
    /// Returns the concatenation of this string plus str2
    /// 
	FDO_API_COMMON FdoStringP operator+=( const FdoStringP str2 )
	{
		(*this) = (*this) + (FdoString*) str2;
		return( *this );
	}

    /// Various comparison operators.

    /// \brief
    /// Greater than comparison operator
    /// 
    /// \param str2 
    /// string to compare
    /// 
    /// \return
    /// Returns true if this string is lexically greater than str2
    /// 
	FDO_API_COMMON bool operator>( const FdoStringP str2 ) const
	{
		return( wcscmp( *this, str2 ) > 0 );
	}

    /// \brief
    /// Greater than or equal comparison operator
    /// 
    /// \param str2 
    /// string to compare
    /// 
    /// \return
    /// Returns true if this string is lexically greater or equal to str2
    /// 
	FDO_API_COMMON bool operator>=( const FdoStringP str2 ) const
	{
		return( wcscmp( *this, str2 ) >= 0 );
	}

    /// \brief
    /// Equals comparison operator
    /// 
    /// \param str2 
    /// string to compare
    /// 
    /// \return
    /// Returns true if this string is lexically equal to str2
    /// 
	FDO_API_COMMON bool operator==( const FdoStringP str2 ) const
	{
		return( wcscmp( *this, str2 ) == 0 );
	}

    /// \brief
    /// Equals comparison operator
    /// 
    /// \param str2 
    /// Unicode string to compare
    /// 
    /// \return
    /// Returns true if this string is lexically equal to str2
    /// 
	FDO_API_COMMON bool operator==( const FdoString* str2 ) const
	{
        return( wcscmp( *this, str2 ? str2 : L"" ) == 0 );
	}

    /// \brief
    /// Not Equals comparison operator
    /// 
    /// \param str2 
    /// Unicode string to compare
    /// 
    /// \return
    /// Returns true if this string is not lexically equal to str2
    /// 
	FDO_API_COMMON bool operator!=( const FdoString* str2 ) const
	{
		return( !((*this) == str2) );
	}

    /// \brief
    /// Less than or Equals comparison operator
    /// 
    /// \param str2 
    /// String to compare
    /// 
    /// \return
    /// Returns true if this string is lexically less than or equal to str2
    /// 
	FDO_API_COMMON bool operator<=( const FdoStringP str2 ) const
	{
		return( wcscmp( *this, str2 ) <= 0 );
	}

    /// \brief
    /// Less than  comparison operator
    /// 
    /// \param str2 
    /// String to compare
    /// 
    /// \return
    /// Returns true if this string is lexically less than str2
    /// 
	FDO_API_COMMON bool operator<( const FdoStringP str2 ) const
	{
		return( wcscmp( *this, str2 ) < 0 );
	}

    /// \brief
    /// Case-insensitive string comparison.
    /// 
    /// \param str2 
    /// String to compare.
    /// 
    /// \return
    /// Returns:
    /// <ul>
    ///      <li>-1 if this is less than str2
    ///      <li>0 if this is equal to str2
    ///       <li>1 if this is greater than str2
    /// </ul>
    /// 
    /// 
    FDO_API_COMMON int ICompare( const FdoStringP str2 ) const;


    /// \return
    /// Returns the Unicode version of this string that the caller does not have
    /// to destroy 
    /// 
	FDO_API_COMMON operator FdoString*( ) const;



    /// \return
    /// Returns the UTF8 version of this string that the caller does not have
    /// to destroy 
    /// 
	FDO_API_COMMON operator const char*( ) const;

    /// \return
    /// Returns the length (in wide characters) of the Unicode version of this string
    /// 
	FDO_API_COMMON size_t GetLength() const;

    /// \brief
    /// Gets the characters to the left of the given sub-string.
    /// 
    /// \param delimiter 
    /// The substring.
    /// 
    /// \return
    /// Returns all of the characters
    /// 	to the left of the first occurance of the delimiter string.
    /// 	All of this string is returned if the delimiter is
    /// 	not in this string. An empty string(L"") is returned if the delimiter is
    /// is NULL or L"".
    /// 

    FDO_API_COMMON FdoStringP Left( FdoString* delimiter ) const;

    /// \brief
    /// Gets the characters to the right of the given sub-string.
    /// 
    /// \param delimiter 
    /// The substring.
    /// 
    /// \return
    /// Returns all of the characters
    /// 	to the right of the first occurance of the delimiter string.
    /// 	an empty string(L"") is returned if the delimiter is
    /// 	not in this string. All of this string is returned if the delimiter is 
    /// NULL or L"".
    /// 

	FDO_API_COMMON FdoStringP Right( FdoString* delimiter ) const;

    /// \brief
    /// Extracts a sub-string of this string
    /// 
    /// \param first 
    /// the 0-based position of the first character to return.
    /// Negative values are treated as 0.
    /// \param count 
    /// the number of characters to return.
    /// If negative then all characters up to the end of this string are returned.
    /// \param useUTF8 
    /// true: perform Mid against the UTF8 representation of this string.
    /// false (default): perform it against the Unicode representation.
    /// 
    /// \return
    /// The extracted sub-string
    /// 
	FDO_API_COMMON FdoStringP Mid( size_t first, size_t count, bool useUTF8 = false );

    /// \brief
    /// Replaces sub-strings.
    /// 
    /// \param pOld 
    /// the sub-string to replace
    /// \param pNew 
    /// the string to replace pOld by
    /// 
    /// \return
    /// Returns a copy of this string, with all occurrences of pOld
    /// replaced by pNew. This string itself is not modified
    /// 
	FDO_API_COMMON FdoStringP Replace( FdoString* pOld, FdoString* pNew ) const;

    /// \return
    /// Returns a copy of this string with all characters in upper case.
    /// 
	FDO_API_COMMON FdoStringP Upper() const;

    /// \return
    /// Returns a copy of this string with all characters in lower case.
    /// 
	FDO_API_COMMON FdoStringP Lower() const;

    /// \brief
    /// Checks for a sub-string.
    /// 
    /// \param subString 
    /// the sub-string to check
    /// 
    /// \return
    /// Returns true if this string has at least 1 occurrence of subString
    /// 
	FDO_API_COMMON bool Contains( FdoString* subString ) const;

    /// \return
    /// Returns true if this string represents a number.
    /// 
	FDO_API_COMMON bool IsNumber() const;

    /// \brief
    /// Converts this string to a long integer.
    /// 
    /// \return
    /// Returns the long integer (0 if the string is not numeric).
    /// 
	FDO_API_COMMON long ToLong() const;

    /// \brief
    /// Converts this string to a double precision number.
    /// 
    /// \return
    /// Returns double (0 if the string is not numeric).
    /// 
	FDO_API_COMMON FdoDouble ToDouble() const;

    /// \brief
    /// Converts this string to a boolean.
    /// 
    /// \param defaultValue 
    /// value returned when string is not recognized as boolean
    /// 
    /// \return
    /// Returns true if the string in lower case is "t", "true", "y", "yes", or "1".
    /// Returns false if the string in lower case is "f", "false", "n", "no", or "0".
    /// Otherwise returns defaultValue.
    /// 
	FDO_API_COMMON FdoBoolean ToBoolean(FdoBoolean defaultValue=false ) const;

    /// \brief
    /// Create a formatted string.
    /// 
    /// \param wValue 
    /// the formatting template. Can contain 
    /// "sprintf" style formatting specs.
    /// <param name="...">
    /// substitution parms to format into string.
    /// 	wValue must have one formatting spec per parm.
    /// </param>
    /// 
    /// \return
    /// Returns the formatted string.
    /// 
	FDO_API_COMMON static FdoStringP Format( FdoString* wValue, ... );

    /// \brief
    /// Constant representing a zero-length string.
    /// 
    FDO_API_COMMON static const wchar_t* mEmptyString;

/// \cond DOXYGEN-IGNORE

    /// Utility function for converting from unicode to utf8.
    /// returned value is allocated and must be deleted by caller.
	FDO_API_COMMON static int Utf8FromUnicode(
        const wchar_t   *   Wtext,
		int         in_size,
        char    *       str_out,
        int         out_max_size,
		bool		thrown_exception = true
    );

    /// Utility function for converting from utf8 to unicode.
    /// returned value is allocated and must be deleted by caller.
    FDO_API_COMMON static int Utf8ToUnicode(
        const char  *   str_in,
		int         in_size,
        wchar_t *   Wtext,
        int         out_size,
		bool		thrown_exception = true
    );

    /// Utility function for converting from unicode to utf8.
    /// returned value is allocated and must be deleted by caller.
	FDO_API_COMMON static int Utf8FromUnicode(
        const wchar_t   *   Wtext,
        char    *       str_out,
        int         out_max_size,
		bool		thrown_exception = true
    );

    /// Utility function for converting from utf8 to unicode.
    /// returned value is allocated and must be deleted by caller.
    FDO_API_COMMON static int Utf8ToUnicode(
        const char  *   str_in,
        wchar_t *   Wtext,
        int         out_size,
		bool		thrown_exception = true
    );

    /// Return the length (in Unicode characters) of a UTF8 string
    static int Utf8Len(const char *utf8String);
/// \endcond

private:
    /// structure used to convert between Unicode and UTF8
    typedef struct
    {
    int     cmask;
    int     cval;
    int     shift;
    long    lmask;
    long    lval;
    } Tab;

    /// General functions to set this object's string value.
	void SetString(const FdoStringP& oValue);
	void SetString(FdoString* wValue, FdoBoolean bAttach = false);
	void SetString(const char* sValue);

	void SetSingle() const;

    /// Caller is responsible for deleting the returned string
	wchar_t* _copyAsWChar( ) const;
	char* _copyAsChar( ) const;

    /// Refcount functions. Refcount is the number of 
    /// FdoStringP objects that point to a particular
    /// string buffer.
	void AddRef();
	void Release();
	
    /// String buffer 

    /// unicode string
	wchar_t* mwString;
    /// utf8 string
	char* msString;
    /// associated ref counter.
	long* mRefCount;

    /// table for converting between UTF8 and Unicode.
    static Tab tab[];
};

#endif


