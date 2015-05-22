// UGSceneStorages.h: interface for the UGSceneStorages class.
//
//////////////////////////////////////////////////////////////////////

/*!
   **************************************************************************************
    \file     UGSceneStorages.h
   **************************************************************************************
    \author   陈国雄
    \brief    三维场景集合管理类，通过三维场景XML存储指针与三维场景名称的一一对应关系
			  进行管理，并保证三维场景名称的唯一性。                                                                         
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2005 SuperMap GIS Technologies,Inc.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-05-19  陈国雄    初始化版本.                                       <br>
   **************************************************************************************
*/

#if !defined(AFX_UGSCENESTORAGES_H__9DCDABD7_A8F5_4424_89CF_0EDCF63CDE61__INCLUDED_)
#define AFX_UGSCENESTORAGES_H__9DCDABD7_A8F5_4424_89CF_0EDCF63CDE61__INCLUDED_

#include "UGSceneStorage.h"
#include "Base/UGDict.h"

namespace UGC {

typedef void (*SCENEVERSIONPROC)(UGSceneStorage* pSceneStorage, UGint nVersion);

class WORKSPACE_API UGSceneStorages  
{
public:
	UGSceneStorages();
	virtual ~UGSceneStorages();

public:
	static void SetSceneVersionFunc(SCENEVERSIONPROC pSceneVersionFunc);
	//========================================================
	//! \brief 		得到不被占用的三维场景名，如果传入的三维场景名不存在就用传入的三维场景名，否则就推荐一个不被占用的三维场景名。
	//! \return 	UGString 返回不被占用的三维场景名。
	//! \param 		strName 希望的三维场景名。
	UGString GetUnoccupiedSceneName(const UGString& strName);
	
	//========================================================
	//! \brief 		设置修改标识，不仅对自己起作用，而且对所有有修改标识的成员都起作用。
	void SetModifiedFlag(UGbool bModified = true);
	//========================================================
	//! \brief 		判断是否有修改，包括任一成员的修改。
	//! \return 	UGbool 如果有修改就返回true，否则就返回false。
	UGbool IsModified()const;
	
	//========================================================
	//! \brief 		移走并删除指定三维场景名称的三维场景存储对象。
	//! \return 	UGbool 如果成功就返回true，否则就返回false。
	//! \param 		&strName 三维场景名称
	UGbool Remove(const UGString &strName);
	//========================================================
	//! \brief 		移走并删除指定索引的三维场景存储对象。
	//! \return 	UGint 返回真正删除三维场景存储对象的数目，如果没有删除旧返回-1。
	//! \param 		nIndex 起始索引，必须大于等于0，小于最大数。
	//! \param 		nCount 起始索引开始，需要删除三维场景存储对象的数目。
	UGint Remove(UGint nIndex, UGint nCount = 1);
	//========================================================
	//! \brief 		清空并删除所有三维场景存储对象。
	//! \return 	void
	void RemoveAll();
	//========================================================
	//! \brief 		得到指定索引的三维场景存储对象指针。
	//! \return 	UGSceneStorage* 如果存在就返回三维场景存储对象指针，否则就返回NULL。
	//! \param 		nIndex 索引位置，必须大于等于0，小于最大数。
	UGSceneStorage* GetSceneAt(UGint nIndex)const;
	//========================================================
	//! \brief 		得到指定索引的三维场景名称。
	//! \return 	UGString 返回三维场景名称。
	//! \param 		nIndex 索引位置，必须大于等于0，小于最大数。
	UGString GetNameAt(UGint nIndex)const;

	//========================================================
	//! \brief 		克隆一个指定名称的三维场景存储对象。
	//! \return 	UGbool 如果成功就返回true，否则就返回false。
	//! \param 		&strOldScene 被克隆的三维场景存储对象的名称。
	//! \param 		&strNewScene 克隆结果三维场景存储对象的名称。
	UGbool CloneScene(const UGString &strOldScene, const UGString &strNewScene);
	//========================================================
	//! \brief 		重新设置，相当于RemoveAll()。
	void Reset();

