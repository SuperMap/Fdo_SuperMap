/*! 
	\file	SMCDatasetVector.h
    \brief	矢量数据集类（抽象类）
	\author	周旭
	\attention
	----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2007 SuperMap GIS Technologies,Inc.                            <br>
    All Rights Reserved.                                                              <br>
    ----------------------------------------------------------------------------------<br> 
	\version 2007-9-21 初始化版本
*/

#ifndef SMCDATASETVECTOR_H
#define SMCDATASETVECTOR_H

#include "SMC.h"
#include "SMCDataset.h"
#include "SMCTable.h"
#include "SMCQueryDef.h"
#include "SMCRecordset.h"

class SMC_API SMCDatasetVector : public SMCDataset, public SMCTable
{
public:
	SMCDatasetVector();
	~SMCDatasetVector();

public:
	//! \brief	打开数据集
	virtual bool Open();

	//! \brief	关闭数据集
	virtual void Close();

	//! \brief		数据集重命名,只改变数据集名,表名不变
	//! \param		steNewName  修改后的新名字
	//! \return     bool 修改成功返回true， 否则返回false
	virtual bool Rename(const _tstring& strNewName) ;

	//! \brief		保存数据集信息
	//! \return		bool 保存成功返回true， 否则返回false
	virtual bool SaveInfo();

public:
	//! brief		返回数据集类型
	//! return		DatasetType 返回矢量数据集的类型
	virtual DatasetType GetType() const;
           
	//! brief		返回数据集名
	//! return		_tstring 返回矢量数据集名称
	virtual _tstring GetName();

	//! \brief		判断是否是矢量数据集
	//! \return		bool 是矢量数据集返回true， 否则返回false
	virtual bool IsVector();

	//! \brief		是否有几何数据，除了Tablur数据集，都有几何数据
	//! \return		bool如果有几何数据则返回true， 否则返回false。
	virtual bool HasGeometry() const;

	//! \brief		查询通用入口
	//! \return     bool查询成功返回true， 否则返回false
	//! \param[in]  查询条件定义
	//! \param[out] pRecordset返回查询获取的记录集
	virtual bool Query(const SMCQueryDef& queryDef, SMCRecordset*& pRecordset);   

	//! \brief		追加记录
	//! \return		bool 添加成功返回true,返回false
	//! \param		pSrcRecordset待插入记录
	virtual bool Append(SMCRecordset* pSrcRecordset, 
		bool bShowProgress = TRUE, _tstring strTileName = _T(""));

	//! \brief		获取父数据集指针
	//! \return		SMCDataset* 返回父数据集指针
//	SMCDataset* GetParentDataset() const ;   //(网络数据集用)

	//! \brief		获取子数据集指针
	//! \return		SMCDatasetVector*返回子数据集指针		
//	SMCDatasetVector* GetChildDataset() const;  //(网络数据集用)

	//! \brief		返回查询得到的记录集个数！！
	//! \note       调用此函数的数据集需先打开
	virtual int GetRecordsetCount();

	//! \brief		返回指定索引的记录集指针
	//! \param[in]	nIndex指定返回的记录集序号
	//! \param[out] pRecordset返回获取的记录集
	//! \return     bool获取成功返回true，否则返回false
	virtual bool GetRecordsetAt(int nIndex, SMCRecordset*& pRecordset);

	//! 通过索引释放记录集
	virtual bool ReleaseRecordset(int nIndex);

	//! 通过引用释放记录集
	virtual bool ReleaseRecordset(SMCRecordset *pRecordset);

};

#endif