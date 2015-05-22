/** \file	 SuperMapInsertReader.h
*  \author	 马俊
*  \attention 
*  Copyright &copy;  1996-2007 SuperMap GIS Technologies,Inc.<br>
*  All Rights Reserved
*  \version 1.0
*  \date 2007-11-07
*/

//本类的注释和SuperMapFeatureReader.h完全一样,只是取数据的来源不一样

#ifndef __SUPERMAP_INSERTREADER_H__
#define __SUPERMAP_INSERTREADER_H__
#ifdef _WIN32
#pragma once
#endif // _WIN32

class SuperMapInsertReader :public FdoIFeatureReader
{

public:
	SuperMapInsertReader( FdoPropertyValueCollection * FeatureValues,FdoClassDefinition* ClassDef );

public:
	SuperMapInsertReader(void);

public:
	virtual ~SuperMapInsertReader(void);
	virtual void Dispose();

public:
	virtual FdoClassDefinition* GetClassDefinition();
	virtual int GetDepth();
	virtual bool     GetBoolean( const FdoString *identifier );
	virtual FdoByte  GetByte( const FdoString *identifier );
	virtual double   GetDouble(const FdoString* identifier);
	virtual short    GetInt16( const FdoString *identifier );
	virtual int      GetInt32( const FdoString *identifier );
	virtual FdoInt64 GetInt64( const FdoString *identifier );
	virtual float    GetSingle( const FdoString *identifier );
	virtual const wchar_t* GetString( const FdoString *identifier );
	virtual FdoLOBValue* GetLOB(const FdoString* identifier );
	virtual FdoIStreamReader* GetLOBStreamReader(const FdoString* identifier );
	virtual bool     IsNull( const FdoString *identifier );
	virtual FdoIFeatureReader* GetFeatureObject(const FdoString* identifier);
	virtual FdoByteArray* GetGeometry(const FdoString* identifier);
	virtual const FdoByte * GetGeometry(const FdoString* identifier, FdoInt32 * count);
	virtual FdoIRaster* GetRaster(const FdoString* identifier);
	virtual bool     ReadNext( );
	virtual void     Close();
	virtual FdoDateTime GetDateTime(const FdoString *identifier );

protected:
  FdoPtr<FdoPropertyValueCollection> m_FeatureValues;
  FdoPtr<FdoClassDefinition> m_ClassDef;
  bool m_IsFirstReadNext;
};

#endif // __SUPERMAP_INSERTREADER_H__