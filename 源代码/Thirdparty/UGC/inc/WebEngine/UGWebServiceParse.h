//////////////////////////////////////////////////////////////////////////
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


namespace UGC{
	
	class UGWebDataSource;
	class UGWebLayerInfos;
	
	class WEBENGINE_API UGWebServiceParse  
	{
	public:
		UGWebServiceParse();
		UGWebServiceParse(const UGString& strParseFilePath);
		
		virtual ~UGWebServiceParse();
		
	public:
		
		//! \brief 解析图层容量。
		//! \param Layers 图层信息数组[out]。
		//! \param strVersion 网络数据源版本[out]。
		//! \param strFormats 服务器支持的图片格式列表[out]。
		//! \param strMap 没有用[out]。
		//! \param strSRS 空间参考系[out]。
		//! \return 是否解析成功，成功返回TRUE,失败返回FALSE。
		virtual UGbool ParseCapabilities(UGWebLayerInfos& Layers,
			UGString& strVersion,
			UGArray<UGString>& strFormats,
			UGString& strMap,
			UGArray<UGString>& arySRS) = 0;
		
		//! \brief 根据图层信息创建图层。
		//! \param Datasets 创建的图层集合[out]。
		//! \param Lys 解析得到的图层信息[in]。
		//! \param strMap 多个图层合并为一个图层时的图层名[in]。
		//! \return 是否创建成功，成功返回TRUE,失败返回FALSE。
		virtual UGbool CreateLayer(UGDatasets& Datasets,
			const UGWebLayerInfos& Lys,
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
		
		//! \brief 解析连接字符串。
		//! \param strConn 连接字符串[in]。
		//! \param &strHttpServer [out]。
		//! \param &strServerPage [out]。
		//! \param &strDataBase [out]。
		//! \param &strServerName [out]。
		//! \param &strVersion [out]。
		//! \param &nPort [out]。
		//! \return 是否解析成功，成功返回TRUE,失败返回FALSE。
		UGbool ParseServerInfo(UGString strConn,
			UGString &strHttpServer,
			UGString &strServerPage,
			UGString &strDataBase,
			UGString &strServerName,
			UGString &strVersion,
			UGlong &nPort);
		
		
	protected:
	//! \brief 要解析文件的路径。
		UGString m_strParseFile;

	//! \brief 数据源指针。
		UGWebDataSource* m_pDs;
		
	};
	
}
#endif // !defined(UGWEBSERVICEPARSE_H)
