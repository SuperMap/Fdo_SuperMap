// UGRenderStage.h: interface for the UGRenderStage class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(UGRENDERSTAGE_H)
#define UGRENDERSTAGE_H
#include "Graphics3D/UGGraphics3DHeaders.h"
#include "Graphics3D/UGRenderBin.h"
#include "UGColorValue.h"
#include "Base/UGDict.h"
#include "UGMatrix4.h"
namespace UGC{
class UGLight;
class GRAPHICS3D_API UGRenderStage
{
public:
	typedef UGDict<UGint, UGRenderBin*>RenderBinList;	
public:
	UGRenderStage();
	virtual ~UGRenderStage();
	//! …Ë÷√Viewport
	void SetViewport(UGint nTop,UGint nLeft, UGint nWidth, UGint nHeight);
	void GetViewport(UGint& nTop,UGint& nLeft, UGint& nWidth, UGint& nHeight);
	void SetClearColor(UGColorValue& color);
	void SetClearDepth(UGdouble dDepth);
	
	void AddLight(UGMatrix4& matrix, UGLight* pLight);	

	void Draw(UGGraphics3D* pGraphics);

	UGRenderBin* CreateRenderBin(UGint nNum); 
	UGRenderBin* GetorCreateRenderBin(UGint nNum);
	UGRenderBin* GetRenderBin(UGint nNum);

	
protected:
	RenderBinList m_BinList;
	UGRenderBin* m_pParent;	
	UGint m_nBinNumber;	
	UGint m_nLeft;
	UGint m_nTop;
	UGint m_nWidth;
	UGint m_nHeight;
	UGColorValue m_ClearColor;
	UGdouble m_nClearDepth;
	UGDict<UGLight*,UGMatrix4>m_Lights;
};

}

#endif // !defined(AFX_UGRENDERSTAGE_H__FC699511_BAAB_413A_BB57_3AB60C72FA75__INCLUDED_)
