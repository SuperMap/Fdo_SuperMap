/*! \file	 UGOpPoints.h
 *  \brief	 点 以及 点点之间的空间运算
 *  \author	 ugc team
 *  \attention 
 *  Copyright(c) 1996-2004 SuperMap GIS Technologies,Inc.<br>
 *  All Rights Reserved
 *  \version $Id: UGOpPoints.h,v 1.16 2007/10/08 07:54:29 guohui Exp $
 */


#ifndef UGOPPOINTS_H
#define UGOPPOINTS_H

#include "Base/ugdefs.h"
#include "Algorithm/UGPoint2D.h"
#include "Algorithm/UGRect2D.h"
#if PACKAGE_TYPE==PACKAGE_UGC
#include "Base/UGList.h"
#endif // end declare ugc API

namespace UGC {

//! \brief 点 以及 点点之间的空间运算
//! \remarks 术语定义: 角度 Angle; 弧度 Radian
class ALGORITHM_API UGOpPoints  
{
private:
	UGOpPoints();

public: // 旋转

	//! \brief 给出角度计算点旋转(逆时针方向)
	static void RotateAngle(const UGPoint2D& pntAnchor, UGdouble dAngle, 
							UGPoint2D& pntSource);

	//! \brief 给出角度批量计算点旋转(逆时针方向)
	static void RotateAngle(const UGPoint2D& pntAnchor, UGdouble dAngle, 
							UGPoint2D* pPoints, UGint nPntCount);

	//! \brief 给出弧度计算点旋转(逆时针方向)
	static void RotateRadian(const UGPoint2D& pntAnchor, UGdouble dRadian, 
							 UGPoint2D& pntSource);

	//! \brief 给出弧度批量计算点旋转(逆时针方向)
	static void RotateRadian(const UGPoint2D& pntAnchor, UGdouble dRadian, 
							 UGPoint2D* pPoints, UGint nPntCount);

	//! \brief 给出参数(cos,sin)计算点旋转(逆时针方向)
	static void Rotate(const UGPoint2D& pntAnchor, UGdouble dCos, UGdouble dSin, 
						UGPoint2D& pntSource);

	//! \brief 给出参数(cos,sin)批量计算点旋转(逆时针方向)
	static void Rotate(const UGPoint2D& pntAnchor, UGdouble dCos, UGdouble dSin, 
					   UGPoint2D* pPoints, UGint nPntCount);


public: // 计算角度

	//! \brief 计算两点的方位角(角度)
	//! \remarks 方位角: 从某点的指北方向线起，依顺时针方向到目标方向线之间的水平夹角
	static UGdouble Azimuth(const UGPoint2D& pntFrom, const UGPoint2D& pntTo);


	//! \brief 计算两点的角度(和正东方向的逆时针夹角)
	//! \brief 以正东方向为起始射线，逆时针旋转，到pntFrom-pntTo的角度
	static UGdouble Angle(const UGPoint2D& pntFrom, const UGPoint2D& pntTo);

	//! \brief 计算两点的弧度(和正东方向的逆时针夹角)
	static UGdouble Radian(const UGPoint2D& pntFrom, const UGPoint2D& pntTo);


public: // 计算距离

	//! \brief 平面两点间的距离的平方
	static UGdouble DistanceSquare(const UGPoint2D& pnt1, const UGPoint2D& pnt2);

	//! \brief 平面两点间的距离
	static UGdouble Distance(const UGPoint2D& pnt1, const UGPoint2D& pnt2);

	//! \brief 球面两点间的距离.pnt1 和 pnt2所在大圆弧
	//! \remarks sphere n. 球, 球形, 球体, 球面; 地球半径默认是以米为单位,可以更改
	//! \param pnt1 坐标值必须都是经纬坐标
	//! \param pnt2 坐标值必须都是经纬坐标
	//! \return	返回值和地球半径单位一致
	static UGdouble SphereDistance(const UGPoint2D& pnt1, const UGPoint2D& pnt2, 
									UGdouble dRadius=6371118);

	// zengzm: 这个函数的精确定义,还是有待用到时再处理吧 
	//! \brief 椭球体上两点间的距离
	//! \remarks ellipsoid n.椭圆体
	//! \param dPrimeAxis 长轴
	//! \param dFlattening 扁率
	//static UGdouble EllipsoidDistance(const UGPoint2D& pnt1, const UGPoint2D& pnt2, 
	//								UGdouble dPrimeAxis, UGdouble dFlattening);
	
public: // 计算Bounds

