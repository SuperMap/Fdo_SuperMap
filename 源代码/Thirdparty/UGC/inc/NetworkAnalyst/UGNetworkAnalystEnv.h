/* 
	\file UGNetworkAnalystEnv.h
	\brief 网络分析环境设置类
	\author ugc team
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>更新说明：</b>
	<em>1、第一条说明。</em>
	<em>2、第二条说明。</em>
*/
#ifndef UGNETWORKANALYSTENV_H
#define UGNETWORKANALYSTENV_H

#include "Base/ugdefs.h"
#include "Base/UGString.h"
#include "Geometry/UGGeoLineM.h"
#include "NetworkAnalyst/UGNetworkTypes.h"
#include "Engine/UGDataSource.h"
#include "NetworkAnalyst/UGRoute.h"

namespace UGC {

class UGDatasetVector;

class NETWORKANALYST_API UGNetworkAnalystEnv  
{
public:
	UGNetworkAnalystEnv();
	
	virtual ~UGNetworkAnalystEnv();
	
	enum UGResultInfoType
	{
		UGRIRoutes			= 0x00000001,	//
		UGRIPathTable		= 0x00000002,	//
		UGRIPathGuides		= 0x00000002,	//
		UGRIViaEdges		= 0x00000004,	//
		UGRIViaNodes		= 0x00000008,	//
		UGRIServiceRegions	= 0x00000010,	//
		UGRILocationCenters	= 0x00000020,	//
		UGRILocationNodes	= 0x00000040,	//
		UGRIPathStops		= 0x00000080,	//
	};

	enum DirectionConstant
	{
		DC_EAST				= 0, // 东
		DC_NORTH_EAST		= 1, // 东北
		DC_NORTH			= 2, // 北
		DC_NORTH_WEST		= 3, // 西北
		DC_WEST				= 4, // 西
		DC_SOUTH_WEST		= 5, // 西南
		DC_SOUTH			= 6, // 南
		DC_SOUTH_EAST		= 7, // 东南
	};
	
	typedef UGArray<UGTurnCost*> TurnCost;
public:
	/*!	\brief	设置网络数据集*/
	UGbool SetDatasetNetwork(UGDatasetVector* pDtNetwork);
	/*!	\brief	获取网络数据集*/
	const UGDatasetVector* GetDatasetNetwork()const;
	/*!	\brief	设置正向权值字段*/
	void SetFTWeightField(const UGString& strFTWeight);
	/*!	\brief	获取正向权值字段*/
	const UGString& GetFTWeightField()const;
	/*!	\brief	设置反向权值字段*/
	void SetTFWeightField(const UGString& strTFWeight);
	/*!	\brief	获取反向权值字段*/
	const UGString& GetTFWeightField()const;
	/*!	\brief	设置节点ID字段*/
	void SetNodeIDField(const UGString& strNodeIDField);
	/*!	\brief	获取节点ID字段*/
	const UGString& GetNodeIDField()const;
	/*!	\brief	设置弧段ID字段*/
	void SetArcIDField(const UGString& strArcIDField);
	/*!	\brief	获取弧段ID字段*/
	const UGString& GetArcIDField()const;
	/*!	\brief	设置FNodeID字段*/
	void SetFNodeIDField(const UGString& strFNodeIDField);
	/*!	\brief	获取FNodeID字段*/
	const UGString& GetFNodeIDField()const;
	/*!	\brief	设置TNodeID字段*/
	void SetTNodeIDField(const UGString& strTNodeIDField);
	/*!	\brief	获取FNodeID字段*/
	const UGString& GetTNodeIDField()const;
	
	/*!	\brief	设置转向表*/
	UGbool SetDatasetTRN(UGDatasetVector* pDtTRN);
	/*!	\brief	获取转向表*/
	const UGDatasetVector* GetDatasetTRN()const;
	/*!	\brief	设置TRN节点ID字段*/
	void SetTRNNodeIDField(const UGString& strTRNNodeID);
	/*!	\brief	获取TRN节点ID字段*/
	const UGString& GetTRNNodeIDField()const;
	/*!	\brief	设置TRN起始弧段ID字段*/
	void SetTRNArcFromIDField(const UGString& strTRNArcFromID);
	/*!	\brief	获取TRN起始弧段ID字段*/
	const UGString& GetTRNArcFromIDField()const;
	/*!	\brief	设置TRN终止弧段ID字段*/
	void SetTRNArcToIDField(const UGString& strTRNArcToID);
	/*!	\brief	获取TRN终止弧段ID字段*/
	const UGString& GetTRNArcToIDField()const;
	/*!	\brief	设置TRNWeight字段*/
	void SetTRNWeightField(const UGString& strTRNWeight);
	/*!	\brief	获取TRNWeight字段*/
	const UGString& GetTRNWeightField()const;
	
	/*!	\brief	设置需求节点表*/
	UGbool SetDatasetDMDNode(UGDatasetVector* pDtDMDNode);
	/*!	\brief	获取需求节点表*/
	const UGDatasetVector* GetDatasetDMDNode()const;
	/*!	\brief	设置需求弧段表*/
	UGbool SetDatasetDMDArc(UGDatasetVector* pDtDMDArc);
	/*!	\brief	获取需求弧段表*/
	const UGDatasetVector* GetDatasetDMDArc()const;
	/*!	\brief	设置节点需求量字段*/
	void SetNodeDemandField(const UGString& strNodeDemand);
	/*!	\brief	获取节点需求量字段*/
	const UGString& GetNodeDemandField()const;
	/*!	\brief	设置弧段需求量字段*/
	void SetArcDemandField(const UGString& strArcDemand);
	/*!	\brief	获取弧段需求量字段*/
	const UGString& GetArcDemandField()const;
	
