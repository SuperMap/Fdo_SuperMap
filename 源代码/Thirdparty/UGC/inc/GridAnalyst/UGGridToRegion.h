//=====================================================================================
// 项目名：			SuperMap Foundation Class (SFC) Library 2.0
// 作  者：			王尔琪
// 单  位：			北京超图地理信息技术有限公司
// 最后修改时间：	以文件日期为准
//-------------------------------------------------------------------------------------
// 重要声明：		1. 类库使用范围为SuperMap GIS软件开发组成员，未经许可不得擅自传播。
//					2. 类库使用者不得修改本文件内容，否则会导致类库使用错误。
//					
//-------------------------------------------------------------------------------------
// 文件名：			UGGridToRegion.h
// 类  名：			UGGridToRegion
// 父  类：			
// 子  类：			
// 功能说明：		栅格矢量化
//
// 调用说明：		
//=====================================================================================

// UGGridToRegion.h: interface for the UGGridToRegion class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGGRIDTOREGION_H__34DC154F_9270_471F_B1DA_8A7F50E09786__INCLUDED_)
#define AFX_UGGRIDTOREGION_H__34DC154F_9270_471F_B1DA_8A7F50E09786__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Base/ugexports.h"
#include "Algorithm/UGPoint.h"
#include "Base/UGList.h"
#include "Engine/UGDatasetRaster.h"

namespace UGC {

#define SHOW_TIME_USED
#define New_Algorithm_USE_BUFFER


#define OUT_OF_RANGE -1

//#define NULLVALUE	0
#define FINISHED		((UGchar)0x0F)
#define INTERNAL		((UGchar)0x0F)
#define NOT_MARKED 255
#define EAST	0
#define SOUTH	1
#define WEST	2
#define NORTH	3
#define MAXSIDESNUMBER 4
#define IS_EDGE_SIDE 1
#define IS_INTERNAL_SIDE 0
//
//			north	
//			6 3 7 
//	west	3   0	east
//			5 1 4
//			south
//
//bits
// 0     1     2     3     4     5     6     7
//east south  west north

enum DIRECTION
{
	east=0,
	south=1,
	west=2,
	north=4
};


class UGSignalArray;

//直线类

class GRIDANALYST_API UGLine
{
public:
	UGPoint LeftEnd, RightEnd;
	UGLine()
	{
	}
	UGLine(UGPoint initLeftEnd,UGPoint initRightEnd)
	{
		LeftEnd=initLeftEnd;
		RightEnd=initRightEnd;
	}
	UGLine(UGlong initLeftEnd_x,UGlong initLeftEnd_y, UGlong initRightEnd_x, UGlong initRightEnd_y)
	{
		LeftEnd.x=initLeftEnd_x;
		LeftEnd.y=initLeftEnd_y;
		RightEnd.x=initRightEnd_x;
		RightEnd.y=initRightEnd_y;
	}
};


//折线类
class GRIDANALYST_API UGPolyLine
{
private:
	enum tagEND_BEGIN
	{
		begin=1,
		end=2,
		both=3,
		none=0
	} NeighborWith;

	UGbyte bNeighborWith;
	UGbool m_isclosed;
public:
	UGPoint & Tail();
	UGPoint & Head();
	UGList<UGPoint> m_Points;

	UGPolyLine();
	~UGPolyLine();
	UGbool IsClosed();
	UGbool CombineWith(UGPoint *points, UGlong count);
	UGbool CombineWith(UGLine lin);
	UGbool CombineWith(UGPolyLine& anotherPoly);
	UGbool ConvertToPoints(UGArray<UGPoint>& arrPoints);
	void PrintOut();
	void Reset();
	UGlong MergeEdgePointWith(UGSignalArray &SignalArray,UGlong p,UGlong &OriginEdges);
};

//折线链表
struct TPolyLines
{
	UGPolyLine PolyLine;
	TPolyLines *next;
};

//复杂形状
class GRIDANALYST_API UGShapes
{
public:
	UGShapes(UGlong initValue);
	~UGShapes();

	UGlong SectEndPos;
	UGlong SectBeginPos;
	UGbool IsExpanded_InUse;
	UGlong value;
	UGbool UnTouched;
	UGbool IsUsed;
	//
	//CTypedPtrArray<CObArray, UGPolyLine*> Poly;

	TPolyLines *polylines;
	UGlong PolyLinesNumber;
public:

	UGbool ToGeoRegion(UGDatasetRaster *pDatasetR,UGGeoRegion& geoRegion);
	void Reset();
	void AddLine(UGLine lin);
	void AddLine(UGPoint end1,UGPoint end2);
	void AddLine(UGlong end1_x,UGlong end1_y,UGlong end2_x,UGlong end2_y);
	//void CombineWithNewLine(UGPoint end1,UGPoint end2);
	UGbool AddShapes(UGShapes *another);
	UGlong MergePolyline(const UGlong nCompareIndex);
	UGlong Add(UGPolyLine &poly);
	//UGlong AddPolyline(UGPolyLine &poly);
	void PrintOut();
	void DeleteAll();
private:
	void Delete(TPolyLines * pPrev);

};

typedef UGArray<UGdouble> UGPointQueue;


class GRIDANALYST_API UGSignalArray
{
public:
	UGbyte* p;
	UGlong size;
	void MarkRangeAsInternal(UGint pnt1, UGint pnt2);
	UGlong y(UGlong pnt);
	UGlong x(UGlong pnt);
	UGlong rows,cols;

	UGSignalArray(UGlong rows, UGlong cols);
	~UGSignalArray();
	UGbool IsEdgePoint(UGlong i);
	UGbool IsUsed(UGlong i);

