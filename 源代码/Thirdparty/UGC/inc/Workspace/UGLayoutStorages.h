// UGLayoutStorages.h: interface for the UGLayoutStorages class.
//
//////////////////////////////////////////////////////////////////////

/*!
   **************************************************************************************
    \file     UGLayoutStorages.h
   **************************************************************************************
    \author   陈国雄
    \brief    布局集合管理类，通过布局XML存储指针与布局名称的一一对应关系进行管理，
			  并保证布局名称的唯一性。                                                              
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2005 SuperMap GIS Technologies,Inc.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-05-19  陈国雄    初始化版本.                                       <br>
   **************************************************************************************
*/

#if !defined(AFX_UGLAYOUTSTORAGES_H__E2F7C6E2_0990_4741_B37D_86155AD90D67__INCLUDED_)
#define AFX_UGLAYOUTSTORAGES_H__E2F7C6E2_0990_4741_B37D_86155AD90D67__INCLUDED_

#include "UGLayoutStorage.h"
#include "Base/UGDict.h"

namespace UGC {

class WORKSPACE_API UGLayoutStorages  
{
public:
	UGLayoutStorages();
	virtual ~UGLayoutStorages();

public:	
	//========================================================
	//! \brief 		得到不被占用的布局名，如果传入的布局名不存在就用传入的布局名，否则就推荐一个不被占用的布局名。
	//! \return 	UGString 返回不被占用的布局名。
	//! \param 		strName 希望的布局名。
	UGString GetUnoccupiedLytName(const UGString& strName);
	//========================================================
	//! \brief 		判断是否有修改，包括任一成员的修改。
	//! \return 	UGbool 如果有修改就返回true，否则就返回false。
	UGbool IsModified()const;
	//========================================================
	//! \brief 		设置修改标识，不仅对自己起作用，而且对所有有修改标识的成员都起作用。
	void SetModifiedFlag(UGbool bModified = true);

	//========================================================
	//! \brief 		得到指定索引的布局名称。
	//! \return 	UGString 返回布局名称。
	//! \param 		nIndex 索引位置，必须大于等于0，小于最大数。
	UGString GetNameAt(UGint nIndex)const;
	//========================================================
	//! \brief 		得到指定索引的布局存储对象指针。
	//! \return 	UGLayoutStorage 如果存在就返回布局存储对象指针，否则就返回NULL。
	//! \param 		nIndex 索引位置，必须大于等于0，小于最大数。
	UGLayoutStorage * GetLayoutAt(UGint nIndex)const;

	//========================================================
	//! \brief 		移走并删除指定布局名称的布局存储对象。
	//! \return 	UGbool 如果成功就返回true，否则就返回false。
	//! \param 		strName 布局名称
	UGbool Remove(const UGString &strName);
	//========================================================
	//! \brief 		移走并删除指定索引的布局存储对象。
	//! \return 	UGint 真正删除布局存储对象的数目，如果没有删除旧返回-1。
	//! \param 		nIndex 起始索引，必须大于等于0，小于最大数。
	//! \param 		nCount 起始索引开始，需要删除布局存储对象的数目。
	UGint Remove(UGint nIndex, UGint nCount = 1);
	//========================================================
	//! \brief 		清空并删除所有布局存储对象。
	void RemoveAll();
	//========================================================
	//! \brief 		克隆一个指定名称的布局存储对象。
	//! \return 	UGbool 如果成功就返回true，否则就返回false。
	//! \param 		strOldName 被克隆的布局存储对象的名称。
	//! \param 		strNewName 克隆结果布局存储对象的名称。
	UGbool CloneLayout(const UGString &strOldName, const UGString &strNewName);

