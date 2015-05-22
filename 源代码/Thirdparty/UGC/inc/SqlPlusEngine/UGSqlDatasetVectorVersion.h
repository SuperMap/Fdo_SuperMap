// UGSqlDatasetVectorVersion.h: interface for the UGSqlDatasetVectorVersion class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGSQLDATASETVECTORVERSION_H__63D4CC6F_6AF4_430A_A2C0_5E1E8618752B__INCLUDED_)
#define AFX_UGSQLDATASETVECTORVERSION_H__63D4CC6F_6AF4_430A_A2C0_5E1E8618752B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Base/ugdefs.h"
#include "ODBCEngine/UGODBCSpatialIndex.h"
#include "SqlPlusEngine/UGSqlDatasetVector.h"
namespace UGC{

class SQLENGINE_API UGSqlDatasetVectorVersion  
{
public:
	UGSqlDatasetVectorVersion();
	UGSqlDatasetVectorVersion(UGSqlDatasetVector *pSqlDatasetVector);
	virtual ~UGSqlDatasetVectorVersion();

public:

	//! \brief 注册版本
	UGbool RegisterOption(UGint nOption);
	//! \brief 注销版本
	UGbool UnRegisterOption(UGint nOption);

	//! \brief 版本提交管理
	// param　strVersion　		版本
	// param　nPostOption		冲突解决方式
	// param　CheckConfilcts	记录发生的冲突
	UGbool PostToMainVersion(UGString strVersion,
					UGPostOption nPostOption,
					UGArray<UGCheckConflict> &CheckConfilcts);	

	//! \brief 版本提交管理
	// param　strVersion　		版本号
	// param　nPostOption		冲突解决方式
	// param　CheckConfilcts	记录发生的冲突
	UGbool PostToMainVersion(UGint nVersionID,
					UGPostOption nPostOption,
					UGArray<UGCheckConflict> &CheckConfilcts);

	UGbool PostToMainVersion(UGint nVersionID,
					UGint nDataID,
					UGPostOption nPostOption);


	//! \brief 版本回滚
	// param　strVersion　		版本号
	UGbool RollBackVersion(UGint nVersion);
	
	//! \brief 创建视图
	UGbool U_FillExtInfos(UGint nVersionID);
	
	//! \brief 数据源删除版本时调用
	UGbool U_DeleteVersion(UGint nVersion);


	//! \brief 版本提交
	//! \brief 检查是否有冲突
	// param　nVersionID　版本号　[in]
	UGbool U_CheckConflict(UGint nVersionID);

	//! \brief 返回冲突的数据
	// param　nVersionID　版本号　[in]
	// param　CheckConfilcts　记录冲突的数组[out]
	UGbool U_ExtractConflicts(UGint nVersionID, UGArray<UGCheckConflict> &CheckConfilcts);

	//! \brief 按照已经提交的版本解决冲突
	// param　nVersionID　版本号　[in]
	UGbool U_PostToMainVersionPrev(UGint nVersionID);
	//! \brief 合并解决冲突
	// param　nVersionID　版本号　[in]
	UGbool U_PostToMainVersionUnion(UGint nVersionID);
	//! \brief 按照当前提交的版本解决冲突
	// param　nVersionID　版本号　[in]
	UGbool U_PostToMainVersionLast(UGint nVersionID);

	//! \brief 合并解决冲突
	// param　CheckConfilcts　记录冲突的数组[in]
	UGbool U_UnionConflict(UGCheckConflict & Checkconflict);

	//! \brief 将A表数据追加到主表同时处理索引
	// param　nVersionID　版本号　[in]
	UGbool U_CopyDataByVersion(UGint nVersionID);

	//! \brief 版本数据集提交时对Delete,SetGeometry编辑操作索引的处理
	// param　nVersionID　版本号　[in]
	//
	/*/
		Delete：		直接从索引表中删除
		SetGeometry:	先从索引表中删除，然后通过A表再添加到索引表
	/*/
	UGbool U_PostDisposeIndex(UGint nVersionID);

protected:
	UGSqlDatasetVector *m_pSqlDatasetVector;

};

}

#endif // !defined(AFX_UGSQLDATASETVECTORVERSION_H__63D4CC6F_6AF4_430A_A2C0_5E1E8618752B__INCLUDED_)
