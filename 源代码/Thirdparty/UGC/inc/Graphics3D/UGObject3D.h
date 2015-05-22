// UGObject.h: interface for the UGObject class.
//
//////////////////////////////////////////////////////////////////////

#ifndef UGOBJECT_H
#define UGOBJECT_H 
#include "Base/UGReferenced.h"
#include "Base/UGRefPtr.h"
#include "Graphics3D/UGGraphics3DHeaders.h"

namespace UGC
{
		
class GRAPHICS3D_API UGObject3D:public UGReferenced  
{
public:
	UGObject3D():UGReferenced(){};
	UGObject3D(const UGObject3D&){};
	inline void SetUserData(UGReferenced* pObj){m_UserData = pObj;}
	inline UGReferenced* GetUserData(){return m_UserData.Get();}
	inline const UGReferenced* GetUserData()const{return m_UserData.Get();}
//	virtual CloneType()()const = 0;
//	virtual Clone()const = 0;

protected:
	virtual ~UGObject3D();
	UGRefPtr<UGReferenced> m_UserData;		

private:
	UGObject3D& operator=(const UGObject3D&){return *this;};	
};
	
}


#endif

