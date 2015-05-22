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
#ifndef SDFCOMPAREHANDLER_H
#define SDFCOMPAREHANDLER_H

#ifdef _WIN32
    #ifdef SDF_EXPORTS
        #define SDF_API __declspec(dllexport)
        #else
        #define SDF_API __declspec(dllimport)
    #endif
#else 
#define SDF_API
#endif

class SdfCompareHandler: public FdoIDisposable
{
private:
	SDF_API SdfCompareHandler();

protected:
	SDF_API virtual ~SdfCompareHandler();

    // dispose this object
	SDF_API virtual void Dispose() { delete this; }

public:
	/// \brief
	/// The factory function that can be used to create new instance of this class.
	///
    /// \return
	 /// Returns a new instance of theSdfCompareHandler class.
	SDF_API static SdfCompareHandler* Create();

	/// \brief
	/// Compares double values.
	///
	/// \param name
	/// Is the property name.</param>
	//
	/// \param val1
	/// Is the value of the first object.
	/// \param val2
	/// Is the value of the second object.
	///
	/// \return
    /// Returns a positive value if val1 is greater than val2, negative if val1 is smaller than val2 or zero if both val1 and val2 are equal.
	SDF_API virtual int Compare( const wchar_t* name, double val1, double val2 );

	/// \brief
	/// Compares float values.
	///
	/// \param name
	/// Is the property name.</param>
	//
	/// \param val1
	/// Is the value of the first object.
	/// \param val2
	/// Is the value of the second object.
	///
	/// \return
    /// Returns a positive value if val1 is greater than val2, negative if val1 is smaller than val2 or zero if both val1 and val2 are equal.
	SDF_API virtual int Compare( const wchar_t* name, float val1, float val2 );

	/// \brief
	/// Compares int64 values.
	///
	/// \param name
	/// Is the property name.</param>
	//
	/// \param val1
	/// Is the value of the first object.
	/// \param val2
	/// Is the value of the second object.
	///
	/// \return
    /// Returns a positive value if val1 is greater than val2, negative if val1 is smaller than val2 or zero if both val1 and val2 are equal.
	SDF_API virtual int Compare( const wchar_t* name, FdoInt64 val1, FdoInt64 val2 );

	/// \brief
	/// Compares int32 values.
	///
	/// \param name
	/// Is the property name.</param>
	//
	/// \param val1
	/// Is the value of the first object.
	/// \param val2
	/// Is the value of the second object.
	///
	/// \return
    /// Returns a positive value if val1 is greater than val2, negative if val1 is smaller than val2 or zero if both val1 and val2 are equal.
	SDF_API virtual int Compare( const wchar_t* name, FdoInt32 val1, FdoInt32 val2 );

	/// \brief
	/// Compares int16 values.
	///
	/// \param name
	/// Is the property name.</param>
	//
	/// \param val1
	/// Is the value of the first object.
	/// \param val2
	/// Is the value of the second object.
	///
	/// \return
    /// Returns a positive value if val1 is greater than val2, negative if val1 is smaller than val2 or zero if both val1 and val2 are equal.
	SDF_API virtual int Compare( const wchar_t* name, FdoInt16 val1, FdoInt16 val2 );

	/// \brief
	/// Compares string values.
	///
	/// \param name
	/// Is the property name.</param>
	//
	/// \param val1
	/// Is the value of the first object.
	/// \param val2
	/// Is the value of the second object.
	///
	/// \return
    /// Returns a positive value if val1 is greater than val2, negative if val1 is smaller than val2 or zero if both val1 and val2 are equal.
	SDF_API virtual int Compare( const wchar_t* name, const wchar_t* val1, const wchar_t* val2 );

	/// \brief
	/// Compares date time values.
	///
	/// \param name
	/// Is the property name.</param>
	//
	/// \param val1
	/// Is the value of the first object.
	/// \param val2
	/// Is the value of the second object.
	///
	/// \return
    /// Returns a positive value if val1 is greater than val2, negative if val1 is smaller than val2 or zero if both val1 and val2 are equal.
	SDF_API virtual int Compare( const wchar_t* name, FdoDateTime val1, FdoDateTime val2 );

	/// \brief
	/// Compares unsigned char values.
	///
	/// \param name
	/// Is the property name.</param>
	//
	/// \param val1
	/// Is the value of the first object.
	/// \param val2
	/// Is the value of the second object.
	///
	/// \return
    /// Returns a positive value if val1 is greater than val2, negative if val1 is smaller than val2 or zero if both val1 and val2 are equal.
	SDF_API virtual int Compare( const wchar_t* name, unsigned char val1, unsigned char val2 );

};


#endif


