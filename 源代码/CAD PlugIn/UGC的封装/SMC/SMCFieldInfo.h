/*! 
	\file	SMCFieldInfo.h
    \brief	字段信息类
	\author	周旭
	\attention
	----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2007 SuperMap GIS Technologies,Inc.                            <br>
    All Rights Reserved.                                                              <br>
    ----------------------------------------------------------------------------------<br> 
	\version 2007-9-24 初始化版本
*/

#ifndef SMCFIELDINFO_H
#define SMCFIELDINFO_H

#include "SMC.h"
//#include "SMCArray.h"

class SMC_API SMCFieldInfo  
{
public:
	SMCFieldInfo(){}
	~SMCFieldInfo(){}
public:
	//! 字段类型
	enum FieldType
	{
		Boolean = 1,
		Byte = 2,
		Integer = 3,
		Long = 4,
		Currency = 5,
		Single = 6,
		Double = 7,
		Date = 8,
		Binary = 9,
		Text = 10,
		LongBinary = 11,
		Memo = 12,
		GUID = 15,
		BigInt = 16,
		VarBinary = 17,
		Char = 18,
		Numeric = 19,
		Decimal = 20,
		Float = 21,
		Time = 22,
		TimeStamp = 23,
		Geometry = 128,
		DgnLink = 129,
		//添加宽字节 20070323
		NVarChar =130
	};

public:
	//! 字段名称
	_tstring m_strName;

	//! 字段类型
	FieldType m_nType;

	//! 字段大小
	int m_nSize;
	
	//! 字段属性
	int m_nAttributes;
	
	//! 字段序号位置
	int m_nOrdinalPosition;

	//! 是否是必填字段
	bool m_bRequired;
	
	//! 字段长度是否允许为零
	bool m_bAllowZeroLength;
	
	//! m_nCollatingOrder,尚未使用
	int m_nCollatingOrder;

	//! 别名
	_tstring m_strForeignName;

	//! 源字段名
	_tstring m_strSourceField;

	//! 源表名
	_tstring m_strSourceTable;

	//! m_strValidationRule,尚未使用
	_tstring m_strValidationRule;

	//! m_strValidationText,尚未使用
	_tstring m_strValidationText;

	//! 默认值
	_tstring m_strDefaultValue;

	//! 刻度
	int m_nScale;
	
	//! 精度
	int m_nPrecision;

	//! 格式
	_tstring m_strFormat;

	//! 限制信息
	_tstring m_strDomain;

	//! 是否可编辑
	bool m_bUpdatable;

	//! 索引表名称
    _tstring m_strIndexTab;
		
};

class SMC_API SMCFieldInfos:public std::vector<SMCFieldInfo>
{
	SMCFieldInfos(){};
	~SMCFieldInfos(){};
};


#endif