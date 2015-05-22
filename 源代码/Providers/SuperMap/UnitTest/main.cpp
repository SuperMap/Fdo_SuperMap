#include <cstddef>
#include <string>
#include <iostream>
#include <tchar.h>
#include <windows.h>

// FDO Headers File
#include <FdoStd.h>
#include <FDO.h>
#include <FdoCommon.h>
#include <FdoGeometry.h>
#include <FdoMessage.h>
#include <SuperMapIniFile.h>

#include "fdoutility.h"
using namespace fdoutility;

/********************************************************************
	转换字符串
********************************************************************/
std::string WcharToString(const wchar_t* wstr)
{
	size_t		nSize;
	char	*ASCIITemp;

	nSize = _tcslen(wstr) * 2;

	ASCIITemp = (char*) malloc (nSize + 1);

	WideCharToMultiByte(
		CP_ACP, /* ANSI code page */
		0, /* no flags */
		wstr, /* wchar_t */
		(int)nSize,
		ASCIITemp,
		(int)nSize,
		NULL, /* Don't worry about other characters */
		NULL  /* Don't worry about other characters */
		);

	ASCIITemp[nSize] = '\0';

	std::string StringTemp(ASCIITemp);

	free(ASCIITemp);

	return StringTemp;
}

/*
#define RETURN_CHECK(x, msg) 	if(NULL == x){ std::cout << msg; return 0;}

#define CONFIG_SECTION	"ProviderConfig"

int _tmain()
{
	SuperMapIniFile inifile;
	inifile.Load("c:\\test.ini");
	inifile.AddSection(CONFIG_SECTION);

	FdoPtr<FdoProviderRegistry> registry = (FdoProviderRegistry *)FdoFeatureAccessManager::GetProviderRegistry();
 
	FdoStringP displayName;
	FdoStringP internalName;
	FdoStringP libraryPath;
	FdoPtr<FdoProvider> provider;
	int count = registry->GetProviders()->GetCount();
	for(int i = 0; i < count; i++) 
	{
		provider = registry->GetProviders()->GetItem(i);
		internalName = provider->GetName();
		displayName = provider->GetDisplayName();
		libraryPath = provider->GetLibraryPath();

		std::cout << "提供者名称：" << WcharToString(internalName) 
				<< "\n显示的名称：" <<  WcharToString(displayName)  
				<< "\n提供者的库：" <<  WcharToString(libraryPath) 
				<< std::endl;
	}

	inifile.SetValue(CONFIG_SECTION, "ProviderName", WcharToString(internalName).c_str());
	inifile.SetValue(CONFIG_SECTION, "ProviderDisplayName", WcharToString(displayName).c_str());
	inifile.SetValue(CONFIG_SECTION, "ProviderLibraryPath", WcharToString(libraryPath).c_str());


	inifile.Save();
	inifile.ClearAll();

	inifile.Load("c:\\test.ini");

	std::cout << "---------------------------------------------" << std::endl;
	std::string strTemp1, strTemp2, strTemp3;
	inifile.GetValue(CONFIG_SECTION, "ProviderName", strTemp1,"");
	inifile.GetValue(CONFIG_SECTION, "ProviderDisplayName", strTemp2, "");
	inifile.GetValue(CONFIG_SECTION, "ProviderLibraryPath", strTemp3, "");

	std::cout << "提供者名称：" << strTemp1 
		<< "\n显示的名称：" <<  strTemp2 
		<< "\n提供者的库：" <<  strTemp3
		<< std::endl;

	inifile.ClearAll();

	std::cout << "建立 OSGeo.SuperMap.1.0 提供者 ..." << std::endl;
	FdoPtr<FdoConnectionManager> connectMgr = (FdoConnectionManager *)FdoFeatureAccessManager::GetConnectionManager();
	FdoPtr<FdoIConnection> fdoConnection = connectMgr->CreateConnection(_T("OSGeo.SuperMap.1.0"));
	RETURN_CHECK(fdoConnection, "建立连接失败... \n");

	FdoPtr<FdoIConnectionInfo> info = fdoConnection->GetConnectionInfo();
	RETURN_CHECK(info, "获取连接信息失败... \n");

	FdoPtr<FdoIConnectionPropertyDictionary> ConnDict = info->GetConnectionProperties();
	RETURN_CHECK(ConnDict, "获取连接属性信息失败... \n");

	FdoInt32 nPropertyCount = 0;
	FdoString ** names = NULL;
	FdoStringP name;
	FdoStringP localname;
	FdoStringP val;
	FdoStringP defaultVal;
	bool isRequired = false;
	bool isProtected = false;
	bool isFilename = false;
	bool isFilepath = false;
	bool isDatastorename = false;
	bool isEnumerable = false;
	FdoInt32 enumCount = 0;
	FdoString ** enumNames = NULL;
	FdoStringP enumName;

	names = ConnDict->GetPropertyNames(nPropertyCount);
	for(int i = 0; i < nPropertyCount; i++)
	{
		name = names[i];
		val = ConnDict->GetProperty(name);
		defaultVal = ConnDict->GetPropertyDefault(name);
		localname = ConnDict->GetLocalizedName(name);
		isRequired = ConnDict->IsPropertyRequired(name);
		isProtected = ConnDict->IsPropertyProtected(name);
		isFilename = ConnDict->IsPropertyFileName(name);
		isFilepath = ConnDict->IsPropertyFilePath(name);
		isDatastorename = ConnDict->IsPropertyDatastoreName(name);
		isEnumerable = ConnDict->IsPropertyEnumerable(name);

		std::cout << "名称：\t\t" << name 
				<< "\n默认值：\t" <<  defaultVal 
				<< "\n本地名称：\t" <<  WcharToString(localname) 
				<< "\n必需：\t\t" <<  (isRequired?"是":"否") 
				<< "\n保护：\t\t" <<  (isProtected?"是":"否")  
				<< "\n文件：\t\t" <<  (isFilename?"是":"否")  
				<< "\n路径：\t\t" <<  (isFilepath?"是":"否")  
				<< "\n数据库名：\t" <<  (isDatastorename?"是":"否")  
				<< "\n列举：\t\t" <<  (isEnumerable?"是":"否") 

				<< std::endl;

		if (isEnumerable) 
		{
			if (isRequired)
			{
				enumNames = ConnDict->EnumeratePropertyValues(name, enumCount);                                             
				for(int j = 0; j < enumCount; j++)
				{
					enumName = enumNames[j];
					std::cout << "列举名称：" << enumName;
				}
				std::cout << std::endl;
			}
		}

	}

	ConnDict->SetProperty(_T("DataSource"), _T("c:\\world.sdb"));

	FdoConnectionState state = fdoConnection->Open();


	std::cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>开始执行Select命令\n";

	FdoPtr<FdoISelect> sampleSelect;
	sampleSelect = (FdoISelect *)fdoConnection->CreateCommand(FdoCommandType_Select);


	sampleSelect->SetFeatureClassName(L"SampleFeatureClass");

	// 建立一个过滤器
	FdoPtr<FdoIdentifier> queryPropertyName;
	queryPropertyName = FdoIdentifier::Create(L"SampleIdentityDataProperty");

	// 2. 建立FdoDataValue
	FdoPtr<FdoDataValue> queryPropertyValue;
	queryPropertyValue = FdoDataValue::Create(101);
	// 3. 调用 FdoComparisonCondition::Create() 建立比较过滤条件

	FdoPtr<FdoFilter> filter;
	filter = FdoComparisonCondition::Create(queryPropertyName, FdoComparisonOperations_EqualTo, queryPropertyValue);
	sampleSelect->SetFilter(filter);
	// 执行查询命令
	FdoPtr<FdoIFeatureReader> queryResults;
	queryResults = sampleSelect->Execute();

	FdoPtr<FdoClassDefinition> classDef;
	FdoPtr<FdoPropertyDefinitionCollection> properties;
	FdoInt32 numProperties = 0;
	FdoPropertyDefinition * propertyDef;
	FdoPropertyType propertyType;
	FdoDataType dataType;
	FdoDataPropertyDefinition * dataPropertyDef;
	FdoString * propertyName = NULL;
	FdoPtr<FdoByteArray> byteArray;
	FdoIGeometry * geometry = NULL;
	FdoGeometryType geometryType = FdoGeometryType_None;
	FdoILineString * linestring = NULL;
	FdoIDirectPosition * position = NULL;
	FdoInt32 dimensionality = FdoDimensionality_XY;
	FdoInt32 numPositions = 0;
	FdoInt32 numInteriorRings = 0;

	// 循环读出几何和数据属性信息
	while (queryResults->ReadNext())
	{
		classDef = queryResults->GetClassDefinition();
		properties = classDef->GetProperties();
		
		numProperties = properties->GetCount();
		for(int i = 0; i < numProperties; i++) 
		{
			propertyDef = properties->GetItem(i);
			propertyName = propertyDef->GetName();
			propertyType = propertyDef->GetPropertyType();
			std::cout << "数据属性名称：" <<  WcharToString(propertyName);
			switch (propertyType) 
			{
			case FdoPropertyType_DataProperty:
				dataPropertyDef = dynamic_cast<FdoDataPropertyDefinition *> (propertyDef);
				dataType = dataPropertyDef->GetDataType();
				switch (dataType) 
				{
				case FdoDataType_Boolean:
					break;
				case FdoDataType_Int32:
					std::cout << "\t数据类型：Int32" << "\t\t值：" << queryResults->GetInt32(propertyName) << std::endl;
					break;
				case FdoDataType_String:
					std::cout << "\t数据类型：字符串" << "\t值：" << WcharToString(queryResults->GetString(propertyName)) << std::endl;
					break;
				default:
					break;
				}
				break;
			case FdoPropertyType_GeometricProperty:
				{
					FdoFgfGeometryFactory * geometryFactory = FdoFgfGeometryFactory::GetInstance();
					byteArray = queryResults->GetGeometry(propertyName);
					geometry = geometryFactory->CreateGeometryFromFgf (byteArray);
					geometryType = geometry->GetDerivedType();
		
					switch (geometryType) 
					{
						case FdoGeometryType_None:
							break;
						case FdoGeometryType_Point:
							std::cout << "\t几何属性类型：点\n" ;
							break;
						case FdoGeometryType_LineString:
							std::cout << "\t几何属性类型：线" ;

							linestring = dynamic_cast<FdoILineString *>(geometry);
							numPositions = linestring->GetCount();

							std::cout << "\t共有" <<  numPositions << "点\n";
							double X, Y, Z, M;
							Z = M = 0;

							for(int i = 0; i < numPositions; i++) 
							{
								position = linestring->GetItem(i);
								if (dimensionality & FdoDimensionality_Z && dimensionality & FdoDimensionality_M)
								{
									X = position->GetX();
									Y = position->GetY();
									Z = position->GetZ();
									M = position->GetM();

								}
								else if (dimensionality & FdoDimensionality_Z && !(dimensionality & FdoDimensionality_M)) 
								{
									X = position->GetX();
									Y = position->GetY();
									Z = position->GetZ();
								}
								else
								{
									X = position->GetX();
									Y = position->GetY();
								}

								std::cout << "X=" << X << "\tY=" << Y << "\tZ=" << Z << "\n";
							}
							break;
						case FdoGeometryType_Polygon:
							std::cout << "\t几何属性类型：面\n" ;
							break;
						case FdoGeometryType_MultiPoint:
							break;
						case FdoGeometryType_MultiLineString:
							break;
						case FdoGeometryType_MultiPolygon:
							break;
						case FdoGeometryType_MultiGeometry:
							break;
						case FdoGeometryType_CurveString:
							break;
						case FdoGeometryType_CurvePolygon:
							break;
						case FdoGeometryType_MultiCurveString:
							break;
						case FdoGeometryType_MultiCurvePolygon:
							break;
						default:
							break;
					}
				}
				
			}
		}
	}
	std::cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<结束执行Select命令\n";


	return 0;
}

*/




