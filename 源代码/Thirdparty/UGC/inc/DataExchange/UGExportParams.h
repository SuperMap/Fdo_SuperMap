
/*!
    **************************************************************************************
     \file     UGExportParams.h
    **************************************************************************************
     \author   艾国
     \brief    数据转换参数导出类           
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


#if !defined(AFX_UGEXPORTPARAMS_H__473310EF_0EE1_4989_8F7C_8D1D9BC4F71F__INCLUDED_)
#define AFX_UGEXPORTPARAMS_H__473310EF_0EE1_4989_8F7C_8D1D9BC4F71F__INCLUDED_


#include "UGExchangeParams.h"

namespace UGC {


struct  UGDgnUnits
{
	//! \brief	一个Main Unit等于多少个Sub Unit
	UGint	m_nSuPerMu;  
	//! \brief	一个Sub Unit等于多少个Pos Unit
	UGint	 m_nPosPerSu; 
	//! \brief	主单位的名字
	UGString m_strMuName; 
	//! \brief	从单位的名字
	UGString m_strSuName; 

	UGDgnUnits()
	{
		m_nSuPerMu = 1000;
		m_nPosPerSu = 1000;
		m_strMuName = ("m");
		m_strSuName = ("mm");
	}
	UGDgnUnits(const UGDgnUnits& dgnUnits)
	{
		m_nSuPerMu = dgnUnits.m_nSuPerMu;
		m_nPosPerSu = dgnUnits.m_nPosPerSu;
		m_strMuName = dgnUnits.m_strMuName;
		m_strSuName = dgnUnits.m_strSuName;
	}
	void operator =(const UGDgnUnits &dgnUnits)
	{
		m_nSuPerMu = dgnUnits.m_nSuPerMu;
		m_nPosPerSu = dgnUnits.m_nPosPerSu;
		m_strMuName = dgnUnits.m_strMuName;
		m_strSuName = dgnUnits.m_strSuName;
	}
}; 



class DATAEXCHANGE_API UGExportParams : public UGExchangeParams  
{
public:
	UGExportParams();
	virtual ~UGExportParams();

public:
	void SetDatasetName(const UGString& strDatasetName);
	UGString GetDatasetName() const;

	void SetVersion(UGint nVersion);
	UGint GetVersion() const;

	void SetDgnUnits(const UGDgnUnits& dgnUnits);
	UGDgnUnits GetDgnUnits() const;

	void SetDgnUnitsSelected(UGint nDgnUnitsSelected);
	UGint GetDgnUnitsSelected() const;

protected:


	//! \brief 	导出数据集的名字 
	UGString m_strDatasetName;
	
	//! \brief	用一个整型变量来设置导出文件格式是什么类型，其值应该是一些枚举型
	UGint m_nVersion;
	
	//! \brief 	Dgn的坐标单位
	UGDgnUnits m_dgnUnits; 

	//! \brief 	说明这个单位m_nDesUnits是作为dgn单位的哪一个(dgn有三个单位)
	UGint m_nDgnUnitsSelected; 


};


}


#endif // !defined(AFX_UGEXPORTPARAMS_H__473310EF_0EE1_4989_8F7C_8D1D9BC4F71F__INCLUDED_)
