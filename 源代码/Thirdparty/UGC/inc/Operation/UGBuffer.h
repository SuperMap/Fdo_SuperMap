/*! \file 		UGBuffer.h
*   \brief 		缓冲区 
*   \remarks 	对象的缓冲区，包括圆头和平头 
*   \author 	LIWENLONG 
*   \date 	2004-12-27 10:51:48

*   Copyright(c) 1996-2004 SuperMap GIS Technologies,Inc.<br> 
*        All Rights Reserved 

*    <b>更新说明：</b><br> 
*	 guohui 2007.11.01	新的缓冲区实现算法(关键词：扫描线算法、最大转角法、构面、构线、线打断、索引)
*/ 


#ifndef UGBUFFER_H
#define UGBUFFER_H

#include "Base/ugdefs.h"
#include "Base/UGString.h"
#include "Base/UGProgress.h"
#include "Algorithm/UGPoint2D.h"
#include "Geometry/UGGeoRegion.h"
#include "Engine/UGDataset.h"
#include "Engine/UGRecordset.h"

namespace UGC {
//! \brief 缓冲区
/**		
使用流程:
	(1) 定义一个 UGBufferParam 对象，根据实际需求，设置其内部值。
	(2) 采用 UGBuffer::CreateBuffer 调用缓冲区接口。

输入：
	对象：0维对象(UGGeoPoint,UGGeoMultiPoint).1维对象(UGGeoLine,UGGeoLineM,UGGeoArc,
	UGGeoCircle,UGGeoPie等，但参数化对象按照线段拟合来处理).2维对象(UGGeoRegion,
	UGGeoRect等)
	数据集：0维、1维、2维数据集。
	记录集：0维、1维、2维记录集。

输出：
	对象：面
	数据集：面数据集
	记录集：面记录集

备注：	
	(1) 如果输入是面数据集、面记录集且要生成合并的多边形，则传入面对象需保证合法的拓扑关系。(合法的拓扑关系:
	请参见 UGC 或 SFC 的相关说明。)
	(2) 对外接口第四个参数 pGeoTestLine、pTestDataset 是为后期维护提供的中间分析数据，外部用户(UGC内核开发人员以外)
	无需传递本参数。UGC 内核不复杂对中间分析数据正确性的维护。
	(3) 本方法支持缓冲区半径为负数的情况。此时，线的缓冲区左右反向；面的缓冲区由膨胀变为紧缩。
*/	

class OPERATION_API UGBuffer  
{
public:

	//! \brief 		边缓冲类型类型
	enum UGSideType
	{
		NONESIDE        = -1,			// 无边类型
		UGFULL			= 0,			// 左右均缓冲(缓冲半径相同)
		UGLEFT			= 1,			// 左边缓冲
		UGRIGHT			= 2,			// 右边缓冲
		UGFULLDIFFR		= 3				// 左右均缓冲(缓冲半径不相同)
	};

	//! \brief 		边缓冲类型类型
	enum UGEndType
	{
		NONEEND	        = 0,			// 无头缓冲
		UGROUND			= 1,			// 圆头缓冲
		UGFLAT			= 2				// 平头缓冲
	};
	enum UGSideDir
	{
		UGSIDELEFT		=0,				// 左边
		UGSIDERIGHT		=1				// 右边
	};
	

	//! \brief 缓冲区参数结构体	
	/**		
		(1) 缓冲半径是直接传入数字，则设置 m_bFieldRadius = false
		(2) 缓冲半径是直接传入数字，则半径保存于 m_dBufferRadius 中。否则字段名保存于 m_strBufferRadius。
		(3) 如果是左右不等的平头缓冲，则半径保存于 m_dDiffBufferRadius ，字段保存于 m_strDiffBufferRadius。
		(4) 缓冲区边类型保存于 m_nSideType.
		(5) 缓冲区端点类型保存于 m_nEndType.
		(6) 对于多个对象(比如数据集、记录集)生成缓冲区，m_bUnionRegion=falsle则返回多边形数与原对象数相同。
		(6) m_nSemicircleSegments 半圆弧拟合的线段数目(最小4，最大200)
	*/	
	struct  UGBufferParam
	{

		//! \brief 缓冲区半径
		/** \remarks 	可以为负数 */
		UGdouble m_dBufferRadius;

		//! \brief 缓冲区半径字段
		UGString m_strBufferRadius;


