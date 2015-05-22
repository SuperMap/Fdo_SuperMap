#ifndef FDO_SEMAPHORE
#define FDO_SEMAPHORE
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

/// \cond DOXYGEN-IGNORE

/// \brief 
/// FdoSemaphore is a semaphore class. It is used to prevent operations
/// from happening concurrently or re-entrantly. FdoSemaphore is not currently part
/// of the FDO API but can be added if there is a demand. It is a wrapper class around
/// a boolean semaphore.
///
/// FdoSemaphore can be used to prevent a member function on another class from 
/// being called re-entrantly for the same object (see FdoXmlReaderXrcs::Parse()) 
/// for an example. This can be done by declaring a FdoSemaphoreP, at the start of the
/// function, that takes a boolean member and an exception. The boolean member must initially
/// be false. When the FdoSemaphoreP is created, the boolean member is set to true. When 
/// the function exits, FdoSemaphoreP goes out of scope and sets the boolean member back
/// to false. However, if the function is called a second time before the first 
/// invokation finishes, the second FdoSemaphoreP created will detect that the boolean member
/// is true, and it will throw the given exception, thus rejecting the re-entrant 
/// function call.
class FdoSemaphore : public FdoIDisposable
{
public:
    /// \brief
    /// Constructs a new semaphore.
    /// \param semaphore 
    /// Input the semaphore switch. If true, then the
    /// given exception is thrown. If false, then semaphore is set to true.
    /// semaphore is set back to false when this object is deleted.
    /// \param ex 
    /// Input the exception to throw when semaphore is true.
    /// 
    /// \return
    /// Returns FdoSemaphore
    /// 
    static FdoSemaphore* Create( FdoBoolean& semaphore, FdoException* ex )
    {
        return new FdoSemaphore( semaphore, ex );
    }

protected:
    FdoSemaphore() {}
    FdoSemaphore( bool& semaphore, FdoException* ex );
    virtual ~FdoSemaphore();

    virtual void Dispose()
    {
        delete this;
    }

private:
    /// Pointer to the bool semaphore, so that it can be reset on destruction
    /// of this object.
    FdoBoolean* mSemaphore;

};

/// \brief
/// FdoSemaphoreP is a FdoPtr on FdoSemaphore, provided for convenience.
typedef FdoPtr<FdoSemaphore> FdoSemaphoreP;

/// \endcond

#endif


