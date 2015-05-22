// UGPen.h: interface for the UGPen class.
//
//////////////////////////////////////////////////////////////////////

/*!
   **************************************************************************************
    \file     UGPen.h   
   **************************************************************************************
    \author   张艳良、陈国雄
    \brief    画笔基类                                                               
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2005 SuperMap GIS Technologies,Inc.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-06-09  陈国雄    初始化版本.                                       <br>
   **************************************************************************************
*/

#if !defined(AFX_UGPEN_H__EBBA00AA_4E20_4A52_A2BD_B6EB9A207829__INCLUDED_)
#define AFX_UGPEN_H__EBBA00AA_4E20_4A52_A2BD_B6EB9A207829__INCLUDED_

#include "Base/ugdefs.h"
// 以下的宏定义在X11和UGC中可能会有冲突.
// 故取消宏定义, 直接使用数字.
#ifdef CapSquare
#undef CapSquare
#endif

#ifdef CapRound
#undef CapRound
#endif

#ifdef CapButt
#undef CapButt
#endif

#ifdef JoinRound
#undef JoinRound
#endif

#ifdef JoinMiter
#undef JoinMiter
#endif

#ifdef JoinBevel
#undef JoinBevel
#endif

namespace UGC
{

class GRAPHICS_API UGPen  
{
public:
	enum CapStyle				//! \brief 线段端口类型
	{
		CapRound = 0,			//! \brief 端口为圆形
		CapSquare = 1,			//! \brief 端口为正方形
		CapFlat = 2			    //! \brief 端口为平的		
	};
	enum JoinStyle
	{
		//! \brief 线段连接类型
		JoinRound = 0,			//! \brief 以round方式相交		
		JoinBevel = 1,			//! \brief 以bevel方式相交
		JoinMiter = 2			//! \brief 以miter方式相交
	};
	enum PenStyle
	{
		//! \brief Windows支持的画笔类型
		PenSolid = 0,			//! \brief 画笔为实线
		PenDash = 1,			//! \brief 画笔为虚短线
		PenDot = 2,				//! \brief 画笔为虚点线
		PenDashDot = 3,			//! \brief 由一个短线和一个点线为一个单元组成的虚线
		PenDashDotDot = 4,		//! \brief 由一个短线和两个点线为一个单元组成的虚线
		PenNull = 5				//! \brief 无画笔
	};
public:
	struct UGPenData            //! \brief 画笔的属性数据
	{		
		UGint nStyle;           //! \brief 画笔的类型
		UGint nWidth;           //! \brief 画笔的宽度
		UGColor clrColor;       //! \brief 画笔的颜色
		UGint nCapStyle;        //! \brief 线段的端口类型
		UGint nJoinStyle;       //! \brief 线段的相交类型
		UGPenData()
		{					
			nStyle = PenSolid;
			nWidth = 0;
			clrColor = UGRGB(0, 0, 0);
			nCapStyle = CapRound;
			nJoinStyle = JoinRound;
		}
	};

protected:
	UGPen();
public:
	virtual ~UGPen();
	
	//! \brief 创建一个UGPen对象
	virtual UGbool Create() = 0;
	//! \brief 创建一个UGPen对象
	//! \param 包含画刷的属性列表 
	virtual UGbool Create(const UGPenData& PenData) = 0;
	//! \brief 创建一个UGPen对象
	//! \param nStyle     画笔的类型
	//! \param nWidth     画笔的宽度
	//! \param clrColor   画笔的颜色
	//! \param nCapStyle  线段的端口类型
	//! \param nJoinStyle 线段的相交类型
	virtual UGbool Create(
					UGint nStyle,
					UGint nWidth = 0,
					UGColor clrColor = UGRGB(0, 0, 0),
					UGint nCapStyle = 0,
					UGint nJoinStyle = 0) = 0;
	
	//! \brief 删除字体
	virtual void DeleteObject() = 0;
	
	virtual void GetPenData(UGPenData& PenData);
		
	//! \brief 获取画笔类型(虚实模式)
	virtual UGint GetStyle() const;
	//! \brief 设置画笔类型(虚实模式)
	//! \param nPenStyle 画笔的类型(虚实模式)
	virtual void SetStyle(UGint nPenStyle);
	//! \brief 获取线宽
	virtual UGint GetWidth() const;
	//! \brief 设置线宽
	//! \param nLineWidth 线宽
	virtual void SetWidth(UGint nLineWidth);
	//! \brief 获取线颜色
	virtual UGColor GetColor() const;
	//! \brief 设置线颜色
	//! \param clrColor 线颜色
	virtual void SetColor(UGColor clrColor);
	//! \brief 获取接头样式
	virtual UGint GetCap() const;
	//! \brief 设置接头样式
	//! \param nCapStyle 接头的样式
	virtual void SetCap(UGint nCapStyle);	
	//! \brief 获取交接点样式
	virtual UGint GetJoin() const;
	//! \brief 设置交接点样式
	//! \param nJoinStyle 交接点的样式
	virtual void SetJoin(UGint nJoinStyle);	

	//! \brief 获取实际对象
	void* GetNative() const;
	//! \brief 设置实际对象
    //! \param pNative 实际对象
	void SetNative(void* pNative);
	//! \brief 获取显示引擎类型 
	virtual UGint GetGraphicsType();
	
protected:
	UGPenData m_PenData;
	void* m_pNative;

	UGint m_nGraphicsType;	
};

}
#endif // !defined(AFX_UGPEN_H__EBBA00AA_4E20_4A52_A2BD_B6EB9A207829__INCLUDED_)