	/*!	\brief	设置中心点数据集*/
	UGbool SetDatasetCenter(UGDatasetVector* pDtCenter);
	/*!	\brief	获取中心点数据集*/
	const UGDatasetVector* GetDatasetCenter()const;

	/*!	\brief	设置中心ID字段*/
	void SetCenterIDField(const UGString& strCenterID);
	/*!	\brief	获取中心ID字段*/
	const UGString& GetCenterIDField()const;
	/*!	\brief	设置候选中心字段*/
	void SetCenterCandidateField(const UGString& strCenterCandidate);
	/*!	\brief	获取候选中心字段*/
	const UGString& GetCenterCandidateField()const;
	/*!	\brief	设置中心资源量字段*/
	void SetCenterResourceField(const UGString& strCenterResource);
	/*!	\brief	获取中心资源量字段*/
	const UGString& GetCenterResourceField()const;
	/*!	\brief	设置中心最大阻值字段*/
	void SetCenterMaxImpedanceField(const UGString& strCenterMaxImpedance);
	/*!	\brief	获取中心最大阻值字段*/
	const UGString& GetCenterMaxImpedanceField()const;
	
	/*!	\brief	设置弧段过滤字段*/
	void SetArcFilter(UGString strArcFilter);
	/*!	\brief	获取弧段过滤字段*/
	const UGString& GetArcFilter()const;
	
	/*!	\brief	设置道路规则字段*/
	void SetRoadRuleField(UGString strRoadRule);
	/*!	\brief	设置正向单行道*/
	void SetLanePositive(UGArray<UGint> &arr_Lane_Positive);
	/*!	\brief	设置逆向单行道*/
	void SetLaneNegative(UGArray<UGint> &arr_Lane_Negative);
	/*!	\brief	设置禁行道路*/
	void SetNOEntry(UGArray<UGint> &arr_NO_Entry);
	/*!	\brief	设置双行道*/
	void SetBothDirection(UGArray<UGint> &arr_Both_Direction);
	
	/*!	\brief	设置行使导引中狐段结点名称字段*/
	void SetPathGuideNameField(const UGPathGuideName& strPathFeildNames);
	
	/*!	\brief	获取行使导引中狐段结点名称字段*/
	const UGPathGuideName& GetPathGuideNameField()const;
	
	/*!	\brief	设置节点选择容限*/
	void SetNodeInterval(UGdouble dNodeInterval);
	/*!	\brief	获取节点选择容限*/
	UGdouble GetNodeInterval()const;
	
	/*!	\brief	设置公交线路权值字段*/
	void SetBusCostFields(const UGArray<UGString> &arrCostFields);
	UGbool GetBusCostFields(UGArray<UGString> &arrBusCostFields);
	
	
	
	UGDatasetVector* CreateResultRouteDT(const UGString& strResultRoute,UGArray<UGGeoLineM>  &arrRoute,UGbool bMSiteAnalyst = FALSE );
	
	//!	\brief	设置存放结果的数据源\n
	//!	\param	pOutputDataSource		数据源指针
	//!	\return	设置成功返回TRUE，否则返回FALSE；
	//!  \remarks	数据源指针不为空，不能ReadOnly；
	UGbool SetOutputDataSource(UGDataSource* pOutputDataSource);
	
	/*!	\brief	得到输出数据源指针*/
	UGDataSource* GetOutputDataSource();
	
	/*!	\brief	设置结点类型字段*/
	void SetNodeType(UGString strNodeType);
	/*!	\brief	获取结点类型字段*/
	const UGString& GetNodeType()const;
	/*!	\brief	设置流向字段*/
	void SetDirection(UGString strDirection);
	/*!	\brief	获取流向字段*/
	const UGString& GetDirection()const;
	
	UGbool GetGeoLineM(UGint nStartNodeID, UGArray<UGuint>& arrArcIDs, UGArray<UGdouble>& arrCost);
	UGbool GetGeoLineM(UGint nStartNodeID, UGArray<UGuint>& arrArcID, UGdouble dTotalCost,UGArray<UGGeoLineM>& arrRoute);
	
	UGbool GetGeoLineM(UGPoint2D pntStart, UGRoute &resRoute,UGdouble dTotalCost);

	UGbool GetGeoLineM(UGRoute &resRoute, UGdouble dTotalCost,UGArray<UGGeoLineM>&arrRoute);
    //! 为资源分配结果或得添加的接口
	UGbool GetAllcateGeoLineM(UGRoute &resRoute, UGdouble dTotalCost,UGArray<UGGeoLineM>&arrRoute,UGArray<UGuint> &arrNodeIDAllocated,UGArray<UGuint> &arrArcIDAllocated);
	
