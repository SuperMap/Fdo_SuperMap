// UGSingleton.h: interface for the UGSingleton class.
//
//////////////////////////////////////////////////////////////////////

#ifndef UGSINGLETON_H
#define UGSINGLETON_H
#include "ugdefs.h"
template<typename T>
namespace UGC
{
	class UGSingleton  
	{ 
	protected:
		static T* m_pSingleton;
		
	public:
		UGSingleton(void)
		{
			if(!m_pSingleton)
			{
				int nOffset = (int)(T*)1 - (int)(UGSingleton<T>*)(T*)1;
				m_pSingleton = (T*)(int(this) + nOffset);
			}
		}
		~UGSingleton(void)
		{
			if(m_pSingleton)
				m_pSingleton = 0;
			
		}
		static T& GetSingleton(void)
		{
			UGASSERT(m_pSingleton);	
			return(*m_pSingleton);
			
		}
		static T* GetSingletonPtr(void)
		{
			UGASSERT(m_pSingleton);
			return m_pSingleton;
		}
	};
}

#endif // !defined(UGSINGLETON_H)
