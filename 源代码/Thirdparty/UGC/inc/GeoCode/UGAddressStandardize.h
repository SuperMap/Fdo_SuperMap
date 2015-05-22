#ifndef UGADDRESSSTANDARDIZE_H
#define UGADDRESSSTANDARDIZE_H

#include "Base/ugdefs.h"
#include "Base/UGArray.h"
#include "Base/UGString.h"

#include "Engine/UGDatasetVector.h"
#include "Engine/UGDataSource.h"
#include "Engine/UGDataset.h"
#include "Engine/UGRecordset.h"
#include "Engine/UGDataSource.h"
#include "Engine/UGQueryDef.h"


#include "UGGeoCodeDefine.h"

/*!
   **************************************************************************************
    \file     UGAddressStandardize.h
   **************************************************************************************
    \author   裘立、郭会
    \brief    地址标准化类                                                             
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 1997-2006 SuperMap GIS Technologies,Inc.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2006-06-21  郭会    初始化版本.       先实现英文街道地址标准化          <br>
   **************************************************************************************
   
   **************************************************************************************
   ********							修改记录									*********
   **************************************************************************************
   2006-06-29	郭会	完成地址解析(仅支持英文街道地址，但预留接口),比较ArcMap实现
   **************************************************************************************
*/


namespace UGC {
	
/* 词典树结点*/
struct DicTreeNode
{
	UGchar m_ch				;				// 该结点代表的字母
	DicTreeNode * pRChild	;				// 兄弟结点 
	DicTreeNode * pLChild	;				// 孩子结点 
	UGString m_strAb		;				// 标准化单词
	UGString m_strWordType	;				// 该单词的类型
	UGbool m_bIsEndNode		;				// 可否作为结束符

};

/* 词典树 用于对单词的快速检索*/
class GEOCODE_API UGDictionaryTree
{
	/*	词典树的设计原理
	 *	词典树中，一个结点如果包含有左孩子，那么左孩子是该结点的后一个字母
	 *	词典树中，一个结点如果包含有右孩子，那么右孩子与该结点有相同的单词前缀
	 *	例如:
	 *						A
	 *					   / \ 	
	 *					  C	  D
	 *					 / \  /	
	 *					E   F G
	 *	对于该树:	D是A的右孩子，那么A与D有相同的前缀(这里为空)	F是C的前缀 说明有单词组合AC××、AF××				
	 *				E是C的左孩子，那么E的前缀就是C，则构成单词ACE.		
	 *	假设每个结点都有结束符号 那么该树有单词:ACE、AC、A、AF、DG			
	 */
	
public:

	UGDictionaryTree();
	virtual ~UGDictionaryTree();


	/*!	\brief			向树添加一个新的单词
	*	\param strWord	添加的单词
	*	\remarks		使用中只要循环调用该接口 就可以了
	*/
	UGbool AddNewWord( UGString  strWord ,UGString strAb ,UGString strType);

	/*!	\brief			查单词表
	*	\param strWord	查找的单词
	*	\return			返回该单词的最后一个结点；如果没有找到 返回null
	*/
	DicTreeNode * FindWord( UGString  strWord );
	
private:

	/*!	\brief	获取一个新的结点	
	*	\param ch	该结点所代表的字母
	*/
	DicTreeNode * GetNewNode( UGchar ch );

	/*!	\brief	从右孩子中查找结点
	*	\param ch	传入父亲结点
	*	\param ch	传入要查找的字母
	*	\remarks	该方法是在一棵树中，知道一个结点，顺序查找该结点和其右边孩子
	*/
	DicTreeNode * FindNodeFromRChild(DicTreeNode * pParent ,UGchar ch ,UGbool bAddNewWhenFaild = FALSE );

	/*!	\brief			删除一个结点及其所有的孩子 	*/
	UGbool DeleteNodeAndChild( DicTreeNode * pDicTreeNode );

private:
	DicTreeNode * m_pRoot ;		// 根结点

};

class GEOCODE_API UGAddressStandardize  
{
public:

	/*!	\brief 地址语种 */
	enum SmLanguageType
	{
		SMChinese	= 1,			// 中文
		SMEnglish	= 2				// 英文
	};

	/*!	\brief 地址类型 */
	enum SmAddressType
	{
		SMStreet	= 1,			// 街道
		SMZone		= 2				// 小区
	};

	UGAddressStandardize();
	virtual ~UGAddressStandardize();
	

	/*!	\brief	地址标准化接口	
	  *	\param strAddress	传入地址串 例如: 380 New York
	  *	\remarks 在调用该接口前，必须先设置地址的种类、语种以及标准地址表
	  *	\remarks 解析结构将存储在m_strArrFieldValue中
	  *	\remarks 不支持交叉道口这种形式 在外部处理然后传入即可
	  */
	UGbool StandardizeAddress(UGString  strAddress);

	/*!	\brief	批量地址标准化接口	
	  *	\param pDtVector	需要标准化的数据集
	  *	\param strFieldName	标准化的字段名称
	  *	\param strNewDtName	存储结果的数据集的名称，如果为空 结果将直接写入到pDtVector中
	  *	\remarks 不支持交叉道口这种形式 在外部处理然后传入即可
	  */
	UGbool StandardizeAddress(UGDatasetVector * pDtVector,UGString  strFieldName, UGString strNewDtName = "");

