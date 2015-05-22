/** \file	 SuperMapLpFeatureSchema.cpp
*  \brief    该类主要完成从SuperMap数据源到Fdo逻辑模式的转换。
*  \author	 周 旭
*  \attention 
*  Copyright &copy;  1996-2007 SuperMap GIS Technologies,Inc.<br>
*  All Rights Reserved
*  \version 1.0
*  \date 2007-11-5
*/

#include "SuperMap.h"

SuperMapLpFeatureSchema::SuperMapLpFeatureSchema()
{
	// 0-argument constructor to please FdoPtr::operator-> 
    throw FdoException::Create(NlsMsgGet(SUPERMAP_UNEXPECTED_ERROR, 
		"Unexpected error '%1$ls'.", L"zero arg SupermapLpFeatureSchema::SuperMapLpFeatureSchema"));
}

SuperMapLpFeatureSchema::SuperMapLpFeatureSchema(
	SuperMapLpFeatureSchemaCollection* parentLpSchemas,
	SuperMapConnection* connection,
	UGC::UGDataSource* pDataSource,
	FdoFeatureSchema* configLogicalSchema,
	bool ignoreStates)
:
	m_parentLpSchemas(parentLpSchemas),
	m_pDataSource(pDataSource)
{
	TRACE(_T("调用 SuperMapLpFeatureSchema::SuperMapLpFeatureSchema() 。\n"));

	VALIDATE_POINTER(connection);

	// 创建逻辑物理类集合
	m_lpClasses = new SuperMapLpClassDefinitionCollection(); 

	VALIDATE_POINTER(pDataSource);
	
	if(configLogicalSchema == NULL)
		ConvertPhysicalToLogical(connection);
	else
		ConvertLogicalToPhysical(connection,configLogicalSchema,ignoreStates);

	// 如果模式已经存在，仅添加新的要素类到存在的这个模式中，否则将新的逻辑物理模式加到它的父集合中
	FdoPtr<SuperMapLpFeatureSchema> schema = m_parentLpSchemas->FindItem(GetName());
	if(schema != NULL)
	{
		FdoPtr<SuperMapLpClassDefinitionCollection> newClasses = GetLpClasses();
		FdoPtr<SuperMapLpClassDefinitionCollection> existingClasses = schema->GetLpClasses();
		FdoPtr<FdoFeatureSchema> existingLogicalSchema = schema->GetLogicalSchema();
		FdoPtr<FdoClassCollection> existingLogicalClasses = existingLogicalSchema->GetClasses();
		FdoPtr<FdoFeatureSchema> newLogicalSchema = GetLogicalSchema();
		FdoPtr<FdoClassCollection> newLogicalClasses = newLogicalSchema->GetClasses();
		for(int i = 0; i < newClasses->GetCount(); ++i)
		{
			FdoPtr<SuperMapLpClassDefinition> definition = newClasses->GetItem(i);
			existingClasses->Add(definition);
			definition->SetParent(schema);
			FdoPtr<FdoClassDefinition> cls = newLogicalClasses->GetItem(definition->GetName());
			newLogicalClasses->Remove(cls);
			existingLogicalClasses->Add(cls);
		}
	}
	else
	{
		m_parentLpSchemas->Add(this);
	}
}

SuperMapLpFeatureSchema::~SuperMapLpFeatureSchema()
{

}

FdoString* SuperMapLpFeatureSchema::GetName() const
{
	return m_logicalSchema->GetName();
}

bool SuperMapLpFeatureSchema::CanSetName() const
{
    return false;
}

FdoFeatureSchema * SuperMapLpFeatureSchema::GetLogicalSchema() const
{
    FDO_SAFE_ADDREF(m_logicalSchema.p);
    return m_logicalSchema;
}

//FdoFeatureSchema * SuperMapLpFeatureSchema::GetImageSchema() const
//{
//	FDO_SAFE_ADDREF(m_ImageSchema.p);
//	return m_ImageSchema;
//}

