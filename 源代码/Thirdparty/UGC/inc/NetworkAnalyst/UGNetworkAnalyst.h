/* 
	\file UGNetworkAnalyst.h
	\brief 网络分析基类
	\author ugc team
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>更新说明：</b>
	<em>1、第一条说明。</em>
	<em>2、第二条说明。</em>
*/
#ifndef UGNETWORKANALYST_H
#define UGNETWORKANALYST_H

#include "Base/ugdefs.h"
#include "Base/UGList.h"
#include "Base/UGArray.h"
#include "Base/UGString.h"

#include "Engine/UGDatasetVector.h"

#include "Geometry/UGGeoLineM.h"
#include "NetworkAnalyst/UGNetworkAnalystEnv.h"

namespace UGC {

class UGRoute;

/*!	\brief	网络分析类 \n*/
class NETWORKANALYST_API UGNetworkAnalyst  : public UGNetworkAnalystEnv
{
public:
	UGNetworkAnalyst();
	virtual ~UGNetworkAnalyst();
	
	/*!	\brief	网络模式： */
	enum UGNetworkType
	{
		UGNTTrafficNetwork	= 1,	//交通网络
		UGNTUtilityNetwork	= 2		//设施网络
	};
	
	/*!	\brief	权值模式：*/
	enum UGWeightType
	{
		UGWTNULL	= 1,	//null
		UGWTBitGate	= 2,	//bit
		UGWTInteger	= 3,	//UGint
		UGWTSingle	= 4,	//float
		UGWTDouble	= 5		//UGdouble
	};

	/*!	\brief	候选中心模式；*/
	enum	UGCenterCandidateType
	{
		UGCCTNULL	= 0,	//非中心
		UGCCTMobile	= 1,	//可选中心
		UGCCTFixed	= 2		//固定中心
	};
	
	/*!	\brief	流向类型：*/
	enum	UGTraceType
	{
		UGTTSource	= 0,	//搜索源
		UGTTSink	= 1,	//搜索汇
	};

	//分幅处理开发
	
	/*!	\brief	边界查找模式 */
	enum UGBoundFindType
	{
		UGBFTypeLeft	=	1 ,		// 左边
		UGBFTypeRight	=	2 ,		// 右边
		UGBFTypeTop 	=	3 ,		// 上边
		UGBFTypeBottom	=	4 		// 下边
	};

public:
	
	/*!	\brief	建立转向表\n
	创建完成后自动打开TRN*/
	UGbool CreateTRN();
	
	/*!	\brief	打开转向表\n
	使用转向表前必须先打开TRN*/
	void OpenTRN();
	
	/*!	\brief	是否已经打开转向表*/
	UGbool IsOpenTRN();
	
	/*!	\brief	关闭转向表\n
	暂时不使用TRN，可以先关闭，等待下一次打开再使用*/
	void CloseTRN();
	
	/*!	\brief	删除转向表\n
	彻底删除TRN，同时释放内存*/
	void DeleteTRN();
	
	/*!	\brief	建立邻接矩阵*/
	UGbool CreateAdjMatrix();
	
	/*!	\brief	建立邻接矩阵*/
	UGbool CreateAdjMatrixUtility();

	/*!	\brief	建立给定范围的邻接矩阵*/
	UGbool CreateAdjMatrixUtility(const UGRect2D& rcBound);

	/*!	\brief	建立给定范围的邻接矩阵*/
	UGbool CreateAdjMatrix(const UGRect2D& rcBound);
	
	/*!	\brief	删除邻接矩阵\n
	同时释放内存*/
	void DeleteAdjMatrixUtility();

	/*!	\brief	删除邻接矩阵\n
	同时释放内存*/
	void DeleteAdjMatrix();
	
	/*!	\brief	建立节点需求表*/
	UGbool CreateNodeDemand();
	
	/*!	\brief	删除节点需求表\n*/
	void DeleteNodeDemand();
	
	/*!	\brief	建立弧段需求表*/
	UGbool CreateArcDemand();
	
	/*!	\brief	删除弧段需求表\n*/
	void DeleteArcDemand();
	
	/*!	\brief	是否考虑道路规则*/
	void UseRoadRule(UGbool bUseRoadRule);
	
	/*!	\brief	设置节点障碍\n
	*	\param	arrNodeID	障碍点集
	*/
	UGbool SetBarrierNodes(const UGArray<UGuint> &arrNodeID);

