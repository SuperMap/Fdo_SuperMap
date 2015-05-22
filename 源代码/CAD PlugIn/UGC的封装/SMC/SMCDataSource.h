/*! 
	\file	SMCDataSource.h
    \brief	数据源抽象基类，当前版本主要用来管理数据集集合
	\author	马 俊
	\attention
	----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2007 SuperMap GIS Technologies,Inc.                            <br>
    All Rights Reserved.                                                              <br>
    ----------------------------------------------------------------------------------<br> 
	\version 2007-9-19 初始化版本
*/

#ifndef SMCDATASOURCE_H
#define SMCDATASOURCE_H

#include "SMC.h"
#include "SMCDsConnection.h"

class SMCDataset;

class SMC_API SMCDataSource
{
public:

	SMCDataSource();
	virtual ~SMCDataSource();

public:

	//========================================================
	//! \brief		获取当前数据源所在的Schema
	//! \return     _tstring 获取到的Schema
	_tstring GetSchema() const;

	//! \brief      执行SQL语句，主要用于在数据库级执行的数据操作
	//! \return     bool 查询成功返回真，否则返回假 
	//! \param      [in]strSQL,要执行的SQL语句
	virtual bool Execute(const _tstring& strSQL)
	{
		return false;
	}

	//! \brief		创建数据源,需要预先设置好连接信息
	//! \return     bool 创建成功返回真，否则返回假
	virtual bool Create();

	//! \brief		打开数据源,需要预先设置好连接信息
	//! \return     bool 成功打开返回真，否则返回假
	virtual bool Open();

	//! \brief      数据源是否和数据连接
	//! \return     bool 已经连接返回真，否则返回假
	virtual bool IsConnected();

	//! \brief      仅仅连接数据库,不刷新数据集等
	//! \return     bool 连接成功返回真，否则返回假
	virtual bool Connect();

	//! \brief      关闭数据源
	virtual void Close();
	
	//! \brief      判断数据源是否已经打开
	//! \return	    bool 已经打开返回真，否则返回假     
	bool IsOpen() const;
	
	//! \brief      保存数据信息
	//! \return	    bool 成功执行返回真，否则返回假      
	virtual bool SaveInfo();

	//! \brief      修改密码
	//! \return     bool 成功执行返回真，否则返回假
	//! \param      strNewPassword 新密码
	virtual bool ChangePassword(const _tstring& strNewPassword);

	//! \brief	    删除数据集(通过名称)
	//! \return     bool 删除成功返回真，否则返回假
	//! \param      strName 数据集名称
	virtual bool DeleteDataset(const _tstring& strName);

public:

	//! \brief		获取数据源名称
	//! \return     _tstring 数据源的名称
	_tstring GetName() const ;

	//! \brief		获取引擎名称
	//! \return		_tstring 引擎名称
	virtual _tstring GetEngineName() const ;

	//! \brief		根据参数生成一个数据源中目前没有的数据集名称
	//! \return		_tstring 生成的数据集的名称
	//! \param      [in]strDataName 数据集名称
	virtual _tstring GetUnoccupiedDatasetName(const _tstring& strDatasetName);

	//! \brief		判断数据源是否修改过
	//! \return		bool 修改过返回真， 否则返回假
	bool IsModified();

	//! \brief		设置数据源是否修改标志
	//! \param		[in]bModified 默认设为已修改
	void SetModifiedFlag(bool bModified = true);

	//! \brief		返回数据集个数
	//! return		int 数据源中数据集的个数
	int GetDatasetCount() const;

	//! \biref		通过序号返回数据集指针
	//! \return		bool 成功执行返回真，否则返回假
	//! \param		[in]nIndex 数据集的序号
	//! \param		[out]pDdataset 返回的数据集
	//! \note		调用该函数前，需要先生成数据集子类对象，然后传入指针
	bool GetDataset(int nIndex, SMCDataset *&pDdataset) const;

	//! \biref		返回指定名称的数据集指针
	//! \return		bool 成功执行返回真，否则返回假
	//! \param		[in]strDatasetName 数据集名称
	//! \param		[out]pDdataset 返回的数据集
	//! \note		调用该函数前，需要先生成数据集子类对象，然后传入指针
	bool GetDataset(const _tstring& strDatasetName, SMCDataset *&pDdataset) const;

	//! \brief 		判断传入的字段名或表名是否可用
	//! \return 	bool 可用返回真，否则返回假
	//! \param 		[in]strFieldOrTableName 字段名或者表名
	//! \param 		nInvalidStata
	bool IsValidFieldOrTableName(const _tstring& strFieldOrTableName, int& nInvalidStata);



	//! \brief		设置数据源的连接信息
	//! \param      [in] conn 连接信息参数
	void SetConnection(const SMCDsConnection& dsconn);

	//! \brief		创建数据源
	//! \return		bool 创建成功返回真，否则返回假
	//! \param		数据源类型，详细见SMCDsConnection类中描述
	//! \note		生成一个数据源对象后，必须调用该对象的此成员函数才能生成，之后才能打开数据源
	bool CreateDataSource(SMCDsConnection::SMEngineType nEngineType);

	//! \brief		根据给定的参数打开数据源
	//! \return		bool 成功打开返回真，否则返回假
	//! \param		[in]sdbDs 数据源对象
	//! \param		[in]strConnection 连接字符串
	bool OpenDataSource(SMCDataSource &sdbDs, _tstring strConnection);

	//! \brief		用来测试Oracle和SQL Server数据源打开的函数
	bool OpenOraDS();

public:
    //! \brief		数据源指针
	void *m_pDataSource;

};
#endif
