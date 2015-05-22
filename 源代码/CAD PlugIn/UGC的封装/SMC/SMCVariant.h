/*! 
	\file	SMCVariant.h
    \brief	通用数据类型类
	\author	马 俊
	\attention
	----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2007 SuperMap GIS Technologies,Inc.                            <br>
    All Rights Reserved.                                                              <br>
    ----------------------------------------------------------------------------------<br> 
	\version 2007-9-24 初始化版本
*/

#ifndef SMCVARIANT_H
#define SMCVARIANT_H

#include "SMC.h"

class SMC_API SMCVariant  
{
public:
	//! \brief		支持的类型
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

	//! \brief		变体联合
	union VarValue
	{
		unsigned char bVal;
		short sVal;
		int	iVal;
		long long int  lVal;
		float fVal;
		double dVal;
		double   tVal; // Time的内部实现
		void* pVal;	//存储String或MemeroyStream的指针
	};

public:
	SMCVariant(){}
	~SMCVariant(){}

public:
	//! \brief		变体类型
	VarType m_nType;
	//! \brief		变体值
	VarValue m_value;	
};

#endif
