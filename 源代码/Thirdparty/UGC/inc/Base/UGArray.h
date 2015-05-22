/*! \file	 UGArray.h
*	\brief	 数组类
*	\author	 李同堂
*	\attention 
*	Copyright(c) 1996-2005 SuperMap GIS Technologies, Inc.<br>
*	All Rights Reserved
*	\version 曾志明  2005-5-8 增加Capacity的处理;
						RemoveAll函数中增加清除剩余空间;
						增加相应注释;
*/

#ifndef UGARRAY_H
#define UGARRAY_H
#include "ugdefs.h"

namespace UGC {

//! \brief 数组类
//! \remarks 内部采用STL的vectory实现
template<typename T>
class UGEXPORT UGArray
{
public:
	//! \brief 默认构造函数
	UGArray() { }	

	//! \brief 预先设置了nSize个元素(每个元素为默认构造)
	//! \param nSize 预设的元素个数, 必须大于等于0
	//! \remarks explicit用来放置隐形的从整型转化为数组类型
	explicit UGArray(UGint nSize) 
	{
		UGASSERT(nSize>=0);
		m_array.resize(nSize);
	}

	//! \brief 预先设置了nSize个元素(默认构造), 默认值为elem
	//! \param nSize 预设的元素个数, 必须大于等于0
	//! \param elem 预设元素的默认值
	UGArray(UGint nSize, const T& elem)
	{
		UGASSERT(nSize>=0);
		m_array.resize(nSize,elem);
	}

public:
	//! \brief 得到目前UGArray中所有空间(包括已经使用的和保留的)所能容纳的元素的个数
	//! \return 返回数组所有空间可容纳的元素个数
	UGint GetCapacity() const
	{
		return m_array.capacity();
	}

	//! \brief 确保UGArray有足够的内存空间存储 指定的元素个数
	//! \param nCapacity 指定可容纳的元素个数,必须大于等于0
	//! \remarks 如果原有空间不够, 内存空间会增加, 但增加的空间不会调用TYPE的构造函数
	//! 如果原有空间比指定的大, 也不会释放空间
	void SetCapacity(UGint nCapacity)
	{
		UGASSERT(nCapacity >= 0);
		m_array.reserve(nCapacity);
	}

	//! \brief 在最后增加一个元素
	//! \param newElement 增加的元素
	//! \return 返回这个元素的索引
	UGint Add(const T& newElement)
	{
		m_array.push_back(newElement);
		return (UGint)m_array.size()-1;
	}

	//! \brief 在数组最后增加指定个数的元素
	//! \param pData 要增加的元素指针
	//! \param nSize 要增加的元素个数
	//! \return 返回加入元素的起始索引
	UGint Append(const T* pData, UGint nSize)
	{
		UGint nOldSize=(UGint)m_array.size();
		m_array.insert(m_array.end(),pData,pData+nSize);
		return nOldSize;
	}

	//! \brief 在数组最后增加一个数组
	//! \brief src 要增加的数组
	//! \return 返回加入数组的起始索引
	UGint Append(const UGArray<T>& src)
	{
		UGint nOldSize=(UGint)m_array.size();
		m_array.insert(m_array.end(),src.m_array.begin(),src.m_array.end());
		return nOldSize;
	}

	//! \brief 数组拷贝,原来的内容被覆盖
	//! \param src 传入的数组
	void Copy(const UGArray<T>& src)
	{
		*this=src;
	}

	//! \brief 得到数组内部指针(地址连续)
	//! \return 返回数组内部指针(地址连续)
	const T* GetData() const
	{
		// modified by zengzm 2005.7.28 
		// dotnet 中的stl vector, 如果为空, 则调用(*begin())会导致程序崩溃
		// 故而先作一个判断
		//return &(*begin());
		if (GetSize() > 0)
		{
			return &(*m_array.begin());
		}
		else 
		{
			return NULL;
		}
	}

