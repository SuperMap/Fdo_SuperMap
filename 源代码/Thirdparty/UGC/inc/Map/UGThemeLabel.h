// UGThemeLabel.h: interface for the UGThemeLabel class.
//
//////////////////////////////////////////////////////////////////////

/**
   **************************************************************************************
    \file     UGThemeLabel.h
   **************************************************************************************
    \author   陈国雄
    \brief    标签专题图类。                                                         
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2005 SuperMap GIS Technologies,Inc.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-05-20  陈国雄    初始化版本.                                       <br>
   **************************************************************************************
*/

#if !defined(AFX_UGTHEMELABEL_H__5FD9A9BE_3A6F_4D8D_9BF0_EEDFA9C7B072__INCLUDED_)
#define AFX_UGTHEMELABEL_H__5FD9A9BE_3A6F_4D8D_9BF0_EEDFA9C7B072__INCLUDED_

#include "UGThemeSymbol.h"
#include "Base/UGTextStyle.h"
//#include "Geometry/UGGeoText.h"
#include "UGLayer.h"

namespace UGC {

//added by lugw 2007-04-02  实现标签专题图中单个文本风格设置功能，采用范围分段的相同方法
class MAP_API UGLabelTextStyle  
{
public:
	UGLabelTextStyle();
	~UGLabelTextStyle();
	UGLabelTextStyle(const UGLabelTextStyle& TextStyle);
	UGLabelTextStyle& operator = (const UGLabelTextStyle& TextStyle);

public:
	UGbool m_bVisible;				//! \brief 可见
	UGString m_strCaption;			//! \brief 标题
	UGTextStyle m_TextStyle;				//! \brief 风格

};

#define LABEL_DIVISION "[/]"

class MAP_API UGThemeLabel : public UGThemeSymbol  
{
public:
	enum UGLabelBackType		//! \brief 背景类型
	{
		NoneBG = 0,				//! \brief  空背景
		Rect = 1,				//! \brief  矩形背景
		RoundRect = 2,			//! \brief  圆角矩形背景
		Ellipse = 3,			//! \brief  椭圆形背景
		Diamond = 4,			//! \brief  菱形背景
		Triangle = 5,			//! \brief  三角形背景
		Circle = 6,			    //! \brief  圆形背景
		Marker = 100			//! \brief  符号背景
	};

	enum UGLabelOverLengthMode
	{
		UGOverLengthNone    = 0,   //! \brief 不处理
		UGOverLengthOmit    = 1,   //! \brief 省略
		UGOverLengthNewline = 2,   //! \brief 换行
	};

	//added by lugw 2007-04-03 仿照范围专题图分段的六种类型
//	enum UGClassType
//	{
//		ctEqualDistance,
//		ctExtraction,
//		ctStdev,
//		ctLogarithm,
//		ctQuantile,
//		ctCustomInterval
//	};

	enum LabelLineDirection		                            //! \brief  超长处理模式
	{
		UGDirectionAlongLine = 0,							//! \brief  沿线法方向
		UGDirectionLeftTopToRightBottom = 1,				//! \brief  从上到下，从左到右
		UGDirectionRightTopToLeftBottom = 2,				//! \brief  从上到下，从右到左
		UGDirectionLeftBottomToRightTop = 3,				//! \brief  从下到上，从左到右
		UGDirectionRightBottomToLeftTop = 4,				//! \brief  从下到上，从右到左
	};

public:
	UGThemeLabel();
	virtual ~UGThemeLabel();
	UGThemeLabel(const UGThemeLabel& ThemeLabel);
	UGThemeLabel& operator = (const UGThemeLabel& ThemeLabel);

public:
	//! \brief  标签专题图是否有效
	virtual UGbool IsValid()const;
	//! \brief  标签专题图保存为XML信息
	virtual UGString ToXML(UGint nVersion = 0)const;
	//! \brief  标签专题图读取XML信息
	virtual UGbool FromXML(const UGString& strXML, UGint nVersion = 0);
	//! \brief  标签专题图检查字段是否合法
	virtual UGbool CheckFieldType(UGint nType);
	//! \brief  标签专题图获取字段
	virtual UGString GetFieldName(UGbool bAddExpression = true)const;
	//! \brief  处理分数表达式时的字段名
	UGbool GetFieldNames(UGArray<UGString>& arrExpressions,UGbool bAddExpression = true)const;
	