	//结果信息设置
	//!	\brief 是否生成结果
	UGbool IsRoute(const ResultInfo &nResultInfo);
	//!	\brief 是否生成结果
	UGbool IsPathTable(const ResultInfo &nResultInfo);
	//!	\brief 是否生成结果
	UGbool IsViaEdge(const ResultInfo &nResultInfo);
	//!	\brief 是否生成结果
	UGbool IsViaNode(const ResultInfo &nResultInfo);
	//!	\brief 是否生成结果
	UGbool IsRegion(const ResultInfo &nResultInfo);
	//!	\brief 是否生成结果
	UGbool IsLocationCenters(const ResultInfo &nResultInfo);
	//!	\brief 是否生成结果
	UGbool IsLocationNodes(const ResultInfo &nResultInfo);
	//!	\brief 是否生成结果
	UGbool IsStops(const ResultInfo &nResultInfo);
	//行使导引
	//!	\brief 是否生成结果
	UGbool IsPathGuide(const ResultInfo &nResultInfo);
	//!	\brief 生成结果
	UGbool GetStops(const ResultInfo &nResultInfo,UGArray<UGuint>& arrNodeID, UGArray<UGdouble>& arrCost);
	//!	\brief 生成结果
	UGbool GetServiceViaEdge( ResultInfo &nResultInfo,UGRoute& ServiceRoute);
	//!	\brief 生成结果
	UGbool GetServiceViaNode( ResultInfo &nResultInfo,UGuchar* pbtOnPath);
	//!	\brief 生成结果
	UGbool GetViaNode( ResultInfo &nResultInfo,UGArray<UGuint>& arrNodeID, UGint nRouteCount);
	//!	\brief 生成结果
	UGbool GetViaNode( ResultInfo &nResultInfo,UGArray<UGuint>& arrNodeID);
	//!	\brief 生成结果
	UGbool GetViaNode( ResultInfo &nResultInfo,UGArray<UGuint>& arrNodeID, UGArray<UGint>& arrViaCount);
	//!	\brief 生成结果
	UGbool GetViaEdge( ResultInfo &nResultInfo,UGArray<UGuint>& arrArcID, UGint nRouteCount);
	//!	\brief 生成结果
	UGbool GetViaEdge( ResultInfo &nResultInfo,UGArray<UGuint>& arrArcID);
	//!	\brief 生成结果
	UGbool GetViaEdge( ResultInfo &nResultInfo,UGArray<UGuint>& arrArcID, UGArray<UGint>& arrViaCount);
	//!	\brief 生成结果
	UGbool GetRegion(UGArray<UGGeoRegion>& arrCoverRegion, ResultInfo &nResultInfo);
	//!	\brief 生成结果
	UGbool GetRoute(const ResultInfo &nResultInfo,UGArray<UGGeoLineM>& arrRoute,UGbool bMSiteAnalyst = FALSE );
	//!	\brief 生成结果
	UGbool GetRoute(const ResultInfo &nResultInfo,UGint nStartNodeID, UGArray<UGuint>& arrArcIDs, UGdouble dTotalCost);
	//!	\brief 生成结果
	UGbool GetRoute(const ResultInfo &nResultInfo,const UGPoint2D& pntStartNode, UGRoute& resRoute, UGdouble dTotalCost);
	//!	\brief 生成结果
	UGbool GetRoute(const ResultInfo &nResultInfo,UGint nStartNodeID, UGArray<UGuint>& arrArcID, UGArray<UGdouble> &arrCost);
	//!	\brief 生成结果
	UGbool GetRoute(const ResultInfo &nResultInfo,const UGPoint2D& pntStart, UGArray<UGRoute>& arrArcIDs, UGArray<UGdouble>& arrFacilityDist);


	//判断是否需要生成路径
	UGbool IsRoute(UGint nOptions);
	
	//判断是否需要生成行驶导引
	UGbool IsPathGuide(UGint nOptions);
	
	//判断是否需要生成经过弧段信息
	UGbool IsViaEdge(UGint nOptions);
	
	//判断是否需要生成经过网络节点信息
	UGbool IsViaNode(UGint nOptions);
	
	//判断是否需要生成站点信息
	UGbool IsStops(UGint nOptions);
	
	//判断是否需要生成经过服务区面
	UGbool IsRegion(UGint nOptions);
	
	//判断是否需要生成资源分配中心点信息
	UGbool IsLocationCenters(UGint nOptions);
	
	//判断是否需要生成选址中心点信息
	UGbool IsLocationNodes(UGint nOptions);
	
	//判断是否需要生成PathTable
	UGbool IsPathTable(UGint nOptions);

	//!	\brief	生成查询字符串表达式
	//!	\param  arrKeys IDs数组[in] 
	//!	\param  strFieldName 指定查询的是数据集字段名称[in] 
	//!	\return	查询字符串表达式
	//!  \remarks 数据库查询的时候，对指定字段的IDs查询
	UGString BuildQueryFilter(UGArray<UGuint> &arrKeyIDs,const UGString strFieldName);

	//{{下面的函数用来生成行使导引的表现形式
	//!	\brief	将数字转化为字符串方向
	//!	\param nDirection 方向位置参数[in] 
	//!	\return	成功：TRUE，任何异常和错误将返回FALSE;
	//!  \remarks
	UGString GetDirection(UGint nDirection);
	
	//!	\brief	转化为转向参数
	//!	\param nViaTurnType 转向位置参数[in] 
	//!	\return	转向字符创方向;
	//!  \remarks
	UGString GetVia2RoadPosition(UGint nViaTurnType);
	
	//!	\brief	将角度转化为八个方位
	//!	\param dDegree 角度[in] 
	//!	\return	将角度转化为八个方位;
	//!  \remarks
	DirectionConstant GetDirectionByDegree(UGdouble dDegree);
	
	//!	\brief	得到路径的方向
	//!	\param nDirection 方位[in] 
	//!	\return	路径方向的字符串;
	//!  \remarks
	UGString GetRoadDirection(DirectionConstant nDirection);
    //}}
	
