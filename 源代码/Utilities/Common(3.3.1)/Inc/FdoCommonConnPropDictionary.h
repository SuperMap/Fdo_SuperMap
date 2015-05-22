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
 */

#ifndef FDOCOMMONPROPDICTIONARY_H
#define FDOCOMMONPROPDICTIONARY_H
#ifdef _WIN32
#pragma once
#endif // _WIN32

//TODO: rename this h file and most of these classes to not contain the keyword
// "Connection" since they are now usable for several kinds of
// FdoIPropertyDictionary subclasses.
#include <FdoCommonOSUtil.h>

class ConnectionProperty : public FdoIDisposable
{
protected:
    FdoStringP mName;
    FdoStringP mLocalizedName;
    FdoStringP mDefaultValue;
    FdoStringP mValue;
    bool mIsPropertyRequired;
    bool mIsPropertyProtected;
    bool mIsPropertyEnumerable;
	bool mIsPropertyFileName;
    bool mIsPropertyFilePath;
	bool mIsPropertyDatastoreName;
	bool mIsPropertyQuoted;
    bool mIsSensitiveCase;

    int mCountEnumerableProperties;
    const wchar_t** mEnumerableProperties;
    bool mIsPropertySet;

public:

    /// zero args constructor needed by FdoPtr on linux:
    ConnectionProperty () :
        mName (L""),
        mLocalizedName (L""),
        mDefaultValue (L""),
        mValue (L""),
        mIsPropertyRequired (false),
        mIsPropertyProtected (false),
        mIsPropertyEnumerable (false),
		mIsPropertyFileName(false),
		mIsPropertyFilePath(false),
		mIsPropertyDatastoreName(false),
		mIsPropertyQuoted(false),
        mCountEnumerableProperties (0),
        mEnumerableProperties (NULL),
        mIsPropertySet (false),
        mIsSensitiveCase (true)
    {
    }


    ConnectionProperty (const wchar_t* name, 
                        const wchar_t* localized_name, 
                        const wchar_t* value, 
                        bool isRequired, 
                        bool isProtected, 
                        bool isEnumerable, 
                        bool isFilename, 
                        bool isFilePath, 
                        bool isDatastoreName, 
                        bool isQuoted,
                        int enumCount, 
                        const wchar_t** enumerables) :
        mName (name),
        mLocalizedName (localized_name),
        mDefaultValue (value),
        mValue ((wchar_t*)value),
        mIsPropertyRequired (isRequired),
        mIsPropertyProtected (isProtected),
        mIsPropertyEnumerable (isEnumerable),
        mIsPropertyFileName (isFilename),
        mIsPropertyFilePath (isFilePath),
        mIsPropertyDatastoreName (isDatastoreName),
        mIsPropertyQuoted (isQuoted),
        mCountEnumerableProperties (0),
        mEnumerableProperties (NULL),
        mIsPropertySet (false),
        mIsSensitiveCase (true)
    {
        UpdateEnumerableProperties (enumCount, enumerables);
    }

    ConnectionProperty (const wchar_t* name, 
                        const wchar_t* localized_name, 
                        const wchar_t* value, 
                        bool isRequired, 
                        bool isProtected, 
                        bool isEnumerable, 
                        bool isFilename, 
                        bool isFilePath, 
                        bool isDatastoreName, 
                        bool isQuoted,
                        bool isSensitiveCase,
                        int enumCount, 
                        const wchar_t** enumerables) :
        mName (name),
        mLocalizedName (localized_name),
        mDefaultValue (value),
        mValue ((wchar_t*)value),
        mIsPropertyRequired (isRequired),
        mIsPropertyProtected (isProtected),
        mIsPropertyEnumerable (isEnumerable),
        mIsPropertyFileName (isFilename),
        mIsPropertyFilePath (isFilePath),
        mIsPropertyDatastoreName (isDatastoreName),
        mIsPropertyQuoted (isQuoted),
        mCountEnumerableProperties (0),
        mEnumerableProperties (NULL),
        mIsPropertySet (false),
        mIsSensitiveCase (isSensitiveCase)
    {
        UpdateEnumerableProperties (enumCount, enumerables);
    }

protected:
    ~ConnectionProperty()
    {
        DeleteEnumerableProperties();
    }

