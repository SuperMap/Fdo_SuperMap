/** \file	 SuperMapInsertReader.cpp
*  \author	 马俊
*  \attention 
*  Copyright &copy;  1996-2007 SuperMap GIS Technologies,Inc.<br>
*  All Rights Reserved
*  \version 1.0
*  \date 2007-11-07
*/

//本类的注释和SuperMapFeatureReader.cpp完全一样,只是取数据的来源不一样
#include "SuperMap.h"

SuperMapInsertReader::SuperMapInsertReader(void)
{
	
}

SuperMapInsertReader::~SuperMapInsertReader(void)
{
	TRACE(_T("SuperMapInsertReader::析构... \n"));
}

SuperMapInsertReader::SuperMapInsertReader( FdoPropertyValueCollection * FeatureValues,FdoClassDefinition* ClassDef )
{
	TRACE(_T("SuperMapInsertReader::构造... \n"));
	m_FeatureValues = FeatureValues;
	m_IsFirstReadNext = true;
	m_ClassDef = ClassDef;
}

void SuperMapInsertReader::Dispose()
{
    delete this;
}

FdoClassDefinition* SuperMapInsertReader::GetClassDefinition()
{
	if(!m_ClassDef)
    {
		return NULL;
    }   
    return FDO_SAFE_ADDREF(m_ClassDef.p);
}

int SuperMapInsertReader::GetDepth()
{
    return 0; //not support nest now
}

FdoLOBValue* SuperMapInsertReader::GetLOB(const FdoString* identifier )
{
	return NULL; //not support nest now
}

FdoIStreamReader* SuperMapInsertReader::GetLOBStreamReader(const FdoString* identifier )
{
	return NULL; //not support nest now
}

FdoIFeatureReader* SuperMapInsertReader::GetFeatureObject( const FdoString* identifier )
{
	return NULL; //not support nest now
}

bool SuperMapInsertReader::GetBoolean( const FdoString *identifier )
{
	TRACE(_T("SuperMapInsertReader::GetBoolean()... \n"));
	//return (GetInt32( identifier ) != 0 );
	FdoPtr<FdoPropertyValue> propvalue = NULL;

	if( m_IsFirstReadNext || m_FeatureValues == NULL )
	{
		throw FdoCommandException::Create( L"SuperMapInsertReader::GetBoolean End of recordset!" );
	}
	try
	{
		propvalue =  m_FeatureValues->GetItem( identifier );
		if( propvalue == NULL )
		{
			throw FdoCommandException::Create( L"SuperMapInsertReader::GetBoolean Property not found!" );
		}
	}
	catch ( FdoException * e)
	{
		FDO_SAFE_RELEASE(e);
		throw FdoCommandException::Create( L"SuperMapInsertReader::GetBoolean Property not found!" );
	}
	FdoPtr<FdoValueExpression> val = propvalue->GetValue();
	FdoDataValue* dataval = (dynamic_cast<FdoDataValue*>(val.p));

	if( !dataval || dataval->GetDataType() != FdoDataType_Boolean )
	{
		throw FdoCommandException::Create( L"SuperMapInsertReader::GetBoolean DataType not FdoDataType_Double!" );
	}

	FdoBooleanValue  *dval = (static_cast<FdoBooleanValue*>(dataval)); 
	return dval->GetBoolean();
}

FdoByte SuperMapInsertReader::GetByte( const FdoString *identifier )
{
	TRACE(_T("SuperMapInsertReader::GetByte()... \n"));
	//return (FdoByte)GetInt32( identifier );
	FdoPtr<FdoPropertyValue> propvalue = NULL;

	if( m_IsFirstReadNext || m_FeatureValues == NULL )
	{
		throw FdoCommandException::Create( L"SuperMapInsertReader::GetBoolean End of recordset!" );
	}
	try
	{
		propvalue =  m_FeatureValues->GetItem( identifier );
		if( propvalue == NULL )
		{
			throw FdoCommandException::Create( L"SuperMapInsertReader::GetBoolean Property not found!" );
		}
	}
	catch ( FdoException * e)
	{
		FDO_SAFE_RELEASE(e);
		throw FdoCommandException::Create( L"SuperMapInsertReader::GetBoolean Property not found!" );
	}
	FdoPtr<FdoValueExpression> val = propvalue->GetValue();
	FdoDataValue* dataval = (dynamic_cast<FdoDataValue*>(val.p));

	if( !dataval || dataval->GetDataType() != FdoDataType_Byte )
	{
		throw FdoCommandException::Create( L"SuperMapInsertReader::GetBoolean DataType not FdoDataType_Double!" );
	}

	FdoByteValue  *dval = (static_cast<FdoByteValue*>(dataval)); 
	return dval->GetByte();
}


