/* 
	\file UGTrafficAnalyst.h
	\brief 交通网络分析类
	\author ugc team
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>更新说明：</b>
	<em>1、第一条说明。</em>
	<em>2、第二条说明。</em>
*/

#ifndef UGTRAFFICANALYST_H
#define UGTRAFFICANALYST_H

#include "NetworkAnalyst/UGNetworkAnalyst.h"
#include "Base/ugdefs.h"

namespace UGC {

class NETWORKANALYST_API UGTrafficAnalyst  : public UGNetworkAnalyst
{
public:
	UGTrafficAnalyst();

	virtual ~UGTrafficAnalyst();
	
	/*!	\brief	路径分析模式：*/
	enum	UGFindPathType
	{
		UGFPTMinWeight		= 1,	//最小权值;			适用于一般的最佳最短路径分析；
		UGFPTMinEdgesSum	= 2		//最少弧段最小阻值；满足于特殊需求的路径分析；
	};
	
	/*!	\brief	资源分配模式：*/
	enum	UGAllocateType
	{
		UGATNodes			= 1,	//节点需求：	分配过程中只考虑节点需求；
		UGATEdges			= 2,	//弧段需求：	分配过程中只考虑弧段需求；
		UGATNodesAndEdges	= 3		//节点和弧段需求：	分配过程考虑节点和弧段需求
	};
	
	/*!	\brief	选址模式：*/
	enum	UGLocateAllocateType
	{
		UGLATMinCost		=1,	//最小权值：	适用于：仓库，批发站等的选址；考虑运输成本最少；
		UGLATMaxCover		=2,	//最大覆盖：	适用于: 急救服务设施选址(比如消防站，急救中心等)；一般不需要考虑资源量；
		UGLATMinCostPower	=3,	//最小变异权值：适用于：公共服务设施等选址(比如图书馆等)；既考虑总距离最少又考虑公平原则；
		UGLATMaxAttend		=4	//最大流量：	适用于：零售点,餐馆选址；考虑最大光顾量；
	};
	
	/*!	\brief	物流配送模式：*/
	enum	UGMTSPType
	{
		UGMTSPMinTotalCost			= 1,	
		UGMTSPMinEachCost			= 2	
	};

	//! 为了支持多线程,网络分析接口已经将网络节点和坐标点模式,统一到一个接口里面

	//!	\brief	最短路径分析
	//!	\param AnalyseParams 路径分析参数设置[in]
	//!	\param arrViaNodeID		顺序结点ID表[in]
	//! \param arrViaPoints     顺序坐标点[in]
	//!	\param bLeastEdgesSum   是否弧段最少[in]
	//!	\return	成功:返回结果Route的Weight；任何异常和错误将返回-1.0。
	UGdouble FindPath(const UGAnalyseParams &AnalyseParams, UGResultInfo& ResInfoOut,UGbool bLeastEdgesSum = FALSE);

	//!	\brief	旅行商分析
	//!	\param AnalyseParams 旅行商分析参数设置[in]
	//!	\param arrViaNodeID         游历结点ID表[in]
	//!	\param bEndNodeSigned		是否指定终点[in]
	//!	\return	成功:返回结果Route的Weight；任何异常和错误将返回-1.0；
	//!	\remarks 指定终点可以分终点和起点相同和不同两种。
	UGdouble FindTSPPath(const UGAnalyseParams &AnalyseParams,UGResultInfo& ResInfoOut,UGbool bEndNodeSigned);

	//!	\brief	最近设施分析：求指定事件点的最近设施 
	//!	\param AnalyseParams 最近设施分析参数设置[in]
	//!	\param nEventID			事件ID[in]
	//!	\param pntEvent			事件点坐标[in]
	//!	\param arrFacilityID	设施ID表[in]
	//!	\param arrFacility		设施点坐标列表[in]
	//!	\param nFacilities		目标设施点个数[in]
	//!	\param arrFacilityDist  查找到设施点的花费数组[out]
	//!	\param dMaxImpedance	最大搜索阻值[in]
	//!	\param bFromEvent		是否从事件点开始搜索[in]	  
	//!	\return	事件点到有效设施点的总距离		
	//!	\remarks 返回有效设施点ID(坐标)放在arrFacilityID(arrFacility)中;
	//! 返回有效设施点数放在nFacilities中；
	//!	dMaxImpedance的默认值为0，表示不限制搜索阻值:
    UGdouble FindClosestFacility(const UGAnalyseParams &AnalyseParams,UGResultInfo& ResInfoOut,
		                               UGdouble dMaxImpedance=0,UGbool bFromEvent = TRUE);
	
	//!	\brief	服务区分析 
	//!	\param AnalyseParams 服务区问题参数设置[in]
	//!	\param nArrSiteID 服务中心点[in]
	//!	\param dArrServiceCost 服务点的cost[in]
	//!	\param bFromSite			[in]
	//!	\param bGeneralized		TRUE:普通服务区分析 FALSE：各个中心点互斥[in]
	//! \param dArrSiteCost	 返回各个中心点的服务距离 （特殊分析暂时没有返回 ）[out]
	//!	\return 如果分析成功返回TRUE，否则返回FALSE
	//! \remarks 
	UGbool FindServiceArea(const UGAnalyseParams& AnalyseParams,UGResultInfo& ResInfoOut,
		                         UGbool bGeneralized = TRUE ,UGbool bFromSite = TRUE);

	//!	\brief	MTSP分析：(物流配送)多旅行商问题
	//!	\param AnalyseParams 多旅行商问题参数设置[in]
	//!	\param arrMTSPIDs			旅行商结点表[in]
    //!	\param arrViaNode			游历结点表[in]
	//!	\param arrDist				游历线路长度[out]
	//!	\param bMinTotalCost		是否总和最小模式[in]
	//!	\return 成功:返回TRUE，同时通过引用返回各条路线的弧段、结点、花费；
	//! \remarks (物流配送)多旅行商问题,
	UGbool FindMTSPPath( const UGAnalyseParams& AnalyseParams,UGResultInfo& ResInfoOut, UGArray <UGuint> &arrOrderIndexs,
					           UGbool bMinTotalCost=FALSE);