    void Dispose()
    {
        delete this;
    };

public:
    const wchar_t* GetName ()
    {
        return (mName);
    }

    const wchar_t* GetLocalizedNamed ()
    {
        return (mLocalizedName);
    }

    const wchar_t* GetDefaultValue ()
    {
        return (mDefaultValue);
    }

    const wchar_t* GetValue ()
    {
        return (mValue);
    }

    void SetValue (const wchar_t* value)
    {
        mValue = value;
        if (mIsPropertyQuoted)
            mValue = mValue.Replace (L"\"", L"");
		if (mValue == L"")
			mIsPropertySet = false;
		else
			mIsPropertySet = true;
    }

    bool GetIsPropertyRequired ()
    {
        return (mIsPropertyRequired);
    }

    void SetIsPropertyRequired (bool required)
    {
        mIsPropertyRequired = required;
    }

    bool GetIsPropertyProtected ()
    {
        return (mIsPropertyProtected);
    }

    bool GetIsPropertyEnumerable ()
    {
        return (mIsPropertyEnumerable);
    }

    bool GetIsPropertyFileName()
    {
        return (mIsPropertyFileName);
    }

    bool GetIsPropertyFilePath()
    {
		return (mIsPropertyFilePath);
    }

    bool GetIsPropertyDatastoreName()
    {
        return (mIsPropertyDatastoreName);
    }

    bool GetIsPropertyQuoted ()
    {
        return (mIsPropertyQuoted);
    }

    void SetIsPropertyQuoted (bool isQuoted)
    {
        mIsPropertyQuoted = isQuoted;
    }

	int GetCountEnumerableProperties ()
    {
        return (mCountEnumerableProperties);
    }

    const wchar_t** GetEnumerableProperties ()
    {
        return (mEnumerableProperties);
    }

    bool GetIsPropertySet ()
    {
        return (mIsPropertySet);
    }

    bool GetIsPropertySensitiveCase ()
    {
        return (mIsSensitiveCase);
    }
    
protected:
    void DeleteEnumerableProperties(void)
    {
        if (mEnumerableProperties != NULL)
        {
            for (int i=0; i<mCountEnumerableProperties; i++)
                delete[] mEnumerableProperties[i];

            delete[] mEnumerableProperties;
        }

        mEnumerableProperties = NULL;
        mCountEnumerableProperties = 0;
    }

public:
    /// The caller allocates newValues but this object takes ownership of it and will deallocate it.
    void UpdateEnumerableProperties(int newCount, const wchar_t** newValues)
    {
    /// Delete old strings:
        DeleteEnumerableProperties();

    /// take ownership of given array of strings:
        mCountEnumerableProperties = newCount;
        mEnumerableProperties = newValues;
    }
};

class ConnectionPropertyCollection : public FdoCollection<ConnectionProperty, FdoException>
{
    //-------------------------------------------------------
    /// FdoIDisposable implementation
    //-------------------------------------------------------

    protected:
    /// dispose this object
        virtual void Dispose()
        {
            delete this;
        }
};

template <class T>
class FdoCommonPropDictionary : public T
{
protected:
    FdoIConnection* mConnection; // weak reference
    FdoPtr<ConnectionPropertyCollection> mProperties;
    wchar_t** mNames;

public:
    /// 0-argument constructor to please FdoPtr::operator->() :
    FdoCommonPropDictionary () { FdoCommonPropDictionary<T>(NULL); }
    FdoCommonPropDictionary (FdoIConnection* connection);

