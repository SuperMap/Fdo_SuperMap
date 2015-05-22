// UGMapStorage.h: interface for the UGMapStorage class.
//
//////////////////////////////////////////////////////////////////////

/*!
   **************************************************************************************
    \file     UGMapStorage.h
   **************************************************************************************
    \author   陈国雄
    \brief    地图XML字符串存储类。                                                
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2005 SuperMap GIS Technologies,Inc.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-05-19  陈国雄    初始化版本.                                       <br>
   **************************************************************************************
*/

#if !defined(AFX_UGMAPSTORAGE_H__B6B3D6D1_559F_467A_9AB4_C71F05D08EF1__INCLUDED_)
#define AFX_UGMAPSTORAGE_H__B6B3D6D1_559F_467A_9AB4_C71F05D08EF1__INCLUDED_

#include "Base/UGString.h"

namespace UGC {
class WORKSPACE_API UGMapStorage  
{
public:
	UGMapStorage();
	virtual ~UGMapStorage();
	UGMapStorage& operator = (const UGMapStorage& storage);

public:
	//========================================================
	//! \brief 		设置修改标识。
	//! \return 	void
	//! \param 		bModified 修改标识。
	void SetModifiedFlag(UGbool bModified = true);
	//========================================================
	//! \brief 		判断是否有修改。
	//! \return 	UGbool 如果有修改就返回true，否则就返回false。
	UGbool IsModified()const;

	//========================================================
	//! \brief 		得到地图名称。
	UGString GetName()const;
	//========================================================
	//! \brief 		设置地图名称。
	void SetName(const UGString& strName);
	//========================================================
	//! \brief 		得到地图信息XML字符串。
	UGString GetXML()const;
	//========================================================
	//! \brief 		设置地图信息XML字符串。
	void SetXML(const UGString& strXML, UGint nVersion = 0);
	//========================================================
	//! \brief 		得到地图版本。
	UGint GetVersion()const;
	
protected:
	//! \brief 		修改标识。
	UGbool m_bModified;
	//! \brief 		地图信息XML字符串。
	UGString m_strXML;
	//! \brief 		地图名称。
	UGString m_strName;
	//! \brief 		地图版本。
	UGint m_nVersion;
};

}

#endif // !defined(AFX_UGMAPSTORAGE_H__B6B3D6D1_559F_467A_9AB4_C71F05D08EF1__INCLUDED_)
