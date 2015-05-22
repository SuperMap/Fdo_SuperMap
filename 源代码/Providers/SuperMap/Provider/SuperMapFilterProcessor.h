
/** \file	 SuperMapFilterProcessor.h
*  \author	 马俊
*  \attention 
*  Copyright &copy;  1996-2007 SuperMap GIS Technologies,Inc.<br>
*  All Rights Reserved
*  \version 1.0
*  \date 2007-11-28
*/

#ifndef __SUPERMAP_FILTERPROCESSOR_H__
#define __SUPERMAP_FILTERPROCESSOR_H__
#ifdef _WIN32
#pragma once
#endif // _WIN32

/*! \class SuperMapFilterProcessor SuperMapFilterProcessor.h
	\brief 用于处理过滤条件
	return 以字符串的形式返回过滤表达式
*/

class UGSpatialQuery;

class SuperMapFilterProcessor : public FdoIFilterProcessor
{
public:
	SuperMapFilterProcessor(UGC::UGEngineType DsEngineType);

public:
	~SuperMapFilterProcessor(void);

public:
	virtual void Dispose() 
	{ 
		delete this; 
	}

	/// \brief
    /// Processes the FdoBinaryLogicalOperator passed in as an argument.
    /// 
    /// \param filter 
    /// Input the FdoBinaryLogicalOperator
    /// 
    /// \return
    /// Returns nothing
    /// 
    virtual void ProcessBinaryLogicalOperator(FdoBinaryLogicalOperator& filter);

    /// \brief
    /// Processes the FdoUnaryLogicalOperator passed in as an argument.
    /// 
    /// \param filter 
    /// Input the FdoUnaryLogicalOperator
    /// 
    /// \return
    /// Returns nothing
    /// 
    virtual void ProcessUnaryLogicalOperator(FdoUnaryLogicalOperator& filter);

    /// \brief
    /// Processes the FdoComparisonCondition passed in as an argument.
    /// 
    /// \param filter 
    /// Input the FdoComparisonCondition
    /// 
    /// \return
    /// Returns nothing
    /// 
    virtual void ProcessComparisonCondition(FdoComparisonCondition& filter);

    /// \brief
    /// Processes the FdoInCondition passed in as an argument.
    /// 
    /// \param filter 
    /// Input the FdoInCondition
    /// 
    /// \return
    /// Returns nothing
    /// 
    virtual void ProcessInCondition(FdoInCondition& filter);

    /// \brief
    /// Processes the FdoNullCondition passed in as an argument.
    /// 
    /// \param filter 
    /// Input the FdoNullCondition
    /// 
    /// \return
    /// Returns nothing
    /// 
    virtual void ProcessNullCondition(FdoNullCondition& filter);

    /// \brief
    /// Processes the FdoSpatialCondition passed in as an argument.
    /// 
    /// \param filter 
    /// Input the FdoSpatialCondition
    /// 
    /// \return
    /// Returns nothing
    /// 
    virtual void ProcessSpatialCondition(FdoSpatialCondition& filter);

    /// \brief
    /// Processes the FdoDistanceCondition passed in as an argument.
    /// 
    /// \param filter 
    /// Input the FdoDistanceCondition
    /// 
    /// \return
    /// Returns nothing
    /// 
    virtual void ProcessDistanceCondition(FdoDistanceCondition& filter);

public:
	/*
		\brief 得到解析后的过滤表达式
		\return 以字符串的形式返回解析后的过滤表达式
	*/
	const char* GetFilterText() 
	{ 
		return m_StringBuff.GetString(); 
	}  

	/*
		\brief 得到空间查询时的几何对象
		\note 使用完该几何对象后，调用者必须释放内存空间，否则会有内存泄露
	*/
	UGC::UGGeometry *GetGeometry();
	
	/*
		\brief 得到空间查询的类型
		\return 空间查询类型
	*/
	int GetSpatialQueryType();


protected:
	/*
		\brief 用于处理过滤串，用于递归调用，处理Filter的左或者右
		\param [in]Filter 指向Fileter的左Filter或者右Filter
		\note 用于递归调用
	*/
	void ProcessFilter(FdoFilter* Filter); 

	/*
		\brief 用于处理表达式
		\param [in]Expr 指向表达式处理器类的指针
		\note 用于处理表达式
	*/
    void ProcessExpresion( FdoExpression* Expr, bool bSpatialCondition=false, bool bEnvelopeIntersect=false);

	/*
		\brief 以下两个函数用于在过滤串的前面或者后面添加字符串
		\param [in]Str 指向要添加字符串的指针
	*/
    void AppendString(const char *Str);
    void PrependString(const char *Str);

protected:
	SuperMapFilterStringBuffer m_StringBuff;	//用于存放解析后的过滤串的缓存区
	UGC::UGGeometry *m_pGeometry;				//用于空间查询时生成的UGC几何对象
	UGC::UGEngineType m_DsEngineType;			//数据源引擎类型，用于处理bool或者时间属性，不用的引擎，格式不同
	int m_nSpatialQueryType;					//空间查询的类型 如果定义成UGC::UGSpatialQuery::SpatialQueryMode type 出错，郁闷!!! 

public:
	std::vector<UGC::UGGeometry *> m_GeometryArray; //多个空间查询条件时，存放UGC几何对象的数组

};

#endif