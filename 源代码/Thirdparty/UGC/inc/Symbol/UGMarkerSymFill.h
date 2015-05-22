
/*!
   **************************************************************************************
    \file     UGMarkerSymFill.h
   **************************************************************************************
    \author   陈国雄
    \brief    点状符号填充类                                                         
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2005 SuperMap GIS Technologies,Inc.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-05-23  陈国雄    初始化版本.                                       <br>
   **************************************************************************************
*/

#ifndef UGMARKERSYMFILL_H
#define UGMARKERSYMFILL_H

#include "UGMarkerSymbolLib.h"
#include "UGFillSymParam.h"
#include "Graphics/UGGraphics.h"

namespace UGC {

class SYMBOL_API UGMarkerSymFill  
{
public:
	UGMarkerSymFill();
	~UGMarkerSymFill();
	UGMarkerSymFill(const UGMarkerSymFill& MarkerSymFill);
	UGMarkerSymFill& operator = (const UGMarkerSymFill& MarkerSymFill);

public:
	UGbool Load(UGStream& stream);
	UGbool Save(UGStream& stream) const;
	UGImage* Render(UGGraphics& graphics, UGFillSymParam& FillSymParam, UGint nRenderImageType)const;

	UGint GetWidth() const;
	void SetWidth(UGint nWidth);
	
	UGint GetHeight() const;
	void SetHeight(UGint nHeight);
	
	UGint GetMarkerSymID() const;
	void SetMarkerSymID(UGint nMarkerSymID);
	
	UGdouble GetMarkerSymSize() const;
	void SetMarkerSymSize(UGdouble dMarkerSymSize);
	
	UGdouble GetMarkerSymAngle() const;
	void SetMarkerSymAngle(UGdouble dMarkerSymAngle);

	UGint GetPointCount() const;
	void AddPoint(const UGPoint& point);
	void AddPoints(const UGArray<UGPoint>& arrPoints);
	void InsertPoint(UGint nIndex, const UGPoint& point);
	void InsertPoints(UGint nIndex, const UGArray<UGPoint>& arrPoints);
	void RemoveAllPoints();
	UGint RemovePoint(UGint nIndex, UGint nCount = 1);
	UGint GetSpace() const;

protected:
	UGint m_nWidth;
	UGint m_nHeight;
	UGint m_nMarkerSymID;
	UGint m_nMarkerSymSize;
	UGint m_nMarkerSymAngle;
	UGArray<UGPoint> m_Points;
};

}

#endif



