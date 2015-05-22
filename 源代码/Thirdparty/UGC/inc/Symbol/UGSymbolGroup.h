
#ifndef UG_SYMBOLGROUP_H
#define UG_SYMBOLGROUP_H

#include "Base/UGString.h"
#include "Base/UGStream.h"

namespace UGC 
{
	
	class UGSymbolLib;
	
	/** 符号管理的分组
	    @remarks
		    1.支持多级分组(一个组下面可以有多个子组m_ChildGroups)
			2.组织管理一组符号，这些符号被称为该组的Item(m_Items中记录所管理符号的ID)
			3.支持库信息的读写
	*/
	class SYMBOL_API UGSymbolGroup  
	{
	public:
		UGSymbolGroup();
		UGSymbolGroup(UGSymbolLib *pSymbolLib);
		~UGSymbolGroup();

		UGSymbolLib* GetAttachedLib();
		void AttachLib(UGSymbolLib * pLib);

        //{{----------与分组相关的操作------------------------------------
		UGSymbolGroup* GetParentGroup() const;
		void SetParentGroup(UGSymbolGroup* pParentGroup);

		UGSymbolGroup* GetRootGroup() const;  //得到系统的根组
		UGSymbolGroup* GetChildGroup(UGint nIndex) const;
		UGSymbolGroup* GetChildGroup(const UGString& strName) const;
		UGint GetChildGroupCount() const;

		//! 创建子组，返回新创建子组的指针，如果没有成功，返回NULL
		UGSymbolGroup* CreateChildGroup(const UGString& strName);
		UGbool AppendGroup(UGSymbolGroup *pSymbolGroup);
		UGbool IsChildGroupExisted(const UGString& strName);
		
		UGString GetGroupName() const;
		void SetGroupName(const UGString& strName);
		//}}--------------------------------------------------------------

        //{{----------与Item的相关操作------------------------------------
		UGint GetItemCount() const;
		UGint GetItemID(UGint nIndex) const;
		UGbool SetItemID(UGint nIndex, UGint nID);
		
		UGString GetItemName(UGint nIndex) const;
		void SetItemName(UGint nIndex, const UGString& strItemName);
		
		UGint FindItemID(UGint nID) const; //! 在本组内查找ID，返回索引
		UGbool IsExistID(UGint nID) const;//! 在本组及子组以下ID是否存在

		//该函数是一个内部函数，外面不要使用。
		UGbool AddItem(UGint nID);  
		//}}--------------------------------------------------------------


		//-------------分组信息的读写操作---------------------------------
		void Load(UGStream& stream, UGuint nVersion = 0);
		void Save(UGStream& stream, UGuint nVersion = 0, UGint nSymLibType =0) const;
		//----------------------------------------------------------------
		
		//! 清空所有叶子(Item)和子组
		void Clear();
		
		//! 移除本组及子组以下指定的ID，并删除符号
		UGbool RemoveSymbol(UGint nID);//
		
		//! 移除本组指定索引的ID，并删除符号，返回删除数目
		UGint RemoveItem(UGint nIndex, UGint nCount = 1);
		
		//! 移除本组指定索引的子组，
		//! 如果bMoveUp为真，将子组中的item移到上层来但不删除符号；
		//! 如果bMoveUp为假，删除符号
		//! 其中遍历处理了子组以下的所有子组的情况
		UGbool RemoveChild(UGint nIndex, UGbool bMoveUp = false);
		
		//! 将该Group中索引号从nIndex开始连续nCount个Item移动到pGroup中, 返回移动的数目(只是移动，并不将符号从库中删除)
		UGint MoveItemTo( UGint nIndex, UGint nCount, UGSymbolGroup* pGroup );

		//! 将 该组中与符号nID对应的Item 移动到 pGroup中(只是移动，并不将符号从库中删除)
		UGbool MoveItemTo( UGint nID, UGSymbolGroup* pGroup );

		//! 在本组及以下查找ID所在的组
		const UGSymbolGroup *FindChildGroupWithID(UGint nID) const;	
		//! 根据组名在本组及以下查找组
		const UGSymbolGroup *FindChildGroup(const UGString& strChildName) const;
				
		UGbool IsModified() const;
		void SetModifiedFlag(UGbool bModified = true);
		
		//! 根据ID在本组及以下进行排序
		void SortByID();
		
	protected:
		
		//! 该组的名称
		UGString                m_strName;       
		
		UGbool m_bModified;
		
		//! 该组隶属于的库
		UGSymbolLib*            m_pSymbolLib;    
		
		//! 该组的父组，如果m_pParentGroup为NULL，表示其为根组
		UGSymbolGroup*          m_pParentGroup;             
		
		//! 该组下的子组数组
		UGArray<UGSymbolGroup*> m_ChildGroups;
		
		//! 该Group组织的符号(Item)，记录其ID；
		//! 注:一个Group中不允许有相同ID的Item存在,同时整个树中的Item所对应的符号ID都是唯一的
		UGArray<UGint>          m_Items;
		
	};
	
}

#endif


