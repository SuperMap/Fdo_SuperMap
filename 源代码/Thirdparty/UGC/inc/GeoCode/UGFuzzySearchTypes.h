/* 
	\file UGFuzzySearchTypes.h
	\brief 中文地址模糊查询需要的几个结构
	\author ugc team
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>更新说明：</b>
	<em>1、第一条说明。</em>
	<em>2、第二条说明。</em>
*/

#ifndef UGFUZZYSEARCHTYPES_H
#define UGFUZZYSEARCHTYPES_H

namespace UGC {
//词典类需要的结构体

//!	\brief单个词条数据结构
struct tagWordItem
{
	//{{最新添加用来生成新词典
	//!	\brief 使用频率
	//UGint nUseCount; 
	//}}
	//!	\brief 词语长度
	UGint nWordLen     ;
	//!	\brief 频率，出现次数
	UGint nFrequency   ;                 
	//!	\brief 词语指针
	UGchar *pcWord      ;    
	tagWordItem()
	{
		nWordLen = 0;
		nFrequency = 0;
		pcWord = NULL;
	}
};
typedef struct tagWordItem WORD_ITEM,*PWORD_ITEM;

//字典索引表结构
struct tagIndexTable
{
	//!	\brief 个数
	UGint nCount                    ;     
	//!	\brief 词条头
	UGArray<WORD_ITEM> arrWordItemHead;     
	//!	\brief 词条头
	//PWORD_ITEM pWordItemHead;   
	tagIndexTable()
	{
		nCount = 0;
		arrWordItemHead.RemoveAll();
	};
};
typedef struct tagIndexTable INDEX_TABLE;

//加载，查询类需要的结构体
struct CHtagAddressDataID 
{
	//!	\brief 数据集索引
	UGuint nDTIndex;                     
	//!	\brief 数据ID
	UGuint nID; 
	//!	\brief 分词的位置
	//UGint nPos;
};
typedef struct CHtagAddressDataID CHAddressDataID,*PCHMapLayer;

//!	\brief 单个词条数据结构
struct ChtagWordItem
{
	//!	\brief 词语长度
	UGint nWordLen ;        
	//!	\brief 频率，出现次数
	UGint  nCount  ;
	//!	\brief 词语
	UGchar *pcWord  ;  
	//!	\brief  
	UGArray<CHAddressDataID> ChAddressIDs;
};
typedef struct ChtagWordItem CHWORD_ITEM,*PCHWORD_ITEM;
	
//!	\brief 词链数据结构
struct CHtagWordChain
{
	//!	\brief  单个词条
	CHWORD_ITEM data           ;            
	//!	\brief  下个词条
	struct CHtagWordChain *next;           
};
typedef struct CHtagWordChain CHWORD_CHAIN,*PCHWORD_CHAIN;

//!	\brief 字典索引表结构
struct CHtagIndexTable
{
	//!	\brief 个数
	UGint nCount           ;          
	
	//!	\brief 词条头
	//PCHWORD_CHAIN pWordItemHead; 

	UGArray <CHWORD_ITEM> arrWordItems;
	
};
typedef struct CHtagIndexTable CHAdressINDEX_TABLE,*pCHAdressINDEX_TABLE;

//!	\brief 结果数据保存格式
struct UGCHAddressMapData
{
	UGint            m_Len; 
	CHAddressDataID  m_ChAddressIDs;
	UGString         m_MapAdress;
	
};
typedef struct UGCHAddressMapData UGCHMapData;

//!	\brief 结果数据保存格式
struct UGCHAddressLocation
{
	//!	\brief 候选对象匹配状态
	UGint		m_nCandidateState;	
	//!	\brief 该点获得的分数 在0到100之间
	UGdouble	m_nScore		;	
	CHAddressDataID  m_ChAddressIDs;
	UGString    m_MapAdress;	
};

//!	\brief 结果数据保存格式
struct UGCHSearchMode
{
	//!	\brief 候选对象匹配状态
	UGint		m_nSearchMode;	
	//!	\brief 该点获得的分数 在0到100之间
	UGchar		m_chword;
	//!	\brief 切词后地址
	UGString    m_strWordAdress;	
};

//!	\brief 结果分数快速排序需要的比较函数类
class CHResultCompareTemp
{
public:
	
	UGbool operator()(const UGCHAddressLocation& CHResult1, const UGCHAddressLocation& CHResult2) 
	{
		
		if (CHResult1.m_nScore == CHResult2.m_nScore)
		{
			if (CHResult1.m_ChAddressIDs.nDTIndex == CHResult2.m_ChAddressIDs.nDTIndex)
			{
				if (CHResult1.m_ChAddressIDs.nID > CHResult2.m_ChAddressIDs.nID)
				{
					return FALSE;
				}
				else
				{
					return TRUE;
				}
				
			}
			else if (CHResult1.m_ChAddressIDs.nDTIndex > CHResult2.m_ChAddressIDs.nDTIndex)
			{
				return FALSE;
			}
			else
			{
				return TRUE;
			}
		}
		//!	\brief 注意分数是从小到大的哦
		else if (CHResult1.m_nScore < CHResult2.m_nScore)
		{
			return FALSE;
		}
		else
		{
			return TRUE;
		}
	}
};

//!	\brief 数据集ID快速排序需要的比较函数类
class CHMapDataCompareTemp
{
public:
	
	UGbool operator()(const UGCHMapData& CHMapData1, const UGCHMapData& CHMapData2) 
	{
		
		if (CHMapData1.m_ChAddressIDs.nDTIndex == CHMapData2.m_ChAddressIDs.nDTIndex)
		{
			if (CHMapData1.m_ChAddressIDs.nID > CHMapData2.m_ChAddressIDs.nID)
			{
				return FALSE;
			}
			else
			{
				return TRUE;
			}
		}
		else if (CHMapData1.m_ChAddressIDs.nDTIndex > CHMapData2.m_ChAddressIDs.nDTIndex)
		{
			return FALSE;
		}
		else
		{
			return TRUE;
		}
	}
};

//!	\brief 快速排序需要的比较函数类
class CHAddressDataIDCompare
{
public:
	
	UGbool operator()(const CHAddressDataID& CHAddressDataID1, const CHAddressDataID& CHAddressDataID2) 
	{
			if (CHAddressDataID1.nDTIndex < CHAddressDataID2.nDTIndex)
			{
				return TRUE;
			}
			else if (CHAddressDataID1.nDTIndex == CHAddressDataID2.nDTIndex)
			{
				return CHAddressDataID1.nID < CHAddressDataID2.nID;
			}
			else
			{
				return FALSE;
			}
	}
		/*
		
		  if (CHAddressDataID1.nDTIndex == CHAddressDataID2.nDTIndex)
		  {
		  if (CHAddressDataID1.nID > CHAddressDataID2.nID)
		  {
		  return FALSE;
		  }
		  else
		  {
		  return TRUE;
		  }
		  }
		  else if (CHAddressDataID1.nDTIndex > CHAddressDataID2.nDTIndex)
		  {
		  return FALSE;
		  }
		  else
		  {
		  return TRUE;
		  }
	*/
};

class CHAddressDataIDCompareEqual
{
public:
	
	UGbool operator()(const CHAddressDataID& CHAddressDataID1, const CHAddressDataID& CHAddressDataID2) 
	{
		
		if (CHAddressDataID1.nDTIndex == CHAddressDataID2.nDTIndex)
		{
			return CHAddressDataID1.nID == CHAddressDataID2.nID;
		}
		else
		{
			return FALSE;
		}
	}

};

}
#endif

