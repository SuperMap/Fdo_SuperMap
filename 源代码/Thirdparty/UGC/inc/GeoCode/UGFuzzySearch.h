/* 
	\file UGDictionary.h
	\brief 中文地址模糊查询模糊查询类
	\author ugc team
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>更新说明：</b>
	<em>1、第一条说明。</em>
	<em>2、第二条说明。</em>
*/

#ifndef UGFUZZYSEARCH_H
#define UGFUZZYSEARCH_H

namespace UGC {

	class UGDictionary;
	class UGMMWordSeg;
	class UGAddressData;
	//查询类函数
	class GEOCODE_API UGFuzzySearch
	{
	public:

		UGFuzzySearch();

		//!	\brief	完整的析构函数，但是需要解决大数据的内存泄露的问题
        virtual ~UGFuzzySearch();

		//!	\brief 设置加载地图数据类变量
		//! \param AddressData 排序首地址指针[in]
		//! \return 如果设置成功返回TRUE,否则FALSE
		UGbool SetLoadMapData(UGAddressData &AddressData);

		//!	\brief 设置指定查询的数据集nLayer
		//! \param nLayer 指定的数据集查询[in]
		//! \return 如果设置成功返回TRUE,否则返回FALSE
		UGbool SetDatasetnLayer(UGint nLayer);

		//!	\brief 删除指定查询的数据集nLayer
		//! \return 如果设置成功返回TRUE,否则返回FALSE
		UGbool RemoveSearchnLayers();

		//!	\brief 设置指定查询的数据集nLayer
		//! \param arrnLayers 数据集指针数组[in]
		//! \return 如果设置成功返回TRUE,否则返回FALSE
		UGbool SetSearchnLayers(UGArray<UGint> &arrnLayers);

		//!	\brief 数据集地址过滤函数
		//! \param nLayer 指定图层[in]
		//! \param arrAddressSrc 原始地址信息[in]
		//! \param arrAddressRes 过滤后的地址信息[in]
		//! \return 数据集地址过滤后返回TRUE,否则返回FALSE
		UGbool  DatasetAddressFilter(UGint &nLayer,UGArray<CHAddressDataID> &arrAddressSrc,UGArray<CHAddressDataID> &arrAddressRes);
	
		//!	\brief 模糊查找函数
		//! \param strAddress 插入地址信息[in]
		//! \param arrnLayers 指定查询图层数组[in]
		//! \param arrLocationResult 查询结果[out]
		//! \return 如果得到地址就返回TRUE,否则返回FALSE
		UGbool FuzzyMatchSearch(UGString &strWordAddress,UGArray<UGint> &arrnLayers,UGArray<UGCHAddressLocation> &arrLocationResult);

		//!	\brief 模糊查找函数
		//! \param strAddress 插入地址信息[in]
		//! \param arrnLayers 指定查询图层数组[in]
		//! \param arrLocationResult 查询结果[out]
		//! \return 如果得到地址就返回TRUE,否则返回FALSE
		UGbool FuzzySearch(UGString &strWordAddress,UGArray<UGint> &arrnLayers,UGArray<UGCHAddressLocation> &arrLocationResult);

		//! 中文地址查询用的是这个接口
		//! 查询函数函数
		//! \param strAddress 插入地址信息[in]
		//! \param arrnLayers 指定查询图层数组[in]
		//! \param arrLocationResult 查询结果[out]
		//! \return 如果得到地址就返回TRUE,否则返回FALSE
        UGbool AptitudinallySearch(UGString &strWordAddress,UGArray<UGint> &arrnLayers,UGArray<UGCHAddressLocation> &arrLocationResult);

		//!	\brief 基于引擎的精确查找函数
		//! \param strAddress 插入地址信息[in]
		//! \param arrnLayers 指定查询图层数组[in]
		//! \param arrLocationResult 查询结果[out]
		//! \return 如果得到地址就返回TRUE,否则返回FALSE
		UGbool AccurateSearchEngine(UGString &strWordAddress,UGArray<UGint> &arrnLayers,UGArray<UGCHAddressLocation> &arrLocationResult);

		//!	\brief 精确查找函数
		//! \param strAddress 插入地址信息[in]
		//! \param arrnLayers 指定查询图层数组[in]
		//! \param arrLocationResult 查询结果[out]
		//! \return 如果得到地址就返回TRUE,否则返回FALSE
		UGbool AccurateSearch(UGString &strWordAddress,UGArray<UGint> &arrnLayers,UGArray<UGCHAddressLocation> &arrLocationResult);

