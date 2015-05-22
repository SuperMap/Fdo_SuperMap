/* 
	\file UGAddressData.h
	\brief 中文地址模糊查询加载数据类
	\author ugc team
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>更新说明：</b>
	<em>1、第一条说明。</em>
	<em>2、第二条说明。</em>
*/

#ifndef UGADDRESSDATA_H
#define UGADDRESSDATA_H

#include "GeoCode/UGDictionary.h"
#include "GeoCode/UGMMWordSeg.h"
#include "Engine/UGDatasetVector.h"



namespace UGC {
	
	class  GEOCODE_API UGAddressData
	{
	public:
	    //!	\brief	构造函数	
		UGAddressData();
		
	     //!	\brief	完整的析构函数，解决了内存泄露的问题
        virtual ~UGAddressData();
		
		//!	\brief	字符类型模式：
		enum SmCharType
		{
			//!	\brief 单字节
			UGChSINGLE	    = 1,	
			//!	\brief 删除符
			UGChDELIMITER	= 2,    
			//!	\brief 汉字
			UGChCHINESE     = 3,    
			//!	\brief 字母
			UGChLETTER	    = 4,	
			//!	\brief 数字
			UGChNUM	        = 5,    
			//!	\brief  索引
			UGChINDEX       = 6,    
			//!	\brief 其他字符
			UGChOTHER       = 7,    
				
		};
		
		//!	\brief 加载词典
		//! \param strDictName 字典名称[in]
		//! \return 加载词典成功返回TRUE,否则返回FALSE
		//! \remarks 加载词典
		UGbool LoadDict(UGchar* pcDictName) ;

		//!	\brief 词典取词语频率
		//! \param pWord 词语指针[in]
		//!	\return 返回词频
		UGint DictGetWordFre(UGchar *pcWord) ;
		
		//!	\brief	  预标准化
		//! \param strAddress	字符串[in]
		//! \return 预处理后返回TRUE,否则返回FALSE
		UGbool PreStand(UGString  &strAddress) ;
		
		//! \brief 字符的索引位置
		//! \param sChar 字符串[in]
		//! \return 返回字符串的索引位置
		UGint GetCharPos(UGchar *pcString);

		//! \brief	 将地址strAddress分词
		//!	\param strAddress 目标串[in]
		//! \return 返回地址strAddress分词结果
		UGString CHAdressSeg(UGString &strAddress);
		
		//! \brief	将地址strAddress按照汉字等原子逐个切分
		//! \param strAddress 目标串[in]
		//! \return 返回地址strAddress分词结果
		UGString CHAdressAtomSeg(UGString  &strAddress);
		
		//!	\brief	检查地址是否切分出词语
		//! \param StrAddress   地址字符串[in]
		//!	\return 如果切分出词语返回TRUE,否则返回FALSE
		UGbool IsChAdressSegSucess(UGString  &strAddress);
		
		//!	\brief	检查地址是否切分出词语
		//! \param StrAddress 地址字符串[in]
		//! \param strAddressRes 切分出词语的字符串[out]
		//! \return	如果切分出词语返回TRUE,否则返回FALS
		UGbool IsChAdressSegSucess(UGString  &strAddress,UGString  &strAddressRes);
		
		//!	\brief 将分词的结果存储为UGStrArray格式
		//! \param strAddress	分词字符串[in]
		//! \param strAddressArray	分词的结果[out]
		//!	\return	如果切分出词语返回TRUE,否则返回FALS
		UGbool GetAdressSeg(UGString &strAddress,UGStrArray &strAddressArray);

		//!	\brief 将分词的结果存储为UGStrArray格式
		//! \param strAddress	分词字符串[in]
		//! \param strAddressArray	分词的结果[out]
		//!	\return	如果切分出词语返回TRUE,否则返回FALS
		UGbool GetAdressMinSeg(UGString &strAddress,UGStrArray &strAddressArray);

		//!	\brief 将分词的结果存储为UGStrArray格式
		//! \param strAddress	分词字符串[in]
		//! \param strAddressArray	分词的结果[out]
		//!	\return	如果切分出词语返回TRUE,否则返回FALS
		UGbool GetLoadAdressMinSeg(UGString &strAddress,UGStrArray &strAddressArray);

