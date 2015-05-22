/*! 
	\file	SMCRecordset.h
    \brief	记录集类，当前版本主要管理查询得到的记录
	\author	马 俊
	\attention
	----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2007 SuperMap GIS Technologies,Inc.                            <br>
    All Rights Reserved.                                                              <br>
    ----------------------------------------------------------------------------------<br> 
	\version 2007-9-24 初始化版本
*/

#ifndef SMCRECORDSET_H
#define SMCRECORDSET_H

#include "SMC.h"
#include "SMCTableRecordset.h"

enum SMCStatisticMode
{
	smMax				= 1,	//! 最大值
	smMin				= 2,	//! 最小值
	smAvg				= 3,	//! 平均值 
	smSum				= 4,	//! 总和
	smStdev				= 5,	//! 标准差
	smVar				= 6		//! 方差
};

class SMCDatasetVector;
class SMCVariant;

class SMC_API SMCRecordset : public SMCTableRecordset
{
public:
	//! 构造函数
	SMCRecordset();
	//! 析构函数
	virtual ~SMCRecordset();

public:
	//!	\brief		获取记录集对应的数据集
	//! \param		[out]pDatasetVector 返回的数据集
	//! \return		bool 成功获取返回真，否则返回假
	bool GetDataset(SMCDatasetVector *&pDatasetVector) const;

	//! \brief		判断是否有属性数据
	//! \return		bool 有属性数据返回真，否则返回假
	bool HasDBInfo();

	//! \brief		判断是否有几何数据
	//! \return		bool 有几何数据返回真，否则返回假
	bool HasGeometry();

	//! \brief		删除所有记录
	//! \return		删除成功返回真，否则返回假
	virtual bool DeleteAll();

	//! \brief		按某种统计方法统计某个字段
	//! \param		[in]strField 字段名
	//! \param		[in]nMode 统计方式
	virtual bool Statistic(const _tstring& strField,SMCStatisticMode nMode, SMCVariant &varVal);

	//! \brief		刷新记录集,一般就是重新查询一遍
	//! \return		成功执行返回真，否则返回假
	virtual bool Refresh();

	//! \brief		复制字段值,strSrcField和
	//! \param		[in]strSrcField 源字段
	//! \param		[in]strDestField 目标字段
	//! \return		bool 成功执行返回真，否则返回假
	//! \attention	必须都存在且字段类型匹配
	virtual bool CopyField(const _tstring& strSrcField,const _tstring& strDestField);

	//! \brief		获取当前记录的ID
	//! \return		获取到的ID,错误返回-1
	virtual int GetID();

	//! \brief		判断记录集是否为空
	//! \return		bool 为空返回真，否则返回假
	bool IsEmpty();

	//! \brief		更新，提交修改
	virtual int Update();

	//! \brief		取消修改
	virtual bool CancelUpdate();

	//! \brief		开始修改数据
	//! \return		bool 成功执行返回真，否则返回假
	virtual bool Edit();

	//! \brief		删除当前记录
	//! \return		bool 成功执行返回真，否则返回假
	virtual bool Delete();

	//! \brief		是否可更新
	//! \return		可以添加返回真，否则返回假
	virtual bool CanUpdate();	

	//! \brief		是否可添加
	//! \return		可以添加返回真，否则返回假
	virtual bool CanAppend();



	//！以下函数从基类配生而来，详细注释见基类
	//! \brief		判断当前记录指针是否指向尾
	virtual bool IsBOF();
	//! \brief		判断当前记录指针是否指向尾
	virtual bool IsEOF();
	//! \brief		关闭记录集
	virtual void Close();
	//! \brief		通过字段名获取字段值
	virtual bool GetFieldValue(const _tstring& strName,SMCVariant &varVal);
	//! \brief		通过索引序号获取字段值
	virtual bool GetFieldValue(int nIndex,SMCVariant &varVal);
	//! brief		通过字段名设置当前记录的字段值,值为变体类型
	virtual bool SetFieldValue(const _tstring& strName,const SMCVariant& varVal);
	//! \brief		通过字段名设置当前记录的字段值,值为字符串类型
	virtual bool SetFieldValue(const _tstring& strName,const _tstring& strVal);
	//! brief		通过字段名设置当前记录的字段值,值为变体类型
	virtual bool SetFieldValue(int nIndex,const SMCVariant& varVal);
	//! \brief		通过索引序号设置当前记录的字段值,值为字符串类型
	virtual bool SetFieldValue(int nIndex,	const _tstring& strVal);
	//! \brief		通过字段名设置字段值为空
	virtual bool SetFieldValueNull(const _tstring& strName);
	//! \brief		通过索引设置字段值为空
	virtual bool SetFieldValueNull(int nIndex);
	//! \brief		在记录集中再次查询,查找符合条件的第一条记录
	virtual bool FindFirst(const _tstring& strFilter);
	//! \brief		在记录集中再次查询,查找符合条件的最后一条记录
	virtual bool FindLast(const _tstring& strFilter);
	//! \brief		在记录集中再次查询,查找符合条件的下一条记录
	virtual bool FindNext(const _tstring& strFilter);
	//! \brief		在记录集中再次查询,查找符合条件的上一条记录
	virtual bool FindPrev(const _tstring& strFilter);
	//! \brief		给定相应的数,向前或向后移动记录指针
	virtual bool Move(int nRows);
	//! \brief		移动记录指针到最前
	virtual bool MoveFirst();
	//! \brief		移动记录指针到最后
	virtual bool MoveLast();
	//! \brief		向下移动一位记录指针
	virtual bool MoveNext();
	//! \brief		向上移动一位记录指针
	virtual bool MovePrev();
	//! \brief		移动记录指针到指定位置
	virtual bool MoveTo(int nRow);
	//! \brief		获取记录个数
	virtual int GetRecordCount();
	//! \brief		收集所有字段的信息
	virtual bool GetFieldInfos(SMCFieldInfos& fieldInfos);
	//! \brief		通过字段名获取字段信息
	virtual bool GetFieldInfo(const _tstring& strName,SMCFieldInfo& fieldInfo);
	//! \brief		通过索引取字段信息
	virtual bool GetFieldInfo(int nIndex,SMCFieldInfo& fieldInfo);
	//! \brief		获取字段个数
	virtual int GetFieldCount();

	

public:
	void *m_pRecordset;

};
#endif

