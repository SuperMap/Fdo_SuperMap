/* 
	\file UGNode.h
	\brief 文件内容的简要描述。
	\author 文件作者
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>更新说明：。</b>
	<em>1、第一条说明。</em>
	<em>2、第二条说明。</em>
*/

// UGNode.h: interface for the UGNode class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGNODE_H__A7527D97_A4DB_41C7_A204_4F252383A7B2__INCLUDED_)
#define AFX_UGNODE_H__A7527D97_A4DB_41C7_A204_4F252383A7B2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Scene/UGPrerequisites.h"
#include "Scene/UGRenderable.h"

namespace UGC
{
//! \brief 类的简要说明。
//! \remarks 备注信息。
class SCENE_API UGNode : public UGRenderable  
{

public:
	//! \brief
	enum TransformSpace
    {
        /// Transform is relative to the local space
        TS_LOCAL,
        /// Transform is relative to the space of the parent UGNode
        TS_PARENT,
        /// Transform is relative to world space
        TS_WORLD
    };
public:
    //! \brief 构造函数
    UGNode();
	//! \brief 构造函数
    UGNode(const UGString& name);
	//! \brief 析构函数
    virtual ~UGNode(); 
	//! \brief
    UGString GetName(void) const;
	//! \brief
    virtual UGNode* GetParent(void) const;
	//! \brief
    virtual UGQuaternion4d GetOrientation() const;
	//! \brief
    virtual void SetOrientation( const UGQuaternion4d& q );
	//! \brief
    virtual void SetOrientation( UGReal w, UGReal x, UGReal y, UGReal z);
	//! \brief
    virtual void ResetOrientation(void);
	//! \brief
    virtual void SetPosition(const UGVector3R& pos);
	//! \brief
    virtual void SetPosition(UGReal x, UGReal y, UGReal z);
	//! \brief
    virtual UGVector3R GetPosition(void) const;
	//! \brief
    virtual void SetScale(const UGVector3R& scale);
	//! \brief
    virtual void SetScale(UGReal x, UGReal y, UGReal z);
	//! \brief
    virtual UGVector3R GetScale(void) const;
	//! \brief
    virtual void SetInheritOrientation(UGbool inherit);
	//! \brief
    virtual UGbool GetInheritOrientation(void) const;
	//! \brief
    virtual void SetInheritScale(UGbool inherit);
	//! \brief
    virtual UGbool GetInheritScale(void) const;
	//! \brief
    virtual void Scale(const UGVector3R& scale);
	//! \brief
    virtual void Scale(UGReal x, UGReal y, UGReal z);
	//! \brief
    virtual void Translate(const UGVector3R& d, TransformSpace relativeTo = TS_PARENT);
	//! \brief
    virtual void Translate(UGReal x, UGReal y, UGReal z, TransformSpace relativeTo = TS_PARENT);
	//! \brief
    virtual void Translate(const UGMatrix3R& axes, const UGVector3R& move, TransformSpace relativeTo = TS_PARENT);
	//! \brief
    virtual void Translate(const UGMatrix3R& axes, UGReal x, UGReal y, UGReal z, TransformSpace relativeTo = TS_PARENT);
	//! \brief
    virtual void Roll(const UGReal& angle, TransformSpace relativeTo = TS_LOCAL);
	//! \brief
    virtual void Pitch(const UGReal& angle, TransformSpace relativeTo = TS_LOCAL);
	//! \brief
    virtual void Yaw(const UGReal& angle, TransformSpace relativeTo = TS_LOCAL);
	//! \brief
    virtual void Rotate(const UGVector3R& axis, const UGReal& angle, TransformSpace relativeTo = TS_LOCAL);
	//! \brief
    virtual void Rotate(const UGQuaternion4d& q, TransformSpace relativeTo = TS_LOCAL);
	//! \brief
	virtual UGMatrix3R GetLocalAxes(void) const;
	//! \brief
    virtual UGNode* CreateChild(const UGVector3R& translate = UGVector3R::ZERO, 
								const UGQuaternion4d& rotate = UGQuaternion4d::IDENTITY );
	//! \brief
    virtual UGNode* CreateChild(const UGString& name, const UGVector3R& translate = UGVector3R::ZERO, const UGQuaternion4d& rotate = UGQuaternion4d::IDENTITY);
	//! \brief
    virtual void AddChild(UGNode* child);
	//! \brief
    virtual UGushort NumChildren(void) const;
	//! \brief
    virtual UGNode* GetChild(UGushort index) const;    
	//! \brief
    virtual UGNode* GetChild(const UGString& name) const; 
	//! \brief
    virtual UGNode* RemoveChild(UGushort index);
	//! \brief
    virtual UGNode* RemoveChild(UGNode* child);
	//! \brief
    virtual UGNode* RemoveChild(const UGString& name);
	//! \brief
    virtual void RemoveAllChildren(void);
	//! \brief
    virtual UGQuaternion4d GetDerivedOrientation(void) const;
	//! \brief
    virtual UGVector3R GetDerivedPosition(void) const;
	//! \brief
    virtual UGVector3R  GetDerivedScale(void) const;
	//! \brief
    virtual UGMatrix4d GetFullTransform(void) const;
	//! \brief
    virtual void Update(UGbool updateChildren, UGbool parentHasChanged);	
	//! \brief
    UGMaterial* GetMaterial(void) const;
	//! \brief
    void GetRenderOperation(UGRenderOperation& op);
	//! \brief
    void GetWorldTransforms(UGMatrix4d* xform) const;
	//! \brief
    UGQuaternion4d GetWorldOrientation(void) const;
	//! \brief
    UGVector3R GetWorldPosition(void) const;
	//! \brief
    virtual void SetInitialState(void);
	//! \brief
    virtual void ResetToInitialState(void);
	//! \brief
    virtual UGVector3R GetInitialPosition(void) const;
	//! \brief
    virtual UGQuaternion4d GetInitialOrientation(void) const;
	//! \brief
    virtual UGVector3R GetInitialScale(void) const;
	//! \brief
    virtual void WeightedTransform(UGReal weight, const UGVector3R& translate, 
									const UGQuaternion4d& rotate, const UGVector3R& scale);
    //! \brief
	UGReal GetSquaredViewDepth(UGCameraBase* cam) const;
	//! \brief
	virtual void NeedUpdate(bool forceParentUpdate = false);
	//! \brief
    virtual void RequestUpdate(UGNode* child, UGbool forceParentUpdate = false);
	//! \brief
    virtual void CancelUpdate(UGNode* child);
	//! \brief
	static void QueueNeedUpdate(UGNode* n);
	//! \brief
	static void ProcessQueuedUpdates(void);
	//! \brief
    UGLightList GetLights(void) const;
	//! \brief
	virtual void UpdateAttachObjects(){};
	//! \brief
	virtual void RenderAttachObjects(){};
	//! \brief
	virtual void NotifyActiveCamera(UGCameraBase* pActiveCamera){};
	//! \brief
	virtual void Release(){};

protected:	
	//! \brief
	virtual void SetParent(UGNode* parent);
	//! \brief
	virtual void UpdateFromParent(void) const;
	//! \brief
	virtual UGNode* CreateChildImpl(void) = 0;
	//! \brief
	virtual UGNode* CreateChildImpl(const UGString& name) = 0;

protected:
	//! \brief
	UGNode* m_Parent;
	//! \brief
	typedef UGDict<UGString, UGNode*> ChildNodeMap;
	//! \brief
	ChildNodeMap m_Children;
	//! \brief
	typedef UGList<UGNode*> ChildUpdateSet;	
	//! \brief List of children which need updating, used if self is not out of date but children are
	mutable ChildUpdateSet m_ChildrenToUpdate;
	//! \brief Flag to indicate own transform from parent is out of date
	mutable UGbool m_bNeedParentUpdate;
	/// Flag indicating that all children need to be updated
	mutable UGbool m_bNeedChildUpdate;
	/// Flag indicating that parent has been notified about update request
	mutable UGbool m_bParentNotified ;
	/// Flag indicating that the UGNode has been queued for update
	mutable UGbool m_bQueuedForUpdate;
	/// Friendly name of this UGNode, can be automatically generated if you don't care
	UGString m_strName;
	/// Stores the orientation of the UGNode relative to it's parent.
	UGQuaternion4d m_quaOrientation;
	/// Stores the position/translation of the UGNode relative to its parent.
	UGVector3R m_vecPosition;
	/// Stores the scaling factor applied to this UGNode
	UGVector3R m_vecScale;
	/// Stores whether this UGNode inherits orientation from it's parent
	UGbool m_bInheritOrientation;
	/// Stores whether this UGNode inherits scale from it's parent
	UGbool m_bInheritScale;
	/// Material pointer should this UGNode be rendered
	mutable UGMaterial* m_pMaterial;
	//! \brief
	mutable UGQuaternion4d m_quaDerivedOrientation;
	//! \brief
	mutable UGVector3R m_vecDerivedPosition;
	//! \brief
	mutable UGVector3R m_vecDerivedScale;
	//! \brief
	UGVector3R m_vecInitialPosition;
	//! \brief
	UGQuaternion4d m_quaInitialOrientation;
	//! \brief
	UGVector3R m_vecInitialScale;
	//! \brief
	UGReal m_dAccumAnimWeight;
	// The total weighted translation from the initial state so far
	UGVector3R m_vecTransFromInitial;
	// The total weighted rotation from the initial state so far
	UGQuaternion4d m_quaRotFromInitial;
	// The total weighted scale from the initial state so far
	UGVector3R m_vecScaleFromInitial;
	/// Cached derived transform as a 4x4 matrix
	mutable UGMatrix4d m_matCachedTransform;
	mutable UGbool m_bCachedTransformOutOfDate;
	/// Incremented count for next name extension
	static UGulong ms_NextGeneratedNameExt;
	//! \brief
	typedef UGList<UGNode*> QueuedUpdates;
	//! \brief
	static QueuedUpdates ms_QueuedUpdates;

};
}
#endif // !defined(AFX_UGNODE_H__A7527D97_A4DB_41C7_A204_4F252383A7B2__INCLUDED_)
