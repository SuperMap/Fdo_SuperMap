/*!
    **************************************************************************************
     \file     UGMetaData.h
    **************************************************************************************
     \author	李文龙
     \brief		元数据操作                   
     \remarks	主要是根据数据源，管理元数据	                                          <br>
				涉及两个方面:	1, 那个数据源的元数据.
								2, 元数据存储在那里
				现在准备这样设计,来源是个数据源,存储也是个数据源.
				一个数据源可以存储多个元数据.
    ----------------------------------------------------------------------------------<br>
     Revision History :                                                               <br>  
     18/05/2005  李文龙    Initial Version.                                           <br>
                                                                                      <br>   
    ----------------------------------------------------------------------------------<br>
     Copyright (c) 1996-2004 SuperMap GIS Technologies,Inc.                           <br>
    ----------------------------------------------------------------------------------<br>

	<b>更新说明</b>
	<em>1、第一条说明。</em>
	<em>2、第二条说明。</em>
    **************************************************************************************
*/

#if !defined(UGMetadata_H)
#define UGMetadata_H

#include "Base/ugdefs.h"
#include "Base/UGString.h"
#include "Base/UGArray.h"
#include "Base/UGMarkup.h"
#include "Base/UGDict.h"

#include "UGDataSource.h"
#include "UGEngDefs.h"

namespace UGC
{
#define  SmEastBLName		"#eastBL"		//东
#define  SmSouthBLName		"#southBL"		//南
#define  SmWestBLName		"#westBL"		//西
#define  SmNorthBLName		"#northBL"		//北
#define  SmFieldinfosName	"#feildInfos"
#define  SmDatasetNameName	"#datasetName"	//数据集名字
#define  SmRecordCountName	"#recordCount"	//数据集记录数
#define  SmDatasetTypeName	"#datasetType"
#define  SmTableNameName	"#tableName"
#define  SmCreatorName		"#creator"
#define  SmCreateTimeName	"#createTime"	
#define  SmLastUpdateTimeName "#lastUpdateTime"
#define  SmNovalueName		"#noValue"
#define  SmPixelFormatName	"#pixelFormat" 
#define  SmWidthName		"#width"
#define  SmHeightName		"#height"
	
class ENGINE_API UGMetaElements:public UGArray<UG_META_ELEMENT> 
{
	
};

class ENGINE_API UGDatasetTierNames:public UGArray<UG_DATASET_TIER_NAME>
{

};

class ENGINE_API UGDatasetMetaData
{
public:
	UGString GetMetadata();
	UGbool ImportMetadata(UGString &strXML);

	UGString GetTileMetadata(UGint nTileID);
	UGbool ImportMetadata(UGint nTileID,UGString &strXML);

	UGbool IsTile();
public:
	UGint m_nDatasetID;
	UGString m_strDatasetName;

};

class ENGINE_API UGDatasourceMetaData
{
public:
	UGString GetDatasourceMeta();
	UGbool GetAllDatasetMetas(UGArray<UGDatasetMetaData> & arydatasetMetas);
public:
	UGint m_nID;
	UGString m_strDsName;
	UGArray<UGDatasetMetaData> m_aryDatasetMeta;
};


class ENGINE_API UGMetadata  
{
public:
	//Maping 文件里的宏
	enum MappingField
	{
		SmNone			= -1,
		SmEastBL		= 0,
		SmSouthBL		= 1,
		SmWestBL		= 2,
		SmNorthBL		= 3,			
		SmDatasetName	= 4,
		SmTableName		= 5,
		SmDatasetType	= 6,
		SmRecordCount	= 7,
		SmFieldinfos	= 8,
		SmCreator		= 9,
		SmCreateTime    = 10,
		SmLastUpdateTime= 11,
		SmNovalue		= 12,
		SmPixelFormat	= 13,
		SmWidth			= 14,
		SmHeight		= 15
	};
	enum MetaQueryMode
	{
		MQVector	=	1,	//只查询矢量元数据
		MQRaster	=	2,	//只查询栅格元数据
		MQAll		=	3	//全查
	};
public:
	UGMetadata();
	virtual ~UGMetadata();

public:
	//! \brief 根据连接信息，得到存储元数据的数据源
	//! \param *conn [in]。
	//! \return 
	//! \remarks 
	//! \attention 。
	UGbool OpenDesDatabase(UGDsConnection conn);
	
	//! \brief 设置元数据库相关的数据源,需要先调用OpenDesDatabase()
	//! \param *pDatasource [in]。
	//! \return 
	//! \remarks 设置之后可以调用刷新功能，来刷新元数据，来保证和当前给的数据源信息一致
	//			 如果元数据库里没有这个数据源，就添加一个。判断是否有的标志是，
	//			 数据库名，用户名。	
	//! \attention 。
	virtual UGbool SetDatasource(UGDataSource *pDatasource);

	//! \brief 删除数据源的元数据相关信息
	virtual UGbool DeleteDSRegister(UGDataSource *pDatasource);

	//! \brief 获得当前元数据库中存储的数据源的连接信息
	virtual UGbool GetDatasoures(UGArray<UGDsConnection> &arrConns);

	//! \brief 获得当前数据源中元数据已经存在的数据集名
	virtual UGbool GetDatasetNames(UGDatasetTierNames &datasetTierIDs);

	//模版相关
	//! \brief 添加模版，如果模版库里strCaptial已经存在则返回False
	virtual UGbool AddTemplateFile(UGString strCaptial,UGString &strFormatFile,UGString &strDescription);

	//! \brief 获取数据库中所有模版的名字
	virtual UGbool GetTemplateNames(UGArray<UGString> &aryNames);

	//! \brief 通过模版名字得到模版内容
	virtual UGString GetTemplateByName(UGString strCaptial);