	//! \brief 得到数组内部指针(地址连续)
	//! \return 返回数组内部指针(地址连续)
	T* GetData()
	{
		// modified by zengzm 2005.7.28 
		// dotnet 中的stl vector, 如果为空, 则调用(*begin())会导致程序崩溃
		// 故而先作一个判断
		//return &(*begin());
		if (GetSize() > 0)
		{
			return &(*m_array.begin());
		}
		else 
		{
			return NULL;
		}
	}

	//! \brief 得到有用的元素的个数 减一, 即下标值 可以取的最大值; 
	//! \return 返回最大可用下标值
	//! \attention 注意: 如果 数组为空, 则 返回 -1
	UGint GetUpperBound() const
	{
		return (UGint)m_array.size()-1;
	}
		
	//! \brief 得到有用的元素的个数
	UGint GetSize() const
	{
		return (UGint)m_array.size();
	}

	//! \brief 释放多余的内存空间
	//! \remarks 即size之后到capacity的空间会被释放
	//! \attention 内部采用拷贝创建一个相同的数组,然后交换的方式实现的,
	//! 因此会破坏之前的内存, 导致之前GetData的指针变为非法, 故而不推荐使用.
	void FreeExtra()
	{
		if(m_array.capacity()>m_array.size()) {
			std::vector<T> vctTemp(m_array.begin(),m_array.end());
			m_array.swap(vctTemp);
		}
	}

	//! \brief 得到指定位置元素的引用
	//! \param nIndex 指定的位置
	//! \return 返回该位置元素的引用
	T& ElementAt(UGint nIndex)
	{
		UGASSERT(nIndex>=0 && nIndex<(UGint)m_array.size());
		return m_array.at(nIndex);
	}

	//! \brief 得到指定位置元素的const引用
	//! \param nIndex 指定的位置
	//! \return 返回该位置元素的const引用
	const T& ElementAt(UGint nIndex) const
	{
		UGASSERT(nIndex>=0 && nIndex<(UGint)m_array.size());
		return m_array.at(nIndex);
	}

	//! \brief 得到指定位置元素的引用
	//! \param nIndex 指定的位置
	//! \return 返回该位置元素的引用
	T& operator[](UGint nIndex)
	{
		UGASSERT(nIndex>=0 && nIndex<(UGint)m_array.size());
		return m_array.at(nIndex);
	}

	//! \brief 得到指定位置元素的const引用
	//! \param nIndex 指定的位置
	//! \return 返回该位置元素的const引用
	const T& operator[](UGint nIndex) const
	{
		UGASSERT(nIndex>=0 && nIndex<(UGint)m_array.size());
		return m_array.at(nIndex);
	}
	
	//! \brief 得到指定位置元素的拷贝
	//! \param nIndex 指定的位置
	//! \return 返回该位置元素的拷贝
	T GetAt(UGint nIndex) const
	{				
		UGASSERT(nIndex>=0 && nIndex<(UGint)m_array.size());
		return m_array.at(nIndex);
	}
	
	//! \brief 在指定位置设置元素(替换原有元素)
	//! \remarks 指定位置必须在数组size范围之内
	//! \param nIndex 指定的位置 
	//! \param newElement 要设置的元素
	void SetAt(UGint nIndex, const T& newElement)
	{			
		UGASSERT(nIndex>=0 && nIndex<(UGint)m_array.size());
		m_array.at(nIndex) = newElement;
	}
	
	//! \brief 在指定位置设置元素(替换原有元素)
	//! \remarks 如果指定位置大于数组size,数组会自动增长
	//! \param nIndex 指定的位置 
	//! \param newElement 要设置的元素
	void SetAtGrow(UGint nIndex,const T& newElement)
	{
		UGASSERT(nIndex >= 0);		
		if(nIndex>=(UGint)m_array.size())
		{
			m_array.resize(nIndex+1);
		}
		m_array.at(nIndex) = newElement;
	}
	
