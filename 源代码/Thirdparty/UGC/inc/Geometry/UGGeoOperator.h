//! \file UGGeoOperator.h
//! \brief 基于Geometry的空间运算
//! \remarks本类中: 返回的Geometry指针pGeoResult为引用传入，如果pGeoResult初始值不为空，
//!			则直接使用pGeoResult指针，如果传入指针pGeoResult是非法指针，后果由调用者自己负责；
//!			如果pGeoResult初始值为空，pGeoResult在函数内部分配空间，调用者需要自己负责释放！
//!			如果返回失败，则pGeoResult不做任何变动；


#ifndef UGGEOOPERATOR_H
#define UGGEOOPERATOR_H

#include "Algorithm/UGRect2D.h"
#include "UGGeometry.h"

namespace UGC {


class GEOMETRY_API UGGeoOperator  
{
private:
	UGGeoOperator();

public: // Geometry 之间的布尔运算

	//! \brief 求并
	//! \param pGeometry1 参加操作的几何对象指针, 不得为NULL
	//! \param pGeometry2 参加操作的几何对象指针, 不得为NULL
	//! \param pGeoResult 结果几何对象; 如果传入时为NULL或者不符合结果几何对象类型要求, 会重新生成结果几何对象
	//! \remarks 两个Geometry的维度必须一样
	//! \attention 仅支持二维对象的并；其他维度的并无意义
	//! \return 如果两个Geometry的维度不相等，返回NULL
	static UGbool Union(const UGGeometry* pGeometry1, const UGGeometry* pGeometry2, UGGeometry*& pGeoResult);

	//! \brief 求交
	//! \param pGeometry1 参加操作的几何对象指针, 不得为NULL
	//! \param pGeometry2 参加操作的几何对象指针, 不得为NULL
	//! \param pGeoResult 结果几何对象; 如果传入时为NULL或者不符合结果几何对象类型要求, 会重新生成结果几何对象
	//! \attention        点面、点线、线线、线面、面面之间求交；点点之间求相同点;
	//!				      结果规则：	点面 = 点(GeoPoint) ; 点线 = 点(GeoPoint)
	//!						     		线线 = 点(GeoMultiPoint) ; 线面 = 线 ; 面面 = 面
	//! \return   
	static UGbool Intersect(const UGGeometry* pGeometry1, const UGGeometry* pGeometry2, UGGeometry*& pGeoResult);

	//! \brief 差(也就是 Erase 操作 )
	//! \remarks 用pGeoClip去裁减pGeoSubject，得到pGeoSubject不在pGeoClip中的部分
	//!			结果为 pGeoSubject - pGeoClip
	//!			pGeoClip的维度>=pGeoSubject的维度，结果Geometry的维度等于pGeoSubject的维度
	//! \return 如果结果为空，返回NULL
	static UGbool Difference(const UGGeometry* pGeoSubject, const UGGeometry* pGeoClip, UGGeometry*& pGeoResult);

	//! \brief 异或
	//! \remarks 异或＝＝并－交
	//!			两个Geometry的维度必须一样(一维之间异或还没有实现)
	//! \return 如果两个Geometry的维度不一样，或者结果为空，返回NULL
	static UGbool Xor(const UGGeometry* pGeometry1, const UGGeometry* pGeometry2, UGGeometry*& pGeoResult);

	//! \brief		更新((A-B)并B). 保留 pGeometry1 与 pGeometry2 相交的部分 以及 pGeometry2 。空间形状发生变化
	//! \remarks	必须是面与面之间的空间操作
	static UGbool Update(const UGGeometry* pGeometry1, const UGGeometry* pGeometry2, UGGeometry*& pGeoResult);
	
	//! \brief 同一运算((A交B)并(A减B))。其空间形状不变
	//! \return pGeoResult 前部分为 pGeometry2 外的对象(未被同一)；后部分为 pGeometry2 内的对象(被同一)
	//! \remarks pGeometry1 可以为点、线、面;pGeometry2只能为面
	static UGbool Identity(const UGGeometry* pGeometry1, const UGGeometry* pGeometry2, UGGeometry*& pGeoResult);

public: // 计算两个Geometry之间的距离
	
	//! \brief 计算两个Geometry之间的距离
	//! \remarks 距离的定义：在pGeometry1和pGeometry2中分别存在两点pnt1和pnt2，使得distance(pnt1,pnt2)
	//!			 达到最小
	static UGdouble Distance(const UGGeometry* pGeometry1, const UGGeometry* pGeometry2);

	//! \brief 计算两个Geometry之间的最大距离
	//! \remarks 最大距离的定义：在pGeometry1和pGeometry2中分别存在两点pnt1和pnt2，使得distance(pnt1,pnt2)
	//!			 达到最大。
	static UGdouble MaxDistance(const UGGeometry* pGeometry1, const UGGeometry* pGeometry2);

public: // 裁减Geometry
	
	//! \brief 矩形裁减
	//! \param bInside=true, 返回在Rect内的部分; bInside=false, 返回在Rect外的部分
	//! \return 如果结果为空,返回NULL
	static UGbool Clip(const UGGeometry* pGeometry, const UGRect2D& rectClip, UGGeometry*& pGeoResult, UGbool bInside=TRUE);

