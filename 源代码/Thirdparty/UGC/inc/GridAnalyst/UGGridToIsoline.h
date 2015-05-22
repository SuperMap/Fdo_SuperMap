//算法思想很经典，可惜实现的很糟糕
//1、不更改算法的思想。
//2、重写其数据结构。
//3、调整程序结构。
//算法的思路是：
//1、根据等值线的值，在DEM中提取出相应的等值点。
//2、将等值点连成等值线。
//
//            ┏。┳━┳━┓
//            ┃ \┃  ┃  ┃
//            ┣。╋━╋━┫
//             。/┃  ┃  ┃ 
//            ┣━╋━╋━┫
//            ┃  ┃  ┃  ┃		
//            ┣━╋━╋━┫
//			  ┃  ┃  ┃  ┃
//			  ┣━╋━╋━┫	
//
//
//
//}}

/*--------by Y.M.Zheng 2006.02-------------------------*\
 1. 修改了GridEdge的数据结构，提高效率
	重写了AcquireIsoPnts()、TopToBottomTrace()、BottomToTopTrace()、
	LeftToRightTrace()、RightToLeftTrace()
	TraceOpenIsoline()、TraceClosedIsoline()、
	TraceContour()这几个主函数
    增加了一个函数TraceNextPoint()

 2. 重构代码(原来的代码太凌乱了)，
    删除所有无用的代码，添加关键注释
\*---------by Y.M.Zheng--------------------------------*/

#if !defined(AFX_GRIDTOISOLINE_H__22CCAB83_B299_11D3_8A28_0080C8EE62D1__INCLUDED_)
#define AFX_GRIDTOISOLINE_H__22CCAB83_B299_11D3_8A28_0080C8EE62D1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Base/ugdefs.h"
#include "Algorithm/UGPoint2D.h"
#include "Engine/UGDatasetRaster.h"
#include "Base/UGList.h"

/*--------------------------------------------------*\
      网格边
  其中记录：
      1. 网格边的标识(xNum,yNum,bIsHorV);
	  2. 该网格边上的等值点的坐标;
	  3. 该网格边在追踪过程中是否被使用过;
  
	              (xNum+1,yNum)       (xNum+1,yNum+1)  
	                      ____________
                         |            |
				         |            |
	          纵边b----→| (网格单元) |
				         |            |
				         |____________|
                   (xNum,yNum) ∣   (xNum+1,yNum)
				               ∣
						       ↓
						     横边a

     // NOTE: 
	 // (xNum,yNum)是端点所在的行号和列号，都是从0开始计数
	 // 端点，对于横边，就是其左端点；对于纵边，就是其下端点
	 // (xNum,yNum,bIsHorV)-->这三个变量来共同标识一条边
	 // 上图中，横边a和纵边b的前2个变量(xNum,yNum)相同，
	 // 靠bIsHorV来区分，bIsHorV为True就是横边，否则是纵边     
       
\*--------------------------------------------------*/
namespace UGC {

const UGdouble dMinTolerance = 1.0e-9;

class GridEdge
{

public:
	//GridPnt  GridPnt1;  
	//GridPnt  GridPnt2;
	
	// 不需要同时记录两端点的位置，
	// 只需要记录一个端点(xNum,yNum)，再加一个是横边还是纵边的标志就行了，
	// 这样的结构有2个好处：
	// 1。相对节省内存；
	// 2。方便算法的实现(因为算法中经常需要判断一条网格边是横边还是纵边)；
	
	UGint  xNum;
	UGint  yNum; 
	UGbool bIsHorV; // true:横边；false:纵边 (note:用UGbool比用UGbool内存要小)

	//一个边上只有一个等值点, 因此在为一个值追踪等值线时,它只能被用一次
	UGbool bUsed;

	// 该网格边上的等值点，一条边上就只有一个等值点
	UGPoint2D EdgeIsoPnt;

	GridEdge() : xNum(0), yNum(0), bIsHorV(true), bUsed(false)
	{}
	
};

//-------- Define Isoline:
class UGIsoline
{
public:
	UGIsoline()/*: IsSelected(FALSE)*/
	{}

	~UGIsoline() 
	{
		// UGList的析构函数中自动会调用RemoveAll()
		/*Isoline2DPntList.RemoveAll();*/ 
	}

    UGdouble m_dz;

	//等值线上的等值点(x,y)数组
	UGList<UGPoint2D> Isoline2DPntList;


	//UGbool IsSelected;

