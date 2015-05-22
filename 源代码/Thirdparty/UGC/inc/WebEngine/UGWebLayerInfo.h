//////////////////////////////////////////////////////////////////////////
//                    _   _   ____   ____                    
//   Project         | | | | / ___) / ___)                   
//                   | | | || | __ | |                       
//                   | |_| || |_\ || \___                    
//                    \____/ \____| \ ___)     2.0           
//                                                           
//!  \file UGWMSLayerInfo.h
//!  \brief UGWMSLayerInfo 的接口定义。
//!  \details 文件详细信息。
//!  \author duxiaomin。
//!  \attention 
//!   Copyright (c) 1996-2007 SuperMap GIS Technologies,Inc.  <br> 
//!   All Rights Reserved.
//!  \version 2.0
//////////////////////////////////////////////////////////////////////////

#ifndef UGWMSLAYERINFO_H
#define UGWMSLAYERINFO_H

#include "Base/ugexports.h"
#include "Base/UGString.h"
#include "Algorithm/UGRect2D.h"
#include "Engine/UGDatasetVectorInfo.h"

namespace UGC
{
	
//! \brief 参考系四至结构。
//! \remarks Web图层的坐标参考系及其四至范围信息。
struct UGCRSBound
{
	//! \brief 图层的坐标参考系。
	UGString m_strCRSName;
	
	//! \brief 图层的四至范围。
	UGRect2D m_rcBound;
};

//! \brief 参考系四至集合。
//! \remarks 用于存放一个Web图层有多个坐标参考系及其四至范围信息的情况。
class WEBENGINE_API UGCRSBounds : public UGArray<UGCRSBound>
{
public:
	UGCRSBounds();
	~UGCRSBounds();
	
	//! \brief 得到参考系四至集合中的某个参考系的四至范围。
	//! \param CRSBounds 参考系四至集合[in]。
	//! \param m_strCRSName 坐标参考系名[in]。
	//! \return 参考系四至集合。
	//! \remarks 图层的四至范围。
	//! \attention 。
	static UGRect2D GetCRSBoundByName(const UGCRSBounds& CRSBounds, 
		const UGString& strCRSName);
};


//! \brief 网络数据源图层信息。
//! \remarks 备注信息。	
class WEBENGINE_API UGWebLayerInfo  
{
public:
	UGWebLayerInfo();
	UGWebLayerInfo(const UGWebLayerInfo& srcLayer);
	virtual ~UGWebLayerInfo();
	
	UGWebLayerInfo& operator=(const UGWebLayerInfo& srcLayer);
	UGbool operator==(const UGWebLayerInfo& layer) const;
	UGbool operator!=(const UGWebLayerInfo& layer) const;
	
public:
	//! \brief 图层名，对应Name标签。
	UGString m_strLayerName;	
	
	//! \brief 图层标题，对应Title标签。
	UGString m_strLayerTitle;
	
	//! \brief 图层摘要信息，对应Abstract标签。
	UGString m_strAbstract;	
	
	//! \brief 图层的坐标参考系和四至范围的集合。
	UGCRSBounds m_CRSBounds;
	
	//! \brief WCS所支持的格式。
	UGArray<UGString> m_aryFormart;
	
};

//! \brief 网络数据源图层信息集合。
class WEBENGINE_API UGWebLayersInfo : public UGArray<UGWebLayerInfo>
{
public:
	UGWebLayersInfo();
	~UGWebLayersInfo();
	
	//! \brief 图层集合的坐标参考系。
	//! \remarks 在1.3 版本以前坐标参考系的英缩写是SRS。
	UGString m_strCRS;
	
	//! \brief 图层集合的标题，对应Title标签。
	UGString m_strTitle;
};
	
}
#endif // !defined(UGWMSLAYERINFO_H)
