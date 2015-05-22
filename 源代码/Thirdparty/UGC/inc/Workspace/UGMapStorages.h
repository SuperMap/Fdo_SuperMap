// UGMapStorages.h: interface for the UGMapStorages class.
//
//////////////////////////////////////////////////////////////////////

/*!
   **************************************************************************************
    \file     UGMapStorages.h
   **************************************************************************************
    \author   陈国雄
    \brief    地图集合管理类，通过地图XML存储指针与地图名称的一一对应关系进行管理，
			  并保证地图名称的唯一性。                                                   
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2005 SuperMap GIS Technologies,Inc.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-05-19  陈国雄    初始化版本.                                       <br>
   **************************************************************************************
*/

#if !defined(AFX_UGMAPSTORAGES_H__5F39D6B3_F5CA_48E7_84A0_A1CC4EFA93CD__INCLUDED_)
#define AFX_UGMAPSTORAGES_H__5F39D6B3_F5CA_48E7_84A0_A1CC4EFA93CD__INCLUDED_

#include "UGMapStorage.h"
#include "Base/UGDict.h"

namespace UGC {
	
	class UGWorkspace;
typedef void (*MAPVERSIONPROC)(UGMapStorage* pMapStorage, UGint nVersion, UGWorkspace* pWorkspace);

class WORKSPACE_API UGMapStorages  
{
public:
	UGMapStorages();
	virtual ~UGMapStorages();

public:
	static void SetMapVersionFunc(MAPVERSIONPROC pMapVersionFunc);
	//========================================================
	//! \brief 		得到不被占用的地图名，如果传入的地图名不存在就用传入的地图名，否则就推荐一个不被占用的地图名。
	//! \return 	UGString 返回不被占用的地图名。
	//! \param 		strName 希望的地图名。
	UGString GetUnoccupiedMapName(const UGString& strName);

	//========================================================
	//! \brief 		设置修改标识，不仅对自己起作用，而且对所有有修改标识的成员都起作用。
	void SetModifiedFlag(UGbool bModified = true);
	//========================================================
	//! \brief 		判断是否有修改，包括任一成员的修改。
	//! \return 	UGbool 如果有修改就返回true，否则就返回false。
	UGbool IsModified()const;

	//========================================================
	//! \brief 		移走并删除指定地图名称的地图存储对象。
	//! \return 	UGbool 如果成功就返回true，否则就返回false。
	//! \param 		&strName 地图名称
	UGbool Remove(const UGString &strName);
	//========================================================
	//! \brief 		移走并删除指定索引的地图存储对象。
	//! \return 	UGint 返回真正删除地图存储对象的数目，如果没有删除旧返回-1。
	//! \param 		nIndex 起始索引，必须大于等于0，小于最大数。
	//! \param 		nCount 起始索引开始，需要删除地图存储对象的数目。
	UGint Remove(UGint nIndex, UGint nCount = 1);
	//========================================================
	//! \brief 		清空并删除所有地图存储对象。
	//! \return 	void
	void RemoveAll();
	//========================================================
	//! \brief 		得到指定索引的地图存储对象指针。
	//! \return 	UGMapStorage* 如果存在就返回地图存储对象指针，否则就返回NULL。
	//! \param 		nIndex 索引位置，必须大于等于0，小于最大数。
	UGMapStorage* GetMapAt(UGint nIndex)const;
	//========================================================
	//! \brief 		得到指定索引的地图名称。
	//! \return 	UGString 返回地图名称。
	//! \param 		nIndex 索引位置，必须大于等于0，小于最大数。
	UGString GetNameAt(UGint nIndex)const;

	//========================================================
	//! \brief 		克隆一个指定名称的地图存储对象。
	//! \return 	UGbool 如果成功就返回true，否则就返回false。
	//! \param 		&strOldMap 被克隆的地图存储对象的名称。
	//! \param 		&strNewMap 克隆结果地图存储对象的名称。
	UGbool CloneMap(const UGString &strOldMap, const UGString &strNewMap);
	//========================================================
	//! \brief 		重新设置，相当于RemoveAll()。
	void Reset();

