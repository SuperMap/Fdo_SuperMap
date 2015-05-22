/** \file	 SuperMapSpatialContextReader.cpp
*  \brief    该类用来实现空间语义读取接口：FdoISpatialContextReader
*  \author	 周 旭
*  \attention 
*  Copyright &copy;  1996-2007 SuperMap GIS Technologies,Inc.<br>
*  All Rights Reserved
*  \version 1.0
*  \date 2007-11-14
*/

#include "SuperMap.h"

SuperMapSpatialContextReader::SuperMapSpatialContextReader(SuperMapSpatialContextCollection *spatialContextColl)
:
	m_spatialContextColl(spatialContextColl),
	m_curIndex(0)
{
	FDO_SAFE_ADDREF(m_spatialContextColl.p);
}

SuperMapSpatialContextReader::~SuperMapSpatialContextReader()
{
}

FdoString* SuperMapSpatialContextReader::GetName ()
{
	TRACE(_T("调用 SuperMapSpatialContextReader::GetName():[%ls] 。\n"), m_context->GetName ());
    validate();
    return (m_context->GetName ());
	
}

FdoString* SuperMapSpatialContextReader::GetDescription()
{
	TRACE(_T("调用 SuperMapSpatialContextReader::GetDescription():[%ls] 。\n"), m_context->GetDescription ());
	validate();
	return (m_context->GetDescription());
}

FdoString* SuperMapSpatialContextReader::GetCoordinateSystem()
{
	TRACE(_T("调用 SuperMapSpatialContextReader::GetCoordinateSystem():[%ls] 。\n"), m_context->GetCoordSysName());
	validate();
	return (m_context->GetCoordSysName());
}

FdoString* SuperMapSpatialContextReader::GetCoordinateSystemWkt()
{
	TRACE(_T("调用 SuperMapSpatialContextReader::GetCoordinateSystemWkt():[%ls] 。\n"), m_context->GetCoordinateSystemWkt ());
	validate();
	return (m_context->GetCoordinateSystemWkt());
}

FdoSpatialContextExtentType SuperMapSpatialContextReader::GetExtentType ()
{
	TRACE(_T("调用 SuperMapSpatialContextReader::GetExtentType() 。\n"));
    validate ();
    return (m_context->GetExtentType ());
}

FdoByteArray* SuperMapSpatialContextReader::GetExtent ()
{
	TRACE(_T("调用 SuperMapSpatialContextReader::GetExtent() 。\n"));
    validate ();
    return (m_context->GetExtent ());
}

const double SuperMapSpatialContextReader::GetXYTolerance ()
{
	TRACE(_T("调用 SuperMapSpatialContextReader::GetXYTolerance():[%f]。\n"),m_context->GetXYTolerance ());
    validate ();
    return (m_context->GetXYTolerance ());
}

const double SuperMapSpatialContextReader::GetZTolerance ()
{
	TRACE(_T("调用 SuperMapSpatialContextReader::GetZTolerance():[%f] 。\n"),m_context->GetZTolerance ());
    validate ();
    return (m_context->GetZTolerance ());
}

const bool SuperMapSpatialContextReader::IsActive ()
{
	TRACE(_T("调用 SuperMapSpatialContextReader::IsActive() 。\n"));
    validate ();
    return (true); // only one context that's always active
}

bool SuperMapSpatialContextReader::ReadNext ()
{
	TRACE(_T("调用 SuperMapSpatialContextReader::ReadNext() 。\n"));
	bool rc = false;
	if ( m_curIndex < m_spatialContextColl->GetCount())
	{
		m_context = m_spatialContextColl->GetItem( m_curIndex++ );
		rc = true;
	}
    return ( rc );
}

void SuperMapSpatialContextReader::Dispose ()
{
	TRACE(_T("调用 SuperMapSpatialContextReader::Dispose() 。\n"));
    delete this;
}

void SuperMapSpatialContextReader::validate ()
{
    if (m_context.p == NULL)
        throw FdoException::Create (NlsMsgGet(SUPERMAP_READER_NOT_READY, "'%1$ls' reader not ready.", L"FdoISpatialContextReader"));
}
