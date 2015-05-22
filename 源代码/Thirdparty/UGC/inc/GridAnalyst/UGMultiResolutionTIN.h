// UGMultiResolutionTIN.h: interface for the UGMultiResolutionTIN class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGMULTIRESOLUTIONTIN_H__8071637D_43D0_4112_92F7_D1EBD6E1E0EB__INCLUDED_)
#define AFX_UGMULTIRESOLUTIONTIN_H__8071637D_43D0_4112_92F7_D1EBD6E1E0EB__INCLUDED_

#if _MSC_VER > 1000
#pragma once 
#endif // _MSC_VER > 1000

#include "Algorithm/UGPoint3D.h"
#include "Algorithm/UGRect2D.h"
#include "Base/UGLogFile.h"
#include "Algorithm/UGKdTree.h"
#include "Geometry/UGTINBlock.h"
#include "Engine/UGDatasetVector.h"
#include "Engine/UGDataSource.h"

#include "UGTriangle.h"

class UGMultiResolutionTINTest;

namespace UGC{

const UGint nAddForOnce = 10; // 点数组每次增长的大小
const UGint SAMPLEFACTOR = 11;  // 寻找一个数，其值为三角形个数除以该值的三次方跟

struct Segment
{
	UGint nTriID;
	
	UGint nFromID;
	UGint nPntID;
	
	Segment ()
	{
		nTriID = -1;
		nFromID = -1;
		nPntID = -1;
	}

	Segment& operator = (const Segment& seg)
	{
		nTriID = seg.nTriID;
		nFromID = seg.nFromID;
		nPntID = seg.nPntID;
		return *this;
	}
};


typedef UGArray<UGint> pntNbrs; // 相邻点信息

struct TriPntInfo 
{
	UGArray<pntNbrs*> arrPntNbrs;
	UGArray<Segment*> arrArc;
	UGint nArcIndex;
};



class GRIDANALYST_API UGMultiResolutionTIN : public UGTriangle
{
public:
	
// 	struct MultiResolution {
// 		UGdouble dTolerance;
// 		UGlong lResolution;
// 	};
	
	struct edgelist
	{
		UGint nFrom;  // 边的起点在块中的位置
		
		UGint nTo; // 边的终点在块中的位置
		
		UGint nBlockID;  // 块号
		
		TriLocation RightTri; // 和该边相邻的三角形
		
		edgelist* next;
	};
	
	enum ExecuteType {UGCreate, UGInsert, UGDelete};
	
	enum BlockMark {UGRead, UGWaited, UGDone, UGUninserted};  // read表示已读入，waited表示未读入, done表示已经处理完成，uninserted表示已读入，但为加入到堆中
	
	enum Direction {UGTop, UGRight, UGBottom, UGLeft, UGNone};
	
	enum TypeForKdTree {UGSave, UGBuild, UGMerge};
	
	struct NeighbourInfo {
		UGArray<UGint> arrNeighbour;
		BlockMark nMark;
		
		NeighbourInfo ()
		{
			nMark = UGWaited;
		}
	};
	
	struct BlockWinge {
		TriLocation farleft;
		TriLocation farright;
		UGint nLeft;
		UGint nRight;
		
		BlockWinge ()
		{
			nLeft = nRight = -1;
		}
	};
	
	class MemoryQueue {
	
	public:
		UGint* pInMemory;
		UGbyte* pInUse;
		UGint* pUsedIndex;
		UGint nUsedCount;
		UGint nCount;
		UGint nRear;
		
		enum MarkType {UGBaseedge, UGLeftcand, UGRightcand, UGNextedge, UGTopcasing};

