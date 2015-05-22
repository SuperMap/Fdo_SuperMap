// UGLineSymParam.h:

#ifndef UG_LINESYMPARAM_H
#define UG_LINESYMPARAM_H

#include "Graphics/UGGraphics.h"

namespace UGC 
{
	
class UGLineSymbolBase;
class UGMarkerSymbolLib;

class UGPen;
class UGBrush;
class UGFont;
	
	/** 线型的显示参数，其中包括风格设置参数(颜色、线宽、缩放率) 
	    @remarks
	       从外部可以对线型进行一些风格设置，包括：
		   1. 线型颜色；
		   2. 线型宽度；
		   3. 缩放比例；
		   基线绘制时，根据这些风格参数来进行创建相应的画笔进行绘制；
		   注：如果线型内部已经固定了颜色或宽度，
		       在绘制时，就使用内部固定的颜色值或固定的宽度值;
			   就不采用这些外部设置的颜色或宽度；
	*/
class SYMBOL_API UGLineSymParam  
{
public:
	//! 基线绘制过程中，要使用到的GDI对象
	struct UGGraphicsObjects
	{
		UGGraphicsObjects();
		~UGGraphicsObjects();

		void  NewPen();
		void  NewBrush();
		void  NewFont();

		UGPen*   m_pOldPen;
		UGBrush* m_pOldBrush;
		UGFont*  m_pOldFont;

		//! UGC的虚拟引擎创建(new)出GDI对象，使用后需要自己来释放
		UGPen*   m_pNewPen;
		UGBrush* m_pNewBrush;
		UGFont*  m_pNewFont;

		UGint    m_nOldTxtAlign;
		UGint    m_nOldBkMode;
		UGColor  m_nOldTxtClr;
	};

public:
	UGLineSymParam();
	~UGLineSymParam();
	
public:
	void SetDefaultPen(UGPen* pDefaultPen);
	UGPen* GetDefaultPen() const;
	
	void SetPenWidth(UGint nPenWidth);
	UGint GetPenWidth() const;
	
	void SetPenColor(UGColor color);
	UGColor GetPenColor() const;
	
	void SetScale(UGdouble dScale);
	UGdouble GetScale() const;
	
	void SetHighlight(UGbool bHighlight = true);
	UGbool IsHighlight() const;

	UGPoints& GetPointsBuffer();
	
	UGMarkerSymbolLib* GetMarkerSymbolLib() const;
	void SetMarkerSymbolLib(UGMarkerSymbolLib *pMarkerSymLib);

	//! \brief 是否需要重新采样，主要用于绘制线型的时候
	UGbool IsNeedSampling();
	void   SetNeedSampling(UGbool bNeedSampling);

	UGGraphicsObjects& GetGraphicsObject();
	
	void Release();

	UGint m_nCrossroadIndex;
	
protected:
	//! 缺省画笔(由外部创建好传递进来的)
	UGPen*           m_pDefaultPen;

	//! 外部对线型设置的线颜色
	UGColor          m_PenClr;

	//! 外部对线型设置的线宽度
	UGint            m_nPenWidth;

	//! 线型符号缩放的比例
	UGdouble         m_dScale;

	//! 是否是高亮显示
	UGbool           m_bHighlight;

	//! 绘制线型时，是否要对折线顶点数据进行重采样
	UGbool           m_bNeedSampling;

	//! 内存缓冲区，被用于线型显示时临时缓存使用
	UGPoints m_PointBuf;
	
	//! 点符号库，仅用于线型的扩展符号中的自定义token(自定义token使用一个点符号来绘制)
	UGMarkerSymbolLib* m_pMarkerSymLib;

	//! 用于线型符号的基线绘制过程中记录新创建GDI对象和graphics选入新对象前的原来的old对象
	//! 静态成员变量，整个程序中共享一份就够了
	//modified by xielin 2007-12-27 现在要支持多线程，全局就不行了，改掉
	UGLineSymParam::UGGraphicsObjects ms_GObjects;

};
	
}

#endif
