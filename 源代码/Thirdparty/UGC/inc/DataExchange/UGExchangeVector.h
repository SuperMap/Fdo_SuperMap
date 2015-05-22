
/*!
    **************************************************************************************
     \file     UGExchangeVector.h
    **************************************************************************************
     \author   艾国
     \brief    数据转换层中-----数据转换矢量类                      
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

#if !defined(AFX_UGEXCHANGEVECTOR_H__F0CBB300_85F0_4105_87D2_F0F9F5C211B5__INCLUDED_)
#define AFX_UGEXCHANGEVECTOR_H__F0CBB300_85F0_4105_87D2_F0F9F5C211B5__INCLUDED_


#include "UGExchangeFile.h"
#include "Base/UGList.h"
#include "Base/UGDict.h"
#include "Base/UGProgress.h"
#include "Engine/UGDatasetVector.h"

namespace UGC {

class UGRecordset;
class UGFileParseVector;
class UGDatasetVector;
	
class UGExchangeVector : public UGExchangeFile  
{
public:
	UGExchangeVector();
	virtual ~UGExchangeVector();

public:
	//! \brief 导入为简单数据集
	virtual UGbool Import(UGDataSource* pDataSource, const UGString& strFilePathName);
	
	//! \brief	导入为复合数据集
	virtual UGbool ImportCAD(UGDataSource* pDataSource, const UGString& strFilePathName);

	//! \brief	导出（未实现）
	virtual UGbool Export(UGDataSource* pDataSource, const UGString& strFilePathName);

	
public:
	//! \brief	以下方法均为参数设置方法
	void SetDgnColorMappingTableName(const UGString& strDgnColorMappingTableName);

	void SetToleranceGrain(UGdouble dToleranceGrain);

	void SetSrcDefaultUnits(UGint nSrcDefaultUnits);

	void SetDgnUnitsSelected(UGint nDgnUnitsSelected);

	void SetLayers(const UGList<UGString>& layers);

	void SetLayerName(const UGString& strLayerName);

	void SetElevationName(const UGString& strElevationName);

	void SetIsImportAsCompressedDatset(UGbool bImportAsCompressedDatset);

	void SetIsIgnoreNetworkTopology(UGbool bIgnoreNetworkTopology);

	void SetIsIgnoreStyle(UGbool bIgnoreStyle);

	void SetIsBuildSpatialIndex(UGbool bBuildSpatialIndex);

	void SetIsHoldNoGeometryDT(UGbool bHoldNoGeoDT);

	void SetSymbolStyle();

	//! brief 设置符号对照
	void SetSymbolStyleMapper(UGSymbolStyleMapper SymbolStyleMapper);
	
	//! brief 设置线型对照
	void SetPenStyleMaper(UGPenStyleMapper PenStyleMapper);
	
	//! brief 设置填充风格对照
	void SetBrushStyleMapper(UGBrushStyleMapper BrushStyleMapper);

	//! brief 设置字体风格对照
	void SetFontStyleMapper(UGFontStyleMapper FontStyleMapper);

protected:

	//! \brief 一个图层导入时,对应的记录集 和 字段名字
	struct UGRecordsetInfo
	{
		//! \brief 记录集指针
		UGRecordset* m_pRecordset;
		//! \brief 图层字段名
		UGString m_strLayerField;
		//! \brief 子图层名
		UGString m_strSubName;
		//! \brief 字段名集合
		UGStrings m_strFieldNames;
		//! \brief 扩展字段名集合
		UGStrings m_strExtendFieldNames;
		//! \brief 析构函数中, 是否自动释放记录集等
		UGbool m_bAutoRelease;
		//! \brief 是否自动建立空间索引
		UGbool m_bBuildSpatialIndex;
		//! \brief 是否保留没有几何对象，只有属性信息的数据集
		UGbool m_bHoldNoGeometryDT;		
		//! \brief 构造函数
		UGRecordsetInfo()
		{
			m_pRecordset=NULL;
			m_bAutoRelease = FALSE;
			m_bBuildSpatialIndex = TRUE;
			m_bHoldNoGeometryDT = FALSE;
		}

		//! \brief 析构函数, 释放记录集，关闭数据集
		~UGRecordsetInfo();
	};

	typedef UGDict<UGString, UGRecordsetInfo*> NameToRecordset;	

	typedef UGArray<UGRecordsetInfo> UGRecordsetInfos;

protected:

	//! \brief	dgn颜色表，注意，这个参数在控件层没有。用工作空间附带的颜色表
	UGString m_strDgnColorMappingTable; 

	//! \brief	在转化曲线为线或面对象时，指定的精度
	UGdouble m_dToleranceGrain; 
	
	//! \brief 	在外部文件没有坐标单位时，设定（假定）它的单位是什么。(对于dgn而言，必须指定转入单位)
	UGint m_nSrcDefaultUnits;	
	
	//! \brief 	dgn的东东，用dgn的哪个单位（main、sub or pos）作为supermap的单位。
	UGint m_nDgnUnitsSelected;	

	//! \brief 	由用户指定要导入的图层的名字集合
	UGList<UGString> m_layers; 
	
	//! \brief 	由外部指定 底层自动加上的表示高度信息的字段的名字
	UGString m_strElevationName; 

	//! \brief	图层字段名
	//! \remarks 导入时，为生成的、存放图层信息的字段（名）
	//! 导出时，用这个字段的值来设置当前记录导出后所属的图层
	UGString m_strLayerName;

	//! \brief 	数据集是否压缩
	UGbool m_bImportAsCompressedDatset; 
	//! \brief 	是否忽略网络拓扑
	UGbool m_bIgnoreNetworkTopology; 
	//! \brief 	是否示范忽略风格
	UGbool m_bIgnoreStyle;
	//! \brief 矢量数据导入后是否自动建立空间索引
	UGbool m_bBuildSpatialIndex;	
	//! \brief 是否保留没有几何对象，只有属性信息的数据集
	UGbool m_bHoldNoGeometryDT;	

	//! brief 符号对照表。
	UGSymbolStyleMapper m_SymbolStyleMapper;	
	//! brief 线型对照
	UGPenStyleMapper m_PenStyleMapper;	
	//! brief 填充风格对照
	UGBrushStyleMapper m_BrushStyleMapper;	
	//! brief 填充风格对照
	UGFontStyleMapper m_FontStyleMapper;	

	//! brief 投影 当前数据源的 空间参考
	UGPrjCoordSys m_UGCSpatialRef;

	//! brief 投影 导入文件的 空间参考
	UGPrjCoordSys m_FileSpatialRef;

	//! brief 进程条
	UGProgress m_Progress;

private:
	//void CopyUserParams(UGFileParseVector* pFileVector);

	//! \brief 创建矢量数据集, 创建字段, 并把查询后的结果通过参数返回
	UGbool CreateDatasetVector(UGFileParseVector* pFileVector, 
						UGDataSource* pDataSource, NameToRecordset& nameToRecordset);

	//! \brief 创建CAD数据集, 创建字段, 并把查询后的结果通过参数返回
	UGbool CreateDatasetCAD(UGFileParseVector* pFileVector, 
		UGDataSource* pDataSource, UGRecordsetInfo& recordsetInfo);

	//! \brief 根据图层名,图层类型 等信息, 创建/得到  数据集的指针
	//! \return 如果出现问题, 返回NULL
	UGDatasetVector* GetDatasetVector(UGDataSource* pDataSource, 
									UGFileParseVector* pFileVector,
									const UGString& strLayerName, 
									UGint nLayerType, const UGString& strSubName, 
									NameToRecordset& nameToRecordset);
	void CreateFields(UGDatasetVector* pDataset, UGFileParseVector* pFileVector, 
						UGRecordsetInfo* pRecordsetInfo, UGint nIndexLayer);

	//! \brief Import简单数据集时,添加一个简单对象
	void AddGeometry(UGRecordsetInfo *pRecordsetInfo, UGFileParseVector* pFileVector, UGGeometry *pGeometry, UGString strLayerName);

	//坐标系统 转换
	enum UGPJConvertType//外部数据文件类型
	{
		Plane2Plane   =0,			//平面坐标之间的转换，主要是坐标单位的统一问题
		Geo2Geo		  =1,			//经纬度坐标之间的转换，应该考虑到不同Datum的差别
		Geo2PJ		  =2,			//经纬度坐标-->投影坐标之间的转换，应该考虑到不同Datum的差别
		PJ2Geo		  =3,			//投影度坐标-->经纬坐标之间的转换，应该考虑到不同Datum的差别
		PJ2PJ		  =4,			//投影度坐标-->投影坐标之间的转换，应该考虑到不同Datum的差别
	};
	
	//空间参考变换要用到的方法
	//! \brief 根据 m_FileSpatialRef 和 DataSource 中的空间参考得到 UGPJConvertType
	UGbool GetDefaultPJConvertType(UGPJConvertType& nPJConvertType);

	//! \brief 坐标系转换	
	void ConvertCoordSys(UGGeometry *pGeometry,UGPJConvertType nConvertType = Plane2Plane);

	//! \brief 进程条处理:初始化
	void InitialProgress(UGString strMesg);
};



} //namespace UGC

#endif // !defined(AFX_UGEXCHANGEVECTOR_H__F0CBB300_85F0_4105_87D2_F0F9F5C211B5__INCLUDED_)
