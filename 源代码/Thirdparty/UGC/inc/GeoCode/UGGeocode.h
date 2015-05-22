#ifndef UGGEOCODE_H
#define UGGEOCODE_H

#include "Base/ugdefs.h"
#include "Base/UGArray.h"
#include "Base/UGString.h"
#include "Base/UGProgress.h"
#include "Base/UGCallback.h"

#include "Algorithm/UGOpLines.h"
#include "Algorithm/UGOpPoints.h"
#include "Algorithm/UGRelLines.h"
#include "Algorithm/UGOpPointLine.h"

#include "Engine/UGDatasetVector.h"
#include "Engine/UGDataSource.h"
#include "Engine/UGDataset.h"
#include "Engine/UGRecordset.h"
#include "Engine/UGDataSource.h"
#include "Engine/UGQueryDef.h"

#include "Geometry/UGGeoLine.h"
#include "Geometry/UGGeoPoint.h"

#include "UGGeoCodeDefine.h"
#include "UGAddressStandardize.h"

#include <math.h>

#include "Base/ugdefs.h"

/*!
   **************************************************************************************
    \file     UGGeocode.h
   **************************************************************************************
    \author   裘立、郭会
    \brief    地理编码类                                                             
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 1997-2006 SuperMap GIS Technologies,Inc.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2006-06-29  郭会    初始化版本.       先实现英文街道地址匹配           <br>
   **************************************************************************************
   
   **************************************************************************************
   ********							修改记录									*********
   **************************************************************************************
   **************************************************************************************
*/

/*	地理编码依赖关系:
*	BuildIndex(建立索引) 
 *	  <- SetIndexField(设置索引字段) <- SetFieldValue(设置基准地址字段意义) 
 *		    <- SetDatasetReference(指定基准地址) <- SetType(地址类型，确定规则)
 *	m_AddStamd(地址标准化) <- 设置关键词、标准化简写、类型字段 <- 设置解析数据集 <- SetType设置地址类型
 
 */
/* 该类的理解难点:
 *	1.(对USStreet地址)存在一个内部对应关系，举例： 如果有地址380 New York Street去匹配一个基准地址 ，则
 *     标准化为7个字段 HN/PD等，HN=380 SN=New York ST= Street ；如果基准地址有字段L_F_HN
 *     内部对应关系为 (外部) 380 ->   (内部)HN->FROMLEFT(内部)   ->		(外部)L_F_HN
 *     (内部)HN->FROMLEFT(内部)是内部自定义的，相当于ESRI中的MAT表
 */



namespace UGC {

class GEOCODE_API UGGeoCode
{
public:
	/*!	\brief 索引状态 */
	enum SmIndexState
	{
		SMIndexNonexistant	= 1,			// 索引不存在
		SMIndexInvalid		= 2,			// 索引无效
		SMIndexUnreadable	= 3,			// 索引不可读
		SMIndexExists		= 4				// 索引存在
	};

	/*!	\brief 地址所在边的左边或者右边 */
	enum SmStreetSide
	{
		SMSideNone			= 0,			// 预留接口 将来一定有用
		SMSideLeft			= 1,			// 在街道左边
		SMSideRight			= 2,			// 在街道右边边
		SMSideBoth			= 3,			// 在街道两边均可
		SMIntersectionSide	= 4,			// 交叉道口
		SMSideOther			= 5				// 其他
	};

	/*!	\brief 匹配结果 */
	enum SmMatchConstants
	{
		SMMatchFailed		= 0,			// 匹配失败
		SMMatchSingleBest	= 1,			// 有一个最佳匹配
		SMMatchMultipleBest	= 2,			// 多个最佳匹配
		SMMatchPartial		= 3,			// 部分匹配，也就是没有达到最低分数
	};
	
	/*!	\brief 候选记录的匹配结果 */
	enum SmCandidateState
	{
		SMCandidateMatch	= 0,			// 候选对象与之匹配
		SMCandidateUnMatch	= 1,			// 候选对象未匹配
	};

	/*!	\brief 字段匹配结果 */
	enum SmFieldMatchConstants
	{
		SMFieldMatchFailed	  = 0,			// 字段匹配成功 扣分
		SMFieldMatchNotFialed = 1,			// 不加分也不扣分
		SMFieldMatchSuccess	  = 2,			// 字段匹配成功 加分
	};