	//!	\brief	将NodeID转化为Node索引
	//!	\param arrIDs ID数组[in] 
	//!	\param arrIndex 索引数组[out] 
	//!	\return	成功转化返回TRUE，否则返回FALSE
	//!  \remarks
	UGbool NodeConvertIDToIndex(UGArray<UGuint> &arrIDs, UGArray<UGuint> &arrIndex);

	//!	\brief	将ArcID转化为Arc索引
	//!	\param arrIDs ID数组[in] 
	//!	\param arrIndex 索引数组[out] 
	//!	\return	成功转化返回TRUE，否则返回FALSE
	//!  \remarks
	UGbool ArcConvertIDToIndex(UGArray<UGuint> &arrIDs, UGArray<UGuint> &arrIndex);

	//!	\brief	生成行使导引报告表格 
	//!	\param PathGuides 转向表结构
	//!	\param strPathGuideName 转向表名称[in]
	//!	\param dTotalCost 总的花费[in]
	//!	\return	成功：TRUE，任何异常和错误将返回FALSE;
	//!  \remarks
	UGbool MakePathguides(UGPathGuides& PathGuides, UGString &strPathGuideName,UGdouble dTotalCost);

	//!	\brief	生成距离矩阵报告表格 
	//!	\param arrDistMatrix 距离矩阵数组[in]
	//!	\param streDistMatrixReportName 距离矩阵报告名称[in]
	//!	\return	成功：TRUE，任何异常和错误将返回FALSE;
	//!  \remarks
	UGbool MakeDistMatrixReport(UGArray<UGDistMatrixUnit> &arrDistMatrix, UGString &streDistMatrixReportName);

	//!	\brief	生成距离矩阵报告表格
	//!	\param arrIDs 数组[in]
	//!	\param strReportName 报告名称[in]
	//!	\return	成功：TRUE，任何异常和错误将返回FALSE;
	//!  \remarks
	UGbool MakeTestArrayReport(UGArray<UGuint> &arrIDs, UGString &strReportName);

	//!	\brief	生成路由数据集 
	//!	\param strResultRoute 路由数据集名称[in]
	//!	\param arrRoute 路由结构[in]
	//!	\return	成功：TRUE，任何异常和错误将返回FALSE;
	//!  \remarks
	UGDatasetVector* MakeRouteDT(const UGString& strResultRoute,UGArray<UGGeoLineM>  &arrRoute,UGbool bCreate = FALSE );
	
	//!	\brief	生成经过网络节点数据集 
	//!	\param strViaNodeName 网络节点数据集名称[in]
	//!	\param arrViaPT 网络节点结构[in]
	//!	\return	成功：TRUE，任何异常和错误将返回FALSE;
	//!  \remarks
	UGbool MakeViaNodeDT( const UGString &strViaNodeName,UGArray<UGViaInfo> &arrViaPT);

	//!	\brief	生成经过网络弧段数据集 
	//!	\param strViaEdgeName 网络弧段数据集名称[in]
	//!	\param arrViaArc 网络弧段结构[in]
	//!	\return	成功：TRUE，任何异常和错误将返回FALSE;
	//!  \remarks
	UGbool MakeViaEdgeDT( const UGString &strViaEdgeName,UGArray<UGViaInfo> &arrViaArc);

	//!	\brief	生成经过站点信息数据集 
	//!	\param strStopName 站点数据集名称[in]
	//!	\param arrViaStop 站点结构[in]
	//!	\return	成功：TRUE，任何异常和错误将返回FALSE;
	//!  \remarks
	UGbool MakeStopsDT( const UGString &strStopName,UGArray<UGStopInfo> &arrViaStop);

	//!	\brief	生成需求中心点信息数据集 
	//!	\param strLocationNodeName 需求点数据集名称[in]
	//!	\param arrDemand 需求点结构[in]
	//!	\return	成功：TRUE，任何异常和错误将返回FALSE;
	//!  \remarks
	UGbool MakeLocationNodeDT( const UGString &strLocationNodeName,UGArray<UGDemandResInfo>& arrDemand);

	//!	\brief	生成选址中心点信息数据集 
	//!	\param strLocationNodeName 选址中心点数据集名称[in]
	//!	\param arrDemand 选址中心点结构[in]
	//!	\return	成功：TRUE，任何异常和错误将返回FALSE;
	//!  \remarks
	UGbool MakeLocationCenterDT( const UGString &strLocationCenterName,UGArray<UGRetCenterInfo>& arrRetCenter);

	//!	\brief	生成服务区分析面信息数据集 
	//!	\param strRegionName 面数据集名称[in]
	//!	\param arrRegion     面结构数组[in]
	//!	\param arrCost       各个面的花费[in]
	//!	\return	成功：TRUE，任何异常和错误将返回FALSE;
	//!  \remarks
	UGbool MakeRegionDT(const UGString &strRegionName,UGArray<UGGeoRegion>& arrRegion,UGArray<UGdouble>& arrCost);


	//!	\brief	得到路由信息函数 
	//!	\param ResInfo 结果结构[in]
	//!	\param arrRoute     路由数组[in]
	//!	\return	成功：TRUE，任何异常和错误将返回FALSE;
	//!  \remarks
	UGbool GetRouteInfo(UGResultInfo &ResInfo,UGArray<UGGeoLineM>& arrRoute);

