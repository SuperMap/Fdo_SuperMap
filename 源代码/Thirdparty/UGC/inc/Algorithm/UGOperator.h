/**  
   \file		UGOperator.h

   \brief		一些基础的算法，比如，二分查找、排序等。

   \author		guohui

   \attention 

   Copyright(c) 1996-2007 SuperMap GIS Technologies, Inc.<br>

   All Rights Reserved.

   \version 2.0

      <b>更新说明：</b>\n

<em>1、第一条说明。\n

<em>2、第二条说明。\n

 */ 

#ifndef UGOPERATOR_H
#define UGOPERATOR_H
#include "Base/ugdefs.h"
#include "Base/UGArray.h"

namespace UGC {

class UGEXPORT UGOperator  
{
private:
	
	UGOperator();

public:

	//! \brief				二分查找比 dID 小的第一个数
	//! \param dID			传入的数
	//! \param arrIDs		数列。数列必须是降序排列的。
	//! \param nCount		数列个数
	//! \remarks			如果不存在比 dID 小的数，则返回-1；否则返回索引(从0开始)
	static UGint FindIndexByDecreaseArray(UGdouble dID, const UGdouble* arrIDs, UGint nCount);

	//! \brief				二分查找比 dID 大的第一个数
	//! \param dID			传入的数
	//! \param arrIDs		数列。数列必须是升序排列的。
	//! \param nCount		数列个数
	//! \remarks			如果不存在比 dID 大的数，则返回-1；否则返回索引(从0开始)
	static UGint FindIndexByIncreaseArray(UGdouble dID, const UGdouble* arrIDs, UGint nCount);

	//! \brief				寻找数列中的最大单调递增子列
	//! \param arrSrc		传入的数列
	//! \param arrSubIndex	传出的索引(从0开始)
	//! \remarks			最大单调递增子列：假定数列 A = {a(i)}(n>i>=0)中任意递增子列B = {b(j)}，b(j)属于A
	//!						，b(j+1)>b(j)>b(j-1).同时，b(j)在A中的位置大于b(j-1)在A中的位置。当子列B的数列个数
	//!						达到最大，B子列就是数列A的最大单调递增子列
	static UGbool FindSubIncreaseArray(const UGArray <UGdouble> &arrSrc, UGArray <UGint> &arrSubIndex);

	//! \brief				寻找数列中的最大单调递减子列
	//! \param arrSrc		传入的数列
	//! \param arrSubIndex	传出的索引(从0开始)
	//! \remarks			最大单调递增子列：假定数列 A = {a(i)}(n>i>=0)中任意递增子列B = {b(j)}，b(j)属于A
	//!						，b(j+1)<b(j)<b(j-1).同时，b(j)在A中的位置大于b(j-1)在A中的位置。当子列B的数列个数
	//!						达到最大，B子列就是数列A的最大单调递减子列
	static UGbool FindSubDecreaseArray(const UGArray <UGdouble> &arrSrc, UGArray <UGint> &arrSubIndex);

	//! \brief				快速排序 UGint 型数组 
	static void QuickSort(UGint  *l, UGint nStart, UGint nEnd);  

	//! \brief				快速排序 UGint 型数组 
	static void QuickSort(UGdouble *d, UGint nStart, UGint nEnd);
	
	static UGint FindInsertPos(UGint nID, UGint* pIDs, UGint nCount);
	
	static UGint FindIndex(UGint nID, UGint* pIDs, UGint nCount);

private:

	//! \brief				快速排序double型数组时找支点
	static UGdouble Median(UGdouble *d, UGint nStart, UGint nEnd);

	//! \brief				快速排序double型数组时找支点
	static UGint Median(UGint *l, UGint nStart, UGint nEnd);
};

}

#endif


