#ifndef UGSYMBOL_H
#define UGSYMBOL_H

#include "Base/UGString.h"
#include "Algorithm/UGPoint.h"

namespace UGC 
{
	/** Symbol符号继承体系的抽象基类
	    @remarks
		    1。每个符号都有一个ID(>0),都有一个名字；
			2。系统中有三种符号：点符号、线符号、填充符号
			3。三种具体符号的子类UGPointSymbol、UGLineSymbol、UGFillSymbol
			   都从该抽象基类UGSymbol继承
			4。符号本身具有读写功能：Load()，Save()
	*/
	class SYMBOL_API UGSymbol  
	{
	public:
		UGSymbol( UGint id = -1) : m_nID(id)
		{
		}

		virtual ~UGSymbol()
		{
			// virtual Destructor
		}

        //暂时还没有必要  Y.M.Zheng 
		//UGSymbol(const UGSymbol& symbol){}
		//virtual void operator = (const UGSymbol& symbol){}
		
	public:
		UGint GetID() const
		{
			return m_nID;
		}
		
		void  SetID(UGint nID)
		{
			m_nID = nID;
		}
		
		UGString GetName() const
		{
			return m_strName;
		}
		
		void SetName(const UGString& strName)
		{
			m_strName = strName;
		}
		
		UGbool IsModified() const
		{
			return m_bModified;
		}
		
		void SetModifiedFlag(UGbool bModified = true)
		{
			m_bModified = bModified;
		}
		
		virtual UGbool Load(UGStream& stream, UGuint nVersion = 0) = 0;
		virtual UGbool Save(UGStream& stream, UGuint nVersion = 0) const = 0;
		
	protected:  
		//设置为protected，是为了让子类能够存取之，
		//特别地，为了子类的operator =重载函数中可以直接为基类数据赋值

		UGbool   m_bModified;
		UGint    m_nID;
		UGString m_strName;
		
	};
	
}

#endif


