/********************************************************************************
*                                                                               *
*                 M u l i t h r e a d i n g   S u p p o r t                     *
*                                                                               *
*********************************************************************************
* Copyright (C) 2004,2006 by Jeroen van der Zijp.   All Rights Reserved.        *
*********************************************************************************
* This library is free software; you can redistribute it and/or                 *
* modify it under the terms of the GNU Lesser General Public                    *
* License as published by the Free Software Foundation; either                  *
* version 2.1 of the License, or (at your option) any later version.            *
*                                                                               *
* This library is distributed in the hope that it will be useful,               *
* but WITHOUT ANY WARRANTY; without even the implied warranty of                *
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU             *
* Lesser General Public License for more details.                               *
*                                                                               *
* You should have received a copy of the GNU Lesser General Public              *
* License along with this library; if not, write to the Free Software           *
* Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA.    *
*********************************************************************************
* $Id: UGThread.h,v 1.8 2007/10/15 04:17:25 zengzm Exp $                          *
********************************************************************************/
#ifndef UGTHREAD_H
#define UGTHREAD_H

#include "Base/ugdefs.h"
#include "Base/UGTime.h"
#include "Base/ugplatform.h"

// 2007-3-26 by zengzm 不得已,还是要放到这里来,因为MFC很变态,把LoadString等都定义为宏
// 在MBCS下, 转变为LoadStringA,导致UGString的LoadString也变为LoadStringA了.
// 所以这些头文件都不能加到ugwin32.h中
#ifdef WIN32
//	#include <afxmt.h>
#endif

namespace UGC {


class UGCondition;

/**
* UGMutex provides a mutex which can be used to enforce critical
* sections around updates of data shared by multiple threads.
*/
class BASE_API UGMutex {
  friend class UGCondition;
private:
  unsigned long data[24];
private:
  UGMutex(const UGMutex&);
  UGMutex &operator=(const UGMutex&);
public:

  /// Initialize the mutex
  UGMutex(UGbool recursive=FALSE);

  /// Lock the mutex
  void lock();

  /// Return true if succeeded locking the mutex
  UGbool trylock();

  /// Return true if mutex is already locked
  UGbool locked();

  /// Unlock mutex
  void unlock();

  /// Delete the mutex
  ~UGMutex();
  };



/**
* An easy way to establish a correspondence between a C++ scope
* and a critical section is to simply declare an UGMutexLock
* at the beginning of the scope.
* The mutex will be automatically released when the scope is
* left (either by natural means or by means of an exception.
*/
class BASE_API UGMutexLock {
private:
  UGMutex& mtx;
private:
  UGMutexLock();
  UGMutexLock(const UGMutexLock&);
  UGMutexLock& operator=(const UGMutexLock&);
public:

  /// Construct & lock associated mutex
  
  //UGMutexLock(UGMutex& m):mtx(m){lock();}
  // 2007-5-28 by malq-以前的构造函中执行了lock(),外面使用的时候可能会出问题，所以这里取消，外面用的时候直接调用lock
  UGMutexLock(UGMutex& m):mtx(m){}

  /// Return reference to associated mutex
  UGMutex& mutex(){ return mtx; }

  /// Lock mutex
  void lock(){ mtx.lock(); }

  /// Return true if succeeded locking the mutex
  UGbool trylock(){ return mtx.trylock(); }

  /// Return true if mutex is already locked
  UGbool locked(){ return mtx.locked(); }

  /// Unlock mutex
  void unlock(){ mtx.unlock(); }

  /// Destroy and unlock associated mutex
  ~UGMutexLock(){ unlock(); }
  };



/**
* A read / write lock allows multiple readers but only a single
* writer.
*/
class BASE_API UGReadWriteLock {
private:
  UGuval data[24];
private:
  UGReadWriteLock(const UGReadWriteLock&);
  UGReadWriteLock &operator=(const UGReadWriteLock&);
public:

  /// Initialize the read/write lock
  UGReadWriteLock();

  /// Acquire read lock for read/write lock
  void readLock();

  /// Try to acquire read lock for read/write lock
  bool tryReadLock();

  /// Unlock read lock
  void readUnlock();

  /// Acquire write lock for read/write lock
  void writeLock();

  /// Try to acquire write lock for read/write lock
  bool tryWriteLock();

  /// Unlock write lock
  void writeUnlock();

  /// Delete the read/write lock
  ~UGReadWriteLock();
  };



/**
* A condition allows one or more threads to synchronize
* to an event.  When a thread calls wait, the associated
* mutex is unlocked while the thread is blocked.  When the
* condition becomes signaled, the associated mutex is
* locked and the thread(s) are reawakened.
*/
class BASE_API UGCondition {
private:
  UGuval data[12];
private:
  UGCondition(const UGCondition&);
  UGCondition& operator=(const UGCondition&);
public:

  /// Initialize the condition
  UGCondition();

  /**
  * Wait until condition becomes signalled, using given mutex,
  * which must already have been locked prior to this call.
  */
  void wait(UGMutex& mtx);

