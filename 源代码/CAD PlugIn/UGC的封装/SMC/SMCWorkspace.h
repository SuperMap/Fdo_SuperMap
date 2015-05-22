/*! 
	\file	SMCWorkspace.h
    \brief	工作空间管理类，当前版本主要用来管理数据源集合
	\author	周 旭
	\attention
	----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2007 SuperMap GIS Technologies,Inc.                            <br>
    All Rights Reserved.                                                              <br>
    ----------------------------------------------------------------------------------<br> 
	\version 2007-9-18 初始化版本
*/

#ifndef SMCWORKSPACE_H
#define SMCWORKSPACE_H

#include "SMC.h"
#include "SMCDataSources.h"

class SMC_API SMCWorkspace
{
public:
	enum SMCWorkspaceType
	{
		WS_Version_NO       = 1, //! \brief 	没有工作空间
	//	WS_Version_SXW30    = 2, //! \brief 	3.0SXW工作空间
	//	WS_Version_SMW30    = 3, //! \brief 	3.0SMW工作空间
		WS_Version_SXW		= 4, //! \brief 	SXW工作空间
		WS_Version_SUW		= 5, //! \brief 	SUW工作空间
		WS_Version_Oracle   = 6, //! \brief 	Oracle工作空间
		WS_Version_Sql		= 7	 //! \brief 	Sql工作空间 
	};

public:
	SMCWorkspace();
	virtual ~SMCWorkspace();

public:
	//! \brief 		打开工作空间
	//! \return 	bool 如果打开成功就返回true, 否则就返回false
	//! \param 		strWorkspaceName 全路径工作空间文件名
	//! \param 		strPassword 是否加密，输入密码，密码不能为空，为空就表示没有密码
	bool Open(const _tstring& strWorkspaceName, const _tstring& strPassword = (_T(""))); 

	//! \brief 		关闭工作空间。	
	void Close();

	//! \brief 		清空当前工作空间重新设置
	void Reset();	

	//! \brief		设置是否修改标志
	void SetModifiedFlag(bool bModified = false);	

	//! \brief 		是否修改过，包括任一成员的修改，您可以通过这个函数来确定是否需要提示用户存盘
	bool IsModified()const;

	//! \brief 		保存工作空间
	//! \return     bool 保存成功返回true, 否则返回false
	bool Save();

	//! \brief 		另存工作空间.
	//! \return 	bool 如果保存成功就返回true，否则就返回false。
	//! \param 		strWorkspaceName 工作空间文件名，带路径
	//! \param 		bFailIfExists如果文件存在，是否创建失败
	//! \param 		bIsXMLFormat 是否把工作空间存成为XML类型,默认不为XML。
	//! \param 		strNewPassword 允许修改密码,输入新的密码。
	//! \param 		nVersion 版本
	bool SaveAs(const _tstring& strWorkspaceName, 
		        bool bFailIfExists = true,
	  	        bool bIsXMLFormat = false,
				int nVersion = 0,
				const _tstring& strNewPassword = (_T("")));

public:
	//! \brief 		返回工作空间的名称，其实是全路径文件名。
	_tstring GetName()const;

	//! \brief 		得到工作空间类型
	//! \note       WS_Version_NO       = 1, //! \brief 	没有工作空间
	//! \note		WS_Version_SXW		= 4, //! \brief 	SXW工作空间
	//! \note		WS_Version_SUW		= 5, //! \brief 	SUW工作空间
	//! \note		WS_Version_Oracle   = 6, //! \brief 	Oracle工作空间
	//! \note		WS_Version_Sql		= 7	 //! \brief 	Sql工作空间
	int GetType()const;

	//! \brief 		得到SUW工作空间密码，要验证。
	_tstring GetPassword()const;

	//! \brief 		修改工作空间密码。
	void ChangePassword(const _tstring& strNewPassword);

public:
	//! \brief		通过数据源别名获取数据源
	//! \return		bool获取成功返回true，否则返回false
	//! \param[in]  strAlias数据源别名
	//! \param[out] pDataSource返回数据源
	bool GetDataSource(const _tstring& strAlias, SMCDataSource*& pDataSource);

	//! \brief		通过数据源序号获取数据源
	//! \return		bool获取成功返回true，否则返回false
	//! \param[in]  nIndex数据源序号
	//! \param[out] pDataSource返回数据源
	bool GetDataSource(int nIndex, SMCDataSource*& pDataSource);

protected:
	void* m_pWorkspace;
public:
	//! 数据源集合
	SMCDataSources m_DataSources;
    
};

#endif 
