#ifndef UGNETWORKTYPES_H
#define UGNETWORKTYPES_H

#include "Base/ugdefs.h"
#include "Algorithm/UGPoint2D.h"
#include "Engine/UGDatasetVector.h"
#include "Geometry/UGGeoLineM.h"
#include "Geometry/UGGeoRegion.h"
namespace UGC {

#define NETWORKINFINITY 10e6
#define SM_NO_MEASURE -9999
#define MAX_RECORD_COUNT 100
#define MAX_TRANSFER_COUNT 5


//邻接弧段存储结构
class UGNeighborArc
{
public:
	UGNeighborArc(UGint nFromArc=-1,UGint nToArc=-1, UGdouble dCost=0.0):m_nFromArc(nFromArc),
		m_nToArc(nToArc),
		m_dCost(dCost) {}
public:
	UGint m_nFromArc;
	UGint m_nToArc;
	UGdouble m_dCost;
};

//邻接节点存储结构
class UGNeighborNode
{
public:
	//UGNeighborNode(UGint nIndex=-1,UGint nArcID=-1, UGdouble dCost=0.0) : m_nIndex(nIndex),
	UGNeighborNode(UGint nIndex=-1,UGint nArcIndex=-1, UGdouble dCost=0.0) : m_nIndex(nIndex),
		//m_nArcID(nArcIndex),
		m_nArcIndex(nArcIndex),
		m_dCost(dCost) {}
public:
	UGint m_nIndex;
	UGint m_nArcIndex;
	UGdouble m_dCost;
};

//路径节点存储结构
class UGPathNode
{
public:
	UGPathNode(){m_nNeighborCount = 0;m_pNeighborNode = NULL;}
	UGbool AddNeighbor(UGint nIndex, UGint nArcID, UGdouble dDist);
	//
	UGbool AddNeighbor(UGint nIndex, UGint nArcIndex);
	
public:
	UGint m_nNeighborCount;
	UGNeighborNode* m_pNeighborNode;
};

//转向节点存储结构
class UGTurnNode
{
public:
	UGTurnNode(){m_nNeighborCount = 0;m_pNeighborArc = NULL;}
	UGbool AddNeighbor(UGint nFromArc,UGint nToArc, UGdouble dCost);
	UGdouble GetTurnCost(UGint nFromArc, UGint nToArc);
	
	//支持多线程
	UGbool AddNeighbor(UGint nFromArc,UGint nToArc,UGint &nInsertPos);
	UGint GetTurnCostIndex(UGint nFromArc, UGint nToArc);
public:
	UGint m_nNeighborCount;
	UGNeighborArc* m_pNeighborArc;
};

//转向节点存储结构
class UGTurnCost
{
public:
	UGTurnCost(){m_nNeighborCount = 0;m_pTurnCost = NULL;}

