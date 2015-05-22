// UGPSGraphicsFactory.h: interface for the UGPSGraphicsFactory class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGPSGRAPHICSFACTORY_H__286758E1_BCEA_48EF_A921_9450A7337370__INCLUDED_)
#define AFX_UGPSGRAPHICSFACTORY_H__286758E1_BCEA_48EF_A921_9450A7337370__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Graphics/UGGraphicsFactory.h"

namespace UGC
{
extern "C" PSGRAPHICS_API UGGraphicsFactory * CreateGraphicsFactory();

class UGPSGraphicsFactory : public UGGraphicsFactory  
{
public:
	UGPSGraphicsFactory();
	virtual ~UGPSGraphicsFactory();
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
#endif // !defined(AFX_UGPSGRAPHICSFACTORY_H__286758E1_BCEA_48EF_A921_9450A7337370__INCLUDED_)
