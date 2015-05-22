// UGGeoRelation.h: interface for the UGGeoRelation class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGGEORELATION_H__4BFF0D4D_CD98_4DF5_B7AD_ED2C116651AD__INCLUDED_)
#define AFX_UGGEORELATION_H__4BFF0D4D_CD98_4DF5_B7AD_ED2C116651AD__INCLUDED_

#include "Base/ugdefs.h"
#include "UGGeometry.h"

namespace UGC {

//! \brief 基于Geometry的空间关系判断算子
//! \remarks 查询对象 : Search ；目标对象： Target
//!			第一个参数为查询对象，第二个为目标对象
//!		类型	边框				边界				内部							外部
//!		点	点对象本身				点对象本身			点对象本身						点对象边界外的区域
//!		线	线对象的最小外接矩形	线对象控制边的并集	线对象的边界去除
//!														线对象的起始点和终止点的部分	线对象边界外的区域
//!		面	面对象的最小外接矩形	面对象控制边的并集	面对象边界围成的区域			面对象边界外的区域
class GEOMETRY_API UGGeoRelation  
{
private:
	UGGeoRelation();

public: // 基本算子
	
	//! \brief 判断是否边框相交
	//! \remarks 查询对象(A)的边框与目标对象(B)的边框相交空；A的边框和B的边框交集不为空；
	//!			查询对象: 点,线,面
	//!			目标对象: 点,线,面
	//!			(A边框 ∩ B边框) 
	static UGbool IsExtentIntersect(const UGGeometry *pGeoSearch, const UGGeometry*pGeoTarget);

	//! \brief 判断是否接触
	//! \remarks 查询对象(A)边界与目标对象(B)相切；A的边界与B边界交集不为空；
	//!			查询对象: 点,线,面
	//!			目标对象: 点,线,面
	//!			(A边界 ∩ B边界) 
	static UGbool IsTouch(const UGGeometry *pGeoSearch, const UGGeometry*pGeoTarget);

	//! \brief 判断是否穿越
	//! \remarks 查询对象(A)穿越目标对象(B)
	//!			线面：A的内部与B的内部的交集不为空；A的内部与B的外部的交集不为空；
	//!			线线；A从B内部的一侧进入并在B内部的某处另一侧穿出；
	//!			查询对象: 线
	//!			目标对象: 线,面
	//!			(A内部 ∩ B内部) && (A内部 ∩ B外部) 
	static UGbool IsCross(const UGGeometry *pGeoSearch, const UGGeometry*pGeoTarget);

	//! \brief 判断是否交叠
	//! \remarks 查询对象(A)与目标对象(B)交叠
	//!			1.A与B的维数相同；
	//!			2.A的内部与B的内部交集(C)不为空； 
	//!			3. C的类型仍与A的类型相同；
	//!			4. C不能等于(Identical)A;
	//!			5. C不能等于(Identical)B;
	//!			查询对象：线,面
	//!			目标对象：线,面
	//!			(A.D==B.D) && (A内部 ∩ B内部) && ((A内部 ∩ B内部).D==A.D) 
	//!			D：Dimension 维数
	static UGbool IsOverlap(const UGGeometry *pGeoSearch, const UGGeometry*pGeoTarget);

	//! \brief 判断是否包含
	//!			查询对象(A)完全包含目标对象(B)(A,B可以边界交集可以不为空)
	//!			1.A的外部与B的内部的交集为空;
	//!			2.A的维数>=B的维数;
	//!			查询对象: 点,线,面
	//!			目标对象: 点,线,面
	//!			(！(A外部 ∩ B内部)) 
	static UGbool IsContain(const UGGeometry *pGeoSearch, const UGGeometry*pGeoTarget);

	//! \brief 判断是否在其内
	//! \remarks Contains的逆算子
	//!			查询对象: 点,线,面
	//!			目标对象: 点,线,面
	//!			(！(A内部∩ B外部)) 
	static UGbool IsWithin(const UGGeometry *pGeoSearch, const UGGeometry*pGeoTarget);

