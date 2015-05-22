// UGSqlHelper.h: interface for the UGSqlHelper class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGSQLHELPER_H__E9B5E982_165B_46A0_B4DB_65A4CBAE1557__INCLUDED_)
#define AFX_UGSQLHELPER_H__E9B5E982_165B_46A0_B4DB_65A4CBAE1557__INCLUDED_

#include "Base/UGString.h"

namespace UGC {

class UGSqlHelper  
{
public:
	UGSqlHelper();
	virtual ~UGSqlHelper();
	
	//!  \brief 构造相关SQL语句
	static UGString GetCreateSmRegisterSql();
	static UGString GetCreateSmImgRegisterSql();
	static UGString GetCreateSmMetaDataSql();
	static UGString GetCreateSmDataSourceInfoSql();
	static UGString GetCreateSmUsersSql();
	static UGString GetCreateSmSmLogSql();
	static UGString GetCreateSmFieldInfoSql();
	static UGString GetCreateSmMaxIDsSql();
	static UGString GetCreateSmActionSql();
	static UGString GetCreateSmAuthentSql();
	static UGString GetCreateSmVectorMetaTableSql();
	static UGString GetCreateSmRasterMetaTableSql();
	static UGString GetCrteateSmMetaElementTableSql();

	static UGString GetCreateProcedureGetMaxIDSql();

	static UGString GetCreateSmSequenceSql();

	static UGString GetCreataSmDatasetLockedSql();

	static UGString GetCreateSmTopoRuleSql();
	static UGString GetCreateSmTopoRelationSql();

	static UGString GetCreateSmDynamicIndexSql();
	static UGString GetTableIsExistSql(UGString strTableName);

	//! brief metadata相关SQL语句
	static UGString GetCreateSmMetaDSRegister();
	static UGString GetCreateSmMetaTemplate();
	static UGString GetCreateSmMetaMapping(UGint nID);
	static UGString GetCreateSmMetaVector(UGint nID);
	static UGString GetCreateSmMetaRaster(UGint nID);
	static UGString GetCreateSmMetaVectorRegister(UGint nID);	
	static UGString GetCreateSmMetaRasterRegister(UGint nID);

	//创建Tin数据集
	static UGString GetCreateTinSql(UGString &strName);

};

}
#endif // !defined(AFX_UGSQLHELPER_H__E9B5E982_165B_46A0_B4DB_65A4CBAE1557__INCLUDED_)
