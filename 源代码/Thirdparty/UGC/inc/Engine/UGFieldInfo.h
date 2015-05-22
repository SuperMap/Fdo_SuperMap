/*! \file	 UGFieldInfo.h
 *  \brief	 字段信息类
 *  \author	 ugc team
 *  \attention 
 *  Copyright(c) 1996-2004 SuperMap GIS Technologies,Inc.<br>
 *  All Rights Reserved
 *  \version $Id: UGFieldInfo.h,v 1.7 2007/10/16 06:56:44 liwl Exp $
 */

#ifndef UGFIELDINFO_H
#define UGFIELDINFO_H

#include "Base/ugdefs.h"
#include "Base/UGString.h"
#include "Base/UGArray.h"

namespace UGC {

class ENGINE_API UGFieldInfo  
{
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

		//添加宽字节 20070323
		NVarChar =127,
		Geometry = 128,
		DgnLink = 129,
	};

public:
	UGFieldInfo();
	~UGFieldInfo();
public:
	
	//! 判断字段是否可更新
	UGbool CanUpdate();

	//! 判断是否是SuperMap系统字段
	UGbool IsSystemField();

	//! 判断是否是几何对象字段
	UGbool IsGeoField();

	//! 判断是否包含索引
	UGbool IsContainIndex(){
		return !m_strIndexTab.IsEmpty(); 
	}
public:
	//! 字段名称
	UGString m_strName;

	//! 字段类型
	FieldType m_nType;

	//! 字段大小
	UGint m_nSize;
	
	//! 字段属性
	UGint m_nAttributes;
	
	//! 字段序号位置
	UGint m_nOrdinalPosition;

	//! 是否是必填字段
	UGbool m_bRequired;
	
	//! 字段长度是否允许为零
	UGbool m_bAllowZeroLength;
	
	//! m_nCollatingOrder,尚未使用
	UGint m_nCollatingOrder;

	//! 别名
	UGString m_strForeignName;

	//! 源字段名
	UGString m_strSourceField;

	//! 源表名
	UGString m_strSourceTable;

	//! m_strValidationRule,尚未使用
	UGString m_strValidationRule;

	//! m_strValidationText,尚未使用
	UGString m_strValidationText;

	//! 默认值
	UGString m_strDefaultValue;

	//! 刻度
	UGint m_nScale;
	
	//! 精度
	UGint m_nPrecision;

	//! 格式
	UGString m_strFormat;

	//! 限制信息
	UGString m_strDomain;

	//! 是否可编辑
	UGbool m_bUpdatable;

	//! 索引表名称
    UGString m_strIndexTab;
		
};

class ENGINE_API UGFieldInfos:public UGArray<UGFieldInfo> 
{
public:
	UGString ToXML() const;	
	
	UGbool AddField(						//添加字段
		const UGString& strName,				//字段名称，注意字段名称的前两个字符不能使用“Sm”或者其任何大小写形式，否则本函数拒绝加入并返回FALSE
		UGFieldInfo::FieldType nType,					//字段类型，参考MFC类库帮助中 CDaoFieldInfo 部分
		UGint lSize,						//大小
		UGint lAttributes = 0,			//属性，默认为0
		UGbool bRequired = FALSE,			//是否必须赋值（不为空）
		UGbool bAllowZeroLength = TRUE,	//是否长度可以为0
		UGString strDefaultValue=(""),	//默认值
		UGString strIndexTabName = ("")	//默认为空	 
		)
	{
		UGFieldInfo fieldinfo;
		fieldinfo.m_strName = strName;
		fieldinfo.m_nType = nType;
		fieldinfo.m_nSize = lSize;
		fieldinfo.m_nAttributes = lAttributes;
		fieldinfo.m_bRequired = bRequired;
		fieldinfo.m_bAllowZeroLength = bAllowZeroLength;
		fieldinfo.m_strDefaultValue = strDefaultValue;
		fieldinfo.m_strIndexTab = strIndexTabName;
		return Add(fieldinfo);
	}
};

}

#endif


