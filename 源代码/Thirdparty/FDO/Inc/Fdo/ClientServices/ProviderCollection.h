#ifndef _FDOPROVIDERCOLLECTION_H_
#define _FDOPROVIDERCOLLECTION_H_
/***************************************************************************

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

 *
 ***************************************************************************/
#ifdef _WIN32
#pragma once
#endif

// Include definitions
#include <vector>
#include <FdoStd.h>
#include <Fdo/ClientServices/ClientServices.h>
#include <Fdo/ClientServices/Provider.h>

/// \brief
/// Read only collection of information describing each of the installed feature providers
class FdoProviderCollection : public FdoIDisposable
{
    /// Instances of interface FdoProviderRegistry are responsible for the 
    /// lifespan of FdoProviderCollection
    friend class FdoProviderRegistry;

/// \cond DOXYGEN-IGNORE
protected:
    /// Constructs a default instance of a FdoProviderCollection.
    FdoProviderCollection();

    /// Default destructor for FdoProviderCollection.
    virtual ~FdoProviderCollection();

    virtual void Dispose();

    /// Adds a new provider to the collection. The pointer passed to the Add method is stored. 
    /// Throws an invalid argument exception if the collection alreay holds a provider with the same name
    /// Adding a provider to the collection only adds the item to the buffered vector contained in the collection.
    /// The provider is not persisted beyond the collection. The collection will attempt to deallocate the provider when
    /// the collection is destructed.
    virtual void Add(FdoProvider* provider);

    /// Removes a provider from the collection. The allocated provider is freed. removing a provider from the 
    /// collection only removes the item from the buffered vector contained in the collection. The provider is not 
    /// removed from the persistant data store. 
    virtual void Remove(const wchar_t* name);
/// \endcond

public:
    /// \brief
    /// Gets the number of items in the collection
    /// 
    /// \return
    /// Returns an int containing the number of items.
    /// Throws an instance of FdoClientServicesException * if an error occurs.
    /// 
    FDO_API virtual int GetCount() const;

    /// \brief
    /// Gets the Provider item in the collection at the specified index. 
    /// 
    /// \param index 
    /// The index of the provider in the collection. The index is 0 based.
    /// 
    /// \return
    /// Returns an instance of an FdoProvider.
    /// Throws an instance of FdoClientServicesException * if the index is out of range or an error occurs.
    /// 
    FDO_API virtual FdoProvider * const GetItem(int index) const;
    
    /// \brief
    /// Determines if the collection contains the specified item
    /// 
    /// \param name 
    /// The unique name of the feature provider. This name should be of the form 
    /// [Company].[Provider].[Version].
    /// 
    /// \return
    /// Returns true if the collection contains the specified item, otherwise false.
    /// Throws an instance of FdoClientServicesException * if an error occurs.
    /// 
    FDO_API virtual bool Contains(const wchar_t* name) const;
    
    /// \brief
    /// Returns the index of the specified item in the collection.
    /// 
    /// \param name 
    /// The unique name of the feature provider. This name should be of the form 
    /// [Company].[Provider].[Version].
    /// 
    /// \return
    /// Returns the index item or -1 if the item does not exist. Index is 0 based.
    /// Throws an instance of FdoClientServicesException * if an error occurs.
    /// 
    FDO_API virtual int IndexOf(const wchar_t* name) const;

private:
    /// The list of providers defined in the registry
    std::vector<FdoProvider*> m_providers;
};
#endif


