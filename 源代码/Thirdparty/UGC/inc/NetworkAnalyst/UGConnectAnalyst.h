/* 
	\file UGConnectAnalyst.h
	\brief 连通性分析
	\author ugc team
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>更新说明：</b>
	<em>1、第一条说明。</em>
	<em>2、第二条说明。</em>
*/
#ifndef UGCONNECTANALYST_H
#define UGCONNECTANALYST_H

#include "NetworkAnalyst/UGNetworkAnalyst.h"
#include "Base/ugdefs.h"

namespace UGC {

class NETWORKANALYST_API UGConnectAnalyst  : public UGNetworkAnalyst
{
public:
	UGConnectAnalyst();

	virtual ~UGConnectAnalyst();

	//!	\brief	创建连通性分析邻接矩阵
	UGbool CreateConnectAdjMatrix();
	
	//!	\brief	删除连通性分析邻接矩阵
	UGbool DeleteConnectAdjMatrix();

	//!	\brief	节点连通性分析 
	//!	\param	nFromID			分析点ID
	//!	\param	nToID			分析方向
	//!	\return	成功：true，任何异常和错误将返回false;
	UGbool IsConnected(const UGint nFromID,const UGint nToID);
	
	//!	\brief	邻接点分析 
	//!	\param	nNodeID			分析点ID
	//!	\param	nDirection		分析方向
	//!	\param	arrNodeID		分析结果点ID表
	//!	\return	邻接点个数
	UGint FindAdjacentNodes(UGint nNodeID,UGint nDirection,UGArray<UGuint> &arrNodeID);
	
	//!	\brief	通达点分析 
	//!	\param	nNodeID			分析点ID
	//!	\param	nDirection		分析方向
	//!	\param	nLevel			分析层数
	//!	\param	arrNodeID		分析结果点ID
	//!	\return	通达点个数
	UGint FindConnectedNodes(UGint nNodeID,UGint nDirection,UGint nLevel,UGArray<UGuint> &arrNodeID);
	
	//!	\brief	通达边分析 
	//!	\param	nNodeID			分析点ID
	//!	\param	nDirection		分析方向
	//!	\param	nLevel			分析层数
	//!	\param	arrEdgeID		分析结果点ID表
	//!	\return	通达边数
	UGint FindConnectedEdges(UGint nNodeID,UGint nDirection,UGint nLevel,UGArray<UGuint> &arrEdgeID);
	
	//!	\brief	关键点分析 
	//!	\param	nStartNode		起点节点ID
	//!	\param	nEndNode		终点节点ID
	//!	\param	nDirection		分析方向
	//!	\param	arrNodeID		分析结果点ID表
	//!	\return	关键点数
	UGint FindCriticalNodes(UGint nStartNode,UGint nEndNode,UGint nDirection,UGArray<UGuint> &arrNodeID);
	
	//!	\brief	关键边分析
	//!	\param	nStartNode		起点节点ID
	//!	\param	nEndNode		终点节点ID
	//!	\param	nDirection		分析方向
	//!	\param	arrEdgeID		分析结果点ID表
    //!	\return	关键边数
	UGint FindCriticalEdges(UGint nStartNode,UGint nEndNode,UGint nDirection,UGArray<UGuint> &arrEdgeID);
		
private:

	//!	\brief	找邻接元素
	//!	\param	nNodeID		节点ID[in]
	//!	\param	nDirection	搜索方向[in]
	//!	\param	arrEdgeID	分析结果弧段点ID表[out]
	//!	\param	arrEdgeID	分析结果节点ID表[out]
    //!	\return	TRUE
	UGbool FindAdjacentElement(UGint nNodeID,UGint nDirection,UGArray<UGuint> &arrEdgeID,UGArray<UGuint> &arrNodeID);
	
