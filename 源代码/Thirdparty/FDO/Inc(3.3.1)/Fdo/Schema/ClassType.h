#ifndef _CLASSTYPE_H_
#define _CLASSTYPE_H_

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

#ifdef _WIN32
#pragma once
#endif

/// \ingroup (enums)
/// \brief
/// The FdoClassType enumeration lists all of the concrete class types defined in
/// the Schema package.
enum FdoClassType
{
    /// Represents the concrete class type Class.
    FdoClassType_Class,

    /// Represents the concrete class type FeatureClass.
    FdoClassType_FeatureClass,

    /// Represents the concrete class type NetworkClass.
    FdoClassType_NetworkClass,

    /// Represents the concrete class type NetworkLayerClass.
    FdoClassType_NetworkLayerClass,

    /// Represents the concrete class type NetworkNodeClass.
    FdoClassType_NetworkNodeClass,

    /// Represents the concrete class type NetworkLinkClass.
    FdoClassType_NetworkLinkClass
};
#endif


