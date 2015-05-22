
//UGSymbolLib.h

#ifndef UG_SYMBOLLIB_H
#define UG_SYMBOLLIB_H

#include "Base/UGString.h"
#include "Base/UGStream.h"
#include "Base/UGDict.h"
#include "UGSymbol.h"
#include "UGSymbolGroup.h"

namespace UGC 
{
	/** 符号资源库
	    @remarks
		    1.存储符号的仓库；
			2.采用多级分组来组织和管理符号；
			3.库下有: 
			    ⊙一个符号存储列表(m_Symbols)，其中存放系统中所有的符号(基类指针UGSymbol*)；
				⊙一个符号ID管理列表(m_IDs)，其中存放m_Symbols中的符号的ID；
				⊙一个分组管理的根组(m_pRootGroup)；
			4.要同时维护m_Symbols和m_IDs的增删动作，m_Symbols和m_IDs的元素个数时时保持一致；
			5.支持读写功能；
	*/
	class SYMBOL_API UGSymbolLib  
	{
	public:
		UGSymbolLib();
		virtual ~UGSymbolLib();
		
		//----------------------------------------------------------------
		virtual UGbool Load(UGStream& stream) = 0;
		virtual UGbool Append(UGStream& stream, UGbool bReplace = TRUE) = 0;
		//! nVersion的默认值是最高版本
		virtual UGbool Save(UGStream& stream, UGuint nVersion = 0) const = 0;
		//----------------------------------------------------------------

		UGbool LoadFromFile(const UGString& strFileName);
		UGbool AppendFromFile(const UGString& strFileName, UGbool bReplace = TRUE);
		//! nVersion的默认值0表示最高版本
		UGbool SaveToFile(const UGString& strFileName, UGuint nVersion = 0) const;

		//----------------------------------------------------------------
		
		UGbool AddSymbol(UGSymbol *pSymbol, UGSymbolGroup *pSymbolGroup = NULL);
		
		//----------------------------------------------------------------

		UGSymbolGroup* GetRootGroup() const;
		UGint GetSymbolCount() const;

		//----------------------------------------------------------------
		
		UGbool IsIDExisted(UGint nID) const;

		//! 查找符号ID，返回索引，找不到返回-1
		UGint FindID(UGint nID) const;
		//! 查找符号名称，返回索引
		UGint FindName(const UGString& strSymName, UGint nStartIndex = 0) const;
		//! 反向查找符号名称，返回正向索引，起始索引从后往前算
		UGint ReverseFindName(const UGString& strSymName, UGint nStartIndex = 0) const;
		
		UGbool Swap(UGint nOldIndex, UGint nNewIndex);
		
		UGint GetMaxID() const;
		void SortByID();
		
		void RemoveAll();
		//! 移除指定位置的符号，返回移除数目
		UGint RemoveAt(UGint nIndex, UGint nCount = 1);
		//! 移除指定ID符号
		UGbool RemoveID(UGint nID);
		
		UGSymbol* GetSymbolAt(UGint nIndex) const;
		//! 查找ID为nID的符号，没有找到则返回NULL
		UGSymbol* GetSymbolByID(UGint nID) const; 

		//! 设置指定位置的符号，将会把原符号释放
		//	void SetAt(UGint nIndex, UGSymbol* pSymbol);
		void InsertAt(UGint nIndex, UGSymbol* pSymbol);
		
		UGint GetIDAt(UGint nIndex) const;
		UGbool SetIDAt(UGint nIndex, UGint nID);
		
		UGString GetNameAt(UGint nIndex) const;
		void SetNameAt(UGint nIndex, const UGString& strSymName);
		
		UGbool IsModified() const;
		void SetModifiedFlag(UGbool bModified = TRUE);
		
		
		UGuint GetVersion();
		
		UGString GetDefaultPath() const;
		void SetDefaultPath(const UGString& strPathName);
		
		UGbool LoadDefault();
		
	protected:

		//! 符号存储列表
		UGDict<UGint, UGSymbol*> m_Symbols;

		//! 符号ID管理组织列表
		UGArray<UGint> m_IDs;
			
		//! 分组管理的根组
		UGSymbolGroup *m_pRootGroup;

		//! 版本
		UGuint m_nVersion;

		UGbool m_bModified;
		
		UGString m_strDefaultPath;
	};
	
}

#endif