    /// Define a new connection property;
    /// Call this method once per connection property
    /// immediately after creating a new instance of FdoCommonPropDictionary:
    virtual void AddProperty(ConnectionProperty *newConnProp);

protected:
    virtual ~FdoCommonPropDictionary (void);
    virtual void Dispose ();
    void Clear ();
    virtual void validate ();

public:
    /// \brief
    ///  Gets the names of all the properties that can appear in a connection string
    /// for this feature provider as an array of Strings. The order of the property
    /// names in the resulting array dictate the order in which they need to be 
    /// specified. This is especially important for the success of the 
    /// EnumeratePropertyValues method because properties that occur earlier in the array
    /// may be required for successful enumeration of properties that appear later.
    /// 
    /// \param count 
    /// Output the number of parameters
    /// 
    /// \return
    /// Returns the list of parameter names
    /// 
    FdoString** GetPropertyNames (FdoInt32& count);

    /// \brief
    /// Gets the value of the specified property.
    /// 
    /// \param name 
    /// Input the property name.
    /// 
    /// \return
    /// Returns the property value.
    /// 
    FdoString* GetProperty (FdoString* name);

    /// \brief
    /// Sets the value of the specified property. An exception is thrown if the connection is currently open.
    /// 
    /// \param name 
    /// Input the property name
    /// \param value 
    /// Input the property value
    /// 
    /// \return
    /// Returns nothing
    /// 
    void SetProperty (FdoString* name, FdoString* value);

    /// \brief
    /// Gets the default value for the specified property.
    /// 
    /// \param name 
    /// Input the property name
    /// 
    /// \return
    /// Returns the property default value
    /// 
    FdoString* GetPropertyDefault (FdoString* name);

    /// \brief
    /// Determines if the specified property is required.
    /// 
    /// \param name 
    /// Input the property name
    /// 
    /// \return
    /// Returns true if the specified property is required
    /// 
    bool IsPropertyRequired (FdoString* name);
 
    /// \brief
    ///  Indicates if the property is a password or other protected field
    /// that should be kept secure.
    /// 
    /// \param name 
    /// Input the property name.
    /// 
    /// \return
    /// Returns true if the property is a password or other protected field
    /// that should be kept secure.
    /// 
    bool IsPropertyProtected (FdoString* name);
   
    /// \brief
    /// Determines if the possible values for the specified property can be enumerated via the EnumeratePropertyValues method.
    /// 
    /// \param name 
    /// Input the property name
    /// 
    /// \return
    /// Returns true if the possible values for the specified property can be enumerated.
    /// 
    bool IsPropertyEnumerable (FdoString* name);

    /// \brief
    ///  Returns an array of possible values for the specified property.
    /// 
    /// \param name 
    /// Input the property name.
    /// \param count 
    /// Output the number of values.
    /// 
    /// \return
    /// Returns the list of values for this property.
    /// 
    FdoString** EnumeratePropertyValues (FdoString* name, FdoInt32& count);

    /// \brief
    ///  Gets a localized name for the property (for NLS purposes).
    /// 
    /// \param name 
    /// Input the property name.
    /// 
    /// \return
    /// Returns the localized name for the property (for NLS purposes).
    /// 
    FdoString* GetLocalizedName (FdoString* name);

    /// \brief
    /// Determines if the specified property represents a file name.
    /// 
    /// \param name 
    /// Input the property name
    /// 
    /// \return
    /// Returns true if the specified property is a file name
    /// 
	bool IsPropertyFileName(FdoString* name);

    /// \brief
    /// Determines if the specified property represents a path name.
    /// 
    /// \param name 
    /// Input the property name
    /// 
    /// \return
    /// Returns true if the specified property is a path name
    /// 
    bool IsPropertyFilePath(FdoString* name);

    /// \brief
    /// Determines if the specified property represents a datastore name.
    /// 
    /// \param name 
    /// Input the property name
    /// 
    /// \return
    /// Returns true if the specified property is a datastore name
    /// 
	bool IsPropertyDatastoreName(FdoString* name);