	UGbool AddTurnCost(UGint nInsertPos,UGdouble dCost);
	UGdouble GetTurnCost(UGint nPos);
	
public:
	UGint m_nNeighborCount;
	UGdouble* m_pTurnCost;
};

//关键元素存储结构
typedef struct tagCriticalOne
{
	UGArray<UGuint>  ForeNbIDs;
	UGArray<UGuint>  BackNbIDs;
	UGArray<UGuint>  ForeRouteIDs;
	UGArray<UGuint>  ForeNoNbIDs;
	UGArray<UGuint>  BackRouteIDs;
	UGArray<UGuint>  BackNoNbIDs;
	
	UGint  nNodeID;
	UGint  nNoNum;
	UGint  nLeftNb;
}CriticalOne;

typedef struct tagTourNode
{
	UGint* pNodeIndex;
	UGint nNodeCount;
}TourNodeIndex;

//关键节点存储结构
typedef struct tagCriticalNode
{
	UGArray<UGuint> NbIDs;
	UGArray<UGuint> RouteIDs;
	UGArray<UGuint> NoNbNums;
	
	UGint  nNodeID;
	UGint  nNoNum;
	UGint  nLeftNb;
}CriticalNode;

//障碍点存储结构
typedef struct tagBarrierNode
{
	UGPathNode* pNode;
	UGint nIndex;
}BarrierNode;

//障碍边存储结构
typedef struct tagBarrierArc
{
	UGint nFNodeIndex;
	UGint nTNodeIndex;
	UGint nArcID;
	UGint nIndex;
}BarrierArc;

//需求点存储结构
typedef struct tagDemandNode
{
	UGint	nDemandID;
	UGdouble	dDemand;
}DemandNode;

typedef struct tagIndex
{
	UGint nID;
	UGint nIndex;
}NetIndex;

//点存储结构
typedef struct tagPointIndex
{
	UGint nIndex;
	UGPoint2D pntNode;
}PointIndex;

typedef struct tagTour
{
	UGint nParentIndex;
	UGint nIndex;
}TourIndex;

//Trace Source
//弧段信息结构
typedef struct tagArcInfo
{
	UGint 	nArcID;
	UGint	nFNodeID;
	UGint	nTNodeID;
}ArcInfo;

typedef struct tagMTSP
{
	UGint	nServiceIndex;
	UGint	nNodeIndex;
	UGdouble	dCost;
}MTSPInfo;

//结果信息结构
typedef struct tagResultInfo
{
	UGint	nOptions;
	
	UGString str_RouteName;
	UGString str_ViaEdgeName;
	UGString str_ViaNodeName;
	UGString str_StopName;
	
	UGString str_PT_Name;
	UGString str_PT_EdgeName;
	UGString str_PT_NodeName;
	
	UGString str_Service_RegionName;
	
	UGString str_Location_NodeName;
	UGString str_Location_CenterName;
}ResultInfo;

//连通性分析关键点和关键边分析需要的结构
typedef struct tagCriticalIndex
{
	UGint nID;
	UGint nOrderNum;
}CriticalIndex;

//中心点数据结构
typedef struct tagCenterNode
{
	UGint	nCandidate;
	UGint	nCenterID;
	UGdouble	dResource;
	UGdouble	dMaxImpedance;
}UGCenterNode;

// 比较函数对象
class NetIndexCompare
{
public:
	UGbool operator()(const NetIndex& netIndex1, const NetIndex& netIndex2) const
	{
		if (netIndex1.nID < netIndex2.nID)
		{
			return true;
		}
		return false;
	}
};


//{{支持多线程
typedef struct tagUGCostFields
{
	UGString strCostName;
	UGString strFTField;
	UGString strTFField;
}UGCostFields;

typedef struct tagUGCostValues
{
	UGdouble *dFTCost;
	UGdouble *dTFCost;
}UGCostValues;

typedef struct tagIniMemory
{
	//UGshort* pbtOnPath;
	UGuchar* pbtOnPath;
	UGdouble* pdNodeCost;
	UGint* pnPrevArcID;
	UGint* pnPrevNodeIndex;
	UGint* pnHeapIndex;
}UGIniMemory;

//转向表结构
typedef struct tagUGTurnCostFields
{
	UGString strTurnCostName;
	UGString strTurnField;
}UGTurnCostFields;

typedef struct tagUGBarriers
{
	UGArray<UGuint> arrBarrierNodeIDs;//障碍点
	UGArray<UGuint> arrBarrierArcIDs;//障碍边
}UGBarriers;
//}}支持多线程

//输出距离矩阵结构单元
typedef struct tagUGDistMatrix
{
	UGuint nFNodeID;
	UGuint nTNodeID;
	UGdouble dCost;
}UGDistMatrixUnit;

//{{行使导引
class  UGElemInfo
{
//{{ by guohui 2008.01.03
public:

	//!	\brief 类型
	enum UGElemType
	{
		ARCELEM		=	0,
		NODEELEM	=	1
	};