	void MarkAsUsed(UGlong i);
	void MarkAsInternal(UGlong i);
	UGlong GetSidePnt(UGlong SideIndex,UGlong pnt);
	UGlong EastPnt(UGlong curPoint);
	UGlong SouthPnt(UGlong curPoint);
	UGlong WestPnt(UGlong curPoint);
	UGlong NorthPnt(UGlong curPoint);
	void ReSetSideMark(UGlong SideIndex,UGlong pnt);
	void SetSideMark(UGlong SideIndex,UGlong pnt);
	void SetOppsiteSideMark(UGlong SideIndex,UGlong pnt);
	void MarkEastSide(UGlong pnt);
	void MarkSouthSide(UGlong pnt);
	void MarkWestSide(UGlong pnt);
	void MarkNorthSide(UGlong pnt);

	UGLine GetSideEdge(UGlong SideIndex,UGlong pnt);
	UGlong GetSideMark(UGlong SideIndex,UGlong pnt);
	void PrintOut();
};

class GRIDANALYST_API UGDivisionSection  
{
private:
	void AddLine(UGLine lin);
	void AddLine(UGlong initLeftEnd_x,UGlong initLeftEnd_y, UGlong initRightEnd_x, UGlong initRightEnd_y);
public:
	UGbool CreateNewPolygon();
	UGbool ConnectTo(UGDivisionSection& j1);
	UGbool CombineTo(UGShapes &existing_polygon);
	void AddThreeNewEdges();
	void AddPartBottomEdge(UGlong left, UGlong right);
	void AddPartTopEdge(UGlong left, UGlong right);
	void AddRightEdge();
	void AddLeftEdge();
	void Init(UGlong begin, UGlong end, UGlong initvalue, UGlong initRowIndex);
	UGShapes *combinewith(UGDivisionSection *another);
	UGLine GetAt(UGlong pos);
	UGlong GetSize();
	void RemoveAll();

	UGint Intersect(UGDivisionSection* pDivisition);

	UGDivisionSection();
	virtual ~UGDivisionSection();
	UGlong b;//begin position of this section
	UGlong e;// end position of this section
	UGlong value;//value which this section represent
	UGlong RowIndex;//row's index which may be the lefttop_y+1
	
	//The following is for new polygon and old polylines
	
	//LeftPoint then RightPoint
	//first line , second line , third line ...
	//UGPolyLine polyline;
	UGArray<UGPoint> lines;
	
	//The following is for being combined polygon
	
	UGShapes* oldpolygon;//point to polygon which this section beUGlongs to
						//if one polygon in then second line has been combined then it's not NULL

	//UGbool IsExpanded_NotFinished;//if not then this polygon is finished

	//UGbool writed;//if be writed to file, then this polygon will be finished
};
//封装了栅格到矢量的转换
class GRIDANALYST_API UGGridToRegion
{
public:
	// 将栅格数据集转成矢量数据集
	// 参数：
    //         pDatasetR:  待转换的栅格数据集
	//         pDatasetV:  转换整的矢量数据集(用户自己分配空间)
	//         SHOW_PROCESS_BAR 是否显示转换进度条
	//         nNullValue  空值的亮度值
	UGbool Grid2Region(UGDatasetRaster *pDatasetR, UGDatasetVector *pDatasetV, UGbool SHOW_PROCESS_BAR=true, UGlong nNullValue=0);
	// 将栅格数据集转成矢量数据集
	// 参数：
    //         pDatasetR:  待转换的栅格数据集
	//         pDatasetV:  转换整的矢量数据集(用户自己分配空间)
	//         SHOW_PROCESS_BAR 是否显示转换进度条
	//         nNullValue  空值的亮度值
	UGbool Grid2RegionLineScan(UGDatasetRaster *pDatasetR, UGDatasetVector *pDatasetV, UGbool SHOW_PROCESS_BAR=true, UGlong nNullValue=0);
    // 查找指定点范围内的区域对象
	UGGeoRegion * Grid2Region(UGDatasetRaster *pDatasetR, UGDatasetVector *pDatasetV, UGPoint A_Point);
	UGGridToRegion();
	virtual ~UGGridToRegion();

	//////////////////////////////////////
	//Find edge of polygon
	//////////////////////////////////////
protected:
	UGlong SearchRegion(UGlong StartPoint,
		UGlong row,UGlong cols,
		UGlong *ValueArray,
		UGSignalArray &SignalArray, UGShapes *Shapes);
	UGlong SearchRegion(UGlong StartPoint,
				  UGlong rows,UGlong cols,
				  UGDatasetRaster *pDatasetR,
				  UGSignalArray &SignalArray, UGShapes *Shapes);
	UGlong FindEdgePoints(UGlong cols, UGlong *ValueArray, UGSignalArray &SignalArray,
		UGPointQueue &FrontEdge, UGPointQueue &EdgePoints);
	UGlong FindEdgePoints(UGlong cols, UGDatasetRaster* pDatasetR, UGSignalArray &SignalArray,
					UGPointQueue &FrontPoints, UGPointQueue &EdgePoints);
	void EdgePoints2PolyLines(UGSignalArray &SignalArray,
		UGPointQueue &EdgePoints, UGShapes *Shapes);
	//UGGeoRegion* Shapes2Poly(UGDatasetRaster *pDatasetR,UGShapes *Shapes);

	UGbool MatchPoints(UGPoint* pPoints,const UGint nCount,UGArray<UGPoint> &arrPoints);//第一次去轮齿  add 9.7 liuqj
	UGbool CompressPoints(UGPoint* pPoints,const UGint nCount,UGlong nTolerance,UGArray<UGPoint> &arrPoints);//压缩  add 8.7 liuqj
};

}

#endif // !defined(AFX_UGGRIDTOREGION_H__34DC154F_9270_471F_B1DA_8A7F50E09786__INCLUDED_)
