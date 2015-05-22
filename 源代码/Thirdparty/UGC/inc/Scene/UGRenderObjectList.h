/* 
	\file UGRenderObjectList.h
	
*/

#if !defined(AFX_UGRENDEROBJECTLIST_H__618529B0_589C_4A7C_BFEF_C57EF5C363A8__INCLUDED_)
#define AFX_UGRENDEROBJECTLIST_H__618529B0_589C_4A7C_BFEF_C57EF5C363A8__INCLUDED_


#include "Scene/UGPrerequisites.h"
#include "Scene/UGRenderObject.h"
#include "Base/UGThread.h"

namespace UGC 
{

class SCENE_API  SyncRenderObjectArray
{
public:
	SyncRenderObjectArray(){};
	virtual ~SyncRenderObjectArray(){};
	void   Lock(){m_mutex.lock();};
	void   Unlock(){m_mutex.unlock();};
public:
	UGMutex m_mutex;
	UGArray<UGRenderObject *> m_Array;

	
};
class SCENE_API UGRenderObjectList : public UGRenderObject
{
public:
	UGRenderObjectList();
	virtual ~UGRenderObjectList();
	virtual void Initialize();
	virtual void Update();
	virtual void Render();
	virtual void Release();
	void Add(UGRenderObject *ro);
	UGbool Remove(UGRenderObject *ro);
	UGbool RemoveAll();
	void SetLayerVisible(UGString strName, UGbool bVisible);
	UGbool IsLayerVisible(UGString strName);
	UGRenderObject* GetRenderObject(const UGString& strName);
	virtual void NotifyActiveCamera(UGCameraBase* pActiveCamera);	
	UGRenderObject* PickModelObjects(const UGint pointx, const UGint pointy, UGbool bPick);
	UGRenderObject* PickVectorObjects(const UGint pointx, const UGint pointy, UGbool bPick);
private:
	SyncRenderObjectArray m_Children;

};

}
#endif // !defined(AFX_UGRENDEROBJECTLIST_H__618529B0_589C_4A7C_BFEF_C57EF5C363A8__INCLUDED_)