	//!	\brief	选址分区分析：  
	//!	\param nMode			选址模式[in]
	//!	\param nLocations		目标中心数[in]
	//!	\param bFromCenter		是否从中心出发[in] 
	//!	\return	成功：TRUE，任何异常和错误将返回FALSE;
	//! \remarks 选址分区分析是决定一个或多个服务设施的最优位置的过程，
	//!	它的定位力求保证服务设施可以以最经济有效的方式为它所服务的人群提供服务。
	UGbool LocateAllocate(const UGAnalyseParams& AnalyseParams,UGResultInfo& ResInfoOut,UGArray<UGuint> &arrLocationID,UGbool bFromCenter=TRUE);
	
	//!	\brief 资源分配分析
	//!	\param AnalyseParams 资源分配分析参数设置[in]
	//!	\param nMode		分配模式[in]
	//!	\param bFromCenter	分配方向是否从中心出发[in]
	//!	\param bConnected	分配过程中生成的Route是否必须连通[in] 
	//!	\return	成功：TRUE，任何异常和错误将返回FALSE;	
	//! \remarks 资源分配分析模拟现实世界网络中资源的供需关系模型;
	//!  资源由供应点逐步向需求点(包括弧段或节点)分配资源,并确保供应点能以最经济有效的方式
	//!  为它所服务的人群提供服务;
	UGbool Allocate( const UGAnalyseParams& AnalyseParams,UGResultInfo& ResInfoOut);

	//!	\brief	距离矩阵接口
	//!	\param AnalyseParams  传入参数列表[in];
	//!	\param arrDistMatrix  传出来的距离矩阵[in]
	//! \remarks 这个属于新接口
	UGbool GetDistanceMatrix(const UGAnalyseParams &AnalyseParams, UGArray<UGDistMatrixUnit>& arrDistMatrix);
	
	//!	\brief	更新弧段权值
	//! \param  nEdgeID			弧段ID[in]
	//! \param  nFromNodeID		弧段起始结点ID[in]
	//! \param  nToNodeID		弧段终止结点ID[in]
	//!	\param strCostName		花费字段[in]
	//!	\param dWeight			跟新权值[in]
	//!	\return 返回狐段更新前的权值，跟新失败返回-1000
	UGdouble UpdateEdgeImp(UGint nEdgeID, UGint nFromNodeID, UGint nToNodeID, UGString& strCostName, UGdouble dWeight);
	
	//!	\brief	更新结点权值
	//! \param  nNodeID			结点ID[in]
	//! \param  nFEdgeID		结点起始弧段ID[in]
	//! \param  nTEdgeID		结点终止弧段ID[in]
	//!	\param strCostName		花费字段[in]
	//!	\param dWeight			跟新权值[in]
	//!	\return 返回结点更新前的权值，跟新失败返回-1000
	UGdouble UpdateNodeImp(UGint nNodeID, UGint nFEdgeID, UGint nTEdgeID, UGString& strCostName, UGdouble dNodeImp);

private:

	//!	\brief	计算最小控制集： 最小控制集即为覆盖整个需求网络的最少中心数 
	//!	\param	arrLocationID		候选中心点表  
	//!	\return	覆盖需求网络的最少中心数
	//! \remarks	固定中心当作必选中心考虑
	UGint CalculateMinControls(UGArray<UGuint> &arrLocationID);

	//多点服务区分析节点模式
	//!	\brief	多点服务区 	
	//!	\param nArrSiteID			服务中心点
	//!	\param dArrServiceCost		服务点的cost
	//!	\param ArrServiceRoute		传出的结果路由
	//!	\param ArrServiceRegion		结果服务区
	//!	\param bFromSite			
	UGbool FindMServiceArea(UGCostValues  *pCostValues ,TurnCost *pTurnCost,UGIniMemory &IniMemory,UGBarriers &Barriers,
		UGResultInfo &ResInfo,const UGArray<UGuint> & nArrSiteID,const UGArray<UGdouble> & dArrServiceCost,
							UGArray<UGdouble  > & dArrSiteCost ,UGbool bFromSite = TRUE);

	//多点服务区分析坐标点模式
	//!	\brief	多点服务区 	
	//!	\param nArrSiteID			服务中心点
	//!	\param dArrServiceCost		服务点的cost
	//!	\param ArrServiceRoute		传出的结果路由
	//!	\param ArrServiceRegion		结果服务区
	//!	\param bFromSite			
	UGbool FindMServiceArea(UGCostValues  *pCostValues ,TurnCost *pTurnCost,UGIniMemory &IniMemory,UGBarriers &Barriers,
		UGResultInfo &ResInfo,const UGPoint2Ds& pntArrSite,const UGArray<UGdouble> & dArrServiceCost,
							UGArray<UGdouble  > & dArrSiteCost ,UGbool bFromSite = TRUE);

	//!	\brief	服务区分析：获取指定位置点的服务网络和服务区域 
	//!	\param nSiteID			中心ID
	//!	\param dServiceCost		覆盖距离
	//!	\param ServiceRoute		服务区Route
	//!	\param ServiceRegion	服务区多边形
	//!	\param bFromSite		是否从中心分配 
	//!	\return	服务网络的总距离
	UGdouble FindServiceArea(UGCostValues  *pCostValues ,TurnCost *pTurnCost,UGIniMemory &IniMemory,UGBarriers &Barriers,
		UGResultInfo &ResInfo,UGint nSiteID,UGdouble dServiceCost,UGbool bFromSite = TRUE);

