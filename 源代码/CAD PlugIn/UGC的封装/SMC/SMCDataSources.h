/*! 
	\file	SMCDataSources.h
    \brief	数据源指针管理类，通过数据源指针与数据源别名的一一对应关系进行管理.
	\author	周 旭
	\attention
	----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2007 SuperMap GIS Technologies,Inc.                            <br>
    All Rights Reserved.                                                              <br>
    ----------------------------------------------------------------------------------<br> 
	\version 2007-9-18 初始化版本
*/

#ifndef SMCDATASOURCES_H
#define SMCDATASOURCES_H

#include "SMC.h"
#include "SMCDataSource.h"

class SMC_API SMCDataSources
{
public:
	SMCDataSources();
	virtual ~SMCDataSources();

public:
	//! \brief 		得到数据源的数目。
	//! \return 	int 如果没有数据源就返回0。
	int GetCount()const;

	//! \brief 		是否不存在数据源。
	//! \return 	bool 如果没有数据源就返回true，否则就返回false。
	bool IsEmpty()const;

	//! \brief 		清空并释放数据源指针。
	void Reset();

	//! \brief 		移走指定别名的数据源指针，并释放数据源指针。
	//! \return 	bool 如果别名存在就返回true，否则就返回false。
	//! \param 		strAlias 数据源别名。
	bool ReleaseAt(const _tstring& strAlias);

	//! \brief 		移走指定索引位置的数据源指针，并释放数据源指针。
	//! \return 	bool 如果成功就返回true，否则就返回false。
	//! \param 		nIndex 索引位置，必须大于等于0，小于最大数。
	bool ReleaseAt(int nIndex);

	//! \brief 		通过数据源别名查找索引。
	//! \return 	int 索引，如果找到就返回索引，否则就返回-1。
	//! \param 		strAlias 数据源别名。
	int FindAlias(const _tstring& strAlias)const;	

	//! \brief 		得到指定索引位置的数据源别名。
	//! \return 	string 数据源别名，如果找到就返回数据源别名，否则就返回空字符串。
	//! \param 		nIndex 索引位置，必须大于等于0，小于最大数。
	_tstring GetAliasAt(int nIndex)const;

	//! \brief 		设置修改标识，不仅对自己起作用，而且对所有有修改标识的成员都起作用。
	//! \return 	void
	//! \param 		bModified 修改标识。
	void SetModifiedFlag(bool bModified = true);

	//! \brief 		判断是否有修改，包括任一成员的修改。
	//! \return 	bool 如果有修改就返回true，否则就返回false。
	bool IsModified()const;

	//! \brief 		
	//! \return 	bool
	//! \param 		strAlias
	//! \param 		strNewAlias
	bool Rename(const _tstring& strAlias, const _tstring& strNewAlias);	

	//! \brief 		数据源别名是否存在。
	//! \return 	bool 如果别名存在就返回true，否则就返回false。
	//! \param 		strAlias 数据源别名。
	bool IsAliasExisted(const _tstring& strAlias)const;	

	//! \brief 		解析包含数据源信息的XML字符串，构造数据源指针集合，并连接或打开数据源。
	//! \return 	bool 如果成功就返回true，否则就返回false。
	//! \param 		strXML 包含数据源信息的XML字符串。
	//! \param 		strWorkspaceName 工作空间全路径名。
	//! \param 		nVersion 工作空间版本号。
	bool FromXML(const _tstring &strXML, const _tstring &strWorkspaceName, int nVersion = 0);

	//! \brief 		把数据源连接信息保存未XML字符串。
	//! \return 	string 返回包含数据源信息的XML字符串，如果不成功就返回空字符串。
	//! \param 		strWorkspaceName 工作空间全路径名。
	//! \param 		nVersion 工作空间版本号。
	_tstring ToXML(const _tstring &strWorkspaceName, int nVersion = 0)const;

public:
	//! \brief 		通过数据源别名查找数据源指针。
	//! \return 	bool 如果找到就返回true，否则就返回false。
	//! \param[in] 		strAlias 数据源别名。
	//! \param[out] 		pResDataSource 返回数据源指针。
	bool Lookup (const _tstring& strAlias, SMCDataSource* &pResDataSource)const;

	//! \brief 		设置修改指定别名的数据源指针，如果别名不存在就新增一个数据源指针。
	//! \param 		strAlias 数据源别名，不能为空字符串。
	//! \param 		pDataSource 数据源指针，不能为NULL。
	void SetAt(const _tstring& strAlias, SMCDataSource *pDataSource);	

	//! \brief 		得到指定索引的数据源别名和指针。
	//! \return 	bool 如果找到就返回true，否则就返回false。
	//! \param[in] 		nIndex 索引位置，必须大于等于0，小于最大数。
	//! \param[out] 		strAlias 返回数据源别名。
	//! \param[out] 		pDataSource 返回数据源指针。
	bool GetAt(int nIndex, _tstring& strAlias, SMCDataSource *&pDataSource)const;

	//! \brief 		通过数据源指针查找数据源别名。
	//! \return     数据源别名，如果找到就返回数据源别名，否则就返回空字符串。
	//! \param 		pDataSource 数据源指针，不能为NULL。
	_tstring GetAlias(SMCDataSource* pDataSource)const;

	//! \brief 		插入一个指定别名的数据源指针。
	//! \return 	bool 如果别名存在就就返回false，否则就返回true。
	//! \param 		strAlias 数据源别名，不能为空字符串。
	//! \param 		pDataSource 数据源指针，不能为NULL。
	bool Insert(const _tstring& strAlias, SMCDataSource* pDataSource);	

public:
	void* m_pDataSources ;
};

#endif