/** \file	 SuperMapGeoToFgfGeo.h
*  \author	 马俊
*  \attention 
*  Copyright &copy;  1996-2007 SuperMap GIS Technologies,Inc.<br>
*  All Rights Reserved
*  \version 1.0
*  \date 2007-11-09
*/

#ifndef __SUPERMAP_GEOTOFGFGEO_H__
#define __SUPERMAP_GEOTOFGFGEO_H__
#ifdef _WIN32
#pragma once
#endif // _WIN32

/*! \class SuperMapGeoToFgfGeo SuperMapGeoToFgfGeo.h
	\brief 几何对象转化，从UGC到FDO，用于查询操作时
    return 以FdoByteArray 的形式返回FDO几何对象
*/

class SuperMapGeoToFgfGeo
{
public:
	SuperMapGeoToFgfGeo(void);
	SuperMapGeoToFgfGeo(UGC::UGRecordset *pRecordset);

public:
	virtual ~SuperMapGeoToFgfGeo(void);

public:
	/*
		\brief 得到转化后的FDO几何对象
		\return 以FdoByteArray 的形式返回FDO几何对象
		\note UGC的记录集不能为空
	*/
	FdoByteArray *GetGeometry();

private:
	/*
		\brief 以二维的形式创建FDO几何对象, 包括点、线、面、CAD数据集中的几何对象
		\note m_pElemGeometry 不能为空
	*/
	void CreateFdoGeo();

	/*
		\brief 以二维的形式创建FDO点
		\note m_pElemGeometry 不能为空
	*/
	void CreateFdoPoint();

	/*
		\brief 以二维的形式创建FDO多线
		\note m_pElemGeometry 不能为空
	*/
	void CreateFdoMultiLine();

	/*
		\brief 以二维的形式创建FDO面
		\note m_pElemGeometry 不能为空
	*/
	void CreateFdoPolygon();

	/*
		\brief 以二维的形式创建CAD数据集中组合对象对应的FDO几何对象，包括各种几何对象
		\note m_pElemGeometry 不能为空
	*/
	void CreateFdoCompoundGeometry();

	/*
		\brief 得到UGC组合几何对象的空间数据
		\param[in] 指向组合对象的指针
		\param[out] 存放几何对象空间数据的数组
		\param[out] 存放各个子对象点数的数组
		\param[out] 子对象数组
		\param[out] 该组合集合对象子对象的类型
 		\note pGeometry 不能为空，可用于递归调用，处理多级组合对象的情况
	*/
	void GetCompoundSpatialData(UGC::UGGeometry *pGeometry, 
								UGC::UGArray<UGC::UGPoint2D> &points, 
								UGC::UGArray<UGC::UGint> &nSubPointsCount, 
								UGC::UGint &nSubCount,
								UGC::UGint &nGeoType);

	/*
		\brief 判断组合几何对象的所有子对象的类型是否一样 
		\param[in] pGeometry 指向组合对象的指针
		\param[in] bFirstCall 标志是否是第一次调用，达到各个几何对象的类型互不影响
		\return 如果所有子对象的类型都一样的话，返回真，否这返回假
 		\note pGeometry不能为空，可用于递归调用，处理多级组合对象的情况
	*/
	bool IsSameCompoundGeometry(UGC::UGGeometry *pCompoundGeometry, bool bFirstCall);

private:
	UGC::UGRecordset *m_pRecordset;					//UGC记录集 
	UGC::UGGeometry *m_pElemGeometry;				//从记录集中取出的几何对象的指针
	UGC::UGArray<double> m_fdoCoordinatesArray;		//存放构造FDO几何对象的坐标数组
	FdoPtr<FdoByteArray> m_pRetByteArray;			//以Fgf格式返回的FDO几何对象的数组指针
	FdoFgfGeometryFactory *m_pFdoGeoFactory;		//FGF几何工厂

	UGC::UGAutoPtr<UGC::UGPoint2D> m_points;		//存放所有子对象坐标信息的数据
	UGC::UGAutoPtr<UGC::UGint> m_subPointsCount;	//UGC几何对象各个子对象点数的数组
	UGC::UGint m_nSubCount;							//UGC几何对象子对象的个数
};


#endif // __SUPERMAP_GEOTOFGFGEO_H__