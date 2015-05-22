/*
 * Copyright (C) 2004-2006  Autodesk, Inc.
* 
* This library is free software; you can redistribute it and/or
* modify it under the terms of version 2.1 of the GNU Lesser
* General Public License as published by the Free Software Foundation.
* 
* This library is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
* Lesser General Public License for more details.
* 
* You should have received a copy of the GNU Lesser General Public
* License along with this library; if not, write to the Free Software
* Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
  *
 */

#ifndef FDOCOMMONMISCUTIL___H
#define FDOCOMMONMISCUTIL___H	1

#ifdef _WIN32
#pragma once
#endif


// Helper Exception macros
#define VALIDATE_POINTER(ptr)       if (ptr == NULL) throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_60_NULL_POINTER)))
#define VALIDATE_ARGUMENT(ptr)      if (ptr == NULL) throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_61_NULL_ARGUMENT)));
#define VALIDATE_ALLOCATION(ptr)    if (ptr == NULL) throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_1_BADALLOC)));

// Helper macro that determines the number of elements in a statically-sized array
// (this doesn't work for dynamically-sized arrays)
#define ELEMENTS(x) (sizeof(x)/sizeof(x[0]))




// Convert double to integer, with rounding (in the correct direction,
// taking sign into account).
// This is here temporarily.  The proper location is the FdoSpatial
// package's FdoMathUtility component, but it is here to avoid adding
// a dependency late in development.

inline FdoInt64 FdoCommonMiscUtil_DoubleToInt64(double x)
{
    FdoInt64 i = 
        (x >= 0.0) ?
            // round up
            (FdoInt64) (x + 0.5) :  
            // round down for negative value
            (FdoInt64) (x - 0.5);   
    return i;
}


// Platform-independent Min/Max macros
#define FdoCommonMax(a,b)  (((a) > (b)) ? (a) : (b))
#define FdoCommonMin(a,b)  (((a) < (b)) ? (a) : (b))


class FdoCommonMiscUtil
{
public:
    /// \brief
    /// Serialize FdoDataType to FdoString*:
    static FdoString* FdoDataTypeToString (FdoDataType type);

    /// \brief
    /// Serialize FdoPropertyType to FdoString*:
    static FdoString* FdoPropertyTypeToString (FdoPropertyType logicalPropertyType);

    /// \brief
    /// Serialize FdoClassType to FdoString*:
    static FdoString* FdoClassTypeToString (FdoClassType logicalClassType);

    /// \brief
    /// Serialize FdoCommandType to FdoString*:
    static FdoStringP FdoCommandTypeToString (FdoInt32 command);

    /// \brief
    /// Serialize FdoSpatialOperations to FdoString*:
    static FdoStringP FdoSpatialOperationsToString (FdoSpatialOperations op);

    /// \brief
    /// Serialize FdoGeometryType to FdoString*:
    static FdoStringP FdoGeometryTypeToString (FdoGeometryType geomType);


    /// brief
    /// Compares two FdoDateTime instances
    /// return 
    /// Returns the following:
    /// \li \c -1 if d1 less than d2
    /// \li \c 0 if d1==d2
    /// \li \c 1 if d1 greater than d2
    /// \note
    /// If d1 and d2 are different date/time types, they are sorted as follows: datetime before date before time.
    static int CompareDateTimes(FdoDateTime d1, FdoDateTime d2);

    /// brief
    /// Compares two FdoDateTime instances
    /// return 
    /// Returns the following:
    /// \li \c -1 if d1 less than d2
    /// \li \c 0 if d1==d2
    /// \li \c 1 if d1 greater than d2
    /// \note
    /// If d1 and d2 are different date/time types, the date/time comparision is only done if both are set.
    /// For example, if d1 has a date and time value and d2 has only a date value, the comparison is done only on the dates.
    static int CompareDateTimes2(FdoDateTime dt1, FdoDateTime dt2);

