// UGNode.h: interface for the UGNode class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(UGNODE_H)
#define UGNODE_H
#include "Graphics3D/UGGraphics3DHeaders.h"
#include "Base/UGString.h"
#include "Graphics3D/UGBoundSphere.h"
namespace UGC
{
class UGGroup;
class UGNodeVisitor;
class UGNodeCallback;
class UGMaterial;
class GRAPHICS3D_API UGNode  
{
public:
	UGNode();
	virtual ~UGNode();
public:

	typedef UGArray<UGGroup*> ParentList;
	inline UGString& GetName();
	inline UGString SetName(const UGString* strName);
	inline const UGBoundSphere& GetBound() const
	{
		if(m_bBoundsDirty)
		{
			ComputeBounds();
		}
		return m_BoundSphere;
	}

	inline const ParentList& GetParents()const;
	inline ParentList& GetParents();
	inline UGGroup* GetParent(unsigned int i);
	inline unsigned int GetNumParents() const;

	virtual void Accept(UGNodeVisitor& nv);
	virtual void Ascend(UGNodeVisitor& nv);
	virtual void Traverse(UGNodeVisitor& /*nv*/) {}
	

	void SetUpdateCallback(UGNodeCallback* pUpdateCallback);
	inline UGNodeCallback* GetUpdateCallback();
	inline const UGNodeCallback* GetUpdateCallback() const;

	void SetCullCallback(UGNodeCallback* nc);
	inline UGNodeCallback* GetCullCallback();
	
	inline const UGNodeCallback* GetCullCallback() const;

	UGMaterial* GetOrCreateMaterial();
	UGMaterial* GetMaterial();

protected:
	virtual UGbool ComputeBounds()const{return FALSE;};	
	UGString m_strName;
	mutable UGBoundSphere m_BoundSphere;
	UGMaterial* m_pMaterial;
	ParentList m_Parents;
	UGbool m_bBoundsDirty;	
};
typedef UGArray<UGNode*> NodePath;
}

#endif // !defined(UGNODE_H)