		MemoryQueue ()
		{
			pInMemory = NULL;
			pInUse = NULL;
			pUsedIndex = NULL;
			nCount = 0;
			nRear = -1;
		}
		void Init(UGint nSize, UGint nBlockCount)
		{
			if (nSize <= 0)
			{
				return;
			}
			UGint i;
			pInMemory = new UGint [nSize];
			
			for (i = 0; i < nSize; i ++) 
			{
				pInMemory[i] = -1;
			}
			nCount = nSize;
			nRear = nCount - 1; // 从数组最后一位开始，计数从0开始

			if (nBlockCount > 0)
			{
				pInUse = new UGbyte [nBlockCount];
				memset(pInUse, 0, nBlockCount * sizeof (UGbyte));

				UGint i;
				nUsedCount = 5;
				pUsedIndex = new UGint [nUsedCount];
				for (i = 0; i < nUsedCount; i ++)
				{
					pUsedIndex[i] = -1;
				}
			}
		}
		void Mark (UGint nBlockID, MarkType type)
		{
			UGint nIndex;
			
			switch (type)
			{
			case UGBaseedge:
				{
					nIndex = pUsedIndex[0];
					pUsedIndex[0] = nBlockID;
				}
				break;
			case UGLeftcand:
				{
					nIndex = pUsedIndex[1];
					pUsedIndex[1] = nBlockID;
				}
				break;
			case UGRightcand:
				{
					nIndex = pUsedIndex[2];
					pUsedIndex[2] = nBlockID;
				}
				break;
			case UGNextedge:
				{
					nIndex = pUsedIndex[3];
					pUsedIndex[3] = nBlockID;
				}
				break;	
			case UGTopcasing:
				{
					nIndex = pUsedIndex[4];
					pUsedIndex[4] = nBlockID;
				}
				break;
			default:
				return;
			}

			if (nIndex != -1)
			{
				UGASSERT (pInUse[nIndex] > 0);

				pInUse[nIndex] --;
			}
			pInUse[nBlockID] ++;
		}

		~MemoryQueue ()
		{
			if (pInMemory)
			{
				delete [] pInMemory;
				pInMemory = NULL;
			}

			if (pInUse)
			{
				delete [] pInUse;
				pInUse = NULL;
			}

			if (pUsedIndex)
			{
				delete [] pUsedIndex;
				pUsedIndex = NULL;
			}
		}
	};
	
	struct BlockSize {
		UGint nIndex;
		UGint nCount;
	};
	
	struct BlockBound {
		UGint nIndex;
		UGRect2D rcbound;
		
		BlockBound& operator = (const BlockBound bb)
		{
			nIndex = bb.nIndex;
			rcbound.top = bb.rcbound.top;
			rcbound.left = bb.rcbound.left;
			rcbound.right = bb.rcbound.right;
			rcbound.bottom = bb.rcbound.bottom;
			return *this;
		}
	};
	
	// 用来存储某块中被加入到别的块的点在别的块的块号及其索引号
	class PointRead {
		
	public:
		PntLocation* m_pPntLoc;
		UGint m_nCount; // 某个点可能被加入到多个块中，在不同的块中对应有不同的索引，m_pPntLoc存储之
		
		PointRead ()
		{
			m_pPntLoc = NULL;
			m_nCount = 0;
		}
		~PointRead ()
		{
			free (m_pPntLoc);
			m_nCount = 0;
		}
	};

	class TriRead {

	public:
		UGint* m_pnRead;
		UGint m_nCount;

		TriRead ()
		{
			m_pnRead = NULL;
			m_nCount = 0;
		}
		UGbool Init (UGint nCount)
		{
			if (nCount <= 0)
			{
				return FALSE;
			}
			m_nCount = nCount;
			m_pnRead = new UGint [nCount];

			if (m_pnRead == NULL)
			{
				UGERROR(UGS_MEMMORY_NOT_ENOUGH);
				return FALSE;
			}
			memset(m_pnRead, 0, nCount * sizeof (UGint));
			return TRUE;
		}
		~TriRead ()
		{
			delete m_pnRead;
			m_nCount = 0;
		}
	};
	
	typedef UGArray<PointRead*> BlockRead;

	class PointMap {
		
	public:
		UGchar* pProcessed;   // 判断每个点是否被处理，0为未处理，1未处理过，放在这的目的是可以一起传入，一起删除
		
		UGTriedge* pTriedge;

		PointMap ()
		{
			pProcessed = NULL;
			pTriedge = NULL;
		}

		PointMap (UGint nCount)
		{
			if (nCount > 0)
			{
				pProcessed = new UGchar[nCount];
				memset(pProcessed, 0, nCount * sizeof (UGchar));

				pTriedge = new UGTriedge[nCount];
			}
			else
			{
				pProcessed = NULL;
				pTriedge = NULL;
			}
		}