SuperMapLpClassDefinitionCollection* SuperMapLpFeatureSchema::GetLpClasses()
{
    FDO_SAFE_ADDREF(m_lpClasses.p);
    return m_lpClasses;
}

UGC::UGDataSource* SuperMapLpFeatureSchema::GetDataSource() const
{
	return m_pDataSource;
}

//负责完成从物理数据源到逻辑模式的转换并促发数据集到要素类的转换
void SuperMapLpFeatureSchema::ConvertPhysicalToLogical(SuperMapConnection * connection) 
{
	TRACE(_T("调用 SuperMapLpFeatureSchema::ConvertPhysicalToLogical() 。\n"));

	// 获取物理数据源
	if(m_pDataSource == NULL)
	{
		m_pDataSource = connection->GetDataSource();
	}
	// 创建逻辑模式（物理数据源名为逻辑模式名）
	//FdoStringP pSchemaName = NlsMsgGet(SUPERMAP_DEFAULT_SCHEMA_NAME, "Default Schema.");
	FdoStringP pSchemaName = SuperMapUtil::StringToWString(m_pDataSource->GetAlias().Cstr()).c_str();
	FdoString* logicalSchemaName = (FdoString*)pSchemaName;
	FdoStringP pDefaultSchDesc = NlsMsgGet(SUPERMAP_DEFAULT_SCHEMA_DESCRIPTION, "Default schema.");
	FdoString * logicalSchemaDescription = (FdoString*)pDefaultSchDesc;
    
	m_logicalSchema = FdoFeatureSchema::Create(logicalSchemaName, logicalSchemaDescription);

	////创建影像模式
	/*pSchemaName = NlsMsgGet(SUPERMAP_IMAGE_SCHEMA_NAME, "Image Schema");
	FdoString* ImageSchemaName = (FdoString*)pSchemaName;
	m_ImageSchema = FdoFeatureSchema::Create(ImageSchemaName, L"");*/
    
	//遍历物理数据源，通过物理数据集促发模式中要素类的建立
	VALIDATE_POINTER(m_pDataSource);

	//根据是否影像模式打开连接判断
	if(!connection->IsOnlyConnectImage())
	{
		TRACE(_T("数据源中数据集个数：%d"),m_pDataSource->GetDatasetCount());
		for(FdoInt32 i = 0; i < m_pDataSource->GetDatasetCount(); ++i)
		{
			UGC::UGDataset* pDataset = m_pDataSource->GetDataset(i);

			//屏蔽掉不支持的数据集类型 added by zhouxu 2007-12-10
			FdoInt32 nDatasetType = pDataset->GetType();
			if ( !(nDatasetType == UGC::UGDataset::Point 
				|| nDatasetType == UGC::UGDataset::Line 
				|| nDatasetType == UGC::UGDataset::Region
				|| nDatasetType == UGC::UGDataset::CAD 
				|| nDatasetType == UGC::UGDataset::Text
				)) // 如果遇到暂不支持的数据集类型，返回
			{
				continue;
			}

			//使用Dataset初始化Class Definition（自动加到父集合中）
			FdoPtr<SuperMapLpClassDefinition> pLpClassDefinition =
				new SuperMapLpClassDefinition(this, connection, pDataset, NULL);
		}  
	}
	else
	{
		for(FdoInt32 i = 0; i < m_pDataSource->GetDatasetCount(); ++i)
		{
			UGC::UGDataset* pDataset = m_pDataSource->GetDataset(i);

			//屏蔽掉不支持的数据集类型 added by zhouxu 2007-12-10
			FdoInt32 nDatasetType = pDataset->GetType();
			if ( nDatasetType != UGC::UGDataset::Image ) // 如果遇到暂不支持的数据集类型，返回
			{
				continue;
			}

			//使用Dataset初始化Class Definition（自动加到父集合中）
			FdoPtr<SuperMapLpClassDefinition> pLpClassDefinition =
				new SuperMapLpClassDefinition(this, connection, pDataset, NULL);
		}  
	}

	
	
	//把新逻辑模式添加都父逻辑模式集合中：
	FdoPtr<FdoFeatureSchemaCollection> logicalSchemas = m_parentLpSchemas->GetLogicalSchemas();
	logicalSchemas->Add(m_logicalSchema);
	// 加入影像模式
	//logicalSchemas->Add(m_ImageSchema);
}