		//! \brief		左右不等的平头缓冲区的半径。 
		//!				m_dDiffBufferRadius[UGSIDELEFT],m_dDiffBufferRadius[UGSIDERIGHT]
		/** \remarks 	UGFULLDIFFR 且 UGFLAT 时有效 		*/
		UGdouble m_dDiffBufferRadius[2];

		//! \brief		左右不等的平头缓冲区的半径字段。 
		//!				m_strDiffBufferRadius[UGSIDELEFT],m_strDiffBufferRadius[UGSIDERIGHT]
		/** \remarks 	UGFULLDIFFR 且 UGFLAT 时有效 		*/
		UGString m_strDiffBufferRadius[2];


		//! \brief		缓冲区边类型
		/** \remarks	UGSideType 中的枚举类型			*/			
		UGint    m_nSideType;
		
		//! \brief		缓冲区端点类型
		/** \remarks	UGEndType 中的枚举类型			*/			
		UGint    m_nEndType;

		
		//! \brief		半圆弧的拟合线段数
		/** \remarks	缺省为 12,必须大于等于4,小于200		*/			
		UGint    m_nSemicircleSegments;		// 


		//! \brief		缓冲区半径是否是字段传入
		/** \remarks	缺省为 false		*/			
		UGbool   m_bFieldRadius;

		//! \brief		是否合并缓冲区
		/** \remarks	缺省为 true.单个对象缓冲区不起作用.	*/			
		UGbool	 m_bUnionRegion;

		//! \brief		是否保存字段信息
		/** \remarks	缺省为 false.单个对象缓冲区不起作用.	*/			
		UGbool   m_bSaveFieldInfo;

		//! \brief		容限
		UGdouble m_dTolerance;
		
		UGBufferParam()
		{
			m_nSideType				= UGFULL		;
			m_nEndType				= UGROUND		;
			m_nSemicircleSegments	= 12			;
			m_bFieldRadius			= FALSE			;
			m_bUnionRegion			= TRUE			;
			m_bSaveFieldInfo		= FALSE			;
			m_dTolerance			= -1			;
		}
	};
public:

	//! \brief 		对象创建缓冲区
	//! \param 		pGeometry		传入对象。支持点、线、面
	//! \param 		BufferParam		缓冲区参数
	//! \param 		buffer			返回缓冲区多边形
	//! \param 		pGeoTestLine	这是为了后期维护使用的缺省参数。外部请直接传递空指针即可。
	//!								除了UGC2.0底层开发外，此参数均无需使用
	static UGbool CreateBuffer(const UGGeometry * pGeometry,const UGBufferParam & BufferParam,
								UGGeoRegion& buffer,UGGeoLine * pGeoTestLine = NULL);

	//! \brief 		数据集创建缓冲区
	//! \param 		pDataset		传入对象。支持点、线、面
	//! \param 		BufferParam		缓冲区参数
	//! \param 		pResDataset		返回缓冲区面数据集.外部需要创建好该面数据集
	//! \param 		pTestDataset	这是为了后期维护使用的缺省参数。外部请直接传递空指针即可。
	//!								除了UGC2.0底层开发外，此参数均无需使用
	static UGbool CreateBuffer(UGDataset *pDataset,const UGBufferParam & BufferParam,
					UGDataset *pResDataset,UGDataset *pTestDataset=NULL);

	//! \brief 		记录集创建缓冲区
	//! \param 		pRecordset		传入对象。支持点、线、面
	//! \param 		BufferParam		缓冲区参数
	//! \param 		pResDataset		返回缓冲区面数据集.外部需要创建好该面数据集指针
	//! \param 		pTestDataset	这是为了后期维护使用的缺省参数。外部请直接传递空指针即可。
	//!								除了UGC2.0底层开发外，此参数均无需使用
	static UGbool CreateBuffer(UGRecordset *pRecordset,const UGBufferParam & BufferParam,
					UGDataset *pResDataset,UGDataset *pTestDataset=NULL);
public:
	//! \brief 		外部请勿使用，用于接口测试
	static UGbool BuildRegionTest(UGDataset *pDataset,UGDataset *pResDataset);
private:

