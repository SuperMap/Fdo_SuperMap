// UGMovableObject.h: interface for the UGMovableObject class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGMOVABLEOBJECT_H__52F5F7B0_C2FD_4687_81F8_A1137A3232DA__INCLUDED_)
#define AFX_UGMOVABLEOBJECT_H__52F5F7B0_C2FD_4687_81F8_A1137A3232DA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Scene/UGPrerequisites.h"
#include "Scene/UGVector3R.h"

namespace UGC
{
class SCENE_API UGMovableObject  
{
public:
	UGMovableObject();
	UGMovableObject(const UGString& name);
	UGMovableObject(const UGString& name, UGScene* pScene);
	virtual ~UGMovableObject();
	virtual UGNode* GetParentNode(void) const;
	virtual UGSceneNode* GetParentSceneNode(void) const;
	virtual void NotifyAttached(UGNode* parent, UGbool isTagPoint = false);
	virtual UGbool IsAttached(void) const;
	virtual UGbool IsInScene(void) const;
	virtual void NotifyCurrentCamera(UGCameraBase* cam);
	virtual void SetVisible(UGbool visible);
	virtual UGbool GetVisible(void) const;
	virtual UGbool IsVisible(void) const;
	virtual UGMatrix4d GetParentNodeFullTransform(void) const;

	// 根据自身情况添加update和render函数
	virtual void Update(){}
	virtual void Render(){}
	virtual void Initialize(){}
	virtual void Release(){}
	virtual void NotifyActiveCamera(UGCameraBase* pActiveCamera);

	
	
	

public:
	virtual void NotifyManager(UGScene* man) { m_pScene = man; }
	virtual UGScene* GetManager(void) const { return m_pScene; }
	virtual UGString GetName(void) const { return m_strName; }
	virtual void SetName(const UGString& name) {m_strName = name;}
	virtual void SetRenderingDistance(UGReal dist) 
	{ 
			m_dUpperDistance = dist; 
			m_dSquaredUpperDistance = m_dUpperDistance * m_dUpperDistance;
	}
	virtual UGReal GetRenderingDistance(void) const { return m_dUpperDistance; }
	
	virtual UGString& GetMovableType(void) const;
	
	// 添加是否于射线相交函数
	// add by luofx
	// 包括模型，点，线，面，文字都要覆盖该函数
	virtual UGbool InterSectWithRadial(const UGVector3R& nearPos, const UGVector3R& farPos){return false;}
	virtual void SetPickStatus(UGbool status);
	virtual UGbool GetPickStatus();

protected:
	UGString m_strName;
	UGScene* m_pScene;
	UGNode* m_ParentNode;
	UGbool m_bVisible;
	UGReal m_dUpperDistance;
	UGReal m_dSquaredUpperDistance;
	UGbool m_bBeyondFarDistance;
	//! \brief 相机成员
	UGCameraBase* m_pActiveCamera;
	
	// 设置是否选中,true选中，false不选中
	UGbool m_bPicked;
};

}
#endif // !defined(AFX_UGMOVABLEOBJECT_H__52F5F7B0_C2FD_4687_81F8_A1137A3232DA__INCLUDED_)
