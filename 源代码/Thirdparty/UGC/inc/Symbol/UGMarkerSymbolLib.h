
// UGMarkerSymbolLib.h

#ifndef UGMARKERSYMBOLLIB_H
#define UGMARKERSYMBOLLIB_H

#include "UGMarkerSymbol.h"
#include "UGSymbolLib.h"
#include "Graphics/UGGraphics.h"
#include "Base/UGStyle.h"

namespace UGC {

class SYMBOL_API UGMarkerSymbolLib : public UGSymbolLib
{
public:
	UGMarkerSymbolLib();
	virtual ~UGMarkerSymbolLib();

	virtual UGbool Load(UGStream& stream);	
	virtual UGbool Append(UGStream& stream, UGbool bReplace = true);
	virtual UGbool Save(UGStream& stream, UGuint nVersion = 0) const;
	
	//判断点符号是否为栅格
	UGbool IsRaster(UGint nID);
	UGMarkerSymbol* GetDefaultSymbol();

	UGbool Add(const UGString& strRasterFile, UGSymbolGroup *pSymbolGroup = NULL);
	UGbool Add(const UGString& strTTFontName, UGchar ch, UGSymbolGroup *pSymbolGroup = NULL, UGbool bConvertRegion = false);

private:
	UGMarkerSymbol m_DefaultSymbol;
};

}

#endif

