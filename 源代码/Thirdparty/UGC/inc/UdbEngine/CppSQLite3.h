////////////////////////////////////////////////////////////////////////////////
// CppSQLite3 - A C++ wrapper around the SQLite3 embedded database library.
//
// Copyright (c) 2004 Rob Groves. All Rights Reserved. rob.groves@btinternet.com
// 
// Permission to use, copy, modify, and distribute this software and its
// documentation for any purpose, without fee, and without a written
// agreement, is hereby granted, provided that the above copyright notice, 
// this paragraph and the following two paragraphs appear in all copies, 
// modifications, and distributions.
//
// IN NO EVENT SHALL THE AUTHOR BE LIABLE TO ANY PARTY FOR DIRECT,
// INDIRECT, SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES, INCLUDING LOST
// PROFITS, ARISING OUT OF THE USE OF THIS SOFTWARE AND ITS DOCUMENTATION,
// EVEN IF THE AUTHOR HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// THE AUTHOR SPECIFICALLY DISCLAIMS ANY WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
// PARTICULAR PURPOSE. THE SOFTWARE AND ACCOMPANYING DOCUMENTATION, IF
// ANY, PROVIDED HEREUNDER IS PROVIDED "AS IS". THE AUTHOR HAS NO OBLIGATION
// TO PROVIDE MAINTENANCE, SUPPORT, UPDATES, ENHANCEMENTS, OR MODIFICATIONS.
//
// V3.0		03/08/2004	-Initial Version for sqlite3
//
// V3.1		16/09/2004	-Implemented getXXXXField using sqlite3 functions
//						-Added CppSQLiteDB3::tableExists()
////////////////////////////////////////////////////////////////////////////////
// SQLite Storage Classes
// 
// INTEGER Integer values are whole numbers (positive and negative). They can
//		vary in size: 1, 2, 3, 4, 6, or 8 bytes. The maximum integer range (8 bytes) is
//		{-9223372036854775808,-1,0,1, -9223372036854775807}. SQLite automatically
//		handles the integer sizes based on the numeric value.
// REAL Real values are real numbers with decimal values. SQLite uses 8-byte floats to store
//		real numbers.
// TEXT Text is character data. SQLite supports various character encodings, which include
//		UTF-8 and UTF-16 (big and little endian). The maximum string value in SQLite
//		is unlimited.
// BLOB Binary large object (BLOB) data is any kind of data. The maximum size for BLOBs in
// 		SQLite is unlimited.
// NULL NULL values represent missing information. SQLite has full support for NULL values.
//////////////////////////////////////////////////////////////////////////
#ifndef _CppSQLite3_H_
#define _CppSQLite3_H_

#include "sqlite3.h"
#include "Base/ugdefs.h"

namespace UGC {

#define CPPSQLITE_ERROR 1000

class UDBENGINE_API CppSQLite3Exception
{
public:

    CppSQLite3Exception(const UGint nErrCode,
                    UGchar* szErrMess,
                    UGbool bDeleteMsg=TRUE);

    CppSQLite3Exception(const CppSQLite3Exception&  e);

    virtual ~CppSQLite3Exception();

    const UGint errorCode() { return mnErrCode; }

    const UGchar* errorMessage() { return mpszErrMess; }

    static const UGchar* errorCodeAsString(UGint nErrCode);

private:

    UGint mnErrCode;
    UGchar* mpszErrMess;
};


class UDBENGINE_API CppSQLite3Buffer
{
public:

    CppSQLite3Buffer();

    ~CppSQLite3Buffer();

    const UGchar* format(const UGchar* szFormat, ...);

    operator const UGchar*() { return mpBuf; }

    void clear();

private:

    UGchar* mpBuf;
};


class UDBENGINE_API CppSQLite3Binary
{
public:

    CppSQLite3Binary();

    ~CppSQLite3Binary();

    void setBinary(const UGuchar* pBuf, UGint nLen);
    void setEncoded(const UGuchar* pBuf);

    const UGuchar* getEncoded();
    const UGuchar* getBinary();

    UGint getBinaryLength();

    UGuchar* allocBuffer(int nLen);

    void clear();

private:

    UGuchar* mpBuf;
    UGint mnBinaryLen;
    UGint mnBufferLen;
    UGint mnEncodedLen;
    UGbool mbEncoded;
};


class UDBENGINE_API CppSQLite3Query
{
public:

    CppSQLite3Query();

    CppSQLite3Query(const CppSQLite3Query& rQuery);

    CppSQLite3Query(sqlite3* pDB,
				sqlite3_stmt* pVM,
                UGbool bEof,
                UGbool bOwnVM=TRUE);

    CppSQLite3Query& operator=(const CppSQLite3Query& rQuery);

    virtual ~CppSQLite3Query();

    UGint numFields();