	/*!	\brief	添加节点障碍\n
	*	\param	arrNodeID	障碍点集
	*/
	UGbool AddBarrierNodes(const UGArray<UGuint> &arrNodeID);
	
	/*!	\brief	获取节点障碍\n
	*	\param	arrNodeID	障碍点集
	*/
	UGbool GetBarrierNodes(UGArray<UGuint> &arrNodeID);
	
	/*!	\brief	设置弧段障碍\n
	*	\param	arrArcID		障碍弧段集
	*/
	UGbool SetBarrierArcs(const UGArray<UGuint> &arrArcID);
	
	/*!	\brief	添加弧段障碍\n
	*	\param	arrArcID	障碍弧段集
	*/
	UGbool AddBarrierArcs(const UGArray<UGuint> &arrArcID);
	
	/*!	\brief	获取弧段障碍\n
	*	\param	arrArcID		障碍弧段集
	*/
	UGbool GetBarrierArcs(UGArray<UGuint> &arrArcID);
	
	/*!	\brief	撤消节点障碍\n
	*	\param	arrNodeID		障碍点集
	*/
	UGbool CancelBarrierNodes(const UGArray<UGuint> &arrNodeID);
	
	/*!	\brief	撤消所有节点障碍 */
	UGbool CancelAllBarrierNodes();
	
	/*!	\brief	撤消弧段障碍\n
	*	\param	arrArcID		障碍弧段集
	*/
	UGbool CancelBarrierArcs(const UGArray<UGuint> &arrArcID);
	
	/*!	\brief	撤消所有弧段障碍 */
	UGbool CancelAllBarrierArcs();
	
	/*!	\brief	设置单个中心点\n
	*	\param	nCenterID		中心点ID
	*	\param	dResource		中心点资源量
	*	\param	dMaxImpedance	中心点最大阻值	
	*	\param	nCandidate		候选地级别(用于选址分区分析)
	*/
	UGbool SetCenter(UGint nCenterID,UGdouble dResource,UGdouble dMaxImpedance=0.0,UGCenterCandidateType nCandidate=UGCCTFixed);

	//!	\brief 设置中心点
	UGbool SetCenter(UGCenterNode CenterNode,UGCenterCandidateType nCandidate=UGCCTFixed);
	
	//Add by wangsh 07.06.19 函数不够完善，需要继续优化！！
	//!	\brief 设置中心点数据集
    UGbool SetCenterDT(UGDatasetVector* pDTCenter);

	//!	\brief 得到中心点信息
	UGbool GetCenters(UGArray<UGCenterNode>&arrCenters);
	
	//!	\brief 得到需求中心点
	UGbool GetNodeDemands(UGArray<UGdouble>&arrNodeDemand);

	/*!	\brief	撤消单个中心点\n
	*	\param	arrNodeID		中心点ID
	*/
	UGbool CancelCenter(UGint nCenterID);
	
	/*!	\brief	撤消所有中心点\n
	*/
	UGbool CancelAllCenters();
	
	/*!	\brief	得到需求节点ID表\n
	*	\param	arrDemandNodeID		结果需求点集
	*/
	void GetAllocateNode(UGArray<UGuint> &arrDemandNodeID);
	
	/*!	\brief	得到需求弧段ID表\n
	*	\param	arrDemandArcID		结果需求弧段集
	*/
	void GetAllocateArc(UGArray<UGuint> &arrDemandArcID);
	
	/*!	\brief	得到路由弧段ID组\n
	*	\param	arrDemandArcID		结果需求弧段集
	*/
	UGbool GetViaArcIDs(UGArray<UGuint> &arrArcID);
	
	/*!	\brief	得到路由节点ID组\n
	*	\param	arrDemandArcID		结果需求弧段集
	*/
	UGbool GetViaNodeIDs(UGArray<UGuint> &arrNodeID);

	/*!	\brief	得到路由坐标点ID组\n
	*	\param	arrNodepnts		坐标点数组
	*/
	UGbool GetViaNodepnts(UGArray<UGPoint2D> &arrNodepnts);

	/*!	\brief	设置返回结果信息*/
	void SetResultInfos(const ResultInfo& resultinfo);
	
	/*!	\brief	获取返回结果信息*/
	ResultInfo GetResultInfos();
	
	/*!	\brief	网络环境是否已经改变*/
	UGbool IsNetEnvModified();
	
