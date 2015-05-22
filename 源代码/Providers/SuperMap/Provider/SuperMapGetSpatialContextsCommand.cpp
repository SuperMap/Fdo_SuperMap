/** \file	 SuperMapGetSpatialContextsCommand.cpp
*  \brief    实现FdoIGetSpatialIContexts接口，获取逻辑要素类的空间语义
*  \author	 周旭
*  \attention 
*  Copyright &copy;  1996-2007 SuperMap GIS Technologies,Inc.<br>
*  All Rights Reserved
*  \version 1.0
*  \date 2007-10-25
*/
#include "SuperMap.h"

SuperMapGetSpatialContextsCommand::SuperMapGetSpatialContextsCommand() :
    FdoCommonCommand<FdoIGetSpatialContexts, SuperMapConnection>(NULL),
    mActiveOnly(false)
{
}

SuperMapGetSpatialContextsCommand::SuperMapGetSpatialContextsCommand(FdoIConnection *connection) :
    FdoCommonCommand<FdoIGetSpatialContexts, SuperMapConnection>(connection),
    mActiveOnly(false)
{
}

SuperMapGetSpatialContextsCommand::~SuperMapGetSpatialContextsCommand(void)
{
}

const bool SuperMapGetSpatialContextsCommand::GetActiveOnly()
{
    return (mActiveOnly);
}

void SuperMapGetSpatialContextsCommand::SetActiveOnly(const bool value)
{
	// Since SHP provider doesn't implement Activate Spatial Context command,
	// disallow this option.
	if ( value )
    //  throw FdoException::Create(NlsMsgGet(SHP_SPATIALCONTEXT_INVALIDOPTION, "Unsupported option." ));
    mActiveOnly = value;
}

FdoISpatialContextReader* SuperMapGetSpatialContextsCommand::Execute()
{
	// Get the spatial context list. The extents will be recomputed with the actual
	// extents of the SHP files grouped by the same Coordinate System.

	TRACE(_T("调用 SuperMapGetSpatialContextsCommand::Execute 。\n"));

	FdoPtr<SuperMapSpatialContextCollection> spatialContextColl = mConnection->GetSpatialContexts();
	return (new SuperMapSpatialContextReader(spatialContextColl));

}