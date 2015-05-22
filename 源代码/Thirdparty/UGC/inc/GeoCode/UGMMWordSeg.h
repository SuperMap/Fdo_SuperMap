/* 
	\file UGDictionary.h
	\brief 中文地址模糊分词类
	\author ugc team
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>更新说明：</b>
	<em>1、第一条说明。</em>
	<em>2、第二条说明。</em>
*/

#ifndef UGMMWORDSEG_H
#define UGMMWORDSEG_H

#include "Base/UGArray.h"
#include "Base/UGString.h"
#include "Base/UGProgress.h"
#include "Base/UGCallback.h"
#include "Base/UGFileStdio.h"


namespace UGC {

	class UGDictionary;
	
	class GEOCODE_API UGMMWordSeg
	{
	public:

		UGMMWordSeg();
		
        virtual ~UGMMWordSeg();
		
		//!	\brief 设置分词需要的词典
		//!	\param DictCoreMM 分词需要的词典[in]
		//!	\return 设置成功返回TRUE,否则返回FALSE
		UGbool SetDict(UGDictionary &DictCoreMM);

		//!	\brief	字符串最大批配法分词函数	
		//!	\param StringSrc 字符串[in]
		//!	\return 返回分词后的结果字符串
		//!	\remarks 对一个字符串进行最大批配法分词函数
		UGString SegmentHzStrMM ( UGString StringSrc); 
		
		//!	\brief  句子最大批配法分词函数
		//!	\param StringSrc 字符串[in]
		//!	\return 返回分词后的结果字符串
		//!	\remarks	        对句子进行最大匹配法分词处理的函数
		UGString SegmentSentenceMM ( UGString StringSrc);   
		
	private:
		//!	\brief 最大匹配法字典
		UGDictionary *m_pdictCoreMM; 
		
	};
	
	class GEOCODE_API UGMPWordSeg
	{
	public:
		UGMPWordSeg();
		
        virtual ~UGMPWordSeg();

		//!	\brief 设置分词需要的词典
		//!	\param DictCoreMP 分词需要的词典[in]
		//!	\return 设置成功返回TRUE,否则返回FALSE
		UGbool SetDict(UGDictionary &DictCoreMP);

		//!	\brief	字符串最大批配法分词函数	
		//!	\param StringSrc 字符串[in]
		//!	\return 返回分词后的结果字符串
		//!	\remarks 对一个字符串进行最大批配法分词函数
		UGString SegmentHzStrMM ( UGString StringSrc); 
		
		//!	\brief  句子最大批配法分词函数
		//!	\param StringSrc 字符串[in]
		//!	\return 返回分词后的结果字符串
		//!	\remarks	        对句子进行最大匹配法分词处理的函数
		UGString SegmentSentenceMM ( UGString StringSrc);   

		//!	\brief 最大概率法分词函数
		//!	\param StringSrc 目标串[in]
		//!	\return 返回分词处理后的字符串
		//!	\remarks 最大概率法分词函数
		UGString SegmentHzStrMP(UGString StringSrc);
		
		//!	\brief 句子最大概率法分词处理的函数
		//!	\param StringSrc 目标串[in] 
		//!	\return 返回分词处理后的字符串 
		//!	\remarks 对句子进行最大概率法分词处理的函数 
		UGString SegmentSentenceMP(UGString StringSrc);
		
		//! \brief 汉字串的原子切割函数
		//!	\param StringSrc  汉字字符串[in]
		//!	\return 返回汉字分词结果，将每个汉字切开了
		//!	\remarks 注意的是非汉字部分如果连在一起就不切分了
		UGString CHWordAtomSegment(UGString StringSrc);

		//! \brief 字符串的原子切割
		//!	\param StringSrc  字符串[in]
		//!	\return 字符串的原子切割的切分结果
		//!	\remarks 注意的是非汉字部分如果连在一起就不切分了
		UGString AtomSegment (UGString StringSrc);

		UGbool IsInDict(UGString StringSrc);

	private:

		//!	\brief 获取所有候选词的函数，最大概率法分词程序调用
		//!	\param StringSrc 目标串[in]
		//!	\return 返回处理的字符串
		//!	\remarks 获取所有候选词的函数，最大概率法分词程序调用
		UGshort GetTmpWords(UGString StringSrc);
		
		//!	\brief 计算候选词的最佳前趋词的函数
		//!	\param nPos	词语的索引位置[in]
		//!	\remarks 计算候选词的最佳前趋词的函数
		void GetPrev(UGint nPos);

	private:
		//!	\brief最大概率法需要的分词词典
		UGDictionary *m_pdictCoreMP; 

	};
}

#endif
