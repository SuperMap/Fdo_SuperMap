/*! \file	 UGRelPointRegion.h
 *  \brief	 点和面的空间位置关系判断
 *  \author	 ugc team
 *  \attention 
 *  Copyright(c) 1996-2004 SuperMap GIS Technologies,Inc.<br>
 *  All Rights Reserved
 *  \version $Id: UGRelPointRegion.h,v 1.5 2007/09/29 06:06:08 guohui Exp $
 */


#if !defined(AFX_UGRELPOINTREGION_H__2312A74C_9CD3_48E9_A1D8_62AE9DC2BF70__INCLUDED_)
#define AFX_UGRELPOINTREGION_H__2312A74C_9CD3_48E9_A1D8_62AE9DC2BF70__INCLUDED_

#include "Base/ugdefs.h"
#include "Algorithm/UGPoint2D.h"
#include "Algorithm/UGRect2D.h"

namespace UGC {

//! \brief 点和面的空间位置关系判断
class ALGORITHM_API UGRelPointRegion  
{
private:
	UGRelPointRegion();

public:  
	

	//! \brief 点是否在简单多边形内
	//! \param pBounds 可选参数, 多边形的Bounds
	//! \param bInside 点在多边形边界上, 属于内还是属于外, =true时,属于内; =false时,属于外
	static UGbool IsWithin(const UGPoint2D& pnt, 
						   const UGPoint2D* pPoints, UGint nPntCount, 
						   const UGRect2D* pBounds=NULL,UGbool bInside=true);

	//! \brief 点是否在复杂多边形内
	//! \param pBounds 可选参数, 多边形的Bounds
	//! \param bInside 点在多边形边界上, 属于内还是属于外,=true时,属于内; =false时,属于外
	static UGbool IsWithin(const UGPoint2D& pnt, 
						   const UGPoint2D* pPoints, const UGint* pPolyCount, UGint nSubCount, 
						   const UGRect2D* pBounds=NULL,UGbool bInside=true);
	
	//! \brief 点是否在复杂多边形内
	//! \param pBounds 多边形的Bounds
	//! \param dTolerance	容限 
	//! \return 0	点在多边形外部; 1	点在多边形内部;	 2 点在边界上;
	static UGint IsWithin(const UGPoint2D &point, UGPoint2D *pPoints,UGint *plPolyCounts,
							UGint nSubCount, const UGRect2D &rcFrame, UGdouble dTolerance=EP);


};

}

#endif // !defined(AFX_UGRELPOINTREGION_H__2312A74C_9CD3_48E9_A1D8_62AE9DC2BF70__INCLUDED_)