	//!	\brief 转向
	enum UGTurnType
	{
		TURNNONE	=	255	,	//	非法值(初始化为该值)
		TERMINUS	=	0	,	//	终点
		TURNLEFT	=	1	,	//	左转
		TURNRIGHT	=	2	,	//	右转
		GOAHEAD		=	3	,	//	直行
		TURNAROUND	=	4		//	掉头
	};

	//!	\brief 方向类型
	enum UGDirectType
	{
		DIRNONE		=	255	,	//	非法值(初始化为该值)
		EAST		=	0	,	//	东
		SOUTH		=	1	,	//	南
		WEST		=	2	,	//	西
		NORTH		=	3	,	//	北
	};

	//!	\brief 转向类型
	enum UGViaTurnType
	{
		VIATURNNONE	=	255	,	//	非法值(初始化为该值)
		ONSIDE		=	0	,	//	在路上
		SIDELEFT	=	1	,	//	在道路左边
		SIDERIGHT	=	2	,	//	在道路右边
	};

//}} by guohui 2008.01.03

public:
	UGElemInfo()
	{
		bViaNode	= FALSE;
		nElemID		= -1;
		nNodeNO		= -1;
		dElemCost	= 0;
		dLength		= 0;
		dAngle		= -1;
		dDirection	= -1;
		bViaTurnType= 0;
		strElemName	= ("");

		//{{ by guohui 2008.01.03
		bTurnType = TURNNONE;
		bDirectType = DIRNONE;
		bViaTurnType = VIATURNNONE;
		//}} by guohui 2008.01.03
	};
	
	~UGElemInfo()
	{
	};
	
public:	
	
	UGElemInfo& operator=(const UGElemInfo& ElemInfo)
	{
		bViaNode		= ElemInfo.bViaNode;
		nElemID			= ElemInfo.nElemID;
		nNodeNO			= ElemInfo.nNodeNO;
		bElemType		= ElemInfo.bElemType;
		bTurnType		= ElemInfo.bTurnType;
		bDirectType		= ElemInfo.bDirectType;
		bViaTurnType	= ElemInfo.bViaTurnType;
		dElemCost		= ElemInfo.dElemCost;
		dLength			= ElemInfo.dLength;
		dAngle			= ElemInfo.dAngle;
		dDirection		= ElemInfo.dDirection;
		strElemName		= ElemInfo.strElemName;
		rcBound			= ElemInfo.rcBound;
		
		return *this;
	};
	/*   (1)  如果是路由点，则 bViaNode = true,bElemType = NODEELEM.此时使用 bViaTurnType 
	*         变量中的值。路由点只存在“在路上”、“在道路左边”、“在道路右边”三种状态。
	*    (2)  如果是弧段，则 bViaNode = false,bElemType = SIDEELEM.此时使用 bDirectType 
	*		  变量中的值。路由点只存在“东”、“南”、“西”、“北”四种状态。
	*    (3)  如果是网络结点，则 bViaNode = false,bElemType = NODEELEM.此时使用 bTurnType 
	*		  变量中的值。路由点只存在“终点”、“左转”、“右转”、“直行”、“调头”五种状态。
	*/
public:
	
	//是否是路由点
	UGbool	bViaNode;

	//弧段或结点的ID
	UGint	nElemID;

	//路由点标号或无名结点或弧段的标号
	UGint	nNodeNO;

	// 0---弧段	1---结点
	// 请使用 UGElemType 枚举常量
	UGbyte	bElemType;

	// 0---终点	1---左转	2---右转	3---直行	4--调头
	// 请使用 UGTurnType 中的枚举常量
	UGbyte	bTurnType;

	//0---东	1---南	2---西	3---北
	// 请使用 UGDirectType 枚举常量
	UGbyte	bDirectType;

	//0---在路上	1---在道路左边	-1---在道路右边
	// 请使用 UGViaTurnType 枚举常量
	UGshort	bViaTurnType;

