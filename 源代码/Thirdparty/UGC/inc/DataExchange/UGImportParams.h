
/*!
    **************************************************************************************
     \file     UGImportParams.h
    **************************************************************************************
     \author   艾国
     \brief    数据转换导入参数类           
     \remarks                                                                          <br>
    ----------------------------------------------------------------------------------<br>
     Revision History :                                                               <br>  
     2005-04-22  艾国    Initial Version.                                           <br>
                                                                                      <br>   
    ----------------------------------------------------------------------------------<br>
     Copyright (c) 1996-2004 SuperMap GIS Technologies,Inc.                           <br>
    ----------------------------------------------------------------------------------<br>

    **************************************************************************************
*/


#if !defined(AFX_UGIMPORTPARAMS_H__7E206152_BB8D_47AC_9C42_1E02DB85017B__INCLUDED_)
#define AFX_UGIMPORTPARAMS_H__7E206152_BB8D_47AC_9C42_1E02DB85017B__INCLUDED_


#include "UGExchangeParams.h"
#include "Base/UGList.h"
#include "Engine/UGDataset.h"

namespace UGC {

	class UGDatasetInfo;


class DATAEXCHANGE_API UGImportParams : public UGExchangeParams  
{
public:
	UGImportParams();
	~UGImportParams();

	//! \brief 以下均为 设置/获取 导入参数方法
	
	void SetDgnColorMappingTableName(const UGString& strDgnColorMappingTableName);
	UGString GetDgnColorMappingTableName() const;

	void SetToleranceGrain(UGdouble dToleranceGrain);
	UGdouble GetToleranceGrain() const;

	void SetSrcDefaultUnits(UGint nSrcDefaultUnits);
	UGint GetSrcDefaultUnits() const;

	void SetDgnUnitsSelected(UGint nDgnUnitsSelected);
	UGint GetDgnUnitsSelected() const;

	void SetLayers(const UGList<UGString>& layers);
	UGList<UGString> GetLayers() const;

	void SetGridDataType(UGint nGridDataType);
	UGint GetGridDataType() const;

	void SetElevationName(const UGString& strElevationName);
	UGString GetElevationName() const;


	//! \brief 设置数据编码方式
	void SetDatasetEncType(UGDataCodec::CodecType encType);
	UGDataCodec::CodecType GetDatasetEncType() const;	

	//! \brief 设置是否导入为复合数据集（导入矢量数据时设置）
	void SetIsImportAsCADDataset(UGbool bImportAsCADDataset);
	UGbool IsImportAsCADDataset() const;
	
	//! \brief是否导入点数据，在SetIsImportASCADDataset(False)时起作用 
	void SetIsImportPoint(UGbool bImportPoint);
	UGbool IsImportPoint() const;

	//! \brief是否导入线数据，在SetIsImportASCADDataset(False)时起作用 
	void SetIsImportLine(UGbool bImportLine);
	UGbool IsImportLine() const;

	//! \brief是否导入面数据，在SetIsImportASCADDataset(False)时起作用 
	void SetIsImportRegion(UGbool bImportRegion);
	UGbool IsImportRegion() const;

	//! \brief是否导入文本数据，在SetIsImportASCADDataset(False)时起作用 
	void SetIsImportText(UGbool bImportText);
	UGbool IsImportText() const;

	void SetCADDatasetName(UGString str);
	UGString GetCADDatasetName() const;

	void SetPointDatasetName(UGString str);
	UGString GetPointDatasetName() const;

	void SetLineDatasetName(UGString str);
	UGString GetLineDatasetName() const;

	void SetRegionDatasetName(UGString str);
	UGString GetRegionDatasetName() const;

	void SetTextDatasetName(UGString stsr);
	UGString GetTextDatasetName() const;

	void SetIsIgnoreCoordSys(UGbool bIgnoreCoordSys);
	UGbool IsIgnoreCoordSys() const;

	void SetIsIgnoreAttribute(UGbool bIgnoreAttribute);
	UGbool IsIgnoreAttribute() const;

	void SetIsIgnoreNetworkTopology(UGbool bIgnoreNetworkTopology);
	UGbool IsIgnoreNetworkTopology() const;

	void SetIsIgnoreStyle(UGbool bIgnoreStyle);
	UGbool IsIgnoreStyle() const;

	void SetIsHoldNoGeometryDataset(UGbool bHoldNoGeometryDT);
	UGbool IsHoldNoGeometryDataset() const;

	void SetIsBuildSpatialIndex(UGbool bBuildSpatialIndex);
	UGbool IsBuildSpatialIndex() const;

	void SetIsBuildPyramid(UGbool bBuildPyramid);
	UGbool IsBuildPyramid() const;

	//! \brief 是否导入为Grid数据集（导入栅格数据时设置）
	void SetIsImportAsGridDataset(UGbool bImportAsGrid);
	UGbool IsImportAsGridDataset() const;

	//! \brief 设置栅格数据集名
	void SetRasterDatasetName(UGString strName);
	UGString GetRasterDatasetName() const;


public:
	//! \brief 标记一下外部是否设置 m_bImportAsCADDataset
	UGbool HasSetImportAsCADDataset() const;	

