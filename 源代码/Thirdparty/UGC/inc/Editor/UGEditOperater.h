// UGEditOperater.h: interface for the UGEditOperater class.
//
//=====================================================================================
// 项目名：			SuperMap Universal GIS class (UGC) Library 2.0
// 作  者：			宋关福
// 单  位：			北京超图地理信息技术有限公司
// 最后修改时间：	以文件日期为准
//-------------------------------------------------------------------------------------
// 重要声明：		1. 类库使用范围为Supermap GIS软件开发组成员，未经许可不得擅自传播。
//					2. 类库使用者不得修改本文件内容，否则会导致类库使用错误。
//					
//-------------------------------------------------------------------------------------
// 文件名：			UGEditOperater.h	
// 类  名：			UGEditOperater
// 父  类：			
// 子  类：			
// 功能说明：		用于坐标计算
// 调用说明：		
//=====================================================================================
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGEDITOPERATER_H__552A08DF_A1F7_4B0A_8EAE_3D35571F3FEE__INCLUDED_)
#define AFX_UGEDITOPERATER_H__552A08DF_A1F7_4B0A_8EAE_3D35571F3FEE__INCLUDED_

#include "Base/ugexports.h"
#include "Base/UGString.h"
#include "Base/UGVariant.h"
#include "Base/UGList.h"
#include "Base/UGArray.h"
#include "Algorithm/UGRect2D.h"
#include "Project/UGPrjCoordSys.h"
#include "Geometry/UGGeoCompound.h"
//#include "Editor/UGEditToolPack.h"

namespace UGC {

class EDITOR_API UGEditOperater
{

public:
	UGEditOperater();
	virtual ~UGEditOperater();
public:
	// 计算面积
	UGdouble CalculateArea(UGPoint2D *pPoints, UGlong nCount);

	// 计算距离
	UGdouble CalculateDistance(UGPoint2D *pPoints, UGlong nCount, UGbool bIsBL = FALSE);

	// 拆分复合对象 
	UGbool SplitGeoCompound(UGGeoCompound *pGeoCompound,UGList<UGGeometry*> *pGeoPtrList);
	//计算经纬度面积
	UGdouble CalculateAreaBL(UGPrjCoordSys &PJCoordSys,UGPoint2D *pPoints,UGlong nCount);
    // about the tolerance of IsZero() function used
	//获得捕捉的容限
    UGdouble GetSnapTolerance();

	//设置捕捉容限
    UGdouble SetSnapTolerance( const UGdouble& dTolerance );
    
    // when you want to get 
	//得到uType中1的个数，获得允许几种捕捉方式
	//uType:捕捉方式允许标志
	//nFlagLength:捕捉标记长度
    UGint  GetFlagCount( UGuint uType, UGint nFlagLength );
    
    ///////////////////////////////////////////////////////////////////////
    // base useful function
	//判断dValue是否在容限之内
    UGbool IsZero( UGdouble dValue );

	//判断dValeu是否在dZone限定的区域内
    UGbool IsInZone( UGdouble dValue, UGdouble dZone );
    
    // useful rotate point, relative to the pnt( 0,0 )
	//计算点(x,y),以(0，0)为圆心，旋转dAngle后的坐标
    void RotatePoint( UGdouble& x, UGdouble& y, const UGdouble& dAngle );
	
	//计算点(x,y),以(0，0)为圆心，旋转dAngle后的坐标
	//dCosAngle:dAngle的余旋值
	//dSinAngle:dAngle的正旋值
    void RotatePoint( UGdouble& x, UGdouble& y, const UGdouble& dCosAngle, const UGdouble& dSinAngle );

	//计算点pnt,以(0，0)为圆心，旋转dAngle后的坐标
    void RotatePoint( UGPoint2D& pnt, const UGdouble& dAngle );

	//计算点pnt,以(0，0)为圆心，旋转dAngle后的坐标
	//dCosAngle:dAngle的余旋值
	//dSinAngle:dAngle的正旋值
    void RotatePoint( UGPoint2D& pnt, const UGdouble& dCosAngle, const UGdouble& dSinAngle );
    // useful rotate point, relative to the pntOrg
	
	//计算点(x,y),以点(xOrg，yOrg)为圆心，旋转dAngle后的坐标
	void RotatePoint( UGdouble& x, UGdouble& y, const UGdouble& xOrg, const UGdouble& yOrg, const UGdouble& dAngle );
	