	//!	\brief	服务区分析：获取指定位置点的服务网络和服务区域 
	//!	\param pntSite			中心坐标
	//!	\param dServiceCost		覆盖距离
	//!	\param ServiceRoute		服务区Route
	//!	\param ServiceRegion	服务区多边形
	//!	\param bFromSite		是否从中心分配 
	//!	\return	服务网络的总距离
	UGdouble FindServiceArea(UGCostValues  *pCostValues ,TurnCost *pTurnCost,UGIniMemory &IniMemory,UGBarriers &Barriers,
		UGResultInfo &ResInfo,const UGPoint2D &pntSite,UGdouble dServiceCost,UGbool bFromSite = TRUE);

	//选址分区代码
	//!	\brief	计算最小控制集
	//! \param  nLocations 选址个数[in]
	//!	\param arrLocationIndex 选址索引数组[in]
	//!	\return 返回计算的个数
    UGint CalculateMinControls(UGCostValues  *pCostValues,TurnCost *pTurnCost,UGIniMemory &IniMemory,UGArray<UGCenterNode> &arrCenters,
		UGArray<UGdouble> &arrNodeDemand,UGint nLocations, UGArray<UGuint> &arrLocationIndex);
	
	UGbool Allocate(UGCostValues  *pCostValues ,TurnCost *pTurnCost,UGIniMemory &IniMemory,UGArray<UGCenterNode> &arrCenters,UGArray<UGdouble> &arrNodeDemand,
		UGArray<UGchar>&arrbtDemandAllocated,UGArray<UGuint> &arrDemandNodeIndex,UGAllocateType nMode,UGint nCenterIndex,UGbool bFromCenter=TRUE);

	//{{坐标点转换
	//!	\brief	将弧段ID数组通过查询转化为弧段相关信息
	//!	\param arrArcID			弧段ID数组[in]
    //!	\param ArcIDsInfo		弧段信息数组[in]
	//!	\return 成功:返回TRUE，否则返回FALSE；
	UGbool GetArcInfos(UGArray<UGuint>& arrArcID, UGElemIDsInfo& ArcIDsInfo);

	//!	\brief	将节点ID数组通过查询转化为节点相关信息
	//!	\param arrNodeID		节点ID数组[in]
    //!	\param NodeIDsInfo		节点信息数组[in]
	//!	\return 成功:返回TRUE，否则返回FALSE；
	UGbool GetNodeInfos(UGArray<UGuint>& arrNodeID, UGElemIDsInfo& NodeIDsInfo);

	//!	\brief	将单个坐标点转化为含有一定的单个节点信息
	//!	\param pCostValues		路径分析阻力花费指针[in]
	//!	\param pntViaNode		坐标点坐标[in]
    //!	\param NodeInfo		    单个节点信息[out]
	//!	\return 成功:返回TRUE，否则返回FALSE；
	UGbool GetAnalyseNode(UGCostValues  *pCostValues,const UGPoint2D &pntViaNode, UGNodeInfo& NodeInfo);

	//!	\brief	将坐标点数组转化为含有一定的节点信息数组
	//!	\param pCostValues		路径分析阻力花费指针[in]
	//!	\param pntViaNodes		坐标点坐标数组[in]
    //!	\param NodeInfos		节点信息数组[out]
	//!	\return 成功:返回TRUE，否则返回FALSE；
	UGbool GetAnalyseNodes(UGCostValues  *pCostValues,const UGPoint2Ds &arrViaNode, UGNodeInfos& NodeInfos);

	//!	\brief	计算从0开始到当前索引的距离之和
	//!	\param nIndex		索引位置[in]
    //!	\param NodeIDsInfo	距离指针[in]
	//!	\return 返回距离；
	UGdouble GetDist(UGint nIndex, UGPoint2D* pPoints);

	//!	\brief	得到节点信息数组
	//!	\param pCostValues		路径分析阻力花费指针[in]
    //!	\param NodeInfos		节点信息数组[in]
	//!	\return 成功:返回TRUE，否则返回FALSE；
	UGbool GetNodeInfo(UGCostValues  *pCostValues,UGNodeInfos& NodeInfos);

	//!	\brief	坐标点分析需要调用的一个子函数
	//!	\param pCostValues		路径分析阻力花费指针[in]
	//!	\param pTurnCost		转向表花费指针[in]
	//!	\param IniMemory		内存结构[in]
	//!	\param Barriers		    障碍点障碍边结构[in]
	//!	\param NodeInfoFrom		起点信息[in]
	//!	\param NodeInfoEnd		终点信息[in]
	//!	\param resRoute		    保存的路由信息[out]
	//!	\param arrArcID		    弧段ID数组[out]
	//!	\param arrNodeID		节点ID数组[out]
    //!	\param bLeastArcs		是否弧段个数最少[in]
	//!	\param bSaveRoute		是否保存路由[in]
	//!	\return 成功:返回花费，否则返回-1.0；
	UGdouble FindPath(UGCostValues  *pCostValues,TurnCost *pTurnCost,UGIniMemory &IniMemory,UGBarriers &Barriers,
		UGNodeInfo& NodeInfoFrom, UGNodeInfo& NodeInfoEnd,
		UGRoute &resRoute, UGArray<UGuint>& arrArcID, UGArray<UGuint>& arrNodeID,
		UGbool bLeastArcs=FALSE,UGbool bSaveRoute=TRUE);
	//}}坐标点转换

	//{{行使导引
	//!	\brief	得到行使导引报告
	//!	\param PathGuide		行使导引结构[out]
	//!	\return 成功:返回TRUE，否则返回FALSE；
	void GetPathGuide(UGPathGuide& PathGuide);

	//!	\brief	得到行使导引数组
	//!	\param PathGuides		行使导引结构数组[out]
	//!	\return 成功:返回TRUE，否则返回FALSE；
	UGbool GetPathGuides(UGPathGuides& PathGuides);
	
