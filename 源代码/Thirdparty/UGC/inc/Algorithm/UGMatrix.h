/*! \file 		UGMatrix.h
*   \brief 		矩阵的运算 
*   \remarks 	 
*   \author 	LIWENLONG 
*   \attention
*   Copyright(c) 1996-2004 SuperMap GIS Technologies,Inc.<br> 
*        All Rights Reserved 

*    <b>更新说明：</b><br> 
	   \Version caogf  放到Algorithm工程中来
*/ 

// UGMatrix.h: interface for the UGMatrix class.
//
//////////////////////////////////////////////////////////////////////

#include "Base/ugdefs.h"
#include "Base/UGString.h"

#if !defined(UGMATRIX_H)
#define UGMATRIX_H

namespace UGC {

class ALGORITHM_API UGMatrix  
{
public:
	UGMatrix();
	UGMatrix(UGint nRow,UGint nColumn);
	virtual ~UGMatrix();

public:

	//! \brief 		
	//! \return 	void
	//! \param 		strFileName
	//! \remarks 	本接口暂时没有实现	
	void display(UGString& strFileName);

	//! \brief 		
	//! \return 	void
	//! \param 		Element
	//! \param 		nIndex
	//! \remarks 		
	void PutElement(UGdouble Element,UGint nIndex);

	//! \brief 		store matrix element(i,j) in the array.
	//! \return 	matrix
	//! \param 		Element
	//! \param 		i
	//! \param 		j
	//! \remarks 		
	void PutElement(UGdouble Element,UGint i,UGint j);

	//! \brief 		retrieve matrix elemnent (i,j) from array.
	//! \return 	matrix
	//! \param 		i
	//! \param 		j
	//! \remarks 		
	UGdouble GetElement(UGint i,UGint j) const;
	
	//operatre attribute
	UGint GetColumnCount();
	UGint GetRowCount();
	UGbool ReInit(UGint nRow,UGint nColumn);

	//matrix arithmetic oprations

	//! \brief 		矩阵求和
	//! \return 	UGbool
	//! \param 		BaseMatrix		加矩阵
	//! \param 		SumtMatrix		返回的和矩阵
	//! \remarks 
	
	/*	reason:	增加const			By: guohui	time: 2005-10-31 14:33:45	*/	
	UGbool AddMatrix(const UGMatrix& BaseMatrix,UGMatrix& SumtMatrix)const;

	//! \brief 		矩阵求乘
	//! \return 	UGbool
	//! \param 		BaseMatrix		乘矩阵
	//! \param 		Product			返回的乘积矩阵
	//! \remarks 		
	UGbool MulMatrix( const UGMatrix& BaseMatrix,UGMatrix& Product) const ;

	//! \brief 		矩阵求转置
	//! \return 	UGbool
	//! \param 		BaseMatrix
	//! \param 		Transpose		返回的转置阵
	//! \remarks 		
	UGbool TranMatrix( const UGMatrix& BaseMatrix,UGMatrix& Transpose) const ;

	//! \brief 		矩阵求转置
	//! \return 	UGbool
	//! \param 		&Transpose		返回的转置阵
	//! \remarks 		
	UGbool TranMatrix(UGMatrix &Transpose)const;

	//! \brief 		对BaseMatrix矩阵求逆
	//! \return 	UGbool
	//! \param 		BaseMatrix		返回逆矩阵
	//! \remarks 	全选主元高斯-约当法	
	UGbool InvsMatrix( UGMatrix& BaseMatrix);

	//! \brief 		矩阵求差
	//! \return 	UGbool
	//! \param 		BaseMatrix
	//! \param 		SubMatrix
	//! \remarks 		
	UGbool SubMatrix( const UGMatrix& BaseMatrix,UGMatrix& SubMatrix) const;

	//! \brief 		矩阵的秩
	//! \return 	UGint
	//! \param 		a
	//! \remarks 		
    UGint ChiResolve(UGMatrix& a);
	
	//! \brief 		矩阵的秩
	//! \return 	UGint
	//! \param 		
	//! \remarks 		
	UGint ChiResolve();

	//! \brief 		将列矩阵写成对角阵形
	//! \return 	UGbool
	//! \param 		&DiagonMatrix
	//! \remarks 		
    UGbool CreateDiagonMatrix(UGMatrix &DiagonMatrix);

	//! \brief 		据原系数矩阵求偏导函数的系数阵
	//! \return 	UGbool
	//! \param 		Coefficient			原系数矩阵
	//! \param 		TargetCoefficient	偏导函数的系数阵
	//! \remarks 		
	UGbool CalDerivate(UGMatrix& Coefficient,UGMatrix& TargetCoefficient);

	//! \brief 		高斯消元法解线性方程组(方程为 a*X = b，解保存于b中)
	//! \return 	UGint
	//! \param 		a		双精度实型二维数组，体积为n*n,存放n*n的实矩阵A
	//! \param 		b		常数向量,体积为n;返回方程组的解向量
	//! \remarks    0,失败;1成功		
	UGint CalGause(UGMatrix& a,UGMatrix& b);

	//! \brief 		一般实矩阵的奇异值分解
	//! \return 	UGint
	//! \param 		a		双精度实型二维数组，体积为m*n,存放m*n的实矩阵A；返回时其对角线给出奇异值，其余元素均为零
	//! \param 		u		双精度实型二维数组，体积为m*m,返回时存放左奇异向量U
	//!	\param 		v		双精度实型二维数组，体积为n*n,返回时存放左奇异向量V
	//! \param 		eps		双精度实型变量，给定的精度要求
	//! \param 		ka		整型变量，其值为max(m,n)+1
	//! \remarks 	豪斯荷尔德(Householder)变换及变形QR算法	
	UGint QYResolve(UGMatrix& a,UGMatrix& u,UGMatrix& v,UGdouble eps,UGint ka);

	//! \brief 		求广义逆的奇异值分解：
	//! \return 	UGint
	//! \param 		a
	//! \param 		aa
	//! \param 		eps
	//! \param 		u
	//! \param 		v
	//! \param 		ka
	//! \remarks 		
	UGint RQYResolve(UGMatrix& a,UGMatrix& aa,UGdouble eps,UGMatrix& u,UGMatrix& v,UGint ka);

	//! \brief 		利用广义逆求超定方程组AX=B的最小二乘解，A为m*n(m>=n)矩阵，且列线性无关，当m=n时即为求线性代数方程
	//! \return 	UGint
	//! \param 		a
	//! \param 		b
	//! \param 		x
	//! \param 		aa
	//! \param 		eps
	//! \param 		u
	//! \param 		v
	//! \param 		ka
	//! \remarks 		
	UGint CalQYMinMulti(UGMatrix& a,UGMatrix& b,UGMatrix& x,UGMatrix& aa,double eps,UGMatrix& u,UGMatrix& v,UGint ka);

	//! \brief 		赋值
	void operator = (const UGMatrix &Matrix);

	//! \brief 		取元素
	UGdouble& operator [] (const UGint nIndex );

protected:
	void ppp(UGMatrix& a,double* e,double* s,UGMatrix& v);
	void sss(UGdouble* fg,UGdouble* cs);

protected:
	UGint m_nRow;            //行数
	UGint m_nCol;            //列数
	UGdouble *m_pdArray ;     //stores the element of Matrix in the array. 

};

}

#endif