	//计算点(x,y),以点(xOrg，yOrg)为圆心，旋转dAngle后的坐标
	//dCosAngle:dAngle的余旋值
	//dSinAngle:dAngle的正旋值
    void RotatePoint( UGdouble& x, UGdouble& y, const UGdouble& xOrg, const UGdouble& yOrg, const UGdouble& dCosAngle, const UGdouble& dSinAngle );

	//计算点pontNew,以点(xOrg，yOrg)为圆心，旋转dAngle后的坐标
	void RotatePoint( UGPoint2D& pntNew, const UGPoint2D& pntOrg, const UGdouble& dAngle );
	
	//计算点pontNew,以点(xOrg，yOrg)为圆心，旋转dAngle后的坐标
	//dCosAngle:dAngle的余旋值
	//dSinAngle:dAngle的正旋值
    void RotatePoint( UGPoint2D& pntNew, const UGPoint2D& pntOrg, const UGdouble& dCosAngle, const UGdouble& dSinAngle );

    // get distance from point1 to point2
	//两点间距离
	UGdouble LineSectDistance(const UGPoint2D& pnt1, const UGPoint2D& pnt2 );
    UGdouble LineSectDistance(const UGdouble& x1, const UGdouble& y1, const UGdouble& x2, const UGdouble& y2 );

    // get angle from point2 to point1
    UGdouble LineSectAngle(const UGPoint2D& pnt1, const UGPoint2D& pnt2 );
    UGdouble LineSectAngle(const UGdouble& x1, const UGdouble& y1, const UGdouble& x2, const UGdouble& y2 );
    
    // judge the point on line
    UGbool IsPntOnLineSect(const UGdouble& x1, const UGdouble& y1, const UGdouble& x2, const UGdouble& y2, const UGdouble& x, const UGdouble& y);
    UGbool IsPntOnLine(const UGdouble& x1, const UGdouble& y1, const UGdouble& x2, const UGdouble& y2, const UGdouble& x, const UGdouble& y);
    UGbool IsPntNearLineSect(const UGdouble& x1, const UGdouble& y1, const UGdouble& x2, const UGdouble& y2, const UGdouble& x, const UGdouble& y, const UGdouble dZone );
    UGbool IsPntNearLine(const UGdouble& x1, const UGdouble& y1, const UGdouble& x2, const UGdouble& y2, const UGdouble& x, const UGdouble& y, const UGdouble dZone );
    
    // judge the point in polygon ( I don't know in or out when point on polygon's line
    UGbool IsInsidePolygon( const UGPoint2D* pPoints, const UGint nCount, const UGPoint2D pnt );
    
    // the two line is the same line
	//判断两条线段是否相同
	UGbool IS_Same_Line( const UGPoint2D& pntStart1, const UGPoint2D& pntEnd1, const UGPoint2D& pntStart2, const UGPoint2D& pntEnd2 );
    UGbool ISSameLine( const UGPoint2D& pntStart1, const UGPoint2D& pntEnd1, const UGPoint2D& pntStart2, const UGPoint2D& pntEnd2 );
    UGbool ISNearSameLine( const UGPoint2D& pntStart1, const UGPoint2D& pntEnd1, const UGPoint2D& pntStart2, const UGPoint2D& pntEnd2, const UGdouble& dZone );
    UGbool MakeSameLine( const UGPoint2D& pntStart1, const UGPoint2D& pntEnd1, const UGPoint2D& pntStart2, UGPoint2D& pntEnd2, const UGdouble& dZone );
    
    // the two line is the Parallel line
    UGbool IS_Parallel_Line( const UGPoint2D& pntStart1, const UGPoint2D& pntEnd1, const UGPoint2D& pntStart2, const UGPoint2D& pntEnd2 );
    UGbool ISParallelLine( const UGPoint2D& pntStart1, const UGPoint2D& pntEnd1, const UGPoint2D& pntStart2, const UGPoint2D& pntEnd2 );
    UGbool ISNearParallelLine( const UGPoint2D& pntStart1, const UGPoint2D& pntEnd1, const UGPoint2D& pntStart2, const UGPoint2D& pntEnd2, const UGdouble& dZone );
    UGbool MakeParallelLine( const UGPoint2D& pntStart1, const UGPoint2D& pntEnd1, const UGPoint2D& pntStart2, UGPoint2D& pntEnd2, const UGdouble& dZone );
    