	//!	\brief	得到路由信息函数 
	//!	\param ResInfo 结果结构[in]
	//!	\param pntStart     起始点坐标[in]
	//!	\param resRoute     单个路由[in]
	//!	\param dTotalCost   单个路由花费[in]
	//!	\return	成功：TRUE，任何异常和错误将返回FALSE;
	//!  \remarks
	UGbool GetRouteInfo(UGResultInfo &ResInfo, UGPoint2D pntStart, UGRoute &resRoute, UGdouble dTotalCost);

	//!	\brief	得到路由信息函数 
	//!	\param ResInfo          结果结构[in]
	//!	\param pntStart         起始点坐标[in]
	//!	\param arrresRoutes     路由数组[in]
	//!	\param arrFacilityDist  路由花费数组[in]
	//!	\return	成功：TRUE，任何异常和错误将返回FALSE;
	//!  \remarks
	UGbool GetRouteInfo(UGResultInfo &ResInfo, UGPoint2D pntStart, UGArray<UGRoute>& arrresRoutes, UGArray<UGdouble>& arrFacilityDist);

	//!	\brief	得到路由信息函数 
	//!	\param ResInfo          结果结构[in]
	//!	\param nStartNodeID     起始点ID[in]
	//!	\param arrArcID         弧段ID数组[in]
	//!	\param dTotalCost       总共花费[in]
	//!	\return	成功：TRUE，任何异常和错误将返回FALSE;
	//!  \remarks
	UGbool GetRouteInfo(UGResultInfo &ResInfo,UGint nStartNodeID, UGArray<UGuint>& arrArcID, UGdouble dTotalCost);

	//!	\brief	得到路由信息函数 
	//!	\param ResInfo          结果结构[in]
	//!	\param nStartNodeID     起始点ID[in]
	//!	\param arrArcID         弧段ID数组[in]
	//!	\param arrFacilityDist  路由花费数组[in]
	//!	\return	成功：TRUE，任何异常和错误将返回FALSE;
	//!  \remarks
	UGbool GetRouteInfo(UGResultInfo &nResultInfo,UGint nStartNodeID, UGArray<UGuint>& arrArcIDs, UGArray<UGdouble>& arrFacilityDist);
	
	//!	\brief	得到经过网络节点信息函数 
	//!	\param ResInfo          结果结构[in]
	//!	\param arrNodeID        节点ID数组[in]
	//!	\param arrViaCount      经过个数数组[in]
	//!	\return	成功：TRUE，任何异常和错误将返回FALSE;
	//!  \remarks
	UGbool GetViaNodeInfo(UGResultInfo &ResInfo,UGArray<UGuint>& arrNodeID, UGArray<UGint>& arrViaCount);

	//!	\brief	得到经过网络节点信息函数 
	//!	\param ResInfo          结果结构[in]
	//!	\param arrNodeID        节点ID数组[in]
	//!	\param nRouteCount      经过个数[in]
	//!	\return	成功：TRUE，任何异常和错误将返回FALSE;
	//! \remarks
	UGbool GetViaNodeInfo(UGResultInfo &ResInfo,UGArray<UGuint>& arrNodeID, UGint nRouteCount);
	
	//!	\brief	得到服务区经过网络节点信息函数 
	//!	\param ResInfo          结果结构[in]
	//!	\param pbtOnPath        经过路径标识数组[in]
	//!	\return	成功：TRUE，任何异常和错误将返回FALSE;
	//! \remarks
	UGbool GetServiceViaNodeInfo( UGResultInfo& ResultInfo,UGuchar* pbtOnPath);

	//!	\brief	得到经过网络弧段信息函数 
	//!	\param ResInfo          结果结构[in]
	//!	\param ServiceRoute     弧段路由[in]
	//!	\return	成功：TRUE，任何异常和错误将返回FALSE;
	//! \remarks
	UGbool GetServiceViaEdgeInfo( UGResultInfo& ResultInfo,UGRoute& ServiceRoute);

	//!	\brief	得到经过网络弧段信息函数 
	//!	\param ResInfo          结果结构[in]
	//!	\param arrArcID         弧段ID数组[in]
	//!	\param arrViaCount      经过弧段路由总个数[in]
	//!	\return	成功：TRUE，任何异常和错误将返回FALSE;
	//! \remarks
	UGbool GetViaEdgeInfo(UGResultInfo &ResInfo,UGArray<UGuint>& arrArcID, UGint arrViaCount);

	//!	\brief	得到经过网络弧段信息函数 
	//!	\param ResInfo          结果结构[in]
	//!	\param arrArcID         弧段ID数组[in]
	//!	\param arrViaCount      经过弧段路由个数数组[in]
	//!	\return	成功：TRUE，任何异常和错误将返回FALSE;
	//! \remarks
	UGbool GetViaEdgeInfo(UGResultInfo &ResInfo,UGArray<UGuint>& arrArcID, UGArray<UGint>& arrViaCount);

	//!	\brief	得到经过站点信息函数 
	//!	\param ResInfo      结果结构[in]
	//!	\param arrNodeID    节点ID数组[in]
	//!	\param arrCost      花费数组[in]
	//!	\return	成功：TRUE，任何异常和错误将返回FALSE;
	//! \remarks
	UGbool GetStopsInfo(UGResultInfo &ResInfo,UGArray<UGuint>& arrNodeID, UGArray<UGdouble>& arrCost);

	//!	\brief	得到经过站点信息函数 
	//!	\param ResInfo      结果结构[in]
	//!	\param arrNodeID    节点索引数组[in]
	//!	\return	成功：TRUE，任何异常和错误将返回FALSE;
	//! \remarks
	UGbool GetStopsInfo(UGResultInfo &ResInfo,UGArray<UGuint>& arrNodeID);


