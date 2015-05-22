// UGOrcDatasetVectorVersion.h: interface for the UGOrcDatasetVectorVersion class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGORCDATASETVECTORVERSION_H__FEBA9AFA_9A12_42EB_AE9D_14A9481A5D5C__INCLUDED_)
#define AFX_UGORCDATASETVECTORVERSION_H__FEBA9AFA_9A12_42EB_AE9D_14A9481A5D5C__INCLUDED_


#include "Base/ugdefs.h"	// Added by ClassView
#include "OrcEngine/UGOrcDatasetVector.h"
#include "UGOCIConnection.h"
namespace UGC{

class ORCENGINE_API UGOrcDatasetVectorVersion
{
public:
	UGOrcDatasetVectorVersion();
	UGOrcDatasetVectorVersion(UGOrcDatasetVector *pOrcDatasetVector);
	virtual ~UGOrcDatasetVectorVersion();

public:
	//! 注册选项信息
	virtual UGbool RegisterOption(UGint nOption);

	UGbool UnRegisterOptionDataVersion();

	UGbool PostToMainVersion(UGString strVersion,
					UGPostOption nPostOption,
					UGArray<UGCheckConflict> &CheckConfilcts);	

	UGbool PostToMainVersion(UGint nVersionID,
					UGPostOption nPostOption,
					UGArray<UGCheckConflict> &CheckConfilcts);

	UGbool PostToMainVersion(UGint nVersionID,
					UGint nDataID,
					UGPostOption nPostOption);


	UGbool RollBackVersion(UGint nVersion);


	UGbool U_FillExtInfos(UGint nVersionID);

	//数据源删除版本时调用
	UGbool U_DeleteVersion(UGint nVersion);

protected:
	//检查是否有冲突
	UGbool U_CheckConflict(UGint nVersionID);

	//返回冲突的数据
	UGbool U_ExtractConflicts(UGint nVersionID, UGArray<UGCheckConflict> &CheckConfilcts);

	//解决冲突
	UGbool U_PostToMainVersionPrev(UGint nVersionID);
	//解决冲突
	UGbool U_PostToMainVersionUnion(UGint nVersionID);
	//强制干活
	UGbool U_PostToMainVersionLast(UGint nVersionID);

	UGbool U_UnionConflict(UGCheckConflict & Checkconflict);

	UGbool U_CopyDataByVersionAndID(UGint nDataVersionID,UGint nDataID);

	UGbool U_CopyDataByVersion(UGint nVersionID);

	UGbool U_ExtractConflict(UGint nVersionID,UGint nDataID,UGCheckConflict &nCheckConflict);

	//索引的处理，如果是图幅索引，则在提交版本的时候更新
	UGbool U_UpdateIndex(UGint nVersionID);
	
protected:
	UGOrcDatasetVector *m_pOrcDatasetVector;
	
};

}

#endif // !defined(AFX_UGORCDATASETVECTORVERSION_H__FEBA9AFA_9A12_42EB_AE9D_14A9481A5D5C__INCLUDED_)