	//========================================================
	//! \brief 		重命名三维场景名称。
	//! \return 	UGbool 如果旧的三维场景名称存在，并且新的三维场景名称没有被占用就返回true，否则就返回false。
	//! \param 		&strOldName 旧的三维场景名称。
	//! \param 		&strNewName 新的三维场景名称。
	UGbool Rename(const UGString &strOldName, const UGString &strNewName);
	//========================================================
	//! \brief 		查找指定名称的三维场景存储对象。
	//! \return 	UGSceneStorage* 如果成功就三维场景存储对象，否则返回NULL。
	//! \param 		&strName 三维场景名称。
	UGSceneStorage* Find(const UGString &strName)const;
	//========================================================
	//! \brief 		创建一个指定名称的三维场景存储对象。
	//! \return 	UGbool 如果三维场景名称没有被占用并成功创建三维场景存储对象就返回true，否则就返回false。
	//! \param 		strName 三维场景名称。
	UGbool Add(const UGString &strName);
	
	//========================================================
	//! \brief 		把三维场景信息保存未XML字符串。
	//! \return 	UGString 返回包含三维场景信息的XML字符串，如果不成功就返回空字符串。
	//! \param 		nVersion 工作空间版本。
	UGString ToXML(UGint nVersion = 0)const;
	//========================================================
	//! \brief 		解析包含三维场景信息的XML字符串，构造三维场景集合。
	//! \return 	UGbool 如果成功就返回true，否则就返回false。
	//! \param 		strXML 包含三维场景信息的XML字符串。
	//! \param 		nVersion 工作空间版本。
	UGbool FromXML(const UGString &strXML, UGint nVersion = 0);

	//========================================================
	//! \brief 		设置修改指定三维场景名称的三维场景存储对象指针，如果三维场景名称不存在就新增一个三维场景存储对象。
	//! \return 	void
	//! \param 		strName 三维场景名称，不能为空字符串。
	//! \param 		pSceneStorage 三维场景存储对象指针。
	void SetAt (const UGString &strName, UGSceneStorage* pSceneStorage);
	//========================================================
	//! \brief 		得到指定索引的三维场景名称和三维场景存储对象指针。
	//! \return 	UGbool 如果找到就返回true，否则就返回false。
	//! \param 		nIndex 索引位置，必须大于等于0，小于最大数。
	//! \param 		strName 返回三维场景名称。
	//! \param 		pSceneStorage 返回三维场景存储对象指针。
	UGbool GetAt (UGint nIndex, UGString &strName, UGSceneStorage *&pSceneStorage);
	//========================================================
	//! \brief 		查找指定名称的三维场景存储对象。
	//! \return 	UGbool 如果找到就返回true，否则就返回false。
	//! \param 		strName 三维场景名称。
	//! \param 		pSceneStorage 返回三维场景存储对象指针。
	UGbool Lookup (const UGString &strName, UGSceneStorage *&pSceneStorage ) const;

	//========================================================
	//! \brief 		得到三维场景存储对象数目。
	UGint GetCount()const;
	//========================================================
	//! \brief 		是否没有三维场景存储对象，如果没有就为true，否则就为false。
	//! \return 	UGbool
	UGbool IsEmpty()const;

protected:
	//! \brief 		修改标识。
	UGbool m_bModified;
	//! \brief 		三维场景存储对象集合。
	UGDict<UGString, UGSceneStorage*> m_SceneStorages;
	//! \brief 		三维场景名称集合。
	UGArray<UGString> m_strArrNames;

	//! \brief 		静态地图版本处理回调函数。
	static SCENEVERSIONPROC m_pSceneVersionFunc;

};

}

#endif // !defined(AFX_UGSCENESTORAGES_H__9DCDABD7_A8F5_4424_89CF_0EDCF63CDE61__INCLUDED_)
