#ifndef UGHASH_H
#define UGHASH_H
#include "ugdefs.h"
#include "UGString.h"

#define HASH1(x,m) (((UGuint)((UGuval)(x)^(((UGuval)(x))>>13)))&(m))
#define HASH2(x,m) (((UGuint)((UGuval)(x)^(((UGuval)(x))>>17)|1))&(m))

namespace UGC {
template<typename T>
class BASE_API UGHash
{
public:
	typedef UGint POSITION;

	struct Entry {
		UGString key;
		T val;
		Entry() 
		{
			key="";	
			val=T();
		}
    };
public:		
	UGHash():m_used(0),m_free(2),m_max(1),m_eof(0)
	{		 
		m_table=new Entry[2];		
	}

	UGHash(const UGHash<T>& h)
	{
		m_table = NULL;
		Copy(h);
	}
	
	UGHash &operator=(const UGHash<T>& h)
	{
		if(this != &h)
		{
			Copy(h);
		}
		return *this;
	}

	virtual ~UGHash()
	{		
		delete []m_table;
		m_table = NULL;
	}
	
	UGint GetCount() const
	{
		UGint n=0;
		for(UGint i=0;i<=m_max;i++)
		{
			if(!(m_table[i].key.IsEmpty())) {
				n++;
			}			
		}
		return n;
	}
	
	UGbool IsEmpty() const
	{
		for(UGint i=0;i<=m_max;i++)
		{
			if(!(m_table[i].key.IsEmpty())) {
				return TRUE;
			}			
		}
		return FALSE;
	}
	
	void Copy(const UGHash<T>& h)
	{
		delete []m_table;
		m_table=NULL;
		m_eof=h.m_eof;
		m_used=h.m_used;
		m_free=h.m_free;
		m_max=h.m_max;
		m_table=new Entry[m_max+1];			
		for(UGint i=0; i<=(UGint)m_max; i++)
		{
			m_table[i]=h.m_table[i];
		}
	}
	
	UGbool Lookup(const UGString& key,T& rValue) const
	{
		UGuint p,x,b;
		if(!(key.IsEmpty())){
			p=HASH1(key.HashVal(),m_max);
			x=HASH2(key.HashVal(),m_max);
			b=p;
			while(m_table[p].key!=key){
				if(m_table[p].key.IsEmpty()) return FALSE;
				p=(p+x)&m_max;
				if(p==b) return FALSE;
			}
			rValue=m_table[p].val;
			return TRUE;
		}
		return FALSE;
	}

	T operator[](const UGString& key) const
	{
		T val=T();
		Lookup(key,val);
		return val;
	}
	
	void SetAt(const UGString& key,const T& val)
	{
		UGuint p,x;
		if(!(key.IsEmpty())){
			if((m_free<<1)<=m_max) Resize((m_max<<1)|1);
			p=HASH1(key.HashVal(),m_max);
			x=HASH2(key.HashVal(),m_max);
			while(!(m_table[p].key.IsEmpty()))
			{
				if(m_table[p].key==key)
				{
					m_table[p].val=val;
					return;
				}
				p=(p+x)&m_max;
			}			
			m_free--;
			m_used++;
			m_table[p].key=key;
			m_table[p].val=val;			
		}		
	}
	
	UGbool RemoveKey(const UGString& key)
	{
		UGuint p,x,b;		
		if(!(key.IsEmpty())){
			p=HASH1(key.HashVal(),m_max);
			x=HASH2(key.HashVal(),m_max);
			b=p;
			while(m_table[p].key!=key){
				if(m_table[p].key.IsEmpty()) return FALSE;
				p=(p+x)&m_max;
				if(p==b) return FALSE;
			}			
			
			m_table[p].key.Empty();	
			m_table[p].val=T();
			m_used--;
			m_free++;
			if((m_used<<2)<=m_max) Resize(m_max>>1);
			return TRUE;
		}
		return FALSE;
	}
	
	void RemoveAll()
	{
		delete []m_table;
		m_table=NULL;
		m_used=0;
		m_free=2;
		m_max=1;			
		m_table=new Entry[2];		
	}
	
	POSITION GetStartPosition()
	{
		m_eof=0;
		for(UGint i=m_max;i>=0;i--)
		{
			if(!(m_table[i].key.IsEmpty()))
			{
				m_eof=i+1;
				break;
			}			
		}
		return 0;
	}
	
	UGbool IsEOF(POSITION pos) const
	{
		return pos>=m_eof;
	}
	
	void GetNextAssoc(POSITION& rNextPosition,UGString& rKey,T& rValue)
	{
		if(rNextPosition<m_eof)
		{
			for(;rNextPosition<=(UGint)m_max;rNextPosition++)
			{
				if(!(m_table[rNextPosition].key.IsEmpty())) {
					rKey=m_table[rNextPosition].key;
					rValue=m_table[rNextPosition].val;	
					rNextPosition++;
					return;
				}
			}
		}
	}

private:
	Entry *  m_table;			// Hash table
	UGuint   m_used;			// Number of used entries
	UGuint   m_free;			// Number of free entries
	UGuint   m_max;			// Maximum entry index
	POSITION   m_eof;			// end Position
private:
	void Resize(UGuint m)
	{
		UGString key;
		T val;
		UGuint p,x,i;
		Entry *newtable = new Entry[m+1];		
		for(i=0; i<=m_max; i++){
			key=m_table[i].key;
			val=m_table[i].val;
			if(key.IsEmpty()) continue;
			p=HASH1(key.HashVal(),m);
			x=HASH2(key.HashVal(),m);
			while(!(newtable[p].key.IsEmpty())) p=(p+x)&m;
			newtable[p].key=key;
			newtable[p].val=val;
		}		
		delete []m_table;		
		m_table=newtable;
		m_free=m+1-m_used;
		m_max=m;
	}		
};

}

#endif