	//!	\brief	得到行使导引数组
	//!	\param PathGuides		行使导引结构数组[out]
	//!	\param pCostValues		阻力花费字段指针[in]
	//!	\param arrNodeID		节点ID数组[in]
	//!	\param arrArcID		    弧段ID数组[in]
	//!	\param arrViaNodeID		经过ID数组[in]
	//!	\return 成功:返回TRUE，否则返回FALSE；
	UGbool MakePathGuide(UGPathGuides& PathGuides,const UGPathGuideName& PathFeildNames,UGCostValues  *pCostValues,UGArray<UGuint>& arrNodeID, UGArray<UGuint>& arrArcID, const UGArray<UGuint>& arrViaNodeID);

	//!	\brief	得到行使导引数组
	//!	\param PathGuides		行使导引结构数组[out]
	//!	\param pCostValues		阻力花费字段指针[in]
	//!	\param NodeInfos		节点信息数组[in]
	//!	\param arrGuideNodeID	节点ID数组[in]
	//!	\param arrGuideArcID   弧段ID数组[in]
	//!	\param nSegCount		经过路径个数[in]
	//!	\return 成功:返回TRUE，否则返回FALSE；
	UGbool MakePathGuide(UGPathGuides& PathGuides,const UGPathGuideName& PathFeildNames,UGCostValues  *pCostValues,UGNodeInfos& NodeInfos, UGArray<UGuint>& arrGuideNodeID, UGArray<UGuint>& arrGuideArcID, UGint nSegCount);
	
	//!	\brief	得到行使导引数组
	//!	\param PathGuides		行使导引结构数组[out]
	//!	\param pCostValues		阻力花费字段指针[in]
	//!	\param EventInfo		事件点信息[in]
	//!	\param NodeInfos	    设施点信息[in]
	//!	\param arrNodeIds       节点ID数组[in]
	//!	\param arrArcIDs        弧段ID数组[in]
	//!	\param nSegCount		经过路径个数[in]
	//!	\return 成功:返回TRUE，否则返回FALSE；
	UGbool MakePathGuides(UGPathGuides& PathGuides,const UGPathGuideName& PathFeildNames,UGCostValues  *pCostValues,UGNodeInfo& EventInfo, UGNodeInfos& NodeInfos, UGArray<UGuint>& arrNodeIds, UGArray<UGuint>& arrArcIds, 
		UGint nRouteCount);

	//!	\brief	得到行使导引数组
	//!	\param PathGuides		行使导引结构数组[out]
	//!	\param pCostValues		阻力花费字段指针[in]
	//!	\param arrNodeIds       节点ID数组[in]
	//!	\param arrArcIDs        弧段ID数组[in]
	//!	\param nSegCount		经过路径个数[in]
	//!	\return 成功:返回TRUE，否则返回FALSE；
	UGbool MakePathGuides(UGPathGuides& PathGuides,const UGPathGuideName& PathFeildNames,UGCostValues  *pCostValues,UGArray<UGuint>& arrNodeIDs, UGArray<UGuint>& arrArcIDs, UGint nRouteCount);
	
	//!	\brief	由分析点信息得到单个行驶报告
	//!	\param pCostValues		阻力花费字段指针[in]
	//!	\param arrNodeIds       节点ID数组[in]
	//!	\param arrEdgeID        弧段ID数组[in]
	//!	\param NodeIDsInfo		节点信息[in]
	//!	\param ArcIDsInfo	    弧段信息[in]
	//!	\param PathGuide		单个行驶导引报告[out]
	//!	\return 成功:返回TRUE，否则返回FALSE；
	UGbool GetAnalyseInfo(const UGPathGuideName& PathFeildNames,UGCostValues  *pCostValues,UGArray<UGuint>& arrNodeID, UGArray<UGuint>& arrEdgeID, UGElemIDsInfo& NodeIDsInfo, 
		UGElemIDsInfo& ArcIDsInfo, UGPathGuide& PathGuide);

	//!	\brief	由分析点信息得到单个行驶报告
	//!	\param pCostValues		阻力花费字段指针[in]
	//!	\param arrNodeIds       节点ID数组[in]
	//!	\param arrEdgeID        弧段ID数组[in]
	//!	\param arrViaNodeID		经过节点数组[in]
	//!	\param PathGuide		单个行驶导引报告[out]
	//!	\return 成功:返回TRUE，否则返回FALSE；
	UGbool GetAnalyseInfo(const UGPathGuideName& PathFeildNames,UGCostValues  *pCostValues,UGArray<UGuint>& arrNodeID, UGArray<UGuint>& arrEdgeID, 
		const UGArray<UGuint>& arrViaNodeID,UGPathGuide& PathGuide);
	
	//!	\brief	由坐标点得到转向信息
	//!	\param arrPoints		坐标点串坐标[in]
	//!	\param arrTurnType      转向数组[in]
	//!	\param arrAngle         转向角度数组[in]
	//!	\return 成功:返回TRUE，否则返回FALSE；
	UGbool GetTurnValue(UGPoint2Ds& arrPoints, UGArray<UGbyte>& arrTurnType, UGArray<UGdouble>& arrAngle);

	//!	\brief	由坐标点得到弧段方向信息
	//!	\param arrPoints		坐标点串坐标[in]
	//!	\param arrDirectType    方向数组[out]
	//!	\param arrArcDirections 弧段方向数组[out]
	//!	\return 成功:返回TRUE，否则返回FALSE；
	UGbool GetArcDirections(UGPoint2Ds& arrPoints, UGArray<UGbyte>& arrDirectType,UGArray<UGdouble>& arrArcDirections);
	//}}行使导引

	//!	\brief	由一个坐标点得到相关信息
	//!	\param pntNode	    坐标点坐标[in]
	//!	\param nArcID       弧段ID[out]
	//!	\param nNodeID      节点ID[out]
	//!	\param dPos         在弧段所占百分比[out]
	//!	\param shtDirection 弧段方向[out]
	//!	\return 成功:返回TRUE，否则返回FALSE.
	UGbool GetAnalyseNode(const UGPoint2D& pntNode,UGint& nArcID,UGint& nNodeID,UGdouble &dPos,UGshort &shtDirection);

