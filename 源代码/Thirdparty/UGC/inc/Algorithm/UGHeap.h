//=====================================================================================
// 项目名：			SuperMap Foundation Class (SFC) Library 2.0
// 作  者：			裘立
// 单  位：			北京超图地理信息技术有限公司
// 最后修改时间：	以文件日期为准
//-------------------------------------------------------------------------------------
// 重要声明：		1. 类库使用范围为SuperMap GIS软件开发组成员，未经许可不得擅自传播。
//					2. 类库使用者不得修改本文件内容，否则会导致类库使用错误。
//					
//-------------------------------------------------------------------------------------
// 文件名：			UGHeap.h
// 类  名：			UGHeap
// 父  类：			
// 子  类：			
// 功能说明：		堆排序 
// 调用说明：		
//=====================================================================================
//{{ by guohui 2007.09.29 增加对该类的说明
//		堆排序是内排序的一种，属于选择排序。堆的定义是：在n个节点的顺序存储的完全二叉树中，满足
//  所有的非叶节点都小于(大于)它的孩子结点之值，也就是任何一个非叶结点值都小于(大于)它的全部后代
//  结点的值。就称该二叉树为一个小顶堆(大顶堆)。其存储顺序为r[0],r[1]...r[n-1],r[0]为堆顶，r[n]
//  为堆底。
//
//
//
//
//}} by guohui 2007.09.29 增加对该类的说明
#if !defined(UGQHEAP_H)
#define UGQHEAP_H

#include "Base/ugdefs.h"
#include "Base/UGArray.h"

namespace UGC{

class ALGORITHM_API UGQHeap
{
public:

	//! \brief 		带参构造函数
	//! \return 	
	//! \param 		pnHeapIndex	堆索引
	//! \param 		dCost		开销
	//! \remarks 	
	UGQHeap(UGint* pnHeapIndex,UGdouble* dCost, UGbool bSmall = TRUE);
	
	//! \brief 		析构函数
	//! \return 	
	//! \param 		
	//! \remarks 	
	~UGQHeap();

	//! \brief 		获得最小耗费的索引
	//! \return 	UGint	失败返回-1
	//! \param 		
	//! \remarks 	
	UGint GetMinCostIndex();

	//! \brief 		插入一个项
	//! \return 	
	//! \param 		lItem		项
	//! \remarks 	
	void Insert(const UGint lItem);

	//! \brief 		更新一个项（向上更新）
	//! \return 	
	//! \param 		lIndex		项索引
	//! \remarks 	
	void Update(const UGint lIndex);

	//! \brief 		更新一个项（向下更新）
	//! \return 	
	//! \param 		lIndex		项索引
	//! \remarks 	
	void UpdateEx(const UGint lIndex);

	//! \brief 		获得大小
	//! \return 	
	//! \param 		
	//! \remarks 	
	UGint GetSize();

private:

	//! \brief 		比较函数
	//! \return 	
	//! \param 		nNode1		节点1
	//! \param 		nNode2		节点2
	//! \remarks 	
	UGbool Compare(const UGint nNode1,const UGint nNode2);
private:

	//! \brief 		搜索链表
	UGArray <UGint> m_SearchedList;

	//! \brief 		开销
	UGdouble* m_pdCost;

	//! \brief 		堆索引
	UGint*	m_pnHeapIndex;

	//! \brief      是否是小顶堆 
	UGbool m_bSmall;
};

}
#endif // !defined(UGQHEAP_H)
