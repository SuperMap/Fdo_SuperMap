// UGSubMesh.h: interface for the UGSubMesh class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGSUBMESH_H__A97AA945_E459_4814_8B1F_48D9BD6F9B09__INCLUDED_)
#define AFX_UGSUBMESH_H__A97AA945_E459_4814_8B1F_48D9BD6F9B09__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Scene/UGPrerequisites.h"
#include "Scene/UGRenderOperation.h"

namespace UGC
{
class SCENE_API UGSubMesh  
{
public:
	UGSubMesh();
	virtual ~UGSubMesh();
	UGbool IsMatInitialised(void) const;
	void SetMaterialName(const UGString& matName);
	UGString GetMaterialName(void) const;
	void GetRenderOperation(UGRenderOperation& rend, UGushort lodIndex = 0);
protected:
	void RemoveLodLevels(void);
public:
	UGbool m_buseSharedVertices;
	UGRenderOperation::OpType operationType;
	UGVertexData* vertexData;
	UGIndexData* indexData;
	typedef UGList<UGushort> IndexMap;
	IndexMap blendIndexToBoneIndexMap;
	UGEntityMesh* parent;

protected:
	UGbool m_bMatInitialised;
	UGString m_strMaterialName;
	
};

}
#endif // !defined(AFX_UGSUBMESH_H__A97AA945_E459_4814_8B1F_48D9BD6F9B09__INCLUDED_)
