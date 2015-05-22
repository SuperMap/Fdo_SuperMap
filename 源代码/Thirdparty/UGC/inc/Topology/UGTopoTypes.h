
#ifndef UGTOPOTYPES_H
#define UGTOPOTYPES_H
#include "Base/ugdefs.h"
#include "Algorithm/UGPoint2D.h"
#include "Engine/UGDatasetVector.h"

namespace UGC {

struct TVertexIndex
{
	UGint SID;
	UGint Pos;
 	UGint Num;
	UGdouble dDistance;
  UGPoint2D XY;
};

struct TArcNode
{
  UGPoint2D XY;
  UGint NextVertexNo;
};

struct IndexLine
{
	UGPoint2D  first0Pnt;
	UGPoint2D  first1Pnt;
	UGint   nlineNo;
};

struct TDangleExtend{
	UGint ArcID;
	TArcNode  CrossLine;
};

struct TNodeStartEnd
{
	UGPoint2D pntStart;
	UGPoint2D pntEnd;
};

struct TNodeType
{
	UGbyte NodeType;
	UGPoint2D XY;
};

struct TNodeIndex
{
	UGint SID;
	UGint Pos;
	UGint Num;
	UGPoint2D XY;
	UGdouble Measure;
};

struct TNodeIndexEx
{
	UGint  SID;
	UGint  Pos;
	UGint  Num;
};

struct TNodeIndexPN
{
	UGint Pos;
	UGint Num;
};

struct TNodeError
{
 	UGbyte NodeFrom;
  UGbyte NodeTo;
};

struct  TGridSegment{
	UGint Arc;
	UGint NextVertexNo;
	UGint nFileIndex;
};

struct TGridSegmentEx{
	UGint nDTIndex;
	UGint Arc;
	UGint NextVertexNo;
	UGint nFileIndex;
};

struct TCentroidUnit{
	UGint ArcNo;
	UGPoint2D Centroid;
};

struct TArcNodeInfo
{
  UGint NodeID;
  UGint ArcPos;
};

struct TNode{
  UGPoint2D XY;
  UGint ArcNo;
};

struct TNodeEx{
	UGPoint2D XY;
	UGint ArcNo;
	UGdouble dAngle;
};

struct TArcAngle{
	UGint ArcNo;
	UGdouble dangle;
};

struct TArcNodeID
{
	UGint From;
	UGint To;
};

struct TPolyUnit
{
 	UGdouble Area;
  UGint SID;
  UGint nSmID;
};

struct THatchHead
{
	UGPoint2D pntOrigin;
	UGdouble dDist;
	UGint nID;
};

struct NodeWithArc
{
	UGint m_nIndex;
	UGint m_nArcID;
};

struct PolygonBounds
{
	UGint nLeftIndex;
	UGint nRightIndex;
	
	UGint nTopIndex;
	UGint nBottomIndex;
	
	UGint nIndex;
	UGdouble dArea;
};

class NodeWithArcs
{
public:
	NodeWithArcs(){m_nArcCount = 0;m_pNodeArcs = NULL;}
	UGbool AddArc(UGint nIndex, UGint nArcID);

public:	
	NodeWithArc* m_pNodeArcs;
	UGint m_nArcCount;
};

class UGTopoArcNodes  
{
public:
	UGTopoArcNodes()
	{
		NodesCount = 0;
		pNodesPos = (UGint *)malloc(sizeof(UGint));
	};
	
	virtual ~UGTopoArcNodes()
	{
		free(pNodesPos);
	};

	UGint NodesCount;
	UGint *pNodesPos;
};

class UGTopoGrid  
{
public:
	UGTopoGrid()
	{
		Count = 0;
		pItems = (UGint *)malloc(sizeof(UGint));
	};
	
	~UGTopoGrid()
	{
		free(pItems);
	};
	
	UGint Count;
	UGint *pItems;
};

class UGTopoGridUnitArcs  
{
public:
	UGTopoGridUnitArcs()
	{
		ArcsCount = 0;
	pCentroidUnit = (TCentroidUnit *)malloc(sizeof(TCentroidUnit));
	};
	