		//!	\brief 加载地址词语字符串
		//! \param nDTIndex 图层[in]
		//! \param nID nID[in]
		//! \param strAddress 地址词语串内容[in]
		//! \return 成功加载返回TRUE,否则返回FALSE
		UGbool Load(UGuint  nDTIndex,UGuint nID,UGString strAddress);
		
		//!	\brief 加载地址词语字符串
		//! \param nDTIndex 图层[in]
		//! \param nID nID[in]
		//! \param strAddress 地址词语串内容[in]
		//! \return 成功加载返回TRUE,否则返回FALSE
		UGbool Load(UGuint  nDTIndex,UGuint nID,UGStrArray StrAddressArray);
		
		//开始写简单地址查询模块的函数
		//!	\brief	查找单个词语对应的地图信息
		//! \param sWord 词语[in]
		//! \param StrAddressArray 地址信息[out]
		//! \param bAppoint 是否指定数据集查询[in]
		//! \return 如果找到返回TRUE,否则返回FALSE
		UGbool FindWordIDs(UGchar *pcWord,UGArray<UGint> &arrnLayers,UGArray<CHAddressDataID> &StrAddressArray,UGbool bAppoint = TRUE);
		
		//!	\brief	查找单个词语索引位置对应的地图信息
		//! \param sWord 词语[in]
		//! \param StrAddressArray 地址信息[out]
		//! \param bAppoint 是否指定数据集查询[in]
		//! \return 如果找到返回TRUE,否则返回FALSE
		UGbool FindWordIDs(UGint &nPOs,UGArray<UGint> &arrnLayers,UGArray<CHAddressDataID> &StrAddressArray,UGbool bAppoint = TRUE);
		
		//!	\brief 设置数据集数组	
		//! \param pArrDatasets 数据集指针数组[in]
		//! \param ArrNames 数据集字段名称数组[in]
		//! \return 设置数据集数组成功返回TRUE,否则FALSE	
		UGbool SetDatasets(UGArray<UGDatasetVector*> pArrDatasets,UGStrArray ArrNames);
		
		//!	\brief 追加数据集数组	
		//! \param pArrDatasets 数据集指针数组[in]
		//! \param ArrNames 数据集字段名称数组[in]
		//! \return 追加数据集数组成功返回TRUE,否则FALSE	
		UGbool AppendDatasets(UGArray<UGDatasetVector*> pArrDatasets,UGStrArray ArrNames);
		
		//!	\brief 判断数据集是否有效	
		//! \param pDataset 数据集指针[in]
		//! \return 数据集有效返回TRUE,否则FALSE	
		UGbool IsDatasetValid(UGDatasetVector* pDatasetNew,UGString &strFeildName);
		
		//!	\brief 得到当前的地图图层	
		//! \param pDatasetNew 数据集指针[in]
		//! \return 返回数据集图层所在的LayerID	
		UGint  GetDatasetLayerID(UGDatasetVector* pDatasetNew);

		//!	\brief 得到所有当前数据集的图层	
		//! \param pDatasetNew 数据集指针[in]
		//! \return 成功找到所有地图图层返回TRUE,否则FALSE	
		UGbool GetDatasetLayerIDs(UGDatasetVector* pDatasetNew,UGArray<UGint> &arrlayerIDs);

		//!	\brief 设置指定数据集的nDTIndex
		//! \param nDTIndex 数据集指针数组[in]
		//! \return 如果设置成功返回TRUE,否则返回FALSE
		UGbool SetDatasetnLayer(UGint nDTIndex);

		//!	\brief 删除数据集数组	
		//! \return 删除指定数据集数组
		UGbool RemoveDatasetnLayer();
		
		//!	\brief 释放数据集数组	
		//! \return 释放数据集数组	
		UGbool ReleaseDatasets();

		//!	\brief 检查过滤地图数据集，如果某个所选的数据集已经添加，不用继续添加了
		//! \param pArrDatasets 数据集指针数组[in]
		//! \param ArrNames 数据集字段名称数组[in]
		void CheckDatasetValid(UGArray<UGDatasetVector*> pArrDatasets,UGStrArray ArrNames);
			