		//!	\brief 多算子操作查找函数
		//! \param arrSearchMode 解析模式数组[in]
		//! \param strAddress 插入地址信息[in]
		//! \param arrnLayers 指定查询图层数组[in]
		//! \param arrLocationResult 查询结果[out]
		//! \return 如果得到地址就返回TRUE,否则返回FALSE
		UGbool MultiSearch(UGArray<UGCHSearchMode> &arrSearchMode,UGArray<UGint> &arrnLayers,UGArray<UGCHAddressLocation> &arrLocationResult);

		//!	\brief	解析查询模式
		//! \param strWordAdressArray 地址信息[in]
		//关键词之间的关系可以是“和”、“或”、“非”（and、or、not）。
		UGbool GetSearchMode(UGString strAddress,UGArray<UGCHSearchMode> &arrSearchMode);

		//!	\brief	解析查询模式
		//! \param strWordAdressArray 地址信息[in]
		//关键词之间的关系可以是“和”、“或”、“非”（and、or、not）。
		UGbool GetAccurateSearch(UGString &strAddress);

		//!	\brief	得到查询模式
		//! \param chPos 地址解析字符[in]
		UGbyte GetMode(UGchar chPos);
		
private:
	   //为了演示, 需要添加几个算子
	   //求交算子
	   
	   //求并算子
	  
	   //求减算子
	   
	   //精确算子,可以归到求交算子里面去

	/*
	   //原子求交查询；
	void SearchAtomInterSection(CString &strWordAddress, CArray<LONG,LONG> &arrnLayers,CArray<CHAddressDataID,CHAddressDataID&> &strAddressArray);
	
	//原子求并查询：
	void SearchAtomUnion(CString &strWordAddress, CArray<LONG,LONG> &arrnLayers,CArray<CHAddressDataID,CHAddressDataID&> &strAddressArray);
    
	//原子求差查询：
    void SearchAtomDifferences(CString &strWordAddress, CArray<LONG,LONG> &arrnLayers,CArray<CHAddressDataID,CHAddressDataID&> &strAddressArray);
	
	//分词求交查询；
	void SearchSegInterSection(CString &strWordAddress, CArray<LONG,LONG> &arrnLayers,CArray<CHAddressDataID,CHAddressDataID&> &strAddressArray);
	
	//分词求并查询：
	void SearchSegUnion(CString &strWordAddress, CArray<LONG,LONG> &arrnLayers,CArray<CHAddressDataID,CHAddressDataID&> &strAddressArray);
	
    //分词求差查询：
	void SearchSegDifferences(CString &strWordAddress, CArray<LONG,LONG> &arrnLayers,CArray<CHAddressDataID,CHAddressDataID&> &strAddressArray);
	
	//求交查询；
	void SearchWholeInterSection(CString &strWordAddress, CArray<LONG,LONG> &arrnLayers,CArray<CHAddressDataID,CHAddressDataID&> &strAddressArray);
	
	//求并查询：
	void SearchWholeUnion(CString &strWordAddress, CArray<LONG,LONG> &arrnLayers,CArray<CHAddressDataID,CHAddressDataID&> &strAddressArray);
    
	//求差查询：
    void SearchWholeDifferences(CString &strWordAddress, CArray<LONG,LONG> &arrnLayers,CArray<CHAddressDataID,CHAddressDataID&> &strAddressArray);
	*/
         
	//为了提高查询的稳定性和智能性，添加新的算子来实现这样的查询


	    //!	\brief	地图数据nID的求并
	    //! \param strWordAdressArray 地址信息[in]
	    //!\param strAddressArray 保存地图nID[out]   
		void UnionORMapIDs(UGStrArray strWordAdressArray, UGArray<UGint> &arrnLayers,UGArray<CHAddressDataID> &strAddressArray);

	    //!	\brief	地图数据nID的求并
		//! \param strWordAdressArray 地址信息[in]
		//!\param strAddressArray 保存地图nID[out]   
		void UnionMapIDs(UGStrArray strWordAdressArray, UGArray<UGint> &arrnLayers,UGArray<CHAddressDataID> &strAddressArray);
		
		//!	\brief	地图数据nID的最小求并
		//! \param strWordAdressArray 地址信息[in]
		//! \param strAddressArray 保存地图IDs[out]   
		void UnionMinMapIDs(UGStrArray strWordAdressArray, UGArray<UGint> &arrnLayers,UGArray<CHAddressDataID> &strAddressArray);
		
		//!	\brief	地图数据nID的求交
		//! \param strWordAdressArray 地址信息[in]
		//!\param strAddressArray 保存地图IDs[out]   
		void InterSectMapIDs(UGStrArray strWordAdressArray, UGArray<UGint> &arrnLayers,UGArray<CHAddressDataID> &strAddressArray);
		
