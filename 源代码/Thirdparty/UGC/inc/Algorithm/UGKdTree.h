//-------------------------------------------------------------------------------------
// 文件名：			UGKdTree.h, UGKdTree.cpp
// 类  名：			UGKdTree
// 父  类：			
// 子  类：			
// 功能说明：		用KdTree进行临近点查找
// 调用说明：		
//-------------------------------------------------------------------------------------
/* 修改说明：
 *		2007.09.25	guohui	为本头文件添加注释
 */

#if !defined(UGKDTREE_H)
#define UGKDTREE_H
#include "Algorithm/UGRect2D.h"

namespace UGC{

class UGPoint3D;

#define MaxBucketSize 2500//30
//! \brief k维树(k-dimensional tree)
/** 
by guohui 2007.09.25
	参考文献：
	《计算几何-算法与应用(第2版)》 M.de Berg,M.van Kreveld,M.Overmars,OSchwarzkofp著，邓俊辉译 p113
*/

class ALGORITHM_API UGKdTreeNode
{
public:
	
	//! \brief 切割方向
	enum DType 
	{
		eKdTreeX,			//	沿 X 方向
		eKdTreeY,			//	沿 Y 方向
		eKdTreeNONE			//  两者均不是
	};  
	

	//! \brief 叶子节点中的点的个数,中间节点为空
	UGint   m_nBucketSize;

	//! \brief 节点中的点的序列号,如果不是叶结点则为NULL，并且可以用这来判断是不是叶子节点
	UGint* m_pPointIndex;

	//! \brief 节点
	UGPoint3D* m_pPoint3D;

	//! \brief 左子树,叶子节点为空
	UGKdTreeNode* m_pLeftChild;

	//! \brief 右子树,叶子节点为空
	UGKdTreeNode* m_pRightChild;

	//! \brief 切割点所在的维数,叶子节点为空
	DType m_nCutDim;

	//! \brief 切割点的值,如果为叶子节点为空
	UGdouble m_dCutValue;

	//! \brief 在数据库中的块号，用于多分辨率的构建
	UGint m_nID;

	//! \brief 块的范围
	UGRect2D m_rcBound;

	//! \brief 设置ID
	void SetID(UGint nID)
	{
		m_nID = nID;
	};
};
	

class ALGORITHM_API UGKdTree  
{
public:
	//! \brief 		缺省构造函数
	UGKdTree();

	//! \brief 		析构函数
	virtual ~UGKdTree();	

public:

	//! \brief 		带参构造函数
	//! \param 		pPointArray		三维坐标点
	//! \param 		nPointCount		坐标点个数
	//! \param 		pPointList		点序列号
	//! \param 		pDistance		距离
	UGKdTree(UGPoint3D *pPointArray,UGint nPointCount,UGint *pPointList,UGdouble *pDistance);

	//! \brief 		带参构造函数
	//! \param 		pPointArray		三维坐标点
	//! \param 		nPointCount		坐标点个数
	//! \param 		pPointList		点序列号
	UGKdTree(UGPoint3D *pPointArray,UGint nPointCount,UGint *pPointList);

	//! \brief 		带参构造函数
	//! \param 		pPointArray		三维坐标点
	//! \param 		nPointCount		坐标点个数
	//! \param 		rect			点的范围
	UGKdTree(UGPoint3D *pPointArray,UGint nPointCount, UGRect2D& rect);

	//! \brief 		创建多维树
	//! \return 	UGbool
	//! \remarks 	
	UGbool KdTree_CreateTree();	

	//! \brief 		相邻点查询(指定查询个数)
	//! \return 	void
	//! \param 		pTree			传入kdtree
	//! \param 		x				横坐标
	//! \param 		y				纵坐标
	//! \param 		nSearchCount	要查找相邻点个数
	//! \param 		pPointIndex		查找到的点的序号,传入之前，需要先分配空间
	//! \param 		pPointDist		查找到的点与待查点的距离，传入之前，需要先分配空间 
	//! \remarks 	本接口只适用于坐标点索引创建的kd树
	void KdTree_SearchKdTree(UGKdTree* pTree,UGdouble x, UGdouble y,
		UGint nSearchCount, UGint *pPointIndex,	UGdouble *pPointDist);

