
/** \file	 SuperMapDescribeSchemaCommand.cpp
*  \author	 郝玉江
*  \attention 
*  Copyright &copy;  1996-2007 SuperMap GIS Technologies,Inc.<br>
*  All Rights Reserved
*  \version 1.0
*  \date 2007-09-19
*  \note : modified by zhouxu 2007-10-23
*/

#include <SuperMap.h>

SuperMapDescribeSchemaCommand::SuperMapDescribeSchemaCommand (FdoIConnection *connection) :
    FdoCommonCommand<FdoIDescribeSchema, SuperMapConnection> (connection)
{
}

/** Do not implement the copy constructor. **/
//SuperMapDescribeSchemaCommand::SuperMapDescribeSchemaCommand (const SuperMapDescribeSchemaCommand &right) { }

SuperMapDescribeSchemaCommand::~SuperMapDescribeSchemaCommand (void)
{
}

/** Do not implement the assignment operator. **/
//SuperMapDescribeSchemaCommand & operator= (const SuperMapDescribeSchemaCommand &right);

/// <summary>Gets the name of the schema to describe. This function is optional;
/// if not specified, execution of the command will describe all schemas.</summary>
/// <returns>Returns the schema name</returns> 
const wchar_t* SuperMapDescribeSchemaCommand::GetSchemaName ()
{
    return (m_SchemaName);
}


/// <summary>Sets the name of the schema to describe. This function is optional; if not
/// specified, execution of the command will describe all schemas.</summary>
/// <param name="value">Input the schema name</param> 
/// <returns>Returns nothing</returns> 
void SuperMapDescribeSchemaCommand::SetSchemaName (const wchar_t* value)
{
    m_SchemaName = value;
}


/// <summary>Executes the DescribeSchema command and returns a 
/// FdoFeatureSchemaCollection. If a schema name is given that has 
/// references to another schema, the dependent schemas will 
/// be returned as well. If the specified schema name does not exist,
/// the Execute method throws an exception.</summary>
/// <returns>Returns the schema collection representing the schema created.</returns> 
FdoFeatureSchemaCollection* SuperMapDescribeSchemaCommand::Execute ()
{
	// writed by zhoux
	TRACE(_T("开始调用 SuperMapDescribeSchemaCommand::Execute 。\n"));
	//SuperMapConfig::Init(); //读配置信息

	FdoPtr<FdoFeatureSchemaCollection> ret; //待返回的逻辑模式集合

	// 获取逻辑模式所在连接
	FdoPtr<SuperMapConnection> smConn = (SuperMapConnection*)GetConnection();
	// 获取逻辑物理模式
	FdoPtr<SuperMapLpFeatureSchemaCollection> lpSchemas = smConn->GetLpSchemas();
	// 获取逻辑模式
	if(lpSchemas != NULL)
	{
		FdoPtr<FdoFeatureSchemaCollection> logicalSchemas = lpSchemas->GetLogicalSchemas();
		VALIDATE_POINTER(logicalSchemas);
		ret = FdoCommonSchemaUtil::DeepCopyFdoFeatureSchemas(logicalSchemas);  
		VALIDATE_POINTER(ret);
	}
	else
	{
		ret = FdoFeatureSchemaCollection::Create(NULL);
	}

	TRACE(_T("结束调用 SuperMapDescribeSchemaCommand::Execute 。\n"));

	////输出模式信息
	//TRACE(_T("通过描述模式命令返回的模式集合信息如下：\n"));
	//TRACE(_T("共有%d个模式 \n"),ret->GetCount());
	//
	//for(FdoInt32 i = 0; i < ret->GetCount(); ++i)
	//{
	//	TRACE(_T("第%d个模式信息如下：\n"), i);
	//	FdoPtr<FdoFeatureSchema> schema = ret->GetItem(i);
	//	TRACE(_T("模式名：%ls \n"), schema->GetName());
	//	FdoPtr<FdoClassCollection> classes = schema->GetClasses();
	//	TRACE(_T("共有%d个要素类\n"), classes->GetCount());
	//	for(FdoInt32 j = 0; j < classes->GetCount(); ++j)
	//	{
	//		FdoPtr<FdoClassDefinition> tmpClass = classes->GetItem(j);
	//		TRACE(_T("第%d个要素类：\n"), j);
	//		TRACE(_T("类名：%ls ---- 类类型： "), tmpClass->GetName());
	//		if(tmpClass->GetClassType() == FdoClassType_Class)
	//			TRACE(_T(" FdoClassType_Class \n"));
	//		else if(tmpClass->GetClassType() == FdoClassType_FeatureClass)
	//			TRACE(_T(" FdoClassType_FeatureClass \n"));
	//		else
	//			TRACE(_T("其他类型 \n"));
	//	}
	//}
 
	return FDO_SAFE_ADDREF(ret.p);
}

