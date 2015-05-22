//-------------------------------------------------------------------------------------
// 文件名：			UGSize2D.h
// 类  名：			UGSize2D
// 父  类：			
// 子  类：			
// 功能说明：		
// 调用说明：		
//=====================================================================================
/* 修改说明：
 *		2007.09.21	guohui	为本头文件添加注释
 */

#ifndef UGSIZE2D_H
#define UGSIZE2D_H
#include "Base/ugdefs.h"

namespace UGC {

class ALGORITHM_API UGSize2D  
{
public:
	UGdouble cx;
	UGdouble cy;
public:
	
	//! \brief 		缺省构造函数
	//! \return 	void
	//! \param 		
	//! \remarks 	
	UGSize2D();	

	//! \brief 		带参构造函数
	//! \return 	void
	//! \param 		cx		横坐标
	//! \param 		cy		纵坐标
	//! \remarks 	
	UGSize2D(UGdouble dx,UGdouble dy);
	
	//! \brief 		重载==
	//! \return 	UGbool
	//! \remarks 	
	friend ALGORITHM_API UGbool operator==(const UGSize2D& s,const UGSize2D& t);

	//! \brief 		重载!=
	//! \return 	UGbool
	//! \remarks 		
	friend ALGORITHM_API UGbool operator!=(const UGSize2D& s,const UGSize2D& t);	

	//! \brief 		重载 +=
	//! \return 	UGSize2D
	//! \remarks 	
	UGSize2D& operator+=(const UGSize2D& s);

	//! \brief 		重载 -=
	//! \return 	UGSize2D
	//! \remarks 	
	UGSize2D& operator-=(const UGSize2D& s);	

	//! \brief 		重载 *=
	//! \return 	UGSize2D
	//! \remarks 	
	UGSize2D& operator*=(UGdouble c);

	//! \brief 		重载 /=
	//! \return 	UGSize2D
	//! \remarks 	
	UGSize2D& operator/=(UGdouble c);	

	//! \brief 		重载 -
	//! \return 	UGSize2D
	//! \remarks 	
	UGSize2D operator-();	

	//! \brief 		重载 +
	//! \return 	UGSize2D
	//! \remarks 	
	friend ALGORITHM_API UGSize2D operator+(const UGSize2D& s,const UGSize2D& t);

	//! \brief 		重载 -
	//! \return 	UGSize2D
	//! \remarks 	
	friend ALGORITHM_API UGSize2D operator-(const UGSize2D& s,const UGSize2D& t);

	//! \brief 		重载 *
	//! \return 	UGSize2D
	//! \remarks 	
	friend ALGORITHM_API UGSize2D operator*(const UGSize2D& s,UGdouble c);

	//! \brief 		重载 *
	//! \return 	UGSize2D
	//! \remarks 	
	friend ALGORITHM_API UGSize2D operator*(UGdouble c,const UGSize2D& s);

	//! \brief 		重载 /
	//! \return 	UGSize2D
	//! \remarks 	
	friend ALGORITHM_API UGSize2D operator/(const UGSize2D& s,UGdouble c);

	//! \brief 		重载 /
	//! \return 	UGSize2D
	//! \remarks 	
	friend ALGORITHM_API UGSize2D operator/(UGdouble c,const UGSize2D& s);
};

}

#endif
