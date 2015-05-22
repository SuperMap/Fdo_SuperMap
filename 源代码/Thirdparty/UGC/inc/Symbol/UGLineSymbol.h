
//UGLineSymbol.h

#ifndef UG_LINESYMBOL_H
#define UG_LINESYMBOL_H

#include "UGSymbol.h"
#include "UGLineSymbolExt.h"
#include "UGLineSymbolBase.h"

namespace UGC {
	
	/** 线符号
	    @remarks
		    1。线符号由多个线基(LineBase，或称为基线)依次重叠组成；
			   这些线基由m_LineBases来组织管理
			2。同时线符号可以有一个线型扩展修饰符(LineSymbolExt)-->参见UGLineSymbolExt
			   线型扩展中记录了若干个位置的token修饰符信息
	*/
class SYMBOL_API UGLineSymbol : public UGSymbol
{
public:
	UGLineSymbol();
	virtual ~UGLineSymbol();
	
	UGLineSymbol(const UGLineSymbol& rhs);
	UGLineSymbol& operator = (const UGLineSymbol& rhs);
	
public:
	virtual UGbool Load(UGStream& stream, UGuint nVersion = 0);
	virtual UGbool Save(UGStream& stream, UGuint nVersion = 0) const;	
	
	//! 绘制函数一(绘制一条折线)
	void DrawPolyline(UGGraphics& graphics, const UGPoint* pPoints, UGint nCount, UGLineSymParam& DrawingParam);
	//! 绘制函数二(同时绘制多条折线)
	void DrawPolyPolyline(UGGraphics& graphics, const UGPoint* pPoints, 
		const UGint* pPntCounts, UGint nLineCount, UGLineSymParam& DrawingParam);	
	
	UGbool Merge(const UGLineSymbol& rhs);
	
	const UGLineSymbolExt& GetExtToken() const;
	UGLineSymbolExt& GetExtToken();
	void SetExtToken(const UGLineSymbolExt& extToken);
	
	UGint GetCountOfLineBase() const;
	UGLineSymbolBase* GetLineBaseAt(UGint nIndex) const;
	void AddLineBase(UGLineSymbolBase* pLineSymBase);
	void InsertLineBaseAt(UGint nIndex, UGLineSymbolBase* pLineSymBase);
	UGint RemoveLineBaseAt(UGint nIndex, UGint nCount = 1);
	void RemoveAllLineBase();
	
	UGbool MoveTo(UGint nIndexFrom, UGint nIndexTo);
	UGbool MoveBottom(UGint nIndex);
	UGbool MoveDown(UGint nIndex);
	UGbool MoveUp(UGint nIndex);
	UGbool MoveTop(UGint nIndex);

	UGbool CanProcessCrossroad();

protected:
	//! 光栏法重采样去点
	UGbool LampHouseSmooth(const UGPoint* lpPoints, UGint nCount, UGdouble dTolerance, UGPoints &arrPoints);

	
protected:
	//! 扩展修饰符
	UGLineSymbolExt m_ExtToken;

	//! 该线符号的基线存储管理器
	UGArray<UGLineSymbolBase*> m_LineBases;
};

}

#endif

