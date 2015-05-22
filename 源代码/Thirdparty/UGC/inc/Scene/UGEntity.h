// UGEntity.h: interface for the UGEntity class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGENTITY_H__05F1D09B_F410_41A3_BC06_49E3D87E0461__INCLUDED_)
#define AFX_UGENTITY_H__05F1D09B_F410_41A3_BC06_49E3D87E0461__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Scene/UGPrerequisites.h"
#include "Scene/UGMovableObject.h"
#include "Scene/UGMatrix4d.h"


namespace UGC
{

class SCENE_API UGEntity : public UGMovableObject
{
friend class UGSubEntity;
public:
	typedef UGList<UGEntity*> EntitySet;
	typedef UGDict<UGString, UGMovableObject*> ChildObjectList;
	typedef UGList<UGSubEntity*> SubEntityList;
	typedef UGList<UGEntity*> LODEntityList;

public:
	UGEntity();
	UGEntity( const UGString& name, UGEntityMesh* mesh);
	virtual ~UGEntity();
	UGEntityMesh* GetMesh(void) const;
	UGSubEntity* GetSubEntity(UGuint index) const;
	UGSubEntity* GetSubEntity(const UGString& name) const;
	UGuint GetNumSubEntities(void) const;
	UGEntity* Clone(UGString& newName) const;
	void SetMaterialName(const UGString& name);
	void NotifyCurrentCamera(UGCameraBase* cam);
	UGString& GetMovableType(void) const;
	UGEntity* GetManualLodLevel(UGuint index) const;
	UGuint GetNumManualLodLevels(void) const;
	void SetMeshLodBias(UGReal factor, UGushort maxDetailIndex = 0, UGushort minDetailIndex = 99);
	void SetMaterialLodBias(UGReal factor, UGushort maxDetailIndex = 0, UGushort minDetailIndex = 99);
	void SetPolygonModeOverrideable(UGbool PolygonModeOverrideable);
	UGMovableObject* DetachObjectFromBone(const UGString &movableName);
	void DetachObjectFromBone(UGMovableObject* obj);
	void DetachAllObjectsFromBone(void);
	UGMovableObject* GetAttachedObject(void);
	UGReal GetBoundingRadius(void) const;
	void NotifyAttached(UGNode* parent, UGbool isTagPoint = false);
	
public:
	void SetNormaliseNormals(UGbool normalise) { m_bNormaliseNormals = normalise; }
	UGbool GetNormaliseNormals(void) const {return m_bNormaliseNormals; }
	UGMatrix4d* GetBoneMatrices(void) const { return m_BoneMatrices;}
	UGushort GetNumBoneMatrices(void) const { return m_unNumBoneMatrices; }
	

protected:
	UGSubEntity* FindSubEntityForVertexData(UGVertexData* orig);
	void BuildSubEntityList(UGEntityMesh* mesh, SubEntityList* sublist);
	void AttachObjectImpl(UGMovableObject *pMovable);
	void DetachObjectImpl(UGMovableObject* pObject);
	void DetachAllObjectsImpl(void);
	
protected:
	UGEntityMesh* m_Mesh;	
	SubEntityList m_SubEntityList;
	UGMatrix4d* m_BoneWorldMatrices;
	UGMatrix4d* m_BoneMatrices;
	UGushort m_unNumBoneMatrices;
	UGushort m_unMeshLodIndex;
	UGushort m_unMinMeshLodIndex;
	UGushort m_unMaxMeshLodIndex;
	UGushort m_unMinMaterialLodIndex;
	UGushort m_unMaxMaterialLodIndex;
	LODEntityList m_LodEntityList;
	UGMatrix4d m_LastParentXform;
	ChildObjectList m_ChildObjectList;
	UGbool m_bNormaliseNormals;
	UGReal m_dMeshLodFactorInv;
	UGReal m_dMaterialLodFactorInv;
	
// 从OGRE中EntityFactory移过来
public:
	static UGString FACTORY_TYPE_NAME;
};
}
#endif // !defined(AFX_UGENTITY_H__05F1D09B_F410_41A3_BC06_49E3D87E0461__INCLUDED_)
