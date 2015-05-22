#if !defined(UGQUADTREE_H)
#define UGQUADTREE_H

#include "Base/ugdefs.h"
#include "Algorithm/UGRect2D.h"

namespace UGC {

class UGRect2D;
class UGPoint3D;
//class UGArray;

enum QuadChild
{
	NW = 0,
	NE = 1,
	SW = 2,
	SE = 3
};

class GRIDANALYST_API UGQuadNode
{
public:
	UGQuadNode();
	~UGQuadNode();
	//!递归创建四插数
	void Create(UGPoint3D* pPointList,UGint* pPointIndex,UGint nPointCount,UGint nMaxPntCount,const UGRect2D& rcBounds);
	//!查询，返回点的序号
	UGint QueryWithBounds(UGPoint3D* pPointList,const UGRect2D& rcBounds,UGArray<UGint>&arrResultIndex);
	//! 得到指定的子节点
	UGQuadNode* GetChild(int nIndex);
	//! 是否为叶子节点
	UGbool IsLeaf();
	//! 获得节点的Bounds
	UGRect2D GetBounds();
	//! 获得叶子节点个数
	UGint GetLeafCount();
protected:
	//!获得点集的中心点
	UGPoint2D GetPointCenter(UGPoint3D* pPointList,UGint* pPointIndex,UGint nPointCount);
	//!如果节点中没有点则创建空节点
	void CreateNullNode(const UGRect2D& rcBounds);
	//!判断该节点是否与rcbounds相交
	UGbool IsIntersect(const UGRect2D& rcBounds);
	//!子节点
	UGQuadNode** m_pChilds;
	UGRect2D m_rcBounds;
	UGint m_nPointCount;
	//!如果为子节点记录该节点存储的点的序号
	UGint* m_pIndex;
};

}

#endif // !defined(UGQUADTREE_H)