	//通过弧段或结点的阻力值
	UGdouble	dElemCost;

	//弧段的长度
	UGdouble	dLength;

	//通过结点的转向角度(角度)
	UGdouble	dAngle;

	//弧段起点和重点和X正方向的夹角
	UGdouble	dDirection;

	//弧段或结点的名称(无名称弧段或结点统一称为"Anonymous")
	UGString strElemName;

	//对象范围
	UGRect2D rcBound;

	//路由点到弧段的距离
	UGdouble	dDist;
};

typedef UGArray<UGElemInfo> UGElemInfos;

class  UGPathGuide
{
public:
	UGPathGuide()
	{
		nRouteID	= 1;
	};
	
    //如果放开，就会出现拷贝函数的问题!
	/*
	UGPathGuide(UGPathGuide& PathGuide)
	{
		ElemInfos.RemoveAll();
		ElemInfos.Append(PathGuide.ElemInfos);
		
		nRouteID = PathGuide.nRouteID;
	};
	*/

	~UGPathGuide()
	{
		ElemInfos.RemoveAll();
	};
	
public:	
	UGint Add(UGElemInfo ElemInfo)
	{
		return ElemInfos.Add(ElemInfo);
	};
	
	UGint Append(UGPathGuide& PathGuide)
	{
		return ElemInfos.Append(PathGuide.ElemInfos);
	};
	
	void RemoveAll()
	{
		ElemInfos.RemoveAll();
		nRouteID = 1;
	};
	
