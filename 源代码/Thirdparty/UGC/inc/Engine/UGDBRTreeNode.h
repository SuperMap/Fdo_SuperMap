/*! \file UGDBRTreeNode.h
 *  \brief R树结点抽象类以及相关类型的定义。
 *  \author 郭其超,陈俊华
 *  \bug

 *	<b>更新说明：</b>\n
	<em>1、2003-11-1 首次完成代码编写.\n</em>
*/  
#ifndef _INC_UGDBRTREENODE_3E9E4B130201_INCLUDED
#define _INC_UGDBRTREENODE_3E9E4B130201_INCLUDED
#include "Base/ugdefs.h"
#include "Algorithm/UGRectUInt.h"
#include "Algorithm/UGRect2D.h"
#include "Base/UGArray.h"

namespace UGC
{
#ifndef SM_DWORD_GRIDS
#define SM_DWORD_GRIDS 4294967295
#endif

//class UGLongArray;

/// \brief 建立R树所需要的数组元素的结构
class  ENGINE_API UGDBRTreeNodeItem
{
public:
	/// \brief 对象的ID
	UGint m_nID ;

	/// \brief 对象的范围
	UGuint m_rcLeft;
	UGuint m_rcTop;
	UGuint m_rcRight;
	UGuint m_rcBottom;
public:
	UGRectUInt GetBound()
	{
		return UGRectUInt(m_rcLeft,m_rcTop,m_rcRight,m_rcBottom);
	}

	/// \brief 把结点的数据保存到内存数组中。
	/// \param arData 用来保存结点的数组。
	/// \return 成功则返回TRUE。
	virtual UGbool Store(UGStream &stream);

	/// \brief 从内存数组中载入结点的数据。
	/// \param arData 保存着结点数据。
	/// \return  成功则返回TRUE。
	virtual UGbool Load(UGStream &stream);
};

class ENGINE_API UGDBRTreeNodeItems
{
public:
	UGint GetSize();
	/// \brief 把结点的数据保存到内存数组中。
	/// \param arData 用来保存结点的数组。
	/// \return 成功则返回TRUE。
	virtual UGbool Store(UGStream &stream);

	/// \brief 从内存数组中载入结点的数据。
	/// \param arData 保存着结点数据。
	/// \return  成功则返回TRUE。
	virtual UGbool Load(UGStream &stream);

	UGbool Sort();
public:
	UGArray<UGDBRTreeNodeItem> m_aryDBRTreeNodeItems;
};

/// \brief 建立R树所需要的数组元素的结构
class  ENGINE_API UGDBRTreeOutNodeItem
{
public:
	/// \brief 对象的ID
	UGint m_nID ;
	/// \brief 对象的范围
	UGRect2D m_rc2Bound;
public:
	/// \brief 把结点的数据保存到内存数组中。
	/// \param arData 用来保存结点的数组。
	/// \return 成功则返回TRUE。
	virtual UGbool Store(UGStream &stream);

	/// \brief 从内存数组中载入结点的数据。
	/// \param arData 保存着结点数据。
	/// \return  成功则返回TRUE。
	virtual UGbool Load(UGStream &stream);


};

typedef UGArray<UGDBRTreeOutNodeItem> UGDBRTreeOutNodeItems;



/// \brief 建立R树的过程中，分割线的数据结构
typedef struct tagDBScanLineInfo	
{
	tagDBScanLineInfo()
	{
		ub8Area = 0;
		nNewCount = 0;
		nOldCount = 0;				
	}
	/// \brief 分割线穿过的所有对象面积总和
	UGulong ub8Area;
	
	/// \brief 分割线右边或者上边的对象的数量
	UGint nNewCount;
	
	/// \brief 分割线左边或者下边的对象的数量
	UGint nOldCount;
}DBScanLineInfo;
 
/// \brief R树结点抽象类
/// \remark UGDBRTreeBranch、UGDBRTreeLeaf、UGDBRTreeBud的父类
class ENGINE_API  UGDBRTreeNode 
{
public:
	UGDBRTreeNode();
	virtual ~UGDBRTreeNode();

public:
	/// \brief 获取结点内元素的数量
	/// \return 结点内元素的数量
	/// \remarks 纯虚函数，由子类实现
	virtual UGint GetEntryCount() = 0;

	/// \brief 获取结点的类型
	/// \return 结点的类型 0： bud，1： branch，2： leaf
	/// \remarks 纯虚函数，由子类实现
	virtual UGuchar GetType() = 0;
	
	/// \brief 获取结点占用内存的字节数
	/// \return 结点占用内存的字节数
	/// \remarks 纯虚函数，由子类实现
	/// \remarks 包括其所有子结点占用的内存字节数
	virtual UGint GetDataSize() = 0;
	
	/// \brief 把结点的数据保存到内存数组中。
	/// \param arData 用来保存结点的数组。
	/// \return 成功则返回TRUE。
	virtual UGbool Store(UGStream &stream);

	/// \brief 从内存数组中载入结点的数据。
	/// \param arData 保存着结点数据。
	/// \return  成功则返回TRUE。
	virtual UGbool Load(UGStream &stream);

	/// \brief 获取该结点下的所有对象的ID
	/// \param arIDs 用来保存获取到的ID
	/// \return 成功则返回TRUE。
	virtual UGbool GetAllIDs( UGArray<UGint> &arIDs );

	/// \brief 获取该结点下的所有叶节点的ID
	/// \return 成功则返回TRUE。
	virtual UGbool GetAllLeafIDs( UGArray<UGint> &/*arLeafIDs*/ ){return FALSE;};



	/// \brief 查询该结点
	/// \param rcBound 查询的范围
	/// \param arIDs 查询的结果ID数组
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


	/// \brief 判断结点是否需要分割
	/// \param nMaxEntryCount 结点能容纳最多的元素数量
	/// \return 需要分割返回TRUE，否则返回FALSE
	/// \remarks 结点内元素大于上限则表明需要分割
	virtual UGbool NeedSplit( UGint nMaxEntryCount );

	/// \brief 分割结点
	/// \param nMaxItemCount 结点能容纳最多的元素数量
	/// \param pScanLines 扫描线数组
	/// \return 分割出来的新的结点
	virtual UGDBRTreeNode* Split( UGint nMaxItemCount,DBScanLineInfo *pScanLines);
	
	virtual UGDBRTreeNode* Split( UGint nMaxItemCount );
public:
	/// \brief 获取结点的范围
	/// \return 结点的范围
	UGRectUInt GetBound() const
	{
		return m_rcBound;
	}

	/// \brief 设置结点的范围
	/// \param 结点的范围
	void SetBound(const UGRectUInt& rcBound)
	{
		m_rcBound = rcBound;
	}

protected:
	/// \brief 结点的范围
	UGRectUInt m_rcBound;
};

}

#endif /* _INC_UGDBRTREENODE_3E9E4B130201_INCLUDED */
