//////////////////////////////////////////////////////////////////////////
//                    _   _   ____   ____                    
//   Project         | | | | / ___) / ___)                   
//                   | | | || | __ | |                       
//                   | |_| || |_\ || \___                    
//                    \____/ \____| \ ___)     2.0           
//                                                           
//!  \file UGWCSRaster.h
//!  \brief UGWCSRaster 的接口定义。
//!  \details 文件详细信息。
//!  \author duxiaomin。
//!  \attention 
//!   Copyright (c) 1996-2007 SuperMap GIS Technologies,Inc.  <br>  
//!   All Rights Reserved.
//!  \version 2.0
//////////////////////////////////////////////////////////////////////////

#ifndef UGWCSRASTER_H
#define UGWCSRASTER_H

#include "Base/ugexports.h"
#include "Engine/UGWebDatasetRaster.h"
#include "WebEngine/UGWebLayerInfo.h"

namespace UGC
{

//! \brief Coverage的范围值。
//! \remarks 通常用来表示波段值。
struct AxisDescription
{
	//! \brief 坐标轴名。
	UGString m_strAxisName;
	
	//! \brief 坐标轴最小值。
	UGint m_nMin;
	
	//! \brief 坐标轴最大值。
	UGint m_nMax;

	//! \brief 无效值
	UGint m_nNullVal;
};

//! \brief Coverage的范围值数组。
typedef UGArray<AxisDescription> AxisDescriptions;

//! \brief WCS数据集类。
//! \remarks WCS的数据集。
class WEBENGINE_API UGWCSRaster : public UGWebDatasetRaster  
{
public:
	UGWCSRaster();

	UGWCSRaster(UGDatasetRasterInfo& rInfo);

	virtual ~UGWCSRaster();

public:
	//! \brief 得到基于内存的栅格数据集。
	//! \param strGetCoverageURL 向Web数据源请求的URL[in]。
	//! \return 栅格数据集指针。
	//! \remarks 其它重载函数都由此函数包装。
	virtual UGDatasetRaster* GetDatasetRaster(UGString strGetCoverageURL);

	//! \brief 得到基于内存的栅格数据集,用于放大缩小平移操作的请求。
	//! \param rcQueryBound 请求影像的四至范围[in]。
	//! \param dWidth 请求影像的宽度,单位像素[in]。
	//! \param dHeight 请求影像的高度,单位像素[in]。
	//! \param strFormat 请求影像的格式[in]。
	//! \return 栅格数据集指针。
	virtual UGDatasetRaster* GetDatasetRaster(UGRect2D rcQueryBound,
		UGint dWidth,UGint dHeight,UGString strFormat ="png");

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
	//! \brief 设置此数据集对应的FeatureTypeInfo的信息。
	//! \param layerSrc 网络数据源图层信息[in]。
	//! \return 是否设置成功,成功返回TRUE,否则返回FALSE。
	UGbool SetCoverageLayer(const UGWebLayerInfo& layerSrc);	

	//! \brief 得到数据集对应的FeatureTypeInfo的信息。
	//! \param layerDest 网络数据源图层信息[in]。
	//! \return 是否成功得到,成功返回TRUE,否则返回FALSE。
	UGbool GetCoverageLayer(UGWebLayerInfo& layerDest) const;
	
	//! \brief 解析得到当前Coverage得到图层的祥细信息。
	//! \param strDescribeXMLPath DescribeCoverage请求的XML文件所在的路径[in]。
	//! \return 是否成功解析,成功返回TRUE,失败返回FALSE。。
	UGbool ParseCoverage(UGString strDescribeXMLPath = "");	
private:
	//! \brief 通过GetCoverage请求的XML文件生成内存数据源。
	//! \param strGetCoverageXMLPath GetCoverage请求的XML文件地址[in]。
	//! \param strImageFormat 请求的影像格式[in]。
	//! \return 内存数据源指针。
	UGDataSource* CreatDataSource(const UGString& strGetCoverageXMLPath, 
		UGRect2D rcGeoRef = UGRect2D(0,0,0,0) ,UGString strImageFormat ="");

	UGDatasetRaster* GetDatasetRaster(UGString strGetCoverageURL,
		 UGRect2D rcGeoref);
	//! \brief 得到图层请求范围的URL查询选项。
	//! \return BBOX URL查询选项。
	//! \remarks 格式为 BBOX=-165.270004272461,-54.7538909912109,177.130187988281,83.1083221435547&amp。
	UGString GetBBoxURLValue(UGRect2D rcSrc) const;
public:
	//! \brief WFS数据源的图层信息。
	//! \remarks 备注信息。
	UGWebLayerInfo m_coverageLayer;
	
	//! \brief WCS图层支持的坐标。
	AxisDescriptions m_aryAxis;

	//! \brief WCS图层支持的参考系四至信息数组。
	UGCRSBounds m_arySuportCRSBound;

	//! \brief spatialDomain的参考系四至信息
	UGCRSBound m_spatialDomainEVlp;

	//! \brief 影像原宽度。
	UGint m_ImageWith;

	//! \brief 影像原高度。
	UGint m_ImageHight;

	//! \brief WCS图层支持的空间操作。
	UGStrings m_aryInterpolations;

	UGString strOLResCapabilities;

	UGString strOLResDescribeCoverage;

	UGString strOLResGetCoverage;
};

}
#endif // !defined(UGWCSRASTER_H)
