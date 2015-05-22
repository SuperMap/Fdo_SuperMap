// UGXGraphicsFactory.h: interface for the UGXGraphicsFactory class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGXGRAPHICSFACTORY_H__59D2A89E_17E6_4842_B96F_41E61EFE6ABF__INCLUDED_)
#define AFX_UGXGRAPHICSFACTORY_H__59D2A89E_17E6_4842_B96F_41E61EFE6ABF__INCLUDED_

#include "Graphics/UGGraphicsFactory.h"

namespace UGC
{

extern "C" XGRAPHICS_API UGGraphicsFactory * CreateGraphicsFactory();

class XGRAPHICS_API UGXGraphicsFactory : public UGGraphicsFactory  
{
public:
	UGXGraphicsFactory();
	virtual ~UGXGraphicsFactory();

public:
	virtual UGint GetType();
	virtual UGString GetName();
	virtual UGGraphics* NewGraphics();
	virtual UGBrush* NewBrush();
	virtual UGFont* NewFont();
	virtual UGImage* NewImage();
	virtual UGPen* NewPen();
	virtual UGRgn* NewRgn();

};

}

#endif // !defined(AFX_UGXGRAPHICSFACTORY_H__59D2A89E_17E6_4842_B96F_41E61EFE6ABF__INCLUDED_)