	//! \brief  标签专题图获取X轴偏移
	virtual UGString GetOffsetXFieldName(UGbool bAddExpression = true)const;
	//! \brief  标签专题图获取Y轴偏移
	virtual UGString GetOffsetYFieldName(UGbool bAddExpression = true)const;

	//! \brief  标签专题图是否沿线标记
	UGbool IsAlongLine()const;
	//! \brief  设置是否沿线标记
	void SetAlongLine(UGbool bAlongLine = false);

	//! \brief  是否固定角度
	UGbool IsFixedAngle()const;
	//! \brief  设置是否固定角度
	void SetFixedAngle(UGbool bFixedAngle = false);

	//! \brief  是否忽略小对象
	UGbool IsIgnoreLittleObject()const;
	//! \brief  设置是否忽略小对象
	void SetIgnoreLittleObject(UGbool bIgnoreLittleObject);

	//! \brief  是否自相交
	UGbool IsSelfOverlap()const;
	//! \brief  设置是否自相交
	void SetSelfOverlap(UGbool bAlongLine = false);
	
	//! \brief  得到字段表达式
	UGString GetExpression()const;
	//! \brief  设置字段表达式
	void SetExpression(const UGString& strExpression);

	//! \brief  得到字体风格
	const UGTextStyle& GetLabelStyle()const;
	//! \brief  设置字体风格
	void SetLabelStyle(const UGTextStyle& LabelStyle);
	
	//! \brief  得到背景风格
	const UGStyle& GetBackStyle()const;
	//! \brief  设置背景风格
	void SetBackStyle(const UGStyle& style);
	
	//! \brief  得到背景类型
	UGint GetBackType()const;
	//! \brief  设置背景类型
	void SetBackType(UGint nBackType);
	//! \brief  得到背景类型
	UGbool IsHasSpecialKey()const;
	
	//! \brief  处理超常标签接口
	//! \brief  得到超长标签处理类型
	UGint GetOverLengthModeType()const;
	//! \brief  设置超长标签处理类型
	void SetOverLengthModeType(UGint nTextLengthLimit);
	//! \brief  得到超长标签字数限制
	UGint GetTextLengthLimit()const;
	//! \brief  设置超长标签字数限制
	void SetTextLengthLimit(UGint nTextLengthLimit);
	
	/*********************************************
	************为了统计专题图也能避让************
	*****避让的一些参数设置已移至ThemeSymbol******
	**********************************************/

	//! \brief added by dongfei 2007-04-14 
	/*
	**设置/获取此标签专题图的优先级
	*/
	void  SetThemePriority(UGint nPriority){m_nThemePriority = nPriority;};
	UGint GetThemePriority(){return m_nThemePriority;};

