/** \file	 SuperMapConnectionInfo.h
 *  \author	 ºÂÓñ½­
 *  \attention 
 *  Copyright &copy;  1996-2007 SuperMap GIS Technologies,Inc.<br>
 *  All Rights Reserved
 *  \version 1.0
 *  \date 2007-09-19
 *  \note : modified by zhouxu 2007-10-23
 */

#ifndef __SUPERMAPCONNECTIONINFO_H__
#define __SUPERMAPCONNECTIONINFO_H__
#ifdef _WIN32
#pragma once
#endif // _WIN32


class SuperMapConnectionInfo:public FdoIConnectionInfo
{
    friend class SuperMapConnection;
public:
    SuperMapConnectionInfo ()  { SuperMapConnectionInfo(NULL); }  // 0-argument constructor to please FdoPtr::operator->
    SuperMapConnectionInfo (SuperMapConnection* connection);

protected:
    virtual ~SuperMapConnectionInfo (void);
    virtual void Dispose ();
    virtual void validate ();

public:
    /// <summary>Gets the name of the feature provider.</summary>
    /// <returns>Returns the provider name</returns>
    FdoString* GetProviderName ();

    /// <summary>Gets the display name of the feature provider.</summary>
    /// <returns>Returns the provider's display name</returns>
    FdoString* GetProviderDisplayName();

    /// <summary>Gets the description of the feature provider.</summary>
    /// <returns>Returns the provider description</returns>
    FdoString* GetProviderDescription ();

    /// <summary>Gets the version of the feature provider.</summary>
    /// <returns>Returns provider version</returns>
    FdoString* GetProviderVersion ();

    /// <summary>Gets the version of the Feature Data Objects specification to which this provider conforms.</summary>
    /// <returns>Returns FDO version supported.</returns>
    FdoString* GetFeatureDataObjectsVersion ();

    /// <summary>Gets the FdoIConnectionPropertyDictionary interface that can be used to dynamically query and set the properties required to establish a connection.</summary>
    /// <returns>Returns the property dictionary</returns>
    FdoIConnectionPropertyDictionary* GetConnectionProperties ();

    /// <summary>Returns the provider type. A provider can be a file-based, database-based or
    /// web-based provider. The valid values the function may return are defined in
    /// the enumeration FdoProviderDatastoreType. The enumeration includes the following
    /// values: FdoProviderDatastoreType_Unknown, FdoProviderDatastoreType_File,
    /// FdoProviderDatastoreType_DatabaseServer, FdoProviderDatastoreType_WebServer.</summary>
    /// <returns>Returns the provider data store type.</returns>
    FdoProviderDatastoreType GetProviderDatastoreType();

    /// <summary>File-based providers depend on a various files. This function returns a list
    /// of fully qualified dependend file names. The return parameter will be NULL if
    /// the provider is not a file-based provider.</summary>
    /// <returns>Returns the list of fully-qualified dependend file names if the provider is a
    /// file-based provider, NULL otherwise.</returns>
    FdoStringCollection* GetDependentFileNames();


private:
    /**
     * The connection that spawned us.
     */
    SuperMapConnection* m_Connection; // weak reference

    /**
     * The dictionary of connection parameters.
     */
    FdoPtr<FdoCommonConnPropDictionary> m_PropertyDictionary;

	 /** added by zhoux
     * The string collection used for the dependent files.
     */
    FdoPtr<FdoStringCollection> m_DependentFiles;

};

#endif // __SUPERMAPCONNECTIONINFO_H__

