// UGLineSymbolBaseDrawer.h: 

#ifndef UG_LINESYMBOLBASE_DRAWER_H
#define UG_LINESYMBOLBASE_DRAWER_H

#include "Algorithm/UGPoint2D.h"
#include "UGPolylineParam.h"
#include "Base/UGThread.h"
#include "Symbol/UGMarkerSymbol.h"
namespace UGC
{
	class UGGraphics;
	class UGLineSymParam; 
	class UGLineSymbolBase;

/** 线型基线的绘制器，封装绘制的实现细节，提供基线BaseLien绘制的接口
	@remarks
	   系统中基线(BaseLine)有49种风格类型，不同风格的绘制方法差异很大，
	根据绘制方法，可以大致把这些基线分成3种类型:		   
	
	1。非虚实模式型
	   对于电力线和渐变线, 需要单独处理, 因为它们不按照虚实模式进行循环
	   DSV_ELECTRIC            -->电力线段 
	   DSV_ELECTRICEX          -->电力线段(带中间线)
	   DSV_ELECTRIC_SPECIAL    -->电力线段(特殊)
	   DSV_ELECTRICEX2         -->电力线段(圆心)

	2。虚实模式型-->按照虚实模式进行循环绘制
	   虚实模式型绘制的方法：沿着折线，从起始点到结束点，按照长度，依次循环绘制由该基线定义的
	虚实模式；注意的是：一个折线段(一条折线有多条折线段)内如果没有把某个模式部分画完，
	那么在下一个折线段内要接着绘制。
	相当于把这条折线拉直成一条直线段，然后从头到尾循环地按照虚实模式指定的长度来绘制完
	整个长度

	3。平行线型
		DSV_DOUBLEPARELLEL     -->平行双线(中心对齐)
		DSV_LEFTPARELLEL       -->平行双线(上边对齐)
		DSV_RIGHTPARELLEL      -->平行双线(下边对齐)
	对于平行线型风格的基线, 必须单独处理(先构造出平行线, 然后再按照虚实模式进行循环绘制)	
*/
	

class UGLineSymbolBaseDrawer
{
public:
    UGLineSymbolBaseDrawer();
	~UGLineSymbolBaseDrawer();

public:
	//! 设置并初始化绘制器的内部参数(注：调用ToDraw()函数之前一定要先调用该函数来设定好内部参数)
	void InitInternalParam(UGLineSymbolBase* pBaseLine, UGGraphics* pGraphics, UGLineSymParam* pDrawParam);

	//! 对外的唯一绘制接口，pPoints中存储的是折线坐标点数据
	void ToDraw(const UGPoint* pPoints, UGint nCount);

protected:
	enum DrawingType
	{
		DT_Modely,       //虚实模式循环绘制
		DT_NonModely,    //非虚实模式绘制
		DT_Parellelly    //平行线绘制
	};
	
	struct ModeLenPair
	{
		UGdouble m_SolidPartLen;  //实部分的长度
		UGdouble m_EmptyPartLen;  //虚部分的长度
	};
	
	/*{--------------------------处理绘制的函数-------------------------------*/
	//! 三个主绘制函数(三大类型的绘制方法：平行线绘制+虚实模式循环绘制+非虚实模式绘制)
	void DrawNonModely(const UGPoint* pPoints, UGint nCount);
	void DrawModely(const UGPoint* pPoints, UGint nCount);
	void DrawParellelly(const UGPoint* pPoints, UGint nCount);

	//! 绘制模式的一个部分『虚部分或实部分』(仅在DrawModely()中被调用)
	UGbool DrawOneModePart(const UGPoint* pPoints, UGint nPntCount, 
		                   UGbool bSolidPartOrEmptyPart, UGdouble dModePartLen, 
						   UGint& curSegIndex, UGdouble& curSegRemainLen, UGPoint2D& pntFrom);

	enum ModePartState
	{  //在绘制一个模式线段时，模式线段的四种绘制状态
	   //用于DrawOneModePart()中和DrawLine()中
		MPS_WholePart,  //整段部分
		MPS_FrontPart,  //前段部分
        MPS_MiddlePart, //中间部分
		MPS_RearPart    //后段部分
	};
	//! 绘制一条“线”，其中会根据基线的风格类型，绘制不同类型的线型(仅在DrawOneModePart()中被调用)
	void DrawLine( const UGPoint2D& pntFrom, const UGPoint2D& pntTo , 
		           UGdouble PartLen, ModePartState ePartState, UGbool bSolidPart );

	//! 为模式开始循环绘制做准备工作(仅被DrawModely()调用)
	void DoPrepareForModelyDraw(const UGPoint* pPoints, UGint nCount);

	/*}--------------------------处理绘制的函数-------------------------------*/

	
protected:
	/*{----------------------处理偏移的函数-------------------------------*/
	
