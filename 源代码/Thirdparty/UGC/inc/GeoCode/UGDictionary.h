/* 
	\file UGDictionary.h
	\brief 中文地址模糊查询词典类
	\author ugc team
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>更新说明：</b>
	<em>1、第一条说明。</em>
	<em>2、第二条说明。</em>
*/

#ifndef UGDICTIONARY_H
#define UGDICTIONARY_H

#include "Base/UGArray.h"
#include "Base/UGString.h"
#include "Base/UGProgress.h"
#include "Base/UGCallback.h"
#include "Base/UGFileStdio.h"   //文件头文件

#include "UGGeoCodeDefine.h"
#include "UGFuzzySearchTypes.h"

namespace UGC {

class   GEOCODE_API UGDictionary  
{
public:

	UGDictionary();

    virtual ~UGDictionary();

	//!	\brief	基于二进制文件的词典载入函数
	//!	\param pcFileName 词典名称[in]
	//!	\param bReset	是否重新设置
	//!	\return 加载词典成功返回TRUE，否则返回FALSE
	//!	\remarks	将二进制文件转化为词典结构
	UGbool Load(const UGchar *pcFileName,UGbool bReset = FALSE);

	//!	\brief	二进制转化为文本文件
	//!	\param pcFileName 词典名称[in]
	//!	\param sFileSavename 输出文件名称[in]
	//!	\param bReset 是否重新设置[in]
	//!	\return 如果转化成功返回TRUE，否则返回FALSE
	//!	\remarks 词典载入
	UGbool DictBinaryToTxt(UGchar *pcFileName,UGchar *sFileSavename,UGbool bReset=FALSE);

	//! \brief 追加文本格式的词条
    //! \param pcFileName 文本名称[in]
	//!	\return 如果转化成功返回TRUE，否则返回FALSE
	//!	\remarks 词典载入
	UGbool AddWordItemsFromTxt(UGchar *pcFileName);

	//! \brief 删除文本格式的词条
    //! \param pcFileName 文本名称[in]
	//!	\return 如果转化成功返回TRUE，否则返回FALSE
	//!	\remarks 词典载入
	UGbool DelWordItemsFromTxt(UGchar *pcFileName);

	//!	\brief 词典合并
	//!	\param dict2	传入字典名称[in]
	//!	\return 如果词典合并成功返回TRUE，否则返回FALSE
	//!	\remarks 合并词典
	UGbool Merge(UGDictionary &DictMerge);

	//!	\brief	得到词语频率
	//! \param pcWord 输入词语[in]
	//! \return 返回词语频率，如果词典没有这个词语,就返回0
	UGint GetFreq( UGchar *pcWord);

	//!	\brief	找词语
	//!	\param pcWord 输入词语[in]
	//!	\return 找到词语返回TRUE，否则返回FALSE
	UGbool IsGetWord(UGchar *pcWord);

	//!	\brief	找词语
	//!	\param pcWord 输入词语[in]
	//!	\return 找到词语返回索引，否则返回-1
	UGint IsContainWord(UGchar *pcWord);

	//!	\brief	得到词语频率
	//! \param pcWord 输入词语[in]
	//! \return 返回词语频率，如果词典没有这个词语,就返回0
	UGint GetSameWordCount( UGchar *pcWord);

	//!	\brief	返回词语总的个数
	//! \return 返回词典中词语总的个数
	UGint GetWordCount( );

	//!	\brief	返回词典某个位置上的词语信息
	//!	\param  nIndex 词语在词典中的位置，取值范围为[0,nCount-1]，nCount=GetWordCount( )[in]
	//!	\param  strWord		索引上对应的词语[Out]
	//!	\param  nFrequency	词语频率信息[Out]
	//! \return 如nIndex不在取值范围内，则返回false。
	UGbool GetWord( UGint nIndex,UGString & strWord,UGint&nFrequency);

	//!	\brief	加载词语
	//!	\param pcWord 词语指针[in]
	//!	\param nFrequency 词语频率信息[in]
	//!	\return 加载词语成功返回TRUE，否则返回FALSE
	UGbool AddItem(UGchar *pcWord,UGint nFrequency);

	//!	\brief	加载词语
	//!	\param pcWord 词语指针[in]
	//!	\return 加载词语成功返回索引，否则返回-1；
	UGint AddItem(UGchar *pcWord);