		~PointMap ()
		{
			if (pProcessed)
			{
				delete [] pProcessed;
				pProcessed = NULL;
			}
			if (pTriedge)
			{
				delete [] pTriedge;
				pTriedge = NULL;	
			}
		}
		
	};

	struct PntRecord {

		PntLocation pntloc;   // 多边形的点

		TriLocation RightTri; // 和该点相邻的三角形
	};

	
	struct DAG {
		int nTriIndex;       // 三角形ID，若三角形不最终存在，只是一个中间结果，那么nTriIndex值为－1；
		int nPntIndex[3];    // 该三角形点索引
		DAG* pDown[3];

		DAG ()
		{
			pDown[0] = pDown[1] = pDown[2] = NULL;
		}
	};

	enum PntRelation {ONEDGE, INSIDE, OUTSIDE};

	typedef UGArray<UGdouble> PTolerance; // 每一块的容限

	typedef UGArray<NeighbourInfo*> NeighboursInfo; // 相邻块信息

	struct NbrTri  // 存放相邻的三角形
	{
		TriLocation* pNbrTri;
		UGint nNbrCount;   // 数组的大小
		UGint nTriCount;   // 数组实际存放的对象个数
	};

	struct NbrBlock  // 存放邻接的块号
	{
		UGint* pNbrBlock;  
		UGint nNbrCount;  // 数组的大小
		UGint nBlockCount; // 数组实际存放的对象个数
	};

public:
	UGMultiResolutionTIN();
	virtual ~UGMultiResolutionTIN();

	friend class UGMultiResolutionTINTest;
	
public:
	
	UGDatasetVector* CreateMultiResolutionTIN(UGDatasetVector* pFromDataset, const UGString& strFieldName, UGDataSource* pOutputDS, const UGString& strTinName);

	UGDatasetVector* CreateMultiResolutionTIN(UGDatasetVector* pFromDataset, const UGString& strFieldName, UGDataSource* pOutputDS, const UGString& strTinName, UGArray<UGdouble>& arrMultiPara);
	
	UGbool InsertResolutionLayer(UGDatasetVector* pTin, UGdouble multiPara);
	
	UGbool DeleteResolutionLayer(UGDatasetVector* pTin, UGint nLayerName);
	
	// 提取等值线
	UGDatasetVector* Contour(UGDataSource* pDataSource, const UGString& strOutputVectorName, UGDatasetVector* pTinDataset, UGdouble dBase, UGdouble dInterval, UGint nSmoothDegree = 3, UGint nSmoothMethod = 0);
	
#ifdef sparc  // 在solaris下对单元测试类的友元类设置不起作用，单元测试编不过去，
	            // 故暂且在solaris系统下将所有的private和pretected类型开放为public
public:
#endif

#ifdef _AIX
public:
#endif

#ifdef WIN32
private:
#endif

	void BuildDelaunay(UGPoint3D*& pnts, UGint lCount, UGRect2D& rect);

	// 初始化m_arrTinBlock
	void InitTINBlock(UGint nBlockCount);
	
	void CalAveragePlane(NbrTri& nbrTri, UGdouble* dAverageNormal, UGPoint3D& pnt);
		
	void CalcuNormal(UGint nBlockID, UGint nApex, UGint nOrg, UGint nDest, UGdouble *dNormal);
	void NormalSingle(UGdouble &f1, UGdouble &f2, UGdouble &f3);
	
	void CalcuArea(UGdouble* dNormal, UGdouble* dArea);
	void CalcuCoordinate(UGint nBlockID, UGint nApex, UGint nOrg, UGint nDest, UGPoint3D* pnt);
	
	// 在某一块中建立每个点和该点所在的一个三角形的映射关系
	void MakePointMap(UGTINBlock* pTinBlock, PointMap** pMap, UGint nBlockID);
	
	// 计算triloc周围一圈的三角形，保存在arrTri中
	void CalNeighbour(const TriLocation& triloc, NbrTri& nbrTri, NbrBlock& nbrBlock);
	
