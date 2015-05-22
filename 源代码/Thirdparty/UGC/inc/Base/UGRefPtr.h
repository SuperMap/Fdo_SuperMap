// UGRefPtr.h: interface for the UGRefPtr class.
//
//////////////////////////////////////////////////////////////////////

#ifndef UGREFPTR_H
#define UGREFPTR_H
#include "Base/ugdefs.h"
namespace UGC
{
	//! \brief 一个智能指针与UGRerenced配合使用
	template <class T>
	class UGEXPORT UGRefPtr  
	{
	public:
		UGRefPtr():m_ptr(0L){}
		UGRefPtr(T* ptr):m_ptr(ptr){if (m_ptr) m_ptr->Ref();}
		UGRefPtr(const UGRefPtr& rp):m_ptr(rp.m_ptr){if (m_ptr) m_ptr->Ref();}
		~UGRefPtr(){if(m_ptr)m_ptr->Unref(); m_ptr = 0L;}
		inline UGRefPtr& operator = (const UGRefPtr& rp )
		{
            if (m_ptr==rp.m_ptr) return *this;
            T* tmp_ptr = m_ptr;
            m_ptr = rp.m_ptr;
            if (m_ptr) m_ptr->Ref();
            if (tmp_ptr) tmp_ptr->Unref();
            return *this;
        }
		inline UGRefPtr& operator = (T* ptr)
		{
			if (m_ptr==ptr) return *this;
			T* tmp_ptr = m_ptr;
			m_ptr = ptr;
			if (m_ptr) m_ptr->Ref();
			if (tmp_ptr) tmp_ptr->Unref();
			return *this;	
		}
		inline UGbool operator == (const UGRefPtr& rp) const { return (m_ptr==rp.m_ptr); }
        inline UGbool operator != (const UGRefPtr& rp) const { return (m_ptr!=rp.m_ptr); }
        inline UGbool operator < (const UGRefPtr& rp) const { return (m_ptr<rp.m_ptr); }
        inline UGbool operator > (const UGRefPtr& rp) const { return (m_ptr>rp.m_ptr); }

		inline UGbool operator == (const T* ptr) const { return (m_ptr==ptr); }
        inline UGbool operator != (const T* ptr) const { return (m_ptr!=ptr); }
        inline UGbool operator < (const T* ptr) const { return (m_ptr<ptr); }
        inline UGbool operator > (const T* ptr) const { return (m_ptr>ptr); }

		inline T& operator*()  { return *m_ptr; }
		
        inline const T& operator*() const { return *m_ptr; }
		
        inline T* operator->() { return m_ptr; }
		
        inline const T* operator->() const   { return m_ptr; }
		
		inline UGbool operator!() const	{ return m_ptr==0L; }
		
		inline UGbool IsValid() const	{ return m_ptr!=0L; }
        
        inline T* Get() { return m_ptr; }
		
        inline const T* Get() const { return m_ptr; }

		//慎用

		inline T* Take() { return Release();}
		
        inline T* Release() { T* tmp=m_ptr; if (m_ptr) m_ptr->UnrefNoDelete(); m_ptr=0; return tmp;}

	private:
		T* m_ptr;
	};

}

#endif 
