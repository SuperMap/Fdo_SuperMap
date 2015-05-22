/* 
	\file UGBusNetwork.h
	\brief 公交换乘建摸和分析
	\author ugc team
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>更新说明：</b>
	<em>1、第一条说明。</em>
	<em>2、第二条说明。</em>
*/

#ifndef UGBUSNETWORK_H
#define UGBUSNETWORK_H

#include "NetworkAnalyst/UGNetworkAnalystEnv.h"

namespace UGC {

class TopoGridEnv;
class NETWORKANALYST_API UGBusNetwork  : public UGNetworkAnalystEnv
{
public:
	UGBusNetwork();
	
	virtual ~UGBusNetwork();
	
	enum UGDirectionType
	{
		UGSingle	= 1,	
		UGBoth		= 2,
		UGRound		= 3
	};
	
public:		
	//! \brief 设置容限
	/**
	 \param		dMergerInterval	站点归并容限
	 \param		dStopInterval	站点捕捉容限
	 \remarks	
	 1、距离在dMergerInterval范围内的站点需要进行合并处理，合并之后产生出一个逻辑站点，真实站点和逻辑站点
		形成多对一的关系；在实际分析中我们使用逻辑站点进行处理；在结果输出中再换算成真实站点。
	 2、站点到线路的距离在dStopInterval范围内就规定该站点属于对应的线路；
	 3、dMergerInterval一定要比dStopInterval大,并且两者都要大于0；
	*/
	void SetInterval(const UGdouble& dMergerInterval, const UGdouble& dStopInterval);
	
	//! \brief 获取已设置的容限
	/**
	 \param		dMergerInterval	站点归并容限
	 \param		dStopInterval	站点捕捉容限
	*/
	void GetInterval(UGdouble& dMergerInterval, UGdouble& dStopInterval);
	
	//!	\brief	公交网络建摸\n
	/**
	//!	\param	pDTBusLine			公交线路数据集
	//!	\param	pDTBusStop			公交站点数据集
	//!	\param	strBusNetworkName	生成公交网络名称
	//!	\return	成功：返回公交网络数据集，任何异常和错误将返回NULL;
	\remarks	公交线路和站点联合生成公交网络，公交网络存储了公交线路和站点之间的拓扑关系，换乘分析基于公交网络；
	*/
	UGDatasetVector* BuildBusNetwork(UGDatasetVector* pDTBusLine, UGDatasetVector* pDTBusStop,
									const UGString& strBusNetworkName);
	
	//!	\brief	更新公交网络部分线路\n
	/**
	//!	\param	pRSBusLine			需要更新的公交线路记录集
	//!	\param	pDTBusStop			公交站点数据集
	//!	\param	pDTBusNetwork		公交网络数据集
	//!	\return	成功：TRUE，任何异常和错误将返回FALSE;
	\remarks	公交线路更新实际上就是更新线路重新匹配关联站点，并把更新结果体现在公交网络pDTBusNetwork中；
	*/
	UGbool UpdateBusLines(UGRecordset* pRSBusLine, UGDatasetVector* pDTBusStop, UGDatasetVector* pDTBusNetwork);
	
	//!	\brief	删除公交网络部分线路\n
	/**
	//!	\param	arrLineIDs			需要删除的公交线路ID集合
	//!	\param	pDTBusNetwork		公交网络数据集
	//!	\return	成功：TRUE，任何异常和错误将返回FALSE;
	\remarks	公交线路删除实际上就是在公交网络pDTBusNetwork中删除和被删除线路相关的记录；
	*/
	UGbool RemoveBusLines(UGArray<UGint> arrLineIDs, UGDatasetVector* pDTBusNetwork);
	
	//!	\brief	删除公交网络一条线路\n
	/**
	//!	\param	nLineID				需要删除的公交线路ID
	//!	\param	pDTBusStop			公交站点数据集
	//!	\param	pDTBusNetwork		公交网络数据集
	//!	\return	成功：TRUE，任何异常和错误将返回FALSE;
	*/
	UGbool RemoveBusLine(UGint nBusLineID, UGDatasetVector* pDTBusNetwork);

public:	
	/*!	\brief	设置公交线路名称字段*/
	void SetRouteNameField(const UGString& strRouteName);
	
	/*!	\brief	获取公交线路名称字段*/
	const UGString& GetRouteNameField()const;
	
	/*!	\brief	设置公交站点名称字段*/
	void SetStopNameField(const UGString& strStopName);
	
	/*!	\brief	获取公交站点名称字段*/
	const UGString& GetStopNameField()const;
	
	//!	\brief	设置公交网络相关数据集\n
	//!	\param	BusNetworkDT		公交网络相关数据集结构
	//!	\return	成功：TRUE，任何异常和错误将返回FALSE;
	UGbool SetBusNetworkDT(const UGBusNetworkDT& BusNetworkDT);
	
	//!	\brief	获取公交网络相关数据集\n
	//!	\return	返回已设置的公交网络相关数据集，无设置返回NULL;
	const UGBusNetworkDT& GetBusNetworkDT() const;
	
	//! \brief 创建内存公交线路和站点的拓扑关系
	UGbool CreateBusNetwork();
	