	/// \brief
    /// Determines if the specified property is quoted.
    /// 
    /// \param name 
    /// Input the property name
    /// 
    /// \return
    /// Returns true if the specified property is quoted
    /// 
    bool IsPropertyQuoted(FdoString* name);

	/// \brief
    /// Determines if the specified property value is sensitive case.
    /// 
    /// \param name 
    /// Input the property name
    /// 
    /// \return
    /// Returns true if the specified property value is sensitive case
    /// 
    bool IsPropertyValueSensitiveCase(FdoString* name);

public:
    ConnectionProperty* FindProperty (const wchar_t* name);
    bool CheckEnumerable (const wchar_t* value, ConnectionProperty* property);

};


template <class T> 
FdoCommonPropDictionary<T>::FdoCommonPropDictionary (FdoIConnection* connection) :
    mConnection (connection),
    mNames (NULL)
{
    // NOTE: we use a weak reference here to avoid a circular dependancy:
    // FDO_SAFE_ADDREF(connection);

    mProperties = new ConnectionPropertyCollection ();
}


// Define a new connection property;
// Dall this method once per connection property
// immediately after creating a new instance of FdoCommonPropDictionary:
template <class T> 
void FdoCommonPropDictionary<T>::AddProperty(ConnectionProperty *newConnProp)
{
    Clear ();
    mProperties->Add (newConnProp);
}


template <class T> 
FdoCommonPropDictionary<T>::~FdoCommonPropDictionary (void)
{
    Clear ();
}

template <class T> 
void FdoCommonPropDictionary<T>::Dispose()
{
    delete this;
}

template <class T> 
void FdoCommonPropDictionary<T>::Clear ()
{
    if (NULL != mNames)
    {
        int count = mProperties->GetCount ();
        for (int i = 0; i < count; i++)
            delete [] mNames[i];
    }
    delete [] mNames;
    mNames = NULL;
}

template <class T> 
void FdoCommonPropDictionary<T>::validate ()
{
    if (mConnection == NULL)
        throw FdoException::Create (FdoException::NLSGetMessage(FDO_NLSID(FDO_63_CONNECTION_INVALID)));
}

/// <summary> Gets the names of all the properties that can appear in a connection string
/// for this feature provider as an array of Strings. The order of the property
/// names in the resulting array dictate the order in which they need to be 
/// specified. This is especially important for the success of the 
/// EnumeratePropertyValues method because properties that occur earlier in the array
/// may be required for successful enumeration of properties that appear later.</summary>
/// <param name="count">Output the number of parameters</param> 
/// <returns>Returns the list of parameter names</returns> 
template <class T> 
FdoString** FdoCommonPropDictionary<T>::GetPropertyNames (FdoInt32& count)
{
    validate ();
    count = mProperties->GetCount ();
    if (NULL == mNames)
    {
        mNames = new wchar_t*[count];

        for (int i = 0; i < count; i++)
        {
            FdoPtr<ConnectionProperty> property = mProperties->GetItem (i);
            const wchar_t* name = property->GetName ();
            if (NULL != name)
            {
                mNames[i] = new wchar_t[wcslen (name) + 1];
                wcscpy (mNames[i], name);
            }
            else
                mNames[i] = NULL;
        }
    }

    return ((const wchar_t**)mNames);
}

/// <summary>Gets the value of the specified property.</summary>
/// <param name="name">Input the property name.</param> 
/// <returns>Returns the property value.</returns> 
template <class T> 
FdoString* FdoCommonPropDictionary<T>::GetProperty (FdoString* name)
{
    validate ();
    FdoPtr<ConnectionProperty> property = FindProperty (name);
    if (property == NULL)
        throw FdoException::Create (FdoException::NLSGetMessage(FDO_NLSID(FDO_66_CONNECTION_PROPERTY_NOT_FOUND), name));
    return (property->GetValue ());
}

