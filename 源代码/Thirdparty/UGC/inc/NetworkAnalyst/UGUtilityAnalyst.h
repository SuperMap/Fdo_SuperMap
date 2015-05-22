/* 
	\file UGUtilityAnalyst.h
	\brief 设施网络分析类
	\author ugc team
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>更新说明：</b>
	<em>1、第一条说明。</em>
	<em>2、第二条说明。</em>
*/

#ifndef UGUTILITYANALYST_H
#define UGUTILITYANALYST_H

#include "NetworkAnalyst/UGNetworkAnalyst.h"
#include "Base/ugdefs.h"

namespace UGC {

class NETWORKANALYST_API UGUtilityAnalyst  : public UGNetworkAnalyst
{
public:
	UGUtilityAnalyst();

	virtual ~UGUtilityAnalyst();
	
	//!	\brief	流向模式
	enum UGDirectionType
	{
		UGDTPositive	= 0,	//正向
		UGDTNegative	= 1,	//负向
		UGDTDisable		= 2,	//无效方向
		UGDTUninitial	= 3,	//未初始化方向
	};

	//!	\brief	创建水系追踪邻接矩阵
	UGbool CreateTraceAdjMatrix();

	//!	\brief 删除水系追踪邻接矩阵
	void DeleteTraceAdjMatrix();

	//!	\brief	计算河流等级
	//! \param  arrSourceIDs 传入的源点ID数组[in]
	//!	\param arrSinkIDs 传入的汇点ID数组[in]
	//!	\param strGrade 保存弧段等级字段[in]
	//!	\return 如果计算成功则创建弧段等级字段，并写进相关弧段值
	UGbool BuildGrade(const UGString strCostName,UGArray<UGuint> &arrSourceIDs, UGArray<UGuint> &arrSinkIDs, const UGString& strGrade,UGbool bFindWithoutLoops = TRUE,UGbool bCreateFeild = FALSE);
	
	//!	\brief	计算河流流向
	//! \param  arrSourceIDs 传入的源点ID数组[in]
	//!	\param arrSinkIDs 传入的汇点ID数组[in]
	//!	\param strDirection 保存河流流向字段[in]
	//!	\param strNodeType 保存节点类型字段[in]
	//!	\return 如果计算成功则创建流向字段和节点类型字段，并写进相关计算值
	UGbool BuildDirection(const UGString strCostName,UGArray<UGuint> &arrSourceIDs, UGArray<UGuint> &arrSinkIDs, const UGString& strDirection, 
		const UGString& strNodeType,UGbool bCreateFeild = FALSE);
	
	//!	\brief	检查和arrTraceIDs中的点连接的网络环路 
	//!	\param  arrTraceIDs	追踪点ID数组[in]
	//!	\param  arrLoopArcID 保存环路的弧段ID数组[out]
	//!	\return 如果成功返回传出环路的弧段ID数组arrLoopArcID
	UGbool FindLoops(const UGUtilityAnalyseParams &AnalyseParams,UGArray<UGuint> &arrLoopArcID);
	
	//!	\brief	检查和arrTraceIDs中的弧段连接的网络环路 
	//!	\param  arrTraceIDs	追踪弧段ID数组[in]
	//!	\param  arrLoopArcID 保存环路的弧段ID数组[out]
	//!	\return 如果成功返回传出环路的弧段ID数组arrLoopArcID
	UGbool FindLoopsFromArc(const UGUtilityAnalyseParams &AnalyseParams,UGArray<UGuint> &arrLoopArcID);
	
	//!	\brief	检查和arrTraceIDs中的点连通或者不连通的弧段 
	//!	\param  arrResultArcID	保存连通的弧段ID数组[in]
	//!	\param  bFindConnected	如果是TRUE，查找的是连通分量，否则是不连通分量[in]
	//!	\return 如果成功返回传出连通的弧段ID数组arrResultArcID
	UGbool FindConnected(const UGUtilityAnalyseParams &AnalyseParams,UGArray<UGuint> &arrResultArcID);
	
	//!	\brief	检查和arrTraceIDs中的弧段连通或者不连通的弧段 
	//!	\param  arrResultArcID	保存连通的弧段ID数组[in]
	//!	\param  bFindConnected	如果是TRUE，查找的是连通分量，否则是不连通分量[in]
	//!	\return 如果成功返回传出连通的弧段ID数组arrResultArcID
	UGbool FindConnectedFromArc(const UGUtilityAnalyseParams &AnalyseParams,UGArray<UGuint> &arrResultArcID);
	