	//!	\brief	得到服务面信息函数 
	//!	\param ResInfo      结果结构[in]
	//!	\param arrRoute     路由数组[in]
	//!	\return	成功：TRUE，任何异常和错误将返回FALSE;
	//! \remarks
	UGbool GetRegionInfo(UGResultInfo &ResInfo,UGArray<UGGeoLineM>& arrRoute);

	//!	\brief	得到花费信息函数 
	//!	\param ResInfo      结果结构[in]
	//!	\param arrCost      花费数组[in]
	//!	\return	成功：TRUE，任何异常和错误将返回FALSE;
	//! \remarks
	UGbool GetCostInfo(UGResultInfo &ResInfo,UGArray<UGdouble>& arrCost);

	//!	\brief	得到花费信息函数 
	//!	\param ResInfo      结果结构[in]
	//!	\param arrNodeID    节点数组[in]
	//!	\param arrCenterID  中心点数组[in]
	//!	\param arrCost      花费数组[in]
	//!	\return	成功：TRUE，任何异常和错误将返回FALSE;
	//! \remarks
	UGbool GetLocationNodesInfo(UGResultInfo &ResInfo,UGArray<UGint>& arrNodeID,UGArray<UGint>& arrCenterID, UGArray<UGdouble>& arrCost);

	//!	\brief	得到花费信息函数 
	//!	\param ResInfo         结果结构[in]
	//!	\param arrCenterIndex  节点数组[in]
	//!	\param arrCenters      中心点数组[in]
	//!	\param arrdCenterCost  中心点花费数组[in]
	//!	\param arrDemand       需求花费数组[in]
	//!	\param arrdResource    资源数组[in]
	//!	\return	成功：TRUE，任何异常和错误将返回FALSE;
	//! \remarks
	UGbool GetLocationCentersInfo(UGResultInfo &ResInfo,const UGArray<UGuint> &arrCenterIndex,const UGArray<UGCenterNode>&arrCenters,
		const UGArray<UGdouble>& arrdCenterCost,UGArray< UGint>& arrDemand,const UGArray<UGdouble>& arrdResource);

	//!	\brief	找节点索引函数
	//! \param  nNodeID 弧段ID[in]
	//!	\return 如果成功找到，则返回索引，否则返回－1
	UGint FindIndex(UGint nNodeID);

	//!	\brief	找弧段索引函数
	//! \param  nArcID 弧段ID[in]
	//!	\return 如果成功找到，则返回索引，否则返回－1
	UGint FindArcIndex(UGint nArcID);

	//!	\brief	找弧段索引函数
	//! \param  nID 弧段ID[in]
	//!	\param pArcInfo 弧段指针[in]
	//!	\param nCount 弧段个数[in]
	//!	\return 如果成功找到，则返回索引，否则返回－1
	UGint FindIndex(UGint nID,ArcInfo* pArcInfo,UGint nCount);
	
	//!	\brief	找UGint索引函数
	//! \param  nID  ID[in]
	//!	\param arrIDs IDs数组[in]
	//!	\param nCount 个数[in]
	//!	\return 如果成功找到，则返回索引，否则返回－1
	UGint FindIndex(UGint nID,UGint* arrIDs,UGint nCount);

	//!	\brief	找NetIndex索引函数
	//! \param  nID  ID[in]
	//!	\param arrNetIndex NetIndex指针[in]
	//!	\param nCount 个数[in]
	//!	\return 如果成功找到，则返回索引，否则返回－1
	UGint FindIndex(UGint nID,NetIndex* arrNetIndex,UGint nCount);

	//!	\brief	找障碍索引函数
	//! \param  nID  ID[in]
	//!	\param arrIDs IDs数组[in]
	//!	\param nCount 排序的个数[in]
	//!	\return 如果成功找到，则返回索引，否则返回－1
	UGbool FindBarrierIndex(UGint nID,UGint* arrIDs,UGint nCount);

	//!	\brief	返回nLineID的索引
	//! \param  nLineID  线 ID[in]
	//!	\param RelRoutes 公交路由结构[in]
	//!	\return 如果成功找到，则返回索引，否则返回－1
	UGint FindIndex(UGint nLineID, UGRelRoutes& RelRoutes);

	//!	\brief	找站点是的索引
	//! \param  nStopID  站点ID[in]
	//!	\param UGRelStops 站点结构[in]
	//!	\return 如果成功找到，则返回索引，否则返回－1
	UGint FindIndex(UGint nStopID, UGRelStops& RelStops);

	//!	\brief	点在点串的索引函数
	//! \param  pntNode  坐标点[in]
	//!	\param arrNetIndex 点信息数组[in]
	//!	\param nCount 排序的个数[in]
	//!	\return 如果成功找到，则返回索引，否则返回－1
	UGint FindIndex(UGPoint2D& pntNode, PointIndex* arrNetIndex, UGint nCount);
	
	//!	\brief	找节点的From弧段和To弧段
	//! \param  pCostValues  阻力花费指针[in]
	//!	\param nNodeID       节点ID[in]
	//!	\param nFEdgeID      起始弧段ID[out]
	//!	\param nTEdgeID      终点弧段ID[out]
	//!	\return 如果成功找到，则返回索引，否则返回－1
	UGdouble GetNodeImp(UGCostValues  *pCostValues,UGint nNodeID, UGint nFEdgeID, UGint nTEdgeID);