		//!	\brief	地图数据nID的最大求交	
		//!\param strWordAdressArray 地址信息[in]
		//!\param strAddressArray  保存地图IDs[out]   
		void InterSectMaxMapIDs(UGStrArray strWordAdressArray, UGArray<UGint> &arrnLayers,UGArray<CHAddressDataID> &strAddressArray);
		
		//!	\brief	两个地图地址信息数组的合并函数	
		//! \param StrAdressArray1 地址信息1[in]
		//! \param StrAdressArray2  地址信息2[in] 
		//! \param StrAdressArrayRes  合并后的地址信息结果[out]
		//! \return 合并成功返回TRUE，否则返回FALSE
		UGbool MergeIDs(UGArray<CHAddressDataID> &strAdressArray1, UGArray<CHAddressDataID> &strAdressArray2,UGArray<CHAddressDataID> &strAdressArrayRes);
		
		//!	\brief	查找字符串方法，这个主要思想是KMP模式匹配的方法	
		//! \param pcStrSource 源字符串[in]
		//! \param lpszFind  查找字符串[in]
		//! \param nStart  在pcStrSource开始查找的位置[in]
		//! \return 查找成功就返回匹配位置，否则返回-1
		//! \remarks：在pcStrSource中查找字符串lpszFind，lpszFind中可以包含通配字符‘?’
		UGint FindingStringOR(const UGchar* pcStrSource, const UGchar* pcStrFind, UGint nStart  = 0 );

		//!	\brief	查找字符串方法，这个主要思想是KMP模式匹配的方法	
		//! \param pcStrSource 源字符串[in]
		//! \param lpszFind  查找字符串[in]
		//! \param nStart  在pcStrSource开始查找的位置[in]
		//! \return 查找成功就返回匹配位置，否则返回-1
		//! \remarks：在pcStrSource中查找字符串lpszFind，lpszFind中可以包含通配字符‘?’
		UGint  FindingString(const UGchar* pcStrSource, const UGchar* pcStrSFind, UGint nStart = 0);
		
		//!	\brief	带通配符的字符串匹配	
		//! \param pcStrSource 源字符串[in]
		//! \param lpszMatch  查找字符串[in]
		//! \param bMatchCase  bMatchCase为0，不区分大小写，否则区分大小写[in]
		//! \return 如果匹配，返回TRUE；否则返回FALSE
		//! \remarks 通配符意义：
		//! \		‘*’	代表任意字符串，包括空字符串；
		//! \		‘?’	代表任意一个字符，不能为空；
		UGbool MatchingString(const UGchar* pcStrSource, const UGchar* pcStrMatch, UGbool bMatchCase = TRUE);
		
		//!	\brief	多重匹配函数
		//! \param pcStrSource 源字符串[in]
		//! \param lpszMatch  查找字符串[in]
		//! \param nMatchLogic  nMatchLogic = 0, 不同匹配求或，else求与[in]
		//! \param bRetReversed  bRetReversed = 0, 匹配返回TRUE；否则不匹配返回TRUE[in]
		//! \return 如果bRetReversed = 0, 匹配返回TRUE；否则不匹配返回TRUE
		//! \remarks：多重匹配，不同匹配字符串之间用‘,’隔开
		//! \			如：“*.h,*.cpp”将依次匹配“*.h”和“*.cpp”
		UGbool MultiMatching(const UGchar* pcStrSource, const UGchar* pcStrMath, UGint nMatchLogic = 0, UGbool bRetReversed = 0, UGbool bMatchCase = TRUE);	
		
		//!	\brief 检查字符串是否顺序匹配
		//! \param sAdressSrc 被匹配串[in]
		//! \param sAdress 匹配串[in]
		//! \param nCount 匹配串的个数[out]
		//! \return 如果按照顺序匹配返回TRUE,否则返回FALSE
		UGbool IsOrderMatch(const UGchar* pcAdressSrc,UGStrArray sAdress,UGint &nCount);
		
		//!	\brief 检查字符串是否全字匹配
		//! \param sAdressSrc 被匹配串[in]
		//! \param sAdress 匹配串[in]
		//! \return 如果按全字匹配返回TRUE,否则返回FALSE
		UGbool IsFullMatch(const UGchar* pcAdressSrc,UGStrArray sAdress);
		
		//!	\brief 计算分词结果后缀的个数,返回相应的后缀索引号的数组
		//! \param strAddress 检查字符串[in]
		//! \param ndex 词索引位置数组[out]
		//! \return 返回经过计算分词结果后缀的个数,同时得到相应的后缀索引号码的数组
		UGint  SuffixCount(UGStrArray &strAddress,UGArray<UGint> &Index);
		
		//!	\brief 计算分词结果后缀的个数,
		//! \param strAddress 检查字符串[in]
		//! \return 返回经过计算分词结果后缀的个数
		UGint  GetSuffixCount(UGString &strAddress);