void SuperMapLpFeatureSchema::ConvertLogicalToPhysical(SuperMapConnection* connection, FdoFeatureSchema* configLogicalSchema, bool ignoreStates)
{
	TRACE(_T("调用 SuperMapLpFeatureSchema::ConvertLogicalToPhysical() 。\n"));

	// 获取物理数据源
	if(m_pDataSource == NULL)
	{
		m_pDataSource = connection->GetDataSource();
	}
	// 创建逻辑模式（并把它加到父集合中）
	VALIDATE_POINTER(configLogicalSchema);
	m_logicalSchema = FdoCommonSchemaUtil::DeepCopyFdoFeatureSchema(configLogicalSchema); //逻辑到物理实际上逻辑模式是不变的，所以此处直接进行深度拷贝,但是要素类的标识属性字段得变成FEATID_PROPERTY
	// 遍历模式中的所有要素类，将标识字段名改为FEATID_PROPERTY
	FdoPtr<FdoClassCollection> tmpClasses = m_logicalSchema->GetClasses();
	FdoPtr<FdoClassDefinition> tmpClass;
	FdoPtr<FdoPropertyDefinitionCollection> tmpProperties;
	FdoPtr<FdoDataPropertyDefinitionCollection> tmpIdProperties;
	FdoPtr<FdoDataPropertyDefinition> tmpIdProperty;
	for(FdoInt32 i = 0; i < tmpClasses->GetCount(); ++i)
	{
		tmpClass = tmpClasses->GetItem(i);
		tmpProperties = tmpClass->GetProperties();
		tmpIdProperties = tmpClass->GetIdentityProperties();
		// 先清空，在增加一个名为FEATID_PROPERTY的标识字段
		for(FdoInt32 j = 0; j < tmpIdProperties->GetCount(); ++j)
		{
			FdoPtr<FdoPropertyDefinition> oldIdProperty = tmpIdProperties->GetItem(i);
			tmpProperties->Remove(oldIdProperty);
		}
		tmpIdProperties->Clear();
		tmpIdProperty = FdoDataPropertyDefinition::Create(FEATID_PROPERTY,L"");
		tmpIdProperty->SetDataType(FdoDataType_Int32);
		tmpIdProperty->SetIsAutoGenerated(true);
		tmpIdProperty->SetNullable(false);
		tmpIdProperty->SetReadOnly(true);
		tmpProperties->Add(tmpIdProperty);
		tmpIdProperties->Add(tmpIdProperty);
	} // end for replace Identity Property

	FdoPtr<FdoFeatureSchemaCollection> logicalSchemas = m_parentLpSchemas->GetLogicalSchemas();
	// 确认此模式是否在父集合中
	bool bAlreadyInCollection = false;
	for(FdoInt32 i = 0;i < logicalSchemas->GetCount() && !bAlreadyInCollection; ++i)
	{
		FdoPtr<FdoFeatureSchema> logicalSchema = logicalSchemas->GetItem(i);
		if(0 == wcscmp(logicalSchema->GetName(), m_logicalSchema->GetName()))
		{
			bAlreadyInCollection = true;
		}
	}
	if(!bAlreadyInCollection)
		logicalSchemas->Add(m_logicalSchema);

	// 获取逻辑类
	FdoPtr<FdoClassCollection> logicalClasses = configLogicalSchema->GetClasses();

	// 创建新的逻辑物理类（在其中创建新的物理数据集）
	FdoInt32 size = logicalClasses->GetCount();
	for(FdoInt32 i = 0; i < size; ++i)
	{
		FdoPtr<FdoClassDefinition> logicalClass = logicalClasses->GetItem(i);
		// 处理ignoreState标志
		FdoSchemaElementState state = logicalClass->GetElementState();
		if(ignoreStates)
		{
			FdoPtr<SuperMapLpClassDefinition> lpExistingClass = m_lpClasses->FindItem(logicalClass->GetQualifiedName());
			if(lpExistingClass == NULL)
				state = FdoSchemaElementState_Added;
			else
				state = FdoSchemaElementState_Modified;
		}
		switch(state)
		{
		case FdoSchemaElementState_Added:
			addClass(connection, logicalClass);
			break;
		case FdoSchemaElementState_Deleted:
			// 正在添加模式与删除类状态矛盾
			throw FdoException::Create(NlsMsgGet(SUPERMAP_SCHEMA_DELETED_CLASS_IN_ADDED_SCHEMA,"Conflicting schema element state: a class marked for deletion was found in a schema to be added."));
			break;
		case FdoSchemaElementState_Detached:
			break;
		case FdoSchemaElementState_Modified:
			throw FdoException::Create(NlsMsgGet(SUPERMAP_SCHEMA_MODIFIED_CLASS_IN_ADDED_SCHEMA,"Conflicting schema element state: a class marked for modification was found in a schema to be added."));
			break;
		case FdoSchemaElementState_Unchanged:
			throw FdoException::Create(NlsMsgGet(SUPERMAP_SCHEMA_UNCHANGED_CLASS_IN_ADDED_SCHEMA,"Conflicting schema element state: a class marked unchanged was found in a schema to be added."));
			break;
		default:
			throw FdoException::Create(NlsMsgGet(SUPERMAP_SCHEMA_UNSUPPORTED_ELEMENT_STATE, "Schema element state '%l$d' is not supported.", (int)logicalClass->GetElementState()));
		}
	}
}

