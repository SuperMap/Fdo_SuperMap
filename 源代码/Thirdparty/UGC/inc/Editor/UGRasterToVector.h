// UGRasterToVector.h: interface for the UGRasterToVector class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGRASTERTOVECTOR_H__E193928D_9B42_45A1_964B_68933BAF9ED6__INCLUDED_)
#define AFX_UGRASTERTOVECTOR_H__E193928D_9B42_45A1_964B_68933BAF9ED6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Engine/UGDatasetRaster.h"
namespace UGC{
class UGPolyLine;

class EDITOR_API UGRasterToVector  
{
public:
	UGRasterToVector();
	UGRasterToVector(UGDatasetRaster *pDatasetRaster);
	virtual ~UGRasterToVector();
public:
	UGColor GetRasterBkColor();								//得到栅格背景色；
	void SetRasterBkColor(UGColor crRasterBack);				//指定栅格背景色；
	UGdouble GetFilter();											//得到过滤参数；
	void SetFilter(UGdouble dFilter);								//设置过滤参数
	UGlong GetSmooth();											//得到光滑度；
	void SetSmooth(UGlong lSmooth);								//设置光滑度；
	UGlong GetColorTolerance();									//得到颜色容限值；
	void SetColorTolerance(UGlong lColorTolerance);				//设置颜色容限值；
	UGbool GetAutoPan();											//得到是否自动移屏
	void SetAutoPan(UGbool bAutoPan);								//设置是否自动移屏
	UGDatasetRaster *GetDatasetRaster();							//得到栅格数据集；
	UGbool GetLastPoint(UGPoint2D &pntMap);						//得到最后一点；
	UGbool RemoveLastPoint();										//移除最后一点；
	UGbool IsCanTracing();										//是否能够跟踪；
	UGbool ImageToMap(UGPoint pntImage,UGPoint2D &pntMap,UGbool bCenter = TRUE);			//图像坐标到地图坐标
	UGbool MapToImage(UGPoint2D pntMap,UGPoint &pntImage);			//地图坐标到图像坐标；
	void Release();												//释放内存；
	UGbool GetGeoLine(UGGeoLine &GeoLine);							//取得跟踪后的线对象；
	void AttachDatasetRaster(UGDatasetRaster *pDatasetRaster);	//载入栅格数据集；
	UGbool IsTracingEnd();										//跟踪是否结束；
	UGbool TracingStart(UGPoint2D pnt2D);							//跟踪开始；
	UGbool TracingContinue();										//跟踪继续；
	UGbool TracingEnd();											//跟踪结束；
	UGbool TracingBack();											//反向跟踪
	UGbool TracingBreak(UGPoint2D pnt2D,UGbool bBreak = FALSE);		//跟踪打断；
	UGbool TracingAdd(UGPoint2D pnt2D);							//跟踪加点；
	UGbool TracingBreakCancel();									//取消跟踪打断；
	UGGeoRegion* TraceRegion(UGPoint2D pnt2D);
protected:
	UGbool FindRegionEdgePoint(UGPoint &pntStart,UGPoint &pntEnd);
	UGbool FindInRegion(UGArray<UGptr> &Regions);
	UGbool FindOutRegion(UGPoint point,UGArray<UGptr> &Regions);
	UGbool FindRegion(UGPoint point,UGPolyLine *pRegion,UGbool bOutRegion = TRUE);
	UGbool IsSameValue(UGdouble dValue1,UGdouble dValue2);
	UGbool IsValidPointEx(UGPoint pntCurrent);
	UGbool PointProjectToLineset(const  UGPoint2D &pntHitTest, UGPoint2D  pntLinsectStart, UGPoint2D pntLinsectEnd, UGPoint2D &resultPoint);
	UGbool PloylineBreak(UGPoint pntCurrent);						//打断折线
	UGbool IsValidPoint(UGPoint pntCurrent);						//是不是有效点；
	UGbool Reverse();												//数据反向；
	UGbool IsToEnd(UGPoint pntLast);								//是否到头；
	UGbool ToLinePoints();										//连接栅格块矢量跟踪所得数据到线数据；
	UGbool ToRasterBlock(UGPoint pntCurrent,UGbool bStart=FALSE);	//得到栅格块数据；
	UGint  GetBlockValue(UGint x,UGint y);							//得到栅格块像素值；
	UGbool IsDeleted(UGint x,UGint y);								//判断该像素点是否可以删除；
	UGbool BlockThinned(UGPoint &pntFront);						//栅格块细化；
	UGbool FindEdgePoint(UGPoint pntFront,UGPoint &pntEdge,UGPoint &pntREdge);	//查找栅格笔划的边缘点
	UGbool RemoveEdgePoint(UGPoint pntStart, UGbool bClockwise = false);			//拨皮法删除边缘点；
	UGbool FindNextEdgePoint(UGPoint pntBack,UGPoint pntCurrent,UGPoint &pntEdge, UGbool bClockwise = false);  //查找下一个边缘点；
	void Rotate(UGint &x,UGint &y, UGbool bClockwise = false);		//旋转90度；
	UGbool AddNextPoint(UGPoint pntBack,UGPoint pntCurrent,UGPoint &pntNext);	//取得下一点块数据；
	UGbool LampHouseSmooth(UGPoint* pPoints,const UGint nCount,UGdouble dTolerance,UGArray<UGPoint> &arrPoints); //光栏法光滑；
	UGbool GetNextCenterPoint(UGPoint &pntCenter);					//得到下一个上栅格块的中心点；
	UGbool IsSamePoint(UGPoint point1,UGPoint point2);				//是否同一点；
	UGbool GetBlockPoints(UGPoint pntCurrent);						//得到栅格块矢量数据；
	UGbool IsSameColor(UGColor color1,UGColor color2);			//判断颜色在允许范围内是否相同；
	UGbool ImageToImage(UGDatasetRaster *pDatasetRaster);			//转换到另一个图像的坐标；
protected:
	UGArray<UGbyte> m_arrRasterBlock;				//存储栅格块栅格数据的数组；
	UGArray<UGPoint> m_arrLinePointsTmp;	//临时存储线数据的数组；
	UGArray<UGPoint> m_arrLinePoints;		//存储线数据的数组；
	UGArray<UGPoint> m_arrBlockPoints;		//存储栅格块线数据的数组；
	UGDatasetRaster *m_pDatasetRaster;			//被跟踪的栅格数据集；

	UGPoint m_pntBlockStart;						//栅格块在栅格图像的起始为置；
	UGPoint m_pntTracingStart;					//继续跟踪或反向跟踪的起点；

	UGdouble		m_dFilter;						//过滤参数，值越大点越少；
	UGint		m_lSmooth;						//光滑参数，插值的点数；
	UGlong		m_lColorTolerance;				//颜色容限值；
	UGbool		m_bAutoPan;						//是否自动移屏；
	UGColor	m_crRasterBack;					//指定栅格背景色；
	UGdouble		m_dCurRasterValue;				//当前栅格值；

	UGbool		m_bTracingBack;					//是否做过反向跟踪操作；
	UGbool		m_bToEnd;						//是否到头；
	UGbool		m_bTracingEnd;					//是否跟踪结束；

};

}
#endif // !defined(AFX_UGRASTERTOVECTOR_H__E193928D_9B42_45A1_964B_68933BAF9ED6__INCLUDED_)
