#ifndef MYSQLOVSTORAGEENGINETYPE_H
#define MYSQLOVSTORAGEENGINETYPE_H

//
//
// Copyright (C) 2004-2006  Autodesk, Inc.
// 
// This library is free software; you can redistribute it and/or
// modify it under the terms of version 2.1 of the GNU Lesser
// General Public License as published by the Free Software Foundation.
// 
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
//
#include <Rdbms/Override/MySQL/MySqlOv.h>

/// \brief
/// Enumerated type representing the possible storage engine types for MySQL tables
/// <param name="MySQLOvStorageEngineType_MyISAM">
/// The binary portable storage engine that is the improved replacement for ISAM
/// </param>
/// <param name="MySQLOvStorageEngineType_ISAM">
/// The original MySQL storage engine
/// </param>
/// <param name="MySQLOvStorageEngineType_InnoDB">
/// Transaction-safe tables with row locking and foreign keys
/// </param>
/// <param name="MySQLOvStorageEngineType_BDB">
/// BerkeleyDB; Transaction-safe tables with page locking
/// </param>
/// <param name="MySQLOvStorageEngineType_Merge">
/// A collection of MyISAM tables used as one table
/// </param>
/// <param name="MySQLOvStorageEngineType_Memory">
/// The data for this table is stored only in memory.  Also known as the Heap storage engine
/// </param>
/// <param name="MySQLOvStorageEngineType_Federated">
/// Storage engine that accesses remote tables
/// </param>
/// <param name="MySQLOvStorageEngineType_Archive">
/// The archiving storage engine
/// </param>
/// <param name="MySQLOvStorageEngineType_CSV">
/// Tables that store rows in comma-separated values format
/// </param>
/// <param name="MySQLOvStorageEngineType_Example">
/// An example engine
/// </param>
/// <param name="MySQLOvStorageEngineType_NDBClustered">
/// Clustered, fault-tolerant, memory-based tables
/// </param>
/// <param name="MySQLOvStorageEngineType_Unknown">
/// The storage engine is unknown
/// </param>
/// <param name="MySQLOvStorageEngineType_Default">
/// The storage engine override is inherited from somewhere else.
/// </param>
enum MySQLOvStorageEngineType
{
    MySQLOvStorageEngineType_MyISAM,
    MySQLOvStorageEngineType_ISAM,
    MySQLOvStorageEngineType_InnoDB,
    MySQLOvStorageEngineType_BDB,
    MySQLOvStorageEngineType_Merge,
    MySQLOvStorageEngineType_Memory,
    MySQLOvStorageEngineType_Federated,
    MySQLOvStorageEngineType_Archive,
    MySQLOvStorageEngineType_CSV,
    MySQLOvStorageEngineType_Example,
    MySQLOvStorageEngineType_NDBClustered,
    MySQLOvStorageEngineType_Unknown,
    MySQLOvStorageEngineType_Default
};

/// \brief
/// XML string constants corresponding to the enumerated type MySQLOvStorageEngineType.
namespace FdoMySQLOverrides
{
    static const FdoString* StorageEngineType_MyISAM       = L"MyISAM";
    static const FdoString* StorageEngineType_ISAM         = L"ISAM";
    static const FdoString* StorageEngineType_InnoDB       = L"InnoDB";
    static const FdoString* StorageEngineType_BDB          = L"BDB";
    static const FdoString* StorageEngineType_Merge        = L"Merge";
    static const FdoString* StorageEngineType_Memory       = L"Memory";
    static const FdoString* StorageEngineType_Federated    = L"Federated";
    static const FdoString* StorageEngineType_Archive      = L"Archive";
    static const FdoString* StorageEngineType_CSV          = L"CSV";
    static const FdoString* StorageEngineType_Example      = L"Example";
    static const FdoString* StorageEngineType_NDBClustered = L"NDBClustered";
    static const FdoString* StorageEngineType_Unknown      = L"Unknown";
    static const FdoString* StorageEngineType_Default      = L"Default";
}