void SuperMapLpFeatureSchema::Modify(SuperMapConnection* connection, FdoFeatureSchema* configLogicalSchema, bool ignoreStates)
{
	TRACE(_T("************SuperMapLpFeatureSchema::Modify ()"));

	FdoString* name;
	FdoSchemaElementState state;

	//获取给定的逻辑类集合
	FdoPtr<FdoClassCollection> logicalClasses = configLogicalSchema->GetClasses();

	//处理要素类
	for(int i = 0, size = logicalClasses->GetCount(); i < size; ++i)
	{
		FdoPtr<FdoClassDefinition> logicalClass = logicalClasses->GetItem(i);
		name = logicalClass->GetName();

		//根据是否忽略元素状态的标志进行处理
		state = logicalClass->GetElementState();
		if(ignoreStates)
		{
			FdoPtr<SuperMapLpClassDefinitionCollection> existingClasses = GetLpClasses();
			FdoPtr<SuperMapLpClassDefinition> classDefinition = existingClasses->FindItem(name);
			if(classDefinition = NULL)
			{
				state = FdoSchemaElementState_Added;
			}
			else
			{
				state = FdoSchemaElementState_Modified;
			}
		}

		switch(state)
		{
		case FdoSchemaElementState_Added:
			addClass(connection, logicalClass);
			break;
		case FdoSchemaElementState_Deleted:
			deleteClass(connection, logicalClass);
			break;
		case FdoSchemaElementState_Detached:
			break;
		case FdoSchemaElementState_Modified:
			modifyClass(connection, logicalClass);
			break;
		case FdoSchemaElementState_Unchanged:
			break;
		default:
			;
		}
	}
	/// added by zhouxu 2008-9-11 
	//FdoPtr<SuperMapLpFeatureSchema> schema = m_parentLpSchemas->FindItem(GetName());
	//FdoPtr<SuperMapLpClassDefinitionCollection> newClasses = GetLpClasses();
	//FdoPtr<SuperMapLpClassDefinitionCollection> existingClasses = schema->GetLpClasses();
	//FdoPtr<FdoFeatureSchema> existingLogicalSchema = schema->GetLogicalSchema();
	//FdoPtr<FdoClassCollection> existingLogicalClasses = existingLogicalSchema->GetClasses();
	//FdoPtr<FdoFeatureSchema> newLogicalSchema = GetLogicalSchema();
	//FdoPtr<FdoClassCollection> newLogicalClasses = newLogicalSchema->GetClasses();
	//for(int i = 0; i < newClasses->GetCount(); ++i)
	//{
	//	FdoPtr<SuperMapLpClassDefinition> definition = newClasses->GetItem(i);
	//	existingClasses->Add(definition);
	//	definition->SetParent(schema);
	//	FdoPtr<FdoClassDefinition> cls = newLogicalClasses->GetItem(definition->GetName());
	//	newLogicalClasses->Remove(cls);
	//	existingLogicalClasses->Add(cls);
	//}
}

