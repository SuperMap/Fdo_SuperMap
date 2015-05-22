/* 
	\file UGOverlayAnalyst.h
	\brief 叠加分析类，包括裁剪、求交、擦除、同一、合并、对称差、更新操作
	\author ugc team
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>更新说明：</b>
	<em>1、第一条说明。</em>
	<em>2、第二条说明。</em>
*/

#ifndef UGOVERLAYANALYST_H
#define UGOVERLAYANALYST_H

#include "Base/ugdefs.h"
#include "Base/UGString.h"
#include "Engine/UGDataset.h"
#include "Engine/UGRecordset.h"
#include "Topology/UGTopoOverlay.h"

namespace UGC {

class UGDataSource;
class UGDatasetVector;

class OPERATION_API UGOverlayAnalyst
{
public:
	UGOverlayAnalyst();
	virtual ~UGOverlayAnalyst();
	
	//! \brief 叠加分析类型
	enum UGOverlayMode
	{   //! \brief 裁剪
		UGClip		= 0,
		//! \brief 擦除	
		UGErase		= 1,
		//! \brief 同一
		UGIdentity	= 2,
		//! \brief 相交
		UGIntersect	= 3,
		//! \brief 对称差
		UGSymmetric	= 4,
		//! \brief 合并
		UGUnion		= 5,
		//! \brief 更新
		UGUpdate	= 6,
	};
	
	//! \brief		设置容限
	//! \param		dInterval	设置的容限
	//! \return		设置成功返回TRUE，无错误返回FALSE
	//! \remarks	如 dInterval<EP,则采用EP作为容限
	void SetInterval(UGdouble dInterval);
	
	//! \brief	获取已设置的容限
	//! \param	dInterval 设置的容限
	//! \return	返回容限值
	//! \remarks	
	UGdouble GetInterval();
	
	//! \brief	设置和获取源数据集的字段 
	//! \param	arrFieldSrc 源数据集(分析中的被叠加的数据集)需要保留的字段
	//! \param	arrFieldOp  操作数据集(分析中的叠加的数据集，即面数据集)需要保留的字段
	UGbool SetFields(UGStrArray& arrFieldSrc, UGStrArray& arrFieldOp);
	
	/*!	\brief	获取源数据集的字段 */
	//! \param	arrFieldSrc 源数据集(分析中的被叠加的数据集)需要保留的字段
	UGbool GetFieldSrc(UGStrArray& arrFieldSrc);
	
	/*!	\brief	设置操作数据集的字段 */
	//! \param	arrFieldOp  操作数据集(分析中的叠加的数据集，即面数据集)需要保留的字段
	UGbool GetFieldOp(UGStrArray& arrFieldOp);
	
	//! \brief 数据集之间叠加操作
	//! param		pSrcDataset		源数据集
	//! param		pDTRegion		操作面数据集
	//! param		pDestDataset	结果数据集
	//! param		nMode			叠加算子类型
	//! remarks		pDTRegion必须是面数据集
	UGbool Overlay(UGDatasetVector *pDataset, UGDatasetVector *pDTRegion, UGDatasetVector *pDestDataset,
		const UGOverlayMode nMode);
	
	//! \brief 记录集之间叠加操作
	//! param		pRecordset		源记录集
	//! param		pRSRegion		操作面记录集
	//! param		pDestDataset	结果数据集
	//! param		nMode			叠加算子类型
	//! remarks		pRSRegion必须是面记录集
	UGbool Overlay(UGRecordset *pRecordset, UGRecordset *pRSRegion, UGDatasetVector *pDestDataset, 
		const UGOverlayMode nMode);
	
	//! \brief 		裁剪数据集操作
	//! \param 		*pSrcDataset 源数据集
	//! \param 		*pClipRegion 操作面数据集
	//! \param 		*pDestDataset 结果数据集
	//! \remarks 	2.0版本只支持面裁剪线、面裁剪面；	
	UGbool ClipDatasets(UGDatasetVector *pSrcDataset, UGGeoRegion *pClipRegion, UGDatasetVector *pDestDataset);
	
private:

