/*! \file 		UGRectify.h
*   \brief 		多项式几何校正 (polynomal geometrical correction) 
*   \remarks 	配准 
*   \author 	LIWENLONG 
*   \date 	2004-12-27 10:55:13

*   Copyright(c) 1996-2004 SuperMap GIS Technologies,Inc.<br> 
*        All Rights Reserved 

*    <b>更新说明：</b><br> 
*/ 


#if !defined(UGRECTIFY_H)
#define UGRECTIFY_H

#include "Base/ugdefs.h"
#include "Base/UGString.h"
#include "Base/UGArray.h"
#include "Algorithm/UGMatrix.h"
#include "Algorithm/UGPoint2D.h"
#include "Geometry/UGGeometry.h"
#include "Engine/UGDataSource.h"

namespace UGC{


class OPERATION_API UGRectifyError  
{
public:
	UGRectifyError(){};
	virtual ~UGRectifyError(){};
public:
	UGdouble dResidualX;  //X方向残差
	UGdouble dResidualY;  //Y方向残差
	UGdouble dOffsetX;    //X方向偏移的象素个数
	UGdouble dOffsetY;    //Y方向偏移的象素个数
    UGdouble dRMS;        //该点的均方差
};

class OPERATION_API UGRectifyErrors : public UGArray <UGRectifyError>
{
public:
	UGRectifyErrors()
	{
	};
	virtual ~UGRectifyErrors()
	{
		if(UGRectifyErrors::GetSize()>0)
		{
			UGRectifyErrors::RemoveAll();
		}
	};
public:
	UGdouble m_dTotalRMS;
};


class OPERATION_API UGRectify  
{
public:
	UGRectify();
	virtual ~UGRectify();

	enum seTransformMethod
	{
		sctRect		= 0, /// 矩形配准(至少2个点)
		sctLinear	= 1, /// 线性配准(至少3个点) 
		sctSquare	= 2, /// 二次配准(至少6个点)
		sctCubic	= 3 /// 立方配准(至少10个点)
	};

	//! \brief 		获取配准误差信息：
	//! \return 	UGbool
	//! \param 		errors
	//! \param 		nMethod
	//! \remarks 		
	UGbool GetErrors(UGRectifyErrors& errors,UGlong nMethod);

	//! \brief 		设置控制点
	//! \return 	UGbool
	//! \param 		OriginalPoints 原始控制点
	//! \param 		TargetPoints   目标控制点
	//! \remarks 		
	UGbool SetContrlPoints(UGPoint2Ds& OriginalPoints,UGPoint2Ds& TargetPoints);

	//! \brief 		设置原始控制点
	//! \return 	UGbool
	//! \param 		OriginalPoints
	//! \remarks 		
	UGbool SetOriginGCP(UGPoint2Ds& OriginalPoints);

	//! \brief 		设置目标控制点
	//! \return 	UGbool
	//! \param 		TargetPoints
	//! \remarks 		
	UGbool SetTargetGCP(UGPoint2Ds& TargetPoints);

	//! \brief 		变换矢量数据对象
	//! \return 	UGbool
	//! \param 		nMethod
	//! \param 		pGeometry
	//! \remarks 	配准方法	
	UGbool RectifyGeometry(UGlong nMethod,UGGeometry* pGeometry);
	//! \brief 		变换矢量图层
	//! \return 	UGbool
	//! \param 		nMethod
	//! \remarks 	配准方法	
	UGbool RectifyVector(UGlong nMethod);

	//! \brief 		撤销
	//! \return 	BOOL
	//! \remarks 		
	UGbool RectifyUndo();
	

	//! \brief 	    重做
	//! \return 	BOOL
	//! \remarks 		
	UGbool RectifyRedo();

	//! \brief 		配准影像图层
	//! \return 	UGbool
	//! \param 		nMethod        配准方法
	//! \param 		strNewLayer
	//! \param 		pSmDatasource=NULL
	//! \remarks 	生成新的数据集所在的数据源，不能是readonly打开的！如果pSmDatasource==NULL,默认使用m_pImgDataset所在的数据源	
	UGbool RectifyImg(UGlong nMethod,UGString strNewLayer,UGDataSource* pSmDatasource=NULL);

	//! \brief 		不重采样配准影像图层
	//! \return 	UGbool
	//! \param 		nMethod
	//! \remarks 	配准方法
	UGbool Rectify(UGlong nMethod);

	//! \brief 		得到总的均方差
	//! \return 	UGdouble
	//! \remarks 		
	UGdouble GetTotalRMS();

	//! \brief 		得到多项式的系数：
	//! \return 	UGString
	//! \remarks 		
	UGString GetCoefficient();