	//!	\brief	公交换乘分析\n
	//!	\param	BusNetworkParams		公交换乘分析参数
	//!	\param	ResultRoutings			结果线路集合
	//!	\return	成功：TRUE，任何异常和错误将返回FALSE;
	UGbool DoTransfer(const UGTransferParams& BusNetworkParams, UGRouteResults& ResultRoutings);
	
	//!	\brief	获取线路几何数据\n
	//!	\param	RouteResult			公交线路
	//!	\param	arrLines			组成该公交线路的几何线集合
	//!	\return	成功：TRUE，任何异常和错误将返回FALSE;
	UGbool GetGeoLines(const UGRouteResult& RouteResult, UGArray<UGGeoLine*>& arrLines);
	
	//!	\brief	获取每段换成乘线路中间经过的站点ID\n
	//!	\param	pResRouting			换成乘线路段
	//!	\param	arrStopIDs			获取该段线路经过的中间站点ID
	//!	\return	成功：TRUE，任何异常和错误将返回FALSE;
	UGbool GetRoutingStopIDs(const UGBusRouting* pResRouting, UGArray<UGint>& arrStopIDs);
	
public:
	//!	\brief	获取某条线路上的站点\n
	//!	\param	nBusLineID			公交线路ID
	//!	\param	arrBusStopIDs		站点集合
	//!	\return	成功：TRUE，任何异常和错误将返回FALSE;
	UGbool GetBusStops(UGint nBusLineID, UGArray<UGint>& arrBusStopIDs);
	
	//!	\brief	获取经过某站点的所有线路\n
	//!	\param	nBusStopID			公交站点ID
	//!	\param	arrBusLineIDs		公交线路集合
	//!	\return	成功：TRUE，任何异常和错误将返回FALSE;
	UGbool GetBusLines(UGint nBusStopID, UGArray<UGint>& arrBusLineIDs);
	
private:
	UGbool BuildBusNetwork(UGRecordset* pRSBusLine, UGRecordset* pRSBusStop, UGDatasetVector* pDTBusNetwork);
	UGbool MergerStops(TopoGridEnv& TopoGridUnitP);
	
	UGbool MatchStops(TopoGridEnv& TopoGridUnitL, UGArray<UGGeometry*> &arrObjects, UGArray<UGint> &arrStopID, 
						UGSingleRoutes& SingleRoutes);
	
	UGbool MergeRoutes(UGSingleRoutes& SingleRoutes, UGBusNetworkParams& BusNetworkParams);
	
	UGbool TransZeroTime(UGBusStop* pFromStop, UGBusStop* pToStop, UGbyte* pbtRouteSign, UGRouteResults& RouteResults);
	UGbool TransOneTime(UGBusStop* pFromStop, UGBusStop* pToStop, UGbyte* pbtRouteSign, UGRouteResults& RouteResults);
	UGbool TransOneTime(UGBusStop* pFromStop, UGBusStop* pToStop, UGbyte* pbtRouteSign, UGBusRouteings& BusRouteings);
	UGbool DirectRoutes(UGBusStop* pFromBusStop, UGBusStop* pToBusStop, UGbyte* pbtRouteSign, UGBusRouteings& BusRouteings);
	UGbool IntersectByStop(UGBusRoute* pFromBusRoute, UGBusRoute* pToBusRoute, UGint nFromIndex, UGint nToIndex,UGBusRouteings& BusRouteings);
	UGbool IntersectByRoute(UGBusRoute* pFromBusRoute, UGBusRoute* pToBusRoute, UGint nFromIndex, UGint nToIndex, 
							UGbyte* pbtRouteSign, UGBusRouteings& BusRouteings, UGint nPassRouteCount);
	
	UGbool DoTransfer(UGBusStop* pFromBusStop, UGBusStop* pToBusStop, UGbyte* pbtRouteSign, UGBusRouteings& BusRouteings, UGint nPassRouteCount);
	UGbool DoTransfer(UGBusStop* pFromBusStop, UGBusStop* pToBusStop, UGbyte* pbtRouteSign, UGRouteResults& RouteResults, UGint nTransferCount);
	UGBusStop* GetBusStop(UGint nStopID);
	UGbool UnionRoutes(UGBusRouting& FromBusRouteing, UGBusRouting& ToBusRouteing,
						UGBusRouteings& BusRouteings, UGBusRouteings& UnionRouteings,
						UGint nPassRouteCount);
	
	UGbool BuildTopoGrid(UGRecordset *pRecordset, UGdouble dGridCount, TopoGridEnv& TopoGridUnit, 
						UGint GridType);
	
	UGbool SortRoutes(UGRouteResults& RouteResults, UGbyte* pbtRouteSign, const UGString& strCostName, 
						UGint nTransferCount);
	
private:	
	UGdouble m_dMergerInterval;
	UGdouble m_dStopInterval;
	UGBusNetworkDT m_BusNetworkDT;
	
	UGBusRoutes m_BusPaths;
	UGBusStops  m_BusStops;
	UGRelRoutes m_RelRoutes;
	UGRelStops  m_RelStops;
	UGArray<UGint> m_arrMergeID;
	UGArray<UGdouble*> m_arrBusLineCost;
	UGdouble* m_pdLength;
	
	UGString m_strRouteName;
	UGString m_strStopName;
};

}


#endif
