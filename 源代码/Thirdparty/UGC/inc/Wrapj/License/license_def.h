#if !defined(_LICENSE_DEF_)
#define _LICENSE_DEF_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


const long STRLENGTH = 256;

enum Module
{
//sfc has defined:
	emdSuperMapDeveloper	=0x08,//8
	emdSuperMapRuntime		=0x09,//9
	emdSuper3DDeveloper		=0x0A,//10
	emdSuper3DRuntime		=0x0B,//11
	emdSuperTopoDeveloper	=0x0C,//12
	emdSuperTopoRuntime		=0x0D,//13
	emdSuperLytDeveloper	=0x0E,//14
	emdSuperLytRuntime		=0x0F,//15
	emdSuperAnalystDeveloper=0x10,//16
	emdSuperAnalystRuntime  =0x11,//17									
	emdSuperMapDeskpro		=0x12,//18
	emdSuperMapISAdv		=0x13,//19
	emdSuperMapExpress		=0x14,//20	
	emdSuperMapSDXDev		=0x15,//21
	emdSuperMapISDev		=0x16,//22	
	emdSuperMapISPro		=0x17,//23
	emdSuperMapSDXRt		=0x18,//24
	emdSuperMapDBuilder		=0x19,//25
	
	emdSuperMapDProducer	=0x1A,//26
	emdSuperMapDChecker		=0x1B,//27
	emdSuperMapWaterGIS		=0x1C,//28

//objects java
	emdJDataDeveloper				=0x20,//32
	emdJDataRuntime					=0x21,//33
	emdJMappingDeveloper			=0x22,//34
	emdJMappingRuntime				=0x23,//35
	emdJSceneDeveloper				=0x24,//36
	emdJSceneRuntime				=0x25,//37
	emdJTopoDeveloper				=0x26,//38
	emdJTopoRuntime					=0x27,//39
	emdJLytDeveloper				=0x28,//40
	emdJLytRuntime					=0x29,//41
	emdJSpatialAnalystDeveloper		=0x2A,//42
	emdJSpatialAnalystRuntime		=0x2B,//43
	emdJNetworkAnalystDeveloper		=0x2C,//44
	emdJNetworkAnalystRuntime		=0x2D,//45									
	emdJ3DAnalystDeveloper			=0x2E,//46
	emdJ3DAnalystRuntime			=0x2F,//47
	emdJConversionDeveloper			=0x30,//48
	emdJConversionRuntime			=0x31,//49								
	emdJGridAnalystDeveloper		=0x32,//50
	emdJGridAnalystRuntime			=0x33,//51									
	emdJImageAnalystDeveloper		=0x34,//52
	emdJImageAnalystRuntime			=0x35,//53
		
//objects .NET
	emdNDataDeveloper				=0x40,//64
	emdNDataRuntime					=0x41,//65
	emdNMappingDeveloper			=0x42,//66
	emdNMappingRuntime				=0x43,//67
	emdNSceneDeveloper				=0x44,//68
	emdNSceneRuntime				=0x45,//69
	emdNTopoDeveloper				=0x46,//70
	emdNTopoRuntime					=0x47,//71
	emdNLytDeveloper				=0x48,//72
	emdNLytRuntime					=0x49,//73
	emdNSpatialAnalystDeveloper		=0x4A,//74
	emdNSpatialAnalystRuntime		=0x4B,//75
	emdNNetworkAnalystDeveloper		=0x4C,//76
	emdNNetworkAnalystRuntime		=0x4D,//77										
	emdN3DAnalystDeveloper			=0x4E,//78
	emdN3DAnalystRuntime			=0x4F,//79
	emdNConversionDeveloper			=0x50,//80
	emdNConversionRuntime			=0x51,//81									
	emdNGridAnalystDeveloper		=0x52,//82
	emdNGridAnalystRuntime			=0x53,//83										
	emdNImageAnalystDeveloper		=0x54,//84
	emdNImageAnalystRuntime			=0x55,//85										

//deskpro .NET:
	emdNDeskpro							=0x57,//87

	// iServer .NET
	emdNiServerData						=0x60,//96
	emdNiServerMapping					=0x61,//97
	emdNiServerCluster					=0x62,//98
	emdNiServerTrafficTransferAnalyst	=0x63,//99
	emdNiServerNetworkAnalyst			=0x64,//100
	emdNiServerSpatialAnalyst			=0x65,//101
	

// iServer Java	
	emdJiServerData						=0x66,//102
	emdJiServerMapping					=0x67,//103
	emdJiServerCluster					=0x68,//104
	emdJiServerTrafficTransferAnalyst	=0x69,//105
	emdJiServerNetworkAnalyst			=0x6A,//106
	emdJiServerSpatialAnalyst			=0x6B,//107

//注意，最大不能超过112，即0x70
};


