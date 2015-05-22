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

#ifndef FdoCommonThreadUtil___H
#define FdoCommonThreadUtil___H	1


#ifdef _WIN32

#include <process.h>
#define FDOCOMMON_THREAD_FUNCTION_SIGNATURE unsigned __stdcall
#define FDOCOMMON_ENDTHREAD(exitcode) _endthreadex(exitcode);  return (exitcode);
#define FDOCOMMON_THREAD_HANDLE HANDLE

#else

#include <pthread.h>
#define FDOCOMMON_THREAD_FUNCTION_SIGNATURE void*
#define FDOCOMMON_ENDTHREAD(exitcode) return (exitcode);
#define FDOCOMMON_THREAD_HANDLE pthread_t

#endif


// This class define methods that run on both Windows and Linux.
class FdoCommonThreadUtil
{
public:

    /// Create a new thread on function 'routine' with input argument 'arg':
    static bool CreateThread(FDOCOMMON_THREAD_HANDLE *handle, void* routine, void *arg);

    /// Close the given thread handle:
    static bool CloseThread(FDOCOMMON_THREAD_HANDLE handle);

    /// Wait for the given threads to terminate:
    static bool WaitForThreads(int count, FDOCOMMON_THREAD_HANDLE* handles, unsigned long timeoutMilliseconds);
};

#endif // FdoCommonThreadUtil___H
