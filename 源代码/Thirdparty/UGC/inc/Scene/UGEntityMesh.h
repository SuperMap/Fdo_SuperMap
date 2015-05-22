// UGEntityMesh.h: interface for the UGEntityMesh class.
// 
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGENTITYMESH_H__16F1848D_40EA_49D8_991B_45623BFD962F__INCLUDED_)
#define AFX_UGENTITYMESH_H__16F1848D_40EA_49D8_991B_45623BFD962F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Scene/UGPrerequisites.h"
#include "Scene/UGIndexData.h"

namespace UGC
{
// 这个类原型是ogre中mesh但与原来系统存在的mesh相冲突
// 故新建EntityMesh对象
class SCENE_API UGEntityMesh  
{
public:
	UGEntityMesh(const UGString& name, UGbool isManual = false);
    ~UGEntityMesh();

	void Load(void);
	UGSubMesh* CreateSubMesh(void);
	UGSubMesh* CreateSubMesh(const UGString& name);
	void NameSubMesh(const UGString& name, UGushort index);
	UGushort GetSubMeshIndex(const UGString& name) const;
	UGushort GetNumSubMeshes(void) const;
	UGSubMesh* GetSubMesh(UGushort index) const;
	UGSubMesh* GetSubMesh(const UGString& name) const ;
	UGEntityMesh* Clone(const UGString& newName, const UGString& newGroup);
	UGushort GetNumLodLevels(void) const;
	void CreateManualLodLevel(UGReal fromDepth, const UGString& meshName);
	void UpdateManualLodLevel(UGushort index, const UGString& meshName);
	UGushort GetLodIndex(UGReal depth) const;
	UGushort GetLodIndexSquaredDepth(UGReal squaredDepth) const;
	void SetLodInfo(UGushort numLevels, UGbool isManual);
	void SetSubMeshLodFaceList(UGushort subIdx, UGushort level, UGIndexData* facedata);
	void RemoveLodLevels(void);

public:
	UGbool IsLodManual(void) const { return m_bIsLodManual; }

public:
	typedef UGList<UGReal> LodDistanceList;
	typedef UGList<UGSubMesh*> SubMeshList;
	typedef UGList<UGushort> IndexMap;
	typedef UGDict<UGString, UGushort> SubMeshNameMap;
	
public:
	UGVertexData *sharedVertexData;
	IndexMap sharedBlendIndexToBoneIndexMap;
protected:
	SubMeshList m_SubMeshList;
	SubMeshNameMap m_SubMeshNameMap ;
	bool m_bIsLodManual;
	UGushort m_unNumLods;

};
}
#endif // !defined(AFX_UGENTITYMESH_H__16F1848D_40EA_49D8_991B_45623BFD962F__INCLUDED_)