	void CalNeighbour(UGKdTreeNode* pRoot, NeighboursInfo* pNeighbourInfo);
	void CalNeighbourInfo(UGKdTreeNode* pNode, UGArray<BlockBound>& arrLeft, UGArray<BlockBound>& arrRight);
	void FillBound(UGKdTreeNode* pNode, UGArray<BlockBound>& arrBlockBound, Direction dir);
	void KnitTeeth(NeighboursInfo* pNeighbourInfo, UGArray<BlockBound>& arrLeft, UGArray<BlockBound>& arrRight, UGKdTreeNode::DType type);
	
	void bondnull(TriLocation& triloc);
	
	// 在第nCurLayer层干掉三角形triloc
	void RemoveSuperfluous(TriLocation& triloc);
	
	UGdouble counterclockwiseInBlock(UGint nFirst, UGint nSecond, UGint nThird, UGint nBlockID);
	UGdouble counterclockwiseInBlock(PntLocation& pntfirst, PntLocation& pntsecond, PntLocation& pntthird);
	
	void GetValue(UGint nBlockID, UGint nIndex, UGdouble& x1, UGdouble& y1);
	
	void CalCircleInBlock(UGint nFirst, UGint nSecond, UGint nThird, UGint nBlockID, 
		UGdouble& dRadius, UGdouble& dX, UGdouble& dY);
	void CalCircleInBlock(PntLocation& pntfirst, PntLocation& pntsecond, PntLocation& pntthird,
		UGdouble& dRadius, UGdouble& dX, UGdouble& dY);
		
	UGbool incircleInBlock(UGint pa, UGint pb, UGint pc, UGint nBlockID, PntLocation& pntloc);
	UGbool incircleInBlock(PntLocation& pntfirst, PntLocation& pntsecond, PntLocation& pntthird, PntLocation& pntloc);
	
	UGPoint3D* GetPnt(PntLocation& pntloc);
	
	// 在nBlockID中增加点pnt，并将该点原始块信息写入
	UGint AddPnt(const UGPoint3D* pnt, const PntLocation& pntloc, UGint  nBlockID);
	
	// 在nBlockID未块号的块中增加pntloc点
	UGint AddPnt(const PntLocation& pntloc, UGint nBlockID);
	
	// 自动生成各级分辨率
	void DoAsDijkstra(NeighboursInfo* pNeighbourInfo, UGdouble* pNeighbourCount, UGint* pIndex, UGArray<PTolerance*>& arrTol, NbrTri& nbrTri, NbrBlock& nbrBlock);

	// 分辨率已经设置好了
	void DoAsDijkstra(NeighboursInfo* pNeighbourInfo, UGdouble* pNeighbourCount, 
										UGint* pIndex, UGdouble dTolerance, UGPoint3D*& pPnts, UGint& nPntIndex, NbrTri& nbrTri, NbrBlock& nbrBlock);
	
	UGint prevIndex(UGint nIndex, UGint nCount);
	
	void MergeDataInKdTree(UGKdTreeNode* pRoot);
	
	void SaveDataInKdTreeNode(UGKdTreeNode* pRoot);
	
	void BuildDataInKdTreeNode(UGKdTreeNode* pRoot);
	
	UGint GetIndex(UGKdTreeNode* pLeft, Direction type);
	UGint GetIndex(UGKdTreeNode* pNode, UGKdTreeNode::DType nCutDim, UGint nType);
	
	void EnQueue(MemoryQueue& memQueue, UGint nIndex, NeighboursInfo* pNeighbourInfo);
	
	// 将块号为nIndex的块读入到内存中
	void EnQueue(MemoryQueue& memQueue, UGint nIndex);
	
	void mergehulls(UGint nLeft, UGint nRight, UGint axis, 
		MemoryQueue& memQueue, NeighboursInfo* pNeighbourInfo);
	void Merge(UGKdTreeNode* pNode, MemoryQueue& memQueue, NeighboursInfo* pNeighbourInfo);
	
	void AddNewTriangle(UGTriedge& newTriedge, UGint nBlockID);
	
	UGbool BlockInMemory(const TriLocation& triloc);
	
