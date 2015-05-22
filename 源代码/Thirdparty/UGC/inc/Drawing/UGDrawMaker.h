// UGDrawMaker.h: interface for the UGDrawMaker class.
//
//////////////////////////////////////////////////////////////////////

/*!
   **************************************************************************************
    \file     UGDrawMaker.h
   **************************************************************************************
    \author   张艳良、陈国雄
    \brief    显示参数预设置类                                                       
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2005 SuperMap GIS Technologies,Inc.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-06-09  陈国雄    初始化版本.                                       <br>
   **************************************************************************************
*/

#if !defined(AFX_UGDRAWMAKER_H__D2C06D05_68DE_4883_B417_F9CB6685D2AE__INCLUDED_)
#define AFX_UGDRAWMAKER_H__D2C06D05_68DE_4883_B417_F9CB6685D2AE__INCLUDED_

#include "Graphics/UGGraphics.h"
#include "Base/UGStyle.h"

namespace UGC {

class UGMarkerSymbolLib;
class UGLineSymbolLib;
class UGFillSymbolLib;
class UGMarkerSymbol;
class UGLineSymbol;
class UGFillSymbol;
class UGMarkerSymParam;
class UGLineSymParam;
class UGFillSymParam;
class UGDrawParamaters;

class DRAWING_API UGDrawMaker  
{
public:
	UGDrawMaker();
	virtual ~UGDrawMaker();
	
public:
	//! \brief 获取符号填充信息
	//! \return 返回当前符号填充信息
	const UGFillSymbol* GetFillSymbol() const;
	//! \brief 获取线性填充信息
	//! \return 返回当前线性填充信息
	const UGLineSymbol* GetLineSymbol() const;
	//! \brief 获取符号填充信息
	//! \return 返回当前符号填充信息
	const UGMarkerSymbol* GetMarkerSymbol() const;
	//! \brief 获取当前画笔
	//! \return 当前画笔
	const UGPen* GetPen() const;
		//! \brief 获取当前画笔
	//! \return 当前画笔
	const UGBrush* GetBrush() const;
	//! \brief 获取当前符号信息参数
	//! \return 当前符号信息参数
	const UGMarkerSymParam* GetMarkerSymParam() const;
	//! \brief 获取当前符号信息参数
	//! \return 当前符号信息参数
	const UGFillSymParam* GetFillSymParam() const;
	//! \brief 获取当前线性信息参数
	//! \return 当前现行信息参数
	const UGLineSymParam* GetLineSymParam() const;
	//! \brief 设置线性库
	//! \param pLineSymLib 要设置的线性库
	void SetLineSymbolLib(UGLineSymbolLib* pLineSymLib);
	//! \brief 获得线性库
	//! \return 当前的线性库
	UGLineSymbolLib* GetLineSymbolLib() const;
	//! \brief 设置符号库
	//! \param pMarkerSymLib 要设置的符号库
	void SetMarkerSymbolLib(UGMarkerSymbolLib* pMarkerSymLib);
	//! \brief 获得符号库
	//! \return 当前的符号库
	UGMarkerSymbolLib* GetMarkerSymbolLib() const;
	//! \brief 设置填充库
	//! \param pMarkerSymLib 要设置的填充库
	void SetFillSymbolLib(UGFillSymbolLib* pFillSymLib);
    //! \brief 获得填充库
	//! \return 当前的填充库
	UGFillSymbolLib * GetFillSymbolLib() const;
	//! \brief 设置是否高亮
	//! \param bHignlight 要设置高亮
	void SetHignlight(UGbool bHignlight);
	//! \brief 判断否高亮
	//! \return 是否高亮
	UGbool IsHignlight() const;
	//! \brief 设置显示参数
	//! \param pGraphics 要设置当前图形显示基类
	//! \param style 要设置当前文本风格
	//! \param pDrawParam 要设置的画笔参数
	//! \param bThemeStyle 是否为标签专题图
	//! \return 设置是否成功
	UGbool Prepare(UGGraphics *pGraphics, UGTextStyle& style, UGDrawParamaters *pDrawParam, UGbool bThemeStyle = FALSE);
	//! \brief 设置显示参数
	//! \param pGraphics 要设置当前图形显示基类
	//! \param style 要设置当前风格
	//! \param pDrawParam 要设置的画笔参数
	//! \param bThemeStyle 是否为标签专题图
	//! \return 设置是否成功
	UGbool Prepare(UGGraphics *pGraphics, UGStyle& style, UGDrawParamaters *pDrawParam = NULL, UGint nDimension = 2);
	//! \brief 释放显示参数
	//! \param pGraphics 要释放的图形显示基类
	//! \param pDrawParam 要释放的画笔参数
	void Release(UGGraphics *pGraphics, UGDrawParamaters *pDrawParam = NULL);
	
protected:
	UGbool m_bHignlight;
	//! 符号库
	UGLineSymbolLib* m_pLineSymLib;
	UGMarkerSymbolLib* m_pMarkerSymLib;
	UGFillSymbolLib * m_pFillSymLib;

	UGMarkerSymbol* m_pMarkerSym;
	UGLineSymbol* m_pLineSym;
	UGFillSymbol* m_pFillSym;

	UGMarkerSymParam* m_pMarkerSymParam;
	UGFillSymParam* m_pFillSymParam;
	UGLineSymParam* m_pLineSymParam;
	
	UGint m_nDimension;
	UGPen* m_pCurPen;
	UGPen* m_pOldPen;
	UGBrush* m_pCurBrush;
	UGBrush* m_pOldBrush;
	UGFont* m_pCurFont;
	UGFont* m_pOldFont;
	UGColor m_crPrevForeColor;
	UGColor m_crPrevBackColor;
	UGint m_nPrevBkMode;
	UGint m_nPreAlign;
};

}

#endif // !defined(AFX_UGDRAWMAKER_H__D2C06D05_68DE_4883_B417_F9CB6685D2AE__INCLUDED_)