	//========================================================
	//! \brief 		重命名布局名称。
	//! \return 	UGbool 如果旧的布局名称存在，并且新的布局名称没有被占用就返回true，否则就返回false。
	//! \param 		strOldName 旧的布局名称。
	//! \param 		strNewName 新的布局名称。
	UGbool Rename(const UGString &strOldName, const UGString &strNewName);
	//========================================================
	//! \brief 		查找指定名称的布局存储对象。
	//! \return 	UGLayoutStorage* 如果成功就布局存储对象，否则返回NULL。
	//! \param 		strName 布局名称。
	UGLayoutStorage* Find(const UGString &strName) const;
	//========================================================
	//! \brief 		创建一个指定名称的布局存储对象。
	//! \return 	UGbool 如果布局名称没有被占用并成功创建布局存储对象就返回true，否则就返回false。
	//! \param 		strName 布局名称。
	UGbool Add(const UGString &strName);

	//========================================================
	//! \brief 		从布局文件导入布局信息，构造并打开布局。
	//! \return 	UGbool 如果成功就返回true，否则就返回false。
	//! \param 		strFileName 布局文件全路径名。
	UGbool LoadFromFile(const UGString &strFileName);
	//========================================================
	//! \brief 		把布局信息保存为布局文件，如果文件存在就覆盖他。
	//! \return 	UGbool 如果成功就返回true，否则就返回false。
	//! \param 		strFileName 布局文件全路径名。
	UGbool SaveToFile(const UGString &strFileName)const;

	//========================================================
	//! \brief 		设置修改指定布局名称的布局存储对象指针，如果布局名称不存在就新增一个布局存储对象。
	//! \return 	void
	//! \param 		strName 布局名称，不能为空字符串。
	//! \param 		pLytStorage 布局存储对象指针。
	void SetAt(const UGString &strName, UGLayoutStorage* pLytStorage);
	//========================================================
	//! \brief 		得到指定索引的布局名称和布局存储对象指针。
	//! \return 	UGbool 如果找到就返回true，否则就返回false。
	//! \param 		nIndex 索引位置，必须大于等于0，小于最大数。
	//! \param 		strName 返回布局名称。
	//! \param 		pLytStorage 返回布局存储对象指针。
	UGbool GetAt(UGint nIndex, UGString &strName, UGLayoutStorage *&pLytStorage);
	//========================================================
	//! \brief 		查找指定名称的布局存储对象。
	//! \return 	UGbool 如果找到就返回true，否则就返回false。
	//! \param 		strName 布局名称。
	//! \param 		pLytStorage 返回布局存储对象指针。
	UGbool Lookup (const UGString &strName, UGLayoutStorage* &pLytStorage) const;

	//========================================================
	//! \brief 		重新设置，相当于RemoveAll()。
	void Reset();	
	//========================================================
	//! \brief 		得到布局存储对象数目。
	UGint GetCount()const;
	//========================================================
	//! \brief 		是否没有布局存储对象，如果没有就为true，否则就为false。
	UGbool IsEmpty()const;
	
	//========================================================
	//! \brief 		解析包含布局文件路径信息的XML字符串，构造并打开布局集合。
	//! \return 	UGbool 如果成功就返回true，否则就返回false。
	//! \param 		strXML 包含布局文件路径信息的XML字符串。
	//! \param 		strWorkspaceName 工作空间全路径名。
	//! \param 		nVersion 工作空间版本
	UGbool FromXML(const UGString &strXML, const UGString &strWorkspaceName, UGint nVersion = 0);
	//========================================================
	//! \brief 		把布局文件路径信息保存未XML字符串。
	//! \return 	UGString 返回包含布局文件路径信息的XML字符串，如果不成功就返回空字符串。
	//! \param 		strWorkspaceName 工作空间全路径名。
	//! \param 		nVersion 工作空间版本
	UGString ToXML(const UGString &strWorkspaceName, UGint nVersion = 0)const;
	
	UGbool Load(UGStream& stream);	
	UGbool Save(UGStream& stream, UGuint nVersion = 0) const;

protected:
	//! \brief 		修改标识。
	UGbool m_bModified;
	//! \brief 		布局存储对象集合。
	UGDict<UGString, UGLayoutStorage*> m_LayoutStorages;
	//! \brief 		布局名称集合。
	UGArray<UGString>  m_strArrNames;

};

}

#endif // !defined(AFX_UGLAYOUTSTORAGES_H__E2F7C6E2_0990_4741_B37D_86155AD90D67__INCLUDED_)