	//added by lugw 2007-04-02 提供设置每个标签的风格，采用类似范围分段的方式，处于效率考虑，默认下不使用此方法读取文本风格，只有在用户选择使用单独设置文本风格时调用。
	//! \brief  计算分段数组
	/**
	\param pDatasetV         查找的数据集[in]
	\param JoinItems         外挂关联条件[in]
	\param strExpression     文本字段的表达式[in]
	\param arrValues         所得数据集对应表达式的字段值[in/out]
	\return 成功分段则返回true，反之为false
	*/
	UGbool CalculateExtremum(UGDatasetVector* pDatasetV, const UGArray<UGJoinItem>& JoinItems, const UGString& strExpression, UGArray<UGdouble>& arrValues);
	UGRecordset * QueryWithExpression(UGDatasetVector *pDatasetV, const UGArray<UGJoinItem>& JoinItems, const UGString& strExpression);
	//! \brief  单独设置文本风格时提供的默认的风格分段
	/**
	*/
	void MakeDefaultTextStyles(UG_ENUM_STOCK_GRADIENT_SET_STYLE nIndex);
	//! \brief  单独设置文本风格时提供的默认实现函数
	/**
	\param nClassType         分段类型[in]
	\param nClasses           分段个数[in]
	\param aryValues          数据集的字段值[in]
	\teturn 成功返回true，反之为false
	*/
	UGbool MakeDefault(UGint nClassType, UGint nClasses, const UGArray<UGdouble> &aryValues, UGDatasetVector* pDatasetV, const UGArray<UGJoinItem>& JoinItems,UGdouble dInterval = 0.0);
	//! \brief  设置文本风格的标题
	/**
	*/
	void MakeDefaultTextCaptions();
	//! \brief  设置文本风格的标题
	/**
	\param nIndex         设置标题的索引号[in]
	\param strCaption     设置标题[in]
	*/
	void SetCaptionAt(UGint nIndex, const UGString& strCaption );
	//! \brief  设置文本风格的标题
	/**
	\param nIndex         设置标题的索引号[in]
	\return 返回索引对应的标题
	*/
	UGString GetCaptionAt(UGint nIndex)const;
	//! \brief  设置文本风格的分段范围
	/**
	\param pValues      分段的段值[in]
	\param nValueCount  分段的个数[in]
	\return 分段是否成功，true成功，false失败
	\remarks 设置分段是否成功
	*/
	UGbool SetTextStylesRanges(UGdouble *pValues,UGint nValueCount);

	//! \brief  得到表达式
	/**
	\param bAddExpression   是否显示真实字段名[in]
	*/
	UGString GetTextFieldName(UGbool bAddExpression = true)const;
	//! \brief  查找该数据集下的文本风格
	/**
	\param pRecordset     所要查询的pRecordset[in]
	\param Style          得到该Recordset所对应的表达式的值[in/out]
	\return 返回信息为该文本风格设置是否为可显示，显示为true，不显示为false
	*/
	UGbool FindTextStyle(UGRecordset *pRecordset, UGLabelTextStyle& Style)const;
	//! \brief  查找单个段值的文本风格
	/**
	\param nValue        该字段的段值[in]
	\param UGTextStyle   得到该段值下的文本风格[in]
	\return 返回信息为该文本风格设置是否为可显示，显示为true，不显示为false
	*/
	UGbool FindTextStyle(UGdouble dValue,UGLabelTextStyle& TextStyle)const;

	//! \brief  设置单个段值的文本风格
	/**
	\param nIndex        设置所在段的索引[in]
	\param UGTextStyle   设置所在段的文本风格[in]
	*/
	void SetTextStyleAt(UGint nIndex, const UGLabelTextStyle& TextStyle);
	//! \brief  得到该字段的文本风格
	/**
	\param nIndex        设置所在段的索引[in]
	\return 该字段对应的文本风格
	*/
	const UGLabelTextStyle& GetTextStyleAt(UGint nIndex)const;

	//! \brief  检查分段数是否在合理范围内，在0～256之间
	/**
	\param nValueCount   分段的个数[in]
	\return 是否为合理值，true为合理，false为不合理
	*/
	UGbool IsValidValueCount(UGint nValueCount)const;
	//! \brief  删除所有分段值和文本风格信息
	void RemoveAll();

	//! \brief  得到分段个数
	/**
	\return 分段个数
	*/
	UGint GetCount();
	//! \brief  得到分段值的个数
	/**
	\return 分段值个数
	*/
	UGint GetValueCount()const;
	//! \brief  查找该分段值是否存在
	/**
	\param dValue   所要查找的分段值[in]
	\return 返回该字段值所在的索引，－1则表示该字段值不存在
	*/
	UGint Find(UGdouble dValue)const;
	