	//!	\brief	检查和arrTraceIDs中的点共同的上游或者下游弧段 
	//!	\param  arrTraceIDs	追踪点ID数组[in]
	//!	\param  nMode 查找模式，如果nMode是STTSource查找共同的上游,STTSink查找共同的下游[in]
	//!	\param  arrResultArcID	保存上游或者下游弧段ID数组[out]
	//!	\return 如果成功返回传出连通的弧段ID数组arrResultArcID
	UGbool FindCommonAncestors(const UGUtilityAnalyseParams &AnalyseParams,UGArray<UGuint> &arrResultArcID);
	
	//!	\brief	检查和arrTraceIDs中弧段共同的上游或者下游弧段 
	//!	\param  arrTraceIDs	追踪弧段ID数组[in]
	//!	\param  nMode 查找模式，如果nMode是STTSource查找共同的上游,STTSink查找共同的下游[in]
	//!	\param  arrResultArcID	保存上游或者下游弧段ID数组[out]
	//!	\return 如果成功返回传出连通的弧段ID数组arrResultArcID
	UGbool FindCommonAncestorsFromArc(const UGUtilityAnalyseParams &AnalyseParams,UGArray<UGuint> &arrResultArcID);
	
	//!	\brief	检查两个节点之间中连接的最少弧段个数的弧段路径 
	//!	\param  nStartID 需要查询的起始节点[in]
	//!	\param  nEndID 需要查询的终止节点[in]
	//!	\param  arrArcID  保存结果弧段ID数组[out]
	//!	\param  arrNodeID 保存结果节点ID数组[out]
	//!	\return 如果成功返回传出连通的弧段ID数组arrArcID，节点ID数组arrNodeID
	UGbool FindLeastArcsPath(const UGUtilityAnalyseParams &AnalyseParams,UGArray<UGuint> &arrArcID, UGArray<UGuint> &arrNodeID);
	
	//!	\brief	检查两个弧段之间中连接的最少弧段个数的弧段路径 
	//!	\param  nStartID 需要查询的起始弧段[in]
	//!	\param  nEndID 需要查询的终止弧段[in]
	//!	\param  arrArcID  保存结果弧段ID数组[out]
	//!	\param  arrNodeID 保存结果节点ID数组[out]
	//!	\return 如果成功返回传出连通的弧段ID数组arrArcID，节点ID数组arrNodeID
	UGbool FindLeastArcsPathFromArc(const UGUtilityAnalyseParams &AnalyseParams,UGArray<UGuint> &arrArcID, UGArray<UGuint> &arrNodeID);
	
	//!	\brief	检查和点nTraceID中的连接的点上游弧段个数最少的路径 
	//! \param  nTraceID 需要查询的一个节点[in]
	//!	\param  nMode 查找模式，如果nMode是STTSource查找上游,STTSink查找下游[in]
	//!	\param arrArcID	保存上游的弧段ID数组[out]
	//!	\param arrNodeID 保存结果节点ID数组[out]
	//!	\return 如果计算成功返回传出上游连通的弧段ID数组arrArcID，节点ID数组arrNodeID
	UGbool FindAlongStreamPath(const UGUtilityAnalyseParams &AnalyseParams,UGArray<UGuint> &arrArcID, UGArray<UGuint> &arrNodeID);
	
	//!	\brief	检查和点nTraceID中的连接的弧段上游或者弧段个数最少的路径 
	//! \param  nTraceID 需要查询的弧段[in]
	//!	\param arrArcID	保存上游的弧段ID数组[out]
	//!	\param arrNodeID 保存结果节点ID数组[out]
	//!	\return 如果计算成功返回传出上游连通的弧段ID数组arrArcID，节点ID数组arrNodeID
	UGbool FindAlongStreamPathFromArc(const UGUtilityAnalyseParams &AnalyseParams,UGArray<UGuint> &arrArcID, UGArray<UGuint> &arrNodeID);
	