	//!	\brief	按照网络节点进行资源分配
	//!	\param pCostValues	        阻力花费指针[in]
	//!	\param pTurnCost            转向花费指针[in]
	//!	\param IniMemory            内存结构[in]
	//!	\param arrCenters           中心点数组[in]
	//!	\param arrNodeDemand        需求点数组[in]
	//!	\param arrbtDemandAllocated	分配需求标识数组[in]
	//!	\param arrDemandNodeIndex   需求节点索引[in]
	//!	\param nCenterIndex         中心点索引[in]
	//!	\param resRoute             分配生成路由[in]
	//!	\return 成功:返回分配花费，否则返回-1.0.
	UGdouble AllocateNode(UGCostValues  *pCostValues ,TurnCost *pTurnCost,UGIniMemory &IniMemory,UGArray<UGCenterNode> &arrCenters,UGArray<UGdouble> &arrNodeDemand,
		UGArray<UGchar>&arrbtDemandAllocated,UGArray<UGuint> &arrDemandNodeIndex,UGint nCenterIndex,UGRoute &resRoute);
	
	//!	\brief	按照网络弧段进行资源分配
	//!	\param pCostValues	        阻力花费指针[in]
	//!	\param pTurnCost            转向花费指针[in]
	//!	\param IniMemory            内存结构[in]
	//!	\param arrCenters           中心点数组[in]
	//!	\param arrNodeDemand        需求点数组[in]
	//!	\param arrbtDemandAllocated	分配需求标识数组[in]
	//!	\param arrDemandNodeIndex   需求节点索引[in]
	//!	\param nCenterIndex         中心点索引[in]
	//!	\param resRoute             分配生成路由[in]
	//!	\return 成功:返回分配花费，否则返回-1.0.
	UGdouble AllocateArc(UGCostValues  *pCostValues ,TurnCost *pTurnCost,UGIniMemory &IniMemory,UGArray<UGCenterNode> &arrCenters,UGArray<UGdouble> &arrNodeDemand,UGint nCenterIndex,UGRoute &resRoute);
	
	//!	\brief	按照网络节点和网络弧段进行资源分配
	//!	\param pCostValues	        阻力花费指针[in]
	//!	\param pTurnCost            转向花费指针[in]
	//!	\param IniMemory            内存结构[in]
	//!	\param arrCenters           中心点数组[in]
	//!	\param arrNodeDemand        需求点数组[in]
	//!	\param arrbtDemandAllocated	分配需求标识数组[in]
	//!	\param arrDemandNodeIndex   需求节点索引[in]
	//!	\param nCenterIndex         中心点索引[in]
	//!	\param resRoute             分配生成路由[in]
	//!	\return 成功:返回分配花费，否则返回-1.0.
	UGdouble AllocateNodeAndArc(UGCostValues *pCostValues,TurnCost *pTurnCost,UGIniMemory &IniMemory,UGArray<UGCenterNode> &arrCenters,UGArray<UGdouble> &arrNodeDemand,UGint nCenterIndex,UGRoute &resRoute);
	
	//!	\brief	按照最小花费进行分配
	//!	\param arrCenters      中心点数组[in]
	//!	\param pdLocationMtx   花费距离矩阵[in]
	//!	\param nLocations	   中心点个数[in]
	//!	\param arrLocationID   分配定位ID数组[in]
	//!	\return 成功:返回TRUE，否则返回FALSE.
	UGbool LocateMinCost(UGArray<UGCenterNode> &arrCenters,UGdouble* pdLocationMtx, UGint nLocations,UGArray<UGuint> &arrLocationID);
	
	//!	\brief	按照网络最大覆盖按照网络节点进行资源分配
	//!	\param pCostValues	   阻力花费指针[in]
	//!	\param pTurnCost       转向花费指针[in]
	//!	\param IniMemory       内存结构[in]
	//!	\param arrCenters      中心点数组[in]
	//!	\param arrNodeDemand   需求数组[in]
	//!	\param pdLocationMtx   花费距离矩阵[in]
	//!	\param nLocations	   中心点个数[in]
	//!	\param ResultInfo	   结果结构[in]
	//!	\param arrLocationID   分配定位ID数组[in]
	//!	\return 成功:返回TRUE，否则返回FALSE.
	//! \remarks 选址分区使用代码.
	UGbool LocateMaxCover(UGCostValues  *pCostValues,TurnCost *pTurnCost,UGIniMemory &IniMemory,UGArray<UGCenterNode> &arrCenters,UGArray<UGdouble> &arrNodeDemand,
		UGdouble* pdLocationMtx,UGint nLocations,UGResultInfo& ResultInfo,UGArray<UGuint> &arrLocationID);
	
	//!	\brief	求取最小中心点数目 按照网络最大覆盖按照网络节点进行资源分配
	//!	\param pCostValues	   阻力花费指针[in]
	//!	\param pTurnCost       转向花费指针[in]
	//!	\param IniMemory       内存结构[in]
	//!	\param arrCenters      中心点数组[in]
	//!	\param arrNodeDemand   需求数组[in]
	//!	\param pdLocationMtx   花费距离矩阵[in]
	//!	\param nLocations	   中心点个数[in]
	//!	\param ResultInfo	   结果结构[in]
	//!	\param arrLocationID   分配定位ID数组[in]
	//!	\return 成功:返回TRUE，否则返回FALSE.
	//! \remarks 选址分区使用代码:求取最小中心点数目 按照网络最大覆盖按照网络节点进行资源分配，
	//! 如果没有给定中心点个数，可以计算最小覆盖网络的中心点个数
	UGbool LocateMaxCover(UGCostValues  *pCostValues,TurnCost *pTurnCost,UGIniMemory &IniMemory,UGArray<UGCenterNode> &arrCenters,UGArray<UGdouble> &arrNodeDemand,
		                  UGdouble* pdLocationMtx,UGResultInfo& ResultInfo,UGArray<UGuint> &arrLocationID);