	~UGTopoGridUnitArcs()
	{
	};

	UGint ArcsCount;
	TCentroidUnit *pCentroidUnit;
};

class UGTopoSegmentNode  
{
public:
	UGbool AddPoint(UGPoint2D point);
	UGTopoSegmentNode();
	~UGTopoSegmentNode();

	UGint NodesCount;
	UGPoint2D *pXY;
};

class TOPOLOGY_API UGTopoSegmentNodeEx  
{
public:
	UGbool AddNode(const TNodeIndex &NodeIndex);
	UGTopoSegmentNodeEx();
	~UGTopoSegmentNodeEx();

	UGint NodesCount;
	TNodeIndex* pNodeIndex;
};

class TOPOLOGY_API UGTopoGridUnit  
{
public:
	UGbool AddSegment(const TGridSegment& tSegment);
	UGTopoGridUnit();
	~UGTopoGridUnit();

	UGint SegmentsCount;
	TGridSegment *pSegments;
	//CArray <TGridSegment, TGridSegment&> pSegments;
};

class UGTopoGridUnitEx
{
public:
	UGbool AddSegment(const TGridSegmentEx& tSegment);
	UGTopoGridUnitEx();
	~UGTopoGridUnitEx();
	
	UGint SegmentsCount;
	TGridSegmentEx *pSegments;
	//CArray <TGridSegment, TGridSegment&> pSegments;
};

class UGTopoGridUnitNodes  
{
public:
	UGTopoGridUnitNodes();
	~UGTopoGridUnitNodes();

	UGint NodesCount;
	UGint *pNodesPos;
};

class TOPOLOGY_API UGTopoGridUnitNodesEx
{
public:
	UGTopoGridUnitNodesEx();
	virtual ~UGTopoGridUnitNodesEx();
	UGArray<UGint> PntIndexNo;
	UGArray<UGint> IntersetPnt;
	UGArray<UGdouble> Positions;
};

struct TOverlayID
{
	UGint nIndex;
	UGint  nSrcID;
	UGint  nTagID;
};

class TOPOLOGY_API UGTopoGlobalFunctions  
{
public:
	UGTopoGlobalFunctions();
	virtual ~UGTopoGlobalFunctions();

	static void Quick_Sort(UGint *pR, UGint l, UGint p);
	static void Quick_Sort(UGdouble *pR, short l, short p);
	
	/*quick sort the DPoint array pointer
	nType: 0 = according to X-Value
				 1 = according to Y-Value
	IsAscending: TRUE = ascending(default)
							 FALSE = descending
	*/
	static void Quick_Sort(UGPoint2D *pR, short l, short p, short nType = 0, UGbool IsAscending = FALSE);
	
	static void Quick_Sort(TNodeIndex *pR, short l, short p);
	
	static UGbool Line_Cross(const UGdouble& X1, const UGdouble& Y1, const UGdouble& X2,
							const UGdouble& Y2, const UGdouble& X3, const UGdouble& Y3, 
							const UGdouble& X4, const UGdouble& Y4, UGdouble &CrossX, UGdouble &CrossY);
	
	static UGdouble Ata(const UGdouble& Y, const UGdouble& X);

	static void Bubble_Sort(TPolyUnit *pData, UGint N);

	static UGint FindIndex(UGint nID,UGint* arrIDs,UGint nCount);
	
	static void q_Sort(THatchHead *pData, UGint N);
	
	static void q_Sort(TArcAngle *pData, UGint N);
	
	static UGint GetArcIDIndex(UGint nArcId, UGArray<UGint> &ArcIds);
	static UGbool EQ(UGdouble &a, UGdouble &b);
	static UGbool EQ(UGPoint2D &a, UGPoint2D &b);
	static UGbool EQ(UGdouble &a, UGdouble &b, UGdouble &dTolerance);
	static UGbool EQ(UGPoint2D &a, UGPoint2D &b, UGdouble &dTolerance);
	static UGint IntersectLineSect(UGPoint2D &pntStart1, UGPoint2D &pntEnd1, UGPoint2D &pntStart2,
									UGPoint2D &pntEnd2, UGPoint2D &pntResult1, UGPoint2D &pntResult2,
									UGdouble MinVertexInterval);
	
