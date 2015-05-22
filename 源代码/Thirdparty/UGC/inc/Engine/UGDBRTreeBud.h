/*! \file UGDBRTreeBud.h
 *  \brief R树芽结点类定义。
 *  \author 郭其超,陈俊华
 *  \bug

 *	<b>更新说明：</b>\n
	<em>1、2003-11-1 首次完成代码编写.\n</em>
*/  
#ifndef _INC_UGDBRTreeBud_3E9E4B130213_INCLUDED
#define _INC_UGDBRTreeBud_3E9E4B130213_INCLUDED



#include "UGDBRTreeNode.h"

namespace UGC
{
	class UGDBRTreeLeaf;
	class UGDBRTree;

/// \brief R树芽结点类，结点中的元素是指向items的索引数组
/// \remarks 父类UGDBRTreeNode
class  ENGINE_API UGDBRTreeBud : public UGDBRTreeNode   
{
public:
	UGDBRTreeBud();
	virtual ~UGDBRTreeBud();

public:
	virtual UGDBRTreeNode* Split( UGint nMaxItemCount,DBScanLineInfo *pScanLines) ;
	
	virtual UGDBRTreeNode* Split( UGint nMaxItemCount );

	virtual UGbool NeedSplit( UGint nMaxEntryCount );
	
	virtual UGint GetEntryCount();

	/// \brief 获取结点的类型
	/// \return 结点的类型
	/// \remarks 返回值是0
	virtual UGuchar GetType();

	virtual UGint GetDataSize();

public:
	/// \brief 演变出一个leaf结点
	/// \param pLeaf 指向演变出来的一个leaf结点对象
	/// \return 演变成功返回true，否则返回false
	UGbool GrowUp(UGDBRTreeLeaf* pLeaf);
	
	/// \brief 设置结点索引数组的指针和rtree的items指针
	/// \param pIndexes 结点索引数组的指针
	/// \param pItems rtree的items指针
	/// \remarks 不拷贝内存，只是简单的指针赋值
	void SetItems( UGArray<UGint>* pIndexes, UGDBRTreeNodeItems* pItems );
	
	/// \brief 计算结点所有元素的范围
	/// \remarks 
	void CalculateBound();

protected:

	/// \brief 选择一条合理的切割线
	/// \param nMaxItemCount 结点能容纳最多的元素数量
	/// \param pScanLines 扫描线数组
	/// \param nPosition 切割线位置
	/// \param bVertical 切割线方向，横向或者纵向
	/// \param nOldCount 按该切割线划分，该保留的结点数量
	/// \param nNewCount 按该切割线划分，该移除的结点数量
	/// \return 选择成功返回true，否则返回false
	/// \remarks 比较横向最佳和纵向最佳切割线，选择较好的一条
	UGbool ChooseCutLine( UGint nMaxItemCount,DBScanLineInfo *pScanLines,
						UGuint& nPosition, UGbool& bVertical, 
						UGint& nOldCount, UGint& nNewCount );
	
	/// \brief 选择一条合理的纵向切割线
	/// \param nMaxItemCount 结点能容纳最多的元素数量
	/// \param pScanLines 扫描线数组
	/// \param nPosition 切割线位置
	/// \param nOldCount 按该切割线划分，该保留的结点数量
	/// \param nNewCount 按该切割线划分，该移除的结点数量
	/// \return 选择成功返回true，否则返回false
	/// \remarks 以过切割线的所有对象组成的bound面积最小为标准
	UGulong ChooseVerticalCutLine( UGint nMaxItemCount,DBScanLineInfo *pScanLines,
									UGuint& nPosition,UGint& nOldCount, UGint& nNewCount );
	 
	/// \brief 选择一条合理的横向切割线
	/// \param nMaxItemCount 结点能容纳最多的元素数量
	/// \param pScanLines 扫描线数组
	/// \param nPosition 切割线位置
	/// \param nOldCount 按该切割线划分，该保留的结点数量
	/// \param nNewCount 按该切割线划分，该移除的结点数量
	/// \return 选择成功返回true，否则返回false
	/// \remarks 以过切割线的所有对象组成的bound面积最小为标准
	UGulong ChooseHorizontalCutLine( UGint nMaxItemCount, DBScanLineInfo *pScanLines,
									UGuint& nPosition,UGint& nOldCount, UGint& nNewCount );

	UGint GetOldItemCount( UGuint nPosition, UGbool bVertical );
	UGint GetNewItemCount( UGuint nPosition, UGbool bVertical );


	/// \brief 根据切割线的位置和方向，判断一个对象应该被保留还是被划分到新的结点内
	/// \param rcBound 对象的范围
	/// \param nPosition 切割线位置
	/// \param bVertical 切割线方向，横向或者纵向
	/// \return 对象应该保留则返回true，否则返回false
	UGbool BeSaved( const UGRectUInt& rcBound, UGuint nPosition, UGbool bVertical );
	
protected:
	//点，二分分包
	//返回 TRUE 表示分好了
	//返回 True 同时nPostion = 0 表示此包不能在分
	//pIndexes此为当前包的id的复制品，在这个函数内可能修改。
	UGbool DichotomyItems(UGArray<UGint>* pIndexes,UGuint &nPostion,UGuint nStartPos,UGuint nEndPos,UGbool bVertical,UGint nCount);
protected:
	/// \brief 指向所有元素的数组的指针
	UGDBRTreeNodeItems* m_pItems ;
	
	/// \brief 指向该结点包含的元素索引的数组
	/// \remark example: 
	/// \remark		获取第nIndex个元素
	/// \remark		m_pItems->ElementAt(m_pIndexes->GetAt(nIndex))
	UGArray<UGint>* m_pIndexes;

};
}


#endif /* _INC_DBRTreeBud_3E9E4B130213_INCLUDED */
