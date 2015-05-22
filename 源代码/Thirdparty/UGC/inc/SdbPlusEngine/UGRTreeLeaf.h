/*! \file UGRTreeLeaf.h
 *  \brief R树叶结点类定义。
 *  \author 郭其超,陈俊华
 *  \bug

 *	<b>更新说明：</b>\n
	<em>1、2003-11-1 首次完成代码编写.\n</em>
*/  

#if !defined(AFX_SMRTREELEAF_H__60DCDD23_A57A_406F_B2A3_B9160FF5B5A1__INCLUDED_)
#define AFX_SMRTREELEAF_H__60DCDD23_A57A_406F_B2A3_B9160FF5B5A1__INCLUDED_


#include "UGRTreeNode.h"

namespace UGC{

/// \brief R树叶结点类，结点中的元素是ID数组
/// \remarks 父类UGRTreeNode
class UGRTreeLeaf : public UGRTreeNode  
{
public:
	UGRTreeLeaf();
	virtual ~UGRTreeLeaf();

public:
	/// \brief 把结点的数据保存到内存数组中。
	/// \param arData 用来保存结点的数组。
	/// \return 成功则返回TRUE。
	virtual UGbool Store(UGMemoryStream& arData);

	/// \brief 从内存数组中载入结点的数据。
	/// \param arData 保存着结点数据。
	/// \return  成功则返回TRUE。	
	virtual UGbool Load(UGMemoryStream &arData);

	/// \brief 获取结点内元素的数量
	/// \return 结点内元素的数量
	virtual UGint GetEntryCount();

	/// \brief 获取结点占用内存的字节数
	/// \return 结点占用内存的字节数
	virtual UGint GetDataSize();
	
	/// \brief 获取该结点下的所有对象的ID
	/// \param arIDs 用来保存获取到的ID
	/// \return 成功则返回TRUE。
	virtual UGbool GetAllIDs( UGArray<UGint> &arIDs );

	/// \brief 在结点下查询
	/// \param rcBound 查询的范围
	/// \param arIDs 查询的结果ID数组
	/// \return  查询到的对象的数量
	virtual UGbool Query(const UGRect2D& rcBound, UGArray<UGint> &arCertainIDs, UGArray<UGint> &arMaybeIDs);

	/// \brief 获取结点的类型
	/// \return 结点的类型
	/// \remarks 返回值是2
	virtual UGuchar GetType();

public:
	/// \brief 获取ID数组的指针
	/// \return ID数组的指针
	UGArray<UGint>* GetIDArray() const;
	
protected:
	/// \brief ID数组的指针
	UGArray<UGint>* m_pIDs;

};


}

#endif // !defined(AFX_SMRTREELEAF_H__60DCDD23_A57A_406F_B2A3_B9160FF5B5A1__INCLUDED_)
