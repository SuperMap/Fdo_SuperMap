// UGGraphics3DManager.h: interface for the UGGraphics3DManager class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(UGGRAPHICS3DMANAGER_H)
#define UGGRAPHICS3DMANAGER_H
#include "Graphics3D/UGGraphics3DHeaders.h"
#include "Base/UGString.h"

namespace UGC{
class UGGraphics3DFactory;
class UGGraphics3D;
class GRAPHICS3D_API UGGraphics3DManager  
{
public:
	enum Graphics3DType
	{
		OGL = 0,
		D3D = 1
	};
	struct UGGraphics3DDefine
	{
		void* hHandle;
		UGGraphics3DFactory *pGraphicsFactory;
		UGString strName;
		Graphics3DType nGraphicsType;
		
		UGGraphics3DDefine()
		{		
			nGraphicsType = OGL;
			pGraphicsFactory = NULL;
			hHandle = NULL;
			strName = ("");
		}
	};
public:
	UGGraphics3DManager();
	virtual ~UGGraphics3DManager();
public:
	static UGbool SetCurGraphicsType(UGint nGraphicsType);
	static UGString GetGraphicsName(UGint nGraphicsType);
	static UGGraphics3D* CreateGraphics3D(UGint nGraphicsType = OGL);

private:
	UGGraphics3DDefine* CheckGraphicsDefine(void* hHandle);
	UGGraphics3DDefine* Find(UGint nGraphicsType);
	// 装载和卸载 实际显示引擎
	void LoadGraphics();
	void UnloadGraphics();	
	
private:
	UGArray<UGGraphics3DDefine*> m_GraphicsDefines;
	Graphics3DType m_nCurGraphicsType; 	
};
extern GRAPHICS3D_API UGGraphics3DManager g_Graphics3DManager;

}
#endif // !defined(UGGRAPHICS3DMANAGER_H)
