
// UGLineSymbolLib.h

#ifndef UGLINESYMBOLLIB_H
#define UGLINESYMBOLLIB_H

#include "UGSymbolLib.h"
#include "UGLineSymbol.h"
#include "UGMarkerSymbolLib.h"

namespace UGC 
{
	
	/** 线符号库
	*/
class SYMBOL_API UGLineSymbolLib : public UGSymbolLib 
{
public:
	UGLineSymbolLib();
	virtual ~UGLineSymbolLib();
	
	virtual UGbool Load(UGStream& stream);	
	virtual UGbool Append(UGStream& stream, UGbool bReplace = true);
	virtual UGbool Save(UGStream& stream, UGuint nVersion = 0) const;
	
	void SetResMarkerSymLib(UGMarkerSymbolLib* pResSymLib);
	UGMarkerSymbolLib* GetResMarkerSymLib() const;
	UGMarkerSymbolLib* GetMarkerSymLib();
	
protected:
	//! 资源中的点符号库的指针
	UGMarkerSymbolLib* m_pResSymLib;
	
	//! 该线符号库中要使用到的点符号库(用于线符号的自定义扩展符号)
	UGMarkerSymbolLib m_MarkerSymLib;
};
	
}

#endif


