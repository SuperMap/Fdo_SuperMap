//////////////////////////////////////////////////////////////////////////
//                    _   _   ____   ____                    
//   Project         | | | | / ___) / ___)                   
//                   | | | || | __ | |                       
//                   | |_| || |_\ || \___                    
//                    \____/ \____| \ ___)     2.0           
//                                                           
//!  \file UGWMSRaster.h
//!  \brief UGWMSRaster 的接口定义。
//!  \details 文件详细信息。
//!  \author duxiaomin。
//!  \attention 
//!   Copyright (c) 1996-2007 SuperMap GIS Technologies,Inc.  <br> 
//!   All Rights Reserved.
//!  \version 2.0
//////////////////////////////////////////////////////////////////////////

#ifndef UGWMSRASTER_H
#define UGWMSRASTER_H

#include "Base/ugexports.h"
#include "Base/UGString.h"
#include "Engine/UGDatasetRaster.h"
#include "Engine/UGWebDatasetRaster.h"
#include "WebEngine/UGWebLayerInfo.h"

namespace UGC{

//! \brief WMS数据集类。
//! \remarks WMS的数据集。
class WEBENGINE_API UGWMSRaster :public UGWebDatasetRaster  
{
public:
	UGWMSRaster();

	UGWMSRaster(UGDatasetRasterInfo& rInfo);

	virtual ~UGWMSRaster();

public:
	//! \brief 得到基于内存的栅格数据集。
	//! \param strURL 向Web数据源请求的URL[in]。
	//! \return 栅格数据集指针。
	//! \remarks 其它重载函数都由此函数包装。
	virtual UGDatasetRaster* GetDatasetRaster(UGString strURL);

	//! \brief 得到基于内存的栅格数据集,用于放大缩小平移操作的请求。
	//! \param rcBound 请求影像的四至范围[in]。
	//! \param dWidth 请求影像的宽度,单位像素[in]。
	//! \param dHeight 请求影像的高度,单位像素[in]。
	//! \param strFormat 请求影像的格式[in]。
	//! \return 栅格数据集指针。
	virtual UGDatasetRaster* GetDatasetRaster(UGRect2D rcBound,
		UGint dWidth,UGint dHeight,UGString strFormat ="image/png");
 	
	//! \brief 得到数据源的所有图层名数组。
	//! \param aryLayerNames 图层名数组[out]。
	//! \return 是否成功得到,成功返回TRUE,失败返回FALSE
	virtual UGbool GetAllLayerNames(UGArray<UGString>& aryLayerNames);

	//! \brief 得到数据源的所有图层标题数组。
	//! \param aryLayerTitles 图层标题数组[out]。
	//! \return 是否成功得到,成功返回TRUE,失败返回FALSE。
	virtual UGbool GetAllLayerTitles(UGArray<UGString>& aryLayerTitles);

	//! \brief 得到数据源的所有图层编号数组。
	//! \param aryLayerIndexes 图层编号数组[out]。
	//! \return 是否成功得到,成功返回TRUE,失败返回FALSE。
	virtual UGbool GetAllLayerIndexes(UGArray<UGint>& aryLayerIndexes);	
	
	//! \brief 得到所有可见图层名数组。
	//! \param aryLayerNames 可见图层名数组[in]。
	//! \return 是否成功得到,成功返回TRUE,失败返回FALSE。
	virtual UGbool GetVisibleLayerNames(UGArray<UGString>& aryLayerNames);

	//! \brief 得到所有可见图层标题数组。
	//! \param aryLayerTitles 可见图层图层标题数组[in]。
	//! \return 是否成功得到,成功返回TRUE,失败返回FALSE。
	virtual UGbool GetVisibleLayerTitles(UGArray<UGString>& aryLayerTitles);

	//! \brief 得到数据集所有可见的图层编号集合。
	//! \param aryLayerIndexes 可见图层编号数组[in]。
	//! \return 是否成功得到,成功返回TRUE,失败返回FALSE。
	virtual UGbool GetVisibleLayerIndexes(UGArray<UGint>& aryLayerIndexes);

