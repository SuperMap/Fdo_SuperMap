// UGVectorDatasetAtr.h: interface for the UGVectorDatasetAtr class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGDatasetATR_H__A72DF377_91FE_468C_A315_A3C11FCB092B__INCLUDED_)
#define AFX_UGDatasetATR_H__A72DF377_91FE_468C_A315_A3C11FCB092B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Scene/UGPrerequisites.h"
#include "Base/UGTextStyle.h"
#include "Scene/UGColorValue.h"
namespace UGC
{
enum HeightStyle
{
	HS_FILED,
	HS_CONSTANT,
	HS_TERRAIN
};
class UGDataset;
class SCENE_API UGVectorDatasetAtr
{
public:
	UGVectorDatasetAtr(const UGString& strName="",UGDataset* pDataset=NULL,const UGString& strDataIndexFilePath="",
		const UGString& strDatasetPath="",HeightStyle enHeightStyle=HS_CONSTANT,UGReal fHeight=0,const UGString& strHeightFiled="");
	virtual ~UGVectorDatasetAtr();
	UGString    GetName()const;
	UGDataset*  GetDataset()const;
	UGString    GetDatasetPath()const;
	UGString    GetDataIndexFilePath()const;
	HeightStyle GetHeightStyle()const;
	UGReal		GetHeight()const;
	UGString	GetHeightField()const;
	UGbool		IsDataChanged()const;
	

	void	    SetName(const UGString& strName);
	void		SetDataset(UGDataset* pDataset);
	void		SetDatasetPath(const UGString& strDataPath);
	void		SetDataIndexFilePath(const UGString& strDataIndexFilePath);
	void		SetHeightStyle(HeightStyle enHightStyle);
	void		SetHeight(UGReal fHeight);
	void		SetHeightField(const UGString& strHeightField);
	void		SetDataChanged(UGbool bChanged);
	
private:
	UGString m_strName;
	
	UGString m_strDatasetPath;
	UGString m_strDataIndexFilePath;
	UGDataset* m_pDataset;
	HeightStyle m_enHeightStyle;
	// 对高程是字段的，记录下字段
	UGString m_strHeightFiled;
	// 对高程是常数的，记录下常数
	UGReal	 m_fHeight;
};
}
#endif // !defined(AFX_UGDatasetATR_H__A72DF377_91FE_468C_A315_A3C11FCB092B__INCLUDED_)
