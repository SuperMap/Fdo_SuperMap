#ifndef FDO_DICTIONARY
#define FDO_DICTIONARY
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

#include <Common/NamedCollection.h>

/// \brief
/// FdoDictionary is a collection of name-value pairs.
class FdoDictionary : public FdoNamedCollection<FdoDictionaryElement, FdoException>
{
public:
    /// \brief
    /// Constructs a new empty dictionary
    /// 
    /// \return
    /// Returns FdoDictionary
    /// 
    FDO_API_COMMON static FdoDictionary* Create(void)
    {
        return new FdoDictionary();
    }

protected:

    FDO_API_COMMON virtual void Dispose()
    {
        delete this;
    }

};

/// \ingroup (typedefs)
/// \brief
/// FdoDictionaryP is a FdoPtr on FdoDictionary, provided for convenience.
typedef FdoPtr<FdoDictionary> FdoDictionaryP;

#endif


