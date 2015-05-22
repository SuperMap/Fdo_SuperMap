#ifndef FDO_CONTEXT_H
#define FDO_CONTEXT_H
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
/// FdoContext is a common base for all FDO context classes. A context class is used in
/// complex operations involving multiple functions. It providers a convenient container for 
/// passing information between these functions. This class provides an error list where
/// errors that occur during processing can be logged and reported when the processing completes.
/// Sub-classes can add more specific information to pass around
class FdoContext : public FdoDisposable
{
public:
    /// \brief
    /// Constructs the context
    /// 
    /// \return
    /// Returns FdoContext
    /// 
    FDO_API_COMMON static FdoContext* Create();

    /// \brief
    /// Adds an error to the error list.
    /// 
    /// \param ex 
    /// Input the error to add. 
    /// \warning 
	/// If this error has a 
    /// cause, it will be overridden when thrown (see ThrowErrors()).
    /// 
    FDO_API_COMMON void AddError( FdoException* ex );

    /// \brief
    /// Throws all errors in the error list.
    /// The errors are thrown as a chain. The first error is one thrown. The
    /// second error is set to be the cause of the first error, the third
    /// the cause of the second and so on.
    /// 
    FDO_API_COMMON virtual void ThrowErrors();

protected:
    FDO_API_COMMON FdoContext();
    FDO_API_COMMON virtual ~FdoContext();

private:
    /// Error Collection definition
    class Errors : public FdoCollection<FdoException,FdoException>
    {
    protected:
        virtual void Dispose();

        Errors() {}

    public:
        static Errors* Create()
        {
            return new  Errors();
        }
    };

    /// Error collection
    FdoPtr<Errors> mErrors;
};

/// \ingroup (typedefs)
/// \brief
/// FdoContextP is a FdoPtr on FdoContext, provided for convenience.
typedef FdoPtr<FdoContext> FdoContextP;

#endif


