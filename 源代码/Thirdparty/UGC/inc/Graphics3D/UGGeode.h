// UGeode.h: interface for the UGeode class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(UGEODE_H_)
#define UGEODE_H_
#include "Graphics3D/UGGraphics3DHeaders.h"
#include "UGNode.h"
#include "UGBoundBox.h"

namespace UGC{

class GRAPHICS3D_API UGGeode :public UGNode
{
public:
	typedef UGArray<UGDrawable*>DrawableList;
public:
	UGGeode();
	virtual ~UGGeode();
	virtual UGbool AddDrawable(UGDrawable* pDrawable);
	virtual UGbool SetDrawable(UGint nIndex, UGDrawable* pDrawable);
	virtual UGint GetDrawableCount();
	virtual UGbool RemoveDrawable(UGDrawable* pDrawable);
	virtual UGbool RemoveDrawables(UGint nIndex, UGint nCount);
	virtual UGbool IsContainDrawable(UGDrawable* pDrawable);
	virtual UGBoundBox& GetBoundBox();

protected:
	virtual UGbool ComputeBounds();	
	DrawableList m_DrawableList;
	UGBoundBox m_bbBoundBox;
	

};
}
#endif // !defined(UGEODE_H_)
