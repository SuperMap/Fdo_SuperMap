
//UGLineSymbolBase.h

#ifndef UG_LINESYMBOLBASE_H
#define UG_LINESYMBOLBASE_H

#include "UGLineSymParam.h"
#include "UGLineSymBaseData.h"
#include "UGLineSymbolBaseDrawer.h"

namespace UGC 
{
class UGGraphics;
class UGPointSymbolLib;
	
	/** 线型的线基(或称为基线、子线)
	    @remarks
		   1。一个线型由若干个基线组成，基线是构成线型的基本单元；
		   2。基线由一系列的参数来描述，绘图时由这些参数来控制；
		   3。基线中有个重要的概念：虚实模式长度，用来控制
		      虚实模式：由2部分组成：实部分+虚部分，
			  他们的长度由虚部分的长度和实部分的长度来指定
	*/
class SYMBOL_API UGLineSymbolBase
{

public:
	/** 虚实模式对, 记录实、虚两部分的模式长度，两部分总是成对出现
	   @note
	*/
	struct ModeLenPair
	{
		UGushort m_SolidPartLen;  //实部分的长度
		UGushort m_EmptyPartLen;  //虚部分的长度
	};

public:
	UGLineSymbolBase();
	~UGLineSymbolBase();
	//UGLineSymbolBase(const UGLineSymbolBase& LineSymbolBase);
	//void operator = (const UGLineSymbolBase& LineSymbolBase);

public:
	//! 基线绘制器，UGLineSymbolBase的绘制主函数将绘制任务委托给UGLineSymbolBaseDrawer来实现
	friend class UGLineSymbolBaseDrawer;
	
public:
	UGbool Load(UGStream& stream, UGuint nVersion = 0);
	UGbool Save(UGStream& stream, UGuint nVersion = 0) const;
	
	//! 主绘制接口 用该线型去绘制由pPoints指定的折线
	void Draw(UGGraphics& graphics, 
			  const UGPoint* pPoints,
			  UGint nCount, 
			  UGLineSymParam& DrawingParam);
	
	void Reset();
	
	//{{------------虚实模式长度(ModeLen)管理函数--------------------------
	UGint GetCountOfModeLens() const;
	const UGushort* GetModeLenData() const;
	void  RemoveModeLenAt(UGint nIndex);
	void  RemoveAllModeLens();
	void    GetModeLenAt(UGint nIndex, UGint& nSolidModeLen, UGint& nEmptyModeLen);
	void    SetModeLenAt(UGint nIndex, UGint nSolidModeLen, UGint nEmptyModeLen);
	void      AddModeLen(UGint nSolidModeLen, UGint nEmptyModeLen);
	void InsertModeLenAt(UGint nIndex, UGint nSolidModeLen, UGint nEmptyModeLen);
	//! \brief 线型绘制时设置完整显示虚实部。
	/**
	设定是否完整显示虚实部，在放大缩小时都能完整显示线型。
	\param bFixed  是否完整显示虚实部[in]
	\remarks 默认下绘制线型会采用此方法。
	*/
	void SetCycleChange (UGbool bFixed);
	//! \brief 线型绘制时是否完整显示虚实部。
	/**
	得到是否完整显示虚实部。
	\return 是否完整显示虚实部，1代表是，0代表否，默认为1。
	*/
	UGbool IsCycleChange() const;
	//}}------------虚实模式长度管理函数--------------------------
	
	const UGLineSymBaseData& GetLineSymBaseData() const;
	void SetLineSymBaseData(const UGLineSymBaseData& LineSymBaseData);

public:
	//! 是否是字型符号风格
	UGbool IsCharacterStyle() const;

	//! 返回基线的风格类型
	UGLineSymBaseData::StyleType GetStyleType()
	{
		return m_LineSymBaseData.GetStyleType();
	}

	//! 是否需要偏移
	UGbool IsNeedOffset()
	{
		return IsNeedVertOffset() || IsNeedHoriOffset();
	}

	//! 是否需要纵向偏移
	UGbool IsNeedVertOffset()
	{
		return m_LineSymBaseData.GetVertOffset() != 0 ;
	}

	//! 是否需要横向偏移
	UGbool IsNeedHoriOffset()
	{
		return  m_LineSymBaseData.GetHoriOffset() != 0 ;
	}

	UGbool IsSolidPartStarted() const
	{
		return m_bWhichPartStarted;
	}

	void SetWhichPartStarted(UGbool bWhichPart)
	{
		// bWhichPart == TRUE  -->实部开始
		// bWhichPart == FALSE -->虚部开始
		m_bWhichPartStarted = bWhichPart;
	}

	UGLineSymBaseData m_LineSymBaseData;

protected:
	UGbool Load_Version2003(UGStream& stream);
	UGbool Load_Version2005(UGStream& stream);
	UGbool Save_Version2003(UGStream& stream)const;
	UGbool Save_Version2005(UGStream& stream)const;
	
protected:
	
	//! True：实部开始绘制，False：虚部开始绘制
	UGbool  m_bWhichPartStarted;

	//! 该基线的虚实模式的长度
	UGArray<ModeLenPair>  m_ModeLengths;

	//! 基线的绘制器(绘制引擎，系统中共享一个)，绘制Polyline时，由该绘制器来完成绘制
	static UGLineSymbolBaseDrawer m_Drawer;
	//! \brief 保存是否完整显示虚实部信息。
	/**
	\remarks 默认为1。
	*/
	UGbool m_bCycleChange;
};

}

#endif