	//! \brief 设置当前数据集的可见图层。
	//! \param aryLayerIndexes 源图层编号数组[in]。
	//! \return 是否设置成功,成功返回TRUE,否则返回FALSE。
	virtual UGbool SetVisibleLayers(const UGArray<UGint>& aryLayerIndexes);	

	//! \brief 设置当前数据集的可见图层。
	//! \param aryLayerNames 源图层信息数组[in]。
	//! \return 是否设置成功,成功返回TRUE,否则返回FALSE。
	virtual UGbool SetVisibleLayers(const UGArray<UGString>& aryLayerNames);	

public:

	//! \brief 设置当前数据集的所有图层。
	//! \param arySrc 源图层信息集合[in]。
	//! \return 是否设置成功,成功返回TRUE,否则返回FALSE。
	UGbool SetAllLayers(const UGWebLayersInfo& arySrc);
	
	//! \brief 得到当前数据集的所有图层。
	//! \param aryDest 目的图层信息集合[out]。
	//! \return 是否成功得到,成功返回TRUE,否则返回FALSE。
	UGbool GetAllLayers(UGWebLayersInfo& aryDest) const;	

	//! \brief 设置当前数据集的可见图层。
	//! \param arySrc 源图层信息集合[in]。
	//! \return 是否设置成功,成功返回TRUE,否则返回FALSE。
	UGbool SetVisibleLayers(const UGWebLayersInfo& arySrc);	

	//! \brief 得到当前数据集的可见图层。
	//! \param aryDest 目的图层信息集合[in]。
	//! \return 是否成功得到,成功返回TRUE,否则返回FALSE。
	UGbool GetVisibleLayers(UGWebLayersInfo& aryDest) const;	

private:
	//! \brief 得到图层信息的边界的联合。
	//! \param layersInfo 图层信息集合[in]。
	//! \return 边界矩形。
	//! \remarks 的有图层信息有多个边框，在些也都合并在最终返回结果里。
	UGRect2D GetLayersBoundUnion(const UGWebLayersInfo& layersInfo) const;

	//! \brief 得到可见图层的URL查询选项,格式为Layers = Layer1,Layer2,Layer3&amp;。
	//! \param layersSrc 图层信息集合[in]。
	//! \return Layers URL查询选项。
	//! \remarks 格式为LAYERS = Layer1,Layer2,Layer3&amp;。
	//! \attention 。
	UGString GetLayersURLValue(const UGWebLayersInfo& layersSrc) const;

	//! \brief 得到可见图层的URL查询选项,格式为Layers = Layer1,Layer2,Layer3&amp;。
	//! \param layersSrc 图层名集合[in]。
	//! \return Layers URL查询选项。
	//! \remarks 格式为LAYERS = Layer1,Layer2,Layer3&amp;。
	//! \attention 。
	UGString GetLayersURLValue(const UGArray<UGString>& layersSrc) const;

	//! \brief 得到图层请求范围的URL查询选项。
	//! \param rcSrc 矩形框对象[in]。
	//! \return BBOX URL查询选项。
	//! \remarks 格式为 BBOX=-165.270004272461,-54.7538909912109,177.130187988281,83.1083221435547&amp。
	//! \attention 。
	UGString GetBBoxURLValue(const UGRect2D& rcSrc) const;
	
protected:
	//! \brief 当前数据集的所有图层信息集合。
	//! \remarks 备注信息。
	UGWebLayersInfo m_aryAllLayers;

	//! \brief 当前数据集的可见图层信息集合。
	//! \remarks 备注信息。
	UGWebLayersInfo m_aryVisibleLayers;
public:
	UGString m_strOLResCapabilities;

	UGString m_strOLResGetMap;

	UGString m_strOLResGetFeatureInfo;

	UGString m_strOLResDescribeLayer;

	UGString m_strOLResGetLegendGraphic;
};

}
#endif // !defined(UGWMSRASTER_H)
