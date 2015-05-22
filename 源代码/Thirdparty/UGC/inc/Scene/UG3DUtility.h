/* 
	\file UG3DUtility.h
	\brief 3D实用类。
	\author malq zhangyl
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>更新说明：。</b>
	<em>1、第一条说明。</em>
	<em>2、第二条说明。</em>
*/

#if !defined(AFX_UG3DUTILITY_H__ED8689C4_45C9_4423_95CA_8C205265AED5__INCLUDED_)
#define AFX_UG3DUTILITY_H__ED8689C4_45C9_4423_95CA_8C205265AED5__INCLUDED_

#include "Scene/UGPrerequisites.h"

namespace UGC 
{

//! \brief 3D实用类。
class SCENE_API UG3DUtility  
{

public:
	
	//! \brief 构造函数。
	UG3DUtility();	
	
	//! \brief 析构函数。
	virtual ~UG3DUtility();
	//! \brief 
	static void ReadIndexFile(const UGString& strIndexFile,UGArray<UGint>& arryID);
	
};

}

#endif // !defined(AFX_UG3DUTILITY_H__ED8689C4_45C9_4423_95CA_8C205265AED5__INCLUDED_)