		//!	\brief 查找地图地址的函数
		//! \param MapLayerID 输入查找的地图信息[in]
		//! \param strAddress 查找的地图信息[out]
		//! \return 返回查找得到的地址
		UGbool FindMapAdress(UGint nIDCount,CHAddressDataID &MapLayerID,UGString &strAddress,UGint & nLength);
		
		//!	\brief 加载地图数据
		//! \param pArrDatasets 数据集指针数组[in]
		//! \param ArrNames 数据集字段名称数组[in]
		//! \param bAdd 是否添加，如果是FALSE，是不添加[in]
		//! \return 如果加载成功就返回TRUE,否则返回FALSE
		UGbool  LoadMapData(UGArray<UGDatasetVector*> pArrDatasets,UGStrArray ArrNames);
		
		//!	\brief 追加地图数据
		//! \param pArrDatasets 数据集指针数组[in]
		//! \param ArrNames 数据集字段名称数组[in]
		//! \return 如果追加成功就返回TRUE,否则返回FALSE
		UGbool  AppendMapData(UGArray<UGDatasetVector*> pArrDatasets,UGStrArray ArrNames);
		
		//!	\brief 追加单个数据集的地图数据
		//! \param pArrDataset 数据集指针[in]
		//! \param ArrName 数据集字段名称[in]
		//! \return 如果追加成功就返回TRUE,否则返回FALSE
		UGbool  AppendMapData(UGDatasetVector* pDataset,UGString &FieldName);

		//!	\brief 得到数据集的个数
		//! \return 返回数据集的个数
		UGint GetDataSetCount();

		//!	\brief 得到相关索引位置的数据集指针
		//! \param nPos 索引位置[in]
		//! \return 返回相关索引位置的数据集指针
		UGDatasetVector* GetDataSetAt(UGint nPos);

		//!	\brief 设置查询数据集
		//! \param ArrnDTIndex 指定数据集地址信息数组[in]
		//! \return 返回匹配的分数
		UGbool SetSearchDT(UGArray<UGint> &ArrnDTIndex);

		//!	\brief 查询数据集排序
		//! \return 数据集排序成功返回TRUE，否则返回FALSE
		UGbool SortSearchDT();

		//!	\brief 查找索引集合
		//! \param location 插入地址信息[in]
		//! \return 如果查找到相关的数据集返回TRUE，否则返回FALSE
		UGbool FindIndexDT(UGint nPos,UGArray<UGint> &arrnDTIndex,UGint nCount);

		UGint GetMapIDCount();

private:
		//! \brief 计算汉字索引位置
		//! \param High  汉字高位[in]
		//! \param Low  汉字低位[in]
		//! \return 汉字的索引nID
		//! \remarks 备注信息
		UGuint ComputeChID(UGuchar High,UGuchar Low);
		
		//! \brief 得到字符类型
		//! \param sChar 字符串[in]
		//! \return 字符类型
		UGint CharType(UGuchar *pcChar);	
		
		//! \brief 计算汉字索引位置
		//! \param sString 字符串[in]
		//! \return 字符串首字的索引位置
		UGuint ComputeChnPos(UGchar *pcString);
		
		//! \brief 判断sString是否都是汉字字符
		//! \param sString 字符串[in]
		//! \return 如果全是汉字返回true，否则返回false
		UGbool IsAllChinese(UGuchar *pucString);
		
		//! \brief 判断字符串是否都是单字节字符
		//! \param sString 字符串[in]
		//! \return 如果全是单字节字符返回true，否则返回false
        UGbool IsAllSingleByte(UGuchar *pucString);
		
		//! \brief 从单词strAddress中获取数字
		//! \param strAddress 目标串[in]
		//! \return 从单词strAddress中获取数字,返回就是该数字;如果没有数字,就返回空字符串
		UGString GetNumeric(UGString  strAddress);

		//!\brief 找字符串
		//! \param string	分词字符串
		//! \param strCharSet 字符串
		//! \return	        找词语
		UGchar *CHWordFind(const UGchar *pctring, const UGchar *pcstrCharSet);
		
		//!	\brief 在索引表中查找词语
		//! \param nPos  索引位置nID
		//! \param sWord  词语
		//! \param pFindRet 词语头指针[out]
		//! \return 如果找到返回TRUE，否则返回FALSE
		UGbool FindInOriginalTable(UGint &nPos,UGchar *pcWord,PCHWORD_CHAIN *pFindRet);
		
