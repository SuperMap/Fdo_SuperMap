//-------------------------------------------------------------------------------------
// 文件名：			UGRect.h
// 类  名：			UGRect
// 父  类：			
// 子  类：			
// 功能说明：		矩形(一般用于屏幕坐标)
// 调用说明：		根据屏幕坐标开发完成。left<right,top<bottom
//------------------------------------------------------------------------------------------------
/*! 更新说明
*    2007.09.21 guohui	对头文件进行详细注释
*/ 
#ifndef UGRECT_H
#define UGRECT_H
#include "Base/ugdefs.h"
#include "UGPoint.h"

namespace UGC {

class ALGORITHM_API UGRect  
{
public:
	UGint left;
	UGint top;
	UGint right;
	UGint bottom;		
public:

	//! \brief 		缺省构造函数
	//! \return 	void
	//! \param 		
	//! \remarks 	
	UGRect();	

	//! \brief 		带参构造函数
	//! \return 	void
	//! \param 		l	左
	//! \param 		t	上
	//! \param 		r	右
	//! \param 		b	下
	//! \remarks 	底层不会对数据进行规则化(不会确保left<right,top<bottom)关系
	UGRect(UGint l,UGint t,UGint r,UGint b);
	
	//! \brief 		带参构造函数
	//! \return 	void
	//! \param 		p	左上角坐标
	//! \param 		s	矩形的大小
	//! \remarks 	
	UGRect(const UGPoint& p,const UGSize& s);

	//! \brief 		带参构造函数
	//! \return 	void
	//! \param 		tl	左上角坐标
	//! \param 		br	右下角坐标
	//! \remarks 	
	UGRect(const UGPoint& tl,const UGPoint& br);	

	//! \brief 		重载 ==
	//! \return 	UGbool
	//! \remarks 	
	friend ALGORITHM_API UGbool operator==(const UGRect& p,const UGRect& q);

	//! \brief 		重载 !=
	//! \return 	UGbool
	//! \remarks 	
	friend ALGORITHM_API UGbool operator!=(const UGRect& p,const UGRect& q);
	
	//! \brief 		设置矩形参数
	//! \return 	void
	//! \param 		l	左
	//! \param 		t	上
	//! \param 		r	右
	//! \param 		b	下
	//! \remarks 	
	void SetRect(UGint l,UGint t,UGint r,UGint b);

	//! \brief 		设置矩形参数
	//! \return 	void
	//! \param 		tl	左上角坐标
	//! \param 		br	右下角坐标
	//! \remarks 	
	void SetRect(const UGPoint& tl,const UGPoint& br);

	//! \brief 		将矩形置为空
	//! \return 	void
	//! \remarks 	将参数置0
	void SetEmpty();

	//! \brief 		矩形是否为空
	//! \return 	UGbool
	//! \remarks 	如果不符合left<right,top<bottom规则，则为空
	UGbool IsEmpty();

	//! \brief 		矩形是否为未初始化
	//! \return 	UGbool
	//! \remarks 	如果不符合left<right,top<bottom规则，则为空
	UGbool IsNull();

	//! \brief 		矩形的宽度
	//! \return 	UGint
	//! \remarks 	有可能为负数
	UGint Width() const;

	//! \brief 		矩形的宽度
	//! \return 	UGint
	//! \remarks 	有可能为负数
	UGint  Height() const;

	//! \brief 		矩形的左上角点
	//! \return 	UGPoint
	//! \remarks 	
	UGPoint& TopLeft();

	//! \brief 		返回const类型的左上角
	//! \return 	UGPoint
	//! \remarks 	如果对象rect为const类型，则将调用本接口
	const UGPoint& TopLeft() const;	

	//! \brief 		返回const类型的右下角
	//! \return 	UGPoint
	//! \remarks 	
	UGPoint& BottomRight();		

	//! \brief 		返回const类型的右下角
	//! \return 	UGPoint
	//! \remarks 	如果对象rect为const类型，则将调用本接口
	const UGPoint& BottomRight() const;
	