	//! \brief 调整UGArray的内存空间为 nNewSize, 
	//! \remarks 如果原有空间不够, 内存空间会增加, 
	//! 增加的空间会调用TYPE的默认构造函数(或等于newElement)
	//! 如果原有空间比指定的大, 不会释放空间,但 在指定的空间之后的元素就无效了
	//! 如果要强制释放内存,请调用FreeExtra(),释放多余的内存空间,
	//! \param nNewSize 指定的新的元素个数
	void SetSize(UGint nNewSize)
	{
		UGASSERT(nNewSize>=0);		
		m_array.resize(nNewSize);
	}	
	
	//! \brief 移除所有元素,同时清空所有空间
	void RemoveAll()
	{
		m_array.clear(); 		
		FreeExtra();
	}

	//! \brief 移除指定位置,指定个数的元素
	//! \remarks 指定位置必须在数组范围内
	//! \param nIndex 要移除的元素位置
	//! \param nCount 要移除的元素个数,默认为1
	//! \return 返回移除的元素个数
	UGint RemoveAt(UGint nIndex,UGint nCount=1)
	{
		UGASSERT(nIndex>=0);
		nCount = UGMAX(nCount,0);
		if(nCount == 0)
		{
			return 0;
		}

		UGint nSize=(UGint)m_array.size();
		if(nIndex >= nSize)
		{
			return 0;
		}

		// modified by zengzm 2005-9-12 增加判断,防止nCount<0
		UGint nEnd=nIndex+nCount;
		if(nEnd>nSize)
		{
			nEnd=nSize;
		}
		m_array.erase(m_array.begin()+nIndex,m_array.begin()+nEnd);
		return nEnd - nIndex;
	}
	
	//! \brief 在指定位置之前,插入指定个数的元素
	//! \remarks 如果指定位置不在数组范围内,会自动调整到[0,size]
	//! \param nIndex 指定的位置
	//! \param newElement 指定的元素
	//! \param nCount 要插入的元素个数,默认为1
	void InsertAt(UGint nIndex,const T& newElement,UGint nCount=1)
	{				
		UGint nSize=(UGint)m_array.size();
		nIndex=UGCLAMP(0,nIndex,nSize);
		if(nCount>0) 
		{
			m_array.insert(m_array.begin()+nIndex,nCount,newElement);
		}				
	}

	//! \brief 在指定位置之前,插入指定个数的元素
	//! \remarks 如果指定位置不在数组范围内,会自动调整到[0,size]
	//! \param nIndex 指定的位置
	//! \param pNewElement 指定的元素指针
	//! \param nCount 要插入的元素个数
	void InsertAt(UGint nIndex,const T* pNewElement,UGint nCount)
	{				
		UGint nSize=(UGint)m_array.size();
		nIndex=UGCLAMP(0,nIndex,nSize);
		if(nCount>0 && pNewElement) 
		{
			m_array.insert(m_array.begin()+nIndex,pNewElement,pNewElement+nCount);
		}				
	}
	
	//! \brief 在指定位置,插入一个新的数组
	//! \remarks 如果指定位置不在数组范围内,会自动调整到[0,size]
	//! \param nIndex 指定的位置
	//! \param newArray 要插入的数组
	void InsertAt(UGint nIndex, const UGArray<T>& newArray)
	{		
		//UGASSERT(pNewArray != NULL);
		UGint nSize=(UGint)m_array.size();
		nIndex=UGCLAMP(0,nIndex,nSize);
		m_array.insert(m_array.begin()+nIndex,newArray.m_array.begin(),newArray.m_array.end());
	}

	//! \brief 得到内部STL类型, 外部一般不要使用
	//! \return 返回内部STL类型
	std::vector<T>& Inner()
	{
		return m_array;
	}

private:
	//! \brief 内部采用STL的vector实现
	std::vector<T> m_array;
};

}

#endif