#define LABEL_JDataDeveloper				("JDataDeveloper")
#define LABEL_JDataRuntime					("JDataRuntime")
#define LABEL_JMappingDeveloper				("JMappingDeveloper")
#define LABEL_JMappingRuntime				("JMappingRuntime")
#define LABEL_JSceneDeveloper				("JSceneDeveloper")
#define LABEL_JSceneRuntime					("JSceneRuntime")
#define LABEL_JTopoDeveloper				("JTopoDeveloper")
#define LABEL_JTopoRuntime					("JTopoRuntime")
#define LABEL_JLytDeveloper					("JLytDeveloper")
#define LABEL_JLytRuntime					("JLytRuntime")
#define LABEL_JSpacialAnalystDeveloper		("JSpatialAnalystDeveloper")
#define LABEL_JSpacialAnalystRuntime		("JSpatialAnalystRuntime")
#define LABEL_JNetworkAnalystDeveloper		("JNetworkAnalystDeveloper")
#define LABEL_JNetworkAnalystRuntime		("JNetworkAnalystRuntime")
#define LABEL_J3DAnalystDeveloper			("J3DAnalystDeveloper")
#define LABEL_J3DAnalystRuntime				("J3DAnalystRuntime")
#define LABEL_JConversionDeveloper			("JConversionDeveloper")
#define LABEL_JConversionRuntime			("JConversionRuntime")
#define LABEL_JGridAnalystDeveloper			("JGridAnalystDeveloper")
#define LABEL_JGridAnalystRuntime			("JGridAnalystRuntime")
#define LABEL_JImageAnalystDeveloper		("JImageAnalystDeveloper")
#define LABEL_JImageAnalystRuntime			("JImageAnalystRuntime")

#define LABEL_NDataDeveloper				("NDataDeveloper")
#define LABEL_NDataRuntime					("NDataRuntime")
#define LABEL_NMappingDeveloper				("NMappingDeveloper")
#define LABEL_NMappingRuntime				("NMappingRuntime")
#define LABEL_NSceneDeveloper				("NSceneDeveloper")
#define LABEL_NSceneRuntime					("NSceneRuntime")
#define LABEL_NTopoDeveloper				("NTopoDeveloper")
#define LABEL_NTopoRuntime					("NTopoRuntime")
#define LABEL_NLytDeveloper					("NLytDeveloper")
#define LABEL_NLytRuntime					("NLytRuntime")
#define LABEL_NSpacialAnalystDeveloper		("NSpatialAnalystDeveloper")
#define LABEL_NSpacialAnalystRuntime		("NSpatialAnalystRuntime")
#define LABEL_NNetworkAnalystDeveloper		("NNetworkAnalystDeveloper")
#define LABEL_NNetworkAnalystRuntime		("NNetworkAnalystRuntime")
#define LABEL_N3DAnalystDeveloper			("N3DAnalystDeveloper")
#define LABEL_N3DAnalystRuntime				("N3DAnalystRuntime")
#define LABEL_NConversionDeveloper			("NConversionDeveloper")
#define LABEL_NConversionRuntime			("NConversionRuntime")
#define LABEL_NGridAnalystDeveloper			("NGridAnalystDeveloper")
#define LABEL_NGridAnalystRuntime			("NGridAnalystRuntime")
#define LABEL_NImageAnalystDeveloper		("NImageAnalystDeveloper")
#define LABEL_NImageAnalystRuntime			("NImageAnalystRuntime")

#define LABEL_NDeskpro			("NDeskpro")

#define LABEL_JiServerPro		("JiServerPro")
#define LABEL_JiServerEtp		("JiServerEtp")
#define LABEL_NiServerPro		("NiServerPro")
#define LABEL_NiServerEtp		("NiServerEtp")


#define LABEL_JiServerData						("JiServerData")
#define LABEL_JiServerMapping					("JiServerMapping")
#define LABEL_JiServerCluster					("JiServerCluster")
#define LABEL_JiServerTrafficTransferAnalyst	("JiServerTrafficTransferAnalyst")
#define LABEL_JiServerNetworkAnalyst			("JiServerNetworkAnalyst")
#define LABEL_JiServerSpatialAnalyst			("JiServerSpatialAnalyst")

#define LABEL_NiServerData						("NiServerData")
#define LABEL_NiServerMapping					("NiServerMapping")
#define LABEL_NiServerCluster					("NiServerCluster")
#define LABEL_NiServerTrafficTransferAnalyst	("NiServerTrafficTransferAnalyst")
#define LABEL_NiServerNetworkAnalyst			("NiServerNetworkAnalyst")
#define LABEL_NiServerSpatialAnalyst			("NiServerSpatialAnalyst")


#define LABEL_USER ("User")
#define LABEL_COMPANY ("Company")
#define LABEL_LICMODE ("LicMode")
#define LABEL_LICFILEPATH ("LicPath")

enum FunctionID
{
	efnGetUserInfo = 1,			// 得到许可中的用户信息
	efnVerifyLicense = 2,		// 验证许可是否正确
	efnOpenLock = 3,			// 打开网络锁
	efnCloseLock = 4,			// 关闭网络锁
};
// 许可保护方式
enum LicMode
{
	Aladdin = 1, // 阿拉丁
	LM   = 2, // LM
	ComputerName = 3, // 计算机名
};

#endif // !defined(_LICENSE_DEF_)