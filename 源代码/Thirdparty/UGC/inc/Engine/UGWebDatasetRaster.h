//////////////////////////////////////////////////////////////////////////
//!  \file UGWebDatasetRaster.h:
//!  \brief UGWebDatasetRaster 栅格型的网络数据集类的接口定义。
//!  \details 文件详细信息。
//!  \author duxiaomin。
//!  \attention 
//!   Copyright (c) 1996-2007 SuperMap GIS Technologies,Inc.  <br>
//!   All Rights Reserved.
//!  \version 2.0
//////////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGWEBDATASETRASTER_H__2D4A9A10_F7EA_4FD6_BE42_677DD871669E__INCLUDED_)
#define AFX_UGWEBDATASETRASTER_H__2D4A9A10_F7EA_4FD6_BE42_677DD871669E__INCLUDED_

#include "Base/ugdefs.h"
#include "Engine/UGDataset.h"

#include "Engine/UGDatasetRaster.h"

namespace UGC{

//! \brief 栅格型的网络数据集类。
class ENGINE_API UGWebDatasetRaster :public UGDataset
{
public:
	UGWebDatasetRaster();
	UGWebDatasetRaster(UGDatasetRasterInfo& rInfo);
	virtual ~UGWebDatasetRaster();

public:
	virtual UGbool Open() ;			
	virtual void Close() ;
	virtual UGTime GetDateLastUpdated() ;
	virtual UGTime GetDateCreated() ;
	virtual UGString GetName() ;		//	
	virtual UGString GetTableName() ;
	virtual UGbool Rename(const UGString& strNewName) ;		//
	virtual UGdouble GetMinZ() ;
	virtual void SetMinZ(UGdouble d) ;
	virtual UGdouble GetMaxZ() ;
	virtual void SetMaxZ(UGdouble d) ;
	virtual UGint GetDimension() ;
	virtual UGbool IsVector() ;		//
	virtual UGbool IsTopoDataset() ;		//
	virtual UGbool IsRaster() ;		//
	virtual UGbool IsLinkTable() ;		//
	virtual const UGRect2D& GetBounds() const ;
	virtual UGDataset::DatasetType GetType() const;		//
	virtual void SetBounds(const UGRect2D& r) ;
	virtual UGDataCodec::CodecType GetCodecType() ;
	virtual void SetCodecType(UGDataCodec::CodecType c) ;
	virtual UGint GetOptions() ;
	virtual UGbool SaveInfo() ;
	virtual UGbool RefreshInfo() ;	
protected:
	virtual void SetOptions(UGint nOptions);

public:

	//! \brief 得到基于内存的栅格数据集。
	//! \param strURL 向Web数据源请求的URL[in]。
	//! \return 栅格数据集指针。
	//! \remarks 其它重载函数都由此函数包装。
	virtual UGDatasetRaster* GetDatasetRaster(UGString strURL) =0;

	//! \brief 得到基于内存的栅格数据集,用于放大缩小平移操作的请求。
	//! \param rcBound 请求影像的四至范围[in]。
	//! \param dWidth 请求影像的宽度,单位像素[in]。
	//! \param dHeight 请求影像的高度,单位像素[in]。
	//! \param strFormat 请求影像的的格式[in]。
	//! \return 栅格数据集指针。
	virtual UGDatasetRaster* GetDatasetRaster(UGRect2D rcBound,
		UGint dWidth,UGint dHeight,UGString strFormat ="") = 0;
	

	//! \brief 得到数据源的所有图层名数组。
	//! \param aryNames 图层名数组[out]。
	//! \return 是否成功得到,成功返回TRUE,失败返回FALSE。
	virtual UGbool GetAllLayerNames(UGArray<UGString>& aryLayerNames) = 0;

	//! \brief 得到数据源的所有图层标题数组。
	//! \param aryNames 图层标题数组[out]。
	//! \return 是否成功得到,成功返回TRUE,失败返回FALSE。
	virtual UGbool GetAllLayerTitles(UGArray<UGString>& aryLayerTitles) = 0;

	//! \brief 得到数据源的所有图层编号数组。
	//! \param aryNames 图层编号数组[out]。
	//! \return 是否成功得到,成功返回TRUE,失败返回FALSE。
	virtual UGbool GetAllLayerIndexes(UGArray<UGint>& aryLayerIndexes) = 0;
	
	//! \brief 得到所有可见图层名数组。
	//! \param aryNames 可见图层名数组[in]。
	//! \return 是否成功得到,成功返回TRUE,失败返回FALSE。
	virtual UGbool GetVisibleLayerNames(UGArray<UGString>& aryLayerNames) = 0;
	
	//! \brief 得到所有可见图层标题数组。
	//! \param aryNames 可见图层图层标题数组[in]。
	//! \return 是否成功得到,成功返回TRUE,失败返回FALSE。
	virtual UGbool GetVisibleLayerTitles(UGArray<UGString>& aryLayerTitles) = 0;

	//! \brief 得到数据集所有可见的图层编号集合。
	//! \param aryNames 可见图层编号数组[in]。
	//! \return 是否成功得到,成功返回TRUE,失败返回FALSE。
	virtual UGbool GetVisibleLayerIndexes(UGArray<UGint>& aryLayerIndexes) = 0;

	//! \brief 设置当前数据集的可见图层。
	//! \param arySrc 源图层编号数组[in]。
	//! \return 是否设置成功,成功返回TRUE,否则返回FALSE。
	virtual UGbool SetVisibleLayers(const UGArray<UGint>& aryLayerIndexes) = 0;	

	//! \brief 设置当前数据集的可见图层。
	//! \param arySrc 源图层信息数组[in]。
	//! \return 是否设置成功,成功返回TRUE,否则返回FALSE。
	virtual UGbool SetVisibleLayers(const UGArray<UGString>& aryLayerNames) = 0;	
	
	//! \brief 从数据源得到基本的URL。
	//! \return 基本的URL。
	UGString GetBasalURL();	

public:
	//! \brief 内存数据源的指针数组。
	//! \remarks 备注信息。
	UGArray<UGDataSource *> m_MemDataSource;
	
protected:
	//! 纯粹为了实现GetBounds而设此成员
	UGDatasetRasterInfo m_RasterInfo;

};

}

#endif // !defined(AFX_UGWEBDATASETRASTER_H__2D4A9A10_F7EA_4FD6_BE42_677DD871669E__INCLUDED_)

