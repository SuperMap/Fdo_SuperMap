// UGOrcHelper.h: interface for the UGOrcHelper class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGORCHELPER_H__A1BEDC69_546B_480D_AF39_28B8676DE1FF__INCLUDED_)
#define AFX_UGORCHELPER_H__A1BEDC69_546B_480D_AF39_28B8676DE1FF__INCLUDED_

#include "Engine/UGDataset.h"

namespace UGC{

class ORCENGINE_API UGOrcHelper  
{
public:
	UGOrcHelper();
	virtual ~UGOrcHelper();

	static UGString GetCreateDatasetSql(UGString strSchema,UGString strTableName,UGDataset::DatasetType nType);
	static UGString GetCreateSmTopoRuleSql(UGString strSchema);       //new
	static UGString GetCreateSequenceSql(UGString strSchema,UGString strName,UGint nStart = 1 );
	static UGString GetCreateSmTopoRelationSql(UGString strSchema);   //new
	static UGString GetCreateSmRegisterSql(UGString strSchema);
	static UGString GetCreateSmImgRegisterSql(UGString strSchema);
	static UGString GetCreateSmDataSourceInfoSql(UGString strSchema);
	static UGString GetCreateSmFieldInfoSql(UGString strSchema);

	//garbage
	static UGString GetCreateSmEventProperty(UGString strSchema);
	static UGString GetCreateSmAuthent(UGString strSchema);
	static UGString GetCreateSmAction(UGString strSchema);
	static UGString GetCreateSmTag(UGString strSchema);
	static UGString GetCreateSmSequence(UGString strSchema);
	static UGString GetCreateSmDatasetLocked(UGString strSchema);
	static UGString GetCreateSmVersion(UGString strSchema);			//new
	static UGString GetCreateSmLog(UGString strSchema);				//new
	static UGString GetCreateSmLTUsers(UGString strSchema);

	//metadata
	static UGString GetCreateSmMetadata(UGString strSchema);
	static UGString GetCreateSmVectorMetaTable(UGString strSchema);
	static UGString GetCreateSmRasterMetaTable(UGString strSchema);
	static UGString GetCreateSmMetaElementTable(UGString strSchema);
	static UGString GetCreateSmMetaTable(UGString strSchema);
	static UGString GetCreateSmMaping(UGString strSchema);
	//有用的
	static UGString GetCreateSmMetaDSRegister(UGString strSchema);
	static UGString GetCreateSmMetaTemplate(UGString strSchema);


	
	static UGString GetCreateSmMetaMapping(UGString strSchema,UGint nID);
	static UGString GetCreateSmMetaVector(UGString strSchema,UGint nID);
	static UGString GetCreateSmMetaRaster(UGString strSchema,UGint nID);
	static UGString GetCreateSmMetaVectorRegister(UGString strSchema,UGint nID);	
	static UGString GetCreateSmMetaRasterRegister(UGString strSchema,UGint nID);

	//创建Tin数据集
	static UGString GetCreateTinSql(UGString strSchema,UGString &strName);
	//索引
	static UGString GetCreateSmDynamicIndexSql(UGString strSchema);
	
	// \brief 判断名字是否过长
	static UGbool IsLongName(UGString strName, UGbool bIsNetWorkDT);
};
}
#endif // !defined(AFX_UGORCHELPER_H__A1BEDC69_546B_480D_AF39_28B8676DE1FF__INCLUDED_)
