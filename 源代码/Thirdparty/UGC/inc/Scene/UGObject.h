// UGObject.h: interface for the UGObject class.
//
//////////////////////////////////////////////////////////////////////

#ifndef UGOBJECT_H
#define UGOBJECT_H 
#include "Scene/UGReferenced.h"
#include "Scene/UGSceneHeaders.h"
#include "Scene/UGRefPtr.h"
namespace UGC
{
		
class SCENE_API UGObject:public UGReferenced  
{
public:
	UGObject():UGReferenced(){};
	UGObject(const UGObject&){};
	inline void SetUserData(UGReferenced* pObj){m_Data = pObj;}
	inline UGReferenced* GetUserData(){return m_Data.Get();}
	inline const UGReferenced* GetUserData()const{return m_Data.Get();}
//	virtual CloneType()()const = 0;
//	virtual Clone()const = 0;

protected:
	virtual ~UGObject();
	UGRefPtr<UGReferenced> m_Data;		
private:
	UGObject& operator=(const UGObject&){return *this;};	
};
	
}


#endif