	//! \brief 		记录集创建缓冲区(左右不等缓冲区)
	//! \param 		pRecordset		传入对象。支持点、线、面
	//! \param 		BufferParam		缓冲区参数
	//! \param 		pResDataset		返回缓冲区面数据集.外部需要创建好该面数据集指针
	//! \param 		pTestDataset	这是为了后期维护使用的缺省参数。外部请直接传递空指针即可。
	//!								除了UGC2.0底层开发外，此参数均无需使用
	static UGbool CreateBufferSIDEDIFF(UGRecordset *pRecordset,const UGBufferParam & BufferParam,
					UGDataset *pResDataset,UGDataset *pTestDataset=NULL);

	//! \brief 		数据集创建缓冲区(合并，缓冲半径相同)
	//! \param 		pDataset		传入对象。支持点、线、面
	//! \param 		BufferParam		缓冲区参数
	//! \param 		pResDataset		返回缓冲区面数据集.外部需要创建好该面数据集
	//! \param 		pTestDataset	这是为了后期维护使用的缺省参数。外部请直接传递空指针即可。
	//!								除了UGC2.0底层开发外，此参数均无需使用
	static UGbool CreateUnionBufferSameRadiu(UGRecordset *pRecordset,const UGBufferParam & BufferParam,
					UGDataset *pResDataset,UGDataset *pTestDataset=NULL);

	//! \brief 		数据集创建缓冲区(不合并，缓冲半径相同)
	//! \param 		pDataset		传入对象。支持点、线、面
	//! \param 		BufferParam		缓冲区参数
	//! \param 		pResDataset		返回缓冲区面数据集.外部需要创建好该面数据集
	//! \param 		pTestDataset	这是为了后期维护使用的缺省参数。外部请直接传递空指针即可。
	//!								除了UGC2.0底层开发外，此参数均无需使用
	static UGbool CreateNotUnionBufferSameRadiu(UGRecordset *pRecordset,const UGBufferParam & BufferParam,
					UGDataset *pResDataset,UGDataset *pTestDataset=NULL);

	//! \brief 		数据集创建缓冲区(不合并，缓冲半径不相同)
	//! \param 		pTestDataset	这是为了后期维护使用的缺省参数。外部请直接传递空指针即可。
	//!								除了UGC2.0底层开发外，此参数均无需使用
	static UGbool CreateUnionBufferDiffRadiu(UGRecordset *pRecordset,const UGBufferParam & BufferParam,
					UGDataset *pResDataset,UGDataset *pTestDataset=NULL);

	//! \brief 		数据集创建缓冲区(不合并，缓冲半径不相同)
	//! \param 		pTestDataset	这是为了后期维护使用的缺省参数。外部请直接传递空指针即可。
	//!								除了UGC2.0底层开发外，此参数均无需使用
	static UGbool CreateNotUnionBufferDiffRadiu(UGRecordset *pRecordset,const UGBufferParam & BufferParam,
					UGDataset *pResDataset,UGDataset *pTestDataset=NULL);
	
//{{==================================================
	//by guohui 2007.10.24 基于转角圆弧法的缓冲区
private:
	enum UGBufferLineType
	{
		NONELINE			=		-1,			// 非法的线
		PRIMARYLINE			=		0,			// 原始线
		PARALLELLINE		=		1,			// 平行线
		ARCLINE				=		2,			// 弧
		RADIUSLINE			=		3,			// (半,直)径
	};

	struct UGLineSeg
	{// 圆弧是从 start 到 end 的逆时针旋转
		UGPoint2D			m_pntStart;						// 线段的开始点
		UGPoint2D			m_pntEnd;						// 线段的结束点
		UGbool				m_bCircleLineSeg;				// 是否圆弧
		UGPoint2D			m_pntCentral;					// 如果是圆弧，则保存其圆心
		UGPoint2Ds			m_arrIntersecPnts;				// 相交的点
		UGint				m_LineType;						// 线的类型
		UGLineSeg()
		{
			m_bCircleLineSeg = false;
			m_LineType       = 1;
		}

	};

	//  只表示线段
	struct UGLineSegEx
	{
		UGPoint2D   m_pntStart;				// 线段的开始点
		UGPoint2D   m_pntEnd;				// 线段的结束点
		UGPoint2D * m_pPntCentral;			// 圆心
		UGLineSegEx()
		{
			m_pPntCentral = NULL;
		}		
		~UGLineSegEx()
		{
			if(m_pPntCentral!=NULL)
			{
				delete m_pPntCentral;
				m_pPntCentral = NULL;
			}
		}
	};

