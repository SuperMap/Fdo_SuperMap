#ifndef _PROPERTYVALUECONSTRAINTRANGE_H_
#define _PROPERTYVALUECONSTRAINTRANGE_H_

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
#include <Fdo/Schema/PropertyValueConstraint.h>
#include <Fdo/Expression/DataValue.h>

/// \brief
/// FdoPropertyValueConstraintRange is used to specify minimum and / or maximum allowed values for a particular property. 
/// It can be used for all data property types except for Boolean, BLOB, or CLOB.
/// One or the other or both of MinValue and MaxValue must be specified. If both are specified, then MaxValue must be greater 
/// than or equal to MinValue and if either MinInclusive or MaxInclusive are false, then MaxValue must be greater than MinValue. 
/// MinValue and MaxValue if specified must be valid values for the property type. E.g. if the property is decimal(4,0), 
/// then the maximum possible MaxValue is 9999.
/// If the data property definition includes a non-null default value, then this constraint is applied to that value as well.
/// If the data property definition allows nulls, a null value is considered as being valid regardless of the range constraint.
class FdoPropertyValueConstraintRange : public FdoPropertyValueConstraint
{
protected:
    /// Constructs a default instance of a FdoPropertyValueConstraintRange.
    FdoPropertyValueConstraintRange();

    /// Constructs an instance of a FdoPropertyValueConstraintRange using the specified
    /// arguments.
    FdoPropertyValueConstraintRange(FdoDataValue  *minValue, FdoDataValue* maxValue);

    virtual ~FdoPropertyValueConstraintRange();

	virtual void Dispose()
    {
        delete this;
    }
public:
    
    /// \brief
    /// Constructs an empty instance of an FdoPropertyValueConstraintRange.
    /// 
    /// \return
    /// Returns an FdoPropertyValueConstraintRange
    /// 
    FDO_API static FdoPropertyValueConstraintRange* Create( );

    /// \brief
    /// Constructs and populates an instance of an FdoPropertyValueConstraintRange.
    /// 
    /// \param minValue 
    /// Minimum allowed value
    /// \param maxValue 
    /// Maximum allowed value
    /// 
    /// \return
    /// Returns an FdoPropertyValueConstraintRange
    /// 
    FDO_API static FdoPropertyValueConstraintRange* Create( FdoDataValue  *minValue, FdoDataValue* maxValue );

    /// \brief
    /// Returns FdoPropertyValueConstraintType_Range type.
    /// 
    /// \return
    /// Returns the constraint type
    /// 
    FDO_API virtual FdoPropertyValueConstraintType GetConstraintType();

    /// \brief
    /// Get the minimum allowed value. The type of this is the same as the type of the property. 
    /// E.g. if the property is int32, then this value is int32.
    /// 
    /// \return
    /// Returns the minimum value
    /// 
	FDO_API FdoDataValue* GetMinValue();

    /// \brief
    /// Set the minimum allowed value.
    /// 
    /// \param value 
    /// Minimum allowed value
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API void SetMinValue(FdoDataValue* value);

    /// \brief
    /// Returns a bool to indicate if the minimum value is inclusive or exclusive. This is the difference between >= and >. 
    /// This is a boolean type where true means inclusive.
    /// 
    /// \return
    /// Returns true if the value is inclusive. false otherwise
    /// 
    FDO_API bool GetMinInclusive();

    /// \brief
    /// Set the minimum value to inclusive or exclusive. This is the difference between >= and >. 
    /// 
    /// \param value 
    /// This is a boolean type where true means inclusive.
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API void SetMinInclusive(bool value);

    /// \brief
    /// Get the maximum allowed value. The type of this is the same as the type of the property. 
    /// E.g. if the property is int32, then this value is int32.
    /// 
    /// \return
    /// Returns the maximum value
    /// 
    FDO_API FdoDataValue* GetMaxValue();

    /// \brief
    /// Set the maximum allowed value.
    /// 
    /// \param value 
    /// Maximum allowed value
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API void SetMaxValue(FdoDataValue* value);

    /// \brief
    /// Returns a bool to indicate if the maximum value is inclusive or exclusive. This is the difference between <= and <. 
    /// This is a boolean type where true means inclusive.
    /// 
    /// \return
    /// Returns true if the value is inclusive. false otherwise
    /// 
    FDO_API bool GetMaxInclusive();