	//! \brief 		相邻点查询(指定查询距离)
	//! \return 	void
	//! \param 		pTree			传入kdtree
	//! \param 		x				横坐标
	//! \param 		y				纵坐标
	//! \param 		dRadius			查询距离，定长搜索制定的半径
	//! \param 		nPointSearched	找到的点
	//! \param 		pPointDist		查找到的点与待查点的距离，传入之前，需要先分配空间 
	//! \remarks 	pPointIndex 和 	pPointDist 内存分配不能少于 MAX_POINTS
	void KdTree_SearchKdTreeDis(UGKdTree *pTree,UGdouble x,UGdouble y, 
		UGdouble dRadius,UGint &nPointSearched,	UGint *pPointIndex,UGdouble *pPointDist);

	//! \brief 		返回头指针
	//! \return 	UGKdTreeNode
	//! \param 		pTree			传入kdtree
	//! \remarks 		
	UGKdTreeNode* ReturnRoot();

	void SetMaxBucketSize(	UGint nMaxBucketSize = MaxBucketSize);
	UGint GetMaxBucketSize(	);

protected:	
	

	//! \brief 		根据索引创建结点
	//! \return 	UGKdTreeNode
	//! \param 		pPointIndex		索引
	//! \param 		lPointCount		索引个数
	//! \remarks 		
	UGKdTreeNode* KdTree_CreateNode(UGint *pPointIndex,UGint lPointCount);

	//! \brief 		根据坐标点创建结点
	//! \return 	UGKdTreeNode
	//! \param 		pPoint3D		坐标点
	//! \param 		lPointCount		索引个数
	//! \param 		rect			矩形
	//! \remarks 		
	UGKdTreeNode* KdTree_CreateNode(UGPoint3D *pPoint3D,UGint lPointCount, UGRect2D& rect);

	//! \brief 		释放内存
	//! \return 	UGbool
	//! \param 		pTreeNode		指针
	//! \remarks 		
	UGbool KdTree_FreeNode(UGKdTreeNode* pTreeNode); 

	//! \brief 		用来选择要split的维数和位置
	//! \return 	void
	//! \param 		pPointIndex		索引
	//! \param 		lPointCount		个数
	//! \param 		nCutDim			类型
	//! \remarks 		
	void KdTree_SelectSplit(UGint *pPointIndex,UGint lPointCount, UGKdTreeNode::DType &nCutDim);

	//! \brief 		用来选择要split的维数和位置
	//! \return 	void
	//! \param 		pPoint3D		坐标点
	//! \param 		lPointCount		个数
	//! \param 		nCutDim			类型
	//! \remarks 		
	void KdTree_SelectSplit(UGPoint3D* pPoint3D,UGint lPointCount, UGKdTreeNode::DType &nCutDim);

	//! \brief 		查找结点
	//! \return 	void
	//! \param 		pTreeNode		结点指针
	//! \remarks 		
	void KdTree_SearchNode(UGKdTreeNode *pTreeNode);

	//! \brief 		查找结点
	//! \return 	void
	//! \param 		pTreeNode		结点指针
	//! \remarks 		
	void KdTree_SearchNodeDis(UGKdTreeNode *pTreeNode);

	//! \brief 		将点集等分为两块
	//! \return 	void
	//! \param 		pPointIndex		索引指针
	//! \param 		lPointCount		个数
	//! \param 		nMedian			
	//! \param 		nCutDim			类型
	//! \remarks 		
	void KdTree_PointMedian(UGint *pPointIndex, UGint lPointCount, UGint nMedian, UGKdTreeNode::DType  nCutDim);  // 将点集等分为两块

	//! \brief 		将点集等分为两块
	//! \return 	void
	//! \param 		pPoint3D		坐标指针
	//! \param 		lPointCount		个数
	//! \param 		nMedian			
	//! \param 		nCutDim			类型
	//! \remarks 		
	void KdTree_PointMedian(UGPoint3D *pPoint3D, UGint lPointCount, UGint nMedian, UGKdTreeNode::DType  nCutDim);
	
private:

	//! \brief 		点的总数
	UGint m_lPointCount;

	//! \brief 		点
	UGPoint3D *m_pPointArray;

	//! \brief 		点的序列号
	UGint *m_pPointIndex;

	//! \brief 		根结点
	UGKdTreeNode *m_pRoot;

	//! \brief 		
	UGdouble  m_dx;               

	//! \brief 		
	UGdouble  m_dy;

	//! \brief 		返回要找的点数
	UGint m_nSearchCount;

	//! \brief 		从近到远返回点列
	UGint *m_pPointList;

	//! \brief 		从小到大返回距离
	UGdouble *m_pdDistance;

	//! \brief 		定长查找的半径
	UGdouble m_dRadius;

	//! \brief 		点的范围
	UGRect2D m_rcBound; 

	//! \brief 		最大块类型
	UGint m_nMaxBucketSize;
};
}

#endif // !defined(UGKDTREE_H)