	struct SmAddressLocation
	{
		UGint	    m_nAddressID	;		// 对应到基准地址上的SMID
		UGint		m_nScore		;		// 该点获得的分数 在0到100之间
		UGPoint2D   m_ptLocation	;		// 定位到的点
		UGdouble    m_dPersent		;		// 从线的开始点FromNode到定位点所占整个线段的百分比
		UGint       m_nSide			;		// 地址所在边
		UGint		m_nCandidateState;		// 候选对象匹配状态
	//---------交叉道口时候才使用
		UGint		m_nAddressID1;		// 交叉道口的另外一个ID
		UGint		m_nAddressID2;		// 交叉道口的另外一个ID
	};

	
	UGGeoCode();
	virtual ~UGGeoCode();


	/*!	\brief	单地址匹配
	*! \remarks 将调用前面的标准化 索引等
	*/
	UGbool MatchAddress(UGString strAddress,UGProgress * pProgres = NULL);

	/*!	\brief	建立索引
	 *! \remarks 调用前 m_strArrIndexFieldName必须不能为空
	 *! \remarks 将第一个单词使用探测法索引 其余依次加入
	*/
	UGbool BuildIndex(UGString strNewDtName = "sm_GeoCode_index",UGProgress * pProgres = NULL);


	/*!	\brief	多地址匹配
	*! \remarks 将调用前面的标准化 索引等 
	*/
	UGbool MatchAddress(UGDatasetVector * pDtVector,UGString  strFieldName,UGString strZip, UGString strNewDtName ,UGProgress * pProgres = NULL );

	/*!	\brief	自动移出索引数据集 建议在地理编码结束后使用	*/
	UGbool RemoveIndexDt();


	/*!	\brief	设置地址的语种和类型，必须同时设置才有效	
	  *	\param nLanguageType	地址种类
	  *	\param nAddressType		语种
	  */
	UGbool SetType(UGint nLanguageType , UGint nAddressType);

//---------------------------------------------------------------	
	/*!	\brief	设置标准化关键字表 */
	UGbool SetDatasetCLS(UGDatasetVector* pDtCLS);	
	/*!	\brief	获取标准化关键字表*/
	const UGDatasetVector* GetDatasetCLS();

	/*!	\brief	设置Word字段*/
	UGbool SetCLSWordField(UGString strCLSWord);
	/*!	\brief	获取Word字段*/
	UGString GetCLSWordField();

	/*!	\brief	设置Abbreviation字段*/
	UGbool SetCLSAbField(UGString& strCLSAb);
	/*!	\brief	获取Abbreviation字段*/
	UGString GetCLSAbField();

	/*!	\brief	设置CLSType字段*/
	UGbool SetCLSTypeField(UGString& strCLSType);
	/*!	\brief	获取CLSType字段*/
	UGString GetCLSTypeField();

	// 重建词典树
	UGbool ReBuildDicTree() ;

	/*!	\brief	获取地址标准化字段个数  */
	UGint GetAddStanFieldNameCount();

	/*!	\brief	获取地址标准化字段名	
	  *	\param nIndex	字段名字索引 该索引必须介于 0－FieldNameCount之间
	  */
	UGString GetAddStanFieldName(UGint nIndex );

	/*!	\brief	获取地址标准化字段值	
	  *	\param nIndex	字段名字索引 该索引必须介于 0－FieldNameCount之间
	  */
	UGString GetAddStanFieldValue(UGint nIndex );

	/*!	\brief	设置地址标准化字段值	
	  *	\param nIndex	字段名字索引 该索引必须介于 0－FieldNameCount之间
	  *	\param strValue	字段值
	  */
	UGbool SetAddStanFieldValue(UGint nIndex,UGString strValue );
	
	/*!	\brief	获取地址标准化字段值	
	  *	\param strFieldName	
	  */
	UGString GetAddStanFieldValue(UGString strFieldName );

	/*!	\brief	设置地址标准化字段值	
	  *	\param strValue	字段值
	  */
	UGbool SetAddStanFieldValue(UGString strFieldName ,UGString strValue );

//---------------------------------------------------------------	
	// 这些操作都是对字段的操作/在外面可以封装成:
	// Private Const m_ToLeft = "L_t_add"
	// geo.MatchVariableField("FromLeft") = m_FromLeft的形式

	/*!	\brief	设置基准地址 */
	UGbool SetDatasetReference(UGDatasetVector* pDtReference);	
	/*!	\brief	获取基准地址*/
	const UGDatasetVector* GetDatasetReference();

	
	/*!	\brief	获取基准地址需求字段个数 --> (MO) MathchVariableCount */
	UGint GetVariableFieldNameCount();

	
	/*!	\brief	获取基准地址需求字段名	--> (MO) MathchVariable
	  *	\param nIndex	字段名字索引 该索引必须介于 0－FieldNameCount之间
	  */
	UGString GetVariableFieldName(UGint nIndex );

	
	
