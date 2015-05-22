
#include "SMCTest.h"

int main()
{
	
/*	SMCWorkspace workspace;
	SMCDataSource* pDataSource = new SMCDataSource ;
	SMCDatasetVector* pDataset = new SMCDatasetVector;

	//! 测试工作空间打开
	_tstring strWorkspaceName(_T("C:\\TestDS\\World.sxw"));
	//	std::string strWorkspaceName("D:\\World.sxw");

	bool bOpen = workspace.Open(strWorkspaceName);
	if(bOpen)
	{
		std::cout << "工作空间打开成功！" << std::endl;
	}
	else
	{
		std::cout << "工作空间打开失败！" << std::endl;
		return 0;
	}

	//! 测试工作空间中数据源的个数
	std::cout << "数据源个数:   " << workspace.m_DataSources.GetCount() << std::endl;



	//! 测试数据源集合和数据源
	SMCDataSource *pDs = new SMCDataSource();

	if(workspace.m_DataSources.Lookup (_T("world"), pDs))
	{ 
		std::wcout << "数据源的全路径名:   "  << pDs->GetName().c_str() << std::endl; //得到数据源的全路径名
		std::wcout << "数据源引擎名:   " << pDs->GetEngineName().c_str() << std::endl;
		std::cout << "数据源是否已经打开:   " << pDs->IsOpen() << std::endl;
		std::cout << "保存数据信息:   " << pDs->SaveInfo() <<std::endl;
		std::cout << "数据源是否连接:   " << pDs->IsConnected() <<std::endl;
		std::cout << "连接数据库:   " << pDs->Connect() <<std::endl;

		pDs->SetModifiedFlag(true);
		std::cout << "数据源是否已经修改:   " << pDs->IsModified() <<std::endl;
		std::cout << "该数据源中数据集的个数:   " << pDs->GetDatasetCount() << std::endl; 

		SMCDatasetVector *pDst = new SMCDatasetVector();

		if(pDs->GetDataset(_T("Ocean"), (SMCDataset*&)pDst))
		{
			std::cout << "获取名称为Ocean的数据集成功!" << std::endl;
			std::wcout << "名称为Ocean的数据集名称为:   " << pDst->GetName() << std::endl;

			pDst->Open();
			//以下测试数据集中查询到的记录集
			SMCQueryDef def;
			SMCRecordset *pRecordset = new SMCRecordset();
			if(pDst->Query(def, pRecordset))
			{
				std::cout << "记录集获取成功!   " << std::endl; 

				//以下测试记录集的接口pRecordset
				std::cout << "记录集是否有属性数据：  " << pRecordset->HasDBInfo() << std::endl;
				std::cout << "记录集是否有几何数据:   " << pRecordset->HasGeometry() <<std::endl;
				pRecordset->GetDataset(pDst);
				std::cout << "记录集对应的数据集为:   " << pDst->m_pDataset <<std::endl;

				std::cout << "刷新记录集:     " << pRecordset->Refresh() <<std::endl;
				std::cout << "记录集是否为空:   " << pRecordset->IsEmpty() <<std::endl;
				int nRecCount = pRecordset->GetRecordCount();

				std::cout << "记录集的个数为:   " << nRecCount << std::endl;

				while (!pRecordset->IsEOF())
				{
					std::cout << "滚动记录集"  << std::endl;
							//以下测试得到字段值
					SMCVariant var;

					pRecordset->GetFieldValue(1, var);
					std::cout << var.m_nType <<std::endl;
//					std::cout << double(var.m_value) << std::endl;
//					double varvalue = (double)var.m_value;

					pRecordset->MoveNext();

				}
				int nFieldCount = pRecordset->GetFieldCount();
				std::cout << "字段的个数为:   " << nFieldCount << std::endl;

				//以下测试得到字段信息
				//SMCFieldInfos infos;
				//pRecordset->GetFieldInfos(infos);
	//			std::wcout << infos.at(3).m_strName <<  std::endl;
			}
			else
			{
				std::cout << "记录集获取失败!   " << std::endl; 
			}

			delete pRecordset;
		}
		else
		{
			std::cout << "获取索引为0的数据集失败!" << std::endl;
		}

		std::cout << "删除T1数据集:   " << pDs->DeleteDataset(_T("T1")) <<std::endl;



		delete pDst;

	}
	delete pDs;




	//! 测试工作空间中数据源是否为空
	std::cout << "数据源是否为空:   " << workspace.m_DataSources.IsEmpty() << std::endl ;

	//! 测试通过数据源别名查找索引
	std::cout << "别名为world的数据源的索引为:   " << workspace.m_DataSources.FindAlias(_T("world")) << std::endl;

	//! 测试数据源集合的ToXML
//	std::cout << workspace.m_DataSources.ToXML("D:\\World.sxw") << std::endl;

	//! 测试数据源的GetAliasAt
	std::wcout << "索引为0的数据源别名为:   " << workspace.m_DataSources.GetAliasAt(0) << std::endl;

	//! 设置数据源集合为已修改状态
	workspace.m_DataSources.SetModifiedFlag();

	//! 判断数据源集合是否已经修改
	std::cout << "数据源是否修改:   " << workspace.m_DataSources.IsModified() << std::endl;

	//! 测试数据源集合的Rename
	//	std::cout << workspace.m_DataSources.Rename(_T("123"),_T("abc")) << std::endl;


	//! 保存工作空间
	bOpen = workspace.Save();
	if(bOpen)
	{
		std::cout << "工作空间保存成功！" << std::endl;
	}
	else
	{
		std::cout << "数据源获取失败！" << std::endl;
		return 0;
	}

	std::cout << "上面的数据源名应该是： " << ASCII_STRING(pDataSource->GetName()) << std::endl;


	SMCRecordset* pRecordset = new SMCRecordset;
	SMCQueryDef queryDef;

	//! 得到工作空间类型
	int nType = workspace.GetType();
	switch( nType )
	{
		pDataSource->GetDataset(n, (SMCDataset*&)pDataset);
		if(!pDataset->Open())
		{
			std::cout << "数据集打开失败！ " << std::endl;
		}
		if(!pDataset->Query(queryDef, pRecordset))
		{
			std::cout << "查询获取记录集失败！" << std::endl;
		}
		if(pDataset != NULL)
		{
			std::cout << ASCII_STRING(pDataset->GetName()) << "记录集个数： " << pDataset->GetRecordsetCount() << std::endl;
		}
	}




	//! 得到工作空间密码
	std::wstring strPwd = workspace.GetPassword();
	std::wcout << _T("工作空间密码是： ") << strPwd << std::endl;

	//! 关闭工作空间
	workspace.Close();*/

	SMCDataSource	sdbDs;
/*	sdbDs.CreateDataSource(SMCDsConnection::SMEngineType::SDBPlus);
	SMCDsConnection conn;
	conn.m_strServer    =	_T("C:\\TestDS\\World.sdb");
	conn.m_strAlias     =	_T("World");
	sdbDs.SetConnection(conn);

//	std::cout << "创建数据源--C:\\World.sdb   " << sdbDs.Create() << std::endl;

	std::cout << "打开数据源--C:\\TestDS\\World.sdb   " << sdbDs.Open() << std::endl;
	std::cout << "是否成功打开数据源--C:\\TestDS\\World.sdb   " << sdbDs.IsOpen() << std::endl;


	std::cout << "删除数据集--T1:   " << sdbDs.DeleteDataset(_T("T1")) <<std::endl;


	std::wcout << "数据源的全路径名:   "  << sdbDs.GetName().c_str() << std::endl; //得到数据源的全路径名
	std::wcout << "数据源引擎名:   " << sdbDs.GetEngineName().c_str() << std::endl;
	std::cout << "数据源是否已经打开:   " << sdbDs.IsOpen() << std::endl;
	std::cout << "保存数据信息:   " << sdbDs.SaveInfo() <<std::endl;
	std::cout << "数据源是否连接:   " << sdbDs.IsConnected() <<std::endl;
	std::cout << "连接数据库:   " << sdbDs.Connect() <<std::endl;

	sdbDs.SetModifiedFlag(true);
	std::cout << "数据源是否已经修改:   " << sdbDs.IsModified() <<std::endl;
	std::cout << "该数据源中数据集的个数:   " << sdbDs.GetDatasetCount() << std::endl;*/
//	_tstring file(_T("SDB;file=C:\\TestDS\\testds.sdb;user=majun;pwd=majun;"));
//	_tstring file(_T("Ora;server=ugces;database=majun2;user=majun2;pwd=majun2;"));

	sdbDs.OpenDataSource(sdbDs, _T("type=SDB;file=C:\\TestDS\\world.sdb;"));


	std::cout << "是否成功打开数据源--  " << sdbDs.IsOpen() << std::endl;
	std::cout << "删除数据集--T1:   " << sdbDs.DeleteDataset(_T("T1")) << std::endl;
	std::wcout << "数据源的全路径名:   "  << sdbDs.GetName().c_str() << std::endl; //得到数据源的全路径名
	std::wcout << "数据源引擎名:   " << sdbDs.GetEngineName().c_str() << std::endl;
	std::cout << "数据源是否已经打开:   " << sdbDs.IsOpen() << std::endl;
	std::cout << "保存数据信息:   " << sdbDs.SaveInfo() << std::endl;
	std::cout << "数据源是否连接:   " << sdbDs.IsConnected() << std::endl;
	std::cout << "连接数据库:   " << sdbDs.Connect() << std::endl;

	sdbDs.SetModifiedFlag(true);
	std::cout << "数据源是否已经修改:   " << sdbDs.IsModified() << std::endl;
	std::cout << "该数据源中数据集的个数:   " << sdbDs.GetDatasetCount() << std::endl;

//	sdbDs.OpenOraDS();




}




