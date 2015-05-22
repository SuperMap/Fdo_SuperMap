/* 
	\file UGMatrix4d.h
	\brief 定义 4 X 4 矩阵类。
	\author malq
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>更新说明：。</b>
	<em>1、第一条说明。</em>
	<em>2、第二条说明。</em>
*/

#if !defined(AFX_UGMATRIX4D_H__67A327BB_7D71_4996_8DBC_4884AB212BCD__INCLUDED_)
#define AFX_UGMATRIX4D_H__67A327BB_7D71_4996_8DBC_4884AB212BCD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include "Scene/UGPrerequisites.h"
#include "Scene/UGVector3R.h"
#include "Scene/UGMatrix3R.h"
#include "Scene/UGQuaternion4d.h"

namespace  UGC 
{

//! \brief   4X4矩阵类
//! \remarks 维护4X4矩阵
class SCENE_API UGMatrix4d  
{
friend class UGQuaternion4d;
public:

	//! \brief 缺省构造函数。
	UGMatrix4d();
	
	
	//! \brief 用16个浮点数构造矩阵类的构造函数。
	//! \param m00 [in]。
	//! \param m01 [in]。
	//! \param m02 [in]。
	//! \param m03 [in]。
	//! \param m10 [in]。
	//! \param m11 [in]。
	//! \param m12 [in]。
	//! \param m13 [in]。
	//! \param m20 [in]。
	//! \param m21 [in]。
	//! \param m22 [in]。
	//! \param m23 [in]。
	//! \param m30 [in]。
	//! \param m31 [in]。
	//! \param m32 [in]。
	//! \param m33 [in]。
	inline UGMatrix4d(
            UGReal m00, UGReal m01, UGReal m02, UGReal m03,
            UGReal m10, UGReal m11, UGReal m12, UGReal m13,
            UGReal m20, UGReal m21, UGReal m22, UGReal m23,
            UGReal m30, UGReal m31, UGReal m32, UGReal m33)	
    {
        m[0][0] = m00;
        m[0][1] = m01;
        m[0][2] = m02;
        m[0][3] = m03;
        m[1][0] = m10;
        m[1][1] = m11;
        m[1][2] = m12;
        m[1][3] = m13;
        m[2][0] = m20;
        m[2][1] = m21;
        m[2][2] = m22;
        m[2][3] = m23;
        m[3][0] = m30;
        m[3][1] = m31;
        m[3][2] = m32;
        m[3][3] = m33;
    }

	//! \brief 析构函数。
	virtual ~UGMatrix4d();
	

	//! \brief 重载*，矩阵与数值相乘。
	//! \param scalar 数值[in]。
	//! \return 运算完成后4x4矩阵。
	inline UGMatrix4d operator*(UGReal scalar)
    {
        return UGMatrix4d(
            scalar*m[0][0], scalar*m[0][1], scalar*m[0][2], scalar*m[0][3],
            scalar*m[1][0], scalar*m[1][1], scalar*m[1][2], scalar*m[1][3],
            scalar*m[2][0], scalar*m[2][1], scalar*m[2][2], scalar*m[2][3],
            scalar*m[3][0], scalar*m[3][1], scalar*m[3][2], scalar*m[3][3]);
    }

	//! \brief 重载*，完成矩阵与矩阵相乘。
	//! \param &m2 乘数矩阵[in]。
	//! \return 运算完成后矩阵。
	inline UGMatrix4d operator * ( const UGMatrix4d &m2 ) const
   	{
        return Concatenate( m2 );
    }

	//! \brief 重载*，矩阵与三维向量相乘。
	//! \param &v 三维向量[in]。
	//! \return 三维向量。
	//! \remarks 从矩阵中取出最上面3X3矩阵与三维向量进行相乘。
	inline UGVector3R operator * ( const UGVector3R &v ) const
	{
		UGVector3R r;		
		UGReal fInvW = (UGReal)(1.0 / ( m[3][0] + m[3][1] + m[3][2] + m[3][3] ));
		
		r.x = ( m[0][0] * v.x + m[0][1] * v.y + m[0][2] * v.z + m[0][3] ) * fInvW;
		r.y = ( m[1][0] * v.x + m[1][1] * v.y + m[1][2] * v.z + m[1][3] ) * fInvW;
		r.z = ( m[2][0] * v.x + m[2][1] * v.y + m[2][2] * v.z + m[2][3] ) * fInvW;
		
		return r;
	}
		