    // the two line is the Vertical line
    UGbool ISVerticalLine( const UGPoint2D& pntStart1, const UGPoint2D& pntEnd1, const UGPoint2D& pntStart2, const UGPoint2D& pntEnd2 );
    UGbool ISNearVerticalLine( const UGPoint2D& pntStart1, const UGPoint2D& pntEnd1, const UGPoint2D& pntStart2, const UGPoint2D& pntEnd2, const UGdouble& dZone );
    UGbool MakeVerticalLine( const UGPoint2D& pntStart1, const UGPoint2D& pntEnd1, const UGPoint2D& pntStart2, UGPoint2D& pntEnd2, const UGdouble& dZone );
    
    // the three point near the angle
    // please make sure the angle is large than 0 and small than 180
    UGbool ISFixAngle( const UGPoint2D& pnt1, const UGPoint2D& pnt2, const UGPoint2D& pnt3, const UGdouble& dAngle );
    UGbool ISNearFixAngle( const UGPoint2D& pnt1, const UGPoint2D& pnt2, const UGPoint2D& pnt3, const UGdouble& dAngle, const UGdouble& dZone );
    UGbool MakeFixAngle( const UGPoint2D& pnt1, const UGPoint2D& pnt2, UGPoint2D& pnt3, const UGdouble& dAngle, const UGdouble& dZone );
    
    // the two point near to the Length
    UGbool ISFixLength( const UGPoint2D& pnt1, const UGPoint2D& pnt2, const UGdouble& dLength );
    UGbool ISNearFixLength( const UGPoint2D& pnt1, const UGPoint2D& pnt2, const UGdouble& dLength, const UGdouble& dZone );
    UGbool MakeFixLength( const UGPoint2D& pnt1, UGPoint2D& pnt2, const UGdouble& dLength, const UGdouble& dZone );
    
    // line's sect, when the line on one line return is TRUE
    UGbool IntersectLine(const UGPoint2D& pntStart1, const UGPoint2D& pntEnd1, const UGPoint2D& pntStart2, const UGPoint2D& pntEnd2, UGPoint2D& pntResult );
    
    // linesect's sect ( supply by WangHong )
    UGbool Line_Cross(const UGdouble& x3, const UGdouble& y3, const UGdouble& x4, const UGdouble& y4, const UGdouble& x1, const UGdouble& y1, const UGdouble& x2, const UGdouble& y2, UGdouble &dCrossx, UGdouble &dCrossy);
    
    //计算点pntHitTest在线段(pntLinsectStart, pntLinsectEnd)或者其延长线上的垂足点(resultPoint)
    //返回值:	TRUE -- 垂足在线段内
    //			FALSE -- 垂足在线段外(延长线上)
    // supply by Watson ( don't use this )
    UGbool PointProjectToLinesetWa( const UGPoint2D& pntHitTest, const UGPoint2D&  pntLinsectStart, const UGPoint2D& pntLinsectEnd, UGPoint2D& resultPoint );
    // supply by Chen Junhua ( don't use this )
    UGbool PointProjectToLinesetCh( const UGPoint2D& pntHitTest, const UGPoint2D&  pntLinsectStart, const UGPoint2D& pntLinsectEnd, UGPoint2D& resultPoint );
    // judge by rotate
    UGbool PointProjectToLinesetRo( const UGPoint2D& pntHitTest, const UGPoint2D&  pntLinsectStart, const UGPoint2D& pntLinsectEnd, UGPoint2D& resultPoint );
    // for line
    void PointProjectToLinesetRn( const UGPoint2D& pntHitTest, const UGPoint2D&  pntLinsectStart, const UGPoint2D& pntLinsectEnd, UGPoint2D& resultPoint );

	// 使这两个点能组成正方形，根据情况改变第二个点的x或y坐标
	void MakeSquare( const UGPoint2D& pnt2DOrg, UGPoint2D& pnt2DNew );

	

protected:
    // attribute
    UGdouble              m_dSnapTolerance;

};

}

#endif // !defined(AFX_UGEDITOPERATER_H__552A08DF_A1F7_4B0A_8EAE_3D35571F3FEE__INCLUDED_)