	//!	\brief  找弧段的起点和终点ID
	//! \param  pCostValues  阻力花费指针[in]
	//!	\param nEdgeID       弧段ID[in]
	//!	\param nFNodeID      弧段起点ID[out]
	//!	\param nTNodeID      弧段终点ID[out]
	//!	\return 如果成功找到，则返回索引，否则返回－1
	UGdouble GetEdgeImp(UGCostValues  *pCostValues,UGint nEdgeID, UGint nFNodeID, UGint nTNodeID);

	//!	\brief	得到路由函数
	//! \param  arrRoute  路由数组ID[in]
	//!	\param resRoute 单个路由[in]
	//!	\param nArrReAllotRoutID 实际分配ID数组[in]
	//!	\return 如果成功找到，则返回TRUE，否则返回FALSE
	UGbool GetGeoLineM(UGArray<UGGeoLineM>& arrRoute,UGRoute &resRoute,const UGArray< UGint > & nArrReAllotRoutID );
	
	//{{多线程支持
	//!	\brief	设置阻力字段函数
	//! \param  arrCostFields  阻力字段结构[in]
	//!	\return 
	void SetCostFields(const UGArray<UGCostFields> &arrCostFields);

	//!	\brief	得到阻力字段别名函数
	//! \param  arrCostName  别名数组[in]
	//!	\return 如果成功找到，则返回TRUE，否则返回FALSE.
	UGbool GetCostName(UGStrArray &arrCostName);

	//!	\brief	得到阻力字段别名函数
	//! \param  arrCostName  别名数组[in]
	//!	\return 如果成功找到，则返回TRUE，否则返回FALSE.
	UGString GetFirstCostName();

	//!	\brief	设置转向表
	//! \param  arrTurnCostFields  转向表结构[in]
	//!	\return 
	void SetTurnCostFields(const UGArray<UGString> &arrTurnCostFields);

	//!	\brief	得到转向字段别名函数
	//! \param  arrTurnCostName  转向别名数组[in]
	//!	\return 如果成功找到，则返回TRUE，否则返回FALSE.
	UGbool GetTurnCostName(UGStrArray &arrTurnCostName);
	//}}多线程支持

	//!	\brief	NetIndex快速排序函数
	//! \param  pData  NetIndex指针[in]
	//! \param  nCount 排序大小[in]
	//!	\return 
	void q_Sort(NetIndex *pData, UGint nCount);

public:
	//成员变量
	UGDatasetVector *m_pDtNetwork;							//分析用的网络数据集
	UGDatasetVector *m_pDtTRN;								//分析用的转向属性表
	UGDatasetVector *m_pDtCenter;							//资源分配中的中心点文件
	UGDatasetVector *m_pDtDMDNode;							//资源分配中的需求节点文件
	UGDatasetVector *m_pDtDMDArc;							//资源分配中的需求弧段文件
	
	UGArray<UGPathNode*> m_AdjMatrix;					//节点邻接表
	UGArray<UGTurnNode*> m_TurnTable;						//节点转向表

	UGArray<UGint> m_NodeIDs;							//节点ID表
	UGdouble m_dNodeInterval;							//分析点选择容限

	//存储信息
	UGArray<UGint> m_ArcIDs;                              //弧段信息表

	UGArray<UGdouble>m_arrViaDist;						//相临路由点行驶距离或时间
	UGArray<short>m_arrViaDirection;					//到达路由点转弯提示
	UGArray<UGuint> m_arrArcID;									//路由弧段表
	UGArray<UGuint> m_arrNodeID;								//路由节点表
	
	UGArray<UGchar> m_arrbtDemandAllocated;						//需求节点分配表
	UGArray<UGchar> m_arrbtCenterAllocated;						//中心节点分配表
	
	UGArray<UGdouble> m_arrNodeDemand;							//节点需求量表
	UGArray<UGPathNode*> m_arrArcDemand;						//弧段需求量表

	//add by wangsh 11.19 弧段分配标记数组
	UGArray<UGbyte> m_arrArcAllocated;				//弧段分配标记数组
	UGArray<double> m_arrArcResources;		        //弧段分配资源量值
	
	UGArray<UGCenterNode> m_arrCenters;							//中心节点表
	UGArray<UGuint> m_arrDemandNodeIndex;						//需求节点Index表
	UGArray<UGuint> m_arrDemandArcID;							//需求弧段ID表
	
	UGArray<UGint>m_arr_Lane_Positive;					//单行(正向通行)
	UGArray<UGint>m_arr_Lane_Negative;					//单行(逆向通行)
	UGArray<UGint>m_arr_NO_Entry;						//禁行
	UGArray<UGint>m_arr_Both_Direction;					//双向通行
	
	UGArray<BarrierNode> m_arrBarrierNode;		//节点障碍表
	UGArray<BarrierArc> m_arrBarrierArc;			//弧段障碍表
	
	//UGArray<UGuint> m_arrArcIDAllocated;								//资源分配结果网络节点
	//UGArray<UGuint> m_arrNodeIDAllocated;								//资源分配结果网络弧段

	//{{多线程支持
	UGArray<UGdouble*> m_arrFTCost;		//弧段正向阻力
	UGArray<UGdouble*> m_arrTFCost;		//弧段逆向阻力
	UGint m_nRefCount;
	UGArray<UGCostFields> m_arrCostFields;

	UGArray<UGdouble*> m_arrTurnCost;	//转向表花费

	UGArray<TurnCost*> m_TurnCost;
	//UGArray<UGTurnCost*> m_TurnCost;						//节点转向花费表
	UGArray<UGString> m_arrTurnCostFields;
	//}}多线程支持
	