	//!	\brief	找词语的索引
	//!	\param pcWord 词语指针[in]
	//!	\return 词语成功返回索引，否则返回-1；
	UGint GetWordnIndex(UGchar *pcWord);

	//!	\brief	删除词条
	//!	\param pcWord	词语[in]
	//!	\return 删除词语就返回TRUE，否则返回FALSE
	UGbool DelItem(UGchar *pcWord);

	//!	\brief	词典保存
	//!	\param pcFileName 词典名称[in]
	//!	\return 成功保存词典就返回TRUE，否则返回FALSE
	UGbool SaveAs(UGchar *pcFileName);

	//!	\brief	词典保存文本格式
	//!	\param pcFileName 词典名称[in]
	//!	\return 成功保存词典就返回TRUE，否则返回FALSE
	UGbool SaveAsTxt( UGchar *pcFileName ,UGbool bStandard = TRUE);

	//////////////////////////////////////////////////////////////////////////
	//最新添加

	//!	\brief	基于文本文件的词典载入函数
	//!	\param pcFileName 词典名称[in]
	//!	\param bReset	是否重新设置
	//!	\return 加载词典成功返回TRUE，否则返回FALSE
	//!	\remarks	将二进制文件转化为词典结构
	UGbool LoadFromTxt(const UGchar *pcFileName,UGbool bReset = FALSE);
	
	//!	\brief	文本文件转化为二进制
	//!	\param pcFileName 词典名称[in]
	//!	\param sFileSavename 输出文件名称[in]
	//!	\param bReset 是否重新设置[in]
	//!	\return 如果转化成功返回TRUE，否则返回FALSE
	//!	\remarks 词典载入
	UGbool DictTxtToBinary(UGchar *pcFileName,UGchar *sFileSavename,UGbool bReset=FALSE);

	//!	\brief	词典保存文本格式
	//!	\param pcFileName 词典名称[in]
	//!	\return 成功保存词典就返回TRUE，否则返回FALSE
	UGbool SaveAsStandardTxtForm( UGchar *pcFileName );

	//!	\brief	得到词语频率
	//! \param pcWord 输入词语[in]
	//! \return 返回词语频率，如果词典没有这个词语,就返回0
	UGbool AddUseCount( UGchar *pcWord);

private:

	//!	\brief			判断字符串类型
	//!	\param sChar 词语指针[in]
	//!	\return 返回字符串类型
	//!	\remarks 使用中只要循环调用该接口 就可以了
	UGint GetCharType( UGuchar *pucChar);

	//!	\brief  得到词语类型
	//!	\param pcWord 词语[in]
	//!	\return 返回词语类型
	UGint  GetWordType(UGchar *pcWord);

	//!	\brief			判断是否都是汉字
	//!	\param sString	判断的字符串指针[in]
	//!	\return 如果都是汉字就返回TRUE，否则返回FALSEe
	UGbool IsAllChinese(UGuchar *pucString);

	//!	\brief	            找汉字
	//!	\param pucString	    目标串指针[in]
	//!	\param pstrCharSet	源串[in]
	//!	\return 汉字是否在源串中开始的指针
	UGchar *CCFind(const UGchar *pucString, const UGchar *pstrCharSet);

	//!	\brief	字典优化
	//!	\return 如果优化词典就返回TRUE，否则返回FALSE
	void Optimum();

	//!	\brief	函数预处理
	//!	\param pcWord 词语[in]
	//!	\param nId 索引位置[out]
	//!	\param sWordRet 去掉首汉字的词语指针[out]
	//!	\return 如果找到相关的位置就返回TRUE，否则返回FALSE
	//!	\remarks	函数预处理，去掉首汉字的词语指针
	UGbool PreProcessing(UGchar *pcWord,UGint *pnId,UGchar *pcWordRet,UGbool bAdd=FALSE);
	
private:
	//!	\brief 词典索引表数组
	INDEX_TABLE   m_IndexTable[UG_GEOCODE_CC_NUM];

protected:
	
	//!	\brief	在原始表中查询函数
    //!	\param nInnerCode 传入内码位置[in]
	//!	\param pcWord 词语信息[in]
	//!	\return 如果查找到就返回TRUE，否则返回FALSE
	//!	\remarks	在词典表中查询的函数
	UGbool FindInOriginalTable(UGint nInnerCode,UGchar *pcWord,UGint *pnPosRet=0);
};

}

#endif
