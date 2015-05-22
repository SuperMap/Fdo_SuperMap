/** \file	 SuperMapCreateDataStoreCommand.cpp
*  \brief    该类主要为实现FDO的FdoICreateDataStore接口，完成创建SDB数据源的功能
*  \author	 周旭
*  \attention 
*  Copyright &copy;  1996-2007 SuperMap GIS Technologies,Inc.<br>
*  All Rights Reserved
*  \version 1.0
*  \date 2008-1-23
*/  

#include "SuperMap.h"

SuperMapCreateDataStoreCommand::SuperMapCreateDataStoreCommand(SuperMapConnection* connection):
	 FdoCommonCommand<FdoICreateDataStore, SuperMapConnection> (connection)
{
	m_dataStorePropertyDictionary = new FdoCommonDataStorePropDictionary(connection);

	//定义所有的连接属性
	char* mbPropName = NULL;

	wide_to_multibyte(mbPropName, CONNECTIONPROPERTY_DATASOURCE);
	FdoPtr<ConnectionProperty> newProp = new ConnectionProperty(CONNECTIONPROPERTY_DATASOURCE,
		NlsMsgGet(SUPERMAP_CONNECTION_STRING, "Connection String"),
				// TODO:: 提示信息改为宏，以适合中英文
				//L"连接字符串",
				L"", true, false, false, true, false, false, false, 0, NULL);
	m_dataStorePropertyDictionary->AddProperty(newProp);
}

void SuperMapCreateDataStoreCommand::Execute()
{
	TRACE(_T("调用 SuperMapCreateDataStoreCommand::Execute()... \n"));

	FdoPtr<SuperMapConnection> connection = (SuperMapConnection*)GetConnection ();
	VALIDATE_POINTER(connection);

	if(connection->GetConnectionState() != FdoConnectionState_Closed)
	{
		throw FdoException::Create(NlsMsgGet(SUPERMAP_CONNECTION_ALREADY_OPEN,"supermap connection already open"));
	}

	FdoCommonConnStringParser againparser (NULL, m_dataStorePropertyDictionary->GetProperty(CONNECTIONPROPERTY_DATASOURCE));
	if (!againparser.IsConnStringValid())
	{
		throw FdoException::Create (NlsMsgGet(SUPERMAP_INVALID_CONNECTION_STRING, 
			"Invalid connection string '%1$ls'", 
			connection->GetConnectionString ()));
	}

	FdoStringP databaseName = _(againparser.GetPropertyValue(CONNECTIONPROPERTY_DATABASE));

	UGC::UGString fileName = SuperMapUtil::WcharToString((FdoString*)databaseName).c_str();
	
	// Todo::检查是否有同名文件存在



	// 记住旧的连接串
	FdoStringP oldConnStr = connection->GetConnectionString();

	FdoStringP connStr = L"DataSource=\"type=sdb;database=XXX;IsImage=false\";";
	FdoStringP newConnStr = connStr.Replace(L"XXX",databaseName);

	// Todo::创建物理sdb文件(或者传个标志给connection？)
	connection->SetCreateSDB();
	
	connection->SetConnectionString(newConnStr);
	if(connection->Open() == FdoConnectionState_Open)
	{
		//do sth
		connection->Close();
	}
	else
	{
		//抛出异常 sdb文件创建失败
	}

	//重新设回旧连接串
	connection->SetConnectionString(oldConnStr);



}