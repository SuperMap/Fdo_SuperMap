
/** \file	 SuperMapFilterStringBuffer.h
*  \author	 马俊
*  \attention 
*  Copyright &copy;  1996-2007 SuperMap GIS Technologies,Inc.<br>
*  All Rights Reserved
*  \version 1.0
*  \date 2007-11-28
*/

#ifndef __SUPERMAP_FILTERSTRINGBUFFER_H__
#define __SUPERMAP_FILTERSTRINGBUFFER_H__
#ifdef _WIN32
#pragma once
#endif // _WIN32

/*! \class SuperMapFilterStringBuffer SuperMapFilterStringBuffer.h
	\brief 用于存放解析后的过滤串
	return 以字符串的形式返回过滤串
*/

class SuperMapFilterStringBuffer
{
public:
	SuperMapFilterStringBuffer(void);

public:
	~SuperMapFilterStringBuffer(void);

protected:
	char* m_pFilterText;		// 用于存储解析后的过滤串
    size_t m_BuffSize;			// 过滤串的大小
    size_t m_FirstBuffIndex;	// 指向过滤串开始的位置，为了方便在串的前面增加字符串
    size_t m_NextBuffIndex;		// 指向过滤串结尾的位置  

public:
	/*
		\brief 得到解析后的过滤串
		\return 指向过滤串的指针
	*/
    const char* GetString();  

	/*
		\brief 在过滤串的末尾增加一个字符串
		\param [in]Str 指向要增加的字符串
		\note 在该函数内可能要分配空间
	*/
    void AppendString(const char *Str);

	/*
		\brief 在过滤串的前面增加一个字符串
		\param [in]Str 指向要增加的字符串
		\note 在该函数内可能要重新分配空间
	*/
    void PrependString(const char *Str);  

	/*
		\brief 清空过滤串，并释放空间
	*/
    void ClearBuffer(void);
      
protected:
	/*
		\brief 重新分配过滤串空间
		\param [in]Size 重新分配内存的大小
		\param [in]bAtEnd 重新分配内存的方向, 如果为真: 从后面分配内存, 否则从前面分配内存; 
	*/
  void ReallocBuffer( size_t Size , bool bAtEnd );
};

#endif