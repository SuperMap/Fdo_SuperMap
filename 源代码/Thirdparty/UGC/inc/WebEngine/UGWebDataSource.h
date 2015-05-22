//////////////////////////////////////////////////////////////////////////
//                    _   _   ____   ____                    
//   Project         | | | | / ___) / ___)                   
//                   | | | || | __ | |                       
//                   | |_| || |_\ || \___                    
//                    \____/ \____| \ ___)     2.0           
//                                                           
//!  \file UGWMSDataSource.h
//!  \brief WMSEngine 的数据源的接口定义。
//!  \details 文件详细信息。
//!  \author duxiaomin。
//!  \attention 
//!   Copyright (c) 1996-2007 SuperMap GIS Technologies,Inc.  <br> 
//!   All Rights Reserved.
//!  \version 2.0
//////////////////////////////////////////////////////////////////////////

#ifndef UGWEBDATASOURCE_H
#define UGWEBDATASOURCE_H

#include "Base/ugexports.h"
#include "Engine/UGDataSource.h"
#include "WebEngine/UGWebLayerInfo.h"
#include "WebEngine/UGWebServiceParser.h"

namespace UGC 
{
class UGWebLayersInfo;
class UGWebServiceParse;

//! \brief 网络数据源的数据源类。
//! \remarks
class WEBENGINE_API UGWebDataSource : public UGDataSource  
{
	friend class UGWFSRecordset;
	friend class UGWMSRaster;
public:
	UGWebDataSource();
	
	UGWebDataSource(UGDsConnection dsConn);
	virtual ~UGWebDataSource();
	
	//! \brief 打开数据源,需要预先设置好连接信息。
	//! \return 返回成功或失败。
	virtual UGbool Open();
	
	//! \brief 创建数据源，需要设定好连接信息。
	//! \return 创建成功返回TRUE,失败返回False。
	virtual UGbool Create();
	
	//!  \brief 数据源是否和数据连接
	virtual UGbool IsConnected();
	
	//!  \brief 仅仅连接数据库,不刷新数据集等
	virtual UGbool Connect();
	
	//! \brief 关闭数据源。
	//! \return 返回成功或失败。
	virtual void Close();
	
	//! \brief 判断数据源是否打开。
	//! \return 数据源状态。
	virtual UGbool IsOpen();
	
	//! \brief 是否有执行某些操作的能力。
	//! \param nAbility 引擎支持的能力[in]。
	//! \return 是否支持，是返加TRUE 否则返回FALSE。
	virtual UGbool HasAbility(UGEngAbility nAbility) const ;
	
	//! \brief 是否支持特定的操作。
	//! \param nAction 引擎支的操作[in]。
	//! \return 是否支持，是返加TRUE 否则返回FALSE。
	virtual UGbool IsSupport(UGEngAction nAction) const ;
	
	//! \brief 获取最后更新时间。
	//! \return 最后更新时间。
	virtual UGTime GetDateLastUpdated() const ;
	
	//!  \brief 获取创建时间
	virtual UGTime GetDateCreated() const;
	
	//! \brief 得到引擎名称。
	//! \return 引擎名称。
	virtual UGString GetEngineName();
	
	//! \brief 保存数据信息。
	//! \return 是否保存成功，是返加TRUE 否则返回FALSE。。
	virtual UGbool SaveInfo();
	
	//! \brief 修改密码。
	//! \param strNewPassword [in]。
	//! \return 是否修改成功，是返加TRUE 否则返回FALSE。
	virtual UGbool ChangePassword(const UGString& strNewPassword);		
	
	//! \brief 开始事务。
	//! \return 是否操作成功，是返加TRUE 否则返回FALSE。
	virtual UGbool BeginTrans();
	
	//! \brief 提交事务。
	//! \return 是否操作成功，是返加TRUE 否则返回FALSE。
	virtual void Commit();
	
	//! \brief 撤消事务。
	//! \return 是否操作成功，是返加TRUE 否则返回FALSE。
	virtual void Rollback();
	
	//! \brief 创建失量数据集。
	//! \param vInfo 失量数据集信息[in]。
	//! \return 失量数据集。
	virtual UGDatasetVector* CreateDatasetVector(
		const UGDatasetVectorInfo& vInfo);
	
	//! \brief 创建拓扑数据集。
	//! \param strName 拓扑数据集名[in]。
	//! \return 拓扑数据集。
	virtual UGDatasetTopo* CreateDatasetTopo(UGString strName);
	
	//! \brief 创建栅格数据集。
	//! \param rInfo 栅格数据集信息[in]。
	//! \return 栅格数据集。
	virtual UGDatasetRaster* CreateDatasetRaster(
		const UGDatasetRasterInfo& rInfo);
	
	//! \brief 删除数据集。
	//! \param strName 数据集名称[in]。
	//! \return 是否操作成功，是返加TRUE 否则返回FALSE。
	virtual UGbool DeleteDataset(const UGString& strName);
	