	//! \brief  添加文本风格和对应的分段值
	/**
	\param dValue      分段的值[in]
	\param TextStyle   分段的风格[in]
	\return 返回分段个数
	*/
	UGint Add(UGdouble dValue, const UGLabelTextStyle& TextStyle);
	//! \brief  删除分段
	/**
	\param nIndex     删除分段的索引号[in]
	\param nCount     删除分段个数[in]
	\return 返回当前的段个数
	*/
	UGint RemoveAt(UGint nIndex, UGint nCount = 1);
	//! \brief  插入某一分段
	/**
	\param nIndex     插入的分段的索引号[in]
	\param dValue     插入的分段值[in]
	\param TextStyle  插入的分段所对应的文本风格[in]
	\return 返回合并段数
	*/
	UGbool InsertAt(UGint nIndex, UGdouble dValue, const UGLabelTextStyle& TextStyle);

	//! \brief  添加和得到分段值
	/**
	\return 返回合并段数
	*/
	UGdouble GetValueAt(UGint nIndex)const;
	void SetValueAt(UGint nIndex, UGdouble dValue);
	
	//! \brief  单独设置文本风格时，得到分段条件表达式,可以是字段名称或表达式
	/**
	*/
	UGString GetTextExpression()const;			
	void SetTextExpression(const UGString& strExpression);

	//! \brief  得到条件表达式,可以是字段名称或表达式
	/**
	\remarks 默认为升序
	*/
	UGbool IsDescending()const;			
	void SetDescending(UGbool bDescending = false);	
	//! \brief  文本是否可见
	/**
	\remarks 默认为可见
	*/
	void SetTextVisibleAt(UGint nIndex, UGbool bVisible = true);
	UGbool IsTextVisibleAt(UGint nIndex)const;
	
	//! \brief  读取和输出文本风格信息的XML格式
	/**
	\param nVersion  读取和输出的版本号
	\remarks 默认为可见
	*/
	UGString SingleTextStyleToXML(UGint nVersion = 0)const;
	UGbool SingleTextStyleFromXML(const UGString& strXML, UGint nVersion = 0);

	//! \brief  UGDouble绘制成分数形式的准备
	/**
	\param strFieldValue 字段表达式内容
	\param labelStyle    文本风格
	\param pntCentroid   绘制点位置，地理坐标
	\param pDrawParam    绘制参数，用于比例尺
	\return  所需绘制的分数形式的复合数据集
	\remarks 暂时还没有开放此接口
	*/
	UGGeoCompound *PrepareForFraction(UGdouble &dValue,UGTextStyle labelStyle ,UGPoint2D &pntCentroid,UGDrawParamaters *pDrawParam);
	//! \brief  UGString绘制成分数形式的准备
	/**
	\param strFieldValue 字段表达式内容
	\param labelStyle    文本风格
	\param pntCentroid   绘制点位置，地理坐标
	\param pDrawParam    绘制参数，用于比例尺
	\return  所需绘制的分数形式的复合数据集
	*/
	//修改参数strFieldValue为UGArray<UGString>类型
	UGGeoCompound *PrepareForFraction(UGArray<UGString> &strFieldArray,UGTextStyle labelStyle ,UGPoint2D &pntCentroid,UGDrawParamaters *pDrawParam);
	//UGGeoCompound *PrepareForFraction(UGString &strFieldValue,UGTextStyle labelStyle ,UGPoint2D &pntCentroid,UGDrawParamaters *pDrawParam);

	void SetLabelAlwaysOnTop(UGbool bAlwaysOnTop);
	UGbool IsLabelAlwaysOnTop()const;

	//! \brief  数值型数据的格式
	UGString GetNumFormat() const;
	void SetNumFormat(const UGString& strNumFormat);

	UGString Variant2String(const UGVariant& var); //! \brief 变体变成字符串

	//! \brief  构造沿线文本对象，考虑了循环标注和指定间隔。
	void MakeAlonglineText(const UGPoint2D& point, const UGString& strValue, UGTextStyle& labelStyle, 
									  UGGeoLine* pSubLine, UGArray<UGGeoText*>& arrTexts, UGDrawParamaters* pDrawParam);