	//!	\brief 导出转向表
	UGbool ExportTRN(UGDatasetVector* pDtTRN);
	
	/*!	\brief	提取提示信息：获取路径分析中通过中间路由点的相关提示信息\n
	  *	\param arrViaWeight			路由点的阻值表
	  *	\param arrViaDirection		路由点的方向表
	  * \return	成功返回TRUE，否则FALSE；
	  *	\remarks 1表示右转，-1表示左转；0表示在路径上
	*/
	UGbool GetDirections(UGArray<UGdouble> &arrViaWeight,UGArray<UGshort> &arrViaDirection);
	
	//!	\brief 得到分析坐标点信息
	UGbool GetAnalyseInfo(UGCostValues  *pCostValues,
		                 UGDatasetVector* pDtResultInfo,
						UGArray <UGuint>& arrNodeID, 
						UGArray <UGuint>& arrEdgeID,
						const UGString& strNodeName,
						const UGString& strEdgeName);
	//!	\brief 得到结果
	UGbool GetPathTable(UGCostValues  *pCostValues,const  ResultInfo &nResultInfo,UGArray<UGuint>& arrNodeID, UGArray<UGuint>& arrArcID, UGint RouteCount);
	//!	\brief 得到结果
	UGbool GetPathTable(UGCostValues  *pCostValues,const  ResultInfo &nResultInfo,UGArray<UGuint>& arrNodeID, UGArray<UGuint>& arrArcID);

	//UGCostValues *GetFeildCost(const UGString &strCostName);
	//!	\brief 得到结果
	UGbool GetFeildCost(const UGString &strCostName,UGCostValues  * pCostValues);

public:

	//TraceWater
	//!	\brief 初始化内存函数
	UGbool AssignIniMemory();
	
	//!	\brief 释放内存函数
	void ReleaseMemory();
	
	//!	\brief 得到三个点之间的角度
	//!	\param pntStart 起始点[in]
	//!	\param pntMiddle 中间点[in]
	//!	\param pntEnd 终止点[in]
	UGdouble GetAngle(const UGPoint2D &pntStart, const UGPoint2D &pntMiddle, const UGPoint2D &pntEnd);

	//!	\brief 得到弧段方向
	UGbool GetArcDirections(UGPoint2Ds& arrPoints,UGArray<UGdouble>& arrArcDirections);

	//!	\brief 得到转向值
	UGbool GetTurnValue(UGPoint2Ds& arrPoints,UGArray<UGint>& arrTurnValue);
	
	//!	\brief 得到追踪符号
	UGbool GetTraceSign(UGint nCenterIndex,UGshort* &pbtOnPath,UGdouble* &pdNodeCost, UGint* &pnPrevArcID);
	
	//!	\brief	弧段快速排序函数
	//! \param  pData 弧段指针[in]
	//!	\param nCount 弧段个数[in]
	void q_Sort(ArcInfo *pData, UGint nCount);

	//!	\brief	弧段快速排序函数
	//! \param  pData 需求点指针[in]
	//!	\param nCount 需求点个数[in]
	void q_Sort(DemandNode *pData, UGint nCount);

	//!	\brief	点快速排序函数
	//! \param  pData 需求点指针[in]
	//!	\param nCount 需求点个数[in]
	void q_Sort(PointIndex *pData, UGint nCount);

	//For TSP problem
	//!	\brief 快速排序函数
	void q_SortSCost(MTSPInfo *pData, UGint nCount);
	

	///For MTSP problem
	//UGbool GetCostMtx(UGArray<UGint>& arrTotalNodeIDs, MTSPInfo* pNodeMtx);
	//!	\brief 快速排序函数
	void q_SortNCost(MTSPInfo *pData, UGint nCount);

	//!	\brief 快速排序函数
	void q_SortSNIndex(MTSPInfo *pData, UGint nCount);
	
	//动态分段
	//!	\brief 判断数组是否相同
	UGbool IsSameArray(UGArray<UGint> &arrOld, UGArray<UGint> &arrNew);
	
	//!	\brief 析构数组中的内存
	void DeleteArray(UGArray< UGshort*> & BArrOnPathPre,	UGArray< UGdouble*> & BArrNodeCostPre);

	// 在 UGbool GetGeoLineM(CGeoRoute &resRoute, UGdouble dTotalCost)基础上增加了一个参数
	