	//!	\brief	按照最小权花费进行分配
	//!	\param arrCenters      中心点数组[in]
	//!	\param pdLocationMtx   花费距离矩阵[in]
	//!	\param nLocations	   中心点个数[in]
	//!	\param arrLocationID   分配定位ID数组[in]
	//!	\return 成功:返回TRUE，否则返回FALSE.
	UGbool LocateMinPowerCost(UGArray<UGCenterNode> &arrCenters,UGdouble* pdLocationMtx, UGint nLocations,UGArray<UGuint> &arrLocationID);
	
	//!	\brief	按照最小权花费进行分配
	//!	\param pdLocationMtx   花费距离矩阵[in]
	//!	\param nLocations	   中心点个数[in]
	//!	\param arrLocationID   分配定位ID数组[in]
	//!	\return 成功:返回TRUE，否则返回FALSE.
	UGbool LocateMaxAttend(UGdouble* pdLocationMtx, UGint nLocations,UGArray<UGuint> &arrLocationID);
	
	//!	\brief	得到分配的距离矩阵
	//!	\param pCostValues	   阻力花费指针[in]
	//!	\param pTurnCost       转向花费指针[in]
	//!	\param IniMemory       内存结构[in]
	//!	\param arrCenters      中心点数组[in]
	//!	\param arrNodeDemand   需求点ID数组[in]
	//!	\param pdLocationMtx   花费距离矩阵[out]
	//!	\return 成功:返回TRUE，否则返回FALSE.
	UGbool GetLocationMtx(UGCostValues  *pCostValues,TurnCost*pTurnCost,UGIniMemory &IniMemory,UGArray<UGCenterNode> &arrCenters,UGArray<UGdouble> &arrNodeDemand,UGdouble* pdLocationMtx);
	
	//!	\brief	旅行商分析调用子接口
	UGdouble TSPAnalyse(UGdouble* pdTSPMtx,UGint nDimension,UGArray<UGuint> &arrOrdinalIndex,UGint nIterations);
	
	//!	\brief	旅行商分析调用子接口计算规约矩阵
	UGdouble GetTSPDivMatrix(UGdouble* pdDivMtx,UGint nCount);

	//!	\brief	多旅行商分析调节花费
	UGbool IniAssign(UGArray<UGuint>* parrMTSP, MTSPInfo* pSN_SNIndexMtx, MTSPInfo* pNN_SNIndexMtx,
							DemandNode* pFirstNode, UGdouble* pdServiceCost, UGint* pnSigned, UGint nMCount,
							UGint nNodeCount);
	
	//!	\brief	多旅行商分析调节花费
	UGbool Adjust(UGArray<UGuint>* parrMTSP, MTSPInfo* pSN_SNIndexMtx, MTSPInfo* pNN_SNIndexMtx,
					UGdouble* pdServiceCost, UGint* pnSigned, UGint nMCount, UGint nNodeCount);

	//!	\brief	多旅行商分析再次调节花费
	UGbool AdjustBak(UGArray<UGuint>* parrMTSP, MTSPInfo* pSN_SNIndexMtx, MTSPInfo* pNN_SNIndexMtx,
					UGdouble* pdServiceCost, UGint* pnSigned, UGint nMCount, UGint nNodeCount);
	
	//!	\brief	多旅行商分析调节花费
	UGbool GSX(UGArray<UGuint>* parrMTSP, MTSPInfo* pSN_SNIndexMtx, MTSPInfo* pNN_SNIndexMtx,
				UGdouble* pdServiceCost, UGint* pnSigned, UGint nMCount, UGint nNodeCount);
	
	//!	\brief	多旅行商分析调节花费
	UGdouble GetReduceCost(UGArray<UGuint>& arrNodeIndexs, 
										UGint nReduceServiceIndex, 
										UGint nMinNodeIndex, 
										MTSPInfo* pSN_SNIndexMtx, 
										MTSPInfo* pNN_SNIndexMtx,
										UGint nNodeCount,UGint& nRemovePos);
	//!	\brief	多旅行商分析调节花费
	UGdouble FindInsertPos(UGArray<UGuint>& arrNodeIndexs, 
										UGint nServiceIndex, UGint nNodeIndex, 
										UGint& nInsertPos,
										MTSPInfo* pSN_SNIndexMtx, 
										MTSPInfo* pNN_SNIndexMtx,
										UGint nNodeCount);

	//!	\brief	多旅行商分析调节花费
	UGdouble FindInsertPos(UGArray<UGuint>& arrNodeIndexs, UGArray<UGuint>& arrServiceIndexs, 
							MTSPInfo* pSN_SNIndexMtx, MTSPInfo* pNN_SNIndexMtx,
							UGint nNodeCount, UGint nServiceIndex, UGint nFromIndex, 
							UGint nInsertCount,UGint& nInsertPos, UGbool& bReverse);
	//!	\brief	多旅行商分析调节花费
	UGbool GetPCenterTable(UGdouble* pdLocationMtx,UGint nLocations,UGint*& pLocation,UGdouble* pdparam);

//	UGbool ShortestPath(UGint nStartID,UGArray<UGuint> &arrTSPIDs,UGdouble *pdDist);
	
//	UGbool ShortestPath(UGPoint2D pntStart,UGPoint2Ds &arrViaNode,UGdouble *pdDist);

//	UGdouble FindPath(const UGPoint2D& pntStart,const UGPoint2D& pntEnd,UGRoute &resRoute,
//		UGbool bLeastArcs=FALSE,UGbool bSaveRoute=TRUE);
	
//	UGdouble ShortestPath(UGint nStartID,UGint nEndID,UGArray<UGuint> &arrArcID,UGbool bSaveArc=TRUE);

	//路径分析用到这个函数

