/*! 
	\file	SMCTableRecordset.h
    \brief	记录集抽象基类，当前版本主要定义记录集的公共接口
	\author	马 俊
	\attention
	----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2007 SuperMap GIS Technologies,Inc.                            <br>
    All Rights Reserved.                                                              <br>
    ----------------------------------------------------------------------------------<br> 
	\version 2007-9-24 初始化版本
*/

#ifndef SMCTABLERECORDSET_H
#define SMCTABLERECORDSET_H

#include "SMC.h"
class SMCVariant;
class SMCFieldInfo;
class SMCFieldInfos;

class  SMC_API SMCTableRecordset
{
public:
	SMCTableRecordset(){}
	virtual ~SMCTableRecordset(){}

public:
	//! \brief		记录集是否为空(没有记录)
	//! \return		记录集为空返回真，否则返回假
	virtual bool IsEmpty() = 0; 

	//! \brief		判断当前记录指针是否指向头
	//! \return		指针指向头返回真，否则返回假
	virtual bool IsBOF() =0;

	//! \brief		判断当前记录指针是否指向尾
	//! \return		指针指向尾部返回真，否则返回假
	virtual bool IsEOF() =0;
	
	//! \brief		关闭记录集
	virtual void Close() =0;

	//! \brief		通过字段名获取字段值
	//! \param		[in]strName 字段名
	//! \param		[out]varVal 字段值
	//! \raturn		bool 获取成功返回真，否则返回假
	virtual bool GetFieldValue(const _tstring& strName,SMCVariant &varVal) =0;

	//! \brief		通过索引序号获取字段值
	//! \param		[in]nIndex 字段索引序号
	//! \param		[out]varVal 字段值
	//! \return		bool 获取成功返回真，否则返回假
	virtual bool GetFieldValue(int nIndex,SMCVariant &varVal) =0;

	//! brief		通过字段名设置当前记录的字段值,值为变体类型
	//! param		[in]strName 字段名
	//! param		[in]varVal 字段值
	//! \return		bool 成功设置返回真，否则返回假
	virtual bool SetFieldValue(const _tstring& strName,const SMCVariant& varVal) =0;
	
	//! \brief		通过字段名设置当前记录的字段值,值为字符串类型
	//! param		[in]strName 字段名
	//! param		[in]strVal 字段值
	//! \return		bool 成功设置返回真，否则返回假
	virtual bool SetFieldValue(const _tstring& strName,const _tstring& strVal) =0;
	
	//! \brief		通过索引序号设置当前记录的字段值,值为变体类型
	//! param		[in]nIndex 字段索引序号
	//! param		[in]varVal 字段值
	//! \return		bool 成功设置返回真，否则返回假
	virtual bool SetFieldValue(int nIndex,const SMCVariant& varVal) =0;

	//! \brief		通过索引序号设置当前记录的字段值,值为字符串类型
	//! param		[in]strName 字段名
	//! param		[in]strVal 字段值
	//! \return		bool 成功设置返回真，否则返回假
	virtual bool SetFieldValue(int nIndex,	const _tstring& strVal) =0;

	//! \brief		通过字段名设置字段值为空
	//! param		[in]strName 字段名
	//! \return		bool 成功设置返回真，否则返回假
	virtual bool SetFieldValueNull(const _tstring& strName) =0;

	//! \brief		通过索引设置字段值为空
	//! param		[in]nIndex 字段索引序号
	//! \return		bool 成功设置返回真，否则返回假
	virtual bool SetFieldValueNull(int nIndex) =0;

	//! \brief		在记录集中再次查询,查找符合条件的第一条记录
	//! \param		[in]strFilter 查询条件
	//! \return		bool 成功执行返回真，否则返回假
	virtual bool FindFirst(const _tstring& strFilter) =0;
	
	//! \brief		在记录集中再次查询,查找符合条件的最后一条记录
	//! \param		[in]strFilter 查询条件
	//! \return		bool 成功执行返回真，否则返回假
	virtual bool FindLast(const _tstring& strFilter) =0;

	//! \brief		在记录集中再次查询,查找符合条件的下一条记录
	//! \param		[in]strFilter 查询条件
	//! \return		bool 成功执行返回真，否则返回假
	virtual bool FindNext(const _tstring& strFilter) =0;

	//! \brief		在记录集中再次查询,查找符合条件的上一条记录
	//! \param		[in]strFilter 查询条件
	//! \return		bool 成功执行返回真，否则返回假
	virtual bool FindPrev(const _tstring& strFilter) =0;

	//! \brief		给定相应的数,向前或向后移动记录指针
	//! \param		[in]nRows 指针移动的次数
	//! \return		bool 移动成功返回真，否则返回假
	virtual bool Move(int nRows) =0;

	//! \brief		移动记录指针到最前
	//! \return		成功执行返回真，否则返回假
	virtual bool MoveFirst() =0;

	//! \brief		移动记录指针到最后
	//! \return		成功执行返回真，否则返回假
	virtual bool MoveLast() =0;

	//! \brief		向下移动一位记录指针
	//! \return		成功执行返回真，否则返回假
	virtual bool MoveNext() =0;

	//! \brief		向上移动一位记录指针
	//! \return		成功执行返回真，否则返回假
	virtual bool MovePrev() =0;

	//! \brief		移动记录指针到指定位置
	//! \param		[in]nRow 指针移动到的位置
	//! \return		bool 移动成功返回真，否则返回假
	virtual bool MoveTo(int nRow) =0;

	//! \brief		获取记录个数
	//! \return		int 记录个数
	virtual int GetRecordCount() =0;

	//! \brief		收集所有字段的信息
	//! \param		[out]fieldInfos 字段信息集合
	//! \return		bool 成功获取返回真，否则返回假
	virtual bool GetFieldInfos(SMCFieldInfos& fieldInfos) =0;
	
	//! \brief		通过字段名获取字段信息
	//! \param		[in]strName 字段名
	//! \param		[out]fieldInfo 获取的字段信息
	//! \return		bool 成功获取返回真，否则返回假
	virtual bool GetFieldInfo(const _tstring& strName,SMCFieldInfo& fieldInfo)  =0;
	
	//! \brief		通过索引取字段信息
	//! \param		[in]nIndex 字段索引
	//! \param		[out]fieldInfo 获取的字段信息
	//! \return		bool 成功获取返回真，否则返回假
	virtual bool GetFieldInfo(int nIndex,SMCFieldInfo& fieldInfo)  =0;
	
	//! \brief		获取字段个数
	//! \return		int 字段个数
	virtual int GetFieldCount()  =0; 

};

#endif