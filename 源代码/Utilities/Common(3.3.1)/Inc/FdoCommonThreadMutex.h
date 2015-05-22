#ifndef FDO_COMMON_THREAD_MUTEX_H
#define FDO_COMMON_THREAD_MUTEX_H
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
 */

#ifdef _WIN32
#include <windows.h>
#else
#include <pthread.h>
#endif

// This class provides a mutex for synchronizing access to static
// variables by different threads.
class FdoCommonThreadMutex
{
public:
    FdoCommonThreadMutex();
    ~FdoCommonThreadMutex();

    /// Enter a critical section
    void Enter();

    /// Leave a critical section.
    void Leave();

private:
#ifdef _WIN32
    CRITICAL_SECTION mMutex;
#else
    pthread_mutex_t mMutex;
    static pthread_mutex_t temp;
#endif
};

#endif