	/*!	\brief	获取基准地址需求字段值	--> (MO) MathchVariableField
	  *	\param nIndex	字段名字索引 该索引必须介于 0－FieldNameCount之间
	  */
	UGString GetVariableFieldLink(UGint nIndex );

	/*!	\brief	设置基准地址需求字段	--> (MO) MathchVariableField
	  *	\param nIndex	字段名字索引 该索引必须介于 0－FieldNameCount之间
	  *	\param strValue	字段值
	  */
	UGbool SetVariableFieldLink(UGint nIndex,UGString strValue );
	
	
	
	/*!	\brief	获取基准地址需求字段值	--> (MO) MathchVariableField
	  *	\param strFieldName	
	  */
	UGString GetVariableFieldLink(UGString strFieldName );

	/*!	\brief	设置基准地址需求字段值	--> (MO) MathchVariableField
	  *	\param strValue	字段值 比如:将SM_GEOCODE_USSTREET_FROMLEFT对应字段设为'fromleft'
	  */
	UGbool SetVariableFieldLink(UGString strFieldName ,UGString strValue );
	

	/*!	\brief	是否有效	 */	
	UGbool IsValid();

	
	/*!	\brief	调用UGAddressStandardize中的方法	 */	
	UGbool StandardizeAddress(UGString  strAddress);

//---------------------------------------------------------------	
	
	
	/*!	\brief	获取基准地址索引数据集	  */
	UGDatasetVector * GetIndexDt();

	/*!	\brief	设置基准地址索引数据集	  */
	UGbool SetIndexDt(UGDatasetVector * pIndexDt );

	
	/*!	\brief	设置哪些添加进入索引数据集 
	  *	\param strValue	strArrFieldsName[0]是主索引 是要建立索引的 其他字段将直接拷贝进入索引数据集
	  *	\param strValue	strArrFieldsName中的字符串必须是m_strArrFieldValue中的字符串 
	  */
	UGbool SetIndexField(const UGStrArray & strArrFieldsName);

	
	// 设置和获取最小分数
	UGbool SetMinMatchScore(UGint nMinMatchScore );
	UGint GetMinMatchScore();

	// 设置边偏移
	UGbool SetOffset(UGdouble dOffset );
	UGdouble GetOffset();

	// 设置末端偏移
	UGbool SetEndOffset(UGdouble dEndOffset  );
	UGdouble GetEndOffset();

	UGbool GetResultLocation(UGArray<SmAddressLocation> & arrLocation);



private:
// 索引匹配的接口是不对外的 暂时打开 后期封闭


	/*!	\brief	索引匹配 返回ID集 
	*! \remarks 将根据地址类型调用不同私有接口
	*! \remarks 其中的一个参数在m_AddStamd中,调用中会将m_nArrIndexMatchIDs清空,然后写入!
	*/
	UGbool MatchIndex();

	/*!	\brief	对索引匹配产生的记录ID进行进一步的匹配 
	*! \remarks 获得是有得分(Composite Score、Point等信息)
	*/
	UGbool MatchCandidate();

	/*!	\brief	获取基准地址索引数据集	  */
	UGbool GetIndexMatchID(UGArray<UGint> & nArrIndexMatchIDs);


	// 获取数据源下的一个合法数据集名
	UGbool GetValidDtName(UGDataSource * pDataSource ,UGString & strDtName);
	
	// 为一个单词获取相应的索引
	UGbool GetIndexForWord(UGString & strWord ) ;
	
	// USStreet类型索引匹配
	UGbool USStreetMatchIndex() ;

	// 根据用户设定地址 获得与之待匹配的标准化字段名字 如:  FROMLEF<--->HN
	// 中间过程是要获得基准地址字段值
	UGString GetAddressFieldNameByLink(UGString strVariableFieldLinkValue);

	// 从用户设置成的字段名字 获得基准数据中的字段名字
	UGString GetReferenceFieldNameByLink(UGString strVariableFieldLinkValue);

	// 从基准数据中的字段名字 获得用户设置成的字段名字 
	UGString GetAddressFieldNameByReferenceFieldName(UGString strAddressFieldName);

	// 设置获取元素的M和U值
	UGdouble GetUnMatchValue( UGString strFieldName );
	UGbool SetUnMatchValue( UGString strFieldName,UGdouble dUValue );

	UGdouble GetMatchValue( UGString strFieldName );
	UGbool SetMatchValue( UGString strFieldName, UGdouble dUValue );

	// 计算最低和最高分数 被NormalizeScore调用
	UGbool CountMaxAndMinScore();

	// 将分数统一到0到100 使用的是m_dMaxScore和m_dMinScore
	UGint NormalizeScore(UGdouble dScore);

