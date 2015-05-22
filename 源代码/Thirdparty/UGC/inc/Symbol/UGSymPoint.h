

#ifndef UG_SYMPOINT_H
#define UG_SYMPOINT_H

#include "Base/ugdefs.h"
#include "Base/UGStream.h"

namespace UGC 
{
/** UGSymPoint点符号的坐标点		
	@remarks
		1.符号的定义区域由逻辑网格点组成；
		  我们将其称之为点符号坐标系统(Point-Symbol Coordinat System)；
		2.逻辑网格坐标x轴向右为正，y轴向下为正；
		3.逻辑网格的范围为256*256(目前暂时定义这么大，以后需要的时候考虑扩展)；
*/
class SYMBOL_API UGSymPoint  
{
public:
	//使用UGuchar数据类型，定义坐标范围为：256×256
	UGuchar x;
	UGuchar y;
	
public:
	UGSymPoint():x(0),y(0){}
	UGSymPoint(UGuchar xx, UGuchar yy):x(xx),y(yy){}

	//像这样的类，编译器默认的方式已经足够胜任了
	//UGSymPoint(const UGSymPoint& symPoint);	
	//void operator = (const UGSymPoint& symPoint);	

	UGbool operator == (const UGSymPoint& rhs)
	{
		return x == rhs.x && y == rhs.y ;
	}

	UGbool operator != (const UGSymPoint& rhs)
	{
		return x != rhs.x || y != rhs.y ;
	}
	
	void Offset(UGuchar xOffset, UGuchar yOffset)
	{
		this->x += xOffset;
		this->y += yOffset;
	}

	friend SYMBOL_API UGStream& operator<<(UGStream& stream, const UGSymPoint& point)
	{
		stream << point.x << point.y;
		return stream;
	}

	friend SYMBOL_API UGStream& operator>>(UGStream& stream, UGSymPoint& point)
	{
		stream >> point.x >> point.y;
		return stream;
	}

	// for Debug Testing
	inline friend std::ostream& operator << ( std::ostream& o, const UGSymPoint& pt )
	{
		o << "UGSymPoint(" << pt.x << ", " << pt.y << ")";
		return o;
	}
};
	
}

#endif