	UGPathGuide& operator=(const UGPathGuide& PathGuide)
	{
		ElemInfos.RemoveAll();
		ElemInfos.Append(PathGuide.ElemInfos);
		
		nRouteID = PathGuide.nRouteID;
		
		return *this;
	};
	
public:
	//该结构数组由结点和弧段交替出现
	UGElemInfos ElemInfos;
	UGint nRouteID;
};

typedef UGArray<UGPathGuide> UGPathGuides;
//}}行使导引

//{{坐标点转换 
typedef struct tagNodeInfo
{
	UGbool	bNode;
	UGshort	btDirection;
	UGint	ArcID;
	UGint	NodeID;
	UGint	FromID;
	UGint	ToID;
	
	UGdouble	dDist;
	UGdouble	dPos;
	
	UGdouble	ForwardCost;
	UGdouble	BackwardCost;
	
	UGPoint2D pntNode;
	
	tagNodeInfo ()
	{
		bNode = FALSE;
		dDist = -1.0;
	};
}UGNodeInfo;

typedef UGArray<UGNodeInfo> UGNodeInfos;

typedef UGArray<NetIndex> UGNetIndexs;

typedef UGArray< UGGeometry*> UGGeometrys;
typedef UGArray<UGdouble> UGLengths;

typedef struct tagElemIDsInfo
{
	UGNetIndexs		NetIndexs;
	UGGeometrys		Geometrys;
	UGStrArray   	Names;
	UGLengths		Lengths;
}UGElemIDsInfo;

typedef UGArray<UGElemIDsInfo> UGElemIDsInfos;
//}}坐标点转换 CP2007移植

//{{网络分析传入分析信息和输出分析结果
typedef struct tagPathGuideName
{
	UGString strNodeName;
	UGString strArcName;
}UGPathGuideName;

typedef struct tagViaInfo
{
	//UGint nCount; //! 大小是Array大小，没有必要存储
	UGArray<UGuint> arrViaIDs;
}UGViaInfo;

typedef struct tagStopInfo
{
	//UGint nCount;//! 大小是Array大小，没有必要存储
	UGArray<UGuint>   arrViaIndex;
	UGArray<UGdouble> arrCost;
}UGStopInfo;

typedef struct tagDemandResInfo
{
    UGuint   nNodeID;
	UGuint   nCenterID;
	UGdouble dCost;
}UGDemandResInfo;

typedef struct tagRetCenterInfo
{
    UGuint   nCenterType;
	UGuint   nCenterID;
	UGdouble dResources;
	UGdouble dMaxIMP;
	UGdouble dAltCost;
	UGdouble dAltDemand;
	UGdouble dAltResources;
	UGdouble dAveCost;
}UGRetCenterInfo;

//! 结果输出结果
typedef struct tagUGResultInfo
{
	//! 选择需要存储的结果模式
	//! 采用基类 UGNetworkAnalystEnv::UGResultInfoType 来赋值
	UGint nOptions;

	//! 结果路径路由信息
	UGArray<UGGeoLineM> arrLineM;
    //! 服务区分析面数据集
	UGArray<UGGeoRegion> arrRegion;
	//! 行驶导引信息
	UGPathGuides PathGuides; 
	//! 经过网络节点信息
	UGArray<UGViaInfo> arrViaPT; 
	//! 经过弧段信息
	UGArray<UGViaInfo> arrViaArc;
	//! 经过站点信息
	UGArray<UGStopInfo> arrViaStop;
	//! 分析花费（最近设施分析时采用该cost）
	UGArray<UGdouble> arrCost;
	//! 需求点信息 选址分析用
    UGArray<UGDemandResInfo> arrDemand;
    //! 中心点信息 选址分析用
	UGArray<UGRetCenterInfo> arrRetCenter;
	//{{ 2007.12.24 by guohui 
	tagUGResultInfo()
	{
		nOptions = 0 ;
	}
	//}} 2007.12.24 by guohui
	void Clear()
	{
		arrLineM.RemoveAll();
		arrRegion.RemoveAll();
		PathGuides.RemoveAll();
		arrViaPT.RemoveAll();
		arrViaArc.RemoveAll();
		arrViaStop.RemoveAll();
		arrCost.RemoveAll();
		arrDemand.RemoveAll();
		arrRetCenter.RemoveAll();
	}
}UGResultInfo;

//! 结果保存格式说明
typedef struct tagUGAnalyseParams
{
	//! 特别需要，需要修改选择需要存储的结果模式
	//! 采用基类 UGNetworkAnalystEnv::UGResultInfoType 来赋值
	UGint nOptions;

	//! 行使导引需要的网络节点和网络弧段的字段名称
	//UGPathGuideName  strPathFeildNames;

	//! 网络分析路径点,设施点,配送点节点ID数组,
	UGArray<UGuint> arrViaNodeIDs;
    //! 网络分析路径点,设施点,配送点坐标点数组
	UGPoint2Ds      arrViaPoints;
	
	//! 物流配送中心点ID数组
	UGArray<UGuint> arrCenterNodeIDs;
    //! 物流配送中心点坐标点数组
	UGPoint2Ds arrCenterPoints;
	
	//! 障碍点
	UGArray<UGuint> arrBarrierNodeID;
	//! 障碍边
	UGArray<UGuint> arrBarrierArcID;
	
	//! 最近设施查找事件点ID
	UGint nNodeID;
	//! 最近设施查找事件坐标点
	UGPoint2D PointEvent;
	//! 最近设施查找个数
	UGint nSearchCount;
	
	//旅行商的迭代次数
	//UGint nIterations;
    //! 花费,服务半径
	UGArray<UGdouble > arrNodeIDCosts;
	
	//! 资源分配模式
	UGint nMode;
	//! 是否从中心开始分配
	UGbool bFromCenter;
	//! 是否连通
	UGbool bConnected;
	
	//! 阻力字段的别名，用来获取正向阻力字段和反向阻力字段，必须设置
	UGString strCostName;
	//! 转向字段名称
	UGString strTurnCostName;
	
	//! 这个需要废弃
	//ResultInfo ResInfo;
	//! 用来输出结果和获取结果 现在输出参数和这个分开处理了
	//UGResultInfo ResInfoOut;

	//{{ 2007.12.24 by guohui 
	tagUGAnalyseParams()
	{
		nOptions = 0 ;
	}
	//}} 2007.12.24 by guohui 
}UGAnalyseParams;

//设施网络分析参数设置信息
typedef struct tagUGUtilityAnalyseParams
{
	//设施网络分析
	UGint nTraceID;
	UGint nEndID;
	UGint nSearchMode;
	UGArray<UGuint> arrTraceIDs;
	
	UGArray<UGuint> arrBarrierNodeID;//障碍点
	UGArray<UGuint> arrBarrierArcID;//障碍边
	
	UGString strCostName;
	
	UGbool bFindConnected;
	UGbool bCreateFeild;
	UGbool bFindWithoutLoops;
	
	tagUGUtilityAnalyseParams()
	{
		bFindWithoutLoops = TRUE;
		bCreateFeild      = FALSE;
	};	
}UGUtilityAnalyseParams;
//}}网络分析传入分析信息和输出分析结果

//{{公交换乘
typedef struct tagUGBusNetworkDT
{
	UGDatasetVector* pDTBusLine;
	UGDatasetVector* pDTBusStop;
	UGDatasetVector* pDTBusNetwork;
}UGBusNetworkDT;

typedef struct tagUGTransferParams
{
	UGint nFromID;
	UGint nToID;
	
	UGString strFromName;
	UGString strToName;
	
	UGString strCostName;
	
	UGPoint2D pntFrom;
	UGPoint2D pntTo;
	
	//设置优先级
	UGbool bPriority;
	UGArray<UGint> arrPriLineIDs;
	//UGQueryDef QueryDef;
	
	//预定换乘方案数
	UGint nTransferCount;
	
	tagUGTransferParams()
	{
		nFromID		= -1;
		nToID		= -1;
		bPriority	= FALSE;
		nTransferCount = MAX_TRANSFER_COUNT;
		
		strFromName.Empty();
		strToName.Empty();
	};
	
}UGTransferParams;

class NETWORKANALYST_API UGBusRouting
{
public:
	UGBusRouting();
	~UGBusRouting();

public:
	UGint nRouteIndex;
	UGint nFromIndex;
	UGint nToIndex;
	