	//!	\brief	查找源头和交汇 
	//!	\param nTraceID		追踪点ID[in]
	//!	\param nMode		追踪模式(查找源或汇)[in]
	//!	\param arrArcID		追踪点到目标点(源或汇)的流经线路ID数组[out]
	//!	\return 成功:返回传出追踪点到目标点的流经线路数组arrArcI
	UGint TraceSource(const UGUtilityAnalyseParams &AnalyseParams, UGArray<UGuint> &arrArcID);
	
	//!	\brief	基于弧段查找源头和交汇 
	//!	\param nTraceID		追踪弧段ID[in]
	//!	\param nMode		追踪模式(查找源或汇)[in]
	//!	\param arrArcID		追踪点到目标点(源或汇)的流经线路ID数组[out]
	//!	\return 成功:返回传出追踪点到目标点的流经线路数组arrArcI
	UGint TraceSourceFromArc(const UGUtilityAnalyseParams &AnalyseParams, UGArray<UGuint> &arrArcID);
	
	//!	\brief	查找上游或下游 
	//!	\param nTraceID		追踪点ID[in]
	//!	\param nMode		追踪模式(查找上游或下游)[in]
	//!	\param arrArcID		流经线路ID数组[out]
	//!	\return 如果成功返回传出追踪点到目标点的流经线路数组arrArcID
	UGbool Trace(const UGUtilityAnalyseParams &AnalyseParams, UGArray<UGuint> &arrArcID);
	
	//!	\brief	查找上游或下游 
	//!	\param nTraceID		追踪弧段ID[in]
	//!	\param nMode		追踪模式(查找上游或下游)[in]
	//!	\param arrArcID		流经线路ID数组[out]
	//!	\return 如果成功返回传出追踪点到目标点的流经线路数组arrArcID
	UGbool TraceFromArc(const UGUtilityAnalyseParams &AnalyseParams, UGArray<UGuint> &arrArcID);
	
	//!	\brief	检查网络环路 
	//!	\param arrErrorArcID	保存环路的弧段ID数组[out]
	//!	\return 成功返回传出环路的弧段ID数组arrErrorArcID
	UGbool TraceCheckError(const UGUtilityAnalyseParams &AnalyseParams,UGArray<UGuint> &arrErrorArcID);

private:
	//!	\brief 将弧段转化为节点
	//!	\param arrArcID		弧段ID数组[in]
	//!	\param arrNodeID	转化为相应的网络节点ID数组[out]
	UGbool ConvertArcIDsToNodeIDs(UGArray<UGuint> &arrArcID, UGArray<UGuint> &arrNodeID);
	
	//!	\brief将弧段转化为节点
	//!	\param strCostName	花费别名[in]
	//!	\param pCostValues	花费结构指针[out]
	UGbool GetTraceFeildCost(const UGString &strCostName,UGCostValues  * pCostValues);

	//!	\brief	计算河流流向
	//! \param  nNodeIndex 节点索引值[in]
	//!	\param arrArcID 弧段ID数组[in]
	//!	\param nMode 计算流向模式[in]
	//!	\return 如果计算成功则创建流向字段和节点类型字段，并写进相关计算值
	UGbool BuildSingleDirection(UGCostValues  *pCostValues,UGIniMemory &IniMemory,UGint nNodeIndex, UGTraceType nMode,UGArray<UGuint> &arrArcID);
	
	//!	\brief	计算河流等级需要的子函数
	//! \param  nSinkID 传入的源点ID[in]
	//!	\param arrArcGrade 保存弧段等级数组[in]
	//!	\return 计算河流等级需要的子函数
	UGbool BuildSingleGrade(UGCostValues  *pCostValues ,UGIniMemory &IniMemory,UGint nSinkID, UGTraceType nMode,UGArray<UGuint> &arrArcGrade,UGbool bFindWithoutLoops = TRUE);
	
private:
	//! \brief 水流方向
	UGArray<UGuint> m_nDirection; 
	//! \brief弧段正向阻力
	UGArray<UGdouble*> m_arrTraceFTCost;
	//! \brief  弧段逆向阻力
	UGArray<UGdouble*> m_arrTraceTFCost;
	//! \brief  花费字段设置信息
	UGArray<UGCostFields> m_arrTraceCostFields;
	//! \brief  节点邻接表
	UGArray<UGPathNode*> m_TraceAdjMatrix;
	//! \brief  弧段信息表
	UGArray <ArcInfo> m_TraceArcInfo;
};

}

#endif 
