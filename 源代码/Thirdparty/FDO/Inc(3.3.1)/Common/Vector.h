#ifndef FDO_VECTOR_H
#define FDO_VECTOR_H		1
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

/// \brief
/// An element in a vector.
/// This class is just a ref-countable wrapper around a double.
class FdoVectorElement : public FdoDisposable
{
public:
    /// \brief
    /// Creates a vector element.
    /// 
    /// \param value 
    /// Input the value to assign the element
    /// 
    /// \return
    /// Returns FdoProviderNameTokens
    /// 
	FDO_API_COMMON static FdoVectorElement* Create( double value )
	{
	    return new FdoVectorElement(value);
	}

    /// \brief
    /// Gets the element value.
    /// 
    /// \return
    /// Returns the value that this element represents.
    /// 
	FDO_API_COMMON double  GetValue()
	{
	    return mValue;
	}

    /// \brief
    /// Sets the element value.
    /// 
    /// \param value 
    /// Input the value to assign the element
    /// 
    FDO_API_COMMON void SetValue( double value ) 
    {
        mValue = value;
    }

    /// \brief
    /// Gets the element value in string format.
    /// 
    /// \return
    /// Returns the value that this element represents.
    /// 
    FDO_API_COMMON FdoStringP GetString();

protected:
/// \cond DOXYGEN-IGNORE
    FdoVectorElement() {}
    FdoVectorElement( double value )
    {
	    mValue = value;
    }

    virtual ~FdoVectorElement(void)
    {
    }
/// \endcond

private:
    double mValue;
};

typedef FdoPtr<FdoVectorElement> FdoVectorElementP;

/// \brief
/// FdoVector is a one-dimensional collection of numbers.
class FdoVector : public FdoCollection<FdoVectorElement,FdoException>
{
public:
    /// \brief
    /// Constructs a new empty vector
    /// 
    /// \return
    /// Returns FdoVector
    /// 
	FDO_API_COMMON static FdoVector* Create(void);

    /// \brief
    /// Creates a copy of a vector
    /// 
    /// \param src 
    /// Input pointer to the source vector
    /// 
    /// \return
    /// Returns FdoVector
    /// 
	FDO_API_COMMON static FdoVector* Create( const FdoVector* src);

    /// \brief
    /// Creates a vector that is tokenize from a string.
    /// The vector contains an element for each token. Non-numberic tokens
    /// become 0.0.
    /// 
    /// \param inString 
    /// Input the string to tokenize.
    /// \param delimiters 
    /// Input list of single character token delimiters.
    /// \param bNullTokens 
    /// true: include zero-length tokens in the vector ( as 0.0 ).
    /// false: exclude zero-length tokens
    /// 
    /// \return
    /// Returns FdoVector
    /// 
	FDO_API_COMMON static FdoVector* Create( const FdoStringP& inString, FdoString* delimiters, bool bNullTokens = false );

    /// \brief
    /// Gets the number in the vector at the specified index. Throws an invalid argument exception if the index is out of range.
    /// 
    /// \param index 
    /// Input index
    /// 
    /// \return
    /// Returns the number in the vector at the specified index
    /// 
	FDO_API_COMMON double GetValue(int index) const;

    /// \brief
    /// Appends the numbers from src to the end of this vector.
    /// 
    /// \param src 
    /// Input the source collection
    /// 
	FDO_API_COMMON void Append( const FdoVector* src);

    /// \brief
    /// Adds a number to the end of this vector.
    /// 
    /// \param value 
    /// Input the source collection
    /// 
	FDO_API_COMMON int Add( double value );

    /// \brief
    /// Concatenates the numbers in this collection.
    /// 
    /// \param separator 
    /// Input separate each collection number with this separator string.
    /// 
    /// \return
    /// Returns the concatenation of all numbers in this vector, 
    /// separated by the given separator..
    /// 
	FDO_API_COMMON FdoStringP ToString( FdoString* separator = L", " );

protected:
/// \cond DOXYGEN-IGNORE
	FdoVector(void);
	FdoVector( const FdoVector* src);
	FdoVector( const FdoStringP& inString, FdoString* delimiters, bool bNullTokens = false );

	virtual ~FdoVector(void);
/// \endcond

    FDO_API_COMMON virtual void Dispose()
    {
        delete this;
    }

private:
};

/// \brief
/// FdoVectorP is a FdoPtr on FdoVector, provided for convenience. It
/// also provides vector arithmetic and comparison operators.
class FdoVectorP : public FdoPtr<FdoVector>
{
public:
    /// \brief
    /// Vector FdoPtr default constructor
    /// 
    /// \return
    /// Returns FdoVectorP
    /// 
    FDO_API_COMMON FdoVectorP() {}

    /// \brief
    /// Vector FdoPtr copy constructor
    /// 
    /// \param src 
    /// Input the source vector as a FdoPtr
    /// 
    /// \return
    /// Returns FdoVectorP
    /// 
    FDO_API_COMMON FdoVectorP( const FdoVectorP& src ) 
        : FdoPtr<FdoVector>(src)
    {}

    /// \brief
    /// Vector FdoPtr copy constructor
    /// 
    /// \param src 
    /// Input the source vector as an object pointer
    /// 
    /// \return
    /// Returns FdoVectorP
    /// 
    FDO_API_COMMON FdoVectorP( FdoVector* src )
        : FdoPtr<FdoVector>(src)
    {}

    /// \brief
    /// Vector FdoPtr destructor
    /// 
    FDO_API_COMMON ~FdoVectorP() {}

