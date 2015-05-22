//////////////////////////////////////////////////////////////////////////
//                    _   _   ____   ____                    
//   Project         | | | | / ___) / ___)                   
//                   | | | || | __ | |                       
//                   | |_| || |_\ || \___                    
//                    \____/ \____| \ ___)     2.0           
//                                                           
//!  \file UGWCSParser.h
//!  \brief UGWCSParser 的接口定义。
//!  \details 文件详细信息。
//!  \author duxiaomin。
//!  \attention 
//!   Copyright (c) 1996-2007 SuperMap GIS Technologies,Inc.  <br> 
//!   All Rights Reserved.
//!  \version 2.0
//////////////////////////////////////////////////////////////////////////

#ifndef UGWCSPARSER_H
#define UGWCSPARSER_H

#include "Base/ugexports.h"
#include "WebEngine/UGWebServiceParser.h"

namespace UGC
{

//! \brief WCS数据源的解析类。
//! \remarks WCS数据源的解析类。
class WEBENGINE_API UGWCSParser : public UGWebServiceParser  
{
public:
	UGWCSParser();
	UGWCSParser(const UGString& strFilePath);
	virtual ~UGWCSParser();
public:
	//! \brief 解析WCS网络数据服务器的能力。
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
		const UGWebLayersInfo& Layers,
		const UGString& strMap);
};

}
#endif // !defined(UGWCSPARSER_H)
