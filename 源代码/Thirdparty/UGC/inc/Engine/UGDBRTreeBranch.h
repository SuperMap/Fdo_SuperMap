 /*! \file UGDBRTreeBranch.h
 *  \brief R树内部结点类的定义。
 *  \author 郭其超,陈俊华
 *  \bug

 *	<b>更新说明：</b>\n
	<em>1、2003-11-1 首次完成代码编写.\n</em>
*/  
#ifndef _INC_UGDBRTreeBranch_3E9E4B130207_INCLUDED
#define _INC_UGDBRTreeBranch_3E9E4B130207_INCLUDED


#include "UGDBRTreeNode.h"

namespace UGC
{

/// \brief R树内部结点类，结点中的元素是其他结点
/// \remarks 父类UGDBRTreeNode
class  ENGINE_API UGDBRTreeBranch : public UGDBRTreeNode    
{	
public:
	UGDBRTreeBranch();
	virtual ~UGDBRTreeBranch();

public:

	/// \brief 把结点的数据保存到内存数组中。
	/// \param arData 用来保存结点的数组。
	/// \return 成功则返回TRUE。
	virtual UGbool Store(UGStream &stream);

	/// \brief 从内存数组中载入结点的数据。
	/// \param arData 保存着结点数据。
	/// \param nPos 从数组的nPos位置开始读取数据
	/// \return  成功则返回TRUE。
	virtual UGbool Load(UGStream &stream);

	/// \brief 判断结点是否需要分割
	/// \param nMaxEntryCount 结点能容纳最多的元素数量
	/// \return 需要分割返回TRUE，否则返回FALSE
	/// \remarks 结点内元素大于上限则表明需要分割
	virtual UGbool NeedSplit( UGint nMaxEntryCount );
	
	/// \brief 获取结点内元素的数量
	/// \return 结点内元素的数量
	virtual UGint GetEntryCount();

	/// \brief 获取结点的类型
	/// \return 结点的类型
	/// \remarks 返回值是1
	virtual UGuchar GetType();

public:

	/// \brief 获取子结点的指针
	/// \param nIndex 子结点的索引
	/// \return 指定索引的子结点指针
	/// \remarks 外部不能删除返回的指针
	UGDBRTreeNode* GetChildAt( UGint nIndex );

	/// \brief 添加一个子结点
	/// \param pChildNode 要添加的子结点指针
	/// \return 添加后子结点的数量
	UGint AddChild( UGDBRTreeNode* pChildNode );

	/// \brief 结点繁衍
	/// \param nMaxItemCount 结点能容纳最多的元素数量
	/// \param pScanLines 扫描线数组
	/// \return 繁衍成功返回true，否则返回false
	UGbool Breed( UGint nMaxItemCount,DBScanLineInfo *pScanLines);

	/// \brief 结点成熟，结点下的所有类型是bud的结点演变为leaf
	/// \return 演变成功返回true，否则返回false
	UGbool GrowUp();

	/// \brief 获取结点占用内存的字节数
	/// \return 结点占用内存的字节数
	/// \remarks 包括其所有子结点占用的内存字节数
	UGint GetDataSize();

	/// \brief 在结点下查询, arIDs 查询的结果ID数组
	/// \param rcBound 查询的范围
	/// \return  查询到的对象的数量			
	virtual UGbool Query(const UGRectUInt& rcBound, 
					   UGArray<UGint> &arCertainLeafIDs,
					   UGArray<UGint> &arMaybeLeafIDs);

	virtual UGbool Query(const UGRectUInt& rcBound,
						UGArray<UGint> &arCertainLeafIDs,
						UGArray<UGRectUInt> &aryCertainBounds,
						UGArray<UGint> &arMaybeLeafIDs,
						UGArray<UGRectUInt> &aryMaybeBounds,
						UGuint nGranule);

	virtual UGbool Query(const UGRectUInt& rcBound,
						const UGRectUInt& rcReferenceBound,
						UGbool bFuzzy,
						UGuint nGranule,
						UGArray<UGint> &aryItemIDs,
						UGArray<UGint> &arCertainLeafIDs,
						UGArray<UGint> &arMaybeLeafIDs);

	virtual UGbool QueryContainedByLeafID(const UGRectUInt& rcBound,UGArray<UGint> & aryLeafIDs);


	/// \brief 获取该结点下的所有对象的ID
	/// \param arIDs 用来保存获取到的ID
	/// \return 成功则返回TRUE。
	UGbool GetAllIDs( UGArray<UGint> &arIDs );

	/// \brief 获取该结点下的所有叶节点的ID
	/// \param arLeafIDs 用来保存获取到的ID
	/// \return 成功则返回TRUE。
	virtual UGbool GetAllLeafIDs( UGArray<UGint> &arLeafIDs );

	/// \brief 获取该结点下的所有叶节点的ID
	/// \param arLeafIDs 用来保存获取到的ID
	/// \return 成功则返回TRUE。
	virtual UGbool GetAllLeafIDs( UGArray<UGint> &arLeafIDs,
		UGArray<UGRectUInt> &aryLeafBounds,
		UGuint nGranule);

public:
	/// \brief 测试使用，取出R树所有叶子节点的范围。
	void GetAllLeafBounds( UGArray<UGRectUInt> &arBounds );

	UGbool GetLeafBounds( UGint nID,UGRectUInt &rcBounds);

protected:
	/// \brief 子结点指针数组
	UGArray<UGDBRTreeNode*> m_arChildren;

};

}

#endif /* _INC_UGDBRTreeBranch_3E9E4B130207_INCLUDED */
