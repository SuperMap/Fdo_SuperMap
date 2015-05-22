// UGColorValue.h: interface for the UGColorValue class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGCOLORVALUE_H__77F37090_FF08_46BD_9EEB_312314BBBD47__INCLUDED_)
#define AFX_UGCOLORVALUE_H__77F37090_FF08_46BD_9EEB_312314BBBD47__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Scene/UGPrerequisites.h"


namespace  UGC 
{
typedef UGuint RGBA;
typedef UGuint ARGB;
typedef UGuint ABGR;

class SCENE_API UGColorValue  
{
public:
	static UGColorValue Black;
	static UGColorValue White;
	static UGColorValue Red;
	static UGColorValue Green;
	static UGColorValue Blue;
	
	UGColorValue(UGuint color);
	UGColorValue( UGReal red = 1.0f,
				    UGReal green = 1.0f,
					UGReal blue = 1.0f,
					UGReal alpha = 1.0f ) : r(red), g(green), b(blue), a(alpha)
	{ }		
	UGbool operator==(const UGColorValue& rhs) const;
	UGbool operator!=(const UGColorValue& rhs) const;
	
	UGReal r,g,b,a;
	
	/** Retrieves colour as RGBA.
	*/
	RGBA GetAsLongRGBA(void) const;
		// malq-2007-11-22-注意，该函数传入的每个变量是0-255
	void SetValue(UGint nRed,UGint nGreen,UGint nBlue,UGint nAlpha);
	// malq-2007-11-22-注意，得到的是长度为4的整形数组，分别表示R,G,B,A并且每个得值范围为0-255
	void GetRGBA(UGint& nRed,UGint& nGreen,UGint& nBlue,UGint& nAlpha) const;
	
 
	
	/** Retrieves colour as ARGB.
	*/
	ARGB GetAsLongARGB(void) const;
	
	/** Retrieves colours as ABGR */
	ABGR GetAsLongABGR(void) const;
	
	ABGR GetAsCOLORREF(void)const;

};
}
#endif // !defined(AFX_UGCOLORVALUE_H__77F37090_FF08_46BD_9EEB_312314BBBD47__INCLUDED_)
