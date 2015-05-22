/*! \file	 UGRelRegions.h
 *  \brief	 判断面面之间的空间关系
 *  \author	 ugc team
 *  \attention 
 *  Copyright(c) 1996-2004 SuperMap GIS Technologies,Inc.<br>
 *  All Rights Reserved
 *  \version $Id: UGRelRegions.h,v 1.4 2007/10/16 02:23:23 guohui Exp $
 */



#if !defined(AFX_UGRELREGIONREGION_H__028F4851_CE7D_4268_B59C_F8C3F632ECF1__INCLUDED_)
#define AFX_UGRELREGIONREGION_H__028F4851_CE7D_4268_B59C_F8C3F632ECF1__INCLUDED_

#include "Base/ugdefs.h"
#include "Algorithm/UGPoint2D.h"
#include "Algorithm/UGRect2D.h"

namespace UGC {

//! \brief 判断面面之间的空间关系
class ALGORITHM_API UGRelRegions
{
private:
	UGRelRegions();
	
public: // 面面基本空间位置关系判断

	//! \brief 判断两个面是否等同
	//! \remarks 点的个数,顺序,坐标 都必须一样
	static UGbool IsIdentical(const UGPoint2D* pPoints1, UGint nPntCount1, 
							  const UGPoint2D* pPoints2, UGint nPntCount2);

	//! \brief 判断两个面是否等同
	//! \remarks 点的个数,顺序,坐标 都必须一样
	static UGbool IsIdentical(const UGPoint2D* pPoints1,const UGint* pPolyCount1, UGint nSubCount1, 
							const UGPoint2D* pPoints2,const UGint* pPolyCount2, UGint nSubCount2 );
	// by guohui 2007.10.12	
	//! \brief 判断面1是否完全在面2的内部
	static UGbool IsWithin(const UGPoint2D* pPoints1,const UGint* pPolyCount1, UGint nSubCount1, 
							const UGPoint2D* pPoints2,const UGint* pPolyCount2, UGint nSubCount2 );

	//! \brief 判断面1是否完全在面2的内部
	static UGbool IsWithin(	const UGPoint2D* pPoints1,const UGint* pPolyCount1, UGint nSubCount1,
							const UGPoint2D* pPoints2, UGint nPntCount2);

	//! \brief 判断面1是否完全在面2的内部
	//! \remarks 两个面的交集等于面1
	static UGbool IsWithin(const UGPoint2D* pPoints1, UGint nPntCount1, 
							const UGPoint2D* pPoints2, UGint nPntCount2);

	//! \brief 判断面1是否完全在面2的内部
	//! \remarks 两个多边形已经确认没有相交关系，否则结果不正确，后果自负。
	//主要用来判断多边形两个子对象之间的相互关系。
	static UGbool IsWithin(const UGPoint2D* pPoints1, UGint nPntCount1, UGRect2D rcBounds1, 
							const UGPoint2D* pPoints2, UGint nPntCount2, UGRect2D rcBounds2);
	
	//! \brief 判断两个面是否接触
	//! \remarks 两个面的边界的交集不为空
	static UGbool IsTouch(const UGPoint2D* pPoints1, UGint nPntCount1, 
						  const UGPoint2D* pPoints2, UGint nPntCount2);

	//! \brief 判断两个面是否交叠
	//! \remarks 两个面的交集有二维部分, 同时交集不等于任何一个面
	static UGbool IsOverlap(const UGPoint2D* pPoints1, UGint nPntCount1, 
						  const UGPoint2D* pPoints2, UGint nPntCount2);


	//! \brief 判断两个面是否相离
	//! \remarks 两个面的边界 内部的交集都为空
	static UGbool IsDisjoint(const UGPoint2D* pPoints1, UGint nPntCount1, 
							 const UGPoint2D* pPoints2, UGint nPntCount2);

};

}

#endif // !defined(AFX_UGRELREGIONREGION_H__028F4851_CE7D_4268_B59C_F8C3F632ECF1__INCLUDED_)
