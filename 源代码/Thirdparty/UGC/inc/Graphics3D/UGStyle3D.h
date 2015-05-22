// UGStyle3D.h: interface for the UGStyle3D class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(UGSTYLE3D_H)
#define UGSTYLE3D_H
#include "Graphics3D/UGGraphics3DHeaders.h"
#include "Graphics3D/UGMaterial.h"

namespace UGC{	
class GRAPHICS3D_API UGStyle3D  
{
public:
	UGStyle3D();
	virtual ~UGStyle3D();
	
	const UGColor& GetColor() const { return m_clrColor; }
	UGColor& GetColor() { return m_clrColor; }
	void SetColor(UGColor c) { m_clrColor=c; }
	
	const UGint& GetBrushStyle() const { return m_nBrushStyle; }
	UGint& GetBrushStyle() { return m_nBrushStyle; }
	void SetBrushStyle(UGint s) { m_nBrushStyle=s; }

	const UGint& GetPenStyle() const { return m_nPenStyle; }
	UGint& GetPenStyle() { return m_nPenStyle; }
	void SetPenStyle(UGint s) { m_nPenStyle=s; }
	
	const UGint& GetPenWidth() const { return m_nPenWidth; }
	UGint& GetPenWidth() { return m_nPenWidth; }
	void SetPenWidth(UGint w) { m_nPenWidth=w; }

	const UGint& GetSymbolStyle()const{return m_nSymbolStyle;}
	UGint& GetSymbolStyle(){return m_nSymbolStyle;}
	void SetSymbolStyle(UGint nStyle){m_nSymbolStyle = nStyle;}
	
protected:

	UGColor m_clrColor;
	UGint m_nBrushStyle;
	
	//! \brief 笔的风格
	UGint m_nPenStyle;
	//! \brief 笔的宽度
	UGint m_nPenWidth;

	//! \brief 符号的ID
	UGint m_nSymbolStyle;
};
}

#endif // !defined(AFX_UGSTYLE3D_H__454C72C9_3317_44DE_97C4_796B046E67A4__INCLUDED_)
