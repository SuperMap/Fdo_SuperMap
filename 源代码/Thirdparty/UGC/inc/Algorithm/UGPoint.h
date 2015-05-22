//-------------------------------------------------------------------------------------
// 文件名：			UGPoint.h
// 类  名：			UGPoint
// 父  类：			
// 子  类：			
// 功能说明：		坐标点(一般用于屏幕坐标)
// 调用说明：		
//------------------------------------------------------------------------------------------------
/*! 更新说明
*    2007.09.21 guohui	对头文件进行详细注释
*/ 

#ifndef UGPOINT_H
#define UGPOINT_H
#include "Base/ugdefs.h"
#include "UGSize.h"
#include "Base/UGStream.h"
#include "Base/UGArray.h"

namespace UGC {

class UGSize;

class ALGORITHM_API UGPoint  
{
public:
	UGint x;
	UGint y;
public:

	//! \brief 		缺省构造函数
	UGPoint();

	//! \brief 		带参构造函数
	//! \return 	
	//! \param 		xx			横坐标
	//! \param 		yy			纵坐标
	//! \remarks 		
	UGPoint(UGint xx,UGint yy);	

	//! \brief 		拷贝构造函数
	//! \return 	
	//! \param 		s			
	//! \remarks 		
	UGPoint(const UGSize& s);

	//! \brief 		绕点旋转
	//! \return 	void
	//! \param 		pntAnchor	中心点
	//! \param 		dRadian		旋转角度(弧度)
	//! \remarks 	
	void Rotate(const UGPoint& pntAnchor, double dRadian);

	//! \brief 		绕点旋转
	//! \return 	void
	//! \param 		pntAnchor	中心点
	//! \param 		dCos		余弦值
	//! \param 		dSin		正弦值
	//! \remarks 	
	void Rotate(const UGPoint& pntAnchor, double dCos, double dSin);

	//! \brief 		点偏移
	//! \return 	void
	//! \param 		szValue		偏移量
	//! \remarks 	
	void Offset(const UGSize &szValue);

	//! \brief 		点偏移
	//! \return 	void
	//! \param 		nOffsetX	横坐标偏移
	//! \param 		nOffsetY	纵坐标偏移
	//! \remarks 	
	void Offset(UGint nOffsetX, UGint nOffsetY);

	//! \brief 		重载 == 
	//! \return 	UGbool
	//! \remarks 	
	friend ALGORITHM_API UGbool operator==(const UGPoint& p,const UGPoint& q);

	//! \brief 		重载 != 
	//! \return 	UGbool
	//! \remarks 	
	friend ALGORITHM_API UGbool operator!=(const UGPoint& p,const UGPoint& q);			

	//! \brief 		重载 = 
	//! \return 	UGPoint
	//! \remarks 	
	UGPoint& operator=(const UGSize& s);		

	//! \brief 		重载 += 
	//! \return 	UGPoint
	//! \remarks 	
	UGPoint& operator+=(const UGPoint& p);

	//! \brief 		重载 += 
	//! \return 	UGPoint
	//! \remarks 	
	UGPoint& operator+=(const UGSize& s);

	//! \brief 		重载 -= 
	//! \return 	UGPoint
	//! \remarks 	
	UGPoint& operator-=(const UGPoint& p);

	//! \brief 		重载 -= 
	//! \return 	UGPoint
	//! \remarks 	
	UGPoint& operator-=(const UGSize& s);	

	//! \brief 		重载 -(取相反数) 
	//! \return 	UGPoint
	//! \remarks 	
	UGPoint operator-();		

	//! \brief 		重载 +
	//! \return 	UGPoint
	//! \remarks 	
	friend ALGORITHM_API UGPoint operator+(const UGPoint& p,const UGPoint& q);

	//! \brief 		重载 +
	//! \return 	UGPoint
	//! \remarks 	
	friend ALGORITHM_API UGPoint operator+(const UGPoint& p,const UGSize& s);
	
	//! \brief 		重载 +
	//! \return 	UGPoint
	//! \remarks 	
	friend ALGORITHM_API UGPoint operator+(const UGSize& s,const UGPoint& p);	
	
	//! \brief 		重载 -
	//! \return 	UGPoint
	//! \remarks 	
	friend ALGORITHM_API UGPoint operator-(const UGPoint& p,const UGPoint& q);

	//! \brief 		重载 -
	//! \return 	UGPoint
	//! \remarks 	
	friend ALGORITHM_API UGPoint operator-(const UGPoint& p,const UGSize& s);

	//! \brief 		重载 -
	//! \return 	UGPoint
	//! \remarks 	
	friend ALGORITHM_API UGPoint operator-(const UGSize& s,const UGPoint& p);
	
	//! \brief 		重载 <<
	//! \return 	UGStream
	//! \remarks 	
	friend ALGORITHM_API UGStream& operator<<(UGStream& store,const UGPoint& p);	

	//! \brief 		重载 >>
	//! \return 	UGStream
	//! \remarks 	
	friend ALGORITHM_API UGStream& operator>>(UGStream& store,UGPoint& p);
	
};

typedef UGArray<UGPoint> UGPoints;
	
}

#endif


