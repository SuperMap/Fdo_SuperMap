// UGContourTree.h: interface for the UGContourTree class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGCONTOURTREE_H__126201E8_7C67_4C3A_910C_DD6E3CC23073__INCLUDED_)
#define AFX_UGCONTOURTREE_H__126201E8_7C67_4C3A_910C_DD6E3CC23073__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Geometry/UGTINBlock.h"
#include "GridAnalyst/UGMultiResolutionTIN.h"

namespace UGC{

class GRIDANALYST_API UGContourTree
{
public:


	struct Component
	{
		UGint nBirth;
		Component *pred, *succ;
		Component *nextPred, *prevPred;
		Component* uf;
	};

	struct Node;

	struct Arc
	{
		/** Node at the top of the arc */
		Node *hi;
		
		/** Node at the bottom of the arc */
		Node *lo;
		
		/** Next arc in the list of arcs attached to the lo node */
		Arc *nextUp;

		/** Prev arc in the list of arcs attached to the lo node */
		Arc *prevUp;
		
		/** Next arc in the list of arcs attached to the hi node */
		Arc *nextDown;

		/** prev arc in the list of arcs attached to the hi node */
		Arc *prevDown;

		/** if arc is not covered, nProcessed = 0; if arc is covered, nProcessed = 1; 
		if arc is covered and segment has attached, nProcessed = 2; default nProcessed = 0.*/
		UGint nProcessed;
		
		/** */
		UGint* pSegments;
		UGint nSize;
		UGint nIndex;

		~Arc ()
		{
			if (pSegments)
				free (pSegments);
			pSegments = NULL;
		}
	};

	struct Node
	{
		/** vertex that this node represents. */
		UGint nIndex;
		
		/** Doubly-linked, null-terminated list of arcs extended upwards from this node. Iterate like this:
		
		  for (Arc * a = node->up; a != NULL; a = a->nextUp )...
		*/
		Arc *up;
		
		/** Doubly-linked, null-terminated list of arcs extended upwards from this node. Iterate like this:
		
		  for (Arc * a = node->down; a != NULL; a = a->nextDown )...
		*/
		Arc *down;

		/** left and right value existed to indicate the relation of parent and child by the way of two iterations ,
		
		  one of which is scan from left to right ,the other is from right to left. if and only if the two values of 
		  
		one node are both smaller than another, we can say that this node is parent of another */
		UGint nLeft, nRight;

	};

	struct LeafQ
	{	
		Component** pComp;

		UGbyte* pType; // 0是join，1是split；0是max，1是min，2是join

		UGint nHead;
		
		UGint nTail;
		
		UGint nSize;		
	};

	struct AET 
	{
		Arc* pArc;
		UGint nMark;
	};

	enum NodeType {UGNull, UGMax, UGMin, UGJoin, UGSplit, UGRegular};

	struct arcNbrs
	{
		Arc** pArc;  // segment跨越的边信息
		UGint nIndex;
		UGint nSize;

		arcNbrs ()
		{
			pArc = NULL; 
			nIndex = nSize = 0;
		}

		arcNbrs (UGint nCount)
		{
			nIndex = 0;
			nSize = nCount;

			pArc = (Arc**)malloc(nCount*sizeof(Arc*));
			memset(pArc, 0x0, nCount*sizeof(Arc*));
		}

		~arcNbrs ()
		{
			if (pArc)
				free (pArc);
			pArc = NULL;
		}
	};
public:

	UGContourTree();
	virtual ~UGContourTree();

	// 构建ContourTree
	void BuildContourTree(UGTINBlock* pTin, UGint nBlockID, TriPntInfo& tripntInfo);

private:

	// 快速排序
	void quicksort(UGint* pPnts, UGint nBegin, UGint nEnd, UGPoint3D* pnt);

	// 扫描
	Component* Sweep(UGint* pPnts, UGint nBegin, UGint nEnd, UGint nAdd, Component** pComps, TriPntInfo& tripntInfo);

	// 新建component
	Component* NewComponent();

	// 建立pCurrent和pPred的关系
	void AddPredComponent(Component* pCurrent, Component* pPred);

	// 解除pCurrent和pPred的关系
	void RemovePredComponent(Component* pCurrent, Component* pPred);

	// 将一条边上的所有segmentuf设置成最后的那个segment的指针
	void UnionComponent(Component* pComp, Component* pNewComp);

	// 裁减掉coponent树的一条边
	void PruneComponent(Component* pLeaf);

	// pSelf是不是叶结点
	UGbool IsLeafComponent(Component* pSelf);

	// pComp是不是一个常规的结点（入度和出度都是1）
	UGbool IsRegularComponent(Component* pComp);

	// 清除pComp，使用前必须判断pComp所指向的结点是否regular
	void EatComponent(Component* pComp);

	// 删除Component
	void DeleteComponent(Component*& pComp);

	// 判断pNewComp是否已经加入comp
	Component* FindComponent(Component* pCurrent);

	// 将jointree和splittree合并成contourtree
	void Merge(Component* pJoinRoot, Component* pSplitRoot, Component** pJoinMap, Component** pSplitMap, Node** pNodeMap);