	//!	\brief 根据routID生成多边形
	UGbool GetCoverRegionByRoutID(UGArray<UGGeoLineM>& arrRoute,UGGeoRegion &CoverRegion,UGint nRoutID = -1 ) ;

	//!	\brief 取消所有的虚结点
	UGbool CancleVirtualNodes();

	//!	\brief 根据给定的弧段ID 给定的弧段百分比建立虚拟结点
	// nArrSiteArcID 坐标点映射的弧段ID
	// dArrPosSiteNode 坐标点映射到弧段ID上与FNode的距离位置 1--0.0之间的数
	// nArrpntNodeID 返回每个坐标点对应虚拟结点ID
	UGbool BuildVirtualNodes(UGArray<UGint> & nArrSiteArcID ,UGArray<UGdouble> & dArrPosSiteNode,UGArray<UGint> & nArrpntNodeID );

	//!	\brief 考虑了障碍点
	UGdouble GetArcCost(UGint nFNodeIndex,UGint nTNodeIndex);

	//!	\brief 设置中心点数据集
	void SetCenterGeometry();
	
//	UGint FindIndex(UGint nNodeID);
	//!	\brief 排序网络节点ID
	void SortNodeIDs();

	//!	\brief 排序网络弧段ID
	void SortArcIDs();
	
	//!	\brief 距离矩阵
	UGbool DistanceMatrix(UGArray<UGuint> &arrTSPIDs,UGdouble *&pdTSPMtx,UGbool bEndNodeSigned);
	
	//UGbool GetAnalyseNode(const UGPoint2D& pntNode,UGint& nArcID,UGint& nNodeID,UGdouble &dPos,short &shtDirection);
	
	//!	\brief 中心点预处理
	UGbool AllocatePreprocessing();
	
	//!	\brief 得到中心点索引
	UGbool GetDemandNodeIndex(UGint nCenterIndex,UGArray<UGuint>& arrDemandNodeIndex);
	
	//!	\brief 检查需求中心点
	UGbool CheckDemandAllocate();

	//!	\brief 得到最大覆盖中心索引
	UGint GetMaxCoverCenterIndex();
	
	//!	\brief 得到中心点覆盖符号
	UGbool GetAllocateSign(UGint nCenterIndex,UGshort* &pbtOnPath,UGdouble* &pdNodeCost,UGdouble dResource,UGdouble dMaxImpedance=0);
	
	//!	\brief 得到需求点表
	void GetDemandTable(UGdouble* pdLocationMtx,UGchar*& pbtDemandMtx,UGint nLocations,UGint* pLocation,UGdouble* pdparam);
	
	//!	\brief 得到花费上界
	UGdouble GetUpperBound(UGdouble* pdLocationMtx,UGint nLocations,UGint* pLocation);
	
	//!	\brief 得到花费下界
	UGdouble GetLowerBound(UGdouble* pdLocationMtx,UGchar* pbtDemandMtx,UGint nLocations,UGint* pLocation);

	//!	\brief 参数更新
	void UpdateParameters(UGchar* pbtDemandMtx,UGdouble* pdparam,UGdouble& dConstant,UGdouble& dStepSize,
		UGdouble dLowerBound,UGdouble dUpperBound);

	//For multithread
	//!	\brief 固定中心点分配
	UGbool AllocateFixedCenters( UGArray<UGCenterNode> &arrCenters,UGArray<UGdouble>&arrNodeDemand,UGResultInfo& ResultInfo,UGdouble* pdLocationMtx,const UGArray<UGuint> &arrCenterIndex);
	//void DeleteArcDemand();
	//UGbool IsIntersectZones(const UGArray<UGuint> &arrCenterID,UGdouble dMaxImpedance,UGbool bFromCenter);
	
	//!	\brief 固定弧段分配
	UGbool GetCoverArcs(UGuchar* pbtOnPath,UGArray<UGuint> &arrArcIDs,UGbool bEnvelop=true);
	
	//!	\brief 得到覆盖距离
	UGdouble GetCoverDist(UGuchar* pbtOnPath,UGbool bEnvelop=true);
	
	//!	\brief 得到覆盖资源量
	UGdouble GetCoverResource(UGuchar* pbtOnPath,UGdouble* pdNodeCost,UGbool bEnvelop=true);

	//!	\brief 得到插入位置
	UGint GetInsertPos(UGdouble dNodeCost,UGList<UGdouble>&lstNodeCost);
	