	struct  UGLineSegPnt
	{
		UGPoint2D m_LineSegPnt;		// 线段的点
		UGint     m_nIndex;			// 索引

		UGLineSegPnt()
		{
			m_nIndex = -1;
		}

		friend UGbool operator < (const UGLineSegPnt & segPoint1,const UGLineSegPnt & segPoint2)
		{
			return segPoint1.m_LineSegPnt<segPoint2.m_LineSegPnt;
		}

		UGbool operator < (const UGLineSegPnt & segPoint2)
		{
			return m_LineSegPnt<segPoint2.m_LineSegPnt;
		}

		void operator = (const UGLineSegPnt & segPoint)
		{
			m_LineSegPnt = segPoint.m_LineSegPnt;
			m_nIndex = segPoint.m_nIndex;
		}
	};

	struct  UGLineSegPntEx
	{
		UGLineSegEx * m_pLineSegEx;		// 线段的点
		UGbool        m_bStartPnt ;		// 开始点	
		
		UGLineSegPntEx()
		{
			m_pLineSegEx = NULL;
			m_bStartPnt  = FALSE;
		}
		friend UGbool operator < (const UGLineSegPntEx & segPoint1,const UGLineSegPntEx & segPoint2)
		{
			if(segPoint1.m_pLineSegEx==NULL || segPoint2.m_pLineSegEx==NULL)
			{
				return FALSE;
			}
			
			UGPoint2D pnt1 = segPoint1.m_bStartPnt? segPoint1.m_pLineSegEx->m_pntStart:segPoint1.m_pLineSegEx->m_pntEnd;
			UGPoint2D pnt2 = segPoint2.m_bStartPnt? segPoint2.m_pLineSegEx->m_pntStart:segPoint2.m_pLineSegEx->m_pntEnd;

			return pnt1<pnt2;
		}
		
		void operator = (const UGLineSegPntEx & segPoint)
		{
			m_pLineSegEx = segPoint.m_pLineSegEx;
			m_bStartPnt = segPoint.m_bStartPnt;
		}
	};

	// 线段的邻接矩阵结点
	struct UGLineSegNode
	{
		UGPoint2D		    m_pntFromNode	;				// 点
		UGArray<UGint>      m_nArrToIndex	;				// 另一点
		UGArray<UGPoint2D*> m_pArrPntCentral;				// 圆心坐标
		UGint				m_nInDegree		;
		UGLineSegNode()
		{
			m_nInDegree = 0;
		}
	};

	// 线段的邻接矩阵
	struct UGLineSegAdjMatrix
	{
		UGLineSegNode * m_pLineSegNode ;		// 结点,按照m_pntFromNode排序
		UGint			m_nNodeCount ;			// 结点个数
		UGLineSegAdjMatrix()
		{
			m_pLineSegNode = NULL;
			m_nNodeCount = 0 ;
		}
	};

private:

	//! \brief 		对线创建缓冲区
	// pGeoline 用于测试使用
	static UGbool CreateLineBuffer(const UGPoint2D* pPoints, const UGint *pPolyCounts,const UGint lSubCount
								,UGGeoRegion &buffer,UGint nSideType = UGFULL,UGint nEndType =UGROUND,
								UGGeoLine * pGeoline = NULL,UGdouble *pRadius=NULL,UGProgress * pProgress = NULL);

	//! \brief 		对点创建缓冲区
	// pGeoline 用于测试使用
	static UGbool CreatePointBuffer(const UGPoint2D* pPoints,const UGint nCount,
							UGGeoRegion &buffer,UGGeoLine * pGeoline = NULL,UGdouble *pRadius=NULL
							,UGProgress * pProgress = NULL);

	//! \brief 		对面创建缓冲区
	// pGeoline 用于测试使用
	static UGbool CreateRegionBuffer(const UGPoint2D* pPoints, const UGint *pPolyCounts,const UGint lSubCount
								,UGGeoRegion &buffer,UGGeoLine * pGeoline = NULL,UGdouble *pRadius=NULL
								,UGProgress * pProgress = NULL);

private:
	//! \brief 		创建缓冲区-按照转角法生成缓冲线
	static UGbool OutLine(const UGPoint2D* pPoints, const UGint *pPolyCounts, UGint lSubCount,
		UGLineSeg * &pLineSegs,UGint & nLineSegCount,UGint nSideType = UGFULL,
		UGint nEndType =UGROUND,UGbool bOnlyParalLine = FALSE,UGdouble *pRadius=NULL
		,UGProgress * pProgress = NULL);