	//! \brief 计算Bounds
	static UGRect2D Bounds(const UGPoint2D& pnt1, const UGPoint2D& pnt2);

	//! \brief 计算Bounds
	static UGRect2D Bounds(const UGPoint2D* pPoints, UGint nPntCount);

	//! \brief 计算Bounds
	static UGRect2D Bounds(const UGPoint2D* pPoints, const UGint* pPolyCounts, UGint nSubCount);
	
public: // 去除	重复点

	//! \brief 去除重复点
	//! \param pntResults 传入时必须为空集
	static void CleanRepeat(const UGPoint2D* pPoints, UGint nPntCount, UGPoint2Ds& pntResults);

public:
	// add by guohui 2007.10.08
	//! \brief 查找相同点
	static UGbool GetSamePnts(const UGPoint2D* pPoints1, const UGint* pPolyCount1,UGint nSubCount1,
							const UGPoint2D* pPoints2, const UGint* pPolyCount2,UGint nSubCount2,
							UGPoint2Ds& pntResult);

#if PACKAGE_TYPE==PACKAGE_UGC
public: // 计算凸包

	//! \brief 计算点串的凸包
	//! \param pPoints 传入的点
	//! \param nPntCount 点个数 点个数必须大于等于2
	//! \param pntResult 返回的首点和末点相同
	static void Flange(const UGPoint2D* pPoints, UGint nPntCount, UGPoint2Ds& pntResult);
	
	//! \brief 两点镜像 多个点
	//! \param pPointDes 外部必须分配好内存
	static UGbool Mirror(UGPoint2D *pPointSrc, UGint nPointCount, UGPoint2D *pPointDes,
						  const UGPoint2D &pntMirror1, const UGPoint2D &pntMirror2);
	
	//! \brief 两点镜像 一个点。
	//! \param pntSrc [in] 原始点。
	//! \param pntDes [out] 镜像后的点。
	//! \param pntMirror1 [in] 构成镜面的第一个点。
	//! \param pntMirror2 [in] 构成镜面的第二个点。
	//! \return 如果构成镜面的点重合,返回false。
	static UGbool Mirror(const UGPoint2D& pntSrc, UGPoint2D& pntDes,
						  const UGPoint2D &pntMirror1, const UGPoint2D &pntMirror2);
	
	//! \brief 两点镜像 角度。
	//! \param dAngleSrc [in] 原始角度。
	//! \param dAngleDes [out] 镜像后的角度。
	//! \param pntMirror1 [in] 构成镜面的第一个点。
	//! \param pntMirror2 [in] 构成镜面的第二个点。
	//! \return 如果构成镜面的点重合,返回false。
	static UGbool Mirror(UGdouble dAngleSrc, UGdouble& dAngleDes, 
						const UGPoint2D &pntMirror1, const UGPoint2D &pntMirror2);	

public: // 计算点的紧缩多边形
	
	// by guohui 2007.09.19 这个方法还不成熟，注释掉，外部也没有使用。
	//! \brief 计算点的紧缩多边形
	//! \param pnt2sSource [in]  传入的点。
	//! \param pnt2sRezult [out] 结果点。
	//! \return 传入点的非重复点个数必须大于2返回False.所有点均在一条直线上返回false
	//static UGbool ImpactRegion(const UGPoint2D* pnt2sSource, UGint nPntCount, UGPoint2Ds& pnt2sRezult);

private:
	// by guohui 2007.09.19 这里的方法已经不再使用了
//	// 在求凸包中需要用到的几个函数
//	static void UpLeft(const UGPoint2D* pPoints, UGint nPntCount, UGList<int> &transmitted);
//	static void DownLeft(const UGPoint2D* pPoints, UGint nPntCount, UGList<int> &transmitted);
//	static void DownRight(const UGPoint2D* pPoints, UGint nPntCount, UGList<int> &transmitted);
//	static void UpRight(const UGPoint2D* pPoints, UGint nPntCount, UGList<int> &transmitted);
//	static UGbool Concavity(const UGPoint2D& pnta, const UGPoint2D& pntb, const UGPoint2D& pntc);
#endif // end declare ugc API
};

}

#endif
