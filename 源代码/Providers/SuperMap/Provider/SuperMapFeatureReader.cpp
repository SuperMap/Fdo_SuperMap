
/** \file	 SuperMapFeatureReader.cpp
*  \author	 马俊
*  \attention 
*  Copyright &copy;  1996-2007 SuperMap GIS Technologies,Inc.<br>
*  All Rights Reserved
*  \version 1.0
*  \date 2007-10-29
*/

#include "SuperMap.h"

//TODO:: 函数返回时抛出异常是否有必要？在MAP3D中没有影响，在别的软件是否有问题！

SuperMapFeatureReader::SuperMapFeatureReader (void)
{
	m_bReadFirst = true;
}

SuperMapFeatureReader::SuperMapFeatureReader(FdoClassDefinition* ClassDef, UGC::UGRecordset *pRecordset)
{
	m_ClassDef = ClassDef;
	m_pRecordset = pRecordset;
	m_pDatasetRaster = NULL;
	m_bReadFirst= true;
}

SuperMapFeatureReader::SuperMapFeatureReader(FdoClassDefinition* ClassDef, UGC::UGDatasetRaster *pDatasetRaster)
{
	m_ClassDef = ClassDef;
	m_pRecordset = NULL;
	m_pDatasetRaster = pDatasetRaster;
	m_bReadFirst= true;
}

SuperMapFeatureReader::~SuperMapFeatureReader (void)
{
	Close();
}

/** Do not implement the copy constructor. **/
//SuperMapFeatureReader::SuperMapFeatureReader (const SuperMapFeatureReader &right) { }

void SuperMapFeatureReader::Dispose ()
{
    delete this;
}

/// <summary>Gets the definition of the object currently being read. If the user
/// has requested only a subset of the class properties, the class 
/// definition reflects what the user has asked, rather than the full class 
/// definition.</summary>
/// <returns>Returns the class definition object.</returns> 
FdoClassDefinition* SuperMapFeatureReader::GetClassDefinition ()
{
	return FDO_SAFE_ADDREF(m_ClassDef.p);
}

/// <summary>Gets a value indicating the depth of nesting for the current reader.
/// The depth value increases each time GetFeatureObject is called and a new 
/// reader is returned. The outermost reader has a depth of 0.</summary>
/// <returns>Returns the depth</returns> 
FdoInt32 SuperMapFeatureReader::GetDepth ()
{
	return 0; //not support nest now
}

/// <summary>Gets a reference to an FdoIFeatureReader to read the data contained in
/// the object or object collection property. If the property is not an
/// object property, an exception is thrown.</summary>
/// <param name="propertyName">Input the property name.</param> 
/// <returns>Returns the nested feature reader</returns> 
FdoIFeatureReader* SuperMapFeatureReader::GetFeatureObject (FdoString* propertyName)
{
	return NULL; //not supported now
}

/// <summary>Gets the geometry value of the specified property as a byte array in 
/// FGF format. Because no conversion is performed, the property must be
/// of Geometric type; otherwise, an exception is thrown. 
/// This method is a language-specific performance optimization that returns a
/// pointer to the array data, rather than to an object that encapsulates
/// the array.  The array's memory area is only guaranteed to be valid
/// until a call to ReadNext() or Close(), or the disposal of this reader
/// object.</summary>
/// <param name="identifier">Input the property name.</param> 
/// <param name="count">Output the number of bytes in the array.</param> 
/// <returns>Returns a pointer to the byte array in FGF format.</returns> 
const FdoByte* SuperMapFeatureReader::GetGeometry (FdoString* identifier, FdoInt32 * count)
{
	FdoPtr<FdoByteArray> byteArray = GetGeometry (identifier);
	if(NULL == byteArray)
	{
		return NULL;
	}
	FdoByte *ret = byteArray->GetData();
	*count = byteArray->GetCount();

	return ret;
}

