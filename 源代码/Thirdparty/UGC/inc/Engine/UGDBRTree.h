/*! \file UGDBRTree.h
 *  \brief R树类的定义.
 *  \author 郭其超,陈俊华
 *  \bug

 *	<b>更新说明：</b>\n
	<em>1、2003-11-1 首次完成代码编写.\n</em>
*/   

#ifndef _INC_UGDBRTREE_3E9E4B130220_INCLUDED
#define _INC_UGDBRTREE_3E9E4B130220_INCLUDED


#include "UGDBRTreeNode.h"
#include "UGDatasetVector.h"

#define SM_QUAD_KEY_START		0
#define SM_QUAD_KEY_END			255
#define SM_GRID_KEY_START		256
#define SM_GRID_KEY_END			267
#define SM_RTREE_KEY_START		512
#define SM_INVALID_KEY			-1
#define SM_DEFAULT_KEY			-2


struct UGRTreeQuery{

};


namespace UGC{

class UGDBRTreeBranch;
class UGDBRTreeLeaf;
	
///	\brief	UGDBRTree，提供R树的创建,查询,保存,读取等功能。
/// \remark	R树的实现方法与传统的R树有很大不同,节点的划分更加合理。
class ENGINE_API UGDBRTree 
{
public:
	/// \brief 默认构造函数
	UGDBRTree();
	/// \brief 默认析构函数
	virtual ~UGDBRTree();

public: 
	UGint GetNextLeafID();
	UGDatasetVector * GetVector();
	void SetVector(UGDatasetVector * pVector);
	
	/// \brief 创建一个R树
	/// \param pItems 用来创建R树的所有对象的Bound和ID的数组。
	/// \param rc2Bounds 所有对象范围。
	/// \param nQuality R树的质量，取值范围[1,10],值越小，R树质量越高，创建时间也越长。
	/// \return 创建成功返回TRUE,否则返回FALSE.
	/// \remarks 调用这个函数以后，生成新的R树前，会删除原来的R树
	UGbool Create( UGDBRTreeNodeItems* pItems,const UGRect2D& rc2Bounds, UGuint nQuality = 5, UGbool bPointDataset = false );

	//! \brief 创建一个R树
	//! \param pItems 用来创建R树的所有对象的Bound和ID的数组
	//! \param rc2Bounds 所有对象范围
	//! \param bPointDataset  
	//! \return 
	//! \remarks 此方法目的是创建一个超大数据量的R 树，提高速度。。。。。
	//! \attention 
	UGbool Create2( UGDBRTreeNodeItems* pItems,const UGRect2D& rc2Bounds,UGuint nQuality = 5 );	

	/// \brief 删除R树中的一个对象
	/// \param UGRectUInt 对象的范围
	/// \param nID 对象的ID
	UGbool Delete(const UGRectUInt& rcBounds,UGint nID);

	/// \brief 销毁R树并释放占用的内存。
	void Destroy();
	
	/// \brief 在R树中查询
	/// \param rcBound 查询的范围
	/// \param arIDs 查询的结果ID数组
	/// \return  查询到的对象的数量
	UGint Query(const UGRect2D& rcBound, 
			   UGRectUInt & rcDWBound,
			   UGArray<UGint> &arCertainLeafIDs,
			   UGArray<UGint> &arMaybeLeafIDs);


	/// \brief 在R树中查询
	/// \param rcBound 查询的范围
	/// \param arIDs 查询的结果ID数组
	/// \return  查询到的对象的数量
	UGint Query(const UGRect2D& rcBound, 
			   UGRectUInt & rcDWBound,
			   UGArray<UGint> &arCertainLeafIDs,
			   UGArray<UGRectUInt> &aryCertainBounds,
			   UGArray<UGint> &arMaybeLeafIDs,
			   UGArray<UGRectUInt> &aryMaybeBounds,
			   UGdouble dGranule);

	UGint Query(const UGRect2D& SearchBounds,
				const UGRect2D& rcReferenceBounds,
				UGbool bFuzzy,
				UGdouble dGranule,
				UGArray<UGint> &aryItemIDs);

	UGint QueryContainedByLeafID(const UGRect2D& rc2Bounds,UGArray<UGint> & aryLeafIDs);

	/// \brief 得到R树的范围
	/// \return  R树索引的范围
	UGRect2D GetBound();

	/// \brief 得到R树占用内存的大小
	/// \return  R树占用内存的数量，以字节为单位。
	UGint GetDataSize();

	/// \brief 从内存数组中载入R树数据并构建R树。
	/// \param arData R树数据。
	/// \return  成功则返回TRUE。
	UGbool Load(UGStream &stream);

	/// \brief 把R树数据保存到内存数组中。
	/// \param arData 用来保存R树的数组。
	/// \return  成功则返回TRUE。
	UGbool Store(UGStream &stream);

	/// \brief 测试使用，取出R树所有叶子节点的范围。
	void GetAllLeafBounds( UGArray<UGRectUInt> &arBounds );
	
	/// \brief 测试使用，取出R树所有叶子节点的范围。
	void GetAllLeafBounds2( UGArray<UGRectUInt> &arBounds );

	//! 
	UGbool GetLeafBounds( UGint nID,UGRectUInt &rcBounds);

public:
	static UGDBRTree * m_pTree;

protected:
	//! \brief 平衡R树
	//! \param pItems [in]。
	//! \param rc2Bounds [in]。
	//! \param false [in]。
	//! \return 。
	//! \remarks 传入索引包结构，重构R树
	//! \attention 。
	UGbool BalanceRTree(UGDBRTreeNodeItems* pItems,const UGRect2D& rc2Bounds,UGbool bPointDataset = false);	

	/// \brief	R树的根结点，保存普通的对象
	UGDBRTreeBranch* m_pRootNormal;
	/// \brief	R树的根结点，保存较大的对象
	UGDBRTreeBranch* m_pRootBig;

	UGint m_nLeafID;
	UGDatasetVector * m_pVector;
public:
	UGRect2D m_rc2Bounds;
	UGuint m_nMemoryUsed;
	UGuint m_nMaxItemCount;
	UGuint m_nBigItemCount;

};

}

#endif /* _INC_UGDBRTREE_3E9E4B130220_INCLUDED */