    UGint fieldIndex(const char* szField);
    const UGchar* fieldName(UGint nCol);

    const UGchar* fieldDeclType(UGint nCol);
    int fieldDataType(UGint nCol);

    const UGchar* fieldValue(UGint nField);
    const UGchar* fieldValue(const UGchar* szField);

    UGint getIntField(UGint nField, UGint nNullValue=0);
    UGint getIntField(const UGchar* szField, UGint nNullValue=0);

    UGdouble getFloatField(UGint nField, UGdouble fNullValue=0.0);
    UGdouble getFloatField(const UGchar* szField, UGdouble fNullValue=0.0);

    const UGchar* getStringField(UGint nField, const UGchar* szNullValue="");
    const UGchar* getStringField(const UGchar* szField, const UGchar* szNullValue="");

    const UGuchar* getBlobField(UGint nField, UGint& nLen);
    const UGuchar* getBlobField(const UGchar* szField, UGint& nLen);

    UGbool fieldIsNull(UGint nField);
    UGbool fieldIsNull(const UGchar* szField);

    UGbool eof();

    void nextRow();

    void finalize();

private:

    void checkVM();

	sqlite3* mpDB;
    sqlite3_stmt* mpVM;
    UGbool mbEof;
    UGint mnCols;
    UGbool mbOwnVM;
};


class UDBENGINE_API CppSQLite3Table
{
public:

    CppSQLite3Table();

    CppSQLite3Table(const CppSQLite3Table& rTable);

    CppSQLite3Table(UGchar** paszResults, UGint nRows, UGint nCols);

    virtual ~CppSQLite3Table();

    CppSQLite3Table& operator=(const CppSQLite3Table& rTable);

    UGint numFields();

    UGint numRows();

    const UGchar* fieldName(UGint nCol);

    const UGchar* fieldValue(UGint nField);
    const UGchar* fieldValue(const UGchar* szField);

    UGint getIntField(UGint nField, UGint nNullValue=0);
    UGint getIntField(const UGchar* szField, UGint nNullValue=0);

    UGdouble getFloatField(UGint nField, UGdouble fNullValue=0.0);
    UGdouble getFloatField(const UGchar* szField, UGdouble fNullValue=0.0);

    const UGchar* getStringField(UGint nField, const UGchar* szNullValue="");
    const UGchar* getStringField(const UGchar* szField, const UGchar* szNullValue="");

    UGbool fieldIsNull(UGint nField);
    UGbool fieldIsNull(const UGchar* szField);

    void setRow(UGint nRow);

    void finalize();

private:

    void checkResults();

    UGint mnCols;
    UGint mnRows;
    UGint mnCurrentRow;
    UGchar** mpaszResults;
};


class UDBENGINE_API CppSQLite3Statement
{
public:

    CppSQLite3Statement();

    CppSQLite3Statement(const CppSQLite3Statement& rStatement);

    CppSQLite3Statement(sqlite3* pDB, sqlite3_stmt* pVM);

    virtual ~CppSQLite3Statement();

    CppSQLite3Statement& operator=(const CppSQLite3Statement& rStatement);

    UGint execDML();

	UGint execDML(sqlite_int64 &nID);

    CppSQLite3Query execQuery();

    void bind(UGint nParam, const UGchar* szValue);
    void bind(UGint nParam, const UGint nValue);
    void bind(UGint nParam, const UGdouble dwValue);
    void bind(UGint nParam, const UGuchar* blobValue, UGint nLen);
    void bindNull(int nParam);

    void reset();

    void finalize();

private:

    void checkDB();
    void checkVM();

    sqlite3* mpDB;
    sqlite3_stmt* mpVM;
};


class UDBENGINE_API CppSQLite3DB
{
public:

    CppSQLite3DB();

    virtual ~CppSQLite3DB();

    UGbool open(const UGchar* szFile);

    void close();

	UGbool tableExists(const UGchar* szTable);

    UGint execDML(const UGchar* szSQL);

	UGint execDML(const UGchar* szSQL,sqlite_int64 &nReturnID);

    CppSQLite3Query execQuery(const UGchar* szSQL);

    UGint execScalar(const UGchar* szSQL);

    CppSQLite3Table getTable(const UGchar* szSQL);

    CppSQLite3Statement compileStatement(const UGchar* szSQL);

    sqlite_int64 lastRowId();

    void interrupt() { sqlite3_interrupt(mpDB); }

    void setBusyTimeout(UGint nMillisecs);

    static const UGchar* SQLiteVersion() { return SQLITE_VERSION; }

private:

    CppSQLite3DB(const CppSQLite3DB& db);
    CppSQLite3DB& operator=(const CppSQLite3DB& db);

    sqlite3_stmt* compile(const UGchar* szSQL);

    void checkDB();

    sqlite3* mpDB;
    UGint mnBusyTimeoutMs;
};
}

#endif
