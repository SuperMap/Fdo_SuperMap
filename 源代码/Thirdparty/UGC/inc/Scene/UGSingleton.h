// UGSingleton.h: interface for the UGSingleton class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGSINGLETON_H__E89D0670_EB32_4782_8964_7F60F1421BCF__INCLUDED_)
#define AFX_UGSINGLETON_H__E89D0670_EB32_4782_8964_7F60F1421BCF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Scene/UGPrerequisites.h"

namespace UGC
{
template<typename T>
class  SCENE_API UGSingleton  
{ 
protected:
	/*SCENE_API */static T* m_pSingleton;
public:
	UGSingleton()
	{
		if(!m_pSingleton)
		{
			// 计算m_pSingleton也就是类头位置的地址，注this指针不是从父类开始的
			T* temp1=(T*)1; 
			UGlong a=(UGlong)temp1;
			UGSingleton<T>* temp2=(UGSingleton<T>*)temp1;
			UGlong b=(UGlong)temp2;
			UGlong nOffset = a -b ;
			m_pSingleton = (T*)(UGlong(this) + nOffset);
		}
	}
	~UGSingleton()
	{
		if(m_pSingleton)
			m_pSingleton = 0;
		
	}
	static T& GetSingleton()
	{
		UGASSERT(m_pSingleton);	
		return(*m_pSingleton);
		
	}
	static T* GetSingletonPtr()
	{
		UGASSERT(m_pSingleton);
		return m_pSingleton;
	}
};
}
#endif // !defined(AFX_UGSINGLETON_H__E89D0670_EB32_4782_8964_7F60F1421BCF__INCLUDED_)
