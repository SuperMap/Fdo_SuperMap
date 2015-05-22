/*! 
	\file	SMCArray.h
    \brief	数组的类型
	\author	周旭
	\attention
	----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2007 SuperMap GIS Technologies,Inc.                            <br>
    All Rights Reserved.                                                              <br>
    ----------------------------------------------------------------------------------<br> 
	\version 2007-9-24 初始化版本
*/

#ifndef SMCARRAY_H
#define SMCARRAY_H

#include <vector>
#include "SMC.h"

template<typename T>
class SMC_API SMCArray
{
public:
	SMCArray(){}
	~SMCArray(){}
public:
	std::vector<T> m_array;
};

#endif
