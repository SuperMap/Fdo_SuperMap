/** \file	 SuperMapRasterPropertyDictionary.h
*  \author	 马俊
*  \attention 
*  Copyright &copy;  1996-2007 SuperMap GIS Technologies,Inc.<br>
*  All Rights Reserved
*  \version 1.0
*  \date 2008-01-08
*/

#ifndef __SUPERMAP_RASTERPROPERTYDICTIONARY_H__
#define __SUPERMAP_RASTERPROPERTYDICTIONARY_H__
#ifdef _WIN32
#pragma once
#endif // _WIN32

/*! \class SuperMapRasterPropertyDictionary SuperMapRasterPropertyDictionary.h
	\brief 用于处理影像的辅助属性，在调用Raster的GetAuxiliaryProperties时，返回该类的对象
    \既可以获取辅助属性，也可以设置这些属性的值，典型的为获取和设置影像的调色板信息
*/

class SuperMapRasterPropertyDictionary : public FdoIRasterPropertyDictionary
{
public:
	SuperMapRasterPropertyDictionary(UGC::UGDatasetRaster * pDatasetRaster);

public:
	~SuperMapRasterPropertyDictionary(void);
	virtual void Dispose();

public:
	/// <summary>Gets the names of all the properties that apply to this
    /// image as a collection of Strings. The order of the property names
    /// in the collection dictate the order in which they need to
    /// be specified. This is especially important for the success of
    /// the EnumeratePropertyValues method as properties that occur
    /// earlier in the collection may be required for successful enumeration
    /// of properties that appear later in the collection.</summary>
    /// <returns>A collection of the names of properties in this dictionary.</returns>
    virtual FdoStringCollection* GetPropertyNames ();

    /// <summary>Gets the data type for the specified property.</summary>
    /// <param name="name">The name of the property to get the data type of.</param>
    /// <returns>The data type of the property.</returns>
    virtual FdoDataType GetPropertyDataType (FdoString* name);

    /// <summary>Gets the value of the specified property (or its default).</summary>
    /// <param name="name">The name of the property to get the value of.</param>
    /// <returns>The value of the property.</returns>
    virtual FdoDataValue* GetProperty (FdoString* name);

    /// <summary>Sets the value of the specified property.</summary>
    /// <param name="name">The name of the property to set the value of.</param>
    /// <param name="value">The new value for the property.</param>
    virtual void SetProperty (FdoString* name, FdoDataValue* value);

    /// <summary>Gets the default value for the specified property.</summary>
    /// <param name="name">The name of the property to get the default value of.</param>
    /// <returns>The default value of the property.</returns>
    virtual FdoDataValue* GetPropertyDefault (FdoString* name);

    /// <summary>Predicate to determine if the property is required to be set.</summary>
    /// <param name="name">The name of the property to get the required status of.</param>
    /// <returns>Returns true if the specified property is required, false if it is optional.</returns>
    virtual bool IsPropertyRequired (FdoString* name);

    /// <summary>Predicate to determine if the property is enumerable (has more than one value).</summary>
    /// <param name="name">The name of the property to get the enumerable status of.</param>
    /// <returns>Returns true if the possible values for the specified property
    /// can be enumerated via the GetPropertyValues method.</returns>
    virtual bool IsPropertyEnumerable (FdoString* name);

    /// <summary>Access the values of the specified enumerable property.
    /// The property must respond TRUE to IsPropertyEnumerable.</summary>
    /// <param name="name">The name of the property to get the collection of values for.</param>
    /// <returns>A collection of datavaluesfor the enumerable property.</returns>
    virtual FdoDataValueCollection* GetPropertyValues (FdoString* name);

    /// <summary>Set the values of the specified enumerable property.
    /// The property must respond TRUE to IsPropertyEnumerable.
    /// Clients will need to use SetPropertyValues when creating an image
    /// with specific values for the enumerable property.
    /// An example would be setting a table of wavelength ranges corresponding
    /// to the false colour used to encode the image.</summary>
    /// <param name="name">The name of the property to set the collection of values for.</param>
    /// <param name="collection">The collection of values for the enumerable property.</param>
    virtual void SetPropertyValues (FdoString* name, FdoDataValueCollection* collection);


private:
	UGC::UGDatasetRaster *m_pDatasetRaster;		//指向栅格数据集的指针
};

#endif // __SUPERMAP_RASTERPROPERTYDICTIONARY_H__