	//!	\brief	最短路径分析
	UGdouble ShortestPath(UGCostValues  *pCostValues,TurnCost *pTurnCost,UGIniMemory &IniMemory,UGBarriers &Barriers,
		UGint nStartID,UGint nEndID,UGArray<UGuint> &arrArcID, UGArray<UGuint> &arrNodeID);
	
	//!	\brief	最短路径分析
	UGbool ShortestPathGroup(UGCostValues  *pCostValues,TurnCost *pTurnCost,UGIniMemory &IniMemory,UGBarriers &Barriers,
		UGint nStartID,UGint* pEndIDs,UGint nCount,UGdouble* pdEndCost);
	
//	UGdouble ShortestPathP(UGint nStartID,UGint nEndID,UGArray<UGuint> &arrArcID,UGint nStartArc=-1,UGint nEndArc=-1,
//		UGbool bSaveArc=TRUE);

	//!	\brief	最短路径分析
	UGdouble ShortestPathP(UGCostValues  *pCostValues,TurnCost *pTurnCost,UGIniMemory &IniMemory,UGBarriers &Barriers,
		UGint nStartID,UGint nEndID,UGArray<UGuint> &arrArcID,UGArray<UGuint> &arrNodeID,UGint nStartArc=-1,UGint nEndArc=-1,
		UGbool bSaveArc=TRUE);
	
//	UGdouble LeastArcsPath(UGint nStartID,UGint nEndID,UGArray<UGuint> &arrArcID);

	//路径分析用到这个函数
	//!	\brief	最短路径分析弧段个数最少
	UGdouble LeastArcsPath(UGCostValues  *pCostValues,TurnCost *pTurnCost,UGIniMemory &IniMemory,UGBarriers &Barriers,
		UGint nStartID,UGint nEndID,UGArray<UGuint> &arrArcID, UGArray<UGuint> &arrNodeID);
	
	//!	\brief	找到虚拟弧段原来属于的弧段
	// nVirtualArcID 虚拟弧段的ID
	// nRelArcID 返回的真实弧段ID
	// dFromPos 虚拟弧段FNode在 nRelArcID开始弧段的位置 0--1之间
	// dToPos 虚拟弧段TNode在 nRelArcID开始弧段的位置 0--1之间
	// dArcCost nRelArcID的正向cost
	// dArcCostBak nRelArcIDBak的正向cost
	UGbool FindIDByVirtualArcID(UGint nVirtualArcID,UGint & nRelArcID ,
				UGdouble & dFromPos,UGdouble & dToPos,UGdouble & dArcCost,UGdouble &dArcCostBak);

	//!	\brief 获取结果多边形
	// nSiteCount 点的个数
	UGbool GetServiceRegion(UGArray<UGGeoLineM>& arrRoute,UGint nSiteCount,UGint *pnRelation,UGArray<UGGeoRegion> & ArrServiceRegion );	
	
	//!	\brief 得到每个中心点的值
	UGdouble GetEachCenterValue(UGint nCenterIndex,UGdouble* pdLocationMtx,UGdouble* pdparam);
	
	
	// 服务区分析
	//!	\brief 得到服务覆盖面信息
	UGbool GetCoverSign(UGCostValues  *pCostValues,TurnCost* pTurnCost,UGIniMemory &IniMemory,UGBarriers &Barriers,
		UGint nCenterIndex, UGArray<UGuint> &arrFacilityID, UGint nCount,UGArray<UGuint> &arrResFacIndex, UGdouble dCoverCost);

	//!	\brief 得到服务覆盖面信息
	UGbool GetCoverSign(UGCostValues  *pCostValues,TurnCost* pTurnCost,UGIniMemory &IniMemory,UGBarriers &Barriers,
		UGint nCenterIndex,UGuchar* &pbtOnPath,UGdouble* &pdNodeCost,UGdouble dCoverCost,
		UGint nCenterArc=-1,UGdouble dSiteCost=-1.0,UGdouble dNeighborCost=-1.0);
	
	//多点服务区分析
	//!	\brief 获取多个服务点的结点cost
	UGbool GetCoverSign(UGCostValues  *pCostValues,TurnCost* pTurnCost,UGIniMemory &IniMemory,UGBarriers &Barriers,
		const UGArray<UGuint> & nArrSiteID,const UGArray<UGdouble> & dArrServiceCost,	
		UGArray< UGshort*> & BArrOnPathPre,	UGArray< UGdouble*> & dArrNodeCostPre);

	//!	\brief 边分配
	// BArrOnPathPre 所有服务中心点的前驱结点信息
	// dArrNodeCostPre 中心点的花销
	// dArrServiceCost 所有中心点的服务范围
	// bPntFind 是坐标点分析还是网络点分析
	UGbool AllotArcService(UGCostValues  *pCostValues ,UGIniMemory &IniMemory,const UGArray< UGshort*> & BArrOnPathPre ,const UGArray< UGdouble* > & dArrNodeCostPre,
		const UGArray<UGdouble > & dArrServiceCost,UGArray<UGdouble> & dArrSiteCost ,UGArray<UGGeoLineM>& arrRoute,
		UGbool bPntFind = FALSE );

	//!	\brief 获得各个分析中心点（虚结点）的岛洞关系 保存于m_pnRelation中
	UGbool GetRelation(UGint nSiteCount,UGint *pnRelation,const UGArray<UGuint> & nArrSiteID,const UGArray<UGdouble> & dArrServiceCost,
		const UGArray< UGshort*> & BArrOnPathPre ,const UGArray< UGdouble*> & dArrNodeCostPre);

	//!	\brief 根据给定的routid 统计 结果linem数据集中的linem长度
	UGdouble StatisticLength(UGint nRouteID);

	//!	\brief 在服务区分析之后 将CoverCost 和 CoverLength 加入到结果面数据集中
	// dArrSiteCost 表示每个中心点的 CoverCost
	// CoverLength 要统计各个 LineM 的 Length 之和
	UGbool AddCostAndLength(UGArray<UGdouble> & dArrSiteCost,ResultInfo &ResInfo);
	
