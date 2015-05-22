// UGOrcMetadata.h: interface for the UGOrcMetadata class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(UGORCMetadata_H)
#define UGORCMetadata_H

#include "Base/ugdefs.h"	// Added by ClassView
#include "Engine/UGMetaData.h"

namespace UGC
{

class ORCENGINE_API UGOrcMetadata :public UGMetadata
{
public:
	UGOrcMetadata();
	UGOrcMetadata(UGDataSource *pDatasource);
	virtual ~UGOrcMetadata();

public:
	//! \brief 设置元数据库相关的数据源
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

	//! \brief 刷新元数据，根据设置的数据源,被删除的数据集元数据要删除，新添加的数据集不会自动添加元数据
	//! \return 。
	//! \remarks 。
	//! \attention 。
    virtual UGbool RefreshDatasource();

	//模版相关
	//! \brief 设置模版，如果模版库里没有则加入	
	virtual UGbool AddTemplateFile(UGString strCaptial,UGString &strFormatFile,UGString &strDescription);
	
	//! \brief 获取数据库中所有模版的名字
	virtual UGbool GetTemplateNames(UGArray<UGString> &aryNames);

	//! \brief 通过模版名字得到模版内容
	virtual UGString GetTemplateByName(UGString strCaptial);

	//! \brief 删除模版
	virtual UGbool DeleteTemplateByName(UGString strCaptial);

	//! \brief 删除元数据
	virtual UGbool DeleteMetadata(UGString strDatasetName, UGint nTierID);

	//Mapping相关
	//! \brief 添加映射 关系，如果strTag已经存在则返回False
	virtual UGbool AddMapping(MappingField nMaping, UGString strTag);

	//! \brief 通过名字获取 对应的字段
	virtual UGint GetMapping(UGString strTag);
	
	//! \brief 获取所有的映射
	virtual UGbool GetAllMapping(UGArray<UGString> aryTags, UGArray<UGint> arrField);

	//! \brief 删除一个映射
	virtual UGbool DeleteMapping(UGString strTag);
	
	virtual UGbool QueryMetadataWithFilter(UGString strFilter,UGMetaElements &Metadatas);
	
protected:
	virtual UGbool IsMetadataExist(UGint nDatasetID);

	virtual UGbool AddMetadataDesc(UGint nDatasetID,UGint nTileID, UG_META_ELEMENT & MetaElement);

private:
	virtual void FillMapping(UGbool bTagFirst);

	virtual void UpdateRegister();
	void UpdateVectorRegister();
	void UpdateRasterRegister();

	UGbool RefreshVectorRegister();
	UGbool RefreshRasterRegister();

	//! \brief 在QueryDTsWithFilter 中调用
	virtual UGbool QueryDTsWithFilterSub(UGArray<UGString> arrTags,UGArray<UGString> arrVals,
		UGDatasetTierNames &datasetTierIDs, UGbool bFuzzyQuery);

	//! \brief 在QueryDTsWithBounds 中调用
	virtual UGbool QueryDTsWithBoundsSub(UGRect2D rcBounds,UGDatasetTierNames &datasetTierIDs);

	UGString BuildQueryFilterSQL(UGArray<UGString> arrTags,UGArray<UGString> arrVals,UGbool bFuzzyQuery);
	
	UGString BuildQueryBoundsSQL(UGRect2D rcBounds);
};

}

#endif // !defined(UGORCMetadata_H)
