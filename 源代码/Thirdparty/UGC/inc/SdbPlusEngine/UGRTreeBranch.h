/*! \file UGRTreeBranch.h
 *  \brief R树内部结点类的定义。
 *  \author 郭其超,陈俊华
 *  \bug

 *	<b>更新说明：</b>\n
	<em>1、2003-11-1 首次完成代码编写.\n</em>
*/  
#ifndef _INC_CSmRTreeBranch_3E9E4B130207_INCLUDED
#define _INC_CSmRTreeBranch_3E9E4B130207_INCLUDED


#include "UGRTreeNode.h"

namespace UGC{

/// \brief R树内部结点类，结点中的元素是其他结点
/// \remarks 父类UGRTreeNode
class UGRTreeBranch : public UGRTreeNode    
{	
public:
	UGRTreeBranch();
	virtual ~UGRTreeBranch();

public:

	/// \brief 把结点的数据保存到内存数组中。
	/// \param arData 用来保存结点的数组。
	/// \return 成功则返回TRUE。
	virtual UGbool Store(UGMemoryStream& arData);

	/// \brief 从内存数组中载入结点的数据。
	/// \param arData 保存着结点数据。
	/// \param nPos 从数组的nPos位置开始读取数据
	/// \return  成功则返回TRUE。
	virtual UGbool Load(UGMemoryStream &arData);

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
	UGRTreeNode* GetChildAt( UGint nIndex );

	/// \brief 添加一个子结点
	/// \param pChildNode 要添加的子结点指针
	/// \return 添加后子结点的数量
	UGint AddChild( UGRTreeNode* pChildNode );

	/// \brief 结点繁衍
	/// \param nMaxItemCount 结点能容纳最多的元素数量
	/// \param pScanLines 扫描线数组
	/// \return 繁衍成功返回true，否则返回false
	UGbool Breed( UGint nMaxItemCount,RScanLineInfo *pScanLines);

	/// \brief 结点成熟，结点下的所有类型是bud的结点演变为leaf
	/// \return 演变成功返回true，否则返回false
	UGbool GrowUp();

	/// \brief 获取结点占用内存的字节数
	/// \return 结点占用内存的字节数
	/// \remarks 包括其所有子结点占用的内存字节数
	UGint GetDataSize();

	/// \brief 在结点下查询
	/// \param rcBound 查询的范围
	/// \param arCertainIDs 查询的确定结果ID数组
	/// \param arMaybeIDs 查询的可能结果ID数组
	/// \return  查询到的对象的数量			
	virtual UGbool Query(const UGRect2D& rcBound, UGArray<UGint> &arCertainIDs, UGArray<UGint> &arMaybeIDs);

	/// \brief 获取该结点下的所有对象的ID
	/// \param arIDs 用来保存获取到的ID
	/// \return 成功则返回TRUE。
	UGbool GetAllIDs( UGArray<UGint> &arIDs );

public:
	/// \brief 测试使用，取出R树所有叶子节点的范围。
	void GetAllLeafBounds( UGArray<UGRect2D> &arBounds );

protected:
	/// \brief 子结点指针数组
	UGArray<UGRTreeNode*> m_arChildren;

};

}

#endif /* _INC_CSmRTreeBranch_3E9E4B130207_INCLUDED */