	//! \brief 判断是否相离
	//! \remarks 查询对象(A)和目标对象(B)相离
	//!			查询对象: 点,线,面
	//!			目标对象: 点,线,面
	//!			(！(A边界 ∩ B边界)) && (！(A内部 ∩ B内部)) 
	static UGbool IsDisjoint(const UGGeometry *pGeoSearch, const UGGeometry*pGeoTarget);

	//! \brief 判断是否等同
	//! \remarks 查询对象和目标对象完全相等（点的顺序也必须一样，一般用于查询复制对象）
	//!			查询对象: 点,线,面
	//!			目标对象: 点,线,面
	//!			(A边框==B边框) && (A边界==B边界) && (A内部==B内部) 
	//!			*A---------*B------------*C------------*D	*A'---------*B'------------*C'
	//!			*E-----------------------*F------------*G	*E'---------*F'------------*G'
	//!          等同:ABCD与EFG不等同；A'B'C'与E'F'G'等同
	static UGbool IsIdentical(const UGGeometry *pGeoSearch, const UGGeometry*pGeoTarget);

public: // 实用 非组合算子（特殊算子）
	
	//! \brief 判断是否有共同节点（vertex）
	//! \remarks 查询对象和目标对象有公共控制点
	//!			查询对象：点,线,面
	//!			目标对象：点,线,面
	//!			*A---------*B------------*C------------*D
	//!			---*E--------------------*F--------------*G
	//!          共同结点: F和C为共同结点
	static UGbool IsCommonPoint(const UGGeometry *pGeoSearch, const UGGeometry*pGeoTarget);

	//! \brief 判断是否有共同线段
	//! \remarks 查询对象和目标对象有公共边(相邻两个结点均相同)
	//!			查询对象：线,面
	//!			目标对象：线,面
	//!			*A---------*B------------*C------------*D
	//!			*E-----------------------*F------------*G
	//!          共同线段: CD与FG为共同线段；ABC与EF不是共同线段；AB与EF不是共同线段。
	static UGbool IsCommonLine(const UGGeometry *pGeoSearch, const UGGeometry*pGeoTarget);

	//! \brief 判断是否有面积相交
	//! \remarks 查询对象和目标对象内部交集不为空; 查询对象和目标对象必须有一个为面对象
	//!			查询对象：点,线,面
	//!			目标对象：点,线,面
	static UGbool IsAreaIntersect(const UGGeometry *pGeoSearch, const UGGeometry*pGeoTarget);

	//! \brief 判断是否包含质心
	//! \remarks 查询对象包含目标对象的质心
	//!			查询对象：面
	//!			目标对象：面
	static UGbool IsCentroidInPolygon(const UGGeometry *pGeoSearch, const UGGeometry*pGeoTarget);

//	//! \brief 判断是否包含第一个点
//	//! \remarks 目标对象包含查询对象的第一个点
//	//!			查询对象：点,线,面
//	//!			目标对象：面
//	//!			暂不作为对外公开算子，仅供内部使用
//	static UGbool IsFirstPointInPolygon(const UGGeometry *pGeoSearch, const UGGeometry*pGeoTarget);

public: // 由基本算子 组合而成的 实用算子

	//! \brief 判断是否相切
	//! \remarks Touch&&(!Cross)&&(!Overlap)&&(!Contain)&&(!Within)
	static UGbool IsTangent(const UGGeometry *pGeoSearch, const UGGeometry*pGeoTarget);
	
	//! \brief 判断是否真包含
	//! \remarks Contain && (!Touch)
	static UGbool IsContainNoTouch(const UGGeometry *pGeoSearch, const UGGeometry*pGeoTarget);

	//! \brief 判断是否真被包含
	//! \remarks Within && (!Touch)
	static UGbool IsWithinNoTouch(const UGGeometry *pGeoSearch, const UGGeometry*pGeoTarget);

