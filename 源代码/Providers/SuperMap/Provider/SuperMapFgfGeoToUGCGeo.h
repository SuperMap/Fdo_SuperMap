/** \file	 SuperMapFgfGeoToUGCGeo.h
*  \author	 马俊
*  \attention 
*  Copyright &copy;  1996-2007 SuperMap GIS Technologies,Inc.<br>
*  All Rights Reserved
*  \version 1.0
*  \date 2007-11-12
*/

#ifndef __SUPERMAP_FGFGEOTOUGCGEO_H__
#define __SUPERMAP_FGFGEOTOUGCGEO_H__
#ifdef _WIN32
#pragma once
#endif // _WIN32

/*! \class SuperMapFgfGeoToUGCGeo SuperMapFgfGeoToUGCGeo.h
	\brief 转化几何对象，从FDO到UGC，用于插入或者更新的操作
    return 指向UGC几何对象的指针
*/

class SuperMapFgfGeoToUGCGeo
{
public:
	SuperMapFgfGeoToUGCGeo(void);
	SuperMapFgfGeoToUGCGeo(FdoByteArray *byteArray, bool IsTextDataset = false, 
		                   UGC::UGString strText = "", double textSize = 0.0, 
						   bool IsCADDataset = false, bool IsSpatialCondition = false); //modified by zhoux

public:
	/*
		\brief 转化几何对象，从FDO到UGC
		\return 指向UGC几何对象的指针
		\note m_FgfArray不能为空
	*/
	UGC::UGGeometry *GetGeometry();

private:

	/*
		\brief 创建UGC点
		\param [in]pFgfArray 从维度开始的，指向FDO几何对象
		\param [in]bMultiPoint  是否创建多点的标志，缺省为假，用于处理CAD数据集时有多点的可能
		\note m_FgfArray不能为空
	*/
	void CreateUGCPoint(const int *pFgfArray, bool bMultiPoint = false);

	/*
		\brief 创建UGC线
		\param [in]pFgfArray 从维度开始的，指向FDO几何对象
		\param [in]bMultiLine  是否创建多线的标志，缺省为假
		\note m_FgfArray不能为空
	*/
	void CreateUGCLine(const int *pFgfArray, bool bMultiLine = false);

	/*
		\brief 创建UGC面
		\param [in]pFgfArray 从维度开始的，指向FDO几何对象
		\param [in]bMultiPolygon  是否创建多面的标志，缺省为假
		\note m_FgfArray不能为空
	*/
	//void CreateUGCRegion(const int *pFgfArray);
	void CreateUGCRegion(const int *pFgfArray, bool bMultiPolygon = false);

	/*
		\brief 创建UGC文本
		\param [in]pFgfArray 从维度开始，指向FDO点对象
		\note m_FgfArray不能为空
	*/
	void CreateUGCText(const int *pFgfArray);             // added by zhouxu


	/*
		\brief 以下两个函数用于创建UGC二维或者三维点，目前简单的忽略第三维
		\param [in]nPointNum 点数，对于点数据集，值为1，但是CAD数据集不是1 
		\param [in]pUGCGeoArray  坐标数组
		\param [in]bMultiLine  是否创建多点的标志，缺省为假
	*/
	void CreateUGC_XYPoint(int nPointNum, double *pUGCGeoArray, bool bMultiPoint = false);
	void CreateUGC_XYZPoint(int nPointNum, double *pUGCGeoArray, bool bMultiPoint = false);

	/*
		\brief 以下两个函数用于创建UGC二维或者三维线，目前简单的忽略第三维
		\param [in]nLineNum 线数，对于简单线，值为1，对于复杂线，不为1 
		\param [in]nPointsNum 第一条线的点数
		\param [in]pUGCGeoArray  指向所有线的坐标数组
		\param [in]bMultiPolygon  是否创建多线的标志，缺省为假
	*/
	void CreateUGC_XYLine(int nLineNum, int nPointsNum, double *pUGCGeoArray);
	void CreateUGC_XYZLine(int nLineNum, int nPointsNum, double *pUGCGeoArray);

	/*
		\brief 以下两个函数用于创建UGC二维或者三维面，目前简单的忽略第三维
		\param [in]nPolygonNum 面数 
		\param [in]nRingPtsNum 第一个环的点数
		\param [in]pUGCGeoArray  指向所有环的坐标数组
		\param [in]bMultiPolygon  是否创建多面的标志，缺省为假
	*/
	void CreateUGC_XYRegion(int nPolygonNum, int nRingNum, int nRingPtsNum, double *pUGCGeoArray);
	void CreateUGC_XYZRegion(int nPolygonNum, int nRingNum, int nRingPtsNum, double *pUGCGeoArray);

private:
	UGC::UGGeometry *m_pUGGeometry;		//指向UGC几何对象的指针，调用者使用完毕后必须释放空间，否则内存泄露 
	FdoPtr<FdoByteArray> m_FgfArray;	//指向FDO几何对象的指针
	bool m_IsCADDataset;				//判断时候是CAD数据集，用于处理多点的情况
	bool m_IsSpatialCondition;			//判断是否是空间查询，空间查询时有三维和多点的情况

protected:    // added by zhouxu 
	bool m_IsPointOfTextDataset;		//用于判断是否文本数据集的点
	UGC::UGString m_strText;			//存储文本数据集的文本内容
	double m_dTextSize;					//存文本大小
	
public:
	virtual ~SuperMapFgfGeoToUGCGeo(void);
};

#endif // __SUPERMAP_FGFGEOTOUGCGEO_H__
