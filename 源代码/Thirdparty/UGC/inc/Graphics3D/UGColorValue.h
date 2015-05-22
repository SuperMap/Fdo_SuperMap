// UGColorValue.h: interface for the UGColorValue class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(UGCOLORVALUE_H)
#define UGCOLORVALUE_H
#include "Graphics3D/UGGraphics3DHeaders.h"
#include "Base/UGString.h"
namespace UGC{
class GRAPHICS3D_API UGColorValue  
{
public:
	static UGColorValue Black;
	static UGColorValue White;
	static UGColorValue Red;
	static UGColorValue Green;
	static UGColorValue Blue;
	UGColorValue( Real red = 1.0f,
				    Real green = 1.0f,
					Real blue = 1.0f,
					Real alpha = 1.0f ) : r(red), g(green), b(blue), a(alpha)
	{ }
	UGColorValue(UGColor color);
	
	bool operator==(const UGColorValue& rhs) const;
	bool operator!=(const UGColorValue& rhs) const;
	
	Real r,g,b,a;
	
	/** Retrieves colour as RGBA.
	*/
	UGColor GetAsLongRGBA(void) const;
	
	/** Retrieves colour as ARGB.
	*/
	UGColor GetAsLongARGB(void) const;
	
	/** Retrieves colours as ABGR */
	UGColor GetAsLongABGR(void) const;
	
	//special for win32
	UGColor GetAsCOLORREF(void)const;
	
	//store stuff related
	UGString CoverToString()const; 
};

typedef UGArray<UGColorValue> UGColorArray;
}

#endif // !defined(AFX_UGCOLORVALUE_H__FBE9CA2A_7848_4976_B86A_0F9390D5F708__INCLUDED_)
