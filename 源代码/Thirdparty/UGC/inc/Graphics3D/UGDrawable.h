// UGDrawable.h: interface for the UGDrawable class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(UGDRAWABLE_H)
#define UGDRAWABLE_H
#include "Graphics3D/UGGraphics3DHeaders.h"
#include "Graphics3D/UGPrimitiveSet.h"
#include "Base/UGArray.h"
#include "Graphics3D/UGBoundSphere.h"

namespace UGC{
class UGGroup;
class GRAPHICS3D_API UGDrawable  
{
public:
	typedef UGArray<UGGroup*> ParentList;
	UGDrawable();
	virtual ~UGDrawable();
public:
	class UGDrawCallback
	{
		virtual void Draw(UGDrawable*) const {}
	};
	virtual void SetDrawCallback(UGDrawCallback* pDrawCallback){};
	virtual UGDrawCallback* GetDrawCallback(){return NULL;};

	class UGUpdateCallback
	{
		virtual void Update(UGDrawable*)const{};
	};
	virtual void SetUpdateCallback(UGUpdateCallback* pUpdateCallback){};
	virtual UGUpdateCallback* GetUpdateCallback(){return NULL;};

	class UGCullCallback
	{
		virtual void Cull(UGDrawable*)const{};
	};
	virtual void SetCullCallback(UGCullCallback* pCullCallback){};
	virtual UGCullCallback* GetCullCallback(){return NULL;};

	inline const ParentList& GetParents()const;
	inline ParentList& GetParents();
	inline UGGroup* GetParent(unsigned int i);
	inline unsigned int GetNumParents() const;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   

	UGMaterial* GetOrCreateMaterial();
	UGMaterial* GetMaterial();
	void ComputeBounds();

	virtual void Draw(UGGraphics3D* pGraphics3D) = 0;

protected:
	UGMaterial* m_pMaterial;
	ParentList m_pParents;
	UGBoundSphere m_BoundSphere;
	UGbool m_bBoundsDirty;
	UGDrawCallback* m_pDrawCallback;
	UGUpdateCallback* m_pUpdataCallback;
	UGCullCallback* m_pCullCallback;
};
}

#endif // !defined(UGDRAWABLE_H)