void SuperMapLpFeatureSchema::addClass(SuperMapConnection *connection, FdoClassDefinition *logicalClass)
{
	TRACE(_T("调用 SuperMapLpFeatureSchema::addClass() 。\n"));
	//确认该类不存在
	FdoPtr<SuperMapLpClassDefinition> oldLpClass = m_lpClasses->FindItem(logicalClass->GetName());
	if(oldLpClass != NULL)
	{
		throw FdoException::Create(FdoException::NLSGetMessage(FDO_NLSID(FDO_126_CLASS_ALREADY_EXISTS),
		logicalClass->GetName()));
	}
	
	// 从给定的逻辑类创建新的逻辑物理类（自动加到父集合中）
	FdoPtr<SuperMapLpClassDefinition> newLpClass = new SuperMapLpClassDefinition(this, connection, NULL, logicalClass);

	//// 把逻辑类添加到逻辑模式中  added by zhouxu 20080926
	//FdoPtr<FdoClassCollection> logicalClasses = m_logicalSchema->GetClasses();
	//logicalClasses->Add(logicalClass);
}

void SuperMapLpFeatureSchema::deleteClass(SuperMapConnection* connection, FdoClassDefinition* logicalClass)
{
	//确定该类是否含有任何数据
	FdoPtr<FdoISelect> select = (FdoISelect*)connection->CreateCommand(FdoCommandType_Select);
	select->SetFeatureClassName(logicalClass->GetQualifiedName());
	FdoPtr<FdoIFeatureReader> reader = select->Execute();
	bool bClassHasData = reader->ReadNext();
	reader->Close();

	//如果要素类任包含数据则不能删除此要素类
	if(bClassHasData)
	{
		throw FdoException::Create(NlsMsgGet(SUPERMAP_CANT_DELETE_NON_EMPTY_CLASS, "Can't delete class '%1$ls'\
			  because it contains data", (FdoString*)logicalClass->GetQualifiedName()));
	}
	
	//通过该类找到对应的逻辑物理类再删除逻辑物理类
	FdoPtr<SuperMapLpClassDefinition> lpClass;
	FdoPtr<SuperMapLpClassDefinitionCollection> lpClasses = this->GetLpClasses();
	int i = 0;
	int size = lpClasses->GetCount();
	for(i = 0; i < size; ++i)
	{
		lpClass = lpClasses->GetItem(i);
		FdoPtr<FdoClassDefinition> classDefinition = lpClass->GetLogicalClass();
		if(0 == wcscmp(classDefinition->GetName(), logicalClass->GetName()))
		{
			break;
		}
	}
	// 判断是找到了目标退出的循环还是循环结束退出的循环
	if(i == size)
	{
		throw FdoException::Create(NlsMsgGet(SUPERMAP_CANT_DELETE_CLASS_NOT_FOUND, "Can't delete class '%1$ls'\
			beacause not find it", logicalClass->GetQualifiedName()));
	}

	lpClass->Delete(connection);
}

void SuperMapLpFeatureSchema::modifyClass(SuperMapConnection* connection, FdoClassDefinition* logicalClass)
{
	//确定是否该类含有任何数据
	FdoPtr<FdoISelect> select = (FdoISelect*)connection->CreateCommand(FdoCommandType_Select);
	select->SetFeatureClassName(logicalClass->GetQualifiedName());
	FdoPtr<FdoIFeatureReader> reader = select->Execute();
	bool bClassHasData = reader->ReadNext();
	reader->Close();

	//如果该类包含数据，抛出异常，否则删除再创建类
	if(bClassHasData)
	{
		throw FdoException::Create(NlsMsgGet(SUPERMAP_CANT_MODIFY_NON_EMPTY_CLASS, "Can't modify class '%1$ls'\
			  because it contains data", (FdoString*)logicalClass->GetQualifiedName()));
	}

	//删除原来的类
	deleteClass(connection, logicalClass);

	//增加新类
	addClass(connection, logicalClass);
}