	//! \brief 		矩形栅格配准，不生成新的数据集
	//! \return 	UGbool
	//! \remarks 		
	UGbool RectifySelf();

protected:

	//! \brief 		计算转换参数
	//! \return 	UGint
	//! \param 		nMethod			TRUE为直接法，FALSE为间接法
	//! \param 		bMethod=FALSE
	//! \remarks 	返回1表示成功，返回0表示失败，返回-1表示不能进行该次参数的计算，需降次处理	
	UGint CalParam(UGlong nMethod,UGbool bMethod=FALSE);

	//! \brief 		计算转换参数,只做系数计算和计算误差，不做系数检验	
	//! \return 	UGbool
	//! \param 		nMethod
	//! \param 		InvsParamX		InvsParamX,InvsParamY为计算所得系数
	//! \param 		InvsParamY
	//! \param 		bMethod=FALSE	TRUE为直接法，FALSE为间接法
	//! \remarks 		
	UGbool CalParamSimple(UGlong nMethod,UGMatrix& InvsParamX,UGMatrix& InvsParamY,UGbool bMethod=FALSE);

	//X坐标反解
	UGdouble XTransPoint(UGint numParam,UGMatrix& TransParam,UGPoint2D &point);
	//Y坐标反解
	UGdouble YTransPoint(UGint numParam,UGMatrix& TransParam,UGPoint2D &point);

	//X坐标反解
	//注意只在重采样时为了加速才使用的，必须预先设定参数数组m_dParamX
	UGdouble XTransPoint(UGint numParam,UGPoint2D &point);
	//Y坐标反解
	//注意只在重采样时为了加速才使用的，必须预先设定参数数组m_dParamY
	UGdouble YTransPoint(UGint numParam,UGPoint2D &point);

	//坐标反解   由变换后的点求其共轭点的坐标
	UGdouble TransPoint(UGint numParam,UGMatrix& TransParam,UGPoint2D& point);

	//最邻近元重采样 
    UGbool NeighborestResample();

	//四舍五入取整
	UGint GetInt(UGdouble dvalue);

	//得到变换后的地理坐标范围
	UGbool RectifyMBR(UGlong nMethod);

	//! \brief 		设置系数矩阵
	//! \return 	UGbool
	//! \param 		&pntXY			控制点数组
	//! \param 		Coefficent		生成求转换参数的系数矩阵
	//! \param 		nMethod			配准方法
	//! \remarks 		
    UGbool SetCoefficientMatrix(UGPoint2Ds &pntXY,UGMatrix& Coefficient,UGlong nMethod);

	//! \brief 		返回加权后的转换参数
	//! \return 	UGbool
	//! \param 		Coefficient		系数矩阵
	//! \param 		&XYMatrix		X/Y的坐标阵
	//! \param 		ReParam			X/Y方向加权后的转换参数
	//! \remarks 		
	UGbool CalcuReParam(UGMatrix& Coefficient,UGMatrix &XYMatrix,UGMatrix& ReParam);

	//! \brief 		返回X/Y方向改正数向量
	//! \return 	UGbool
	//! \param 		&Coefficient	系数矩阵
	//! \param 		&Observation	一组X/Y的观测值
	//! \param 		&Param			由二乘法计算的转换参数
	//! \param 		&RectifierX		改正数向量
	//! \remarks 		
	UGbool CalcuError(UGMatrix &Coefficient,UGMatrix &Observation,UGMatrix &Param,UGMatrix &Rectifier);

public:
    //!指向影像数据集
	UGDatasetRaster* m_pImgDataset;
	//!指向新的影像数据集
	UGDatasetRaster* m_pNewImgDataset;
	//!指向矢量数据集
	UGDatasetVector* m_pDatasetVector;

protected:
	
	//原始控制点
	UGPoint2Ds m_SrcControlPoint;
	//目标控制点
	UGPoint2Ds m_DestControlPoint;
	//配准后的数据集地理坐标范围
	UGRect2D m_rcRectify;

	UGlong m_lColIndex;             //原始图像块的列号
	UGlong m_lRowIndex;             //原始图像块的行号
	UGlong m_lNewColIndex;          //新的图像块的列号
	UGlong m_lNewRowIndex;          //新的图像块的行号

	UGMatrix m_ParamX;  //X的转换系数
	UGMatrix m_ParamY;  //Y的转换系数
	UGMatrix m_ErrorX;  //X的误差矩阵
	UGMatrix m_ErrorY;  //Y的误差矩阵

	UGdouble m_dParamX[10];
	UGdouble m_dParamY[10];

	UGdouble m_dTotalRMS; //最小均方差之和
	
};

}

#endif // !defined(UGRECTIFY_H)
