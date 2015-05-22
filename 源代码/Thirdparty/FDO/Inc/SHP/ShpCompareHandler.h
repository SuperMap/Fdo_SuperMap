// 
//  Copyright (C) 2004-2006  Autodesk, Inc.
//  
//  This library is free software; you can redistribute it and/or
//  modify it under the terms of version 2.1 of the GNU Lesser
//  General Public License as published by the Free Software Foundation.
//  
//  This library is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//  Lesser General Public License for more details.
//  
//  You should have received a copy of the GNU Lesser General Public
//  License along with this library; if not, write to the Free Software
//  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA


#ifndef _SHPCOMPAREHANDLER_H
#define _SHPCOMPAREHANDLER_H

#include "stdafx.h"

class ShpCompareHandler: public FdoIDisposable
{
private:
	ShpCompareHandler();

protected:
	virtual ~ShpCompareHandler();

    // dispose this object
	virtual void Dispose() { delete this; }

public:
	/// <summary>The factory function that can be used to create new instance of this class.</summary>
    /// <returns>Returns a new instance of theShpCompareHandler class.</returns> 
	static ShpCompareHandler* Create();

	/// <summary>Compares double values.</summary>
	/// <param name="name">Is the property name.</param> 
	/// <param name="val1">Is the value of the first object.</param> 
	/// <param name="val1">Is the value of the second object.</param> 
    /// <returns>Returns a positive value if val1 is greater than val2, negative if val1 is smaller than val2 or zero if both val1 and val2 are equal.</returns> 
	virtual int Compare( const wchar_t* name, double val1, double val2 );

	/// <summary>Compares float values.</summary>
	/// <param name="name">Is the property name.</param> 
	/// <param name="val1">Is the value of the first object.</param> 
	/// <param name="val1">Is the value of the second object.</param> 
    /// <returns>Returns a positive value if val1 is greater than val2, negative if val1 is smaller than val2 or zero if both val1 and val2 are equal.</returns> 
	virtual int Compare( const wchar_t* name, float val1, float val2 );

	/// <summary>Compares int64 values.</summary>
	/// <param name="name">Is the property name.</param> 
	/// <param name="val1">Is the value of the first object.</param> 
	/// <param name="val1">Is the value of the second object.</param> 
    /// <returns>Returns a positive value if val1 is greater than val2, negative if val1 is smaller than val2 or zero if both val1 and val2 are equal.</returns> 
	virtual int Compare( const wchar_t* name, FdoInt64 val1, FdoInt64 val2 );

	/// <summary>Compares int32 values.</summary>
	/// <param name="name">Is the property name.</param> 
	/// <param name="val1">Is the value of the first object.</param> 
	/// <param name="val1">Is the value of the second object.</param> 
    /// <returns>Returns a positive value if val1 is greater than val2, negative if val1 is smaller than val2 or zero if both val1 and val2 are equal.</returns> 
	virtual int Compare( const wchar_t* name, FdoInt32 val1, FdoInt32 val2 );

	/// <summary>Compares int16 values.</summary>
	/// <param name="name">Is the property name.</param> 
	/// <param name="val1">Is the value of the first object.</param> 
	/// <param name="val1">Is the value of the second object.</param> 
    /// <returns>Returns a positive value if val1 is greater than val2, negative if val1 is smaller than val2 or zero if both val1 and val2 are equal.</returns> 
	virtual int Compare( const wchar_t* name, FdoInt16 val1, FdoInt16 val2 );

	/// <summary>Compares string values.</summary>
	/// <param name="name">Is the property name.</param> 
	/// <param name="val1">Is the value of the first object.</param> 
	/// <param name="val1">Is the value of the second object.</param> 
    /// <returns>Returns a positive value if val1 is greater than val2, negative if val1 is smaller than val2 or zero if both val1 and val2 are equal.</returns> 
	virtual int Compare( const wchar_t* name, const wchar_t* val1, const wchar_t* val2 );

	/// <summary>Compares date time values.</summary>
	/// <param name="name">Is the property name.</param> 
	/// <param name="val1">Is the value of the first object.</param> 
	/// <param name="val1">Is the value of the second object.</param> 
    /// <returns>Returns a positive value if val1 is greater than val2, negative if val1 is smaller than val2 or zero if both val1 and val2 are equal.</returns> 
	virtual int Compare( const wchar_t* name, FdoDateTime val1, FdoDateTime val2 );

	/// <summary>Compares unsigned char values.</summary>
	/// <param name="name">Is the property name.</param> 
	/// <param name="val1">Is the value of the first object.</param> 
	/// <param name="val1">Is the value of the second object.</param> 
    /// <returns>Returns a positive value if val1 is greater than val2, negative if val1 is smaller than val2 or zero if both val1 and val2 are equal.</returns> 
	virtual int Compare( const wchar_t* name, unsigned char val1, unsigned char val2 );

};


#endif


