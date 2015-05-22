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

#ifndef __SUPERMAP_TRANSACTION_H__
#define __SUPERMAP_TRANSACTION_H__
#ifdef _WIN32
#pragma once
#endif // _WIN32

class SuperMapTransaction : public FdoITransaction
{
    friend class SuperMapConnection;

protected:
    SuperMapConnection* m_pConnection; // can't use FdoPtr<> because of circular reference
    bool m_bSpent; // goes true when commit or rollback done

public:
    SuperMapTransaction ();
    virtual ~SuperMapTransaction(void);

    /// <summary> Gets the FdoIConnection object associated with the transaction.</summary>
    /// <returns>Returns FdoIConnection object</returns>
    FdoIConnection* GetConnection ();

    /// <summary> Commits the transaction.</summary>
    /// <returns>Returns nothing</returns>
    void Commit ();

    /// <summary> Rolls back a transaction from a pending state.</summary>
    /// <returns>Returns nothing</returns>
    void Rollback ();

    void Dispose ();

protected:
    void SetConnection (SuperMapConnection* pConnection);
    bool IsSpent ();

};

#endif // __SUPERMAP_TRANSACTION_H__