		//!	\brief 在索引表中查找词语
		UGbool FindInOriginalTable( UGint &nPos,UGchar *pcWord);

		//!	\brief 在索引表中查找词语插入位置
		UGint FindInsetPos(UGint nPos,UGchar *pcWord,UGint nCount,UGint &nPosIndex);

		//!	\brief 在索引表中查找词语	
		//! \param nPos 索引位置nID[in]
		//! \param sWord  词语串[in]
		//! \param pFindRet 词语链式指针[out]
		//! \return 如果找到返回TRUE，否则返回FALSE
		UGbool FindPreNodeInOriginalTable(UGint &nPos,UGchar *pcWord,PCHWORD_CHAIN *pFindRet);

		//!	\brief 在索引表中查找词语是给定词语的个数	
		//! \param nPos 索引位置nID[in]
		//! \param pWord 词语字符串[in]
		//! \return 返回的是索引表中nID是nPos,且词语是sWord内容的词语个数
		UGint GetWordCount(UGint &nPos,UGchar *pcWord);
		
		//!	\brief 在索引表中查找词语个数	
		//! \param nPos 索引位置nID[in]
		//! \return 返回的是索引表中nID是nPos的词语个数		
		UGint GetWordCount(UGint &nPos);
		
		//!	\brief 在索引表中总的词语出现的个数	
		//! \return 返回的是索引表中总的词语出现的个数	
		UGint GetWordTotalCount();
		
		//!	\brief 在索引表中总的词语个数	
		//! \return 返回的是索引表中总的词语个数	
		UGint GetCHWordTotalCount();
		
		//!	\brief 在索引表中词语最多的个数	
		//! \return 返回的是在索引表中词语最多的个数	
		UGint GetCHWordMaxCount();
		
		//!	\brief 在地图数据表中索引位置是nPos的词语是sWord相关的地址nID个数	
		//! \param nPos 索引位置nID[in]
		//! \param pWord 词语字符串[in]
		//! \return 在地图数据表中索引位置是nPos的词语是sWord相关的地址nID个数	
		UGint GetMapWordIDSCount(UGint &nPos,UGchar *pcWord);
		
		//!	\brief 在地图数据表中索引位置是nPos的词语相关的地址nID个数 	
		//! \param nPos 索引位置nID[in]
		//! \return 返回的是在在地图数据表中索引位置是nPos的词语相关的地址nID个数 	
		UGint GetMapWordIDSCount(UGint &nPos);
		
		//!	\brief 地图数据总的词语个数	
		//! \return 返回的是地图数据总的词语个数	
		UGint GetMapWordIDSTotalCount();
		
		//!	\brief 得到单个地址切分的个数	
		//! \param SigleAddressSeg 地址串[in]
		//! \return 返回单个地址切分的个数	
		UGint GetSigleAddressSegCount(UGString &SigleAddressSeg);
		
		//!	\brief 加载单个词语
		//! \param nDTIndex 图层[in]
		//! \param nID nID[in]
		//! \param sWord 词语串内容[in]
		//! \return 成功加载返回TRUE,否则返回FALSE
		UGbool Load(UGuint  nDTIndex,UGuint nID,UGchar *pcWord);

public:
		//! \brief 数据集数组
		UGArray<UGDatasetVector*> m_pArrDatasets;
			
			//! \brief 地址字段名数组
		UGStrArray m_ArrNames;

private:
		//! \brief 数组指针
		pCHAdressINDEX_TABLE m_pMapIndexTable;
		//CHAdressINDEX_TABLE  m_pMapIndexTable[UG_GEOCODE_CHNSIZE];

         //! \brief 词典类
		UGDictionary m_dictCore;
		
		//! \brief 分词类
		UGMPWordSeg  m_MPWordSegment;

		//! \brief 指定图层ID数组
		UGArray <UGint> m_ArrnDTIndex;
		
		//! \brief 地图字段信息存储
		UGArray<UGCHMapData>    m_ArrCHMapData;

		//! \brief 地图每个图层对象的个数
		UGArray< UGint >    m_ArrLayerCount;
		
		//! \brief 指定图层的nDTIndex
		//UGint  m_nLayer;
		
  protected:
		//! \brief 字段
		UGFieldInfo m_FieldInfo ;
};

}

#endif
