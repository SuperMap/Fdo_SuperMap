#ifndef FDO_XML_ATTRIBUTECOLLECTION
#define FDO_XML_ATTRIBUTECOLLECTION
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

/// \brief
/// FdoXmlAttributeCollection is a collection of XML Attribute objects.
class FdoXmlAttributeCollection : public FdoNamedCollection<FdoXmlAttribute, FdoXmlException>
{
public:
    /// \brief
    /// Constructs an empty XML attribute collection.
    /// 
    /// \return
    /// Returns FdoXmlAttributeCollection
    /// 
    FDO_API_COMMON static FdoXmlAttributeCollection* Create(void)
    {
        return new FdoXmlAttributeCollection();
    }

protected:
/// \cond DOXYGEN-IGNORE
    FdoXmlAttributeCollection() : FdoNamedCollection<FdoXmlAttribute, FdoXmlException>()
    {
    }
/// \endcond

    FDO_API_COMMON virtual void Dispose()
    {
        delete this;
    }
};

/// \ingroup (typedefs)
/// \brief
/// FdoXmlAttributeCollectionP is a FdoPtr on FdoXmlAttributeCollection, provided for convenience.
typedef FdoPtr<FdoXmlAttributeCollection> FdoXmlAttributesP;

#endif


