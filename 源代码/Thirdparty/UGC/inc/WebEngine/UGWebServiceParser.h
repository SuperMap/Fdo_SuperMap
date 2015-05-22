//////////////////////////////////////////////////////////////////////////
//                    _   _   ____   ____                    
//   Project         | | | | / ___) / ___)                   
//                   | | | || | __ | |                       
//                   | |_| || |_\ || \___                    
//                    \____/ \____| \ ___)     2.0           
//                                                           
//!  \file UGWebServiceParse.h
//!  \brief UGWebServiceParse 的接口定义。
//!  \details 文件详细信息。
//!  \author duxiaomin。
//!  \attention 
//!   Copyright (c) 1996-2007 SuperMap GIS Technologies,Inc.  <br> 
//!   All Rights Reserved.
//!  \version 2.0
//////////////////////////////////////////////////////////////////////////

#ifndef UGWEBSERVICEPARSE_H
#define UGWEBSERVICEPARSE_H

#include "Base/ugexports.h"
#include "Base/UGString.h"
#include "Engine/UGDataset.h"

#define DEFAULT_CRS_NAME	"EPSG:4326"
#define DEFAULT_SRS_NAME	"EPSG:4326"

namespace UGC{

class UGWebDataSource;
class UGWebLayersInfo;

//! \brief 网络数据源的解析基类。
class WEBENGINE_API UGWebServiceParser  
{
public:
	UGWebServiceParser();
	UGWebServiceParser(const UGString& strParseFilePath);
	
	virtual ~UGWebServiceParser();
	
public:
	
	//! \brief 解析网络数据服务器的能力。
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
		UGArray<UGString>& aryCRS) = 0;
	
	//! \brief 根据图层信息创建图层。
	//! \param Datasets 创建的图层集合[out]。
	//! \param Lys 解析得到的图层信息[in]。
	//! \param strMap 多个图层合并为一个图层时的图层名[in]。
	//! \return 是否创建成功，成功返回TRUE,失败返回FALSE。
	virtual UGbool CreateLayer(UGDatasets& Datasets,
		const UGWebLayersInfo& Lys,
		const UGString& strMap) = 0;
	
public:
	//! \brief 设置解析文件的路径。
	//! \param strParseFilePath 解析文件的路径[in]。
	void SetParseFilePath(const UGString& strParseFilePath);
	
	//! \brief 得到解析文件的路径。
	//! \return 解析文件的路径。。
	UGString GetParseFilePath();
	
	//! \brief 设置解析类作用的数据源。
	//! \param pDs 数据源指针[in]。
	//! \return 是否设置成功，成功返回TRUE,失败返回FALSE。
	virtual UGbool SetServerPtr(UGWebDataSource* pDs);
	
	
	//! \brief 通过连接URL解析服务器信息。
	//! \param strConn 连接URL字符串[in]。
	//! \param &strHost 主机名或IP地址[out]。
	//! \param &strPath 网络数据服务相对于Web服务器根的相对路径。[out]。
	//! \param &strService 网络数据服务类型[out]。
	//! \param &strMapName 网络数据源地图集名,非标准,SuperMap独有[out]。
	//! \param &strVersion 网络数据执行规范的版本号[out]。
	//! \param &nPort 端口号[out]。
	//! \return 是否解析成功，成功返回TRUE,失败返回FALSE。
	UGbool ParseServerInfo(UGString strConn,
		UGString &strHost,			
		UGString &strPath,			
		UGString &strService,		
		UGString &strMapName,		
		UGString &strVersion,
		UGushort &nPort);		
	
	
protected:
	//! \brief 要解析文件的路径。
	UGString m_strParseFile;
	
	//! \brief 数据源指针。
	UGWebDataSource* m_pDs;
	
};
	
}
#endif // !defined(UGWEBSERVICEPARSE_H)