	// 新建队列
	LeafQ* NewLeafQ(UGint nSize);

	// 往队列里添加对象
	void PushBackLeafQ(LeafQ* pSelf, Component* pComp, UGint nType);

	// 从队列中弹出对象
	void PopFrontLeafQ(LeafQ* pSelf, Component*& pComp, UGint& nType);

	// 判断队列是否为空
	UGbool IsEmptyLeafQ(LeafQ* pSelf);

	// 清除leaf
	void DeleteLeaf(LeafQ*& pLeafQ);

	// 将Component数中的叶结点加到leafQ中
	void QueueLeaves(LeafQ* pLeafQ, Component* pRoot, Component** pMap, UGint nType);

	// 新建node结点
	Node* NewNode(UGint nPntIndex);

	// 把pArc加到pHigh结点的下面
	void AddDownArcNode(Node* pHigh, Arc* pArc);

	// 把pArc结点加到pLow结点的上面
	void AddUpArcNode(Node* pLow, Arc* pArc);

	// 新建一条新的边
	Arc* NewArc(Node* pHigh, Node* pLow);

	// 删除边pDown
	void DeleteDownArc(Arc* pDown);

	// 删除边pUp
	void DeleteUpArc(Arc* pUp);

	// 最后通过这个扫描函数计算出所有的contours
	void SweepForContours(UGint* pPnts, Node** pNodeMap, UGint nPntCount, UGArray<ContourLayer*>& arrContours, TriPntInfo& tripntInfo);

	// 从aet表中删除某条arc
	AET RemoveFromAET(Arc* pArc, UGArray<AET>& arrAET);

	// 往aet表中加入某条arc
	void InsertIntoAET(Arc* pArc, UGArray<AET>& arrAET);

	// 将nBegin到nEnd段的segment加入到pLayer中
	void AddToContours(Arc* pArc, UGint nBegin, UGint nEnd, ContourLayer* pLayer, TriPntInfo& tripntInfo);

	// 重新计算aet中nMark
	void RecalAET(AET& aet, UGdouble dCut, TriPntInfo& tripntInfo);

	// 返回顶点的类型
	NodeType GetNodeType(const Node* pNode);

	// 得到每条边上一个较小的segment覆盖集
	void GetSmallCover(Node** pNodeMap, UGint nPntCount, TriPntInfo& tripntInfo);

	// 扫描contourtree，建立各个结点间的关系
	void IterateGraph(Node* pBeginNode);

	// 从左到右设置
	void SetNodesValueFromLeft(Arc* const pArc, UGint& nPntCount, UGint& nLastBegin, UGArray<Arc*>& arrRightArc, Arc* pTerminate = NULL);

	// 在设置nLeft值时，设置某一条arc的所有node点值
	void SetSplitValueFromLeft(Arc* const pArc, UGint& nPntCount, UGint& nLastBegin, UGArray<Arc*>& arrRightArc);

	// 从右到左设置
	void SetNodesValueFromRight(Arc * const pArc, UGint& nPntCount, UGint& nLastBegin, UGArray<Arc*>& arrRightArc, Arc* pTerminate = NULL);

	// 在设置nRight值时，设置某一条arc的所有node点值
	void SetSplitValueFromRight(Arc* const pArc, UGint& nPntCount, UGint& nLastBegin, UGArray<Arc*>& arrRightArc);

	// 删除arrArcPass(每个点所在的segment所经过的arc信息)
	void DeleteArcPass(UGArray<arcNbrs*>& arrArcPass);

	// 判断nCur是否在nLeft和nRight之间
	UGbool IsBetween(UGint nCur, UGint nLeft, UGint nRight);

	// 判断pFromNode和pToNode间覆盖了哪些弧段
	UGint Wander(Node* pFromNode, Node* pToNode, UGint nSegIndex, arcNbrs* pArcNbrs);

	// 扫描，删除regular结点，并将arc跨越的segment和arc绑定，为第二次扫描左准备
	void SweepForSegment(UGint* pPnts, Node** pNodeMap, UGint nPntCount);

	// 排序
	void ReOrder(Arc* pArc, UGint nBegin, UGint nEnd, UGdouble dTopValue, UGdouble dDownValue, TriPntInfo& tripntInfo);

	// 删除点和弧段
	void DeleteNodeArc(Node** pNodeMap, UGint nPntCount);

	// test
	UGbool TestComponent(Component* pComp);
	UGbool TestNode(Node** pNodeMap, UGint nPntCount);
	UGbool TestPnt(UGint* pnt, UGint nCount);
	UGbool TestContour(UGArray<ContourLayer*>& arrContours);
	UGbool TestGragh(Node** pNodeMap, UGint nCount);
	void TestArcCovered(Node** pNodeMap, UGint nPntCount);

private:
	UGTINBlock* m_pTin;
};

}
#endif // !defined(AFX_UGCONTOURTREE_H__126201E8_7C67_4C3A_910C_DD6E3CC23073__INCLUDED_)