    /// \brief
    /// Returns a bool to indicate if the maximum value is inclusive or exclusive. This is the difference between <= and <. 
    /// This is a boolean type where true means inclusive.
    /// 
    /// \return
    /// Returns true if the value is inclusive. false otherwise
    /// 
    FDO_API void SetMaxInclusive(bool value);

/// \cond DOXYGEN-IGNORE
    // Public non-API functions for XML and Schema Merge support

    /// Update this range constraint from the given value constraint.
    virtual void Set( FdoPropertyValueConstraint* pProperty, FdoString* parentName, FdoSchemaMergeContext* pContext );

    // \brief
    // Compares this range constraint with another one.
    // 
    // \param value 
    // The Property Value constraint to compare with
    // 
    // \return
    // Returns true if this range constraint is the same as pConstraint
    // (same constraint type and all members have the same values).
    virtual bool Equals( FdoPropertyValueConstraint* pConstraint );

    // \brief
    // Checks if a constraint domain is contained within another
    // 
    // \param value 
    // The Property Value constraint to compare with
    // 
    // \return
    // Returns true if this constraint's domain is a superset of the domain
    // for pConstraint (all values that do not violate pConstraint also do not
    // violate this constraint).
    virtual bool Contains( FdoPropertyValueConstraint* pConstraint );

    // \brief
    // Checks if the given value violates this constraint.
    // 
    // \param value 
    // The Property Value
    // 
    // \return
    // Returns true if the value is null or is within this constraint's value range.
    // Returns false if the value does violate this constraint.
    virtual bool Contains( FdoDataValue* pValue );

private:
    // \brief
    // Compares two data values
    // 
    // \param myValue 
    // The first property value
    // 
    // \param theirValue 
    // The second property value
    //
    // \return
    // Returns true if the values are equal or both null.
    bool ValueEquals( FdoPtr<FdoDataValue> myValue, FdoPtr<FdoDataValue> theirValue );

    // \brief
    // Converts data value to string, handling memory cleanup and null values.
    //
    // \param value 
    // The data value
    //
    // \return
    // Returns the data value as a string. L"" if the value is null.
    FdoStringP ValueToString( FdoPtr<FdoDataValue> value );

    // Same as CompareEnd expect that some extra checks are done for 
    // date ranges. If any of the component nullities of the values to 
    // compare are different, then FdoCompareType_Undefined is returned.
    // For example, if one values is a DateTime but the other is a Time
    // then Undefined is returned. This causes Contains( FdoPropertyValueConstraint*)
    // to always return false if the component nullities of the range
    // endpoints differ.
    FdoCompareType CompareRangeEnd( FdoBoolean myInclusive, FdoPtr<FdoDataValue> myValue, FdoBoolean theirInclusive, FdoPtr<FdoDataValue> theirValue, FdoBoolean isMax );

    // \brief
    // Compares the ends of two range constraints.
    // 
    // \param myInclusive 
    // First constraint's inclusivity setting. When the first and second values are equal, the 
    // inclusive settings are then checked:
    //    When isMax is true, inclusive values are greater than exclusive values
    //    When isMax is false, inclusive values are less than exclusive values
    // There is currently a limitation in that, for integral types, inclusive values are not checked
    // when the values differ by 1. Therefore, values are sometimes reported as not equal when 
    // they are equal.
    // 
    // \param myValue 
    // Value from the first constraint
    // 
    // \param myInclusive 
    // Second constraint's inclusivity setting
    //
    // \param theirValue 
    // Value from the second constraint
    //
    // \param isMax
    // Determines how null and not null values are compared:
    //   true: values are maximum end of ranges. NULL values are considered to be greater than not null values.
    //   false: they are the minimum ends. NULL values are considered to be less than not null values.
    //
    // \return
    // Returns:
    //     FdoCompareType_Equal when first and second values are equal
    //     FdoCompareType_Greater when the first value is greater than the second value
    //     FdoCompareType_Less when the first value is less than the second value
    //     FdoCompareType_Undefined when these two values have incompatible types.

    FdoCompareType CompareEnd( FdoBoolean myInclusive, FdoPtr<FdoDataValue> myValue, FdoBoolean theirInclusive, FdoPtr<FdoDataValue> theirValue, FdoBoolean isMax );
    
    FdoDataValue*	m_minValue;
	FdoDataValue*	m_maxValue;
	bool			m_isMinInclusive;
	bool			m_isMaxInclusive;
/// \endcond
};

#endif