FdoDateTime SuperMapInsertReader::GetDateTime( const FdoString *identifier )
{
	TRACE(_T("SuperMapInsertReader::GetDateTime()... \n"));
	FdoPtr<FdoPropertyValue> propvalue = NULL;

	if( m_IsFirstReadNext || m_FeatureValues == NULL )
	{
		throw FdoCommandException::Create( L"SuperMapInsertReader::GetDateTime End of recordset!" );
	}
	try
	{
	  propvalue =  m_FeatureValues->GetItem( identifier );
	  if( propvalue == NULL )
	  {
		  throw FdoCommandException::Create( L"SuperMapInsertReader::GetDateTime Property not found!" );
	  }
	}
	catch ( FdoException * e)
	{
		FDO_SAFE_RELEASE(e);
		throw FdoCommandException::Create( L"SuperMapInsertReader::GetDateTime Property not found!" );
	}
	FdoPtr<FdoValueExpression> val = propvalue->GetValue();
	FdoDataValue* dataval = (dynamic_cast<FdoDataValue*>(val.p));

	if( !dataval || dataval->GetDataType() != FdoDataType_DateTime)
	{
		throw FdoCommandException::Create( L"SuperMapInsertReader::GetDateTime DataType not FdoDataType_DateTime!" );
	}

	FdoDateTimeValue *dval = (static_cast<FdoDateTimeValue*>(dataval));
	return dval->GetDateTime();
}


double SuperMapInsertReader::GetDouble( const FdoString *identifier )
{
	TRACE(_T("SuperMapInsertReader::GetDouble()... \n"));
   FdoPtr<FdoPropertyValue> propvalue = NULL;

  if( m_IsFirstReadNext || m_FeatureValues == NULL )
  {
      throw FdoCommandException::Create( L"SuperMapInsertReader::GetDouble End of recordset!" );
  }
  try
  {
      propvalue =  m_FeatureValues->GetItem( identifier );
      if( propvalue == NULL )
	  {
          throw FdoCommandException::Create( L"SuperMapInsertReader::GetDouble Property not found!" );
	  }
  }
  catch ( FdoException * e)
  {
	  FDO_SAFE_RELEASE(e);
	  throw FdoCommandException::Create( L"SuperMapInsertReader::GetDouble Property not found!" );
  }
  FdoPtr<FdoValueExpression> val = propvalue->GetValue();
  FdoDataValue* dataval = (dynamic_cast<FdoDataValue*>(val.p));
  
  if( !dataval || dataval->GetDataType() != FdoDataType_Double )
  {
	  throw FdoCommandException::Create( L"SuperMapInsertReader::GetDouble DataType not FdoDataType_Double!" );
  }

  FdoDoubleValue  *dval = (static_cast<FdoDoubleValue*>(dataval)); 
  return dval->GetDouble();
}

const FdoString* SuperMapInsertReader::GetString( const FdoString * identifier)
{
	TRACE(_T("SuperMapInsertReader::GetString()... \n"));
	FdoPtr<FdoPropertyValue> propvalue = NULL;

	if( m_IsFirstReadNext || m_FeatureValues == NULL )
	{
		throw FdoCommandException::Create( L"SuperMapInsertReader::GetString End of recordset!" );
	}
	try
	{
		propvalue =  m_FeatureValues->GetItem( identifier );
		if( propvalue == NULL )
		{
			throw FdoCommandException::Create( L"SuperMapInsertReader::GetString Property not found!" );
		}
	}
	catch ( FdoException * e)
	{
		FDO_SAFE_RELEASE(e);
		throw FdoCommandException::Create( L"SuperMapInsertReader::GetString Property not found!" );
	}
	FdoPtr<FdoValueExpression> val = propvalue->GetValue();
	FdoDataValue* dataval = (dynamic_cast<FdoDataValue*>(val.p));

	if( !dataval || dataval->GetDataType() != FdoDataType_String )
	{
		throw FdoCommandException::Create( L"SuperMapInsertReader::GetString DataType not FdoDataType_String!" );
	}

	FdoStringValue  *str = (static_cast<FdoStringValue*>(dataval));
	return str->GetString();
}

