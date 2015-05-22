/** \file	 SuperMapConnectionInfo.cpp
*  \author	 郝玉江
*  \attention 
*  Copyright &copy;  1996-2007 SuperMap GIS Technologies,Inc.<br>
*  All Rights Reserved
*  \version 1.0
*  \date 2007-09-19
*/

#include "SuperMap.h"

SuperMapCommandCapabilities::SuperMapCommandCapabilities ()
{
}

SuperMapCommandCapabilities::~SuperMapCommandCapabilities ()
{
}

void SuperMapCommandCapabilities::Dispose()
{
	delete this;
}

/// <summary>Gets an array of the FdoCommandType values supported by the feature provider.</summary>
/// <param name="size">Output the number of commands</param> 
/// <returns>Returns the list of commands</returns> 
FdoInt32* SuperMapCommandCapabilities::GetCommands (FdoInt32& size)
{
	TRACE(_T("调用 SuperMapCommandCapabilities::GetCommands()... \n"));
	// 增加可以执行的命令
	static const FdoCommandType commands[] =
	{
        FdoCommandType_Select,
		//TODO::测试在什么时候调用这个命令
       // FdoCommandType_SelectAggregates,
        FdoCommandType_DescribeSchema,
       // FdoCommandType_DescribeSchemaMapping,
        FdoCommandType_GetSpatialContexts,
		FdoCommandType_CreateSpatialContext,
        FdoCommandType_Insert,
        FdoCommandType_Update,
        FdoCommandType_Delete,
        FdoCommandType_ApplySchema,
		FdoCommandType_DestroySchema
		// TODO:: 再加入建立数据源的功能
		//FdoCommandType_CreateDataStore
		//FdoCommandType_DestroyDataStore,
		//TODO:: 再添加扩展的SdfCommandType_CreateSDFFile类似的SDB命令
	};

	/* static const FdoCommandType commands[] =
    {
        FdoCommandType_Select,
        FdoCommandType_SelectAggregates,
        FdoCommandType_DescribeSchema,
        FdoCommandType_DescribeSchemaMapping,
        FdoCommandType_GetSpatialContexts,
		FdoCommandType_CreateSpatialContext,
        FdoCommandType_Insert,
        FdoCommandType_Update,
        FdoCommandType_Delete,
        FdoCommandType_ApplySchema,
        FdoCommandType_DestroySchema
    };*/


	size = sizeof (commands) / sizeof (FdoCommandType);

	return ((FdoInt32*)commands);
}

/// <summary>Determines if commands support parameterization.</summary>
/// <returns>Returns true if commands support parameterization</returns> 
bool SuperMapCommandCapabilities::SupportsParameters ()
{
	TRACE(_T("调用 SuperMapCommandCapabilities::SupportsParameters()... \n"));
	//TODO:: 如果要建立SDB数据源的时候可能要用到
	return (false);
}

/// <summary>Determines if the feature provider supports command execution timeout.</summary>
/// <returns>Returns true if the feature provider supports timeout.</returns> 
bool SuperMapCommandCapabilities::SupportsTimeout ()
{
	TRACE(_T("调用 SuperMapCommandCapabilities::SupportsTimeout()... \n"));
	return (false);
}


/// <summary>Determines if the feature provider can use expressions for properties with Select and SelectAggregate commands.</summary>
/// <returns>Returns true if the feature provider supports select expressions.</returns> 
bool SuperMapCommandCapabilities::SupportsSelectExpressions()
{
	TRACE(_T("调用 SuperMapCommandCapabilities::SupportsSelectExpressions()... \n"));
	return true;
}

/// <summary>Determines if simple functions can be used in Select and SelectAggregates command. 
/// Aggregate functions can only be used in the SelectAggregates command. Capability for using SelectAggregates is found in 
/// CommandCapabilities.</summary>
/// <returns>Returns true if the feature provider supports select simple functions.</returns> 
bool SuperMapCommandCapabilities::SupportsSelectFunctions()
{
	TRACE(_T("调用 SuperMapCommandCapabilities::SupportsSelectFunctions()... \n"));
	//TODO::再做测试，可能要改成TRUE
	return false;
}

/// <summary>Determines if Distinct can be used with SelectAggregates. This can be true only 
/// if the SelectAggregates command is supported by the provider.</summary>
/// <returns>Returns true if the feature provider supports select distinct.</returns> 
bool SuperMapCommandCapabilities::SupportsSelectDistinct()
{
	TRACE(_T("调用 SuperMapCommandCapabilities::SupportsSelectDistinct()... \n"));
	/*return true;*/
	return false;   // modified by zhouxu 2008-2-20
}

/// <summary>Determines  if ordering is available in the Select and SelectAggregates command.</summary>
/// <returns>Returns true if the feature provider supports select ordering.</returns> 
bool SuperMapCommandCapabilities::SupportsSelectOrdering()
{
	TRACE(_T("调用 SuperMapCommandCapabilities::SupportsSelectOrdering()... \n"));
	return false;
}

/// <summary>Determines if a grouping criteria is available in the SelectAggregates command. 
/// This can be true only if the SelectAggregates command is supported by the provider. Note that aggregate 
/// functions can be supported without also supporting grouping criteria (but not vice versa).</summary>
/// <returns>Returns true if the feature provider supports select grouping.</returns> 
bool SuperMapCommandCapabilities::SupportsSelectGrouping()
{
	TRACE(_T("调用 SuperMapCommandCapabilities::SupportsSelectGrouping()... \n"));
	return false;
}