  /**
  * Wait until condition becomes signalled, using given mutex,
  * which must already have been locked prior to this call.
  * Returns true if successful, false if timeout occurred.
  * Note that the wait-time is specified in nanoseconds
  * since the Epoch (Jan 1, 1970).
  */
  UGbool wait(UGMutex& mtx,UGuint nsec);
  /**
  * Wake or unblock a single blocked thread
  */
  void signal();

  /**
  * Wake or unblock all blocked threads
  */
  void broadcast();

  /// Delete the condition
  ~UGCondition();
  };



/**
* A semaphore allows for protection of a resource that can
* be accessed by a fixed number of simultaneous threads.
*/
class BASE_API UGSemaphore {
private:
  UGuval data[16];
private:
  UGSemaphore(const UGSemaphore&);
  UGSemaphore& operator=(const UGSemaphore&);
public:

  /// Initialize semaphore with given count
  UGSemaphore(UGint initial=1);

  /// Decrement semaphore
  void wait();

  /// Non-blocking semaphore decrement; return true if locked
  UGbool trywait();

  /// Increment semaphore
  void post();

  /// Delete semaphore
  ~UGSemaphore();
  };



/**
* UGThread provides system-independent support for threads.
* Subclasses must implement the run() function do implement
* the desired functionality of the thread.
* The storage of the UGThread object is to be managed by the
* calling thread, not by the thread itself.
*/
class BASE_API UGThread {
private:
  volatile UGThreadID tid;
private:
  UGThread(const UGThread&);
  UGThread &operator=(const UGThread&);

  static UGHandle UGCALLBACK execute(void*);

public:
  // added by zengzm 2007-06-04 得到当前线程id
  //! \brief 得到当前线程的ID
  //! \return 返回当前线程的ID
  static UGuint GetCurrentThreadId();

public:

  /// Thread priority levels
  enum Priority {
    PRIORITY_ERROR=-1,  /// Failed to get priority
    PRIORITY_DEFAULT,  	/// Default scheduling priority
    PRIORITY_MINIMUM,   /// Minimum scheduling priority
    PRIORITY_LOWER,     /// Lower scheduling priority   
    PRIORITY_MEDIUM,    /// Medium priority           
    PRIORITY_HIGHER,    /// Higher scheduling priority  
    PRIORITY_MAXIMUM    /// Maximum scheduling priority
    };

  /// Thread scheduling policies
  enum Policy {
    POLICY_ERROR=-1,    /// Failed to get policy
    POLICY_DEFAULT,     /// Default scheduling     
    POLICY_FIFO,        /// First in, first out scheduling
    POLICY_ROUND_ROBIN 	/// Round-robin scheduling 
    };

protected:

  /**
  * All threads execute by deriving the run method of UGThread.
  * If an uncaught exception was thrown, this function returns -1.
  */
  virtual UGint run() = 0;

public:

  /// Initialize thread object.
  UGThread();

  /**
  * Return handle of this thread object.
  * This handle is valid in the context of the thread which
  * called start().
  */
  UGThreadID id() const;

  /**
  * Return true if this thread is running.
  */
  UGbool running() const;

  /**
  * Start thread; the thread is started as attached.
  * The thread is given stacksize for its stack; a value of
  * zero for stacksize will give it the default stack size.
  */
  UGbool start(unsigned long stacksize=0);

  /**
  * Suspend calling thread until thread is done.
  */
  UGbool join();

  /**
  * Suspend calling thread until thread is done, and set code to the
  * return value of run() or the argument passed into exit().
  * If an exception happened in the thread, return -1.
  */
  UGbool join(UGint& code);

  /**
  * Cancel the thread, stopping it immediately, running or not.
  * If the calling thread is this thread, nothing happens.
  * It is probably better to wait until it is finished, in case the
  * thread currently holds mutexes.
  */
  UGbool cancel();

  /**
  * Detach thread, so that a no join() is necessary to harvest the
  * resources of this thread.
  */
  UGbool detach();

  /**
  * Exit the calling thread.
  * No destructors are invoked for objects on thread's stack;
  * to invoke destructors, throw an exception instead.
  */
  static void exit(UGint code=0);

  /**
  * Make the thread yield its time quantum.
  */
  static void yield();

  /**
  * Return time in nanoseconds since Epoch (Jan 1, 1970).
  */
  static UGulong time();

  /**
  * Make the calling thread sleep for a number of nanoseconds.
  */
  static void sleep(UGuint nsec);

  /**
  * Wake at appointed time specified in nanoseconds since Epoch.
  */
  static void wakeat(UGuint nsec);

  /**
  * Return pointer to the UGThread instance associated
  * with the calling thread; it returns NULL for the main
  * thread and all threads not created by FOX.
  */
  static UGThread* self();

  /**
  * Return thread id of calling thread.
  */
  static UGThreadID current();

  /**
  * Set thread scheduling priority.
  */
  UGbool priority(Priority prio);

  /**
  * Return thread scheduling priority.
  */
  Priority priority() const;

  /**
  * Set thread scheduling policy.
  */
  UGbool policy(Policy plcy);


  /**
  * Get thread scheduling policy.
  */
  Policy policy() const;

  /**
  * Destroy the thread immediately, running or not.
  * It is probably better to wait until it is finished, in case
  * the thread currently holds mutexes.
  */
  virtual ~UGThread();
  };

}

#endif