short SuperMapInsertReader::GetInt16( const FdoString *identifier )
{
	TRACE(_T("SuperMapInsertReader::GetInt16()... \n"));
	FdoPtr<FdoPropertyValue> propvalue = NULL;

	if( m_IsFirstReadNext || m_FeatureValues == NULL )
	{
		throw FdoCommandException::Create( L"SuperMapInsertReader::GetInt16 End of recordset!" );
	}
	try
	{
		propvalue =  m_FeatureValues->GetItem( identifier );
		if( propvalue == NULL )
		{
			throw FdoCommandException::Create( L"SuperMapInsertReader::GetInt16 Property not found!" );
		}
	}
	catch ( FdoException *e )
	{
		FDO_SAFE_RELEASE(e);
		throw FdoCommandException::Create( L"SuperMapInsertReader::GetInt16 Property not found!" );
	}
	FdoPtr<FdoValueExpression> val = propvalue->GetValue();
	FdoDataValue* dataval = (dynamic_cast<FdoDataValue*>(val.p));

	if( !dataval || dataval->GetDataType() != FdoDataType_Int16 )
	{
		throw FdoCommandException::Create( L"SuperMapInsertReader::GetInt16 DataType not FdoDataType_Int16!" );
	}

	FdoInt16Value  *int16Value = (static_cast<FdoInt16Value*>(dataval));
	return int16Value->GetInt16();
}

int SuperMapInsertReader::GetInt32( const FdoString *identifier )
{
	/*TRACE(_T("SuperMapInsertReader::GetInt32()...[%ls] \n"), identifier);
	TRACE(_T("SuperMapInsertReader::GetInt32()...[%d] \n"), m_FeatureValues->GetCount());

	FdoPtr<FdoPropertyValue> propvalue = NULL;

	if( m_IsFirstReadNext || m_FeatureValues == NULL )
	{
		throw FdoCommandException::Create( L"SuperMapInsertReader::GetInt32 End of recordset!" );
	}
	try
	{
		propvalue =  m_FeatureValues->GetItem( identifier );
		if( propvalue == NULL )
		{
			throw FdoCommandException::Create( L"SuperMapInsertReader::GetInt32 Property not found!" );
		}
	}
	catch ( FdoException * e )
	{
		TRACE(_T("SuperMapInsertReader::GetInt32()...[%ls]... 产生异常! \n"), identifier);
		FDO_SAFE_RELEASE(e);
		throw FdoCommandException::Create( L"SuperMapInsertReader::GetInt32 Property not found!" );
	}
	FdoPtr<FdoValueExpression> val = propvalue->GetValue();
	FdoDataValue* dataval = (dynamic_cast<FdoDataValue*>(val.p));

	if( !dataval || dataval->GetDataType() != FdoDataType_Int32 )
	{
		throw FdoCommandException::Create( L"SuperMapInsertReader::GetInt32 DataType not FdoDataType_Int32!" );
	}

	FdoInt32Value  *int32Value = (static_cast<FdoInt32Value*>(dataval));
	return int32Value->GetInt32();*/
	return 165;

}

FdoInt64 SuperMapInsertReader::GetInt64( const FdoString *identifier )
{
	TRACE(_T("SuperMapInsertReader::GetInt64()... \n"));
	FdoPtr<FdoPropertyValue> propvalue = NULL;

	if( m_IsFirstReadNext || m_FeatureValues == NULL )
	{
		throw FdoCommandException::Create( L"SuperMapInsertReader::GetInt64 End of recordset!" );
	}
	try
	{
		propvalue =  m_FeatureValues->GetItem( identifier );
		if( propvalue == NULL )
		{
			throw FdoCommandException::Create( L"SuperMapInsertReader::GetInt64 Property not found!" );
		}
	}
	catch ( FdoException *e )
	{
		FDO_SAFE_RELEASE(e);
		throw FdoCommandException::Create( L"SuperMapInsertReader::GetInt64 Property not found!" );
	}
	FdoPtr<FdoValueExpression> val = propvalue->GetValue();
	FdoDataValue* dataval = (dynamic_cast<FdoDataValue*>(val.p));

	if( !dataval || dataval->GetDataType() != FdoDataType_Int64 )
	{
		throw FdoCommandException::Create( L"SuperMapInsertReader::GetInt64 DataType not FdoDataType_Int64!" );
	}

	FdoInt64Value  *int64Value = (static_cast<FdoInt64Value*>(dataval));
	return int64Value->GetInt64();
}