	//! \remarks Contain || Overlap
	static UGbool IsContainOrOverlap(const UGGeometry *pGeoSearch, const UGGeometry*pGeoTarget);

	//! \remarks Touch && (!Cross)
	static UGbool IsTouchNoCross(const UGGeometry *pGeoSearch, const UGGeometry*pGeoTarget);

public: // 由 基本算子和特殊算子 组合而成的 实用算子

	//! \brief 是否具有相同点或者穿越
	static UGbool IsCommonPointOrCross(const UGGeometry *pGeoSearch, const UGGeometry*pGeoTarget);

	//! \brief 是否面积相交并且不互相包含
	static UGbool IsAreaIntersectsNoContain(const UGGeometry *pGeoSearch, const UGGeometry*pGeoTarget);

	//! \brief 是否面积相交或者接触
	static UGbool IsAreaIntersectOrTouch(const UGGeometry *pGeoSearch, const UGGeometry*pGeoTarget);

	//! \brief 是否相同线或者重叠
	static UGbool IsCommonLineOrOverlap(const UGGeometry *pGeoSearch, const UGGeometry*pGeoTarget);

	//! \brief 是否相同线并且交叠
	static UGbool IsCommonLineAndOverlap(const UGGeometry *pGeoSearch, const UGGeometry*pGeoTarget);
	
private: // Geometry内部、外部、边界的关系判断

	//! \brief 内部与内部的关系
	static UGbool InteriorToInterior(const UGGeometry *pGeoSearch, const UGGeometry*pGeoTarget);

	//! \brief 内部与边界的关系
	static UGbool InteriorToBoundary(const UGGeometry *pGeoSearch, const UGGeometry *pGeoTarget);

	//! \brief 内部与外部的关系
	static UGbool InteriorToExterior(const UGGeometry *pGeoSearch, const UGGeometry *pGeoTarget);

	//! \brief 边界与内部的关系
	static UGbool BoundaryToInterior(const UGGeometry *pGeoSearch, const UGGeometry *pGeoTarget);

	//! \brief 边界与边界的关系
	static UGbool BoundaryToBoundary(const UGGeometry *pGeoSearch, const UGGeometry *pGeoTarget);

	//! \brief 边界与外部的关系
	static UGbool BoundaryToExterior(const UGGeometry *pGeoSearch, const UGGeometry *pGeoTarget);

	//! \brief 外部与内部的关系
	static UGbool ExteriorToInterior(const UGGeometry *pGeoSearch, const UGGeometry *pGeoTarget);

	//! \brief 外部与边界的关系
	static UGbool ExteriorToBoundary(const UGGeometry *pGeoSearch, const UGGeometry *pGeoTarget);
	
	//! \brief 线内部是否与线边界相交
	static UGbool IsLineIIntersectLineB(UGPoint2D *pSrcPoints,UGint nSrcPointCount,UGPoint2D *pTagPoints,
										UGint nTagPointCount);
	//! \brief 面内部是否与线相交
	static UGbool IsRegionIIntersectLineB(UGPoint2D *pSrcPoints,UGint *pSrcRegionCounts,UGint nSrcSubCount,
										  UGPoint2D *pTagPoints,UGint *pTagLineCounts,UGint nTagSubCount);
	//! \brief 线边界是否包含线边界
	static UGbool IsLineBContainLineB(UGPoint2D *pSrcPoints,UGint *pSrcLineCounts,UGint nSrcSubCount,
										UGPoint2D *pTagPoints,UGint *pTagLineCounts,UGint nTagSubCount);
	//! \brief 面是否包含线
	static UGbool IsRegionContainLine(UGPoint2D *pSrcPoints,UGint *pSrcRegionCounts,UGint nSrcSubCount,
											  UGPoint2D *pTagPoints,UGint *pTagLineCounts,UGint nTagSubCount);

};

}

#endif // !defined(AFX_UGGEORELATION_H__4BFF0D4D_CD98_4DF5_B7AD_ED2C116651AD__INCLUDED_)
