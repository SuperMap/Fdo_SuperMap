/*!
   **************************************************************************************
    \file     UGList.h
   **************************************************************************************
    \author   曾志明
    \brief    List链表模板类                                           
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2005 SuperMap GIS Technologies,Inc.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-06-16  曾志明    由于VC8(.NET2005beta2)下list begin()迭代器不能-- ,		 
			 空list end()迭待器不能--, 故而原有实现会出错; 增加了对可能出错地方的判断.	<br>
			 2007-4-16 1)增加注释, 2)把从std::list继承改为组合, 3) 修改部分接口,使之更规范
			 4)增加单元测试			<br>
   **************************************************************************************
*/


#ifndef UGLIST_H
#define UGLIST_H
#include "ugdefs.h"

namespace UGC {

//! \brief 链表模板类
//! \remarks 接口参考MFC的CList,内部采用stl的list实现
template<typename T>
class UGEXPORT UGList
{
public:
	// zengzm 不得已修改POSITION的定义, 因为VC8的begin不能--,无法确定是否已到链表头
	//typedef typename std::list<T>::iterator POSITION;
	typedef typename std::list<T>::iterator STD_POSITION;
	//! \brief 在List中定位用的类,不能直接构造,必须通过UGList来进行操作.
	struct POSITION
	{
		friend class UGList<T>;
	public:
		POSITION() {
			bIsBOF = false;
		}
	private:
		STD_POSITION it;
		// UGbool bIsEOF; // 是否已到链表尾
		UGbool bIsBOF; // 是否已到链表头

		POSITION(STD_POSITION it, UGbool bIsBOF=false){
			this->it = it;
			this->bIsBOF = bIsBOF;
		}
	};

public:
	//! \brief 默认构造函数
	UGList()
	{
	}
	
	//! \brief 得到元素个数
	UGint GetCount() const
	{
		return (UGint)m_list.size();
	}

	//! \brief 判断是否为空
	//! \return 空返回true;不为空返回false
	UGbool IsEmpty() const
	{
		return m_list.empty();	
	}

	//! \brief 得到头元素
	//! \return 返回头元素的引用,即调用者可直接修改
	T& GetHead()
	{
		UGASSERT(!IsEmpty());
		return m_list.front();
	}

	//! \brief 得到头元素
	//! \return 返回头元素的const引用
    const T& GetHead() const
	{
		UGASSERT(!IsEmpty());
		return m_list.front();
	}

	//! \brief 得到尾元素
	//! \return 返回尾元素的引用,即调用者可直接修改
    T& GetTail()
	{
		UGASSERT(!IsEmpty());
		return m_list.back();
	}

	//! \brief 得到尾元素
	//! \return 返回尾元素的const引用
    const T& GetTail() const
	{
		UGASSERT(!IsEmpty());
		return m_list.back();
	}

	//! \brief 移除头元素
	//! \return 返回被移除的元素
	T RemoveHead()
	{
		UGASSERT(!IsEmpty());
		T f=m_list.front();
		m_list.pop_front();
		return f;
	}

	//! \brief 移除尾元素
	//! \return 返回被移除的元素
    T RemoveTail()
	{
		UGASSERT(!IsEmpty());
		T t=m_list.back();
		m_list.pop_back();
		return t;
	}

	//! \brief 在头部增加元素
	//! \param newElement 要被添加的元素
	//! \return 返回增加元素的Position
	POSITION AddHead(const T& newElement)
	{
		m_list.push_front(newElement);
		return m_list.begin();
	}

	//! \brief 在尾部增加元素
	//! \param newElement 要被添加的元素
	//! \return 返回增加元素的Position
    POSITION AddTail(const T& newElement)
	{
		m_list.push_back(newElement);
		return --m_list.end();
	}

	//! \brief 在头部增加一个链表
	//! \param newList 要被添加的链表
	void AddHead(const UGList<T>& newList)
	{
		//UGASSERT(pNewList);
		m_list.insert(m_list.begin(),newList.m_list.begin(),newList.m_list.end());
	}

	//! \brief 在尾部增加一个链表
	//! \param newList 要被添加的链表
    void AddTail(const UGList<T>& newList)
	{
		//UGASSERT(pNewList);
		m_list.insert(m_list.end(),newList.m_list.begin(),newList.m_list.end());
	}
	
	//! \brief 移除所有元素
	void RemoveAll()
	{
		m_list.clear();
	}

	//! \brief 得到头部位置
	//! \return 返回头部位置
	POSITION GetHeadPosition() const
	{				
		// return const_cast<UGList<T>*>(this)->begin();
		// 下面的语句意思是: 先把m_list的常量性去掉, 然后得到指向begin的迭代器
		// 这个迭代器就是非const的了, 然后构造出POSITION对象来.
		// 后来还有好几个地方用到了这种方法,
		return POSITION( (const_cast< std::list<T>& >(m_list)).begin());
	}

	//! \brief 得到尾部位置
	//! \return 返回尾部位置
    POSITION GetTailPosition() const
	{
		// return --(const_cast<UGList<T>*>(this)->end());
		STD_POSITION itEnd = const_cast<std::list<T>&>(m_list).end();
		if (GetCount() == 0) {
			return POSITION(itEnd, true);
		}
		return POSITION(--itEnd);
	}

	//! \brief 判断某位置是否已到链表尾
	//! \param position 要判断的位置
	//! \return 已到链表尾返回true;否则返回false
	UGbool IsEOF(POSITION position) const
	{
		return position.it==const_cast<std::list<T>&>(m_list).end();
	}

