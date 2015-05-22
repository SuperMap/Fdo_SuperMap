/*! \file	 UGRectUInt.h
 *  \brief	 4 byte unsinged int rect
 *  \author	 ugc team
 *  \attention 
 *  Copyright(c) 1996-2004 SuperMap GIS Technologies,Inc.<br>
 *  All Rights Reserved
 *  \version $Id: UGRectUInt.h,v 1.2 2007/09/29 06:06:07 guohui Exp $
 */
/*! 更新说明
*    2007.09.29 guohui	对头文件进行详细注释
*/ 

#ifndef UGRECTUINT_H
#define UGRECTUINT_H

#include "Base/ugdefs.h"

namespace UGC {

class ALGORITHM_API UGRectUInt  
{
public:

	UGuint left;
	UGuint top ;
	UGuint right;
	UGuint bottom;
public:

	//! \brief 		缺省构造函数
	//! \return 	void
	//! \param 		
	//! \remarks 	
	UGRectUInt();

	//! \brief 		析构函数
	//! \return 	void
	//! \param 		
	//! \remarks 	
	virtual ~UGRectUInt();

	//! \brief 		带参构造函数
	//! \return 	void
	//! \param 		l	左
	//! \param 		t	上
	//! \param 		r	右
	//! \param 		b	下
	//! \remarks 	底层不会对数据进行规则化(不会确保left<right,top<bottom)关系
	UGRectUInt(UGuint l, UGuint t, UGuint r, UGuint b);

	//! \brief 		拷贝构造函数
	//! \return 	void
	//! \param 		
	//! \remarks 	
	UGRectUInt(const UGRectUInt& srcRect);
	
	//! \brief 		宽度
	//! \return 	void
	//! \param 		
	//! \remarks 	
	UGuint Width() const;

	//! \brief 		高度
	//! \return 	void
	//! \param 		
	//! \remarks 	
	UGuint Height() const;
	
	//! \brief 		重载 =
	UGRectUInt& operator=(const UGRectUInt& srcRect);

	//! \brief 		重载 ==
	UGbool operator==(const UGRectUInt& rect) const;

	//! \brief 		重载 !=
	UGbool operator!=(const UGRectUInt& rect) const;
	
	//! \brief 		将对象置空
	void SetRectEmpty();
	
	//! \brief 		将对象置空(0,0,0,0)
	void SetNULL();
	
	//! \brief 		合并对象
	UGbool UnionRect(const UGRectUInt &rect1, const UGRectUInt &rect2);

	//! \brief 		是否包含
	UGbool Contain(const UGRectUInt &rect) const;

	//! \brief 		是否相交(包括边或角点重叠)	
	UGbool IsIntersect(const UGRectUInt &rect) const;
	
	//! \brief 		是否为空矩形
	//! \return     TRUE if rectangle has no area
	UGbool IsRectEmpty() const;

	//! \brief 		是否为空
	//! \return     TRUE if rectangle is (0,0,0,0)
	UGbool IsRectNull() const;

};

}

#endif