	// 去匹配其中的一条记录 
	// 这条记录的信息存储再 strArrAddressElem 中，它按照m_strArrVariableFieldName进行存储
	// 它按照不同地址类型调用MatchUSStreetAddress 等
	UGbool MatchOneAddress(UGStrArray strArrRefFieldValue,SmAddressLocation & location);
	
	// 去匹配其中的一条记录 
	// 这条记录的信息存储再 strArrAddressElem 中，它按照m_strArrVariableFieldName进行存储
	UGbool MatchUSStreetAddress(UGStrArray strArrRefFieldValue,SmAddressLocation & location);
	
	// 在 m_ArrLocationResult 中插入一个结果 保证时有序的
	UGbool InsertLocation(SmAddressLocation location);

	UGdouble GetScore(UGdouble dM,UGdouble dU,UGbool bMatch = TRUE );

	// 一个与 m_strArrVariableFieldName 相同结构的记录 要获取其中的某个字段
	UGString GetLinkValue(UGStrArray strArrRefFieldValue,UGString strFieldName );
	
	// 传入2个门牌号码 求出匹配情况
	UGbool MatchHN(UGint nHN  ,UGint nFROM,UGint nTO , UGdouble & dPosPercent );

	// 根据所在位置的百分比来获取点
	UGPoint2D FindPoint(UGGeoLine * pline,UGdouble dPosPercent,UGint nSide = SMSideNone) ;

	UGbool MatchUSStreetIntersection (UGString strAddress1,UGString strAddress2);
	UGbool GetSamePnt(UGGeoLine * pline1,UGGeoLine *pline2,UGPoint2D & pntSamePoint);
	
	
	// 校正交叉道口的分数 在交叉道口中 已经将门牌处理为非法的门牌-100了
	UGint GetIntersectionScore(UGint nScore1,UGint nScore2);

	// 只是保留字符串中的字母
	UGbool GetLetters(UGString & str);

private:
	
	//! \brief 地址标准化私有变量
	//! \remarks m_AddStamd中的条件设计与本类中的相关设置一致
	UGAddressStandardize m_AddStand ;

	//! \brief 地址字段U值
	//! \remarks SM_GEOCODE_USSTREET_HN_U 等
	UGArray<UGdouble>  m_dArrUnMatchValue	;

	//! \brief 地址字段M值
	//! \remarks SM_GEOCODE_USSTREET_HN_M 等
	UGArray<UGdouble> m_dArrMatchValue	;

	//! \brief 地址语种
	//! \remarks 暂时支持中文、英文，为以后接口扩展
	UGint m_nLanguageType	;
	
	//! \brief 地址种类
	//! \remarks 街道、小区等类型
	UGint m_nAddressType	;

	//! \brief 地址字段名字
	//! \remarks SM_GEOCODE_USSTREET_FROMLEFT、SM_GEOCODE_USSTREET_FROMRIGHT等
	UGStrArray m_strArrVariableFieldName	;

	//! \brief 基准地址字段值
	//! \remarks 也就是将这些字段代号设置到基准地址上面对应的字段
	//! \remarks 例如：[SM_GEOCODE_USSTREET_TOLEFT] = "LEFT_TO"
	UGStrArray m_strArrVariableFieldLink	;

	//! \brief 基准地址
	//! \remarks 基准地址是用于匹配的标准地址
	UGDatasetVector  * m_pReferencDt ;

	//! \brief 索引状态
	UGint m_nIndexState	;
	
	//! \brief 被索引字段名字
	//! \remarks 所有的索引字段名字必须来自m_strArrFieldValue中
	//! \remarks m_strArrIndexFieldName中的第一个所指字段是要进行索引的
	UGStrArray m_strArrIndexFieldName	;

	//! \brief 索引数据集
	UGDatasetVector * m_pIndexDt ;

	//! \brief 索引匹配产生的结果ID集
	UGArray<UGint> m_nArrIndexMatchIDs;
	
	//! \brief 最低匹配分数 大于0小于100 缺省为60分
	UGint m_nMinMatchScore	;
	
	//! \brief 地址匹配结果
	UGArray<SmAddressLocation> m_ArrLocationResult	;

	// 这是按照M和U值计算的最大和最小值 用来将一个得分标准化到0到100之间
	UGdouble m_dMaxScore	;
	UGdouble m_dMinScore	;

	// 标示在美国街道数据中门牌号码所占有的分数 用于在交叉道口的修正
	UGdouble m_dUSStreetHNScore ;
	
	// 交叉道口标示符 每个字母就是一个标识符
	UGStrArray m_IntersectionSeparate ;
	
	// 边偏移
	UGdouble m_dOffset ;
	// 末端偏移
	UGdouble m_dEndOffset;

};


}// end of namespace

#endif