	//! \brief 矩阵相乘。
	//! \param &m2 另外一个4X4矩阵[in]。
	//! \return 完成运算后4X4矩阵。
	inline UGMatrix4d Concatenate(const UGMatrix4d &m2) const
    {
        UGMatrix4d r;
        r.m[0][0] = m[0][0] * m2.m[0][0] + m[0][1] * m2.m[1][0] + m[0][2] * m2.m[2][0] + m[0][3] * m2.m[3][0];
        r.m[0][1] = m[0][0] * m2.m[0][1] + m[0][1] * m2.m[1][1] + m[0][2] * m2.m[2][1] + m[0][3] * m2.m[3][1];
        r.m[0][2] = m[0][0] * m2.m[0][2] + m[0][1] * m2.m[1][2] + m[0][2] * m2.m[2][2] + m[0][3] * m2.m[3][2];
        r.m[0][3] = m[0][0] * m2.m[0][3] + m[0][1] * m2.m[1][3] + m[0][2] * m2.m[2][3] + m[0][3] * m2.m[3][3];

        r.m[1][0] = m[1][0] * m2.m[0][0] + m[1][1] * m2.m[1][0] + m[1][2] * m2.m[2][0] + m[1][3] * m2.m[3][0];
        r.m[1][1] = m[1][0] * m2.m[0][1] + m[1][1] * m2.m[1][1] + m[1][2] * m2.m[2][1] + m[1][3] * m2.m[3][1];
        r.m[1][2] = m[1][0] * m2.m[0][2] + m[1][1] * m2.m[1][2] + m[1][2] * m2.m[2][2] + m[1][3] * m2.m[3][2];
        r.m[1][3] = m[1][0] * m2.m[0][3] + m[1][1] * m2.m[1][3] + m[1][2] * m2.m[2][3] + m[1][3] * m2.m[3][3];

        r.m[2][0] = m[2][0] * m2.m[0][0] + m[2][1] * m2.m[1][0] + m[2][2] * m2.m[2][0] + m[2][3] * m2.m[3][0];
        r.m[2][1] = m[2][0] * m2.m[0][1] + m[2][1] * m2.m[1][1] + m[2][2] * m2.m[2][1] + m[2][3] * m2.m[3][1];
        r.m[2][2] = m[2][0] * m2.m[0][2] + m[2][1] * m2.m[1][2] + m[2][2] * m2.m[2][2] + m[2][3] * m2.m[3][2];
        r.m[2][3] = m[2][0] * m2.m[0][3] + m[2][1] * m2.m[1][3] + m[2][2] * m2.m[2][3] + m[2][3] * m2.m[3][3];

        r.m[3][0] = m[3][0] * m2.m[0][0] + m[3][1] * m2.m[1][0] + m[3][2] * m2.m[2][0] + m[3][3] * m2.m[3][0];
        r.m[3][1] = m[3][0] * m2.m[0][1] + m[3][1] * m2.m[1][1] + m[3][2] * m2.m[2][1] + m[3][3] * m2.m[3][1];
        r.m[3][2] = m[3][0] * m2.m[0][2] + m[3][1] * m2.m[1][2] + m[3][2] * m2.m[2][2] + m[3][3] * m2.m[3][2];
        r.m[3][3] = m[3][0] * m2.m[0][3] + m[3][1] * m2.m[1][3] + m[3][2] * m2.m[2][3] + m[3][3] * m2.m[3][3];

        return r;
    }
 