void SuperMapLpFeatureSchema::Delete(SuperMapConnection* connection)
{
	FdoPtr<FdoISelect> select = (FdoISelect*)connection->CreateCommand(FdoCommandType_Select);
	FdoPtr<FdoIFeatureReader> reader;

	FdoPtr<FdoFeatureSchema> logicalSchema = this->GetLogicalSchema();
	FdoPtr<FdoClassCollection> logicalClasses = logicalSchema->GetClasses();

	//先检查所有的类是否都是空的
	for(int i = 0; i < logicalClasses->GetCount(); ++i)
	{
		FdoPtr<FdoClassDefinition> logicalClass = logicalClasses->GetItem(i);
		select->SetFeatureClassName(logicalClass->GetQualifiedName());
		reader = select->Execute();

		if(reader->ReadNext())
		{
			throw FdoException::Create(NlsMsgGet(SUPERMAP_CANT_DELETE_NON_EMPTY_SCHEMA, "Can't delete schema '%1$ls'\
				because class '%2$ls' contains data", (FdoString*)logicalSchema->GetQualifiedName(),
				(FdoString*)logicalClass->GetQualifiedName()));
		}
		reader->Close();
	}

	// 删除该逻辑物理模式包括的所有逻辑物理类
	FdoPtr<SuperMapLpClassDefinitionCollection> lpClasses = this->GetLpClasses();
	for(int i = 0, size = lpClasses->GetCount(); i < size; ++i)
	{
		FdoPtr<SuperMapLpClassDefinition> lpClass = lpClasses->GetItem(0);
		lpClass->Delete(connection);
	}

	// 从逻辑物理模式集合中移除这个逻辑物理模式
	m_parentLpSchemas->Remove(this);

	// 删除物理数据部分（是否在这删物理文件？）
	m_pDataSource->Close();
	
	// 删除逻辑部分
	FdoPtr<FdoFeatureSchemaCollection> logicalSchemas = m_parentLpSchemas->GetLogicalSchemas();
	logicalSchemas->Remove(m_logicalSchema);
}

////////////////////////////////////////////////////////////////////////
SuperMapLpFeatureSchemaCollection::SuperMapLpFeatureSchemaCollection()
{
	  m_logicalSchemas = FdoFeatureSchemaCollection::Create (NULL);
}

FdoFeatureSchemaCollection* SuperMapLpFeatureSchemaCollection::GetLogicalSchemas()
{
	return FDO_SAFE_ADDREF(m_logicalSchemas.p);
}

SuperMapLpFeatureSchemaCollection::SuperMapLpFeatureSchemaCollection(SuperMapConnection *connection, UGC::UGDataSource *pDataSource)
{
	TRACE(_T("调用 SuperMapLpFeatureSchemaCollection::构造函数() 。\n"));

	VALIDATE_POINTER(pDataSource);
	ConvertPhysicalToLogical(connection, pDataSource);
}

void SuperMapLpFeatureSchemaCollection::ConvertPhysicalToLogical(
	SuperMapConnection *connection, 
	UGC::UGDataSource *pDataSource)
{
	TRACE(_T("调用 SuperMapLpFeatureSchemaCollection::ConvertPhysicalToLogical() 。\n"));

	//创建逻辑模式集合
	m_logicalSchemas = FdoFeatureSchemaCollection::Create(NULL);
    VALIDATE_POINTER(pDataSource);

	//从物理数据源创建逻辑物理模式（自动加到集合中）
	FdoPtr<SuperMapLpFeatureSchema> pLpSchema = new SuperMapLpFeatureSchema(
		this, connection, pDataSource,NULL);
}