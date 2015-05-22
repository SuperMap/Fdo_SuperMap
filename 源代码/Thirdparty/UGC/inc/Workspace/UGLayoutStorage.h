// UGLayoutStorage.h: interface for the UGLayoutStorage class.
//
//////////////////////////////////////////////////////////////////////

/*!
   **************************************************************************************
    \file     UGLayoutStorage.h
   **************************************************************************************
    \author   陈国雄
    \brief    布局二进制存储类。                                                       
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2005 SuperMap GIS Technologies,Inc.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-05-19  陈国雄    初始化版本.                                       <br>
   **************************************************************************************
*/

#if !defined(AFX_UGLAYOUTSTORAGE_H__3514CA02_9B5F_4C46_937B_79CF456279A8__INCLUDED_)
#define AFX_UGLAYOUTSTORAGE_H__3514CA02_9B5F_4C46_937B_79CF456279A8__INCLUDED_

#include "Base/UGString.h"
#include "Base/UGStream.h"

namespace UGC {

class WORKSPACE_API UGLayoutStorage  
{
public:
	UGLayoutStorage();
	virtual ~UGLayoutStorage();
	UGLayoutStorage& operator = (const UGLayoutStorage& storage);

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
	//! \brief 		设置布局名称。
	//! \return 	void
	//! \param 		strName 布局名称，不能为空字符串。
	void SetName(const UGString& strName);
	//========================================================
	//! \brief 		得到布局名称。
	//! \return 	UGString 返回布局名称。
	UGString GetName()const;

	//========================================================
	//! \brief 		导入布局。
	//! \return 	UGbool
	//! \param 		pData
	//! \param 		nSize 内存块字节大小。
	UGbool Load(const UGuchar* pData, UGint nSize);
	//========================================================
	//! \brief 		保存布局。
	//! \return 	UGbool
	//! \param 		pData 外面先分配好内存
	//! \param 		nSize 内存块字节大小。
	UGbool Save(UGuchar* pData, UGint nSize) const;
	//========================================================
	//! \brief 		得到布局内存块的字节大小。
	//! \return 	UGuint
	UGuint GetSize()const;
	//========================================================
	//! \brief 		得到布局内存块指针。
	//! \return 	UGuchar*
	const UGuchar* GetData() const;

protected:
	//! \brief 		修改标识。
	UGbool m_bModified;
	//! \brief 		布局信息内存块。
	UGArray<UGuchar> m_LytData;	
	//! \brief 		布局名称。
	UGString m_strName;

};

}

#endif // !defined(AFX_UGLAYOUTSTORAGE_H__3514CA02_9B5F_4C46_937B_79CF456279A8__INCLUDED_)
