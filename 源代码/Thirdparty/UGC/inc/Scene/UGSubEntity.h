// UGSubEntity.h: interface for the UGSubEntity class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGSUBENTITY_H__0905FDE1_DFA3_4807_AF48_38688B9520CC__INCLUDED_)
#define AFX_UGSUBENTITY_H__0905FDE1_DFA3_4807_AF48_38688B9520CC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Scene/UGPrerequisites.h"
#include "Scene/UGRenderable.h"

namespace UGC
{
class SCENE_API UGSubEntity : public UGRenderable 
{
friend class UGEntity;
public:
	UGSubMesh* GetSubMesh(void);
public:

	UGSubEntity(UGEntity* parent, UGSubMesh* subMeshBasis);
	virtual ~UGSubEntity();
	
	UGString GetMaterialName() const;
	void SetMaterialName( const UGString& name );
	virtual void SetVisible(UGbool visible);
	virtual UGbool IsVisible(void) const;
	
	UGMaterial* GetMaterial(void) const;
	void GetRenderOperation(UGRenderOperation& op);
	void GetWorldTransforms(UGMatrix4d* xform) const;
	UGQuaternion4d GetWorldOrientation(void) const;
	UGVector3R GetWorldPosition(void) const;
	UGbool GetNormaliseNormals(void) const; 
	UGushort GetNumWorldTransforms(void) const;
	UGReal GetSquaredViewDepth(UGCameraBase* cam) const;
	UGLightList GetLights(void) const;
	UGVertexData* GetVertexDataForBinding(void);
	
public:
	UGEntity* GetParent(void) const { return m_ParentEntity; }
	
protected:
	UGEntity* m_ParentEntity;
	UGString m_strMaterialName;
	UGMaterial* m_pMaterial;
	UGSubMesh* m_SubMesh;
	UGbool m_bVisible;
	UGushort m_unMaterialLodIndex;
	
};
}
#endif // !defined(AFX_UGSUBENTITY_H__0905FDE1_DFA3_4807_AF48_38688B9520CC__INCLUDED_)