	//! \brief 		点数据集叠加分析
	UGbool OverlayPoints(UGRecordset *pRecordsetSrc, UGRecordset *pRecordsetTag, UGDatasetVector *pDatasetRes, 
						 UGStrArray& arrFieldSrc, UGStrArray& arrFieldTag, UGStrArray& arrFieldRes, 
						 UGOverlayMode nMode);
	
	//! \brief 		线数据集叠加分析
	UGbool OverlayLines(UGRecordset *pRecordsetSrc, UGRecordset *pRecordsetTag, UGDatasetVector *pDatasetRes, 
						 UGStrArray& arrFieldSrc, UGStrArray& arrFieldTag, UGStrArray& arrFieldRes, 
						 UGOverlayMode nMode);
	
	//! \brief 		面数据集叠加分析
	UGbool OverlayRegions(UGRecordset *pRecordsetSrc, UGRecordset *pRecordsetTag, UGDatasetVector *pDatasetRes, 
						 UGStrArray& arrFieldSrc, UGStrArray& arrFieldTag, UGStrArray& arrFieldRes, 
						 UGOverlayMode nMode);
	
	//! \brief 		记录集叠加分析
	UGbool Overlay(UGRecordset *pRecordsetSrc, UGRecordset *pRecordsetTag, UGDatasetVector *pDatasetRes, 
					UGStrArray& arrFieldSrc, UGStrArray& arrFieldTag, UGStrArray& arrFieldRes, 
					UGOverlayMode nMode);
	
	//! \brief 		判断传入参数是否有效
	UGbool IsValid(UGDatasetVector *pDatasetSrc, UGDatasetVector *pDatasetTag, UGDatasetVector *pDatasetRes, 
					UGOverlayMode nMode);
	
	//! \brief 		保存数据集叠加分析结果
	UGbool SaveLeftObjects(UGDatasetVector *pDatasetSrc, UGDatasetVector *pDatasetTag, UGDatasetVector *pDatasetRes, 
						UGStrArray& arrFieldSrc, UGStrArray& arrFieldTag, UGStrArray& arrFieldRes, 
						UGOverlayMode nMode);
	
	//! \brief 		保存记录集叠加分析结果
	UGbool SaveLeftObjects(UGRecordset *pRecordsetSrc, UGRecordset *pRecordsetTag, UGDatasetVector *pDatasetRes, 
						UGStrArray& arrFieldSrc, UGStrArray& arrFieldTag, UGStrArray& arrFieldRes, 
						UGOverlayMode nMode);
	
	//! \brief 		根据记录集创建目标字段
	UGbool CreateDestFeilds(UGRecordset* pRecordsetSrc, 
							UGRecordset* pRecordsetTag, 
							UGDatasetVector *pDatasetRes, 
							UGStrArray& arrFieldSrc, 
							UGStrArray& arrFieldTag, 
							UGStrArray& arrFieldRes, 
							const UGOverlayMode nMode);
	
	//! \brief 		根据数据集创建目标字段
	UGbool CreateDestFeilds(UGDatasetVector *pSrcDataset,
							UGDatasetVector *pDSRegion, 
							UGDatasetVector *pDestDataset,
							UGStrArray& arrFieldSrc, 
							UGStrArray& arrFieldTag, 
							UGStrArray& arrFieldRes, 
							const UGOverlayMode nMode);
	
	//! \brief 		调整字段名
	UGbool AdjustFieldNames(UGFieldInfos& fields);
private:

	//! \brief 		容限
	UGdouble m_dInterval;

	//! \brief 		Topo变量
	UGTopoOverlay m_TopoOverlay;

	//! \brief 		源数据集需要保存的字段
	UGStrArray m_arrFieldSrc;

	//! \brief 		目标数据集需要保存的字段
	UGStrArray m_arrFieldTag;
};

}

#endif // !defined(UGOVERLAYANALYST_H)
