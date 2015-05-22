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
#include <FdoCommonThreadMutex.h>

#ifndef _WIN32
pthread_mutex_t FdoCommonThreadMutex::temp = PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP;
#endif

FdoCommonThreadMutex::FdoCommonThreadMutex()
{
#ifdef _WIN32
    InitializeCriticalSection(&mMutex);
#else
    mMutex = temp;
#endif
}

FdoCommonThreadMutex::~FdoCommonThreadMutex()
{
#ifdef _WIN32
    DeleteCriticalSection(&mMutex);
#else
    pthread_mutex_destroy(&mMutex);
#endif
}

void FdoCommonThreadMutex::Enter()
{
#ifdef _WIN32
    EnterCriticalSection(&mMutex);
#else
    pthread_mutex_lock(&mMutex);
#endif
}

void FdoCommonThreadMutex::Leave()
{
#ifdef _WIN32
    LeaveCriticalSection(&mMutex);
#else
    pthread_mutex_unlock(&mMutex);
#endif
}

/* TODO:
ut_thread_data_def* ut_thread_get_value()
{
#ifdef _WIN32
    ut_thread_data_def *data = TlsGetValue(tlsIndex);
	if (data == NULL)
	{
		data = (ut_thread_data_def *) calloc(1, sizeof(ut_thread_data_def));	
	    init(data);
        TlsSetValue(tlsIndex, data);
	}
	return data;
#else

	ut_thread_data_def *data = pthread_getspecific(key);
	if (data == NULL)
	{		
		data = (ut_thread_data_def *) calloc(1, sizeof(ut_thread_data_def));	
		init(data);
		pthread_setspecific(key, data);
	}
	return data;

#endif


}
*/

