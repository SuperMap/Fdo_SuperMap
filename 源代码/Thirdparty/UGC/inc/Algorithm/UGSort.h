/* 修改说明：
 *		2007.09.21	guohui	为本头文件添加注释
 */
#ifndef UGSORT_H
#define UGSORT_H
#include "Base/ugdefs.h"

namespace UGC {

using namespace std;
template<typename T>

class UGEXPORT UGSort  
{
public:

	//! \brief				快速排序\n	
	//! \param pSort		模版类指针
	//! \param nFIndex		起始索引
	//! \param nTIndex		终止nTIndex
	//! \param IsAscending	是否升序
	//! \remarks			成功:序列pSort在[nFIndex,nTIndex]之间的元素按IsAscending顺序排序
	//! \remarks			如果T不是内置类型，则T内部必须提供"<"重载符,谨记！
	static void QSort(T* pSort, UGint nFIndex, UGint nTIndex, UGbool IsAscending = TRUE)
	{
		std::sort(pSort+nFIndex, pSort+nTIndex+1);
		
		if (!IsAscending)
		{
			std::reverse(pSort+nFIndex,pSort+nTIndex+1);
		}
	}
	
	//! \brief				局部快速排序\n	
	//! \param pSort		模版类指针
	//! \param nFIndex		起始索引
	//! \param nMIndex		中间索引
	//! \param nCount		pSort的长度
	//! \param IsAscending	是否升序
	//! \return				成功:序列pSort在[nFIndex,nMIndex]之间的元素按IsAscending顺序排序
	//! \remarks 			该方法对整个序列做部分排序，被排序的元素的个数正好可以放到[nFIndex,nMIndex]范围
	//! \remarks 			内，在[nMIndex，nCount)中的元素是未经排序的，它们都落在实际被排序的序列之外；
	//! \remarks 			如果T不是内置类型，则T内部必须提供"<"重载符,谨记！
	static void PartialSort(T* pSort, UGint nFIndex, UGint nMIndex, UGint nCount, UGbool IsAscending = TRUE)
	{
		std::partial_sort(pSort+nFIndex, pSort+nMIndex+1, pSort+nCount);
		
		if (!IsAscending)//在没有实现min_heap之前先这样实现吧；
		{
			std::sort(pSort+nFIndex, pSort+nCount);
			std::reverse(pSort+nFIndex,pSort+nCount);
			
			//=============利用heap实现===============
			/*
			std::make_heap(pSort+nFIndex, pSort+nMIndex+1);
			for (UGint i=nMIndex+1; i < nCount; i++)
			{
				if ((*pSort) < (*(pSort+i)))
				{
					//_Pop_heap();
				}
			}
			std::sort_heap(pSort+nFIndex, pSort+nMIndex+1);
			std::reverse(pSort+nFIndex,pSort+nMIndex+1);*/
			//=============利用heap实现===============
		}
	}
	
	//! \brief				归并排序\n	
	//! \param pSort1,2		模版类指针
	//! \param nFIndex1,2	起始索引
	//! \param nTIndex1,2	终止索引
	//! \param pSort		结果模版指针
	//! \param IsAscending	是否升序
	//! \return	
	//! \remarks			把两个经过排序的集合pSort1和pSort2，合并起来置于另一段空间;所得结果也是一个有序序列。
	//!						  如果T不是内置类型，则T内部必须提供"<"重载符,谨记！
	static void MergeSort(T* pSort1, UGint nFIndex1, UGint nTIndex1,
						  T* pSort2, UGint nFIndex2, UGint nTIndex2,
						  T* pSort, UGbool IsAscending = TRUE)
	{
		std::merge(pSort1+nFIndex1, pSort1+nTIndex1+1,
					pSort2+nFIndex2, pSort2+nTIndex2+1, pSort);
		
		if (!IsAscending)
		{
			std::reverse(pSort, pSort + nTIndex1+1-nFIndex1 + nTIndex2+1-nFIndex2);
		}
	}
};


}

#endif