	static void SortOverlayIDs(TOverlayID*pData, UGint nCount);
//		return 0: 相离
//		return 1: 相交									返回交点顺序
//		return 2: S1-----S2(E2)-----E1-----E2(S2)		S2(E2)-->E1
//		return 3: S2(E2)-----S1-----E2(S2)-----E1		S1-->E2(S2)
//		return 4: 包含关系line1包含line2
//		return 5: 包含关系line2包含line1
//		return 6: 重合
static UGint IntersectLineSectEx(UGPoint2D &pntStart1, UGPoint2D &pntEnd1, UGPoint2D &pntStart2,
								UGPoint2D &pntEnd2, UGPoint2D &pntResult1, UGPoint2D &pntResult2,
								UGdouble &MinVertexInterval);

static UGbool FindBounds(UGRect2D rcBounds, UGArray<UGRect2D> &arrBounds);

};


class TOPOLOGY_API TopoGridEnv
{
public:
	TopoGridEnv();
	virtual ~TopoGridEnv();
	
public:
	UGGeometry* pGeometry;
	UGTopoGrid* pGridUnit;
	UGTopoGridUnit *pGridUnits;
	
	UGbool bUserID;
	UGint nObjCount;
	UGint IndexCols;
	UGint IndexRows;
	UGdouble dGridInterval;
	UGRect2D rcBounds;
	
	UGArray<UGint> arrEndPointIndexs;
	UGArray<UGPoint2D> arrPoints;
	UGArray<UGRect2D> arrBounds;
	UGArray<UGGeometry*> arrObjects;
};

class AreaCompare
{
public:
	UGbool operator()(const PolygonBounds& netIndex1, const PolygonBounds& netIndex2) const
	{
		if (netIndex1.dArea < netIndex2.dArea)
		{
			return TRUE;
		}
		
		return FALSE;
	}
};



//class OverlayIDCompare
//{
//public:
//	UGbool operator()(const TOverlayID& netIndex1, const TOverlayID& netIndex2) const
//	{
//		if (netIndex1.nSrcID < netIndex2.nSrcID)
//		{
//			return TRUE;
//		}
//		else if (netIndex1.nSrcID == netIndex2.nSrcID)
//		{
//			if (netIndex1.nTagID <= netIndex2.nTagID)
//			{
//				return TRUE;
//			}
//		}
//		
//		return FALSE;
//	}
//};

class RectCompare
{
public:
	UGbool operator()(const UGRect2D& netIndex1, const UGRect2D& netIndex2) const
	{
		if (netIndex1.left < netIndex2.left)
		{
			return TRUE;
		}
		else if (netIndex1.left == netIndex2.left)
		{
			if (netIndex1.bottom < netIndex2.bottom)
			{
				return TRUE;
			}
			else if (netIndex1.bottom == netIndex2.bottom)
			{
				if (netIndex1.top < netIndex2.top)
				{
					return TRUE;
				}
				else if (netIndex1.top == netIndex2.top)
				{
					if (netIndex1.right < netIndex2.right)
					{
						return TRUE;
					}
				}
			}
		}
		
		return FALSE;
	}
};

#define ooDMAX 1.7E+308	//UGdouble max
#define ooSMAX 3.37E+38	//single max
#define ooLMAX 2147483647	//UGint max
#define ooIMAX 32767	//int max
#define MinE12 1e-012
#define MinE13 1e-013
#define MinE14 1e-014
//#define OBJECTS_COUNT 21000//用于确定使用memory或disk的弧段数
#define OBJECTS_COUNT 410000//用于确定使用memory或disk的弧段数
#define MAXGRIDCOUNT 250000	//网格化最大行列书

//{{CDialogTopoXXXXX class 使用的参数
#define ID_OK 0
#define ID_CONTINUE 1
#define ID_NOTASKAGAIN 2
#define ID_CANCEL 3

//}}/////////////////////////////




}

#endif