	// 重建词典树
	UGbool ReBuildDicTree();

	UGbool GetResult(UGString & strResult ) ;



	/*!	\brief	设置标准化关键字表 */
	UGbool SetDatasetCLS(UGDatasetVector* pDtCLS);	
	/*!	\brief	获取标准化关键字表*/
	const UGDatasetVector* GetDatasetCLS()const;

	/*!	\brief	设置Word字段*/
	UGbool SetCLSWordField(const UGString& strCLSWord);
	/*!	\brief	获取Word字段*/
	const UGString GetCLSWordField()const;

	/*!	\brief	设置Abbreviation字段*/
	UGbool SetCLSAbField(const UGString& strCLSAb);
	/*!	\brief	获取Abbreviation字段*/
	const UGString GetCLSAbField()const;

	/*!	\brief	设置CLSType字段*/
	UGbool SetCLSTypeField(const UGString& strCLSType);
	/*!	\brief	获取CLSType字段*/
	const UGString GetCLSTypeField()const;

	/*!	\brief	设置地址的语种和类型，必须同时设置才有效	
	  *	\param nLanguageType	地址种类
	  *	\param nAddressType		语种
	  */
	UGbool SetType(UGint nLanguageType , UGint nAddressType);

	/*!	\brief	获取地址字段个数  */
	UGint GetFieldNameCount();

	/*!	\brief	获取地址字段名	
	  *	\param nIndex	字段名字索引 该索引必须介于 0－FieldNameCount之间
	  */
	UGString GetFieldName(UGint nIndex );

	/*!	\brief	获取地址字段值	
	  *	\param nIndex	字段名字索引 该索引必须介于 0－FieldNameCount之间
	  */
	UGString GetFieldValue(UGint nIndex );

	/*!	\brief	设置地址字段值	
	  *	\param nIndex	字段名字索引 该索引必须介于 0－FieldNameCount之间
	  *	\param strValue	字段值
	  */
	UGbool SetFieldValue(UGint nIndex,UGString strValue );
	
	/*!	\brief	获取地址字段值	
	  *	\param strFieldName	
	  */
	UGString GetFieldValue(UGString strFieldName );

	/*!	\brief	设置地址字段值	
	  *	\param strValue	字段值
	  */
	UGbool SetFieldValue(UGString strFieldName ,UGString strValue );
	

	/*!	\brief	是否有效	 */	
	UGbool IsValid();

	// 在数据集中获取一个合法的数据集名称
	UGbool GetFieldValidName(UGDatasetVector * pDtVector ,UGString & strFieldName);


private:
	// USStreet格式类型
	UGbool USStreetStandardize(UGString  strAddress);
	
	// 从单词strAddress中获取数字 返回就是该数字 如果没有数字 就返回空字符串
	UGString GetNumeric(UGString  strAddress);

	// 判断传入的类型是否是关键词类型 比如T、A等
	UGbool IsAddressKeyElem(UGString strType);

	// 判断传入的类型是否是方向关键词类型
	UGbool IsDirectionElem(UGString strType);

	// 判断传入的类型是否是类型关键词类型
	UGbool IsTypeElem(UGString strType);


	// 预标准化
	UGbool PreStand(UGString  & strAddress) ;

	// 后期处理 主要是对有些特殊地址进行处理 在标准化后使用 strAddress就是标准化的时候传入的单词
	UGbool SufStand(UGString   strAddress) ;

	// 设置m_nArrPos变量 例如 将PT赋值为street 则就设置m_nArrPos[1] = 2 (2表示来自m_strArrSplitWord第二个单词)
	UGbool SetFieldPos(UGString strFieldName,int nPos);
	UGint GetFieldPos(UGString strFieldName);



private:
	
	//! \brief 地址语种
	//! \remarks 暂时支持中文、英文，为以后接口扩展
	UGint m_nLanguageType	;
	
	//! \brief 地址种类
	//! \remarks 街道、小区等类型
	UGint m_nAddressType	;

	//! \brief 地址字段名字
	//! \remarks "SN"、"ST"等
	UGStrArray m_strArrFieldName	;

	//! \brief 地址字段值
	//! \remarks "380"、"New York"等
	UGStrArray m_strArrFieldValue	;
	
	//! \brief 地址被空格分开后的有效部分保存 不对外 内部使用(后期处理的时候使用)
	//! \remarks 这里保存的地址是没有经过简写标准化的 
	UGStrArray m_strArrSplitWord	;

	//! \brief 保存解析的地址元素在m_strArrSplitWord中的位置 内部使用(后期处理的时候使用)
	UGArray<UGint> m_nArrPos		;

	//! \brief 地址关键词解析表
	//! \remarks 关键词表中要有三个字段:一般单词(word)、缩写(Abbreviation)、关键词类型(Type)
	UGDatasetVector   * m_pDtCLS;
	UGString	 m_strCLSWordField	;		// 关键词解析表中的单词字段
	UGString	 m_strCLSAbField	;		// 关键词解析表中的缩写字段
	UGString	 m_strCLSTypeField	;		// 关键词解析表中的类型字段

private:
	UGDictionaryTree * m_pDicTree	;		// 私有的辞典树
	UGbool		 m_bReBuildDicTree  ;		// 是否需要重建词典树


};

/* 裘立的想法
 * 写一个地址类，在这个类后派生多个地址类型类，便于控制	
 */

}// end of namespace

#endif