	//! \brief 		获取矩形的中心点
	//! \return 	UGPoint
	//! \remarks 	矩形对角线的交点
	UGPoint CenterPoint() const;
	
	//! \brief 		获取矩形的大小
	//! \return 	UGSize
	//! \remarks 	
	UGSize Size() const;

	//! \brief 		交换左、右值
	//! \return 	void
	//! \remarks 	
	void SwapLeftRight();

	//! \brief 		交换上、下值
	//! \return 	void
	//! \remarks 	
	void SwapTopBottom();	

	//! \brief 		点是否在矩形中
	//! \return 	UGbool
	//! \param 		p	坐标点
	//! \remarks 	
	UGbool PtInRect(const UGPoint& p) const;

	//! \brief 		矩形r是否包含在本矩形中
	//! \return 	UGbool
	//! \param 		r	矩形
	//! \remarks 	
	UGbool Contains(const UGRect& r) const;

	//! \brief 		本矩形是否在矩形r中
	//! \return 	UGbool
	//! \param 		r	矩形
	//! \remarks 	
	UGbool Withins(const UGRect& r) const;

	//! \brief 		本矩形与矩形r是否相交
	//! \return 	UGbool
	//! \param 		r	矩形
	//! \remarks 	
	UGbool Intersects(const UGRect& r) const;


	//! \brief 		进行表转化，确保left<=right,top<=bottom
	//! \return 	void
	//! \remarks 	
	void Normalize();
	
	//! \brief 		对矩形进行偏移
	//! \return 	void
	//! \param 		x	横坐标偏移量
	//! \param 		y	纵坐标偏移量
	//! \remarks 	
	void Offset(UGint x,UGint y);
	
	//! \brief 		对矩形进行偏移
	//! \return 	void
	//! \param 		s	横纵坐标偏移量
	//! \remarks 	
	void Offset(const UGSize& s);
	
	//! \brief 		对矩形进行偏移
	//! \return 	void
	//! \param 		p	横纵坐标偏移量
	//! \remarks 	
	void Offset(const UGPoint& p);

	//! \brief 		对矩形进行放大
	//! \return 	void
	//! \param 		margin	横纵放大量
	//! \remarks 	
	void Inflate(UGint margin);

	//! \brief 		对矩形进行放大
	//! \return 	void
	//! \param 		hormargin	横坐标放大量
	//! \param 		vermargin	总坐标放大量
	//! \remarks 	
	void Inflate(UGint hormargin,UGint vermargin);

	//! \brief 		对矩形进行放大
	//! \return 	void
	//! \param 		leftmargin	
	//! \param 		topmargin	
	//! \param 		rightmargin	
	//! \param 		bottommargin
	//! \remarks 	
	void Inflate(UGint leftmargin,UGint topmargin,UGint rightmargin,UGint bottommargin);
	
	//! \brief 		对矩形进行缩小
	//! \return 	void
	//! \param 		margin	横纵缩小量
	//! \remarks 	
	void Deflate(UGint margin);

	//! \brief 		对矩形进行缩小
	//! \return 	void
	//! \param 		hormargin	横坐标缩小量
	//! \param 		vermargin	总坐标缩小量
	//! \remarks 	
	void Deflate(UGint hormargin,UGint vermargin);

	//! \brief 		对矩形进行缩小
	//! \return 	void
	//! \param 		leftmargin	
	//! \param 		topmargin	
	//! \param 		rightmargin	
	//! \param 		bottommargin
	//! \remarks 	
	void Deflate(UGint leftmargin,UGint topmargin,UGint rightmargin,UGint bottommargin);

	//! \brief 		矩形合并
	//! \return 	void
	//! \param 		p	
	//! \remarks 	
	void Union(const UGPoint& p);

	//! \brief 		矩形合并
	//! \return 	void
	//! \param 		r	
	//! \remarks 	
	void Union(const UGRect& r);	

	//! \brief 		矩形求交
	//! \return 	void
	//! \param 		r	
	//! \remarks 	
	void Intersection(const UGRect& r);

};

}

#endif 


