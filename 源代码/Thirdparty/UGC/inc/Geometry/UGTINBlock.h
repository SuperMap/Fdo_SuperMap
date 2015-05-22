// UGTINBlock.h: interface for the UGTINBlock class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGTINBLOCK_H__B8A0F1B0_141E_406A_9ED8_915ED741FD93__INCLUDED_)
#define AFX_UGTINBLOCK_H__B8A0F1B0_141E_406A_9ED8_915ED741FD93__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Base/ugdefs.h"
#include "UGGeometry.h"
#include "Algorithm/UGRect2D.h"
#include "Base/UGLogFile.h"
//#include "GridAnalyst/UGMultiResolutionTIN.h"

namespace UGC {

class UGTriedge {
public:
	UGint tri;
	UGchar ori;

	UGTriedge()
	{
		tri = -1;
		ori = 0;
	}
	~UGTriedge()
	{
	}
	UGTriedge& operator = (const UGTriedge& triedge)
	{
		tri = triedge.tri;
		ori = triedge.ori;
		return *this;
	}
	UGbool operator == (const UGTriedge& triedge)
	{
		return tri == triedge.tri
			&& ori == triedge.ori;
	}
};

class UGTri {
public:
	
	UGbool  bConstrained[3];
	UGdouble dSlope;
	UGdouble dAspect;
	UGint  nTri[3];
	UGTriedge triedge[3];
	UGbool bDeleted;

	UGTri() 
	{
		nTri[0] = nTri[1] = nTri[2] = -1;
		bConstrained[0] = bConstrained[1] = bConstrained[2] = false;
		
		dSlope = 0.0;
		dAspect = 0.0;
		
		bDeleted = FALSE;
	}
	~UGTri()
	{
	}
	UGTri& operator = (const UGTri& tri)
	{
		bConstrained[0] = tri.bConstrained[0];
		bConstrained[1] = tri.bConstrained[1];
		bConstrained[2] = tri.bConstrained[2];
		dSlope = tri.dSlope;
		dAspect = tri.dAspect;
		nTri[0] = tri.nTri[0];
		nTri[1] = tri.nTri[1];
		nTri[2] = tri.nTri[2];
		triedge[0] = tri.triedge[0];
		triedge[1] = tri.triedge[1];
		triedge[2] = tri.triedge[2];
		bDeleted = tri.bDeleted;

		return *this;
	}
	void Init ()
	{
		nTri[0] = nTri[1] = nTri[2] = -1;
		bConstrained[0] = bConstrained[1] = bConstrained[2] = false;
		
		dSlope = 0.0;
		dAspect = 0.0;
		triedge[0].tri = triedge[1].tri = triedge[2].tri = -1;
		triedge[0].ori = triedge[1].ori = triedge[2].ori = 0;
		bDeleted = FALSE;
	}
};

struct TriLocation {
	UGTriedge triedge;
	UGint nBlockID;   // 块索引

	TriLocation& operator = (const TriLocation& triloc)
	{
		nBlockID = triloc.nBlockID;
		triedge = triloc.triedge;
		return *this;
	}
	UGbool operator == (const TriLocation& triloc)
	{
		return nBlockID == triloc.nBlockID 
			&& triedge == triloc.triedge;
	}
	UGbool operator != (const TriLocation& triloc)
	{
		return ! operator == (triloc);
	}
};


struct PntLocation {
	UGint nPntID;
	UGint nBlockID;
	PntLocation& operator = (const PntLocation& pntloc)
	{
		nPntID = pntloc.nPntID;
		nBlockID = pntloc.nBlockID;
		return *this;
	}
	UGbool operator == (const PntLocation& pntloc)
	{
		return nPntID == pntloc.nPntID 
			&& nBlockID == pntloc.nBlockID;
	}
};

struct TinBlock {
	UGTri* pTriangle;     // UGTri类中的邻接三角形信息在这里存储的不再是三角形的指针，而是三角形的id，
                          // 若相邻三角形在该块以外，那么用arrNeighbour来存储相邻的三角形信息，

	UGPoint3D* pPnt;      // 该块内存用malloc分配，在处理过程中，点的个数会增加，那就可以用realloc来实现

	PntLocation* pPntLocs;  // 块中会有一些冗余点，这个结构存储这些冗余点在别的块中的位置

	UGArray<TriLocation*> arrNeighbour;  // 三角网内有些三角形的邻接三角形在别的块中，使用这个array来存放这些三角形的邻接关系
	