	//{{BusNetwork
	UGArray<UGString> m_arrBusCostFields;
	//}}BusNetwork
	
	UGString	 m_strFTWeight;			//弧段的向前阻值字段
	UGString	 m_strTFWeight;			//弧段的向后阻值字段
	
	UGString	 m_strNodeID;			//节点ID字段
	UGString	 m_strArcID;			//弧段ID字段
	UGString	 m_strFNodeID;			//起始节点字段
	UGString	 m_strTNodeID;			//终止节点字段
	
	UGString	 m_strRoadRule;			//道路规则字段
	
	UGString	 m_strTRNNodeID;		//转向表中节点ID字段
	UGString	 m_strTRNWeight;		//转向表中Cost字段
	UGString     m_strTRNArcFromID;		//转向表中From弧段ID字段
	UGString	 m_strTRNArcToID;		//转向表中To弧段ID字段
	
	//UGString	 m_strNodeFilter;		//节点过滤字段
	UGString	 m_strArcFilter;			//弧段过滤字段
	
	UGString	 m_strNodeDemand;			//节点需求量字段
	UGString	 m_strArcDemand;			//弧段需求量字段
	
	UGString	 m_strCenterID;				//中心ID字段
	
	UGString	 m_strCenterCandidate;		//候选中心字段
	UGString	 m_strCenterResource;		//中心资源量字段
	UGString	 m_strCenterMaxImpedance;	//中心最大阻值字段
	UGPathGuideName m_strPathFeildNames;
	//====================Network Flow===============================
	//UGString	 m_strFlowDirection;	//流向字段(设施网络)Against,With;
	//UGString	 m_strRole;				//节点脚色Source,Sink;
	//UGString	 m_strEnabled;			//节点或弧段是否禁流；yes,no
	//====================Network Flow===============================
	UGbool m_bAdjModified;
	UGbool m_bTRNModified;
	UGbool m_bUseTRN;
	UGbool m_bCreateReverse;
	UGbool m_bUseRoadRule;
	
    //Trace Source
	UGArray < UGPathNode*> m_TraceAdjMatrix;
	
	UGArray <ArcInfo> m_ArcInfo;					//弧段信息表
	UGuchar* m_pbtOnPath;
	UGdouble* m_pdNodeCost;
	UGint* m_pnPrevArcID;
	UGint* m_pnPrevNodeIndex;
	UGint* m_pnHeapIndex;
	UGint  m_nLeft;
	
	UGString m_strDirection;
	UGString m_strNodeType;
	
	ResultInfo m_ResultInfo;
	UGint m_nOptions;
	
	UGDataSource  *m_pOutputDataSource;					//输出数据源
	
	//UGArray<UGGeoLineM> m_arrRoute;				//弧段障碍表
	//多点服务区分析
	
	// 记录原来结点邻接矩阵的大小
	UGint m_nAdjMatrixSize ;
	
	// 记录原来最大的结点ID
	UGint m_nNodeMaxID	  ;
	
	// 记录原来弧段的弧段个数
	UGint m_nArcSzie 	  ;
	
	// 记录原来弧段的最大ID
	UGint m_nArcMaxID ;
	
	// 临时存储被虚拟结点替代的弧段信息
	UGArray <ArcInfo> m_TempArcInfo ;
	
	// 同上配合 记录该弧段的正向cost
	UGArray <UGdouble> m_TempArcCost ;
	
	// 同上配合 记录该弧段的逆向cost
	UGArray <UGdouble> m_TempArcCostBak ;
	
	// 存储虚拟结点的原始弧段
	UGArray <ArcInfo> m_VirtualArcArcInfo ;
	
	// 存储虚拟结点的开始结点在原始弧段中的位置
	UGArray <UGdouble> m_VirtualFNodePos ;
	
	// 保存多点服务区各个中心点的洞的中心点ID
	// 采用矩阵来保存 m_pnRelation[ nCount * a + b] = 1 表示 b 是 a 的洞
	UGint * m_pnRelation ;

	UGint   m_nSiteCount ;	// 中心点个数
	
	//{{行使导引
	//UGPathGuides m_PathGuides;
	//}}行使导引

	// 	//分幅处理开发
	// 	// 传入的不同图幅 
	// 	UGArray <UGDatasetVector *>  m_arrDMDtNetWorks ;	
	// 	// 所有图幅的节点
	// 	UGArray <UGuint>  m_nDMNodeIDs ;
	// 	
	// 	// 所有图幅的邻接矩阵
	// 	UGArray <UGPathNode*>  m_DMTraceAdjMatrix ;
	// 	// 图幅的节点分配情况 m_nDivMapsNodeIndexFrom[i] 表示第i个图幅节点在m_nDivMapsNodeIDs 中的开始位置
	// 	UGArray <UGuint>  m_nDMFromIndex ;
	// 	// 图幅相同节点的index(index是在m_nDivMapsNodeIDs中的index)
	// 	UGArray<UGint >   m_nDMSameNode ;
	// 
	// 	// 是否重建邻接矩阵
	// 	UGbool m_bReBuildDMatrix ;
	
	/*
	//关键点分析相关结构：
	UGArray<CriticalOne50*> m_CriticalOneAdjMatrix;
	
	  UGArray<CriticalNode50*> m_CriticalNodeAdjMatrix;
	  
		//UGArray<UGint> m_arrOrder;
		UGArray<CriticalIndex> m_arrOrder;
	*/
};

}

#endif 
