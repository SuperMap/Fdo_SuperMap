/* 
	\file UGTopoProcess.h
	\brief 拓扑处理
	\author ugc team
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>更新说明：</b>
	<em>1、第一条说明。</em>
	<em>2、第二条说明。</em>
*/

#ifndef UGTOPOPROCESS_H
#define UGTOPOPROCESS_H

#include "Engine/UGTopoDataset.h"

namespace UGC {

class OPERATION_API UGTopoProcess  
{
public:
	UGTopoProcess();
	virtual ~UGTopoProcess();
	
	//! \brief  拓扑生效处理
	/**
	拓扑生效处理就是使拓扑数据集设置的拓扑规则生效，并输出错误到相应的错误数据集中
	 \param		pTopology		拓扑数据集指针数组
	 \return	拓扑数据集合法返回TRUE，否则返回FALSE
	 \remarks	
	*/
	static UGbool ValidateTopology(UGDatasetTopo* pTopology);
	
	//! \brief  拓扑预处理
	/**
	拓扑预处理要处理三件事：1、结点捕捉；2、插入交点；3、复杂对象岛、洞多边形坐标顺序按顺、逆时针排序
	 \param		parrDatasets		数据集指针数组
	 \param		arrPricision		数据集精度数组
	 \return	检查出错误返回TRUE，无错误返回FALSE
	 \remarks	数据集精度值越大表示数据精度越高，数据质量越好； 结点捕捉遵循低精度数据往高精度数据靠拢；
	*/
	static UGbool TopoIniProcess(UGArray<UGTopoDTPricision> &arrTopoDTPricision, UGdouble dInterval=EP);

private:
	static UGbool SaveError(UGRecordset* pRecordset, UGRecordset* pRSCheck, UGArray<UGint> &arrIDs, 
							UGArray<UGint> &arrCheckIDs, UGint nTopoRule, UGDatasetVector* pDTError);
	
	static UGbool SaveError(UGRecordset* pRecordset, UGArray<UGint> &arrIDs, UGArray<UGPoint2D> &arrpnts,
							UGint nTopoRule, UGDatasetVector* pDTError);
	
	static UGbool SaveError(UGRecordset* pRecordset, UGArray<UGint> &arrIDs, UGint nTopoRule, 
							UGDatasetVector* pDTError);
	
	static UGbool SaveError(UGRecordset* pRecordset, UGArray<UGGeoRegion*> &arrpGeoRegion, UGint nTopoRule, 
							UGDatasetVector* pDTError);
	
	static UGbool SaveError(UGRecordset* pRecordset, UGArray<UGGeoLine*> &arrpGeoLine, UGint nTopoRule, 
							UGDatasetVector* pDTError);
};

}

#endif // !defined(UGTOPOCHECK_H)
