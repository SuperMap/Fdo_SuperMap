//////////////////////////////////////////////////////////////////////////
//!  \file UGWFSParse.h
//!  \brief UGWFSParse 的接口定义。
//!  \details 文件详细信息。
//!  \author duxiaomin。
//!  \attention 
//!   Copyright (c) 1996-2007 SuperMap GIS Technologies,Inc.  <br>
//!   All Rights Reserved.
//!  \version 2.0
//////////////////////////////////////////////////////////////////////////

#ifndef UGWFSPARSE_H
#define UGWFSPARSE_H


#include "WebEngine/UGWebServiceParse.h"
#include "WebEngine/UGWebLayerInfo.h"
#include "WebEngine/UGWebDataSource.h"

namespace UGC{
	
	
	class WEBENGINE_API UGWFSParse : public UGWebServiceParse 
	{
	public:
		UGWFSParse();
		virtual ~UGWFSParse();
		
	public:
		//! \brief 解析图层容量。
		//! \param Layers 图层信息数组[out]。
		//! \param strVersion 网络数据源版本[out]。
		//! \param strFormats 服务器支持的图片格式[out]。
		//! \param strMap 没有用[out]。
		//! \param arySRS 空间参考系数组[out]。
		//! \return 是否解析成功，成功返回TRUE,失败返回FALSE。
		virtual UGbool ParseCapabilities(UGWebLayerInfos& Layers,
			UGString& strVersion,
			UGArray<UGString>& strFormats,
			UGString& strMap,
			UGArray<UGString>& arySRS);
		
		//! \brief 根据图层信息创建图层。
		//! \param Datasets 创建的图层[out]。
		//! \param Layers 解析得到的图层信息[in]。
		//! \param strMap 多个图层合并为一个图层时的图层名[in]。
		//! \return 是否创建成功，成功返回TRUE,失败返回FALSE。
		virtual UGbool CreateLayer(UGDatasets& Datasets,
			const UGWebLayerInfos& Layers,
			const UGString& strMap);
		
	};
	
}
#endif // !defined(UGWFSPARSE_H)