int _tmain()
{
	try
	{
		std::wstring provider(L"SuperMap.SuperMap SDX.1.0");

		// Create connection
		FdoPtr<FdoIConnection> conn = fdoutility::create_connection(provider);

		// Connection string with datastore specified
		FdoPtr<FdoIConnectionInfo> info = conn->GetConnectionInfo();

		FdoPtr<FdoIConnectionPropertyDictionary> ConnDict = info->GetConnectionProperties();


		//ConnDict->SetProperty(_T("DataSource"), _T("type=sql;server=192.168.1.76;database=test1;user=fdo;password=fdo;IsImage=false"));
		ConnDict->SetProperty(_T("DataSource"), _T("type=sdb;database=C:\\sdbguass.sdb;IsImage=false"));

		// Open connection
		FdoConnectionState state = conn->Open();

		std::wcout <<  "FdoIConnection::Open()\n";
		std::wcout <<  " State: " << conn->GetConnectionState() << std::endl;

		// Close connection (usually optional)
		conn->Close();

		std::wcout <<  "FdoIConnection::Close()\n";
		std::wcout <<  " State: " << conn->GetConnectionState() << std::endl;
	}
	catch (FdoException* ex)
	{
		std::wcout << L"*** FDO Error:\n";
		int i = 5;
		FdoException* nex = ex;
		while (nex)
		{
			const wchar_t* msg = nex->GetExceptionMessage();
			if (NULL == msg)
			{
				msg = L"NO MESSAGE";
			}
			std::wcout << std::setw(++i) << L"*** " << msg << std::endl;
			nex = nex->GetCause();
		}
		ex->Release();
	}
	catch(std::exception& ex)
	{
		std::cout << "*** Std Error: " << ex.what() << std::endl;
	}
	catch(...)
	{
		std::cout << "*** Undefined error!\n" << std::endl;
	}
	return 0;
}