	//! \brief 删除模版
	virtual UGbool DeleteTemplateByName(UGString strCaptial);

	//! \brief 通过模版名字 设置当前使用的模版
	//! \param strCaptial [in]。
	UGbool SetTemplate(UGString strCaptial);

	//Mapping相关
	//! \brief 添加映射 关系，如果strTag已经存在则返回False
	virtual UGbool AddMapping(MappingField nMaping, UGString strTag);

	//! \brief 通过名字获取 对应的字段
	virtual UGint GetMapping(UGString strTag);
	
	//! \brief 获取所有的映射
	virtual UGbool GetAllMapping(UGArray<UGString> aryTags, UGArray<UGint> arrField);

	//! \brief 删除一个映射
	virtual UGbool DeleteMapping(UGString strTag);

	UGString GetMetaMappintTable(){
		return m_strMetaMappingTable;
	};

	UGString GetMetaVectorTable(){
		return m_strMetaVectorTable;
	};

	UGString GetMetaRasterTable(){
		return m_strMetaRasterTable;
	};

	//! \brief 刷新元数据，根据设置的数据源,被删除的数据集元数据要删除，新添加的数据集不会自动添加元数据
	//! \return 。
	//! \remarks 。
	//! \attention 。
    virtual UGbool RefreshDatasource();

//	//! \brief 得到所有的数据的元数据
//	//! \param aryDSMetadatas [in]。
//	//! \return 。
//	//! \remarks 。
//	//! \attention 。
//	UGbool GetDatasourceMetadatas(UGArray<UGDatasourceMetaData> & aryDSMetadatas);
//
//	//! \brief 。
//	//! \param nIndex [in]。
//	//! \return 。
//	//! \remarks 。
//	//! \attention 。
//	UGDatasourceMetaData* GetDatasourceMetadata(UGint nIndex);
//
//	//! \brief 。
//	//! \param strAlias [in]。
//	//! \return 。
//	//! \remarks 。
//	//! \attention 。
//	UGDatasourceMetaData* GetDatasourceMetadata(UGString strAlias);	

public:
	//! \brief 导入元数据
	UGbool ImportMetadata(UGString strDatasetName, UGint nTileID, UGString &strMetaFile);

	//! \brief 删除元数据
	virtual UGbool DeleteMetadata(UGString strDatasetName, UGint nTierID);

	//! \brief 获取元数据
	UGbool GetMetadata(UGString strDatasetName,UGint nTierID,UGString &strXml);

	//! \brief 查询元数据
	UGbool SetQueryMode(MetaQueryMode mode);

	virtual UGbool QueryMetadataWithFilter(UGString strFilter,UGMetaElements &Metadatas) = 0;
	
	UGbool QueryDTsWithFilter(UGArray<UGString> arrTags,UGArray<UGString> arrVals,
		UGDatasetTierNames &datasetTierIDs, UGbool bFuzzyQuery);

	UGbool QueryDTsWithBounds(UGRect2D rcBounds,UGDatasetTierNames &datasetTierIDs);
	
	UGString GetMappingFieldName(MappingField nField);

	UGint GetMappingFieldCaption(UGString strTag);

	UGTextCodec::Charset GetFileEncoding(UGString &strFile, UGbool bStrIsFile = TRUE);

	UGbool InitDataset(UGString strDataset, UGint nTileID);

protected:
	//! \brief 判断当前数据集的元数据是否已经存在
	virtual UGbool IsMetadataExist(UGint nDatasetID);
	
	virtual UGbool AddMetadataDesc(UGint nDatasetID,UGint nTierID,UG_META_ELEMENT & MetaElement) = 0;
	
	void ParseMetadata(UGMarkup &makeup,UG_META_ELEMENT &metadata);
	
	void MatchingMetaData(UGMarkup &markup,UGString &strMetaFile,UGString &strFormatFile);

private:
	
	void MatchingElem(UGMarkup &markup,UGMarkup &Metafile, UGMarkup &Formatfile);
	
	//!从数据库读出来
	UGbool ReadMaping(UGMarkup &markup,UG_META_ELEMENT &metaElement);

	virtual void FillMapping(UGbool bTagFirst);

	virtual void UpdateRegister();

	//! \brief 在QueryDTsWithFilter 中调用
	virtual UGbool QueryDTsWithFilterSub(UGArray<UGString> arrTags,UGArray<UGString> arrVals,
		UGDatasetTierNames &datasetTierIDs, UGbool bFuzzyQuery) = 0;

	//! \brief 在QueryDTsWithBounds 中调用
	virtual UGbool QueryDTsWithBoundsSub(UGRect2D rcBounds,UGDatasetTierNames &datasetTierIDs)  = 0;

	UGString DatasetType2String(UGDataset::DatasetType nType); 

	UGString PixelFormat2String(PixelFormat pixF);

protected:
	//需要 存储元数据的数据源
	UGDataSource *m_pDatasource;
	
	//存储元数据的数据库
	UGDataSource *m_pDesDatasource;

	//跟 m_pDatasource 数据源相关的 元数据表 表名
	UGString m_strMetaMappingTable;
	UGString m_strMetaVectorTable;
	UGString m_strMetaRasterTable;
	UGString m_strMetaVectorRegister;
	UGString m_strMetaRasterRegister;

	//当前数据集是否是矢量数据集或者topo数据集
	UGbool m_bIsDatasetVector;

	//当前设置的元数据模版
	UGString m_strTemplateName;

	UGint m_nLevel;
	UGint m_nDatasetID;
	UGint m_nTileID;

	//映射表
	UGDict<UGString,UGString> m_MapDict;
	
	//当前数据集指针
	UGDataset    *m_pDataset;

	//查询模式
	MetaQueryMode m_QueryMode;
};
}


#endif // !defined(UGMetadata_H)
