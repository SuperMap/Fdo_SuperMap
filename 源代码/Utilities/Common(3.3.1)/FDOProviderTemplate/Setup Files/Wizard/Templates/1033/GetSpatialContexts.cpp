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
#include "[!output PREFIX]GetSpatialContexts.h"
#include "[!output PREFIX]SpatialContextReader.h"


[!output PREFIX]GetSpatialContexts::[!output PREFIX]GetSpatialContexts() :
    FdoCommonCommand<FdoIGetSpatialContexts, [!output PREFIX]Connection>(NULL),
    m_bActiveOnly(false)
{
}

[!output PREFIX]GetSpatialContexts::[!output PREFIX]GetSpatialContexts(FdoIConnection *connection) :
    FdoCommonCommand<FdoIGetSpatialContexts, [!output PREFIX]Connection>(connection),
    m_bActiveOnly(false)
{
}

[!output PREFIX]GetSpatialContexts::~[!output PREFIX]GetSpatialContexts(void)
{
}

const bool [!output PREFIX]GetSpatialContexts::GetActiveOnly()
{
    return m_bActiveOnly;
}

void [!output PREFIX]GetSpatialContexts::SetActiveOnly(const bool value)
{
    m_bActiveOnly = value;
}

FdoISpatialContextReader* [!output PREFIX]GetSpatialContexts::Execute()
{
#pragma message ("ToDo: get spatial context")
    return (new [!output PREFIX]SpatialContextReader ());
}