	void MoveToEnd(TriLocation& triloc, UGint dir,  MemoryQueue& memQueue, NeighboursInfo* pNeighbourInfo);
	void MoveBack(TriLocation& triloc, UGint dir, MemoryQueue& memQueue, NeighboursInfo* pNeighbourInfo);
	
	UGint GetAxis(Direction type);
	UGint GetAxis(UGKdTreeNode::DType type);
	
	void Sort(UGKdTreeNode* pNode, MemoryQueue& memQueue, NeighboursInfo* pNeighbourInfo);
	
	void WriteNewQueue(UGKdTreeNode* pNode, NeighboursInfo* pNeighbourInfo, MemoryQueue& memTemp);
	
	// 设置数据集的Bound
	void SetBound(UGRect2D& rect);
	
	// 清理边界上无用的三角形
	void CleanBound(TriLocation& triloc, MemoryQueue& memQueue);
	
	// 清除边界上的三角形，triloc的apex要么朝向左边，要么朝向右边
	void CleanBound(TriLocation& triloc);

	// 存储每块相邻块的指针被清除
	void CleanNeighbourInfo();
	
	// 将无用的三角形删除标志修改为0，并将相邻三角形bondnull
	void DeleteTri(TriLocation& triloc, MemoryQueue& memQueue);
	
	// 将无用的三角形删除标志修改为0，并将相邻三角形bondnull
	void DeleteTri(TriLocation& triloc);
	
	UGint Add(UGTINBlock* tin);
	UGbool Save(UGTINBlock* tin, UGint nBlockID);
	UGbool Load(UGTINBlock* tin, UGint nBlockID);
	
	// 返回指定块的指针，为该块分配内存
	BlockRead* SetBlockReadAt(UGArray<BlockRead*>& arrBlockRead, UGint nIndex);
	
	UGint FindPointRead(PointRead* pPointRead, UGint nBlockID);
	
	// 返回某个冗余点的实际位置
	void GetOriginPnt(PntLocation& pntloc);
	
	// 清理arrBlockRead
	void CleanBlockRead();

	// 清理m_arrTinBlock
	void CleanTINBlock();
	
	// 清空pointmap
	void CleanPointMap();

	// 清空winge
	void CleanWinge();

	// 对在三角网中删除某个点而形成的多边形三角化
	void PolygonTriangulation(UGArray<PntRecord*>& arrPntRecords, UGRect2D& rect);

	// 计算序号为nIndex的点落在了哪个三角形内
	PntRelation GetTriIndex(UGint nIndex, DAG* pTriRecord, UGArray<PntRecord*>& arrPntRecords, UGTriedge& triedge);

	// 将三角形delaunay化
	void LegalizeTriangle(UGTriedge& triedge, UGArray<PntRecord*>& arrPntRecords, UGArray<DAG*>& arrDAG);

	void ReAlign(UGArray<PTolerance*>& arrTol, UGint lCount, UGdouble& dTol, UGint& lLayerCount);

	UGdouble GetTolValue(UGint nPivot, UGint nBlockSize, UGArray<PTolerance*>& arrTol);
	
	void GetPointsTolerance(UGArray<PTolerance*>& arrTol, NbrTri& nbrTri, NbrBlock& nbrBlock, UGint nBlockID);

	UGdouble GetTolerance(const TriLocation& triloc, NbrTri& nbrTri, NbrBlock& nbrBlock);

	void GetPoints(UGPoint3D*& pPnts, UGint& nPntIndex, UGint& nPntCount, NbrTri& nbrTri, NbrBlock& nbrBlock, UGint nBlockID, UGdouble dTolerance);

	// 清理arrPntNbrs内存空间
	void DeletePntNbrs(UGArray<pntNbrs*>& arrPntNbrs);

	// 为相邻三角形分配内存
	void AllocTriLocation(NbrTri& nbrTri, UGint nCount);

	// 加入三角形
	void AddToNbrTri(NbrTri& nbrTri, const TriLocation& triOri);

	// 为相邻三角形数组释放内存
	void FreeNbrTri(NbrTri& nbrTri);

	// 开辟空间，存放相邻块数被更改过的块号
	UGint* AllocQueue(UGint nCount);