	//! 处理偏移
	void ProcessOffSet(const UGPoint* pOriginalPoints, UGint nOriginalCount, UGPoints& offsetPointArry);

	//! 处理横向偏移，仅在ProcessOffSet()中被调用
	void HoriOffSet(const UGPoint* pOriginalPoints, UGint nOriginalCount, UGPoints& offsetPointArry);

	//! 处理纵向偏移，仅在ProcessOffSet()中被调用
	void VertOffSet(const UGPoint* pOriginalPoints, UGint nOriginalCount, UGPoints& offsetPointArry);

	//! 计算平行线(仅在VertOffSet和DrawParellelly()中被调用)
	UGbool CalcParallel(const UGPoint *lpPoints, UGint nPntCount, UGdouble dWidth, UGPoints& pntParallels);

	//! 光栏法去点(仅在CalcParallel中被调用)
	UGbool LampHouseSmooth(const UGPoint* lpPoints, UGint nCount, UGdouble dTolerance, UGPoints &arrPoints);

	/*}----------------------处理偏移的函数-------------------------------*/


protected:
	//! 根据绘制参数DrawingParam以及基线本身的参数，来设置Graphics新GDI对象，同时将原来的GDI对象指针记录起来
	void PrepareGraphics();
	//! 恢复Graphics
	void RestoreGraphics();

	//! 以下3个函数在PrepareGraphics()中被调用，准备新的GDI对象
	void PrepareNewPen();
	void PrepareNewBrush();
	void PrepareNewFont();

	//! \brief 调整虚实部的长度，实现完整的绘制
	/**
	\param dtotalModeLens  线型一个周期的长度[in]
	\param dScale  返回虚实部调整比例[out]
	\return 是否调整成功
	*/
	UGbool AdjustModeLenPair(UGdouble& dtotalModeLens,UGdouble& dScale);

protected:
	//// 3个处理偏移以及模式绘制时的辅助函数
	//! 求一个线段的长度
	UGdouble SegmentLength(UGdouble xPntStart, UGdouble yPntStart, 
								  UGdouble xPntEnd, UGdouble yPntEnd);
	//! 求线段上的某个点，该点偏离线段起点(PntStart)的距离为offsetLen(如果距离为负，则是反方向延长线上的点)
	UGPoint2D CalcOffsetPntOnSegment(UGdouble xPntStart, UGdouble yPntStart, 
											UGdouble xPntEnd,   UGdouble yPntEnd, UGdouble offsetLen);
	//! 求垂直于线段, 起点为pntAnchor, 高度为 dHeight 的点的坐标
	UGPoint2D CalcVerticalPntOfSegment( UGdouble xPntStart,  UGdouble yPntStart, 
											   UGdouble xPntEnd,    UGdouble yPntEnd, 
											   UGdouble xPntAnchor, UGdouble yPntAnchor, 
											   UGdouble dHeight );

	//! 计算 渐变线两端 的折线(仅在DrawGradient()中被使用)
	void CalculateGradient( const UGPoint* lpPoints, UGint nCount,
							UGdouble dStartWidth, UGdouble dEndWidth, 
							UGPoints &arrLeftPoints, UGPoints &arrRightPoints);

protected:
	//! 是什么绘制类型(由基线的风格类型来确定的)
    DrawingType IsWhatDrawingType();

	//! 长度的逻辑转换计算(0.1mm的单位到逻辑单位，同时考虑缩放)
	UGdouble LOMETRIC2LPWithScaling(UGint nLOMETRICLen);

	//! 基线是否需要进行偏移处理(内部辅助函数)
	UGbool IsBaseLineNeedHoriOffset();
	UGbool IsBaseLineNeedVertOffset();


protected:  //以下是各种具体风格线型的绘制函数
	
	//绘制渐变线
	void DrawGradient(const UGPoint* pPoints, UGint nCount);
	
	//! 绘制电力线箭头
	void DrawElectricArrow(const UGPoint2D& pntFrom, const UGPoint2D& pntTo );
	
	//! 绘制电力线
	void DrawElectric(const UGPoint* pPoints, UGint nCount);
	
	//! 绘制电力线(特殊)
	void DrawElectricSpecial(const UGPoint* pPoints, UGint nCount);
	
	//! 绘制电力线(圆心)
	void DrawElectricWithCircle(const UGPoint* pPoints, UGint nCount);

	//! 绘制短竖线
	void DrawShortVert(const UGPoint2D& pntAnchor);

	//! 绘制上下交错线
	void DrawUpDownCross(const UGPoint2D& pntAnchor, UGbool bSolidPart);

	//! 绘制倾斜线
	void DrawBevel(const UGPoint2D& pntStart, const UGPoint2D& pntEnd,
		           ModePartState ePartState, UGdouble PartLen );
	//! 绘制倾斜上下交错线
	void DrawBevelUpDownCross(const UGPoint2D& pntStart, const UGPoint2D& pntEnd, UGbool bSolidPart, 
		                      ModePartState ePartState, UGdouble PartLen);

