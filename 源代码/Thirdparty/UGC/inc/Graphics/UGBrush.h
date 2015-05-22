// UGBrush.h: interface for the UGBrush class.
//
//////////////////////////////////////////////////////////////////////

/*!
   **************************************************************************************
    \file     UGBrush.h 
   **************************************************************************************
    \author   张艳良、陈国雄
    \brief    画刷基类                                                                       
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2005 SuperMap GIS Technologies,Inc.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-06-09  陈国雄    初始化版本.                                       <br>
   **************************************************************************************
*/

#if !defined(AFX_UGBRUSH_H__B12A270F_FBBC_4892_BC1C_F65122F24B83__INCLUDED_)
#define AFX_UGBRUSH_H__B12A270F_FBBC_4892_BC1C_F65122F24B83__INCLUDED_

#include "Algorithm/UGSize.h"

namespace UGC
{

class UGImage;

class GRAPHICS_API UGBrush  
{
public:
	enum BrushStyle
	{
		//! \brief Windows支持的画刷类型
		BrushSolid = 0,			//! \brief 实填充画刷
		BrushNull = 1,			//! \brief 无画刷

		BrushDownward = 2,		//! \brief ///// 
		BrushCross = 3,			//! \brief +++++ 
		BrushCross45 = 4,		//! \brief xxxxx 
		BrushUpward = 5,		//! \brief \\\\\ 

		BrushHorizontal = 6,	//! \brief ----- 
		BrushVertical = 7,		//! \brief ||||| 
		
		BrushTile = 8,			//! \brief 填充图片
		//! \brief gradient
		BrushGradientLinear = 10, //! \brief 斜直线
		BrushGradientRadial = 11, //! \brief 斜射线
		BrushGradientConical = 12,//! \brief 斜锥线
		BrushGradientSquare = 13  //! \brief 斜方线
	};

	struct UGBrushData              //! \brief 画刷的属性
	{   
		UGint nStyle;               //! \brief 画刷的形状
		UGColor clrColor;           //! \brief 画刷的颜色
		UGint nOpacity;             //! \brief 画刷是否透明
		UGint nGradientAngle;       //! \brief 画刷的渐进角度
		UGSize szGradientOffset;    //! \brief 画刷的渐进填充的偏移量
		UGImage* pImage;            //! \brief 画刷的填充图片   

		UGBrushData()               //! \brief 默认的画刷的属性
		{
			nStyle = BrushSolid; 
			clrColor = UGRGB(255,255,255); 
			nOpacity = 100;
			nGradientAngle = 0;
			szGradientOffset = UGSize(0,0);
			pImage = NULL;
		}
	};

protected:
	UGBrush();
public:
	virtual ~UGBrush();
	
	//! \brief 创建一个UGBrush对象
	virtual UGbool Create() = 0;
	//! \brief 创建一个UGBrush对象
	//! \param BrushData 包含画刷里面的属性列表.
	virtual UGbool Create(const UGBrushData& BrushData) = 0;
	//! \brief 创建一个UGBrush对象
	//! \param nStyle 画刷的类型 ,实线,虚线
	//! \param clrColor 画刷的颜色.
	//! \param nOpacity 画刷是否透明
	//! \param nGradientAngle 画刷的渐进角度
	//! \param szGradientOffset 画刷的渐进填充的偏移量
	//! \param pImage 画刷的填充图片
	virtual UGbool Create(UGint nStyle, UGColor clrColor, 
						UGint nOpacity = 100,
						UGint nGradientAngle = 0,
						UGSize szGradientOffset = UGSize(0, 0),
						UGImage* pImage = NULL) = 0;
	
	//! \brief 删除字体
	virtual void DeleteObject() = 0;
	//! \brief 获取BrushData对象
	//! \param BrushData 返回的的BrushData对象
	virtual void GetBrushData(UGBrushData& BrushData);			

	//! \brief 获取画刷的填充模式
	virtual UGint GetStyle() const;
	//! \brief 设置画刷的填充模式
	//! \param nBrushStyle 画刷的填充模式
	virtual void SetStyle(UGint nBrushStyle);		
	//! \brief 获取画刷的颜色
	virtual UGColor GetColor() const;
	//! \brief 设置画刷的颜色
	//! \param clrColor 画刷的颜色
	virtual void SetColor(UGColor clrColor);
    //! \brief 获取画刷的填充图片
	virtual UGImage* GetImage() const;
	//! \brief 设置画刷的填充图片
	//! \param pImage 填充的图片
	virtual void SetImage(UGImage* pImage);

	//! \brief 获取画刷的不透明度
	virtual UGint GetOpacity() const;
	//! \brief 设置画刷的不透明度
	//! \param nOpacity 画刷的透明度
	virtual void SetOpacity(UGint nOpacity);	
	//! \brief 获取渐进角度
	virtual UGint GetGradientAngle() const;
	//! \brief 设置渐进角度
	//! \param nAngle 渐进角度
	virtual void SetGradientAngle(UGint nAngle);	
	//! \brief 获取渐进填充的偏移量
	virtual UGSize GetGradientOffset() const;
	//! \brief 设置渐进填充的偏移量
	//! \param offset 渐进填充的偏移量
	virtual void SetGradientOffset(const UGSize& offset);
	
	//! \brief 获取实际对象
	void* GetNative() const;
	//! \brief 设置实际对象
	//! \param pNative 实际对象
	void SetNative(void* pNative);
	//! \brief 获取显示引擎类型
	virtual UGint GetGraphicsType();
	
protected:
	UGBrushData m_BrushData;
	void *m_pNative;
	UGint m_nGraphicsType;	
};
}
#endif // !defined(AFX_UGBRUSH_H__B12A270F_FBBC_4892_BC1C_F65122F24B83__INCLUDED_)