    /// \brief
    /// Copies a vector
    /// 
    /// \param src 
    /// Input the source vector
    /// 
    /// \return
    /// Returns a new copy of the input vector
    /// 
	FDO_API_COMMON FdoVector* operator=( FdoVector* src ); 

    /// \brief
    /// Adds two vectors, by adding each individual element. The output vector has
    /// the same length as the longer of the input vectors. If one input
    /// vector is shorter than the other, it is treated as if it 
    /// is padded with zeros.
    /// 
    /// \param vec2 
    /// Input vector to add to this vector
    /// 
    /// \return
    /// Returns the sum of the two input vectors
    /// 
	FDO_API_COMMON const FdoVectorP operator+( const FdoVectorP vec2 ) const;

    /// \brief
    /// Subtracts two vectors, by subtracting each individual element. The output vector has
    /// the same length as the longer of the input vectors. If one input
    /// vector is shorter than the other, it is treated as if it 
    /// is padded with zeros.
    /// 
    /// \param vec2 
    /// Input vector to subtract from this vector
    /// 
    /// \return
    /// Returns the difference of the two input vectors
    /// 
	FDO_API_COMMON const FdoVectorP operator-( const FdoVectorP vec2 ) const;

    /// \brief
    /// Adds a vector, to this vector, by adding each individual element. The output vector has
    /// the same length as the longer of the input vectors. If one input
    /// vector is shorter than the other, it is treated as if it 
    /// is padded with zeros.
    /// 
    /// \param vec2 
    /// Input vector to add to this vector
    /// 
    /// \return
    /// Returns the sum of the two input vectors
    /// 
	FDO_API_COMMON FdoVectorP operator+=( const FdoVectorP vec2 );

    /// \brief
    /// Subtracts a vector, from this vector, by subtracting each individual element. The output vector has
    /// the same length as the longer of the input vectors. If one input
    /// vector is shorter than the other, it is treated as if it 
    /// is padded with zeros.
    /// 
    /// \param vec2 
    /// Input vector to subtract from this vector
    /// 
    /// \return
    /// Returns the difference of the two input vectors
    /// 
	FDO_API_COMMON FdoVectorP operator-=( const FdoVectorP vec2 );

    /// \brief
    /// Compare two vectors for equality. The vectors are equal
    /// if all of their elements are equal. If one vector is shorter than the other
    /// then it is treated as if it were padded with zeros to the length of the
    /// other vector.
    /// 
    /// \param vec2 
    /// Input vector to compare this vector
    /// 
    /// \return
    /// Returns true if the two vectors are identical.
    /// 
	FDO_API_COMMON FdoBoolean operator==( const FdoVectorP vec2 ) const;

    /// \brief
    /// Compare two vectors for difference. The vectors are differnt
    /// if one of their elements is differnt. If one vector is shorter than the other
    /// then it is treated as if it were padded with zeros to the length of the
    /// other vector.
    /// 
    /// \param vec2 
    /// Input vector to compare this vector
    /// 
    /// \return
    /// Returns true if the two vectors are different.
    /// 
	FDO_API_COMMON FdoBoolean operator!=( const FdoVectorP vec2 ) const;

    /// \brief
    /// Checks if this vector is greater than a second vector.
    /// Comparison is done by comparing the first element in each vector.
    /// If they are equal, then the second element is check and so on until
    /// a differing element is found. If one vector is shorter than the other
    /// then it is treated as if it were padded with zeros to the length of the
    /// other vector.
    /// 
    /// \param vec2 
    /// Input vector to compare this vector
    /// 
    /// \return
    /// Returns true if this vector is greater than vec2.
    /// 
	FDO_API_COMMON FdoBoolean operator>( const FdoVectorP vec2 ) const;

    /// \brief
    /// Checks if this vector is greater or equal to a second vector.
    /// Comparison is done by comparing the first element in each vector.
    /// If they are equal, then the second element is check and so on until
    /// a differing element is found. If one vector is shorter than the other
    /// then it is treated as if it were padded with zeros to the length of the
    /// other vector.
    /// 
    /// \param vec2 
    /// Input vector to compare this vector
    /// 
    /// \return
    /// Returns true if this vector is greater or equal vec2.
    /// 
	FDO_API_COMMON FdoBoolean operator>=( const FdoVectorP vec2 ) const;

    /// \brief
    /// Checks if this vector is less than a second vector.
    /// Comparison is done by comparing the first element in each vector.
    /// If they are equal, then the second element is check and so on until
    /// a differing element is found. If one vector is shorter than the other
    /// then it is treated as if it were padded with zeros to the length of the
    /// other vector.
    /// 
    /// \param vec2 
    /// Input vector to compare this vector
    /// 
    /// \return
    /// Returns true if this vector is less than vec2.
    /// 
	FDO_API_COMMON FdoBoolean operator<( const FdoVectorP vec2 ) const;

    /// \brief
    /// Checks if this vector is less than or equal to a second vector.
    /// Comparison is done by comparing the first element in each vector.
    /// If they are equal, then the second element is check and so on until
    /// a differing element is found. If one vector is shorter than the other
    /// then it is treated as if it were padded with zeros to the length of the
    /// other vector.
    /// 
    /// \param vec2 
    /// Input vector to compare this vector
    /// 
    /// \return
    /// Returns true if this vector is less than or equal vec2.
    /// 
	FDO_API_COMMON FdoBoolean operator<=( const FdoVectorP vec2 ) const;

/// \cond DOXYGEN-IGNORE
protected:
    /// General function to do the vector comparisons.
    FdoBoolean Compare( const FdoVectorP vec2, FdoBoolean lt, FdoBoolean eq, FdoBoolean gt ) const;
/// \endcond
};

#endif


