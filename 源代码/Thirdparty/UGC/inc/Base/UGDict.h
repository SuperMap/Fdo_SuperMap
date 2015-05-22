/* 
	\file UGDict.h
	\brief 字典类。
	\author 文件作者
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>更新说明：。</b>
	<em>1、第一条说明。</em>
	<em>2、第二条说明。</em>
*/

#ifndef UGDICT_H
#define UGDICT_H
#include "ugdefs.h"

namespace UGC {

#define UGLess std::less
#define UGGreater std::greater

//! \brief 字典类。
//! \remarks 类似于MFC中的CMap,内部采用stl的map实现。
template<typename Key, typename T, class Compare = std::less<Key> >
class  UGEXPORT UGDict 
{
public:
	typedef typename std::map<Key,T,Compare>::const_iterator POSITION;
	
public:
	//! \brief 默认构造函数。
	UGDict()	
	{

	}

	//! \brief 得到元素个数。
	//! \return 返回元素个数。
	UGint GetCount() const	
	{
		return (UGint)m_dict.size();
	}

	//! \brief 判断是否为空。
	//! \return 空返回true;非空返回false。
	UGbool IsEmpty() const	
	{
		return m_dict.empty();
	}

	//! \brief 从另一个字典拷贝。
	//! \param src 用于拷贝的字典[in]。
	void Copy(const UGDict<Key,T,Compare>& src)	
	{
		*this=src;
	}

	//! \brief 查找指定key的value元素。
	//! \param key 要查找的key[in]。
	//! \param rValue 得到的元素[out]。
	//! \return 查找成功返回true;不成功返回false。
	UGbool Lookup(const Key& key,T& rValue) const	
	{
		POSITION it=m_dict.find(key);		
		if(it!=m_dict.end())
		{
			rValue = it->second;
			return TRUE;
		}
		return FALSE;
	}

	//! jifang 添加于08/18/2005.
	//! \brief 通过key直接查找到元素的指针。
	//! \param key 要查找的key值[in]。
	//! \return 找到则返回指向UGDict内部的元素的指针, 不是拷贝;若没查到, 则返回空指针。
	const T* Lookup(const Key &key) const	
	{
		POSITION it=m_dict.find(key);		
		if(it!=m_dict.end())
		{
			return (const T*)(&it->second);
		}
		return NULL;
	}	

	//! \brief 给指定的key设置指定的元素。
	//! \param key 指定的键值[in]。
	//! \param newValue 指定的元素[in]。
	void SetAt(const Key& key,const T& newValue)	
	{
		operator[](key)=newValue;
	}

	//! \brief 通过指定的key得到对应元素的引用。
	//! \param key 指定的key值[in]。
	//! \return 返回对应元素的引用。
	const T& operator[](const Key& key) const	
	{
		return m_dict.operator [](key);
	}

	//! \brief 通过指定的key得到对应元素的引用。
	//! \param key 指定的key值[in]。
	//! \return 返回对应元素的引用。
	T& operator[](const Key& key) 
	{
		return m_dict.operator [](key);
	}

	//! \brief 移除key值对应的元素。
	//! \param key 要移除的key值[in]。
	//! \return 成功返回true;失败返回false。
	UGbool RemoveKey(const Key& key)	
	{
		return m_dict.erase(key)>0;
	}

	//! \brief 移除所有元素
	void RemoveAll()
	{
		m_dict.clear();
	}

	//! \brief 得到开始位置。
	//! \return 返回开始位置。
	//! \remarks 得到开始位置后,再通过GetNextAssoc函数就可以一个接着一个得到字典中所有的元素
	//! \attention 注意使用IsEOF函数判断不要超过字典的范围
	POSITION GetStartPosition() const	
	{
		return m_dict.begin();
	}

	//! \brief 判断传入的位置是否是字典尾。
	//! \param pos 要判断的位置[in]。
	//! \return 如果已到字典尾则发挥true;否则返回false。
	UGbool IsEOF(POSITION pos) const	
	{
		return pos==m_dict.end();
	}

	//! \brief 得到指定pos的key和元素,并把pos移动到下一个位置
	//! \param rNextPosition 指定的位置[in]。
	//! \param rKey 得到的key[out]。
	//! \param rValue 得到的元素[out]。
	void GetNextAssoc(POSITION& rNextPosition,Key& rKey,T& rValue) const	
	{
		UGASSERT(!IsEOF(rNextPosition));		
		rKey = rNextPosition->first;
		rValue = rNextPosition->second;
		++rNextPosition;
	}

private:
	std::map<Key,T,Compare> m_dict;
};

}

#endif