	//! \brief 重载[]，取出对应行。
	//! \param iRow 行号，有效范围为零到三[in]。
	//! \return 矩阵指定一行数据，返回行数据指针。
	inline UGReal* operator[] (UGuint iRow)
    {
        UGASSERT( iRow < 4 );
        return (UGReal*)m[iRow];
    }

 
	//! \brief 判断两个矩阵是否相等。
	//! \param &m2 另外一个矩阵[in]。
	//! \return 若相等返回为TRUE，若不相等则返回为FALSE。
	inline UGbool operator == (const UGMatrix4d &m2)
    {
			return
			(
			UGIS0(m[0][0]-m2.m[0][0])&& 
			UGIS0(m[0][1]-m2.m[0][1])&& 
			UGIS0(m[0][2]-m2.m[0][2])&& 
			UGIS0(m[0][3]-m2.m[0][3])&& 
			UGIS0(m[1][0]-m2.m[1][0])&& 
			UGIS0(m[1][1]-m2.m[1][1])&& 
			UGIS0(m[1][2]-m2.m[1][2])&& 
			UGIS0(m[1][3]-m2.m[1][3])&& 
			UGIS0(m[2][0]-m2.m[2][0])&& 
			UGIS0(m[2][1]-m2.m[2][1])&& 
			UGIS0(m[2][2]-m2.m[2][2])&& 
			UGIS0(m[2][3]-m2.m[2][3])&& 
			UGIS0(m[3][0]-m2.m[3][0])&& 
			UGIS0(m[3][1]-m2.m[3][1])&& 
			UGIS0(m[3][2]-m2.m[3][2])&& 
			UGIS0(m[3][3]-m2.m[3][3])
			);
    }
 
	//! \brief 取出只读矩阵行数据。
	//! \param iRow 行号，有效范围为零到三[in]。
	//! \return 行数据。
	inline const UGReal *const operator [] ( UGuint iRow ) const
    {
        UGASSERT( iRow < 4 );
        return m[iRow];
    }
    
	UGReal operator () (UGuint iRow, UGuint iCol)
	{
		UGASSERT( iRow < 4 || iCol < 4);
		return m[iRow][iCol];
	}

	//! \brief 生成右手坐标系下模型视点矩阵。
	//! \param cameraPosition 相机位置[in]。
	//! \param cameraTarget 相机焦点对准位置[in]。
	//! \param cameraUpVector 相机向上方向[in]。
	//! \return  模型视点矩阵。
	//! \remarks 生成该矩阵后必须在三维中使用该矩阵后才算完成对三维中模型视点矩阵的设置，在OpenGL中使用。
	static UGMatrix4d LookAtRH(UGVector3R cameraPosition, UGVector3R cameraTarget, UGVector3R cameraUpVector);

	//! \brief 生成左手坐标系模型视点矩阵。
	//! \param cameraPosition 相机位置[in]。
	//! \param cameraTarget 相机焦点对准位置[in]。
	//! \param cameraUpVector 相机向上方向[in]。
	//! \return 模型视点矩阵。
	//! \remarks 主要是在DirectX中使用，必须在DirectX中设置该矩阵为模型视点矩阵才算设置试点模型矩阵成功。
	static UGMatrix4d LookAtLH(UGVector3R cameraPosition, UGVector3R cameraTarget, UGVector3R cameraUpVector);
	
	//! \brief 矩阵平移。
	//! \param x X轴移动大小[in]。
	//! \param y Y轴移动大小[in]。
	//! \param z Z轴移动大小[in]。
	//! \return 平移后矩阵。
	static UGMatrix4d Translation(UGReal x, UGReal y, UGReal z);

	//! \brief 旋转。
	//! \param rotationX 绕X轴旋转角度[in]。
	//! \param rotationY 绕Y轴旋转角度[in]。
	//! \param rotationZ 绕Z轴旋转角度[in]。
	//! \return 旋转后矩阵。
	static UGMatrix4d RotationXYZ(UGReal rotationX, UGReal rotationY, UGReal rotationZ);
	