float SuperMapInsertReader::GetSingle( const FdoString *identifier )
{
	TRACE(_T("SuperMapInsertReader::GetSingle()... \n"));
	FdoPtr<FdoPropertyValue> propvalue = NULL;

	if( m_IsFirstReadNext || m_FeatureValues == NULL )
	{
		throw FdoCommandException::Create( L"SuperMapInsertReader::GetSingle End of recordset!" );
	}
	try
	{
		propvalue =  m_FeatureValues->GetItem( identifier );
		if( propvalue == NULL )
		{
			throw FdoCommandException::Create( L"SuperMapInsertReader::GetSingle Property not found!" );
		}
	}
	catch ( FdoException * e)
	{
		FDO_SAFE_RELEASE(e);
		throw FdoCommandException::Create( L"SuperMapInsertReader::GetSingle Property not found!" );
	}
	FdoPtr<FdoValueExpression> val = propvalue->GetValue();
	FdoDataValue* dataval = (dynamic_cast<FdoDataValue*>(val.p));

	if( !dataval || dataval->GetDataType() != FdoDataType_Single )
	{
		throw FdoCommandException::Create( L"SuperMapInsertReader::GetDouble DataType not FdoDataType_Single!" );
	}

	FdoSingleValue  *dval = (static_cast<FdoSingleValue*>(dataval)); 
	return dval->GetSingle();
}

bool SuperMapInsertReader::IsNull( const FdoString *identifier )
{
/*	TRACE(_T("SuperMapInsertReader::IsNull()... \n"));
	FdoPtr<FdoPropertyValue> propval = NULL;

	if( m_IsFirstReadNext || m_FeatureValues == NULL )
	{
		throw FdoCommandException::Create( L"SuperMapInsertReader::IsNull End of recordset!" );
	}
	try
	{
		propval =  m_FeatureValues->GetItem( identifier );
		if( propval == NULL )
		{
			throw FdoCommandException::Create( L"SuperMapInsertReader::IsNull Property not found!" );
		}
	}
	catch( FdoException *e )
	{
		FDO_SAFE_RELEASE(e);
		throw FdoCommandException::Create( L"SuperMapInsertReader::IsNull Property not found!" );
	}

	FdoPtr<FdoValueExpression> val = propval->GetValue();
	if( val.p == NULL )
	{
		return true;  
	}
	else
	{
		return false;
	}*/
	return false;
}

FdoByteArray* SuperMapInsertReader::GetGeometry(const FdoString* identifier )
{
	TRACE(_T("SuperMapInsertReader::GetGeometry()... \n"));
	FdoPtr<FdoPropertyValue> propval = NULL;

	if( m_IsFirstReadNext || m_FeatureValues == NULL )
	{
		throw FdoCommandException::Create( L"SuperMapInsertReader::IsNull End of recordset!" );
	}
	try
	{
		propval =  m_FeatureValues->GetItem( identifier );
		if( propval == NULL )
		{
			throw FdoCommandException::Create( L"SuperMapInsertReader::IsNull Property not found!" );
		}
	}
	catch( FdoException *e )
	{
		FDO_SAFE_RELEASE(e);
		throw FdoCommandException::Create( L"SuperMapInsertReader::IsNull Property not found!" );
	}
	FdoPtr<FdoValueExpression> val = propval->GetValue();
	FdoGeometryValue* geoval = (dynamic_cast<FdoGeometryValue*>(val.p));
	return geoval->GetGeometry(); 
}

const FdoByte * SuperMapInsertReader::GetGeometry(const FdoString* identifier, FdoInt32* count)
{
	FdoPtr<FdoByteArray> byteArray = GetGeometry(identifier);
	FdoByte *ret = byteArray->GetData();
	*count = byteArray->GetCount();
	return ret;
}

FdoIRaster* SuperMapInsertReader::GetRaster(const FdoString* identifier)
{
	return NULL; //not support nest now
}

bool SuperMapInsertReader::ReadNext( )
{
	bool ret = m_IsFirstReadNext;
	m_IsFirstReadNext = false;   
	return ret;
}

void SuperMapInsertReader::Close( )
{
  //do nothing
}