	//! \brief  循环标注的周期长度。
	UGdouble GetRepeatLength()const;
	void SetRepeatLength(UGdouble dRepeatLength);

	//! \brief  沿线标注循环标注的周期长度。周期长度，只有沿线文本时有效。
	UGbool IsFixedRepeatLength()const;
	void SetFixedRepeatLength(UGbool bFixedRepeatLength);
	
	//! \brief  文本间距，单位为字高的倍数。大于1就以线中心为准，按指定间隔往两边标注，0到1之间就在线中心标注沿线角度的单个文本。
	//! \brief  小于等于0就采用默认的沿线标注。只对沿线标注起作用。
	void SetFontSpaceRatio(UGdouble dFontSpaceRatio);
	UGdouble GetFontSpaceRatio() const;

	//! \brief  根据线方向类型，计算线是否需要返向。
	static void ChangeLineDirection(UGGeoLine* pSubLine, UGint nLineDirection);

	//! \brief  沿线文本的标注方向。只对沿线标注起作用。
	UGint GetLineDirection()const;
	void SetLineDirection(UGint nLineDirection);

	//! \brief  当前可见区域本图层显示的最大标注个数，超过该值后面的就不显示。
	UGint GetMaxTextNum()const;
	void SetMaxTextNum(UGint nMaxTextNum);



	UGDict<UGint, UGPoint2D> m_arrCustomLabel;
	//! \brief 获取专题图对象的hashcode
	virtual UGint GetHashCode() const;

	//! \brief 字符串拆分成单字，英文以空格隔开。
	static void StringToWordArray(const UGString, UGStrArray& strs);
	void SetLeaderLineToBack(UGbool bLeaderLineToBack);
	UGbool IsLeaderLineToBack();

protected:  
	void Swap(const UGThemeLabel& theme);
	//! \brief  范围专题图分段方式
	void ClassifyWithCustomInterval(UGdouble dInterval, UGdouble dMaxVaue, UGdouble dMinValue);
	void ClassifyWithEqualDistance(UGint nClasses, UGdouble dMaxVaue, UGdouble dMinValue);
	void ClassifyWithExtraction(UGint nClasses, UGdouble dMaxVaue, UGdouble dMinValue);
	void ClassifyWithStdev(const UGArray<UGdouble> &arySrc);
	void Stdev(const UGArray<UGdouble> &arySrc, UGdouble &dMean, UGdouble &dStdev);
	void ClassifyWithLogarithm(UGint nClasses, UGdouble dMaxVaue, UGdouble dMinValue);
	void ClassifyWithQuantile(UGint nClasses, UGint nKeyCount, UGDatasetVector* pDatasetV, const UGArray<UGJoinItem>& JoinItems);

protected:	
	UGTextStyle	m_LabelStyle; 
	UGString m_strExpression;
	UGint m_nBackType;
	UGStyle m_BackStyle;

	//! \brief  保存单独设置文本风格时的分段值和各个段值的风格
	UGArray<UGdouble > m_Values;
	UGArray<UGLabelTextStyle> m_RangeTextStyle;

public:
	UGbool m_bDescending;

protected:	
	UGString m_strTextExpression;

	//! \brief 文本规定字数
	UGint m_nTextLengthLimit;
	UGint m_nLabelOverLengthMode;
	
	UGbool m_bLabelAlwaysOnTop;
	UGString m_strNumFormat;
	UGdouble m_dRepeatLength;
	UGdouble m_dFontSpaceRatio;
	UGint m_nLineDirection;
	UGint m_nMaxTextNum;
	UGArray<UGString> m_arrExpression;
	UGbool m_bLeaderLineToBack;		//是否将牵引线合并到背景框中
};

}

#endif // !defined(AFX_UGTHEMELABEL_H__5FD9A9BE_3A6F_4D8D_9BF0_EEDFA9C7B072__INCLUDED_)