	//! \brief 裁减
	//! \param pGeoSource 参加操作的几何对象指针, 不得为NULL
	//! \param pGeoClip   参加操作的几何对象指针, 不得为NULL
	//! \param pGeoResult 结果几何对象; 如果传入时为NULL或者不符合结果几何对象类型要求, 会重新生成结果几何对象
	//! \attention        点面、点线、线线、线面、面面之间求交；点点之间求相同点;
	//!				      结果规则：	点面 = 点(GeoPoint) ; 点线 = 点(GeoPoint)
	//!						     		线线 = 点(GeoMultiPoint) ; 线面 = 线 ; 面面 = 面
	//! \return 如果结果为空,返回NULL
	static UGbool Clip(const UGGeometry* pGeoSource, const UGGeometry* pGeoClip, UGGeometry*& pGeoResult);
	
	//! \brief 矩形裁剪面，并返回两者的相互空间位置关系
	//! \param RegionSource		被裁剪多边形 
	//! \param RectClipper		裁剪矩形
	//! \param RegionResult		裁剪后结果多边形
	//! \param dInterval		判断结点相等的容限
	//! \return 
	//! 0-------相离
	//! 1-------相交
	//! 2-------矩形包含多边形
	//! 3-------多边形包含矩形
	static UGint IsIntersectRegionWithRect(UGGeometry* pRegionSource,UGRect2D &RectClipper,UGGeoRegion &RegionResult, 
											UGdouble dInterval=EP);
public: // 重采样

	//! \brief 距离重采样
	//! \return 返回的Geometry的维度和输入Geometry的维度一致
	//! \remark 只支持1维、2维对象
	static UGbool Resample(const UGGeometry* pGeoSource, UGGeometry*& pGeoResult, UGdouble dTolerance);

	//! \brief 分割,pGeoSource被pGeoSplit所分割
	//! \remarks pGeoSplit只能是0维或者1维对象; 
	//!			pGeoSource的维度=pGeoSplit的维度, 或者pGeoSource的维度=pGeoSplit的维度+1
	//!         支持 点分割线、线分割线、线分割面
	static UGbool Split(const UGGeometry* pGeoSource, const UGGeometry* pGeoSplit, 
						UGGeometry* &pGeoResult1, UGGeometry* &pGeoResult2);
	
	//! \brief 消融, 消除两个 Geometry 重叠的部分,形成一个对象
	//! \remarks 两个Geometry必须有重叠部分,且维度必须一样
	//static UGGeometry* Dissolve(const UGGeometry* pGeometry1, const UGGeometry* pGeometry2);

	//! \brief 链接, 
	//! \remarks 两个Geometry的维度必须一样
	//!			两个Geometry必须首尾相连,不可有重叠
	//!			内部还没有实现
	static UGbool Link(const UGGeometry* pGeometry1, const UGGeometry* pGeometry2, UGGeometry*& pGeoResult);
	
	//! \brief 计算对象的弧度长度
	//! \return  返回对象的弧度长度
	//! \remarks 对象维度必须大于零维。1维：球上距离；2维：球上周长。pGeometry中坐标值为经纬坐标
	static UGdouble GetRadianDistance(UGGeometry* pGeometry, UGdouble dRadius/*, UGint nDistUnits*/);
	
	
	//! \brief 用点去打断 Geometry 
	//! \param pGeometry		被打断几何对象
	//! \param pntBomb			打断点
	//! \param pBreakLine		返回线
	//! \param dTolerance		容限(如果点到直线的距离大于容限，则不打断)
	//! \return 
	//! \remarks 只支持 Geometry 为 一维对象。          
	static UGbool Break(UGGeometry* pGeometry, UGPoint2D& pntBomb, UGArray<UGGeometry*>& pBreakLine, 
						UGdouble dTolerance);

	//! \brief 计算Geometry经过多少个网格
	//! \param *pGeometry [in] 参与计算的空间对象
	//! \param &pntCenter [in]。参照的中心点坐标
	//! \param &dGrid0 [in]。0级别网格宽度
	//! \param &dGrid1 [in]。1级别网格宽度
	//! \param &dGrid2 [in]。2级别网格宽度
	//! \param &aryMaybeGrid [out]。结果，对象经过的格子数组
	//! \param &aryGrid [out]。结果，被对象完全包含的格子数组
	//! \param dGridRatio [in]。网格长宽比默认为1；
	//! \return 。
	//! \remarks 。
	//! \attention 。
	static UGbool ComputeGrid(UGGeometry *pGeometry,UGPoint2D &pntCenter, UGdouble &dGrid0, UGdouble &dGrid1,
							UGdouble &dGrid2,UGArray<UGPoint> &aryMaybeGrid, UGArray<UGPoint> &aryGrid, 
							UGdouble dGridRatio=1);
};


}

#endif // !defined(AFX_UGGEOOPERATOR_H__38FEB7EF_6E68_49EA_9A5F_6E472FFF15D4__INCLUDED_)
