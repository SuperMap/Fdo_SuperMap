
/** \file	 SuperMapInsertCommand.cpp
*  \author	 马俊
*  \attention 
*  Copyright &copy;  1996-2007 SuperMap GIS Technologies,Inc.<br>
*  All Rights Reserved
*  \version 1.0
*  \date 2007-10-23
*/

#include "SuperMap.h"

SuperMapInsertCommand::SuperMapInsertCommand (FdoIConnection *connection) :
    FdoCommonFeatureCommand<FdoIInsert, SuperMapConnection> (connection)
{

}

/** Do not implement the copy constructor. **/
//SuperMapInsertCommand::SuperMapInsertCommand (const SuperMapInsertCommand &right) { }

SuperMapInsertCommand::~SuperMapInsertCommand (void)
{

}


/// <summary>Gets the FdoBatchParameterValueCollection that can be used for optimized
/// batch inserts of multiple features with a single insert command. Batch
/// inserts can be performed by using Parameters for each of the property
/// values, then adding collections of parameter values to the
/// FdoBatchParameterValueCollection. Each FdoParameterValueCollection in the
/// FdoBatchParameterValueCollection should contain one FdoParameterValue for each
/// of the parameters specified for property values.</summary>
/// <returns>Returns FdoBatchParameterValueCollection</returns>
FdoBatchParameterValueCollection* SuperMapInsertCommand::GetBatchParameterValues ()
{
    if (m_BatchParameters == NULL)
        m_BatchParameters = FdoBatchParameterValueCollection::Create();

    return (FDO_SAFE_ADDREF(m_BatchParameters.p));
}


/// <summary>Executes the insert command and returns a reference to an
/// FdoIFeatureReader. Some feature providers can generate automatic identity
/// values for features. This will happen automatically as the features are
/// inserted. The returned FdoIFeatureReader allows the client to obtain the
/// automatic identity property value(s) of newly inserted object(s). The
/// returned feature reader at a minimum will read the unique identity
/// properties of the objects just inserted. Multiple objects will be
/// returned through the reader in the case of a batch insert.</summary>
/// <returns>Returns an FdoIFeatureReader</returns> 
FdoIFeatureReader* SuperMapInsertCommand::Execute ()
{
	TRACE(_T("调用 SuperMapInsertCommand::Execute()... \n"));
	
	//****************** 从模式描述中获取要素类定义 ******************
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
	FdoPtr<SuperMapLpFeatureSchemaCollection> pLPFeatureSchemaCollection = superMapConn->GetLpSchemas();
	FdoPtr<FdoFeatureSchemaCollection> pFeatureSchemaCollection = pLPFeatureSchemaCollection->GetLogicalSchemas();

	FdoPtr<FdoFeatureSchema> pFeatureSchema;
	FdoPtr<FdoClassCollection> pClassCollection;
	FdoPtr<FdoClassDefinition> pClassDef;
	// 大容量COPY的后，在一个数据源中可能对应多个模式，在这种情况下就可能需要在多个模式中查询所需要素类。
	for(FdoInt32 i = 0; i < pFeatureSchemaCollection->GetCount(); ++i)
	{
		pFeatureSchema = pFeatureSchemaCollection->GetItem(i);
		pClassCollection = pFeatureSchema->GetClasses();
		pClassDef = pClassCollection->FindItem(mClassName->GetName());
		// 找到就跳出循环，多个模式都在同一个数据源中，而一个数据源不可能有同名的数据集，因此多个模式中也不会有同名的要素类
		if(pClassDef != NULL)
			break;        
	}

	//******* 从FDO连接中获取数据源，并从数据源中按照要素类名获取记录集 *********
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
		if(!pDataset->IsOpen()) //打开数据集
		{
			pDataset->Open();
		}
		UGC::UGQueryDef querydef;
		querydef.m_strFilter = " 1 > 2 ";
		pRecordset = pDataset->Query(querydef);
	}
	else
	{
		throw FdoException::Create (NlsMsgGet (SUPERMAP_FEATURE_SOURCE_NOT_OPEN, "SuperMap feature source is not opened'%1$ls'.", L"Execute"));
	}

	if(pDataset->GetType() == UGC::UGDataset::Text)  // added by zhoux 
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

	if(pRecordset)
	{
		//以下执行Insert命令
		FdoPtr<FdoPropertyValue> propval = NULL;
		UGC::UGGeometry *pGeometry = NULL;
		propval = mValues->FindItem(GEOMETRY_PROPERTY);
		if(NULL == propval) //无几何对象
		{

		}
		else
		{
			//********************* 获取UGC几何对象*******************
			FdoPtr<FdoValueExpression> lval = propval->GetValue();
			FdoGeometryValue* geomval = dynamic_cast<FdoGeometryValue*>(lval.p);
			if(NULL != geomval)
			{
				FdoPtr<FdoByteArray> fgf = geomval->GetGeometry(); 
				SuperMapFgfGeoToUGCGeo FgfGeoToUGCGeo(FDO_SAFE_ADDREF(fgf.p), IsTextDataset, strText, textSize, IsCADDataset);  //modified by zhoux
				pGeometry = FgfGeoToUGCGeo.GetGeometry();
			}
			mValues->Remove(propval); //将几何值从集合中删除
		}

		// TODO::判断pGeometry是否NULL
		//********************* 在记录集中设置几何对象***********
		pRecordset->AddNew(pGeometry); 
	
		//********************设置记录集中的属性字段*************
		FdoPtr<FdoIdentifier> propidentifier;
		FdoStringP propname;
		unsigned int nprop_count = mValues->GetCount();
		for(unsigned int ind = 0; ind < nprop_count; ind++) //设置数据值
		{
			propval = NULL;
			propval = mValues->GetItem(ind);
			if(NULL == propval)
			{
				continue;
			}
			propidentifier = propval->GetName();
			propname = propidentifier->ToString();
			//忽略除SmUserID之外的系统字段
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
			FdoFloat FloatPropVal = 0.0;
			FdoDouble DoublePropVal = 0.0;
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

						else //数据库和其他类型的引擎
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

				//TODO::UGVARIANT无对应类型
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
		FdoPtr<FdoIFeatureReader> ret = new SuperMapFeatureReader(FDO_SAFE_ADDREF(pClassDef.p), pRecordset);
		return FDO_SAFE_ADDREF(ret.p);
	}//if(pRecordset)
	else
	{
		throw FdoException::Create (NlsMsgGet (SUPERMAP_FEATURE_SOURCE_NOT_OPEN, "SuperMap feature source is not opened'%1$ls'!.", L"SuperMapInsertCommand::Execute"));
	}
}