    /// \brief
    /// Compares two FdoDataValue instances.
    /// \return
    /// Returns the following:
    /// \li \c -1 if d1 less than d2
    /// \li \c 0 if d1==d2
    /// \li \c 1 if d1 greater than d2
    /// \note
    /// If d1 and d2 are not the same data type, or one or both are null, an exception is thrown.
    static int CompareDataValues(FdoDataValue *d1, FdoDataValue *d2);

    /// \brief
    /// Fetches the property of given name from the given reader, returned as a FdoPropertyValue instance:
    static FdoPropertyValue* GetPropertyValue(FdoString* propName, FdoPropertyType propType, FdoDataType dataType, FdoIReader* reader);

    /// \brief
    ///  Returns the requested item in the given property value collection, or NULL if not found.
    /// 
    static FdoPropertyValue* GetItemNoThrow(FdoPropertyValueCollection *coll, FdoString* name);

    /// \brief
    ///  Handles read-only properties and default values in the given PropertyValue collection.
    /// 
    static void HandleReadOnlyAndDefaultValues(FdoClassDefinition *classDef, FdoPropertyValueCollection *propValues, bool bMakeNullsExplicit = false);

    /// \brief
    ///  Throw a detailed exception stating that the given data value violates the given property's constraint. 
    /// 
    static void ThrowPropertyConstraintException(FdoDataPropertyDefinition* dataProperty, FdoDataValue* dataValue);

    /// \brief
    ///  Returns true if-and-only-if the given geomTypes array contains the given geomType value. 
    /// 
    static bool ContainsGeomType(FdoGeometryType* geomTypes, FdoInt32 geomTypeCount, FdoGeometryType geomType);

    /// \brief
    ///  Creates a new FdoFunctionDefinition based on the given input.
    /// \note
    ///  The first four arguments represent the function's name, description, aggregate flag, and number
    ///  of signatures which must be at least 1.
    ///  The remainder of the arguments consist of a variable list of arguments describing each signature.
    ///  For each signature, the following arguments must be given in this order:
    ///     FdoPropertyType  <-- the property type of the return value of this signature
    ///     FdoDataType      <-- the data type of the return value of this signature (ignored if not a data property)
    ///     int              <-- the number of input arguments of this signature
    ///     [FdoPropertyType, FdoDataType, ...]  <-- a pair of property type and data type for each input argument
    /// 
    static FdoFunctionDefinition* CreateFunctionDefinition(
        FdoString* functionName, FdoString* functionDesc, bool isAggregate, int numSignatures, ...);


    // Returns the type of the expression

    /// \brief
    /// Returns the type of expression
    /// 
    /// \param functions
    /// Input the list of functions
    ///
    /// \param originalClassDef
    /// Input the class definition
    ///
    /// \param propType
    /// Output the property type
    ///
    /// \param dataType
    /// Output the data type
    ///
    /// \return
    /// Returns nothing
    /// 

	static void GetExpressionType(FdoFunctionDefinitionCollection *functionDefinitions, FdoClassDefinition* originalClassDef, FdoExpression *expr, FdoPropertyType &retPropType, FdoDataType &retDataType);

    /// \brief
    /// Check if the data values are equal
    /// 
    /// \param argLeft
    /// Input first value
    ///
    /// \param argRight
    /// Input second value
    ///
    /// \return
    /// Returns true if the data values are equal
    /// 
	static bool IsEqualTo (FdoDataValue* argLeft, FdoDataValue* argRight);

    /// \brief
    /// Check if the first argument is less than the second argument
    /// 
    /// \param argLeft
    /// Input first value
    ///
    /// \param argRight
    /// Input second value
    ///
    /// \return
    /// Returns true if first argument is less than the second argument
    /// 
	static bool IsLessThan (FdoDataValue* argLeft, FdoDataValue* argRight);

    /// \brief
    /// Check if the first argument is greater than the second argument
    /// 
    /// \param argLeft
    /// Input first value
    ///
    /// \param argRight
    /// Input second value
    ///
    /// \return
    /// Returns true if first argument is greater than the second argument
    /// 

    static bool IsGreaterThan (FdoDataValue* argLeft, FdoDataValue* argRight);

};


#endif // FDOCOMMONMISCUTIL___H


