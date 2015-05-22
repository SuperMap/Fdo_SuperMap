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
#ifndef FdoWmsOvLayerCollection_H
#define FdoWmsOvLayerCollection_H

#ifdef _WIN32
#pragma once
#endif //_WIN32

#include <WMS/FdoWmsOvProvider.h>
#include <WMS/Override/FdoWmsOvLayerDefinition.h>

/// \brief
///  
/// The FdoWmsOvLayerCollection holds a list of WMS Layer definitions.
class FdoWmsOvLayerCollection : public FdoPhysicalElementMappingCollection<FdoWmsOvLayerDefinition>
{
public:
    /// \brief
    /// Constructs a new empty Layer Definition collection.
    /// 
    /// \param parent 
    /// Input parent object
    /// 
    /// \return
    /// Returns the newly created FdoWmsOvLayerCollection instance.
    /// 
	FDOWMS_API static FdoWmsOvLayerCollection* Create(FdoPhysicalElementMapping *parent);

/// \cond DOXYGEN-IGNORE

protected:
	FDOWMS_API FdoWmsOvLayerCollection(void);
    FDOWMS_API FdoWmsOvLayerCollection(FdoPhysicalElementMapping *parent);
    FDOWMS_API virtual ~FdoWmsOvLayerCollection(void);
	void Dispose();

/// \endcond

};

/// \brief
///  FdoWmsLayeresP is a GisPtr on FdoWmsOvLayerCollection, provided for convenience. 
typedef FdoPtr<FdoWmsOvLayerCollection> FdoWmsOvLayersP;

#endif // FdoWmsOvLayerCollection_H


