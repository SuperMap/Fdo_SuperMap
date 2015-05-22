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
//  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  US

#ifndef _ShpIScrollableFeatureReader_
#define _ShpIScrollableFeatureReader_

#include "Fdo.h"

class ShpIScrollableFeatureReader : public FdoIFeatureReader
{
public:

	/// <summary>Returns the number of records of the query result.</summary>
    /// <returns>Returns number of records.</returns> 
	virtual int Count() = 0;
	
	/// <summary>Position the reader at the first record of the query result. This method returns false if the query result is empty.</summary>
    /// <returns>Returns true if a record is found or false if the result is empty.</returns>
	virtual bool ReadFirst() = 0;

	/// <summary>Position the reader at the last record of the query result. This method returns false if the query result is empty.</summary>
    /// <returns>Returns true if a record is found or false if the result is empty.</returns>
	virtual bool ReadLast() = 0;

	/// <summary>Advances the reader to the previous item and returns true if there is
    /// another object to read or false if reading is complete.  The default
    /// position of the reader is prior to the first item.  Therefore you
    /// must call ReadFirst or ReadLast to begin accessing any data.</summary>
	/// <returns>Returns true if a record is found or false otherwise.</returns>
    virtual bool ReadPrevious() = 0;

	/// <summary>provide the ad-hoc access to the query result. It positions the position of the reader at a given record 
	/// defined by the key. If the record is not found, then the reader position is unset and false value is returned. 
	/// Once the reader’s position becames unset, the caller needs to call ReadFirst, ReadLast or ReadAt to re-position 
	/// the reader at a valid location.</returns>
	/// <param name="key">The key that identifies a record.</param> 
	/// <returns>Returns true if a record is found or false otherwise.</returns>
	virtual bool ReadAt(FdoPropertyValueCollection* key) = 0;

	/// <summary>Provides an ad-hoc access to the query result. The recordindex is the one-based nth item in the query result. 
	/// If successful, this method will position the reader at the feature identified by the recordindex.</summary>
	/// <param name="recordindex">The index of the row.</param> 
	/// <returns>Returns true if a record is found or false otherwise.</returns>
	virtual bool  ReadAtIndex( unsigned int recordindex ) = 0;

	/// <summary>Given a key of a feature, IndexOf will return the one based index or the record number of the feature within 
	/// the returned query result. If the record is not found, then zero is retuned. This is the mirror function of the GetAtIndex function. This method does not affect the reader position. 
	///  GetAtIndex need to be called to move the reader to the returned index.</summary>
	/// <param name="key">The key that identifies a record.</param> 
	/// <returns>Returns true if a record is found or false otherwise.</returns>
	virtual unsigned int IndexOf(FdoPropertyValueCollection* key) = 0;
};

#endif