	// nNbr为更改过的块号，将这个块号插入到pNbr数组中存储起来
	void InsertToQueue(UGint*& pNbr, UGint& nQueueIndex, UGint& nQueueSize, UGint nNbr);

	// 释放空间
	void FreeQueue(UGint*& pNbr);

	// 分配空间，用来存放doasdijkstra中新读入的块号
	void AllocBlock(NbrBlock& nbrBlock, UGint nCount);

	// 加入块号到数组nbrBlock中
	void AddToNbrBlock(NbrBlock& nbrBlock, UGint nBlockID);

	// 释放内存
	void FreeNbrBlock(NbrBlock& nbrBlock);

	// 计算每块的邻接块
	void CalBlockNeighbours(UGDatasetVector* pTin, NeighboursInfo*& pNeighbourInfo);

	// 从数据集集中提取点
	void GetPntFromDataset(UGDatasetVector* pDataset, const UGString& strFieldName, UGPoint3D*& pnt, UGint& lCount);

	// 剔除重复点
	void CleanRepeatedPnt(UGPoint3D*& pnts, UGint& lCount);

	// 扩大块的范围到包含pnt
	void InflateBound(UGTINBlock* pTinBlock, const UGPoint3D* pnt);

	// 初始化tripntInfo，该参数作为计算contourtree的传入参数
	void InitTriPnt(TriPntInfo& tripntInfo);

	// 删除tripntInfo
	void DeleteTriPnt(TriPntInfo& tripntInfo);

	// 提取某一块的等值线
	void Contour(UGDatasetVector* pRtDataset, const UGString strElev, UGint nBlockID, UGdouble dBase, UGdouble dInterval);

#ifdef sparc
public:
#endif

#ifdef _AIX
public:
#endif

#ifdef WIN32
protected:
#endif

	UGbool symselfInBlock(TriLocation& triLoc);
	UGbool symInBlock(TriLocation& triloc1, TriLocation& triloc2);
	void apexInBlock(const TriLocation& triloc, UGint& apex);
	void orgInBlock(const TriLocation& triloc, UGint& org);
	void destInBlock(const TriLocation& triloc, UGint& dest);
	void setorgInBlock(TriLocation& triloc, UGint point);
	void setdestInBlock(TriLocation& triloc, UGint point);
	void setapexInBlock(TriLocation& triloc, UGint point);
	
	void bondInBlock(TriLocation& triNew, TriLocation& triOld);
	
	UGbool symselfInBlock(TriLocation& triloc, MemoryQueue& memQueue, NeighboursInfo* pNeighbourInfo);
	
	UGbool symInBlock(TriLocation& triloc1, TriLocation& triloc2, MemoryQueue& memQueue, NeighboursInfo* pNeighbourInfo);

	// 计算每个点相邻的点以及块里有哪些边
	void CalPntNbrs(UGTINBlock* pTin, UGint nBlockID, TriPntInfo& tripntInfo);

	// 快速排序
	void QuickSort(UGPoint3D* p, UGint lCount);

	// 计算三角形triloc的坡度坡向
	void ReCalSlopeAspect(TriLocation& triloc);

#ifdef sparc
public:
#endif

#ifdef _AIX
public:
#endif

#ifdef WIN32
private:
#endif
	UGPoint3D* m_pPoint3D;
	UGRect2D m_rcBound;  // 整个数据集的范围
	
	NeighboursInfo* m_pNeighbourInfo;
	
	UGArray<BlockRead*> m_arrBlockRead; // 散列表，在处理不同块之间的冗余点时用该表来管理，避免冗余点的重复加入
	
	UGArray<PointMap*> m_arrPointMap; // 重复点信息(用于构建多分辨率图层以及插入图层)
	
	UGArray<UGTINBlock*> m_arrTinBlock;    // tin数据
	
	UGint m_nBlockCount;
	
	UGRecordset *m_pRecordset;

	// 每块都保留一个左三角形，一个右三角形，放在BlockWinge中，建立一个数组，保存每块的BlockWinge信息
	UGArray<BlockWinge*> m_arrWinge;

};

}
#endif // !defined(AFX_UGMULTIRESOLUTIONTIN_H__8071637D_43D0_4112_92F7_D1EBD6E1E0EB__INCLUDED_)
