/*! \file	 UGQueryDef.h
 *  \brief	 查询定义类
 *  \author	 ugc team
 *  \attention 
 *  Copyright(c) 1996-2004 SuperMap GIS Technologies,Inc.<br>
 *  All Rights Reserved
 *  \version $Id: UGQueryDef.h,v 1.14 2008/04/03 03:51:11 zhouqin Exp $
 */

#include "Base/ugdefs.h"
#include "Base/UGString.h"
#include "Base/UGArray.h"
#include "Geometry/UGGeometry.h"
#include "Algorithm/UGRect2D.h"
#if PACKAGE_TYPE==PACKAGE_UGC
#include "Base/UGTime.h"
#include "Engine/UGDsConnection.h"
#endif // end declare ugc sdk
#ifndef UGQUERY_H
#define UGQUERY_H

namespace UGC
{

//! 关联查询项
struct ENGINE_API UGJoinItem
{	
	//! 连接类型枚举
	enum JoinType
	{
		InnerJoin						=0, //! 内连接
		LeftJoin						=1, //! 左连接
		RightJoin						=2, //! 右连接
		FullJoin						=3  //! 全连接
	};

	//! 连接类型
	JoinType m_nJoinType;
	//! 外部表名
	UGString m_strForeignTable;
	//! 外部连接条件
	//! 表AA BB : AA.Field1 = BB.Field2
	UGString m_strJoinFilter;
	//! 名称
	UGString m_strName;

public:
	UGbool operator==(UGJoinItem joinItem);
};

//! 关联查询项
struct ENGINE_API UGLinkItem
{	
	//! 外部表名，如果是SuperMap的数据集 则应为数据集名字
	UGString m_strForeignTable;

	//! 主空间数据集的外键
	UGArray<UGString > m_aryForeignKeys;

	//! 属性表的外键
	UGArray<UGString > m_aryPrimaryKeys;
	
	//! 名称
	UGString m_strName;

	//! 外部数据源
	UGDsConnection m_DsConnect;

	//! 外挂异构属性表的过滤条件,只有在使用m_DsConnect,使用
	UGString m_strFilter;

	//! 属性表的字段
	UGArray<UGString > m_aryFields;
};

//! 查询定义类
class ENGINE_API UGQueryDef
{
public:
	//! 查询类型枚举
	enum QueryType
	{
		General							=0, //! 一般查询
		Bounds							=1, //! 使用Bounds查询
		IDs								=2, //! 使用ID数组查询
	};

	//! 查询选项枚举
	enum QueryOption
	{		
		Geometry						= 1,//! 查询几何对象
		Attribute						= 2,//! 查询属性信息
		Both							= 3 //! 查询几何对象及属性信息
	};

	//! 查询模式枚举
	enum QueryMode
	{
		GeneralQuery					=0x00000000, //! 一般查询
		FuzzyQuery						=0x00000001  //! 模糊查询
	};

#if PACKAGE_TYPE==PACKAGE_UGC
	//! 游标类型枚举
	enum CursorType
	{
		OpenForwardOnly					=0, //! 前向滑动游标
		OpenKeyset						=1, //! 关键集游标
		OpenDynamic						=2, //! 动态游标
		OpenStatic						=3, //! 静态游标
		OpenUnspecified					=-1 //! 未定义
	};

	//! 游标位置枚举
	enum CursorLocation
	{
		UseDefault						=1, //! 不指定游标位置
		UseServer						=2, //! 服务器端游标
		UseClient						=3  //! 客户端游标
	};

#endif // end declare ugc sdk

public:
	//! 构造函数
	UGQueryDef();
	//! 析构函数
	~UGQueryDef();
	
	void operator=(const UGQueryDef &querydef);

	UGbool operator==(const UGQueryDef &querydef);

	//! 将查询定义信息存为XML格式
	//! \param nVersion 版本号
	//! \return 导出的XML格式字符串
	UGString ToXML(UGint nVersion) const;

	//! 从XML中解析查询定义信息(存储工作空间时，有可能会用到，比如替换以前地图的DisplayFilter)
	//! \param strXML XML格式字符串
	//! \param nVersion 版本号	
	UGbool FromXML(const UGString& strXML,UGint nVersion);

protected:
	UGString GetQueryType(QueryType nType) const;
	void SetQueryType(UGString strQueryType);

public:
	//! 查询类型(General,Bounds,IDs及各种空间查询等）
	//! 必须 (默认 General)
    QueryType			m_nType;
	
	//! 查询选项(是否返回Geometry或Attribute,或两者都有等）
	//! 必须 （默认 Both）
	QueryOption			m_nOptions;

	//! 查询方式(GeneralQuery或FuzzyQuery)
	//! 可选 默认呢，GeneralQuery
	QueryMode			m_nMode;

	//! 属性数据查询条件
	//! 可选 默认 ""
	UGString			m_strFilter;
	
	//! 属性数据查询排序
	//! 可选 默认 ""
	UGString			m_strSort;
	
	//! 属性数据查询字段名
	//! 可选 默认 ""
	UGArray<UGString>	m_Fields;

	//! 存储外挂关联条件
	//! 可选 默认 ""
	UGArray<UGJoinItem>	m_JoinItems;

	//! 外挂关联属性表
	UGArray<UGLinkItem>	m_aryLinkItems;
	//! 属性数据分组语句
	//! 可选 默认 ""
	UGString			m_strGroup;

	//! 空间查询时需要的几何对象
	//! 可选 默认 NULL
	UGGeometry*			m_pGeometry;

	//! Bounds查询时的外接矩形
	//! 可选 默认 empty
	UGRect2D			m_rc2Bounds;

	//! ID查询时的ID队列
	//! 可选 默认 ""
	UGArray<UGint>		m_IDs;

	//! ID查询时的ID队列,目前只支持数值型字段
	//! 可选 默认 ""
	UGString			m_strIDFieldName;

	//! Bounds 查询,并且 m_nMode = FuzzyQuery
	//! 可选 默认 0
	UGdouble			m_dGranule;

	//! 游标(光标)类型
	//! 可选 默认 OpenDynamic
	CursorType			m_nCursorType;

	//! 游标位置
	CursorLocation		m_nCursorLocation;

	//! 时序数据的显示时间点
	UGTime				m_SequenceTime;
};

}

#endif