static MySQLOvStorageEngineType StorageEngine_StringToEnum(FdoString* storageEngineTypeString, FdoXmlSaxContext* pContext = NULL)
{
    MySQLOvStorageEngineType ret;

    if (0==wcscmp(storageEngineTypeString, FdoMySQLOverrides::StorageEngineType_MyISAM))
        ret = MySQLOvStorageEngineType_MyISAM;
    else if (0==wcscmp(storageEngineTypeString, FdoMySQLOverrides::StorageEngineType_ISAM))
        ret = MySQLOvStorageEngineType_ISAM;
    else if (0==wcscmp(storageEngineTypeString, FdoMySQLOverrides::StorageEngineType_InnoDB))
        ret = MySQLOvStorageEngineType_InnoDB;
    else if (0==wcscmp(storageEngineTypeString, FdoMySQLOverrides::StorageEngineType_BDB))
        ret = MySQLOvStorageEngineType_BDB;
    else if (0==wcscmp(storageEngineTypeString, FdoMySQLOverrides::StorageEngineType_Merge))
        ret = MySQLOvStorageEngineType_Merge;
    else if (0==wcscmp(storageEngineTypeString, FdoMySQLOverrides::StorageEngineType_Memory))
        ret = MySQLOvStorageEngineType_Memory;
    else if (0==wcscmp(storageEngineTypeString, FdoMySQLOverrides::StorageEngineType_Federated))
        ret = MySQLOvStorageEngineType_Federated;
    else if (0==wcscmp(storageEngineTypeString, FdoMySQLOverrides::StorageEngineType_Archive))
        ret = MySQLOvStorageEngineType_Archive;
    else if (0==wcscmp(storageEngineTypeString, FdoMySQLOverrides::StorageEngineType_CSV))
        ret = MySQLOvStorageEngineType_CSV;
    else if (0==wcscmp(storageEngineTypeString, FdoMySQLOverrides::StorageEngineType_Example))
        ret = MySQLOvStorageEngineType_Example;
    else if (0==wcscmp(storageEngineTypeString, FdoMySQLOverrides::StorageEngineType_NDBClustered))
        ret = MySQLOvStorageEngineType_NDBClustered;
    else if (0==wcscmp(storageEngineTypeString, FdoMySQLOverrides::StorageEngineType_Unknown))
        ret = MySQLOvStorageEngineType_Unknown;
    else if (0==wcscmp(storageEngineTypeString, FdoMySQLOverrides::StorageEngineType_Default))
        ret = MySQLOvStorageEngineType_Default;
    else
    {
        ret = MySQLOvStorageEngineType_Default;
		if (pContext != NULL)
		{
	        FdoPtr<FdoException> e = FdoException::Create(L"TODO");
	        pContext->AddError(e);
		}
    }

    return ret;
}

static FdoString* StorageEngine_EnumToString(MySQLOvStorageEngineType storageEngineTypeEnum)
{
    if (storageEngineTypeEnum == MySQLOvStorageEngineType_MyISAM)
        return FdoMySQLOverrides::StorageEngineType_MyISAM;
    else if (storageEngineTypeEnum == MySQLOvStorageEngineType_ISAM)
        return FdoMySQLOverrides::StorageEngineType_ISAM;
    else if (storageEngineTypeEnum == MySQLOvStorageEngineType_InnoDB)
        return FdoMySQLOverrides::StorageEngineType_InnoDB;
    else if (storageEngineTypeEnum == MySQLOvStorageEngineType_BDB)
        return FdoMySQLOverrides::StorageEngineType_BDB;
    else if (storageEngineTypeEnum == MySQLOvStorageEngineType_Merge)
        return FdoMySQLOverrides::StorageEngineType_Merge;
    else if (storageEngineTypeEnum == MySQLOvStorageEngineType_Memory)
        return FdoMySQLOverrides::StorageEngineType_Memory;
    else if (storageEngineTypeEnum == MySQLOvStorageEngineType_Federated)
        return FdoMySQLOverrides::StorageEngineType_Federated;
    else if (storageEngineTypeEnum == MySQLOvStorageEngineType_Archive)
        return FdoMySQLOverrides::StorageEngineType_Archive;
    else if (storageEngineTypeEnum == MySQLOvStorageEngineType_CSV)
        return FdoMySQLOverrides::StorageEngineType_CSV;
    else if (storageEngineTypeEnum == MySQLOvStorageEngineType_Example)
        return FdoMySQLOverrides::StorageEngineType_Example;
    else if (storageEngineTypeEnum == MySQLOvStorageEngineType_NDBClustered)
        return FdoMySQLOverrides::StorageEngineType_NDBClustered;
    else if (storageEngineTypeEnum == MySQLOvStorageEngineType_Unknown)
        return FdoMySQLOverrides::StorageEngineType_Unknown;
    else if (storageEngineTypeEnum == MySQLOvStorageEngineType_Default)
        return FdoMySQLOverrides::StorageEngineType_Default;
    else
        throw FdoException::Create(L"TODO");
}


#endif  // MYSQLOVSTORAGEENGINETYPE_H