	virtual UGbool IsSupport(UGDataset::DatasetType nDtType) const;
public:
	
	//! \brief 得到当前服务所有的图层及投影类型。
	//! \param layerinfos 所有图层的信息数组[out]。
	//! \param arySRS 数据源支持的投影类型数组[out]。
	//! \return 是否得到成功，是返加TRUE 否则返回FALSE。
	UGbool GetServiceInfo(UGWebLayersInfo& layerinfos, UGArray<UGString>& aryCRS);
	
	//! \brief 得到坐标参考系字符串。
	//! \return 坐标参考系字符串。
	UGString GetCRS(){return m_strCRS;}
	
	//! \brief 设置坐标参考系字符串。
	//! \return 是否设置成功，是返加TRUE 否则返回FALSE。
	void SetCRS(const UGString& strCRS){m_strCRS = strCRS;}


	//! \brief 设置数据集是否打开缓冲机制。
	//! \param bIsCached 是否打开缓冲机制[in]。
	//! \return TRUE为打开缓冲。
	void SetCached(const UGbool& bIsCached){m_bIsCached = bIsCached;}		

	//! \brief 数据集是否打开缓冲机制。
	//! \return TRUE为打开缓冲。
	UGbool IsCached(){return m_bIsCached;}
	
	//	protected:
private:
	
	//! \brief 测试某个URL是否能够成功进行GetCapbility请求。
	//! \param strGetCapbilityURL GetCapbility请求URL[in]。
	//! \return 是否解析成功，成功返加TRUE 否则返回FALSE。
	UGbool CheckGetCapbility(UGString strGetCapbilityURL);		
	
	//! \brief 得到解析用的临时文件。
	//! \param pDataSourceConnection 数据源指针[in]。
	//! \param strFilePath 文件路径[in]。
	//! \return 得到成功返回TRUE,失败返回FALSE。
	//! \remarks 调用函数负责删除。
	UGbool GetCapabilitiesFile(UGDsConnection * pDSConn, 
		UGString& strFilePath);
	
	// 
	//! \brief 解析网络数据源的信息。
	//! \param strFilePath 文件路径[in]。
	//! \return 是否解析成功，成功返加TRUE 否则返回FALSE。
	//! \remarks 。
	//! \attention 。
	UGbool ParseCapabilities(UGString &strFilePath);
	
	//! \brief 由CRS字符串得到投影坐标系。
	//! \param Prj 投影坐标系对象[out]。
	//! \param strCRS Web数据源的空间参考系字符串[in]。
	//! \return 是否得到成功，成功返加TRUE 否则返回FALSE。
	UGbool GetProjectionByName(UGPrjCoordSys& Prj, const UGString& strCRS);

public:
	//! \brief URL。
	//! \remarks URL。
	//! \brief http://maps.supermap.com:7070/ogc3/smwms?REQUEST=GetCapabilities&SERVICE=WMS&VERSION=1.3.0
	//UGString m_strURL;
	
	//! \brief 服务器名。
	//! \remarks 服务器名加域名或IP地址。
	//! \brief maps.supermap.com.  或  220.194.106.169。
	UGString m_strHost;
	
	//! \brief 端口号。
	//! \remarks 默认为tcp 80 端口。
	//! \brief :7070
	UGushort m_nPort;			
	
	//! \brief 服务路径。
	//! \remarks 网络数据服务相对于Web服务器根的相对路径。
	//! \brief /ogc3/smwms
	UGString m_strPath;
	
	//! \brief WMS、WCS或WFS规范的版本号。
	//! \remarks 截到2007年6月18日，WMS规范的最新版本是1.3.0 , WFS的最新版本版本是 1.1.1 。
	//! \brief VERSION=1.3.0&
	UGString m_strVersion;
	
	//! \brief 网络数据源地图集。
	//! \remarks 非标准,SuperMap独有,对应于IS Java发布的地图名。
	//! \brief SERVICENAME=World&
	UGString m_strMapName;
	
	//! \brief 数据源的坐标参考系。
	//! \remarks 存放Web数据源的坐标参考系。
	UGString m_strCRS;

	//! \brief 数据源的边界。
	//! \remarks 存放Web数据源的坐标参考系边界。
	UGRect2D m_rcBounds;
	
	//! \brief 数据源图层集合信息。
	//! \remarks 此数组保存了当前服务器的某一地图的所有图层的信息。
	UGWebLayersInfo m_layersInfo;
	
	//! \brief WMS支持的影像格式,或WFS支持的GML的版式本。
	//! \remarks 现在支持png、bmp、jpg 格式。
	UGArray<UGString> m_AryFormat;
	
	//! \brief 网络数据解析器。
	//! \remarks 失量栅格解析器有所不同。
	UGWebServiceParser* m_pWebParse;
	
	//! \brief 是否缓冲网络数据。
	//! \remarks 备注信息。
	UGbool m_bIsCached;
};

extern "C" WEBENGINE_API UGDataSource* CreateDataSource();	
}
#endif // !defined(UGWEBDATASOURCE_H)