	//========================================================
	//! \brief 		重命名地图名称。
	//! \return 	UGbool 如果旧的地图名称存在，并且新的地图名称没有被占用就返回true，否则就返回false。
	//! \param 		&strOldName 旧的地图名称。
	//! \param 		&strNewName 新的地图名称。
	UGbool Rename(const UGString &strOldName, const UGString &strNewName);
	//========================================================
	//! \brief 		查找指定名称的地图存储对象。
	//! \return 	UGMapStorage* 如果成功就地图存储对象，否则返回NULL。
	//! \param 		&strName 地图名称。
	UGMapStorage* Find(const UGString &strName) const;
	//========================================================
	//! \brief 		创建一个指定名称的地图存储对象。
	//! \return 	UGbool 如果地图名称没有被占用并成功创建地图存储对象就返回true，否则就返回false。
	//! \param 		strName 地图名称。
	UGbool Add(const UGString &strName);
	
	//========================================================
	//! \brief 		把地图信息保存未XML字符串。
	//! \return 	UGString 返回包含地图信息的XML字符串，如果不成功就返回空字符串。
	//! \param 		nVersion 工作空间版本。
	UGString ToXML(UGint nVersion = 0)const;
	//========================================================
	//! \brief 		解析包含地图信息的XML字符串，构造地图集合。
	//! \return 	UGbool 如果成功就返回true，否则就返回false。
	//! \param 		strXML 包含地图信息的XML字符串。
	//! \param 		nVersion 工作空间版本。
	UGbool FromXML(const UGString &strXML, UGint nVersion = 0);

	//========================================================
	//! \brief 		设置修改指定地图名称的地图存储对象指针，如果地图名称不存在就新增一个地图存储对象。
	//! \return 	void
	//! \param 		strName 地图名称，不能为空字符串。
	//! \param 		pMapStorage 地图存储对象指针。
	void SetAt (const UGString &strName, UGMapStorage* pMapStorage);
	//========================================================
	//! \brief 		得到指定索引的地图名称和地图存储对象指针。
	//! \return 	UGbool 如果找到就返回true，否则就返回false。
	//! \param 		nIndex 索引位置，必须大于等于0，小于最大数。
	//! \param 		strName 返回地图名称。
	//! \param 		pMapStorage 返回地图存储对象指针。
	UGbool GetAt (UGint nIndex, UGString &strName, UGMapStorage *&pMapStorage);
	//========================================================
	//! \brief 		查找指定名称的地图存储对象。
	//! \return 	UGbool 如果找到就返回true，否则就返回false。
	//! \param 		strName 地图名称。
	//! \param 		pMapStorage 返回地图存储对象指针。
	UGbool Lookup (const UGString &strName, UGMapStorage *&pMapStorage ) const;

	//========================================================
	//! \brief 		得到地图存储对象数目。
	UGint GetCount()const;
	//========================================================
	//! \brief 		是否没有地图存储对象，如果没有就为true，否则就为false。
	//! \return 	UGbool
	UGbool IsEmpty()const;

	void AttachWorkspace(UGWorkspace* pWorkspace);

protected:
	//! \brief 		修改标识。
	UGbool m_bModified;
	//! \brief 		静态地图版本处理回调函数。
	static MAPVERSIONPROC m_pMapVersionFunc;

	UGWorkspace* m_pWorkspace;
public:
	//! \brief 		地图存储对象集合。
	UGDict<UGString, UGMapStorage*> m_MapStorages;
	//! \brief 		地图名称集合。
	UGArray<UGString> m_strArrNames;

};

}

#endif // !defined(AFX_UGMAPSTORAGES_H__5F39D6B3_F5CA_48E7_84A0_A1CC4EFA93CD__INCLUDED_)