	//! \brief 		创建缓冲区-将缓冲线进行打断
	static UGbool BreakLines(UGLineSeg * &pLineSegs,UGint & nLineSegCount,UGProgress * pProgress = NULL);

	//! \brief 		去除非法线
	static UGbool ClearLineSegs(const UGPoint2D* pPoints, const UGint *pPolyCounts, UGint lSubCount,
		UGLineSeg * pLineSegs,UGint nLineSegCount,
		UGLineSegEx * &pResLineSegs,UGint &nResLineSegCount,
		UGint nSideType = UGFULL,UGint nEndType =UGROUND,UGdouble *pRadius=NULL,UGProgress * pProgress = NULL);

	//! \brief 		创建缓冲区-创建面
	static UGbool BuildRegion(UGLineSegEx * pLineSegs,UGint nLineSegCount,UGGeoRegion & buffer,
		UGPoint2Ds &pntInRgns,UGbool bNotCounterClockwise=FALSE,UGProgress * pProgress = NULL);

	//! \brief 		创建缓冲区-对单对象创建平行线(转角圆弧)
	static UGbool OutSingleLine(const UGPoint2D* pPoints, const UGint lCount,UGLineSeg * pLineSegs,UGint &nLineSegCount,UGbool bRight=true);

	//! \brief 		创建缓冲区-生成开始或者结束的半圆弧
	static UGint MakeSemicircle(const UGPoint2D& pntFrom,const UGPoint2D& pntTo,UGLineSeg * pLineSegs,UGint nSideType = UGFULL);

	//! \brief 		查找范围内的索引
	static UGbool FindIndex(UGLineSegPnt * pPnts,UGint nPntCount,UGdouble dMinX,UGdouble dMaxX,UGint &nFrom,UGint &nTo);

	//! \brief 		线段相交
	static UGbool LinesIntersect(UGLineSeg *pLineSeg1,UGLineSeg *pLineSeg2);

	//! \brief 		线段与圆弧相交
	static UGbool LineArcIntersect(UGLineSeg *pLsarc,UGLineSeg *pLsline);

	//! \brief 		圆弧与圆弧相交
	static UGbool ArcsIntersect(UGLineSeg *pArc1,UGLineSeg *pArc2);

	//! \brief 		创建邻接矩阵
	static UGbool BuildAdjMatrix(UGLineSegEx * pLineSegs,UGint nLineSegCount,UGLineSegAdjMatrix * &pLineAdjMatrix
		,UGProgress * pProgress = NULL);

	//! \brief	二分查找某点
	static UGbool FindNextLine(UGLineSegAdjMatrix * pLineAdjMatrix,UGint nFromIndex,
								UGint nToIndex,UGint&NextToIndex,UGPoint2D* &pCurrentCirle);

	//! \brief	弧段转为线段
	static UGbool ArcToLines(UGLineSegEx * pLineSegs,UGint nLineSegCount,UGGeoLine * pGeoline);
	
	//! \brief	夹角是否大于 PI(由此判断凹、凸)
	//! \remark  1	小于PI,凹;0,等于PI,直;-1,大于PI,凸
	//!			 pntStart-pntMid 绕 pntMid 逆时针旋转，到达	pntMid-	pntEnd的角度		
	static UGint  AngleOverPI(const UGPoint2D &pntStart,const UGPoint2D &pntMid,const UGPoint2D &pntEnd);

	//! \brief	二分查找某点
	static UGint FindIndexByPnt(const UGPoint2D &pnt,UGLineSegAdjMatrix * pLineAdjMatrix);
	
	//! \brief	从邻接矩阵中移除某线段
	static UGbool RemoveLineseg(UGLineSegAdjMatrix * pLineAdjMatrix,UGint nFromIndex,UGint nToNodeIndex);

	//! \brief 获得正确的面之间岛洞关系
	//!			保证复杂对象岛(顺时针)、洞(逆时针)多边形坐标顺序按顺、逆时针排序
	static UGbool GetOrdinalRegion(UGGeoRegion &geoRegion);

	//! \brief 对点进行排序
	static UGbool SortPnt(const UGPoint2D &pntFrom,const UGPoint2D &pntTo,UGPoint2Ds & ArrPnts);

