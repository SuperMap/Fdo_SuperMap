/** \file	 SuperMapCreateSpatialContextCommand.cpp
*  \author	 周 旭
*  \attention 
*  Copyright &copy;  1996-2007 SuperMap GIS Technologies,Inc.<br>
*  All Rights Reserved
*  \version 1.0
*  \date 2007-10-30
*/

#include "SuperMap.h"

SuperMapCreateSpatialContextCommand::SuperMapCreateSpatialContextCommand()
: FdoCommonCommand<FdoICreateSpatialContext, SuperMapConnection>(NULL)
{
    m_Connection = (SuperMapConnection *)NULL;
    m_ExtentType = FdoSpatialContextExtentType_Static;
    m_Extent = NULL;
    m_XYTolerance = 0;
    m_ZTolerance = 0;
    m_UpdateExisting = false;
}

SuperMapCreateSpatialContextCommand::SuperMapCreateSpatialContextCommand(FdoIConnection *connection)
: FdoCommonCommand<FdoICreateSpatialContext, SuperMapConnection>(connection)
{
    m_Connection = (SuperMapConnection *)connection;
    m_ExtentType = FdoSpatialContextExtentType_Static;
    m_Extent = NULL;
    m_XYTolerance = 0;
    m_ZTolerance = 0;
    m_UpdateExisting = false;
}

SuperMapCreateSpatialContextCommand::~SuperMapCreateSpatialContextCommand()
{
}

FdoString* SuperMapCreateSpatialContextCommand::GetName()
{
    return m_SCName;
}

void SuperMapCreateSpatialContextCommand::SetName(FdoString* value)
{
    m_SCName = value;
}

FdoString* SuperMapCreateSpatialContextCommand::GetDescription()
{
    return m_Description;
}

void SuperMapCreateSpatialContextCommand::SetDescription(FdoString* value)
{
    m_Description = value;
}

FdoString* SuperMapCreateSpatialContextCommand::GetCoordinateSystem()
{
    return m_CoordSysName;
}

void SuperMapCreateSpatialContextCommand::SetCoordinateSystem(FdoString* value)
{
    m_CoordSysName = value;
}

FdoString* SuperMapCreateSpatialContextCommand::GetCoordinateSystemWkt()
{
    return m_CoordSysWkt;
}

void SuperMapCreateSpatialContextCommand::SetCoordinateSystemWkt(FdoString* value)
{
    m_CoordSysWkt = value;
}

FdoSpatialContextExtentType SuperMapCreateSpatialContextCommand::GetExtentType()
{
    return m_ExtentType;
}

void SuperMapCreateSpatialContextCommand::SetExtentType(FdoSpatialContextExtentType value)
{
    m_ExtentType = value;
}

FdoByteArray* SuperMapCreateSpatialContextCommand::GetExtent()
{
    return FDO_SAFE_ADDREF( m_Extent.p );
}

void SuperMapCreateSpatialContextCommand::SetExtent(FdoByteArray* value)
{
    m_Extent = FDO_SAFE_ADDREF( value );
}

const double SuperMapCreateSpatialContextCommand::GetXYTolerance()
{
    return m_XYTolerance;
}

void SuperMapCreateSpatialContextCommand::SetXYTolerance(double value)
{
    m_XYTolerance = value;
}

const double SuperMapCreateSpatialContextCommand::GetZTolerance()
{
    return m_ZTolerance;
}

void SuperMapCreateSpatialContextCommand::SetZTolerance(const double value)
{
    m_ZTolerance = value;
}

const bool SuperMapCreateSpatialContextCommand::GetUpdateExisting()
{
    return m_UpdateExisting;
}

void SuperMapCreateSpatialContextCommand::SetUpdateExisting(const bool value)
{
    m_UpdateExisting = value;
}

void SuperMapCreateSpatialContextCommand::Execute()
{
	TRACE(_T("调用 SuperMapCreateSpatialContextCommand::Execute.\n"));

	// 忽略从WKT以外的所有设置，从WKT串中分解有用的信息
	if(m_CoordSysWkt == L"")
	{
		throw FdoException::Create(NlsMsgGet(SUPERMAP_SPATIALCONTEXT_EMPTYWKT, "WKT cannot be empty."));
	}
	
	FdoStringP right;
	FdoStringP csName;

	// 解析WKT串，忽略空格
	if(m_CoordSysWkt.Contains(L"PROJCS"))
	{
		right = m_CoordSysWkt.Right(L"PROJCS");
	}
	else if(m_CoordSysWkt.Contains(L"GEOGCS"))
	{
		right = m_CoordSysWkt.Right(L"GEOGCS");
	}
	else if(m_CoordSysWkt.Contains(L"LOCAL_CS"))
	{
		right = m_CoordSysWkt.Right(L"LOCAL_CS");
	}
	
	if(right != L"")
	{
		FdoStringP right2 = right.Right(L"[");
		FdoStringP right3 = right2.Right(L"\"");
		csName = right3.Left(L"\"");
	}
	
	if(csName == L"")
	{
		throw FdoException::Create(NlsMsgGet(SUPERMAP_SPATIALCONTEXT_INVALIDWKT, 
			"Invalid WKT. Cannot extract coordinate system name."));
	}

	// 检查从WKT解析出的坐标系名称是否与传入的相同
	if(m_SCName != L"" && m_SCName != csName)
	{
		throw FdoException::Create(NlsMsgGet(SUPERMAP_SPATIALCONTEXT_CONFLICTINGWKT,
			"Spatial Context name conflicts with the coordinate system name in WKT."));
	}

	//m_CoordSysName = csName;
	//m_SCName = m_CoordSysName;   // 投影坐标系这两个名称不一定相同

    m_Connection->CreateSpatialContext(
        m_SCName, m_Description,
        m_CoordSysName, m_CoordSysWkt,
        m_ExtentType, m_Extent,
        m_XYTolerance, m_ZTolerance,
		false );

}