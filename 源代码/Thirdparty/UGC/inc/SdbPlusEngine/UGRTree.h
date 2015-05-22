/*! \file UGRTree.h
 *  \brief R树类的定义.
 *  \author 郭其超,陈俊华
 *  \bug

 *	<b>更新说明：</b>\n
	<em>1、2003-11-1 首次完成代码编写.\n</em>
*/   

#ifndef _INC_SMRTREE_3E9E4B130220_INCLUDED
#define _INC_SMRTREE_3E9E4B130220_INCLUDED

#include "Base/UGArray.h"
#include "Algorithm/UGRect2D.h"

#include "UGRTreeNode.h"


namespace UGC{

class UGRTreeBranch;


///	\brief	UGRTree，提供R树的创建,查询,保存,读取等功能。
/// \remark	R树的实现方法与传统的R树有很大不同,节点的划分更加合理。
class UGRTree 
{
public:
	/// \brief 默认构造函数
	UGRTree();
	/// \brief 默认析构函数
	virtual ~UGRTree();

public: 
	
	/// \brief 创建一个R树
	/// \param pItems 用来创建R树的所有对象的Bound和ID的数组。
	/// \param rcBound 所有对象范围。
	/// \param nQuality R树的质量，取值范围[1,10],值越小，R树质量越高，创建时间也越长。
	/// \return 创建成功返回TRUE,否则返回FALSE.
	/// \remarks 调用这个函数以后，生成新的R树前，会删除原来的R树
	UGbool Create( UGRTreeNodeItems* pItems,const UGRect2D& rcBound, UGuint nQuality = 5, UGbool bPointDataset = false );

	/// \brief 删除R树中的一个对象
	/// \param UGRect2D 对象的范围
	/// \param nID 对象的ID
	UGbool Delete(const UGRect2D& rcBounds,UGint nID);

	/// \brief 销毁R树并释放占用的内存。
	void Destroy();
	
	/// \brief 在R树中查询
	/// \param rcBound 查询的范围
	/// \param arIDs 查询的结果ID数组
	/// \return  查询到的对象的数量
	UGint Query(const UGRect2D& rcBound, UGArray<UGint> &arCertainIDs, UGArray<UGint> &arMaybeIDs );

	/// \brief 得到R树的范围
	/// \return  R树索引的范围
	UGRect2D GetBound();

	/// \brief 得到R树占用内存的大小
	/// \return  R树占用内存的数量，以字节为单位。
	UGint GetDataSize();

	/// \brief 从内存数组中载入R树数据并构建R树。
	/// \param arData R树数据。
	/// \return  成功则返回TRUE。
	UGbool Load(UGMemoryStream &arData);

	/// \brief 把R树数据保存到内存数组中。
	/// \param arData 用来保存R树的数组。
	/// \return  成功则返回TRUE。
	UGbool Store(UGMemoryStream& arData);

//#ifdef DEBUG
	/// \brief 测试使用，取出R树所有叶子节点的范围。
	void GetAllLeafBounds( UGArray<UGRect2D> &arBounds );
	
	/// \brief 测试使用，取出R树所有叶子节点的范围。
	void GetAllLeafBounds2( UGArray<UGRect2D> &arBounds );
//#endif

protected:
	/// \brief	R树的根结点，保存普通的对象
	UGRTreeBranch* m_pRootNormal;
	/// \brief	R树的根结点，保存较大的对象
	UGRTreeBranch* m_pRootBig;

};

}

#endif /* _INC_SMRTREE_3E9E4B130220_INCLUDED */
