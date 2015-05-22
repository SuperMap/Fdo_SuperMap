//-------------------------------------------------------------------------------------
// 文件名：			UGSize.h
// 类  名：			UGSize
// 父  类：			
// 子  类：			
// 功能说明：		
// 调用说明：		
//=====================================================================================
/* 修改说明：
 *		2007.09.21	guohui	为本头文件添加注释
 */

#ifndef UGSIZE_H
#define UGSIZE_H
#include "Base/ugdefs.h"

namespace UGC {

class ALGORITHM_API UGSize  
{
public:
	UGint cx;
	UGint cy;
public:

	//! \brief 		缺省构造函数
	//! \return 	void
	//! \param 		
	//! \remarks 	
	UGSize();	

	//! \brief 		带参构造函数
	//! \return 	void
	//! \param 		ww		横坐标
	//! \param 		hh		纵坐标
	//! \remarks 	
	UGSize(UGint ww,UGint hh);

	//! \brief 		重载==
	//! \return 	UGbool
	//! \remarks 	
	friend ALGORITHM_API UGbool operator==(const UGSize& s,const UGSize& t);

	//! \brief 		重载!=
	//! \return 	UGbool
	//! \remarks 	
	friend ALGORITHM_API UGbool operator!=(const UGSize& s,const UGSize& t);	

	//! \brief 		重载 +=
	//! \return 	UGSize
	//! \remarks 	
	UGSize& operator+=(const UGSize& s);

	//! \brief 		重载 -=
	//! \return 	UGSize
	//! \remarks 	
	UGSize& operator-=(const UGSize& s);	

	//! \brief 		重载 -
	//! \return 	UGSize
	//! \remarks 	
	UGSize operator-();	

	//! \brief 		重载 +
	//! \return 	UGSize
	//! \remarks 	
	friend ALGORITHM_API UGSize operator+(const UGSize& s,const UGSize& t);

	//! \brief 		重载 -
	//! \return 	UGSize
	//! \remarks 	
	friend ALGORITHM_API UGSize operator-(const UGSize& s,const UGSize& t);
	
};

}

#endif 


