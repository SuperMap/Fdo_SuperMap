// UGFillSymParam.h: interface for the UGFillSymParam class.
//
//////////////////////////////////////////////////////////////////////

/*!
   **************************************************************************************
    \file     UGFillSymParam.h
   **************************************************************************************
    \author   陈国雄
    \brief    填充符号参数类                                                                       
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2005 SuperMap GIS Technologies,Inc.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-05-23  陈国雄    初始化版本.                                       <br>
   **************************************************************************************
*/

#if !defined(AFX_UGFILLSYMPARAM_H__FD7DA634_1368_40D9_80A9_6593E14331D4__INCLUDED_)
#define AFX_UGFILLSYMPARAM_H__FD7DA634_1368_40D9_80A9_6593E14331D4__INCLUDED_

#include "Algorithm/UGSize2D.h"
#include "Graphics/UGGraphics.h"

namespace UGC {

class UGFillSymbol;
class UGMarkerSymbolLib;

class SYMBOL_API UGFillSymParam  
{
public:
	UGFillSymParam();
	virtual ~UGFillSymParam();

public:
	//! 填充符号显示时的大小，如果为UGSize(0,0)就用默认大小
	UGSize2D GetSize() const;
	void SetSize(const UGSize2D& size);

	//! 填充符号显示时的背景色；
	UGColor GetBackColor() const;
	void SetBackColor(UGColor color);

	//! 填充符号显示时的前景色；
	UGColor GetForeColor() const;
	void SetForeColor(UGColor color);

	//! 填充符号显示时的缩放比例；
	UGdouble GetScale() const;
	void SetScale(UGdouble dScale);

	//! 填充符号显示时是否背景不透明；
	UGbool IsBackOpaque() const;
	void SetBackOpaque(UGbool bOpaque);
	
	//! 填充符号；
	UGFillSymbol* GetFillSymbol() const;
	void SetFillSymbol(UGFillSymbol *pFillSymbol);
	
	//! 填充符号使用到的点状符号库；
	UGMarkerSymbolLib* GetMarkerSymbolLib() const;
	void SetMarkerSymbolLib(UGMarkerSymbolLib *pMarkerSymLib);
	
	//! 填充符号显示时位图临时的缓存；
	const UGImage* GetImageAnd() const;	
	const UGImage* GetImageOr() const;
	const UGImage* GetImage() const;

	//! 创建位图零时缓存；
	UGbool Create(UGGraphics& graphics);
	UGbool Create(UGGraphics& graphics, 
			UGFillSymbol *pFillSymbol,			
			UGMarkerSymbolLib *pPointSymLib,
			UGColor clrFore = UGRGB(0,0,0),
			UGColor clrBack = UGRGB(255,255,255),
			const UGSize2D& size = UGSize2D(0.0,0.0),
			UGdouble dScale = 1.0,
			UGbool bBackOpaque = true,
			UGbyte btOpaqueRate = 100);
	//! 释放零时缓存；
	void Release();

	//! 填充点缓存；
	UGRect PreProcessPoints(UGGraphics& graphics, const UGPoint* pPoints, UGint nCount);
	const UGPoint* GetPointsBuf() const;
	UGint GetPointsBufSize() const;

	//! 填充透明度
	UGbyte GetOpaqueRate() const;
	void SetOpaqueRate(UGbyte btOpaqueRate);

protected:
	//! 填充模式显示时的大小；
	UGSize2D m_szSize;	
	//! 填充模式显示时的背景色；
	UGColor m_clrBack;	
	//! 填充模式显示时的前景色；
	UGColor m_clrFore;		

	//!  填充缩放比例
	UGdouble m_dScale;

	//! 透明显示时，求交用的Image
	UGImage* m_pImageAnd;			
	//! 透明显示时，求并用的Image
	UGImage* m_pImageOr;		
	//! 具有指定前背景色的Image
	UGImage*  m_pImage;		

	UGbool m_bBackOpaque;
	UGbyte m_btOpaqueRate;

	UGFillSymbol* m_pFillSymbol;
	UGMarkerSymbolLib* m_pMarkerSymLib;

	UGPoint* m_pPoints;
	UGint m_nPntCount;

};

}

#endif // !defined(AFX_UGFILLSYMPARAM_H__FD7DA634_1368_40D9_80A9_6593E14331D4__INCLUDED_)
