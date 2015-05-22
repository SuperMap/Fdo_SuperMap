// UGKrigingBuilder.h: interface for the UGKrigingBuilder class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(UGKRIGINGBUILDER_H)
#define UGKRIGINGBUILDER_H

#include "GridAnalyst/UGGridBuilder.h"
#include "GridAnalyst/UGGridOptions.h"

namespace UGC{
class UGQuadNode;
class UGKdTree;
class UGKrigingBuilder: public UGGridBuilder  
{
public:    
	UGKrigingBuilder();
	virtual ~UGKrigingBuilder();
	//! \brief 计算变差函数的确省参数 not implemented yet
	void CalculateDefaultParameters(UGdouble& dRange,UGdouble& dNugget,UGdouble& dSill,const UGGridOptions& options);
protected:
	//! \brief 通过查找最近点进行插值
	virtual UGbool DoInterpolation(UGDatasetRaster* pResultGrid,const UGGridOptions& options);	
	//! \brief 不进行搜索，用全部的点进行运算，这对于点数两比较少的时候比较有效
	UGbool Interpolate1(UGDatasetRaster* pResultGrid,const UGGridOptions& options);
	//! \brief 按照KDTree找临近点的方法计算,指定点数
	UGbool Interpolate2(UGDatasetRaster* pResultGrid,const UGGridOptions& options);
	//! \brief 按照KDTree找临时点,指定距离
	UGbool Interpolate21(UGDatasetRaster* pResultGrid,const UGGridOptions& options);
	//! \brief 按照四茶树分块进行插值
	UGbool Interpolate3(UGDatasetRaster* pResultGrid,const UGGridOptions& options);
	//! \brief Implemention details here
	void QuadInterpolate(UGDatasetRaster* pResultGrid,UGQuadNode* pTree);
	//! \brief 对数据进行分组,not implemented yet
	void RegroupThePoints(UGdouble dLagSize, UGint nLagNums);
	
	UGdouble KGetRange(void);
	UGbool TranspMatrix(UGdouble *pMatrix_arg, UGint iM_arg,UGint iN_arg,UGdouble *pTranspMatrix_arg);	
	//功能：计算矩阵的乘积；
	//参数：pLMatrix_arg: 左矩阵的指针；
	//      iLm_arg     : 左矩阵的行数；
	//      iLn_arg     : 左矩阵的列数；
	//      pRMatrix_arg: 右矩阵的指针；
	//      iRm_arg     : 右矩阵的行数；
	//      iRn_arg     : 右矩阵的列数；
	//      pMultiMatrix_arg : 乘积后的结构矩阵；
	//返回值：如果计算成功返回true,否则返回false;
	//  可能的改进：试着用斯特拉森算法实现。    
	UGbool CalMatrix(UGdouble  *pLMatrix_arg,UGint iLm_arg,UGint iLn_arg, UGdouble *pRMatrix_arg,UGint iRm_arg,UGint iRn_arg,UGdouble *pMultiMatrix_arg);
	
	//功能：用Gause-Jordan方法计算矩阵逆矩阵；
	//       当矩阵维数<20时常用。
	//参数: pMatrix_arg:需要算逆矩阵的矩阵；
	//      iN_arg: 输入矩阵的阶数；
	//返回值：计算成功返回true;否则返回false;
	UGbool  KCalInverMatrix(UGdouble *pMatrix_arg,UGint iN_arg);
	//}}Kriging插值得辅助函数 added by caogf 2003-6-7 

	//功能:计算矩阵协方差;
	//参数:pMatrix_arg:指向要计算的矩阵的指针;
	//      iM_arg    :输入矩阵的行数;
	//      iN_arg    :输入矩阵的列数;
	//  pCovMatrix_arg:要返回的矩阵指针;
	//完成日期:8/9/2002
	UGbool CalCov( UGdouble *pMatrix_arg,UGint iM_arg, UGint iN_arg,UGdouble *pCovMatrix_arg);
	
protected:
	UGQuadNode* m_pQuadRoot;
	UGKdTree* m_pKdTree;	
	UGdouble m_dSill;
	UGdouble m_dNugget;
	UGdouble m_dRange;
	UGGridOptions::VariogramMode m_nVairogramMode;
	UGint m_nMax;
	UGint m_nMax2;
	UGint m_nNodeCount;
	UGint m_nCurrentNode;
};
}

#endif // !defined(UGKRIGINGBUILDER_H)





















