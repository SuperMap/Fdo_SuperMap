/** \file	 SuperMapConnectionCapabilities.cpp
 *  \author	 郝玉江
 *  \attention 
 *  Copyright &copy;  1996-2007 SuperMap GIS Technologies,Inc.<br>
 *  All Rights Reserved
 *  \version 1.0
 *  \date 2007-09-19
 */


#include "SuperMap.h"

SuperMapConnectionCapabilities::SuperMapConnectionCapabilities ()
{

}

SuperMapConnectionCapabilities::~SuperMapConnectionCapabilities ()
{

}

void SuperMapConnectionCapabilities::Dispose()
{
    delete this;
}

/// <summary>Gets an FdoThreadCapability value that declares the feature provider's level of thread safety.</summary>
/// <returns>Returns the connection thread capability.</returns> 
FdoThreadCapability SuperMapConnectionCapabilities::GetThreadCapability ()
{
	TRACE(_T("调用 SuperMapConnectionCapabilities::GetThreadCapability()... \n"));
	// 返回提供者支持的线程类型
    return (FdoThreadCapability_SingleThreaded);
	//return (FdoThreadCapability_PerConnectionThreaded);
}

/// <summary>Gets the spatial context extent types supported by the feature provider.</summary>
/// <param name="length">Output the number of spatial context types.</param> 
/// <returns>Returns the list of spatial context extent types.</returns> 
FdoSpatialContextExtentType* SuperMapConnectionCapabilities::GetSpatialContextTypes (FdoInt32& length)
{
	TRACE(_T("调用 SuperMapConnectionCapabilities::GetSpatialContextTypes()... \n"));
    static FdoSpatialContextExtentType types[] =
    {
        FdoSpatialContextExtentType_Static
    };

    length = sizeof(types) / sizeof(FdoSpatialContextExtentType);

    return (types);
}

/// <summary>Determines if the feature provider supports persistent locking.</summary>
/// <returns>Returns true if the feature provider supports persistent locking.</returns> 
bool SuperMapConnectionCapabilities::SupportsLocking ()
{
	TRACE(_T("调用 SuperMapConnectionCapabilities::SupportsLocking()... \n"));
    return (false);
}

/// <summary>Gets an array of the FdoLockType values supported by the feature provider.</summary>
/// <param name="size">Output the number of lock types.</param>
/// <returns>Returns the list of lock types.</returns> 
FdoLockType* SuperMapConnectionCapabilities::GetLockTypes(FdoInt32& size)
{
	TRACE(_T("调用 SuperMapConnectionCapabilities::GetLockTypes()... \n"));
    size = 0;
    return ((FdoLockType*)NULL);
}

/// <summary>Determines if the feature provider supports connection timeout.</summary>
/// <returns>Returns true if the feature provider supports connection timeout.</returns> 
bool SuperMapConnectionCapabilities::SupportsTimeout ()
{
	TRACE(_T("调用 SuperMapConnectionCapabilities::SupportsTimeout()... \n"));
    return (false);
}

/// <summary>Determines if the feature provider supports transactions.</summary>
/// <returns>Returns true if the feature provider supports transactions.</returns> 
bool SuperMapConnectionCapabilities::SupportsTransactions ()
{
	TRACE(_T("调用 SuperMapConnectionCapabilities::SupportsTransactions()... \n"));
	// TODO::进一步研究
    return (false); ////  暂时修改为不支持 by zhouxu 2008-6-2
}

/// <summary>Determines true if the feature provider supports long transactions.</summary>
/// <returns>Returns true if the feature provider supports long transactions.</returns> 
bool SuperMapConnectionCapabilities::SupportsLongTransactions ()
{
	TRACE(_T("调用 SuperMapConnectionCapabilities::SupportsLongTransactions()... \n"));
    return (false);
}

/// <summary>Determines if the feature provider supports SQL commands.</summary>
/// <returns>Returns true if the feature provider supports SQL commands.</returns> 
bool SuperMapConnectionCapabilities::SupportsSQL()
{
	TRACE(_T("调用 SuperMapConnectionCapabilities::SupportsSQL()... \n"));
    return (false);
}

/// <summary>Determines if the feature provider supports XML configuration.</summary>
/// <returns>Returns true if the feature provider supports the setting of a configuration.</returns> 
bool SuperMapConnectionCapabilities::SupportsConfiguration()
{
	TRACE(_T("调用 SuperMapConnectionCapabilities::SupportsConfiguration()... \n"));
	return (false);//
 }

/// <summary>Determines if the provider supports multiple spatial contexts.</summary>
/// <returns>Returns true if the provider supports multiple spatial contexts.</returns> 
bool SuperMapConnectionCapabilities::SupportsMultipleSpatialContexts()
{
	TRACE(_T("调用 SuperMapConnectionCapabilities::SupportsMultipleSpatialContexts()... \n"));
    return (true);
}

/// <summary>Determines if the provider supports specifying the coordinate system by name
/// or ID without specifying the WKT when creating a new spatial context.</summary>
/// <returns>Returns true if the provider supports specifying the coordinate system by name
/// or ID without specifying the WKT when creating a new spatial context.</returns> 
bool SuperMapConnectionCapabilities::SupportsCSysWKTFromCSysName()
{
	TRACE(_T("调用 SuperMapConnectionCapabilities::SupportsCSysWKTFromCSysName()... \n"));
    return (false);
}

bool SuperMapConnectionCapabilities::SupportsWrite()
{
	TRACE(_T("调用 SuperMapConnectionCapabilities::SupportsWrite()... \n"));
    return true;
}

bool SuperMapConnectionCapabilities::SupportsMultiUserWrite()
{
	TRACE(_T("调用 SuperMapConnectionCapabilities::SupportsMultiUserWrite()... \n"));
    return false; //Todo： 如果是数据库引擎就支持多用户写 sdb就不支持
}

bool SuperMapConnectionCapabilities::SupportsFlush()
{
	TRACE(_T("调用 SuperMapConnectionCapabilities::SupportsFlush()... \n"));
	return true; //Todo： 是否支持缓冲函数
}
