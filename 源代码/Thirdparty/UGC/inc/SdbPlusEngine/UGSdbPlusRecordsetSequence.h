// SdbRecordsetSequence.h: interface for the UGSdbPlusRecordsetSequence class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SDBRECORDSETSEQUENCE_H__9EB3CDB9_C0D4_4F9B_8565_421CD9672C33__INCLUDED_)
#define AFX_SDBRECORDSETSEQUENCE_H__9EB3CDB9_C0D4_4F9B_8565_421CD9672C33__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Base/UGDict.h"
#include "UGSdbPlusRecordset.h"

namespace UGC
{

//edit sequence dataset is not the same with other.
class UGSdbPlusRecordsetSequence  : public UGSdbPlusRecordset
{
public:
	UGSdbPlusRecordsetSequence();
	UGSdbPlusRecordsetSequence(UGSdbPlusDatasetVector *pDataset);
	virtual ~UGSdbPlusRecordsetSequence();

public:
	virtual UGint AddNew(UGGeometry *pGeometry,UGbool bReturnID=FALSE);	//增加新记录,成功，返回非0值，参数bReturnID=true,返回对象ID号；失败，返回-1。如果失败，则不能调用Update和CancelUpdate.
	virtual UGbool Edit();	//SetXXX前需要设置Edit状态
	virtual UGint Update();	//Addnew或SetXXX更新,注意空间数据update前不可删除
	virtual UGbool CancelUpdate();//取消Update
	virtual UGbool Delete();	//记录删除
	virtual UGbool DeleteAll();		//删除所有的记录
	virtual void FlushCurrentRecord();	//记录刷新
	virtual UGbool Refresh();			//刷新记录集
	virtual UGbool SetGeometry(UGGeometry &geometry);	//set geometry
protected:
	UGDict<UGint,UGVariant> m_FieldValues; //编辑记录的各个属性值，不包含系统字段
};

}
#endif // !defined(AFX_SDBRECORDSETSEQUENCE_H__9EB3CDB9_C0D4_4F9B_8565_421CD9672C33__INCLUDED_)
