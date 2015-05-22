// UGWPen.h: interface for the UGWPen class.
//
//////////////////////////////////////////////////////////////////////

/*!
   **************************************************************************************
    \file     UGWPen.h  
   **************************************************************************************
    \author   张艳良、陈国雄
    \brief    Windows画笔类                                                          
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2005 SuperMap GIS Technologies,Inc.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-06-09  陈国雄    初始化版本.                                       <br>
   **************************************************************************************
*/

#if !defined(AFX_UGWPEN_H__CBB55B90_7B33_4712_8F05_26D0778778E2__INCLUDED_)
#define AFX_UGWPEN_H__CBB55B90_7B33_4712_8F05_26D0778778E2__INCLUDED_

#include "Graphics/UGPen.h"

namespace UGC
{

class WGRAPHICS_API UGWPen : public UGPen  
{
public:
	UGWPen();
	virtual ~UGWPen();	

	//
	virtual UGbool Create();
	virtual UGbool Create(const UGPenData& PenData);
	virtual UGbool Create(
		UGint nStyle,
		UGint nWidth = 0,
		UGColor clrColor = UGRGB(0, 0, 0),
		UGint nCapStyle = 0,
		UGint nJoinStyle = 0);
	
	//
	virtual void DeleteObject();

private:
	UGbool m_bNeedRelease;
	
};

}

#endif // !defined(AFX_UGWPEN_H__CBB55B90_7B33_4712_8F05_26D0778778E2__INCLUDED_)
