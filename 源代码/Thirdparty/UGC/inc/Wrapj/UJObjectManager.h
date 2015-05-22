// UJObjectManager.h: interface for the UJObjectManager class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UJOBJECTMANAGER_H__890A573A_5B5E_4F98_B96A_F0E2FD96C91E__INCLUDED_)
#define AFX_UJOBJECTMANAGER_H__890A573A_5B5E_4F98_B96A_F0E2FD96C91E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Wrapj/SuperMapStubH.h"
#include "Base/UGLogFile.h"


// Wrapper class for ugc class that can be create
class CCreatableObject 
{
public:
	virtual UGlong CreateObject();
	virtual void DeleteObject(UGlong hInstacePtr);
};



// template class act as single entry for construct ugc class 
template<class T>
class CTemplateObject : public CCreatableObject
{
public:
//	CTemplateObject();

	UGlong CreateObject();
	void DeleteObject(UGlong hInstacePtr);

};


template <class T>
UGlong CTemplateObject<T>::CreateObject()
{
	return (UGlong) new T();
}

template <class T>
void CTemplateObject<T>::DeleteObject(UGlong hInstacePtr)
{
	T* pT = (T*)hInstacePtr;
	if (pT!=NULL) {
		delete pT;
		//pT = NULL;
	}
	
	
}

// 全局仅一个，否则内存会出错
class UJObjectManager  
{
public:
	UJObjectManager();
	virtual ~UJObjectManager();
public:
	void ReleaseAll();
	UGlong CreateObject(UGlong classID);	
	
	UGbool RegisterObject(UGlong hInstance, UGlong classID);

	UGbool RegisterObject(UGlong hInstance, UGString className);

	
	UGbool RegisterGeometryObject(UGGeometry* pGeo);

	UGint DeleteObject(UGlong hInstance, UGlong classID);

	UGint RemoveObjectFromMap(UGlong hInstacePtr, UGlong classID);
	//和delete不一样的的是，这个接口只是从map中移除对应的记录，并不删除指针，也就是说
	//当某种情况下，new出来的对象不需要删除的时候，调用这个接口，那么以后这个对象就
	//不会被删除，调用这个接口一定要确认这个对象真的不用你来释放了，add by xll

private:
	UGDict<UGlong, UGlong> m_ObjectHeap;	
	// key为CreateObject出来的对象，value为CreateObject使用的CTemplateObject对象
	UGbool m_bDeleteObject;
	UGbool m_bCreateObject;
	//上面两个变量主要解决多线程下同时new对象，java虚拟机又同时在释放对象的时候，往map中添加移除key值的时候
	//冲突的问题，一定要这样做，否则很多隐患  add by xll 06.3.9


};

UGlong GetIndexFromGeometryType(UGGeometry::Type geoType);
UGlong GetIndexFromClassName(UGString strClassName);
UJObjectManager * GetObjectManager();

#endif // !defined(AFX_UJOBJECTMANAGER_H__890A573A_5B5E_4F98_B96A_F0E2FD96C91E__INCLUDED_)