	//! \brief 保存所有的线段
	static UGbool SaveOutLine(UGDataset * pTestDataset,UGGeoLine * pgeoOutline);

	//! \brief 获得弧段的切向与正东方向的角度(**度，逆时针夹角)
	static UGdouble GetArcAngle(const UGPoint2D&pntFrom,const UGPoint2D&pntTo,
		const UGPoint2D&pntCircle,UGbool bIn = TRUE);

	//! \brief 获取点串
	static UGbool MatrixToLine(UGLineSegAdjMatrix * pLineAdjMatrix,	UGArray<UGint>&nArrNodeIndex,
							UGArray<UGPoint2D*>&pArrPntCentral,UGPoint2Ds& ResLinePoints);
	
private:

	// 静态缓冲区的半径
	static UGdouble m_dBufferRadiusEx ;

	static UGdouble m_dBufferRadiusExAbs ;

	// 静态缓冲区的半径的平方
	static UGdouble m_dBufferRadius2Ex ;	
	
	//弧的线段数, 即精度
	static UGint m_nSemicircleSegmentsEx;

	// 静态缓冲区的半径
	static UGdouble m_dTolerance ;

//}}==================================================
public:

	UGBuffer(UGdouble dBufferRadius, UGint nSemicircleSegments=12);
	UGBuffer();
	virtual ~UGBuffer();

	static void SetParam(UGdouble dBufferRadius, UGint nSemicircleSegments=12);

	//! \brief 	    圆角BUFFER
	//! \return 	BOOL
	//! \param 		pPoints
	//! \param 		lCount
	//! \param 		buffer
	static UGbool CreateBuffer(UGPoint2D* pPoints,UGint lCount,UGGeoRegion& buffer);


	//! \brief 		直角BUFFER
	//! \return 	BOOL
	//! \param 		*pPoints
	//! \param 		nCount
	//! \param 		dLeft	左边距
	//! \param 		dRight  右边距
	//! \param 		&bufferRegion
	//! \param 		iFlag
	//! \remark		iFlag=1 创建左边
	//!				iFlag=2 创建右边
	//!				iFlag=3（默认）全创建
	static UGbool CreateBuffer(UGPoint2D *pPoints, UGint nCount, UGdouble dLeft,UGdouble dRight,
						UGGeoRegion &bufferRegion, UGint iFlag=3);

	//! \brief		圆头BUFFER
	static UGbool CreateBuffer(UGGeometry *pGeometry,UGGeoRegion &bufferRegion);

	//! \brief		直角BUFFER
	static UGbool CreateBuffer(UGGeometry *pGeometry,UGGeoRegion &bufferRegion,UGdouble dLeft,UGdouble dRight,UGint iFlag=3);

	//! \brief		数据集的BUFFER
	static UGbool CreateBuffer(UGDataset *pDataset,UGDataset *pResDataset,UGbool bIsUnion = TRUE);

	//! \brief	数据集非对称BUFFER
	static UGbool CreateBuffer(UGDataset *pDataset,UGDataset *pResDataset,UGdouble dLeft,UGdouble dRight,UGint iFlag=3,UGbool bIsUnion = TRUE);
private:
	static void Init();
	static void Outline(const UGPoint2D& pntStart,const UGPoint2D& pntEnd, UGGeoRegion*& pSkewRect);
	static void MakeSemicircle(const UGPoint2D& point,UGdouble dx,UGdouble dy,UGbool bUp,UGPoint2D* pPoints);
	static inline UGdouble CosAdd(UGdouble doSin,UGdouble dSin,UGdouble doCos,UGdouble dCos);
	static inline UGdouble SinAdd(UGdouble doSin,UGdouble dSin,UGdouble doCos,UGdouble dCos);
	static void MakeCircle(UGPoint2D *pPoints,UGint nSemicircleSegments);

private:
	static UGbool Buffer(UGint nStartPointID,UGint nEndPointID,UGPoint2D* pLeftPoints,
					UGPoint2D* pRightPoints,UGGeoRegion &RegionResult);

private:

	//半径和半径的平方
	static UGdouble m_dBufferRadius;
	static UGdouble m_dBufferRadius2;
	//弧的线段数, 即精度
	static UGint m_nSemicircleSegments;
	static UGPoint2D *m_pCirclePoints;
};

}

#endif // !defined(UGBUFFER_H)