/// <summary>Sets the value of the specified property. An exception is thrown if the connection is currently open.</summary>
/// <param name="name">Input the property name</param> 
/// <param name="value">Input the property value</param> 
/// <returns>Returns nothing</returns> 
template <class T> 
void FdoCommonPropDictionary<T>::SetProperty (FdoString* name, FdoString* value)
{
    validate ();

    // validate input
    FdoPtr<ConnectionProperty> property = FindProperty (name);
    if (property == NULL)
        throw FdoException::Create (FdoException::NLSGetMessage(FDO_NLSID(FDO_66_CONNECTION_PROPERTY_NOT_FOUND), name));
    if (property->GetIsPropertyRequired () && (NULL == value))
        throw FdoException::Create (FdoException::NLSGetMessage(FDO_NLSID(FDO_64_CONNECTION_REQUIRED_PROPERTY_NULL)));

    if (!CheckEnumerable (value, property))
        throw FdoException::Create (FdoException::NLSGetMessage(FDO_NLSID(FDO_65_CONNECTION_ENUM_PROPERTY_WRONG_VALUE), value, name));

    // update the property
    property->SetValue (value);
}

/// <summary>Gets the default value for the specified property.</summary>
/// <param name="name">Input the property name</param> 
/// <returns>Returns the property default value</returns> 
template <class T> 
FdoString* FdoCommonPropDictionary<T>::GetPropertyDefault (FdoString* name)
{
    validate ();
    FdoPtr<ConnectionProperty> property = FindProperty (name);
    if (property == NULL)
        throw FdoException::Create (FdoException::NLSGetMessage(FDO_NLSID(FDO_66_CONNECTION_PROPERTY_NOT_FOUND), name));
    return (property->GetDefaultValue ());
}

/// <summary>Determines if the specified property is required.</summary>
/// <param name="name">Input the property name</param> 
/// <returns>Returns true if the specified property is required</returns> 
template <class T> 
bool FdoCommonPropDictionary<T>::IsPropertyRequired (FdoString* name)
{
    validate ();
    FdoPtr<ConnectionProperty> property = FindProperty (name);
    if (property == NULL)
        throw FdoException::Create (FdoException::NLSGetMessage(FDO_NLSID(FDO_66_CONNECTION_PROPERTY_NOT_FOUND), name));
    return (property->GetIsPropertyRequired ());
}

/// <summary> Indicates if the property is a password or other protected field
/// that should be kept secure.</summary>
/// <param name="name">Input the property name.</param> 
/// <returns>Returns true if the property is a password or other protected field
/// that should be kept secure.</returns> 
template <class T> 
bool FdoCommonPropDictionary<T>::IsPropertyProtected (FdoString* name)
{
    validate ();
    FdoPtr<ConnectionProperty> property = FindProperty (name);
    if (property == NULL)
        throw FdoException::Create (FdoException::NLSGetMessage(FDO_NLSID(FDO_66_CONNECTION_PROPERTY_NOT_FOUND), name));
    return (property->GetIsPropertyProtected ());
}

/// <summary>Determines if the possible values for the specified property can be enumerated via the EnumeratePropertyValues method.</summary>
/// <param name="name">Input the property name</param> 
/// <returns>Returns true if the possible values for the specified property can be enumerated.</returns> 
template <class T> 
bool FdoCommonPropDictionary<T>::IsPropertyEnumerable (FdoString* name)
{
    validate ();
    FdoPtr<ConnectionProperty> property = FindProperty (name);
    if (property == NULL)
        throw FdoException::Create (FdoException::NLSGetMessage(FDO_NLSID(FDO_66_CONNECTION_PROPERTY_NOT_FOUND), name));
    return (property->GetIsPropertyEnumerable ());
}

