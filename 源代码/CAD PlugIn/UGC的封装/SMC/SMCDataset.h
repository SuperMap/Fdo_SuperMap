/*! 
	\file	SMCDataset.h
    \brief	数据集基类（抽象类）
	\author	周旭
	\attention
	----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2007 SuperMap GIS Technologies,Inc.                            <br>
    All Rights Reserved.                                                              <br>
    ----------------------------------------------------------------------------------<br> 
	\version 2007-9-19 初始化版本
*/


#ifndef SMCDATASET_H
#define SMCDATASET_H

#include "SMC.h"

class SMCDataSource;

class SMC_API SMCDataset
{
public:
	//! brief	数据集类型
	enum DatasetType
	{
		Tabular		=0,		//! 只有属性表，没有几何对象
		Point		=1,		//! 点数据集
		Line		=3,		//! 线数据集
		Network		=4,		//! 网络数据集
		Region		=5,		//! 多边形数据集
		Text		=7,		//! 文本数据集
		LineM		=35,	//! 路线数据集
		Image		=81,	//! 影像
		MrSID		=82,	//! MrSID
		Grid		=83,	//! 栅格
		DEM			=84,	//! DEM
		ECW			=85,	//! ECW
		WMS			=86,	//! WMS		
	
		PointZ		=101,	//! 三维点
		LineZ		=103,	//! 三维线
		RegionZ		=105,	//! 三维面
		PointGL		=137,	//! 带法向量的Point3D
		TIN			=139,	//! TIN数据集
		CAD			=149,	//! CAD数据集
		
		WFS			=151,	//! WFS
		LinkTable	=153,	//! 数据库表,只读功能
		Topo		=154	//! Topo数据集	
	}; 

public:
	SMCDataset();
	~SMCDataset();

public:
	//! \brief	打开数据集
	virtual bool Open() = 0;

	//! \brief	关闭数据集
	virtual void Close() = 0;

	//! \brief 		得到数据集类型
	//! \return     SMCDataset::DatasetType (or int) 返回数据集类型，见上面数据集类型枚举定义
	virtual DatasetType GetType() const=0;

	//! \brief		返回数据集名(可以和表名不同)
	virtual _tstring GetName() =0;

	//! \brief		数据集重命名,只改变数据集名,表名不变
	//! \param		steNewName  修改后的新名字
	//! \return     bool 修改成功返回true， 否则返回false
	virtual bool Rename(const _tstring& strNewName) = 0;

	//! \brief		判断是否是矢量数据集
	//! \return		bool 是矢量数据集返回true， 否则返回false
	virtual bool IsVector() =0;

	//! \brief		保存数据集信息
	//! \return		bool 保存成功返回true， 否则返回false
	virtual bool SaveInfo() = 0;

	//! \brief		刷新数据集信息
	//! \return		bool 刷新成功返回true， 否则返回false
//	virtual bool RefreshInfo() = 0;	

public:
	//! \brief		返回数据集的ID
	//! \return		int 数据集的ID
	int GetID() const ;

	//! \brief		设置数据集的ID
	//! \param		nID 待设置的ID号
	void SetID(int nID);

	//! /brief		返回数据源指针
	//! /param[out] pDataSource返回数据集所属的数据源
	//! /return		bool获取数据源成功返回true，否则返回false
	bool GetDataSource(SMCDataSource*& pDataSource) const ;

	//! /brief		设置数据源指针
	//! /param	    pDataSource,把数据集设为属于此数据源
	void SetDataSource(SMCDataSource* pDataSource);

	//! /brief		判断数据集是否被修改
	//! return		如果被修改则返回true， 否则返回false
	bool IsModified() const;

	//! /brief		设置修改标志
	//! /param		bModified,如果修改了数据集则设为true，否则设为false，默认设为true
	void SetModifiedFlag(bool bModified = TRUE);

	//! /brief		判断数据集是否已经打开
	//! /return     bool如果已经打开则返回true，否则返回false
	virtual bool IsOpen() const;

public:
	void *m_pDataset;
};

#endif