/* 
	\file UGBitArray.h
	\brief 位数组。
	\author jifang
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>更新说明：。</b>
	<em>1、把UGbool改为bool by zengzm。确认一个size只占用一个bit,std::vector<bool>内部会处理好</em>
	<em>2、第二条说明。</em>
*/
	
#if !defined(UGBITARRAY_H_)
#define UGBITARRAY_H_

#include "Base/ugdefs.h"
#include <vector>

namespace UGC {

//! \brief 位数组类,用法和UGArray非常类似。
//! \remarks 内部采用std::vector<bool>实现,每个bool元素仅占用一个位,以减少内存占用的空间。
class BASE_API UGBitArray 
{
public:
	//! \brief 构造函数。
	//! \param n 元素个数[in]。
	//! \param b 每个元素的初始值[in]。
	UGBitArray(UGint n = 0, bool b = FALSE);	
	
	//! \brief 拷贝构造函数。
	//! \param bitArray 用来构造新对象的bitArray[in]。
	UGBitArray(const UGBitArray & bitArray);	
	
	//! \brief 析构函数。
	~UGBitArray();	
	
	//! \brief 拷贝赋值函数。
	//! \param bitArray 用来给对象进行赋值的bitArray[in]。
	//! \return 赋值后该对象的引用,以支持连点。
	UGBitArray &operator=(const UGBitArray &bitArray);	

	//! \brief 返回容器所含元素数量.
	//! \return 元素个数
	UGint GetSize() const;
	
	//! \brief 设置元素个数, 比原来大的部份用参数b填充, 如果比原来小, 自动截断.
	//! \param n 元素个数[in]。
	//! \param b 如果数组扩展,增加部分元素的值 [in]。
	void SetSize(UGint n, bool b = FALSE);	

	//! \brief 得到指定索引的元素值
	//! \param i 指定的索引[in]。
	//! \return 返回指定元素的bool值。
	//! \remarks 索引值如果越界, 抛出out_of_range异常。
	bool GetAt(UGint i) const;	
	
	//! \brief 设置指定索引的元素的bool值。
	//! \param i 指定的索引[in]。
	//! \param b 指定的bool值[in]。
	//! \remarks 索引值如果越界, 抛出out_of_range异常.。
	void SetAt(UGint i, bool b);	
	
	//! \brief 得到指定索引元素的bool值
	//! \param i 指定的索引[in]。
	//! \return 返回指定索引元素的bool值。
	//! \remarks 对索引值没有边界检查, 由调用者保证.。
	bool operator[](UGint i);	
	
	//! \brief 在最后增加一个元素。
	//! \param b 增加的元素的值[in]。
	//! \return 返回这个元素的索引(从0起)。
	UGint Add(bool b);	
	
	//! \brief 在数组最后增加另一个数组。
	//! \param bitArray 要增加的数组[in]。
	//! \return 返回新添加元素的起始位置。
	UGint Append(const UGBitArray &bitArray);	
	
	//! \brief 在指定的索引前插一个元素。
	//! \param nIndex 指定的索引[in]。
	//! \param b 要插入的元素[in]。
	void InsertAt(UGint nIndex, bool b);	
	
	//! \brief 在指定的索引前插UGBitArray对象。
	//! \param nIndex 指定的索引[in]。
	//! \param bitArray 要插入的数组[in]。
	void InsertAt(UGint nIndex, const UGBitArray &bitArray);	
	
	//! \brief 得到整体存储空间大小
	//! \return 返回整体存储空间大小
	//! \remarks 整体存储空间大小=已有元素大小+预备空间大小
	UGint GetCapacity() const;
	
	//! \brief 设置整体存储空间大小
	//! \param nCapacity 要设置的大小[in]。
	//! \remarks 无论设置的值为多少,都不会导致已有的空间被缩小;更不会导致小于已有元素的大小。
	void SetCapacity(UGint nCapacity);	
	
	//! \brief 移除所有元素, 释放容量.
	void RemoveAll();
	
	//! \brief 释放多余存储空间.
	//! \remarks 内部通过新分配一个数组,然后进行交换实现
	void FreeExtra();
private:
	//! \brief 内部实现用的stl的vector<bool>
	std::vector<bool> m_bitvect;
};

}

#endif // UGBITARRAY_H_