	//! \brief 标记一下外部是否设置 m_bImportAsGridDataset
	UGbool HasSetImportAsGridDataset() const;

protected:

	//! \brief 复合数据集名
	UGString m_strCADDatasetName;

	//! \brief 点数据集名
	UGString m_strPointDatasetName;

	//! \brief 线数据集名
	UGString m_strLineDatasetName;

	//! \brief 面数据集名
	UGString m_strRegionDatasetName;

	//! \brief 文本数据集名
	UGString m_strTextDatasetName;

	//! \biref 栅格数据集名
	UGString m_strRasterDatasetName;

	//! \brief	dgn颜色表，注意，这个参数在控件层没有。用工作空间附带的颜色表
	UGString m_strDgnColorMappingTable; 

	//! \brief 数据集的编码方式
	UGDataCodec::CodecType m_encType;

protected:

	//! \brief	在转化曲线为线或面对象时，指定的精度
	UGdouble m_dToleranceGrain; 
	
	//! \brief 	在外部文件没有坐标单位时，设定（假定）它的单位是什么。(对于dgn而言，必须指定转入单位)
	UGint m_nSrcDefaultUnits;
	
	//! \brief 	dgn的东东，用dgn的哪个单位（main、sub or pos）作为supermap的单位。
	UGint m_nDgnUnitsSelected;	
	
	//! \brief 	转入影像数据后，每个栅格的数据类型（几个字节来表示一个栅格数据），有预定义的宏
	UGint m_nGridDataType; 

	//! \brief 	由外部指定 底层自动加上的表示高度信息的字段的名字
	UGString m_strElevationName; 

protected:

	struct bImportParams 
	{
		//! \brief 	是否导入到复合数据集（CAD数据集中）
		UGbool m_bImportAsCADDataset; 

		//! \brief 	是否导入点数据
		UGbool m_bImportPoint; 

		//! \brief 	是否导入线数据
		UGbool m_bImportLine; 

		//! \brief 	是否导入面数据
		UGbool m_bImportRegion; 

		//! \brief 	是否导入文本数据
		UGbool m_bImportText; 
		
		//! \brief 	是否忽略源文件的坐标系统，
		UGbool m_bIgnoreCoordSys; 
		
		//! \brief 	是否忽略属性信息，
		UGbool m_bIgnoreAttribute; 
		
		//! \brief 	是否忽略网络拓扑
		UGbool m_bIgnoreNetworkTopology; 
		
		//! \brief 	是否示范忽略风格
		UGbool m_bIgnoreStyle;

		//! \brief 矢量数据导入后是否自动建立空间索引
		UGbool m_bBuildSpatialIndex;

		//! \brief 是否保留没有几何对象，只有属性信息的数据集
		UGbool m_bHoldNoGeometryDT;	

		//! \brief 是否导入为gird数据集
		UGbool m_bImportAsGridDataset;

		//! \brief 栅格数据导入后是否自动建立影像金字塔
		UGbool m_bBuildPyramid;


		bImportParams()
		{
			m_bImportAsCADDataset = FALSE;
			m_bImportPoint = TRUE;
			m_bImportLine = TRUE;
			m_bImportRegion = TRUE;
			m_bImportText = TRUE;
			m_bIgnoreCoordSys = TRUE;
			m_bIgnoreAttribute = FALSE;
			m_bIgnoreNetworkTopology = TRUE;
			m_bIgnoreStyle = FALSE;
			m_bBuildSpatialIndex = TRUE;
			m_bHoldNoGeometryDT = FALSE;	

			m_bImportAsGridDataset = TRUE;
			m_bBuildPyramid = TRUE;
		}
	};

	bImportParams m_bImportParams;
	
	//! \brief 外部是否设置m_bImportAsCADDataset（是否导入为复合数据集），没有设置则提供一套默认的
	UGbool m_bHasSetIsImportAsCADDataset;

	//! \brief 外部是否设置m_bImportAsGridDataset（是否导入为复合数据集），没有设置则提供一套默认的
	UGbool m_bHasSetIsImportAsGridDataset;




	//{{一下是UGC6.0预留接口

	//! \brief 是否忽略 M 值
	UGbool m_bIgnoreMValue;

	//! \brief 是否忽略 Z 值
	UGbool m_bIgnoreZValue;
	
	//! \brief 	由用户指定要导入的图层的名字集合（CAD DGN 专用）
	UGList<UGString> m_layers; 

	//! \brief 是否将每个图层中点、线、面、文本单独导入为一个数据集，与m_layers联合使用，（CAD DGN 专用）
	UGbool m_bDivideLayer;

	//另外要增加CAD DGN 专用的，外部可以设置 导入后的颜色值、颜色索引、块名等字段名
	//}}

};


} //namespace UGC

#endif // !defined(AFX_UGIMPORTPARAMS_H__7E206152_BB8D_47AC_9C42_1E02DB85017B__INCLUDED_)