	UGint nRouteID;
	UGint nFromID;
	UGint nToID;
	
	UGdouble dCost;
	UGdouble dLength;
	
	UGString strFromStopName;
	UGString strToStopName;
	UGString strRouteName;
};

typedef UGArray<UGBusRouting> UGBusRouteings;

class NETWORKANALYST_API UGRouteResult
{
public:
	UGRouteResult();
	~UGRouteResult();
	UGbool Add(UGBusRouting& BusRouteing);

public:
	UGArray<UGBusRouting> BusRouteings;
	//UGBusRouting* pBusRouteings;
	UGint nCount;
	
	UGdouble dCost;
};

typedef UGArray<UGRouteResult> UGRouteResults;

class UGBusStop
{
public:
	UGBusStop();
	~UGBusStop();
	
	UGbool SetStopID(UGint nStopID);
	UGbool AddRoute(UGint nRouteID);
	//UGbool GetPassRoutes(UGArray<UGint>& arrRouteID);
	
public:
	
	UGint nIndex;
	UGint nRouteCount;
	UGint* pRoutes;
	UGint* pIndexs;
	//UGString strName;
};
typedef UGArray<UGBusStop*> UGBusStops;

class UGBusRoute
{
public:
	UGBusRoute();
	~UGBusRoute();
	
	UGbool SetRouteID(UGint nRouteID);
	UGbool AddStop(UGint nStopID, UGbool bForward=TRUE);
	UGbool GetStops(UGArray<UGint>& arrStopID);
	
public:
	