	//! 绘制箭头
	void DrawArrow(const UGPoint2D& pntStart, const UGPoint2D& pntEnd, 
		           ModePartState ePartState, UGdouble PartLen);

	//! 绘制波浪线(虚部分需要画的)
	void DrawWaveLine(const UGPoint2D& pntStart, const UGPoint2D& pntEnd, 
		              UGbool bSolidPart, ModePartState ePartState);

	//! 绘制长城符号(虚部分需要画的)
	void DrawGreatWall(const UGPoint2D& pntStart, const UGPoint2D& pntEnd, UGbool bSolidPart);

	//! 绘制长方盒(虚部分不用画)
	void DrawBox(const UGPoint2D& pntStart, const UGPoint2D& pntEnd);

	//! 绘制交叉符号(虚部分不用画)
	void DrawCrossSymbol(const UGPoint2D& pntStart, const UGPoint2D& pntEnd);
	//! 绘制交叉符号(虚部分需要画的，只针对DSV_VCROSSUPDOWN)
	void DrawCrossSymbolUpDown(const UGPoint2D& pntStart, const UGPoint2D& pntEnd, UGbool bSolidPart);

	//! 绘制半圆弧
	void DrawArc(const UGPoint2D& pntStart, const UGPoint2D& pntEnd);
	//! 绘制半圆弧(只针对DSV_VBIARCUPDOWN)
	void DrawArcUpDown(const UGPoint2D& pntStart, const UGPoint2D& pntEnd, UGbool bSolidPart = TRUE);

	//! 绘制填充圆
	void DrawCircle(const UGPoint2D& pntStart, const UGPoint2D& pntEnd);
	//! 绘制填充圆(只针对DSV_VCIRCLEUPDOWN)
	void DrawCircleUpDown(const UGPoint2D& pntStart, const UGPoint2D& pntEnd, UGbool bSolidPart = TRUE);

	//! 绘制带箭头的短横线
	void DrawDashWithArrow(const UGPoint2D& pntStart, const UGPoint2D& pntEnd, ModePartState ePartState);
	
	//! 绘制字符
	void DrawCharacter(const UGPoint2D& pntFrom, const UGPoint2D& pntTo);

	//! 绘制自定义符号
	void DrawSymbol(const UGPoint2D& pntFrom, const UGPoint2D& pntTo);

private:
	//! 画布
	UGGraphics* m_pGraphics;

	//! 绘制参数
	UGLineSymParam* m_pDrawingParam;

	//! 线型的基线，该绘制器以此基线的参数去绘制
	UGLineSymbolBase* m_pBaseLine;

	//! 缩放后的基线的垂直方向上的逻辑高度(只计算一次保存起来，在循环绘制中使用，提高效率)
	UGdouble m_nLogicalVertLenWithScaling;

	//modified by xielin 2007-12-27 现在要支持多线程，全局就不行了，改掉
	//! 缩放后的绘制模式的逻辑长度(只计算一次保存起来，在循环绘制中使用，提高效率)
	UGArray<ModeLenPair> m_LogModeLens;

	//modified by xielin 2007-12-27 现在要支持多线程，全局就不行了，改掉
	//! 折线的参数，用于线型循环绘制模式长度时计算绘制点
	UGPolylineParam  m_PolylineParam;
	
	//! 绘制过程中的辅助变量，标志是否是刚开始绘制折线(仅用于DrawWaveLine()和DrawGreatWall()中)
	UGbool m_bPolyLineStart;

	//! 绘制过程中的辅助变量，当前线段已经被绘制的长度(仅用于DrawOneModePart()中)
	UGdouble  m_dLenHaveDrawnOnCurSegment;

	//! 4个内部临时缓冲坐标点(用于在各具体风格线型的绘制过程中临时保存中间计算的坐标点)
	UGPoint2D m_BufferPnt1;
	UGPoint2D m_BufferPnt2;
	UGPoint2D m_BufferPnt3;
	UGPoint2D m_BufferPnt4;

	//! 绘制字符型基线时的辅助变量，计算一次后保存在这里，以便循环绘制过程中不用再计算，直接拿来使用
	UGint m_nFontHeight;	

	//! 绘制自定义型基线时的辅助变量,
	UGMarkerSymbol* m_pSymbol;
	UGMarkerSymParam* m_pSymParamForSymbol;

	//xll test ^_^
	UGMutex m_mutex;
	
private:
	//! 禁止拷贝和复制(not implemented)
	UGLineSymbolBaseDrawer(const UGLineSymbolBaseDrawer& rhs);
	UGLineSymbolBaseDrawer& operator=(const UGLineSymbolBaseDrawer& rhs);
};

	
}

#endif


