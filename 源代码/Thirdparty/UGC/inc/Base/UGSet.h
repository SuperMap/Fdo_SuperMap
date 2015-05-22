/* 
	\file UGSet.h
	\brief 集合类,保证集合类的元素都不一样,基本等同于stl中的set。
	\author zengzm
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>更新说明：。</b>
	<em>1、第一条说明。</em>
	<em>2、第二条说明。</em>
*/
	// UGSet.h: interface for the UGSet class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGSET_H__61360F7F_9E23_4E6C_8B5F_BF3473B8A87F__INCLUDED_)
#define AFX_UGSET_H__61360F7F_9E23_4E6C_8B5F_BF3473B8A87F__INCLUDED_

#include "ugdefs.h"

namespace UGC {

//! \brief 集合类,保证集合类的元素都不一样,基本等同于stl中的set
//! \remarks 内部采用set实现
//! \attention 暂时还用不到这个类, 暂不实现, 需要时或有足够资源时再做
template<typename T>
class UGEXPORT UGSet  
{
public:
	//! \brief 默认构造函数
	UGSet();

	//! \brief 往集合中增加一个元素
	//! \return 返回是否成功加入, 如果该元素已经在集合中存在,则加入失败
	UGbool Add(const T& value);

	//! \brief 在集合中查找某元素是否存在
	//! \return 存在返回true,不存在返回false
	UGbool Find(const T& value);

	//! \brief 得到集合中元素的个数
	UGint GetSize();

	//! \brief 从集合中移除某元素
	//! \return 成功返回true;失败返回false,例如该元素不存在
	UGbool Remove(const T& value);

	//! \brief 清空整个集合
	void RemoveAll();

	// 和集合相关的几个静态函数

	static Union();
	//static 

private:
	std::set<T> m_set;
};

#endif // !defined(AFX_UGSET_H__61360F7F_9E23_4E6C_8B5F_BF3473B8A87F__INCLUDED_)
