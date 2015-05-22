// UGSceneStorage.h: interface for the UGSceneStorage class.
//
//////////////////////////////////////////////////////////////////////

/*!
   **************************************************************************************
    \file     UGSceneStorage.h
   **************************************************************************************
    \author   陈国雄
    \brief    三维场景XML字符串存储类。                                          
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2005 SuperMap GIS Technologies,Inc.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-05-19  陈国雄    初始化版本.                                       <br>
   **************************************************************************************
*/

#if !defined(AFX_UGSCENESTORAGE_H__83180122_F19C_4C57_9AC2_41C962B884B8__INCLUDED_)
#define AFX_UGSCENESTORAGE_H__83180122_F19C_4C57_9AC2_41C962B884B8__INCLUDED_

#include "Base/UGString.h"

namespace UGC {

class WORKSPACE_API UGSceneStorage  
{
public:
	UGSceneStorage();
	virtual ~UGSceneStorage();
	UGSceneStorage& operator = (const UGSceneStorage& storage);

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
	//! \brief 		得到三维场景名称。
	UGString GetName()const;
	//========================================================
	//! \brief 		设置三维场景名称。
	void SetName(const UGString& strName);
	//========================================================
	//! \brief 		得到三维场景信息XML字符串。
	UGString GetXML()const;
	//========================================================
	//! \brief 		设置三维场景信息XML字符串。
	void SetXML(const UGString& strXML, UGint nVersion = 0);
	//========================================================
	//! \brief 		得到地图版本。
	UGint GetVersion()const;

protected:
	//! \brief 		修改标识。
	UGbool m_bModified;
	//! \brief 		三维场景信息XML字符串。
	UGString m_strXML;
	//! \brief 		三维场景名称。
	UGString m_strName;
	//! \brief 		三维场景版本。
	UGint m_nVersion;

};

}

#endif // !defined(AFX_UGSCENESTORAGE_H__83180122_F19C_4C57_9AC2_41C962B884B8__INCLUDED_)