		//!	\brief 检查是否有后缀,有就删除后缀
		//! \param strAddress 检查字符串[in]
		//! \return 如果删除成功就返回TRUE,否则返回FALSE
		UGbool  IsDelSuffix(UGStrArray &strAddress);

		//!	\brief 将对应的nID信息对应到相关的属性字段
		//! \param strAddress 地图地址信息[in]
		//! \param strWordAddress 地址字段值[out]
		//! \return 如果得到地址就返回TRUE,否则返回FALSE
		UGbool GetMapIDString( CHAddressDataID &strAddress ,UGString &strWordAddress );
	
		//!	\brief 查找分词查找相关地图信息函数
		//! \param strWordAddress 输入查找的地址串[in]
		//! \param strAddressArray 查找到的地图信息[out]
		void Search(UGString &strWordAddress, UGArray<UGint> &arrnLayers,UGArray<CHAddressDataID> &strAddressArray);

		//!	\brief 查找分词查找相关地图信息函数
		//! \param strWordAddress 输入查找的地址串[in]
		//! \param strAddressArray 查找到的地图信息[out]
		void SearchMinSeg(UGString &strWordAddress, UGArray<UGint> &arrnLayers,UGArray<CHAddressDataID> &strAddressArray);

		//!	\brief 查找分词查找相关地图信息函数
		//! \param strWordAddress 输入查找的地址串[in]
		//! \param strAddressArray 查找到的地图信息[out]
		void SearchAccurate(UGString &strWordAddress, UGArray<UGint> &arrnLayers,UGArray<CHAddressDataID> &strAddressArray);
		
		//!	\brief 查找分词查找相关地图信息函数
		//! \param strWordAddress 输入查找的地址串[in]
		//! \param strAddressArray 查找到的地图信息[out]
		void SearchUnion(UGString &strWordAddress, UGArray<UGint> &arrnLayers,UGArray<CHAddressDataID> &strAddressArray);

		//!	\brief 处理多个词语后缀的函数
		//! \param strWordAddress 输入待处理的地址信息[in]
		//! \return 返回处理后的地址串
		UGString DelSuffex(UGString &strWordAddress);
		
		//!	\brief 通过切分汉语地址串原子单字切分查找相关地图信息的函数
		//! \param strWordAddress 输入查找的地址串[in]
		//! \param strAddressArray 查找到的地图信息[out]
		void SearchBySingleWord(UGString &strWordAddress, UGArray<UGint> &arrnLayers,UGArray<CHAddressDataID> &strAddressArray);

		//!	\brief 通过切分汉语地址串原子单字切分查找相关地图信息的函数
		//! \param strWordAddress 输入查找的地址串[in]
		//! \param strAddressArray 查找到的地图信息[out]
		void SearchBySingleWordUnion(UGString &strWordAddress, UGArray<UGint> &arrnLayers,UGArray<CHAddressDataID> &strAddressArray);
		
		//!	\brief 计算分数函数
		//! \param StrMapAddress 地图地址信息[in]
		//! \param strAddress 输入查询的地址[in]
		//! \return 返回经过计算匹配的分数
		//! \remarks 将计算的分数经过标准化转化到0-100之间 
		UGdouble ComputeScore(UGString &StrMapAddress, UGString &strAddress);

		//!	\brief 计算分数函数
		//! \param StrMapAddress 地图地址信息[in]
		//! \param strAddress 输入查询的地址[in]
		//! \return 返回经过计算匹配的分数
		//! \remarks 将计算的分数经过标准化转化到0-100之间 
		UGdouble ComputeScore(UGString &StrMapAddress, UGbool bFullMatch , UGbool bOrderMatch ,UGbool bSegSucess = TRUE);

		//!	\brief 结果插入函数
		//! \param location 查询到的地图信息[in]
		//! \param ArrLocationResult 地图信息数组[in]
		//! \return 如果返回TRUE
		//! \remarks 将地图信息插入到已知的地图信息数组中
		UGbool InsertLocation(UGCHAddressLocation location,UGArray<UGCHAddressLocation> &arrLocationResult);
private:
	    //!	\brief 加载图层指针
	    UGAddressData * m_pAddressData;

		//!	\brief 是否指定最小分数
		UGbool m_bSetMinSore;
		
		//! \brief 最低匹配分数 大于0小于100 缺省为50分
		UGint m_nMinMatchScore	;

		//! \brief 指定查询数据集
		UGArray<UGint> m_ArrnLayers;
		
		//! \brief 数据集		
		UGDatasetVector * m_pDtSet;
		
		//! \brief 属性字段
		UGFieldInfo m_FieldInfo ;

		//! \brief 地址字段名字
		//! \remarks "Name"、"StrName"等
		UGString m_ArrFieldName;
		
};

}

#endif
