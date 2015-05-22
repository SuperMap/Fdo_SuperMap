// UGMarkerSymbol.h

#ifndef UGMARKERSYMBOL_H
#define UGMARKERSYMBOL_H

#include "Base/UGArray.h"

#include "UGSymbol.h"
#include "UGSymPoint.h"
#include "UGMarkerSymParam.h"	//在该头文件中包含它，是为了其他工程使用时的方便
								//因为使用UGMarkerSymbol时通常都会使用UGMarkerSymParam
#include "UGMarkerSymStroke.h"     // 组成点符号的笔画Stroke

namespace UGC {


class UGGraphics;
//class UGMarkerSymStroke;

/** UGMarkerSymbol 点符号
	@remarks
		1。一个点符号是由多个笔画(Stroke)组成的；
		2。点符号有自己的局部坐标系(网格坐标)，参见UGSymPoint中的说明;
*/
class SYMBOL_API UGMarkerSymbol : public UGSymbol
{
public:
	UGMarkerSymbol();
	UGMarkerSymbol(UGint id);
	virtual ~UGMarkerSymbol();

	UGMarkerSymbol(const UGMarkerSymbol& rhs);
	virtual UGMarkerSymbol& operator = (const UGMarkerSymbol& rhs);
	
public:
	//! 从父类继承而来的读写功能函数
	virtual UGbool Load(UGStream& stream, UGuint nVersion = 0);
	virtual UGbool Save(UGStream& stream, UGuint nVersion = 0) const;

protected:
	//! UGC第一版本
	UGbool Load_Version2005(UGStream& stream);
	UGbool Save_Version2005(UGStream& stream) const;

	//! \brief 读取得到符号库中的数据、信息。
	/**
	\param stream  符号库文件的数据流信息[in]
	\return 读取是否成功。
	\remarks UGC第二版本，同第一版本相比基本相同，只是多了一个是否固定符号宽度的数据信息m_bPenFixedWidth的读取。
	*/
	UGbool Load_Version2007(UGStream& stream);
	//! \brief 保存符号信息保存到流文件中。
	/**
	\param stream  符号库文件的数据流信息[out]
	\return 保存是否成功。
	\remarks UGC第二版本，同第一版本相比基本相同，只是多了一个是否固定符号宽度的数据信息m_bPenFixedWidth的保存。
	*/
	UGbool Save_Version2007(UGStream& stream) const;

	//! SFC5.0版本
	UGbool Load_Version2003(UGStream& stream);
	UGbool Save_Version2003(UGStream& stream) const;

public:
	void Draw(UGGraphics& Graphics, UGMarkerSymParam& SymParam) const;
	UGbool HitTest(const UGPoint& pntHitTest,
			       UGMarkerSymParam& SymParam,
				   UGint nTolerance) const;
	
	/** 判断点符号是否为栅格符号(其笔划中有Bitmap或Icon类型的笔划) */
	UGbool IsRaster() const;

	/** 将symSource合并到该符号中
		即：将symSource中的所有的笔划复制到该符号中
	*/
	UGbool Merge(const UGMarkerSymbol& symSource);
	
	UGint GetDefaultSize() const;
	void SetDefaultSize(UGint nDefaultSize);
	
	UGSymPoint GetOrgPoint() const;
	void SetOrgPoint(const UGSymPoint& symPoint);

	//! \brief 点符号绘制时得到是否固定符号宽度信息。
	/**
	得到是否固定画笔，实现符号宽度的固定。
	*/
	UGbool IsFixedPenWidth() const;
	//! \brief 点符号绘制时设置是否固定符号宽度。
	/**
	设定是否固定符号宽度，实现在放大缩小时符号宽度固定不变。
	\param bFixed  是否固定符号宽度[in]
	*/
	void SetFixedPenWidth(UGbool bFixed);
	
	//----与笔画Stroke相关的操作------
	UGbool IsEmpty() const;
	UGint GetCountOfStrokes() const;
	void  Add(UGMarkerSymStroke* pSymStroke);
	UGMarkerSymStroke* GetAt(UGint nIndex) const;
	void  InsertAt(UGint nIndex, UGMarkerSymStroke* pSymStroke);

	//从管理列表中清除，同时负责释放内存空间
	UGint RemoveAt(UGint nIndex, UGint nCount = 1);
	void RemoveAll();
	void MakeDefault();
	
	//! \brief 计算符号的范围（在0-255的坐标系内）added by dongfei 2007-03-29
	void CalcSymRect(UGRect* pRect);
	//! \brief 根据符号的缩放比例系数计算(255,255)范围的缩放比例系数
	//added by dongfei 2007-03-29
	void SymBacktoBounds(UGdouble &dScale,UGdouble &dScaleX);
	//! \brief 计算符号的范围（设备坐标）
	//added by xielin 2007-07-20
	UGRect CalBounds(const UGPoint &pntAnchor,UGdouble dSize);

protected:
	// 将逻辑坐标LogPt转换为点符号的定义坐标系中的坐标SymPt( 用于HitTest )
	void LogPt2SymPt(const UGPoint& LogPt, UGPoint& SymPt, UGMarkerSymParam& SymParam)const;
	
protected:
	//! 缺省的大小
	UGint      m_nDefaultSize;
	//! 原点
	UGSymPoint m_pntOrg;
	//! \brief 保存是否固定符号宽度。
	/**
	\remarks 默认为false，不固定。
	*/
	UGbool m_bPenFixedWidth;

	//! 组成点符号的笔画Stroke
	UGArray<UGMarkerSymStroke*> m_Strokes;
};

}

#endif

