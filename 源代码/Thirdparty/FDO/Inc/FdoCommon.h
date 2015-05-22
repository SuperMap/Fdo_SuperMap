#ifndef _FDOCOMMON_H_
#define _FDOCOMMON_H_

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

#include <Common/Std.h>
#include <Common/FdoTypes.h>
#include <Common/IDisposable.h>
#include <Common/Disposable.h>
#include <Common/Exception.h>
#include <Common/Ptr.h>
#include <Common/Array.h>
#include <Common/ArrayHelper.h>
#include <Common/Compare.h>
#include <Common/StringP.h>
#include <Common/Dimensionality.h>
#include <Common/GeometryType.h>
#include <Common/StringCollection.h>
#include <Common/Context.h>
#include <Common/DictionaryElement.h>
#include <Common/Dictionary.h>
#include <Common/ReadOnlyNamedCollection.h>
#include <Common/RestrictedNamedCollection.h>
#include <Common/IStreamReader.h>
#include <Common/Vector.h>
#include <Common/Io/MemoryStream.h>
#include <Common/Io/FileStream.h>
#include <Common/Io/TextReader.h>
#include <Common/Io/TextWriter.h>
#include <Common/Io/ObjectStreamReader.h>
#include <Common/Io/ByteStreamReader.h>
#include <Common/Xml/Xml.h>
#include <Common/Xml/XmlException.h>
#include <Common/Xml/Attribute.h>
#include <Common/Xml/AttributeCollection.h>
#include <Common/Xml/SaxContext.h>
#include <Common/Xml/SaxHandler.h>
#include <Common/Xml/CharDataHandler.h>
#include <Common/Xml/SkipElementHandler.h>
#include <Common/Xml/Reader.h>
#include <Common/Xml/Writer.h>
#include <Common/Xml/CopyHandler.h>
#include <Common/Xsl/Transformer.h>
#include <Common/Gml212/Schema.h>
#include <Common/Gml212/Gml212.h>

#endif