	UGint nTriCount;
	UGint nRealTri;

	UGint nLivePnt;
 	UGint nDeadPnt;
	UGint nRealPnt;     // pPnt真正的大小，可能后面有的位置是空的，为了存放新增的点

	TinBlock()
	{
		pTriangle = NULL;
		pPnt = NULL;
		pPntLocs = NULL;
		
		nTriCount = nRealTri = 0;
		nLivePnt = nDeadPnt = nRealPnt = 0;
	}
	TinBlock& operator = (const TinBlock& tinblock)
	{
		pTriangle = tinblock.pTriangle;
		pPnt = tinblock.pPnt;
		pPntLocs = tinblock.pPntLocs;

		nTriCount = tinblock.nTriCount;
		nRealTri = tinblock.nRealTri;

		nLivePnt = tinblock.nLivePnt;
		nDeadPnt = tinblock.nDeadPnt;
		nRealPnt = tinblock.nRealPnt;

		arrNeighbour.Append(tinblock.arrNeighbour);

		return *this;
	}
	~TinBlock ()
	{
		UGint i;
		UGint nSize;
		TriLocation* pTriNeighbour = NULL;
		if (pTriangle)
		{
			free (pTriangle);	
			pTriangle = NULL;
		}
		if (pPnt)
		{
			free (pPnt);
			pPnt = NULL;
		}
		if (pPntLocs)
		{
			free (pPntLocs);
			pPntLocs = NULL;
		}
		
		nSize = arrNeighbour.GetSize();
		for (i = 0; i < nSize; i ++)
		{
			pTriNeighbour = arrNeighbour.GetAt(i);
			delete pTriNeighbour;
			pTriNeighbour = NULL;
		}
		arrNeighbour.RemoveAll();
		
		nRealTri = nTriCount = 0;
		nRealPnt = nLivePnt = nDeadPnt = 0;
	}
};

struct Contour
{
	UGdouble dTopValue;
	UGint nTriIndex;
};

typedef UGArray<Contour> Contours;

struct ContourLayer
{
	UGdouble dBegin;
	
	UGArray<Contours*> arrContours;
};

typedef UGArray<UGint> NbrTris;

struct TriInfo 
{
	UGdouble dSlope;
	UGdouble dAspect;
	UGPoint2D pnt[3];
};

class GEOMETRY_API UGTINBlock : public UGGeometry
{
public:
	UGTINBlock();

	virtual ~UGTINBlock();

public: //! 得到和设置一些信息
	
	//! \brief 清空地理数据
	virtual void Clear();
	
	//! \brief 得到维度
	virtual UGint GetDimension() const;
	
	//! \brief 得到类型
	virtual Type GetType() const;
	
	//! \brief 得到内点（在Geometry内部，靠近中央的点）
	virtual UGPoint2D GetInnerPoint() const;
	
	
	//! \brief 得到空间数据
	virtual UGbool GetSpatialData(UGAutoPtr<UGPoint2D>& pPoints, 
		UGAutoPtr<UGint>& pPolyCount, UGint& nSubCount, UGint nSegmentCount=0) const;
	
	//! \brief 几何对象是否有效
	virtual UGbool IsValid() const;
	
	//! \brief 点击测试
	virtual UGbool HitTest( const UGPoint2D &pntHitTest, UGdouble dTolerance) const;
	
	//! \brief 缩放
	virtual void Inflate( UGdouble dRatioX, UGdouble dRatioY);
	
	//! \brief 缩放
	virtual void Inflate( UGdouble dRatio);
	
	//! \brief 平移
	virtual void Offset( UGdouble dX, UGdouble dY);
	
	//! \brief 平移
	virtual void Offset( UGdouble dOffset);
	
	//! \brief 平移
	virtual void Offset( const UGSize2D &szOffset);
	
	//! \brief 旋转
	virtual void Rotate(const UGPoint2D& pntOrigin, UGdouble dAngle);
	
	//! \brief 旋转
	virtual void Rotate( const UGPoint2D& pntOrigin, UGdouble dCosAngle, UGdouble dSinAngle,double dAngle = 0);
	
	virtual UGbool Resize(const UGRect2D& rcNewBounds);
	
	virtual UGbool SaveGeoData(UGStream& stream, UGDataCodec::CodecType eCodecType,UGbool bSDBPlus = FALSE) const;
	virtual UGbool LoadGeoData( UGStream& stream , UGDataCodec::CodecType eCodecType = UGDataCodec::encNONE,UGbool bSDBPlus = FALSE );