	UGint nIndex;
	UGint* pStopIndexs;
	UGint* pStopIDs;
	UGdouble* pdMeasures;
	UGdouble* pdPositions;
	UGint nStopCount;
	UGint nDirection;
	UGbool bDirty;
	//UGString strName;
	//UGbool bPriority;//考虑多线程就不能用了
};

typedef UGArray<UGBusRoute*> UGBusRoutes;

typedef struct tagUGBusNetworkParam
{
	UGint nLineID;
	//UGint nRouteID;
	UGint nStopID;
	UGint nMergeStopID;
	UGint nIndex;
	UGdouble dMeasure;
	UGdouble dPosition;
	
	tagUGBusNetworkParam()
	{
		//nRouteID		= -1;
		nMergeStopID	= -1;
		nStopID			= -1;
		nIndex			= -1;
	};
	
}UGBusNetworkParam;
typedef UGArray<UGBusNetworkParam*> UGBusNetworkParams;

class UGSingleRoute
{
public:
	UGSingleRoute();
	~UGSingleRoute();

public:	
	UGint nLineID;
	//UGint nRouteID;
	UGint nStopCount;
	UGint* pStopIDs;
	UGint* pMergeIDs;
	UGdouble* pdMeasures;
	UGdouble* pdPositions;
};
typedef UGArray<UGSingleRoute*> UGSingleRoutes;

typedef struct tagUGRelRoute
{
	UGint nLineID;
	//UGint nRouteID;
	UGint nDirection;
	UGdouble dCost;
	UGString strName;
}UGRelRoute;
typedef UGArray<UGRelRoute*> UGRelRoutes;

typedef struct tagUGRelStop
{
	UGint nID;
	UGint nMergeID;
	UGString strName;
}UGRelStop;
typedef UGArray<UGRelStop*> UGRelStops;

//按nLineID从小到大进行排序
class RelRouteCompare
{
public:
	UGbool operator()(const UGRelRoute* netIndex1, const UGRelRoute* netIndex2) const
	{
		if (netIndex1->nLineID < netIndex2->nLineID)
		{
			return TRUE;
		}
		return FALSE;
	}
};

//按nLineID(主)和dPosition(从)从小到大进行排序
class BusNetworkParamCompare
{
public:
	UGbool operator()(const UGBusNetworkParam* netIndex1, const UGBusNetworkParam* netIndex2) const
	{
		if (netIndex1->nLineID < netIndex2->nLineID)
		{
			return TRUE;
		}
		else if (netIndex1->nLineID == netIndex2->nLineID)
		{
			if (netIndex1->dPosition < netIndex2->dPosition)
			{
				return TRUE;
			}
		}
		
		return FALSE;
	}
};

typedef struct tagUGResultRouteInfo
{
	UGbyte btPriority;
	UGint nRouteIndex;
	UGint nTransferCount;
	UGdouble dCost;
}UGResultRouteInfo;
typedef UGArray<UGResultRouteInfo*> UGResultRouteInfos;

class CostCompare
{
public:
	UGbool operator()(const UGResultRouteInfo* netIndex1, const UGResultRouteInfo* netIndex2) const
	{
		if (netIndex1->nTransferCount < netIndex2->nTransferCount)
		{
			return TRUE;
		}
		else if (netIndex1->nTransferCount == netIndex2->nTransferCount)
		{
			if (netIndex1->btPriority < netIndex2->btPriority)
			{
				return TRUE;
			}
			else if  (netIndex1->btPriority == netIndex2->btPriority)
			{
				if (netIndex1->dCost < netIndex2->dCost)
				{
					return TRUE;
				}
			}
		}
		
		return FALSE;
	}
};
//}}公交换乘

//堆排序结构
class UGHeap
{
public:
	UGHeap(UGint* pnHeapIndex,UGdouble* dCost);
	~UGHeap();
	UGint GetMinCostIndex();
	void Insert(const UGint lItem);
	void Update(const UGint lIndex);
	UGint GetSize();
private:
	UGbool Compare(const UGint nNode1,const UGint nNode2);
private:
	UGArray <UGint> m_SearchedList;
	UGdouble* m_pdCost;
	UGint*	m_pnHeapIndex;
};

}

#endif