	//! \brief 绕X轴旋转。
	//! \param angle 绕X轴旋转角度[in]。
	//! \return 旋转后矩阵。		
	static UGMatrix4d RotationX(UGReal angle);

	//! \brief 绕Y轴旋转。
	//! \param angle 绕Y轴旋转角度[in]。
	//! \return 旋转后矩阵。
	static UGMatrix4d RotationY(UGReal angle);

	//! \brief 绕Z轴旋转。
	//! \param angle [in]。
	//! \return 旋转后矩阵。		
	static UGMatrix4d RotationZ(UGReal angle);
	
	//! \brief 生成透视投影矩阵。
	//! \param fieldOfViewY 视角在Y轴上大小[in]。
	//! \param aspectRatio 视锥体宽高比[in]。
	//! \param znearPlane 近平面Z值[in]。
	//! \param zfarPlane 远平面Z值[in]。
	//! \return 透视投影矩阵。
	static UGMatrix4d PerspectiveFovRH(UGReal fieldOfViewY, UGReal aspectRatio, UGReal znearPlane, UGReal zfarPlane);
	
	//! \brief 计算矩阵的伴随矩阵。
	//! \return 矩阵的伴随矩阵。
	//! \remarks 。	
	UGMatrix4d Adjoint();

	//! \brief 计算矩阵行列式值。
	//! \return 行列式值。。
	UGReal Determinant();

	//! \brief 计算机矩阵逆矩阵。
	//! \return 矩阵逆矩阵。
	UGMatrix4d Invert();	

	UGMatrix4d Transpose();

	//! \brief 4X4零矩阵
	//! \remarks 所有元素为零
	static const UGMatrix4d ZERO;


	//! \brief 4X4 单位矩阵
	//! \remarks 对角线元素为1，其他为0
	static const UGMatrix4d IDENTITY;

	static const UGMatrix4d CLIPSPACE2DTOIMAGESPACE;
	
	
	//! \brief 计算4x4中任意3x3子矩阵行列式。
	//! \param m 4x4矩阵[in]。
	//! \param r0 第一行行号[in]。
	//! \param r1 第二行行号[in]。
	//! \param r2 第三行行号[in]。
	//! \param c0 第一列列号[in]。
	//! \param c1 第二列列号[in]。
	//! \param c2 第三列列号[in]。
	inline UGReal MINOR(const UGMatrix4d& m, const size_t r0, const size_t r1, const size_t r2, 
		const size_t c0, const size_t c1, const size_t c2)
	{
		return m[r0][c0] * (m[r1][c1] * m[r2][c2] - m[r2][c1] * m[r1][c2]) -
			m[r0][c1] * (m[r1][c0] * m[r2][c2] - m[r2][c0] * m[r1][c2]) +
			m[r0][c2] * (m[r1][c0] * m[r2][c1] - m[r2][c0] * m[r1][c1]);
	}
	inline void operator = ( const UGMatrix3R& mat3 )
    {
        m[0][0] = mat3.m[0][0]; m[0][1] = mat3.m[0][1]; m[0][2] = mat3.m[0][2];
        m[1][0] = mat3.m[1][0]; m[1][1] = mat3.m[1][1]; m[1][2] = mat3.m[1][2];
        m[2][0] = mat3.m[2][0]; m[2][1] = mat3.m[2][1]; m[2][2] = mat3.m[2][2];
    }
	inline void SetTrans( const UGVector3R& v )
    {
        m[0][3] = v.x;
        m[1][3] = v.y;
        m[2][3] = v.z;
    }
	void MakeTransform(UGVector3R& position, UGVector3R& scale, UGQuaternion4d& orientation);
    
	static UGMatrix4d ComputeRotateMatrix(UGdouble angle, UGVector3R vecRotateAxis);

	
protected:


	//! \brief 矩阵中数据
	//! \remarks 矩阵中数据保存在该变量中。
	UGReal m[4][4];

};


}
#endif // !defined(AFX_UGMATRIX4D_H__67A327BB_7D71_4996_8DBC_4884AB212BCD__INCLUDED_)
