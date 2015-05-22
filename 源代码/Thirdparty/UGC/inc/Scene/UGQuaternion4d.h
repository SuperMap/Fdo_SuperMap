/* 
	\file UGQuaternion4d.h
	\brief 四元数类文件
	\author malq
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>更新说明：。</b>
	<em>1、第一条说明。</em>
	<em>2、第二条说明。</em>
*/

#if !defined(AFX_UGQUATERNION4D_H__828A96C2_95EA_4DCC_9468_666159FA635E__INCLUDED_)
#define AFX_UGQUATERNION4D_H__828A96C2_95EA_4DCC_9468_666159FA635E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Scene/UGPrerequisites.h"
#include "Scene/UGMatrix3R.h"
#include "Scene/UGMatrix4d.h"

namespace  UGC 
{

//! \brief 四元数类
//! \remarks 四元数主要负责空间旋转
class SCENE_API UGQuaternion4d  
{

public:
	//! \brief 构造函数
	UGQuaternion4d();
	//! \brief 构造函数
	UGQuaternion4d(UGReal x, UGReal y, UGReal z, UGReal w);
	UGQuaternion4d(const UGVector3R& xaxis, const UGVector3R& yaxis, const UGVector3R& zaxis);
	//! \brief 析构函数
	virtual ~UGQuaternion4d();
	//! \brief 重载元算符四元数相乘 
	UGQuaternion4d operator*(const UGQuaternion4d& obj);
	//! \brief 重载元算符四元数和向量相乘
	UGVector3R operator* (const UGVector3R& v) const;
	//! \brief 由旋转轴向量转为四元数
	void FromAxes (const UGVector3R* akAxis);
	//! \brief 由三维旋转轴向量转为四元数
	void FromAxes (const UGVector3R& xAxis, const UGVector3R& yAxis, const UGVector3R& zAxis);
	//! \brief 由旋转矩阵转为四元树
	void FromRotationMatrix (const UGMatrix3R& kRot);
	//! \brief 标准化四元数
	void Normalize();
	//! \brief 四元数长度
	UGReal Length();
	//! \brief 四元数转为轴和角 
	void ToAngleAxis (UGReal& rfAngle, UGVector3R& rkAxis);
	//! \brief 四元数点积 
	static UGReal Dot(const UGQuaternion4d& a, const UGQuaternion4d& b);
	//! \brief 四元数转为欧拉角 
	static UGVector3R QuaternionToEuler(const UGQuaternion4d& q);
	//! \brief 欧拉角转为四元数
	static UGQuaternion4d EulerToQuaternion(UGReal yaw, UGReal pitch, UGReal roll);
	//! \brief 四元数插值
	static UGQuaternion4d Slerp(const UGQuaternion4d& q0, const UGQuaternion4d& q1, UGReal t);
	//! \brief 从轴角转为四元数
	void FromAngleAxis (const UGReal& rfAngle,
								const UGVector3R& rkAxis);
	//! \brief 由四元数专为旋转矩阵
	void ToRotationMatrix (UGMatrix3R& kRot);
	//! \brief 由四元数专为旋转矩阵
	void ToRotationMatrix (UGMatrix4d& kRot); 
	UGQuaternion4d Inverse () const;
	UGQuaternion4d UnitInverse () const;
	UGbool operator== (const UGQuaternion4d& rhs) const;
	
	//! \brief  
	UGReal x;
	//! \brief  
	UGReal y;
	//! \brief  
	UGReal z;
	//! \brief  
	UGReal w;

	static const UGQuaternion4d ZERO;
    static const UGQuaternion4d IDENTITY;

};
}
#endif // !defined(AFX_UGQUATERNION4D_H__828A96C2_95EA_4DCC_9468_666159FA635E__INCLUDED_)