	//!	\brief	找关键元素个数
	//!	\param	nStartID 	 起始节点ID[in]
	//!	\param	nEndID	     终点节点ID[in]
	//!	\param	arrElementID 元素ID数组[out]
	//!	\param	bIsNode	     是否为节点[out]
    //!	\return	关键元素个数
	UGint FindCriticalElement(UGint nStartID,UGint nEndID,UGArray<UGuint> &arrElementID,UGbool bIsNode=false);
	
	//!	\brief	找关键元素个数
	//!	\param	nStartID 	 起始节点ID[in]
	//!	\param	nEndID	     终点节点ID[in]
	//!	\param	arrElementID 元素ID数组[out]
	//!	\param	bIsNode	     是否为节点[out]
    //!	\return	关键元素个数
	UGbool FindCriticalTow(UGint nStartID,UGint nEndID,UGArray<UGuint> &arrElementID,UGbool bIsNode=false);
	
	//!	\brief	找相连元素
	//!	\param	nStartNode 	 起始节点ID[in]
	//!	\param	nDirection	 分析方向[in]
	//!	\param	arrEdgeID    弧段ID数组[out]
	//!	\param	arrStartEnd	 弧段ID数组[out]	
	void FindConnectEP(UGint nStartNode,UGint nDirection,UGArray<UGuint> &arrEdgeID,UGArray<UGuint> &arrStartEnd);
	
	//!	\brief	找连接元素
	//!	\param	nNodeID		节点ID[in]
	//!	\param	arrArcID	弧段ID数组[out]
	//!	\param	arrNodeID	节点ID数组[out]
    //!	\return	TRUE
	UGbool FindConnectedElement(UGint nNodeID,UGArray<UGuint> &arrArcID,UGArray<UGuint> &arrNodeID);

	//关键点,关键边分析相关结构
	//!	\brief 创建关键元素邻接矩阵
	UGbool CreateCriticalOneAdjMatrix();

	//!	\brief 析构关键元素邻接矩阵
	UGbool DeleteCriticalOneAdjMatrix() ;

	//!	\brief 创建关键点邻接矩阵
	UGbool CreateCriticalNodeAdjMatrix();
		
	//!	\brief 析构关键点邻接矩阵
	UGbool DeleteCriticalNodeAdjMatrix();

	//!	\brief	检查两个点是否是关键点
	//!	\param	nEndNodeID  终点节点ID[in]
	//!	\param	ntestNodeID	检查点ID[in]
	//!	\param	pNodeLevels	距离数组[in]
	//!	\param	nCount	个数[in]
    //!	\return	TRUE
	UGbool TestNode(UGint nEndNodeID,UGint ntestNodeID,UGint *pNodeLevels,UGint nCount);
	
	//!	\brief	检查边是否是关键边
	//!	\param	nEndNodeID  终点节点ID[in]
	//!	\param	ntestNodeID	检查点ID[in]
	//!	\param	pNodeLevels	距离数组[in]
	//!	\param	nCount	个数[in]
    //!	\return	TRUE
	UGbool IsCritiCalEdge(UGint nEndNode,UGint nTestNode,UGint *pNodeLevel,UGint &nCount);
	
	//!	\brief	检查点是否是关键点
	//!	\param	nEndNodeID  终点节点ID[in]
	//!	\param	ntestNodeID	检查点ID[in]
	//!	\param	pNodeLevels	距离数组[in]
	//!	\param	nCount	个数[in]
    //!	\return	TRUE
	UGbool IsCriticalNode(UGint nEndNode,UGint nJudgeNode,UGint *pNodeLevel,UGint nCount);

public:
	//关键点分析相关结构：
	UGArray<CriticalOne*> m_CriticalOneAdjMatrix;

	//关键点分析相关结构：
	UGArray<CriticalNode*> m_CriticalNodeAdjMatrix;

	//UGArray<UGint> m_arrOrder;
	UGArray<CriticalIndex> m_arrOrder;


	UGArray <ArcInfo> m_ConnectArcInfo;					//弧段信息表
	// 是否重建邻接矩阵
	UGbool m_bReBuildCriticalNodeMatrix ;
};

}

#endif 
