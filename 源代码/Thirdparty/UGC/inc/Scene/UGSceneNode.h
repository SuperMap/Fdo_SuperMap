// UGSceneNode.h: interface for the UGSceneNode class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGSCENENODE_H__E987C770_0688_4BF4_85B3_26CE3182777E__INCLUDED_)
#define AFX_UGSCENENODE_H__E987C770_0688_4BF4_85B3_26CE3182777E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Scene/UGPrerequisites.h"
#include "Scene/UGNode.h"

namespace UGC
{
class SCENE_API UGSceneNode : public UGNode 
{
public:
	typedef UGDict<UGString, UGMovableObject*> ObjectMap;
	
public:
	UGSceneNode(UGScene* creator);
	UGSceneNode(UGScene* creator, const UGString& name);
	virtual ~UGSceneNode();
	virtual void AttachObject(UGMovableObject* obj);
	virtual UGushort NumAttachedObjects(void) const;
	virtual UGMovableObject* GetAttachedObject(UGushort index);
	virtual UGMovableObject* GetAttachedObject(const UGString& name);
	virtual UGMovableObject* DetachObject(UGushort index);
	virtual void DetachObject(UGMovableObject* obj);
	virtual UGMovableObject* DetachObject(const UGString& name);
	virtual void DetachAllObjects(void);
	virtual void Update(UGbool updateChildren, UGbool parentHasChanged);
	virtual void UpdateBounds(void);
	UGScene* GetCreator(void) const;
	virtual void RemoveAndDestroyChild(const UGString& name);
	virtual void RemoveAndDestroyChild(UGushort index);
	virtual void RemoveAndDestroyAllChildren(void);
	virtual void ShowBoundingBox(UGbool bShow);
	virtual UGbool GetShowBoundingBox() const;
	virtual UGSceneNode* CreateChildSceneNode(const UGVector3R& translate = UGVector3R::ZERO, 
                                              const UGQuaternion4d& rotate = UGQuaternion4d::IDENTITY );
	virtual UGSceneNode* CreateChildSceneNode(const UGString& name, const UGVector3R& translate = UGVector3R::ZERO, 
		                                      const UGQuaternion4d& rotate = UGQuaternion4d::IDENTITY);
	virtual UGLightList& FindLights(UGReal radius) const;
	virtual void SetFixedYawAxis(UGbool useFixed, const UGVector3R& fixedAxis = UGVector3R::UNIT_Y );
	virtual void Yaw(const UGReal angle, TransformSpace relativeTo = TS_LOCAL);
	virtual void SetDirection(UGReal x, UGReal y, UGReal z, TransformSpace relativeTo = TS_LOCAL, 
							  const UGVector3R& localDirectionVector = UGVector3R::NEGATIVE_UNIT_Z);
	virtual void SetDirection(const UGVector3R& vec, TransformSpace relativeTo = TS_LOCAL, 
							  const UGVector3R& localDirectionVector = UGVector3R::NEGATIVE_UNIT_Z);
	virtual void LookAt(const UGVector3R& targetPoint, TransformSpace relativeTo,
						const UGVector3R& localDirectionVector = UGVector3R::NEGATIVE_UNIT_Z);
	virtual void SetAutoTracking(UGbool enabled, UGSceneNode* target = 0, 
								 const UGVector3R& localDirectionVector = UGVector3R::NEGATIVE_UNIT_Z,
								 const UGVector3R& offset = UGVector3R::ZERO);
	void AutoTrack(void);
	UGSceneNode* GetParentSceneNode(void) const;
	virtual void SetVisible(UGbool visible, UGbool cascade = true);
	virtual void FlipVisibility(bool cascade = true);
	// malq-2008
	virtual void UpdateAttachObjects();
	virtual void RenderAttachObjects();
	virtual void NotifyActiveCamera(UGCameraBase* pActiveCamera);
	virtual void Release();


public:
	virtual UGbool IsInSceneGraph(void) const { return m_bIsInSceneGraph; }
	virtual void NotifyRootNode(void) { m_bIsInSceneGraph = true; }
	virtual UGSceneNode* GetAutoTrackTarget(void) { return m_AutoTrackTarget; }
	virtual UGVector3R& GetAutoTrackOffset(void) { return m_vecAutoTrackOffset; }
	virtual UGVector3R& GetAutoTrackLocalDirection(void) { return m_vecAutoTrackLocalDirection; }
protected:
	UGNode* CreateChildImpl(void);
	UGNode* CreateChildImpl(const UGString& name);
	void SetParent(UGNode* parent);
	virtual void SetInSceneGraph(UGbool inGraph);
	
protected:
	ObjectMap m_ObjectsByName;
	UGbool m_bShowBoundingBox;
    mutable UGLightList m_LightList;
    mutable UGbool m_bLightListDirty;
	UGScene* m_pCreator;
	UGbool m_bYawFixed;
	UGVector3R m_vecYawFixedAxis;
	UGSceneNode* m_AutoTrackTarget;
	UGVector3R m_vecAutoTrackOffset;
    UGVector3R m_vecAutoTrackLocalDirection;
	UGbool m_bIsInSceneGraph;


	
};
}
#endif // !defined(AFX_UGSCENENODE_H__E987C770_0688_4BF4_85B3_26CE3182777E__INCLUDED_)