	//!	\brief 得到最大花费索引
	UGint GetMaxCostIndex(const UGArray<UGdouble> &arrCoverDist);
	
	//!	\brief 得到弧段距离
	UGdouble GetArcDist(UGint nArcID);
	
	//!	\brief 某点到另外点串的距离
	UGdouble GetDistToStartNode(const UGPoint2D &pntHitTest,const UGPoint2D* pPoint,UGint nCount);
	
	//!	\brief 更新中心点数据集
	void UpdateCentersFile(UGDatasetVector* pDTCenters);
	
	//UGString BuildQueryFilter(UGArray<UGuint> &arrKeys,const UGString strFieldName);
	//!	\brief 将需求点设置为障碍
	UGbool SetDemandNodesToBarrier(const UGArray<UGuint> &arrDemandNodeIndex);
	
	//!	\brief 快速排序函数
	void q_Sort(NetIndex *pData, UGint nCount);
	
	//UGdouble GetTSPDivMatrix(UGdouble* pdDivMtx,UGint nCount,TourIndex* pTourNodeIndex = NULL,
	//						UGint nLevel = 0);
	
	//!	\brief 得到弧度
	UGdouble GetDirectAngle(UGPoint2D pntStart, UGPoint2D pntEnd);
	
	//求紧缩多边形
public:

	//!	\brief 求紧缩多边形 该方法总结于互斥服务区分析
	// arrLines 传入的线段 这些线段是类似网络数据集中的线 必须严格打断
	// arrRegions 返回的多边形 
	// dBufferRadius 如果不能构成面 则作buffer 当dBufferRadius小于0时，不作buffer
	static UGbool ShrinkRegion(UGArray<UGGeoLine> & arrLines,UGArray<UGGeoRegion> & arrRegions,UGdouble dBufferRadius = EP);	

private:

	//!	\brief 求紧缩多边形 
	// arrLines 传入的线段 这些线段都是彼此相通的
	// regions 返回的多边形 
	static UGbool ShrinkRegion(UGArray<UGGeoLine> & arrLines,UGGeoRegion  & region,double dBufferRadius = EP);	

	//!	\brief 获取凸包点
	static  UGbool GetPackagePnt( UGArray<UGGeoLine> & arrLines,UGPoint2Ds & arrPnts);

	//!	\brief 根据给定的线段创建覆盖多边形
	// 覆盖多边形:以pntStart为开始点，顺时针沿arrLines移动 直到回到pntStart点
	static UGbool GetCoverRegion( UGPoint2D pntStart ,UGArray<UGGeoLine> & arrLines,UGGeoRegion & CoverRegion );

	//!	\brief 获取紧缩多边形的构成点
	// CoverRegion  这是由GetCoverRegion 获得的面
	static UGbool GetShrinkPnt( UGGeoRegion & CoverRegion,UGPoint2Ds & arrPnts );

	//!	\brief 如果 nLineIndex小于0 查找以pnt为开头或者结尾的弧段 
	// 如果大于0 就查找nlineIndex所在弧段夹角最小的弧段
	static  int FindPntOnLines( UGPoint2D pnt ,UGArray<UGGeoLine> & arrLines,UGint nLineIndex = -1);

	//!	\brief 获取 GetShrinkPnt 中的点 在 CoverRegion 中的位置
	static UGbool GetPntPosInRegion( UGGeoRegion & CoverRegion,UGPoint2Ds & arrPnts,UGArray<UGint>& nArrPos );

	//!	\brief 连接各点 最后形成一个多边形
	static UGbool LinkAllPnt( UGGeoRegion & CoverRegion ,UGPoint2Ds & arrPnts ,UGArray<UGint>& nArrPos,
		UGGeoRegion  & RegionShrink,UGdouble dBufferRadius = EP);
	
	//!	\brief 得到线段
	static UGbool GetLinesSets(UGArray<UGGeoLine> & arrLines,UGArray<UGint>  & arrLineState  ) ;
	
	//!	\brief 递归实现 GetLinesSets 方法
	static UGbool GetLinesSets(UGint nLineIndex  ,UGArray<UGGeoLine> & arrLines,UGArray<UGint>  & arrLineState  ) ;

	//!	\brief 修正多边形
	static UGbool AllInRegion(UGArray<UGGeoLine> & arrLines,	UGGeoRegion  & region ) ;
	
};

}

#endif