	UGbool CompressPoints(UGdouble dTolerance);
	UGbool ConvertToPoint2Ds(UGArray<UGPoint2D> &arrPoints);
	//UGIsoline& operator=(UGIsoline &p);
};

/*inline UGIsoline &UGIsoline::operator=(UGIsoline &PolyLine)
{  	
	this->m_dz=PolyLine.m_dz;
	Isoline2DPntList.RemoveAll();
	
	POSITION Pos = PolyLine.Isoline2DPntList.GetHeadPosition();
    while(Pos != NULL) 
	{
	   Isoline2DPntList.AddTail(PolyLine.Isoline2DPntList.GetNext(Pos));
	}
	return *this;
}*/



//----------  The below:  fully use the above definations --------------
class UGGridToIsoline  
{
public:
	UGGridToIsoline(UGDatasetRaster *pSmDatasetGrid, UGint nSmoothDegree = 3, UGint nSmoothMethod = 0,UGdouble dTolerance = 0.0f);
	virtual ~UGGridToIsoline();

public:
    
	// 数据的相关信息
	UGDatasetRaster* m_pDtRaster;
	UGuint m_unWidth;  // 网格的列数
	UGuint m_unHeight; // 网格的行数
    UGdouble m_dResolutionX; // 网格列之间的距离间隔
	UGdouble m_dResolutionY; // 网格行之间的距离间隔
	UGdouble m_dMinZ; // 数据中的最小值
//	UGdouble m_dMaxZ; // 数据中的最大值

	// 所要追踪的等值线的值
	UGdouble m_dZValue; // Isoline Z Value

	// 等值线曲线进行光滑的光滑参数
//	UGdouble m_dBaseContourVal;//基曲线高度 
	UGuint m_nSmoothDegree; //光滑度	
	UGuint m_nSmoothMethod; //光滑方法
	UGdouble m_dTolerance; //压缩点的容限 caogf
	
protected:
	UGdouble m_dSmoothCut; //抹角法等分线段数
	
//    POSITION  m_posHeadPos, m_Pos, m_posTailPos;
//    POSITION  m_posHeadPos1,m_Pos1;
//    
//    UGPoint2D  m_pntA1;
//	  UGPoint2D  m_pntCurrA1;
//    GridEdge* m_pGridEdge2;
	
	// 追踪算法过程中需要前一等值点、当前等值点、下一等值点这三个信息
	UGList<GridEdge*>::POSITION  m_CurrentPos, m_NextPos;
	GridEdge  *m_pPrevGridEdge, *m_pCurrentGridEdge, *m_pNextGridEdge;
	UGPoint2D  m_CurIsoPt, m_NextIsoPt;
	

	GridEdge m_PrevGridEdge;
	

	// 在追踪下一个等值点时用到的临时辅助变量
	GridEdge *m_pTopHEdge, *m_pBottomHEdge, *m_pLeftVEdge, *m_pRightVEdge;
	GridEdge *m_pTmpGridEdge;
	UGPoint2D  TopTmpIsoPnt, BottomTmpIsoPnt, LeftTmpIsoPnt, RightTmpIsoPnt;
    

public:
	
	//output:
	UGList<GridEdge*> m_GridEdgeListWithIsoPnts;//存放带有等值点的Grid边的数组
    
    UGList<UGIsoline*> SmoothIsolines;//存放光滑等值线的数组

public:	
	// 获取Grid边上等值点的分布情况，记录带等值点的Grid边：
	UGbool AcquireIsoPnts(UGdouble dIsolineVal);

protected:

	UGbool TopToBottomTrace(/*UGPoint2D& OutIsoPnt*/);
	UGbool BottomToTopTrace(/*UGPoint2D& OutIsoPnt*/);
	UGbool LeftToRightTrace(/*UGPoint2D& OutIsoPnt*/);
	UGbool RightToLeftTrace(/*UGPoint2D& OutIsoPnt*/);
	
	UGbool TraceOpenIsoline(UGbool bSmooth = TRUE);
	UGbool TraceClosedIsoline(UGbool bSmooth = TRUE);

	// 根据前一点和当前点的信息，追踪下一点
	UGbool TraceNextPoint(); // added by Y.M.Zheng


public:
	UGbool TraceContour(UGdouble dContourVal, UGbool bSmooth = TRUE);

protected:	

	//设置抹角法光滑程度  如需进行4次抹角运算时，参数为4。注意：每进行一次，数据量增大一倍
	void SetSmoothDegree(UGlong nSmoothDegree);
	void SetSmoothMethod(UGlong nSmoothMethod);
    UGbool Smooth(UGIsoline* pIsoline, UGuint nSmoothDegree, UGlong nSmoothMethod = 0);//只为一个值光滑等值线,为多个则需要循环调用.

	void ExcludeUsedIsoPnts();//剔除已被追踪进等值线了的等值点
	void Reset();
	
public:

	void freeSmoothIsolines();
	void freeGridEdgeList();

};

}
#endif // !defined(AFX_GRIDTOISOLINE_H__22CCAB83_B299_11D3_8A28_0080C8EE62D1__INCLUDED_)




