//////////////////////////////////////////////////////////////////////////
//                    _   _   ____   ____                    
//   Project         | | | | / ___) / ___)                   
//                   | | | || | __ | |                       
//                   | |_| || |_\ || \___                    
//                    \____/ \____| \ ___)     2.0           
//                                                           
//!  \file UGWMSParser.h
//!  \brief UGWMSParser 的接口定义。
//!  \details 文件详细信息。
//!  \author duxiaomin。
//!  \attention 
//!   Copyright (c) 1996-2007 SuperMap GIS Technologies,Inc.  <br> 
//!   All Rights Reserved.
//!  \version 2.0
//////////////////////////////////////////////////////////////////////////

#ifndef UGWMSPARSER_H
#define UGWMSPARSER_H

#include "Base/ugexports.h"
#include "WebEngine/UGWebServiceParser.h"
#include "Base/UGDict.h"

namespace UGC{
	
//! \brief WMS数据源的解析类。
//! \remarks WMS数据源的解析类。
class WEBENGINE_API UGWMSParser : public UGWebServiceParser
{
public:
	UGWMSParser();
	UGWMSParser(const UGString& strFilePath);
	virtual ~UGWMSParser();
	
public:
	//! \brief 解析WMS网络数据服务器的能力。
	//! \param Layers 图层信息数组[out]。
	//! \param strVersion 网络数据源版本[out]。
	//! \param strFormats 服务器支持的图片格式[out]。
	//! \param strMap Title名称[out]。
	//! \param aryCRS 坐标参考系数组[out]。
	//! \return 是否解析成功，成功返回TRUE,失败返回FALSE。
	virtual UGbool ParseCapabilities(UGWebLayersInfo& Layers,
		UGString& strVersion,
		UGArray<UGString>& strFormats,
		UGString& strMap,
		UGArray<UGString>& aryCRS);
	
	//! \brief 根据图层信息创建图层。
	//! \param Datasets 创建的图层[out]。
	//! \param Lys 解析得到的图层信息[in]。
	//! \param strMap 多个图层合并为一个图层时的图层名[out]。
	//! \return 是否创建成功，成功返回TRUE,失败返回FALSE。
	virtual UGbool CreateLayer(UGDatasets& Datasets,
		const UGWebLayersInfo& Lys,
		const UGString& strMap);

	UGbool ParseOnlineResource(UGString& strOLResCapabilities, 
		UGString& strOLResGetMap,
		UGString& strOLResGetFeatureInfo,
		UGString& strOLResDescribeLayer,
		UGString& strOLResGetLegendGraphic);

	// 定义一个WMS的关键字字典
	UGDict<UGString,UGint>  m_dictKeyWords;
private:
	UGbool LoadDict();

	UGString TrimKeyWord(const UGString& strURL);
};
	
}
#endif // !defined(UGWMSPARSER_H)
