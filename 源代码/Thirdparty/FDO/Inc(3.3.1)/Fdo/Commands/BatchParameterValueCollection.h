#ifndef _BATCHPARAMETERVALUECOLLECTION_H_
#define _BATCHPARAMETERVALUECOLLECTION_H_
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

#ifdef _WIN32
#pragma once
#endif

#include <FdoStd.h>
#include <Fdo/Commands/ParameterValueCollection.h>

/// \brief
/// The FdoBatchParameterValueCollection class represents a collection of parameter value collections that is used for
/// optimized batch inserts.
class FdoBatchParameterValueCollection : public FdoCollection<FdoParameterValueCollection, FdoCommandException>
{
protected:
/// \cond DOXYGEN-IGNORE
    virtual void Dispose()
    {
        delete this;
    }
/// \endcond

public:
    /// \brief
    /// Constructs a default empty instance of an FdoBatchParameterValueCollection.
    /// 
    /// \return
    /// Returns FdoBatchParameterValueCollection
    /// 
    FDO_API static FdoBatchParameterValueCollection* Create();
};
#endif


