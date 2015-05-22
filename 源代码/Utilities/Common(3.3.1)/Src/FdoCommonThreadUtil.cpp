/*
 * 
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

#include "stdafx.h"
#include "FdoCommonThreadUtil.h"


#pragma warning(push)
#pragma warning(disable: 4100)  // Disable warning C4100: 'xxxx' : unreferenced formal parameter



bool FdoCommonThreadUtil::CreateThread(FDOCOMMON_THREAD_HANDLE *handle, void* routine, void *arg)
{
#ifdef _WIN32
    unsigned int threadId;
    unsigned int (__stdcall* routine2)(void*) = (unsigned int (__stdcall*)(void*)) routine;
    *handle = (FDOCOMMON_THREAD_HANDLE)_beginthreadex (NULL, 0, routine2, arg, 0, &threadId);
    return (0 != *handle);
#else
    void* (*routine2)(void*) = (void* (*)(void*)) routine;
    int ret = pthread_create(handle, NULL, routine2, arg);
    return (ret == 0);
#endif
}


bool FdoCommonThreadUtil::CloseThread(FDOCOMMON_THREAD_HANDLE handle)
{
#ifdef _WIN32
    return 0 != CloseHandle(handle);
#else
    /* no-op */
    return true;
#endif
}


bool FdoCommonThreadUtil::WaitForThreads(int count, FDOCOMMON_THREAD_HANDLE* handles, unsigned long timeoutMilliseconds)
{
    bool success = true;
#ifdef _WIN32
    DWORD wait;
    wait = WaitForMultipleObjects (count, handles, true, timeoutMilliseconds);
    if ((WAIT_OBJECT_0 <= wait) && ((WAIT_OBJECT_0 + count - 1) >= wait))
        // all ran to completion
        success = true;
    else if (WAIT_TIMEOUT == wait)
        // timeout occured
        success = false;
#else
    int ret=0;
    for (int i=0; i<count; i++)
    {
        ret = pthread_join(handles[i], NULL);   // TODO: handle timeoutMilliseconds
        if (ret != 0)
            success = false;
    }
#endif

    return success;
}




#pragma warning(pop) // Enable warning C4100: 'xxxx' : unreferenced formal parameter

