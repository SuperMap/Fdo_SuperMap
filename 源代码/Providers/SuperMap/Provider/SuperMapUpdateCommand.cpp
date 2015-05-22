
/** \file	 SuperMapUpdateCommand.cpp
*  \author	 马俊
*  \attention 
*  Copyright &copy;  1996-2007 SuperMap GIS Technologies,Inc.<br>
*  All Rights Reserved
*  \version 1.0
*  \date 2007-10-23
*/

#include "SuperMap.h"

SuperMapUpdateCommand::SuperMapUpdateCommand (FdoIConnection *connection) :
    superclass (connection)
{
}

/** Do not implement the copy constructor. **/
//SuperMapUpdateCommand::SuperMapUpdateCommand (const SuperMapUpdateCommand &right) { }

SuperMapUpdateCommand::~SuperMapUpdateCommand (void)
{
	
}

/// <summary>Gets the FdoPropertyValueCollection that specifies the names and values of the 
/// properties to be updated.</summary>
/// <returns>Returns the list of properties and their values.</returns> 
FdoPropertyValueCollection* SuperMapUpdateCommand::GetPropertyValues ()
{
    return (superclass::GetPropertyValues ());
}


/// <summary>Executes the update command and returns the number of modified 
/// instances.</summary>
/// <returns>Returns the number of features updated.</returns> 
FdoInt32 SuperMapUpdateCommand::Execute ()
{
	//******* 从FDO连接中获取数据源，并从数据源中按照要素类名获取记录集 *********
	FdoPtr<SuperMapConnection> superMapConn = (SuperMapConnection*)GetConnection ();
	UGC::UGDataSource *pDataSource = NULL;
	UGC::UGDatasetVector *pDataset = NULL;
	UGC::UGRecordset *pRecordset = NULL;
	bool IsCADDataset = false;
	bool IsTextDataset = false; // added by zhoux
	UGC::UGString strText = ""; // added by zhoux 用于存储转回去的文本内容
	double textSize = 0.0; // 用于存储文本的大小

	if(!superMapConn.p)
	{
		throw FdoException::Create (NlsMsgGet (SUPERMAP_CONNECTION_NOT_ESTABLISHED, "SuperMap connection is invalid'%1$ls'.", L"Execute"));
	}

	pDataSource = superMapConn->GetDataSource(); //Get UGC DataSource

	if(NULL == pDataSource)
	{
		throw FdoException::Create (NlsMsgGet (SUPERMAP_FEATURE_SOURCE_NOT_OPEN, "SuperMap feature source is not opened'%1$ls'.", L"Execute"));
	}
	if( !pDataSource->IsOpen() )
	{
		throw FdoException::Create (NlsMsgGet (SUPERMAP_FEATURE_SOURCE_NOT_OPEN, "SuperMap feature source is not opened'%1$ls'.", L"Execute"));
	}

	UGC::UGString strDatasetName = SuperMapUtil::WcharToString(mClassName->GetName()).c_str();
	pDataset = (UGC::UGDatasetVector *)pDataSource->GetDataset(strDatasetName); //get the dataset

	if(pDataset)
	{
		if(pDataset->GetType() == UGC::UGDataset::CAD)
		{
			IsCADDataset = true;
		}
		if(!pDataset->IsOpen()) //open the database
		{
			pDataset->Open();
		}
		UGC::UGQueryDef querydef;
		if(NULL != mFilter)
		{	
			SuperMapFilterProcessor filterPro(pDataSource->GetEngineType());
			mFilter->Process( &filterPro );
			querydef.m_strFilter = filterPro.GetFilterText();
		}
		//************* 按照过滤条件获取记录集************
		pRecordset = pDataset->Query(querydef);
	}
	else
	{
		throw FdoException::Create (NlsMsgGet (SUPERMAP_FEATURE_SOURCE_NOT_OPEN, "SuperMap feature source is not opened'%1$ls'.", L"Execute"));
	}

	if(pDataset->GetType() == UGC::UGDataset::Text)  // added by zhoux 取TEXT_PROPERTY字段内容
	{
		IsTextDataset = true;

		//modified by majun
		// 取TEXT_PROPERTY字段内容
		FdoPtr<FdoPropertyValue> propTextValue = mValues->FindItem(TEXT_PROPERTY);
		if(NULL != propTextValue)
		{
			FdoPtr<FdoValueExpression> textExpression = propTextValue->GetValue();
			FdoDataValue* textDataVal = dynamic_cast<FdoDataValue*>(textExpression.p);
			if( !textDataVal->IsNull() )
			{
				FdoString* text = (static_cast<FdoStringValue*>(textDataVal))->GetString();
				strText = SuperMapUtil::WcharToString(text).c_str();
			}
		}
		// 取TEXT_SIZE_PROPERTY字段内容
		FdoPtr<FdoPropertyValue> propTextSize = mValues->FindItem(TEXT_SIZE_PROPERTY);
		if(NULL != propTextSize)
		{
			FdoPtr<FdoValueExpression> textSizeExp = propTextSize->GetValue();
			FdoDataValue* textSizeVal = dynamic_cast<FdoDataValue*>(textSizeExp.p);
			if( !textSizeVal->IsNull() )
			{
				textSize = (static_cast<FdoDoubleValue*>(textSizeVal))->GetDouble();
			}
		}
	}

	//added by zhouxu 2008-4-28 for support text in CAD dataset
	if(pDataset->GetType() == UGC::UGDataset::CAD)
	{
		UGC::UGGeometry* pGeometry = NULL;
		pRecordset->GetGeometry(pGeometry);
		if(pGeometry->GetType() == UGC::UGGeometry::GeoText)
		{
			IsTextDataset = true;
			// 取TEXT_PROPERTY字段内容
			FdoPtr<FdoPropertyValue> propTextValue = mValues->FindItem(TEXT_PROPERTY);
			if(NULL != propTextValue)
			{
				FdoPtr<FdoValueExpression> textExpression = propTextValue->GetValue();
				FdoDataValue* textDataVal = dynamic_cast<FdoDataValue*>(textExpression.p);
				if( !textDataVal->IsNull() )
				{
					FdoString* text = (static_cast<FdoStringValue*>(textDataVal))->GetString();
					strText = SuperMapUtil::WcharToString(text).c_str();
				}
			}
			// 取TEXT_SIZE_PROPERTY字段内容
			FdoPtr<FdoPropertyValue> propTextSize = mValues->FindItem(TEXT_SIZE_PROPERTY);
			if(NULL != propTextSize)
			{
				FdoPtr<FdoValueExpression> textSizeExp = propTextSize->GetValue();
				FdoDataValue* textSizeVal = dynamic_cast<FdoDataValue*>(textSizeExp.p);
				if( !textSizeVal->IsNull() )
				{
					textSize = (static_cast<FdoDoubleValue*>(textSizeVal))->GetDouble();
				}
			}
		}
	}
	// end added by zhouxu 2008-4-28

	if(pRecordset)
	{	
		int nRecNum = pRecordset->GetRecordCount();
		if(0 == nRecNum)
		{
			throw FdoException::Create (NlsMsgGet (SUPERMAP_FEATURE_NOT_EXIST, "Feature already not exist, please cancle the checkout!"));
			return nRecNum;
		}
		//**********************首先创建几何对象*************************
		pRecordset->Edit(); 
		FdoPtr<FdoPropertyValue> propval = NULL;
		UGC::UGGeometry *pGeometry = NULL;
		propval = mValues->FindItem(GEOMETRY_PROPERTY);
		if(NULL != propval) //判断是否有几何数据
		{
			FdoPtr<FdoValueExpression> lval = propval->GetValue();
			FdoGeometryValue* geomval = dynamic_cast<FdoGeometryValue*>(lval.p);
			if(NULL != geomval)
			{
				FdoPtr<FdoByteArray> fgf = geomval->GetGeometry(); 
				SuperMapFgfGeoToUGCGeo FgfGeoToUGCGeo(FDO_SAFE_ADDREF(fgf.p), IsTextDataset, strText, textSize, IsCADDataset);  //modified by zhoux
				pGeometry = FgfGeoToUGCGeo.GetGeometry();
				if(pGeometry)
				{
					pRecordset->SetGeometry(*pGeometry); //设置记录集的几何对象
				}
			}
			mValues->Remove(propval); //将几何属性从结合中删除		
		}

		//*********************在记录集中设置属性信息**********************
		FdoPtr<FdoIdentifier> propidentifier;
		FdoStringP propname;
		unsigned int nprop_count = mValues->GetCount();
		for(unsigned int ind = 0; ind < nprop_count; ind++) //设置数据属性
		{
			propval = NULL;
			propval = mValues->GetItem(ind);
			if(NULL == propval)
			{
				continue;
			}
			propidentifier = propval->GetName();
			propname = propidentifier->ToString();
			//忽略非SmUserID之外的系统属性字段.
			if((wcscmp( L"Sm", propname.Mid(0,2)) == 0) && (0 != wcscmp(L"SmUserID", propname))) 
			{
				continue;
			}
			// 忽略文本点的特殊字段 added by zhouxu 2007-11-28
			if(wcscmp(propname, TEXT_PROPERTY) == 0 || wcscmp(propname, TEXT_SIZE_PROPERTY) == 0)
			{
				continue;
			}

			FdoPtr<FdoValueExpression> expr = propval->GetValue();
			FdoDataValue* dataval = dynamic_cast<FdoDataValue*>(expr.p);

			FdoBoolean BoolPropVal = false;
			FdoByte BytePropVal = 0;
			FdoDateTime TimePropVal;
			FdoFloat FloatPropVal = 0;
			FdoDouble DoublePropVal = 0;
			FdoInt16 ShortPropVal = 0;
			FdoInt32 IntPropVal = 0;
			FdoInt64 LongPropVal = 0; //64 bit
			FdoString *StrPropVal;

			UGC::UGVariant var;		
			if(NULL != dataval)
			{
				switch(dataval->GetDataType())
				{
				case FdoDataType_Boolean:
					if(!dataval->IsNull())
					{
						BoolPropVal = (static_cast<FdoBooleanValue*>(dataval))->GetBoolean();
						if(UGC::SDBPlus == pDataSource->GetEngineType() || 
							UGC::SDB == pDataSource->GetEngineType()) //SDB引擎类型
						{
							var.Set(BoolPropVal);
						}

						else //数据库引擎和其他类型的引擎
						{
							if(BoolPropVal)
							{
								var.Set(UGC::UGuchar(1));
							}
							else
							{
								var.Set(UGC::UGuchar(0));
							}
						}
					}
					break;

				case FdoDataType_Byte:
					if(!dataval->IsNull())
					{
						BytePropVal = (static_cast<FdoByteValue*>(dataval))->GetByte();
						var.Set(BytePropVal);
					}
					break;
				case FdoDataType_DateTime:
					{
						if(!dataval->IsNull())
						{
							TimePropVal = (static_cast<FdoDateTimeValue*>(dataval))->GetDateTime();
							UGC::UGTime time(TimePropVal.year, TimePropVal.month, TimePropVal.day, 
								TimePropVal.hour, TimePropVal.minute, int(TimePropVal.seconds));
							var.Set(time);
						}
					}
					break;

				case FdoDataType_Double:
					if(!dataval->IsNull())
					{
						DoublePropVal = (static_cast<FdoDoubleValue*>(dataval))->GetDouble();
						var.Set(DoublePropVal);
					}
					break;

				case FdoDataType_Int16:
					if(!dataval->IsNull())
					{
						ShortPropVal = (static_cast<FdoInt16Value*>(dataval))->GetInt16();
						var.Set(ShortPropVal);
					}
					break;

				case FdoDataType_Int32:
					if(!dataval->IsNull())
					{
						IntPropVal = (static_cast<FdoInt32Value*>(dataval))->GetInt32();
						var.Set(IntPropVal);
					}
					break;

				case FdoDataType_Int64:
					if(!dataval->IsNull())
					{
						LongPropVal = (static_cast<FdoInt64Value*>(dataval))->GetInt64();
						var.Set(LongPropVal);
					}
					break;

				case FdoDataType_Single:
					if(!dataval->IsNull())
					{
						FloatPropVal = (static_cast<FdoSingleValue*>(dataval))->GetSingle();
						var.Set(FloatPropVal);
					}
					break;

				case FdoDataType_String:
					{
						if(!dataval->IsNull())
						{
							StrPropVal = (static_cast<FdoStringValue*>(dataval))->GetString();
							UGC::UGString strPropString(SuperMapUtil::WcharToString(StrPropVal).c_str());
							var.Set(strPropString);
						}
					}
					break;

				case FdoDataType_Decimal: // not supported now
					break;

				case FdoDataType_BLOB: // not supported now
					break;

				case FdoDataType_CLOB: // not supported now
					break;

				default :
					break;

				}//switch
				pRecordset->SetFieldValue(SuperMapUtil::WcharToString(propname).c_str(), var);

			}//if(NULL != dataval)
			else
			{

			}
		}//for

		if( pRecordset->CanUpdate() )
		{
			pRecordset->Update();
			pDataSource->SaveInfo();
		}
		delete pGeometry;
		//int nRecNum = pRecordset->GetRecordCount();
		pDataset->ReleaseRecordset(pRecordset);
		pRecordset = NULL;
		pDataset->Close();
		return nRecNum;
	}//if(pRecordset)
	else
	{
		TRACE(_T("SuperMapUpdateCommand::获取记录集失败... \n"));
		throw FdoException::Create (NlsMsgGet (SUPERMAP_FEATURE_SOURCE_NOT_OPEN, "Feature source is not opened'%1$ls'!.", L"SuperMapUpdateCommand::Execute"));
	}
}


/// <summary> Updating objects might result in lock conflicts if objects
/// to be updated are not exclusively locked for the user attempting to
/// update the object. If objects to be updated are not exclusively locked for the 
/// user attempting to update the object, a lock conflict report is generated.
/// The function GetLockConflicts returns a lock conflict reader providing
/// access to the list of lock conflicts that occurred during the execution
/// of the update operation.</summary>
/// <returns>Returns a lock conflict reader.</returns> 
FdoILockConflictReader* SuperMapUpdateCommand::GetLockConflicts ()
{
    throw FdoException::Create (NlsMsgGet (SUPERMAP_LOCKING_NOT_SUPPORTED, "Locking not supported (%1$ls).", L"GetLockConflicts"));
}
