// UGFractal.h: interface for the UGFractal class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGFRACTAL_H__32BD3F6D_DD5E_4A4B_AB33_C5C3E4C0391C__INCLUDED_)
#define AFX_UGFRACTAL_H__32BD3F6D_DD5E_4A4B_AB33_C5C3E4C0391C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Scene/UGPrerequisites.h"

namespace UGC
{

class SCENE_API UGFractal  
{
public:
	UGFractal();
	virtual ~UGFractal();
	static UGfloat Randnum (UGfloat min, UGfloat max);
	static UGfloat AvgEndpoints (UGint i, UGint stride, UGfloat *fa);
	static UGfloat AvgDiamondVals (UGint i, UGint j, UGint stride,
			     UGint size, UGint subSize, UGfloat *fa);
	static UGfloat AvgSquareVals (UGint i, UGint j, UGint stride, UGint size, UGfloat *fa);
	static UGint PowerOf2 (UGint size);
	static void Fill1DFractArray (UGfloat *fa, UGint size,
		       UGint seedValue, UGfloat heightScale, UGfloat h);
	static void Fill2DFractArray (UGfloat *fa, UGint size,
		       UGint seedValue, UGfloat heightScale, UGfloat h,UGfloat fCloudDensity=1.2);
	static UGfloat* Alloc1DFractArray (UGint size);
	static UGfloat* Alloc2DFractArray (UGint size);
	static void FreeFractArray (UGfloat *fa);

};

}

#endif // !defined(AFX_UGFRACTAL_H__32BD3F6D_DD5E_4A4B_AB33_C5C3E4C0391C__INCLUDED_)
