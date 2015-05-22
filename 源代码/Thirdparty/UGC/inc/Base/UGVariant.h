/*! \file	 UGVariant.h
 *  \brief	 变体类的定义
 *  \author	 ugc team
 *  \attention 
 *  Copyright(c) 1996-2004 SuperMap GIS Technologies,Inc.<br>
 *  All Rights Reserved
 *  \version $Id: UGVariant.h,v 1.7 2007/11/19 09:59:18 pengliang Exp $
 */


#ifndef UGVARIANT_H
#define UGVARIANT_H

#include "ugdefs.h"
#include "UGString.h"
#include "UGTime.h"
#include "UGStream.h"

namespace UGC {

class BASE_API UGVariant  
{
public:
	//! 支持的类型
	enum VarType
	{ 
		Null			=	0, //! 未定义的类型
		Byte			=	1, //! 单字节类型
		Short			=	2, //! 双字节整型类型
		Integer			=	3, //! 四字节整型类型
		Long			=	4, //! 八字节整型类型
		Float			=	5, //! 四字节浮点类型
		Double			=	6, //! 八字节浮点类型
		Time			=	7, //! 时间类型
		Binary			=	8, //! 二进制类型
		String			=   9  //! 字符串
	};

	//! 变体联合
	union VarValue
	{
		UGuchar bVal;
		UGshort sVal;
		UGint	iVal;
		UGlong  lVal;
		UGfloat fVal;
		UGdouble dVal;
		double   tVal; // UGTime的内部实现
		void* pVal;	//存储UGString或UGMemeroyStream的指针
	};
	
public:
	//! 默认构造函数
	UGVariant();

	//! 析构函数
	~UGVariant();

	//! 拷贝构造函数
	UGVariant(const UGVariant& varSrc);

	//! 其他构造函数
	UGVariant(UGuchar bVal);
	UGVariant(UGshort sVal);
	UGVariant(UGint iVal);
	UGVariant(UGlong lVal);
	UGVariant(UGfloat fVal);
	UGVariant(UGdouble dVal);	
	UGVariant(const UGTime& tVal);
	UGVariant(const UGuchar* pData,UGint nSize);	
	UGVariant(const UGString& string);	
	
	//! 赋值操作符
	const UGVariant& operator=(const UGVariant& varSrc);
	const UGVariant& operator=(UGuchar bVal);
	const UGVariant& operator=(UGshort sVal);
	const UGVariant& operator=(UGint iVal);
	const UGVariant& operator=(UGlong lVal);
	const UGVariant& operator=(UGfloat fVal);
	const UGVariant& operator=(UGdouble dVal);
	const UGVariant& operator=(const UGTime& tVal);	
	const UGVariant& operator=(const UGString& string);

	//! 设置变量值
	void Set(UGuchar bVal);
	void Set(UGshort sVal);
	void Set(UGint iVal);
	void Set(UGlong lVal);
	void Set(UGfloat fVal);
	void Set(UGdouble dVal);	
	void Set(const UGTime& tVal);
	void Set(const UGuchar* pData,UGint nSize);	
	void Set(const UGString& string);	
	
	//! 判断是否相等或不等
	//! 类型不相等, 则认为不相等(COleVariant的处理方式)
	UGbool operator==(const UGVariant& varSrc) const;
	UGbool operator!=(const UGVariant& varSrc) const;
	UGbool operator<(const UGVariant& varSrc) const;

	//! 清空
	void Clear();	

	//! 获取变体类型
	VarType GetType() const {
		return m_nType;
	}

	//! 获取变体值
	VarValue& GetValue() {
		return m_value;
	}

	const VarValue& GetValue() const {
		return m_value;
	}

	// 应大家要求, 增加转换为double int 和UGString 类型
	//! 转换为double类型
	UGdouble ToDouble() const;
	//! 转换为int32 类型
	UGint ToInt() const;
	//! 转换为int64 类型
	UGlong ToLong() const;
	//! 转换为String类型
	UGString ToString() const;
	

private:
	
	//! 设置为空
	void SetNull();
	
	//! 变体类型
	VarType m_nType;
	
	//! 变体值
	VarValue m_value;	
};

}

#endif


