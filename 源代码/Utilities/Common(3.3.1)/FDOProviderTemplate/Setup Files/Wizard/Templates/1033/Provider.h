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

#ifndef [!output UPPER_PREFIX]PROVIDER_H
#define [!output UPPER_PREFIX]PROVIDER_H

// General descriptive items of [!output PREFIX] Provier:
#define [!output PREFIX]ProviderName L"Autodesk.[!output PREFIX].3.3"
#define [!output PREFIX]ProviderDisplayName L"OSGeo FDO Provider for [!output PREFIX]"
#define [!output PREFIX]ProviderDescription L"OSGeo FDO Provider for [!output PREFIX]"
#define [!output PREFIX]ProviderVersion L"3.3.0.0"
#define FeatureDataObjectsVersion L"3.3.0.0"

// Connection property strings:
const wchar_t CONNECTIONPROPERTY_DATASTORE[] = L"Datastore";
// ToDo: add more connection properties here
const wchar_t CONNECTIONPROPERTY_DELIMITER[] = L";";
const wchar_t CONNECTIONPROPERTY_SEPARATOR[] = L"=";

#include <[!output PREFIX]Connection.h>

#endif // [!output UPPER_PREFIX]PROVIDER_H

