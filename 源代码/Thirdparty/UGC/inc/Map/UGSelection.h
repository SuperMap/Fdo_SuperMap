// UGSelection.h: interface for the UGSelection class.
//
//////////////////////////////////////////////////////////////////////

/*!
   **************************************************************************************
    \file     UGSelection.h
   **************************************************************************************
    \author   陈国雄
    \brief    选择集合类                                                             
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2005 SuperMap GIS Technologies,Inc.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-05-20  陈国雄    初始化版本.                                       <br>
   **************************************************************************************
*/

#if !defined(AFX_UGSELECTION_H__2FBE2AA1_B3D6_469E_854F_CC6E86B762D0__INCLUDED_)
#define AFX_UGSELECTION_H__2FBE2AA1_B3D6_469E_854F_CC6E86B762D0__INCLUDED_

#include "Engine/UGDataSource.h"
#include "Drawing/UGDrawing.h"

namespace UGC {

class MAP_API UGSelection  
{
public:
	UGSelection();
	virtual ~UGSelection();

public:
	void SetReserveRs(UGRecordset* pRecordset, UGbool bAutoRelease = false);   
	UGRecordset* GetReservedRs()const;  
	UGbool FromRecordset(UGRecordset* pRecordset);
	UGRecordset* ToRecordset(UGbool bGeometryOnly = true,UGRect2D rcBounds = UGRect2D(0,0,0,0) )const;

	UGint FindID(UGint nID, UGint nSearchCount = 0) const;

	UGint Add(UGuint unID);
	UGint RemoveAt(UGint nIndex, UGint nCount = 1);
	void InsertAt(UGint nIndex, UGuint unID);
	void SetAt(UGint nIndex, UGuint unID);
	UGuint GetAt(UGint nIndex)const;
	void RemoveAll();
	UGuint* GetData();
	UGint Append(UGArray<UGuint>& arrIDs);
	void Copy(UGArray<UGuint>& arrIDs);

	void SetSize(UGint nSize);
	UGint GetSize()const;
	UGbool IsEmpty()const;

	UGbool Hignlight(UGGraphics* pGraphics, UGDrawing *pDrawing);
	
	UGbool HasCustomStyle()const;
	void SetCustomStyle(UGbool bCustomStyle = false); 
	
	void SetControlSelectLevel(UGint nControlSelectLevel);
	UGint GetControlSelectLevel()const;
	
	void SetStyle(const UGStyle& style);
	const UGStyle& GetStyle()const;
	
	void SetDatasetVector(UGDatasetVector* pDatasetVector);
	UGDatasetVector* GetDatasetVector()const;

protected:
	UGDatasetVector* m_pDatasetVector;
	UGRecordset *m_pReserveRs;   // 用于将取得的记录集保留

	UGbool m_bCustomStyle;		   //默认为False, 即用户没有设置选择集风格,
	UGbool m_bAutoReleaseRs;         //是否自动释放数据集，如果此数据集是外面传入的则不需要自动
	UGint m_nControlSelectLevel;
	
	UGStyle m_Style;
	UGArray<UGuint> m_arrIDs;

};

}

#endif // !defined(AFX_UGSELECTION_H__2FBE2AA1_B3D6_469E_854F_CC6E86B762D0__INCLUDED_)
