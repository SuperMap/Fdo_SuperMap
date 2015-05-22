// UGGraphicsFactory.h: interface for the UGGraphicsFactory class.
//
//////////////////////////////////////////////////////////////////////

/*!
   **************************************************************************************
    \file     UGGraphicsFactory.h
   **************************************************************************************
    \author   陈国雄
    \brief    显示工厂基类                                                           
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2005 SuperMap GIS Technologies,Inc.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-06-09  陈国雄    初始化版本.                                       <br>
   **************************************************************************************
*/

#if !defined(AFX_UGGRAPHICSFACTORY_H__A02FE462_798F_458D_8C59_37C018C542E4__INCLUDED_)
#define AFX_UGGRAPHICSFACTORY_H__A02FE462_798F_458D_8C59_37C018C542E4__INCLUDED_

#include "UGGraphics.h"

namespace UGC {

class GRAPHICS_API UGGraphicsFactory  
{
public:
	UGGraphicsFactory();
	virtual ~UGGraphicsFactory();

public:
	virtual UGint GetType() = 0;
	virtual UGString GetName() = 0;
	virtual UGGraphics* NewGraphics() = 0;
	virtual UGBrush* NewBrush() = 0;
	virtual UGFont* NewFont() = 0;
	virtual UGImage* NewImage() = 0;
	virtual UGPen* NewPen() = 0;
	virtual UGRgn* NewRgn() = 0;

};

}

#endif // !defined(AFX_UGGRAPHICSFACTORY_H__A02FE462_798F_458D_8C59_37C018C542E4__INCLUDED_)