/// <summary>Gets the geometry value of the specified property as a byte array in 
/// FGF format. Because no conversion is performed, the property must be
/// of Geometric type; otherwise, an exception is thrown.</summary>
/// <param name="identifier">Input the property name.</param> 
/// <returns>Returns the byte array in FGF format.</returns> 
FdoByteArray* SuperMapFeatureReader::GetGeometry (FdoString* identifier)
{
	TRACE(_T("开始调用 SuperMapFeatureReader::GetGeometry()... \n"));
	if(NULL == m_pRecordset || NULL == identifier)
		return NULL;
	
	FdoPtr<FdoByteArray> ret; //the result for return
	SuperMapGeoToFgfGeo FgfGeo(m_pRecordset);
	ret = FgfGeo.GetGeometry();

	if(NULL == ret)
		throw FdoException::Create(NlsMsgGet(SUPERMAP_UNEXPECTED_DATATYPE, "No geometry has been queried (%1$ls).","GetGeometry"));
	
	return FDO_SAFE_ADDREF(ret.p);
}

//-------------------------------------------------------
// FdoIReader implementation
//-------------------------------------------------------

/// <summary>Gets the Boolean value of the specified property. No conversion is
/// performed, thus the property must be FdoDataType_Boolean or an 
/// exception is thrown.</summary>
/// <param name="identifier">Input the property name.</param> 
/// <returns>Returns the Boolean value.</returns> 
bool SuperMapFeatureReader::GetBoolean (const FdoString* identifier)
{
	//TODO::再测试一下ORA一情况是否一样

	if(NULL == m_pRecordset || NULL == identifier)
	{
		return false;
	}

	UGC::UGString strProperName = SuperMapUtil::WcharToString(identifier).c_str();

	UGC::UGVariant var;
	m_pRecordset->GetFieldValue(strProperName, var);
	if(var.GetType() == UGC::UGVariant::Byte) // UGC类库升级后，各个引擎都放在该字段中，统一了
	{
		unsigned char ret = var.GetValue().bVal;
		TRACE(_T("调用 SuperMapFeatureReader::GetBoolean[%d] \n"), ret);
		if (ret)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	//if(var.GetType() == UGC::UGVariant::Short) // sdb/sdb+ 引擎放在SVal字段中
	//{
	//	short ret = var.GetValue().sVal;
	//	TRACE(_T("调用 SuperMapFeatureReader::GetBoolean[%d] \n"), ret);
	//	if (ret)
	//	{
	//		return true;
	//	}
	//	else
	//	{
	//		return false;
	//	}
	//}

	//if (var.GetType() == UGC::UGVariant::Integer) //SQL/SQL+ 引擎放在IVal字段中
	//{
	//	int ret = var.GetValue().iVal;
	//	TRACE(_T("调用 SuperMapFeatureReader::GetBoolean[%d] \n"), ret);
	//	if(ret)
	//	{
	//		return true;
	//	}
	//	else
	//	{
	//		return false;
	//	}
	//}
	else
	{
		throw FdoException::Create(NlsMsgGet(SUPERMAP_UNEXPECTED_DATATYPE, "The field type is not bool (%1$ls).", "GetBoolean"));
	}
}

/// <summary>Gets the byte value of the specified property. No conversion is 
/// performed, thus the property must be FdoDataType_Byte or an 
/// exception is thrown.</summary>
/// <param name="identifier">Input the property name.</param> 
/// <returns>Returns the byte value.</returns> 
FdoByte SuperMapFeatureReader::GetByte (FdoString* identifier)
{
	if(NULL == m_pRecordset || NULL == identifier)
	{
		return 0;
	}
	
	UGC::UGString strProperName = SuperMapUtil::WcharToString(identifier).c_str();
	UGC::UGVariant var;
	m_pRecordset->GetFieldValue(strProperName, var);
	if(var.GetType() == UGC::UGVariant::Byte)
	{
		FdoByte ret = (FdoByte)var.GetValue().bVal;
		return ret;
	}
	else
	{
		throw FdoException::Create(NlsMsgGet(SUPERMAP_UNEXPECTED_DATATYPE, "The field type is not byte (%1$ls).", "GetByte"));
	}
}

/// <summary> Gets the date and time value of the specified property. No conversion is 
/// performed, thus the property must be FdoDataType_DateTime or an 
/// exception is thrown.</summary>
/// <param name="identifier">Input the property name.</param> 
/// <returns>Returns the date and time value.</returns> 
FdoDateTime SuperMapFeatureReader::GetDateTime (FdoString* identifier)
{
	if(NULL == m_pRecordset || NULL == identifier)
	{
		FdoDateTime Ftime;
		return Ftime;
	}

	UGC::UGString strProperName = SuperMapUtil::WcharToString(identifier).c_str();
	UGC::UGVariant var;
	m_pRecordset->GetFieldValue(strProperName, var);

	//if(var.GetType() == UGC::UGVariant::Double) //sdb/sdb+ 引擎将时间值放在dVal中
	//{
	//	double timeVar = var.GetValue().dVal;
	//	UGC::UGTime ugTime(timeVar);

	//	FdoDateTime Ftime((FdoInt16)ugTime.GetYear(), 
	//		(FdoInt8)ugTime.GetMonth(), 
	//		(FdoInt8)ugTime.GetDay(),
	//		(FdoInt8)ugTime.GetHour(), 
	//		(FdoInt8)ugTime.GetMinute(), 
	//		(float)ugTime.GetSecond());

	//	return Ftime;
	//}
	
	if(var.GetType() == UGC::UGVariant::Time) //UGC类库升级后，各个引擎都放在该字段中，统一了
	{
		double timeVar = var.GetValue().tVal;
		UGC::UGTime ugTime(timeVar);

		FdoDateTime Ftime((FdoInt16)ugTime.GetYear(), 
							(FdoInt8)ugTime.GetMonth(), 
							(FdoInt8)ugTime.GetDay(), 
							(FdoInt8)ugTime.GetHour(), 
							(FdoInt8)ugTime.GetMinute(), 
							(FdoInt8)ugTime.GetSecond());
		//TRACE(_T("调用 SuperMapFeatureReader::GetDateTime().年[%d].月[%d].日[%d].时[%d].分[%d].秒[%f]. \n"), Ftime.year, Ftime.month, Ftime.day, Ftime.hour, Ftime.minute, Ftime.seconds);
		return Ftime;
	}
	else
	{
		throw FdoException::Create(NlsMsgGet(SUPERMAP_UNEXPECTED_DATATYPE, "The field type is not datatime (%1$ls).", "GetDateTime"));
		//TODO::再测试是否要加
		FdoDateTime Ftime;
		return Ftime;
	}
}

/// <summary>Gets the double-precision floating point value of the specified property. No
/// conversion is performed, thus the property must be FdoDataType_Double
/// or an exception is thrown.</summary>
/// <param name="identifier">Input the property name.</param> 
/// <returns>Returns the double floating point value</returns> 
double SuperMapFeatureReader::GetDouble (FdoString* identifier)
{
	if(NULL == m_pRecordset || NULL == identifier)
	{
		return 0;
	}

	UGC::UGString strProperName = SuperMapUtil::WcharToString(identifier).c_str();
	UGC::UGVariant var;

	// added by zhoux 2007-12-10 for 文本数据集的TEXT_SIZE_PROPERTY字段内容作为点数据集的文本大小字段

	UGC::UGDatasetVector* pDatasetVector = m_pRecordset->GetDataset();
	VALIDATE_POINTER(pDatasetVector);

	if((pDatasetVector->GetType() == UGC::UGDataset::Text) && (0 == wcscmp(identifier,TEXT_SIZE_PROPERTY)))
	{
		UGC::UGGeoText* pGeoText = NULL;
		m_pRecordset->GetGeometry((UGC::UGGeometry*&)pGeoText); // pGeoText 需要在内部分配空间，需要释放
		if(pGeoText != NULL)  //暂时不考虑文本子对象个数大于1的情况 ToDo:
		{
			UGC::UGTextStyle textStyle = pGeoText->GetTextStyle();     
			double retSize = textStyle.GetHeight(); // 取大小
			delete pGeoText;
			return retSize;	
		}
		else
		{
			return 0.0;
		}
	}
	// end added 

	// added by zhoux 2008-4-28 支持复合数据集的文本对象
	if((pDatasetVector->GetType() == UGC::UGDataset::CAD) && (0 == wcscmp(identifier,TEXT_SIZE_PROPERTY)))
	{
		UGC::UGGeoText* pGeoText = NULL;
		UGC::UGGeometry* pGeometry = NULL;
		m_pRecordset->GetGeometry(pGeometry); // pGeoText 需要在内部分配空间，需要释放
		if(pGeometry->GetType() != UGC::UGGeometry::GeoText)
		{
			//复合数据集中非文本对象的此字段值设为0.0
			return 0.0;
		}
		pGeoText = (UGC::UGGeoText*)pGeometry ;
		if(pGeoText != NULL)  //暂时不考虑文本子对象个数大于1的情况 ToDo:
		{
			UGC::UGTextStyle textStyle = pGeoText->GetTextStyle();     
			double retSize = textStyle.GetHeight(); // 取大小
			delete pGeoText;
			return retSize;	
		}
		else
		{
			return 0.0;
		}
	}
	// end added 

	m_pRecordset->GetFieldValue(strProperName, var);
	if(var.GetType() == UGC::UGVariant::Double)
	{
		double ret = var.GetValue().dVal;
		return ret;
	}
	else
	{
		throw FdoException::Create(NlsMsgGet(SUPERMAP_UNEXPECTED_DATATYPE, "The field type is not double (%1$ls).", "GetDouble"));
	}
}

/// <summary>Gets the 16-bit integer value of the specified property. No conversion is
/// performed, thus the property must be FdoDataType_Int16 or an exception
/// is thrown.</summary>
/// <param name="identifier">Input the property name.</param> 
/// <returns>Returns the FdoInt16 value.</returns> 
FdoInt16 SuperMapFeatureReader::GetInt16 (FdoString* identifier)
{
	if(NULL == m_pRecordset || NULL == identifier)
	{
		return 0;
	}

	UGC::UGString strProperName = SuperMapUtil::WcharToString(identifier).c_str();
	UGC::UGVariant var;
	m_pRecordset->GetFieldValue(strProperName, var);
	if(var.GetType() == UGC::UGVariant::Short) //UGC类库升级后，各个引擎都放在该字段中，统一了
	{
		FdoInt16 ret = (FdoInt16)var.GetValue().sVal;
		return ret;
	}
	//if(var.GetType() == UGC::UGVariant::Integer) //Oracle 短整型放在次变量中
	//{
	//	FdoInt32 ret = (FdoInt16)var.GetValue().iVal;
	//	return ret;
	//}
	else
	{
		throw FdoException::Create(NlsMsgGet(SUPERMAP_UNEXPECTED_DATATYPE, "The field type is not short (%1$ls).", "GetInt16"));
	}
}

/// <summary>Gets the 32-bit integer value of the specified property. No conversion is
/// performed, thus the property must be FdoDataType_Int32 or an exception
/// is thrown.</summary>
/// <param name="identifier">Input the property name.</param> 
/// <returns>Returns the FdoInt32 value</returns> 
FdoInt32 SuperMapFeatureReader::GetInt32 (FdoString* identifier)
{
	if(NULL == m_pRecordset || NULL == identifier)
	{
		return 0;
	}

	UGC::UGString strProperName = SuperMapUtil::WcharToString(identifier).c_str();
	UGC::UGVariant var;
	m_pRecordset->GetFieldValue(strProperName, var);
	if(var.GetType() == UGC::UGVariant::Integer)
	{
		FdoInt32 ret = (FdoInt32)var.GetValue().iVal;
		return ret;
	}
	else
	{
		throw FdoException::Create(NlsMsgGet(SUPERMAP_UNEXPECTED_DATATYPE, "The field type is not int (%1$ls).", "GetInt32"));
	}
}

/// <summary>Gets the 64-bit integer value of the specified property. No conversion is
/// performed, thus the property must be FdoDataType_Int64 or an exception
/// is thrown.</summary>
/// <param name="identifier">Input the property name.</param> 
/// <returns>Returns the FdoInt64 value.</returns> 
FdoInt64 SuperMapFeatureReader::GetInt64 (FdoString* identifier)
{
	if(NULL == m_pRecordset || NULL == identifier)
	{
		return 0;
	}

	UGC::UGString strProperName = SuperMapUtil::WcharToString(identifier).c_str();
	UGC::UGVariant var;
	m_pRecordset->GetFieldValue(strProperName, var);
	if(var.GetType() == UGC::UGVariant::Long)
	{
		FdoInt64 ret = (FdoInt64)var.GetValue().lVal;
		return ret;
	}
	else
	{
		throw FdoException::Create(NlsMsgGet(SUPERMAP_UNEXPECTED_DATATYPE, "The field type is not long (%1$ls).", "GetInt64"));
	}
}

/// <summary>Gets the Single floating point value of the specified property. No
/// conversion is performed, thus the property must be FdoDataType_Single
/// or an exception is thrown.</summary>
/// <param name="identifier">Input the property name.</param> 
/// <returns>Returns the single value</returns> 
float SuperMapFeatureReader::GetSingle (FdoString* identifier)
{
	if(NULL == m_pRecordset || NULL == identifier)
	{
		return 0;
	}

	UGC::UGString strProperName = SuperMapUtil::WcharToString(identifier).c_str();
	UGC::UGVariant var;
	m_pRecordset->GetFieldValue(strProperName, var);
	if(var.GetType() == UGC::UGVariant::Float) //UGC类库升级后，各个引擎都放在该字段中，统一了
	{
		float ret = var.GetValue().fVal;
		return ret;
	}
	//if(var.GetType() == UGC::UGVariant::Double) //Oracle 单精度放在此变量中
	//{
	//	double ret = var.GetValue().dVal;
	//	TRACE(_T("调用 SuperMapFeatureReader::GetSingle[%g] \n"), ret);
	//	return ret;
	//}
	else
	{
		throw FdoException::Create(NlsMsgGet(SUPERMAP_UNEXPECTED_DATATYPE, "The field type is not float (%1$ls).", "GetSingle"));
	}
}

/// <summary>Gets the string value of the specified property. No conversion is
/// performed, thus the property must be FdoDataType_String or an exception
/// is thrown.</summary>
/// <param name="identifier">Input the property name.</param> 
/// <returns>Returns the string value</returns> 
FdoString* SuperMapFeatureReader::GetString (FdoString* identifier)
{
	if(NULL == m_pRecordset || NULL == identifier)
	{
		return NULL;
	}

	UGC::UGString strProperName = SuperMapUtil::WcharToString(identifier).c_str();
	UGC::UGVariant var;

	// added by zhoux 2007-11-28 for 文本数据集的TEXT_PROPERTY字段内容作为点数据集的文本字段

	UGC::UGDatasetVector* pDatasetVector = m_pRecordset->GetDataset();
	VALIDATE_POINTER(pDatasetVector);
	if((pDatasetVector->GetType() == UGC::UGDataset::Text) && (0 == wcscmp(identifier,TEXT_PROPERTY)))
	{
		UGC::UGGeoText* pGeoText = NULL;
		m_pRecordset->GetGeometry((UGC::UGGeometry*&)pGeoText); // pGeoText 需要在内部分配空间，需要释放
		if(pGeoText != NULL)  //对于文本子对象个数大于1的情况，将文本内容合并:
		{
			FdoStringP tmpString;
			m_CachedString = L"";
			for(FdoInt32 i = 0; i < pGeoText->GetSubCount(); ++i)
			{
				tmpString = SuperMapUtil::StringToWString(pGeoText->GetSub(i).GetText().Cstr()).c_str();
				m_CachedString += tmpString;
			}
			delete pGeoText;
			return m_CachedString.operator FdoString*( );	
		}
		else
		{
			return L"";
		}
	}
	// end added 

	// added by zhouxu 2008-4-28  支持复合数据集中的文本对象
	if((pDatasetVector->GetType() == UGC::UGDataset::CAD) && (0 == wcscmp(identifier,TEXT_PROPERTY)))
	{
		UGC::UGGeoText* pGeoText = NULL;
		UGC::UGGeometry* pGeometry = NULL;
		m_pRecordset->GetGeometry(pGeometry); // pGeometry 需要在内部分配空间，需要释放
		if(pGeometry->GetType() != UGC::UGGeometry::GeoText)
		{
			//对于复合数据集的非文本对象，此字段置为空
			return L"";
		}
		pGeoText = (UGC::UGGeoText*)pGeometry;
		if(pGeoText != NULL)  //对于文本子对象个数大于1的情况，将文本内容合并:
		{
			FdoStringP tmpString;
			m_CachedString = L"";
			for(FdoInt32 i = 0; i < pGeoText->GetSubCount(); ++i)
			{
				tmpString = SuperMapUtil::StringToWString(pGeoText->GetSub(i).GetText().Cstr()).c_str();
				m_CachedString += tmpString;
			}
			delete pGeoText;
			return m_CachedString.operator FdoString*( );	
		}
		else
		{
			return L"";
		}
	}
	// end added
	
	m_pRecordset->GetFieldValue(strProperName, var);
	if(var.GetType() == UGC::UGVariant::String)
	{
		/*char *strHeader = (char*)var.GetValue().pVal;
		strHeader += 4;
		m_CachedString = SuperMapUtil::StringToWString(strHeader).c_str();
		return m_CachedString.operator FdoString*( );*/	
		
		UGC::UGString StrVal = "";
		StrVal = var.ToString();
		m_CachedString = SuperMapUtil::StringToWString(StrVal.Cstr()).c_str();
		if(StrVal.GetLength() == 0)
		{
			TRACE(_T("调用 SuperMapFeatureReader::GetString()..字符串为空! \n"));
		}
		return m_CachedString.operator FdoString*( );
	}

	else
	{
		throw FdoException::Create(NlsMsgGet(SUPERMAP_UNEXPECTED_DATATYPE, "The field type is not string (%1$ls).", "GetString"));
	}
}

/// <summary>Gets a LOBValue reference. The LOB is fully read in and data available.
/// Because no conversion is performed, the property must be FdoDataType_BLOB or
/// FdoDataType_CLOB etc. (a LOB type)
/// <param name="propertyName">Input the property name.</param> 
/// <returns>Returns the reference to LOBValue</returns> 
FdoLOBValue* SuperMapFeatureReader::GetLOB (FdoString* identifier)
{
	return NULL; //not support now;
}

/// <summary>Gets a reference of the specified LOB property as a FdoBLOBStreamReader or
/// FdoCLOBStreamReader etc. to allow reading in blocks of data.
/// Because no conversion is performed, the property must be FdoDataType_BLOB 
/// or FdoDataType_CLOB etc. (a LOB type)
/// Cast the FdoIStreamReader to the appropiate LOB Stream Reader.
/// <param name="propertyName">Input the property name.</param> 
/// <returns>Returns a reference to a LOB stream reader</returns> 
FdoIStreamReader* SuperMapFeatureReader::GetLOBStreamReader(FdoString* identifier)
{
	return NULL; //not support now;
}

/// <summary>Returns true if the value of the specified property is null.</summary>
/// <param name="identifier">Input the property name.</param> 
/// <returns>Returns true if the value is null.</returns> 
bool SuperMapFeatureReader::IsNull (FdoString* identifier)
{
	if(NULL == m_pRecordset || NULL == identifier)
	{
		return true;
	}

	UGC::UGString strProperName = SuperMapUtil::WcharToString(identifier).c_str();
	if(wcscmp(GEOMETRY_PROPERTY, identifier) == 0) //空间信息
	{
		if(m_pRecordset->HasGeometry())//有几何信息
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	// added by zhouxu 2007-11-28
	if(wcscmp(TEXT_PROPERTY, identifier) == 0)
	{
		return false; 
	}
	
	// added by zhouxu 2007-12-10
	if(wcscmp(TEXT_SIZE_PROPERTY, identifier) == 0)
	{
		return false;
	}

	UGC::UGVariant var;
	m_pRecordset->GetFieldValue(strProperName, var);//TRACE(_T("调用 SuperMapFeatureReader::ISNull()..[%ls].[%d] \n"), identifier, var.GetType());
	if(var.GetType() == UGC::UGVariant::Null) //if the value of this property is NULL
	{
		return true;
	}
	else
	{
		return false;
	}
}

/// <summary>Gets the raster object of the specified property.
/// Because no conversion is performed, the property must be
/// of Raster type; otherwise, an exception is thrown.</summary>
/// <param name="propertyName">Input the property name.</param> 
/// <returns>Returns the raster object.</returns> 
FdoIRaster* SuperMapFeatureReader::GetRaster (FdoString* identifier)
{
	if(NULL == m_pDatasetRaster || NULL == identifier)
	{
		return NULL;
	}
	FdoPtr<FdoIRaster> rv = new SuperMapRaster(m_pDatasetRaster, FDO_SAFE_ADDREF(m_ClassDef.p));
	return FDO_SAFE_ADDREF(rv.p);
}

/// <summary>Advances the reader to the next item and returns true if there is
/// another object to read or false if reading is complete. The default
/// position of the reader is prior to the first item. Thus you must
/// call ReadNext to begin accessing any data.</summary>
/// <returns>Returns true if there is a next item.</returns> 
bool SuperMapFeatureReader::ReadNext ()
{
	TRACE(_T("开始调用 SuperMapFeatureReader::ReadNext()... \n"));
	if( NULL == m_pDatasetRaster ) //处理矢量数据集
	{
		if(NULL == m_pRecordset)
		{
			return false;
		}

		if (m_bReadFirst)
		{
			if (!m_pRecordset->IsEmpty()) //记录集不空
			{
				m_pRecordset->MoveFirst();
				m_bReadFirst = false;
			}
			else //记录集空
			{
				return false;
			}		
		}
		else
		{
			m_pRecordset->MoveNext();
		}

		if (!m_pRecordset->IsEOF())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else //处理栅格数据集
	{
		if (m_bReadFirst)
		{
			m_bReadFirst = false;
			return true;
		}
		else
		{
			return false;
		}
	}
}

/// <summary>Closes the Reader object, freeing any resources it may be holding.</summary>
/// <returns>Returns nothing</returns> 
void SuperMapFeatureReader::Close ()
{
	if(NULL != m_pRecordset)
	{
		UGC::UGDatasetVector *pDataset = m_pRecordset->GetDataset();
		// 由于UGC的原因，还有手动释放查询的记录集
		pDataset->ReleaseRecordset(m_pRecordset);
		m_pRecordset = NULL;
		pDataset->Close();
	}
}

//four functions do with the SuperMapDataReader
FdoInt32 SuperMapFeatureReader::GetPropertyCount()
{
	FdoInt32 nPropCount = 0;
	if(NULL != m_pRecordset)
	{
		nPropCount =  m_pRecordset->GetFieldCount();
	}
	return nPropCount;
}

FdoString* SuperMapFeatureReader::GetPropertyName(FdoInt32 index)
{
	UGC::UGFieldInfo fieldInfo;
	FdoString *ret = NULL;
	if(NULL != m_pRecordset)
	{
		m_pRecordset->GetFieldInfo(index, fieldInfo);
		ret = SuperMapUtil::StringToWString(fieldInfo.m_strName.Cstr()).c_str();
	}
	return ret;
}

FdoDataType SuperMapFeatureReader::GetDataType(FdoString* propertyName)
{
	UGC::UGString strProperName = SuperMapUtil::WcharToString(propertyName).c_str();
	UGC::UGFieldInfo fieldInfo;
	FdoDataType nDataType = FdoDataType_Int32;
	if(m_pRecordset)
	{
		m_pRecordset->GetFieldInfo(strProperName, fieldInfo);
		switch(fieldInfo.m_nType)
		{
		case UGC::UGFieldInfo::Boolean:
			nDataType = FdoDataType_Boolean;
			break;

		case UGC::UGFieldInfo::Byte:
		case UGC::UGFieldInfo::Char:
			nDataType = FdoDataType_Byte;
			break;

		case UGC::UGFieldInfo::Integer:
			nDataType = FdoDataType_Int16;
			break;

		case UGC::UGFieldInfo::Long:   
			nDataType = FdoDataType_Int32;
			break;

		case UGC::UGFieldInfo::Single:
		case UGC::UGFieldInfo::Float:
			nDataType = FdoDataType_Single;
			break;

		case UGC::UGFieldInfo::Double:
			nDataType = FdoDataType_Double;
			break;

		case UGC::UGFieldInfo::Date:
		case UGC::UGFieldInfo::Time:
		case UGC::UGFieldInfo::TimeStamp:
			nDataType = FdoDataType_DateTime;
			break;

		case UGC::UGFieldInfo::Decimal:
			nDataType = FdoDataType_Decimal;
			break;

		case UGC::UGFieldInfo::Binary:
		case UGC::UGFieldInfo::LongBinary:
		case UGC::UGFieldInfo::VarBinary:
			nDataType = FdoDataType_BLOB;
			break;

		case UGC::UGFieldInfo::Text:
			nDataType = FdoDataType_String; 
			break;

		default:
			break;
		}
	}
	return nDataType;
}

FdoPropertyType SuperMapFeatureReader::GetPropertyType(FdoString* propertyName)
{
	FdoPropertyType nPropType = FdoPropertyType_DataProperty;
	if( wcscmp(propertyName, GEOMETRY_PROPERTY) == 0)
	{
		nPropType = FdoPropertyType_GeometricProperty;
	}
	return nPropType;

}