	virtual UGString ToXML(UGGeometry::GMLVersionType versionType, UGint nPace = 0)  const;
	
	//! \brief 从XML字符串中生成Geometry
	virtual UGbool FromXML(const UGString& strXML,UGGeometry::GMLVersionType versionType);

protected:
	
	virtual UGRect2D ComputeBounds() const;
	
public:

	// 得到三角形
	UGTri* GetTriangle();

	// 设置三角形
	void SetTriangle(UGTri* pTriangle);

	// 得到点
	UGPoint3D* GetPoints();

	// 设置点指针
	void SetPoints(UGPoint3D* pnt);

	// 得到三角形的个数
	UGint GetTriCount();

	// 得到实际三角形的个数
	UGint GetRealTriCount();

	// 设置块内新的三角形数
	UGTri* AllocRealTriCount(UGint nCount);

	// 得到块内点的个数
	UGint GetLivePntCount();

	// 设置块内点的个数
	void SetLivePntCount(UGint nCount);

	// 设置块内三角形的个数
	void SetTriCount(UGint nCount);

	// 设置块内实际三角刑的个数
	void SetRealTricount(UGint nCount);

	// 得到该块内冗余点的个数
	UGint GetDeadPntCount();

	// 设置冗余点的个数
	void SetDeadPntCount(UGint nCount);

	// 得到实际块内的点数
	UGint GetRealPntCount();

	// 设置实际块内点数
	void SetRealPntCount(UGint nCount);

	// 设置块内新的点数
	UGPoint3D* AllocRealPntCount(UGint nCount);

	// 得到某个冗余点实际所在的位置
	PntLocation* GetOriLocation(UGint nIndex);

	// 得到邻居
	TriLocation* GetNeighbour(UGint nIndex);

	// 添加邻居
	UGint AddNeighbour(TriLocation* pTriloc);

	// 返回记录冗余点位置的数组
	PntLocation* GetPntLocation();

	// 为记录冗余点位置的数组分配内存空间
	PntLocation* AllocPntLocation(UGint nCount);

	// 删除tinblock
	void DeleteTinBlock();

	// 设置最大高程值
	void SetMax(UGdouble dMax);

	// 得到最大高程值
	UGdouble GetMax();

	// 设置最小高程值
	void SetMin(UGdouble dMin);

	// 得到最小高程值
	UGdouble GetMin();

	// 该块有数据
	UGbool IsInUse();

	// 为m_pTinBlock分配内存
	TinBlock* AllocTinBlock();

	// 返回m_arrContours
	UGArray<ContourLayer*>& GetContourLayer();
	
	// 删除arrContours
	void DeleteContourLayer(UGArray<ContourLayer*>& arrContours);

	// 找出dValue跨越的三角形id，并将id存放在arrTriIndex中
	void FindContours(UGdouble dValue, UGArray<UGint>& arrTriIndex);

	// 将三角网里每个三角形都转化为闭合线
	void ToGeoLine(UGGeoLine*& pGeoLine, UGint& nCount);

	// 重新写hittest
	UGbool HitTest1( const UGPoint2D &pntHitTest, UGdouble dTolerance, TriInfo& triInfo);

	// 将UGTri信息转化为TriInfo输出
	void ToTriInfo(UGTri* pTri, TriInfo& triInfo);

	//! \brief 拷贝构造GeoTinBlock
	//! \param geoTinBlock [in] 已有Tin对象。
	//! \return 已有Tin对象非法, 返回false。
	UGbool Make(UGTINBlock& geoTinBlock);
	
	// 返回邻居的个数
	UGint GetNbrCount();

private:

	// 逆时针判断
	UGint counterclockwise(UGdouble x1, UGdouble y1, UGdouble x2, UGdouble y2, UGdouble x3, UGdouble y3);

	// 点在三角形内方法判断
	UGint PntInTriangle(const UGPoint2D& pnt, UGdouble* pTriangle);

private:

	TinBlock* m_pTinBlock;

	UGArray<ContourLayer*> m_arrContours;	

	UGdouble m_dMin;
	UGdouble m_dMax;

public:
	
	

};

}
#endif // !defined(AFX_UGTINBLOCK_H__B8A0F1B0_141E_406A_9ED8_915ED741FD93__INCLUDED_)