/// <summary> Gets a localized name for the property (for NLS purposes).</summary>
/// <param name="name">Input the property name.</param> 
/// <returns>Returns the localized name for the property (for NLS purposes).</returns> 
template <class T> 
bool FdoCommonPropDictionary<T>::IsPropertyFileName(FdoString* name)
{
    validate ();
    FdoPtr<ConnectionProperty> property = FindProperty (name);
    if (property == NULL)
        throw FdoException::Create (FdoException::NLSGetMessage(FDO_NLSID(FDO_66_CONNECTION_PROPERTY_NOT_FOUND), name));
    return (property->GetIsPropertyFileName ());
}

/// <summary>Determines if the specified property represents a path name.</summary>
/// <param name="name">Input the property name</param> 
/// <returns>Returns true if the specified property is a path name</returns> 
template <class T> 
bool FdoCommonPropDictionary<T>::IsPropertyFilePath(FdoString* name)
{
    validate ();
    FdoPtr<ConnectionProperty> property = FindProperty (name);
    if (property == NULL)
        throw FdoException::Create (FdoException::NLSGetMessage(FDO_NLSID(FDO_66_CONNECTION_PROPERTY_NOT_FOUND), name));
    return (property->GetIsPropertyFilePath ());
}

/// <summary>Determines if the specified property represents a datastore name.</summary>
/// <param name="name">Input the property name</param> 
/// <returns>Returns true if the specified property is a datastore name</returns> 
template <class T> 
bool FdoCommonPropDictionary<T>::IsPropertyDatastoreName(FdoString* name)
{
    validate ();
    FdoPtr<ConnectionProperty> property = FindProperty (name);
    if (property == NULL)
        throw FdoException::Create (FdoException::NLSGetMessage(FDO_NLSID(FDO_66_CONNECTION_PROPERTY_NOT_FOUND), name));
    return (property->GetIsPropertyDatastoreName ());
}

/// <summary>Determines if the specified property represents a datastore name.</summary>
/// <param name="name">Input the property name</param> 
/// <returns>Returns true if the specified property is a datastore name</returns> 
template <class T> 
bool FdoCommonPropDictionary<T>::IsPropertyQuoted(FdoString* name)
{
	// no need to validate. this method can be called before connect is active
    FdoPtr<ConnectionProperty> property = FindProperty (name);
    if (property == NULL)
        throw FdoException::Create (FdoException::NLSGetMessage(FDO_NLSID(FDO_66_CONNECTION_PROPERTY_NOT_FOUND), name));
    return (property->GetIsPropertyQuoted ());
}

/// <summary> Returns an array of possible values for the specified property.</summary>
/// <param name="name">Input the property name.</param> 
/// <param name="count">Output the number of values.</param> 
/// <returns>Returns the list of values for this property.</returns> 
template <class T> 
FdoString** FdoCommonPropDictionary<T>::EnumeratePropertyValues (FdoString* name, FdoInt32& count)
{
    validate ();
    FdoPtr<ConnectionProperty> property = FindProperty (name);
    if (property == NULL)
        throw FdoException::Create (FdoException::NLSGetMessage(FDO_NLSID(FDO_66_CONNECTION_PROPERTY_NOT_FOUND), name));
    count = property->GetCountEnumerableProperties ();
    return (property->GetEnumerableProperties ());
}

/// <summary> Gets a localized name for the property (for NLS purposes).</summary>
/// <param name="name">Input the property name.</param> 
/// <returns>Returns the localized name for the property (for NLS purposes).</returns> 
template <class T> 
FdoString* FdoCommonPropDictionary<T>::GetLocalizedName (FdoString* name)
{
    validate ();
    FdoPtr<ConnectionProperty> property = FindProperty (name);
    if (property == NULL)
        throw FdoException::Create (FdoException::NLSGetMessage(FDO_NLSID(FDO_66_CONNECTION_PROPERTY_NOT_FOUND), name));
    return (property->GetLocalizedNamed ());
}