	//!	\brief 得到多旅行商花费矩阵
	UGbool GetCostMtx(UGCostValues  *pCostValues,TurnCost *pTurnCost,UGIniMemory &IniMemory,UGBarriers &Barriers,
		UGArray<UGuint>& arrTotalNodeIDs, MTSPInfo* pNodeMtx);

	//!	\brief 得到多旅行商花费矩阵
	UGbool GetCostMtx(UGCostValues  *pCostValues,TurnCost *pTurnCost,UGIniMemory &IniMemory,UGBarriers &Barriers,
		UGArray<UGuint>& arrServiceIDs, UGArray<UGuint>& arrNodeIDs, MTSPInfo* pCostMtx);
	
	//!	\brief 得到多旅行商花费矩阵
	UGbool GetCostMtx(UGCostValues  *pCostValues,TurnCost *pTurnCost,UGIniMemory &IniMemory,UGBarriers &Barriers,
		UGArray<UGuint>& arrNodeIDs, UGdouble* pCostMtx);

	//!	\brief 得到多旅行商花费矩阵
	UGbool GetCostMtx(UGCostValues  *pCostValues,TurnCost *pTurnCost,UGIniMemory &IniMemory,UGBarriers &Barriers,
		UGPoint2Ds& arrTotalNodeIDs, MTSPInfo* pNodeMtx);

	//!	\brief 得到多旅行商花费矩阵
	UGbool GetCostMtx(UGCostValues  *pCostValues,TurnCost *pTurnCost,UGIniMemory &IniMemory,UGBarriers &Barriers,
		UGPoint2Ds& arrServiceIDs, UGPoint2Ds& arrNodeIDs, MTSPInfo* pCostMtx);

	//!	\brief 最短路径分析
	UGbool ShortestPath(UGCostValues  *pCostValues,TurnCost *pTurnCost,UGIniMemory &IniMemory,UGBarriers &Barriers,UGint nStartID,
		UGArray<UGuint> &arrTSPIDs,UGdouble *pdDist,UGArray<UGint> *parrPreArcID=NULL,UGArray<UGint> *parrPreNodeID=NULL);
	
	//!	\brief 最短路径分析
	UGbool ShortestPath(UGCostValues  *pCostValues,TurnCost *pTurnCost,UGIniMemory &IniMemory,UGBarriers &Barriers,UGint nStartID, UGArray<UGuint> &arrTSPIDs, UGdouble *pdDist, UGint *pnArcID, UGint *pnNodeID, 
						UGdouble *pdPos, UGint *pnPreArcID);

	//!	\brief 局部优化函数
	void LocalOptimize(MTSPInfo *pNN_CostMtx, UGint nNodeCount, UGArray<UGuint>& arrNodeIndexs, UGdouble& dTotalCost);
	
	//!	\brief	旅行商分析调用网络节点分析子接口
	UGdouble FindTSPPath(const UGAnalyseParams &AnalyseParams,UGResultInfo &ResInfoOut,UGCostValues  *pCostValues,TurnCost *pTurnCost,UGIniMemory &IniMemory,UGArray<UGuint> &arrNodeIDs, UGArray<UGuint> &arrOrderIndexs, UGbool bEndNodeSigned=TRUE,
						UGbool bReturnStart=TRUE);

	//!	\brief	旅行商分析调用坐标点分析子接口
	UGdouble FindTSPPath(const UGAnalyseParams &AnalyseParams,UGResultInfo &ResInfoOut,UGCostValues  *pCostValues,TurnCost *pTurnCost,UGIniMemory &IniMemory,UGPoint2Ds &arrNodeIDs, UGArray<UGuint> &arrOrderIndexs, UGbool bEndNodeSigned=TRUE,
						UGbool bReturnStart=TRUE);

	//!	\brief	转向信息
	UGbool GetTurnCostValue(UGString strTurnCost,TurnCost*& pTurnCost);

	//!	\brief	得到覆盖路由
	//! \param BArrOnPathPre 所有服务中心点的前驱结点信息
	//! \param dArrNodeCostPre 中心点的花销
	//! \param nSite 当前处理中心点
    //! \param pnMinCost 所有结点中花销最小的服务中心点
	//! \param dArrServiceCost 所有中心点的服务范围
	//! \param CoverRoute 返回结果
	UGbool GetCoverRoute(const UGArray< UGshort*> & BArrOnPathPre ,const UGArray< UGdouble*> & dArrNodeCostPre,
		UGint nSite,const UGint  * pnMinCost ,	const UGArray<UGdouble> & dArrServiceCost,
		UGRoute &CoverRoute, UGint nSiteArcID = -1 );

	//!	\brief	得到覆盖路由
	UGdouble GetCoverRoute(UGCostValues  *pCostValues,UGBarriers&Barriers,
		UGuchar* pbtOnPath,UGdouble* pdNodeCost,UGdouble dCoverCost,UGRoute &CoverRoute,UGArray<UGuint> arrNodeIDs,UGint nSiteArcID = -1);
	
	//!	\brief	得到覆盖面
	UGbool GetCoverRegion(UGuchar* pbtOnPath,UGdouble* pdNodeCost,UGdouble dCoverCost,UGGeoRegion &ServiceRegion);

	//!	\brief	得到覆盖面
	UGbool GetCoverRegion(UGArray<UGGeoLineM>&arrRoute,UGGeoRegion &CoverRegion);

	//!	\brief	分配单个中心
	//! \param  nCenterIndex 中心索引[in]
	//!	\param pdCost 花费数组[in]
	//!	\return 返回分配单个索引最小花费
	UGdouble AllocateSingleCenter(UGCostValues  *pCostValues,TurnCost *pTurnCost,UGIniMemory &IniMemory,UGArray<UGCenterNode> &arrCenters,UGArray<UGdouble> &arrNodeDemand,UGint nCenterIndex, UGdouble* pdCost);
};

}

#endif 
