// UGTriangle.h: interface for the UGTriangle class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGTRIANGLE_H__BF0834D4_D398_4B7F_B027_68076A8B642E__INCLUDED_)
#define AFX_UGTRIANGLE_H__BF0834D4_D398_4B7F_B027_68076A8B642E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Base/UGArray.h"
#include "Algorithm/UGPoint3D.h"
#include "Geometry/UGTINBlock.h"

namespace UGC {

class GRIDANALYST_API UGTriangle
{
public:

	UGTri* m_pTri;
	UGint m_nTriCount;
	UGint m_nRealCount;

public:
	UGTriangle();
	virtual ~UGTriangle();

protected:
	void SetPoints(UGPoint3D* p, UGint lPointCount);
	void Delaunay(UGPoint3D* p, UGint lPointCount, UGTriedge& farleft, UGTriedge& farright);

	UGTri* GetAt(UGint nIndex);
	UGint GetSize();
	

	void AddPoints(UGPoint3D* pnts);
	void CalCircle(UGdouble dxa, UGdouble dya, UGdouble dxb, UGdouble dyb, UGdouble dxc, UGdouble dyc,
		UGdouble& dRadius, UGdouble& dX, UGdouble& dY);
	void CalCircle(UGint pa, UGint pb, UGint pc, UGdouble& dRadius, UGdouble& dX, UGdouble& dY);
private:
	void alternateaxes(UGint *pPointIndex, UGint lPointCount, UGint axis);
	void pointmedian(UGint *pPointIndex, UGint lPointCount, UGint median, UGint axis);

	void DivConDelaunay(UGint* pPointIndex, UGint lPointCount, UGint axis, UGTriedge& farleft, UGTriedge& farright);
	UGbool MakeTriangle(UGTriedge& triedge);
	void mergehulls(UGTriedge &farleft, UGTriedge &innerleft, UGTriedge &innerright, UGTriedge &farright, UGint axis);

	UGbool incircle(UGint pa, UGint pb, UGint pc, UGint pd);
	UGdouble counterclockwise(UGint p1, UGint p2, UGint p3);
	
	
	void bondnull(UGTriedge& triedge);
	
	
protected:
	void org(const UGTriedge& triedge, UGint& point);
	void dest(const UGTriedge& triedge, UGint& point);
	void apex(const UGTriedge& triedge, UGint& point);
	void setorg(const UGTriedge& triedge, UGint point);
	void setdest(const UGTriedge& triedge, UGint point);
	void setapex(const UGTriedge& triedge, UGint point);
	void bond(UGTriedge& triedge1, UGTriedge& triedge2);
	void sym(const UGTriedge& triedge1, UGTriedge& triedge2);
	void symself(UGTriedge& triedge);
	void lnext(const UGTriedge& triedge1, UGTriedge& triedge2);
	void lnextself(UGTriedge& triedge);
	void lprev(const UGTriedge& triedge1, UGTriedge& triedge2);
	void lprevself(UGTriedge& triedge);
	void triedgecopy(UGTriedge& triedge1, UGTriedge& triedge2);
	UGbool triedgeequal(UGTriedge& triedge1, UGTriedge& triedge2);
	
	// 返回1时为逆时针，－1时为顺时针，0为共线
	UGint counterclockwise(UGdouble x1, UGdouble y1, UGdouble x2, UGdouble y2, UGdouble x3, UGdouble y3);
	UGdouble CalDistance(UGdouble dx1, UGdouble dy1, UGdouble dx2, UGdouble dy2);

	// 计算坡度坡向
	void CalTriSlopeAspect();

	// 计算单个三角形的坡度坡向
	void CalSlopeAspect(const UGPoint3D& p1, const UGPoint3D& p2, const UGPoint3D& p3, UGdouble& dSlope, UGdouble& dAspect);


#ifdef sparc  // 在solaris下对单元测试类的友元类设置不起作用，单元测试编不过去，
	// 故暂且在solaris系统下将所有的private和pretected类型开放为public
public:
#else
#ifdef _AIX
public:
#endif
protected:
#endif
	UGint scale_expansion_zeroelim(int elen, double *e, double b, double *h);
	UGdouble incircleadapt(UGdouble x1, UGdouble y1, UGdouble x2, UGdouble y2, UGdouble x3, UGdouble y3, UGdouble x4, UGdouble y4, UGdouble permanent);
	UGdouble incircle1(UGdouble x1, UGdouble y1, UGdouble x2, UGdouble y2, UGdouble x3, UGdouble y3, UGdouble x4, UGdouble y4);
	UGdouble estimate(int elen, double *e);
	UGint fast_expansion_sum_zeroelim(int elen, double *e, int flen, double *f, double *h);
	UGdouble counterclockwiseadapt(UGdouble x1, UGdouble y1, UGdouble x2, UGdouble y2, UGdouble x3, UGdouble y3, double detsum);
	UGdouble counterclockwise1(UGdouble x1, UGdouble y1, UGdouble x2, UGdouble y2, UGdouble x3, UGdouble y3);
	void exactinit();

	UGdouble epsilon;
	UGdouble splitter;
	UGdouble resulterrbound;
	UGdouble ccwerrboundA, ccwerrboundB, ccwerrboundC;
	UGdouble iccerrboundA, iccerrboundB, iccerrboundC;
	UGdouble o3derrboundA, o3derrboundB, o3derrboundC;


protected:
	UGPoint3D* m_pPoint3D;
	UGint plus1mod3[3];
	UGint minus1mod3[3];
};

}
#endif // !defined(AFX_UGTRIANGLE_H__BF0834D4_D398_4B7F_B027_68076A8B642E__INCLUDED_)
