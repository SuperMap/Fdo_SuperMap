// FillSymbolManager.h: interface for the FillSymbolManager class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FILLSYMBOLMANAGER_H__609CC082_7CA1_4601_B1F7_3E6ED9567737__INCLUDED_)
#define AFX_FILLSYMBOLMANAGER_H__609CC082_7CA1_4601_B1F7_3E6ED9567737__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Wrapj/UJImage.h"
#include "Wrapj/SuperMapStubH.h"

class FillSymbolManager  
{
public:
	FillSymbolManager();
	virtual ~FillSymbolManager();
	
	void Release();
	void Line(UGint X1, UGint Y1, UGint X2, UGint Y2);
	void Arc(UGint x1,UGint y1,UGint x2,UGint y2,UGint x3,UGint y3,
		UGint x4,UGint y4);
	void Ellipse(UGint x1, UGint y1, UGint x2, UGint y2,UGbool fill);
	void Rectangle(UGint x1, UGint y1, UGint x2, UGint y2,UGbool fill);
	void Polygon(UGArray<UGint> points,UGint count,UGbool fill);
	
public:
	UGArray<UGint> m_nXAndY;

};
FillSymbolManager * GetFillSymbolManager();
#endif // !defined(AFX_FILLSYMBOLMANAGER_H__609CC082_7CA1_4601_B1F7_3E6ED9567737__INCLUDED_)
