#ifndef FDO_XML_UTILXRCS_H
#define FDO_XML_UTILXRCS_H
// 

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

#include <FdoCommon.h>

/// \cond DOXYGEN-IGNORE
// This class provides some utility functions for using Xerces to parse XML 
// documents.
class FdoXmlUtilXrcs {
public:
    /// Do one-time initialization of Xerces package. This function can be called 
    /// multiple times. It only initializes Xerces once.
    FDO_API_COMMON static void Initialize();
    /// Xerces wide characters are always 2 bytes. FDO wide character size varies between
    /// operating systems:

    /// Converts Xerces wide char string to FDO wide chars.
    /// 
    FDO_API_COMMON static FdoStringP Xrcs2Unicode( const XMLCh* chars, const unsigned int length = 0 );
    /// Converts FDO wide char string to Xerces wide chars.
    /// Caller is responsible for freeing returned string. The string must be freed using
    /// XERCES_CPP_NAMESPACE::XMLString::release().
    FDO_API_COMMON static XMLCh* Unicode2Xrcs( FdoString* chars );
};
/// \endcond

#endif


