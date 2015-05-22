/** \file	 SuperMapConnectionInfo.cpp
 *  \author	 郝玉江
 *  \attention 
 *  Copyright &copy;  1996-2007 SuperMap GIS Technologies,Inc.<br>
 *  All Rights Reserved
 *  \version 1.0
 *  \date 2007-09-19
 *  \note : modified by zhouxu 2007-10-23
 */


#include <SuperMap.h>
#include <FdoCommonStringUtil.h>

SuperMapConnectionInfo::SuperMapConnectionInfo (SuperMapConnection* connection) :
    m_Connection (connection)
{
    // NOTE: we use a weak reference here to avoid a circular dependancy:
    // FDO_SAFE_ADDREF(mConnection.p);
}

SuperMapConnectionInfo::~SuperMapConnectionInfo (void)
{
}

void SuperMapConnectionInfo::Dispose()
{
    delete this;
}

void SuperMapConnectionInfo::validate ()
{
    if (m_Connection == NULL)
	{
        throw FdoException::Create (NlsMsgGet (SUPERMAP_CONNECTION_INVALID, "Connection is invalid."));
	}
}

/// <summary>Gets the name of the feature provider.</summary>
/// <returns>Returns the provider name</returns>
FdoString* SuperMapConnectionInfo::GetProviderName ()
{
    validate ();
    return (SUPERMAP_PROVIDER_NAME);
}

/// <summary>Gets the display name of the feature provider.</summary>
/// <returns>Returns the provider's display name</returns>
FdoString* SuperMapConnectionInfo::GetProviderDisplayName()
{
    validate ();
    return NlsMsgGet(SUPERMAP_PROVIDER_DISPLAY_NAME, SUPERMAP_PROVIDER_DEFAULT_DISPLAY_NAME);
}

/// <summary>Gets the description of the feature provider.</summary>
/// <returns>Returns the provider description</returns>
FdoString* SuperMapConnectionInfo::GetProviderDescription ()
{
    validate ();
    return NlsMsgGet(SUPERMAP_PROVIDER_DESCRIPTION, SUPERMAP_PROVIDER_DEFAULT_DESCRIPTION);
}

/// <summary>Gets the version of the feature provider.</summary>
/// <returns>Returns provider version</returns>
FdoString* SuperMapConnectionInfo::GetProviderVersion ()
{
    validate ();
    return (SUPERMAP_PROVIDER_VERSION);
}

/// <summary>Gets the version of the Feature Data Objects specification to which this provider conforms.</summary>
/// <returns>Returns FDO version supported.</returns>
FdoString* SuperMapConnectionInfo::GetFeatureDataObjectsVersion ()
{
    validate ();
    return (SUPERMAP_FDO_VERSION);
}

/// <summary>Gets the FdoIConnectionPropertyDictionary interface that can be used to dynamically query and set the properties required to establish a connection.</summary>
/// <returns>Returns the property dictionary</returns>
FdoIConnectionPropertyDictionary* SuperMapConnectionInfo::GetConnectionProperties ()
{
    validate ();
    if (m_PropertyDictionary == NULL)
    {
        m_PropertyDictionary = new FdoCommonConnPropDictionary (m_Connection);

        // Define all the connection properties:
        char* mbPropName = NULL;

        wide_to_multibyte(mbPropName, CONNECTIONPROPERTY_DATASOURCE);
        FdoPtr<ConnectionProperty> property = new ConnectionProperty (CONNECTIONPROPERTY_DATASOURCE,
                NlsMsgGet(SUPERMAP_CONNECTION_STRING, "Connection String"),
				// TODO:: 提示信息改为宏，以适合中英文
				//L"连接字符串",
				L"", true, false, false, true, false, false, false, 0, NULL);
        m_PropertyDictionary->AddProperty(property);
    }
    return (FDO_SAFE_ADDREF(m_PropertyDictionary.p));
}

/// <summary>Returns the provider type. A provider can be a file-based, database-based or
/// web-based provider. The valid values the function may return are defined in
/// the enumeration FdoProviderDatastoreType. The enumeration includes the following
/// values: FdoProviderDatastoreType_Unknown, FdoProviderDatastoreType_File,
/// FdoProviderDatastoreType_DatabaseServer, FdoProviderDatastoreType_WebServer.</summary>
/// <returns>Returns the provider data store type.</returns>
FdoProviderDatastoreType SuperMapConnectionInfo::GetProviderDatastoreType()
{
	// 支持SDB文件
	// TODO::情况特殊，再做测试，会不会影响整个Provider
    return FdoProviderDatastoreType_File;
	//return FdoProviderDatastoreType_DatabaseServer; //for test
}

/// <summary>File-based providers depend on a various files. This function returns a list
/// of fully qualified dependend file names. The return parameter will be NULL if
/// the provider is not a file-based provider.</summary>
/// <returns>Returns the list of fully-qualified dependend file names if the provider is a
/// file-based provider, NULL otherwise.</returns>
FdoStringCollection* SuperMapConnectionInfo::GetDependentFileNames()
{
    return NULL;
	// If the connection is not yet open return NULL.
}
