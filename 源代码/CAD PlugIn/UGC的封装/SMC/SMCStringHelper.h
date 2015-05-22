#pragma once
/*! 
	\file	SMCStringHelper.h
    \brief	字符串操作类
	\author	马 俊
	\attention
	----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2007 SuperMap GIS Technologies,Inc.                            <br>
    All Rights Reserved.                                                              <br>
    ----------------------------------------------------------------------------------<br> 
	\version 2007-9-28 初始化版本
*/

#include "SMC.h"

class SMC_API SMCStringHelper
{
public:
	//! \brief      对以delimeter分隔的字符串进行解析，分隔成子字符串
	//! \return     std::vector<_tstring> 解析结果存于Vector中
	//! \param      [in]strSorce,要分隔的字符串
	//! \param		[in]delimeter,字符串的界定符，例如;等
	//! \note		该函数是静态成员函数
	static std::vector<_tstring> Explode(const _tstring &strSorce, const _tstring& delimeter);

	//! \brief      对类似A=B格式的串转化为Map中的Key=A，Value=B
	//! \param      [in]strSorce,源串的向量
	//! \param		[out]connInfo,转化后的Map
	//! \note		该函数是静态成员函数
	static void ProKeyAndVal(const std::vector<_tstring> &strSource, std::map<_tstring, _tstring> &connInfo); 

	//! \brief      将字符串转化为小写
	//! \return		结果字符串
	//! \param      [in]strSorce,源字符串串
	//! \note		该函数是静态成员函数
	static _tstring MakeStrLower(const _tstring &strSource);
};