// Returns the property with the specified name.
template <class T> 
ConnectionProperty* FdoCommonPropDictionary<T>::FindProperty (const wchar_t* name)
{
	// no need to validate. this method can be called before connect is active
    int count = mProperties->GetCount ();
    for (int i = 0; i < count; i++)
    {
        FdoPtr<ConnectionProperty> property = mProperties->GetItem (i);
        if (0 == FdoCommonOSUtil::wcsnicmp (property->GetName (), name, wcslen(property->GetName ())))
            return (property.Detach ());
    }
    return NULL;
}

/// <summary>Determines if the specified property represents sensitive case value.</summary>
/// <param name="name">Input the property name</param> 
/// <returns>Returns true if the specified property is represents sensitive case value</returns> 
template <class T> 
bool FdoCommonPropDictionary<T>::IsPropertyValueSensitiveCase(FdoString* name)
{
	// no need to validate. this method can be called before connect is active
    FdoPtr<ConnectionProperty> property = FindProperty (name);
    if (property == NULL)
        throw FdoException::Create (FdoException::NLSGetMessage(FDO_NLSID(FDO_66_CONNECTION_PROPERTY_NOT_FOUND), name));
    return (property->GetIsPropertySensitiveCase ());
}

// Returns whether the specified value is in the set of enumerable values.
template <class T> 
bool FdoCommonPropDictionary<T>::CheckEnumerable (const wchar_t* value, ConnectionProperty* property)
{
    const wchar_t** choices;
    int count;
    bool ret;

    ret = false;
    if (!property->GetIsPropertyRequired() && (value == NULL || wcslen(value) == 0))
        return true;

    count = property->GetCountEnumerableProperties ();
    choices = property->GetEnumerableProperties ();
    if (NULL == choices)
        ret = true;
    else
    {
        bool cmpSens = property->GetIsPropertySensitiveCase ();
        for (int i = 0; i < count && !ret; i++)
        {
            if ( !cmpSens )
            {
                if (0 == FdoCommonOSUtil::wcsnicmp (value, choices[i], wcslen (choices[i])))
                    ret = true;
            }
            else
            {
                if (0 == wcscmp (value, choices[i]))
                    ret = true;
            }
        }
    }
    return (ret);
}



// Instanciation of FdoCommonPropDictionary for the interface FdoIDataStorePropertyDictionary:
class FdoCommonDataStorePropDictionary : public FdoCommonPropDictionary<FdoIDataStorePropertyDictionary>
{
public:
    FdoCommonDataStorePropDictionary(FdoIConnection* conn) : FdoCommonPropDictionary<FdoIDataStorePropertyDictionary>(conn) {};
    FdoCommonDataStorePropDictionary() : FdoCommonPropDictionary<FdoIDataStorePropertyDictionary>() {};
};


// Instanciation of FdoCommonPropDictionary for the interface FdoIConnectionPropertyDictionary:
class FdoCommonConnPropDictionary : public FdoCommonPropDictionary<FdoIConnectionPropertyDictionary>
{
public:
    FdoCommonConnPropDictionary(FdoIConnection* conn) : FdoCommonPropDictionary<FdoIConnectionPropertyDictionary>(conn) {};
    FdoCommonConnPropDictionary() : FdoCommonPropDictionary<FdoIConnectionPropertyDictionary>() {};

    /// Syncronizes this dictionary to the given connection string;
    /// Call this method whenever the user updates the connection string directly
    /// (e.g. in FdoIConnection::SetConnectionString()):
    void UpdateFromConnectionString(FdoString *newConnectionString);

    // Define a new connection property;
    // Call this method once per connection property
    // immediately after creating a new instance of FdoCommonPropDictionary:
    virtual void AddProperty(ConnectionProperty *newConnProp);

    /// Sets the value of the specified property. An exception is thrown if the connection is currently open.
    virtual void SetProperty (FdoString* name, FdoString* value);
};


#endif // FDOCOMMONPROPDICTIONARY_H
