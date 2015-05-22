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
#include "[!output PREFIX]CreateSpatialContext.h"


[!output PREFIX]CreateSpatialContext::[!output PREFIX]CreateSpatialContext([!output PREFIX]Connection *connection) :
    FdoCommonCommand<FdoICreateSpatialContext, [!output PREFIX]Connection>(connection),
    m_bUpdateExisting(false),
    m_bDescriptionSet(false),
    m_bCoordinateSystemSet(false),
	m_bCoordinateSystemWktSet(false),
    m_bExtentTypeSet(false),
    m_eExtentType(FdoSpatialContextExtentType_Static),
    m_bExtentSet(false),
    m_bXYToleranceSet(false),
    m_bZToleranceSet(false),
    m_dZTolerance(0.001)
{
}

[!output PREFIX]CreateSpatialContext::~[!output PREFIX]CreateSpatialContext(void)
{
}

FdoString* [!output PREFIX]CreateSpatialContext::GetName()
{
    return m_wcsName;
}

void [!output PREFIX]CreateSpatialContext::SetName(FdoString* value)
{
    m_wcsName = value;
}

FdoString* [!output PREFIX]CreateSpatialContext::GetDescription()
{
    return m_wcsDescription;
}

void [!output PREFIX]CreateSpatialContext::SetDescription(FdoString* value)
{
    m_wcsDescription = value;
    m_bDescriptionSet = true;
}

FdoString* [!output PREFIX]CreateSpatialContext::GetCoordinateSystem()
{
    return m_wcsCoordSys;
}

void [!output PREFIX]CreateSpatialContext::SetCoordinateSystem(FdoString* value)
{
    m_wcsCoordSys = value;
    m_bCoordinateSystemSet = true;
}

FdoSpatialContextExtentType [!output PREFIX]CreateSpatialContext::GetExtentType()
{
    return m_eExtentType;
}

void [!output PREFIX]CreateSpatialContext::SetExtentType(FdoSpatialContextExtentType value)
{
    m_eExtentType = value;
    m_bExtentTypeSet = true;
}

FdoByteArray* [!output PREFIX]CreateSpatialContext::GetExtent()
{
    return FDO_SAFE_ADDREF(m_Extent.p);
}

void [!output PREFIX]CreateSpatialContext::SetExtent(FdoByteArray* value)
{
    m_Extent = FDO_SAFE_ADDREF(value);
    m_bExtentSet = true;
}

const double [!output PREFIX]CreateSpatialContext::GetXYTolerance()
{
    return m_dXYTolerance;
}

void [!output PREFIX]CreateSpatialContext::SetXYTolerance(const double value)
{
    m_dXYTolerance = value;
    m_bXYToleranceSet = true;
}

const double [!output PREFIX]CreateSpatialContext::GetZTolerance()
{
    return m_dZTolerance;
}

void [!output PREFIX]CreateSpatialContext::SetZTolerance(const double value)
{
    m_dZTolerance = value;
    m_bZToleranceSet = true;
}

const bool [!output PREFIX]CreateSpatialContext::GetUpdateExisting()
{
    return m_bUpdateExisting;
}

void [!output PREFIX]CreateSpatialContext::SetUpdateExisting(const bool value)
{
    m_bUpdateExisting = value;
}

void [!output PREFIX]CreateSpatialContext::Execute()
{
#pragma message ("ToDo: create spatial context")
}

FdoString* [!output PREFIX]CreateSpatialContext::GetCoordinateSystemWkt()
{
	return m_wcsCoordSysWkt;
}

void [!output PREFIX]CreateSpatialContext::SetCoordinateSystemWkt(FdoString* value)
{
	m_wcsCoordSysWkt = value;
	m_bCoordinateSystemWktSet = true;
}