	//! \brief 判断某位置是否已到链表头
	//! \param position 要判断的位置
	//! \return 已到链表头返回true;否则返回false
	UGbool IsBOF(POSITION position) const
	{
		return position.bIsBOF 
			|| (++position.it==const_cast<std::list<T>&>(m_list).begin());
	}
	
	//! \brief 得到某位置的下一个位置
	//! \remarks 该位置不能是头位置或者尾位置
	//! \param rPosition[in][out] 给出的位置,得到下一个的位置
	//! \return 返回传入位置的元素的引用
	T& GetNext(POSITION& rPosition)
	{
		UGASSERT(!(IsEOF(rPosition) || IsBOF(rPosition)));
		return *rPosition.it++;
	}

	//! \brief 得到某位置的下一个位置
	//! \remarks 该位置不能是头位置或者尾位置
	//! \param rPosition[in][out] 给出的位置,得到下一个的位置
	//! \return 返回传入位置的元素的引用
    const T& GetNext(POSITION& rPosition) const
	{
		UGASSERT(!(IsEOF(rPosition) || IsBOF(rPosition)));
		return *rPosition.it++;
	}

	//! \brief 得到某位置的上一个位置
	//! \remarks 该位置不能是头位置或者尾位置
	//! \param rPosition[in][out] 给出的位置,得到上一个的位置
	//! \return 返回传入位置的元素的引用
    T& GetPrev(POSITION& rPosition)
	{
		UGASSERT(!(IsEOF(rPosition) || IsBOF(rPosition)));
		if (rPosition.it == m_list.begin()) 
		{ // 如果到头了, 要记录一下, 并且不--了
			rPosition.bIsBOF = true; 
			return *rPosition.it;
		}
		return *rPosition.it--;
	}

	//! \brief 得到某位置的上一个位置
	//! \remarks 该位置不能是头位置或者尾位置
	//! \param rPosition[in][out] 给出的位置,得到上一个的位置
	//! \return 返回传入位置的元素的引用
    const T& GetPrev(POSITION& rPosition) const
	{
		UGASSERT(!(IsEOF(rPosition) || IsBOF(rPosition)));
		if (rPosition.it == m_list.begin()) 
		{ // 如果到头了, 要记录一下, 并且不--了
			rPosition.bIsBOF = true; 
			return *rPosition.it;
		}
		return *rPosition.it--;
	}
	
	//! \brief 得到某位置的值
	//! \param position 传入的位置
	//! \return 返回传入位置的元素的引用
	T& GetAt(POSITION position)
	{
		UGASSERT(!(IsEOF(position) || IsBOF(position)));
		return *position.it;
	}

	//! \brief 得到某位置的值
	//! \param position 传入的位置
	//! \return 返回传入位置的元素的引用
    const T& GetAt(POSITION position) const
	{
		UGASSERT(!(IsEOF(position) || IsBOF(position)));
		return *position.it;
	}

	//! \brief 设置某位置的值
	//! \param position 要设置值的位置
	//! \param newElement 要设置位置的新值
	void SetAt(POSITION pos, const T& newElement)
	{
		UGASSERT(!(IsEOF(pos) || IsBOF(pos)));
		*pos.it=newElement;
	}

	//! \brief 移除某位置的元素
	//! \param position 要移除的位置
    void RemoveAt(POSITION position)
	{
		UGASSERT(!(IsEOF(position) || IsBOF(position)));
		m_list.erase(position.it);
	}
	
	//! \brief 在某位置之前插入一个元素
	//! \param position 要插入的位置
	//! \param newElement 要插入的元素
	//! \return 返回被插入元素在链表中的位置
	POSITION InsertBefore(POSITION position,const T& newElement)
	{
		UGASSERT(!IsBOF(position));
		return m_list.insert(position.it,newElement);
	}

	//! \brief 在某位置之后插入一个元素
	//! \param position 要插入的位置
	//! \param newElement 要插入的元素
	//! \return 返回被插入元素在链表中的位置
    POSITION InsertAfter(POSITION position,const T& newElement)
	{
		UGASSERT(!IsEOF(position));
		return m_list.insert(++position.it,newElement);
	}

	//! \brief 从头开始查找值等于指定参数的元素的位置
	//! \param searchValue 要查找的元素
	//! \return 返回第一个找到的元素的位置
	POSITION Find(const T& searchValue) const
	{
		return std::find(const_cast<std::list<T>&>(m_list).begin(),
			const_cast<std::list<T>&>(m_list).end(),searchValue);
	}

	//! \brief 从指定的位置之后,开始查找值等于指定参数的元素的位置
	//! \param searchValue 要查找的元素
	//! \param startAfter 指定查找的位置(该位置不被查找)
	//! \return 返回第一个找到的元素的位置
    POSITION Find(const T& searchValue, POSITION startAfter) const
	{
		UGASSERT(!IsEOF(startAfter));
		return std::find(++startAfter.it,const_cast<std::list<T>&>(m_list).end(),searchValue);
	}
	
	//! \brief 得到指定索引的元素的位置
	//! \param nIndex 指定的查找开始的索引
	//! \return 返回找到的元素的位置; 如果整个链表都未找到,则返回尾位置
    POSITION FindIndex(UGint nIndex) const
	{		
		
		POSITION pos(const_cast<std::list<T>&>(m_list).begin());
		for(UGint i=0;i<nIndex;i++)
		{
			if(++pos.it==const_cast<std::list<T>&>(m_list).end())
				break;
		}
		return pos;
	}

private:
	//! \brief 内部实现采用stl的list
	std::list<T> m_list;
};

}

#endif


